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

  4. **The other direction: one offset, one name.** Checks 1-3 all ask whether
     a *name* denotes one offset. They cannot see the opposite failure, where
     one offset is referred to by several names, and that failure is present:
     137 of 358 drawn bank offsets carry more than one name. A shared-bank
     offset is identified here as one drawn by `video type=0`, which selects
     the video2 bank -- plain `video` selects the per-stage cinematic bank, so
     the *same numeric offset* legitimately names different pictures in the
     two and comparing EQU values without that discriminator reports 105
     "duplicates" that are nothing of the kind.

Two causes, reported separately because only one is actionable:

  - **`COMMON_VIDEO_nnn` in the GBA branch.** T7's re-key covered 225 files
    and left `foxy_gba_2004_*.asm` alone. That release packages its art
    differently and has no extracted resource `0x11`, so the old names there
    are not obviously wrong -- but the offset still has two names tree-wide.
  - **Address-shaped aliases in the shared `_unified/_helpers/DRAW_CV_*.inc`
    chunks**: `ADDR_AT_00B4`, `LABEL_0128`, `DELAY_LOOP_VARED_AT_0844`,
    `HANG_DRAW_CIN_003_AT_125A`, `STATE_VAR12_BIG_DISPATCH_CASE_30_AT_2D4E`
    and others -- code-label spellings used as polygon operands, which the
    re-key did not reach. These alias offsets that everywhere else use the
    key, so the same picture is `CV_00B4` in seventeen files and
    `ADDR_AT_00B4` in one.

    Merging them is **not** a global token replace: `LABEL_0128` is also a
    real code label in dos/CAPSULE, and the two uses are unrelated. It has to
    be done per definition site, with the canonical name proven defined for
    every branch that reaches the chunk through the include graph.

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

    # Check 4: one offset, one name. `video type=0` is the bank discriminator.
    re_t0 = re.compile(r"\bvideo\s+type=0,\s*offset=([A-Za-z_]\w*)")
    drawn_t0: set[str] = set()
    for f in files:
        drawn_t0 |= set(re_t0.findall(f.read_text(errors="replace")))
    at_off: dict[str, set] = collections.defaultdict(set)
    for name in drawn_t0:
        v = vals.get(name)
        if v and len(v) == 1:
            at_off[next(iter(v))].add(name)
    dup = {o: ns for o, ns in at_off.items() if len(ns) > 1}
    gba_only = {o for o, ns in dup.items()
                if len({n for n in ns if not n.startswith("COMMON_VIDEO_")}) == 1}
    alias = {o: ns for o, ns in dup.items() if o not in gba_only}
    print(f"\n{len(at_off)} bank offsets are drawn under a name; {len(dup)} "
          f"carry more than one:")
    print(f"  {len(gba_only):4d}  a COMMON_VIDEO_nnn survivor in the GBA "
          f"branch, which T7's re-key did not cover")
    print(f"  {len(alias):4d}  an address-shaped alias in a shared helper "
          f"chunk (actionable)")
    for o, ns in sorted(alias.items())[:40]:
        extra = sorted(n for n in ns
                       if not RE_KEY.match(n)
                       and not n.startswith("COMMON_VIDEO_"))
        canon = sorted(n for n in ns if RE_KEY.match(n)) or ["(none)"]
        print(f"      {o:<8} {canon[0]:<26} also: {', '.join(extra)}")

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
        print("(check 4, one-offset-one-name, is reported but not failed on: "
              "the aliases\npredate this probe and merging them is a separate, "
              "per-site change.)")
        return 1
    print("\nEvery shared-bank name denotes exactly one offset in every file.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
