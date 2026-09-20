#!/usr/bin/env python3
"""Rename routine labels, in the files the branch that owns them actually reads.

Question answered
-----------------
`name_routines_from_art.py` proposes `(port, stage, label) -> name`. Applying
it is not a token replace, because a label is **per branch** and the unified
tree splices per-branch chunks: `LABEL_6C78` exists in amiga/PRISON and in
msdos/PRISON and they are different code that happens to sit at the same
address.

Where a rename may land
-----------------------
  - `src/levels/<branch>/<STAGE>.asm`, the canonical file;
  - `_unified/<stage>/` chunks whose basename says which branches read them.
    The convention there is a `__`-separated prefix: `amiga__entry.inc`,
    `dos__post_...`, `cart__...`, `amiga_dos__post_SHARED_RET.inc`. A chunk
    with no prefix is read by every branch.

A rename is written to a chunk **only when every branch that reads it agrees
on the new name for that label**. If amiga proposes a name and msdos does not,
a shared chunk keeps the old spelling and the rename is refused for that
chunk, and reported. Otherwise the msdos build would lose a label the amiga
pass renamed out from under it -- which is the shape of the breakage that took
verify-unified from 29/29 to 27/29 earlier in this session, found only by the
byte gate.

**A label referenced by an all-branch chunk is dropped from the pass
entirely**, not merely skipped in that chunk. Skipping only the chunk is worse
than useless: amiga and msdos would rename their canonical copies while the
shared chunk still names the old spelling, which is a dangling reference the
pass itself created. There is no proposal for the cartridge and GBA branches
here, so a name those branches also read cannot be changed by this pass at
all. `capsule_init_dispatch.inc` referencing `GUARDED_DRAW_CV_126` is the real
case that forced this rule.

What verifies it
----------------
Nothing here proves correctness. Afterwards, in this order:

    python3 notes/unified-symbol-check/undefined_symbols.py
    make test

`undefined_symbols.py` names a symbol left dangling in the unified tree;
`make test` is the only thing that proves no byte moved, and it is the check
that catches a breakage confined to the canonical files.

Usage
-----
    python3 notes/caller-derived-naming/apply_routine_names.py --dry
    python3 notes/caller-derived-naming/apply_routine_names.py
"""

from __future__ import annotations

import argparse
import collections
import re
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
PREFIX = {"amiga": "amiga", "msdos": "dos"}
ALL_PREFIXES = {"amiga": "amiga", "dos": "msdos", "cart": "snes_eu",
                "gba": "gba_usa"}


def readers(name: str) -> set[str] | None:
    """Which branch prefixes read this chunk; None = all of them."""
    if "__" not in name:
        return None
    head = name.split("__", 1)[0]
    parts = head.split("_")
    if all(p in ALL_PREFIXES for p in parts):
        return set(parts)
    return None


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry", action="store_true")
    args = ap.parse_args()

    out = subprocess.run(
        [sys.executable, str(HERE.parent / "name_routines_from_art.py"),
         "--proposals"], capture_output=True, text=True, check=True).stdout
    table: dict[tuple, str] = {}
    for line in out.splitlines():
        f = line.split()
        if len(f) == 4 and f[0] in PORTS and not line.startswith(" "):
            table[(f[0], f[1], f[2])] = f[3]
    if not table:
        print("no proposals")
        return 1
    print(f"{len(table)} proposal(s)")

    # A label any all-branch chunk names cannot be renamed by this pass.
    universal: set[tuple[str, str]] = set()
    for (port, stage, lab) in list(table):
        d = SRC / "src" / "levels" / "_unified" / stage.lower()
        if not d.is_dir():
            continue
        for f in d.rglob("*.inc"):
            if readers(f.name) is not None:
                continue
            if re.search(rf"\b{re.escape(lab)}\b",
                         f.read_text(errors="replace")):
                universal.add((stage, lab))
                break
    dropped = [k for k in table if (k[1], k[2]) in universal]
    for k in dropped:
        del table[k]
    if dropped:
        print(f"  {len(dropped)} proposal(s) dropped: the label is referenced "
              f"by a chunk every branch reads,\n     and this pass has no "
              f"proposal for the cartridge or GBA branches")

    # label -> {port: name} per stage, for the agreement test
    per_stage: dict[str, dict[str, dict[str, str]]] = collections.defaultdict(
        lambda: collections.defaultdict(dict))
    for (port, stage, lab), name in table.items():
        per_stage[stage][lab][port] = name

    written = collections.Counter()
    refused: list[str] = []

    for (port, stage, lab), name in sorted(table.items()):
        p = SRC / "src" / "levels" / PORTS[port] / f"{stage}.asm"
        if not p.is_file():
            continue
        t = p.read_text(errors="replace")
        new, n = re.subn(rf"\b{re.escape(lab)}\b", name, t)
        if n and not args.dry:
            p.write_text(new)
        written["canonical .asm tokens"] += n

    for stage, labs in per_stage.items():
        d = SRC / "src" / "levels" / "_unified" / stage.lower()
        if not d.is_dir():
            continue
        for f in sorted(d.rglob("*.inc")):
            t = f.read_text(errors="replace")
            who = readers(f.name)
            changed = t
            for lab, byport in labs.items():
                if not re.search(rf"\b{re.escape(lab)}\b", changed):
                    continue
                if who is None:
                    refused.append(f"{f.name}: read by every branch, "
                                   f"{lab} left alone")
                    continue
                want = {ALL_PREFIXES[w] for w in who}
                have = {PORTS[p2] if p2 in PORTS else p2 for p2 in byport}
                have = {("amiga" if p2 == "amiga" else "msdos")
                        for p2 in byport}
                want_ports = {("amiga" if w == "amiga" else
                               "msdos" if w == "dos" else w) for w in who}
                if not want_ports <= have:
                    refused.append(f"{f.name}: read by {sorted(want_ports)} "
                                   f"but only {sorted(have)} propose for "
                                   f"{lab}")
                    continue
                names = {byport[p2] for p2 in have if p2 in byport}
                if len(names) != 1:
                    refused.append(f"{f.name}: readers disagree on {lab}")
                    continue
                changed = re.sub(rf"\b{re.escape(lab)}\b", names.pop(), changed)
                written["unified chunk tokens"] += 1
            if changed != t and not args.dry:
                f.write_text(changed)

    for k, v in written.most_common():
        print(f"  {v:6d}  {k}")
    if refused:
        print(f"\n{len(refused)} chunk/label pair(s) left alone:")
        for r in sorted(set(refused))[:20]:
            print(f"  {r}")
    if args.dry:
        print("\n(dry run: nothing written)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
