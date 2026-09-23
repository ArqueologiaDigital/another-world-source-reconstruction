#!/usr/bin/env python3
"""Contact sheets of still-numbered art, with its draw context on every tile.

Question answered
-----------------
Every structural method in `notes/` is exhausted: `../cross-port-art/`,
`../backdrop-drawer/ --layers`, `../shared-bank-geometry/mirror_exact.py`,
`../scene-reading/composed_of.py` and the rest all propose 0. What is left
needs someone to look at the art and say what it is, which `docs/NAMING.md`
grade E3 has always asked for -- "render the polygon and look at it before
naming it".

This is the looking tool. It renders every still-numbered picture in a stage
that is big enough to read, biggest first, and puts on each tile the three
things that keep the eye honest:

* the **measured extent and path count**, because this project has three
  recorded wrong readings from judging a magnified thumbnail -- a 1x12 speck
  read as a "band", a gun barrel read off a scaled render. A 4x2 glyph blown
  up to fill a tile looks like a mushroom. The numbers say it is four pixels
  wide.
* **how many times it is drawn and at what screen y**, which is independent
  of the picture. A 12x30 shape that tapers upward and is drawn four times at
  y=165 is standing on the floor; the same shape drawn at y=20 is hanging
  from the ceiling. The draw position decides between readings the silhouette
  cannot.
* the **routines that draw it**, since a named one narrows the subject before
  the picture is even seen.

Names derived this way carry `medium` confidence and say so in their evidence
column. The byte gate cannot catch a wrong name -- a rename moves no bytes --
so these are the one class of name in the tree with no independent check
behind them, and `../render-and-name/README.md` lists every one so they can
be audited or reverted as a group.

Usage
-----
    python3 notes/render-and-name/sheet.py --stage CAVES --renders <dir> \\
        --out <dir> --min 24 --per-sheet 12
    python3 notes/render-and-name/sheet.py --stage CAVES --list

Producing the renders (regenerable, not committed):

    cd AnotherWorld_VMTools
    cargo run --quiet --bin awvm-render-polygons -- \\
      --port amiga --stage 4 \\
      --romset ../another-world-archaeology/tmp/output/amiga/romset \\
      --bank cinematic --out <render-dir> --palette 0
"""

from __future__ import annotations

import argparse
import collections
import re
import subprocess
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(SRC / "notes" / "polygon-extent-correction"))
sys.path.insert(0, str(SRC.parent / "another-world-archaeology" / "tools"))
from polygon_tree import parse_polygon_tree                  # noqa: E402
from polygon_extent import extent                            # noqa: E402
from extent_matches_renderer import slab                     # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGE_ID = {"PRISON": 3, "CAVES": 4, "CAPSULE": 6}
RE_NUM = re.compile(r"^CINEMATIC_\d+$")
RE_EQU = re.compile(r"^(CINEMATIC_[A-Za-z0-9_]+)\s+EQU\s+(0x[0-9A-Fa-f]+)",
                    re.M)
RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
RE_V = re.compile(r"^\s*video\s+(?:type=\d+,\s*)?offset=([A-Za-z_]\w*),"
                  r"\s*x=([^,]+),\s*y=([^,\s]+)")
PH = re.compile(r"^(LABEL_|JUNK__|RET_TARGET_|ADDR_AT_|KILL_CHAN_AT_)")


def load(port: str, stage: str):
    f = SRC / "src" / "levels" / PORTS[port] / f"{stage}.asm"
    txt = f.read_text(errors="replace")
    equ = {n: int(v, 16) for n, v in RE_EQU.findall(txt)}
    sites: dict[str, list] = collections.defaultdict(list)
    cur = None
    for line in txt.splitlines():
        m = RE_LBL.match(line)
        if m:
            cur = m.group(1)
            continue
        v = RE_V.match(line)
        if v:
            sites[v.group(1)].append((cur, v.group(2).strip(),
                                      v.group(3).strip()))
    return equ, sites


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--stage", required=True, choices=sorted(STAGE_ID))
    ap.add_argument("--port", default="amiga", choices=sorted(PORTS))
    ap.add_argument("--renders", type=Path)
    ap.add_argument("--out", type=Path)
    ap.add_argument("--min", type=int, default=24)
    ap.add_argument("--per-sheet", type=int, default=12)
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--only", help="comma-separated constants")
    args = ap.parse_args()

    equ, sites = load(args.port, args.stage)
    bank = slab("cinematic", args.port, STAGE_ID[args.stage])
    rows = []
    for n, o in equ.items():
        if not RE_NUM.match(n):
            continue
        try:
            x0, y0, x1, y1, lv = extent(parse_polygon_tree(bank, o))
        except Exception:
            continue
        w, h = x1 - x0, y1 - y0
        if w < args.min or h < args.min:
            continue
        s = sites.get(n, [])
        ys = sorted({int(y) for _l, _x, y in s if y.isdigit()})
        labs = sorted({l for l, _x, _y in s if l and not PH.match(l)})
        rows.append({"n": n, "o": o, "w": w, "h": h, "lv": lv,
                     "draws": len(s), "ys": ys, "labs": labs})
    rows.sort(key=lambda r: -(r["w"] * r["h"]))
    if args.only:
        keep = set(args.only.split(","))
        rows = [r for r in rows if r["n"] in keep]

    if args.list or not args.renders:
        print(f"  {len(rows)} still-numbered picture(s) at least "
              f"{args.min}x{args.min} in {args.port}/{args.stage}\n")
        for r in rows[:60]:
            y = (f"y {r['ys'][0]}" if len(r["ys"]) == 1
                 else f"y {r['ys'][0]}..{r['ys'][-1]}" if r["ys"] else "y var")
            print(f"  {r['n']:<16}{r['w']:6.0f}x{r['h']:<6.0f}/{r['lv']:<4}"
                  f"{r['draws']:>3} draw(s)  {y:<12}{', '.join(r['labs'][:2])}")
        return 0

    args.out.mkdir(parents=True, exist_ok=True)
    made = 0
    for start in range(0, len(rows), args.per_sheet):
        chunk = rows[start:start + args.per_sheet]
        tiles = []
        tmp = args.out / f"_tiles{start}"
        tmp.mkdir(exist_ok=True)
        for r in chunk:
            svg = list(args.renders.glob(f"*_0x{r['o']:04X}.svg"))
            if not svg:
                continue
            y = (f"y{r['ys'][0]}" if len(r["ys"]) == 1
                 else f"y{r['ys'][0]}-{r['ys'][-1]}" if r["ys"] else "y?")
            cap = (f"{r['n']}  {r['w']:.0f}x{r['h']:.0f}/{r['lv']}  "
                   f"{r['draws']}x {y}")
            if r["labs"]:
                cap += f"\\n{r['labs'][0][:44]}"
            t = tmp / f"{r['o']:04X}.png"
            subprocess.run(
                ["convert", "-background", "#999999", str(svg[0]),
                 "-trim", "+repage", "-resize", "300x300",
                 "-bordercolor", "#999999", "-border", "6",
                 "-background", "#222222", "-fill", "white",
                 "-pointsize", "14", f"label:{cap}",
                 "-gravity", "center", "-append", str(t)], check=False)
            if t.is_file():
                tiles.append(str(t))
        if not tiles:
            continue
        out = args.out / f"{args.port}_{args.stage}_{start:03d}.png"
        subprocess.run(["montage", "-tile", "4x", "-geometry", "+5+5",
                        "-background", "#111111", *tiles, str(out)],
                       check=False)
        made += 1
        print(f"  {out}  ({len(tiles)} tiles)")
    print(f"\n  {made} sheet(s) over {len(rows)} picture(s)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
