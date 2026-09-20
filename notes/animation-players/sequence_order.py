#!/usr/bin/env python3
"""Take the frame order from a routine that plays the animation, not from a name.

Question answered
-----------------
`hero_pose_consensus.py` names shared-bank art when independent stages agree
on a motion, a direction and a frame ordinal *spelled in the drawer's name*.
Two whole hero families have no such ordinal anywhere and stayed unnamed: the
26 jump frames at `0x4D98..0x514C` and `0x52C0..0x5444`.

They do not need one. The routine that draws them is a straight-line
animation player:

    HERO_JUMP_RIGHT_FROM_STAND:
        video type=0, offset=CV_4D98, x=[HERO_X], ...
        break
        video type=0, offset=CV_4DE4, x=[HERO_X], ...
        break
        ...
        video type=0, offset=CV_4E7C, ...
        add [HERO_X], 0x0005            <- the arc, frame by frame
        break

Draw, `break`, draw, `break`. **The draw order is the frame order**, stated by
the code rather than inferred from a label. That is a different thing from a
dispatcher, which selects one of N frames with a `jne` chain, and the
difference is what this probe tests.

Why these were invisible
------------------------
`hero_pose_consensus.py` rule 8 rejects any routine drawing more than two
pictures, because a per-frame dispatcher like `PRISON_HERO_STAND_LEFT_TICK`
reaches eight walk frames and would assert STAND about all of them. A player
draws twelve and is excluded by the same rule -- correctly, for that probe's
purpose, and wrongly for this one. A dispatcher *branches to* one of its
frames; a player *draws all of them in order*. Separating the two is what
makes a twelve-draw routine usable evidence.

The tests
---------
A named routine qualifies as a player for a family when:

  - its name carries a motion and a direction;
  - every draw is at the same slot and its operands are all still unnamed
    bank keys;
  - the draws are separated by `break` and **no conditional jump appears
    between the first and last of them** -- so nothing selects among them;
  - the sequence is strictly increasing in bank offset, so sheet order and
    play order agree;
  - every port and stage that has the routine yields the same sequence.

Where two players share a family, the frame numbers come from the **ascending
union** of their sequences, and each player's own sequence must be a
subsequence of it. For the jump that is a real check rather than a formality:
`HERO_JUMP_RIGHT_FROM_STAND` draws twelve frames skipping `CV_4FBC`, and
`HERO_JUMP_RIGHT_FROM_RUN` draws eight including it. Both are subsequences of
the same thirteen, which is what says they are two entries into one
animation rather than two animations.

What it found, 2026-09-20: six players, and every one contested
----------------------------------------------------------------
    JUMP_RIGHT   HERO_JUMP_RIGHT_FROM_STAND   12 frames   0x4D98..0x514C
    JUMP_LEFT    HERO_JUMP_LEFT_FROM_STAND    12 frames   0x52C0..0x5444
    CRAWL_RIGHT  PRISON_HERO_CRAWL_RIGHT_START 6 frames   0x448C..0x4C40
    CRAWL_LEFT   PRISON_HERO_CRAWL_LEFT_START  6 frames   0x57C4..0x5B4C
    RUN_LEFT     HERO_RUN_LEFT_BURST_LOOP     12 frames   0x52C0..0x5444
    WALK_RIGHT   HERO_WALK_RIGHT_LOOP         12 frames   0x4D98..0x514C

The last two are the first two. One thirteen-frame sheet per direction is
played by `HERO_JUMP_*_FROM_STAND` and `HERO_JUMP_*_FROM_RUN` in CAVES, by
`PRISON_HERO_WALK_JUMP_*` and `PRISON_HERO_RUN_JUMP_*` in PRISON, and by
`HERO_WALK_RIGHT_LOOP` / `HERO_RUN_LEFT_BURST_LOOP` in LAKE and CAPSULE.
JUMP, WALK and RUN for one animation.

Measured, to see whether the code settles it: the net X step per frame is
**identical** in the CAVES and LAKE versions -- 5, 7, 13, 12, 2, 7, 4, 7 (the
extra ±15 and ±12 pairs in CAVES bracket a `CAVES_SCREEN_STEP_UP_ONE_ROW_L4`
call and cancel) -- and **neither writes `HERO_Y` at all**. So the two are the
same motion under two names and the code does not say which name is right.

It is not resolved here. #0120: a tool must not pick a winner between two
semantic names, and neither may its author when the tally is CAVES against
LAKE and CAPSULE with PRISON's `_WALK_JUMP_` saying both. The crawl families
are contested the same way -- `HERO_PRONE_RISE_LEFT` in CAVES,
`HERO_WALK_LEFT_STOP_TO_GUN_READY` in CAPSULE,
`PRISON_HERO_CRAWL_LEFT_START` in PRISON -- so **nothing is proposed**.

That is the result worth recording: the hero art still unnamed is not art
nobody has looked at. It is the art the stages **disagree about**, and the
disagreement is about what the motion is called, not about which picture it
is. Settling it needs the game, not another probe.

Usage
-----
    python3 notes/animation-players/sequence_order.py
    python3 notes/animation-players/sequence_order.py --proposals
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
sys.path.insert(0, str(HERE.parents[1] / "shared-bank-geometry"))
import hero_pose_consensus as H                     # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES",
          "TANK", "CAPSULE", "ENDING", "PASSCODE"]
RE_LABEL = re.compile(r"^([A-Za-z_]\w*):")
RE_DRAW = re.compile(r"^\s*video\s+type=0,\s*offset=(\w+),\s*x=\[(\w+)\]")
RE_COND = re.compile(r"^\s*(jne|je|jl|jg|jle|jge|dbra)\b")
RE_KEY = re.compile(r"^CV_[0-9A-F]{4}$")


def players(text: str):
    """Named routines that draw a straight-line sequence of bank keys."""
    lines = [l.split(";", 1)[0] for l in text.splitlines()]
    bounds = [(i, m.group(1)) for i, l in enumerate(lines)
              if (m := RE_LABEL.match(l))]
    out = {}
    for n, (start, name) in enumerate(bounds):
        end = bounds[n + 1][0] if n + 1 < len(bounds) else len(lines)
        seq, slots, cond = [], set(), False
        first = last = None
        for i in range(start, end):
            d = RE_DRAW.match(lines[i])
            if d:
                seq.append(d.group(1))
                slots.add(d.group(2))
                first = i if first is None else first
                last = i
            elif RE_COND.match(lines[i]):
                cond = True if first is not None else cond
        if len(seq) < 4 or len(slots) != 1:
            continue
        # a conditional anywhere between the first and last draw disqualifies
        if any(RE_COND.match(lines[i]) for i in range(first, last)):
            continue
        if not all(RE_KEY.match(s) for s in seq):
            continue
        out[name] = tuple(seq)
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--proposals", action="store_true")
    args = ap.parse_args()

    H.SUBJECT[0] = "hero"
    offs, _art, _by = H.collect()

    found: dict[str, set] = collections.defaultdict(set)
    where: dict[str, set] = collections.defaultdict(set)
    for port, br in PORTS.items():
        for stage in STAGES:
            p = SRC / "src" / "levels" / br / f"{stage}.asm"
            if not p.is_file():
                continue
            for name, seq in players(p.read_text(errors="replace")).items():
                found[name].add(seq)
                where[name].add(f"{port}/{stage}")

    ok = {}
    for name, seqs in sorted(found.items()):
        m = H.RE_MOTION.search("_" + name + "_")
        if not m:
            continue
        if len(seqs) != 1:
            print(f"  {name}: ports disagree on the sequence, skipped")
            continue
        seq = next(iter(seqs))
        if any(s not in offs for s in seq):
            continue
        if [offs[s] for s in seq] != sorted(offs[s] for s in seq):
            print(f"  {name}: play order is not sheet order, skipped")
            continue
        ok[name] = (m.group(1), m.group(2), seq)

    fams: dict[tuple, list] = collections.defaultdict(list)
    for name, (mo, di, seq) in ok.items():
        fams[(mo, di)].append((name, seq))

    # A sheet played under two different motion words is contested. Group the
    # families by the offsets they cover, not by the motion their player
    # happens to assert, so the collision is visible instead of producing two
    # numberings of one animation.
    by_sheet: dict[frozenset, set] = collections.defaultdict(set)
    for key, members in fams.items():
        sheet = frozenset(s for _n, seq in members for s in seq)
        by_sheet[sheet].add(key)
    contested = {k for ks in by_sheet.values() if len(ks) > 1 for k in ks}

    proposals: list[tuple[str, str]] = []
    print(f"\n{len(ok)} animation player(s) in {len(fams)} famil(y/ies)\n")
    for key, members in sorted(fams.items()):
        union = sorted({s for _n, seq in members for s in seq},
                       key=lambda s: offs[s])
        good = True
        for name, seq in sorted(members):
            sub = iter(union)
            issub = all(any(x == y for y in sub) for x in seq)
            print(f"  {'_'.join(key):<18}{name:<32}{len(seq):3d} frames"
                  f"{'' if issub else '   NOT a subsequence of the union'}")
            good &= issub
        print(f"  {'':<18}union: {len(union)} frames "
              f"0x{offs[union[0]]:04X}..0x{offs[union[-1]]:04X}"
              f"{'' if good else '   HELD'}")
        if key in contested:
            others = sorted("_".join(k) for ks in by_sheet.values()
                            if key in ks for k in ks if k != key)
            print(f"  {'':<18}HELD: the same sheet is also played as "
                  f"{', '.join(others)}")
            good = False
        if good:
            for i, s in enumerate(union):
                proposals.append((s, f"HERO_{key[0]}_{key[1]}_F{i:02d}"))
        print()

    if args.proposals:
        for cv, name in proposals:
            print(f"{cv} {name}")
    else:
        print(f"{len(proposals)} nameable; --proposals for the map.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
