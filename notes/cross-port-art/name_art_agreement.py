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

What it found, 2026-09-23
-------------------------
```
2064  same art in both ports
  10  ** DIFFERENT art under one name
```

Ten, and they are two different things.

**Six are defects, all in INTRO.** For each, msdos' named constant holds art
that amiga calls by a bare number, and amiga's art sits on a *different* msdos
number, a couple of indices away:

| name | msdos' holder is amiga's | amiga's art is msdos' |
| --- | --- | --- |
| `CINEMATIC_LIFT_SCENE_BG` | `CINEMATIC_533` | `CINEMATIC_535` |
| `CINEMATIC_LIFT_SCENE_VIEW` | `CINEMATIC_528` | `CINEMATIC_530` |
| `CINEMATIC_ACCELERATOR_TUNNEL_VIEW_FAR` | `CINEMATIC_378` | `CINEMATIC_380` |
| `CINEMATIC_ACCELERATOR_TUNNEL_VIEW_NEAR` | `CINEMATIC_243` | `CINEMATIC_255` |
| `CINEMATIC_PARTICLE_LAB_HOLO_CONSOLE` | `CINEMATIC_171` | `CINEMATIC_183` |
| `CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F2` | `CINEMATIC_517` | `CINEMATIC_517` |

The consistent two-to-twelve index offset is the signature of a transfer done
on the number. The last row is the same fault seen from both sides at once: the
two ports' `CINEMATIC_517` hold each other's art.

**Four are not defects.** In CAPSULE and PASSCODE the art of the amiga name is
absent from msdos entirely and vice versa, so the two ports genuinely drew
different pictures for one role. That is the documented case where a shared
name is the role and the per-port value is that port's art — the name is right
in both.

Telling them apart is the point of reporting the *counterpart* rather than
just the mismatch: a defect has a twin somewhere in the other port, a
divergence does not.

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
