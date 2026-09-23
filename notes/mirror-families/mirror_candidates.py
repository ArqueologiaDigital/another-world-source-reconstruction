#!/usr/bin/env python3
"""A run of numbered art that measures like a named family is its mirror.

Question answered
-----------------
`canonical_md5` finds art that is *the same*. It cannot find art that is the
same **reflected**, and a reflection is the commonest thing a stage holds twice:
every walk, every aim, every death has a left and a right, and again and again
one of the two was named and the other left numbered.

A mirrored frame is not the same polygon tree, but it is the same drawing turned
over, so it keeps two properties exactly:

  * the **leaf count** -- reflecting changes no polygon's existence;
  * the **height**, and the width to within the half-pixel the renderer's
    rounding can move.

So: for every still-numbered constant, look for named constants in the same
stage and port with the same leaf count and an extent within tolerance. Report
the ones where a **run** of consecutive numbered constants matches a **run** of
one named family's members, because that is a mirrored family and not a
coincidence of size.

What it found
-------------
Run on 2026-09-23, after the batches that had already been done by hand:
`CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F2..F6` against `CINEMATIC_645..649`, five
frames, exact on every leaf count and every height. The routines confirmed it --
`LABEL_2551` is `LABEL_24CF` with every `sub [HERO_X]` an `add [HERO_X]` -- and
the same run turned up an eighth frame the left family had been missing.

The four-way death families (`HERO_DEATH_{STANDING,KNEELING}_{LEFT,RIGHT}`) and
the beam-span rungs were found the same way by hand before this existed.

What it is not
--------------
Proof. Two figures of the same build measure alike, and a run of three is a
weaker claim than a run of seven. The routine is what settles it: a mirror
family is drawn by a routine that is the other one with its x steps negated, and
that is cheap to check once the probe says where to look.

Usage
-----
    python3 notes/mirror-families/mirror_candidates.py
    python3 notes/mirror-families/mirror_candidates.py --port msdos --stage CAPSULE
    python3 notes/mirror-families/mirror_candidates.py --min-run 2
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
RE_NUM = re.compile(r"^CINEMATIC_(\d+)$")
RE_FAM = re.compile(r"^(CINEMATIC_\w+?)_F?(\d+)$")
TOL = 1.0


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", action="append", choices=sorted(BRANCH))
    ap.add_argument("--stage", action="append", choices=sorted(STAGE_ID))
    ap.add_argument("--min-run", type=int, default=3)
    ap.add_argument("--min-leaf", type=int, default=4)
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
            slab = data[STAGE_ID[stage] * SLAB:(STAGE_ID[stage] + 1) * SLAB]
            meas = {}
            for line in asm.read_text(errors="replace").splitlines():
                m = RE_EQU.match(line)
                if not m:
                    continue
                t = parse_polygon_tree(slab, int(m.group(2), 16))
                if not t:
                    continue
                a = extent(t)
                if a[4] < args.min_leaf:
                    continue
                meas[m.group(1)] = (a[4], a[2] - a[0], a[3] - a[1])

            numbered = sorted((int(RE_NUM.match(n).group(1)), n)
                              for n in meas if RE_NUM.match(n))
            named = [n for n in meas if not RE_NUM.match(n)]
            # numbered constant -> the family members it measures like
            hit = collections.defaultdict(list)
            for _, n in numbered:
                lf, w, h = meas[n]
                for o in named:
                    lo, wo, ho = meas[o]
                    if lo == lf and abs(wo - w) <= TOL and abs(ho - h) <= TOL:
                        m = RE_FAM.match(o)
                        if m:
                            hit[n].append((m.group(1), int(m.group(2)), o))
            # a run: consecutive numbers whose hits are consecutive members
            runs, cur = [], []
            for i, (num, n) in enumerate(numbered):
                fams = {f for f, _, _ in hit.get(n, [])}
                if not fams:
                    if len(cur) >= args.min_run:
                        runs.append(cur)
                    cur = []
                    continue
                if cur:
                    pnum, pn, pfam = cur[-1]
                    if num == pnum + 1 and (fams & pfam):
                        cur.append((num, n, fams))
                        continue
                    if len(cur) >= args.min_run:
                        runs.append(cur)
                cur = [(num, n, fams)]
            if len(cur) >= args.min_run:
                runs.append(cur)
            if not runs:
                continue
            print(f"\n=== {port}/{stage}")
            for run in runs:
                fam = set.intersection(*[f for _, _, f in run])
                for f in sorted(fam):
                    print(f"  {f}_*")
                    for num, n, _ in run:
                        idx = [i for g, i, _ in hit[n] if g == f]
                        lf, w, h = meas[n]
                        print(f"      {n:<16} {w:7.1f}x{h:<7.1f} {lf:3d} leaf"
                              f"   <-> {f}_{idx[0] if idx else '?'}")
                    total += len(run)
    print(f"\n{total} numbered constant(s) sit in a run of at least "
          f"{args.min_run} that measures\nlike a run of one named family. "
          "The routine settles it: a mirror family is drawn by\nthe other "
          "family's routine with its x steps negated.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
