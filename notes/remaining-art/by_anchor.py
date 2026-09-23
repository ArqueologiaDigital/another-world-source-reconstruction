#!/usr/bin/env python3
"""What shape is the art that is still called CINEMATIC_<index>?

Question answered
-----------------
`../sole-named-drawer/README.md` ends with a ledger showing every
drawer-side seam into the remaining art is now worth 0, and that 1,655
pictures are numbered in **both** priority ports with identical art. Nothing
in the call graph distinguishes them. So the next question is not "who draws
it" but "how is it drawn", because the draw operands sort the backlog into
classes that need different evidence.

This sorts it, and it is the map a scene-identification pass should start
from rather than re-derive.

Signal being read
-----------------
The `x=` and `y=` operands of every `video` that names a still-numbered
constant in PRISON, CAVES and CAPSULE, plus the extent of the polygon tree at
that constant.

    anchor                            draws   distinct pictures
    fixed literal x,y                  2978                1152
    variable pair (actor/prop slot)    2647                1534
    hero slot                          1256                 788
    one literal, one variable           474                 228

(as this module prints them; a distinct picture is a (port, stage, constant)
triple, so a constant numbered in both ports counts twice)

Those want different methods, and the project already has them:

- **Hero slot** is `../shared-bank-geometry/` territory: pose, height and
  gait-phase measurement against the named walk frames.
- **Actor slot** is `../actor-sprite-sheet/`, plus the `#0138` rule that a
  picture at the actor slot is not named from the scene that draws it.
- **Fixed literal** is scenery, and it is the largest distinct-picture class
  after the actor slot. It cannot be named from its coordinates -- NAMING.md
  §1 forbids that, and `../lake-shooting/` is the cautionary tale of a whole
  scene hidden inside a coordinate-grouped name.

The backdrop composites
-----------------------
Inside the fixed-literal class there is one structurally obvious subset: a
routine whose body is `fill` followed by N full-screen pictures at a single
anchor, then `ret`.

    DRAW_CIN_305_TO_309_5F_AT_AACB4DF5:
        fill page=0x00, color=0x03
        video offset=CINEMATIC_305, x=160, y=100
        video offset=CINEMATIC_306, x=160, y=100
        video offset=CINEMATIC_307, x=160, y=100
        video offset=CINEMATIC_308, x=160, y=100
        video offset=CINEMATIC_309, x=160, y=100
        ret

That is a backdrop drawn in layers, and the caller confirms it --
`selectVideoPage 0x00`, the call, `selectVideoPage 0xFF`.

**What is missing is which screen it is for**, and that is why none of these
is named here. Two guesses were tested and both failed:

- The two-hex token in the generated label (`..._5F_AT_...`) is **not** the
  screen number: of the 54 such labels, **0** are reached under a
  `[SCREEN_NUM]` guard equal to their token.
- It is not reliably the draw count either: 42 of 74 match the number of
  draws in the body and 32 do not.

And the screen cannot be read off the call site. `DRAW_CIN_305_TO_309_5F` is
called from `LABEL_815E`, itself unnamed, with no guard on the call. The
stages do not have one screen dispatcher to read: `[SCREEN_NUM]` is compared
182 times across 52 distinct values in CAVES alone, scattered as guards. So
attaching a screen to a backdrop is a multi-hop reachability problem through
unnamed labels, not a lookup -- which is the honest reason this class is
still numbered.

Pass/fail
---------
Exits 0 always; it is a survey, not a check.

Usage
-----
    python3 notes/remaining-art/by_anchor.py
    python3 notes/remaining-art/by_anchor.py --backdrops
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
sys.path.insert(0, str(SRC.parent / "another-world-archaeology" / "tools"))
sys.path.insert(0, str(SRC / "notes" / "polygon-extent-correction"))
from polygon_tree import parse_polygon_tree                  # noqa: E402
from polygon_extent import extent                            # noqa: E402
from extent_matches_renderer import slab                     # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGE_ID = {"PRISON": 3, "CAVES": 4, "CAPSULE": 6}

RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
RE_V = re.compile(r"^\s*video\s+(?:type=\d+,\s*)?offset="
                  r"([A-Za-z_][A-Za-z0-9_]*),\s*x=([^,]+),\s*y=([^,\s]+)")
RE_NUM = re.compile(r"^CINEMATIC_\d+$")
RE_FILL = re.compile(r"^\s*fill\s")
RE_RET = re.compile(r"^\s*ret\s*$")
FULL_W, FULL_H = 240, 160


def anchor_kind(x: str, y: str) -> str:
    x, y = x.strip(), y.strip()
    if x.isdigit() and y.isdigit():
        return "fixed literal x,y"
    if "HERO_X" in x or "HERO_Y" in y:
        return "hero slot"
    if x.startswith("[") and y.startswith("["):
        return "variable pair (actor/prop slot)"
    return "one literal, one variable"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--proposals", action="store_true",
                    help="name the layers of a backdrop composite whose "
                         "label carries the screen, where the layer is drawn "
                         "by that composite and nothing else")
    ap.add_argument("--backdrops", action="store_true",
                    help="list the fill + N full-screen layers routines")
    args = ap.parse_args()

    draws = collections.Counter()
    distinct: dict[str, set] = collections.defaultdict(set)
    backdrops = []
    sites: dict[tuple, set] = collections.defaultdict(set)

    for port, branch in PORTS.items():
        for stage, sid in STAGE_ID.items():
            f = SRC / "src" / "levels" / branch / f"{stage}.asm"
            if not f.is_file():
                continue
            text = f.read_text(errors="replace")
            equ = {n: int(v, 16) for n, v in re.findall(
                r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s+(0x[0-9A-Fa-f]+)",
                text, re.M)}
            bank = slab("cinematic", port, sid)
            lines = text.splitlines()
            cur, run, filled = None, [], False
            for line in lines:
                if m := RE_LBL.match(line):
                    cur, run, filled = m.group(1), [], False
                    continue
                if RE_FILL.match(line):
                    filled = True
                    continue
                if RE_RET.match(line):
                    if filled and len(run) >= 2 and len({a for _c, a in run}) == 1:
                        big = 0
                        for c, _a in run:
                            if c in equ:
                                x0, y0, x1, y1, _lv = extent(
                                    parse_polygon_tree(bank, equ[c]))
                                big += (x1 - x0) >= FULL_W and (y1 - y0) >= FULL_H
                        if big:
                            backdrops.append((port, stage, cur,
                                              [c for c, _a in run], big))
                    run, filled = [], False
                    continue
                if v := RE_V.match(line):
                    const = v.group(1)
                    if not RE_NUM.match(const):
                        continue
                    k = anchor_kind(v.group(2), v.group(3))
                    draws[k] += 1
                    distinct[k].add((port, stage, const))
                    sites[(port, stage, const)].add(cur)
                    run.append((const, (v.group(2).strip(),
                                        v.group(3).strip())))

    if args.proposals:
        # A composite's label may carry the screen -- CAVES_SCREEN_92_
        # BACKDROP_DRAW. Its layers are then that screen's backdrop, in the
        # order the machine draws them. Only a layer drawn by this composite
        # and NOTHING else can take the name: screens 0x92 and 0x93 share
        # their base and their top layer and differ in one, so the shared two
        # belong to neither screen and are left numbered.
        by: dict[tuple, list] = {}
        for port, stage, lab, consts, _big in sorted(backdrops):
            m = re.search(r"SCREEN_([0-9A-F]{2})", lab or "")
            if not m:
                continue
            for i, const in enumerate(consts):
                if not RE_NUM.match(const):
                    continue
                if sites[(port, stage, const)] != {lab}:
                    continue
                branch = PORTS[port]
                new = (f"CINEMATIC_{stage}_SCREEN_{m.group(1)}_BACKDROP"
                       f"_LAYER_{i}")
                by.setdefault((branch, stage), []).append(
                    (const, new, lab, i, len(consts)))
        for (branch, stage), rows in sorted(by.items()):
            print(f"\n----- {branch} / {stage} -----")
            print("| constant | proposed name | confidence | evidence |")
            print("| --- | --- | --- | --- |")
            for const, new, lab, i, n in rows:
                print(f"| {const} | {new} | high | `{lab}` is `fill` then "
                      f"{n} pictures at one anchor then `ret`, and draws this "
                      f"one {i + 1}{'st' if i == 0 else 'nd' if i == 1 else 'rd' if i == 2 else 'th'} "
                      f"of the {n}; no other routine in the stage draws it, "
                      f"so it belongs to that screen's backdrop and to no "
                      f"other |")
        return 0

    if args.backdrops:
        print(f"{len(backdrops)} routine(s) are `fill` + layers at one "
              f"anchor, with at least one full-screen layer:\n")
        for port, stage, lab, consts, big in sorted(backdrops):
            print(f"  {port:<6}{stage:<9}{lab:<46}"
                  f"{len(consts)} layer(s), {big} full-screen")
        print("\nWhich screen each belongs to is NOT derivable from the "
              "label or the call site;\nsee this module's docstring for the "
              "two hypotheses that were tested and failed.")
        return 0

    print("  still-numbered art in PRISON, CAVES and CAPSULE, "
          "by how it is anchored\n")
    print(f"  {'anchor':<34}{'draws':>8}{'distinct pictures':>20}")
    for k, n in draws.most_common():
        print(f"  {k:<34}{n:>8}{len(distinct[k]):>20}")
    print(f"\n  {len(backdrops)} routine(s) look like backdrop composites "
          f"(--backdrops)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
