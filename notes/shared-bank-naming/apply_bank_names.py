#!/usr/bin/env python3
"""Name shared-bank art, once, for every port at the same time.

Why this can exist now
----------------------
`docs/NAMING.md` §2 forbade hand-naming the shared bank "until that lands",
where "that" is plan item T7. T7's source half landed on 2026-09-19: the bank
is re-keyed from per-port encounter order to `CV_<OFFSET4>`, which is
port-invariant because the bank is literally one file (resource 0x11, 25,108
bytes, identical sha256 on both priority ports).

That is what makes naming worth doing. Before, identifying a picture told you
about `COMMON_VIDEO_099` on amiga and nothing about msdos, because that same
label is a *different picture* there -- 346 of 353 names denoted different art
across the two ports. Now one identification names the art everywhere, which
is why this script renames globally rather than per branch.

Each key resolves to exactly its own offset in every file by construction, so
a whole-tree token replace is correct here and would not have been before.

How the names were earned
-------------------------
E3, render-before-naming. The bank renders by offset, which is exactly the
key:

    awvm-render-polygons --port amiga --stage 3 --bank video2 \
        --romset tmp/output/amiga/romset --out <dir> --palette 2
    # -> amiga_stage3_group_0x40CA.svg, one file per offset

Rendered, trimmed, enlarged and looked at. See the README beside this file for
the contact sheet recipe and what each shape turned out to be.

What the names deliberately do NOT say
--------------------------------------
**Whose** body it is. These are drawn at `x=[0x07], y=[0x08]` -- the
actor-context slot, whose occupant is chosen by whichever channel filled it
(#0138, and `notes/draw-slot-probes/`). The same shape is drawn by
`CAVES_HERO_PER_FRAME_TICK` and by `CAPSULE_BUDDY_PER_FRAME_TICK`: parallel
code animating whoever that stage has. So the names describe the picture --
a figure, its orientation, its stance -- and claim no character.

They also do not lose the offset: the EQU keeps it
(`CV_FIGURE_PROFILE_STANCE EQU 0x40CA`), so anything can be re-rendered.

Usage
-----
    python3 notes/shared-bank-naming/apply_bank_names.py
    python3 notes/shared-bank-naming/apply_bank_names.py --apply
    python3 notes/shared-bank-naming/apply_bank_names.py --map <file> --apply

`--map` reads `OLD NEW` pairs, one per line, `#` for comments, instead of the
`NAMES` table below. A batch large enough to be generated rather than typed
belongs in a committed map file next to the probe that derived it, so the
derivation and the application are separable and both reviewable;
`hero_sprite_sheet.map` is the first.
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels"

# offset key -> name earned from its render
NAMES = {
    "CV_3E4E": "CV_FIGURE_CROUCH_FACING_LEFT",
    "CV_3F8C": "CV_FIGURE_FRONT_STANCE_WIDE",
    "CV_3FD4": "CV_FIGURE_FRONT_STANCE_NARROW",
    "CV_40CA": "CV_FIGURE_PROFILE_STANCE",
    "CV_40EC": "CV_FIGURE_PROFILE_STRIDE",
    "CV_4132": "CV_FIGURE_CROUCH_FACING_RIGHT",
}

RE_EQU = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s+(0x[0-9A-Fa-f]+)")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--map", type=Path,
                    help="read OLD NEW pairs from a file instead of NAMES")
    args = ap.parse_args()

    names = dict(NAMES)
    if args.map:
        names = {}
        for line in args.map.read_text().splitlines():
            line = line.split("#", 1)[0].strip()
            if not line:
                continue
            parts = line.split()
            if len(parts) != 2:
                raise SystemExit(f"bad map line: {line!r}")
            if parts[0] in names:
                raise SystemExit(f"duplicate source in map: {parts[0]}")
            names[parts[0]] = parts[1]
        dups = [v for v in names.values()
                if list(names.values()).count(v) > 1]
        if dups:
            raise SystemExit(f"duplicate target(s) in map: {sorted(set(dups))}")

    files = sorted(list(SRC.rglob("*.asm")) + list(SRC.rglob("*.asm.in"))
                   + list(SRC.rglob("*.inc")))

    # precondition 1: every key resolves to its own offset, everywhere
    # precondition 2: no target name is already taken
    seen_off: dict[str, set[str]] = {k: set() for k in names}
    taken: set[str] = set()
    for f in files:
        for line in f.read_text(errors="replace").splitlines():
            m = RE_EQU.match(line)
            if not m:
                continue
            if m.group(1) in seen_off:
                seen_off[m.group(1)].add(m.group(2).upper())
            taken.add(m.group(1))

    problems = []
    for key, offs in seen_off.items():
        want = "0X" + key[3:]
        if not offs:
            problems.append(f"{key}: not defined anywhere")
        elif offs != {want}:
            problems.append(f"{key}: resolves to {sorted(offs)}, expected "
                            f"{want}")
    for new in names.values():
        if new in taken:
            problems.append(f"{new}: already defined")
    if problems:
        print("REFUSING:")
        for p in problems:
            print(f"  {p}")
        return 1

    pat = re.compile(r"\b(" + "|".join(sorted(names)) + r")\b")
    total, touched = 0, 0
    for f in files:
        text = f.read_text(errors="replace")
        new, n = pat.subn(lambda m: names[m.group(1)], text)
        if n:
            total += n
            touched += 1
            if args.apply:
                f.write_text(new)
    print(f"{len(names)} name(s), {total} token(s) across {touched} file(s)")
    for k, v in sorted(names.items()):
        print(f"  {k} -> {v}")
    if not args.apply:
        print("dry run -- re-run with --apply")
    return 0


if __name__ == "__main__":
    sys.exit(main())
