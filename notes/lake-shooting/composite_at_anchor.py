#!/usr/bin/env python3
"""Draw several polygons the way the bytecode draws them: at one shared anchor.

Question answered
-----------------
`awvm-render-polygons` emits one SVG per offset, each trimmed to its own art.
That is the right default, and it is why two passes over LAKE misread the same
group: when the bytecode draws two pictures at the SAME x,y in the same frame,
looking at them side by side shows two objects where the screen shows one.

    DECOR_AT_305_155_F14_F9_BG:
        video offset=CINEMATIC_LAKE_REED,                x=[0x32], y=[0x33]
        video offset=CINEMATIC_DECOR_AT_305_155_F9,      x=[0x32], y=[0x33]

Rendered apart, that is "a tall solid bar" and "a small angular shape beside a
vertical line". Rendered at the shared anchor it is one thing, and the note in
`../lake-decor-split/` shows what guessing from the separate views costs.

How
---
Rasterises the expanded polygon tree directly, with each point placed at its
true anchor-relative coordinate -- the same arithmetic `polygon_extent.extent`
walks, so a picture lands here exactly where that probe says it lands. No
trimming, no per-picture normalisation: the canvas is the union of the boxes,
and every layer keeps its offset within it.

Signal being read
-----------------
Solid leaves only; a group contributes its children. Colour is ignored and
every leaf is filled flat, because the question these renders answer is what
shape is drawn where, and the palette is a separate question. `--stack`
overlays in the order given (later on top, as the VM does); the default puts
each layer in its own panel at a common origin so the alignment is visible.

Usage
-----
    python3 notes/lake-shooting/composite_at_anchor.py \
        --port amiga --stage 2 \
        --stack CINEMATIC_LAKE_REED CINEMATIC_DECOR_AT_305_155_F9 \
        --out /tmp/reed_f9.png

    python3 notes/lake-shooting/composite_at_anchor.py --port amiga --stage 2 \
        --under CINEMATIC_LAKE_REED \
        --frames CINEMATIC_DECOR_AT_305_155_F9 CINEMATIC_DECOR_AT_305_155_F10 \
        --out /tmp/strip.png
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

from PIL import Image, ImageDraw

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
sys.path.insert(0, str(SRC.parent / "another-world-archaeology" / "tools"))
sys.path.insert(0, str(SRC / "notes" / "polygon-extent-correction"))
from polygon_tree import parse_polygon_tree            # noqa: E402
from extent_matches_renderer import slab               # noqa: E402
from polygon_extent import extent                      # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGES = {"CODE_WHEEL": 0, "INTRO": 1, "LAKE": 2, "PRISON": 3, "CAVES": 4,
          "TANK": 5, "CAPSULE": 6, "ENDING": 7, "PASSCODE": 8}
RE_EQU = re.compile(r"^(\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)


def polys(tree, ox=0.0, oy=0.0, out=None):
    """Every solid leaf as an anchor-relative point list.

    Mirrors `polygon_extent.extent`: a solid's two size bytes are halved, a
    group's are subtracted whole.
    """
    if out is None:
        out = []
    if tree is None:
        return out
    if tree[0] == "solid":
        w, h, pts = tree[1], tree[2], tree[3]
        out.append([(ox - w / 2 + px, oy - h / 2 + py) for px, py in pts])
    elif tree[0] == "group":
        w, h, ch = tree[1], tree[2], tree[3]
        for px, py, _col, sub in ch:
            polys(sub, ox - w + px, oy - h + py, out)
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", default="amiga", choices=sorted(PORTS))
    ap.add_argument("--stage", default="LAKE", choices=sorted(STAGES))
    ap.add_argument("--stack", nargs="*", default=[],
                    help="names overlaid into ONE image, later on top")
    ap.add_argument("--under", help="drawn beneath every --frames panel")
    ap.add_argument("--frames", nargs="*", default=[],
                    help="one panel each, all at the same origin")
    ap.add_argument("--scale", type=int, default=4)
    ap.add_argument("--out", type=Path, required=True)
    args = ap.parse_args()

    stage = STAGES[args.stage]
    text = (SRC / "src" / "levels" / PORTS[args.port]
            / f"{args.stage}.asm").read_text(errors="replace")
    table = {n: int(v, 16) for n, v in RE_EQU.findall(text)}
    bank = slab("cinematic", args.port, stage)

    def tree(name):
        if name not in table:
            raise SystemExit(f"{name} is not defined in {args.port}/{args.stage}")
        return parse_polygon_tree(bank, table[name])

    groups = ([args.stack] if args.stack else
              [([args.under] if args.under else []) + [f] for f in args.frames])
    if not groups:
        raise SystemExit("give --stack or --frames")

    # One coordinate frame for every panel, so alignment is readable.
    box = [1e9, 1e9, -1e9, -1e9]
    for g in groups:
        for name in g:
            x0, y0, x1, y1, _ = extent(tree(name))
            box = [min(box[0], x0), min(box[1], y0),
                   max(box[2], x1), max(box[3], y1)]
    s = args.scale
    w = int((box[2] - box[0]) * s) + 2 * s
    h = int((box[3] - box[1]) * s) + 2 * s

    panels = []
    for g in groups:
        img = Image.new("RGB", (w, h), (150, 150, 150))
        d = ImageDraw.Draw(img)
        for i, name in enumerate(g):
            shade = (40, 40, 40) if i == 0 and len(g) > 1 else (0, 0, 0)
            for pts in polys(tree(name)):
                d.polygon([((x - box[0]) * s + s, (y - box[1]) * s + s)
                           for x, y in pts], fill=shade)
        panels.append(img)

    out = Image.new("RGB", (w * len(panels) + 4 * (len(panels) - 1), h),
                    (17, 17, 17))
    for i, p in enumerate(panels):
        out.paste(p, (i * (w + 4), 0))
    args.out.parent.mkdir(parents=True, exist_ok=True)
    out.save(args.out)
    print(f"{args.out}  {out.size[0]}x{out.size[1]}  "
          f"{len(panels)} panel(s), anchor-relative box "
          f"({box[0]:.1f},{box[1]:.1f})..({box[2]:.1f},{box[3]:.1f})")
    return 0


if __name__ == "__main__":
    sys.exit(main())
