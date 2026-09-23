#!/usr/bin/env python3
"""Do the hero's feet leave the ground, and is that in the anchor or the art?

Question answered
-----------------
`../HANDOFF.md` listed the jump sheets as held, with this reasoning:

    Jump sheets held (13 frames per direction): CAVES says JUMP,
    LAKE/CAPSULE say WALK/RUN, identical X steps, and neither writes
    `HERO_Y`.

The "neither writes HERO_Y" half is true and the inference drawn from it was
wrong. A previous session had established that `HERO_FALL_LEFT_LOOP` writes
`add [HERO_Y], 0x0000` four times -- a no-op -- and is therefore not a fall,
and it is tempting to run the same argument here: no vertical write, no jump.

**That argument does not hold, and this probe is why.** The anchor is the
ground reference. A sprite sheet can lift the figure inside its own frame,
and this one does: measured from the shared bank, the 12-frame sheet has its
lowest point at y=+0.5 in ten frames and at **-7.0 and -3.5** in the other
two. The feet leave the ground for two frames. The jump is drawn in the art.

So both stages were right about the motion and the probe that could not see
it was the problem, not the names.

Signal being read
-----------------
For each frame in a sequence, the expanded polygon tree's **bottom edge**
relative to the draw anchor (`polygon_extent.extent`, index 3). The anchor
sits at the hero's feet on the ground, so:

Ground level is taken from the data, not assumed to be zero. Extents sit on
a half-unit grid (a solid's size bytes are halved), the standing frames of
these sheets bottom out at +0.5, and one sheet has a frame at -0.5 -- a
single grid step, which is not a jump. So:

    ground   = the most common bottom value across the sequence
    airborne = bottom < ground - TOLERANCE  (default 1.0, one grid step)

The first version of this probe tested `bottom > 0` and duly reported a
12-frame sheet as having two separate airborne runs, one of them a single
frame at -0.5. Its own "a jump should leave and return once" check is what
caught that, which is the reason that check is in here.

Top edge and height are printed too, because they do NOT answer the question:
a figure that crouches and straightens changes its top edge without leaving
the ground. The bottom edge is the one that means airborne.

What "pass" looks like
----------------------
A jump shows a contiguous run of frames with a negative bottom, opening and
closing at the ends of the sheet rather than at its edges. A walk or run
shows a bottom that never goes negative. `--sequence` takes the frames in
draw order; order matters, since an airborne run split across the sheet
would mean the sequence was assembled wrong.

Usage
-----
    python3 notes/shared-bank-geometry/airborne_in_art.py --routine \
        HERO_JUMP_LEFT_FROM_STAND --port amiga --stage CAVES
    python3 notes/shared-bank-geometry/airborne_in_art.py --sequence \
        CV_52C0 CV_52E0 CV_5300 --port amiga
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
ARCH = SRC.parent / "another-world-archaeology"
sys.path.insert(0, str(ARCH / "tools"))
sys.path.insert(0, str(SRC / "notes" / "polygon-extent-correction"))
from polygon_tree import parse_polygon_tree                   # noqa: E402
from polygon_extent import extent                             # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
RE_DRAW = re.compile(r"video\s+type=0,\s*offset=(CV_[0-9A-F]{4}),\s*x=\[HERO_X\]")
RE_EQU = re.compile(r"^(CV_[0-9A-F]{4})\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)


def bank(port: str) -> bytes:
    p = ARCH / "tmp" / "output" / port / "resources" / "resource-0x11.bin"
    if not p.is_file():
        raise SystemExit(f"missing {p}; run tools/aw_unpacker.py")
    return p.read_bytes()


def frames_of(port: str, stage: str, routine: str) -> list[str]:
    """The CV_ frames a routine draws at the hero anchor, in draw order."""
    text = (SRC / "src" / "levels" / PORTS[port] / f"{stage}.asm").read_text(
        errors="replace")
    cur, out = None, []
    for line in text.splitlines():
        m = RE_LBL.match(line)
        if m:
            if cur == routine and out:
                return out
            cur = m.group(1)
            continue
        if cur == routine:
            d = RE_DRAW.search(line)
            if d:
                out.append(d.group(1))
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", default="amiga", choices=sorted(PORTS))
    ap.add_argument("--stage", default="CAVES")
    ap.add_argument("--routine")
    ap.add_argument("--sequence", nargs="*")
    ap.add_argument("--tolerance", type=float, default=1.0,
                    help="how far below the modal ground level counts as "
                         "airborne (default one grid step)")
    args = ap.parse_args()

    if args.routine:
        seq = frames_of(args.port, args.stage, args.routine)
        label = f"{args.port}/{args.stage} {args.routine}"
    elif args.sequence:
        seq, label = args.sequence, f"{args.port} (explicit sequence)"
    else:
        raise SystemExit("give --routine or --sequence")
    if not seq:
        raise SystemExit("no hero-anchored CV_ draws found")

    text = (SRC / "src" / "levels" / PORTS[args.port]
            / f"{args.stage}.asm").read_text(errors="replace")
    table = {n: int(v, 16) for n, v in RE_EQU.findall(text)}
    b = bank(args.port)

    import collections
    rows = []
    for n in seq:
        # A CV_ name IS its offset. Falling back to that keeps --sequence
        # working for frames EQU'd in some other stage than --stage: the
        # walk maps in this directory are exactly that case, and looking
        # them up only through one stage's table crashed on an empty list.
        off = table.get(n)
        if off is None:
            m = re.fullmatch(r"CV_([0-9A-F]{4})", n)
            off = int(m.group(1), 16) if m else None
        rows.append((n, extent(parse_polygon_tree(b, off))
                     if off is not None else None))
    bottoms = [e[3] for _n, e in rows if e is not None]
    if not bottoms:
        raise SystemExit(
            f"none of the {len(seq)} frame(s) could be resolved to an offset "
            f"-- check the names, or pass --stage for the stage that EQUs "
            f"them")
    ground = collections.Counter(bottoms).most_common(1)[0][0]

    print(f"{label}   {len(seq)} frame(s)")
    print(f"ground level = {ground:+.1f} (modal bottom); airborne means "
          f"more than {args.tolerance:.1f} above it\n")
    print(f"  {'#':>3}  {'frame':<10}{'bottom':>9}{'top':>8}{'height':>8}"
          f"{'width':>8}   ground?")
    air = []
    for i, (n, e) in enumerate(rows):
        if e is None:
            print(f"  {i:>3}  {n:<10}  not defined in {args.stage}")
            continue
        x0, y0, x1, y1, _lv = e
        on = y1 >= ground - args.tolerance
        if not on:
            air.append(i)
        print(f"  {i:>3}  {n:<10}{y1:>9.1f}{y0:>8.1f}{y1 - y0:>8.1f}"
              f"{x1 - x0:>8.1f}   {'on ground' if on else 'AIRBORNE'}"
              f"{'' if on else f'  ({ground - y1:.1f} up)'}")

    if not air:
        print(f"\nNo frame's lowest point rises more than "
              f"{args.tolerance:.1f} above the modal ground level: the feet "
              f"stay down throughout. Whatever this is, it is not a jump "
              f"drawn in the art.")
        return 0
    runs, start = [], air[0]
    for a, bnext in zip(air, air[1:] + [None]):
        if bnext != (a + 1 if a is not None else None):
            runs.append((start, a))
            start = bnext
    span = ", ".join(f"{s}..{e}" if s != e else f"{s}" for s, e in runs)
    print(f"\n{len(air)} of {len(seq)} frames are airborne (frame index "
          f"{span}). The anchor is the ground reference and the lift is drawn "
          f"INSIDE the sprite, so a routine can animate a jump without ever "
          f"writing HERO_Y.")
    if len(runs) > 1:
        print("More than one airborne run -- check the frame order; a jump "
              "should leave and return once.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
