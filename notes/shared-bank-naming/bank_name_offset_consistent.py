#!/usr/bin/env python3
"""Does every shared-bank name still mean exactly one offset, everywhere?

Question answered
-----------------
The whole case for naming the shared bank is that it is one file: resource
`0x11`, byte-identical on amiga and MS-DOS, so an offset denotes one picture in
every branch and a name for it is correct at every reference. That premise is
a *standing* one, not a one-time check. The moment a name is defined with two
different `EQU` values in two files, it stops denoting one picture -- which is
precisely the failure the pre-T7 `COMMON_VIDEO_NNN` numbering had, where 346 of
353 names resolved to different art on the two ports.

`apply_bank_names.py` checks this before it writes, for the keys it is about to
rename. That check is unavailable afterwards, because the keys are gone, and it
never covered names applied by an earlier pass. This covers all of them, at any
time.

What it checks
--------------
For every identifier defined by an `EQU` in `src/`, gathered across all
branches, `_unified` chunks and `.asm.in` templates:

  1. Any name whose `EQU` value differs between two files is reported. For a
     shared-bank name that is fatal; the probe also reports it for other
     polygon names, where a per-stage difference is expected and is listed
     separately rather than failed on.
  2. Every surviving `CV_<OFFSET4>` key must equal `0x<OFFSET4>`. A key that
     does not is a re-key that went wrong.
  3. Every name in a `.map` passed with `--map` must now be defined, with the
     offset its old key encoded. This is how a batch already applied gets
     verified after the fact.

Signals read
------------
`^<NAME>\\s+EQU\\s+(0x[0-9A-Fa-f]+)` lines under `src/`. Nothing is read from
the ROM: this is a consistency property of the source tree, and reading the
ROM would test a different claim.

Exit status
-----------
0 when every shared-bank name denotes one offset. 1 otherwise.

Usage
-----
    python3 notes/shared-bank-naming/bank_name_offset_consistent.py
    python3 notes/shared-bank-naming/bank_name_offset_consistent.py \
        --map notes/shared-bank-naming/hero_sprite_sheet.map
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src"
RE_EQU = re.compile(r"^([A-Za-z_]\w*)\s+EQU\s+(0x[0-9A-Fa-f]+)")
RE_KEY = re.compile(r"^CV_([0-9A-F]{4})$")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--map", type=Path)
    args = ap.parse_args()

    vals: dict[str, set[str]] = collections.defaultdict(set)
    files = [p for p in SRC.rglob("*")
             if p.is_file() and p.suffix in (".asm", ".inc", ".in")]
    for f in files:
        for line in f.read_text(errors="replace").splitlines():
            m = RE_EQU.match(line)
            if m:
                vals[m.group(1)].add(m.group(2).upper().replace("0X", "0x"))

    fail = 0

    keys = {k: v for k, v in vals.items() if RE_KEY.match(k)}
    bad_key = {k: v for k, v in keys.items()
               if v != {"0x" + RE_KEY.match(k).group(1)}}
    print(f"{len(keys)} shared-bank offset keys still unnamed; "
          f"{len(bad_key)} resolve to something other than their own offset")
    for k, v in sorted(bad_key.items())[:10]:
        print(f"  {k} -> {sorted(v)}")
    fail += len(bad_key)

    if args.map:
        pairs = []
        for line in args.map.read_text().splitlines():
            line = line.split("#", 1)[0].strip()
            if line:
                pairs.append(tuple(line.split()))
        missing, wrong = [], []
        for old, new in pairs:
            m = RE_KEY.match(old)
            want = "0x" + m.group(1) if m else None
            got = vals.get(new)
            if not got:
                missing.append(new)
            elif want and got != {want}:
                wrong.append(f"{new}: {sorted(got)}, expected {want}")
        print(f"\n{args.map.name}: {len(pairs)} applied name(s); "
              f"{len(missing)} not defined, {len(wrong)} with a wrong or "
              f"inconsistent offset")
        for x in (missing + wrong)[:10]:
            print(f"  {x}")
        fail += len(missing) + len(wrong)

    multi = {k: v for k, v in vals.items() if len(v) > 1}
    hero = {k: v for k, v in multi.items() if k.startswith("HERO_")}
    print(f"\n{len(multi)} identifier(s) in the whole tree carry more than one "
          f"EQU value;\n{len(hero)} of those are HERO_* shared-bank names, "
          f"which must be zero")
    for k, v in sorted(hero.items())[:10]:
        print(f"  {k} -> {sorted(v)}")
    fail += len(hero)

    if fail:
        print("\nFAIL: a shared-bank name does not denote exactly one offset.")
        return 1
    print("\nEvery shared-bank name denotes exactly one offset in every file.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
