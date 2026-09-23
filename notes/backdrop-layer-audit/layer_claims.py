#!/usr/bin/env python3
"""Does every `..._SCREEN_<HH>_BACKDROP_LAYER_<n>` name keep its own promise?

Question answered
-----------------
`notes/backdrop-drawer/` names a screen's backdrop pieces from the routine that
paints it: `<STAGE>_SCREEN_<HH>_BACKDROP_DRAW` is a `fill` followed by N
pictures at one anchor and a `ret`, so picture i of N is `..._LAYER_i`. The name
makes two claims at once -- **this routine draws it**, and **at this position**.

Both can go wrong without any gate noticing, because a rename moves no bytes:

  * a name applied globally instead of per branch lands on another port's
    constant at the same index (#0107), and that constant is not in the routine
    at all;
  * a family transferred or extended by hand can outrun the routine, claiming
    layers the routine never paints.

This checks every such name against its own routine, in each port's canonical
file, and reports:

    MISSING      the routine exists and does not draw this constant
    OUT OF ORDER drawn, but before a lower-numbered sibling
    NO ROUTINE   no `..._SCREEN_<HH>_BACKDROP_DRAW` in this stage at all

`MISSING` is the defect. `NO ROUTINE` is usually a screen whose painter is still
a bare `LABEL_xxxx`, which is a labelling job, not a wrong name.

The index is deliberately **not** checked against the position in the routine.
`PRISON_SCREEN_24_BACKDROP_DRAW` draws `LAYER_8, 9, 10, 11` and nothing else --
its first four layers come from the `PRISON_BACKDROP_TILE_REPEAT_DOWN` it calls
first -- so position 0 legitimately carries index 8. A naive position check
called 30 such rows wrong. What the name really claims about order is only that
siblings run in increasing index, and that is what `OUT OF ORDER` tests.

Why it was written
------------------
`notes/render-and-name/correction_capsule_6a_layer0.md` found one by accident.
Then a cross-port transfer offered to copy `CAPSULE_SCREEN_8A_BACKDROP_LAYER_2`
from msdos to amiga on a byte-identical polygon tree -- correct by the transfer
probe's own criterion, and wrong, because msdos'
`CAPSULE_SCREEN_8A_BACKDROP_DRAW` is

    fill page=0x00, color=0x00
    video offset=CINEMATIC_CAPSULE_SCREEN_8A_BACKDROP_LAYER_0, x=160, y=100
    ret

one layer, not three. `LAYER_1` and `LAYER_2` are drawn nowhere in it; `LAYER_2`
is drawn five times at actor anchors, `[0x26], [BUDDY_Y]` and
`[BUDDY_X], [BUDDY_Y]`, and measures 6.0x70.0 in a single leaf.

> A transfer probe propagates a name without ever asking whether the name is
> right. Audit the family before spreading it.

`notes/backdrop-drawer/README.md` had already recorded the same shape for msdos
CAVES' `SCREEN_ED` layers -- "those names already claim an exclusivity they do
not have" -- as an observation about one screen. This makes it a measurement
over all of them.

Usage
-----
    python3 notes/backdrop-layer-audit/layer_claims.py
    python3 notes/backdrop-layer-audit/layer_claims.py --port msdos --stage CAPSULE
    python3 notes/backdrop-layer-audit/layer_claims.py --kind MISSING
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
BRANCH = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992",
          "genesis_europe": "cartridge_1992", "gba_usa": "gba_2004"}
RE_LAYER = re.compile(
    r"^(CINEMATIC_(?:([A-Z_]+?)_)?SCREEN_([0-9A-Fa-f]{2})_BACKDROP_LAYER_(\d+))"
    r"\s+EQU\s+", re.M)
RE_LBL = re.compile(r"^(\w+):")
RE_VID = re.compile(r"^\s*video offset=(\w+)")


def routines(text: str) -> dict[str, list[str]]:
    """label -> the constants its straight-line body draws, in order."""
    out, name, cur = {}, None, []
    for line in text.splitlines():
        m = RE_LBL.match(line)
        if m:
            if name:
                out[name] = cur
            name, cur = m.group(1), []
            continue
        m = RE_VID.match(line)
        if m:
            cur.append(m.group(1))
    if name:
        out[name] = cur
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", action="append", choices=sorted(BRANCH))
    ap.add_argument("--stage")
    ap.add_argument("--kind", choices=["MISSING", "NO ROUTINE", "OUT OF ORDER"])
    args = ap.parse_args()

    tot = collections.Counter()
    for port in (args.port or sorted(BRANCH)):
        for asm in sorted((ROOT / "src" / "levels" / BRANCH[port]).glob("*.asm")):
            stage = asm.stem
            if args.stage and stage != args.stage:
                continue
            text = asm.read_text(errors="replace")
            rt = routines(text)
            rows = []
            for full, pre, hh, idx in RE_LAYER.findall(text):
                want = f"{pre + '_' if pre else ''}SCREEN_{hh.upper()}_BACKDROP_DRAW"
                body = rt.get(want)
                if body is None:
                    rows.append(("NO ROUTINE", full, want))
                elif full not in body:
                    rows.append(("MISSING", full, f"{want} draws {len(body)}: "
                                 + ", ".join(body[:4])))
                else:
                    sibs = [(body.index(n), int(i)) for n, _, h, i in
                            RE_LAYER.findall(text)
                            if h.upper() == hh.upper() and n in body]
                    if sorted(sibs) != sorted(sibs, key=lambda t: t[1]):
                        rows.append(("OUT OF ORDER", full,
                                     f"{want} draws this screen's layers as "
                                     + ", ".join(str(i) for _, i in
                                                 sorted(sibs))))
                    else:
                        tot["ok"] += 1
            for kind, full, why in rows:
                tot[kind] += 1
                if args.kind and kind != args.kind:
                    continue
                print(f"  {kind:<12} {port:<15} {stage:<11} {full}\n"
                      f"{'':>15}{why}")
    print()
    for k in ("ok", "OUT OF ORDER", "MISSING", "NO ROUTINE"):
        if tot[k]:
            print(f"{tot[k]:6d}  {k}")
    print("\nA layer name claims two things -- that its screen's DRAW routine "
          "paints it, and\nthat its siblings run in order. Neither is "
          "checked by the byte gate.")
    return 1 if (tot["MISSING"] or tot["OUT OF ORDER"]) else 0


if __name__ == "__main__":
    sys.exit(main())
