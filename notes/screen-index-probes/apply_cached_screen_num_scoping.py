#!/usr/bin/env python3
"""Second half of the SCREEN_NUM work:
  - TANK uses 0x66 as a djnz counter, not the backdrop cache, so revert its
    three sites to the raw id and keep the alias out of that stage.
  - declare CACHED_SCREEN_NUM per stage (LAKE/PRISON/CAVES/CAPSULE), not in
    _common_vars.inc, because of the TANK exception.
  - rename the unified chunk FILES whose names embedded the retired labels,
    and every .include that points at them.
"""
import re
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
_PRECHECK = [Path(__file__).resolve().parents[2] / "src/levels/chahi_amiga_1991/TANK.asm"]
# Precondition. These are one-shot migrations, and re-running one on an
# already-migrated tree would undo it (the keypad one is a swap, so it
# swaps back; the 0x66 one would re-alias TANK's djnz counter). Refuse.
if not any('[CACHED_SCREEN_NUM]' in q.read_text(errors="replace")
           for q in _PRECHECK):
    print("already applied: TANK already keeps the raw [0x66]")
    raise SystemExit(0)


SRC = ROOT / "src"

# ---------------------------------------------------------------- TANK revert
tank_files = [p for p in SRC.rglob("*")
              if p.is_file() and p.suffix in (".asm", ".inc", ".in")
              and ("TANK" in p.name.upper() or "/tank/" in str(p))]
n = 0
for p in tank_files:
    text = p.read_text()
    new, k = re.subn(r"\[CACHED_SCREEN_NUM\]", "[0x66]", text)
    if k:
        p.write_text(new)
        n += k
print(f"TANK: reverted {n} site(s) to raw [0x66] (djnz counter, not the cache)")

# ------------------------------------------------- per-stage CACHED_SCREEN_NUM
STAGES = ("LAKE", "PRISON", "CAVES", "CAPSULE")
EQU = "CACHED_SCREEN_NUM\t\t; EQU-PLACEHOLDER"
added = []
for p in sorted(SRC.rglob("*")):
    if not p.is_file() or p.suffix not in (".asm", ".in"):
        continue
    stem = p.stem.replace(".asm", "")
    if not any(s in stem.upper() for s in STAGES):
        continue
    text = p.read_text()
    if "CACHED_SCREEN_NUM" not in text:
        continue
    if re.search(r"^CACHED_SCREEN_NUM\s+EQU", text, re.M):
        continue
    lines = text.splitlines(keepends=True)
    # insert straight after the last EQU of the header block, or after the
    # .include of _common_vars.inc if there is no EQU yet
    idx = None
    for i, line in enumerate(lines[:80]):
        if re.match(r"^[A-Za-z_][A-Za-z0-9_]*\s+EQU\s", line):
            idx = i + 1
        elif idx is None and "_common_vars.inc" in line:
            idx = i + 1
    if idx is None:
        print(f"  !! no insertion point in {p}")
        continue
    lines.insert(idx, "CACHED_SCREEN_NUM\tEQU 0x66\n")
    p.write_text("".join(lines))
    added.append(str(p.relative_to(ROOT)))
print(f"declared CACHED_SCREEN_NUM in {len(added)} file(s):")
for a in added:
    print(f"  {a}")

# ------------------------------------------------------- chunk file renames
FILE_RENAMES = {
    "COPY_HACK67_TO_VAR66": "CACHE_SCREEN_NUM_RET",
    "COPY_PAGE0_TO_3_AND_VAR66_TO_VAR65": "SHELVE_BACKDROP_TO_PAGE3",
    "ADD_HACK67_BY_20": "SCREEN_STEP_DOWN_ONE_ROW",
    "SUB_HACK67_BY_20": "SCREEN_STEP_UP_ONE_ROW",
    "INCR_HACK67_BY_1": "SCREEN_STEP_RIGHT_ONE_COLUMN",
    "DECR_HACK67_BY_1": "SCREEN_STEP_LEFT_ONE_COLUMN",
}
renamed = []
for p in sorted(SRC.rglob("*.inc")):
    new_name = p.name
    for old, new in FILE_RENAMES.items():
        if old in new_name:
            new_name = new_name.replace(old, new)
    if new_name != p.name:
        subprocess.run(["git", "mv", str(p), str(p.with_name(new_name))],
                       cwd=ROOT, check=True)
        renamed.append((p.name, new_name))
print(f"renamed {len(renamed)} chunk file(s)")

# every .include line that still points at an old chunk name
pat = re.compile("|".join(re.escape(o) for o in FILE_RENAMES))
fixed = 0
for p in sorted(SRC.rglob("*")):
    if not p.is_file() or p.suffix not in (".inc", ".in", ".asm"):
        continue
    text = p.read_text()
    out = []
    changed = False
    for line in text.splitlines(keepends=True):
        if ".include" in line and pat.search(line):
            for old, new in FILE_RENAMES.items():
                line = line.replace(old + ".inc", new + ".inc")
            changed = True
        out.append(line)
    if changed:
        p.write_text("".join(out))
        fixed += 1
print(f"fixed .include lines in {fixed} file(s)")
