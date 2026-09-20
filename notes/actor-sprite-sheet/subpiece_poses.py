#!/usr/bin/env python3
"""Name the limb pieces a walk cycle reuses, by gait phase instead of by frame.

Question answered
-----------------
`hero_pose_consensus.py --subject actor` names the actor's walk and run
*bodies* and holds every LIMB family back, because their index runs have
interior gaps and NAMING.md §2 bars that. The gaps are not missing art: a limb
piece is **shared between frames**, so it has no single frame number and the
frame-indexed scheme cannot describe it.

What it has instead is a stable set of gait phases, and that set is the thing
worth naming. Per piece, the frames its drawers assign it:

    CV_247C  3x13/1   frames {0, 1}        CV_2D6E  3x13/1   frames {0, 1}
    CV_2474  9x19/1   frames {5, 11}       CV_2D66  9x19/1   frames {5, 11}
    CV_246C  11x17/1  frames {6, 10}       CV_2D5E  11x17/1  frames {6, 10}
    CV_2464  11x17/1  frames {8, 9}        CV_2D56  11x17/1  frames {8, 9}
    (walk-right)                           (walk-left)

The pairs are not arbitrary. In a 16-frame cycle `5 + 11 = 6 + 10 = 16`: those
are the two moments symmetric about mid-stride, when the limb is in the same
place. `{0,1}` and `{8,9}` are the two mid-stance moments of a two-step cycle.
And the two directions use the **same four shapes at the same four phase
pairs**, which is a second, independent reason to believe the grouping is
real rather than an artefact of how the names were earned.

Rendered, the four are bent single-leaf limbs, straight at `{0,1}` and
progressively more bent — the same shape family as the hero's arm series. They
are named `LIMB` and not `ARM` on purpose: the hero's series was confirmed as
an arm by `HERO_GUN_ARM_POSE_CASE_02` drawing one of its gun-holding
variants, and no such confirmation exists here. Similar shape on a different
figure is a resemblance, not evidence.

The naming
----------
`CV_FIGURE_WALK_<DIR>_LIMB_POSE_<nn>`, numbered by **ascending first gait
phase** — POSE_00 is the piece used at frames {0,1}, POSE_01 at {5,11},
POSE_02 at {6,10}, POSE_03 at {8,9}. Four per direction, a complete run 0..3
with no gap.

`POSE` rather than `F` is the point: an `F<n>` would claim a frame, and the
whole reason these were stuck is that they are not one frame. The ordinal
orders the poses, and the docstring and README record which phases each
serves.

Not covered
-----------
The RUN sub-pieces. `CV_2548` serves frames {3,5,6}, `CV_2552` {2,7,8} and
`CV_255C` {1,8} — three pieces with an overlapping phase and no coverage of a
nine-frame cycle. Neither symmetric nor complete, so nothing is proposed.

Usage
-----
    python3 notes/actor-sprite-sheet/subpiece_poses.py
    python3 notes/actor-sprite-sheet/subpiece_poses.py --proposals
"""

from __future__ import annotations

import argparse
import collections
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
sys.path.insert(0, str(HERE.parents[1] / "shared-bank-geometry"))
sys.path.insert(0, str(HERE.parents[2].parent / "another-world-archaeology"
                       / "tools"))
import hero_pose_consensus as H                      # noqa: E402
from polygon_tree import parse_polygon_tree          # noqa: E402
from polygon_extent import extent                    # noqa: E402

# Measured per stage by ../shared-bank-geometry/phase_base_calibration.py.
BASE = {"CAPSULE": 0, "PRISON": 0, "CAVES": 1}
CYCLE = 16


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--proposals", action="store_true")
    args = ap.parse_args()

    H.SUBJECT[0] = "actor"
    offs, art, by_stage = H.collect()
    b = H.bank()

    pieces = []
    for cv in sorted(art, key=lambda c: offs[c]):
        per: dict[str, set] = collections.defaultdict(set)
        md: set = set()
        for stage, routines in sorted(by_stage[cv].items()):
            for r in sorted(routines):
                c = H.parse_claim(r)
                if not c or c[2] is None:
                    continue
                md.add((c[0], c[1]))
                per[stage].add(c[2] - BASE.get(stage, 0))
        if not per or max(len(v) for v in per.values()) < 2:
            continue
        if len(md) != 1:
            continue
        motion, direction = md.pop()
        frames = sorted(set().union(*per.values()))
        tree = parse_polygon_tree(b, offs[cv])
        x0, y0, x1, y1, lv = extent(tree)
        pieces.append({"cv": cv, "motion": motion, "dir": direction,
                       "frames": frames, "lv": lv,
                       "geom": f"{x1 - x0:.0f}x{y1 - y0:.0f}/{lv}"})

    fam: dict[tuple, list] = collections.defaultdict(list)
    for p in pieces:
        fam[(p["motion"], p["dir"])].append(p)

    proposals: list[tuple[str, str]] = []
    print(f"{len(pieces)} shared sub-pieces in {len(fam)} families\n")
    for key in sorted(fam):
        ps = sorted(fam[key], key=lambda p: p["frames"][0])
        served = [f for p in ps for f in p["frames"]]
        dup = len(served) != len(set(served))
        pairs = all(len(p["frames"]) == 2 for p in ps)
        symmetric = all(sum(p["frames"]) in (CYCLE, p["frames"][0] * 2 + 1)
                        for p in ps)
        ok = key[0] == "WALK" and pairs and symmetric and not dup
        print(f"  {'_'.join(key)}: {len(ps)} piece(s)"
              f"{'' if ok else '   HELD'}")
        for i, p in enumerate(ps):
            name = (f"CV_FIGURE_{key[0]}_{key[1]}_LIMB_POSE_{i:02d}"
                    if ok else "-")
            print(f"     {p['cv']:<10}{p['geom']:<10} phases "
                  f"{str(p['frames']):<12} {name}")
            if ok:
                proposals.append((p["cv"], name))
        if not ok:
            why = []
            if key[0] != "WALK":
                why.append("not a walk cycle")
            if not pairs:
                why.append("a piece serves other than two phases")
            if dup:
                why.append("two pieces share a phase")
            if not symmetric:
                why.append("phases are not symmetric about mid-stride")
            print(f"     held: {'; '.join(why)}")
        print()

    if args.proposals:
        for cv, name in proposals:
            print(f"{cv} {name}")
    else:
        print(f"{len(proposals)} nameable; run with --proposals for the map.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
