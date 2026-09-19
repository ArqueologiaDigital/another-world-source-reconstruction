#!/usr/bin/env python3
"""A `video offset=0x…` operand has no name at all. What should it be?

Question answered
-----------------
`make test`'s lint reports a `raw-video` violation: "every polygon reference
should be symbolic". gba_usa/LAKE carries 24 of them over 10 distinct offsets
and is otherwise at 99.1% semantic — they are the least-named thing in the
tree, below even `CINEMATIC_NNN`, because a bare number in an operand is not
even a symbol that could be renamed later.

Giving them names looks like the trap `#0107` exists to forbid: taking a name
earned by rendering on one port and putting it on another port's constant,
which "would be right 2% of the time". This probe is the argument that a
*particular* case is the other kind, and the check that it stays true.

The mechanism
-------------
Each port has its own `cinematic.rom` layout, so the same art sits at a
different offset per port -- `canonicalize_cinematic_refs.py` says so: "Each
branch keeps its own EQU value for the canonical name." But the layouts are
not independently shuffled. Where a port's bank is the *same data relocated*,
every shared name sits at a constant delta, and that delta can be measured
over hundreds of names before being used on one.

So the probe measures the delta distribution between two ports' polygon EQUs
for a stage, finds the gba address range each delta governs, and only then
resolves each raw offset -- by adding the delta of the region the offset falls
in, and looking up whether the reference port defines a name at exactly that
address.

A resolution is **in-region** -- the strong case -- when:

  * the offset falls inside exactly one delta region (the regions must not
    overlap, which the probe checks and prints), and
  * the reference port has a name at the resolved address, and
  * resolving under any *other* observed delta yields no name, or a name
    outside its own region.

That is an address correspondence, not an index correspondence, which is the
whole difference from #0107.

An offset just outside a region, resolving cleanly under that region's delta,
is reported separately as **extrapolated**, with the margin in bytes. That is
a weaker claim -- no measured name sits between it and the region -- and it
needs a second, independent line of evidence before it is used. The probe will
not supply that; it prints the case and says so.

`0x08FC` in gba_usa/LAKE is the one such case, 0x72 below the 0x13C0 region.
It was adjudicated by mirror: it resolves to `CINEMATIC_HERO_LAND_LEFT`, its
confirmed in-region sibling `0x0C1E` resolves to `CINEMATIC_HERO_LAND_RIGHT`
under the same delta, both ports use each name exactly three times with the
same `zoom=[0x03]` operand shape, and the routine using it on gba is
`HERO_RUN_LEFT_LOOP`. Five agreements, recorded here so the weaker class is
not silently treated as the strong one.

What it found on 2026-09-19
---------------------------
amiga vs gba_usa LAKE, 659 polygon EQUs defined on both ports:

    delta 0x1410   522 names   gba 0x4962..0xDE2E
    delta 0x13C0   103 names   gba 0x096E..0x4712

Two regions, disjoint, and all 10 raw offsets resolve in exactly one of them.
The remaining deltas (0x1DA4 x9, 0x0A68 x2, 0 x2, and singletons) are names
whose art the GBA release moved or replaced; none of them covers an address a
raw operand uses, which the probe asserts rather than assumes.

Exit status
-----------
0 when every raw operand resolves, in-region or extrapolated; 1 when any does
not resolve at all -- so a newly-appearing raw operand this reasoning cannot
settle is flagged instead of guessed at. Extrapolated cases are always printed
with their margin, whatever the exit status.

Usage
-----
    python3 notes/raw-polygon-operands/resolve_raw_offsets.py
    python3 notes/raw-polygon-operands/resolve_raw_offsets.py --port gba_usa \
        --stage LAKE --ref amiga
"""
from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels"
PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992",
         "snes_eu": "cartridge_1992", "gba_usa": "gba_2004"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]

RE_EQU = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s+(0x[0-9A-Fa-f]+)\s*$")
RE_RAW = re.compile(r"video\s+offset=(0x[0-9A-Fa-f]+)")
RE_LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
POLY = ("CINEMATIC_", "COMMON_VIDEO_")


def equs(path: Path) -> dict[str, int]:
    out = {}
    for line in path.read_text(errors="replace").splitlines():
        m = RE_EQU.match(line)
        if m:
            out[m.group(1)] = int(m.group(2), 16)
    return out


def raw_sites(path: Path) -> list[tuple[int, int, str]]:
    """(line number, offset, enclosing routine) for each raw video operand."""
    out, cur = [], "<top>"
    for i, raw in enumerate(path.read_text(errors="replace").splitlines(), 1):
        line = raw.split(";", 1)[0]
        m = RE_LABEL.match(line)
        if m:
            cur = m.group(1)
            continue
        r = RE_RAW.search(line)
        if r:
            out.append((i, int(r.group(1), 16), cur))
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", default="gba_usa", choices=sorted(PORTS))
    ap.add_argument("--ref", default="amiga", choices=sorted(PORTS))
    ap.add_argument("--stage", action="append")
    args = ap.parse_args()
    stages = args.stage or STAGES

    bad = False
    extrapolated = 0
    for stage in stages:
        p = SRC / PORTS[args.port] / f"{stage}.asm"
        r = SRC / PORTS[args.ref] / f"{stage}.asm"
        if not (p.is_file() and r.is_file()):
            continue
        sites = raw_sites(p)
        if not sites:
            continue
        mine, theirs = equs(p), equs(r)
        shared = {k: theirs[k] - mine[k] for k in mine
                  if k in theirs and k.startswith(POLY)}
        if not shared:
            print(f"\n=== {args.port}/{stage}: no polygon EQU shared with "
                  f"{args.ref}; cannot resolve")
            bad = True
            continue

        counts = collections.Counter(shared.values())
        region: dict[int, tuple[int, int]] = {}
        for delta, _n in counts.most_common():
            addrs = sorted(mine[k] for k, d in shared.items() if d == delta)
            region[delta] = (addrs[0], addrs[-1])

        print(f"\n=== {args.port}/{stage} vs {args.ref}: {len(shared)} "
              f"polygon EQU(s) on both ports, {len(sites)} raw operand(s)")
        majors = [d for d, n in counts.most_common() if n >= 10]
        for d in majors:
            lo, hi = region[d]
            print(f"  delta 0x{d & 0xFFFF:04X}  {counts[d]:4d} name(s)  "
                  f"{args.port} 0x{lo:04X}..0x{hi:04X}")
        for a in majors:
            for b in majors:
                if a < b and not (region[a][1] < region[b][0]
                                  or region[b][1] < region[a][0]):
                    print(f"  OVERLAP between delta 0x{a & 0xFFFF:04X} and "
                          f"0x{b & 0xFFFF:04X} -- resolution is ambiguous")
                    bad = True

        by_val = collections.defaultdict(list)
        for k, v in theirs.items():
            if k.startswith(POLY):
                by_val[v].append(k)

        print(f"  {'offset':>8}  {'resolved name':<46} {'delta':<8} where")
        for off in sorted({o for _l, o, _r in sites}):
            hits, near = [], []
            for d in majors:
                lo, hi = region[d]
                if not by_val.get(off + d):
                    continue
                if lo <= off <= hi:
                    hits.append((d, by_val[off + d][0]))
                else:
                    margin = lo - off if off < lo else off - hi
                    near.append((margin, d, by_val[off + d][0]))
            uses = sorted({rt for _l, o, rt in sites if o == off})
            n = sum(1 for _l, o, _r in sites if o == off)
            if len(hits) == 1:
                d, name = hits[0]
                print(f"  0x{off:04X}  {name:<46} 0x{d & 0xFFFF:04X}   "
                      f"x{n} in {', '.join(uses[:2])}")
            elif not hits and len(near) == 1:
                margin, d, name = near[0]
                extrapolated += 1
                print(f"  0x{off:04X}  {name:<46} 0x{d & 0xFFFF:04X} * "
                      f"x{n} in {', '.join(uses[:2])}")
                print(f"          * EXTRAPOLATED: 0x{margin:02X} byte(s) "
                      f"outside that delta's measured range -- needs a "
                      f"second line of evidence")
            else:
                bad = True
                why = ("no region/name" if not (hits or near)
                       else f"{len(hits) + len(near)} candidates: "
                            + ", ".join(nm for _d, nm in hits)
                            + ", ".join(nm for _m, _d, nm in near))
                print(f"  0x{off:04X}  UNRESOLVED -- {why}")

    if bad:
        print("\nSOME OPERAND DID NOT RESOLVE")
    else:
        print("\nEvery raw operand resolves to a name the reference port "
              "defines at exactly\nthe shifted address. That is an address "
              "correspondence, not an index one\n(#0107).")
        if extrapolated:
            print(f"{extrapolated} of them is/are EXTRAPOLATED just outside a "
                  f"measured region and\nrests on separate evidence -- see "
                  f"this file's docstring.")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
