#!/usr/bin/env python3
"""Which pictures are N exact copies of another picture?

Question answered
-----------------
Rendering CAVES screen 0x6C showed a scatter of small two-part specks across
the cavern floor, and one tile next to it holding a single speck of the same
shape. That is checkable without deciding what a speck depicts:

    CINEMATIC_336 has 2 leaf shapes -- one 4x1, one 0x1.
    CINEMATIC_407 has 38 leaves: 19 of each, every one byte-identical.

`CINEMATIC_407` **is** 19 copies of `CINEMATIC_336`. Exact composition, not
resemblance. If either member were named the other would follow, so the
question worth asking tree-wide is how often this happens.

Why the obvious version of the question is useless
--------------------------------------------------
Asked plainly -- "is this picture's leaf multiset a whole multiple of that
one's?" -- there are **4,736** such pairs across PRISON, CAVES and CAPSULE in
both priority ports, and they are noise. A one-leaf unit divides anything
built from that leaf, so `CINEMATIC_093` alone "decomposes" into ten different
1-leaf constants at once, including three that are already named for entirely
different things.

Two filters make it mean something:

* the composite must have **exactly one** candidate unit -- 245 have several,
  and a decomposition that is not unique is not a decomposition;
* the unit must have **two or more distinct leaf shapes**, so it is a shape
  rather than a repeated dot. 3 more fall here.

That leaves **2**, and they are the same pair seen from both ports:

    amiga CAVES   CINEMATIC_407 = 19 x CINEMATIC_336
    msdos CAVES   CINEMATIC_428 = 19 x CINEMATIC_357

Both members of both are still numbered, so there is nothing to inherit and
this names nothing today. It is committed because the relation is exact and
because naming either member now names its partner for free -- which is worth
knowing before someone names one of them in isolation.

Usage
-----
    python3 notes/scene-reading/composed_of.py
    python3 notes/scene-reading/composed_of.py --all   # the 4,736, to see the noise
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(SRC / "notes" / "polygon-extent-correction"))
sys.path.insert(0, str(SRC.parent / "another-world-archaeology" / "tools"))
from polygon_tree import parse_polygon_tree                  # noqa: E402
from extent_matches_renderer import slab                     # noqa: E402

PORTS = (("chahi_amiga_1991", "amiga"), ("dos_1992", "msdos"))
STAGE_ID = {"PRISON": 3, "CAVES": 4, "CAPSULE": 6}
RE_NUM = re.compile(r"^CINEMATIC_\d+$")
RE_EQU = re.compile(r"^(CINEMATIC_[A-Za-z0-9_]+)\s+EQU\s+(0x[0-9A-Fa-f]+)",
                    re.M)


def leaf_counts(bank, off):
    t = parse_polygon_tree(bank, off)
    out = []

    def walk(x):
        if x[0] == "solid":
            out.append((x[1], x[2], tuple(x[3])))
        else:
            for _cx, _cy, _c, ch in x[3]:
                walk(ch)
    walk(t)
    return collections.Counter(out)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--all", action="store_true",
                    help="drop both filters, to see why they are needed")
    args = ap.parse_args()

    rows, held = [], collections.Counter()
    for branch, port in PORTS:
        for stage, sid in STAGE_ID.items():
            f = SRC / "src" / "levels" / branch / f"{stage}.asm"
            if not f.is_file():
                continue
            equ = {n: int(v, 16)
                   for n, v in RE_EQU.findall(f.read_text(errors="replace"))}
            bank = slab("cinematic", port, sid)
            leaves = {}
            for n, o in equ.items():
                try:
                    leaves[n] = leaf_counts(bank, o)
                except Exception:
                    pass
            for big, cb in leaves.items():
                if sum(cb.values()) < 4:
                    continue
                units = []
                for unit, cu in leaves.items():
                    if unit == big or not cu:
                        continue
                    if sum(cu.values()) >= sum(cb.values()):
                        continue
                    if set(cb) != set(cu):
                        continue
                    r = sum(cb.values()) // sum(cu.values())
                    if r < 2 or any(cb[k] != cu[k] * r for k in cu):
                        continue
                    units.append((unit, r))
                if args.all:
                    for unit, r in units:
                        rows.append((branch, stage, unit, big, r))
                    continue
                if len(units) != 1:
                    held["the composite has several candidate units"] += bool(units)
                    continue
                unit, r = units[0]
                if len(leaves[unit]) < 2:
                    held["the unit is a single repeated leaf"] += 1
                    continue
                rows.append((branch, stage, unit, big, r))

    print(f"  {len(rows)} pair(s)\n")
    for branch, stage, unit, big, r in rows[:40]:
        tag = []
        if not RE_NUM.match(unit):
            tag.append("unit NAMED")
        if not RE_NUM.match(big):
            tag.append("composite NAMED")
        print(f"  {branch[:5]:<6}{stage:<9}{big:<42}= {r:>3} x {unit:<40}"
              f"{', '.join(tag)}")
    if len(rows) > 40:
        print(f"  ... and {len(rows) - 40} more")
    print()
    for why, c in held.most_common():
        print(f"  held: {c:>5}  {why}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
