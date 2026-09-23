#!/usr/bin/env python3
"""How much of the routine layer is waiting on the shared bank?

Question answered
-----------------
The shared bank is one file -- resource 0x11, identical on both priority
ports -- so naming one key names the art everywhere. That makes the remaining
`CV_<OFFSET4>` keys the highest-leverage item in the backlog, and this
measures the leverage instead of guessing at it: **how many drawing labels
would become nameable if a given key were identified?**

A label like `CAVES_DRAW_CV_355_L2` or `CAPSULE_DRAW_CV263_AT_X07_Y08_L7`
carries the key's raw index in its own name, which `docs/NAMING.md` §1
forbids. It cannot be fixed until the key it draws has a name, at which point
`../draw-label-follows-constant/` renames it mechanically. So the count below
is a real dependency, not a coincidence of spelling.

Measured 2026-09-23, after the four `CV_FIGURE_RUN_RIGHT_LIMB_POSE_*` names:

    53 still-numbered keys drawn in the priority ports
    302 distinct drawing labels wait on them

which was 57 and 378 before those four. One key is worth about seven labels.

The control
-----------
`--claims` checks the evidence this module's neighbours run on. A key whose
drawers unanimously name one (motion, direction) should, if it is already
named, carry that motion and that direction in its own name. Over the named
keys: **152 agree, 6 do not**.

None of the 6 is a contradiction, and each is a different kind of non-
contradiction, which is why they are printed rather than counted:

    HERO_CRAWL_POSE_00, _02, _10        the name carries no direction at all
    HERO_PRONE_TRANSITION_LEFT_F03, _F05  drawn by crawl routines -- the same
                                          movement in other words
    HERO_WATER_DEPTH_LEFT_CASE_00       drawn by a walk routine -- wading

A seventh and eighth appeared briefly and were **my own doing**: a change to
`hero_pose_consensus.motion_of` that read a motion word following the
direction made `CV_FIGURE_CROUCH_FACING_LEFT` look as though its drawers all
said RIGHT. The art says otherwise and the change is reverted; see
`hero_pose_consensus.py --token-order`.

That ratio is why the drawers are usable as evidence at all, and the six
exceptions are why they are used with a unanimity requirement rather than a
majority one.

Usage
-----
    python3 notes/shared-bank-geometry/blocked_by_bank.py
    python3 notes/shared-bank-geometry/blocked_by_bank.py --claims
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(Path(__file__).resolve().parent))
import hero_pose_consensus as H                              # noqa: E402

PORTS = ("chahi_amiga_1991", "dos_1992")
RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
RE_V = re.compile(r"^\s*video\s+type=0,\s*offset=([A-Za-z_][A-Za-z0-9_]*)")
RE_NUM = re.compile(r"^CV_[0-9A-F]{4}$")


def drawers():
    """{shared-bank key: {label that draws it}} over the priority ports."""
    out: dict[str, set] = collections.defaultdict(set)
    for br in PORTS:
        for f in sorted((SRC / "src" / "levels" / br).glob("*.asm")):
            cur = None
            for line in f.read_text(errors="replace").splitlines():
                m = RE_LBL.match(line)
                if m:
                    cur = m.group(1)
                    continue
                v = RE_V.match(line)
                if v and cur:
                    out[v.group(1)].add(cur)
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--claims", action="store_true",
                    help="do a named key's drawers agree with its own name?")
    args = ap.parse_args()
    by = drawers()

    if args.claims:
        ok = bad = 0
        for key in sorted(by):
            if RE_NUM.match(key):
                continue
            cs = {H.parse_claim(l) for l in by[key]}
            cs = {(c[0], c[1]) for c in cs if c}
            if len(cs) != 1:
                continue
            motion, direction = next(iter(cs))
            # SHOOT is the normal form of FIRE, SHOT and AIM (see
            # hero_pose_consensus.SYNONYM), so a key spelled with any of
            # those satisfies a SHOOT claim.
            spelled = motion in key or (motion == "SHOOT" and any(
                w in key for w in ("SHOOT", "FIRE", "SHOT", "AIM")))
            agree = direction in key and spelled
            ok += agree
            bad += not agree
            if not agree:
                print(f"  {key:<44}drawers say {motion} {direction}")
        print(f"\n  {ok} named key(s) agree with their drawers' unanimous "
              f"claim, {bad} do not")
        return 0

    numbered = {k: v for k, v in by.items() if RE_NUM.match(k)}
    labels = {l for v in numbered.values() for l in v}
    print(f"  {len(numbered)} still-numbered shared-bank key(s) drawn in the "
          f"priority ports")
    print(f"  {len(labels)} distinct drawing label(s) wait on them\n")
    print(f"  {'key':<10}{'labels':>7}   the labels, first two")
    for k in sorted(numbered, key=lambda k: (-len(numbered[k]), k)):
        ls = sorted(numbered[k])
        print(f"  {k:<10}{len(ls):>7}   {', '.join(ls[:2])}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
