#!/usr/bin/env python3
"""What are these constants, measured? Offset, extent, leaf count, hash, colour.

Question answered
-----------------
Nearly every proposal table in `notes/` quotes the same four or five numbers per
constant: its offset, its bounding box, how many leaves its polygon tree has, its
`canonical_md5`, and often the palette indices its polygons ask for. Those
numbers decided the names.

They were produced, over and over, by hand-written six-line calls to
`polygon_tree.parse_polygon_tree` and `polygon_extent.extent` -- the same call
retyped a dozen times in one session, each time in a shell heredoc that vanished.
The library was always committed; the *invocation* never was, so a table's
numbers could be reproduced only by someone who knew to write the call. This is
that call, written once.

It settles a class of scratch script rather than a single one: bbox.py, bbox2.py,
bbox.mjs, leaves.py, leafcheck.py and poly.mjs were six attempts at exactly this
during one naming pass.

Signal read
-----------
  * `NAME EQU 0xHHHH` from `src/levels/<branch>/<STAGE>.asm` -- so a constant can
    be given by name, which is what a table cites;
  * the stage's own 64 KiB slab of `cinematic.rom`, or `video2.rom` whole for a
    `CV_*` key, which is how the two banks differ;
  * `polygon_extent.extent`, which returns [minx, miny, maxx, maxy, leafcount];
  * `polygon_tree.canonical_md5`, the project's cross-port art identity;
  * `--colours` adds the palette indices, through the JS renderer via
    `notes/beam-span-ladder/colour_of.mjs`, because that is where the colour
    logic is already checked against MAME.

The box is printed as x[min,max] y[min,max] as well as WxH, because whether a
layer sits above or below its anchor has decided several names this project got
wrong the first time -- an arm that reaches below the feet is not an arm.

Run it
    python3 notes/measure_constants.py --branch dos_1992 --stage PRISON \\
        CINEMATIC_240 CINEMATIC_168
    python3 notes/measure_constants.py --branch dos_1992 --stage PRISON \\
        --pattern 'CINEMATIC_PRISON_BUDDY_ARM_.*'
    ... --port msdos        which romset to read (default: from the branch)
    ... --colours           also print each polygon's palette index
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ARCH = ROOT.parent / "another-world-archaeology"
sys.path.insert(0, str(ARCH / "tools"))

STAGE_ID = {"CODE_WHEEL": 0, "INTRO": 1, "LAKE": 2, "PRISON": 3, "CAVES": 4,
            "TANK": 5, "CAPSULE": 6, "ENDING": 7, "PASSCODE": 8}
BRANCH_PORT = {"chahi_amiga_1991": "amiga", "dos_1992": "msdos",
               "cartridge_1992": "genesis_europe", "gba_2004": "gba_usa"}
RE_EQU = re.compile(r"^(\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)\s*$", re.M)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--branch", default="dos_1992")
    ap.add_argument("--stage", required=True)
    ap.add_argument("--port")
    ap.add_argument("--pattern", help="a regex over EQU names, instead of a list")
    ap.add_argument("--colours", action="store_true")
    ap.add_argument("names", nargs="*")
    a = ap.parse_args()

    asm = ROOT / "src" / "levels" / a.branch / f"{a.stage}.asm"
    if not asm.is_file():
        print(f"no {asm}", file=sys.stderr)
        return 2
    equ = dict(RE_EQU.findall(asm.read_text(errors="replace")))

    names = list(a.names)
    if a.pattern:
        rx = re.compile(a.pattern)
        names += sorted(n for n in equ if rx.fullmatch(n))
    if not names:
        print("give constant names, or --pattern", file=sys.stderr)
        return 2

    port = a.port or BRANCH_PORT.get(a.branch)
    romset = ARCH / "tmp" / "output" / str(port) / "romset"
    try:
        from polygon_tree import parse_polygon_tree, canonical_md5
        from polygon_extent import extent
    except ImportError as e:
        print(f"need {ARCH}/tools on the path: {e}", file=sys.stderr)
        return 2

    lvl = STAGE_ID.get(a.stage)
    cine = romset / "cinematic.rom"
    vid2 = romset / "video2.rom"
    if not cine.is_file():
        print(f"no {cine} -- is this port extracted? (#0106 for cartridge)",
              file=sys.stderr)
        return 2
    slab = cine.read_bytes()[lvl * 0x10000:(lvl + 1) * 0x10000]
    bank = vid2.read_bytes() if vid2.is_file() else b""

    print(f"{a.branch}/{a.stage} ({port})")
    print(f"  {'constant':<44} {'offset':<8} box                      "
          f"{'WxH':<14} leaves  canonical_md5")
    for n in names:
        if n not in equ:
            print(f"  {n:<44} no EQU in this stage")
            continue
        off = int(equ[n], 16)
        data = bank if n.startswith("CV_") else slab
        try:
            t = parse_polygon_tree(data, off)
            e = extent(t)
            h = canonical_md5(t)[:12]
        except Exception as exc:                                  # noqa: BLE001
            print(f"  {n:<44} 0x{off:04X}   unreadable: {exc}")
            continue
        box = f"x[{e[0]:6.1f},{e[2]:6.1f}] y[{e[1]:6.1f},{e[3]:6.1f}]"
        print(f"  {n:<44} 0x{off:04X}   {box}  "
              f"{e[2]-e[0]:6.1f}x{e[3]-e[1]:<6.1f} {e[4]:5d}   {h}")

    if a.colours:
        print("\n  colours (palette indices, via notes/beam-span-ladder/"
              "colour_of.mjs):")
        import subprocess
        cmd = ["node", str(ROOT / "notes/beam-span-ladder/colour_of.mjs"),
               "--romset", str(romset), "--level", str(lvl),
               "--branch", a.branch, "--stage", a.stage] + names
        r = subprocess.run(cmd, capture_output=True, text=True)
        for line in (r.stdout or r.stderr).splitlines():
            print("  " + line)
    return 0


if __name__ == "__main__":
    sys.exit(main())
