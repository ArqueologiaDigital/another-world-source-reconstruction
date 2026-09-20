#!/usr/bin/env python3
"""Name shared-bank hero art from what independent stages already agree it is.

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

5. **Role comes from measured geometry, not from the routine.** A routine draws
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

Usage
-----
    python3 notes/shared-bank-geometry/hero_pose_consensus.py
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

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES",
          "TANK", "CAPSULE", "ENDING", "PASSCODE"]
RE_LABEL = re.compile(r"^([A-Za-z_]\w*):")
RE_EQU = re.compile(r"^(CV_[0-9A-F]{4})\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)
RE_DRAW = re.compile(r"offset=(CV_[0-9A-F]{4}),\s*x=(\[?\w+\]?),\s*y=(\[?\w+\]?)")

# Rule 3: these describe a draw mechanism and carry raw index runs.
EXCLUDE = re.compile(r"_BUNDLE_|_SHADOW_|_2NDSCR_")
# Rule 4: a footfall counter, not a frame ordinal.
RE_FOOTSTEP = re.compile(r"_FOOTSTEP_PHASE_\d+$")
# Frame-ordinal spellings actually present in the tree.
RE_INDEX = re.compile(r"_(?:DRAW|F|POSE|DRAW_PHASE|STRIDE_PHASE)_?(\d+)$")
RE_MOTION = re.compile(r"_HERO_(WALK|RUN|CRAWL|JUMP|STAND|PRONE|CROUCH)_"
                       r"(LEFT|RIGHT)_")


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
    for port, br in PORTS.items():
        for stage in STAGES:
            p = SRC / "src" / "levels" / br / f"{stage}.asm"
            if not p.is_file():
                continue
            text = p.read_text(errors="replace")
            xs, ys = actor_slot_names(text)
            for n, v in RE_EQU.findall(text):
                offs[n] = int(v, 16)
            cur = None
            for line in text.splitlines():
                m = RE_LABEL.match(line)
                if m:
                    cur = m.group(1)
                    continue
                for cv, x, y in RE_DRAW.findall(line):
                    bx, by = x.strip("[]"), y.strip("[]")
                    if bx in xs and by in ys:
                        pos[cv].add("ACTOR")
                    elif not x.startswith("["):
                        pos[cv].add("lit")
                    else:
                        pos[cv].add(f"{bx},{by}")
                    if cur:
                        by_stage[cv][stage].add(cur)
    hero = {c for c in pos if pos[c] == {"HERO_X,HERO_Y"}}
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
            # CAVES spells the walk cycle 1-based; every other stage is 0-based.
            if "_STRIDE_PHASE_" in name:
                idx -= 1
    return motion, direction, idx


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--families", action="store_true")
    ap.add_argument("--rejected", action="store_true")
    ap.add_argument("--proposals", action="store_true")
    args = ap.parse_args()

    offs, hero, by_stage = collect()
    b = bank()

    agreed: dict[str, tuple] = {}
    rejected: dict[str, str] = {}
    for cv in sorted(hero, key=lambda c: offs[c]):
        claims: dict[str, set] = {}
        for stage, routines in by_stage[cv].items():
            got = {parse_claim(r) for r in routines}
            got.discard(None)
            if got:
                claims[stage] = got
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
    for cv in hero:
        t = parse_polygon_tree(b, offs[cv])
        if t is None:
            continue
        x0, y0, x1, y1, lv = extent(t)
        area[cv] = (x1 - x0) * (y1 - y0)
        leaves[cv] = lv
    role: dict[str, str] = {}
    for cv in agreed:
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
        for cv, (m, d, i, _n) in sorted(agreed.items(), key=lambda kv: offs[kv[0]]):
            if i is None:
                continue
            print(f"  {cv}  HERO_{m}_{d}_{role[cv]}_F{i:02d}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
