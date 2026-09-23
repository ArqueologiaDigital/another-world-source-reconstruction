#!/usr/bin/env python3
"""Name every picture painted while a screen is being entered.

Question answered
-----------------
`screen_entry.py` named 264 `<STAGE>_SCREEN_<NN>_ENTRY` routines. Each has the
same shape: write the camera bounds, tear down the previous screen's channels,
`setPalette`, **paint the backdrop**, and only then `setup` the threads that
animate the screen. The `setup` is the line between static and moving: nothing
drawn before it is animated by anything, because nothing is running yet.

So the pictures an entry draws before its first `setup` -- directly or through
routines it calls -- are that screen's painted background, in the order they
go down. This names them.

    CINEMATIC_<STAGE>_SCREEN_<NN>_BACKDROP_LAYER_<i>

`i` is the position in that sequence: the machine's own order, not an index a
namer chose. A picture is named only when it is in the backdrop phase of
**exactly one** screen; 72 of 288 appear in two or more and are left numbered,
because a shared layer belongs to no single screen (the same reason screens
0x92 and 0x93 kept their shared base numbered in `../remaining-art/`).

Why this index and not the composite's
--------------------------------------
`../remaining-art/by_anchor.py` named 73 layers earlier by their position
inside a `fill`-led composite. Those two orders are derived from different
things and they agree in **57 of 60** cases where both exist -- an independent
check on both, since one counts draws inside one routine and the other counts
the whole phase across several.

The 3 that disagree are screens where the entry paints something before or
after the composite, so the composite's internal index is not the phase
position: `CAPSULE_SCREEN_4B` (composite index 2, phase position 3) and
`CAPSULE_SCREEN_6D` (0 and 1, phase positions 7 and 8). Phase position is the
more general of the two -- it is defined for every painted picture, not only
for those inside a composite -- so this module renumbers those three and every
layer in the tree ends up on one scheme.

Pass/fail
---------
`--check` exits 1 if two different pictures in one screen would take the same
index, which is the property that must hold. Contiguity must NOT be required:
a shared layer is skipped and leaves a hole, exactly as in
`../remaining-art/`, and the hole is the information that the position is
occupied by a picture belonging to more than one screen.

Usage
-----
    python3 notes/screen-scope/backdrop_phase.py
    python3 notes/screen-scope/backdrop_phase.py --check
    python3 notes/screen-scope/backdrop_phase.py --proposals
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
sys.path.insert(0, str(HERE.parent))
import screen_scope as S                                     # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992",
         "cart": "cartridge_1992"}
STAGES = ("PRISON", "CAVES", "CAPSULE")

RE_V = re.compile(r"^\s*video\s+(?:type=\d+,\s*)?offset="
                  r"([A-Za-z_][A-Za-z0-9_]*)")
RE_CALL = re.compile(r"^\s*call\s+([A-Za-z_][A-Za-z0-9_]*)")
RE_SETUP = re.compile(r"^\s*setup\s")
RE_NUM = re.compile(r"^CINEMATIC_\d+$")
RE_ENTRY = re.compile(r"^([A-Z_]+)_SCREEN_([0-9A-F]{2})_ENTRY$")
RE_LAYER = re.compile(r"^CINEMATIC_([A-Z_]+)_SCREEN_([0-9A-F]{2})"
                      r"_BACKDROP_LAYER_(\d+)$")
MAX_DEPTH = 3


def bodies(lines):
    out, cur = collections.defaultdict(list), None
    for line in lines:
        if m := S.RE_LBL.match(line):
            cur = m.group(1)
        elif cur:
            out[cur].append(line)
    return out


def drawn_by(body, lab, depth=0, seen=None):
    """Pictures a routine paints, in order, following `call` only."""
    seen = seen or set()
    if lab in seen or depth > MAX_DEPTH:
        return []
    seen = seen | {lab}
    out = []
    for line in body.get(lab, []):
        if v := RE_V.match(line):
            out.append(v.group(1))
        elif c := RE_CALL.match(line):
            out += drawn_by(body, c.group(1), depth + 1, seen)
    return out


def phases(lines):
    """entry label -> the ordered pictures it paints before its first setup."""
    body = bodies(lines)
    out = {}
    for lab in sorted(body):
        if not RE_ENTRY.match(lab):
            continue
        seq = []
        for line in body[lab]:
            if RE_SETUP.match(line):
                break
            if v := RE_V.match(line):
                seq.append(v.group(1))
            elif c := RE_CALL.match(line):
                seq += drawn_by(body, c.group(1), 1)
        if seq:
            out[lab] = seq
    return out


def scan():
    """(branch, stage, old, new) plus the counters, over all three branches."""
    rows, stats = [], collections.Counter()
    for port, branch in PORTS.items():
        for stage in STAGES:
            lines = S.load(port, stage)
            if lines is None:
                continue
            ph = phases(lines)
            owners = collections.defaultdict(set)
            for lab, seq in ph.items():
                for const in seq:
                    owners[const].add(lab)
            names = {n for n in re.findall(
                r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU", "\n".join(lines), re.M)}
            for lab, seq in sorted(ph.items()):
                m = RE_ENTRY.match(lab)
                # A picture painted twice in one phase has no single
                # position, so it cannot take a position-indexed name --
                # CAPSULE screen 0x92 paints CINEMATIC_557 at positions 1
                # and 6. Same shape as a limb piece shared between frames in
                # ../actor-sprite-sheet/: what is shared has no index.
                twice = {c for c, n in collections.Counter(seq).items()
                         if n > 1}
                for i, const in enumerate(seq):
                    if const in twice:
                        stats["painted twice in the same phase"] += 1
                        continue
                    if len(owners[const]) != 1:
                        stats["in several screens' backdrop phase"] += 1
                        continue
                    new = (f"CINEMATIC_{stage}_SCREEN_{m.group(2)}"
                           f"_BACKDROP_LAYER_{i}")
                    if const == new:
                        stats["already correct"] += 1
                        continue
                    if RE_NUM.match(const):
                        stats["** still numbered, nameable"] += 1
                    elif RE_LAYER.match(const):
                        stats["** a layer name whose index is not the "
                              "phase position"] += 1
                    else:
                        stats["named something else, left alone"] += 1
                        continue
                    if new in names and new != const:
                        stats["derived name already taken"] += 1
                        continue
                    rows.append((branch, stage, const, new, lab, i))
    return rows, stats


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--proposals", action="store_true")
    args = ap.parse_args()
    rows, stats = scan()

    if args.check:
        taken = {}
        clash = 0
        for branch, stage, old, new, _lab, _i in rows:
            key = (branch, stage, new)
            if key in taken and taken[key] != old:
                print(f"  ** {branch}/{stage}: {taken[key]} and {old} would "
                      f"both become {new}", file=sys.stderr)
                clash += 1
            taken[key] = old
        print(f"  {len(rows)} rename(s), {clash} index clash(es)")
        return 1 if clash else 0

    if args.proposals:
        by: dict[tuple, list] = {}
        for branch, stage, old, new, lab, i in rows:
            by.setdefault((branch, stage), []).append((old, new, lab, i))
        for (branch, stage), rs in sorted(by.items()):
            print(f"\n----- {branch} / {stage} -----")
            print("| constant | proposed name | confidence | evidence |")
            print("| --- | --- | --- | --- |")
            for old, new, lab, i in rs:
                print(f"| {old} | {new} | high | `{lab}` paints it at "
                      f"position {i} of the sequence it draws before its "
                      f"first `setup`, i.e. before anything is animating; no "
                      f"other screen's entry paints it |")
        return 0

    for k, v in stats.most_common():
        print(f"  {v:>5}  {k}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
