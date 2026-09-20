#!/usr/bin/env python3
"""Name shared-bank art from what independent stages already agree it is.

Question answered
-----------------
`bank_draw_position.py` settled that 191 shared-bank offsets are hero art,
because every call site draws them at `[HERO_X],[HERO_Y]` and that alias means
the same thing in every stage (NAMING.md §3's scoping rule for
`_common_vars.inc`). That fixes the *subject*. It leaves the *pose*.

The pose is already in the tree, several times over. The same bank offset is
drawn by routines in CAPSULE, CAVES and PRISON, on two ports, and those routine
names were earned separately, stage by stage, by people who were not looking at
this bank:

    CV_331A   CAPSULE_HERO_WALK_LEFT_DRAW_14
              CAVES_HERO_WALK_LEFT_STRIDE_PHASE_15
              PRISON_HERO_WALK_LEFT_DRAW_PHASE_14
              DRAW_HERO_WALK_LEFT_F14

Four independent derivations, one claim. That is not an inference from an
index -- which NAMING.md §2 forbids and issue #0107 shows is right "2% of the
time" -- it is agreement between derivations that never consulted each other.
This probe requires that agreement and reports everything it cannot get.

The rules, and why each is there
--------------------------------
1. **Two independent sources minimum**, where independent means a different
   stage prefix. Two names for the same routine, or two ports of one stage, are
   one source: the ports are byte-identical here, so they cannot disagree and
   agreeing proves nothing.

2. **Unanimity, not majority.** One dissenting source drops the offset to the
   report instead of resolving it by vote. #0120: a tool must not pick a winner
   between two semantic names.

3. **Bundle and shadow names are excluded outright.** `DRAW_HERO_STOP_R_BUNDLE_081_082`
   and `DRAW_HERO_SHADOW_BUNDLE_109_110` carry raw index runs, which NAMING.md
   §1 forbids as a name form, and they describe a *draw mechanism* -- one
   routine blitting several unrelated frames -- rather than a pose. Counting
   them as a source would launder the index straight back in.

4. **Footstep-phase numbering is read for motion and direction but never for
   the frame index.** `CAPSULE_HERO_WALK_LEFT_FOOTSTEP_PHASE_2` numbers
   footfalls, not frames; taking its 2 as a frame ordinal would collide with
   the real frame 2.

4b. **The base of an index is measured per source, not assumed from its
   spelling.** `PRISON_HERO_WALK_LEFT_DRAW_PHASE_00` is 0-based and
   `CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_1` is 1-based -- the same
   `_DRAW_PHASE_` suffix, different bases, in the same tree. Hardcoding the
   rule by suffix (which an earlier version did for `_STRIDE_PHASE_` alone)
   makes every 1-based source disagree with every 0-based one by exactly one,
   and the probe then rejects families that are in perfect agreement. It also
   produced a family reporting index 3 twice and indices running to 16.

   The base is found by **calibrating each stage against a reference stage**: over the offsets both name, take the set of
   differences. A single constant difference means one is offset from the
   other by that much, and it is applied. More than one value is a real
   disagreement and is left alone so the unanimity rule rejects it.

   **Every iteration here is over a sorted sequence, and that is load-bearing.**
   An earlier version walked the offset set directly. Python randomises string
   set order per process, so the order stages entered the calibration varied
   between runs, the tie-break for the reference stage varied with it, and the
   probe returned 22, 21 and 22 proposals on three consecutive runs of the
   same command. A naming probe that is not reproducible cannot be evidence
   for anything.

   Calibrating pairwise rather than per stage matters. A first version asked
   whether one stage's indices were contiguous and started at 1 -- but CAVES
   claims only the odd frames of the actor walk, `{1, 3, 5, 7}`, because the
   even ones are named `_PHASE_n` with no parseable ordinal. Not contiguous,
   so the test never fired and every CAVES claim disagreed with CAPSULE and
   PRISON by exactly one, rejecting a family all three stages agree about.

5. **Role comes from measured geometry, not from the routine, and it belongs
   in the name.** A routine draws
   a body polygon *and* a limb polygon and its name describes the whole pose,
   so transferring that name to both would put one name on two pictures
   (#0118). The split is made from the ROM: within the offsets a routine draws,
   the largest by area is the body and a single-leaf one an order of magnitude
   smaller is the limb. Rendered, the small series is unmistakably a bent arm,
   and the independently-earned `HERO_GUN_ARM_POSE_CASE_02` draws one of the
   forked, gun-holding variants -- which is the cross-check that the geometric
   split found the right thing.

6. **The consensus index is checked against offset order**, not trusted. A
   sprite sheet stores frames consecutively, so within one (motion, direction,
   role) family the consensus indices should be offset order up to a rotation.
   The probe reports the concordance and refuses a family where it is not.

7. **A draw is credited to the routine whose control flow reaches it**, via
   `notes/routine-extent/named_routine_draws.py`, not to the nearest preceding
   label. The first run of this probe used nearest-label and rejected `CV_0358`
   for having one source when it has three: `PRISON_HERO_STAND_LEFT_DRAW`
   draws it from a block behind a conditional, which the nearest-label rule
   files under `LABEL_6DC2`. That bias only ever *loses* sources, so the
   offsets it accepted stayed sound -- but its rejections did not.

8. **A routine is a source only if it draws at most two distinct shared-bank
   pictures.** Following control flow (rule 7) reaches further, and that
   immediately created a failure the nearest-label rule could not have:
   `PRISON_HERO_STAND_LEFT_TICK` is a per-frame dispatcher that reaches eight
   walk-left frames, so it began "asserting" STAND about every one of them and
   turned six settled offsets into disagreements.

   The bound is read off the data rather than picked. Distinct shared-bank
   pictures per named routine:

       1 picture   182 routines      2 pictures  100      (85.7 % cumulative)
       3            4                4             3
       5           12                6             5
       7            1 (the TICK)     8+           22

   The distribution is bimodal, and the low mode is exactly what a frame is:
   a body and an arm, drawn together, which `bank_draw_position.py` and the
   co-draw check established independently. A routine reaching more than that
   is a dispatcher or a multi-pose loop and is not asserting a pose about any
   single picture in it.

   The count is over pictures **drawn at the hero's position**, not over
   `CV_*` symbols. Counting the keys would make the bound decay as the bank
   gets named: after the first 52 names landed, the TICK's key count fell from
   seven to two and it came back as a source for the very frames it had just
   been excluded from. A draw position cannot be renamed.

   It is also taken as the **maximum over every port**, not per file. The same
   `PRISON_HERO_STAND_LEFT_TICK` reaches 7 hero pictures in msdos/PRISON and
   only 2 in amiga/PRISON, because the two ports lay the blocks out
   differently and the amiga walk stops sooner. Judged per file it was
   excluded on one port and admitted on the other, which let it go on
   asserting STAND about walk frames. A name that dispatches anywhere is a
   dispatcher.

The actor slot: `--subject actor`
---------------------------------
The other 148 offsets are drawn at the shared actor record. #0138 bars saying
**which character** they are, not what pose they are in -- the existing
`CV_FIGURE_CROUCH_FACING_LEFT` names are that distinction already applied. So
the same consensus runs there, with one difference: the *subject* words in the
drawer names are discarded and the name asserts none.

That is not a precaution, it is what the evidence says. One eight-frame run is
called `CAPSULE_BUDDY_WALK_RIGHT_DRAW_0`, `CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_1`
and `CAVES_HERO_WALK_RIGHT_PHASE_2` by three different stages -- buddy, actor
and hero, for one picture. The stages disagree about the character and agree
about the motion, the direction and the frame number, which is exactly the
shape #0138 describes. Names go on what they agree about:
`CV_FIGURE_WALK_RIGHT_F00`, carrying the bank's `CV_FIGURE_` prefix that marks
"a figure whose character is not claimed".

Usage
-----
    python3 notes/shared-bank-geometry/hero_pose_consensus.py
    python3 notes/shared-bank-geometry/hero_pose_consensus.py --subject actor
    python3 notes/shared-bank-geometry/hero_pose_consensus.py --families
    python3 notes/shared-bank-geometry/hero_pose_consensus.py --rejected
    python3 notes/shared-bank-geometry/hero_pose_consensus.py --proposals
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
ARCH = SRC.parent / "another-world-archaeology"
sys.path.insert(0, str(ARCH / "tools"))
sys.path.insert(0, str(HERE.parents[1]))
from polygon_tree import parse_polygon_tree            # noqa: E402
from polygon_extent import extent                      # noqa: E402
from naming_census import classify                     # noqa: E402
from actor_slot import actor_slot_names                # noqa: E402
sys.path.insert(0, str(HERE.parents[1] / "routine-extent"))
from named_routine_draws import routine_draws          # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES",
          "TANK", "CAPSULE", "ENDING", "PASSCODE"]
RE_LABEL = re.compile(r"^([A-Za-z_]\w*):")
RE_EQU = re.compile(r"^(CV_[0-9A-F]{4})\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)
RE_DRAW = re.compile(r"offset=(\w+),\s*x=(\[?\w+\]?),\s*y=(\[?\w+\]?)")
RE_KEY = re.compile(r"^CV_[0-9A-F]{4}$")

# Rule 3: these describe a draw mechanism and carry raw index runs.
EXCLUDE = re.compile(r"_BUNDLE_|_SHADOW_|_2NDSCR_")
# Rule 4: a footfall counter, not a frame ordinal.
RE_FOOTSTEP = re.compile(r"_FOOTSTEP_PHASE_\d+$")
# Frame-ordinal spellings actually present in the tree.
# A bare `_PHASE_<n>` looks like a frame ordinal -- CAPSULE_BUDDY_WALK_RIGHT_
# PHASE_1 does sit between the offsets numbered 0 and 2 -- and admitting it
# was tried and reverted. It made the actor tables worse, not better: the
# walk-right family disappeared entirely and walk-left grew an index 16 in a
# 0..15 run, because `_PHASE_<n>` is used with a third base convention again
# and the pairwise calibration has too few shared offsets to pin it. Left out
# until that is measured rather than guessed.
RE_INDEX = re.compile(r"_(?:DRAW|F|POSE|DRAW_PHASE|STRIDE_PHASE)_?(\d+)$")
RE_MOTION = re.compile(r"_(?:HERO|BUDDY|ACTOR|ALIEN|BEAST)_"
                       r"(WALK|RUN|CRAWL|JUMP|STAND|PRONE|CROUCH|SHOOT|FALL)_"
                       r"(LEFT|RIGHT)_")
# Rule 8; see the module docstring for how this number was chosen.
MAX_PICTURES_PER_SOURCE = 2
# Set by --subject before collect() runs. A list so it is mutable at module
# scope without a global statement in every function that reads it.
SUBJECT = ["hero"]


def bank() -> bytes:
    p = ARCH / "tmp" / "output" / "amiga" / "resources" / "resource-0x11.bin"
    if not p.is_file():
        raise SystemExit(f"missing {p}; run tools/aw_unpacker.py in the "
                         f"archaeology repo")
    return p.read_bytes()


def collect():
    """offset table, hero-art set, and {offset: {stage: {routine names}}}."""
    offs: dict[str, int] = {}
    pos: dict[str, set] = collections.defaultdict(set)
    by_stage: dict[str, dict[str, set]] = collections.defaultdict(
        lambda: collections.defaultdict(set))
    drawn_by: dict[tuple, dict] = {}
    for port, br in PORTS.items():
        for stage in STAGES:
            p = SRC / "src" / "levels" / br / f"{stage}.asm"
            if not p.is_file():
                continue
            text = p.read_text(errors="replace")
            xs, ys = actor_slot_names(text)
            for n, v in RE_EQU.findall(text):
                offs[n] = int(v, 16)
            for cv, x, y in RE_DRAW.findall(text):
                bx, by = x.strip("[]"), y.strip("[]")
                if bx in xs and by in ys:
                    pos[cv].add("ACTOR")
                elif not x.startswith("["):
                    pos[cv].add("lit")
                else:
                    pos[cv].add(f"{bx},{by}")
            drawn_by[(port, stage)] = routine_draws(text)
    slot = {"HERO_X,HERO_Y"} if SUBJECT[0] == "hero" else {"ACTOR"}
    hero_art = {c for c, p in pos.items() if p == slot}
    widest: dict[str, int] = collections.Counter()
    for rds in drawn_by.values():
        for routine, art in rds.items():
            n = len({a for a in art if a in hero_art})
            widest[routine] = max(widest[routine], n)
    for (_port, stage), rds in drawn_by.items():
        # Rules 7 and 8: attribution follows control flow, and a routine
        # reaching more than one frame's worth of hero art is a dispatcher
        # rather than a source. Counting hero-positioned pictures rather than
        # CV_ keys keeps the bound from decaying as the bank gets named.
        for routine, art in rds.items():
            seen = {a for a in art if a in hero_art}
            if widest[routine] > MAX_PICTURES_PER_SOURCE:
                continue
            for cv in seen:
                if RE_KEY.match(cv):
                    by_stage[cv][stage].add(routine)
    want = {"HERO_X,HERO_Y"} if SUBJECT[0] == "hero" else {"ACTOR"}
    hero = {c for c in pos if pos[c] == want and RE_KEY.match(c)}
    return offs, hero, by_stage


def parse_claim(name: str):
    """(motion, direction, index|None) a routine name asserts, or None."""
    if EXCLUDE.search(name):
        return None
    if classify(name) != "semantic":
        return None
    m = RE_MOTION.search("_" + name + "_")
    if not m:
        return None
    motion, direction = m.group(1), m.group(2)
    idx = None
    if not RE_FOOTSTEP.search(name):
        mi = RE_INDEX.search(name)
        if mi:
            idx = int(mi.group(1))
    return motion, direction, idx


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--families", action="store_true")
    ap.add_argument("--rejected", action="store_true")
    ap.add_argument("--proposals", action="store_true")
    ap.add_argument("--subject", default="hero", choices=["hero", "actor"])
    args = ap.parse_args()
    SUBJECT[0] = args.subject

    offs, hero, by_stage = collect()
    b = bank()

    # Rule 4b: calibrate each stage's index base against the stage with the
    # most claims in the same (motion, direction).
    raw: dict[tuple, dict] = collections.defaultdict(dict)
    for cv in sorted(hero, key=lambda c: offs[c]):
        for stage, routines in by_stage[cv].items():
            for r in sorted(routines):
                c = parse_claim(r)
                if c and c[2] is not None:
                    raw[(stage, c[0], c[1])][cv] = c[2]
    fams: dict[tuple, list] = collections.defaultdict(list)
    for (stage, m, d) in sorted(raw):
        fams[(m, d)].append(stage)
    shift: dict[tuple, int] = {}
    for (m, d), stages in fams.items():
        # The reference must be a 0-based stage, not merely a well-attested
        # one. CAPSULE, CAVES and PRISON each claim 16 frames of the actor
        # walk, so picking by claim count is a coin toss -- and landing on
        # CAVES (1-based) shifted the other two UP to 1-based while PRISON,
        # whose calibration fails on two genuine outliers, stayed at 0. The
        # family then looked like a disagreement between 0 and 1 when all
        # three agree. A family starts at frame 0, so anchor on the stage
        # with the lowest minimum index, breaking ties by claim count.
        ref = min(stages, key=lambda s: (min(raw[(s, m, d)].values()),
                                         -len(raw[(s, m, d)])))
        shift[(ref, m, d)] = 0
        for s in sorted(stages):
            if s == ref:
                continue
            both = set(raw[(s, m, d)]) & set(raw[(ref, m, d)])
            diffs = {raw[(s, m, d)][cv] - raw[(ref, m, d)][cv] for cv in both}
            shift[(s, m, d)] = diffs.pop() if len(diffs) == 1 else 0

    def claims_for(cv):
        out: dict[str, set] = {}
        for stage, routines in sorted(by_stage[cv].items()):
            got = set()
            for r in sorted(routines):
                c = parse_claim(r)
                if not c:
                    continue
                m, d, i = c
                if i is not None:
                    i -= shift.get((stage, m, d), 0)
                got.add((m, d, i))
            if got:
                out[stage] = got
        return out

    agreed: dict[str, tuple] = {}
    rejected: dict[str, str] = {}
    for cv in sorted(hero, key=lambda c: offs[c]):
        claims = claims_for(cv)
        if len(claims) < 2:
            rejected[cv] = (f"only {len(claims)} independent source"
                            f"{'' if len(claims) == 1 else 's'}")
            continue
        md = {(m, d) for s in claims.values() for (m, d, _i) in s}
        if len(md) != 1:
            rejected[cv] = ("sources disagree: "
                            + ", ".join(sorted(f"{m}_{d}" for m, d in md)))
            continue
        motion, direction = md.pop()
        idxs = {i for s in claims.values() for (_m, _d, i) in s if i is not None}
        if len(idxs) > 1:
            rejected[cv] = ("sources agree on " + f"{motion}_{direction}"
                            + " but disagree on the index: "
                            + ",".join(str(i) for i in sorted(idxs)))
            continue
        idx = idxs.pop() if idxs else None
        agreed[cv] = (motion, direction, idx, len(claims))

    # Rule 5: role from measured geometry, per routine.
    area: dict[str, float] = {}
    leaves: dict[str, int] = {}
    for cv in sorted(hero):
        t = parse_polygon_tree(b, offs[cv])
        if t is None:
            continue
        x0, y0, x1, y1, lv = extent(t)
        area[cv] = (x1 - x0) * (y1 - y0)
        leaves[cv] = lv
    role: dict[str, str] = {}
    for cv in sorted(agreed):
        a, lv = area.get(cv, 0), leaves.get(cv, 0)
        role[cv] = "BODY" if (lv >= 4 and a >= 400) else "LIMB"

    print(f"{len(hero)} hero-art offsets; {len(agreed)} have two or more "
          f"independent stages agreeing\non motion and direction, "
          f"{len(rejected)} do not.\n")
    by_n = collections.Counter(v[3] for v in agreed.values())
    for n in sorted(by_n):
        print(f"  {by_n[n]:4d}  agreed by {n} independent stages")
    print()
    by_role = collections.Counter(
        (v[0], v[1], role[k]) for k, v in agreed.items())
    print(f"{'motion':<9}{'dir':<7}{'role':<6}{'count':>6}   "
          f"{'with an index':>14}")
    for (m, d, r), n in sorted(by_role.items()):
        wi = sum(1 for k, v in agreed.items()
                 if (v[0], v[1]) == (m, d) and role[k] == r
                 and v[2] is not None)
        print(f"{m:<9}{d:<7}{r:<6}{n:>6}{wi:>15}")

    if args.families:
        print("\nindex concordance: consensus index vs offset order, per "
              "family\n(a sprite sheet stores frames consecutively, so these "
              "should match up to a rotation)")
        fams: dict[tuple, list] = collections.defaultdict(list)
        for k, v in agreed.items():
            if v[2] is not None:
                fams[(v[0], v[1], role[k])].append((offs[k], v[2], k))
        for key in sorted(fams):
            rows = sorted(fams[key])
            order = [i for _o, i, _k in rows]
            n = len(order)
            rot = [r for r in range(n)
                   if all((order[j] - order[0]) % max(max(order) + 1, 1)
                          == (j) for j in range(n))]
            contiguous = sorted(order) == list(range(min(order),
                                                     min(order) + n))
            print(f"  {'_'.join(key):<26} {n:2d} frames  indices "
                  f"{','.join(str(i) for i in order)}"
                  f"{'  [contiguous]' if contiguous else '  [GAPS]'}")

    if args.rejected:
        print(f"\n{len(rejected)} not agreed:")
        for cv, why in sorted(rejected.items(), key=lambda kv: offs[kv[0]]):
            print(f"  {cv}  {why}")

    if args.proposals:
        print("\nproposals (offset -> name), role from measured geometry:")
        for cv, (m, d, i, _n) in sorted(agreed.items(),
                                        key=lambda kv: offs[kv[0]]):
            if i is None:
                continue
            if args.subject == "actor":
                # No character is claimed: see the docstring and #0138. The
                # role word is not optional -- without it the body and the
                # limb of one frame derive the same name, which is how
                # CV_2FD6 (41x56, five leaves) and CV_3212 (14x24, one leaf)
                # both came out as CV_FIGURE_RUN_LEFT_F04.
                print(f"{cv} CV_FIGURE_{m}_{d}_{role[cv]}_F{i:02d}")
            else:
                print(f"{cv} HERO_{m}_{d}_{role[cv]}_F{i:02d}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
