#!/usr/bin/env python3
"""Is a bare `_PHASE_<n>` 0-based or 1-based, and does that follow the stage?

Question answered
-----------------
`hero_pose_consensus.py` accepts several spellings of a frame ordinal
(`_DRAW_<n>`, `_F<n>`, `_POSE_<n>`, `_DRAW_PHASE_<n>`, `_STRIDE_PHASE_<n>`)
and calibrates each stage's base by comparing it against another stage over
the offsets both name. A bare `_PHASE_<n>` is deliberately *not* accepted, and
the actor families have holes exactly where those names sit.

Admitting it is only safe if its base is known. This measures it without
assuming anything about the spelling, by position:

  take the offsets in a family whose index is already trusted and calibrated;
  for a bare-`_PHASE_` offset sitting between a trusted `lo` and a trusted
  `hi` with **exactly one slot between them** (`hi - lo == 2`), its frame must
  be `lo + 1`; the base is then its stated `n` minus that.

Only unambiguous single gaps count, so the measurement never has to guess how
many frames fill a hole.

**It parses with its own regex, not with `hero_pose_consensus.parse_claim`.**
Borrowing that function makes the measurement circular the moment anyone
admits `_PHASE_` there: the names being calibrated become part of the trusted
input, and the probe reports CAVES as using bases 0 *and* 1 -- which is what
happened the first time it was run, immediately after that experiment. The
trusted set must be defined here and be exactly "the spellings this probe is
not measuring".

Result, 2026-09-20
------------------
    CAPSULE/RUN/RIGHT   {0: 3}      CAVES/RUN/RIGHT    {1: 3}
    CAPSULE/WALK/RIGHT  {0: 3}      CAVES/WALK/LEFT    {1: 2}
    PRISON/RUN/RIGHT    {0: 3}      CAVES/WALK/RIGHT   {1: 3}

Unanimous within every stage, and the base **follows the stage, not the
spelling**: CAPSULE and PRISON count from 0, CAVES counts from 1, which is
exactly what their `_DRAW_PHASE_` names already do. So the earlier note
claiming a bare `_PHASE_` used "a third base convention" was wrong, and is
corrected where it was written.

Why the spelling is still not admitted
--------------------------------------
Knowing the base was necessary and is not sufficient. With bare `_PHASE_`
accepted and the base calibrated, `RUN_RIGHT_BODY` comes out as
`0,1,2,3,4,5,6,7,8,8` -- two offsets claiming frame 8 -- and `WALK_LEFT_BODY`
still grows an index 16 inside a 0..15 run. Something about these names is
not a simple re-based frame ordinal, and the sample this probe measures
(single gaps only) is biased towards the easy cases. Until the duplicates are
explained the spelling stays out, and the actor families keep their holes.

Exit status
-----------
0 when every stage's base is unanimous across the families measured; 1 if any
stage yields more than one base, which would mean the spelling is not even
stage-consistent.

Usage
-----
    python3 notes/shared-bank-geometry/phase_base_calibration.py
"""

from __future__ import annotations

import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
sys.path.insert(0, str(HERE.parent))
import hero_pose_consensus as H                      # noqa: E402

RE_BARE = re.compile(r"_PHASE_(\d+)$")
RE_TRUSTED = re.compile(r"_(?:DRAW|F|POSE|DRAW_PHASE|STRIDE_PHASE)_?(\d+)$")


def main() -> int:
    H.SUBJECT[0] = "actor"
    offs, art, by_stage = H.collect()

    raw: dict[tuple, dict] = collections.defaultdict(dict)
    for cv in sorted(art, key=lambda c: offs[c]):
        for stage, routines in sorted(by_stage[cv].items()):
            for r in sorted(routines):
                if "_FOOTSTEP_" in r:
                    continue
                mi = RE_TRUSTED.search(r)
                mm = H.RE_MOTION.search("_" + r + "_")
                if not mi or not mm:
                    continue
                raw[(stage, mm.group(1), mm.group(2))][cv] = int(mi.group(1))

    fams: dict[tuple, list] = collections.defaultdict(list)
    for (stage, m, d) in sorted(raw):
        fams[(m, d)].append(stage)
    shift: dict[tuple, int] = {}
    for (m, d), stages in fams.items():
        ref = min(stages, key=lambda s: (min(raw[(s, m, d)].values()),
                                         -len(raw[(s, m, d)])))
        shift[(ref, m, d)] = 0
        for s in sorted(stages):
            if s == ref:
                continue
            both = set(raw[(s, m, d)]) & set(raw[(ref, m, d)])
            diffs = {raw[(s, m, d)][cv] - raw[(ref, m, d)][cv] for cv in both}
            shift[(s, m, d)] = diffs.pop() if len(diffs) == 1 else 0

    trusted: dict[tuple, dict] = collections.defaultdict(dict)
    for (stage, m, d), mp in raw.items():
        for cv, i in mp.items():
            trusted[(m, d)][cv] = i - shift.get((stage, m, d), 0)

    found: dict[tuple, collections.Counter] = collections.defaultdict(
        collections.Counter)
    for cv in sorted(art, key=lambda c: offs[c]):
        for stage, routines in sorted(by_stage[cv].items()):
            for r in sorted(routines):
                mb = RE_BARE.search(r)
                if not mb or RE_TRUSTED.search(r) or "_FOOTSTEP_" in r:
                    continue
                mm = H.RE_MOTION.search("_" + r + "_")
                if not mm:
                    continue
                m, d = mm.group(1), mm.group(2)
                fam = trusted.get((m, d), {})
                below = [(offs[c], i) for c, i in fam.items()
                         if offs[c] < offs[cv]]
                above = [(offs[c], i) for c, i in fam.items()
                         if offs[c] > offs[cv]]
                if not below or not above:
                    continue
                lo, hi = max(below)[1], min(above)[1]
                if hi - lo != 2:
                    continue
                found[(stage, m, d)][int(mb.group(1)) - (lo + 1)] += 1

    per_stage: dict[str, set] = collections.defaultdict(set)
    print(f"{'stage/motion/direction':<26}"
          f"{'base of a bare _PHASE_<n>':>32}")
    for key in sorted(found):
        print(f"  {'/'.join(key):<24}{str(dict(found[key])):>32}")
        per_stage[key[0]] |= set(found[key])

    print()
    bad = 0
    for stage, bases in sorted(per_stage.items()):
        if len(bases) == 1:
            print(f"  {stage:<10} counts from {bases.pop()}")
        else:
            bad += 1
            print(f"  {stage:<10} INCONSISTENT: {sorted(bases)}")
    if bad:
        print("\nFAIL: the spelling is not even stage-consistent.")
        return 1
    print("\nThe base follows the stage, not the spelling -- the same split "
          "these stages\nalready show in their `_DRAW_PHASE_` names.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
