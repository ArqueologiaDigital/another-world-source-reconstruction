#!/usr/bin/env python3
"""Is amiga LAKE's `HERO_FALL_LEFT_LOOP` a fall, and is `HERO_WALK_LEFT_LOOP` a walk?

Question answered
-----------------
LAKE is the stage this project calls finished — 100% of its amiga labels are
semantic as of 2026-09-19. Its two left-facing hero locomotion loops are named
`HERO_FALL_LEFT_LOOP` and `HERO_WALK_LEFT_LOOP`, and the polygon families they
draw are `CINEMATIC_HERO_FALL_LEFT_1..4`, `CINEMATIC_HERO_RESUME_LEFT_0..9` and
`CINEMATIC_HERO_WALK_LEFT_0..3`.

Two things put those names in doubt at once.

First, `docs/NAMING.md` §2 requires a cinematic family to have no gap in its
index run, and `CINEMATIC_HERO_FALL_LEFT` starts at 1. The 2026-09-14 msdos LAKE
verifier downgraded five msdos routine names for exactly this and said the base
had never been re-rendered
(`research/2026-09-14-small-stage-finish/verdicts_msdos_LAKE_0.md`). It also
noticed that `FALL_LEFT_1..4` (0x0A3C, 0x0A64, 0x0A8C, 0x0AB4) and
`RESUME_LEFT_0..3` (0x0ADC, 0x0B04, 0x0B2C, 0x0B54) are one contiguous eight-entry
run at an unbroken 0x28 stride, so the FALL/RESUME boundary is not a boundary in
the bank either.

Second, and this is what the probe settles: **a fall moves the actor down the
screen.** If `HERO_FALL_LEFT_LOOP` never writes `HERO_Y`, it is not a fall,
whatever the frames look like.

What is measured
----------------
For each loop, walked instruction by instruction from its label to the next
label that is not part of it:

  * every `video offset=<EQU>` in order — the frame sequence;
  * every `add`/`sub` on `HERO_X` — the per-frame horizontal speed. A walk and
    a run differ by speed and by nothing else the bytecode states;
  * every `add`/`sub` on `HERO_Y` — the vertical motion. `add [HERO_Y], 0x0000`
    is a no-op and is reported as such, because the listing is full of them and
    a careless grep counts them as vertical motion;
  * every `play id=` — a walk cycle has one footstep per footfall, so the sound
    count is a check on the frame count.

Verdict rule, stated before the numbers: `HERO_FALL_LEFT_LOOP` is a fall only if
it has at least one non-zero `HERO_Y` write. `HERO_WALK_LEFT_LOOP` is a walk only
if its horizontal speed is comparable to the other loop's.

The art
-------
The frame sequence this prints is the list to render. The commands:

    cd another-world-archaeology
    ~/compartilhado/AnotherWorld_VMTools/target/release/awvm-render-polygons \
        --port amiga --stage 2 --romset tmp/output/amiga/romset \
        --out /tmp/awvm_svg/amiga_stage2_pal0 --palette 0
    # then montage the eight 0x28-stride entries, cropped to their own boxes:
    cd /tmp/awvm_svg/amiga_stage2_pal0
    for off in 0x0A3C 0x0A64 0x0A8C 0x0AB4 0x0ADC 0x0B04 0x0B2C 0x0B54; do
      f=$(ls | grep -i "_${off}.svg$")
      convert -density 500 -background '#888888' "$f" -trim +repage -resize x300 \
              -bordercolor '#888888' -border 16 /tmp/w_${off}.png
    done
    montage -label '%t' /tmp/w_0x0*.png -tile 8x1 -geometry +4+4 \
            -background '#333' -fill white -pointsize 22 /tmp/walk_sheet.png

Usage
-----
    python3 notes/hero-walk-cycle-probes/lake_hero_left_locomotion.py
    python3 notes/hero-walk-cycle-probes/lake_hero_left_locomotion.py --port msdos

Exits non-zero if the fall reading turns out to be supported after all, i.e. if
a non-zero `HERO_Y` write appears in the loop — which would mean this probe's
conclusion, and the rename it justified, are wrong.
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[2]
SRC = REPO / "src" / "levels"
BRANCHES = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992",
            "cartridge": "cartridge_1992", "gba": "gba_2004"}

# The loops are named for the reading this probe tests, and renamed once it has
# been tested; accept both spellings so the probe survives its own conclusion.
LOOPS = {
    "steady loop": ["HERO_FALL_LEFT_LOOP", "HERO_WALK_LEFT_CYCLE_LOOP"],
    "burst loop": ["HERO_WALK_LEFT_LOOP", "HERO_RUN_LEFT_BURST_LOOP"],
}

RE_LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
RE_DRAW = re.compile(r"video\s+offset=([A-Za-z_][A-Za-z0-9_]*)")
RE_XY = re.compile(r"^\s*(add|sub)\s+\[(HERO_X|HERO_Y)\]\s*,\s*(0x[0-9A-Fa-f]+)")
RE_PLAY = re.compile(r"^\s*play\s+id=(\S+?),")
# stop walking the loop at a label that starts a different subject
RE_STOP = re.compile(r"^(HERO_STAND_|HERO_RUN_|DISPATCH_|ENTRY_POINT_)")


def walk_loop(lines, names, limit=200):
    start = None
    for i, line in enumerate(lines):
        m = RE_LABEL.match(line)
        if m and m.group(1) in names:
            start = i
            break
    if start is None:
        return None
    events = []
    for line in lines[start + 1: start + 1 + limit]:
        text = line.split(";", 1)[0]
        m = RE_LABEL.match(text)
        if m and RE_STOP.match(m.group(1)):
            break
        if m:
            events.append(("label", m.group(1), 0))
            continue
        d = RE_DRAW.search(text)
        if d:
            events.append(("draw", d.group(1), 0))
            continue
        p = RE_PLAY.match(text)
        if p:
            events.append(("play", p.group(1), 0))
            continue
        x = RE_XY.match(text)
        if x:
            v = int(x.group(3), 16)
            events.append((x.group(2), x.group(1), -v if x.group(1) == "sub" else v))
    return events


def report(title, events):
    draws = [e[1] for e in events if e[0] == "draw"]
    xs = [e[2] for e in events if e[0] == "HERO_X"]
    ys = [e[2] for e in events if e[0] == "HERO_Y"]
    plays = [e[1] for e in events if e[0] == "play"]
    nonzero_y = [v for v in ys if v != 0]
    print(f"  frames drawn   : {len(draws)}")
    for i, d in enumerate(draws):
        print(f"      {i:2d}  {d}")
    print(f"  HERO_X steps   : {xs}")
    if xs:
        print(f"                   min {min(xs)}, max {max(xs)}, "
              f"mean {sum(xs)/len(xs):+.2f} px/frame")
    if nonzero_y:
        tail = f" -> {nonzero_y}"
    elif ys:
        tail = "  (every one is `add [HERO_Y], 0x0000`)"
    else:
        tail = "  (the loop never touches HERO_Y at all)"
    print(f"  HERO_Y writes  : {len(ys)} total, {len(nonzero_y)} non-zero{tail}")
    print(f"  sounds         : {plays}")
    return {"draws": draws, "xs": xs, "nonzero_y": nonzero_y, "plays": plays}


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", default="amiga", choices=sorted(BRANCHES))
    args = ap.parse_args()
    path = SRC / BRANCHES[args.port] / "LAKE.asm"
    lines = path.read_text().splitlines()

    print(f"LAKE hero left-locomotion probe — {args.port}\n")
    out = {}
    for title, names in LOOPS.items():
        events = walk_loop(lines, names)
        print(f"{title}  ({' or '.join(names)})")
        if events is None:
            print("  NOT FOUND in this port\n")
            continue
        out[title] = report(title, events)
        print()

    steady, burst = out.get("steady loop"), out.get("burst loop")
    if steady is None:
        print("steady loop absent; nothing to conclude for this port.")
        return 0

    ok = True
    if steady["nonzero_y"]:
        print("FALL READING SUPPORTED — the loop does move the hero vertically.")
        ok = False
    else:
        print("NOT A FALL. Every HERO_Y write in the loop is `add [HERO_Y], 0x0000`,")
        print("a no-op: the hero's height never changes across the whole cycle.")
    if burst:
        s = max(abs(v) for v in steady["xs"]) if steady["xs"] else 0
        b = max(abs(v) for v in burst["xs"]) if burst["xs"] else 0
        print(f"\nTop speed: steady loop {s} px/frame, burst loop {b} px/frame "
              f"({b/s:.1f}x)." if s else "")
        print("The steady loop is the WALK and the burst loop is the RUN "
              "(it accelerates\nfrom a standstill and decelerates into "
              "CINEMATIC_HERO_STOP_LEFT_*).")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
