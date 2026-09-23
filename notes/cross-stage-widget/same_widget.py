#!/usr/bin/env python3
"""The same drawing, in two stages of one port -- a name that can be reused.

Question answered
-----------------
`notes/crossport-transfer/transfer_by_art_identity.py` moves a name between
PORTS on identical art. This moves one between STAGES of the SAME port, which
is a different and much smaller population: each stage has its own 0x10000
bank, and a widget the game reuses -- a charge meter, a readout bar, a flash --
is *copied into* every bank that shows it, at its own offset, under its own
constant number.

So the question is: which still-numbered `CINEMATIC_<n>` in stage A is the
byte-for-byte same polygon tree as something already named in stage B, in the
same port's ROM?

What it does NOT license
------------------------
Copying the name. `docs/NAMING.md` §1 and #0107 both say a name describes what
the constant is *in its stage*, and the stage-prefixed convention this repo
settled on (`CINEMATIC_CAPSULE_SEGMENT_BAR_F0`) makes that explicit. Identical
art in two stages earns the *words*, not the symbol: PRISON's copy is
`CINEMATIC_PRISON_SEGMENT_BAR_F0`, not CAPSULE's name pasted in.

Nor does it license the whole family. On 2026-09-23 this found five of an
eight-constant widget identical between PRISON and CAPSULE, and three not:
the four bar frames share slot F0 but PRISON redraws F1, F2 and F3. Five
identities settled "this is that widget"; the play order settled the other
three. A run of identities is evidence about the widget; each frame still has
to be placed by where the routine draws it.

What it prints
--------------
Per match: the two stages, the constant and offset in each, the shared md5,
the extent and leaf count. `--pairs` restricts to one stage pair.

`--show STAGE:NAME,...` is the other mode: no matching, just the measurement
table for constants you name -- offset, extent, leaf count, md5 -- which is
what a proposal quotes.

Signal being read
-----------------
`canonical_md5(parse_polygon_tree(slab, offset))` where
`slab = rom[stage * 0x10000 : (stage + 1) * 0x10000]` of
`tmp/output/<port>/romset/cinematic.rom` in the archaeology repo. Equal md5
means every header byte and every vertex is equal. It is **colour-blind**
(`notes/cross-port-art/colour_blind_hashes.py`): a recolour of the same shape
hashes the same, and ten distinct one-path INTRO marks share one hash. So a
match on a one- or two-path shape is weak on its own and needs the draw site;
a match on a four-path 6x3 bar is not.

Usage
-----
    python3 notes/cross-stage-widget/same_widget.py --port amiga
    python3 notes/cross-stage-widget/same_widget.py --port amiga --pairs PRISON:CAPSULE
    python3 notes/cross-stage-widget/same_widget.py --port amiga \
        --show PRISON:CINEMATIC_361,CINEMATIC_362

Run `make extract` in the archaeology repo first if the romsets are absent.
"""

from __future__ import annotations

import argparse
import collections
import itertools
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT.parent / "another-world-archaeology" / "tools"))
from _paths import REPO_ROOT                                # noqa: E402
from polygon_tree import parse_polygon_tree, canonical_md5  # noqa: E402
from polygon_extent import extent                           # noqa: E402

BRANCH = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992",
          "genesis_europe": "cartridge_1992", "gba_usa": "gba_2004"}
STAGES = {0: "CODE_WHEEL", 1: "INTRO", 2: "LAKE", 3: "PRISON", 4: "CAVES",
          5: "TANK", 6: "CAPSULE", 7: "ENDING", 8: "PASSCODE"}
SLAB = 0x10000
RE_EQU = re.compile(r"^(CINEMATIC_\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)
RE_NUM = re.compile(r"^CINEMATIC_\d+$")


def rom(port: str) -> bytes:
    p = REPO_ROOT / "tmp" / "output" / port / "romset" / "cinematic.rom"
    if not p.is_file():
        sys.exit(f"missing {p} -- run `make extract` in the archaeology repo")
    return p.read_bytes()


def equs(port: str, stage: str) -> dict[str, int]:
    f = ROOT / "src" / "levels" / BRANCH[port] / f"{stage}.asm"
    if not f.is_file():
        return {}
    return {m.group(1): int(m.group(2), 16)
            for m in RE_EQU.finditer(f.read_text(errors="replace"))}


def measure(slab: bytes, off: int):
    """(md5, 'WxH', leaf count) for one offset, or None if it does not parse."""
    t = parse_polygon_tree(slab, off)
    if not t:
        return None
    a = extent(t)
    return canonical_md5(t), f"{a[2] - a[0]:.1f}x{a[3] - a[1]:.1f}", a[4]


def index(port: str, data: bytes, stage: str, si: int):
    out = collections.defaultdict(list)
    for name, off in equs(port, stage).items():
        m = measure(data[si * SLAB:(si + 1) * SLAB], off)
        if m:
            out[m[0]].append((name, off, m[1], m[2]))
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", default="amiga", choices=sorted(BRANCH))
    ap.add_argument("--pairs", help="A:B -- only this stage pair")
    ap.add_argument("--show", help="STAGE:NAME,NAME,... -- measurement table only")
    args = ap.parse_args()

    data = rom(args.port)
    byname = {v: k for k, v in STAGES.items()}

    if args.show:
        stage, names = args.show.split(":", 1)
        tab = equs(args.port, stage)
        slab = data[byname[stage] * SLAB:(byname[stage] + 1) * SLAB]
        print(f"{args.port}/{stage}")
        for n in names.split(","):
            if n not in tab:
                print(f"  {n:<44} not defined in this stage"); continue
            m = measure(slab, tab[n])
            if not m:
                print(f"  {n:<44} 0x{tab[n]:04X}  does not parse"); continue
            print(f"  {n:<44} 0x{tab[n]:04X}  {m[1]:>12}  {m[2]:>3} leaf  {m[0][:12]}")
        return 0

    want = None
    if args.pairs:
        a, b = args.pairs.split(":", 1)
        want = {(a, b), (b, a)}

    have = [s for i, s in STAGES.items()
            if (ROOT / "src" / "levels" / BRANCH[args.port] / f"{s}.asm").is_file()]
    idx = {s: index(args.port, data, s, byname[s]) for s in have}

    total = 0
    for a, b in itertools.combinations(have, 2):
        if want and (a, b) not in want:
            continue
        rows = []
        for h, av in idx[a].items():
            bv = idx[b].get(h)
            if not bv:
                continue
            for an, ao, ae, al in av:
                for bn, bo, be, bl in bv:
                    # one side still a number, the other carrying one name
                    if RE_NUM.match(an) and not RE_NUM.match(bn):
                        rows.append((a, an, ao, b, bn, bo, ae, al, h))
                    elif RE_NUM.match(bn) and not RE_NUM.match(an):
                        rows.append((b, bn, bo, a, an, ao, be, bl, h))
        if not rows:
            continue
        print(f"\n=== {args.port}: {a} <-> {b}  ({len(rows)} identity/identities)")
        for ns, num, no, ms, named, mo, ext, leaf, h in sorted(rows):
            print(f"  {ns:<8} {num:<16} 0x{no:04X}  ==  "
                  f"{ms:<8} {named:<46} 0x{mo:04X}"
                  f"  {ext:>12} {leaf:>3} leaf  {h[:12]}")
        total += len(rows)

    print(f"\n{total} numbered constant(s) are the same drawing as something "
          f"named in another stage of {args.port}.")
    print("Identical art earns the WORDS, not the symbol: give the copy its "
          "own stage prefix,\nand place each frame by the routine that draws "
          "it before trusting a whole family.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
