#!/usr/bin/env python3
"""Which still-numbered pictures are scenery kit pieces, and how big is each?

Question answered
-----------------
`notes/remaining-art/by_anchor.py` puts 1,152 distinct still-numbered pictures
in the "fixed literal x, y" class and records that it is the one class with no
method -- it cannot be named from its coordinates (`docs/NAMING.md` §1) and
there is no actor slot to hang it on.

There is a method, and it is a counting one. A scenery picture that the stage
*dresses with* is placed many times by many routines: CAVES' stalactites are
placed 61 times by eighteen routines between them. A picture placed **once** by
**one** routine, at `160, 100`, is that routine's backdrop layer instead.

    one placement by one routine   -> a layer, named from its screen
    many placements by many        -> a kit piece, named from its construction

This lists the second kind, with everything a name needs: how many placements,
how many routines, the leaf count, and the extent -- so a family can be indexed
on increasing size the way `CAVES_FALLING_ROCK_{SMALL,MEDIUM,LARGE}` was.

What it deliberately does not do
--------------------------------
Name anything. Two constants of the same leaf count and similar size are only
*candidates* to be one family; whether they are wants a composite, which is
`../render-and-name/compose_run.py` and the eye. This narrows 1,152 to the ones
where that is worth doing and says which to look at together.

Usage
-----
    python3 notes/scenery-kit/kit_pieces.py
    python3 notes/scenery-kit/kit_pieces.py --port amiga --stage CAVES
    python3 notes/scenery-kit/kit_pieces.py --min-placements 8 --min-routines 4
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT.parent / "another-world-archaeology" / "tools"))
from _paths import REPO_ROOT                        # noqa: E402
from polygon_tree import parse_polygon_tree         # noqa: E402
from polygon_extent import extent                   # noqa: E402

BRANCH = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGE_ID = {"CODE_WHEEL": 0, "INTRO": 1, "LAKE": 2, "PRISON": 3, "CAVES": 4,
            "TANK": 5, "CAPSULE": 6, "ENDING": 7, "PASSCODE": 8}
SLAB = 0x10000
RE_EQU = re.compile(r"^(CINEMATIC_\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)")
RE_LBL = re.compile(r"^(\w+):")
RE_FIXED = re.compile(r"^\s*video offset=(CINEMATIC_\d+), x=(-?\d+), y=(-?\d+)")
RE_ANY = re.compile(r"^\s*video offset=(CINEMATIC_\d+)\b")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", action="append", choices=sorted(BRANCH))
    ap.add_argument("--stage", action="append", choices=sorted(STAGE_ID))
    ap.add_argument("--min-placements", type=int, default=5)
    ap.add_argument("--min-routines", type=int, default=3)
    args = ap.parse_args()

    total = 0
    for port in (args.port or sorted(BRANCH)):
        for stage in (args.stage or sorted(STAGE_ID, key=STAGE_ID.get)):
            asm = ROOT / "src" / "levels" / BRANCH[port] / f"{stage}.asm"
            if not asm.is_file():
                continue
            text = asm.read_text(errors="replace")
            equ = {m.group(1): int(m.group(2), 16)
                   for m in map(RE_EQU.match, text.splitlines()) if m}
            lab = None
            fixed = collections.Counter()
            routines = collections.defaultdict(set)
            anywhere = collections.Counter()
            for line in text.splitlines():
                m = RE_LBL.match(line)
                if m:
                    lab = m.group(1)
                    continue
                m = RE_ANY.match(line)
                if m:
                    anywhere[m.group(1)] += 1
                m = RE_FIXED.match(line)
                if m:
                    fixed[m.group(1)] += 1
                    routines[m.group(1)].add(lab)
            rom = (REPO_ROOT / "tmp" / "output" / port / "romset"
                   / "cinematic.rom")
            if not rom.is_file():
                sys.exit(f"missing {rom} -- run `make extract`")
            slab = rom.read_bytes()[STAGE_ID[stage] * SLAB:
                                    (STAGE_ID[stage] + 1) * SLAB]
            rows = []
            for name, n in fixed.items():
                # every placement must be a fixed literal one, or it is not
                # pure scenery and something else owns the picture
                if n != anywhere[name] or n < args.min_placements:
                    continue
                if len(routines[name]) < args.min_routines:
                    continue
                t = parse_polygon_tree(slab, equ[name])
                if not t:
                    continue
                a = extent(t)
                rows.append((a[4], a[2] - a[0], a[3] - a[1], name, n,
                             len(routines[name])))
            if not rows:
                continue
            print(f"\n=== {port}/{stage}   {len(rows)} kit piece(s)")
            for leaf, w, h, name, n, r in sorted(rows):
                print(f"  {leaf:3d} leaf  {w:7.1f}x{h:<7.1f} {name:<16} "
                      f"{n:3d} placement(s) in {r:2d} routine(s)")
            total += len(rows)
    print(f"\n{total} still-numbered picture(s) are placed at least "
          f"{args.min_placements} times\nby at least {args.min_routines} "
          f"routines, always at fixed literal coordinates.")
    print("Same leaf count and neighbouring sizes is a candidate family. "
          "Composite before naming.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
