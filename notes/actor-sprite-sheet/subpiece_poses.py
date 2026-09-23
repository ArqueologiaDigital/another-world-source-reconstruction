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
import re
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


RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
RE_CALL = re.compile(r"^\s*call\s+([A-Za-z_][A-Za-z0-9_]*)")
RE_T0 = re.compile(r"video type=0, offset=(CV_[0-9A-F]{4})")
RE_RET = re.compile(r"^[A-Za-z_]*_(WALK|RUN)_(RIGHT|LEFT)_DRAW_(\d+)_RET:")


def shared_pieces(stage_text: str, stage: str):
    """{piece: {(motion, direction, frame)}} for pieces reached by a `call`.

    `hero_pose_consensus.collect()` attributes a picture to a routine only
    when exactly ONE named routine reaches it (rule 7). That is right for a
    frame claim and it makes shared sub-pieces invisible: 69 of the 100
    actor-slot offsets have no routine attributed at all, because a piece
    used by frames 2 and 14 has no unique reacher.

    Being shared is exactly what makes a piece poseable rather than
    frame-indexable, so the information rule 7 discards -- the SET of frames
    a piece serves -- is the information this module needs. It is recoverable
    without weakening rule 7, because the frame routines name themselves on
    the label they return to:

        LABEL_6D5E:
            call LABEL_6C74                      <- draws the shared piece
        CAPSULE_BUDDY_WALK_RIGHT_DRAW_0_RET:     <- says which frame that was

    So: for each `call` to a routine whose first type=0 draw is a CV_ piece,
    look ahead a few lines for a `..._DRAW_<n>_RET:` label and credit the
    piece with that frame. The frame number is the machine's, not the
    disassembler's, which is the same argument `../gun-arm-dispatch/` makes
    for reading a switch case.
    """
    lines = stage_text.splitlines()
    first: dict[str, str] = {}
    cur = None
    for line in lines:
        m = RE_LBL.match(line)
        if m:
            cur = m.group(1)
            continue
        d = RE_T0.search(line)
        if d and cur and cur not in first:
            first[cur] = d.group(1)

    out: dict[str, set] = collections.defaultdict(set)
    for i, line in enumerate(lines):
        c = RE_CALL.match(line)
        if not c or c.group(1) not in first:
            continue
        for j in range(i + 1, min(i + 8, len(lines))):
            m = RE_RET.match(lines[j])
            if m:
                frame = int(m.group(3)) - BASE.get(stage, 0)
                out[first[c.group(1)]].add((m.group(1), m.group(2), frame))
                break
    return out


def report_shared() -> int:
    PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
    SRC = HERE.parents[2] / "src" / "levels"
    agg: dict[str, set] = collections.defaultdict(set)
    for port, br in PORTS.items():
        for stage in BASE:
            f = SRC / br / f"{stage}.asm"
            if not f.is_file():
                continue
            for cv, fr in shared_pieces(f.read_text(errors="replace"),
                                        stage).items():
                agg[cv] |= fr
    if not agg:
        print("no call-reached shared pieces found")
        return 0

    b = H.bank()
    H.SUBJECT[0] = "actor"
    offs, _art, _by = H.collect()
    print(f"{len(agg)} piece(s) reached by a `call` from a named frame, with "
          f"the frames each serves.\nBase applied per stage "
          f"({', '.join(f'{k} {v}' for k, v in BASE.items())}).\n")
    print(f"  {'piece':<9}{'geom':>11}  {'motion dir':<12}{'frames':<26}"
          f"pairs summing to {CYCLE}")
    for cv in sorted(agg, key=lambda c: offs.get(c, 0)):
        rows = sorted(agg[cv])
        mds = {(m, d) for m, d, _ in rows}
        frames = sorted({fr for _m, _d, fr in rows})
        if cv in offs:
            x0, y0, x1, y1, lv = extent(parse_polygon_tree(b, offs[cv]))
            geom = f"{x1 - x0:.0f}x{y1 - y0:.0f}/{lv}"
        else:
            geom = "?"
        pairs = sorted({(a, c) for a in frames for c in frames
                        if a < c and a + c == CYCLE})
        md = "/".join(f"{m} {d}" for m, d in sorted(mds))
        print(f"  {cv:<9}{geom:>11}  {md:<12}{str(frames):<26}"
              f"{pairs if pairs else ''}")
    return 0


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--proposals", action="store_true")
    ap.add_argument("--shared", action="store_true",
                    help="report pieces rule 7 hides because several named "
                         "frames reach them")
    args = ap.parse_args()

    if args.shared:
        return report_shared()

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
