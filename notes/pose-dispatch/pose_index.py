#!/usr/bin/env python3
"""Every picture a sprite dispatcher selects, with the index it is selected by.

Question answered
-----------------
CAPSULE picks an actor's picture with a two-level dispatch. Both of its
dispatchers begin identically:

    mov [0xF8], [0x09]        ; the selector byte
    shr [0xF8], 0x0004        ; its HIGH NIBBLE is the sub-index
    and [0xF8], 0x000F
    jne [0x0E], 0x00, <next group>
    je  [0xF8], 0x00, DRAW_CIN_195
    je  [0xF8], 0x01, DRAW_CIN_196
    ...

so `[0x0E]` chooses a group and the high nibble of `[0x09]` chooses a frame
within it, and each target is a one-line routine that draws exactly one
constant. That is an index **out of the bytecode** -- no render, no palette, no
judgement -- for every picture the dispatcher can reach.

This matters because those targets are otherwise the hardest kind of constant
to name: 37 of them in amiga/CAPSULE are each drawn by their own generated
`DRAW_CIN_<n>` routine and by nothing else, so there is no run to read, no
neighbour to compare against and no earned routine word.

What it reports
---------------
One row per reachable target: dispatcher, group, index, the routine and the
constant it draws. Targets whose routine draws more than one picture, or none,
are reported separately rather than guessed at.

The group tracking follows the chain's own shape: `jne [G], 0xNN, <label>`
means "if we fall through, [G] == NN", so the rows after it belong to group NN
-- **until the arm ends**. An arm ends at its `ret`, and nothing is recorded
again until the next `jne [G], ...` opens another. Without that, every `je
[0xF8], ...` later in the file was being attributed to the last group seen, and
group 7 collected six unrelated targets.

Run it
------
    python3 notes/pose-dispatch/pose_index.py --branch chahi_amiga_1991 --stage CAPSULE
    python3 notes/pose-dispatch/pose_index.py ... --unnamed     # only what is still numbered
"""
from __future__ import annotations

import argparse
import collections
import pathlib
import re

SRC = pathlib.Path(__file__).resolve().parents[2] / "src" / "levels"

RE_LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
RE_JNE = re.compile(r"^\s*jne\s+\[(0x[0-9A-Fa-f]+)\],\s*(0x[0-9A-Fa-f]+),\s*(\S+)")
RE_JE = re.compile(r"^\s*je\s+\[(0x[0-9A-Fa-f]+)\],\s*(0x[0-9A-Fa-f]+),\s*(\S+)")
RE_SEL = re.compile(r"^\s*shr\s+\[(0x[0-9A-Fa-f]+)\],\s*0x0*4\s*$")
RE_DRAW = re.compile(r"video\s+(?:type=\d+,\s*)?offset=(CINEMATIC_[A-Za-z0-9_]+)")
RE_NUMBERED = re.compile(r"^CINEMATIC_\d+$")


def routine_bodies(lines: list[str]) -> dict[str, list[str]]:
    out: dict[str, list[str]] = {}
    cur = None
    for line in lines:
        m = RE_LABEL.match(line)
        if m:
            cur = m.group(1)
            out.setdefault(cur, [])
            continue
        if cur is not None:
            out[cur].append(line)
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--branch", default="chahi_amiga_1991")
    ap.add_argument("--stage", default="CAPSULE")
    ap.add_argument("--unnamed", action="store_true")
    args = ap.parse_args()

    lines = (SRC / args.branch / f"{args.stage}.asm").read_text().splitlines()
    bodies = routine_bodies(lines)

    # A dispatcher starts at a `shr [V], 4`; the group variable is whatever the
    # following `jne` tests. Everything until the next `shr` belongs to it.
    rows = []
    odd = []
    dispatcher = None
    group = None
    group_var = None
    cur_label = None
    for line in lines:
        m = RE_LABEL.match(line)
        if m:
            cur_label = m.group(1)
            continue
        if RE_SEL.match(line):
            dispatcher = cur_label
            group, group_var = 0, None
            continue
        if dispatcher is None:
            continue
        if re.match(r"^\s*(ret|killChannel)\s*$", line):
            group = None          # this arm is over; wait for the next group test
            continue
        j = RE_JNE.match(line)
        if j:
            var, val, _ = j.groups()
            if group_var is None or var == group_var:
                group_var, group = var, int(val, 16)
            continue
        e = RE_JE.match(line)
        if e:
            if group is None:
                continue
            var, val, target = e.groups()
            if var == group_var:          # a group test, not an index test
                group = int(val, 16)
                continue
            body = bodies.get(target)
            if body is None:
                odd.append((dispatcher, group, int(val, 16), target, "no such label"))
                continue
            consts = []
            for b in body:
                d = RE_DRAW.search(b)
                if d:
                    consts.append(d.group(1))
                if re.match(r"^\s*(ret|jmp\s|killChannel)", b):
                    break
            if len(consts) == 1:
                rows.append((dispatcher, group, int(val, 16), target, consts[0]))
            else:
                odd.append((dispatcher, group, int(val, 16), target,
                            f"{len(consts)} draws"))

    if args.unnamed:
        rows = [r for r in rows if RE_NUMBERED.match(r[4])]

    by_disp = collections.defaultdict(list)
    for r in rows:
        by_disp[r[0]].append(r)

    print(f"  {args.branch.split('_')[0]}/{args.stage}: "
          f"{len(rows)} dispatched target(s) in {len(by_disp)} dispatcher(s)"
          + (", still numbered only" if args.unnamed else "") + "\n")
    for disp, rs in by_disp.items():
        print(f"    {disp}")
        for _, g, i, target, const in sorted(rs, key=lambda r: (r[1], r[2])):
            print(f"        group {g:>2}  index {i:>2}   {target:<34} {const}")
        print()
    if odd:
        print("  not single-draw targets, reported rather than guessed at:")
        for disp, g, i, target, why in odd:
            print(f"      {disp} group {g} index {i} -> {target}: {why}")

    seen = collections.Counter((r[0], r[1], r[2]) for r in rows)
    dupes = [k for k, v in seen.items() if v > 1]
    if dupes:
        print(f"\n  {len(dupes)} (dispatcher, group, index) triple(s) claimed twice "
              f"-- an index alone would not be unique")
    else:
        print("\n  every (dispatcher, group, index) is unique, so the triple names "
              "the picture")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
