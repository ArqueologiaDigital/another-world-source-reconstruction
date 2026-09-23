#!/usr/bin/env python3
"""Cut a rendered constant down to the pixels it actually covers.

Question answered
-----------------
`awvm-render-polygons` writes one 320x200 page per constant, anchored where the
engine would draw it -- which for most art is nowhere near the middle. Looking at
those pages directly wastes the whole frame on background and, worse, invites
cropping to the centre and cutting the subject in half. That happened here: a
first look at CAVES' `CINEMATIC_233` cropped to `x[128,194] y[68,140]` and showed
a leg and a shoe, because the figure is at `x[132,168] y[44,100]`.

This reads each rendered SVG's own path coordinates, takes their bounding box,
and writes a tight SVG with a chosen background. Montage those and the run is
legible at a glance.

    python3 notes/render-and-name/crop_to_extent.py --renders DIR --branch B \
        --stage CAVES --out DIR2 CINEMATIC_233 CINEMATIC_234 ...
    magick montage -density 700 -background "#707080" -tile 5x2 -geometry +5+5 \
        DIR2/*.svg out.png

`--over C` stacks the named constants on top of constant C first, at the same
anchor, for the case `../render-and-name/README.md` calls "composite before you
judge a sliver": a one- or two-leaf overlay is unreadable alone and obvious over
the body it is drawn on.

`--at X,Y` offsets each by `(X-160, Y-100)` instead, which is what the engine
does with `video offset=..., x=X, y=Y`, so a scene's pieces land where the
routine puts them.

Nothing here reads the ROM. The renders are the input, which is the rule
`../polygon-extent-correction/` settled: measure the drawn thing, not the tree,
when the question is what it looks like.
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
RE_PATH = re.compile(r'<path[^>]*/>')
RE_PT = re.compile(r"(-?[\d.]+)\s+(-?[\d.]+)")
RE_EQU = re.compile(r"^(CINEMATIC_\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)")
PORT_OF = {"chahi_amiga_1991": "amiga", "dos_1992": "msdos"}
STAGE_ID = {"CODE_WHEEL": 0, "INTRO": 1, "LAKE": 2, "PRISON": 3, "CAVES": 4,
            "TANK": 5, "CAPSULE": 6, "ENDING": 7, "PASSCODE": 8}


def paths_of(renders: Path, port: str, stage: str, off: int):
    pat = f"{port}_stage{STAGE_ID[stage]}_*_0x{off:04X}.svg"
    for p in renders.glob(pat):
        return RE_PATH.findall(p.read_text())
    return []


def shift(ps, dx, dy):
    if dx == 0 and dy == 0:
        return ps
    def mv(m):
        return f"{float(m.group(1)) + dx:.3f} {float(m.group(2)) + dy:.3f}"
    return [RE_PT.sub(mv, p) for p in ps]


def box(ps, pad=2.0):
    xs, ys = [], []
    for p in ps:
        d = p.split(' d="', 1)[1] if ' d="' in p else ""
        for a, b in RE_PT.findall(d):
            xs.append(float(a)); ys.append(float(b))
    if not xs:
        return None
    return min(xs) - pad, min(ys) - pad, max(xs) + pad, max(ys) + pad


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("constants", nargs="+")
    ap.add_argument("--renders", required=True)
    ap.add_argument("--branch", required=True, choices=sorted(PORT_OF))
    ap.add_argument("--stage", required=True, choices=sorted(STAGE_ID))
    ap.add_argument("--out", required=True)
    ap.add_argument("--bg", default="#707080")
    ap.add_argument("--over", help="stack each one over this constant first")
    ap.add_argument("--at", help="X,Y -- place at the engine's anchor instead "
                                 "of cropping each to itself")
    args = ap.parse_args()

    port = PORT_OF[args.branch]
    asm = ROOT / "src" / "levels" / args.branch / f"{args.stage}.asm"
    equ = {m.group(1): int(m.group(2), 16)
           for m in map(RE_EQU.match, asm.read_text(errors="replace").splitlines()) if m}
    renders, out = Path(args.renders), Path(args.out)
    out.mkdir(parents=True, exist_ok=True)
    under = paths_of(renders, port, args.stage, equ[args.over]) if args.over else []
    dx = dy = 0.0
    if args.at:
        x, y = args.at.split(",")
        dx, dy = float(x) - 160.0, float(y) - 100.0

    for name in args.constants:
        if name not in equ:
            print(f"  {name}: not defined in {args.branch}/{args.stage}")
            continue
        ps = under + shift(paths_of(renders, port, args.stage, equ[name]), dx, dy)
        b = box(ps)
        if not b:
            print(f"  {name}: nothing rendered at 0x{equ[name]:04X}")
            continue
        x0, y0, x1, y1 = b
        w, h = x1 - x0, y1 - y0
        svg = ['<?xml version="1.0" encoding="UTF-8"?>',
               f'<svg xmlns="http://www.w3.org/2000/svg" width="{w:.0f}" '
               f'height="{h:.0f}" viewBox="{x0:.0f} {y0:.0f} {w:.0f} {h:.0f}">',
               f'<rect x="{x0:.0f}" y="{y0:.0f}" width="{w:.0f}" '
               f'height="{h:.0f}" fill="{args.bg}"/>'] + ps + ["</svg>"]
        (out / f"{name}.svg").write_text("\n".join(svg))
        print(f"  {name:<44} 0x{equ[name]:04X}  {w:6.1f}x{h:<6.1f} -> "
              f"{out / (name + '.svg')}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
