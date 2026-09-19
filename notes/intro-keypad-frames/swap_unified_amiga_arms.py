#!/usr/bin/env python3
"""Apply the amiga-only keypad-frame swap inside the unified INTRO chunks.

A name here is branch-scoped by `.if BRANCH == "..."`, so the swap must touch
only the lines that are live for chahi_amiga_1991. Any occurrence in an
unconditional region is reported and NOT touched — swapping one there would
change the name for every branch.
"""
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels" / "_unified" / "intro"
_PRECHECK = [Path(__file__).resolve().parents[2] / "src/levels/_unified/intro/intro_lake_transition.inc"]
# Precondition. These are one-shot migrations, and re-running one on an
# already-migrated tree would undo it (the keypad one is a swap, so it
# swaps back; the 0x66 one would re-alias TANK's djnz counter). Refuse.
if not any('CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F1\t\tEQU 0x446C' in q.read_text(errors="replace")
           for q in _PRECHECK):
    print("already applied: the amiga keypad arms are already swapped")
    raise SystemExit(0)


AMIGA = "chahi_amiga_1991"
SWAP = {
    "CINEMATIC_116": "CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F1",
    "CINEMATIC_117": "CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F2",
    "CINEMATIC_119": "CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F4",
    "CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F1": "CINEMATIC_121",
    "CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F2": "CINEMATIC_122",
    "CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F4": "CINEMATIC_124",
}
PAT = re.compile(r"\b(" + "|".join(sorted(SWAP, key=len, reverse=True)) + r")\b")
RE_IF = re.compile(r'^\s*\.if\s+BRANCH\s*(==|!=)\s*"([^"]+)"')
RE_ELIF = re.compile(r'^\s*\.elif\s+BRANCH\s*(==|!=)\s*"([^"]+)"')

apply = "--apply" in sys.argv
swapped = unconditional = 0
for p in sorted(SRC.glob("*.inc")):
    lines = p.read_text().splitlines(keepends=True)
    # stack of per-nesting-level state: (amiga_live, some_arm_matched_amiga)
    stack = []
    out = []
    for i, line in enumerate(lines, 1):
        m = RE_IF.match(line)
        if m:
            op, br = m.groups()
            live = (br == AMIGA) if op == "==" else (br != AMIGA)
            stack.append([live, live])
            out.append(line)
            continue
        m = RE_ELIF.match(line)
        if m and stack:
            op, br = m.groups()
            live = (br == AMIGA) if op == "==" else (br != AMIGA)
            live = live and not stack[-1][1]
            stack[-1][0] = live
            stack[-1][1] = stack[-1][1] or live
            out.append(line)
            continue
        if re.match(r"^\s*\.else\b", line) and stack:
            stack[-1][0] = not stack[-1][1]
            out.append(line)
            continue
        if re.match(r"^\s*\.endif\b", line):
            if stack:
                stack.pop()
            out.append(line)
            continue
        if not PAT.search(line.split(";", 1)[0]):
            out.append(line)
            continue
        if not stack:
            unconditional += 1
            print(f"  UNCONDITIONAL {p.name}:{i}  {line.strip()}")
            out.append(line)
            continue
        if all(s[0] for s in stack):          # live for amiga
            new = PAT.sub(lambda m: SWAP[m.group(1)], line)
            swapped += 1
            out.append(new)
        else:
            out.append(line)                   # a non-amiga arm: leave it
    if apply:
        p.write_text("".join(out))

print(f"{swapped} amiga-arm line(s) swapped, "
      f"{unconditional} unconditional occurrence(s) left alone"
      + ("" if apply else "   [dry run — pass --apply]"))
