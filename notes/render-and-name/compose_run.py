#!/usr/bin/env python3
"""Render a run of frames **over the backdrop its routine already drew**.

Question answered
-----------------
`docs/NAMING.md` grade E3 says render the polygon and look at it. On its own
background a great many pictures are unreadable: a few black wedges on grey,
a sliver, a two-path speck. `README.md`'s composite rule is the fix -- when a
run's pictures are thin and its routine installs them beside another draw, put
them **over** that other draw before judging them. This is the tool that does
it, and it answers two questions at once:

  1. what does the frame look like where the engine actually puts it, and
  2. do the frames of a run form one animation?

For (2) it prints, per frame, the whole picture's box, its path count, and the
box of each fill colour it is asked to track. A run that is one animation
shows it in the numbers before the eye is consulted: a core that carries
through at shrinking sizes, a box that converges on one point. That is what
separates "these fifteen pictures are one thing" from "these fifteen pictures
are drawn in a row".

The signal read is the **renderer's own SVG**, not the ROM -- deliberately.
`notes/polygon-extent-correction/` records a bug that survived for eight days
because extents were measured straight from the bank with no renderer in
between. `awvm-render-polygons` is a port of the engine, so its output is the
arbiter. Coordinates below are page coordinates on the 320x200 page, with the
polygon placed at whatever anchor the renderer used.

Producing the renders first (regenerable, not committed):

    AnotherWorld_VMTools/target/release/awvm-render-polygons \\
        --port amiga --stage 1 \\
        --romset another-world-archaeology/tmp/output/amiga/romset \\
        --bank cinematic --out <dir> --palette 22

**The palette must be the one the routine itself sets**, not 0. Palette 0x16
is 22 in decimal; passing 0 here renders this run as black on black.

Run it
------
The INTRO pulse run, which is what it was written for -- `--under` is the
backdrop the routine copies to page 0, `--frames` the run:

    python3 notes/render-and-name/compose_run.py --renders <dir> --out <dir> \\
        --under 3052 EA1C EA30 \\
        --frames 887C 8890 8958 8A24 8AE0 8B90 8C04 8C68 8CD8 8D4A 8DA0 \\
                 8DF0 8E10 8E30 8E3E \\
        --track '#fb7474' '#fbdbb7'

reproduces the table in `proposals_chahi_amiga_1991__INTRO_pulse.md`, writes
`frame00.svg` .. `frame14.svg` (each frame over the backdrop) and `trail.svg`
(every frame at once, which shows the trajectory in one picture). With no
`--under` it composites over flat grey, which is still the right thing for a
run that has no backdrop.

`--progressive` changes what each frame SVG holds: frame N becomes layers 0..N
drawn together rather than layer N alone. That is what a background composite
routine does, and it is the only way to see what a layer contributes.

Turning the SVGs into something viewable is one line and deliberately not done
here, so the tool has no image-library dependency:

    for f in <dir>/*.svg; do magick -density 220 "$f" "${f%.svg}.png"; done
"""
from __future__ import annotations

import argparse
import pathlib
import re
import sys

RE_PATH = re.compile(r'<path fill="([^"]*)" d="([^"]*)"\s*/>')
RE_PT = re.compile(r"(-?[\d.]+)\s+(-?[\d.]+)")


def paths(renders: pathlib.Path, off: str) -> list[tuple[str, str]]:
    """Every `<path>` of the polygon rendered at `off`, as (fill, d)."""
    hits = sorted(renders.glob(f"*_0x{off.upper()}.svg"))
    if not hits:
        raise SystemExit(f"no render for 0x{off.upper()} in {renders}\n"
                         f"  (did awvm-render-polygons run for this stage?)")
    return RE_PATH.findall(hits[0].read_text())


def box(ps, fill=None):
    pts = [(float(a), float(b))
           for f, d in ps if fill is None or f == fill
           for a, b in RE_PT.findall(d)]
    if not pts:
        return None
    xs = [p[0] for p in pts]
    ys = [p[1] for p in pts]
    return (max(xs) - min(xs), max(ys) - min(ys), min(xs), max(xs), min(ys), max(ys))


RE_EQU = re.compile(r"^(CINEMATIC_[A-Za-z0-9_]+)\s+EQU\s+(0x[0-9A-Fa-f]+)\s*$", re.M)
RE_LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
RE_DRAW = re.compile(r"video offset=(\S+?),\s*x=(-?\d+|\[[^\]]+\]),"
                     r"\s*y=(-?\d+|\[[^\]]+\])")
SRC = pathlib.Path(__file__).resolve().parents[2] / "src" / "levels"


def signed(v: int) -> int:
    return v - 0x10000 if v >= 0x8000 else v


def draws_of(branch: str, stage: str, routine: str):
    """Every literal draw in `routine`, as (label, offset-hex, dx, dy).

    A draw with a variable coordinate cannot be placed and is skipped, with a
    note, rather than guessed at.
    """
    text = (SRC / branch / f"{stage}.asm").read_text()
    equ = {n: int(v, 16) for n, v in RE_EQU.findall(text)}
    out, inside, skipped = [], False, 0
    for line in text.splitlines():
        m = RE_LABEL.match(line)
        if m:
            if inside and m.group(1) != routine:
                break
            inside = m.group(1) == routine
            continue
        if not inside:
            continue
        d = RE_DRAW.search(line)
        if not d:
            continue
        name, x, y = d.groups()
        if x.startswith("[") or y.startswith("[") or name not in equ:
            skipped += 1
            continue
        out.append((name.replace("CINEMATIC_", ""), f"{equ[name]:04X}",
                    signed(int(x)) - 160.0, signed(int(y)) - 100.0))
    if skipped:
        print(f"  ({skipped} draw(s) skipped: a variable coordinate or an "
              f"unresolved name)")
    return out


def shift(path: tuple[str, str], dx: float, dy: float) -> tuple[str, str]:
    """Translate one (fill, d) pair by (dx, dy)."""
    if dx == 0 and dy == 0:
        return path
    fill, d = path
    def mv(m):
        return f"{float(m.group(1)) + dx:.3f} {float(m.group(2)) + dy:.3f}"
    return (fill, re.sub(r"(-?[\d.]+)\s+(-?[\d.]+)", mv, d))


def svg(body: list[tuple[str, str]], bg: str) -> str:
    return ('<svg xmlns="http://www.w3.org/2000/svg" width="320" height="200" '
            'viewBox="0 0 320 200">\n'
            f'  <rect x="-40" y="-40" width="400" height="280" fill="{bg}"/>\n'
            + "\n".join(f'  <path fill="{f}" d="{d}"/>' for f, d in body)
            + "\n</svg>\n")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--renders", type=pathlib.Path, required=True,
                    help="awvm-render-polygons output directory")
    ap.add_argument("--out", type=pathlib.Path, required=True)
    ap.add_argument("--under", nargs="*", default=[],
                    help="offsets drawn BEHIND every frame, in draw order")
    ap.add_argument("--under-routine",
                    help="build the backdrop from this routine's own draw list, "
                         "each layer PLACED at its x, y -- the scene a run plays over")
    ap.add_argument("--frames", nargs="*", default=[],
                    help="offsets of the run, in the order the routine draws them")
    ap.add_argument("--routine",
                    help="instead of --frames: take the draw list from this routine "
                         "in --branch/--stage, and PLACE each layer at its own x, y")
    ap.add_argument("--branch", default="chahi_amiga_1991")
    ap.add_argument("--stage", default="INTRO")
    ap.add_argument("--track", nargs="*", default=[],
                    help="fill colours to measure separately, e.g. '#fb7474'")
    ap.add_argument("--progressive", action="store_true",
                    help="each frame is drawn OVER the ones before it, which is "
                         "what a background composite actually does")
    ap.add_argument("--bg", default="#909090",
                    help="colour behind everything; only visible where nothing draws")
    args = ap.parse_args()

    if not args.frames and not args.routine:
        raise SystemExit("pass --frames or --routine")


    args.out.mkdir(parents=True, exist_ok=True)
    under = [p for o in args.under for p in paths(args.renders, o)]
    if args.under_routine:
        for _, off, dx, dy in draws_of(args.branch, args.stage, args.under_routine):
            under += [shift(p, dx, dy) for p in paths(args.renders, off)]

    placed: list[tuple[str, str, float, float]] = []   # (label, offset, dx, dy)
    if args.routine:
        placed = draws_of(args.branch, args.stage, args.routine)
        if not placed:
            raise SystemExit(f"no literal draws found in {args.routine}")
        args.frames = [o for _, o, _, _ in placed]

    head = "  f   offset   whole picture                                 paths"
    for c in args.track:
        head += f"  {c:>9}"
    print(head)

    trail = list(under)
    for i, off in enumerate(args.frames):
        ps = paths(args.renders, off)
        if placed:
            _, _, dx, dy = placed[i]
            ps = [shift(p, dx, dy) for p in ps]
        trail += ps
        body = list(trail) if args.progressive else under + ps
        (args.out / f"frame{i:02d}.svg").write_text(svg(body, args.bg))
        w = box(ps)
        tag = placed[i][0][:26] if placed else f"F{i}"
        line = (f"  {tag:<26} 0x{off.upper():<6} {w[0]:6.1f}x{w[1]:6.1f}  "
                f"x[{w[2]:7.1f},{w[3]:7.1f}] y[{w[4]:6.1f},{w[5]:6.1f}]  {len(ps):>3}")
        for c in args.track:
            b = box(ps, c)
            line += f"  {b[0]:4.1f}x{b[1]:4.1f}" if b else "        - "
        print(line)

    (args.out / "trail.svg").write_text(svg(trail, args.bg))
    first, last = box(paths(args.renders, args.frames[0])), box(paths(args.renders, args.frames[-1]))
    print(f"\n  first {first[0]:.1f}x{first[1]:.1f}  ->  last {last[0]:.1f}x{last[1]:.1f}")
    print(f"  last frame's box: x[{last[2]:.1f}, {last[3]:.1f}] y[{last[4]:.1f}, {last[5]:.1f}]")
    print(f"\n  wrote {len(args.frames)} frame svg(s) + trail.svg to {args.out}")
    print("  a run that converges on one point is one animation; a run whose")
    print("  boxes wander is several pictures drawn in a row.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
