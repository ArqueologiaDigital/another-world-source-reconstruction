#!/usr/bin/env python3
"""Which shared-bank art sits behind a guard that can never fail?

Question answered
-----------------
`bank_draw_position.py` counts an offset as outstanding work if the tree
draws it. That is the right default and it over-counts, because a `video`
instruction behind a branch that is always taken never runs.

One case is large enough to matter. The 18 pieces at `CV_5F74..CV_5FFC`,
stride 8, pair one-to-one with the named
`CV_FIGURE_WALK_<DIR>_UPPER_POSE_00..08` and are drawn only like this:

    video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_08, ...
    mov [0xF5], [BUDDY_X]
    jg  [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW   <- always jumps
    video type=0, offset=CV_5F74, ...                  <- never reached
    jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

`[0xF6]` is written **nine times across all four branches and every one is
`mov [0xF6], 0x0001`**. Nothing ever sets it to zero, and every stage that
contains the guard also contains the write. So `jg [0xF6], 0x00` is
unconditionally true, all 180 such guards jump, and all 108 draws of this
series are dead.

Per issue #0126 a role name must not be put on an unreachable byte, so these
18 are not outstanding naming work. They are art that ships in the bank and
is never shown.

What is checked
---------------
For each candidate variable used as a guard:

  * every write to it anywhere in `src/levels`, and whether any could make
    the guard fail;
  * every draw of the art behind it, and whether ANY draw site lacks the
    guard -- one unguarded site would make the art reachable and the whole
    conclusion wrong;
  * per stage, that the stage which contains the guard also contains the
    write, since a stage with the guard and no write could see the variable
    at its initial value.

Exit status
-----------
1 if any draw of the series is NOT behind the guard, since that contradicts
the finding and the note would need correcting.

Usage
-----
    python3 notes/shared-bank-geometry/unreachable_guarded_art.py
"""
from __future__ import annotations

import collections
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels"
BRANCHES = ("chahi_amiga_1991", "dos_1992", "cartridge_1992", "gba_2004")
STAGES = ("CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE")

VAR = "0xF6"
GUARD = re.compile(rf"jg\s+\[{VAR}\],\s*0x0+,")
WRITE = re.compile(rf"(mov|add|sub|and|or|xor|shr|shl)\s+\[{VAR}\],\s*(\S+)")
SERIES = re.compile(r"video type=0, offset=(CV_5F[0-9A-F]{2}),")


def main() -> int:
    writes: collections.Counter = collections.Counter()
    per_stage: dict = collections.defaultdict(lambda: [0, 0, 0])
    unguarded = []
    draws = guards = 0

    for br in BRANCHES:
        for stage in STAGES:
            p = SRC / br / f"{stage}.asm"
            if not p.is_file():
                continue
            lines = p.read_text(errors="replace").splitlines()
            for i, line in enumerate(lines):
                m = WRITE.search(line)
                if m:
                    writes[f"{m.group(1)} [{VAR}], {m.group(2)}"] += 1
                    per_stage[f"{br}/{stage}"][0] += 1
                if GUARD.search(line):
                    guards += 1
                    per_stage[f"{br}/{stage}"][1] += 1
                d = SERIES.search(line)
                if d:
                    draws += 1
                    per_stage[f"{br}/{stage}"][2] += 1
                    window = "\n".join(lines[max(0, i - 4):i])
                    if not GUARD.search(window):
                        unguarded.append(f"{br}/{stage}:{i + 1} {d.group(1)}")

    print(f"writes to [{VAR}] anywhere in src/levels:")
    for k, v in writes.most_common():
        print(f"  {v:>4}  {k}")
    can_fail = [k for k in writes if not k.endswith("0x0001")]
    print(f"\nwrites that could make `jg [{VAR}], 0x00` fail: "
          f"{can_fail if can_fail else 'NONE'}")
    print(f"guards: {guards}    draws of CV_5F**: {draws}    "
          f"draws NOT behind the guard: {len(unguarded)}")

    print(f"\nper stage -- a stage with the guard but no write could see "
          f"{VAR} at its initial value:")
    bad_stage = []
    for k in sorted(per_stage):
        w, g, d = per_stage[k]
        if not (g or d):
            continue
        flag = ""
        if g and not w:
            flag = "   <-- guard without a write"
            bad_stage.append(k)
        print(f"  {k:<28} writes {w}  guards {g:>3}  draws {d:>3}{flag}")

    if unguarded:
        print(f"\n{len(unguarded)} draw(s) are NOT behind the guard, so the "
              f"art IS reachable and the note is wrong:")
        for u in unguarded[:10]:
            print(f"  {u}")
        return 1
    if can_fail or bad_stage:
        print("\nthe guard is not unconditional after all -- see above.")
        return 1
    print(f"\nEvery draw of the series is behind a guard that cannot fail, in "
          f"every stage that draws it.\nThe 18 pieces CV_5F74..CV_5FFC are "
          f"never shown; per #0126 they take no role name.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
