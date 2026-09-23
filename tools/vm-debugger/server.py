#!/usr/bin/env python3
"""Backend for the Another World VM debugger: ROMs, names, and a rename log.

Why this exists
---------------
The naming effort reads pictures out of a renderer one at a time. What it has
never had is the game *running*, with every polygon on screen labelled and a way
to say "that one is the hero's gun arm" at the moment you are looking at it.

This serves three things and does nothing clever with any of them:

1. **The ROM slabs**, straight from the archaeology repo's `tmp/output/<port>/
   romset/`, so the browser can run the VM against the same bytes every probe in
   `notes/` measures.
2. **The names**, parsed out of `src/levels/<branch>/<STAGE>.asm` -- the
   canonical tree, which `notes/shared-bank-naming/asset_naming_share.py`
   counts and which `notes/tree-name-drift/name_drift.py` shows the unified tree
   lags.
3. **A rename log**, append-only, one JSON object per line.

The log is the point of the whole exercise. A rename typed into the debugger is
NOT applied to the tree here: applying a name is what
`apply_branch_scoped_names.py` is for, and it has a validator with a
family-gap rule, a collision check and a byte gate behind it, none of which a
web form should be allowed to skip. What the log carries is a human saying what
a picture *is*, with the frame they said it on -- guidance for an agent to turn
into a proposal table with evidence, the same as any other batch.

Usage
-----
    python3 tools/vm-debugger/server.py            # http://127.0.0.1:8017
    python3 tools/vm-debugger/server.py --port 9000 --romsets /path/to/romsets

Stdlib only: no Flask, no build step, nothing to install.
"""

from __future__ import annotations

import argparse
import json
import mimetypes
import re
import sys
import time
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from urllib.parse import urlparse

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
STATIC = HERE / "static"
LOG = HERE / "rename_log.jsonl"

BRANCH_PORT = {"chahi_amiga_1991": "amiga", "dos_1992": "msdos",
               "cartridge_1992": "genesis_europe", "gba_2004": "gba_usa"}
STAGE_ID = {"CODE_WHEEL": 0, "INTRO": 1, "LAKE": 2, "PRISON": 3, "CAVES": 4,
            "TANK": 5, "CAPSULE": 6, "ENDING": 7, "PASSCODE": 8}

RE_EQU = re.compile(r"^(\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)\s*$")
RE_LABEL = re.compile(r"^(\w+):")
RE_NUMBERED = re.compile(r"^CINEMATIC_\d+$|^VIDEO2_\d+$")


def names_for(branch: str, stage: str) -> dict:
    """Every EQU and label the stage defines, split by what it names.

    `cinematic` and `video2` are keyed by offset because that is what a `video`
    instruction carries and what the debugger has in hand at draw time. Two
    constants at one offset (the tree has ~30 such twins, see
    `undefined_symbols.py --redundant`) both land in `aliases`.
    """
    f = ROOT / "src" / "levels" / branch / f"{stage}.asm"
    if not f.is_file():
        return {"error": f"no {branch}/{stage}.asm"}
    cinematic: dict[str, str] = {}
    video2: dict[str, str] = {}
    aliases: dict[str, list[str]] = {}
    labels: dict[str, str] = {}
    for line in f.read_text(errors="replace").splitlines():
        m = RE_EQU.match(line)
        if m:
            name, off = m.group(1), m.group(2).upper().replace("0X", "0x")
            tgt = (cinematic if name.startswith("CINEMATIC_")
                   else video2 if name.startswith("VIDEO2_") else None)
            if tgt is None:
                continue
            if off in tgt and tgt[off] != name:
                aliases.setdefault(off, [tgt[off]]).append(name)
                # Prefer the semantic one when a numbered twin exists.
                if RE_NUMBERED.match(tgt[off]):
                    tgt[off] = name
            else:
                tgt[off] = name
            continue
        m = RE_LABEL.match(line)
        if m:
            labels.setdefault(m.group(1), m.group(1))
    return {"branch": branch, "stage": stage, "stage_id": STAGE_ID.get(stage),
            "cinematic": cinematic, "video2": video2, "aliases": aliases,
            "labels": sorted(labels)}


class Handler(BaseHTTPRequestHandler):
    romsets: Path = Path()

    def log_message(self, fmt, *args):            # quieter console
        if "api/rename" in (args[0] if args else ""):
            sys.stderr.write("%s - %s\n" % (self.address_string(), args[0]))

    # ---- helpers ----------------------------------------------------
    def _send(self, code: int, body: bytes, ctype: str):
        self.send_response(code)
        self.send_header("Content-Type", ctype)
        self.send_header("Content-Length", str(len(body)))
        self.send_header("Cache-Control", "no-store")
        self.end_headers()
        self.wfile.write(body)

    def _json(self, obj, code: int = 200):
        self._send(code, json.dumps(obj).encode(), "application/json")

    # ---- routes -----------------------------------------------------
    def do_GET(self):
        path = urlparse(self.path).path
        if path in ("/", "/index.html"):
            return self._file(STATIC / "index.html")
        if path.startswith("/static/"):
            p = (STATIC / path[len("/static/"):]).resolve()
            if STATIC.resolve() in p.parents or p.parent == STATIC.resolve():
                return self._file(p)
            return self._json({"error": "outside static"}, 403)
        if path.startswith("/api/rom/"):
            _, _, _, port, fname = path.split("/", 4)
            if "/" in fname or ".." in fname or ".." in port:
                return self._json({"error": "bad name"}, 400)
            p = self.romsets / port / "romset" / fname
            if not p.is_file():
                return self._json({"error": f"missing {p}"}, 404)
            return self._send(200, p.read_bytes(), "application/octet-stream")
        if path.startswith("/api/names/"):
            _, _, _, branch, stage = path.split("/", 4)
            return self._json(names_for(branch, stage))
        if path == "/api/config":
            return self._json({
                "branches": {b: p for b, p in BRANCH_PORT.items()
                             if (self.romsets / p / "romset"
                                 / "cinematic.rom").is_file()},
                "stages": STAGE_ID,
                "romsets": str(self.romsets),
            })
        if path == "/api/renames":
            if not LOG.is_file():
                return self._json([])
            return self._json([json.loads(l) for l in
                               LOG.read_text().splitlines() if l.strip()])
        return self._json({"error": "no such route", "path": path}, 404)

    def do_POST(self):
        if urlparse(self.path).path != "/api/rename":
            return self._json({"error": "no such route"}, 404)
        n = int(self.headers.get("Content-Length", 0))
        try:
            payload = json.loads(self.rfile.read(n) or b"{}")
        except json.JSONDecodeError as exc:
            return self._json({"error": f"bad json: {exc}"}, 400)
        rows = payload.get("renames") or []
        if not rows:
            return self._json({"error": "no renames in payload"}, 400)
        entry = {
            "at": time.strftime("%Y-%m-%dT%H:%M:%S%z"),
            "branch": payload.get("branch"),
            "stage": payload.get("stage"),
            "mode": payload.get("mode", "single"),
            "pattern": payload.get("pattern"),
            "replacement": payload.get("replacement"),
            "note": payload.get("note", ""),
            "frame": payload.get("frame"),
            "on_screen": payload.get("on_screen"),
            "renames": rows,
        }
        with LOG.open("a") as fh:
            fh.write(json.dumps(entry) + "\n")
        return self._json({"ok": True, "logged": len(rows), "at": entry["at"]})

    def _file(self, p: Path):
        if not p.is_file():
            return self._json({"error": f"missing {p.name}"}, 404)
        ctype = mimetypes.guess_type(p.name)[0] or "application/octet-stream"
        if p.suffix in (".js", ".css", ".html"):
            ctype += "; charset=utf-8"
        return self._send(200, p.read_bytes(), ctype)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--port", type=int, default=8017)
    ap.add_argument("--host", default="127.0.0.1")
    ap.add_argument("--romsets", default=str(
        ROOT.parent / "another-world-archaeology" / "tmp" / "output"),
        help="directory holding <port>/romset/*.rom")
    args = ap.parse_args()
    Handler.romsets = Path(args.romsets).resolve()
    if not Handler.romsets.is_dir():
        print(f"romsets not found: {Handler.romsets}\n"
              f"run `make extract` in the archaeology repo, or pass --romsets",
              file=sys.stderr)
        return 2
    srv = ThreadingHTTPServer((args.host, args.port), Handler)
    print(f"VM debugger on http://{args.host}:{args.port}")
    print(f"  romsets  {Handler.romsets}")
    print(f"  names    {ROOT / 'src' / 'levels'}")
    print(f"  log      {LOG}")
    try:
        srv.serve_forever()
    except KeyboardInterrupt:
        print()
    return 0


if __name__ == "__main__":
    sys.exit(main())
