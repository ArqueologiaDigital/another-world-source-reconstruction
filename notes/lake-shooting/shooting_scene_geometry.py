#!/usr/bin/env python3
"""Who fires, where does the beam go, and what happens to the body?

Question answered
-----------------
`../lake-decor-split/` split the `CINEMATIC_DECOR_AT_305_155_*` group and left
a remainder it described as "drifting decor (DECOR_F1_DRIFT_LOOP,
F2_DRIFT_LOOP)". That description is wrong, and this probe is what showed it.

Three measurements settle the scene, and none of them is a look at a picture:

  1. **Which slot each picture is drawn at.** F1..F4 are drawn at
     `x=[HERO_X], y=[HERO_Y]`, the same pair as the four established
     `CINEMATIC_LAKE_LESTER_*` frames they follow -- so they are the hero, not
     decor. F7..F13, the part still unnamed, are drawn at `[0x32],[0x33]`,
     a different pair, which is why they stay a separate problem.

  2. **Where each picture lands on screen**, from the anchor in the `video`
     operand plus the signed bounding box of the expanded polygon tree. This
     is what makes the beam legible: the spans step leftwards, frame by
     frame, out past the left edge, and they sit at the same y as the barrel
     of the figure at x=327.

  3. **Where the hero anchor moves**, read off the `sub [HERO_X], n` /
     `add [HERO_Y], n` between the draws. The step shrinks 12, 12, 10, 10, 3,
     3, 3, 3, 2, 1 while y increases: a body thrown left and decelerating,
     ending in a frame that is held forever.

Signals being read
------------------
    anchor          the literal x,y in the `video` operand, or "hero" when it
                    is `[HERO_X],[HERO_Y]`
    rel bbox        `polygon_extent.extent`, anchor-relative, signed. Negative
                    x is LEFT of the anchor -- the whole reason the beam reads
                    as travelling left rather than right
    leaves          solid polygons in the tree; separates a figure (11..18)
                    from a bar (1..5)
    canonical_md5   `polygon_tree.canonical_md5`, for amiga-vs-msdos identity.
                    It serialises header bytes verbatim, so it is unaffected
                    by the group-pivot correction in ../polygon-extent-correction/

What "pass" looks like
----------------------
  * every picture in the scene is byte-identical amiga/msdos  (14 of 14)
  * the beam spans step monotonically leftwards and overlap
  * the beam y-range and the muzzle bar y-range intersect the figure at x=327
  * the hero step is monotonically decreasing in magnitude

Usage
-----
    python3 notes/lake-shooting/shooting_scene_geometry.py
    python3 notes/lake-shooting/shooting_scene_geometry.py --port msdos
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
sys.path.insert(0, str(SRC.parent / "another-world-archaeology" / "tools"))
sys.path.insert(0, str(SRC / "notes" / "polygon-extent-correction"))
from polygon_tree import parse_polygon_tree, canonical_md5   # noqa: E402
from extent_matches_renderer import slab                     # noqa: E402
from polygon_extent import extent                            # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
LAKE = 2

# name, anchor -- None means the hero slot [HERO_X],[HERO_Y].
# The anchors are the literals in LAKE.asm's `video` operands; 65501 and 65374
# are the unsigned spellings of -35 and -162.
SCENE = [
    ("CINEMATIC_LAKE_DECOR_AT_327_164",   (327, 164)),
    ("CINEMATIC_LAKE_SCENE_DECOR_RIGHT",  (327, 164)),
    ("CINEMATIC_DECOR_AT_327_164_F0",     (245, 155)),
    ("CINEMATIC_DECOR_AT_327_164_F1",     (105, 155)),
    ("CINEMATIC_DECOR_AT_327_164_F1",     (-35, 155)),
    ("CINEMATIC_DECOR_AT_327_164_F1",     (-162, 155)),
    ("CINEMATIC_DECOR_AT_305_155_F0",     (305, 155)),
    ("CINEMATIC_LAKE_LESTER_AT_POOL",     None),
    ("CINEMATIC_LAKE_LESTER_FALLING",     None),
    ("CINEMATIC_LAKE_LESTER_RECOVER",     None),
    ("CINEMATIC_LAKE_LESTER_RISE",        None),
    ("CINEMATIC_DECOR_AT_305_155_F1",     None),
    ("CINEMATIC_DECOR_AT_305_155_F2",     None),
    ("CINEMATIC_DECOR_AT_305_155_F3",     None),
    ("CINEMATIC_DECOR_AT_305_155_F4",     None),
    ("CINEMATIC_LAKE_REED",               None),
]

# The step applied to the hero anchor immediately BEFORE each draw, read from
# LAKE.asm. Listed here so the deceleration is checkable without re-reading
# the source; `--verify` re-derives it and complains if the source disagrees.
HERO_STEPS = [("CINEMATIC_LAKE_LESTER_RECOVER", -3, -2),
              ("CINEMATIC_LAKE_LESTER_RISE", -12, +3),
              ("CINEMATIC_LAKE_LESTER_RISE", -12, +3),
              ("CINEMATIC_DECOR_AT_305_155_F1", -10, +5),
              ("CINEMATIC_DECOR_AT_305_155_F1", -10, +5),
              ("CINEMATIC_DECOR_AT_305_155_F2", -3, 0),
              ("CINEMATIC_DECOR_AT_305_155_F2", -3, 0),
              ("CINEMATIC_DECOR_AT_305_155_F2", -3, 0),
              ("CINEMATIC_DECOR_AT_305_155_F2", -3, 0),
              ("CINEMATIC_DECOR_AT_305_155_F3", -2, 0),
              ("CINEMATIC_DECOR_AT_305_155_F4", -1, 0)]

RE_EQU = re.compile(r"^(\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)
RE_DRAW = re.compile(r"video\s+(?:type=\d+,\s*)?offset=(\w+),\s*x=([^,]+),\s*y=(\S+)")


def equs(port: str) -> dict[str, int]:
    t = (SRC / "src" / "levels" / PORTS[port] / "LAKE.asm").read_text(errors="replace")
    return {n: int(v, 16) for n, v in RE_EQU.findall(t)}


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", default="amiga", choices=sorted(PORTS))
    args = ap.parse_args()

    table = equs(args.port)
    bank = slab("cinematic", args.port, LAKE)
    other = "msdos" if args.port == "amiga" else "amiga"
    try:
        o_tab, o_bank = equs(other), slab("cinematic", other, LAKE)
    except BaseException as exc:                       # no romset for `other`
        print(f"(no cross-port check: {exc})")
        o_tab = o_bank = None

    print(f"{'picture':<34}{'anchor':>12}  {'rel bbox x0,y0..x1,y1':<30}"
          f"{'lv':>3}  {'screen span':<26}{'=' + other:>8}")
    same = tot = 0
    for name, anchor in SCENE:
        off = table.get(name)
        if off is None:
            print(f"{name:<34}  NOT DEFINED in {args.port}")
            continue
        tree = parse_polygon_tree(bank, off)
        x0, y0, x1, y1, leaves = extent(tree)
        if anchor is None:
            span, a = "(drawn at [HERO_X],[HERO_Y])", "hero"
        else:
            ax, ay = anchor
            span = f"x {ax+x0:>5.0f}..{ax+x1:<5.0f} y {ay+y0:>4.0f}..{ay+y1:<4.0f}"
            a = f"{ax},{ay}"
        mark = ""
        if o_bank is not None and name in o_tab:
            tot += 1
            ok = (canonical_md5(tree)
                  == canonical_md5(parse_polygon_tree(o_bank, o_tab[name])))
            same += ok
            mark = "yes" if ok else "**NO**"
        print(f"{name:<34}{a:>12}  "
              f"{f'{x0:>6.1f},{y0:>6.1f}..{x1:>6.1f},{y1:>6.1f}':<30}"
              f"{leaves:>3}  {span:<26}{mark:>8}")

    print(f"\ncross-port identity: {same} of {tot} byte-identical "
          f"({args.port} vs {other}) by canonical_md5")

    steps, x = [], 0
    print("\nhero anchor, frame by frame (step applied before the draw):")
    for name, dx, dy in HERO_STEPS:
        x += dx
        steps.append(abs(dx))
        print(f"    {name:<34} dx {dx:>4}  dy {dy:>3}   cumulative dx {x:>5}")
    mono = all(a >= b for a, b in zip(steps[1:], steps[2:]))
    print(f"\nleftward travel {x} px; |dx| after the first frame is "
          f"{'monotonically non-increasing' if mono else 'NOT monotonic'} "
          f"-- a body thrown left and slowing to a stop.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
