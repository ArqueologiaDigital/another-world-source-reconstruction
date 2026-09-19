#!/usr/bin/env python3
"""Re-base LAKE's left-facing hero locomotion onto what the bytecode proves.

Evidence: notes/hero-walk-cycle-probes/lake_hero_left_locomotion.py
  - the loop called HERO_FALL_LEFT_LOOP never writes HERO_Y (4 writes, all
    `add [HERO_Y], 0x0000`), moves -2.13 px/frame over 15 frames and fires two
    footsteps. It is the walk, not a fall.
  - the loop called HERO_WALK_LEFT_LOOP peaks at -13 px/frame, 4.3x faster,
    accelerates from a standstill and decelerates into CINEMATIC_HERO_STOP_LEFT_*.
    It is the run; its first four frames have zero X motion, so they are the
    run's wind-up.
"""
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels"
_PRECHECK = [Path(__file__).resolve().parents[2] / "src/levels/chahi_amiga_1991/LAKE.asm"]
# Precondition. These are one-shot migrations, and re-running one on an
# already-migrated tree would undo it (the keypad one is a swap, so it
# swaps back; the 0x66 one would re-alias TANK's djnz counter). Refuse.
if not any('CINEMATIC_HERO_FALL_LEFT_1' in q.read_text(errors="replace")
           for q in _PRECHECK):
    print("already applied: the walk-left family is already re-based")
    raise SystemExit(0)



RENAMES = {}

# --- polygons: the four zero-motion frames vacate the WALK_LEFT name
for i in range(4):
    RENAMES[f"CINEMATIC_HERO_WALK_LEFT_{i}"] = f"CINEMATIC_HERO_RUN_LEFT_WINDUP_{i}"

# --- polygons: the 15-frame cycle becomes one gap-free family (NAMING.md §2)
RENAMES["CINEMATIC_HERO_LEFT_PROFILE"] = "CINEMATIC_HERO_WALK_LEFT_0"
for i in range(1, 5):                      # FALL_LEFT_1..4  -> WALK_LEFT_1..4
    RENAMES[f"CINEMATIC_HERO_FALL_LEFT_{i}"] = f"CINEMATIC_HERO_WALK_LEFT_{i}"
for i in range(10):                        # RESUME_LEFT_0..9 -> WALK_LEFT_5..14
    RENAMES[f"CINEMATIC_HERO_RESUME_LEFT_{i}"] = f"CINEMATIC_HERO_WALK_LEFT_{i + 5}"

# --- routines that carry the refuted FALL token or a now-shifted frame index
RENAMES.update({
    "HERO_FALL_LEFT_LOOP":          "HERO_WALK_LEFT_CYCLE_LOOP",
    "HERO_FALL_LEFT_PRELUDE":       "HERO_WALK_LEFT_CYCLE_PRELUDE",
    "HERO_FALL_L_F2_HOLD_LOOP":     "HERO_WALK_LEFT_F7_HOLD_LOOP",
    "HERO_RESUME_LEFT_F3_DONE":     "HERO_WALK_LEFT_F8_DONE",
    "HERO_LEFT_PROFILE_DONE_X_INC": "HERO_WALK_LEFT_F0_DONE_X_INC",
    "FALL_L_F1_X_DELTA_DONE":       "WALK_LEFT_F1_X_DELTA_DONE",
    "FALL_L_F2_X_DELTA_DONE":       "WALK_LEFT_F2_X_DELTA_DONE",
    "FALL_L_F3_X_DELTA_DONE":       "WALK_LEFT_F3_X_DELTA_DONE",
    "FALL_L_F3_INNER_DONE":         "WALK_LEFT_F3_INNER_DONE",
    "FALL_L_F4_X_DELTA_DONE":       "WALK_LEFT_F4_X_DELTA_DONE",
    "STAND_L_FALL_LEFT_PATH":       "STAND_L_WALK_LEFT_PATH",
    "DRAW_HERO_LEFT_PROFILE":       "DRAW_HERO_WALK_LEFT_F0",
    # the fast loop and everything that names it
    "HERO_WALK_LEFT_LOOP":                "HERO_RUN_LEFT_BURST_LOOP",
    "DISPATCH_HERO_WALK_LEFT":            "DISPATCH_HERO_RUN_LEFT",
    "MAYBE_RESUME_WALK_LEFT_IF_GROUNDED": "MAYBE_START_RUN_LEFT_IF_GROUNDED",
    "MAYBE_RESUME_WALK_LEFT_DRAW":        "MAYBE_START_RUN_LEFT_DRAW",
})
# the msdos/cartridge/gba composite stubs, keyed by the amiga frame they match
for i in range(1, 10):                     # RESUME_LEFT_F1..F9 -> WALK_LEFT_F6..F14
    RENAMES[f"DRAW_HERO_RESUME_LEFT_F{i}"] = f"DRAW_HERO_WALK_LEFT_F{i + 5}"

# LAKE only. HERO_WALK_LEFT_LOOP is also defined, independently, in PRISON,
# CAVES and CAPSULE; this measurement was made on LAKE and says nothing about
# those. No affected label is defined in a cross-stage _helpers/ chunk, so the
# LAKE file set is closed under these names.
def is_lake(p: Path) -> bool:
    rel = str(p.relative_to(SRC))
    return ("LAKE" in p.name.upper()) or rel.startswith("_unified/lake/")

files = [p for p in SRC.rglob("*")
         if p.suffix in (".asm", ".inc", ".in") and is_lake(p)]
print(f"scope: {len(files)} LAKE file(s)")

# --- collision check: a target must not already exist unless it is itself
#     being renamed away in the same (simultaneous) pass
defined = set()
for p in files:
    defined |= set(re.findall(r"^([A-Za-z_][A-Za-z0-9_]*):", p.read_text(), re.M))
    defined |= set(re.findall(r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s", p.read_text(), re.M))
clash = [(o, n) for o, n in RENAMES.items() if n in defined and n not in RENAMES]
if clash:
    print("COLLISION:", clash)
    sys.exit(1)

pattern = re.compile(r"\b(" + "|".join(sorted(RENAMES, key=len, reverse=True)) + r")\b")
counts, touched = {}, 0
for p in files:
    text = p.read_text()
    new, n = pattern.subn(lambda m: RENAMES[m.group(1)], text)
    if n:
        for m in pattern.finditer(text):
            counts[m.group(1)] = counts.get(m.group(1), 0) + 1
        p.write_text(new)
        touched += 1
print(f"{touched} file(s) rewritten, {sum(counts.values())} reference(s)")
for k in sorted(counts):
    print(f"  {counts[k]:4d}  {k} -> {RENAMES[k]}")
missing = [k for k in RENAMES if k not in counts]
if missing:
    print("not present in the tree (fine if the branch lacks it):")
    for k in sorted(missing):
        print(f"        {k}")
