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

Renames in one table are applied **simultaneously**
(`rename_simultaneously`), so a renumber -- where a new name is also an
old name -- is safe in whatever order the table lists its rows.

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
RE_IDENT = re.compile(r"[A-Za-z_]\w*")
RE_ADDR_LABEL = re.compile(r"LABEL_[0-9A-Fa-f]{4}")
PREFIX = {"chahi_amiga_1991": "amiga", "dos_1992": "dos",
          "cartridge_1992": "cart", "gba_2004": "gba"}


def rename_simultaneously(text: str, live: list[tuple[str, str]]
                          ) -> tuple[str, int]:
    """One pass, so a renumber cannot eat its own output.

    Applying the pairs one `re.subn` at a time is only correct when no new
    name is also an old name. A renumber is exactly the case where that
    fails: `CINEMATIC_682 -> ..._PUPIL_0` followed by `..._PUPIL_0 ->
    ..._PUPIL_1` renames the constant this same table just created, and both
    the old `_0` and the new one land on `_1`.

    That is not hypothetical. This file previously did the sequential thing
    and a CINEMATIC_272 shift left `LEFT_4` defined twice, at 0xCA7C and
    0xCA04, which `verify_unified.py` caught only because the duplicate
    happened to move bytes. The work-around on record -- order the shifts
    descending and put new names last -- works but has to be remembered by
    every caller, and a proposal table's row order is documentation, not a
    place to encode a tool's defect.

    Alternatives are tried longest-first so a name that is another's prefix
    cannot shadow it.
    """
    if not live:
        return text, 0
    mapping = dict(live)
    alts = "|".join(re.escape(o) for o in
                    sorted(mapping, key=len, reverse=True))
    return re.subn(rf"\b(?:{alts})\b", lambda m: mapping[m.group(0)], text)


def self_test() -> int:
    """The PRISON pupil renumber, as a table that is hostile on purpose.

    `CINEMATIC_682` claims `PUPIL_0` in the same table where `PUPIL_0`
    becomes `PUPIL_1` and `PUPIL_1` becomes `PUPIL_5`. Run row by row in
    table order, every one of those three ends up spelled `PUPIL_5`. The
    signal read is the rewritten text: each of the four source spellings must
    survive as a distinct destination spelling, and the substitution count
    must equal the number of tokens present.
    """
    P = "CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_"
    text = f"{P}2 {P}1 {P}0 CINEMATIC_682"
    live = [("CINEMATIC_682", f"{P}0"), (f"{P}0", f"{P}1"),
            (f"{P}1", f"{P}5"), (f"{P}2", f"{P}6")]
    got, n = rename_simultaneously(text, live)
    want = f"{P}6 {P}5 {P}1 {P}0"
    ok = got == want and n == 4
    print(f"  in   {text}")
    print(f"  out  {got}   ({n} substitution(s))")
    print(f"  want {want}   (4)")

    seq = text
    for old, name in live:
        seq = re.sub(rf"\b{re.escape(old)}\b", name, seq)
    print(f"\n  what row-by-row would have produced:\n  {seq}")
    print(f"\n  {'PASS' if ok else 'FAIL'}: simultaneous rename of a "
          f"renumber table")
    return 0 if ok else 1


def adopted(name: str, canonical: str) -> bool:
    """Has the canonical `.asm` actually taken this name?

    Constants are adopted as `NAME  EQU 0x....` and routines as `NAME:`.
    Either counts; nothing else does. This is the "a proposal is not an
    application" rule -- a row the validator rejected must not be able to
    reach the unified tree through the sync -- and it has to cover labels
    now that `apply_routine_renames.py` feeds tables through here too.
    """
    return bool(re.search(rf"^{re.escape(name)}(\s+EQU\b|:)", canonical,
                          re.M))


def stage_branches(stage: str) -> list[str]:
    return [b for b in PREFIX if (SRC / b / f"{stage}.asm").is_file()]


def shared_pass(stage: str, live: list[tuple[str, str]], apply: bool
                ) -> int:
    """Rewrite the chunks no branch prefix claims.

    A shared chunk is read by several branches, so renaming a token there is
    only safe once **every** branch has moved off the old spelling. The test
    is exactly that: the old name is defined in no branch's canonical `.asm`
    for this stage, and the new name is defined in at least one. While any
    branch still calls the routine by its old name, the shared chunk keeps
    it and this pass reports the pair as held.
    """
    canon = {b: (SRC / b / f"{stage}.asm").read_text(errors="replace")
             for b in stage_branches(stage)}
    ready, held, refused = [], [], []
    for old, name in live:
        if RE_ADDR_LABEL.fullmatch(old):
            # A bare address label is per-branch BY CONSTRUCTION: amiga's
            # LABEL_4E09 is the eyelid rung at [0x15] <= 0x12 and dos's
            # LABEL_4E09 is the pupil rung at [0x16] <= 0x04. One branch's
            # table cannot say what such a token means to the other readers
            # of a shared chunk, so this pass never touches one. The
            # branch-prefixed pass above renames them, where the branch is
            # known.
            refused.append(old)
        elif any(adopted(old, t) for t in canon.values()):
            held.append(old)
        elif any(adopted(name, t) for t in canon.values()):
            ready.append((old, name))
    d = SRC / "_unified" / stage.lower()
    total = touched = 0
    for f in sorted(d.rglob("*.inc")):
        if "__" in f.name:
            continue
        t = f.read_text(errors="replace")
        new, n = rename_simultaneously(t, ready)
        if n:
            total += n
            touched += 1
            if apply:
                f.write_text(new)
    print(f"  shared chunks: {len(ready)} pair(s) ready, {len(held)} held "
          f"because a branch still defines the old name")
    for h in held:
        print(f"      held: {h}")
    if refused:
        print(f"      {len(refused)} address label(s) never eligible here")
    print(f"  {'rewrote' if apply else 'would rewrite'} {total} token(s) in "
          f"{touched} shared chunk(s)")
    return total


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("table", type=Path, nargs="?")
    ap.add_argument("stage", nargs="?")
    ap.add_argument("branch", nargs="?", choices=sorted(PREFIX))
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--shared", action="store_true",
                    help="also rewrite the chunks no branch prefix claims, "
                         "for the pairs every branch has moved off")
    ap.add_argument("--self-test", action="store_true",
                    help="renumber control: does one table that both frees "
                         "and claims a name land every row on its own name?")
    args = ap.parse_args()

    if args.self_test:
        return self_test()
    if not (args.table and args.stage and args.branch):
        ap.error("table, stage and branch are required without --self-test")

    pairs = []
    for line in args.table.read_text().splitlines():
        if not line.startswith("|"):
            continue
        cols = [c.strip() for c in line.split("|")]
        # Constants AND routine labels: `adopted()` below is the real guard,
        # and restricting the parse to CINEMATIC_ silently returned "no rows"
        # for a routine table rather than saying the format was wrong.
        if len(cols) > 3 and RE_IDENT.fullmatch(cols[1]) \
                and RE_IDENT.fullmatch(cols[2]):
            pairs.append((cols[1], cols[2]))
    if not pairs:
        print("no rows")
        return 1

    canon = SRC / args.branch / f"{args.stage}.asm"
    text = canon.read_text(errors="replace")
    live = [(o, n) for o, n in pairs if adopted(n, text)]
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
        new, n = rename_simultaneously(t, live)
        if n:
            total += n
            touched += 1
            if args.apply:
                f.write_text(new)
    print(f"{'rewrote' if args.apply else 'would rewrite'} {total} token(s) "
          f"in {touched} {pre}-only chunk(s)")
    if args.shared:
        shared_pass(args.stage, live, args.apply)
    if not args.apply:
        print("(dry run)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
