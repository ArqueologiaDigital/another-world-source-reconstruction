#!/usr/bin/env python3
"""Composite Another World INTRO polygon SVGs at their bytecode draw positions.

Question answered: "what does this scene look like once every `video offset=...,
x=, y=` in the routine is painted?"  Per-polygon SVGs are authored 320x200 with
the shape centred on (160,100), so drawing at (x,y) is translate(x-160, y-100).

Usage: compose_sheets45.py OUT.svg SVGDIR OFFSET:X:Y[:COLOR] ...
"""
import os, re, sys

out, svgdir = sys.argv[1], sys.argv[2]
parts = []
pal = ["#000000", "#d02020", "#2050d0", "#20a020", "#c0a000",
       "#a020a0", "#00a0a0", "#804000", "#ff8000", "#404040"]
for i, spec in enumerate(sys.argv[3:]):
    f = spec.split(":")
    off, x, y = f[0], int(f[1]), int(f[2])
    col = f[3] if len(f) > 3 else pal[i % len(pal)]
    if x > 32767:
        x -= 65536
    if y > 32767:
        y -= 65536
    src = None
    for kind in ("group", "solid"):
        p = f"{svgdir}/amiga_stage1_{kind}_0x{off}.svg"
        if os.path.exists(p):
            src = open(p).read()
            break
    if src is None:
        sys.exit(f"no SVG for 0x{off}")
    paths = [p for p in re.findall(r"<path[^>]*/>", src) if 'fill="#888888"' not in p]
    paths = [re.sub(r'fill="#000000"', f'fill="{col}"', p) for p in paths]
    parts.append(f'<g transform="translate({x-160},{y-100})">' + "".join(paths) + "</g>")

open(out, "w").write(
    '<?xml version="1.0" encoding="UTF-8"?>'
    '<svg xmlns="http://www.w3.org/2000/svg" width="320" height="200" viewBox="0 0 320 200">'
    '<rect width="320" height="200" fill="#c8c8c8"/>' + "".join(parts) + "</svg>")
print(out)
