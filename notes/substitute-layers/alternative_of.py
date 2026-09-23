#!/usr/bin/env python3
"""Find the branch that chooses between a named picture and an unnamed one.

Question answered
-----------------
The shared bank went from 77 unnamed keys to 57 in two passes, and both used
the same move: not looking at the art, but finding the **conditional that
picks between it and something already named**.

    CAPSULE_ACTOR_RUN_RIGHT_DRAW_2:
        video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F02, ...
        je [0x0D], 0x00, LABEL_6A11
        call LABEL_691B                                    <- the unnamed one
        jmp LABEL_6A16
    LABEL_6A11:
        video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_02, ...  <- named

Whatever `[0x0D]` means, the two arms draw the same thing in two states, so
the unnamed piece is a variant of the named one and inherits everything but
the variance. That is a far stronger handle than a render: it survives not
knowing what the picture depicts.

This generalises the move. For every two-armed conditional it compares what
each arm draws, and reports the pairs where exactly one side is named.

What it will not claim
----------------------
The pairing says "these two are alternatives", not what the difference *is*.
`CV_3B44` was named `..._GUN_UPPER_RIGHT_POSE_00` only because a second line
of evidence -- leaf count against its counterpart, 6 against 2, the gun added
-- said what the variance was. This module stops at the pairing and reports
how many distinct named counterparts each unnamed piece has, because a piece
that substitutes for eight different frames is a shared variant and cannot
take any one of their names.

Pass/fail
---------
Exits 0; it is a proposer of leads, not a check.

Usage
-----
    python3 notes/substitute-layers/alternative_of.py
    python3 notes/substitute-layers/alternative_of.py --var 0x0D
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

BRANCHES = ("chahi_amiga_1991", "dos_1992")
RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
RE_V = re.compile(r"^\s*video\s+(?:type=\d+,\s*)?offset="
                  r"([A-Za-z_][A-Za-z0-9_]*),")
RE_CALL = re.compile(r"^\s*call\s+([A-Za-z_][A-Za-z0-9_]*)")
RE_COND = re.compile(r"^\s*(je|jne)\s+\[([A-Za-z0-9_]+)\],\s*"
                     r"(0x[0-9A-Fa-f]+),\s*([A-Za-z_][A-Za-z0-9_]*)")
RE_UNNAMED = re.compile(r"^(CV_[0-9A-F]{4}|CINEMATIC_\d+)$")
MAX_DEPTH = 2
LOOKAHEAD = 4


def bodies(lines):
    out, cur = collections.defaultdict(list), None
    for line in lines:
        if m := RE_LBL.match(line):
            cur = m.group(1)
        elif cur:
            out[cur].append(line)
    return out


def draws(body, lab, depth=0, seen=None):
    seen = seen or set()
    if lab in seen or depth > MAX_DEPTH:
        return []
    seen = seen | {lab}
    out = []
    for line in body.get(lab, []):
        if v := RE_V.match(line):
            out.append(v.group(1))
        elif c := RE_CALL.match(line):
            out += draws(body, c.group(1), depth + 1, seen)
    return out


def scan(var_filter=None):
    pairs = collections.defaultdict(collections.Counter)
    gate = collections.defaultdict(collections.Counter)
    for branch in BRANCHES:
        for f in sorted((SRC / "src" / "levels" / branch).glob("[A-Z]*.asm")):
            lines = f.read_text(errors="replace").splitlines()
            body = bodies(lines)
            for lab, b in body.items():
                for i, line in enumerate(b):
                    m = RE_COND.match(line)
                    if not m:
                        continue
                    _op, var, _val, target = m.groups()
                    if var_filter and var != var_filter:
                        continue
                    # the fallthrough arm: the next draw or call
                    here = []
                    for nxt in b[i + 1:i + 1 + LOOKAHEAD]:
                        if v := RE_V.match(nxt):
                            here.append(v.group(1))
                        elif c := RE_CALL.match(nxt):
                            here += draws(body, c.group(1), 1)
                        if here:
                            break
                    there = draws(body, target)
                    if not here or not there:
                        continue
                    for a in here[:1]:
                        for bb in there[:1]:
                            if a == bb:
                                continue
                            au, bu = RE_UNNAMED.match(a), RE_UNNAMED.match(bb)
                            if au and not bu:
                                pairs[a][bb] += 1
                                gate[a][var] += 1
                            elif bu and not au:
                                pairs[bb][a] += 1
                                gate[bb][var] += 1
    return pairs, gate


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--var", help="only this gate variable, e.g. 0x0D")
    args = ap.parse_args()
    pairs, gate = scan(args.var)

    one = {k: v for k, v in pairs.items() if len(v) == 1}
    many = {k: v for k, v in pairs.items() if len(v) > 1}
    print(f"  {len(pairs)} unnamed picture(s) sit opposite a named one "
          f"across a conditional")
    print(f"    {len(one):>5}  have exactly ONE named counterpart")
    print(f"    {len(many):>5}  have several -- a shared variant, so no one "
          f"name fits")
    if one:
        print("\n  the single-counterpart leads:")
        for k, v in sorted(one.items()):
            other, n = v.most_common(1)[0]
            g = ", ".join(sorted(gate[k]))
            print(f"    {k:<16}opposite {other:<46}"
                  f"{n}x on [{g}]")
    return 0


if __name__ == "__main__":
    sys.exit(main())
