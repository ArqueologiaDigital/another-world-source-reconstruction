#!/usr/bin/env python3
"""Animation threads: a `setup` target whose whole body is a run of draws.

Question answered
-----------------
The CAVES trap columns were named from a `setup` block that installs a named
watch loop and an unnamed draw thread on adjacent channels:

    mov [0x68], 0x005E                                   <- slot 0's position
    setup channel=0x22, address=CAVES_TRAP_COLUMN_WATCH_SLOT_0_LOOP
    setup channel=0x23, address=LABEL_2DAC               <- its draw thread
    mov [0x6A], 0x0064                                   <- slot 1's position
    setup channel=0x24, address=CAVES_TRAP_COLUMN_WATCH_SLOT_1_LOOP
    setup channel=0x25, address=LABEL_2E0C

The named neighbour says what the thread animates and the channel pairing
says which instance. This sweeps for that shape, and for the population it
belongs to.

What it finds
-------------
Over both priority ports, **126** unnamed threads draw a run of three or more
still-numbered constants and nothing else -- the shape of an animation. Only
**4** sit beside a named routine that is not itself a mechanism; the ones
that neighbour `KILL_CHANNEL_LANDING` are excluded, because naming a
mechanism says nothing about a subject.

So the trap columns were the good case and not a seam: the remaining **122**
have no naming anchor in their setup block at all. They are a
well-characterised population rather than a lead -- each is a short animation
at a known slot, and what they need is to be recognised, which is the render
problem this project keeps running into.

One worked example of that difficulty is recorded rather than guessed at.
`LABEL_3813` in CAVES draws eleven frames at `[HERO_X],[HERO_Y]`, installed
at stage init on the channel right after `HERO_DIRECTION_LEFT_IDLE_ENTRY` --
everything about the context says "hero animation". Rendered, the frames are
1-2 path slivers between 4x3 and 16x6: flat angular wedges, not a figure.
Debris, a dropped object and sparks all fit. It is left numbered.

Usage
-----
    python3 notes/substitute-layers/draw_threads.py
    python3 notes/substitute-layers/draw_threads.py --anchored
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
from naming_census import classify                           # noqa: E402

BRANCHES = ("chahi_amiga_1991", "dos_1992")
RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
RE_SETUP = re.compile(r"^\s*setup\s+channel=(0x[0-9A-Fa-f]+),\s*"
                      r"address=([A-Za-z_][A-Za-z0-9_]*)")
RE_NUMV = re.compile(r"^\s*video\s+(?:type=\d+,\s*)?offset=(CINEMATIC_\d+),")
RE_ANYV = re.compile(r"^\s*video\s+(?:type=\d+,\s*)?offset="
                     r"([A-Za-z_][A-Za-z0-9_]*),")
MIN_FRAMES = 3
NEAR = 2
# A neighbour that names a mechanism says nothing about the subject.
MECHANISM = ("KILL_CHANNEL", "NOOP", "SHARED_RET", "DELETE", "TEARDOWN")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--anchored", action="store_true",
                    help="only threads beside a named, non-mechanism routine")
    args = ap.parse_args()

    stats = collections.Counter()
    rows = []
    for branch in BRANCHES:
        for f in sorted((SRC / "src" / "levels" / branch).glob("[A-Z]*.asm")):
            lines = f.read_text(errors="replace").splitlines()
            body: dict[str, list] = collections.defaultdict(list)
            cur = None
            for line in lines:
                if m := RE_LBL.match(line):
                    cur = m.group(1)
                elif cur:
                    body[cur].append(line)
            run: list = []
            for line in lines + [""]:
                m = RE_SETUP.match(line)
                if m:
                    run.append((int(m.group(1), 16), m.group(2)))
                    continue
                if not line.strip() or re.match(r"^\s*mov ", line):
                    continue
                if len(run) >= 2:
                    named = [(c, a) for c, a in run
                             if classify(a) == "semantic"
                             and not any(t in a for t in MECHANISM)]
                    for ch, addr in run:
                        if classify(addr) == "semantic":
                            continue
                        b = body.get(addr, [])
                        nums = [v.group(1) for x in b
                                if (v := RE_NUMV.match(x))]
                        allv = [v.group(1) for x in b
                                if (v := RE_ANYV.match(x))]
                        if len(nums) < MIN_FRAMES or len(nums) != len(allv):
                            continue
                        near = [a for c, a in named if abs(c - ch) <= NEAR]
                        if near:
                            stats["** beside a named, non-mechanism routine"] += 1
                            rows.append((branch, f.stem, addr, near[0],
                                         len(nums), nums[0], nums[-1]))
                        else:
                            stats["no naming anchor in its setup block"] += 1
                            if not args.anchored:
                                rows.append((branch, f.stem, addr, None,
                                             len(nums), nums[0], nums[-1]))
                run = []

    for k, v in stats.most_common():
        print(f"  {v:>5}  {k}")
    print()
    seen = set()
    for branch, stage, addr, near, n, a, b in rows:
        if (branch, stage, addr) in seen:
            continue
        seen.add((branch, stage, addr))
        tail = f"   beside {near}" if near else ""
        print(f"    {branch.split('_')[0]:<6}{stage:<9}{addr:<24}"
              f"{n:>3} frames {a}..{b}{tail}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
