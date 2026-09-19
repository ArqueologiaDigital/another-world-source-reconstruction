#!/usr/bin/env python3
"""Render a stage's background BITMAP, which the polygon tooling never sees.

Question answered
-----------------
`notes/render-attempts/` measured why the remaining polygon runs will not
resolve: of the ten largest exclusive unnamed runs left in the big three,
**eight have no semantically-named routine anywhere in their setup block**.
Both runs that did resolve had one, and the neighbour is what named them.

So the blocker is unnamed *scenes*. And a scene's identity is frequently not
in the polygon bank at all. amiga/CAPSULE's `LABEL_7F7E` sets a palette,
calls `LOAD_RES90_COPY_PAGE0_TO_3_LOAD_RES91`, and installs eleven channels
whose art is 13x24 to 71x68 -- small animated elements and no backdrop
anywhere. The backdrop is resource 0x90/0x91: 32,000 bytes each, which is
320x200 at 4 bits per pixel, a full-screen image. Every polygon probe in
this tree is blind to it.

Rendering 0x91 shows a vaulted hall with columns, draped arches, coloured
ceiling panels and a blue pool -- the baths, a location this project already
names in TANK (`TANK_ARENA_EXIT_CAPSULES_RISE_TO_BATHS`).

What it does
------------
Extracts resources with `banks2resources` if they are not already extracted,
then decodes one as an Another World bitmap and writes a PPM.

The format, recorded because the numbers are the check: four bitplanes of
8,000 bytes, stored one after another. Row `y`, byte column `xb`, bit `i`
contributes bit `p` of the pixel from plane `p` at `p*8000 + y*40 + xb`, most
significant bit leftmost. 320*200/8 = 8,000 per plane, 32,000 total, and a
resource of any other size is not a bitmap.

Palettes come from `palettes.rom`: 32 palettes of 16 big-endian words, each
`0x0RGB` with four bits a channel, scaled by 17 to fill a byte. The palette
number is the one the scene's `setPalette` gives -- rendering with the wrong
one produces a legible picture in the wrong colours, which is worse than no
picture.

Usage
-----
    python3 notes/scene-backdrops/render_backdrop.py --resource 0x91 \
        --palette 1 --out /tmp/baths.ppm

    # which resources are full-screen bitmaps at all
    python3 notes/scene-backdrops/render_backdrop.py --list
"""

from __future__ import annotations

import argparse
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ARCH = ROOT.parent / "another-world-archaeology"
BANKS = ARCH / "extract" / "aworld" / "aworld"
TOOLS = ROOT.parent / "AnotherWorld_VMTools" / "target" / "release"
BITMAP_SIZE = 32000
W, H = 320, 200


def ensure_resources(out_dir: Path) -> Path:
    res = out_dir / "resources"
    if res.is_dir() and any(res.glob("resource-0x*.bin")):
        return res
    out_dir.mkdir(parents=True, exist_ok=True)
    exe = TOOLS / "banks2resources"
    if not exe.is_file():
        print(f"{exe} missing -- cargo build --release --bin banks2resources",
              file=sys.stderr)
        sys.exit(2)
    subprocess.run([str(exe), str(BANKS), str(out_dir)],
                   check=True, stdout=subprocess.DEVNULL)
    return res


def palette(n: int) -> list[tuple[int, int, int]]:
    raw = (ARCH / "tmp" / "output" / "amiga" / "romset" / "palettes.rom").read_bytes()
    out = []
    for i in range(16):
        w = struct.unpack(">H", raw[n * 32 + i * 2:n * 32 + i * 2 + 2])[0]
        out.append((((w >> 8) & 0xF) * 17, ((w >> 4) & 0xF) * 17, (w & 0xF) * 17))
    return out


def decode(data: bytes, pal: list) -> bytes:
    px = bytearray(W * H * 3)
    for y in range(H):
        for xb in range(40):
            base = y * 40 + xb
            b = (data[base], data[8000 + base],
                 data[16000 + base], data[24000 + base])
            for bit in range(8):
                s = 7 - bit
                idx = ((b[0] >> s) & 1) | (((b[1] >> s) & 1) << 1) \
                    | (((b[2] >> s) & 1) << 2) | (((b[3] >> s) & 1) << 3)
                r, g, bl = pal[idx]
                o = (y * W + xb * 8 + bit) * 3
                px[o], px[o + 1], px[o + 2] = r, g, bl
    return bytes(px)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--resource")
    ap.add_argument("--palette", type=int, default=0)
    ap.add_argument("--out", type=Path)
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--work", type=Path,
                    default=Path("/tmp/aw-resources"))
    args = ap.parse_args()

    res = ensure_resources(args.work)
    if args.list:
        found = sorted(f for f in res.glob("resource-0x*.bin")
                       if f.stat().st_size == BITMAP_SIZE)
        print(f"{len(found)} resource(s) are {BITMAP_SIZE} bytes, i.e. "
              f"full-screen 320x200 4bpp bitmaps:\n")
        print("  " + " ".join(f.stem.split("-")[1] for f in found))
        return 0
    if not args.resource or not args.out:
        print("--resource and --out are required unless --list",
              file=sys.stderr)
        return 2
    f = res / f"resource-{args.resource}.bin"
    data = f.read_bytes()
    if len(data) != BITMAP_SIZE:
        print(f"{f.name} is {len(data)} bytes, not a bitmap", file=sys.stderr)
        return 1
    args.out.write_bytes(b"P6\n%d %d\n255\n" % (W, H)
                         + decode(data, palette(args.palette)))
    print(f"wrote {args.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
