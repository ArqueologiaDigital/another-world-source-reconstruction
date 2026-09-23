#!/usr/bin/env python3
"""Whose picture is this? The anchor variable and the names disagree.

Question answered
-----------------
A `video` drawn at `x=[HERO_X], y=[HERO_Y]` looks like proof that the picture is
the player character's, and one at `x=[BUDDY_X], y=[BUDDY_Y]` like proof it is
the companion's. That reasoning was used here to name ten CAPSULE constants
`CINEMATIC_BUDDY_*`, and it is not safe.

In amiga/CAPSULE the two earned namings contradict each other:

  * `CINEMATIC_BUDDY_SMASHING_WINDOW_F0..F8` -- a name that commits to the
    companion -- is drawn at **`[HERO_X], [HERO_Y]`**;
  * the routines `DRAW_HERO_POSE_0_1`, `DRAW_HERO_POSE_1`, `DRAW_HERO_POSE_2`,
    `DRAW_HERO_POSE_3`, `DRAW_HERO_POSE_5` -- names that commit to the hero --
    all draw at **`[BUDDY_X], [BUDDY_Y]`**.

Both cannot be right, and nothing in the bytecode settles it: the variable
numbers come from the VM's own convention (HERO_X is 0x01, BUDDY_X is 0x07) and
a script is free to drive any actor through any variable.

What the tree already does about it is the answer. Every other figure name at
either anchor uses the neutral word **FIGURE** -- `CAPSULE_FIGURE_FLUNG_*` and
`CAPSULE_FIGURE_PROP_UP_*` at `[HERO_X]`, `CAPSULE_FIGURE_THROW_*`,
`CAPSULE_FIGURE_WALK_RIGHT_BODY_*`, `CAPSULE_KNEELING_FIGURE_*` and
`CAPSULE_PRONE_FIGURE_*` at `[BUDDY_X]`. An earlier pass met this same question
and declined to answer it, which is what #0120 asks for.

What this probe reports
-----------------------
Per branch and stage, every anchor that is a pair of named variables, how many
draws use it, and which **named** constants are drawn there. Then it flags the
contradictions: a constant whose own name contains HERO drawn at a BUDDY anchor,
or vice versa.

A stage only spells a variable `HERO_X` if its own file defines that EQU, and
they do not agree: CAVES defines `HERO_X` but not `BUDDY_X` and then draws 403
times at a raw `[0x07]`; ENDING defines `BUDDY_X` but not `HERO_X` and draws 73
times at `[0x01]`. The scan normalises `0x01/0x02/0x07/0x08` to the canonical
names before grouping, because without that it silently reports those stages as
using one actor only -- which it did, and which produced a wrong conclusion
before the spelling was checked.

Run it
------
    python3 notes/actor-anchors/anchor_identity.py
    python3 notes/actor-anchors/anchor_identity.py --stage CAPSULE --names
"""
from __future__ import annotations

import argparse
import collections
import pathlib
import re

SRC = pathlib.Path(__file__).resolve().parents[2] / "src" / "levels"
BRANCHES = ["chahi_amiga_1991", "dos_1992"]
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]

RE_DRAW = re.compile(
    r"video\s+(?:type=\d+,\s*)?offset=(CINEMATIC_[A-Za-z0-9_]+),"
    r"\s*x=\[([A-Za-z_0-9][A-Za-z0-9_]*)\],\s*y=\[([A-Za-z_0-9][A-Za-z0-9_]*)\]")
RE_VAR_EQU = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s+(0x[0-9A-Fa-f]{2})\s*$", re.M)
# The same VM variable is spelled `HERO_X` in some stages and `[0x01]` in others,
# because a stage only gets the symbol if that stage's file defines it. CAVES has
# 403 draws at a raw `[0x07]` and no `BUDDY_X` EQU at all. Any query over anchors
# has to normalise, or it silently misses them -- this one did, once.
CANON = {"0x01": "HERO_X", "0x02": "HERO_Y", "0x07": "BUDDY_X", "0x08": "BUDDY_Y"}
RE_LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
RE_NUMBERED = re.compile(r"^CINEMATIC_\d+$")


def scan(branch: str, stage: str):
    f = SRC / branch / f"{stage}.asm"
    if not f.is_file():
        return None
    text = f.read_text()
    lines = text.splitlines()
    local = {v: n for n, v in RE_VAR_EQU.findall(text)}

    def canon(v: str) -> str:
        """Spell a variable the same way whatever the stage happens to call it."""
        if v.startswith("0x"):
            key = "0x" + v[2:].lower().zfill(2)
            return local.get(key) or CANON.get(key) or v
        return v
    anchors: dict[tuple[str, str], collections.Counter] = collections.defaultdict(
        collections.Counter)
    routine_anchor: dict[str, set[tuple[str, str]]] = collections.defaultdict(set)
    cur = None
    for line in lines:
        m = RE_LABEL.match(line)
        if m:
            cur = m.group(1)
            continue
        d = RE_DRAW.search(line)
        if not d:
            continue
        const, xv, yv = d.groups()
        xv, yv = canon(xv), canon(yv)
        anchors[(xv, yv)][const] += 1
        if cur:
            routine_anchor[cur].add((xv, yv))
    return anchors, routine_anchor


def word(s: str) -> str | None:
    if "BUDDY" in s:
        return "BUDDY"
    if "HERO" in s:
        return "HERO"
    return None


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--branch", choices=BRANCHES)
    ap.add_argument("--stage", choices=STAGES)
    ap.add_argument("--names", action="store_true",
                    help="list the named constants at each anchor")
    args = ap.parse_args()

    total_conflicts = 0
    for branch in BRANCHES:
        if args.branch and branch != args.branch:
            continue
        for stage in STAGES:
            if args.stage and stage != args.stage:
                continue
            got = scan(branch, stage)
            if not got:
                continue
            anchors, routine_anchor = got
            if not anchors:
                continue
            print(f"\n  === {branch.split('_')[0]}/{stage}")
            for (xv, yv), c in sorted(anchors.items(), key=lambda kv: -sum(kv[1].values())):
                named = [n for n in c if not RE_NUMBERED.match(n)]
                nums = [n for n in c if RE_NUMBERED.match(n)]
                print(f"      x=[{xv}], y=[{yv}]   {sum(c.values()):>4} draw(s), "
                      f"{len(named)} named / {len(nums)} still numbered")
                if args.names:
                    for n in sorted(named):
                        print(f"          {n}")
                aw = word(xv)
                for n in sorted(named):
                    nw = word(n)
                    if aw and nw and nw != aw:
                        total_conflicts += 1
                        print(f"          CONFLICT  {n} says {nw}, anchor says {aw}")
                for r, a in sorted(routine_anchor.items()):
                    rw = word(r)
                    if rw and aw and rw != aw and (xv, yv) in a:
                        total_conflicts += 1
                        print(f"          CONFLICT  routine {r} says {rw}, "
                              f"but draws at the {aw} anchor")
    print(f"\n  {total_conflicts} conflict(s) between a name's own actor word and")
    print("  the actor word of the anchor it is drawn at. Where there is one, the")
    print("  tree's own practice is the neutral word FIGURE -- see the README.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
