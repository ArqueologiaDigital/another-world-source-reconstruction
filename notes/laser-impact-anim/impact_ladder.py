#!/usr/bin/env python3
"""Read CAVES' laser-impact flash off its dispatch ladder, by evaluating it.

Question answered
-----------------
`../sole-named-drawer/nameable_from_drawer.py` offered six names here and every
one of them was wrong, in the same way:

    amiga/CAVES  CINEMATIC_777  ->  CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_ABOVE_04

`CAVES_LASER_IMPACT_ANIM_RIGHT_ABOVE_04` is not a frame. It is an **interior
node of a binary search** over the timer `[0x13]`:

    CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT:
        jge [0x13], 0x64, <elsewhere>
        jle [0x13], 0x03, ..._RIGHT_ABOVE_02     <- so this arm is v <= 3
        jle [0x13], 0x05, ..._RIGHT_ABOVE_04     <- and this one is 4 <= v <= 5
        video offset=CINEMATIC_778               <- and the fallthrough is v >= 6

The label `..._ABOVE_04` is reached for v in {4,5} and the picture drawn there
is the one for v == 5, so inheriting the label's number onto the constant gets
the frame off by one *and* records a search threshold where a frame index
belongs. Worse, it names only the three pictures whose branch happens to carry
a named label and leaves the other three behind `DRAW_CIN_<n>` fallthroughs,
which is where the 01/02/04 "family gap" came from: the gap is in which labels
were named, not in the art.

So this module does not read labels. It **evaluates** the ladder for each timer
value and reports the picture that value actually draws.

What the evaluation shows (both priority ports, identical)
----------------------------------------------------------
Six pictures per direction, a one-shot flash driven by a counter that the
caller increments once per tick:

    CAVES_LASER_IMPACT_ANIM_ADVANCE_RIGHT:
        and [0x13], 0x7FFF          <- low 15 bits are the counter,
        mov [0x0E], 0x0000             the high bit marks the slot busy
        call CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT
        add [0x13], 0x0001          <- one frame per tick
        or  [0x13], 0x8000

`CAVES_LASER_SHOT_IMPACT_RESOLVE_RIGHT` seeds `[0x13] = 0x0001` and the helper
it calls never writes `[0x13]`, so the run is v = 1,2,3,4,5,6; at v >= 6 the
dispatch writes `[0x13] = 0xFFFE`, which the `add`/`or` turn into 0xFFFF, the
value `CAVES_LASER_SHOT_SLOTS_UPDATE_LOOP` reads as "slot free". A closed run
with a terminator, so the index is the machine's own and has no gap.

The geometry is a flash: it grows for four frames and leaves a residue.

    v=1   2.0 x  5.0  6 leaves        v=4  17.0 x 17.0  6 leaves
    v=2   9.0 x 10.0  6 leaves        v=5  16.0 x 17.0  4 leaves
    v=3  17.0 x 12.0  7 leaves        v=6   4.0 x  6.0  2 leaves

The signal read is the `video offset=` operand reached by evaluating the
ladder at each v, and the extent/leaf count of the polygon tree at that
constant's EQU value in the CAVES cinematic bank. All twelve pictures are
byte-identical (`canonical_md5`) between amiga and msdos; LEFT and RIGHT are
different art, as mirrored sprites are.

Pass/fail
---------
Exits 1 if a direction does not evaluate to exactly six distinct pictures over
v = 1..6, if any constant named in the ladder has no EQU, or if the amiga and
msdos series stop agreeing. That makes it a read-back check after renaming as
well as the derivation: it follows whatever the ladder says today, so a rename
that put a name on the wrong frame would show up here as a changed mapping.

Usage
-----
    python3 notes/laser-impact-anim/impact_ladder.py
    python3 notes/laser-impact-anim/impact_ladder.py --proposals
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
sys.path.insert(0, str(SRC.parent / "another-world-archaeology" / "tools"))
sys.path.insert(0, str(SRC / "notes" / "polygon-extent-correction"))

from polygon_tree import parse_polygon_tree, canonical_md5   # noqa: E402
from polygon_extent import extent                            # noqa: E402
from extent_matches_renderer import slab                     # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGE, STAGE_ID = "CAVES", 4
TIMER = "0x13"
VALUES = range(1, 7)
DISPATCH = "CAVES_LASER_IMPACT_ANIM_DISPATCH_{}"

RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
RE_CMP = re.compile(r"^\s*(jge|jle|jl|jg|je|jne)\s+\[" + TIMER
                    + r"\],\s*(0x[0-9A-Fa-f]+),\s*([A-Za-z_][A-Za-z0-9_]*)")
RE_JMP = re.compile(r"^\s*jmp\s+([A-Za-z_][A-Za-z0-9_]*)")
RE_VID = re.compile(r"^\s*video\s+offset=([A-Za-z_][A-Za-z0-9_]*)")
RE_SET = re.compile(r"^\s*mov\s+\[" + TIMER + r"\],\s*(0x[0-9A-Fa-f]+)")
RE_RET = re.compile(r"^\s*ret\s*$")
RE_EQU = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)

TAKEN = {"jge": lambda v, k: v >= k, "jle": lambda v, k: v <= k,
         "jl": lambda v, k: v < k, "jg": lambda v, k: v > k,
         "je": lambda v, k: v == k, "jne": lambda v, k: v != k}


def evaluate(lines: list[str], labels: dict[str, int], start: str, v: int):
    """Walk the ladder for timer value `v`; return (constant, terminates)."""
    pc, seen, terminal = labels[start], 0, False
    while pc < len(lines):
        if (seen := seen + 1) > 4000:
            raise RuntimeError(f"{start} v={v}: no draw reached")
        line = lines[pc]
        if m := RE_CMP.match(line):
            op, k, target = m.group(1), int(m.group(2), 16), m.group(3)
            pc = labels[target] if TAKEN[op](v, k) else pc + 1
            continue
        if m := RE_JMP.match(line):
            pc = labels[m.group(1)]
            continue
        if m := RE_SET.match(line):
            terminal = True
        if m := RE_VID.match(line):
            return m.group(1), terminal
        if RE_RET.match(line):
            return None, terminal
        pc += 1
    return None, terminal


def series(branch: str, direction: str):
    text = (SRC / "src" / "levels" / branch / f"{STAGE}.asm").read_text(
        errors="replace")
    lines = text.splitlines()
    labels = {m.group(1): i for i, line in enumerate(lines)
              if (m := RE_LBL.match(line))}
    equ = {n: int(val, 16) for n, val in RE_EQU.findall(text)}
    start = DISPATCH.format(direction)
    if start not in labels:
        raise SystemExit(f"{branch}: {start} not found -- ladder restructured")
    out = []
    for v in VALUES:
        const, terminal = evaluate(lines, labels, start, v)
        if const is None:
            raise SystemExit(f"{branch}/{direction} v={v}: no picture drawn")
        if const not in equ:
            raise SystemExit(f"{branch}/{direction} v={v}: {const} has no EQU")
        out.append((v, const, equ[const], terminal))
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--proposals", action="store_true",
                    help="emit the per-branch proposal tables")
    args = ap.parse_args()

    banks = {p: slab("cinematic", p, STAGE_ID) for p in PORTS}
    table, bad = {}, 0
    for direction in ("RIGHT", "LEFT"):
        for port, branch in PORTS.items():
            rows = series(branch, direction)
            hashes = []
            if not args.proposals:
                print(f"\n{port}/{direction}    "
                      f"[{TIMER}] -> picture drawn")
            for v, const, off, terminal in rows:
                tree = parse_polygon_tree(banks[port], off)
                x0, y0, x1, y1, leaves = extent(tree)
                h = canonical_md5(tree)
                hashes.append(h)
                if not args.proposals:
                    print(f"  v={v}{'+' if terminal else ' '} {const:<46}"
                          f"{x1 - x0:5.1f} x{y1 - y0:5.1f}  "
                          f"{leaves} leaves  {h[:8]}")
            if len({h for h in hashes}) != len(VALUES):
                print(f"  ** {port}/{direction}: {len(VALUES)} values map to "
                      f"{len(set(hashes))} distinct pictures", file=sys.stderr)
                bad += 1
            table[(port, direction)] = (rows, hashes)

    print("\ncross-port agreement (the name is a shared claim only if these "
          "agree)")
    for direction in ("RIGHT", "LEFT"):
        (ra, ha), (rm, hm) = table[("amiga", direction)], table[("msdos", direction)]
        for (v, ca, _o, _t), cm, a, m in zip(ra, [r[1] for r in rm], ha, hm):
            ok = a == m
            bad += not ok
            print(f"  {direction:<6}v={v}  {ca:<46}{cm:<46}"
                  f"{'same art' if ok else '** DIFFERENT **'}")

    if args.proposals:
        for port, branch in PORTS.items():
            print(f"\n----- {branch} -----")
            print("| constant | proposed name | confidence | evidence |")
            print("| --- | --- | --- | --- |")
            for direction in ("RIGHT", "LEFT"):
                for v, const, _o, _t in table[(port, direction)][0]:
                    print(f"| {const} | CINEMATIC_CAVES_LASER_IMPACT_ANIM_"
                          f"{direction}_F{v:02d} | high | "
                          f"`{DISPATCH.format(direction)}` draws it when the "
                          f"impact timer `[{TIMER}]` (masked with 0x7FFF, "
                          f"incremented once per tick) holds {v}"
                          f"{'; at this value the dispatch also writes '
                             '`[0x13] = 0xFFFE`, freeing the slot'
                             if _t else ''} |")

    if bad:
        print(f"\nFAIL: {bad} check(s) failed", file=sys.stderr)
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
