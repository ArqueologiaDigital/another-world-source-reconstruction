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

# Branch -> the port whose extracted ROM carries that branch's art. A branch
# with no ROM still gets its ladder evaluated -- the timer-to-constant mapping
# is read from the branch's own source and needs no art -- it only loses the
# geometry and the cross-branch md5 comparison.
BRANCH_PORT = {"chahi_amiga_1991": "amiga", "dos_1992": "msdos",
               "cartridge_1992": "snes_eu"}
PRIORITY = ("chahi_amiga_1991", "dos_1992")
STAGE_ID = {"PRISON": 3, "CAVES": 4, "CAPSULE": 6}
TIMER = "0x13"
VALUES = range(1, 7)

# A dispatch entry is discovered, not listed: the block containing the second
# comparison of the binary search, `jle [<timer>], 0x05, <arm>`, is the entry.
# Six exist per branch -- three stages times two directions -- and none exists
# in gba_2004, which drops the effect.
RE_SIG = re.compile(r"^\s*jle\s+\[" + TIMER + r"\],\s*0x0*5,")

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


def load(branch: str, stage: str):
    text = (SRC / "src" / "levels" / branch / f"{stage}.asm").read_text(
        errors="replace")
    lines = text.splitlines()
    labels = {m.group(1): i for i, line in enumerate(lines)
              if (m := RE_LBL.match(line))}
    equ = {n: int(val, 16) for n, val in RE_EQU.findall(text)}
    return lines, labels, equ


def dispatches(lines: list[str], labels: dict[str, int]) -> list[str]:
    """Entry labels of every `[0x13]` six-way ladder in this file."""
    by_line = {i: n for n, i in labels.items()}
    found, cur = [], None
    for i, line in enumerate(lines):
        if i in by_line:
            cur = by_line[i]
        elif RE_SIG.match(line) and cur and cur not in found:
            found.append(cur)
    return found


def series(branch: str, stage: str, start: str):
    lines, labels, equ = load(branch, stage)
    if start not in labels:
        raise SystemExit(f"{branch}/{stage}: {start} not found")
    out = []
    for v in VALUES:
        const, terminal = evaluate(lines, labels, start, v)
        if const is None:
            raise SystemExit(f"{branch}/{stage}/{start} v={v}: nothing drawn")
        if const not in equ:
            raise SystemExit(f"{branch}/{stage}/{start} v={v}: {const} has "
                             f"no EQU")
        out.append((v, const, equ[const], terminal))
    return out


# The direction is not taken from the label text -- PRISON's rightward
# dispatch is still called LABEL_3BB3 and says nothing. The machine states it:
# the advance block that calls the dispatch sets [0x0E] first, and the drawing
# code reads [0x0E] to pick the mirrored art. 0 is rightward, 1 is leftward,
# and that holds in all three stages and all three branches.
RE_CALL_DIR = re.compile(r"^\s*mov\s+\[0x0E\],\s*0x0*([01])\s*$")
DIR_NAME = {0: "RIGHT", 1: "LEFT"}


def direction_of(lines: list[str], labels: dict[str, int], start: str) -> str:
    """RIGHT/LEFT from the [0x0E] the caller sets, or '?' if unreadable."""
    seen = set()
    for i, line in enumerate(lines):
        if line.strip() == f"call {start}":
            for j in range(i - 1, max(i - 6, -1), -1):
                if m := RE_CALL_DIR.match(lines[j]):
                    seen.add(int(m.group(1)))
                    break
    return DIR_NAME[seen.pop()] if len(seen) == 1 else "?"


RE_TAIL = re.compile(r"_F?(\d+)$")


def index_disagrees(const: str, v: int) -> str:
    """'' if the name carries no index, else a note when it contradicts v.

    A name may legitimately number the run from 0 or from 1, so a whole
    family shifted by one is not an error -- only a family that is not a
    consistent shift is. The caller collects these per ladder.
    """
    m = RE_TAIL.search(const)
    if not m or const.startswith("CINEMATIC_") and const[10:].isdigit():
        return ""
    return str(int(m.group(1)) - v)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--branches", nargs="+", default=list(BRANCH_PORT),
                    help="default: every branch that has one of these ladders")
    ap.add_argument("--proposals", action="store_true",
                    help="emit a proposal table per branch for the unnamed "
                         "ladders only")
    args = ap.parse_args()

    banks, bad, ladders, all_shifts = {}, 0, [], set()
    for branch in args.branches:
        port = BRANCH_PORT[branch]
        for stage in STAGE_ID:
            f = SRC / "src" / "levels" / branch / f"{stage}.asm"
            if not f.is_file():
                continue
            lines, labels, _equ = load(branch, stage)
            for start in dispatches(lines, labels):
                rows = series(branch, stage, start)
                direction = direction_of(lines, labels, start)
                if direction == "?":
                    print(f"  ** {branch}/{stage}/{start}: caller does not "
                          f"set [0x0E] to a single direction", file=sys.stderr)
                    bad += 1
                if port not in banks:
                    try:
                        banks[port] = slab("cinematic", port, 0)
                    except BaseException:
                        banks[port] = None
                ladders.append((branch, port, stage, start,
                                direction, rows))

    if not ladders:
        print("no [0x13] six-way ladder found", file=sys.stderr)
        return 1

    for branch, port, stage, start, direction, rows in ladders:
        bank = None
        if banks.get(port) is not None:
            bank = slab("cinematic", port, STAGE_ID[stage])
        if not args.proposals:
            print(f"\n{branch}/{stage}  {start}  [0x0E]->{direction}")
        hashes, shifts = [], []
        for v, const, off, terminal in rows:
            geom, h = "", ""
            if bank is not None:
                tree = parse_polygon_tree(bank, off)
                x0, y0, x1, y1, leaves = extent(tree)
                h = canonical_md5(tree)
                geom = f"{x1 - x0:5.1f} x{y1 - y0:5.1f}  {leaves} leaves  "
            hashes.append(h or f"?{v}")
            if (d := index_disagrees(const, v)):
                shifts.append(d)
            if not args.proposals:
                print(f"  v={v}{'+' if terminal else ' '} {const:<48}"
                      f"{geom}{h[:8]}")
        if len(set(hashes)) != len(VALUES) and bank is not None:
            print(f"  ** {branch}/{stage}/{start}: {len(VALUES)} values map "
                  f"to {len(set(hashes))} distinct pictures", file=sys.stderr)
            bad += 1
        if not args.proposals and shifts:
            uniq = sorted(set(shifts))
            note = (f"named run is the timer shifted by {uniq[0]}"
                    if len(uniq) == 1 else
                    f"** named indices are NOT a consistent shift: {uniq}")
            print(f"     {len(shifts)}/6 names carry an index; {note}")
            bad += len(uniq) != 1
        ladders[ladders.index((branch, port, stage, start, direction,
                               rows))] = (branch, port, stage, start,
                                          direction, rows, hashes)
        all_shifts.update(shifts)

    print("\ncross-branch agreement per (stage, ladder position)")
    groups = {}
    for branch, port, stage, start, direction, rows, hashes in ladders:
        groups.setdefault((stage, direction), []).append(
            (branch, rows, hashes))
    for key, members in sorted(groups.items()):
        known = [m for m in members if not m[2][0].startswith("?")]
        if len(known) < 2:
            print(f"  {key[0]:<9}{key[1]:<7}only {len(known)} branch(es) "
                  f"have art to compare")
            continue
        same = all(m[2] == known[0][2] for m in known)
        bad += not same
        print(f"  {key[0]:<9}{key[1]:<7}{', '.join(m[0] for m in known)}: "
              f"{'all six frames identical' if same else '** DIFFER **'}")

    if args.proposals:
        # The family stem is taken from the frames that are ALREADY named, in
        # any branch, for this (stage, direction) -- not from the dispatch
        # label. PRISON's rightward dispatch is LABEL_3BB3 and offers nothing,
        # and CAPSULE's is CAPSULE_SHOT_STATE_FRAME_DISPATCH_RIGHT while its
        # constants are CINEMATIC_CAPSULE_SHOT_HIT_BURST_RIGHT_*, so a
        # label-derived stem would open a second family beside the real one.
        stems: dict[tuple, set] = {}
        for _b, _p, stage, start, direction, rows, _h in ladders:
            for _v, const, _o, _t in rows:
                if m := re.fullmatch(r"CINEMATIC_(.+?)_F?\d+", const):
                    stems.setdefault((stage, direction), set()).add(m.group(1))
        for _b, _p, stage, start, direction, rows, _h in ladders:
            key = (stage, direction)
            found = stems.get(key, set())
            if len(found) > 1:
                print(f"\n** {stage}/{direction}: frames already named under "
                      f"{len(found)} different stems {sorted(found)}; not "
                      f"proposing over an existing disagreement (#0120)",
                      file=sys.stderr)
                continue
            # next(iter(...)), not .pop(): `found` is the shared set for this
            # (stage, direction) and every branch in the group reads it.
            stem = (next(iter(found)) if found
                    else start.replace("_DISPATCH", ""))
            wanted = [(v, const, t) for v, const, _o, t in rows
                      if const != f"CINEMATIC_{stem}_{v - 1}"]
            if not wanted:
                continue
            print(f"\n----- {_b} / {stage} -----")
            print("| constant | proposed name | confidence | evidence |")
            print("| --- | --- | --- | --- |")
            for v, const, terminal in wanted:
                print(f"| {const} | CINEMATIC_{stem}_{v - 1} | high | "
                      f"`{start}` draws it when the shot timer `[{TIMER}]` "
                      f"(seeded to 1, masked with 0x7FFF, incremented once "
                      f"per tick) holds {v}, the {v}th and "
                      f"{'last' if terminal else f'{v}th'} frame of the "
                      f"burst"
                      + ("; at this value the dispatch also writes "
                         "`[0x13] = 0xFFFE`, which the caller's add/or turn "
                         "into the 0xFFFF that frees the slot" if terminal
                         else "") + " |")

    if all_shifts:
        print(f"\nindex base: every named frame is the timer value shifted "
              f"by {sorted(all_shifts)}"
              f"{'' if len(all_shifts) == 1 else '  ** not one convention **'}")
        bad += len(all_shifts) != 1

    if bad:
        print(f"\nFAIL: {bad} check(s) failed", file=sys.stderr)
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
