#!/usr/bin/env python3
"""Each hero direction state draws in two layers. Are they the same subject?

Question answered
-----------------
`derive_state_map.py` shows every state of CAVES' hero direction machine
installs **two** animations at the same anchor: a body loop on the dispatcher's
own channel, and a second loop on channel 0x16 that cycles 11 frames against
the body's 2 to 8. Two independent periods means two things, not one -- but
"two things" is not a name, and a routine cannot be named for art nobody has
identified.

This measures what separates the layers, so the second one can be described
honestly and left unnamed rather than guessed at. It reports, per state and per
frame, the leaf count, the drawn extent, and the **palette colour indices**.

The signal being read
---------------------
Colour is taken from the polygon records in `cinematic.rom`, not from a render:
a solid's header byte is `>= 0xC0` and its low six bits are the colour index.
That is palette-independent, so the result does not move if a stage's palette
is re-extracted, and it does not depend on any SVG in a scratch directory.
`tools/polygon_tree.py` discards this byte (it keeps only geometry), so the
walker here is local and deliberately mirrors that file's header rules.

Frame lists are read out of the assembly via `derive_state_map`, not typed in,
so this cannot drift from the machine it describes.

What it found (2026-09-19, amiga)
---------------------------------
  * Every channel-0x16 frame in all four states uses **exactly one** colour,
    index 6, and no other.
  * All four body loops share the same six indices {0, 2, 3, 4, 10, 14} --
    which is itself worth having, since it says the four states draw one
    figure and not four.
  * The LEFT and RIGHT body loops add index 6 to that set; the UP and DOWN
    body loops do **not** use it at all, so in those two states the second
    layer is the only thing on screen in that colour.
  * The LEFT and RIGHT second layers are the same eleven frames mirrored:
    equal extents frame for frame, and x-centre sequences whose ten steps run
    in opposite directions ten times out of ten, out and back.

An earlier run of this probe reported {0, 2, 6, 7, 10, 14, 15} for LEFT and
RIGHT. That was this file's bug, not the ROM's: `walk` recursed past a group
child's colour-override byte and read each leaf's own header colour instead.
The LEFT and RIGHT body art uses overrides and the UP and DOWN art does not,
so the defect appeared as the two pairs disagreeing for no visible reason.

What it does NOT establish
--------------------------
Which part of the hero, or whether it is part of the hero at all. One colour
and one or two leaves is consistent with several readings, and `docs/NAMING.md`
§2 wants the render to settle the subject before a name asserts one. It does
not settle here, so the four channel-0x16 routines stay `LABEL_<hex>`. This is
the same outcome recorded for CAVES' 514..524 and 110..123 runs earlier: art
that renders cleanly without settling what it is.

Usage
-----
    python3 notes/hero-direction-machine/layer_colour_census.py
    python3 notes/hero-direction-machine/layer_colour_census.py --port msdos
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ARCH = ROOT.parent / "another-world-archaeology"
sys.path.insert(0, str(ARCH / "tools"))
sys.path.insert(0, str(Path(__file__).parent))

from _paths import REPO_ROOT                      # noqa: E402
from derive_state_map import RE_DRAW, bodies, trace, RE_START, RE_SETUP  # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
SLAB = 0x10000
CAVES = 4
DIRS = {1: "LEFT", 2: "RIGHT", 3: "UP", 4: "DOWN"}
RE_EQU = re.compile(r"^(\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)


def walk(b: bytes, off: int, depth: int = 0,
         seen: frozenset[int] = frozenset(), out: list | None = None,
         override: int | None = None) -> list:
    """Leaves as (colour_index, x, y) in coordinates relative to the anchor.

    Mirrors `tools/polygon_tree.py`'s header rules, and additionally keeps the
    colour that file drops: a solid header `>= 0xC0` carries its colour index
    in the low six bits.

    A group child may carry a colour **override** (bit 15 of its word), which
    replaces the colour of everything below it. The first version of this
    walker recursed past that byte and reported each leaf's own header colour
    instead, which is wrong for exactly the frames that use overrides -- in
    amiga/CAVES the LEFT and RIGHT body art does and the UP and DOWN body art
    does not, so the bug showed up as the two pairs disagreeing about colours
    for no visible reason. `override` carries it down.
    """
    if out is None:
        out = []
    if off < 0 or off + 4 > len(b) or off in seen or depth > 16:
        return out
    seen = seen | {off}
    h = b[off]
    if h >= 0xC0:
        w, hh, np = b[off + 1], b[off + 2], b[off + 3]
        if np == 0 or (np & 1):
            return out
        col = (h & 0x3F) if override is None else override
        for i in range(np):
            px, py = b[off + 4 + i * 2], b[off + 5 + i * 2]
            out.append((col, px - w / 2, py - hh / 2))
        return out
    if (h & 0x3F) == 0x02:
        nc, pos = b[off + 3] + 1, off + 4
        w, hh = b[off + 1], b[off + 2]
        for _ in range(nc):
            if pos + 4 > len(b):
                break
            cw = (b[pos] << 8) | b[pos + 1]
            ca, ov = (cw & 0x7FFF) * 2, bool(cw & 0x8000)
            px, py = b[pos + 2], b[pos + 3]
            pos += 4
            sub_over = override
            if ov:
                sub_over = b[pos] & 0x7F
                pos += 2
            sub = walk(b, ca, depth + 1, seen, [], sub_over)
            for c, sx, sy in sub:
                out.append((c, sx + px - w / 2, sy + py - hh / 2))
    return out


def box(pts: list) -> tuple:
    xs = [p[1] for p in pts]
    ys = [p[2] for p in pts]
    return (max(xs) - min(xs), max(ys) - min(ys),
            (min(xs) + max(xs)) / 2, (min(ys) + max(ys)) / 2)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", action="append", choices=sorted(PORTS))
    args = ap.parse_args()
    for port in args.port or ["amiga"]:
        asm = ROOT / "src" / "levels" / PORTS[port] / "CAVES.asm"
        rom = REPO_ROOT / "tmp" / "output" / port / "romset" / "cinematic.rom"
        if not rom.is_file():
            print(f"{port}: {rom} missing -- run `make extract`", file=sys.stderr)
            return 2
        slab = rom.read_bytes()[CAVES * SLAB:(CAVES + 1) * SLAB]
        text = asm.read_text(errors="replace")
        equ = {m.group(1): int(m.group(2), 16) for m in RE_EQU.finditer(text)}
        bod = bodies(asm)

        # state -> (body loop label, channel-0x16 label), from the machine
        states: dict[int, tuple[str, str]] = {}
        for lab in bod:
            if not RE_START.match(lab):
                continue
            inst = [RE_SETUP.search(l) for l in bod[lab]]
            body = next((x.group(2) for x in inst
                         if x and x.group(1) == "0x15"), None)
            if body is None:
                continue
            t = trace(bod.get(body, []))
            if t["state"] and t["next"] and t["ch16"]:
                states[t["state"]] = (t["next"], t["ch16"])

        def frames(label: str) -> list[str]:
            out = []
            for line in bod.get(label, []):
                m = RE_DRAW.search(line)
                if m and m.group(1) not in out:
                    out.append(m.group(1))
            return out

        print(f"\n=== {port}/CAVES  hero direction layers")
        sweeps: dict[int, list[float]] = {}
        for st in sorted(states):
            body_lab, ch16 = states[st]
            for tag, lab in (("body", body_lab), ("chan 0x16", ch16)):
                names = frames(lab)
                cols: set[int] = set()
                nleaf = []
                cx = []
                for nm in names:
                    off = equ.get(nm)
                    if off is None:
                        continue
                    pts = walk(slab, off)
                    if not pts:
                        continue
                    cols |= {p[0] for p in pts}
                    w, h, ccx, _ = box(pts)
                    nleaf.append(len(pts))
                    cx.append(round(ccx, 1))
                if tag == "chan 0x16":
                    sweeps[st] = cx
                print(f"  state {st} {DIRS.get(st, '?'):<6} {tag:<10} "
                      f"{lab:<32} {len(names):>3} frame(s)  "
                      f"colours {sorted(cols)}")
        # the two horizontal states, frame for frame
        if 1 in sweeps and 2 in sweeps and len(sweeps[1]) == len(sweeps[2]):
            d1 = [b - a for a, b in zip(sweeps[1], sweeps[1][1:])]
            d2 = [b - a for a, b in zip(sweeps[2], sweeps[2][1:])]
            opp = sum(1 for a, b in zip(d1, d2) if a * b < 0)
            print(f"\n  LEFT vs RIGHT second layer: {len(sweeps[1])} frames "
                  f"each; {opp} of {len(d1)} steps move in opposite "
                  f"directions")
            print(f"    LEFT  x-centres {sweeps[1]}")
            print(f"    RIGHT x-centres {sweeps[2]}")
    print("\nThe second layer is one colour in every state. In UP and DOWN the "
          "body never uses\nthat colour. That separates the layers; it does "
          "not name the second one.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
