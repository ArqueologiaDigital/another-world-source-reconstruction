#!/usr/bin/env python3
"""Name the limb pieces a walk or run cycle reuses, by gait phase.

Question answered
-----------------
`hero_pose_consensus.py --subject actor` names the actor's walk and run
*bodies* and holds every LIMB family back, because their index runs have
interior gaps and NAMING.md §2 bars that. The gaps are not missing art: a limb
piece is **shared between frames**, so it has no single frame number and the
frame-indexed scheme cannot describe it. What it has instead is a stable set
of gait phases, and that set is the thing worth naming.

`POSE` rather than `F` is the point: an `F<n>` would claim a frame, and the
whole reason these were stuck is that they are not one frame.

Where the ORDER comes from
--------------------------
Not from the phases. The two directions of one gait are parallel runs in the
bank at a constant offset step, and the committed
`CV_FIGURE_WALK_<DIR>_LIMB_POSE_00..03` family -- numbered by a person from
the phases alone, with no reference to the bank -- runs

    0x247C 0x2474 0x246C 0x2464     POSE_00..03, right
    0x2D6E 0x2D66 0x2D5E 0x2D56     POSE_00..03, left

Index up, offset **down**, both directions. `--control` re-derives every
committed index from the offsets alone: **12 of 12**.

So the order is the bank layout, and the phases are the **check** on it: read
in descending-offset order the first phases must strictly ascend. A family is
the longest stretch where both hold. Where they disagree the stretch ends, and
that boundary is itself evidence -- `CV_2570` sits one step above the
right-hand run and is attested at phase 4, which would put it ahead of phase
0. Its other drawers are `BUDDY_RIGHT_FIRE_AIM_PHASE_1`, which `parse_claim`
cannot read because the direction precedes the motion word, so its RUN claim
is the only visible one and is not the whole story. Cutting there is the
conservative reading.

The mirror sum, which used to be a constant and was wrong
---------------------------------------------------------
`CYCLE = 16` lived at the top of this file and the symmetry test asked whether
each piece's phases contain a pair summing to it. That is the walk cycle. RUN
is a ten-frame sheet, so its mirror sum is **9**, and every RUN piece was
reported "not symmetric about mid-stride" when all of them are. The sum is now
DERIVED: the single S every multi-phase piece in the family has a pair
summing to. For both RUN families exactly one S fits, and it is 9.

    CV_2566  14x9/1   phase  0            -- mirror 9 not attested
    CV_255C  10x7/1   phases 1, 8         -- 1 + 8 = 9
    CV_2552  14x6/1   phases 2, 7, 8      -- 2 + 7 = 9
    CV_2548  15x28/1  phases 3, 5, 6      -- 3 + 6 = 9

Phase 4 is attested for none of them, and that is corroboration rather than a
hole: `../shared-bank-geometry/walk_left_arm_gap.md` records `HERO_RUN_LEFT_ARM`
missing exactly F04 because that frame draws no arm.

A piece with one attested phase is a member of the sheet -- the filter used to
require two phases IN ONE STAGE, which dropped `CV_2566` and `CV_320A`
(attested at phase 0 by three stages each) -- but it carries no weight in S.

Not covered
-----------
**`CV_245C` and `CV_2D4E`, which look exactly like a fifth WALK limb pose and
are not safely one.** They are an exact mirror pair (11x17/1, x spans
reflected about -0.5, identical y), and each sits one 8-byte step below its
family's last member -- 0x245C under `..._WALK_RIGHT_LIMB_POSE_03` at 0x2464,
0x2D4E under the left one at 0x2D56. By the offset rule that is POSE_04 on
both sides.

The phases say otherwise. The committed family, in descending-offset order,
serves first phases 0, 5, 6, 8 -- ascending, which is the check the offset
rule has to pass. `CV_2D4E` is attested at phase **7**, so as POSE_04 it would
follow phase 8, and by phase it belongs between POSE_02 and POSE_03 where the
offsets have no room for it.

That is the same disagreement `mirror_exact.py` resolved for RUN_LEFT, without
the thing that resolved it: there, the right-hand family was already numbered
and each unnamed key was the exact mirror of a *named* one, so the slot came
from the mirror and the offsets merely agreed. Here the two mirror only **each
other**, so there is no named slot to inherit and the offsets are the sole
evidence -- against a phase that contradicts them. Held.

**RUN_LEFT was held here and is now named** by `../shared-bank-geometry/
mirror_exact.py`; the paragraph below is kept because it states what the
mirror had to overcome. Its four pieces mirror the right-hand run exactly:
identical geometry, identical y, x spans reflected about ~0, the same 10-byte
step. But read in bank order its first phases are 0, 8, 2, 3, not ascending --
`CV_3200` is attested at 8 and 9 and never at 1, where its right-hand twin
`CV_255C` is attested at both 1 and 8. The mirror alone would place it, and
one precedent family is too thin to override a phase that contradicts. A named
left-hand drawer at phase 1, or a render, settles it.

Usage
-----
    python3 notes/actor-sprite-sheet/subpiece_poses.py --control
    python3 notes/actor-sprite-sheet/subpiece_poses.py
    python3 notes/actor-sprite-sheet/subpiece_poses.py --proposals
    python3 notes/actor-sprite-sheet/subpiece_poses.py --shared
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

# `CYCLE = 16` used to live here and it was wrong for anything but WALK.
# The symmetric-about-mid-stride test asked whether each piece's phases
# contain a pair summing to 16, and applied that to RUN, whose body sheet is
# ten frames -- so its mirror sum is 9, and every RUN piece was reported as
# "not symmetric" when all of them are. The sum is now DERIVED per family:
# the S for which every piece in the family has a pair summing to S. For the
# two RUN families exactly one S fits, and it is 9.
SUM_RANGE = range(2, 40)


def mirror_sum(phase_sets):
    """The unique S every piece has a pair summing to, or None.

    Returning None when several S fit is deliberate. Two pieces serving two
    phases each admit many sums by coincidence; a family where only one value
    works has said something.
    """
    fits = [S for S in SUM_RANGE
            if all(any(a + b == S for a in fr for b in fr if a < b)
                   for fr in phase_sets)]
    return fits[0] if len(fits) == 1 else None


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
          f"pairs summing to the family mirror sum")
    for cv in sorted(agg, key=lambda c: offs.get(c, 0)):
        rows = sorted(agg[cv])
        mds = {(m, d) for m, d, _ in rows}
        frames = sorted({fr for _m, _d, fr in rows})
        if cv in offs:
            x0, y0, x1, y1, lv = extent(parse_polygon_tree(b, offs[cv]))
            geom = f"{x1 - x0:.0f}x{y1 - y0:.0f}/{lv}"
        else:
            geom = "?"
        S = mirror_sum([frames]) or 0
        pairs = sorted({(a, c) for a in frames for c in frames
                        if a < c and a + c == S})
        md = "/".join(f"{m} {d}" for m, d in sorted(mds))
        print(f"  {cv:<9}{geom:>11}  {md:<12}{str(frames):<26}"
              f"{pairs if pairs else ''}")
    return 0


RE_POSE = re.compile(r"^(CV_FIGURE_[A-Z]+_(?:LEFT|RIGHT)_LIMB_POSE)_(\d+)"
                     r"\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)


def control() -> int:
    """Does the bank-layout rule reproduce the indices a person wrote?

    The committed `CV_FIGURE_WALK_<DIR>_LIMB_POSE_00..03` families were
    numbered by ascending first gait phase, with no reference to where the
    pieces sit in the bank. If numbering them by DESCENDING OFFSET gives the
    same answer, the two orderings agree on a family that was settled
    independently, and the layout can carry the order where a phase is not
    attested. If it does not, the layout reading is wrong and RUN must not
    use it.
    """
    fams: dict[str, list] = collections.defaultdict(list)
    seen: set = set()
    for f in sorted((HERE.parents[2] / "src" / "levels").glob("*/*.asm")):
        for m in RE_POSE.finditer(f.read_text(errors="replace")):
            k = (m.group(1), int(m.group(2)), int(m.group(3), 16))
            if k in seen:
                continue
            seen.add(k)
            fams[m.group(1)].append((int(m.group(2)), int(m.group(3), 16)))
    ok = bad = 0
    for stem, rows in sorted(fams.items()):
        rows.sort()
        by_offset = sorted(rows, key=lambda r: -r[1])
        for want, (got, off) in enumerate(by_offset):
            agree = got == want
            ok += agree
            bad += not agree
            print(f"  {stem}_{got:02d}  0x{off:04X}  "
                  f"layout says {want:02d}  {'AGREE' if agree else '**'}")
    print(f"\n  {ok} index(es) reproduced from the bank layout, {bad} not")
    return 1 if bad else 0


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--control", action="store_true",
                    help="re-derive the index of every committed "
                         "CV_FIGURE_*_LIMB_POSE_<nn> from the bank layout")
    ap.add_argument("--proposals", action="store_true")
    ap.add_argument("--shared", action="store_true",
                    help="report pieces rule 7 hides because several named "
                         "frames reach them")
    args = ap.parse_args()

    if args.control:
        return control()

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
        # Was `max(len(v)) < 2`: a piece needed two phases IN ONE STAGE. That
        # dropped CV_2566 and CV_320A, each attested at phase 0 by three
        # stages, and CV_3200, attested at 8 by two and 9 by a third -- all
        # three sitting in the same contiguous bank run as pieces it kept. A
        # piece with one phase is still a member of the sheet; what it cannot
        # do is carry the family's ORDER on its own, which is why the order
        # now comes from the bank layout and the phases check it.
        if not per:
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

    # A piece with no parseable drawer has no phases of its own and cannot
    # join a family on its own evidence. It can still be placed by its
    # MIRROR: the two directions of one gait are laid out as parallel runs in
    # the bank, same geometry in the same order at the same offset step, and
    # a left/right pair has identical y and an x span reflected about ~0.
    # That is the test ../lake-shooting/ and the teleport beams established,
    # applied to a sheet instead of a single picture. --mirror-control checks
    # it against the WALK family, which a person already numbered.
    everything = {}
    for cv, off in offs.items():
        try:
            everything[cv] = extent(parse_polygon_tree(b, off))
        except Exception:
            pass

    def geom(cv):
        x0, y0, x1, y1, lv = everything[cv]
        return (round(x1 - x0, 1), round(y1 - y0, 1), lv, round(y0, 1),
                round(y1, 1))

    def mirrors(a, c):
        """Same size, same y, and x spans reflected about the same axis."""
        if a not in everything or c not in everything:
            return False
        if geom(a) != geom(c):
            return False
        ax0, _ay0, ax1, _ay1, _al = everything[a]
        cx0, _cy0, cx1, _cy1, _cl = everything[c]
        return abs((ax0 + cx1) - (ax1 + cx0)) < 0.01 and abs(ax0 + cx1) <= 1.0

    def twin_of(cv, other_dir_pieces):
        """The piece in the other direction this one mirrors, if exactly one."""
        hits = [o for o in other_dir_pieces if mirrors(cv, o)]
        return hits[0] if len(hits) == 1 else None

    proposals: list[tuple[str, str]] = []
    print(f"{len(pieces)} shared sub-pieces in {len(fam)} families\n")
    for key in sorted(fam):
        # ORDER COMES FROM THE BANK LAYOUT, not from the phases. The two
        # directions of one gait are parallel runs at a constant offset step,
        # and the committed CV_FIGURE_WALK_*_LIMB_POSE_* family -- which a
        # person numbered from the phases alone -- runs 0x247C, 0x2474,
        # 0x246C, 0x2464 for POSE_00..03 and 0x2D6E..0x2D56 for the mirror:
        # index up, offset DOWN, in both directions. Ordering by first phase
        # gives the same answer wherever both are measurable, and keeps
        # working where a phase is simply not attested in one direction.
        allp = sorted(fam[key], key=lambda p: -offs[p["cv"]])
        # The run is the longest stretch where the two orderings AGREE:
        # constant offset step, and first phases strictly ascending. Where
        # they disagree the stretch ends, and that boundary is evidence --
        # CV_2570 sits one 10-byte step above the right-hand run and is
        # attested at phase 4, which would put it before phase 0. Its other
        # drawers are `BUDDY_RIGHT_FIRE_AIM_PHASE_1`, which `parse_claim`
        # cannot read because the direction precedes the motion word, so its
        # RUN claim is the only one visible and it is not the whole story.
        # Cutting there is the conservative reading.
        best: list = []
        for i in range(len(allp)):
            run = [allp[i]]
            for j in range(i + 1, len(allp)):
                step = offs[run[-1]["cv"]] - offs[allp[j]["cv"]]
                first_step = (offs[run[0]["cv"]] - offs[run[1]["cv"]]
                              if len(run) > 1 else step)
                if step != first_step:
                    break
                if allp[j]["frames"][0] <= run[-1]["frames"][0]:
                    break
                run.append(allp[j])
            if len(run) > len(best):
                best = run
        ps = best
        cut = len(allp) - len(ps)
        o = [offs[x["cv"]] for x in ps]
        steps = {o[i] - o[i + 1] for i in range(len(o) - 1)}
        contiguous = len(steps) == 1 and len(ps) >= 2
        firsts = [x["frames"][0] for x in ps]
        # Where a piece has two or more phases, it must contain a pair
        # summing to one family-wide S. Pieces with a single attested phase
        # are members of the sheet but say nothing about S.
        multi = [x["frames"] for x in ps if len(x["frames"]) >= 2]
        S = mirror_sum(multi) if multi else None
        # The phases must not CONTRADICT the layout order: read in bank
        # order, the first phases should ascend. A piece whose other
        # direction never attests its early frame breaks this once; more
        # than once and the layout reading is wrong.
        ok = contiguous and S is not None and len(ps) >= 3
        print(f"  {'_'.join(key)}: {len(ps)} piece(s)"
              f"{'' if ok else '   HELD'}"
              f"{'' if S is None else f'   mirror sum {S}'}"
              f"{f'   offset step {next(iter(steps))}' if contiguous else ''}"
              f"{f'   ({cut} cut where the orderings disagree)' if cut else ''}")
        for i, x in enumerate(ps):
            name = (f"CV_FIGURE_{key[0]}_{key[1]}_LIMB_POSE_{i:02d}"
                    if ok else "-")
            note = ""
            if len(x["frames"]) >= 2 and S is not None:
                pr = [(a, c) for a in x["frames"] for c in x["frames"]
                      if a < c and a + c == S]
                note = f"  mirror pair {pr[0]}" if pr else ""
            print(f"     {x['cv']:<10}0x{offs[x['cv']]:04X}  "
                  f"{x['geom']:<10} phases {str(x['frames']):<12} "
                  f"{name}{note}")
            if ok:
                proposals.append((x["cv"], name))
        if not ok:
            why = []
            if not contiguous:
                why.append(f"offsets are not one constant step ({sorted(steps)})")
            if S is None:
                why.append("no single mirror sum fits the multi-phase pieces")
            if len(ps) < 3:
                why.append(f"the longest stretch where the bank order and the "
                           f"phase order agree is only {len(ps)} piece(s) "
                           f"(first phases in bank order: "
                           f"{[x['frames'][0] for x in allp]})")
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
