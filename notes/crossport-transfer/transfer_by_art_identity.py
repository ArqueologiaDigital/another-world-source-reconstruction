#!/usr/bin/env python3
"""Names one port earned, on art the other port holds unnamed.

Question answered
-----------------
`docs/NAMING.md` §2 forbids carrying a name earned on one port's render to
another port's symbol, and #0107 is that rule being broken -- repeatedly,
because the tempting shortcut is the EQU **index**, which is per-port and
means nothing across ports.

The rule forbids the shortcut, not the transfer. Where the two ports hold
the *same picture*, a name earned on one describes the other, and the whole
of this session's correction work has been establishing what "same picture"
may mean: the md5 of the whole parsed polygon tree, every vertex, in each
port's own ROM slab. That is what this transfers on.

It is the same move already made by hand for CAVES' idle families, the INTRO
tunnel recede, the scanner ring and the TANK capsules, each verified
frame-for-frame before applying. This does it as a measurement.

What is required before a name moves
------------------------------------
  1. the source port has a **semantic** name for that md5;
  2. exactly one, so there is nothing to choose between (#0120);
  3. the destination holds that md5 under exactly one constant, and that
     constant is still `CINEMATIC_<index>` -- if it is already named, the
     ports disagree and that is the cross-port audit's business, not this;
  4. the destination does not already define the name for something else.

Transfers are then applied per branch with `apply_branch_scoped_names.py`,
whose own validator adds the family-gap check -- a transferred subset of a
family must not open a hole the source does not have.

Result on 2026-09-19
--------------------
278 constants qualify: 262 msdos (INTRO 203, CAVES 40, CAPSULE 14, TANK 5)
and 16 amiga (INTRO 12, CAVES 2, CAPSULE 2). The asymmetry is itself a fact
worth recording -- amiga is where most of the naming was done, so it is
mostly amiga's names that have somewhere to go.

**71 applied, 203 blocked.** Everything outside msdos/INTRO went in: amiga
CAVES 2, amiga CAPSULE 2, msdos TANK 5, amiga INTRO 12, msdos CAPSULE 8 of
14 (the rename validator held the other 6 on its own family-gap rule), msdos
CAVES 40.

msdos/INTRO's 203 looked blocked by the tree: applying the batch left 42
undefined references at 26/29, and extending to cartridge_1992 and gba_2004
-- the fix that worked for LAKE's three-port arms -- changed neither number.
That read was wrong, and the way it was wrong is the lesson: **the batch was
not blocked, fourteen of its rows were.**

Applying, collecting the undefined names, reverting and dropping just those,
twice, converges in two iterations: 12 names then 2 more, and the remaining
**186 apply at 29/29 and 29/29**. The fourteen are names like
`CINEMATIC_CARPARK_NEAR_PILLAR` and `CINEMATIC_IDENT_SCREEN_GRATICULE`, read
from shared chunks by the 1992 ports while defined only in amiga blocks.
They still want INTRO's chunks restructured; the other 186 never did.

Reading a batch failure as a batch verdict cost this pass a commit that said
203 were blocked when 14 were. `undefined_symbols.py` names the symbols, so
the failing rows can always be subtracted rather than the batch abandoned.

**The lever is spent.** Re-running after the 186 landed offers 23 more --
naming one port can unlock a transfer the other way -- but all 23 fail: 17
msdos/INTRO are the tree-blocked names again or rejected by the rename
validator's family-gap rule, and 6 msdos/CAPSULE are rejected by the same
rule. What remains needs either INTRO's chunks restructured or a family
completed first, and neither is a transfer. Re-run this after any of that
lands, because each name given somewhere can open a transfer elsewhere.

Applying also needs a step this probe does not do. Where the unified tree
defines a transferred name UNCONDITIONALLY, that definition belongs to the
SOURCE port: the destination's new definition is overridden by it and the
destination's bytes move, with every symbol still defined, so
undefined_symbols.py stays clean and only the byte gate notices. Scope it to
the source port's branches -- byte-neutral, EQU lines emit nothing. Thirteen
such definitions across INTRO and CAPSULE. And scope only the names actually
applied: scoping one that was rejected breaks the port that still relies on
it, which cost a revert here.

Usage
-----
    python3 notes/crossport-transfer/transfer_by_art_identity.py
    python3 notes/crossport-transfer/transfer_by_art_identity.py --proposals OUT
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT.parent / "another-world-archaeology" / "tools"))
from _paths import REPO_ROOT                                # noqa: E402
from polygon_tree import parse_polygon_tree, canonical_md5  # noqa: E402
from polygon_extent import extent                           # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGES = {0: "CODE_WHEEL", 1: "INTRO", 2: "LAKE", 3: "PRISON", 4: "CAVES",
          5: "TANK", 6: "CAPSULE", 7: "ENDING", 8: "PASSCODE"}
SLAB = 0x10000
RE_EQU = re.compile(r"^(CINEMATIC_\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)
RE_NUM = re.compile(r"^CINEMATIC_\d+$")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--proposals", type=Path,
                    help="stem; one table per (port, stage) is written")
    ap.add_argument("--stage", action="append")
    args = ap.parse_args()
    want = set(args.stage) if args.stage else None

    roms = {}
    for p in PORTS:
        f = REPO_ROOT / "tmp" / "output" / p / "romset" / "cinematic.rom"
        if not f.is_file():
            print("run `make extract` first", file=sys.stderr)
            return 2
        roms[p] = f.read_bytes()

    skipped = collections.Counter()
    out: dict[tuple[str, str], list[tuple[str, str, str]]] = \
        collections.defaultdict(list)
    for si, stage in STAGES.items():
        if want and stage not in want:
            continue
        tab = {}
        for port, br in PORTS.items():
            f = ROOT / "src" / "levels" / br / f"{stage}.asm"
            if not f.is_file():
                tab = {}
                break
            tab[port] = {m.group(1): int(m.group(2), 16)
                         for m in RE_EQU.finditer(f.read_text(errors="replace"))}
        if len(tab) < 2:
            continue
        slabs = {p: roms[p][si * SLAB:(si + 1) * SLAB] for p in PORTS}
        by: dict[str, dict[str, list[str]]] = {}
        ext: dict[str, dict[str, tuple]] = {}
        for port in PORTS:
            by[port] = collections.defaultdict(list)
            ext[port] = {}
            for n, o in tab[port].items():
                t = parse_polygon_tree(slabs[port], o)
                if not t:
                    continue
                a = extent(t)
                if a[4] == 0:
                    continue
                by[port][canonical_md5(t)].append(n)
                ext[port][n] = (round(a[2] - a[0]), round(a[3] - a[1]), a[4])

        for src, dst in (("amiga", "msdos"), ("msdos", "amiga")):
            for h, names in by[src].items():
                sem = [n for n in names if not RE_NUM.match(n)]
                if not sem:
                    continue
                if len(sem) > 1:
                    skipped["source has two names for one picture (#0120)"] += 1
                    continue
                targets = by[dst].get(h, [])
                if not targets:
                    continue
                if any(not RE_NUM.match(n) for n in targets):
                    skipped["destination already names it -- the cross-port "
                            "audit's business"] += 1
                    continue
                if len(targets) > 1:
                    skipped["destination holds the picture twice; one name "
                            "cannot go to both"] += 1
                    continue
                if sem[0] in tab[dst]:
                    skipped["destination already uses that name for other "
                            "art"] += 1
                    continue
                out[(dst, stage)].append((targets[0], sem[0],
                                          f"{ext[src][sem[0]][0]}x"
                                          f"{ext[src][sem[0]][1]}/"
                                          f"{ext[src][sem[0]][2]}"))

    total = sum(len(v) for v in out.values())
    print(f"{total} constant(s) can take a name the other port earned\n")
    for (port, stage), rows in sorted(out.items(), key=lambda kv: -len(kv[1])):
        print(f"  {port}/{stage:<10} {len(rows):4d}")
    if skipped:
        print("\nnot offered:")
        for k, v in skipped.most_common():
            print(f"  {v:5d}  {k}")
    if args.proposals:
        for (port, stage), rows in out.items():
            f = args.proposals.with_name(
                f"{args.proposals.stem}_{port}_{stage}.md")
            with f.open("w") as fh:
                fh.write("| constant | proposed name | confidence | "
                         "evidence |\n| --- | --- | --- | --- |\n")
                for const, name, dims in rows:
                    src = "amiga" if port == "msdos" else "msdos"
                    fh.write(
                        f"| {const} | {name} | high | Cross-port transfer by "
                        f"ART IDENTITY, never by index. `{name}` was earned "
                        f"in {src}, and this {port} constant's polygon tree "
                        f"is byte-identical to it -- the same md5 over every "
                        f"vertex, measured in each port's own ROM slab, "
                        f"{dims}. {src} has exactly one name for that "
                        f"picture and {port} holds it under exactly this one "
                        f"constant, still numeric, so there is nothing to "
                        f"choose between and nothing displaced. |\n")
            print(f"  wrote {f}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
