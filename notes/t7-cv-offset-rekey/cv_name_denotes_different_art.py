#!/usr/bin/env python3
"""Does one COMMON_VIDEO name mean one picture?

Question answered
-----------------
`notes/shared-bank-probes/` proves the shared bank is a single file: resource
0x11 is 25,108 bytes with an identical sha256 on amiga and msdos. That is T7's
premise, and it is true.

It is tempting to read it as "so an offset means the same art on both ports,
therefore the bank is safe territory". The first half is right. This probe is
about what the second half does *not* follow from, and it decides how T7's
interim `CV_<OFFSET4>` step has to be built.

`COMMON_VIDEO_099` is one name. The unified tree references it from
`_unified/_helpers/DRAW_CV_099.inc`, a chunk shared by every branch and
sitting outside any `.if`. But the EQU that gives it a value lives in a
**branch-specific** chunk, and the values are not the same:

    amiga  COMMON_VIDEO_099 EQU 0x037C
    msdos  COMMON_VIDEO_099 EQU 0x3674

Since the bank is one file, two offsets are two places in it, and this reads
the bytes at each to see whether they are the same picture.

What is measured
----------------
For every `COMMON_VIDEO_*` name defined in both amiga's and msdos's copy of a
stage, the two offsets, and -- when they differ -- the first 32 bytes of the
bank at each.

  offsets equal            the name denotes one place, so one picture
  offsets differ, bytes equal   two places holding the same record
  offsets differ, bytes differ  **the name denotes two different pictures**

Result, 2026-09-19
------------------
    352 distinct (name, amiga offset, msdos offset) triples
      6 offsets equal
    346 offsets differ -- and 0 of those have matching bank bytes

So **346 of 352 canonical names denote different art on the two ports.**

Why this matters more than it sounds
------------------------------------
1. It is why `docs/NAMING.md` §2 forbids hand-naming `COMMON_VIDEO_NNN`, and
   the reason is stronger than "the numbering is arbitrary": the name is not
   a per-port alias for one picture, it is **two pictures under one label**.
   Any semantic name earned by rendering one port's art would be wrong for
   the other -- #0107, structurally built into the shared tree.

2. It constrains T7. Keying by offset makes the name port-specific for 346 of
   352 entries, and the unified tree makes **3,205** references to these names
   from code outside any `.if`. A straight rename would leave every one of
   those references resolving to a name only one branch defines. T7's interim
   step therefore cannot be a rename: either those chunks gain branch arms --
   de-unifying the thing the unified tree exists to unify -- or the emitter
   change comes first and the tree is regenerated around offset keys.

   `rekey_common_video_by_offset.py` beside this file performs the rename and
   is deliberately **not run**: it handles per-branch `.asm` files correctly
   and has nothing to say about the 3,205 shared references, and applying half
   would leave the two representations disagreeing about 979 names.

3. It does not contradict `cv_offset_is_port_invariant.py`. That probe pairs
   *routines* by body and finds their CV **offsets** agree, 71 times with no
   disagreement. Those are cases where the two ports reach the same art
   through different index names. The population here is the opposite one:
   the same index name on both ports. Both are true, and together they say the
   art correspondence lives in the offsets and never in the indices.

Input
-----
Needs the extracted bank at
`another-world-archaeology/tmp/output/<port>/resources/resource-0x11.bin`,
which is volatile; regenerate with `python3 tools/aw_unpacker.py` from that
repo. The expected hash is recorded in
`notes/shared-bank-probes/shared_bank_bytes_identical.py`.

Exit status
-----------
0 on a successful measurement, 2 if the bank is not extracted.

Usage
-----
    python3 notes/t7-cv-offset-rekey/cv_name_denotes_different_art.py
    python3 notes/t7-cv-offset-rekey/cv_name_denotes_different_art.py --list 20
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SRC = ROOT / "src" / "levels"
BANK = (ROOT.parent / "another-world-archaeology" / "tmp" / "output"
        / "amiga" / "resources" / "resource-0x11.bin")
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]
RE_EQU = re.compile(r"^(COMMON_VIDEO_[A-Za-z0-9_]+)\s+EQU\s+(0x[0-9A-Fa-f]+)\s*$")
WINDOW = 32


def table(branch: str, stage: str) -> dict[str, int]:
    f = SRC / branch / f"{stage}.asm"
    out: dict[str, int] = {}
    if f.is_file():
        for line in f.read_text(errors="replace").splitlines():
            m = RE_EQU.match(line)
            if m:
                out[m.group(1)] = int(m.group(2), 16)
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--list", type=int, default=0)
    args = ap.parse_args()

    if not BANK.is_file():
        print(f"bank not extracted at {BANK}")
        print("regenerate: cd another-world-archaeology && "
              "python3 tools/aw_unpacker.py")
        return 2
    bank = BANK.read_bytes()

    seen: set[tuple[str, int, int]] = set()
    eq = diff_same = diff_diff = 0
    rows = []
    for stage in STAGES:
        a, d = table("chahi_amiga_1991", stage), table("dos_1992", stage)
        for n in sorted(set(a) & set(d)):
            key = (n, a[n], d[n])
            if key in seen:
                continue
            seen.add(key)
            if a[n] == d[n]:
                eq += 1
                continue
            same = bank[a[n]:a[n] + WINDOW] == bank[d[n]:d[n] + WINDOW]
            if same:
                diff_same += 1
            else:
                diff_diff += 1
                rows.append((stage, n, a[n], d[n]))

    print(f"{len(seen)} distinct (name, amiga offset, msdos offset) triple(s)")
    print(f"  {eq:4d} offsets equal -- one place, one picture")
    print(f"  {diff_same:4d} offsets differ but the first {WINDOW} bank bytes "
          f"match")
    print(f"  {diff_diff:4d} offsets differ AND the bank bytes differ "
          f"<- two pictures, one name")
    for stage, n, ao, do in rows[:args.list]:
        print(f"      {stage:<8} {n:<20} amiga 0x{ao:04X}  msdos 0x{do:04X}")
        print(f"               amiga {bank[ao:ao + 12].hex(' ')}")
        print(f"               msdos {bank[do:do + 12].hex(' ')}")
    if diff_diff:
        print(f"\n{diff_diff} of {len(seen)} canonical COMMON_VIDEO names "
              f"denote DIFFERENT art on the two\nports. The name is not a "
              f"per-port alias for one picture. See this file's\ndocstring "
              f"for what that means for T7.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
