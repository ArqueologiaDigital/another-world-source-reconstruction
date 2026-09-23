#!/usr/bin/env python3
"""The unnamed hero-slot pieces, rendered beside the named ones.

Question answered
-----------------
Of the 77 shared-bank keys still called `CV_<hex>`, nine are drawn at
`[HERO_X],[HERO_Y]` and so are the hero. Two of those are degenerate (0x1, a
single point). The other seven are 14..40 wide and 48..49 tall -- upright, by
`pose_height.py`'s measured 49.0 median for standing against 33.0 for a
crouch.

Every routine that draws them is a placeholder (`LABEL_<hex>`,
`DRAW_CV_279`), so `hero_pose_consensus.py` reports 0 of 9 with two stages
agreeing: there is no name anywhere to inherit. That leaves the art itself,
and the art is only readable against something known.

So this renders the seven unknowns in one grid together with named hero
pieces of comparable height, each captioned with its extent and leaf count.
A pose is identified by what it sits next to.

Signal being read
-----------------
The polygon tree at each key's offset in the shared video2 bank (resource
0x11), drawn at its own bounding box so a 7x18 piece and a 40x49 one are both
legible, with `polygon_render.synthetic_palette` for contrast between
neighbouring shapes rather than fidelity to any stage's palette.

Usage
-----
    python3 notes/shared-bank-geometry/unknown_vs_named_sheet.py
    python3 notes/shared-bank-geometry/unknown_vs_named_sheet.py --out /tmp/x.png
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
sys.path.insert(0, str(SRC / "notes" / "scene-reading"))

import cairo                                                 # noqa: E402
import polygon_render                                        # noqa: E402
from extent_matches_renderer import slab                     # noqa: E402
import contact_sheet as CS                                   # noqa: E402

RE_EQU = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s+(0x[0-9A-Fa-f]+)",
                    re.M)
RE_DRAW = re.compile(r"^\s*video\s+type=0,\s*offset=([A-Za-z_][A-Za-z0-9_]*),"
                     r"\s*x=([^,]+)")
RE_CV = re.compile(r"^CV_[0-9A-F]{4}$")
BRANCHES = ("chahi_amiga_1991", "dos_1992")
MIN_H, MAX_H = 40.0, 56.0          # the upright band, from pose_height.py


def hero_slot_pieces():
    """offset-name -> True for every shared-bank piece drawn at the hero."""
    out: dict[str, int] = {}
    for branch in BRANCHES:
        for f in sorted((SRC / "src" / "levels" / branch).glob("[A-Z]*.asm")):
            text = f.read_text(errors="replace")
            equ = {n: int(v, 16) for n, v in RE_EQU.findall(text)}
            for line in text.splitlines():
                if m := RE_DRAW.match(line):
                    name, x = m.group(1), m.group(2)
                    if "HERO_X" in x and name in equ:
                        out[name] = equ[name]
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", type=Path,
                    default=Path("/tmp/hero_unknowns.png"))
    args = ap.parse_args()

    bank = slab("video2", "amiga", 0)
    pieces = hero_slot_pieces()

    def measure(off):
        r = polygon_render.Renderer(bank,
                                    polygon_render.synthetic_palette())
        r.render(off, color=0xFF, zoom=polygon_render.DEFAULT_ZOOM)
        pts = [p for path in r.paths for p in path.points]
        if not pts:
            return r.paths, 0.0, 0.0
        return (r.paths,
                max(p[0] for p in pts) - min(p[0] for p in pts),
                max(p[1] for p in pts) - min(p[1] for p in pts))

    unknown, named = [], []
    for name, off in sorted(pieces.items()):
        paths, w, h = measure(off)
        if not paths:
            continue
        if RE_CV.match(name):
            if h >= 2.0:
                unknown.append((name, paths, w, h))
        elif MIN_H <= h <= MAX_H:
            named.append((name, paths, w, h))

    named.sort(key=lambda r: r[0])
    step = max(1, len(named) // 12)
    shown = unknown + named[::step][:12]
    if not shown:
        print("nothing to draw", file=sys.stderr)
        return 1

    cols = 5
    rows_n = math.ceil(len(shown) / cols)
    W = cols * (CS.TILE_W + CS.PAD) + CS.PAD
    H = rows_n * (CS.TILE_H + CS.CAPTION + CS.PAD) + CS.PAD + 24
    surf = cairo.ImageSurface(cairo.FORMAT_ARGB32, W, H)
    ctx = cairo.Context(surf)
    ctx.set_source_rgb(0.09, 0.09, 0.10)
    ctx.paint()
    ctx.select_font_face("monospace")
    ctx.set_font_size(12)
    ctx.set_source_rgb(0.8, 0.8, 0.85)
    ctx.move_to(CS.PAD, 16)
    ctx.show_text(f"shared bank, hero slot -- {len(unknown)} unnamed "
                  f"(yellow) beside {len(shown) - len(unknown)} named "
                  f"(green) of comparable height")

    for i, (name, paths, w, h) in enumerate(shown):
        cx = CS.PAD + (i % cols) * (CS.TILE_W + CS.PAD)
        cy = 24 + CS.PAD + (i // cols) * (CS.TILE_H + CS.CAPTION + CS.PAD)
        ctx.set_source_rgb(0.16, 0.16, 0.18)
        ctx.rectangle(cx, cy, CS.TILE_W, CS.TILE_H)
        ctx.fill()
        CS.draw_tile(ctx, paths, cx, cy)
        is_cv = bool(RE_CV.match(name))
        ctx.set_source_rgb(*(0.9, 0.8, 0.4) if is_cv else (0.45, 0.7, 0.45))
        ctx.set_font_size(11)
        ctx.move_to(cx + 2, cy + CS.TILE_H + 12)
        ctx.show_text(f"[{i}] {name[:28]}")
        ctx.move_to(cx + 2, cy + CS.TILE_H + 23)
        ctx.set_source_rgb(0.55, 0.55, 0.6)
        ctx.show_text(f"    {w:.0f}x{h:.0f}  {len(paths)} paths")

    surf.write_to_png(str(args.out))
    print(f"  {args.out}  {len(unknown)} unnamed, "
          f"{len(shown) - len(unknown)} named references")
    for i, (n, _p, w, h) in enumerate(shown):
        print(f"    [{i}] {n:<34}{w:.0f}x{h:.0f}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
