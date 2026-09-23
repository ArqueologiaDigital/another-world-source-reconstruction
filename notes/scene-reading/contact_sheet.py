#!/usr/bin/env python3
"""One image showing every unnamed layer of a screen, so a look names many.

Question answered
-----------------
`../prison-cell-block/` named PRISON screen 0x04 by rendering it, and the
cost was one composite plus six single-layer renders looked at one at a time.
At four names a screen and fifty screens a stage that is the bottleneck, and
it is a bottleneck in *looking*, not in rendering.

So: render every layer of a screen into one labelled grid. A single look then
covers the whole screen, and the tiles are side by side, which is how you see
that five tiles are variants of one object or that a tile is a mirror of its
neighbour.

What it draws
-------------
Each tile is one polygon, scaled to fill the tile, on the tile's own bounding
box rather than the 320x200 canvas -- a 6x70 sliver is unreadable at canvas
scale and obvious at tile scale. Under each tile: the constant, its extent and
its path count, so the picture and the numbers are read together.

The tile order is the paint order, so the sheet reads as the screen is built
up, and a layer that is already named is included and marked, because knowing
what sits next to a thing is most of identifying it.

Colours come from `polygon_render.synthetic_palette`, not the stage's real
palette. That is deliberate: the synthetic palette gives adjacent indices
contrasting colours, which separates a shape from its neighbours, where the
real palette often paints a whole object in two near-identical dark blues.
`../prison-cell-block/` was read this way and the cell bars were unmistakable.

Usage
-----
    python3 notes/scene-reading/contact_sheet.py --stage PRISON --screen 04
    python3 notes/scene-reading/contact_sheet.py --stage CAVES --screen 6D \\
        --port msdos --out /tmp/caves_6d.png
    python3 notes/scene-reading/contact_sheet.py --stage CAVES --list
"""

from __future__ import annotations

import argparse
import math
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
ARCH = SRC.parent / "another-world-archaeology"
sys.path.insert(0, str(ARCH / "tools"))
sys.path.insert(0, str(SRC / "notes" / "polygon-extent-correction"))
sys.path.insert(0, str(SRC / "notes" / "screen-scope"))

import cairo                                                 # noqa: E402
import polygon_render                                        # noqa: E402
from extent_matches_renderer import slab                     # noqa: E402
import screen_scope as S                                     # noqa: E402
import backdrop_phase as B                                   # noqa: E402

STAGE_ID = {"PRISON": 3, "CAVES": 4, "CAPSULE": 6}
TILE_W, TILE_H, PAD, CAPTION = 210, 150, 8, 26
RE_EQU = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)


def paths_for(data: bytes, offset: int):
    r = polygon_render.Renderer(data, polygon_render.synthetic_palette())
    r.render(offset, color=0xFF, zoom=polygon_render.DEFAULT_ZOOM)
    return r.paths


def draw_tile(ctx, paths, ox: float, oy: float):
    """Fit one polygon's own bbox into a tile at (ox, oy)."""
    pts = [p for path in paths for p in path.points]
    if not pts:
        return
    x0 = min(p[0] for p in pts)
    x1 = max(p[0] for p in pts)
    y0 = min(p[1] for p in pts)
    y1 = max(p[1] for p in pts)
    w, h = max(x1 - x0, 1e-6), max(y1 - y0, 1e-6)
    k = min((TILE_W - 12) / w, (TILE_H - 12) / h)
    ctx.save()
    ctx.translate(ox + TILE_W / 2, oy + TILE_H / 2)
    ctx.scale(k, k)
    ctx.translate(-(x0 + x1) / 2, -(y0 + y1) / 2)
    for path in paths:
        if not path.points:
            continue
        r, g, b = path.color
        ctx.set_source_rgb(r / 255, g / 255, b / 255)
        ctx.move_to(*path.points[0])
        for x, y in path.points[1:]:
            ctx.line_to(x, y)
        ctx.close_path()
        ctx.fill()
    ctx.restore()


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--stage", required=True, choices=sorted(STAGE_ID))
    ap.add_argument("--screen")
    ap.add_argument("--port", default="amiga", choices=["amiga", "msdos"])
    ap.add_argument("--list", action="store_true",
                    help="screens with still-numbered layers, most first")
    ap.add_argument("--out", type=Path)
    args = ap.parse_args()

    lines = S.load(args.port, args.stage)
    if lines is None:
        raise SystemExit(f"no {args.port}/{args.stage}")
    ph = B.phases(lines)
    text = "\n".join(lines)
    equ = {n: int(v, 16) for n, v in RE_EQU.findall(text)}

    if args.list:
        rows = []
        for lab, seq in ph.items():
            m = B.RE_ENTRY.match(lab)
            n = sum(1 for c in dict.fromkeys(seq) if B.RE_NUM.match(c))
            if n:
                rows.append((n, m.group(2), lab, len(set(seq))))
        for n, scr, lab, tot in sorted(rows, reverse=True):
            print(f"  screen 0x{scr}  {n:>3} still numbered of {tot:>3}  {lab}")
        print(f"\n  {len(rows)} screen(s) with unnamed layers in "
              f"{args.port}/{args.stage}")
        return 0

    if not args.screen:
        raise SystemExit("give --screen NN, or --list")
    want = args.screen.upper()
    hit = [(lab, seq) for lab, seq in ph.items()
           if B.RE_ENTRY.match(lab).group(2) == want]
    if not hit:
        raise SystemExit(f"no screen 0x{want} in {args.port}/{args.stage}")
    lab, seq = hit[0]
    layers = list(dict.fromkeys(seq))

    bank = slab("cinematic", args.port, STAGE_ID[args.stage])
    cols = min(5, max(1, math.ceil(math.sqrt(len(layers)))))
    rows_n = math.ceil(len(layers) / cols)
    W = cols * (TILE_W + PAD) + PAD
    H = rows_n * (TILE_H + CAPTION + PAD) + PAD + 24
    surf = cairo.ImageSurface(cairo.FORMAT_ARGB32, W, H)
    ctx = cairo.Context(surf)
    ctx.set_source_rgb(0.09, 0.09, 0.10)
    ctx.paint()
    ctx.select_font_face("monospace")
    ctx.set_font_size(12)
    ctx.set_source_rgb(0.8, 0.8, 0.85)
    ctx.move_to(PAD, 16)
    ctx.show_text(f"{args.port}/{args.stage} screen 0x{want} -- {lab} -- "
                  f"{len(layers)} layer(s), in paint order")

    for i, const in enumerate(layers):
        cx = PAD + (i % cols) * (TILE_W + PAD)
        cy = 24 + PAD + (i // cols) * (TILE_H + CAPTION + PAD)
        ctx.set_source_rgb(0.16, 0.16, 0.18)
        ctx.rectangle(cx, cy, TILE_W, TILE_H)
        ctx.fill()
        if const not in equ:
            continue
        paths = paths_for(bank, equ[const])
        draw_tile(ctx, paths, cx, cy)
        pts = [p for pa in paths for p in pa.points]
        ext = (f"{max(p[0] for p in pts) - min(p[0] for p in pts):.0f}x"
               f"{max(p[1] for p in pts) - min(p[1] for p in pts):.0f}"
               if pts else "-")
        named = not B.RE_NUM.match(const)
        ctx.set_source_rgb(*(0.45, 0.65, 0.45) if named else (0.9, 0.8, 0.4))
        ctx.set_font_size(11)
        ctx.move_to(cx + 2, cy + TILE_H + 12)
        short = const.replace("CINEMATIC_", "")
        ctx.show_text(f"[{i}] {short[:26]}")
        ctx.move_to(cx + 2, cy + TILE_H + 23)
        ctx.set_source_rgb(0.55, 0.55, 0.6)
        ctx.show_text(f"    {ext}  {len(paths)} paths"
                      f"{'  (named)' if named else ''}")

    out = args.out or Path(f"/tmp/{args.port}_{args.stage}_{want}.png")
    surf.write_to_png(str(out))
    print(f"  {out}  {len(layers)} tile(s), {cols}x{rows_n}")
    for i, c in enumerate(layers):
        print(f"    [{i}] {c}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
