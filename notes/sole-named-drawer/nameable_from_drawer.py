#!/usr/bin/env python3
"""Polygons the routine layer can name, instead of the other way round.

Question answered
-----------------
`notes/caller-derived-naming/named_art_only.py` established the direction of
the backlog: the big stages' routine layer waits on their polygon layer,
because a routine drawing only unidentified art cannot be named from it. That
is true of the bulk. It is not true of everything, and this measures the
exception -- **unnamed polygons whose drawer is already named**, where the
dependency runs the other way and the polygon layer is the one that can move.

Across the two priority ports, 799 unnamed `CINEMATIC_<index>` constants are
drawn by exactly one routine and that routine has a semantic name. That number
is the *pool*, not the yield, and the gap between them is the whole point of
this file: a routine's name describes the routine, and only sometimes
describes its art.

Two counter-examples from CAVES, both real:

  * `FILL_PAGE_00_COLOR_08` draws two constants. It is a mechanism name. The
    art is not "a page fill".
  * `CAVES_SCREEN_70_BACKDROP_DRAW` draws three, and two of them are drawn by
    *other* screens' backdrop routines as well. A shared layer named for one
    screen would be wrong for the others -- the shape of #0118.

So the rule here is deliberately narrow, and it is the narrowness that makes
the result applicable without a render:

  1. the routine's name ends in `_DRAW` and is semantic;
  2. it draws exactly one distinct constant, and that constant is still
     `CINEMATIC_<index>`;
  3. no other routine in the stage draws it;
  4. it is not drawn at `x=[0x07], y=[0x08]` (#0138 -- no actor claim);
  5. the derived name, the routine's minus `_DRAW`, is not already taken.

The constant then takes the routine's name. One routine, one draw, one user:
there is no index to invent and no second subject to confuse.

Verify, do not just transfer
----------------------------
A name arriving this way should still be checked against the art's measured
shape, because the check is nearly free and it has teeth. For the eight this
reported on 2026-09-19 it passed loudly: the two teleport beams measure 6x94
and 6x80 with 4 leaves -- a thin vertical sliver, which is what a beam is --
and the two backdrops measure 538x436 with 240 leaves and 544x470 with 24.
Cross-port the four pairs are identical in extent, leaf count and corners at
different indices (amiga 856/854/432/540, msdos 879/877/453/561), which is
the offset-and-render agreement NAMING.md wants and never an index match.

Usage
-----
    python3 notes/sole-named-drawer/nameable_from_drawer.py
    python3 notes/sole-named-drawer/nameable_from_drawer.py --pool
    python3 notes/sole-named-drawer/nameable_from_drawer.py --proposals OUT.md

`--pool` prints the wider 799 instead, grouped by drawer, for picking further
batches by hand. Those need a render; the default list does not.
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT.parent / "another-world-archaeology" / "tools"))
from naming_census import classify                      # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]
RE_LABEL = re.compile(r"^([A-Za-z_]\w*):")
RE_DRAW = re.compile(r"video\s+(?:type=\d+,\s*)?offset=([A-Za-z_]\w*)")
RE_ACTOR = re.compile(r"x=\[0x07\]\s*,\s*y=\[0x08\]")
RE_NUM = re.compile(r"^CINEMATIC_\d+$")


def parse(path: Path) -> dict[str, list[str]]:
    bodies: dict[str, list[str]] = {}
    cur = None
    for line in path.read_text(errors="replace").splitlines():
        m = RE_LABEL.match(line)
        if m:
            cur = m.group(1)
            bodies.setdefault(cur, [])
            continue
        if cur is not None:
            t = line.split(";", 1)[0]
            if t.strip():
                bodies[cur].append(t)
    return bodies


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--pool", action="store_true")
    ap.add_argument("--proposals", type=Path)
    ap.add_argument("--port", action="append", choices=sorted(PORTS))
    args = ap.parse_args()

    rows: list[tuple[str, str, str, str]] = []
    pool: list[tuple[str, str, str, str]] = []
    skipped = collections.Counter()
    for port in args.port or sorted(PORTS):
        for stage in STAGES:
            path = ROOT / "src" / "levels" / PORTS[port] / f"{stage}.asm"
            if not path.is_file():
                continue
            bodies = parse(path)
            drawn: dict[str, set[str]] = collections.defaultdict(set)
            for lab, body in bodies.items():
                for line in body:
                    for m in RE_DRAW.finditer(line):
                        if RE_NUM.match(m.group(1)):
                            drawn[m.group(1)].add(lab)
            for const, labs in drawn.items():
                if len(labs) == 1 and classify(next(iter(labs))) == "semantic":
                    pool.append((port, stage, const, next(iter(labs))))
            for lab, body in bodies.items():
                if not lab.endswith("_DRAW") or classify(lab) != "semantic":
                    continue
                seq = [m.group(1) for line in body
                       for m in RE_DRAW.finditer(line)]
                nums = [c for c in seq if RE_NUM.match(c)]
                if len(set(seq)) != 1 or len(nums) != 1:
                    continue
                const = nums[0]
                if drawn[const] != {lab}:
                    continue
                if any(RE_ACTOR.search(line) for line in body):
                    skipped["draws at the actor slot (#0138)"] += 1
                    continue
                new = "CINEMATIC_" + lab[: -len("_DRAW")]
                if new in bodies or new in drawn:
                    skipped["derived name already taken"] += 1
                    continue
                rows.append((port, stage, const, new))

    if args.pool:
        by: dict[str, list[str]] = collections.defaultdict(list)
        for port, stage, const, lab in pool:
            by[f"{port}/{stage}  {lab}"].append(const)
        print(f"{len(pool)} unnamed constants have exactly one drawer and it "
              f"is named.\nThese need a render; the default list does not.\n")
        for k in sorted(by, key=lambda k: -len(by[k]))[:40]:
            print(f"  {len(by[k]):3d}  {k}")
        return 0

    print(f"{len(rows)} constant(s) nameable from a sole `_DRAW` routine:\n")
    for port, stage, const, new in rows:
        print(f"  {port}/{stage:<10} {const:<18} -> {new}")
    for why, n in skipped.items():
        print(f"\n  ({n} skipped: {why})")
    if args.proposals:
        ev = ("Sole-named-drawer. The routine's name ends in `_DRAW`, it draws "
              "this one constant and nothing else, and no other routine in the "
              "stage draws it, so the routine's subject is this polygon's "
              "subject with no index to invent. Not drawn at `[0x07],[0x08]`, "
              "so no actor is asserted (#0138).")
        for port in sorted({r[0] for r in rows}):
            out = args.proposals.with_name(
                args.proposals.stem + f"_{port}" + args.proposals.suffix)
            with out.open("w") as f:
                f.write("| constant | proposed name | confidence | evidence |\n")
                f.write("| --- | --- | --- | --- |\n")
                for p, s, c, n in rows:
                    if p == port:
                        f.write(f"| {c} | {n} | high | {ev} |\n")
            print(f"\nwrote {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
