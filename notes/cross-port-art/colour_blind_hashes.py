#!/usr/bin/env python3
"""`canonical_md5` cannot see colour. How often does that matter?

Question answered
-----------------
Every cross-port claim in this tree rests on `canonical_md5` -- it is the
"legitimate bridge between ports" that #0107 leaves open, and
`transfer_by_art.py`, `align_draw_sites.py` and every proposal table that says
"identical art to amiga's ..." use it. So it is worth knowing exactly what it
does not distinguish.

It does not distinguish colour. `tools/polygon_tree.py` builds

    solid polygon  -> ("solid", bbox_w, bbox_h, [(x, y), ...])

with no colour field at all; only a **group child** carries one, as its
`color_override`. Two solid polygons of identical shape drawn in different
colours therefore have the same hash.

That is not a hypothetical. `CH_11_DRAW_PARTICLES_LOOP` and its sibling draw
four marks of 2.0x1.0, one path each, at 0x0630, 0x063C, 0x0648 and 0x0654 in
amiga/INTRO. All four hash to `afafd0dda5fb`, and so does the lab-door lamp at
0x06CC. The renderer gives them #102044, #103054, #204464, #305474 -- a
brightness ramp -- so they are four different pictures the bridge reports as
one.

What this probe measures
------------------------
Per stage, it groups every `CINEMATIC_*` constant by `canonical_md5` and then
asks the **renderer's own SVG** -- the arbiter, per
`../polygon-extent-correction/` -- what colours each one actually draws in. A
group whose members render in different colour sets is a group the hash merges
and the screen does not.

    COLLIDING   >1 constant shares a hash
    RECOLOURED  ... and at least two of them draw a different set of fills

A `RECOLOURED` group is where a `canonical_md5` match is **not** sufficient
evidence to carry a name across. The rest of the collisions are genuine
duplicates of the same picture under two names, which is a different problem
(`one_picture_many_names.py`).

Run it
------
Render the stage first, at any palette -- the comparison is between constants
at the *same* palette, so which one does not matter:

    awvm-render-polygons --port amiga --stage 1 --romset <dir> \\
        --bank cinematic --out <dir> --palette 1

    python3 notes/cross-port-art/colour_blind_hashes.py --branch chahi_amiga_1991 \\
        --stage INTRO --renders <dir>
    python3 notes/cross-port-art/colour_blind_hashes.py ... --show 20
"""
from __future__ import annotations

import argparse
import collections
import pathlib
import re
import sys

HERE = pathlib.Path(__file__).resolve().parents[2]
ARCH = HERE.parent / "another-world-archaeology"
sys.path.insert(0, str(ARCH / "tools"))
from polygon_tree import parse_polygon_tree, canonical_md5  # noqa: E402

SRC = HERE / "src" / "levels"
STAGE_ID = {"CODE_WHEEL": 0, "INTRO": 1, "LAKE": 2, "PRISON": 3, "CAVES": 4,
            "TANK": 5, "CAPSULE": 6, "ENDING": 7, "PASSCODE": 8}
PORT = {"chahi_amiga_1991": "amiga", "dos_1992": "msdos"}
RE_EQU = re.compile(r"^(CINEMATIC_[A-Za-z0-9_]+)\s+EQU\s+(0x[0-9A-Fa-f]+)\s*$", re.M)
RE_FILL = re.compile(r'<path fill="([^"]*)"')


def fills(renders: pathlib.Path, off: int) -> tuple[str, ...] | None:
    """The multiset of fill colours the renderer emits, in draw order."""
    hits = list(renders.glob(f"*_0x{off:04X}.svg"))
    if not hits:
        return None
    return tuple(RE_FILL.findall(hits[0].read_text()))


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--branch", default="chahi_amiga_1991")
    ap.add_argument("--stage", default="INTRO", choices=sorted(STAGE_ID))
    ap.add_argument("--renders", type=pathlib.Path, required=True)
    ap.add_argument("--show", type=int, default=8)
    args = ap.parse_args()

    port = PORT.get(args.branch)
    if port is None:
        raise SystemExit(f"no romset mapping for {args.branch}")
    rom = ARCH / "tmp" / "output" / port / "romset" / "cinematic.rom"
    if not rom.is_file():
        raise SystemExit(f"missing {rom}; run tools/aw_unpacker.py")
    i = STAGE_ID[args.stage]
    bank = rom.read_bytes()[i * 0x10000:(i + 1) * 0x10000]

    equ = {n: int(v, 16) for n, v
           in RE_EQU.findall((SRC / args.branch / f"{args.stage}.asm").read_text())}

    by_hash: dict[str, list[tuple[str, int]]] = collections.defaultdict(list)
    unparsed = 0
    for n, off in equ.items():
        try:
            t = parse_polygon_tree(bank, off)
            h = canonical_md5(t) if t else None
        except (OverflowError, ValueError, IndexError):
            h = None
        if h is None:
            unparsed += 1
            continue
        by_hash[h].append((n, off))

    colliding = {h: v for h, v in by_hash.items() if len(v) > 1}
    recoloured = []
    for h, members in colliding.items():
        seen = {}
        for n, off in members:
            f = fills(args.renders, off)
            if f is not None:
                seen[n] = f
        if len({v for v in seen.values()}) > 1:
            recoloured.append((h, sorted(seen.items())))

    print(f"  {args.branch}/{args.stage}: {len(equ)} constant(s), "
          f"{len(by_hash)} distinct canonical_md5, {unparsed} unparseable\n")
    print(f"  COLLIDING   {len(colliding)} hash(es) held by more than one constant")
    print(f"  RECOLOURED  {len(recoloured)} of those draw in more than one colour set\n")

    for h, members in sorted(recoloured, key=lambda x: -len(x[1]))[:args.show]:
        print(f"  {h[:12]}  {len(members)} constant(s):")
        for n, f in members:
            pal = ",".join(sorted(set(f))) or "(no paths)"
            print(f"      {n:<52} 0x{equ[n]:04X}  {pal}")
        print()

    print("  A RECOLOURED group is where a canonical_md5 match is NOT sufficient")
    print("  evidence to carry a name across ports: the bridge merges pictures the")
    print("  screen keeps apart. Match those by offset and draw site instead.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
