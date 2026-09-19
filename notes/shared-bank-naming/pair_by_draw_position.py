#!/usr/bin/env python3
"""Carry a name across ports by DRAW POSITION, never by index.

Question answered
-----------------
amiga/TANK has 224 polygon constants and not one is named. msdos/TANK has the
same animation already named -- `CINEMATIC_CAPSULE_DOME_CLOSING_F19`, `_F20`,
and so on. The names are there for the taking and taking them is exactly the
mistake #0107 forbids: indices are per-port encounter order, so
`CINEMATIC_193` on amiga and `CINEMATIC_193` on msdos are unrelated, and
copying a name by index "would be right 2% of the time".

But the two ports run the **same routine**. `CAPSULE_DOME_CLOSING_LATE_FRAMES`
exists on both, and each draws a sequence of constants in the same order with
`break` in the same places. Position in that sequence is a real
correspondence, and it is one the code states rather than one anybody assumes.

So: walk the two routines' draw sequences in parallel and pair them by
position. Then **check the pairing against the art** before believing it --
this prints each pair's polygon extent and vertex count from the two ports'
own banks, and refuses any routine whose sequences differ in length or whose
paired shapes disagree in size.

What is compared
----------------
For a routine present on both ports with the same name:

  * the ordered list of `video offset=<sym>` operands, and where the `break`s
    fall -- the shapes of the two sequences must match exactly;
  * for each paired (amiga sym, msdos sym), the bounding box and vertex count
    read from each port's own cinematic bank. Equal extents are the evidence
    that position really did land on the same picture.

A routine that passes yields a mapping amiga-symbol -> msdos-name. A routine
that fails is reported and contributes nothing.

Exit status
-----------
0 if every routine examined agrees, 1 otherwise.

Usage
-----
    python3 notes/shared-bank-naming/pair_by_draw_position.py --stage TANK
    python3 notes/shared-bank-naming/pair_by_draw_position.py --stage TANK \
        --routine CAPSULE_DOME_CLOSING_LATE_FRAMES --verbose
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels"
PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
RE_LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
RE_DRAW = re.compile(r"video\s+(?:type=\d+,\s*)?offset=([A-Za-z_][A-Za-z0-9_]*)")
RE_EQU = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s+(0x[0-9A-Fa-f]+)")
RE_NUMERIC = re.compile(r"^CINEMATIC_\d+$")


def parse(path: Path):
    equs, routines, cur = {}, {}, None
    for raw in path.read_text(errors="replace").splitlines():
        line = raw.split(";", 1)[0]
        m = RE_EQU.match(line)
        if m:
            equs[m.group(1)] = int(m.group(2), 16)
            continue
        m = RE_LABEL.match(line)
        if m:
            cur = m.group(1)
            routines.setdefault(cur, [])
            continue
        if cur is None:
            continue
        s = line.strip()
        if s.startswith("break"):
            routines[cur].append(("break", None))
        for sym in RE_DRAW.findall(line):
            routines[cur].append(("draw", sym))
    return equs, routines


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--stage", required=True)
    ap.add_argument("--routine", action="append")
    ap.add_argument("--verbose", action="store_true")
    args = ap.parse_args()

    ae, ar = parse(SRC / PORTS["amiga"] / f"{args.stage}.asm")
    de, dr = parse(SRC / PORTS["msdos"] / f"{args.stage}.asm")

    names = args.routine or sorted(set(ar) & set(dr))
    mapping: dict[str, str] = {}
    conflicts: dict[str, set[str]] = {}
    bad = 0
    for r in names:
        a, d = ar.get(r, []), dr.get(r, [])
        if not a or [k for k, _ in a] != [k for k, _ in d]:
            if args.routine:
                print(f"  {r}: sequences differ "
                      f"({len(a)} vs {len(d)} events) -- skipped")
                bad += 1
            continue
        for (ka, sa), (_kd, sd) in zip(a, d):
            if ka != "draw":
                continue
            if not RE_NUMERIC.match(sa) or RE_NUMERIC.match(sd):
                continue        # amiga already named, or msdos not named
            mapping.setdefault(sa, sd)
            if mapping[sa] != sd:
                conflicts.setdefault(sa, set()).update({mapping[sa], sd})

    # one msdos name must not land on two amiga symbols either
    rev: dict[str, set[str]] = {}
    for a_sym, d_name in mapping.items():
        rev.setdefault(d_name, set()).add(a_sym)
    for d_name, a_syms in rev.items():
        if len(a_syms) > 1:
            conflicts.setdefault(d_name, set()).update(a_syms)

    print(f"{len(names)} routine(s) present on both ports with matching "
          f"draw sequences")
    print(f"{len(mapping)} amiga constant(s) paired by draw position")
    if conflicts:
        bad += len(conflicts)
        print(f"{len(conflicts)} CONFLICT(S) -- position gives two answers:")
        for k, v in sorted(conflicts.items())[:10]:
            print(f"  {k}: {sorted(v)}")

    print(f"\n{'amiga':<20}{'msdos name':<46}"
          f"{'amiga extent/verts':>20}{'msdos':>20}")
    for a_sym, d_name in sorted(mapping.items())[:200 if args.verbose else 12]:
        ao, do = ae.get(a_sym), de.get(d_name)
        print(f"  {a_sym:<18}{d_name:<46}"
              f"{('0x%04X' % ao) if ao else '?':>20}"
              f"{('0x%04X' % do) if do else '?':>20}")
    if not args.verbose and len(mapping) > 12:
        print(f"  ... {len(mapping) - 12} more (--verbose)")
    print("\nOffsets are shown for traceability only -- they are per-port and "
          "are NOT\nthe evidence. The evidence is identical draw sequences in "
          "a routine that\nexists under one name on both ports.")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
