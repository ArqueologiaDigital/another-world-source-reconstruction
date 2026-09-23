#!/usr/bin/env python3
"""Where do the sixteen checkpoint register tables come from?

Question answered
-----------------
A stage entered with every variable at zero does not run: the copy-protection
check deletes all 64 threads (`notes/stage-entry/`). Seeding the five variables
that check reads is enough to make a stage draw, and it is NOT enough to make it
play -- the game's scripts read dozens of other variables that a real
playthrough would have set, and a wrong one shows up as a frozen or nonsensical
scene rather than as an error.

The reference engines solve this with a table of initial register values per
CHECKPOINT, applied when a level is restarted. This transcribes them, from the
local Rust engine at `../another-world-suite/engine`, into the JSON the
debugger's VM loads. Generated rather than typed, because 16 x 49 hand-copied
numbers is 784 chances to be wrong in a way nothing would catch.

Signal read
-----------
`src/lib/defines.rs`'s `LEVEL_<NN>_INITIAL_REGISTERS_VALUES` arrays, and the
`level -> part` match in `restart_level` in `src/lib/virtual_machine.rs`. The
part numbers there are this project's stage ids: 1 INTRO, 2 LAKE, 3 PRISON,
4 CAVES, 5 TANK, 6 CAPSULE.

Note the reference zeroes registers 0x00..0x3F before applying a table and
leaves 0x40..0xFF alone, so the table is not a full machine state; it is the
delta from whatever the previous part left behind. The debugger reproduces that
exactly.

Run it
    python3 tools/vm-debugger/tools/extract_checkpoints.py \
        --engine ../another-world-suite/engine \
        --out tools/vm-debugger/static/checkpoints.json
    # --check re-derives and diffs against the committed file instead of writing
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

RE_TABLE = re.compile(
    r"pub const LEVEL_(\d+)_INITIAL_REGISTERS_VALUES:[^=]*=\s*\[(.*?)\];",
    re.S)
RE_PAIR = re.compile(r"\[\s*(0x[0-9a-fA-F]+|\d+)\s*,\s*(-?\d+)\s*\]")
RE_ARM = re.compile(r"(\d+)\s*=>\s*\{(.*?)\n      \}", re.S)
RE_PART = re.compile(r"part\s*=\s*(\d+)")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--engine", required=True, type=Path)
    ap.add_argument("--out", type=Path)
    ap.add_argument("--check", action="store_true")
    a = ap.parse_args()

    defines = (a.engine / "src/lib/defines.rs").read_text()
    vm = (a.engine / "src/lib/virtual_machine.rs").read_text()

    tables: dict[str, dict[str, int]] = {}
    for lvl, body in RE_TABLE.findall(defines):
        regs = {}
        for reg, val in RE_PAIR.findall(body):
            regs[f"0x{int(reg, 0):02X}"] = int(val)
        tables[str(int(lvl))] = regs

    # level -> part, from restart_level's match arms
    start = vm.index("pub fn restart_level")
    end = vm.index("self.load_part(part);", start)
    parts = {}
    for lvl, arm in RE_ARM.findall(vm[start:end]):
        m = RE_PART.search(arm)
        if m:
            parts[str(int(lvl))] = int(m.group(1))

    missing = sorted(set(tables) - set(parts))
    if missing:
        print(f"levels with a table and no part: {missing}", file=sys.stderr)
        return 1

    out = {
        "_source": "another-world-suite/engine "
                   "src/lib/{defines.rs,virtual_machine.rs}",
        "_note": "registers 0x00..0x3F are zeroed before a table is applied; "
                 "0x40..0xFF keep whatever the previous part left. Regenerate "
                 "with tools/vm-debugger/tools/extract_checkpoints.py.",
        "checkpoints": [
            {"level": int(l), "part": parts[l], "registers": tables[l]}
            for l in sorted(tables, key=int)
        ],
    }
    text = json.dumps(out, indent=1) + "\n"

    if a.check:
        if not a.out or not a.out.is_file():
            print("nothing to check against", file=sys.stderr)
            return 1
        same = a.out.read_text() == text
        print("checkpoints.json matches the engine" if same
              else "checkpoints.json DIFFERS from the engine -- regenerate")
        return 0 if same else 1

    n = sum(len(t["registers"]) for t in out["checkpoints"])
    print(f"{len(out['checkpoints'])} checkpoint(s), {n} register value(s), "
          f"parts {sorted({t['part'] for t in out['checkpoints']})}")
    if a.out:
        a.out.write_text(text)
        print(f"wrote {a.out}")
    else:
        sys.stdout.write(text)
    return 0


if __name__ == "__main__":
    sys.exit(main())
