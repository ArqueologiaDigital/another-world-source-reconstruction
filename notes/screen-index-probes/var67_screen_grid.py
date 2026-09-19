#!/usr/bin/env python3
"""Is VM variable 0x67 a screen index into a 32-column grid?

Question answered
-----------------
`docs/NAMING.md` §3 lists `HACK_VAR_67` as the biggest placeholder in the tree
(6,281 references) and proposes `SCREEN_NUM` at E2, on the strength of three
helper labels an earlier pass had already spelled out (`COPY_HACK67_TO_VAR66`,
`ADD_HACK67_BY_20`, `SUB_HACK67_BY_20`) and the remark that "±0x20 is
screen-grid navigation". That is an inference from three label names, and a
6,281-reference rename deserves to rest on the opcodes instead.

This probe reads the committed source and checks five things. All five have to
hold for `SCREEN_NUM` to be the right name; any one of them failing would mean
0x67 is something else that happens to be stepped by 32.

  1. ARITHMETIC IS A GRID STEP AND NOTHING ELSE.  Every `add`/`sub` whose
     destination is 0x67 must use an immediate in {1, 0x20}, and no other
     arithmetic opcode (mul, div, and, or, shl, shr) may write it.  A variable
     that is only ever stepped by 1 or by 32 is an index into a 32-wide
     row-major array.  If a counter-ish `add [0x67], 0x0003` existed anywhere,
     the grid reading would be wrong.

  2. THE VALUES WRITTEN FALL IN BANDS ~0x20 APART.  Collect every
     `mov [0x67], <imm>` in the tree and cluster the immediates with a gap of
     more than 8 starting a new band.  A 32-column grid whose rooms occupy a
     few columns per row produces bands whose *starts* are near-multiples of
     0x20 apart.  A free-running counter would produce one dense run instead.

  3. THE FOUR DIRECTION HELPERS ARE THE TAILS OF THE FOUR EXIT CHAINS.  In
     amiga CAVES the four routines that step 0x67 generically are each the
     fall-through tail of a chain of special-case room links, and the chains
     are already named by direction.  The probe re-derives, from the source,
     which step each *_SCREEN_EXIT_<DIR>_LINK_CASE_* chain ends in, and asserts
     the pairing:  DOWN -> +0x20, UP -> -0x20, RIGHT -> +1, LEFT -> -1.
     That is what fixes the stride at 32 columns and the orientation as
     row-major.

  4. THE COLUMN IS EXTRACTED WITH A MASK OF 31.  CAPSULE and PRISON both do
        mov [0xF8], [0x66]   /   and [0xF8], 0x001F
     before branching on the result.  `& 31` is the column of a 32-wide grid
     written out in opcodes, by two stages that are not CAVES -- so the stride
     is not an artefact of one stage's room layout.

  5. 0x66 CACHES 0x67 AND A MISMATCH REDRAWS THE BACKGROUND.  The idiom
        je [0x66], [0x67], <copy>   /   copyVideoPage src=0x00, dst=0xFF
        <copy>:  mov [0x66], [0x67] / ret
     is "if the screen changed since the last frame, repaint the backdrop from
     page 0".  That is what makes 0x66 `CACHED_SCREEN_NUM` rather than a second
     independent variable.

What the signal means
---------------------
0x67 is read at thousands of `jne [0x67], [<v>], <ret>` guards — the per-scene
threads each begin by checking they are on their own screen and returning if
not.  Those guards are consistent with almost any identity variable, which is
why they are NOT used as evidence here; the five checks above are the ones that
distinguish a screen index from a mode, a phase or a counter.

Usage
-----
    python3 notes/screen-index-probes/var67_screen_grid.py            # all ports
    python3 notes/screen-index-probes/var67_screen_grid.py --port amiga

Exits non-zero if any of the five checks fails, so it doubles as a regression
test on the claim behind the `SCREEN_NUM` rename.
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[2]
SRC = REPO / "src" / "levels"

BRANCHES = {
    "amiga": "chahi_amiga_1991",
    "msdos": "dos_1992",
    "cartridge": "cartridge_1992",
    "gba": "gba_2004",
}

# The alias is `HACK_VAR_67` today and `SCREEN_NUM` after the rename this probe
# justifies; accept either spelling plus the raw id, so the probe keeps working
# across the commit that renames it.
V67 = r"(?:HACK_VAR_67|SCREEN_NUM|0x67)"
V66 = r"(?:HACK_VAR_66|CACHED_SCREEN_NUM|0x66)"

RE_ARITH = re.compile(
    r"^\s*(add|sub|mul|div|and|or|shl|shr|addConst)\s+\[" + V67 + r"\]\s*,\s*(\S+)")
RE_MOV_IMM = re.compile(r"^\s*mov\s+\[" + V67 + r"\]\s*,\s*(0x[0-9A-Fa-f]+)")
RE_LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
RE_EXIT_CHAIN = re.compile(
    r"^([A-Za-z0-9_]*SCREEN_EXIT_(DOWN|UP|LEFT|RIGHT)_LINK_CASE_[0-9A-Fa-f]+):")

GRID_STEPS = {1, 0x20}
EXPECTED_DIRECTION_STEP = {"DOWN": +0x20, "UP": -0x20, "RIGHT": +1, "LEFT": -1}


def strip_comment(line: str) -> str:
    return line.split(";", 1)[0]


def read_stage_lines(branch: str):
    """Yield (path, list-of-lines) for every .asm of one branch."""
    for path in sorted((SRC / branch).glob("*.asm")):
        yield path, path.read_text().splitlines()


# --------------------------------------------------------------------------
# check 1 — arithmetic on 0x67 is a grid step and nothing else
# --------------------------------------------------------------------------
def check_arithmetic(ports):
    print("1. arithmetic written to 0x67")
    seen = collections.Counter()
    offenders = []
    for port in ports:
        for path, lines in read_stage_lines(BRANCHES[port]):
            for n, line in enumerate(lines, 1):
                m = RE_ARITH.match(strip_comment(line))
                if not m:
                    continue
                op, operand = m.group(1), m.group(2).strip().rstrip(",")
                seen[(op, operand)] += 1
                if op not in ("add", "sub"):
                    offenders.append((path, n, line.strip(), "non-additive op"))
                    continue
                if not operand.startswith("0x"):
                    offenders.append((path, n, line.strip(), "non-immediate"))
                    continue
                if int(operand, 16) not in GRID_STEPS:
                    offenders.append((path, n, line.strip(), "step not 1 or 0x20"))
    for (op, operand), n in sorted(seen.items()):
        print(f"     {n:4d}  {op} [0x67], {operand}")
    if offenders:
        print("   FAIL — 0x67 is stepped by something other than 1 or 0x20:")
        for path, n, text, why in offenders[:20]:
            print(f"     {path.relative_to(REPO)}:{n}  {text}   ({why})")
        return False
    print("   PASS — every write is +/-1 or +/-0x20: a step in a 32-wide grid\n")
    return True


# --------------------------------------------------------------------------
# check 2 — the immediates assigned fall in bands about 0x20 apart
# --------------------------------------------------------------------------
def check_value_bands(ports, gap=8):
    print("2. immediates assigned to 0x67, clustered (new band when gap > %d)" % gap)
    values = set()
    for port in ports:
        for _path, lines in read_stage_lines(BRANCHES[port]):
            for line in lines:
                m = RE_MOV_IMM.match(strip_comment(line))
                if m:
                    values.add(int(m.group(1), 16))
    ordered = sorted(values)
    bands, cur = [], [ordered[0]]
    for v in ordered[1:]:
        if v - cur[-1] > gap:
            bands.append(cur)
            cur = []
        cur.append(v)
    bands.append(cur)
    prev_start = None
    strides = []
    for band in bands:
        start = band[0]
        delta = "" if prev_start is None else f"  (+0x{start - prev_start:02X} from previous band)"
        if prev_start is not None:
            strides.append(start - prev_start)
        print(f"     0x{start:02X}..0x{band[-1]:02X}  {len(band):2d} value(s){delta}")
        prev_start = start
    # Every band start after the first should sit within 6 of a multiple of 0x20
    # away from the previous one: rooms occupy a few columns of consecutive rows.
    off = [min(s % 0x20, 0x20 - (s % 0x20)) for s in strides]
    worst = max(off) if off else 0
    print(f"     band-to-band strides: {[hex(s) for s in strides]}")
    print(f"     worst deviation from a multiple of 0x20: {worst}")
    if worst > 6:
        print("   FAIL — bands are not spaced on a 32 stride\n")
        return False
    print("   PASS — the value space is rows of a 32-column grid\n")
    return True


# --------------------------------------------------------------------------
# check 3 — each named exit chain ends in the grid step its direction implies
# --------------------------------------------------------------------------
def check_exit_chains(port="amiga"):
    print(f"3. direction of each *_SCREEN_EXIT_<DIR>_LINK_CASE_* chain ({port})")
    ok = True
    found = 0
    for path, lines in read_stage_lines(BRANCHES[port]):
        labels = {}
        for n, line in enumerate(lines):
            m = RE_LABEL.match(line)
            if m:
                labels[m.group(1)] = n
        for n, line in enumerate(lines):
            m = RE_EXIT_CHAIN.match(line)
            if not m:
                continue
            chain_head, direction = m.group(1), m.group(2)
            step = walk_chain_to_step(lines, labels, n)
            found += 1
            want = EXPECTED_DIRECTION_STEP[direction]
            verdict = "ok" if step == want else "MISMATCH"
            if step != want:
                ok = False
            shown = "none" if step is None else f"{step:+d} (0x{abs(step):02X})"
            print(f"     {path.stem:<10} {chain_head:<42} {direction:<5} "
                  f"generic tail {shown:>12}  want {want:+d}  {verdict}")
    if not found:
        print("   FAIL — no named exit chains found; the probe cannot check this\n")
        return False
    if not ok:
        print("   FAIL — a chain's generic step disagrees with its direction\n")
        return False
    print("   PASS — DOWN/UP are +/-0x20 and RIGHT/LEFT are +/-1: "
          "row-major, 32 columns\n")
    return True


def walk_chain_to_step(lines, labels, start, limit=40):
    """Follow the `jne [0x67], <imm>, <next>` fall-through chain from `start`
    until a routine whose body is a bare `add`/`sub` on 0x67; return the signed
    step, or None."""
    seen = set()
    cur = start
    for _ in range(limit):
        # The chain's guard is the first instruction under the label.
        target = None
        for line in lines[cur + 1: cur + 6]:
            text = strip_comment(line).strip()
            if not text:
                continue
            m = re.match(r"jne\s+\[" + V67 + r"\]\s*,\s*0x[0-9A-Fa-f]+\s*,\s*"
                         r"([A-Za-z_][A-Za-z0-9_]*)", text)
            if m:
                target = m.group(1)
            break
        if target is None or target in seen or target not in labels:
            return None
        seen.add(target)
        cur = labels[target]
        body = [strip_comment(l).strip() for l in lines[cur + 1: cur + 4]]
        body = [b for b in body if b]
        m = re.match(r"(add|sub)\s+\[" + V67 + r"\]\s*,\s*(0x[0-9A-Fa-f]+)",
                     body[0] if body else "")
        if m and len(body) > 1 and body[1] == "ret":
            step = int(m.group(2), 16)
            return step if m.group(1) == "add" else -step
    return None


# --------------------------------------------------------------------------
# check 4 — the column is extracted with a mask of 31
# --------------------------------------------------------------------------
def check_column_mask(ports):
    print("4. `& 0x1F` column extraction on the cached screen number")
    hits = collections.Counter()
    for port in ports:
        for path, lines in read_stage_lines(BRANCHES[port]):
            for n, line in enumerate(lines):
                text = strip_comment(line).strip()
                m = re.match(r"mov\s+\[(0x[0-9A-Fa-f]+)\]\s*,\s*\[" + V66 + r"\]", text)
                if not m:
                    continue
                scratch = m.group(1)
                nxt = next((strip_comment(l).strip()
                            for l in lines[n + 1: n + 3]
                            if strip_comment(l).strip()), "")
                if re.match(r"and\s+\[" + re.escape(scratch) + r"\]\s*,\s*0x001F", nxt):
                    hits[f"{port}/{path.stem}"] += 1
    for k in sorted(hits):
        print(f"     {k}: {hits[k]} site(s)   mov [scratch],[0x66] ; and [scratch],0x001F")
    stages = {k.split("/", 1)[1] for k in hits}
    if len(stages) < 2:
        print("   FAIL — fewer than two stages mask the screen number by 31\n")
        return False
    print(f"   PASS — {sum(hits.values())} site(s) in {len(stages)} stage(s) "
          f"({', '.join(sorted(stages))}) take\n          the screen number "
          "modulo 32: that is the column of a 32-wide grid\n")
    return True


# --------------------------------------------------------------------------
# check 5 — 0x66 caches 0x67 and a mismatch repaints the backdrop
# --------------------------------------------------------------------------
def check_cache_pair(ports):
    print("5. the 0x66/0x67 compare-and-repaint idiom")
    hits = 0
    for port in ports:
        for path, lines in read_stage_lines(BRANCHES[port]):
            for n, line in enumerate(lines):
                text = strip_comment(line).strip()
                m = re.match(r"je\s+\[" + V66 + r"\]\s*,\s*\[" + V67 + r"\]\s*,\s*"
                             r"([A-Za-z_][A-Za-z0-9_]*)", text)
                if not m:
                    continue
                nxt = next((strip_comment(l).strip()
                            for l in lines[n + 1: n + 4]
                            if strip_comment(l).strip()), "")
                if "copyVideoPage" not in nxt:
                    continue
                hits += 1
                print(f"     {port}/{path.stem}:{n+1}")
                print(f"         {text}")
                print(f"         {nxt}          <- only when the screen changed")
    if not hits:
        print("   FAIL — idiom not found\n")
        return False
    print(f"   PASS — {hits} site(s): 0x66 is last frame's 0x67, and the "
          "backdrop is\n          repainted from page 0 exactly when they "
          "differ\n")
    return True


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", choices=sorted(BRANCHES), action="append",
                    help="restrict to one port (repeatable); default all")
    args = ap.parse_args()
    ports = args.port or sorted(BRANCHES)

    print(f"var 0x67 screen-grid probe — ports: {', '.join(ports)}\n")
    results = [
        check_arithmetic(ports),
        check_value_bands(ports),
        check_exit_chains("amiga" if "amiga" in ports else ports[0]),
        check_column_mask(ports),
        check_cache_pair(ports),
    ]
    if all(results):
        print("ALL FIVE CHECKS PASS — 0x67 is a screen index into a 32-column "
              "row-major grid.\n0x67 -> SCREEN_NUM, 0x66 -> CACHED_SCREEN_NUM "
              "at E2.")
        return 0
    print("AT LEAST ONE CHECK FAILED — do not rely on the SCREEN_NUM name.")
    return 1


if __name__ == "__main__":
    sys.exit(main())
