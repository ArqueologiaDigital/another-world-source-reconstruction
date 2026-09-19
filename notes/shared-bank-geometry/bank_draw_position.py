#!/usr/bin/env python3
"""Whose art is at each shared-bank offset? Ask the draw position, not the shape.

Question answered
-----------------
`bank_shape_census.py` next to this file measured the shape at all 352 shared-bank
offsets and sorted them by what geometry alone could assert. For 143 "large" and
94 "small-cluster" entries the honest answer was "needs a render", and for the 13
"figure" entries it was "NOT settled by shape -- *which* figure is the question".
That is where shape stops.

This asks a different question and gets further. `docs/NAMING.md` §2 says a
shared-bank name must be true in every stage that draws it -- 349 of the 352 are
drawn from more than one stage, so no scene can supply it. But the *draw
position operand* is stage-invariant in exactly the way a scene is not:

    video type=0, offset=CV_5C4C, x=[HERO_X], y=[HERO_Y], zoom=0x40

`HERO_X`/`HERO_Y` is an engine alias (`docs/NAMING.md` §3), it means the same
thing in CAVES as in CAPSULE, and it is earned independently of this bank. So
if every call site of an offset -- across both priority ports and all nine
stages -- draws it at the hero, that art *is* hero art, and saying so is true
everywhere the offset is referenced.

Result, 2026-09-20
------------------
    191  only [HERO_X],[HERO_Y]
    148  only the actor slot (#0138)
     13  mixed

So the bank is not a miscellany. It is, in the main, **the hero's sprite sheet
plus a generic actor's**, which is precisely why it is shared: the hero is in
every stage, so his art cannot live in a stage's cinematic bank. That is the
first structural account of what this bank *is*, as opposed to where it sits.

It also sharpens #0138 rather than dissolving it: for the 148 actor-slot
offsets the draw position is the shared actor record, loaded from a different
record before each draw, so the position says an actor and refuses to say
which. Those stay blocked -- `notes/actor_slot.py` is what resolves the
aliases, and using the literal `[0x07],[0x08]` test instead under-reports
them badly (PRISON, CAPSULE and ENDING write `[BUDDY_X],[BUDDY_Y]`).

What this does and does not license
-----------------------------------
It licenses the *subject* of 191 offsets, not their *pose*. `CV_34BA` being
hero art is settled here; whether it is a running frame or a falling one is not,
and NAMING.md still requires a render before the name is written. What changed
is that the render now only has to answer "which pose", with the subject fixed
and checkable -- instead of "who is this", which no render of a 6x8 blob in an
unknown palette was ever going to answer.

Signals read
------------
`video ... offset=CV_xxxx, x=..., y=...` operands in
`src/levels/{chahi_amiga_1991,dos_1992}/<STAGE>.asm`. Actor-slot aliases are
resolved through `notes/actor_slot.py`, which reads the `EQU 0x07` / `EQU 0x08`
table per file rather than matching the literal spelling.

Exit status
-----------
0 normally. 1 if any offset is drawn at the hero in one place and the actor slot
in another, which would mean one picture serving two subjects and would break
the one-name-per-offset premise this whole approach rests on.

Usage
-----
    python3 notes/shared-bank-geometry/bank_draw_position.py
    python3 notes/shared-bank-geometry/bank_draw_position.py --list hero
    python3 notes/shared-bank-geometry/bank_draw_position.py --list mixed
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
sys.path.insert(0, str(HERE.parents[1]))
from actor_slot import actor_slot_names            # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES",
          "TANK", "CAPSULE", "ENDING", "PASSCODE"]
RE_DRAW = re.compile(
    r"offset=(CV_[0-9A-F]{4}),\s*x=(\[?\w+\]?),\s*y=(\[?\w+\]?)")

HERO = "HERO"
ACTOR = "ACTOR_SLOT"


def census() -> dict[str, collections.Counter]:
    pos: dict[str, collections.Counter] = collections.defaultdict(
        collections.Counter)
    for port, br in PORTS.items():
        for st in STAGES:
            p = SRC / "src" / "levels" / br / f"{st}.asm"
            if not p.is_file():
                continue
            text = p.read_text(errors="replace")
            xs, ys = actor_slot_names(text)
            for cv, x, y in RE_DRAW.findall(text):
                bx, by = x.strip("[]"), y.strip("[]")
                if bx in xs and by in ys:
                    key = ACTOR
                elif not x.startswith("["):
                    key = "literal"
                elif bx == "HERO_X" and by == "HERO_Y":
                    key = HERO
                else:
                    key = f"{bx},{by}"
                pos[cv][key] += 1
    return pos


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--list", choices=["hero", "actor", "mixed", "other"])
    args = ap.parse_args()

    pos = census()
    groups: dict[str, list[str]] = collections.defaultdict(list)
    for cv, c in pos.items():
        if len(c) > 1:
            groups["mixed"].append(cv)
        elif HERO in c:
            groups["hero"].append(cv)
        elif ACTOR in c:
            groups["actor"].append(cv)
        else:
            groups["other"].append(cv)

    print(f"{len(pos)} shared-bank offsets are drawn by the tree.\n")
    print(f"{len(groups['hero']):5d}  only [HERO_X],[HERO_Y]  -- hero art, "
          f"and that is true in every stage that draws it")
    print(f"{len(groups['actor']):5d}  only the actor slot     -- #0138: an "
          f"actor, but the record says which, not the art")
    print(f"{len(groups['mixed']):5d}  mixed")
    print(f"{len(groups['other']):5d}  other fixed position")

    both = [cv for cv in groups["mixed"]
            if HERO in pos[cv] and ACTOR in pos[cv]]
    if both:
        print(f"\nFAIL: {len(both)} offsets are drawn at the hero in one place "
              f"and at the actor slot in\nanother, so one picture serves two "
              f"subjects: {', '.join(sorted(both))}")
        return 1
    print("\nNo offset is drawn at both the hero and the actor slot, so the "
          "subject split is\nclean and one name per offset stays correct.")

    if args.list:
        sel = sorted(groups[args.list])
        print(f"\n{len(sel)} in '{args.list}':")
        for i in range(0, len(sel), 8):
            print("  " + "  ".join(sel[i:i + 8]))
        if args.list == "mixed":
            print("\nwhere each is drawn:")
            for cv in sel:
                print(f"  {cv}  " + ", ".join(
                    f"{k}x{n}" for k, n in pos[cv].most_common()))
    return 0


if __name__ == "__main__":
    sys.exit(main())
