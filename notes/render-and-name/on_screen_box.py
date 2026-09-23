#!/usr/bin/env python3
"""Where does this picture actually land, at each of its draw sites?

Question answered
-----------------
`compose_run.py` reports the box the renderer draws, and the renderer places
every polygon at its own default anchor, **(160, 100)**. A `video` instruction
places it somewhere else. Those are not the same question, and confusing them
is easy: on first reading, `CINEMATIC_543` drawn at `x=357` and
`CINEMATIC_112` drawn at `y=-9` both looked as though they fell off the page
entirely, and the conclusion drawn from that -- that they are never visible --
was wrong.

The rule is one line. A polygon's rendered box is relative to (160, 100), so
its on-screen box at a draw site is that box translated by
`(draw_x - 160, draw_y - 100)`. It is **not** centred on the draw position:
the offset from the anchor is part of the art and is usually not symmetric.
`CINEMATIC_543` renders at x[87.0, 136.0] and is drawn at x=357, so it lands at
x[284.0, 333.0] -- straddling the right edge, mostly visible, not gone.

This also depends on the coordinates being read as signed
(`../coordinate-signedness/`), which is why this tool does that conversion
itself rather than trusting the listing's decimal.

What it prints
--------------
Per draw site: the instruction, the translated box, and whether it lands inside
a 320x200 page, straddles an edge, or misses entirely. A site with a variable
coordinate is reported as such and not guessed at.

Run it
------
Render the stage first at the palette `palette_in_force.py` reports, then:

    python3 notes/render-and-name/on_screen_box.py --renders <dir> \\
        --branch chahi_amiga_1991 --stage INTRO --const CINEMATIC_112
    python3 notes/render-and-name/on_screen_box.py ... --const CINEMATIC_543
"""
from __future__ import annotations

import argparse
import pathlib
import re

SRC = pathlib.Path(__file__).resolve().parents[2] / "src" / "levels"
ANCHOR_X, ANCHOR_Y = 160.0, 100.0
PAGE_W, PAGE_H = 320.0, 200.0

RE_PT = re.compile(r"(-?[\d.]+)\s+(-?[\d.]+)")
RE_PATH = re.compile(r'<path fill="[^"]*" d="([^"]*)"')
RE_EQU = re.compile(r"^(CINEMATIC_[A-Za-z0-9_]+)\s+EQU\s+(0x[0-9A-Fa-f]+)\s*$", re.M)


def signed(v: int) -> int:
    return v - 0x10000 if v >= 0x8000 else v


def rendered_box(renders: pathlib.Path, off: int):
    hits = list(renders.glob(f"*_0x{off:04X}.svg"))
    if not hits:
        return None
    pts = [(float(a), float(b))
           for d in RE_PATH.findall(hits[0].read_text())
           for a, b in RE_PT.findall(d)]
    if not pts:
        return None
    xs = [p[0] for p in pts]
    ys = [p[1] for p in pts]
    return min(xs), max(xs), min(ys), max(ys)


def verdict(x0, x1, y0, y1) -> str:
    if x1 < 0 or x0 > PAGE_W or y1 < 0 or y0 > PAGE_H:
        return "OFF PAGE entirely"
    if x0 < 0 or x1 > PAGE_W or y0 < 0 or y1 > PAGE_H:
        return "straddles an edge"
    return "fully on page"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--renders", type=pathlib.Path, required=True)
    ap.add_argument("--branch", default="chahi_amiga_1991")
    ap.add_argument("--stage", default="INTRO")
    ap.add_argument("--const", required=True)
    args = ap.parse_args()

    asm = SRC / args.branch / f"{args.stage}.asm"
    text = asm.read_text()
    equ = {n: int(v, 16) for n, v in RE_EQU.findall(text)}
    if args.const not in equ:
        raise SystemExit(f"{args.const} is not defined in {args.branch}/{args.stage}")
    off = equ[args.const]

    box = rendered_box(args.renders, off)
    if box is None:
        raise SystemExit(f"no render for 0x{off:04X} in {args.renders}")
    rx0, rx1, ry0, ry1 = box
    print(f"  {args.const}  EQU 0x{off:04X}")
    print(f"      rendered at the default anchor ({ANCHOR_X:.0f}, {ANCHOR_Y:.0f}): "
          f"x[{rx0:.1f}, {rx1:.1f}] y[{ry0:.1f}, {ry1:.1f}]")
    print(f"      so its offset from the anchor is "
          f"x[{rx0 - ANCHOR_X:+.1f}, {rx1 - ANCHOR_X:+.1f}] "
          f"y[{ry0 - ANCHOR_Y:+.1f}, {ry1 - ANCHOR_Y:+.1f}]\n")

    pat = re.compile(rf"video offset={re.escape(args.const)},\s*x=(-?\d+|\[[^\]]+\]),"
                     rf"\s*y=(-?\d+|\[[^\]]+\])([^\n]*)")
    sites = pat.findall(text)
    if not sites:
        print("      never drawn in this branch/stage")
        return 0
    print(f"      {len(sites)} draw site(s):")
    for x, y, rest in sites:
        if x.startswith("[") or y.startswith("["):
            print(f"        x={x:<9} y={y:<9}{rest}   -- variable, not resolved here")
            continue
        dx, dy = signed(int(x)), signed(int(y))
        X0, X1 = rx0 + dx - ANCHOR_X, rx1 + dx - ANCHOR_X
        Y0, Y1 = ry0 + dy - ANCHOR_Y, ry1 + dy - ANCHOR_Y
        note = f"  (y={y} reads as {dy})" if int(y) >= 0x8000 else ""
        print(f"        x={dx:<6} y={dy:<6}{rest}  ->  "
              f"x[{X0:7.1f}, {X1:7.1f}] y[{Y0:7.1f}, {Y1:7.1f}]  {verdict(X0, X1, Y0, Y1)}{note}")
    print("\n      The rendered box is relative to the anchor, NOT centred on the")
    print("      draw position. Translating it is the whole calculation.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
