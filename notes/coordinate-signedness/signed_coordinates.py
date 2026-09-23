#!/usr/bin/env python3
"""Are `video` x and y signed? The distribution answers it without an engine.

Question answered
-----------------
`CINEMATIC_112` in amiga/INTRO is drawn five times at `y=65527, 65530, 65529,
65531, 65534`, and the whole reading of the picture turns on what those mean.
The toolchain is self-consistent and unhelpful: `awvm/src/disasm.rs:686-692`
reads the two bytes into a `u32` and prints that decimal, and
`awvm/src/polygons.rs:180` parses it straight back, so awvm draws at
`y = 65527.0` -- far below a 200-line page. A `int16_t` engine would read -9
and put the mark just above the top edge. Opposite places, same bytes.

The bytecode settles it by itself, without deciding how any engine is written.
If these operands were **unsigned**, the values above 0x8000 would be scattered
through the 0x8000..0xFFFF range like any other garbage-looking-but-intended
coordinate. If they are **signed**, they must all cluster just below 0x10000,
because a signed coordinate a little off the edge of a 320x200 page is a small
negative number and nothing else.

So: collect every literal `video` x and y in every branch's `.asm`, and look at
where the large ones fall.

Result, 2026-09-23
------------------
    14668 literal y operands; 75 are >= 0x8000, in 17 distinct values
    every one of them between 65456 and 65535  =  -80 to -1 signed
    largest y below 0x8000: 400

Not one value anywhere else in the 32,768-wide range above 0x8000. The ordinary
y range is 0..400 and the "large" values fill -80..-1, which together make one
contiguous band around a 200-line page with margins. Unsigned, the game would
be placing 75 draws between 65,456 and 65,535 pixels below the screen and
nowhere else. **The operands are signed**, and a listing that prints 65527 is
printing -9.

Run it
------
    python3 notes/coordinate-signedness/signed_coordinates.py
    python3 notes/coordinate-signedness/signed_coordinates.py --axis x
    python3 notes/coordinate-signedness/signed_coordinates.py --sites   # which constants

Reads only `src/levels/<branch>/*.asm`; no romset needed.
"""
from __future__ import annotations

import argparse
import collections
import pathlib
import re

SRC = pathlib.Path(__file__).resolve().parents[2] / "src" / "levels"
RE_DRAW = re.compile(
    r"video offset=(\S+?), x=(-?\d+|\[[^\]]+\]), y=(-?\d+|\[[^\]]+\])")


def scan(axis: str):
    vals = collections.Counter()
    sites: dict[int, list[str]] = collections.defaultdict(list)
    total = 0
    for f in sorted(SRC.rglob("*.asm")):
        if "_unified" in str(f):
            continue
        branch = f.parent.name
        for const, x, y in RE_DRAW.findall(f.read_text()):
            raw = x if axis == "x" else y
            if raw.startswith("["):
                continue
            total += 1
            v = int(raw)
            vals[v] += 1
            if v >= 0x8000:
                sites[v].append(f"{branch}/{f.stem} {const}")
    return total, vals, sites


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--axis", default="y", choices=["x", "y"])
    ap.add_argument("--sites", action="store_true",
                    help="list the constants drawn at each large value")
    args = ap.parse_args()

    total, vals, sites = scan(args.axis)
    big = {v: c for v, c in vals.items() if v >= 0x8000}
    small = [v for v in vals if v < 0x8000]

    print(f"  {total} literal {args.axis} operand(s) across every branch .asm")
    print(f"  {sum(big.values())} are >= 0x8000, in {len(big)} distinct value(s)\n")
    if not big:
        print("  nothing above 0x8000 on this axis; the question does not arise")
        return 0

    lo, hi = min(big), max(big)
    print(f"  value           as signed   count")
    for v in sorted(big):
        print(f"      {v:>6}      {v - 0x10000:>6}      x{big[v]}")
        if args.sites:
            for s in sorted(set(sites[v])):
                print(f"            {s}")
    print(f"\n  range above 0x8000: {lo}..{hi}  =  {lo - 0x10000}..{hi - 0x10000} signed")
    print(f"  that is {hi - lo + 1} wide inside a {0x10000 - 0x8000}-wide space")
    print(f"  ordinary range below 0x8000: {min(small)}..{max(small)}")
    print()
    if hi - lo < 512 and hi == 0xFFFF or hi >= 0xFF00:
        print("  Every large value sits just below 0x10000 and none anywhere else,")
        print("  which is what SIGNED operands look like and is not what unsigned")
        print("  ones look like. A listing printing 65527 is printing -9.")
    else:
        print("  The large values are spread, which does NOT fit the signed reading.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
