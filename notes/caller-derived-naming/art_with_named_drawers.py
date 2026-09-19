#!/usr/bin/env python3
"""Which unnamed polygons are drawn only by routines that already have a name?

Question answered
-----------------
`named_art_only.py` measured the gate and found it shut: 3,495 of the 3,515
unnamed routines in the big three that draw anything draw only unidentified
art. So the routine layer waits on the polygon layer, and the question becomes
which polygons are cheapest to identify.

This is the inverse lookup. For every `CINEMATIC_<index>` still carrying the
disassembler's per-port counter, it collects the routines that draw it and
asks whether **every** one of them already has a semantic name. Where that
holds, the render has a caption before it is looked at: a polygon drawn only
from `CAVES_GROUND_MAP_SCREEN_*` is a piece of ground, and the namer opens the
SVG knowing what to expect and what would refute it.

**This does not name anything by itself, and must not.** `docs/NAMING.md` §2
sets the bar at E3 — render the polygon and look at it — and a routine name is
not a render. What this produces is a *work order*: the constants whose
identification is cheapest, grouped so that one contact sheet answers many of
them, with the caption the drawing sites imply. The 2026-09-19 pass that
measured the gate also found the counter-example that makes the caution
concrete: `LABEL_4CC4` draws `CINEMATIC_BUDDY_SMASHING_WINDOW_F8` while tiling
a beam, so even a *named* polygon's name need not describe the use, and the
implication runs no more reliably in this direction.

What is measured
----------------
For each port and stage, over `CINEMATIC_<n>` constants that the bytecode
actually draws:

  drawn           constants with at least one `video offset=` site
  all drawers named   every drawing routine classifies as semantic
  mixed           some named, some not
  none named      no drawing routine has a name yet

`--list` prints the ready ones grouped by the stem the drawing routines share,
longest common prefix first, because a group that shares a stem is a run to
render together rather than a list to walk one by one.

Usage
-----
    python3 notes/caller-derived-naming/art_with_named_drawers.py
    python3 notes/caller-derived-naming/art_with_named_drawers.py \
        --port amiga --stage CAVES --list
"""

from __future__ import annotations

import argparse
import collections
import os
import re
import sys
from pathlib import Path

ARCH = Path(__file__).resolve().parents[2].parent / "another-world-archaeology"
sys.path.insert(0, str(ARCH / "tools"))
from _paths import AW_SRC                      # noqa: E402
from naming_census import classify              # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992",
         "snes_eu": "cartridge_1992", "gba_usa": "gba_2004"}
BIG3 = ["PRISON", "CAVES", "CAPSULE"]
ALL = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
       "CAPSULE", "ENDING", "PASSCODE"]

RE_LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
RE_DRAW = re.compile(r"video\s+(?:type=\d+,\s*)?offset=([A-Za-z_][A-Za-z0-9_]*)")
RE_NUMERIC = re.compile(r"^CINEMATIC_\d+$")
RE_EQU = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s+(0x[0-9A-Fa-f]+)\s*$")


def stem(name: str, keep: int = 4) -> str:
    """The first few segments of a routine name, as a grouping key."""
    return "_".join(name.split("_")[:keep])


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", action="append", choices=sorted(PORTS))
    ap.add_argument("--stage", action="append", choices=ALL)
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--min-group", type=int, default=1,
                    help="with --list, only show stems with this many constants")
    args = ap.parse_args()
    ports = args.port or ["amiga"]
    stages = args.stage or BIG3

    grand = collections.Counter()
    if not args.list:
        print(f"{'port/stage':<20}{'drawn':>8}{'all drawers named':>20}"
              f"{'mixed':>8}{'none named':>12}")
    for port in ports:
        for stage in stages:
            path = AW_SRC / "src" / "levels" / PORTS[port] / f"{stage}.asm"
            if not path.is_file():
                continue
            text = path.read_text()
            equ = {m.group(1): m.group(2)
                   for m in (RE_EQU.match(l) for l in text.splitlines()) if m}
            drawers: dict[str, set[str]] = collections.defaultdict(set)
            cur = None
            for line in text.splitlines():
                m = RE_LABEL.match(line)
                if m:
                    cur = m.group(1)
                    continue
                if cur is None:
                    continue
                for sym in RE_DRAW.findall(line.split(";", 1)[0]):
                    if RE_NUMERIC.match(sym):
                        drawers[sym].add(cur)
            n = collections.Counter()
            ready: dict[str, list[tuple[str, str]]] = collections.defaultdict(list)
            for sym, who in drawers.items():
                n["drawn"] += 1
                named = [w for w in who if classify(w) == "semantic"]
                if len(named) == len(who):
                    n["all named"] += 1
                    ready[stem(sorted(who)[0])].append((sym, equ.get(sym, "?")))
                elif named:
                    n["mixed"] += 1
                else:
                    n["none named"] += 1
            grand.update(n)
            if args.list:
                groups = {k: v for k, v in ready.items()
                          if len(v) >= args.min_group}
                total = sum(len(v) for v in groups.values())
                print(f"\n# {port}/{stage} — {total} constant(s) in "
                      f"{len(groups)} group(s) drawn only by named routines\n")
                for k, v in sorted(groups.items(), key=lambda kv: -len(kv[1])):
                    print(f"  {k}*   ({len(v)})")
                    for sym, off in sorted(v, key=lambda p: p[1]):
                        print(f"      {sym:<20} {off}")
            elif n["drawn"]:
                print(f"{port + '/' + stage:<20}{n['drawn']:>8}"
                      f"{n['all named']:>20}{n['mixed']:>8}{n['none named']:>12}")

    if not args.list:
        print(f"\n{'TOTAL':<20}{grand['drawn']:>8}{grand['all named']:>20}"
              f"{grand['mixed']:>8}{grand['none named']:>12}")
        print("\n`all drawers named` is the work order: these constants can be "
              "rendered with a\ncaption already in hand. It is a priority "
              "ordering, NOT a naming rule — §2's\nE3 bar is a render, and a "
              "routine name is not one.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
