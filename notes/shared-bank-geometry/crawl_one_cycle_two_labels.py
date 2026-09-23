#!/usr/bin/env python3
"""Why do six crawl pieces claim both LEFT and RIGHT?

Question answered
-----------------
`hero_pose_consensus.py --rejected` reports eight offsets where "sources
disagree", and six of them are the same disagreement:

    CV_4954   CRAWL_LEFT, CRAWL_RIGHT, WALK_RIGHT
    CV_49B0   CRAWL_LEFT, CRAWL_RIGHT, WALK_RIGHT
    ...

A picture cannot face both ways, so one of the claims must be wrong. This
finds out which, and the answer is structural rather than a slip: **CAVES
labels one crawl cycle from both ends.**

The measurement
---------------
For every piece CAVES claims in both directions, take the two phase numbers:

    piece      LEFT  RIGHT   sum
    CV_4954       5     10    15
    CV_49B0       6      9    15
    CV_4A04       7      8    15
    CV_4A6C       8      7    15
    CV_4ACC       9      6    15
    CV_4B4C      10      5    15

Six for six, the sum is **exactly 15**. That is not what two independent
animations look like; it is one sequence indexed forwards as LEFT and
backwards as RIGHT.

The pieces claimed in only one direction fit the same map. LEFT covers 2..10
and RIGHT covers 3, 4; under `right = 15 - left` the LEFT-only pieces would
be RIGHT 13, 12, 11 and the RIGHT-only ones LEFT 12, 11 -- indices neither
label ever uses. Together the two labelings enumerate one cycle of eleven
distinct pictures with no piece left over.

What this does and does not settle
----------------------------------
It settles that the two directions' phase numbers are **not independent
evidence**, so a consensus engine must not treat CAVES/LEFT and CAVES/RIGHT
as two agreeing sources, and the six "disagreements" are one artefact rather
than six problems.

It does **not** settle which labeling is right. Either CAVES's crawl-right
routines really draw this art (and the art is direction-neutral), or they are
mis-labelled and the cycle is left-facing only. Deciding that needs evidence
this probe does not have -- the anchor arithmetic of the routines, or a
render -- and #0120 bars picking between two earned names without it.

Exit status
-----------
1 if any doubly-claimed piece has a sum other than the constant, since the
whole argument rests on that constant.

Usage
-----
    python3 notes/shared-bank-geometry/crawl_one_cycle_two_labels.py
"""
from __future__ import annotations

import collections
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels"
RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
RE_T0 = re.compile(r"video type=0, offset=(CV_[0-9A-F]{4})")
RE_PH = re.compile(r"HERO_CRAWL_(LEFT|RIGHT)_(?:PHASE|DRAW)_(\d+)")


def main() -> int:
    claims: dict = collections.defaultdict(dict)
    for p in SRC.glob("*/CAVES.asm"):
        cur, buf = None, []

        def flush(cur, buf):
            if not cur:
                return
            g = RE_PH.search(cur)
            if not g:
                return
            for line in buf:
                t = RE_T0.search(line)
                if t:
                    claims[t.group(1)][g.group(1)] = int(g.group(2))

        for line in p.read_text(errors="replace").splitlines():
            m = RE_LBL.match(line)
            if m:
                flush(cur, buf)
                cur, buf = m.group(1), []
            elif cur is not None:
                buf.append(line)
        flush(cur, buf)

    if not claims:
        print("no CAVES crawl phase labels found")
        return 0

    print(f"  {'piece':<9}{'LEFT':>6}{'RIGHT':>7}{'sum':>6}")
    sums = []
    for cv in sorted(claims, key=lambda c: int(c[3:], 16)):
        d = claims[cv]
        L, R = d.get("LEFT"), d.get("RIGHT")
        s = L + R if (L is not None and R is not None) else None
        if s is not None:
            sums.append(s)
        print(f"  {cv:<9}{str(L):>6}{str(R):>7}{str(s):>6}")

    both = len(sums)
    uniq = sorted(set(sums))
    print(f"\n{both} piece(s) claimed in both directions; sums {uniq}")
    if not sums:
        print("nothing claimed both ways -- the finding does not apply here.")
        return 0
    if len(uniq) != 1:
        print("The sums are NOT constant, so the two labelings are not a "
              "single cycle counted from both ends, and the note that says "
              "they are needs correcting.")
        return 1
    k = uniq[0]
    print(f"Constant sum {k}: CAVES indexes ONE crawl cycle forwards as LEFT "
          f"and backwards as RIGHT.\nThe two directions are therefore not "
          f"independent sources, and the {both} 'disagreements' the consensus"
          f"\nengine reports for these offsets are one artefact, not "
          f"{both} problems.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
