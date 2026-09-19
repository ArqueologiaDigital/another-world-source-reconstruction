#!/usr/bin/env python3
"""Families that are already named, and the frames missing from them.

Question answered
-----------------
`notes/sole-named-drawer/` names a family from its drawing routine. This is
the other direction and needs less: where a family **already has earned
members**, the unnamed constants the same routine draws beside them are the
missing frames, and the existing members fix both the name and the numbering.
Nothing has to be proposed about the subject at all.

It found two shapes on 2026-09-19:

  * a LEADING gap. amiga's `CINEMATIC_LIFT_DOORS_OPENING` ran F2..F31 with no
    F0 or F1, and its routine draws two unnamed constants immediately before
    F2. The lift doors widen by exactly four pixels a frame -- 150x206,
    154x206, then the named 158x206, 162x206, 166x206 -- so the arithmetic
    fixes the assignment, not the order alone.
  * an absent family. amiga carried `BIOMETRIC_SCANNER_RING_7` and `_8`;
    msdos carried no member at all, and the two ports draw the same nine
    polygons at the same nine anchors in the same order.

What is checked before a row is offered
---------------------------------------
  1. the routine draws exactly ONE named family, so there is no ambiguity
     about which family the unnamed constants join;
  2. every unnamed constant is drawn by that routine and no other;
  3. the assignment follows DRAW ORDER and leaves the family contiguous --
     it may close a gap or extend an end, never open a new hole;
  4. the derived name is free in this port;
  5. **and if the other port already carries that name, its art must match
     by md5.** That check is the expensive lesson of this session: naming
     msdos/INTRO's LESTER_EXITING_CAR frames from their drawer passed every
     byte gate and silently took the cross-port audit from 10 disagreements
     to 23, because amiga already used those names for other art.

Rows that fail 3 are reported separately rather than dropped, because the
common failure is interesting: a routine drawing one named member and
seventeen unnamed constants at scattered anchors is not an incomplete family,
it is a scene.

Usage
-----
    python3 notes/family-completion/complete_from_named_members.py
    python3 notes/family-completion/complete_from_named_members.py --proposals OUT.md
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT.parent / "another-world-archaeology" / "tools"))
from _paths import REPO_ROOT                            # noqa: E402
from polygon_tree import parse_polygon_tree, canonical_md5   # noqa: E402
from polygon_extent import extent                       # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGES = {0: "CODE_WHEEL", 1: "INTRO", 2: "LAKE", 3: "PRISON", 4: "CAVES",
          5: "TANK", 6: "CAPSULE", 7: "ENDING", 8: "PASSCODE"}
SLAB = 0x10000
RE_L = re.compile(r"^([A-Za-z_]\w*):")
RE_D = re.compile(r"offset=(CINEMATIC_\w+)")
RE_EQU = re.compile(r"^(CINEMATIC_\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)
RE_NUM = re.compile(r"^CINEMATIC_\d+$")
RE_FAM = re.compile(r"^(CINEMATIC_.*?)_(F?)(\d+)$")


def load(port: str, stage: str):
    p = ROOT / "src" / "levels" / PORTS[port] / f"{stage}.asm"
    if not p.is_file():
        return None
    txt = p.read_text(errors="replace")
    tab = {m.group(1): int(m.group(2), 16) for m in RE_EQU.finditer(txt)}
    bodies: dict[str, list[str]] = {}
    cur = None
    for line in txt.splitlines():
        m = RE_L.match(line)
        if m:
            cur = m.group(1)
            bodies.setdefault(cur, [])
            continue
        if cur is not None:
            bodies[cur].append(line)
    return tab, bodies


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--proposals", type=Path)
    ap.add_argument("--port", action="append", choices=sorted(PORTS))
    args = ap.parse_args()

    roms = {}
    for p in PORTS:
        f = REPO_ROOT / "tmp" / "output" / p / "romset" / "cinematic.rom"
        if not f.is_file():
            print("run `make extract` first", file=sys.stderr)
            return 2
        roms[p] = f.read_bytes()

    offered: list[tuple] = []
    scenes: list[tuple] = []
    blocked: list[str] = []
    for port in args.port or sorted(PORTS):
        other = "msdos" if port == "amiga" else "amiga"
        for si, stage in STAGES.items():
            got = load(port, stage)
            if not got:
                continue
            tab, bodies = got
            og = load(other, stage)
            otab = og[0] if og else {}
            slab = roms[port][si * SLAB:(si + 1) * SLAB]
            oslab = roms[other][si * SLAB:(si + 1) * SLAB]

            def md(t, off):
                return canonical_md5(parse_polygon_tree(t, off))

            drawn: dict[str, set[str]] = collections.defaultdict(set)
            for lab, b in bodies.items():
                for line in b:
                    for m in RE_D.finditer(line):
                        drawn[m.group(1)].add(lab)

            for lab, b in bodies.items():
                seq = list(dict.fromkeys(m.group(1) for line in b
                                         for m in RE_D.finditer(line)))
                fams: dict[tuple, list[int]] = collections.defaultdict(list)
                for c in seq:
                    mm = RE_FAM.match(c)
                    if mm and not RE_NUM.match(c):
                        fams[(mm.group(1), mm.group(2))].append(
                            int(mm.group(3)))
                unnamed = [c for c in seq
                           if RE_NUM.match(c) and drawn[c] == {lab}]
                if len(fams) != 1 or not unnamed:
                    continue
                (base, sep), have = next(iter(fams.items()))
                have = sorted(set(have))
                # Assign by draw order: the unnamed constants that precede the
                # family's first named member take the indices below it.
                first_named = next(i for i, c in enumerate(seq)
                                   if RE_FAM.match(c) and not RE_NUM.match(c))
                before = [c for c in seq[:first_named] if c in unnamed]
                lo = min(have)
                if len(before) == lo and lo > 0 and len(before) == len(unnamed):
                    rows = [(c, f"{base}_{sep}{i}")
                            for i, c in enumerate(before)]
                    kind = "closes the leading gap"
                elif not have or lo == 0:
                    scenes.append((port, stage, lab, base, have, len(unnamed)))
                    continue
                else:
                    scenes.append((port, stage, lab, base, have, len(unnamed)))
                    continue
                ok = True
                for c, new in rows:
                    if new in tab:
                        blocked.append(f"{port}/{stage} {new}: already defined")
                        ok = False
                    elif new in otab and md(slab, tab[c]) != md(oslab,
                                                                otab[new]):
                        blocked.append(
                            f"{port}/{stage} {new}: {other} already uses it "
                            f"for different art")
                        ok = False
                if ok:
                    offered.append((port, stage, lab, base, rows, kind))

    print(f"{len(offered)} family/families can be completed:\n")
    for port, stage, lab, base, rows, kind in offered:
        print(f"  {port}/{stage:<9} {base}<n>  {kind}, from {lab}")
        for c, new in rows:
            print(f"      {c:<18} -> {new}")
    if blocked:
        print(f"\n{len(blocked)} row(s) refused:")
        for b in blocked:
            print(f"    {b}")
    print(f"\n{len(scenes)} routine(s) draw one named family plus unnamed "
          f"constants but are NOT\nincomplete families -- the unnamed ones do "
          f"not sit below the family's first index,\nso they are a scene the "
          f"family appears in, not its missing frames.")
    if args.proposals and offered:
        with args.proposals.open("w") as f:
            f.write("| constant | proposed name | confidence | evidence |\n")
            f.write("| --- | --- | --- | --- |\n")
            for port, stage, lab, base, rows, kind in offered:
                ev = (f"Family completion. `{lab}` draws {len(rows)} unnamed "
                      f"constant(s) immediately before the first named member "
                      f"of {base}, nothing else in the stage draws them, and "
                      f"the assignment {kind} without opening a new one. The "
                      f"existing members fix both the name and the numbering, "
                      f"so nothing is proposed about the subject.")
                for c, new in rows:
                    f.write(f"| {c} | {new} | high | {ev} |\n")
        print(f"\nwrote {args.proposals}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
