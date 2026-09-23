#!/usr/bin/env python3
"""A still-numbered key that is the exact mirror of a named one takes its flip.

Question answered
-----------------
`mirror_match.py` pairs left- and right-facing art by a similarity *score*,
and its own control fails where it matters: a wrong aim-vs-shoot pairing
scores 0.451 against true pairs at 0.520-0.923, so it is only usable where the
gap is wide. This asks a narrower question with a yes/no answer, and gets a
clean control for it.

Two pieces are an **exact mirror** when they have the same leaf count, the
same width, the same top and bottom edge, and x spans reflected about the same
axis within half a unit:

    CV_FIGURE_RUN_RIGHT_LIMB_POSE_01   (-5.0,-39.5)..(+5.0,-32.5)
    CV_3200                            (-5.0,-39.5)..(+5.0,-32.5)

The signed bounding box is relative to the draw anchor, which is what makes
this a statement about facing rather than about size -- the same reasoning
`../lake-shooting/` and the teleport beams rest on.

The control, and the class it restricts this to
-----------------------------------------------
Every named key containing `_LEFT` or `_RIGHT` whose flipped name also exists
is a test case: the two should be exact mirrors. By leaf count:

    1 leaf  (limb)      8 exact,  0 not
    2 leaves (body)    24 exact,  0 not
    3 leaves            2 exact,  2 not
    4 leaves            0 exact,  2 not
    5 leaves (body)    28 exact, 26 not

So the test is **exact for simple pieces and unreliable for complex bodies**,
where the two facings are genuinely drawn at different widths rather than
reflected -- `CV_FIGURE_WALK_RIGHT_BODY_F00` spans -17.0..+15.5 against its
twin's -16.5..+17.0. `--max-leaves` bounds the class; the default of 2 is
where the control is 32 for 32.

Index for index
---------------
A flipped *name* is only right if the two families correspond member by
member. They do: the committed `CV_FIGURE_WALK_{LEFT,RIGHT}_LIMB_POSE_00..03`
pairs are exact mirrors at the same index, 4 for 4.

Usage
-----
    python3 notes/shared-bank-geometry/mirror_exact.py --control
    python3 notes/shared-bank-geometry/mirror_exact.py
    python3 notes/shared-bank-geometry/mirror_exact.py --proposals
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(Path(__file__).resolve().parent))
sys.path.insert(0, str(SRC / "notes" / "polygon-extent-correction"))
sys.path.insert(0, str(SRC.parent / "another-world-archaeology" / "tools"))
import hero_pose_consensus as H                              # noqa: E402
from polygon_tree import parse_polygon_tree                  # noqa: E402
from polygon_extent import extent                            # noqa: E402

RE_NUM = re.compile(r"^CV_[0-9A-F]{4}$")
RE_EQU = re.compile(r"^(CV_[A-Za-z0-9_]+)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)


def flip(name: str) -> str:
    return (name.replace("_LEFT", "\0").replace("_RIGHT", "_LEFT")
                .replace("\0", "_RIGHT"))


def load():
    equ: dict[str, int] = {}
    for f in sorted((SRC / "src" / "levels").glob("*/*.asm")):
        for n, v in RE_EQU.findall(f.read_text(errors="replace")):
            equ[n] = int(v, 16)
    bank = H.bank()
    ext = {}
    for n, o in equ.items():
        try:
            ext[n] = extent(parse_polygon_tree(bank, o))
        except Exception:
            pass
    return equ, ext


def exact_mirror(a, c) -> bool:
    ax0, ay0, ax1, ay1, al = a
    cx0, cy0, cx1, cy1, cl = c
    if al != cl or abs((ax1 - ax0) - (cx1 - cx0)) >= 0.01:
        return False
    if abs(ay0 - cy0) >= 0.01 or abs(ay1 - cy1) >= 0.01:
        return False
    # Reflected about one axis, and that axis within half a unit of the
    # anchor: x -> 2k - x with |k| <= 0.5.
    return (abs((ax0 + cx1) - (ax1 + cx0)) < 0.01 and abs(ax0 + cx1) <= 1.0)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--control", action="store_true")
    ap.add_argument("--max-leaves", type=int, default=2,
                    help="only propose for pieces this simple; the control "
                         "is exact at 2 and degrades above it")
    ap.add_argument("--proposals", action="store_true")
    args = ap.parse_args()
    equ, ext = load()

    if args.control:
        by = collections.defaultdict(lambda: [0, 0])
        for n in sorted(ext):
            if RE_NUM.match(n) or ("_LEFT" not in n and "_RIGHT" not in n):
                continue
            f = flip(n)
            if f not in ext:
                continue
            k = ext[n][4]
            by[k][0 if exact_mirror(ext[n], ext[f]) else 1] += 1
        print(f"  {'leaves':<10}{'exact mirror':>13}{'not':>6}")
        for k in sorted(by):
            print(f"  {k:<10}{by[k][0]:>13}{by[k][1]:>6}")
        run = sum(by[k][0] for k in by if k <= args.max_leaves)
        bad = sum(by[k][1] for k in by if k <= args.max_leaves)
        print(f"\n  at --max-leaves {args.max_leaves}: {run} exact, {bad} not")
        print("\n  index for index, the committed WALK limb families:")
        ok = 0
        for i in range(4):
            L = f"CV_FIGURE_WALK_LEFT_LIMB_POSE_{i:02d}"
            R = f"CV_FIGURE_WALK_RIGHT_LIMB_POSE_{i:02d}"
            if L in ext and R in ext and exact_mirror(ext[L], ext[R]):
                ok += 1
        print(f"    {ok} of 4 pairs are exact mirrors at the same index")
        return 1 if bad else 0

    named = [n for n in ext if not RE_NUM.match(n)
             and ("_LEFT" in n or "_RIGHT" in n)]
    rows = []
    held = collections.Counter()
    for u in sorted(n for n in ext if RE_NUM.match(n)):
        if ext[u][4] > args.max_leaves:
            continue
        hits = [n for n in named if exact_mirror(ext[u], ext[n])]
        if len(hits) != 1:
            held["mirrors no named key, or more than one"] += 1
            continue
        want = flip(hits[0])
        if want in ext:
            held["the flipped name is already taken"] += 1
            continue
        # The named key must itself be mirrored by only this one, or the
        # correspondence is not one-to-one.
        back = [v for v in ext if RE_NUM.match(v)
                and ext[v][4] <= args.max_leaves
                and exact_mirror(ext[v], ext[hits[0]])]
        if len(back) != 1:
            held["several still-numbered keys mirror the same named one"] += 1
            continue
        rows.append((u, want, hits[0]))

    if args.proposals:
        for u, want, src in rows:
            print(f"{u} {want}")
        return 0
    print(f"{len(rows)} still-numbered key(s) are the exact mirror of exactly "
          f"one named key, with the flipped name free\n")
    for u, want, src in rows:
        x0, y0, x1, y1, lv = ext[u]
        print(f"  {u:<10}0x{equ[u]:04X}  ({x0:+.1f},{y0:+.1f}).."
              f"({x1:+.1f},{y1:+.1f})/{lv}  ->  {want}")
        print(f"      mirrors {src}")
    print()
    for why, c in held.most_common():
        print(f"  held: {c:>4}  {why}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
