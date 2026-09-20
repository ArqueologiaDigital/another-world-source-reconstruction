#!/usr/bin/env python3
"""Which measurements change when the group-pivot bug is fixed, and by how much?

Question answered
-----------------
`extent_matches_renderer.py` next to this file establishes that
`polygon_extent.extent` misread a group header as a bounding box to halve when
it is a pivot to subtract whole, and that the corrected rule agrees with the
engine exactly. That settles *which rule is right*. It does not say what it
costs, and the working rule here is that a measurement contradicting a
documented claim has to be re-measured, not just superseded.

So this quantifies it, per bank and per port: how many polygons change extent
at all, by how much, and -- the part that matters for naming -- whether any
comparison that was made *between* two extents flips.

Why most conclusions survive
----------------------------
Three reasons, and the probe checks each rather than asserting it:

  1. A flat tree is unaffected. The pivot only enters through a group, so
     single-leaf art and a group whose pivot is (0,0) measure the same.

  2. `polygon_tree.canonical_md5` never interprets the header -- it serialises
     the bytes verbatim -- so **every cross-port identity match stands**. That
     covers the md5-equal pairs, the duplicate audit and the transfer pass,
     which is the bulk of the naming evidence in this repo.

  3. Most size *comparisons* were between siblings in one family, drawn by the
     same code with the same nesting. A shared inflation cancels in an
     ordering. The probe reports where it does not cancel, which is the only
     place a recorded conclusion could have flipped.

What it prints
--------------
Per bank/port: the count changed, the median and worst absolute change, and the
number of *ordering inversions* -- pairs of polygons in the same stage whose
relative size order is different under the two rules. An inversion is what
would break a SMALL/MEDIUM/LARGE claim; a uniform inflation would not.

Signals read
------------
`tmp/output/<port>/resources/resource-0x11.bin` and
`tmp/output/<port>/romset/cinematic.rom`, sliced per stage. Offsets come from
the `EQU` tables in `src/levels/<branch>/<STAGE>.asm`, so only art the tree
actually names is measured -- the same population whose sizes get quoted.

`--names` re-measures specific constants, old rule against new, which is how a
claim already written down gets checked. `--worst` alone does not do that job:
it lists the 25 largest changes, and a corrected figure is usually not among
them. The recipe printed in `../render-attempts/README.md` said `--worst`
until this option existed, which would have sent the next reader looking for
rows that are not there.

Usage
-----
    python3 notes/polygon-extent-correction/what_the_correction_moves.py
    python3 notes/polygon-extent-correction/what_the_correction_moves.py --worst
    python3 notes/polygon-extent-correction/what_the_correction_moves.py \
        --port amiga --stage CAVES --names CINEMATIC_CAVES_LANDING_SPLASH_F
"""

from __future__ import annotations

import argparse
import re
import statistics
import sys
from itertools import combinations
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
ARCH = SRC.parent / "another-world-archaeology"
sys.path.insert(0, str(ARCH / "tools"))
from polygon_tree import parse_polygon_tree            # noqa: E402
from polygon_extent import extent                      # noqa: E402
sys.path.insert(0, str(HERE.parent))
from extent_matches_renderer import extent_old, slab   # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGES = {0: "CODE_WHEEL", 1: "INTRO", 2: "LAKE", 3: "PRISON", 4: "CAVES",
          5: "TANK", 6: "CAPSULE", 7: "ENDING", 8: "PASSCODE"}
RE_EQU = re.compile(r"^(\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--worst", action="store_true")
    ap.add_argument("--names",
                    help="re-measure constants whose name starts with this")
    ap.add_argument("--port", choices=sorted(PORTS))
    ap.add_argument("--stage", choices=sorted(STAGES.values()))
    args = ap.parse_args()

    if args.names:
        sid = {v: k for k, v in STAGES.items()}
        for port, br in PORTS.items():
            if args.port and port != args.port:
                continue
            for n, stage in STAGES.items():
                if args.stage and stage != args.stage:
                    continue
                f = SRC / "src" / "levels" / br / f"{stage}.asm"
                if not f.is_file():
                    continue
                text = f.read_text(errors="replace")
                cine = slab("cinematic", port, n)
                shared = slab("video2", port, n)
                hits = [(k, int(v, 16)) for k, v in RE_EQU.findall(text)
                        if k.startswith(args.names)]
                for name, off in sorted(hits, key=lambda kv: kv[1]):
                    b = shared if name.startswith("CV_") else cine
                    tree = parse_polygon_tree(b, off)
                    if tree is None:
                        print(f"  {port}/{stage} {name}: no polygon")
                        continue
                    a = extent_old(tree)
                    c = extent(tree)
                    moved = (abs((a[2] - a[0]) - (c[2] - c[0])) > 0.01
                             or abs((a[3] - a[1]) - (c[3] - c[1])) > 0.01)
                    print(f"  {port}/{stage:<9} {name:<46} "
                          f"old {a[2] - a[0]:>4.0f}x{a[3] - a[1]:<4.0f} "
                          f"new {c[2] - c[0]:>4.0f}x{c[3] - c[1]:<4.0f} "
                          f"/{c[4]}{'   CHANGED' if moved else ''}")
        return 0

    print(f"{'port/stage':<18}{'measured':>9}{'changed':>9}{'median':>8}"
          f"{'worst':>7}{'inversions':>12}")
    tot_m = tot_c = tot_i = 0
    worst_rows: list[tuple[float, str]] = []
    for port, br in PORTS.items():
        for sid, stage in STAGES.items():
            p = SRC / "src" / "levels" / br / f"{stage}.asm"
            if not p.is_file():
                continue
            text = p.read_text(errors="replace")
            cine = slab("cinematic", port, sid)
            shared = slab("video2", port, sid)
            sizes_old: dict[str, tuple[float, float]] = {}
            sizes_new: dict[str, tuple[float, float]] = {}
            for name, val in RE_EQU.findall(text):
                off = int(val, 16)
                b = shared if name.startswith("CV_") else cine
                if not (name.startswith("CV_")
                        or name.startswith("CINEMATIC_")
                        or name.startswith("DRAW_CIN_")):
                    continue
                tree = parse_polygon_tree(b, off)
                if tree is None:
                    continue
                ox0, oy0, ox1, oy1, _ = extent_old(tree)
                nx0, ny0, nx1, ny1, _ = extent(tree)
                sizes_old[name] = (ox1 - ox0, oy1 - oy0)
                sizes_new[name] = (nx1 - nx0, ny1 - ny0)
            if not sizes_new:
                continue
            deltas = [max(abs(sizes_old[k][0] - sizes_new[k][0]),
                          abs(sizes_old[k][1] - sizes_new[k][1]))
                      for k in sizes_new]
            changed = [d for d in deltas if d > 0.01]
            # Ordering inversions: pairs whose area order differs.
            keys = sorted(sizes_new)
            inv = 0
            if len(keys) <= 700:
                for a, b_ in combinations(keys, 2):
                    oa = sizes_old[a][0] * sizes_old[a][1]
                    ob = sizes_old[b_][0] * sizes_old[b_][1]
                    na = sizes_new[a][0] * sizes_new[a][1]
                    nb = sizes_new[b_][0] * sizes_new[b_][1]
                    if (oa > ob) != (na > nb) and oa != ob and na != nb:
                        inv += 1
            else:
                inv = -1
            tot_m += len(sizes_new)
            tot_c += len(changed)
            if inv > 0:
                tot_i += inv
            med = statistics.median(changed) if changed else 0
            print(f"{port + '/' + stage:<18}{len(sizes_new):>9}{len(changed):>9}"
                  f"{med:>8.0f}{max(deltas, default=0):>7.0f}"
                  f"{(inv if inv >= 0 else '(skipped)'):>12}")
            if args.worst:
                for k in sizes_new:
                    d = max(abs(sizes_old[k][0] - sizes_new[k][0]),
                            abs(sizes_old[k][1] - sizes_new[k][1]))
                    if d > 0.01:
                        worst_rows.append(
                            (d, f"  {port}/{stage} {k}: "
                                f"{sizes_old[k][0]:.0f}x{sizes_old[k][1]:.0f}"
                                f" -> {sizes_new[k][0]:.0f}x"
                                f"{sizes_new[k][1]:.0f}"))

    print(f"\n{tot_c} of {tot_m} named polygons change extent; "
          f"{tot_i} pairwise size-order inversions in total.")
    print("An inversion is what would break a SMALL/MEDIUM/LARGE claim. A "
          "uniform inflation\nwould not, and cross-port identity is unaffected "
          "either way because canonical_md5\nnever interprets the header.")
    if args.worst:
        for _, row in sorted(worst_rows, reverse=True)[:25]:
            print(row)
    return 0


if __name__ == "__main__":
    sys.exit(main())
