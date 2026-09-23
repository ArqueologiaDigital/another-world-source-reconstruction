#!/usr/bin/env python3
"""The holes this pass left in its own label families are the footsteps.

Question answered
-----------------
`label_vs_constant.py` names a label after the picture it draws, but only when
drawing is *all* the label does -- a body that also plays a sound is not named
by its picture, because the existing name records the sound's operands. That
rule dropped 13 of 223 candidates.

The consequence shows up one layer later. The label families it created have
interior gaps:

    CAVES_DRAW_HERO_RUN_LEFT_BODY_<n>    1 2 3 4 _ 6 7 8 9     (no 0, no 5)
    CAVES_DRAW_HERO_WALK_LEFT_BODY_<n>   0 1 2 3 4 _ 6 ... 12 _ 14

`docs/NAMING.md` bars gaps in a family's index run, so this needs an answer,
and the answer is not "renumber them densely". These indices are **inherited**
from the constant each label draws, not assigned by a namer. Renumbering would
make `CAVES_DRAW_HERO_RUN_LEFT_BODY_4` draw frame 6, which is precisely the
off-by-one that `../laser-impact-anim/` exists to document.

So: what is in the holes?

What it measures
----------------
For every label whose body draws exactly one `HERO_<MOTION>_LEFT_BODY_F<nn>`,
whether the body does anything else, and if so what. Measured over PRISON,
CAVES and CAPSULE in both priority ports:

    amiga/CAVES    RUN   stubs 1 2 3 4 6 7 8 9    excluded {0: play 0x0060, 5: play 0x0060}
    amiga/CAVES    WALK  stubs 0..4 6..12 14      excluded {5: play 0x0060, 13: play 0x0060}
    amiga/PRISON   RUN   stubs 1 2 3 4 6 7 8 9    excluded {0: play 0x0060, 5: play 0x0060}
    amiga/PRISON   WALK  stubs 0..14              excluded {}
    amiga/CAPSULE  RUN   stubs 1 2 3 4 6 7 8 9    excluded {0: play 0x0060, 5: play 0x0060}
    amiga/CAPSULE  WALK  stubs 0..4 6..12 14      excluded {5: play 0x0060, 13: play 0x0060}

and msdos identically. **Every** excluded frame is excluded for the same
reason: it plays sound `0x0060`, and nothing else is ever in a hole.

That is the footstep. The run cycle steps on frames **0 and 5** of ten, which
is the same pair `../actor-sprite-sheet/` derived independently from the gait
geometry; the walk cycle steps on **5 and 13** of fifteen. Two steps per
cycle, evenly spaced, in both gaits.

So the gaps are not missing names. They are the frames where the foot lands,
and the rule that produced them is what makes them visible.

The one asymmetry
-----------------
`PRISON/WALK` has no exclusions in either port: all fifteen frames are pure
draws and none plays `0x0060`. PRISON's walking hero makes no footstep sound
where CAVES' and CAPSULE's do. Reported, not explained -- this module measures
which frames carry the `play`, not why one stage drops it.

Pass/fail
---------
Exits 1 if any hole in one of these families is a frame whose drawer does NOT
play a sound, because that would be a genuinely missing name rather than a
footstep, and the reasoning above would no longer cover it.

Usage
-----
    python3 notes/draw-label-follows-constant/footstep_frames.py
"""

from __future__ import annotations

import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGES = ("PRISON", "CAVES", "CAPSULE")

RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
RE_VID = re.compile(r"^\s*video\s+(?:type=\d+,\s*)?offset="
                    r"([A-Za-z_][A-Za-z0-9_]*)")
RE_PLAY = re.compile(r"^\s*play\s+id=(0x[0-9A-Fa-f]+)")
RE_RET = re.compile(r"^\s*ret\s*$")
RE_FRAME = re.compile(r"^HERO_(RUN|WALK)_LEFT_BODY_F(\d+)$")


def classify_body(body: list[str]):
    """(the one frame drawn, what else the body does) or None."""
    drawn, plays, other = [], [], False
    for line in body:
        if RE_RET.match(line):
            break
        if not line.strip() or line.lstrip().startswith(";"):
            continue
        if v := RE_VID.match(line):
            drawn.append(v.group(1))
            continue
        if p := RE_PLAY.match(line):
            plays.append(p.group(1))
            continue
        other = True
    if len(drawn) != 1:
        return None
    m = RE_FRAME.match(drawn[0])
    if not m:
        return None
    what = "pure" if not plays and not other else (
        f"play {plays[0]}" if plays else "other")
    return m.group(1), int(m.group(2)), what


def main() -> int:
    bad = 0
    for port, branch in PORTS.items():
        for stage in STAGES:
            f = SRC / "src" / "levels" / branch / f"{stage}.asm"
            if not f.is_file():
                continue
            lines = f.read_text(errors="replace").splitlines()
            body: dict[str, list[str]] = collections.defaultdict(list)
            cur = None
            for line in lines:
                if m := RE_LBL.match(line):
                    cur = m.group(1)
                elif cur:
                    body[cur].append(line)
            seen: dict[str, dict[int, str]] = collections.defaultdict(dict)
            for lab, b in body.items():
                if (r := classify_body(b)) is not None:
                    seen[r[0]][r[1]] = r[2]
            for motion, frames in sorted(seen.items()):
                pure = sorted(k for k, v in frames.items() if v == "pure")
                held = {k: v for k, v in sorted(frames.items())
                        if v != "pure"}
                print(f"  {port:<6}{stage:<9}{motion:<5}"
                      f"stubs {pure}")
                print(f"  {'':20}excluded {held if held else '{}'}")
                for k, v in held.items():
                    if not v.startswith("play"):
                        print(f"  ** {port}/{stage} frame {k} is held back by "
                              f"'{v}', not a sound", file=sys.stderr)
                        bad += 1
    if bad:
        print(f"\nFAIL: {bad} hole(s) are not footsteps", file=sys.stderr)
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
