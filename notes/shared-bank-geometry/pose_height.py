#!/usr/bin/env python3
"""Is this hero picture upright or crouched? Measured, not read off a name.

Question answered
-----------------
`hero_pose_consensus.py` reports offsets where two stages describe the same
picture differently. Six of them are the same argument twice over: CAPSULE
says the hero is aiming, CAVES says the hero is crouching.

    CV_17CC   CAPSULE HERO_GUN_AIM_HOLD_LEFT_LOOP      -> AIM   LEFT
              CAVES   HERO_CROUCH_ARMED_LEFT_LOOP      -> CROUCH LEFT

Neither name is obviously wrong and #0120 forbids a tool picking a winner
between two earned names. But this particular question is not a matter of
preference: a crouch is **shorter than standing**, and the art says by how
much.

Signal being read
-----------------
Figure height (`polygon_extent.extent`, y1 - y0) against an upright
reference: the 15 `HERO_WALK_LEFT_BODY` frames in `walk_left_body.map`,
which are the hero on his feet and were named from an independent line of
evidence. Median upright height is 49.0.

Measured, the answer is bimodal with nothing in the middle:

    CV_1664   44.5   -4.5 from upright   UPRIGHT
    CV_17CC   45.0   -4.0               UPRIGHT
    CV_1784   33.0  -16.0               CROUCHED
    CV_3764   33.0  -16.0               CROUCHED
    CV_39A2   33.5  -15.5               CROUCHED
    CV_389E   33.0  -16.0               CROUCHED
    CV_3ADC   33.5  -15.5               CROUCHED

So CAVES is right about four of them and wrong about two: `CV_1664` and
`CV_17CC` are within 5 units of standing height and are not crouches at all.
CAPSULE's "aim" is the better name there.

**Positive control.** `CV_1784` is the one offset in this group where the
sources already agreed on CROUCH, with no AIM claim against it. It measures
33.0 -- the crouched mode -- so the test confirms an independently agreed
answer before being trusted on the disputed ones.

The threshold is -6, which is a gap, not a cutoff: the two modes are 44.5..45
and 33..33.5 and nothing lies between them. `--threshold` moves it;
`--reference` takes a different upright map.

What this does NOT settle
-------------------------
Whether the figure is aiming. Height distinguishes upright from crouched and
says nothing about the arms, so "CROUCH vs AIM" resolves only in the
direction of the body. A crouched figure may well be aiming too, and for the
four crouched ones both names are partly right -- which is the #0120
intersection, not a winner.

Usage
-----
    python3 notes/shared-bank-geometry/pose_height.py CV_17CC CV_1784
    python3 notes/shared-bank-geometry/pose_height.py --disputed
"""
from __future__ import annotations

import argparse
import statistics
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
SRC = HERE.parents[1]
ARCH = SRC.parent / "another-world-archaeology"
sys.path.insert(0, str(ARCH / "tools"))
sys.path.insert(0, str(SRC / "notes" / "polygon-extent-correction"))
from polygon_tree import parse_polygon_tree                   # noqa: E402
from polygon_extent import extent                             # noqa: E402

# The six disputed offsets plus CV_1784, the agreed-CROUCH control.
DISPUTED = {
    "CV_1664": "AIM_RIGHT vs CROUCH_RIGHT",
    "CV_17CC": "AIM_LEFT vs CROUCH_LEFT",
    "CV_3764": "AIM_RIGHT vs CROUCH_RIGHT",
    "CV_39A2": "AIM_LEFT vs CROUCH_LEFT",
    "CV_389E": "CROUCH_RIGHT vs SHOOT_RIGHT",
    "CV_3ADC": "CROUCH_LEFT vs SHOOT_LEFT",
    "CV_1784": "CROUCH, agreed -- the control",
}


def height(bank: bytes, cv: str) -> float:
    x0, y0, x1, y1, _lv = extent(parse_polygon_tree(bank, int(cv[3:], 16)))
    return y1 - y0


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("offsets", nargs="*")
    ap.add_argument("--disputed", action="store_true",
                    help="use the built-in AIM-vs-CROUCH set plus its control")
    ap.add_argument("--threshold", type=float, default=-6.0)
    ap.add_argument("--reference", type=Path,
                    default=HERE / "walk_left_body.map")
    args = ap.parse_args()

    p = ARCH / "tmp" / "output" / "amiga" / "resources" / "resource-0x11.bin"
    if not p.is_file():
        raise SystemExit(f"missing {p}; run tools/aw_unpacker.py")
    bank = p.read_bytes()

    ref = [l.split()[0] for l in args.reference.read_text().splitlines()
           if l.startswith("CV_")]
    if not ref:
        raise SystemExit(f"no CV_ rows in {args.reference}")
    hs = [height(bank, c) for c in ref]
    med = statistics.median(hs)
    print(f"upright reference: {len(ref)} frames from {args.reference.name}")
    print(f"  min {min(hs):.1f}   median {med:.1f}   max {max(hs):.1f}\n")

    targets = args.offsets or (list(DISPUTED) if args.disputed else [])
    if not targets:
        raise SystemExit("give offsets, or --disputed")

    print(f"  {'offset':<9}{'height':>8}{'vs upright':>12}   "
          f"{'verdict':<10} note")
    seen = []
    for cv in targets:
        v = height(bank, cv)
        d = v - med
        verdict = "UPRIGHT" if d > args.threshold else "CROUCHED"
        seen.append(d)
        print(f"  {cv:<9}{v:>8.1f}{d:>+12.1f}   {verdict:<10} "
              f"{DISPUTED.get(cv, '')}")

    up = [d for d in seen if d > args.threshold]
    down = [d for d in seen if d <= args.threshold]
    if up and down:
        gap = min(up) - max(down)
        print(f"\nthe two modes are separated by {gap:.1f} units with nothing "
              f"between them, so the {args.threshold:.0f} threshold is a gap "
              f"rather than a cutoff.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
