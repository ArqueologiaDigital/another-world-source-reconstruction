#!/usr/bin/env python3
"""Lay a run of shared-bank offsets out as a labelled filmstrip, in offset order.

Question answered
-----------------
`bank_draw_position.py` settled that 191 shared-bank offsets are hero art.
`bank_shape_census.py` showed those fall into five contiguous runs by offset,
and a run of consecutive offsets in a sprite sheet is an animation. So the
remaining question per run is "which motion", and that needs the frames seen
*in order and next to each other* -- a single frame of a 10-leaf 80x66 figure
says "a person", and only the sequence says what the person is doing.

Each cell is labelled with its symbol and its **measured** extent and leaf
count, not just the picture. This is deliberate: three separate wrong readings
in this project came from judging a magnified thumbnail instead of the numbers
(a 1x12 speck read as a "band", a gun barrel read off a scaled render). The
label is the check on the eye.

Renders come from `awvm-render-polygons --bank video2`, which normalises every
polygon to its anchor and discards the authored position, so a filmstrip shows
shape and pose but says nothing about where a frame sits on screen. Extents
here are anchor-relative for the same reason.

Signals read
------------
`CV_<OFFSET4> EQU 0x<OFFSET4>` lines for the offsets, `resource-0x11.bin` for
the geometry, and one SVG per offset from the render directory, named
`<port>_stage<N>_<group|solid>_0x<OFFSET4>.svg`.

Producing the renders (they are regenerable, so they are not committed):

    cd AnotherWorld_VMTools
    cargo run --quiet --bin awvm-render-polygons -- \
      --port amiga --stage 4 \
      --romset ../another-world-archaeology/tmp/output/amiga/romset \
      --bank video2 --out <render-dir> --palette 0

`video2.rom` there is resource `0x11` zero-padded to 32 KiB; the first 25,108
bytes are identical, so the offsets agree. Stage 4 is arbitrary -- the video2
bank is one shared slab and `--stage` only selects a palette slot.

Usage
-----
    python3 notes/shared-bank-geometry/bank_filmstrip.py \
        --renders <dir> --from 0x00B4 --to 0x17CC --out strip.png
    python3 notes/shared-bank-geometry/bank_filmstrip.py --renders <dir> --runs
"""

from __future__ import annotations

import argparse
import collections
import re
import subprocess
import sys
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
ARCH = SRC.parent / "another-world-archaeology"
sys.path.insert(0, str(ARCH / "tools"))
sys.path.insert(0, str(HERE.parents[1]))
from polygon_tree import parse_polygon_tree            # noqa: E402
from polygon_extent import extent                      # noqa: E402
from actor_slot import actor_slot_names                # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
RE_EQU = re.compile(r"^(CV_[0-9A-F]{4})\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)
RE_D = re.compile(r"offset=(CV_[0-9A-F]{4}),\s*x=(\[?\w+\]?),\s*y=(\[?\w+\]?)")


def load() -> tuple[dict[str, int], dict[str, set]]:
    offs: dict[str, int] = {}
    pos: dict[str, set] = collections.defaultdict(set)
    for br in PORTS.values():
        for p in sorted((SRC / "src" / "levels" / br).glob("*.asm")):
            text = p.read_text(errors="replace")
            xs, ys = actor_slot_names(text)
            for n, v in RE_EQU.findall(text):
                offs[n] = int(v, 16)
            for cv, x, y in RE_D.findall(text):
                bx, by = x.strip("[]"), y.strip("[]")
                if bx in xs and by in ys:
                    pos[cv].add("ACTOR")
                elif not x.startswith("["):
                    pos[cv].add("lit")
                else:
                    pos[cv].add(f"{bx},{by}")
    return offs, pos


def bank() -> bytes:
    p = ARCH / "tmp" / "output" / "amiga" / "resources" / "resource-0x11.bin"
    if not p.is_file():
        raise SystemExit(f"missing {p}; regenerate with "
                         f"`python3 tools/aw_unpacker.py` in the archaeology repo")
    return p.read_bytes()


def svg_for(renders: Path, off: int) -> Path | None:
    for kind in ("group", "solid"):
        for p in renders.glob(f"*_{kind}_0x{off:04X}.svg"):
            return p
    return None


def runs_of(offs: dict[str, int], pos: dict[str, set], subject: str
            ) -> list[list[str]]:
    """Maximal runs of offsets that are adjacent in the *whole* bank's order."""
    want = {"hero": {"HERO_X,HERO_Y"}, "actor": {"ACTOR"}}[subject]
    sel = sorted((c for c in pos if pos[c] == want), key=lambda c: offs[c])
    order = {o: i for i, o in enumerate(sorted(offs.values()))}
    out: list[list[str]] = []
    cur: list[str] = []
    for c in sel:
        if cur and order[offs[c]] == order[offs[cur[-1]]] + 1:
            cur.append(c)
        else:
            if cur:
                out.append(cur)
            cur = [c]
    if cur:
        out.append(cur)
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--renders", type=Path, required=True)
    ap.add_argument("--runs", action="store_true")
    ap.add_argument("--subject", default="hero", choices=["hero", "actor"])
    ap.add_argument("--from", dest="lo")
    ap.add_argument("--to", dest="hi")
    ap.add_argument("--symbols",
                    help="comma-separated CV_xxxx list, laid out in the order "
                         "given rather than by offset -- use this to view an "
                         "animation in its claimed frame order, which is the "
                         "test of whether the claim is continuous")
    ap.add_argument("--out", type=Path)
    ap.add_argument("--tile", default="10x")
    ap.add_argument("--cell", type=int, default=150)
    args = ap.parse_args()

    offs, pos = load()
    b = bank()

    if args.runs:
        for r in runs_of(offs, pos, args.subject):
            ex = []
            for c in r:
                x0, y0, x1, y1, lv = extent(parse_polygon_tree(b, offs[c]))
                ex.append(f"{x1 - x0:.0f}x{y1 - y0:.0f}/{lv}")
            print(f"{len(r):3d}  {r[0]}..{r[-1]}")
            print(f"      {' '.join(ex)}")
        return 0

    if args.symbols:
        if not args.out:
            print("need --out", file=sys.stderr)
            return 2
        sel = [s.strip() for s in args.symbols.split(",") if s.strip()]
        unknown = [s for s in sel if s not in offs]
        if unknown:
            print(f"unknown symbol(s): {', '.join(unknown)}", file=sys.stderr)
            return 2
    else:
        if not (args.lo and args.hi and args.out):
            print("need --from and --to (or --symbols), and --out",
                  file=sys.stderr)
            return 2
        lo, hi = int(args.lo, 16), int(args.hi, 16)
        sel = sorted((n for n, o in offs.items() if lo <= o <= hi),
                     key=lambda n: offs[n])
        if not sel:
            print(f"no bank offsets in [{args.lo}, {args.hi}]", file=sys.stderr)
            return 2

    with tempfile.TemporaryDirectory() as td:
        cells = []
        missing = []
        for n in sel:
            svg = svg_for(args.renders, offs[n])
            if svg is None:
                missing.append(n)
                continue
            x0, y0, x1, y1, lv = extent(parse_polygon_tree(b, offs[n]))
            label = f"{n} {x1 - x0:.0f}x{y1 - y0:.0f}/{lv}"
            png = Path(td) / f"{offs[n]:04X}.png"
            subprocess.run(
                ["convert", "-background", "#888888", str(svg),
                 "-trim", "+repage",
                 "-resize", f"{args.cell}x{args.cell}",
                 "-bordercolor", "#888888", "-border", "4",
                 "-background", "#222222", "-fill", "#ffffff",
                 "-pointsize", "13", "-gravity", "south",
                 "label:" + label, "-append", str(png)],
                check=True)
            cells.append(str(png))
        if missing:
            print(f"no render for {len(missing)}: {', '.join(missing[:8])}",
                  file=sys.stderr)
        # Never pipe a generator through `head` here: a SIGPIPE once silently
        # truncated a 17-row job to 14 in this project. Assert the count.
        assert len(cells) + len(missing) == len(sel), "lost a frame"
        subprocess.run(["montage", "-tile", args.tile, "-geometry", "+3+3",
                        "-background", "#111111", *cells, str(args.out)],
                       check=True)
    print(f"{len(cells)} frames -> {args.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
