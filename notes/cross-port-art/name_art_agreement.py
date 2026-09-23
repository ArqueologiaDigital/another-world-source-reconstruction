#!/usr/bin/env python3
"""Does a name shared by both priority ports sit on the same picture in each?

Question answered
-----------------
A name that exists in amiga and msdos for the same stage is making one claim
about two constants. `docs/NAMING.md` records the hazard behind that (#0107):
the two releases index their art differently, so a name transferred **by
index** lands on whatever the other port happens to keep at that number.

This checks every such pair by `canonical_md5` and reports the ones that
disagree.

What it found
-------------
First run, 2026-09-23: `2064 same / 10 different`. Six of the ten were defects,
all in INTRO -- msdos' named constant held art amiga called by a bare number,
and amiga's art sat on a *different* msdos number two to twelve indices away.
That consistent offset is the signature of a transfer done on the number. One
row, `CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F2`, was the same fault seen
from both sides at once: the two ports' `CINEMATIC_517` held each other's art.

Those six were fixed. Re-run at the end of the same day, after several thousand
more names had landed:

```
   2878  same art in both ports
     11  ** name on the wrong constant
      9  different art, no counterpart -- per-port divergence
```

**The count goes up as naming proceeds, and that is the point** -- this is a
standing audit, not a one-off. Re-run it after every batch. The numbers in this
docstring are a record of two runs, not a target.

How a name gets onto the wrong constant
---------------------------------------
The mechanism was established on 2026-09-23 by working one row,
`CINEMATIC_CAPSULE_SCREEN_6A_BACKDROP_LAYER_0`
(`notes/render-and-name/correction_capsule_6a_layer0.md`). msdos' constant is
a 459.0x232.5 backdrop in 54 leaves; amiga's constant of the same name is a
26.0x22.0 blob in 3, drawn at an actor anchor.

The proposal that earned the name was right. The **apply** was global instead
of `--branch dos_1992`, and the three ports' entry files are parallel by index,
line for line:

    amiga__entry.inc:643   CINEMATIC_000   EQU 0x3E1C
    dos__entry.inc:643     CINEMATIC_000   EQU 0xF9A8
    cart__entry.inc:643    CINEMATIC_000   EQU 0xDBD4

so one global rename of `CINEMATIC_000` put msdos' name on all three ports'
index 0. That is #0107 arriving through the applier rather than through a
proposal, and it is invisible to every other check: the bytes do not move, no
symbol goes undefined, and the lint sees a well-formed name.

> A numbered constant is a per-port index. Renaming one is **never** a global
> operation unless the art has been shown identical in every branch it touches.

The tell, once you know to look for it, is a **one-member family**: amiga had
`SCREEN_6A_BACKDROP_LAYER_0` and no `LAYER_1`, because the sibling row in the
same batch *was* branch-scoped correctly.

Telling defects from divergences is the point of reporting the *counterpart*
rather than just the mismatch: a defect has a twin somewhere in the other port,
a divergence does not. The 6A row is the third shape -- amiga's art has a
counterpart (msdos' `CINEMATIC_258`) while msdos' named constant has none in
amiga, because amiga simply never drew that backdrop.

Pass/fail
---------
Exits 1 when a disagreement has a counterpart, because that is a name on the
wrong constant. A disagreement with no counterpart is reported and not failed.

Usage
-----
    python3 notes/cross-port-art/name_art_agreement.py
"""

from __future__ import annotations

import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
sys.path.insert(0, str(SRC.parent / "another-world-archaeology" / "tools"))
sys.path.insert(0, str(SRC / "notes" / "polygon-extent-correction"))
from polygon_tree import parse_polygon_tree, canonical_md5   # noqa: E402
from extent_matches_renderer import slab                     # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGE_ID = {"CODE_WHEEL": 0, "INTRO": 1, "LAKE": 2, "PRISON": 3, "CAVES": 4,
            "TANK": 5, "CAPSULE": 6, "ENDING": 7, "PASSCODE": 8}
RE_EQU = re.compile(r"^(CINEMATIC_[A-Za-z0-9_]+)\s+EQU\s+(0x[0-9A-Fa-f]+)",
                    re.M)
RE_NUM = re.compile(r"^CINEMATIC_\d+$")


def load(port, branch, stage):
    f = SRC / "src" / "levels" / branch / f"{stage}.asm"
    if not f.is_file():
        return None
    text = f.read_text(errors="replace")
    bank = slab("cinematic", port, STAGE_ID[stage])
    equ, h2n = {}, collections.defaultdict(list)
    for n, v in RE_EQU.findall(text):
        equ[n] = int(v, 16)
        try:
            h2n[canonical_md5(parse_polygon_tree(bank, int(v, 16)))].append(n)
        except BaseException:
            pass
    return equ, bank, h2n, text


def main() -> int:
    stats = collections.Counter()
    defects, diverged = [], []
    for stage in STAGE_ID:
        T = {}
        for port, branch in PORTS.items():
            got = load(port, branch, stage)
            if got is None:
                T = None
                break
            T[port] = got
        if not T:
            continue
        shared = set(T["amiga"][0]) & set(T["msdos"][0])
        for n in sorted(shared):
            if RE_NUM.match(n):
                continue
            hs = {}
            ok = True
            for port in PORTS:
                equ, bank, _h2n, text = T[port]
                if f"offset={n}," not in text:
                    ok = False
                    break
                try:
                    hs[port] = canonical_md5(
                        parse_polygon_tree(bank, equ[n]))
                except BaseException:
                    ok = False
                    break
            if not ok:
                stats["not drawn in both"] += 1
                continue
            if hs["amiga"] == hs["msdos"]:
                stats["same art in both ports"] += 1
                continue
            a_of_m = T["amiga"][2].get(hs["msdos"], [])
            m_of_a = T["msdos"][2].get(hs["amiga"], [])
            if a_of_m or m_of_a:
                stats["** name on the wrong constant"] += 1
                defects.append((stage, n, a_of_m, m_of_a))
            else:
                stats["different art, no counterpart -- per-port "
                      "divergence"] += 1
                diverged.append((stage, n))

    for k, v in stats.most_common():
        print(f"  {v:>5}  {k}")
    if defects:
        print(f"\n{len(defects)} name(s) on the wrong constant:")
        for stage, n, a_of_m, m_of_a in defects:
            print(f"  {stage:<9}{n}")
            print(f"      msdos holder is amiga's : {a_of_m}")
            print(f"      amiga art is msdos's    : {m_of_a}")
    if diverged:
        print(f"\n{len(diverged)} name(s) over genuinely different per-port "
              f"art -- the name is the role, not a defect:")
        for stage, n in diverged:
            print(f"  {stage:<9}{n}")
    return 1 if defects else 0


if __name__ == "__main__":
    sys.exit(main())
