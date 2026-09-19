#!/usr/bin/env python3
"""Retire HACK_VAR_67 -> SCREEN_NUM, alias 0x66 -> CACHED_SCREEN_NUM, and rename
every label that embedded the placeholder. Whole-identifier renames only."""
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[2]
SRC = REPO / "src"
_PRECHECK = [Path(__file__).resolve().parents[2] / "src/levels/chahi_amiga_1991/CAVES.asm"]
# Precondition. These are one-shot migrations, and re-running one on an
# already-migrated tree would undo it (the keypad one is a swap, so it
# swaps back; the 0x66 one would re-alias TANK's djnz counter). Refuse.
if not any('HACK_VAR_67' in q.read_text(errors="replace")
           for q in _PRECHECK):
    print("already applied: HACK_VAR_67 is already gone")
    raise SystemExit(0)



VAR_RENAMES = {"HACK_VAR_67": "SCREEN_NUM"}

LABEL_RENAMES = {
    # the four generic grid steps, tails of the four exit chains
    "ADD_HACK67_BY_20":  "SCREEN_STEP_DOWN_ONE_ROW",
    "SUB_HACK67_BY_20":  "SCREEN_STEP_UP_ONE_ROW",
    "INCR_HACK67_BY_1":  "SCREEN_STEP_RIGHT_ONE_COLUMN",
    "DECR_HACK67_BY_1":  "SCREEN_STEP_LEFT_ONE_COLUMN",
    # the backdrop cache
    "COPY_HACK67_TO_VAR66": "CACHE_SCREEN_NUM_RET",
    "COPY_PAGE0_TO_3_AND_VAR66_TO_VAR65": "SHELVE_BACKDROP_TO_PAGE3",
    # the per-stage repaint gates (two of these also unify a cross-branch
    # name divergence: amiga and dos had different names for one routine)
    "CHECK_VAR66_VAR67_AND_BLIT":  "CAVES_REPAINT_BACKDROP_IF_SCREEN_CHANGED",
    "PAGE_COPY_IF_VAR67_DIFFERS":  "CAVES_REPAINT_BACKDROP_IF_SCREEN_CHANGED",
    "VAR66_MOD_32_DRAW_DISPATCH":  "CAPSULE_REPAINT_BACKDROP_IF_SCREEN_CHANGED",
    "VAR66_RANGE_DISPATCH_BY_VAR01": "PRISON_REPAINT_BACKDROP_IF_SCREEN_CHANGED",
    "PRISON_HACK_VAR_66_DISPATCH_BY_BITS_AND_HERO_X":
        "PRISON_REPAINT_BACKDROP_IF_SCREEN_CHANGED",
    # CODE_WHEEL's two screen-number threads
    "MARK_VAR67_AND_KILL":        "CODEWHEEL_SET_SCREEN_NUM_1_AND_KILL",
    "CODEWHEEL_PIN_HACK_VAR67_TO_0": "CODEWHEEL_HOLD_SCREEN_NUM_AT_0_LOOP",
    # still operand-transcription, but no longer a placeholder
    "SET_VARHACK_VAR_67_TO_0064": "SET_SCREEN_NUM_TO_0064",
    "SET_VARHACK_VAR_67_TO_00AA": "SET_SCREEN_NUM_TO_00AA",
    # the name claimed var 0x67; the body never touches it
    "DRAW_CIN_130_NESTED_OUTER":   "INTRO_KEYPAD_HANDS_STEP_LOOP",
    "DRAW_CIN_130_AT_VAR67_INNER": "INTRO_KEYPAD_HANDS_HOLD_LOOP",
    # fold-chain arms carried along with their stems (still _L<n> backlog)
    "CAPSULE_ADD_HACK67_BY_20_L0": "CAPSULE_SCREEN_STEP_DOWN_ONE_ROW_L0",
    "CAPSULE_ADD_HACK67_BY_20_L1": "CAPSULE_SCREEN_STEP_DOWN_ONE_ROW_L1",
    "CAVES_SUB_HACK67_BY_20_L3":   "CAVES_SCREEN_STEP_UP_ONE_ROW_L3",
    "CAVES_SUB_HACK67_BY_20_L4":   "CAVES_SCREEN_STEP_UP_ONE_ROW_L4",
    "CAVES_COPY_HACK67_TO_VAR66_L0": "CAVES_CACHE_SCREEN_NUM_RET_L0",
    "CAPSULE_COPY_PAGE0_TO_3_AND_VAR66_TO_VAR65_L0":
        "CAPSULE_SHELVE_BACKDROP_TO_PAGE3_L0",
    "CAPSULE_COPY_PAGE0_TO_3_AND_VAR66_TO_VAR65_L1":
        "CAPSULE_SHELVE_BACKDROP_TO_PAGE3_L1",
    "CAVES_COPY_PAGE0_TO_3_AND_VAR66_TO_VAR65_L0":
        "CAVES_SHELVE_BACKDROP_TO_PAGE3_L0",
    "CAVES_COPY_PAGE0_TO_3_AND_VAR66_TO_VAR65_L1":
        "CAVES_SHELVE_BACKDROP_TO_PAGE3_L1",
    "PRISON_COPY_PAGE0_TO_3_AND_VAR66_TO_VAR65_L0":
        "PRISON_SHELVE_BACKDROP_TO_PAGE3_L0",
    "CAPSULE_SET_VARHACK_VAR_67_TO_00AA_L0": "CAPSULE_SET_SCREEN_NUM_TO_00AA_L0",
    "CAPSULE_SET_VARHACK_VAR_67_TO_00AA_L1": "CAPSULE_SET_SCREEN_NUM_TO_00AA_L1",
    "CAPSULE_SET_VARHACK_VAR_67_TO_00AA_L2": "CAPSULE_SET_SCREEN_NUM_TO_00AA_L2",
    # the amiga chunk name in the unified tree follows its stem
    "amiga__post_COPY_HACK67_TO_VAR66": "amiga__post_CACHE_SCREEN_NUM_RET",
}

RENAMES = {**VAR_RENAMES, **LABEL_RENAMES}

files = [p for p in SRC.rglob("*") if p.suffix in (".asm", ".inc", ".in")]

# --- collision check: a new name must not already exist as a DIFFERENT symbol
existing = set()
for p in files:
    for m in re.finditer(r"^([A-Za-z_][A-Za-z0-9_]*):", p.read_text(), re.M):
        existing.add(m.group(1))
clashes = []
for old, new in LABEL_RENAMES.items():
    if new in existing and new not in LABEL_RENAMES:
        clashes.append((old, new))
if clashes:
    print("COLLISION — new name already defined:")
    for old, new in clashes:
        print(f"  {old} -> {new}")
    sys.exit(1)

# --- per-file: renaming two distinct labels onto one name must not create a
#     duplicate definition inside the same file
by_new = {}
for old, new in LABEL_RENAMES.items():
    by_new.setdefault(new, []).append(old)
for new, olds in by_new.items():
    if len(olds) < 2:
        continue
    for p in files:
        text = p.read_text()
        defs = [o for o in olds if re.search(rf"^{o}:", text, re.M)]
        if len(defs) > 1:
            print(f"DUPLICATE in {p}: {defs} both -> {new}")
            sys.exit(1)

pattern = re.compile(r"\b(" + "|".join(sorted(RENAMES, key=len, reverse=True)) + r")\b")
counts = {}
touched = 0
for p in files:
    text = p.read_text()
    new_text, n = pattern.subn(lambda m: RENAMES[m.group(1)], text)
    if n:
        for m in pattern.finditer(text):
            counts[m.group(1)] = counts.get(m.group(1), 0) + 1
        p.write_text(new_text)
        touched += 1

# --- alias the raw 0x66 references
raw66 = re.compile(r"\[0x66\]")
n66 = 0
for p in files:
    if p.name == "_common_vars.inc":
        continue
    text = p.read_text()
    new_text, n = raw66.subn("[CACHED_SCREEN_NUM]", text)
    if n:
        p.write_text(new_text)
        n66 += n

print(f"{touched} file(s) rewritten; {n66} raw [0x66] -> [CACHED_SCREEN_NUM]")
for k in sorted(counts, key=lambda k: -counts[k]):
    print(f"  {counts[k]:6d}  {k} -> {RENAMES[k]}")
