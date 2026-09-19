#!/usr/bin/env python3
"""A name is on both ports. Do the two ports draw the same picture?

Question answered
-----------------
#0107 forbids carrying a name from one port's symbol to another's, because
indices are per-port encounter order. Many names are nonetheless defined on
both ports -- propagated by tools that align instruction streams, or applied
to both deliberately. Nothing has ever checked that the two definitions point
at the same art, and the byte gate cannot: a name is not a byte.

This checks it, by rendering.

Why rendering, and not the resource bytes
-----------------------------------------
The obvious test -- read each port's polygon EQU offset, seek into that
stage's cinematic resource, compare the bytes -- **does not work**, and this
probe originally did exactly that and reported 968 names as pointing at
different art. That result was wrong. The offsets index the stage slab the
renderer assembles, not the layout of the standalone `resource-0x??.bin`
dump, so the comparison reads unrelated bytes for most stages. It happened to
agree for TANK, which is what made it look sound.

The refutation was one render: amiga's `CINEMATIC_BACKGROUND_BEAST_BODY` at
0x73F6 and msdos's at 0x5FE6 come out as the same beast, pixel for pixel.

So the comparator is the renderer's own output. Two SVGs for the same art are
byte-identical once the port name is normalised out -- same path data, same
coordinates, same colours -- which makes this exact rather than a similarity
score.

Preparing the input
-------------------
Per stage, render both ports once (stage numbers: CODE_WHEEL 0, INTRO 1,
LAKE 2, PRISON 3, CAVES 4, TANK 5, CAPSULE 6, ENDING 7, PASSCODE 8):

    cd another-world-archaeology
    R=~/compartilhado/AnotherWorld_VMTools/target/release/awvm-render-polygons
    for p in amiga msdos; do
      $R --port $p --stage 2 --romset tmp/output/$p/romset \
         --bank cinematic --out /tmp/art/$p/LAKE --palette 5
    done

then point this at `/tmp/art`. Renders are a large regenerable corpus and are
not committed; this recipe is.

Found 2026-09-19, and NOT resolved
----------------------------------
LAKE: 668 names defined on both ports, **651 render identically, 17 differ**.
TANK: 48 of 48 identical, which independently confirms that day's dome names.

The 17 are all hero locomotion -- `CINEMATIC_HERO_RUN_LEFT_*`,
`_WALK_RIGHT_*`, `_STOP_*`. On amiga each renders as a striding human figure,
6 to 10 paths, orange hair and grey trousers. On msdos the same name renders
as a single featureless brown slab: 1 path, and the offsets sit 10 bytes apart
in 0xDFF2..0xE09C, the last ~170 bytes of a 0xE0A6-byte bank.

Three things are known and one is not:

  * the names predate this session -- `git log -S` puts them before the
    2026-09-19 walk/run re-base, which only renamed four of them;
  * amiga's hero art has **no matching render anywhere** in msdos's LAKE bank,
    so msdos is not simply holding it at another offset;
  * msdos does draw a hero, and the shared video2 bank holds lower-body poses
    (`CV_FIGURE_*`) drawn as overlays after a sprite dispatcher.

What is not known is whether msdos composes its hero differently -- shared
lower body plus a small per-stage piece, which those 10-byte records could
be -- or whether 17 msdos names are simply on the wrong constants. **Nothing
was renamed.** Settling it needs someone who knows the engine's sprite
composition, and a wrong name is worse than a number in both directions.

Exit status
-----------
1 if any name defined on both ports renders differently, 0 otherwise, 2 if
the renders are missing.

Usage
-----
    python3 notes/shared-bank-naming/crossport_art_identity.py \
        --svg-root /tmp/art --stage LAKE --stage TANK
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels"
PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]
RE_EQU = re.compile(r"^(CINEMATIC_[A-Za-z0-9_]+)\s+EQU\s+(0x[0-9A-Fa-f]+)")
RE_NUMERIC = re.compile(r"^CINEMATIC_\d+$")


def equs(port: str, stage: str) -> dict[str, int]:
    f = SRC / PORTS[port] / f"{stage}.asm"
    out: dict[str, int] = {}
    if f.is_file():
        for line in f.read_text(errors="replace").splitlines():
            m = RE_EQU.match(line)
            if m:
                out[m.group(1)] = int(m.group(2), 16)
    return out


def svg(root: Path, port: str, stage: str, off: int) -> str | None:
    d = root / port / stage
    if not d.is_dir():
        return None
    for f in d.glob(f"*_0x{off:04X}.svg"):
        t = f.read_text(errors="replace")
        return t.replace(port, "PORT").replace(f"0x{off:04X}", "OFF")
    return None


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--svg-root", required=True, type=Path)
    ap.add_argument("--stage", action="append")
    args = ap.parse_args()
    stages = args.stage or STAGES

    if not args.svg_root.is_dir():
        print(f"no renders at {args.svg_root}; see this file's docstring")
        return 2

    bad = 0
    print(f"{'stage':<11}{'names on both':>15}{'same art':>10}"
          f"{'DIFFER':>8}{'not rendered':>14}")
    for stage in stages:
        ae, de = equs("amiga", stage), equs("msdos", stage)
        shared = [n for n in sorted(set(ae) & set(de))
                  if not RE_NUMERIC.match(n)]
        if not shared:
            continue
        same = diff = miss = 0
        worst = []
        for n in shared:
            sa = svg(args.svg_root, "amiga", stage, ae[n])
            sd = svg(args.svg_root, "msdos", stage, de[n])
            if sa is None or sd is None:
                miss += 1
                continue
            if sa == sd:
                same += 1
            else:
                diff += 1
                worst.append((n, ae[n], de[n]))
        bad += diff
        print(f"{stage:<11}{len(shared):>15}{same:>10}{diff:>8}{miss:>14}")
        for n, o1, o2 in worst[:5]:
            print(f"    DIFFER {n}  amiga 0x{o1:04X}  msdos 0x{o2:04X}")

    print("\n" + ("A NAME DEFINED ON BOTH PORTS RENDERS DIFFERENTLY -- one of "
                  "the two is wrong" if bad else
                  "Every name defined on both ports renders identically on "
                  "both."))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
