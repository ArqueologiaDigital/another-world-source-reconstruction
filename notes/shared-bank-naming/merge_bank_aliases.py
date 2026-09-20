#!/usr/bin/env python3
"""One offset, one name: fold address-shaped bank aliases onto the canonical key.

Question answered
-----------------
`bank_name_offset_consistent.py` check 4 finds that 43 shared-bank offsets are
referred to by an address-shaped alias in a shared `_unified/_helpers/*.inc`
chunk as well as by the canonical key everywhere else -- `ADDR_AT_00B4`,
`LABEL_0128`, `DELAY_LOOP_VARED_AT_0844`, `HANG_DRAW_CIN_003_AT_125A`,
`STATE_VAR12_BIG_DISPATCH_CASE_30_AT_2D4E`. T7's re-key did not reach them.

That breaks the premise the whole shared-bank naming rests on: identify the art
once and the name is right everywhere. With an alias, naming `CV_00B4` leaves
`ADDR_AT_00B4` still pointing at the same picture under a name that says only
where it is.

Why this is not a token replace
-------------------------------
`LABEL_0128` is **also a real code label** in `dos/CAPSULE.asm`, at an
unrelated place. `DELAY_LOOP_VARED_AT_0844` and
`STATE_VAR12_BIG_DISPATCH_CASE_30_AT_2D4E` are code-label spellings too. A
global rename of those tokens would rewrite jump targets.

So this rewrites **only the operand position** of a `video type=0, offset=...`
instruction, and only where the operand is a known alias. `type=0` is the bank
discriminator: plain `video` selects the per-stage cinematic bank, where the
same numeric offset is a different picture. Everything else -- label
definitions, jump operands, the alias's own `EQU` -- is left exactly as it is.

The alias's own `EQU` line **is** rewritten, and it has to be. Rewriting only
the operands produced **240 undefined references**, because these aliases are
not redundant spellings sitting beside the key -- they are branch-guarded
stand-ins for the branches where the key is *not* defined:

    ; EQU aliases for stuck literal-address operands in CAVES.
    .if BRANCH in ("cartridge_1992", "dos_1992")
    ADDR_AT_00B4        EQU 0x00B4

So the merge renames the definition in place, inside the same `.if` guard,
leaving exactly one definition per branch under the canonical name.

The rename matches a name followed by `EQU` and therefore cannot touch a *label*
definition, which is `<NAME>:`. That distinction is what keeps `LABEL_0128:`
in `dos/CAPSULE.asm` intact while `LABEL_0128 EQU 0x0128` in an alias chunk is
rewritten. A first attempt restricted the rename to `*_equ_aliases.inc` out of
caution about exactly that collision; the restriction was the bug. The
canonical `.asm` files define some of these aliases too, so the operands
changed there while the definitions did not, and `make test` dropped to 27/29
on amiga CAVES and CAPSULE. `undefined_symbols.py` did **not** catch it,
because it checks the unified tree and these were the per-branch canonical
files -- so the byte gate is the check that matters here, and it must be run.

One further case the merge cannot fix by itself. In CAPSULE the operand
`LABEL_3640` resolved to a **code label** `LABEL_3640:` whose address happens
to equal the bank offset 0x3640, so nothing defined it as a picture at all.
Pointing the operand at `CV_3640` then needs that key defined for the branches
that reach the chunk; it is added to `capsule_equ_aliases.inc` under the same
guard, which emits no bytes.

Preconditions, checked before writing
-------------------------------------
  - each alias maps to exactly one offset, and exactly one canonical `CV_` or
    earned name maps to that same offset;
  - the canonical name is defined in at least one file, so the rewrite cannot
    introduce an undefined symbol at the point of substitution. The real test
    is `notes/unified-symbol-check/undefined_symbols.py`, which resolves per
    reaching branch, and must be run after.

After applying
--------------
    python3 notes/unified-symbol-check/undefined_symbols.py
    make test
    python3 notes/shared-bank-naming/bank_name_offset_consistent.py

Usage
-----
    python3 notes/shared-bank-naming/merge_bank_aliases.py --dry
    python3 notes/shared-bank-naming/merge_bank_aliases.py
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src"
RE_EQU = re.compile(r"^([A-Za-z_]\w*)\s+EQU\s+(0x[0-9A-Fa-f]+)")
RE_KEY = re.compile(r"^CV_[0-9A-F]{4}$")
RE_T0 = re.compile(r"(\bvideo\s+type=0,\s*offset=)([A-Za-z_]\w*)")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry", action="store_true")
    args = ap.parse_args()

    files = [p for p in SRC.rglob("*")
             if p.is_file() and p.suffix in (".asm", ".inc", ".in")]
    texts = {p: p.read_text(errors="replace") for p in files}

    vals: dict[str, set] = collections.defaultdict(set)
    for t in texts.values():
        for line in t.splitlines():
            m = RE_EQU.match(line)
            if m:
                vals[m.group(1)].add(int(m.group(2), 16))

    drawn: set[str] = set()
    for t in texts.values():
        drawn |= {m.group(2) for m in RE_T0.finditer(t)}

    at_off: dict[int, set] = collections.defaultdict(set)
    for n in drawn:
        v = vals.get(n)
        if v and len(v) == 1:
            at_off[next(iter(v))].add(n)

    table: dict[str, str] = {}
    skipped = []
    for off, names in at_off.items():
        if len(names) < 2:
            continue
        canon = sorted(n for n in names
                       if RE_KEY.match(n) or not re.search(r"_[0-9A-F]{4}$", n)
                       and not n.startswith("COMMON_VIDEO_"))
        canon = [c for c in canon if not c.startswith("COMMON_VIDEO_")]
        others = sorted(n for n in names
                        if n not in canon and not n.startswith("COMMON_VIDEO_"))
        if len(canon) != 1 or not others:
            if others:
                skipped.append((off, sorted(names)))
            continue
        for o in others:
            table[o] = canon[0]

    if skipped:
        print(f"{len(skipped)} offset(s) skipped: no single canonical name")
        for off, ns in skipped[:10]:
            print(f"  0x{off:04X}  {', '.join(ns)}")
    if not table:
        print("nothing to merge")
        return 0

    undef = sorted({v for v in table.values() if v not in vals})
    if undef:
        print(f"FAIL: canonical name(s) not defined anywhere: "
              f"{', '.join(undef)}")
        return 1

    re_def = re.compile(
        r"^(" + "|".join(re.escape(a) for a in sorted(table)) + r")(\s+EQU\s+)",
        re.M)
    touched = total = defs = 0
    for p, t in sorted(texts.items()):
        n = sum(1 for m in RE_T0.finditer(t) if m.group(2) in table)
        new = RE_T0.sub(
            lambda m: m.group(1) + table.get(m.group(2), m.group(2)), t)
        d = len(re_def.findall(new))
        new = re_def.sub(lambda m: table[m.group(1)] + m.group(2), new)
        if n or d:
            touched += 1
            total += n
            defs += d
            if not args.dry:
                p.write_text(new)
    print(f"{len(table)} alias(es) folded onto their canonical key: "
          f"{'would rewrite' if args.dry else 'rewrote'} {total} operand(s) "
          f"and {defs} definition(s) in {touched} file(s)")
    for a, c in sorted(table.items())[:50]:
        print(f"  {a:<44} -> {c}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
