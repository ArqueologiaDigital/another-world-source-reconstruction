#!/usr/bin/env python3
"""Does each beam-span rung's name match the threshold that selects it?

Question answered
-----------------
PRISON, CAVES and CAPSULE each hold the same routine -- `<branch>__post_COPY_-
VAR27_TO_VAR07.inc` in all three -- which draws a shot as a pair of 1-pixel-tall
horizontal bars, one extending right from `[0x21]` and one extending left from
`[0x22]`, picked from a ladder by the span between them:

    [0x26] = [0x22] - [0x21]
    jl [0x26], 0x7E -> ...        ; 126
      jge [0x12], 0x2000 -> ...   ; a second set at the two longest widths
      video <right>, x=[0x21]
      video <left>,  x=[0x22]

The thresholds are `0x02, 0x06, 0x0E, 0x1E, 0x3E, 0x7E` = 2, 6, 14, 30, 62, 126,
each `2n + 2` of the one below, and **each equals the drawn width of the pair it
selects**. So the rung index is not a guess: it is the position in that sequence,
and it is checkable against the art.

This walks the routine, pairs every threshold with the constants it draws,
measures those constants, and reports three things per row:

  * the threshold, and the measured width -- they should be equal;
  * whether a named constant's `_<n>` suffix matches its position in the ladder;
  * which side it is drawn on, `x=[0x21]` being right and `x=[0x22]` left.

What it found, 2026-09-23
-------------------------
Every rung in both priority ports, in all three stages, is in its right place.
Once the rows are read correctly there is not a single `**`.

Getting them read correctly took two corrections, and both are the point of
this file:

**1. The `0x2000` arm runs when the bit is CLEAR.** `jge [0x12], 0x2000, T`
jumps *away* to `T`, so the block that contains the test is the bit-clear path
and `T` is the bit-set one. Labelling them the other way round made the default
ladder look like the exception.

**2. A unified routine must be resolved against the unified EQU tables.** The
body walked here comes from `src/levels/_unified/<stage>/<arm>__post_*.inc`.
Resolving its symbols against `src/levels/<branch>/<STAGE>.asm` reported msdos
CAVES' entire ladder as misplaced, `CINEMATIC_TELEPORT_UP_BEAM_LEFT` as a
6-pixel beam rung and amiga CAPSULE's `SCREEN_91_BACKDROP_LAYER_3` as a
224-pixel one. All of it was false. The two trees do not always carry the same
name for one offset, and 452 semantic names in the canonical files appear
nowhere in the corresponding unified stage directory (TANK 330 of them, msdos
CAVES 20, LAKE 9 per branch). Both trees assemble byte-identically, so no gate
sees it.

    A name means what the tree it was read from says it means. Never resolve a
    body from one tree against a table from the other.

The tool now resolves unified-first and **reports the disagreements** rather
than silently picking one.

What the ladder is, as measured
-------------------------------
Widths 2, 6, 14, 30, 62, 126, each `2n + 2` of the one below, selected by
thresholds `0x02, 0x06, 0x0E, 0x1E, 0x3E, 0x7E` -- the same numbers. Two
exceptions, neither a defect:

  * the `0x64` (100) rung reuses the 62 pair, there being no 100-wide art;
  * below `0x02` a single 0-wide dot is drawn on the right slot only, which
    PRISON names `CINEMATIC_PRISON_SHOT_BEAM_SINGLE_DOT`.

The `bit set` arm is a **second set at 62 and 126 only**, in a different colour
index -- at PRISON's palette 2, `#fb6487` where the default is `#a74400`.
`amiga__post_STEP_VAR29_DOWN10_SET_VAR2F_11.inc` sets that bit for the scripted
beam drawn between `[BUDDY_X]` and `[HERO_X]`. Those four constants per stage
were left numbered on purpose: the fact is established, the cause is not, and a
colour word under a palette that varies is not a name.

Usage
-----
    python3 notes/beam-span-ladder/rung_thresholds.py
    python3 notes/beam-span-ladder/rung_thresholds.py --port msdos --stage PRISON
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT.parent / "another-world-archaeology" / "tools"))
from _paths import REPO_ROOT                                # noqa: E402
from polygon_tree import parse_polygon_tree                 # noqa: E402
from polygon_extent import extent                           # noqa: E402

BRANCH = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992",
          "genesis_europe": "cartridge_1992"}
ARM = {"amiga": "amiga", "msdos": "dos", "genesis_europe": "cart"}
STAGE_ID = {"PRISON": 3, "CAVES": 4, "CAPSULE": 6}
SLAB = 0x10000
FILE = "{arm}__post_COPY_VAR27_TO_VAR07.inc"
RE_EQU = re.compile(r"^(CINEMATIC_\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)
RE_JL = re.compile(r"^\s*jl \[0x26\], (0x[0-9A-Fa-f]+),")
RE_GATE = re.compile(r"^\s*jge \[0x12\], 0x2000, (\w+)")
RE_VID = re.compile(r"^\s*video offset=(CINEMATIC_\w+), x=\[(0x2[12])\]")
RE_LBL = re.compile(r"^(\w+):")


def width(port: str, stage: str, off: int):
    p = REPO_ROOT / "tmp" / "output" / port / "romset" / "cinematic.rom"
    if not p.is_file():
        return None
    slab = p.read_bytes()[STAGE_ID[stage] * SLAB:(STAGE_ID[stage] + 1) * SLAB]
    t = parse_polygon_tree(slab, off)
    if not t:
        return None
    a = extent(t)
    return a[2] - a[0]


def blocks(text: str):
    """Every straight-line block, as (label, [lines]) in file order."""
    out, cur, name = [], [], "<top>"
    for line in text.splitlines():
        m = RE_LBL.match(line)
        if m:
            out.append((name, cur))
            name, cur = m.group(1), []
        else:
            cur.append(line)
    out.append((name, cur))
    return out


def walk(port: str, stage: str):
    """(threshold, bit, right, left) for every rung the routine dispatches.

    `bit` is what `[0x12] & 0x2000` must be for this block to run. The block
    that *contains* the `jge` runs when the bit is CLEAR -- the jump goes to
    the other one -- which is the opposite of how it reads at a glance and was
    got backwards once here.
    """
    f = (ROOT / "src" / "levels" / "_unified" / stage.lower()
         / FILE.format(arm=ARM[port]))
    if not f.is_file():
        return None
    rows, thr, seen_02 = [], None, False
    gate_of: dict[str, str] = {}
    for label, lines in blocks(f.read_text(errors="replace")):
        pair, bit = {}, gate_of.get(label)
        for line in lines:
            m = RE_JL.match(line)
            if m:
                thr = int(m.group(1), 16)
                continue
            m = RE_GATE.match(line)
            if m:
                gate_of[m.group(1)] = "set"
                bit = "clear"
                continue
            m = RE_VID.match(line)
            if m:
                pair["right" if m.group(2) == "0x21" else "left"] = m.group(1)
        if pair:
            rows.append((thr, bit, pair.get("right"), pair.get("left")))
            if seen_02:
                break                      # the below-0x02 fallback, then stop
            if thr == 0x02:
                seen_02, thr = True, None
    return rows


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", action="append", choices=sorted(BRANCH))
    ap.add_argument("--stage", action="append", choices=sorted(STAGE_ID))
    args = ap.parse_args()
    ports = args.port or ["amiga", "msdos", "genesis_europe"]
    stages = args.stage or ["PRISON", "CAVES", "CAPSULE"]

    bad = 0
    for port in ports:
        for stage in stages:
            rows = walk(port, stage)
            if not rows:
                continue
            # The routine walked above comes from the UNIFIED tree, so its
            # symbols have to be resolved against the unified tree's own EQU
            # tables. The canonical per-branch file does not always agree:
            # a rename applied to one and not synced to the other leaves the
            # same offset under two different names, and resolving a unified
            # body against the canonical table invents defects that are not
            # there (it reported msdos CAVES' whole ladder as misplaced).
            # Canonical is the fallback, and only for names unified lacks.
            equ = {}
            d = ROOT / "src" / "levels" / "_unified" / stage.lower()
            for inc in sorted(d.glob("*.inc")):
                if inc.name.split("__")[0] not in (ARM[port], inc.name):
                    continue
                for n, v in RE_EQU.findall(inc.read_text(errors="replace")):
                    equ.setdefault(n, int(v, 16))
            asm = ROOT / "src" / "levels" / BRANCH[port] / f"{stage}.asm"
            can = {}
            for n, v in RE_EQU.findall(asm.read_text(errors="replace")):
                can.setdefault(n, int(v, 16))
            drift = sorted(n for n, v in can.items()
                           if n in equ and equ[n] != v)
            for n, v in can.items():
                equ.setdefault(n, v)
            print(f"\n=== {port}/{stage}")
            for n in drift:
                print(f"  ! {n} is 0x{equ[n]:04X} in the unified tree and "
                      f"0x{can[n]:04X} in {BRANCH[port]}/{stage}.asm")
            for thr, bit, r, l in rows:
                tag = {"set": " bit set", "clear": "   bit 0",
                       None: "        "}[bit]
                t = f"{thr:#04x}" if thr is not None else "  --"
                cells = []
                for side, name in (("R", r), ("L", l)):
                    if not name:
                        cells.append(f"{side} --"); continue
                    off = equ.get(name)
                    w = width(port, stage, off) if off is not None else None
                    mark = ""
                    if w is None:
                        mark = "  (not measurable)"
                    elif thr is None:
                        mark = f"  w={w:.0f}  (below the ladder)"
                    else:
                        ok = abs(w - thr) < 0.01 or (thr == 0x64 and w == 62)
                        mark = "  ok" if ok else f"  ** w={w:.0f}"
                        if not ok:
                            bad += 1
                    cells.append(f"{side} {name}{mark}")
                print(f"  span >= {t} {tag}  " + "   ".join(cells))
    print("\nWidths are 2, 6, 14, 30, 62, 126 and the thresholds that select "
          "them are the same\nnumbers, so a `**` row is a constant in the "
          "wrong rung. The 0x64 rung is the one\nexception and not a defect: "
          "there is no 100-wide art, so it reuses the 62 pair.\n"
          "`bit 0` and `bit set` are the two sets at 62 and 126, chosen by "
          "[0x12] & 0x2000.")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
