#!/usr/bin/env python3
"""Do the two priority ports agree about what a shared polygon name draws?

Question answered
-----------------
A polygon name is earned by rendering, in one port. `docs/NAMING.md` §2 then
forbids carrying it to another port's symbol: "Never take a name earned on one
port's render to another port's symbol. It would be right 2% of the time."
Issue #0107 is that rule being broken, and it has been broken more than once --
sixteen CAPSULE names in an earlier pass, and six CAVES hero-idle names on
2026-09-19, all of them landing at the SAME EQU-table index in the other port,
which is the same line number, because the tables are emitted in index order.

Those were found one family at a time, by suspicion. This measures the whole
tree instead: for every semantic `CINEMATIC_*` name defined in both priority
ports, it measures the art each port's symbol actually points at and reports
the ones that disagree.

What it measures
----------------
Per name, in each port's own ROM slab: the drawn extent and the leaf count of
the polygon tree at that port's offset for that name. Agreement means the two
ports' symbols hold the same picture, which is what a shared name claims.
Extent plus leaf count is the project's established identity test -- it is
what settled the CAVES hero idle families five for five -- and it never
compares indices.

For a disagreement the tool also searches the other port's whole table for a
constant whose art DOES match, and names it. That is the constructive half:
it says not just "this name is wrong here" but "this is the constant it
belongs on".

Result on 2026-09-19
--------------------
1,482 shared semantic names compared, **1,400 agree and 82 do not**, spread
over CAVES 26, PRISON 19, LAKE 17, INTRO 10, CAPSULE 9, PASSCODE 1.

The disagreements are shuffles, not noise. msdos's
`CINEMATIC_BUDDY_CRAWLING_STUCK_AT_RING` measures 410x253 with 525 leaves,
which is exactly what amiga's `CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0` measures;
msdos's own `..._BG_0` is a 37x4 eight-leaf sliver. The names were copied by
index and landed on each other's art.

Caveat, stated plainly
----------------------
Disagreement is not proof of misapplication. The ports really do differ: the
1991 release has frames the 1992 ports dropped, so a family can legitimately
hold neighbouring frames at one index. What makes a row actionable is the
second column -- a different constant in the same port whose art matches
exactly -- plus a check of which routine draws it. Treat the list as a
worklist, not a verdict.

Exit status
-----------
1 when any shared name disagrees, so the count cannot drift upward unnoticed.

Usage
-----
    python3 notes/crossport-name-audit/shared_name_art_audit.py
    python3 notes/crossport-name-audit/shared_name_art_audit.py --stage CAVES
    python3 notes/crossport-name-audit/shared_name_art_audit.py --suggest
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT.parent / "another-world-archaeology" / "tools"))
from _paths import REPO_ROOT                       # noqa: E402
from polygon_tree import parse_polygon_tree        # noqa: E402
from polygon_extent import extent                  # noqa: E402

STAGES = {0: "CODE_WHEEL", 1: "INTRO", 2: "LAKE", 3: "PRISON", 4: "CAVES",
          5: "TANK", 6: "CAPSULE", 7: "ENDING", 8: "PASSCODE"}
PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
SLAB = 0x10000
RE_EQU = re.compile(r"^(CINEMATIC_\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)
RE_NUM = re.compile(r"^CINEMATIC_\d+$")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--stage", action="append")
    ap.add_argument("--suggest", action="store_true",
                    help="for each disagreement, the other port's constant "
                         "whose art matches")
    args = ap.parse_args()
    want = set(args.stage) if args.stage else None

    roms = {}
    for p in PORTS:
        f = REPO_ROOT / "tmp" / "output" / p / "romset" / "cinematic.rom"
        if not f.is_file():
            print(f"{f} missing -- run `make extract`", file=sys.stderr)
            return 2
        roms[p] = f.read_bytes()

    tot = collections.Counter()
    rows: list[tuple] = []
    for si, stage in STAGES.items():
        if want and stage not in want:
            continue
        tabs = {}
        for port, br in PORTS.items():
            f = ROOT / "src" / "levels" / br / f"{stage}.asm"
            if not f.is_file():
                tabs = {}
                break
            tabs[port] = {m.group(1): int(m.group(2), 16)
                          for m in RE_EQU.finditer(f.read_text(errors="replace"))}
        if len(tabs) < 2:
            continue
        slabs = {p: roms[p][si * SLAB:(si + 1) * SLAB] for p in PORTS}

        def measure(port: str, off: int):
            a = extent(parse_polygon_tree(slabs[port], off))
            return None if a[4] == 0 else (round(a[2] - a[0]),
                                           round(a[3] - a[1]), a[4])

        art = {p: {n: measure(p, o) for n, o in tabs[p].items()} for p in PORTS}
        # reverse index for the suggestion: art -> names, per port
        rev = {p: collections.defaultdict(list) for p in PORTS}
        for p in PORTS:
            for n, a in art[p].items():
                if a:
                    rev[p][a].append(n)

        for name in tabs["amiga"]:
            if RE_NUM.match(name) or name not in tabs["msdos"]:
                continue
            a, m = art["amiga"][name], art["msdos"][name]
            if a is None or m is None:
                tot["unparsable in one port"] += 1
                continue
            tot["shared semantic names compared"] += 1
            if a == m:
                tot["  art agrees"] += 1
            else:
                tot["  art DIFFERS"] += 1
                holder = [x for x in rev["msdos"].get(a, []) if x != name]
                rows.append((stage, name, a, m, holder))

    for k, v in tot.items():
        print(f"{v:6d}  {k}")
    if rows:
        print("\ndisagreements by stage:")
        for k, v in collections.Counter(r[0] for r in rows).most_common():
            print(f"  {v:5d}  {k}")
        print("\n  stage      name"
              "                                     amiga        msdos")
        for stage, name, a, m, holder in sorted(
                rows, key=lambda r: (-abs(r[2][2] - r[3][2]))):
            s = (f"  {stage:<9} {name:<45} "
                 f"{a[0]}x{a[1]}/{a[2]:<6} {m[0]}x{m[1]}/{m[2]}")
            if args.suggest and holder:
                s += f"\n{'':<12}-> msdos holds amiga's art under {holder[0]}"
            print(s)
        print(f"\n{len(rows)} shared name(s) disagree about their art. "
              f"Disagreement is not proof:\nthe releases really do differ. A "
              f"row is actionable when --suggest finds the same\nart in the "
              f"other port under another name, and the routine that draws it "
              f"agrees.")
        return 1
    print("\nEvery shared semantic polygon name holds the same art in both "
          "priority ports.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
