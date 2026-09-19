#!/usr/bin/env python3
"""Give the 24 raw `video offset=0x…` operands in gba_usa/LAKE their names.

This is the one-off migration for what
`resolve_raw_offsets.py` establishes. Run that first; it is the evidence, this
is only the edit.

It adds ten `CINEMATIC_… EQU 0x…` lines to the end of the file's EQU block --
each with **gba's own offset**, not amiga's, which is the rule
`another-world-archaeology/tools/canonicalize_cinematic_refs.py` states: "Each
branch keeps its own EQU value for the canonical name." -- and rewrites each
`offset=0x…` to the symbol.

Not a byte change: an EQU resolves to the same number the literal was, which
`make test` confirms at 29/29. The point is that a bare number in an operand
is not a symbol anyone can later rename, so it sits below even `CINEMATIC_NNN`
on the evidence ladder.

Refuses to run on an already-migrated file, so it is safe to re-run.

    python3 notes/raw-polygon-operands/apply_gba_lake_raw_offsets.py --apply
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

TARGET = (Path(__file__).resolve().parents[2] / "src" / "levels"
          / "gba_2004" / "LAKE.asm")

# offset in gba_usa/LAKE -> canonical name, as resolve_raw_offsets.py prints.
NAMES = {
    0x08FC: "CINEMATIC_HERO_LAND_LEFT",            # extrapolated, see probe
    0x0C1E: "CINEMATIC_HERO_LAND_RIGHT",
    0xB808: "CINEMATIC_REED_PLANT_5",
    0xB8A0: "CINEMATIC_REED_PLANT_6",
    0xB8EE: "CINEMATIC_REED_PLANT_7",
    0xDC8A: "CINEMATIC_PARTICLE_BURST_2_FRAME_0",
    0xDC9A: "CINEMATIC_PARTICLE_BURST_2_FRAME_1",
    0xDCB2: "CINEMATIC_PARTICLE_BURST_2_FRAME_2",
    0xDCC6: "CINEMATIC_PARTICLE_BURST_2_FRAME_3",
    0xDCF6: "CINEMATIC_PARTICLE_BURST_2_FRAME_4",
}

RE_EQU = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s+(0x[0-9A-Fa-f]+)\s*$")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    args = ap.parse_args()

    lines = TARGET.read_text().splitlines()
    defined = {m.group(1) for m in (RE_EQU.match(l) for l in lines) if m}

    clash = sorted(n for n in NAMES.values() if n in defined)
    if clash:
        print("REFUSING: these names are already defined in the file, so this "
              "would\ncreate a duplicate EQU:")
        for n in clash:
            print(f"  {n}")
        return 1

    last_equ = max(i for i, l in enumerate(lines) if RE_EQU.match(l))
    block = [f"{name}\t\tEQU 0x{off:04X}"
             for off, name in sorted(NAMES.items(), key=lambda kv: kv[1])]

    subs = 0
    out = []
    for i, line in enumerate(lines):
        for off, name in NAMES.items():
            new = re.sub(rf"(video\s+(?:type=\d+,\s*)?offset=)0x0*{off:X}\b",
                         rf"\g<1>{name}", line, flags=re.IGNORECASE)
            if new != line:
                line = new
                subs += 1
        out.append(line)
        if i == last_equ:
            out.extend(block)

    remaining = sum(1 for l in out if re.search(r"video\s+(?:type=\d+,\s*)?"
                                                r"offset=0x", l))
    print(f"{len(block)} EQU line(s) to add after line {last_equ + 1}")
    print(f"{subs} raw operand(s) rewritten, {remaining} still raw")
    if remaining:
        print("REFUSING: some raw operand was not covered by the table above")
        return 1
    if not args.apply:
        print("dry run -- re-run with --apply")
        return 0
    TARGET.write_text("\n".join(out) + "\n")
    print(f"written: {TARGET}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
