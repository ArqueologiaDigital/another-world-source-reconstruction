#!/usr/bin/env python3
"""Still-numbered constants that sit together in the bank are one family.

Question answered
-----------------
Every other queue in these notes groups art by what *draws* it: a routine's run
of frames, a dispatcher's slots, a screen's backdrop stack. That misses families
whose frames each get their own one-line routine, because no single routine ever
holds more than one of them.

The bank itself groups them. Art for one animation is laid down together, so a
stretch of consecutive still-numbered constants between two named ones is a
family the naming has not reached -- and when the offsets are an exact stride
apart it is an array the assembler emitted in one go.

    python3 notes/bank-locality/offset_runs.py
    python3 notes/bank-locality/offset_runs.py --port msdos --stage CAPSULE
    python3 notes/bank-locality/offset_runs.py --min-run 8

Per run: the offsets, the stride if it is constant, and each member's extent and
leaf count, so a size ladder or a symmetric pair shows up in the listing itself.

What it found
-------------
PRISON's longest run, fifteen constants at `0x2190 + 0x14k`, is the cage's chain
at fifteen tilt angles -- one dispatch on a **signed** `[0x06]` from +7 to -7,
widths symmetric about zero to the pixel. See
`../render-and-name/proposals_chahi_amiga_1991__PRISON_cage_chain.md`.

Two tells worth carrying:

  * **an unvarying stride** is an array, not a coincidence of layout;
  * **read the sign**: `0xFFFA` is -6, and a dispatch running `0, 1, ... 6,
    0xFFFF, 0xFFFE, ...` is a range centred on zero, not a jump to 65535.
    `../coordinate-signedness/` established the same for `video` operands.

What it is not
--------------
A family. Adjacency is the game's memory layout, not its meaning, and a run can
hold two families end to end or one family plus the odd unrelated picture the
assembler happened to put there. It says where to look and in what company.
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
RE_NUM = re.compile(r"^CINEMATIC_\d+$")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", action="append", choices=sorted(BRANCH))
    ap.add_argument("--stage", action="append", choices=sorted(STAGE_ID))
    ap.add_argument("--min-run", type=int, default=5)
    ap.add_argument("--top", type=int, default=6,
                    help="how many runs per stage to print, longest first")
    args = ap.parse_args()

    total = 0
    for port in (args.port or sorted(BRANCH)):
        rom = REPO_ROOT / "tmp" / "output" / port / "romset" / "cinematic.rom"
        if not rom.is_file():
            sys.exit(f"missing {rom} -- run `make extract`")
        data = rom.read_bytes()
        for stage in (args.stage or sorted(STAGE_ID, key=STAGE_ID.get)):
            asm = ROOT / "src" / "levels" / BRANCH[port] / f"{stage}.asm"
            if not asm.is_file():
                continue
            equ = sorted((int(m.group(2), 16), m.group(1))
                         for m in map(RE_EQU.match,
                                      asm.read_text(errors="replace").splitlines())
                         if m)
            slab = data[STAGE_ID[stage] * SLAB:(STAGE_ID[stage] + 1) * SLAB]
            runs, cur = [], []
            for off, n in equ:
                if RE_NUM.match(n):
                    cur.append((off, n))
                else:
                    if len(cur) >= args.min_run:
                        runs.append(cur)
                    cur = []
            if len(cur) >= args.min_run:
                runs.append(cur)
            if not runs:
                continue
            print(f"\n=== {port}/{stage}   {len(runs)} run(s) of "
                  f"{args.min_run}+")
            for run in sorted(runs, key=len, reverse=True)[:args.top]:
                steps = {b - a for (a, _), (b, _) in zip(run, run[1:])}
                stride = (f"stride 0x{steps.pop():02X}" if len(steps) == 1
                          else f"{len(steps)} different steps")
                print(f"  {len(run)} constant(s)  0x{run[0][0]:04X}.."
                      f"0x{run[-1][0]:04X}  {stride}")
                for off, n in run:
                    t = parse_polygon_tree(slab, off)
                    if not t:
                        print(f"      {n:<16} 0x{off:04X}  (does not parse)")
                        continue
                    a = extent(t)
                    print(f"      {n:<16} 0x{off:04X}  "
                          f"{a[2] - a[0]:7.1f}x{a[3] - a[1]:<7.1f} "
                          f"{a[4]:3d} leaf")
                total += len(run)
    print(f"\n{total} still-numbered constant(s) sit in a contiguous run of "
          f"{args.min_run} or more.\nAdjacency is the memory layout, not the "
          "meaning: it says where to look and in what company.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
