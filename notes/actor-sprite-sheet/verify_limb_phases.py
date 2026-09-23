#!/usr/bin/env python3
"""Do the committed LIMB_POSE phase sets survive a second, different signal?

Question answered
-----------------
`CV_FIGURE_WALK_<DIR>_LIMB_POSE_00..03` were named from the frames their
**drawer routine names** assign them, after a per-stage index base
calibration. That is one signal, and a naming pass that leans on routine
names can be wrong in exactly the way routine names are wrong.

This checks them against a signal that uses no routine name at all: when a
routine draws **exactly one** `CV_FIGURE_WALK_<DIR>_BODY_F<n>` and also draws
a limb piece, the frame is unambiguous -- the body frame IS the frame number,
and it is already named from a separate line of evidence. Collect those
co-draws and compare with what the limb name claims.

    name                                claimed    observed
    CV_FIGURE_WALK_RIGHT_LIMB_POSE_00   [0, 1]     [0, 1]
    CV_FIGURE_WALK_RIGHT_LIMB_POSE_01   [5, 11]    [5, 11]
    CV_FIGURE_WALK_RIGHT_LIMB_POSE_02   [6, 10]    [6, 10]
    CV_FIGURE_WALK_RIGHT_LIMB_POSE_03   [8, 9]     [8, 9]

Four for four, exactly, with no extra frame. The symmetry that justified the
pairing -- `5 + 11 = 6 + 10 = 16`, the moments either side of mid-stride --
is therefore not an artefact of how the drawers were named.

What it does NOT cover
----------------------
The four left-facing poses are **unobserved**, not confirmed. No routine in
the stages scanned draws exactly one `WALK_LEFT_BODY_F<n>` together with a
left limb, so this signal is silent about them and the check says so rather
than reporting them as passing. Their claim still rests on the drawer names
alone.

An observed frame outside the claimed set is a contradiction and exits 1. A
subset is consistent: a limb genuinely used at two phases need not be
co-drawn at both in the routines this scan can read.

Usage
-----
    python3 notes/actor-sprite-sheet/verify_limb_phases.py
"""
from __future__ import annotations

import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2] / "src" / "levels"

# The committed claim, from README.md's table. Kept here so the check fails
# loudly if someone edits the names without revisiting the evidence.
CLAIM = {
    "CV_FIGURE_WALK_RIGHT_LIMB_POSE_00": {0, 1},
    "CV_FIGURE_WALK_RIGHT_LIMB_POSE_01": {5, 11},
    "CV_FIGURE_WALK_RIGHT_LIMB_POSE_02": {6, 10},
    "CV_FIGURE_WALK_RIGHT_LIMB_POSE_03": {8, 9},
    "CV_FIGURE_WALK_LEFT_LIMB_POSE_00": {0, 1},
    "CV_FIGURE_WALK_LEFT_LIMB_POSE_01": {5, 11},
    "CV_FIGURE_WALK_LEFT_LIMB_POSE_02": {6, 10},
    "CV_FIGURE_WALK_LEFT_LIMB_POSE_03": {8, 9},
}
BRANCHES = ("chahi_amiga_1991", "dos_1992")
STAGES = ("CAVES", "CAPSULE", "PRISON", "ENDING")

RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
RE_BODY = re.compile(r"offset=CV_FIGURE_WALK_(?:RIGHT|LEFT)_BODY_F(\d+)")
RE_LIMB = re.compile(r"offset=(CV_FIGURE_WALK_(?:RIGHT|LEFT)_LIMB_POSE_\d+)")


def observed() -> dict[str, set]:
    out: dict[str, set] = collections.defaultdict(set)
    for br in BRANCHES:
        for stage in STAGES:
            p = SRC / br / f"{stage}.asm"
            if not p.is_file():
                continue
            cur, buf = None, []

            def flush(buf):
                bodies = [m for line in buf for m in RE_BODY.finditer(line)]
                limbs = [m for line in buf for m in RE_LIMB.finditer(line)]
                if len(bodies) == 1 and limbs:
                    frame = int(bodies[0].group(1))
                    for m in limbs:
                        out[m.group(1)].add(frame)

            for line in p.read_text(errors="replace").splitlines():
                m = RE_LBL.match(line)
                if m:
                    flush(buf)
                    cur, buf = m.group(1), []
                elif cur is not None:
                    buf.append(line)
            flush(buf)
    return out


def main() -> int:
    obs = observed()
    print("committed LIMB_POSE phase sets, checked against body co-draws")
    print("(a routine drawing exactly one BODY_F<n> plus a limb)\n")
    print(f"  {'name':<40}{'claimed':<12}{'observed':<14}verdict")
    ok = bad = quiet = 0
    for name, claim in sorted(CLAIM.items()):
        o = obs.get(name, set())
        if not o:
            verdict, quiet = "no observation", quiet + 1
        elif o <= claim:
            verdict, ok = "CONSISTENT", ok + 1
        else:
            verdict, bad = f"**CONTRADICTS** (extra {sorted(o - claim)})", bad + 1
        print(f"  {name:<40}{str(sorted(claim)):<12}"
              f"{str(sorted(o)):<14}{verdict}")
    print(f"\n{ok} consistent, {bad} contradicted, {quiet} unobserved -- "
          f"unobserved is silence, not confirmation.")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
