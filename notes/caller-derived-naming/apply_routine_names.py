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

`--iterate` replaces the conservative `_helpers` rule with the real check.
Three heuristics for "is this label safe to rename across the unified tree"
have now been wrong, each in a way only the byte gate or
`undefined_symbols.py` caught:

  1. rename references in `_unified/<stage>/` and not the `_helpers` chunk
     that defines them -- 114 undefined, verify-unified 20/29;
  2. also rewrite the helper when every *proposer* agrees -- worse, 150,
     because a build that proposed nothing still reads that helper;
  3. allow it when every build that *reads the helper* has the same proposal
     -- 24 undefined, because a label also lives in branch chunks that do not
     read the helper.

So `--iterate` stops predicting. It applies the whole table, runs
`undefined_symbols.py`, maps each undefined symbol back to the label that
produced it, drops those labels, reverts and applies again -- until the check
is clean. The oracle is the thing that was catching the mistakes anyway.

It reverts with `git checkout -- src/`, so it refuses to run on a dirty tree.

Usage
-----
    python3 notes/caller-derived-naming/apply_routine_names.py --dry
    python3 notes/caller-derived-naming/apply_routine_names.py
    python3 notes/caller-derived-naming/apply_routine_names.py --iterate
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


def _apply_table(table: dict) -> None:
    """Rewrite every file that mentions a renamed label, everywhere."""
    roots = [SRC / "src"]
    files = [f for r in roots for f in r.rglob("*")
             if f.is_file() and f.suffix in (".asm", ".inc", ".in")]
    by_lab: dict[str, set] = collections.defaultdict(set)
    where: dict[str, set] = collections.defaultdict(set)
    for (port, stage, lab), name in table.items():
        by_lab[lab].add(name)
        where[lab].add((port, stage))
    # A global rewrite is only sound when the label exists in exactly the
    # places that proposed for it. Otherwise a label msdos proposed for gets
    # renamed in amiga too, where it may be a different routine drawing
    # different art -- the build stays clean and the NAME is wrong, which
    # undefined_symbols.py cannot see. This is the precondition the oracle
    # does not supply.
    exists: dict[str, set] = collections.defaultdict(set)
    lab_re = {lab: re.compile(rf"^{re.escape(lab)}:", re.M) for lab in by_lab}
    for port, br in PORTS.items():
        for stage in {s for _p, s, _l in table}:
            f = SRC / "src" / "levels" / br / f"{stage}.asm"
            if not f.is_file():
                continue
            txt = f.read_text(errors="replace")
            for lab, rx in lab_re.items():
                if rx.search(txt):
                    exists[lab].add((port, stage))
    flat = {lab: next(iter(n)) for lab, n in by_lab.items()
            if len(n) == 1 and exists[lab] == where[lab]}
    if not flat:
        return
    pat = re.compile(r"\b(" + "|".join(re.escape(k) for k in flat) + r")\b")
    for f in files:
        t2 = f.read_text(errors="replace")
        new = pat.sub(lambda m: flat[m.group(1)], t2)
        if new != t2:
            f.write_text(new)


def visible_to(labels: set) -> dict:
    """label -> {(branch, stage)} whose build actually sees it.

    `undefined_symbols.walk` evaluates `.if BRANCH` while following
    `.include`, so its `defs` and `refs` are what that build really
    assembles -- not what the files happen to contain. That distinction is
    the whole point here: `_unified/prison/amiga__entry.inc` contains
    `DRAW_CV097_AT_X01_Y02` while amiga/PRISON's build does not emit it,
    because the text sits in an arm amiga skips. File membership says amiga
    sees it; the walk says it does not.
    """
    sys.path.insert(0, str(SRC / "notes" / "unified-symbol-check"))
    from undefined_symbols import walk as _walk           # noqa: E402
    out: dict[str, set] = collections.defaultdict(set)
    stages = [f.stem.replace(".asm", "") for f in
              (SRC / "src" / "levels" / "_unified").glob("*.asm.in")]
    for port, br in PORTS.items():
        for stage in stages:
            tmpl = SRC / "src" / "levels" / "_unified" / f"{stage}.asm.in"
            if not tmpl.is_file():
                continue
            defs: set = set()
            refs: dict = {}
            _walk(tmpl, br, set(), defs, refs)
            seen = (defs | set(refs)) & labels
            for lab in seen:
                out[lab].add((port, stage))
    return out


def iterate(table: dict) -> int:
    """Apply, ask the oracle, drop the guilty labels, revert, repeat."""
    import subprocess
    if subprocess.run(["git", "status", "--porcelain", "src"],
                      cwd=SRC, capture_output=True, text=True).stdout.strip():
        print("refusing: src/ is dirty; commit or revert first")
        return 1
    # Precondition, computed once: a label may be renamed only if EVERY
    # build that sees it proposes the same name. Three earlier rules failed
    # because they asked about files rather than builds --
    # DRAW_CV097_AT_X01_Y02 lives in one shared helper and is seen by amiga,
    # dos and cart across PRISON, CAVES and CAPSULE, while only msdos/PRISON
    # proposed for it.
    labels = {lab for _p, _s, lab in table}
    vis = visible_to(labels)
    have: dict[str, set] = collections.defaultdict(set)
    names: dict[str, set] = collections.defaultdict(set)
    for (port, stage, lab), name in table.items():
        have[lab].add((port, stage))
        names[lab].add(name)
    unsafe = {lab for lab in labels
              if len(names[lab]) != 1 or not vis.get(lab, set()) <= have[lab]}
    if unsafe:
        table = {k: v for k, v in table.items() if k[2] not in unsafe}
        print(f"  {len(unsafe)} label(s) held: a build that sees them has no "
              f"proposal, or proposals differ")

    banned: set[str] = set()
    for round_ in range(1, 9):
        live = {k: v for k, v in table.items() if k[2] not in banned}
        if not live:
            print("nothing left to apply")
            return 1
        _apply_table(live)
        out = subprocess.run(
            [sys.executable, str(SRC / "notes" / "unified-symbol-check"
                                 / "undefined_symbols.py")],
            cwd=SRC, capture_output=True, text=True).stdout
        bad = set(re.findall(r"^\s{4}(\S+)\s+first referenced", out, re.M))
        if not bad:
            print(f"round {round_}: {len(live)} rename(s) applied, "
                  f"undefined_symbols clean "
                  f"({len(banned)} label(s) dropped over {round_ - 1} "
                  f"earlier round(s))")
            return 0
        guilty = {lab for (_p, _s, lab), name in live.items() if name in bad}
        print(f"round {round_}: {len(bad)} undefined -> dropping "
              f"{len(guilty)} label(s)")
        banned |= guilty
        subprocess.run(["git", "checkout", "--", "src"], cwd=SRC, check=True)
    print("did not converge in 8 rounds")
    subprocess.run(["git", "checkout", "--", "src"], cwd=SRC, check=True)
    return 1


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry", action="store_true")
    ap.add_argument("--iterate", action="store_true",
                    help="apply, ask undefined_symbols.py, drop the labels "
                         "responsible, revert and retry until clean")
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
    if args.iterate:
        return iterate(table)

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
