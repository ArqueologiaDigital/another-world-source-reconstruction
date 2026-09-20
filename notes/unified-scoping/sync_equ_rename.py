#!/usr/bin/env python3
"""Carry a canonical constant rename into that branch's own unified chunks.

Question answered
-----------------
`tools/apply_branch_scoped_names.py` renames a `CINEMATIC_<index>` in a
branch's canonical `.asm` and in the unified draw sites it can see. It does
not rename the `EQU` that defines the constant when that `EQU` lives in the
branch's own entry chunk. The result assembles and is wrong:

    _unified/prison/amiga__entry.inc:1728   CINEMATIC_505       EQU 0x4D5E
    _unified/prison/prison_var2f_state_machine.inc:687
                                    video offset=CINEMATIC_PRISON_SHOT_BEAM_SINGLE_DOT

The shared chunk now names a symbol only the canonical file defines, so the
unified build has an undefined reference -- which **assembles silently to
zero and moves bytes**. Seven of these took verify-unified to 26/29 while
verify-stages stayed at 29/29, because the canonical files were each
self-consistent.

What it does
------------
For a `(branch, stage)` and a proposal table of `old -> new`, renames `old` to
`new` in `_unified/<stage>/` chunks that **that branch reads**: its own
`<prefix>__*.inc`, by the `amiga__` / `dos__` / `cart__` / `gba__` convention.
Shared and other-branch chunks are left alone -- another branch still uses the
old spelling and renaming there is how you break it.

It only rewrites a name the canonical file has actually adopted, so a proposal
the validator rejected cannot leak in: the same "a proposal is not an
application" rule that `scope_fix.py` beside this file had to learn.

Usage
-----
    python3 notes/unified-scoping/sync_equ_rename.py <table.md> <STAGE> <branch>
    python3 notes/unified-scoping/sync_equ_rename.py ... --apply

Afterwards, always:

    python3 notes/unified-symbol-check/undefined_symbols.py
    make test
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels"
PREFIX = {"chahi_amiga_1991": "amiga", "dos_1992": "dos",
          "cartridge_1992": "cart", "gba_2004": "gba"}


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("table", type=Path)
    ap.add_argument("stage")
    ap.add_argument("branch", choices=sorted(PREFIX))
    ap.add_argument("--apply", action="store_true")
    args = ap.parse_args()

    pairs = []
    for line in args.table.read_text().splitlines():
        if not line.startswith("|"):
            continue
        cols = [c.strip() for c in line.split("|")]
        if len(cols) > 3 and cols[1].startswith("CINEMATIC_"):
            pairs.append((cols[1], cols[2]))
    if not pairs:
        print("no rows")
        return 1

    canon = SRC / args.branch / f"{args.stage}.asm"
    text = canon.read_text(errors="replace")
    live = [(o, n) for o, n in pairs
            if re.search(rf"^{re.escape(n)}\s+EQU", text, re.M)]
    print(f"{len(live)} of {len(pairs)} proposal(s) actually applied in "
          f"{canon.name}")
    if not live:
        return 0

    pre = PREFIX[args.branch]
    d = SRC / "_unified" / args.stage.lower()
    total = touched = 0
    for f in sorted(d.rglob("*.inc")):
        head = f.name.split("__", 1)[0] if "__" in f.name else None
        if head is None or pre not in head.split("_"):
            continue
        t = f.read_text(errors="replace")
        new = t
        n = 0
        for old, name in live:
            new, k = re.subn(rf"\b{re.escape(old)}\b", name, new)
            n += k
        if n:
            total += n
            touched += 1
            if args.apply:
                f.write_text(new)
    print(f"{'rewrote' if args.apply else 'would rewrite'} {total} token(s) "
          f"in {touched} {pre}-only chunk(s)")
    if not args.apply:
        print("(dry run)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
