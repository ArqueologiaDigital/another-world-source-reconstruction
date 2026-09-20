#!/usr/bin/env python3
"""Which routine families have a hole in their index run, and is it real?

Question answered
-----------------
`docs/NAMING.md` §2: "no family has a gap in its index run. Keep it that way:
a gap means a frame was missed or misfiled." That rule is enforced on
*polygon* families by the naming validator. Nothing measured it on **routine**
families, and it turns out to bite there too, downstream: the
sole-named-drawer pass derives constant names from routine names, and
`tools/apply_branch_scoped_names.py` rejected 32 otherwise-good constants
because the routine family they came from was gapped --
`CAPSULE_SHOT_STATE_FRAME_RIGHT_ABOVE_01`, `_02`, `_04`, with no `_03`
anywhere in the file. A hole in the routine layer stops the polygon layer.

The measurement that did not work
---------------------------------
Taking every semantic label matching `<base>_<digits>` as a family gives 130
gapped families out of 366, and it is wrong. Most of those trailing numbers
are **values, not indices**:

    PRISON_LIFT_LANDING_IN_VIEW_FROM_2008     a Y coordinate
    CAPSULE_SHOT_BEAM_SPAN_DRAW_FROM_64       a span length
    PRISON_LIFT_SHAFT_STRIP_TILT_UPTO_16      a tilt threshold

Reported as a family, `{2008, 2198, 2328, 2648, 2968}` looks like five frames
with 955 missing. It is five thresholds.

What separates them is **density**: a frame family covers most of the range
it spans, a set of thresholds covers almost none. Requiring members to fill
at least 60 % of their range drops 57 of these and leaves 309 real families.

Result, 2026-09-20
------------------
    309  dense index families (3+ members, >=60 % of their range)
     73  of those have an interior gap
     57  rejected as thresholds rather than indices

Not all 73 are missing work
---------------------------
Many are **spelling splits**, not absences. `CAPSULE_HERO_WALK_RIGHT_DRAW` is
missing 5, 7 and 13 — and frame 5 exists, named
`CAPSULE_HERO_WALK_RIGHT_FOOTSTEP_PHASE_1`. The frame is there under another
word, which is the same problem
`notes/caller-derived-naming/name_routines_from_art.spelling` solves for the
gun arms by pinning a derived name onto an earned sibling's spelling.

So this number is a worklist with more than one pile in it. Asking, per gap,
"does a named routine draw the art at that slot" splits the 73 as:

    17  the gap slot IS drawn by a named routine
    16  family members draw more than one constant each, so the slot cannot
        be located from the art at all
     5  the slot has art and no named drawer -- genuine backlog
     2  no art between the neighbours; the family may simply skip
    33  no neighbour on one side, so no slot to look at

**The 17 are still two things, and this probe cannot tell them apart.**
`CAPSULE_SHOT_STATE_FRAME_RIGHT_ABOVE` is missing 3, and the art at that slot
is drawn by `CAPSULE_SHOT_IMPACT_SPARK_RIGHT_PHASE_4`. That is *not*
`ABOVE_03` under another spelling -- it is a **second series interleaved with
the first**, the same shape as the hero's body-and-arm pairing, where two
layers of one animation sit in alternating offsets. Merging them would be
wrong in a way that `CAPSULE_HERO_WALK_RIGHT_DRAW` missing frame 5 while
`CAPSULE_HERO_WALK_RIGHT_FOOTSTEP_PHASE_1` exists would not.

Telling a renamed member from a parallel layer needs what separated body from
arm in `../shared-bank-geometry/`: the measured geometry of the two, and
whether one routine draws both. That is the next step, and it is a
measurement rather than a judgement.

Usage
-----
    python3 notes/family-gaps/routine_family_gaps.py
    python3 notes/family-gaps/routine_family_gaps.py --list
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
sys.path.insert(0, str(SRC.parent / "another-world-archaeology" / "tools"))
from naming_census import classify                   # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
RE_LABEL = re.compile(r"^([A-Za-z_]\w*):")
RE_FAMILY = re.compile(r"^(.*?)_(F?)(\d+)$")
MIN_DENSITY = 0.6


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--slots", action="store_true",
                    help="for each gap, whether a named routine draws the "
                         "art at that slot (see the docstring: a hit is "
                         "either a renamed member or a parallel layer, and "
                         "this does not distinguish them)")
    args = ap.parse_args()

    n = collections.Counter()
    gappy: list = []
    for port, br in PORTS.items():
        for p in sorted((SRC / "src" / "levels" / br).glob("*.asm")):
            labels = [m.group(1)
                      for line in p.read_text(errors="replace").splitlines()
                      if (m := RE_LABEL.match(line))]
            fam: dict[tuple, set] = collections.defaultdict(set)
            for lab in labels:
                if classify(lab) != "semantic":
                    continue
                m = RE_FAMILY.match(lab)
                if m:
                    fam[(m.group(1), m.group(2))].add(int(m.group(3)))
            for key, idx in fam.items():
                if len(idx) < 3:
                    continue
                span = max(idx) - min(idx) + 1
                if len(idx) / span < MIN_DENSITY:
                    n["rejected as thresholds rather than indices"] += 1
                    continue
                n["dense index families"] += 1
                miss = [i for i in range(min(idx), max(idx) + 1)
                        if i not in idx]
                if miss:
                    n["  of those, with an interior gap"] += 1
                    gappy.append((port, p.stem,
                                  key[0] + ("_" + key[1] if key[1] else ""),
                                  len(idx), miss))
    for k, v in n.most_common():
        print(f"{v:5d}  {k}")
    if args.list:
        print()
        for port, stage, base, members, miss in sorted(
                gappy, key=lambda r: (-len(r[4]), r[0], r[1])):
            print(f"  {port}/{stage:<10}{base[:50]:<52}{members:3d} members, "
                  f"missing {miss}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
