#!/usr/bin/env python3
"""Is this left-facing piece the mirror of that right-facing one?

Question answered
-----------------
`half_named_mirrors.py` finds a piece whose twin is unnamed by reading
*names* -- it pairs `..._LEFT_F03` with `..._RIGHT_F03`. That cannot help
where neither side has a name, which is exactly the case for the seven
unnamed hero-slot pieces in `stand_aim.map`.

The art can answer it directly. A mirrored sprite is the same polygon with x
negated, so: take both point sets, translate each to its own bounding-box
centre, flip one in x, and compare. If the two sets agree point for point,
one is the mirror of the other.

The control
-----------
The bank already contains mirrored pairs a person named from other evidence
-- `HERO_CROUCH_AIM_LEFT`/`_RIGHT`, `HERO_CROUCH_SHOOT_LEFT_F0`/`_RIGHT_F0`
and so on. `--control` runs the test over those and reports the match score
for each, so the threshold is set from pairs known to be right rather than
chosen. It also scores deliberately wrong pairings, so the gap between a true
mirror and a near miss is visible.

Signal being read
-----------------
The polygon tree's leaf points in the shared video2 bank, via
`polygon_render.Renderer`, which is the same geometry `polygon_extent` and
the PNG renderer use. Score is the mean nearest-neighbour distance between
the two centred point sets after the flip, in polygon units; identical art
scores 0.

Usage
-----
    python3 notes/shared-bank-geometry/mirror_match.py --control
    python3 notes/shared-bank-geometry/mirror_match.py --unknowns
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
sys.path.insert(0, str(SRC.parent / "another-world-archaeology" / "tools"))
sys.path.insert(0, str(SRC / "notes" / "polygon-extent-correction"))
import polygon_render                                        # noqa: E402
from extent_matches_renderer import slab                     # noqa: E402

RE_EQU = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s+(0x[0-9A-Fa-f]+)",
                    re.M)
BRANCHES = ("chahi_amiga_1991", "dos_1992")

# Pairs a person named from other evidence, used only as the control.
CONTROL = [("HERO_CROUCH_AIM_LEFT", "HERO_CROUCH_AIM_RIGHT"),
           ("HERO_CROUCH_SHOOT_LEFT_F0", "HERO_CROUCH_SHOOT_RIGHT_F0"),
           ("HERO_CROUCH_SHOOT_LEFT_F1", "HERO_CROUCH_SHOOT_RIGHT_F1"),
           ("HERO_STAND_ARMED_LEFT", "HERO_STAND_ARMED_RIGHT"),
           ("HERO_CROUCH_LEFT", "HERO_CROUCH_RIGHT")]
WRONG = [("HERO_CROUCH_AIM_LEFT", "HERO_CROUCH_SHOOT_RIGHT_F1"),
         ("HERO_CROUCH_SHOOT_LEFT_F0", "HERO_CROUCH_AIM_RIGHT"),
         ("HERO_STAND_ARMED_LEFT", "HERO_CROUCH_AIM_RIGHT")]
UNKNOWN_L = ["HERO_STAND_AIM_LEFT", "CV_3A96", "CV_391A"]
UNKNOWN_R = ["CV_3858", "CV_36D2", "CV_15DC"]


def offsets() -> dict[str, int]:
    out: dict[str, int] = {}
    for branch in BRANCHES:
        for f in sorted((SRC / "src" / "levels" / branch).glob("[A-Z]*.asm")):
            for n, v in RE_EQU.findall(f.read_text(errors="replace")):
                out.setdefault(n, int(v, 16))
    return out


def points(bank: bytes, off: int):
    r = polygon_render.Renderer(bank, polygon_render.synthetic_palette())
    r.render(off, color=0xFF, zoom=polygon_render.DEFAULT_ZOOM)
    return [p for path in r.paths for p in path.points]


def centred(pts):
    if not pts:
        return []
    cx = (min(p[0] for p in pts) + max(p[0] for p in pts)) / 2
    cy = (min(p[1] for p in pts) + max(p[1] for p in pts)) / 2
    return [(p[0] - cx, p[1] - cy) for p in pts]


def score(a, b) -> float:
    """Mean nearest-neighbour distance after flipping `b` in x."""
    A, B = centred(a), [(-x, y) for x, y in centred(b)]
    if not A or not B:
        return float("inf")
    tot = 0.0
    for x, y in A:
        tot += min((x - u) ** 2 + (y - v) ** 2 for u, v in B) ** 0.5
    return tot / len(A)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--control", action="store_true")
    ap.add_argument("--unknowns", action="store_true")
    args = ap.parse_args()

    off = offsets()
    bank = slab("video2", "amiga", 0)

    def pts(name):
        return points(bank, off[name]) if name in off else []

    if args.control or not args.unknowns:
        print("  known mirrored pairs (named from other evidence):")
        good = []
        for a, b in CONTROL:
            if a not in off or b not in off:
                print(f"    {a:<30}{b:<30}(absent)")
                continue
            s = score(pts(a), pts(b))
            good.append(s)
            print(f"    {a:<30}{b:<30}{s:8.3f}")
        print("\n  deliberately wrong pairings:")
        bad = []
        for a, b in WRONG:
            if a not in off or b not in off:
                continue
            s = score(pts(a), pts(b))
            bad.append(s)
            print(f"    {a:<30}{b:<30}{s:8.3f}")
        if good and bad:
            print(f"\n  true pairs score at most {max(good):.3f}; "
                  f"wrong pairs at least {min(bad):.3f}")
            if max(good) >= min(bad):
                print("  ** the two ranges overlap -- the test does not "
                      "separate them", file=sys.stderr)
                return 1

    if args.unknowns:
        print("\n  every unnamed left against every unnamed right:")
        print(f"    {'':<12}" + "".join(f"{r:>12}" for r in UNKNOWN_R))
        for l in UNKNOWN_L:
            row = "".join(f"{score(pts(l), pts(r)):12.3f}" for r in UNKNOWN_R)
            print(f"    {l:<12}{row}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
