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
  - **`_unified/_helpers/*.inc`**, which is shared across **stages** as well
    as branches: `DRAW_CV_099.inc` defines one routine that PRISON, CAVES and
    CAPSULE all include. A per-stage proposal cannot rename it unilaterally,
    and the applier did not walk that directory at all -- so a pass renamed
    the *reference* in `prison/amiga__post_INLINE_KILL_041.inc` while the
    *definition* stayed put, giving 114 undefined references and
    verify-unified **20/29**. A label any `_helpers` chunk mentions is now
    dropped from the pass unless every stage and branch referencing it
    proposes the same name.
  - **`_unified/<STAGE>.asm.in`, the stage template**, which is also read by
    every branch. Leaving it out is not a cosmetic omission: `JUNK__0467` is
    *defined* only there while `cart__entry.inc` references it, so a pass
    that rewrote the reference and not the definition produced one undefined
    symbol and took verify-unified to 28/29. The byte gate caught it;
    `undefined_symbols.py` also named it, because this time the breakage was
    inside the unified tree.

A rename is written to a chunk **only when every branch that reads it agrees
on the new name for that label**. If amiga proposes a name and msdos does not,
a shared chunk keeps the old spelling and the rename is refused for that
chunk, and reported. Otherwise the msdos build would lose a label the amiga
pass renamed out from under it -- which is the shape of the breakage that took
verify-unified from 29/29 to 27/29 earlier in this session, found only by the
byte gate.

An all-branch file — no prefix, or the `.asm.in` template — is rewritten only
when **every** branch that has the label proposes the same new name for it.
Otherwise the label is **dropped from the pass entirely**, not merely skipped
in that file. Skipping only the chunk is worse
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
PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992",
         "snes_eu": "cartridge_1992", "gba_usa": "gba_2004"}
PREFIX = {"amiga": "amiga", "msdos": "dos", "snes_eu": "cart",
          "gba_usa": "gba"}
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

    # A label any cross-stage helper names can only be renamed if every
    # stage and branch that references it agrees; the helpers directory is
    # shared by PRISON, CAVES and CAPSULE at once.
    helpers = sorted((SRC / "src" / "levels" / "_unified"
                      / "_helpers").glob("*.inc"))
    helper_text = {f: f.read_text(errors="replace") for f in helpers}
    by_label: dict[str, set] = collections.defaultdict(set)
    for (port, stage, lab), name in table.items():
        by_label[lab].add(name)
    # Every helper-referenced label is dropped, even when the proposers
    # agree. Agreement among PROPOSERS is not the test: `DRAW_CV_069.inc` is
    # included by amiga and msdos alike, so renaming it because msdos
    # proposed a name breaks amiga, which did not. Requiring "every branch
    # and stage whose build includes this helper has the same proposal" is
    # the correct test and is not cheaply computable from here, so the pass
    # declines the whole class. Trying the weaker test first took
    # verify-unified from 20/29 to 20/29 with 150 undefined references
    # instead of 114 -- worse, not better.
    shared_helper = {lab for lab in by_label
                     if any(re.search(rf"\b{re.escape(lab)}\b", t2)
                            for t2 in helper_text.values())}
    dropped_h = [k for k in table if k[2] in shared_helper]
    for k in dropped_h:
        del table[k]
    if dropped_h:
        print(f"  {len(dropped_h)} proposal(s) dropped: the label lives in "
              f"a cross-stage _helpers chunk,\n     which is included by "
              f"stages and branches this pass has no proposal for")

    # A label any all-branch chunk names cannot be renamed by this pass.
    universal: set[tuple[str, str]] = set()
    for (port, stage, lab) in list(table):
        d = SRC / "src" / "levels" / "_unified" / stage.lower()
        if not d.is_dir():
            continue
        cands = list(d.rglob("*.inc"))
        tmpl = SRC / "src" / "levels" / "_unified" / f"{stage}.asm.in"
        if tmpl.is_file():
            cands.append(tmpl)
        for f in cands:
            if f.suffix == ".inc" and readers(f.name) is not None:
                continue
            if not re.search(rf"\b{re.escape(lab)}\b",
                             f.read_text(errors="replace")):
                continue
            # All-branch file: allowed only if every branch agrees.
            byport = {p2: n2 for (p2, st2, l2), n2 in table.items()
                      if st2 == stage and l2 == lab}
            present = {p2 for p2 in PORTS
                       if (SRC / "src" / "levels" / PORTS[p2]
                           / f"{stage}.asm").is_file()
                       and re.search(
                           rf"\b{re.escape(lab)}\b",
                           (SRC / "src" / "levels" / PORTS[p2]
                            / f"{stage}.asm").read_text(errors="replace"))}
            if present <= set(byport) and len(set(byport.values())) == 1:
                continue          # safe to rewrite everywhere
            universal.add((stage, lab))
            break
    dropped = [k for k in table if (k[1], k[2]) in universal]
    for k in dropped:
        del table[k]
    if dropped:
        print(f"  {len(dropped)} proposal(s) dropped: the label is "
              f"referenced by a chunk every branch reads,\n     and at least "
              f"one of those branches has no proposal for it")

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
        files = sorted(d.rglob("*.inc"))
        tmpl = SRC / "src" / "levels" / "_unified" / f"{stage}.asm.in"
        if tmpl.is_file():
            files.append(tmpl)
        for f in files:
            t = f.read_text(errors="replace")
            who = readers(f.name)
            changed = t
            for lab, byport in labs.items():
                if not re.search(rf"\b{re.escape(lab)}\b", changed):
                    continue
                if who is None and len(set(byport.values())) == 1:
                    changed = re.sub(rf"\b{re.escape(lab)}\b",
                                     next(iter(byport.values())), changed)
                    written["all-branch file tokens"] += 1
                    continue
                if who is None:
                    refused.append(f"{f.name}: read by every branch, "
                                   f"{lab} left alone")
                    continue
                want = {ALL_PREFIXES[w] for w in who}
                back = {v: k for k, v in PREFIX.items()}
                have = set(byport)
                want_ports = {back[w] for w in who if w in back}
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
