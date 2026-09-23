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
3. **An annotation log**, append-only, one JSON object per line. It is
   committed and never rewritten: an entry's id is the sha1 of its line, so
   editing a line orphans every proposal row and verdict that cites it.

The log is the point of the whole exercise, and what it mostly carries is not
names. It is **prose**: a human pointing at a picture on a frame and saying
what is happening in it --

    "this is Buddy stuck in a tunnel while crawling. He is clearly struggling
     to move further down because there is a ring in the way, and he is moving
     the ring with his hands as if trying to get rid of the obstruction"

-- which is worth far more than a name typed into a box, for two reasons.

**One annotation names a whole family.** The entry records which routine issued
the draw, and "all the frames of that sequence" is exactly "the other draws in
that routine" -- the same grouping `notes/render-and-name/frame_runs.py` works
from. An agent reads the sentence above, finds the run, and names every frame of
it with evidence, which is a job a rename box cannot do.

**Concatenated, the annotations are a description of the game.** Every entry is
tied to a stage, a frame and the constants on screen at that moment, so reading
the log end to end -- `GET /api/guidance`, or `--export` -- gives an agent
something no probe in `notes/` can produce: what the scenes *are*. Naming has
been done from geometry and control flow; this is the only channel through which
a person who has played the game can say what they are looking at.

Renaming is still here, single and by pattern, and is logged the same way. But a
rename typed into the debugger is NOT applied to the tree: applying a name is
what `apply_branch_scoped_names.py` is for, and behind it sit a family-gap rule,
a collision check, `undefined_symbols.py` and the byte gate -- none of which a
web form should be allowed to skip.

Usage
-----
    python3 tools/vm-debugger/server.py            # http://127.0.0.1:8017
    python3 tools/vm-debugger/server.py --port 9000 --romsets /path/to/romsets

Stdlib only: no Flask, no build step, nothing to install.
"""

from __future__ import annotations

import argparse
import hashlib
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
RE_VAR = re.compile(r"^(\w+)\s+EQU\s+0x([0-9A-Fa-f]{2})\s*$")
RE_DRAW = re.compile(r"^\tvideo (type=0, )?offset=(\w+)", re.M)
RE_LABEL = re.compile(r"^(\w+):")
RE_NUMBERED = re.compile(r"^CINEMATIC_\d+$|^CV_[0-9A-F]{4}$")


def names_for(branch: str, stage: str) -> dict:
    """Every EQU and label the stage defines, split by what it names.

    `cinematic` and `video2` are keyed by offset because that is what a `video`
    instruction carries and what the debugger has in hand at draw time. Two
    constants at one offset (the tree has ~30 such twins, see
    `undefined_symbols.py --redundant`) both land in `aliases`.

    The two namespaces are `CINEMATIC_*` for the stage's own 64 KiB slab and
    `CV_*` for the shared bank -- which the disassembly spells
    `video type=0, offset=CV_...` and `notes/shared-bank-naming/` calls the
    shared bank. A still-unnamed shared-bank key is spelled `CV_<offset in
    hex>`, e.g. `CV_5FBC`, which is why the numbered-form test has to know
    about both shapes.

    **Which bank a constant belongs to is read off its DRAW SITE, not its
    prefix.** Sorting by prefix was wrong and the unnamed counter paid for it: a
    great many shared-bank constants have been renamed out of `CV_*` into real
    names -- `HERO_CRAWL_POSE_09`, `HERO_PRONE_TRANSITION_LEFT_F00` -- and
    `dos_1992/CAVES.asm` alone draws 192 art constants whose names begin with
    neither prefix. Dropped by the prefix rule, every one of them reached the
    debugger as "no EQU" and was **counted as unnamed while already being
    named**. So: `video type=0, offset=NAME` puts NAME in the shared bank,
    `video offset=NAME` puts it in the stage's slab, and the prefix rule is kept
    only for constants this stage defines but never draws.
    """
    f = ROOT / "src" / "levels" / branch / f"{stage}.asm"
    if not f.is_file():
        return {"error": f"no {branch}/{stage}.asm"}
    cinematic: dict[str, str] = {}
    video2: dict[str, str] = {}
    aliases: dict[str, list[str]] = {}
    labels: dict[str, str] = {}
    text = f.read_text(errors="replace")

    # Pass 1: which bank does each drawn constant come from? The draw site says
    # so outright, and it is the only thing that does.
    bank: dict[str, str] = {}
    for m in RE_DRAW.finditer(text):
        bank[m.group(2)] = "video2" if m.group(1) else "cinematic"

    for line in text.splitlines():
        m = RE_EQU.match(line)
        if m:
            name, off = m.group(1), m.group(2).upper().replace("0X", "0x")
            where = bank.get(name)
            if where is None:                       # never drawn here
                where = ("cinematic" if name.startswith("CINEMATIC_")
                         else "video2" if name.startswith("CV_") else None)
            tgt = (cinematic if where == "cinematic"
                   else video2 if where == "video2" else None)
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
            "labels": sorted(labels), "vars": var_names(branch, stage)}


def var_names(branch: str, stage: str) -> dict:
    """VM variable number -> the name the disassembly gives it.

    Two sources, the per-stage file winning: `src/levels/_common_vars.inc` for
    the ones every stage shares (`HERO_X`, `SCREEN_NUM`, `PAUSE_SLICES`) and the
    stage's own `.asm` for the rest. A two-hex-digit EQU is a variable; anything
    wider is a polygon offset or an address.
    """
    out: dict[str, str] = {}
    for f in (ROOT / "src" / "levels" / "_common_vars.inc",
              ROOT / "src" / "levels" / branch / f"{stage}.asm"):
        if not f.is_file():
            continue
        for line in f.read_text(errors="replace").splitlines():
            m = RE_VAR.match(line)
            if m and not m.group(1).startswith(("CINEMATIC_", "CV_")):
                out[str(int(m.group(2), 16))] = m.group(1)
    return out


# --- address -> label ---------------------------------------------------
# The listing has no address column: `awvm-disasm` emits labels, data and
# instructions in address order and nothing else. But the order is enough.
# Walk the bytecode from 0 computing each instruction's length, walk the
# listing's instruction lines in step, and every label lands on the address of
# the instruction that follows it.
#
# This is what turns a thread's raw pc into the routine it is in -- which is
# what makes an annotation actionable, because "all the frames of that
# sequence" is exactly "the other draws in that routine", the same grouping
# `notes/render-and-name/frame_runs.py` works from.
#
# Self-checking: `vm.js` reports every `setup channel=N, address=A` it
# executes, and every such A must be a key in this map. The test asserts it.

RE_DB = re.compile(r"^\s*db\s+(.*)$")
RE_INSTR = re.compile(r"^\s+\S")


def _instr_len(rom: bytes, base: int, pc: int) -> int:
    """Length in bytes of the instruction at `pc`, by the same encodings
    `awvm/src/disasm.rs` decodes. Kept in this order so the two can be diffed."""
    op = rom[base + pc]
    if op & 0x80:
        return 4                                  # compact video
    if op & 0x40:                                 # full video
        n = 3                                     # opcode + 2 offset bytes
        n += 1                                    # x
        if not op & 0x20:
            n += 1 if not op & 0x10 else 0        # 16-bit literal x
        n += 1                                    # y
        if not op & 8 and not op & 4:
            n += 1                                # 16-bit literal y
        if not op & 2:
            if op & 1:
                n += 1                            # zoom from a variable
        elif not op & 1:
            n += 1                                # immediate zoom
        return n
    fixed = {0x00: 4, 0x01: 3, 0x02: 3, 0x03: 4, 0x04: 3, 0x05: 1, 0x06: 1,
             0x07: 3, 0x08: 4, 0x09: 4, 0x0B: 3, 0x0C: 4, 0x0D: 2, 0x0E: 3,
             0x0F: 3, 0x10: 2, 0x11: 1, 0x12: 6, 0x13: 3, 0x14: 4, 0x15: 4,
             0x16: 4, 0x17: 4, 0x18: 6, 0x19: 3, 0x1A: 6, 0x1B: 1}
    if op == 0x0A:                                # conditional jump, variable
        sub = rom[base + pc + 1]
        return 6 if sub & 0x80 else (7 if sub & 0x40 else 6)
    return fixed.get(op, 1)


def label_addresses(branch: str, stage: str, rom: bytes) -> dict:
    """label -> address, by walking listing order against bytecode order."""
    f = ROOT / "src" / "levels" / branch / f"{stage}.asm"
    sid = STAGE_ID.get(stage)
    if not f.is_file() or sid is None or not rom:
        return {}
    base = sid * 0x10000
    pc = 0
    pending: list[str] = []
    out: dict[str, int] = {}
    for line in f.read_text(errors="replace").splitlines():
        code = line.split(";", 1)[0].rstrip()
        if not code.strip():
            continue
        m = RE_LABEL.match(code)
        if m:
            pending.append(m.group(1))
            continue
        head = code.strip()
        if RE_EQU.match(head) or head.startswith((".", "#")):
            continue
        # `org` sets the cursor rather than emitting bytes. Missing this put
        # every label three bytes late: the listing opens with `org 0x0000`,
        # which was being counted as whatever instruction sits at 0.
        if head.startswith("org "):
            for name in pending:
                out.setdefault(name, pc)
            pending = []
            pc = int(head.split()[1], 0)
            continue
        if not RE_INSTR.match(code):
            continue
        for name in pending:
            out.setdefault(name, pc)
        pending = []
        m = RE_DB.match(code)
        if m:
            pc += len([b for b in m.group(1).split(",") if b.strip()])
            continue
        if pc >= 0x10000:
            break
        pc += _instr_len(rom, base, pc)
    return out


def annotation_id(line: str) -> str:
    r"""`ann:` + twelve hex of the sha1 of one raw log line, newline stripped.

    The id the rest of the mechanism cites -- proposal tables as
    `annot:<id>`, `notes/play-and-describe/verdicts.tsv` and
    `annotation_queue.py` as `ann:<id>`. It is content-derived on purpose: the
    only write this server performs is an append, so an existing line never
    changes, and an id computed here is the same one an agent gets from

        sed -n '<N>p' tools/vm-debugger/rename_log.jsonl | tr -d '\n' | sha1sum

    with no tool and no index file. An edited line therefore gets a new id and
    its old citations show up as orphans rather than pointing silently at a
    sentence that is no longer there -- which is why the log is append-only.
    """
    return "ann:" + hashlib.sha1(line.encode()).hexdigest()[:12]


def guidance() -> str:
    """Every annotation, in order, as one document an agent can read.

    The user's point, and it is a good one: any single annotation names one
    family, but *concatenated* they are a description of the game. Nothing else
    in this repository can produce that. Every probe in `notes/` reasons from
    geometry, control flow or bank layout; none of them has ever been able to
    say what a scene is about. A person who has played the game can, and this is
    the channel.

    Grouped by stage, because that is how the naming work is batched, and each
    entry keeps its frame, the routine that drew it and what else was on screen,
    so a claim can be checked rather than taken on trust.

    The document carries the **typed names** too -- `kind:"rename"` and
    `kind:"bulk_rename"` -- in a subsection of their own per stage. They were
    left out until 2026-09-23, which hid two thirds of the log from the only two
    ways it is read. They are not descriptions: a name typed into a box states
    no grounds, so they are proposals, `low` on their own (`docs/NAMING.md`),
    and a `bulk_rename` is a convention proposal rather than a batch to apply.

    Every heading carries the entry's `ann:` id, so a row in a proposal table
    can cite what it was read from.
    """
    if not LOG.is_file():
        return "# No annotations yet.\n"
    rows = []
    for line in LOG.read_text().splitlines():
        if not line.strip():
            continue
        r = json.loads(line)
        r["_id"] = annotation_id(line)          # from the raw line, not the dict
        rows.append(r)
    notes = [r for r in rows if r.get("kind") == "annotate" and r.get("text")]
    typed = [r for r in rows if r.get("kind") in ("rename", "bulk_rename")
             and r.get("renames")]
    out = ["# What the game is doing, as described at the screen",
           "",
           f"{len(notes)} description(s) and {len(typed)} typed-name entr"
           f"{'y' if len(typed) == 1 else 'ies'} from the VM debugger, in the",
           "order they were made. Each was typed while looking at the frame it",
           "names. The `ann:` id on a heading is the sha1 of that log line: cite",
           "it as `annot:<id>` in a proposal table's evidence cell, and see",
           "`notes/play-and-describe/README.md` for what to do with it.",
           ""]
    by_stage: dict[str, dict[str, list]] = {}
    for bucket, group in (("notes", notes), ("typed", typed)):
        for r in group:
            key = f"{r.get('branch')}/{r.get('stage')}"
            by_stage.setdefault(key, {"notes": [], "typed": []})[bucket].append(r)
    for key, slot in by_stage.items():
        out += [f"## {key}", ""]
        for r in slot["notes"]:
            tgt = r.get("target") or {}
            name = tgt.get("name") or "?"
            off = tgt.get("offset")
            offs = f"0x{off:04X}" if isinstance(off, int) else "?"
            out.append(f"### {name}  ({offs}, frame {r.get('frame')})"
                       f"  {r['_id']}")
            if r.get("routine"):
                out.append(f"drawn by `{r['routine']}`")
            out += ["", r["text"], ""]
            others = [d.get("name") for d in (r.get("on_screen") or [])
                      if d.get("name") and d.get("offset") != off]
            if others:
                out += ["on screen with it: " + ", ".join(
                    f"`{n}`" for n in dict.fromkeys(others)), ""]
            sib = [d.get("name") for d in (r.get("routine_draws") or [])]
            if sib:
                out += ["the same routine also draws: " + ", ".join(
                    f"`{n}`" for n in dict.fromkeys(sib)), ""]
        if not slot["typed"]:
            continue
        out += ["### names typed into the box", "",
                "Proposals with no stated grounds -- the form takes a name, not",
                "a sentence -- so none of these is above `low` on its own, and a",
                "`bulk_rename` is a convention proposal for the owner rather",
                "than a batch to apply. Same queue as the descriptions.", ""]
        for r in slot["typed"]:
            head = f"**{r['_id']}**  frame {r.get('frame')}"
            if r.get("kind") == "bulk_rename":
                head += (f", bulk `{r.get('pattern')}` -> "
                         f"`{r.get('replacement')}`")
            out += [head, ""]
            for row in r.get("renames") or []:
                off = row.get("offset")
                offs = f"0x{off:04X}" if isinstance(off, int) else "?"
                bank = "CV " if row.get("kind") == "video2" else ""
                out.append(f"- `{row.get('from')}` -> `{row.get('to')}`"
                           f"  ({bank}{offs})")
            out.append("")
    return "\n".join(out) + "\n"


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
            out = names_for(branch, stage)
            port = BRANCH_PORT.get(branch)
            rom = self.romsets / (port or "") / "romset" / "bytecode.rom"
            addrs = label_addresses(branch, stage,
                                    rom.read_bytes() if rom.is_file() else b"")
            out["labels"] = addrs
            out["by_address"] = {str(a): n for n, a in
                                 sorted(addrs.items(), key=lambda kv: -kv[1])}
            return self._json(out)
        if path == "/api/config":
            return self._json({
                "branches": {b: p for b, p in BRANCH_PORT.items()
                             if (self.romsets / p / "romset"
                                 / "cinematic.rom").is_file()},
                "stages": STAGE_ID,
                "romsets": str(self.romsets),
            })
        if path == "/api/guidance":
            return self._send(200, guidance().encode(),
                              "text/plain; charset=utf-8")
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
        kind = payload.get("kind", "rename")
        rows = payload.get("renames") or []
        text = (payload.get("text") or "").strip()
        if kind == "annotate" and not text:
            return self._json({"error": "an annotation needs text"}, 400)
        if kind != "annotate" and not rows:
            return self._json({"error": "no renames in payload"}, 400)
        entry = {
            "at": time.strftime("%Y-%m-%dT%H:%M:%S%z"),
            "kind": kind,
            "branch": payload.get("branch"),
            "stage": payload.get("stage"),
            "frame": payload.get("frame"),
            # what the human was pointing at, and what else was on screen with
            # it -- the context an agent needs to find the rest of the sequence
            "target": payload.get("target"),
            "routine": payload.get("routine"),
            "routine_draws": payload.get("routine_draws"),
            "on_screen": payload.get("on_screen"),
            "text": text,
            "pattern": payload.get("pattern"),
            "replacement": payload.get("replacement"),
            "renames": rows,
        }
        # The id is the sha1 of the whole line, so it cannot be stored *in*
        # the entry without circularity. Compute it from the bytes just
        # written, hand it back, and print it: the person at the screen can
        # then quote `ann:<id>` at an agent without opening the log.
        line = json.dumps(entry)
        # An id is the sha1 of the line, so the same line twice is one id
        # twice -- and the log is append-only, which makes that unfixable
        # afterwards. Reachable without trying: `at` has one-second resolution
        # and the Save handlers are async with no button disable, so a
        # double-click inside one second posts the identical payload. Refuse it
        # here, where it can still be refused.
        if LOG.is_file():
            prev = LOG.read_text().rstrip("\n").rsplit("\n", 1)[-1]
            if prev == line:
                return self._json({"ok": False, "kind": kind,
                                   "error": "identical to the last entry; "
                                            "not appended"}, code=409)
        with LOG.open("a") as fh:
            fh.write(line + "\n")
        aid = annotation_id(line)
        sys.stderr.write(f"queued {aid} -- python3 notes/play-and-describe/"
                         f"annotation_queue.py --id {aid} --measure\n")
        return self._json({"ok": True, "kind": kind, "id": aid,
                           "logged": len(rows) or 1, "at": entry["at"]})

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
    ap.add_argument("--export", action="store_true",
                    help="print the annotation log as one readable document "
                         "and exit -- what /api/guidance serves")
    ap.add_argument("--dump", nargs=2, metavar=("BRANCH", "STAGE"),
                    help="print the names+labels JSON for one stage and exit, "
                         "which is what tests/check_label_addresses.mjs reads")
    args = ap.parse_args()
    Handler.romsets = Path(args.romsets).resolve()
    if args.export:
        print(guidance(), end="")
        return 0
    if args.dump:
        branch, stage = args.dump
        out = names_for(branch, stage)
        rp = Handler.romsets / (BRANCH_PORT.get(branch) or "") / "romset" / "bytecode.rom"
        out["labels"] = label_addresses(branch, stage,
                                        rp.read_bytes() if rp.is_file() else b"")
        print(json.dumps(out))
        return 0
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
