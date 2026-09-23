#!/usr/bin/env python3
"""Which pieces are drawn with a named body frame, but only under a guard?

Question answered
-----------------
`arm_case_table.py` reads a switch where each case draws one arm. This is the
other shape the same idea takes, and it is far more common:

    CAPSULE_HERO_RUN_RIGHT_DRAW_8:
        video type=0, offset=HERO_RUN_RIGHT_BODY_F08, x=[HERO_X], ...
        jne [0x0A], 0x00, DRAW_CV_265        <- a companion, only when armed

The frame number does not come from the routine's name. It comes from the
**art**: `HERO_RUN_RIGHT_BODY_F08` is already named, from a separate line of
evidence, so a routine drawing exactly one member of a named `*_BODY_F<n>`
family plus a guarded piece fixes that piece's frame without trusting any
routine label. That is what makes this usable where the routine names are
placeholders, which is most of what is left.

A piece appearing at several frames is a shared sub-piece and cannot take a
frame-indexed name -- see `../actor-sprite-sheet/` -- but the SET of frames
it serves is exactly what a pose-indexed name needs.

Signals read
------------
    `*_BODY_F<n>`   a named body family member; exactly one per routine, or
                    the frame is ambiguous and the routine is skipped
    the guard       `jne`/`je [var], value, target`, and the first `type=0`
                    draw inside `target`
    coverage        whether the frames found run 0..max with no gap, which
                    is what separates a nameable family from a held one

Usage
-----
    python3 notes/gun-arm-dispatch/guarded_companions.py
    python3 notes/gun-arm-dispatch/guarded_companions.py --family CV_FIGURE_RUN_RIGHT_BODY
"""
from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2] / "src" / "levels"
ARCH = HERE.parents[3] / "another-world-archaeology"
sys.path.insert(0, str(ARCH / "tools"))
sys.path.insert(0, str(HERE.parents[1] / "polygon-extent-correction"))
from polygon_tree import parse_polygon_tree                   # noqa: E402
from polygon_extent import extent                             # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]
RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
RE_BODY = re.compile(r"offset=([A-Za-z_][A-Za-z0-9_]*_BODY_F(\d+))")
# `0x0+` and not `0x0000`: the source writes `0x00`, and requiring four
# digits made a first version of this sweep report nothing at all.
RE_GUARD = re.compile(r"(jne|je|jg|jl|jge|jle)\s+\[(0x[0-9A-Fa-f]+)\],"
                      r"\s*([^,]+),\s*([A-Za-z_][A-Za-z0-9_]*)")
RE_T0 = re.compile(r"video type=0, offset=(CV_[0-9A-F]{4})")


def sweep():
    fam: dict = collections.defaultdict(lambda: collections.defaultdict(set))
    guards: dict = collections.defaultdict(collections.Counter)
    for _port, br in PORTS.items():
        for stage in STAGES:
            p = SRC / br / f"{stage}.asm"
            if not p.is_file():
                continue
            lines = p.read_text(errors="replace").splitlines()
            first: dict[str, str] = {}
            cur = None
            for line in lines:
                m = RE_LBL.match(line)
                if m:
                    cur = m.group(1)
                    continue
                d = RE_T0.search(line)
                if d and cur and cur not in first:
                    first[cur] = d.group(1)
            cur, buf = None, []

            def flush(buf):
                bodies = [m for l in buf for m in RE_BODY.finditer(l)]
                gs = [m for l in buf for m in RE_GUARD.finditer(l)]
                if len(bodies) != 1 or not gs:
                    return
                base = re.sub(r"_F\d+$", "", bodies[0].group(1))
                frame = int(bodies[0].group(2))
                for g in gs:
                    cv = first.get(g.group(4))
                    if cv:
                        fam[base][cv].add(frame)
                        guards[base][f"{g.group(1)} [{g.group(2)}], "
                                     f"{g.group(3).strip()}"] += 1

            for line in lines:
                m = RE_LBL.match(line)
                if m:
                    flush(buf)
                    cur, buf = m.group(1), []
                elif cur is not None:
                    buf.append(line)
            flush(buf)
    return fam, guards


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--family")
    args = ap.parse_args()
    fam, guards = sweep()
    if not fam:
        print("no body family has a guarded companion")
        return 0

    p = ARCH / "tmp" / "output" / "amiga" / "resources" / "resource-0x11.bin"
    bank = p.read_bytes() if p.is_file() else None

    for base in sorted(fam):
        if args.family and base != args.family:
            continue
        frames = sorted({f for v in fam[base].values() for f in v})
        complete = frames == list(range(0, max(frames) + 1))
        g = ", ".join(f"{k} ({v})" for k, v in guards[base].most_common(3))
        print(f"\n{base}   {len(fam[base])} piece(s), frames {frames}"
              f"   {'COMPLETE' if complete else 'GAPPED'}")
        print(f"  guard: {g}")
        if bank:
            print(f"    {'piece':<9}{'top':>8}{'bottom':>9}{'height':>8}"
                  f"{'lv':>4}  frames")
        for cv in sorted(fam[base], key=lambda c: min(fam[base][c])):
            row = ""
            if bank:
                x0, y0, x1, y1, lv = extent(
                    parse_polygon_tree(bank, int(cv[3:], 16)))
                row = f"{y0:>8.1f}{y1:>9.1f}{y1 - y0:>8.1f}{lv:>4}  "
            print(f"    {cv:<9}{row}{sorted(fam[base][cv])}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
