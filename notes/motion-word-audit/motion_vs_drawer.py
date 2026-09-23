#!/usr/bin/env python3
"""Does a picture's motion word agree with the motion of whoever draws it?

Question answered
-----------------
`CAVES_DRAW_HERO_IDLE_LEFT_1` drew the first frame of a laser-impact flash,
and nothing in the byte gate could see it: a rename moves no bytes. What
caught it was reading a name against the thing it names. This module does the
same comparison over a vocabulary narrow enough to be checkable -- the gait
words -- for every named picture in the two priority ports.

A picture whose name contains a motion word, drawn only by routines that name
a *different* motion, is a candidate. `HERO_FALL_LEFT_LOOP` was once exactly
that and turned out to be the walk.

Signal being read
-----------------
The motion vocabulary and its synonyms come from
`../shared-bank-geometry/hero_pose_consensus.py`, so there is one list, not
two: WALK, RUN, CRAWL, JUMP, STAND, PRONE, CROUCH, SHOOT (with FIRE and SHOT
folded into SHOOT), FALL, AIM. A constant is attributed to every label whose
body draws it, by `video offset=` or `video type=0, offset=`.

Why this is a prompt and not a gate
-----------------------------------
Because a routine draws more than its own pose. Measured over both priority
ports, 107 named pictures disagree with every drawer, and the pairings sort
themselves by how often they happen:

    constant says   drawer says   times
    PRONE           CRAWL            24
    JUMP            RUN              21
    PRONE           WALK             18
    CRAWL           WALK             13
    RUN             WALK             12
    JUMP            WALK             12
    CROUCH          AIM               4
    CROUCH          SHOOT             4
    CRAWL           STAND             4
    STAND           AIM               4
    STAND           CROUCH            4
    STAND           WALK              2

Frequency separates a convention from an accident, but it does **not**
separate right from wrong -- a systematic mislabel is systematic. Reading the
top classes shows why they are legitimate, and the reason is structural:

**A loop draws the pose it exits into.** `HERO_CROUCH_HOLD_LEFT_LOOP` draws
`HERO_CROUCH_LEFT` while it spins, and `HERO_STAND_ARMED_LEFT` once, on the
way out, before `jmp HERO_WALK_LEFT_LOOP` -- the hero standing back up. Both
names are correct and they will never share a word. That accounts for
STAND/CROUCH and STAND/WALK.

**A transition is named for the state it reaches.** `HERO_PRONE_TRANSITION_*`
is drawn by `PRISON_HERO_CRAWL_RIGHT_START` and `..._STOP`, which is where a
prone transition belongs; PRONE/CRAWL and PRONE/WALK are that.

**A sprite sheet can lift the figure inside its own frames.** JUMP/RUN and
JUMP/WALK are the finding in `../actor-sprite-sheet/` -- the jump sheets are
driven from the run and walk loops, and the lift is drawn, not written to
`HERO_Y`.

What is left
------------
RUN/WALK is the one class this module cannot dismiss, and it is not the LAKE
entry (`HERO_SHADOW_RUN_RIGHT_0` is drawn by `HERO_WALK_RIGHT_LOOP` once, on
the same exit-transition pattern). It is PRISON:

    CV_FIGURE_RUN_LEFT_BODY_F00  drawn only by PRISON_ACTOR_WALK_LEFT_PHASE_0_DONE
    CV_FIGURE_RUN_LEFT_BODY_F03  drawn only by PRISON_ACTOR_WALK_LEFT_PHASE_3_DONE
    CV_FIGURE_RUN_LEFT_BODY_F05  drawn only by PRISON_ACTOR_WALK_LEFT_PHASE_5_DONE
    CV_FIGURE_RUN_LEFT_BODY_F07  drawn only by PRISON_ACTOR_WALK_LEFT_PHASE_7_DONE
    CV_FIGURE_RUN_LEFT_BODY_F08  drawn only by PRISON_ACTOR_WALK_LEFT_PHASE_8_DONE

The frame index and the phase index agree every time, so this is one
animation under two conventions rather than a misattribution, and it is the
class `../HANDOFF.md` already tracks. Settling it needs the measurement that
settled FALL-versus-WALK: pixels of travel per frame. Not done here, and not
guessed here.

Pass/fail
---------
Exits 0 always. The list is a reading list. Exiting 1 on it would fail the
tree for `HERO_CROUCH_HOLD_LEFT_LOOP` drawing the hero standing up, which is
the code being correct.

Usage
-----
    python3 notes/motion-word-audit/motion_vs_drawer.py
    python3 notes/motion-word-audit/motion_vs_drawer.py --pairs
    python3 notes/motion-word-audit/motion_vs_drawer.py --pair RUN WALK
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
sys.path.insert(0, str(SRC / "notes" / "shared-bank-geometry"))
import hero_pose_consensus as H                          # noqa: E402

BRANCHES = ("chahi_amiga_1991", "dos_1992")
SYNONYM = dict(H.SYNONYM)
CANON = {SYNONYM.get(m, m) for m in H.MOTIONS}

RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
RE_VID = re.compile(r"^\s*video\s+(?:type=\d+,\s*)?offset="
                    r"([A-Za-z_][A-Za-z0-9_]*)")
RE_PLACEHOLDER = re.compile(r"^(CINEMATIC_\d+|CV_[0-9A-F]{4})$")


def motions(name: str) -> set[str]:
    return {SYNONYM.get(w, w) for w in name.split("_")} & CANON


def scan():
    """(branch, stage, constant, its motions, drawers) for each disagreement."""
    out, stats = [], collections.Counter()
    for branch in BRANCHES:
        for f in sorted((SRC / "src" / "levels" / branch).glob("[A-Z]*.asm")):
            lines = f.read_text(errors="replace").splitlines()
            drawers: dict[str, set[str]] = collections.defaultdict(set)
            cur = None
            for line in lines:
                if m := RE_LBL.match(line):
                    cur = m.group(1)
                elif cur and (v := RE_VID.match(line)):
                    drawers[v.group(1)].add(cur)
            for const, labs in drawers.items():
                if RE_PLACEHOLDER.match(const):
                    continue
                cm = motions(const)
                if not cm:
                    continue
                stats["named pictures carrying a motion word"] += 1
                lm = set().union(*(motions(l) for l in labs)) if labs else set()
                if not lm:
                    stats["  no drawer names a motion"] += 1
                elif cm & lm:
                    stats["  agrees with at least one drawer"] += 1
                else:
                    stats["  ** every drawer names a different motion"] += 1
                    out.append((branch, f.stem, const, cm, sorted(labs)))
    return out, stats


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--pairs", action="store_true",
                    help="summarise by (constant motion, drawer motion)")
    ap.add_argument("--pair", nargs=2, metavar=("CONST", "DRAWER"),
                    help="list only this pairing")
    args = ap.parse_args()

    rows, stats = scan()
    for k, v in stats.most_common():
        print(f"  {v:>5}  {k}")

    pairs = collections.Counter()
    for _b, _s, _c, cm, labs in rows:
        lm = set().union(*(motions(l) for l in labs))
        for a in sorted(cm):
            for b in sorted(lm):
                pairs[(a, b)] += 1

    if args.pairs:
        print(f"\n  {'picture says':<14}{'drawer says':<14}{'times':>6}")
        for (a, b), n in pairs.most_common():
            print(f"  {a:<14}{b:<14}{n:>6}")
        print("\n  Frequency separates a convention from an accident. It does "
              "NOT\n  separate right from wrong: a systematic mislabel is "
              "systematic.")
        return 0

    print(f"\n{len(rows)} named picture(s) whose motion word no drawer shares:")
    for branch, stage, const, cm, labs in sorted(rows):
        if args.pair:
            lm = set().union(*(motions(l) for l in labs))
            if args.pair[0] not in cm or args.pair[1] not in lm:
                continue
        print(f"  {branch.split('_')[0]:<6}{stage:<9}"
              f"{const.replace('CINEMATIC_', ''):<42}"
              f"says {sorted(cm)}  drawn by {labs[:3]}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
