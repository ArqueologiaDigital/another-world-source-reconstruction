#!/usr/bin/env python3
"""Lay polygons out where they were authored, not where the renderer puts them.

Question answered
-----------------
`awvm-render-polygons` writes one SVG per polygon on a 320x200 canvas, but it
**normalises each one to the draw anchor**: `CINEMATIC_016` in PASSCODE is
authored at x 126..154 and comes out at x 156..179, centred on (160,100) like
every other polygon in the bank. The authored offset -- which is the only thing
distinguishing a set of polygons drawn at one anchor -- is discarded.

That is why `render_scene_composite.py` could not settle PASSCODE's seventeen
glyph constants: handed all seventeen at the shared anchor (114,62) it stacks
them into a single 23x7 blob and reports "17 draw(s) composited". The blob is
not a picture of anything.

`another-world-archaeology/tools/polygon_extent.py` does read the polygon
records' own coordinates. This bridges the two: it takes each polygon's
rendered SVG, trims it to its ink, and pastes it at the box `polygon_extent`
reports -- reconstructing the layout the game actually draws.

What it is for
--------------
Any set of polygons drawn at ONE anchor whose separation is baked into their
own coordinates. PASSCODE's code strings are the case it was written for; the
same shape of problem appears wherever a routine draws several constants at a
fixed `x=`/`y=` and the constants are not simply successive frames.

It is NOT for polygons drawn at moving anchors -- there the caller's
coordinates matter and `render_scene_composite.py` is the right tool.

Usage
-----
    python3 notes/passcode-glyph-probes/compose_at_authored_coords.py \
        --stage 8 --port amiga --svg-dir /tmp/pc --out /tmp/layout.png \
        --equ CINEMATIC_016 CINEMATIC_015 ...

    # or every constant in a numeric range
    python3 notes/passcode-glyph-probes/compose_at_authored_coords.py \
        --stage 8 --port amiga --svg-dir /tmp/pc --out /tmp/layout.png \
        --range 0 16
"""
from __future__ import annotations

import argparse
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ARCH = ROOT.parent / "another-world-archaeology"
STAGE_ASM = {0: "CODE_WHEEL", 1: "INTRO", 2: "LAKE", 3: "PRISON", 4: "CAVES",
             5: "TANK", 6: "CAPSULE", 7: "ENDING", 8: "PASSCODE"}
PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
RE_EXT = re.compile(r"^\s*(0x[0-9A-F]+)\s+(\d+)x(\d+)\s+(\d+) leaf.*?"
                    r"x (\d+)\.\.(\d+)\s+y (\d+)\.\.(\d+)")


def equ_offset(stage: int, port: str, name: str) -> int | None:
    f = ROOT / "src" / "levels" / PORTS[port] / f"{STAGE_ASM[stage]}.asm"
    m = re.search(rf"^{re.escape(name)}\s+EQU\s+(0x[0-9A-Fa-f]+)",
                  f.read_text(errors="replace"), re.M)
    return int(m.group(1), 16) if m else None


def extents(stage: int, port: str, offs: list[int]) -> dict[int, tuple]:
    out = subprocess.run(
        ["python3", "tools/polygon_extent.py", "--stage", str(stage),
         "--port", port, "--offsets", *[f"0x{o:04X}" for o in offs]],
        cwd=ARCH, capture_output=True, text=True).stdout
    res = {}
    for line in out.splitlines():
        m = RE_EXT.match(line)
        if m:
            res[int(m.group(1), 16)] = (int(m.group(5)), int(m.group(7)),
                                        int(m.group(2)), int(m.group(3)))
    return res


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--stage", type=int, required=True)
    ap.add_argument("--port", default="amiga", choices=sorted(PORTS))
    ap.add_argument("--svg-dir", required=True, type=Path)
    ap.add_argument("--out", required=True, type=Path)
    ap.add_argument("--equ", nargs="*", default=[])
    ap.add_argument("--range", nargs=2, type=int)
    ap.add_argument("--scale", type=int, default=6)
    args = ap.parse_args()

    names = list(args.equ)
    if args.range:
        names += [f"CINEMATIC_{n:03d}"
                  for n in range(args.range[0], args.range[1] + 1)]
    if not names:
        print("nothing to compose")
        return 2

    pairs = [(n, equ_offset(args.stage, args.port, n)) for n in names]
    missing = [n for n, o in pairs if o is None]
    if missing:
        print("no EQU for: " + ", ".join(missing))
        return 1
    ext = extents(args.stage, args.port, [o for _n, o in pairs])

    cmd = ["magick", "-size", "320x200", "xc:#606060"]
    placed = 0
    for n, off in pairs:
        if off not in ext:
            print(f"  {n} 0x{off:04X}: no extent reported, skipped")
            continue
        x, y, _w, _h = ext[off]
        svg = list(args.svg_dir.glob(f"*_0x{off:04X}.svg"))
        if not svg:
            print(f"  {n} 0x{off:04X}: no SVG in {args.svg_dir}, skipped")
            continue
        cmd += ["(", "-background", "none", "-density", "300", str(svg[0]),
                "-resize", "320x200!", "-trim", "+repage", ")",
                "-geometry", f"+{x}+{y}", "-composite"]
        placed += 1
    cmd += ["-filter", "point", "-resize", f"{args.scale * 100}%",
            str(args.out)]
    subprocess.run(cmd, check=True)
    print(f"{placed} polygon(s) placed at their AUTHORED coordinates -> "
          f"{args.out}")
    print("Unlike render_scene_composite.py these do not stack: each sits "
          "where the\npolygon record puts it, which is the only thing "
          "separating a set drawn at one\nanchor.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
