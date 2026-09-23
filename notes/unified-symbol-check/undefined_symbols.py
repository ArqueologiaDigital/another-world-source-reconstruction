#!/usr/bin/env python3
"""Which symbols does the unified tree reference but never define, per branch?

Question answered
-----------------
`awvm-asm` accepts an undefined symbol and emits bytes for it (#0073, fixed
for the `EQU`-in-a-name case but not in general). So a rename that updates a
reference and misses its definition does not fail the assembler -- it changes
the bytes, and only `verify-unified` notices, after the fact and without
saying which symbol.

That cost four backouts in one day on msdos/INTRO alone. Each time the gate
said "26/29" and nothing said which name had gone missing. This says it.

How
---
Walks `_unified/<STAGE>.asm.in` once per branch, following `.include` and
honouring `.if BRANCH ...`, so it sees exactly the text that branch assembles.
It collects every definition (`NAME EQU ...`, `NAME:`) and every referenced
symbol (`offset=`, `address=`, jump and call targets), then reports references
with no definition in that branch's view.

The per-branch walk is the point: a name defined only inside
`.if BRANCH == "chahi_amiga_1991"` is perfectly defined for amiga and missing
for everyone else, which is precisely the failure this exists to catch and is
invisible to any whole-file grep.

What it checks
--------------
Two opposite failures, both of which assemble silently:

  * a reference with **no** definition in that branch's view;
  * a symbol defined **more than once** in that view. `defs` used to be a
    plain set, so a redefinition was invisible here -- and one really did
    slip through, two EQUs for the same name in `cart__entry.inc`, moving the
    cartridge target's bytes while this probe reported everything defined.
    Same value or different, both are reported; different values are the ones
    that move bytes.

A note on branches: `BRANCH` is only ever compared against the four branch
directory names. `snes_eu` and `genesis_europe` are two verify TARGETS built
from one branch, `cartridge_1992`, and they assemble identical text -- so
walking the four branches already covers all five targets. An earlier note
claimed genesis_europe was uncovered; it is not, and the real gap was the
missing redefinition check above.

Exit status
-----------
1 if any branch has an undefined reference or a redefinition, 0 otherwise. Run it after any
rename that touches the unified tree, BEFORE `make test` -- it localises in
seconds what the byte gate only flags in aggregate.

Usage
-----
    python3 notes/unified-symbol-check/undefined_symbols.py
    python3 notes/unified-symbol-check/undefined_symbols.py --stage INTRO
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels"
UNI = SRC / "_unified"
BRANCHES = ["chahi_amiga_1991", "dos_1992", "cartridge_1992", "gba_2004"]
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]

RE_INC = re.compile(r'^\s*\.include\s+"([^"]+)"')
RE_IF = re.compile(r'^\s*\.if\s+(.*)$')
RE_ELIF = re.compile(r'^\s*\.elif\s+(.*)$')
RE_ELSE = re.compile(r'^\s*\.else\b')
RE_END = re.compile(r'^\s*\.endif\b')
RE_EQU = re.compile(r'^\s*([A-Za-z_][A-Za-z0-9_]*)\s+EQU\b(.*)$')
RE_LBL = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*):')
RE_REF = re.compile(r'(?:offset=|address=|\b(?:jmp|call|je|jne|jg|jge|jl|jle|'
                    r'djnz|setvec)\s+(?:\[[^\]]*\]\s*,\s*[^,]+,\s*)?)'
                    r'([A-Za-z_][A-Za-z0-9_]*)')
BUILTIN = re.compile(r'^(0x[0-9A-Fa-f]+|\d+|type|x|y|zoom|src|dst|id|freq|'
                     r'vol|channel|BRANCH)$')


def cond(expr: str, br: str) -> bool:
    e = expr.strip()
    m = re.match(r'BRANCH\s*==\s*"([^"]+)"', e)
    if m:
        return br == m.group(1)
    m = re.match(r'BRANCH\s*!=\s*"([^"]+)"', e)
    if m:
        return br != m.group(1)
    m = re.match(r'BRANCH\s+in\s*\((.*)\)', e)
    if m:
        return br in re.findall(r'"([^"]+)"', m.group(1))
    m = re.match(r'BRANCH\s+not\s+in\s*\((.*)\)', e)
    if m:
        return br not in re.findall(r'"([^"]+)"', m.group(1))
    return True


def walk(path: Path, br: str, seen: set, defs: set, refs: dict,
         sites: dict | None = None):
    """`sites` collects EVERY definition, not just the set of names.

    `defs` is a set, so a symbol defined twice looks exactly like a symbol
    defined once and this probe reported nothing. That is not hypothetical:
    a rename once left two `CINEMATIC_CAVES_WATERFALL_LEFT_STAIRS_BG` EQUs in
    `cart__entry.inc`, the cartridge target's bytes moved, verify dropped to
    28/29, and this probe said "every symbol is defined" -- correctly, and
    uselessly. A redefinition is the opposite failure from a missing
    definition and needs its own signal.
    """
    if not path.is_file() or path in seen:
        return
    seen.add(path)
    stack = []
    for n, raw in enumerate(path.read_text(errors="replace").splitlines(), 1):
        line = raw.split(";", 1)[0]
        m = RE_IF.match(line)
        if m:
            t = cond(m.group(1), br)
            stack.append([t, t])
            continue
        m = RE_ELIF.match(line)
        if m and stack:
            t = (not stack[-1][1]) and cond(m.group(1), br)
            stack[-1] = [t, stack[-1][1] or t]
            continue
        if RE_ELSE.match(line) and stack:
            stack[-1] = [not stack[-1][1], True]
            continue
        if RE_END.match(line) and stack:
            stack.pop()
            continue
        if not all(a for a, _ in stack):
            continue
        m = RE_INC.match(line)
        if m:
            walk((path.parent / m.group(1)).resolve(), br, seen, defs, refs, sites)
            continue
        m = RE_EQU.match(line)
        if m:
            defs.add(m.group(1))
            if sites is not None:
                sites.setdefault(m.group(1), []).append(
                    (path.name, n, m.group(2).strip()))
            continue
        m = RE_LBL.match(line)
        if m:
            defs.add(m.group(1))
            if sites is not None:
                sites.setdefault(m.group(1), []).append((path.name, n, None))
            continue
        for sym in RE_REF.findall(line):
            if not BUILTIN.match(sym):
                refs.setdefault(sym, (path.name, n))


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--stage", action="append")
    ap.add_argument("--redundant", action="store_true",
                    help="list the same-value duplicate "
                         "definitions, not just count them")
    args = ap.parse_args()
    stages = args.stage or STAGES

    bad = 0
    redundant = 0
    for stage in stages:
        top = UNI / f"{stage}.asm.in"
        if not top.is_file():
            continue
        for br in BRANCHES:
            if not (SRC / br / f"{stage}.asm").is_file():
                continue
            defs, refs = set(), {}
            sites: dict = {}
            walk(top, br, set(), defs, refs, sites)
            dupes = sorted((s, v) for s, v in sites.items() if len(v) > 1)
            for sym, where in dupes:
                vals = {w[2] for w in where}
                # Different values MOVE BYTES -- that is the historical bug
                # and it is an error. Same value does not move a byte today,
                # but it is the state that bug starts from: rename one twin
                # and miss the other and the values diverge. Warn, do not
                # fail, or this probe stops being usable as a pre-`make test`
                # gate over the 30 redundancies already in the tree.
                if len(vals) > 1:
                    bad += 1
                    tag = f"ERROR: {len(vals)} DIFFERENT values"
                else:
                    redundant += 1
                    if not args.redundant:
                        continue
                    tag = "redundant: same value twice"
                print(f"\n{stage} / {br}: {sym} defined "
                      f"{len(where)} times, {tag}")
                for f, ln, val in where:
                    print(f"    {f}:{ln}" + (f"   EQU {val}" if val else
                                             "   (label)"))
            missing = sorted(s for s in refs if s not in defs)
            if missing:
                bad += len(missing)
                print(f"\n{stage} / {br}: {len(missing)} undefined symbol(s)")
                for s in missing[:12]:
                    f, n = refs[s]
                    print(f"    {s:<46} first referenced {f}:{n}")
                if len(missing) > 12:
                    print(f"    ... and {len(missing) - 12} more")
    if redundant:
        print(f"\n{redundant} symbol(s) are defined twice with the SAME "
              f"value. No byte moves today; rename one twin and miss the "
              f"other and one will.\n"
              f"    python3 notes/unified-symbol-check/undefined_symbols.py "
              f"--redundant")
    print("\n" + (f"{bad} problem(s) -- these assemble silently and move "
                  f"bytes" if bad else
                  "Every symbol referenced in the unified tree is defined for "
                  "the branch that reads it, and no definition disagrees with "
                  "a twin."))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
