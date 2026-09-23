#!/usr/bin/env python3
"""Do the canonical tree and the unified tree agree on what a name means?

Question answered
-----------------
The repository holds the same program twice: `src/levels/<branch>/<STAGE>.asm`,
one file per port, and `src/levels/_unified/<stage>/`, the shared form with
`.if BRANCH` arms. Both assemble, and `make test` checks both -- 29/29 and
29/29.

Neither gate checks that they use the same NAMES. A rename applied to one tree
and not synced to the other leaves the same offset under two different symbols,
and both trees still assemble byte-identically, because an EQU emits nothing and
each tree is internally consistent.

This reports two kinds of disagreement:

  * **missing** -- a semantic name in the canonical file that appears nowhere in
    the corresponding unified stage directory;
  * **moved** -- a name both trees define, at different offsets.

`moved` is the dangerous one. It is what made
`notes/beam-span-ladder/rung_thresholds.py` report msdos CAVES' entire beam
ladder as misplaced when it resolved a unified routine against the canonical
table: every symbol resolved, to the wrong picture. Nothing warned.

    A name means what the tree it was read from says it means. A probe that
    reads a body from one tree must read its table from the same tree.

Result, 2026-09-23
------------------
See the run at the bottom of `README.md`, which is where the numbers are kept
so they can be dated. Run it rather than trust a number in a comment.

Which tree is right? The canonical files are what
`notes/shared-bank-naming/asset_naming_share.py` counts, so the naming record
is the canonical tree and the unified tree is the one that is behind. That also
means the drift costs no coverage -- it is a consistency debt, not a naming gap.

Usage
-----
    python3 notes/tree-name-drift/name_drift.py
    python3 notes/tree-name-drift/name_drift.py --kind moved --stage PRISON
    python3 notes/tree-name-drift/name_drift.py --list
"""

from __future__ import annotations

import argparse
import collections
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ARM = {"chahi_amiga_1991": "amiga", "dos_1992": "dos",
       "cartridge_1992": "cart", "gba_2004": "gba"}
RE_EQU = re.compile(r"^(CINEMATIC_\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)
RE_NUM = re.compile(r"^CINEMATIC_\d+$")


def unified(stage: str):
    """(all text of the stage dir, name -> EVERY offset it is defined at).

    Every offset, not one: a shared `.inc` may define the same name once per
    `.if BRANCH` arm, so one name legitimately has one value per port. Taking
    the first hit and calling the rest a disagreement reported 631 false rows
    in amiga LAKE alone -- `pool_underwater_cinematic.inc` defines
    `CINEMATIC_CONSOLE_UNDERWATER_EXPLOSION_0` at 0x1D82 on line 11 and at
    0x3142 on line 52, in two arms, and 0x3142 is amiga's.

    So a name is `moved` only when the canonical offset is among NONE of them.
    That under-reports where two ports' values are swapped between arms, and is
    the conservative direction: every row it prints is real.
    """
    d = ROOT / "src" / "levels" / "_unified" / stage.lower()
    if not d.is_dir():
        return None, None
    text, equ = [], collections.defaultdict(set)
    for inc in sorted(d.glob("*.inc")):
        t = inc.read_text(errors="replace")
        text.append(t)
        for n, v in RE_EQU.findall(t):
            equ[n].add(int(v, 16))
    return " ".join(text), equ


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--kind", choices=["missing", "moved"])
    ap.add_argument("--stage")
    ap.add_argument("--list", action="store_true",
                    help="print every row, not just the counts")
    args = ap.parse_args()

    tot = collections.Counter()
    rows = collections.defaultdict(list)
    for branch, arm in ARM.items():
        for asm in sorted((ROOT / "src" / "levels" / branch).glob("*.asm")):
            stage = asm.stem
            if args.stage and stage != args.stage:
                continue
            text, uequ = unified(stage)
            if text is None:
                continue
            for n, v in RE_EQU.findall(asm.read_text(errors="replace")):
                if RE_NUM.match(n):
                    continue
                if n in uequ:
                    if int(v, 16) not in uequ[n]:
                        tot["moved"] += 1
                        got = ", ".join(f"0x{x:04X}" for x in sorted(uequ[n]))
                        rows[("moved", branch, stage)].append(
                            f"{n}  unified {got}  canonical {v}")
                elif not re.search(r"\b" + re.escape(n) + r"\b", text):
                    tot["missing"] += 1
                    rows[("missing", branch, stage)].append(n)

    print(f"{tot['missing']:6d}  semantic names missing from the unified tree")
    print(f"{tot['moved']:6d}  names both trees define at different offsets")
    print()
    for (kind, branch, stage), r in sorted(rows.items(),
                                           key=lambda kv: -len(kv[1])):
        if args.kind and kind != args.kind:
            continue
        print(f"  {kind:<8} {branch:<18} {stage:<11} {len(r):4d}")
        if args.list:
            for x in r:
                print(f"      {x}")
    print("\nThe canonical tree is the naming record -- asset_naming_share.py "
          "counts it --\nso a row here is the unified tree lagging, and costs "
          "no coverage.")
    return 1 if tot["moved"] else 0


if __name__ == "__main__":
    raise SystemExit(main())
