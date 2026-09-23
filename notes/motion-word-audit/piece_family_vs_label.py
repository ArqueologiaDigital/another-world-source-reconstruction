#!/usr/bin/env python3
"""A routine's gait is the gait of the pieces it draws.

Question answered
-----------------
`motion_vs_drawer.py` leaves one class it cannot dismiss: five PRISON frames
named `CV_FIGURE_RUN_LEFT_BODY_F<nn>` drawn only by
`PRISON_ACTOR_WALK_LEFT_PHASE_<n>_DONE`. Two names, one animation, and no way
to pick a winner from the names alone (#0120).

This module picks it from the *pieces*, which is not a name contest. The
shared bank's figure families -- `CV_FIGURE_WALK_*`, `CV_FIGURE_RUN_*`,
`CV_FIGURE_CRAWL_*` -- were named from geometry in
`../shared-bank-geometry/` and `../actor-sprite-sheet/`, independently of any
stage's label conventions. So: resolve everything a label draws, following
`call`/`jmp` two levels deep, and ask which figure families those pieces come
from. A label that draws pieces from exactly **one** family while its own name
says a different motion is making a claim its own body contradicts.

What it finds
-------------
The three stages that animate this actor split cleanly except for one:

    amiga/CAVES     RUN  PHASE -> RUN  (30)     WALK PHASE -> WALK (19)
    amiga/CAPSULE   RUN  DRAW  -> RUN  (30)
    amiga/PRISON    RUN  POSE  -> RUN  (6)      WALK POSE  -> WALK (46)
                    WALK PHASE -> RUN (10) + WALK (19)      <- mixed

CAVES draws the same two sequences as PRISON and keeps them apart: its
`WALK ... PHASE` labels draw 19 WALK pieces and its `RUN ... PHASE` labels
draw RUN pieces. PRISON's `WALK ... PHASE` family holds **both** -- the same
19 WALK draws, and 10 more that are pure RUN. The 19 matching exactly is the
corroboration: PRISON is not using a different scheme, it has ten labels in
the wrong half of its own.

The ten, identical in both priority ports and unambiguous -- not one of them
draws a piece from more than one family:

    PRISON_ACTOR_WALK_LEFT_PHASE_{0,3,5,7,8}_DONE
    PRISON_BUDDY_WALK_LEFT_PHASE_{0,3,5,7,8}

each drawing `CV_FIGURE_RUN_LEFT_BODY_F<nn>` together with a
`CV_FIGURE_RUN_LEFT_UPPER_POSE_<nn>`. A body and an upper from the run sheet,
under a label that says walk.

Why the pieces win
------------------
Because they are the older and better-evidenced claim. The figure families
were derived from measured geometry across stages, and two stages that never
consulted each other -- CAPSULE (`..._ACTOR_RUN_LEFT_DRAW_<n>`) and CAVES
(`..._ACTOR_RUN_LEFT_PHASE_<n>`) -- call this same code RUN. The identical
routine appears in all three: same shape, same `sub [<actor>_Y], 0x0001`, same
`CV_320A` fallback, same two draws. PRISON is one vote against two, and its
own vote is internally split, since it already carries three
`PRISON_ACTOR_RUN_LEFT_*` labels in the same region.

Pass/fail
---------
Exits 1 if any label draws pieces from exactly one figure family while naming
a different motion, because unlike the drawer comparison this one has no
benign explanation: a body and an upper from one sheet is what the routine
draws, not what it exits into. Ambiguous labels -- pieces from two families --
are reported separately and never failed.

Usage
-----
    python3 notes/motion-word-audit/piece_family_vs_label.py
    python3 notes/motion-word-audit/piece_family_vs_label.py --proposals
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]

BRANCHES = ("chahi_amiga_1991", "dos_1992", "cartridge_1992", "gba_2004")
MOTIONS = ("WALK", "RUN", "CRAWL")

RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
RE_VID = re.compile(r"^\s*video\s+(?:type=\d+,\s*)?offset="
                    r"([A-Za-z_][A-Za-z0-9_]*)")
RE_CALL = re.compile(r"^\s*(?:call|jmp)\s+([A-Za-z_][A-Za-z0-9_]*)")
RE_PIECE = re.compile(r"^CV_FIGURE_(" + "|".join(MOTIONS) + r")_")
MAX_DEPTH = 2


def label_bodies(lines: list[str]) -> dict[str, list[str]]:
    body: dict[str, list[str]] = collections.defaultdict(list)
    cur = None
    for line in lines:
        if m := RE_LBL.match(line):
            cur = m.group(1)
        elif cur:
            body[cur].append(line)
    return body


def resolved_draws(body, lab, depth=0, seen=None) -> set[str]:
    """Everything `lab` draws, following call/jmp up to MAX_DEPTH."""
    seen = seen or set()
    if lab in seen or depth > MAX_DEPTH:
        return set()
    seen = seen | {lab}
    out: set[str] = set()
    for line in body.get(lab, []):
        if v := RE_VID.match(line):
            out.add(v.group(1))
        elif c := RE_CALL.match(line):
            out |= resolved_draws(body, c.group(1), depth + 1, seen)
    return out


def label_motion(lab: str) -> set[str]:
    return {m for m in MOTIONS if f"_{m}_" in lab}


def scan():
    wrong, ambiguous = [], []
    for branch in BRANCHES:
        d = SRC / "src" / "levels" / branch
        if not d.is_dir():
            continue
        for f in sorted(d.glob("[A-Z]*.asm")):
            body = label_bodies(f.read_text(errors="replace").splitlines())
            for lab in sorted(body):
                lm = label_motion(lab)
                if len(lm) != 1:
                    continue
                pieces = {p for p in resolved_draws(body, lab)
                          if RE_PIECE.match(p)}
                if not pieces:
                    continue
                fams = {RE_PIECE.match(p).group(1) for p in pieces}
                if len(fams) > 1:
                    if lm & fams:
                        continue
                    ambiguous.append((branch, f.stem, lab, sorted(fams),
                                      sorted(pieces)))
                elif not (lm & fams):
                    wrong.append((branch, f.stem, lab, next(iter(fams)),
                                  sorted(pieces), next(iter(lm))))
    return wrong, ambiguous


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--proposals", action="store_true")
    args = ap.parse_args()
    wrong, ambiguous = scan()

    if args.proposals:
        by: dict[tuple, list] = {}
        for branch, stage, lab, fam, pieces, said in wrong:
            by.setdefault((branch, stage), []).append((lab, fam, pieces, said))
        for (branch, stage), rows in sorted(by.items()):
            print(f"\n----- {branch} / {stage} -----")
            print("| routine | proposed name | confidence | evidence |")
            print("| --- | --- | --- | --- |")
            for lab, fam, pieces, said in rows:
                print(f"| {lab} | {lab.replace(f'_{said}_', f'_{fam}_')} | "
                      f"high | every figure piece it draws is from the "
                      f"{fam} sheet ({', '.join(pieces)}), and no piece from "
                      f"any other; the name says {said} |")
        return 0

    print(f"{len(wrong)} label(s) name one motion and draw pieces from "
          f"exactly one OTHER figure family:\n")
    for branch, stage, lab, fam, pieces, said in wrong:
        print(f"  {branch.split("_")[0]:<10}{stage:<9}{lab:<44}"
              f"says {said:<6}draws {fam}: {', '.join(pieces)}")
    if ambiguous:
        print(f"\n{len(ambiguous)} label(s) draw pieces from two families and "
              f"match neither -- reported, not failed:")
        for branch, stage, lab, fams, pieces in ambiguous:
            print(f"  {branch:<17}{stage:<9}{lab:<44}{fams}")
    return 1 if wrong else 0


if __name__ == "__main__":
    sys.exit(main())
