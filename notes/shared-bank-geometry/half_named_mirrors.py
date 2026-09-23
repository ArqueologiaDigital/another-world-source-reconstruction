#!/usr/bin/env python3
"""Which named pieces have no named twin in the opposite direction?

Question answered
-----------------
`crouch_poses.map` and `stand_right.map` both came from the same oversight:
a left-facing piece was named and its right-facing counterpart was left as a
`CV_` placeholder. **Neither gap shows up in any count.** The family looks
complete, the routine that draws it looks complete, and the left-hand routine
genuinely IS complete -- it is the right-hand one that ends on an unnamed
constant.

So it needs its own check. For every named shared-bank piece whose name
contains `_LEFT` or `_RIGHT`, this asks whether the name with the direction
flipped also exists.

Reading the output
------------------
A missing twin is a QUESTION, not a defect. Three answers are legitimate and
the project has instances of each:

  * **the twin is unnamed art** -- a real gap. `HERO_STAND_RIGHT_BODY` and
    `HERO_CROUCH_RIGHT` were found this way.
  * **the twin does not exist** -- the animation is one-sided. The nine
    missing `HERO_WALK_LEFT_ARM_F05..F13` are absences verified three ways
    in `walk_left_arm_gap.md`, and `HERO_RUN_LEFT_ARM_F04` is a frame that
    draws no arm.
  * **the cycles differ in length** -- `CV_FIGURE_RUN_LEFT_UPPER_POSE_06`
    has no right-facing twin because that cycle has one fewer pose.

So the list is a worklist, not an error report, and every entry needs the
same treatment: find the mirror routine, compare its components in order,
and check the candidate's geometry against the named twin's.

Usage
-----
    python3 notes/shared-bank-geometry/half_named_mirrors.py
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels"
RE_T0 = re.compile(r"video type=0, offset=([A-Z][A-Z0-9_]*)")
RE_PLACEHOLDER = re.compile(r"^CV_[0-9A-F]{4}$")

# Missing twins already adjudicated, with where the reasoning lives.
KNOWN = {
    **{f"HERO_WALK_LEFT_ARM_F{n:02d}": "absence, walk_left_arm_gap.md"
       for n in range(5, 14)},
    "HERO_RUN_LEFT_ARM_F04": "absence, run_left_body.map (frame draws no arm)",
    **{f"HERO_RUN_LEFT_GUN_ARM_POSE_{n:02d}":
       "absence, run_right_gun_arm.map (no left-facing guard on [0x0A])"
       for n in range(0, 5)},
    "CV_FIGURE_RUN_RIGHT_UPPER_POSE_06": "cycle length differs, 6 vs 7 poses",
}


def main() -> int:
    text = "\n".join(p.read_text(errors="replace")
                     for p in SRC.rglob("*.asm"))
    named = {n for n in RE_T0.findall(text) if not RE_PLACEHOLDER.match(n)}

    open_, settled = [], []
    for n in sorted(named):
        if "_LEFT" in n:
            twin = n.replace("_LEFT", "_RIGHT")
        elif "_RIGHT" in n:
            twin = n.replace("_RIGHT", "_LEFT")
        else:
            continue
        if twin in named:
            continue
        (settled if twin in KNOWN else open_).append((n, twin))

    print(f"{len(open_) + len(settled)} named piece(s) with no named twin\n")
    if open_:
        print(f"OPEN -- worth chasing ({len(open_)}):")
        for n, twin in open_:
            print(f"  {n:<44} -> {twin}")
    else:
        print("OPEN: none -- every missing twin has a recorded reason.")
    if settled:
        print(f"\nadjudicated ({len(settled)}):")
        for n, twin in settled:
            print(f"  {twin:<44} {KNOWN[twin]}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
