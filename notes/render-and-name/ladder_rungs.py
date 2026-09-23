#!/usr/bin/env python3
"""Read a `jg [var], N` selector ladder and report its rungs, per branch.

Question answered
-----------------
Some picture families in this tree are not animations played in order. They
are **ladders**: a chain of `jg [var], <threshold>` tests, each falling
through to one `video offset=` and jumping to a common tail. The VM walks it
to pick one picture for the current value of `var`, and the driver moves
`var` both up and down.

    LABEL_4DA1:
            jg [0x15], 0x02, LABEL_4DAE
            video offset=CINEMATIC_675, x=160, y=100
            jmp LABEL_4E75

For such a family, "frame index" has no meaning and draw order is not a
sequence -- but the **rung** is a real, ordered, port-independent property,
and it is in the bytecode rather than in the art. `PRISON_WAKE_CLOSEUP_EYELID_0`
means "the picture this ladder picks when [0x15] is at its lowest", and that
is what this script reads out.

Two things it is used for:

* deriving the index of a ladder family before naming it, so the number is
  read rather than guessed;
* checking a ladder against another branch. The cartridge (SNES/Genesis)
  polygon data cannot be measured at all -- archaeology issue #0106, "Locate
  SNES cinematic + video2 polygon-data offsets in the SFC ROM", is open, so
  there is no `cinematic.rom` for it and no `canonical_md5` to compare. A
  name can still be carried there when the ladder is rung-for-rung the same
  chain over the same constants, because then the name indexes bytecode both
  branches share. `--diff` is that check.

Signal read
-----------
Per rung, in ladder order: the threshold the `jg` tests, and the constant the
fall-through draws. A rung is counted only when the `video` line lies between
a `jg [var], ...` and the next label, so an unrelated draw in the same
routine cannot be mistaken for one. PASS for `--diff` is: same number of rungs and the **same threshold at
every rung**. Constant spellings are printed but not judged -- once one
branch has been renamed they differ by construction, and reading that as a
structural difference would make the check useless exactly when it is needed.
What IS judged, besides the thresholds, is a rung where both branches already
carry a semantic name and the two names disagree: that is one name meaning
two things, hazard #0118, and it fails.

Usage
-----
    python3 notes/render-and-name/ladder_rungs.py --stage PRISON --var 0x15
    python3 notes/render-and-name/ladder_rungs.py --stage PRISON --var 0x16 \
        --diff chahi_amiga_1991 cartridge_1992
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels"
BRANCHES = ["chahi_amiga_1991", "dos_1992", "cartridge_1992", "gba_2004"]
RE_LBL = re.compile(r"^([A-Za-z_]\w*):\s*$")
RE_VID = re.compile(r"^\s*video\s+(?:type=\d+,\s*)?offset=([A-Za-z_]\w*),")


def rungs(branch: str, stage: str, var: str) -> list[tuple[str, str]]:
    """(threshold, constant) for every rung of every `jg [var], N` ladder.

    The last rung of a ladder has no `jg` of its own -- it is the block the
    final test jumps TO -- so it is picked up as threshold `else` when the
    label that follows a ladder rung draws one more picture before the tail.
    """
    f = SRC / branch / f"{stage}.asm"
    if not f.is_file():
        return []
    jg = re.compile(rf"^\s*jg\s+\[{var}\],\s*(0x[0-9A-Fa-f]+),\s*(\w+)")
    lines = f.read_text(errors="replace").splitlines()
    out: list[tuple[str, str]] = []
    pending: str | None = None
    tail_targets: set[str] = set()
    at_label: str | None = None
    for line in lines:
        m = RE_LBL.match(line)
        if m:
            at_label = m.group(1)
            continue
        j = jg.match(line)
        if j:
            pending = j.group(1)
            tail_targets.add(j.group(2))
            continue
        v = RE_VID.match(line)
        if v:
            if pending is not None:
                out.append((pending, v.group(1)))
                pending = None
            elif at_label in tail_targets and out:
                # the block the last `jg` of a ladder jumps to: the `else`
                out.append(("else", v.group(1)))
                tail_targets.discard(at_label)
            continue
        if line.strip() and not line.startswith(("\t", " ")):
            pending = None
    return out


def numbered(const: str) -> bool:
    """A constant still spelled `CINEMATIC_<index>` carries no claim."""
    return bool(re.fullmatch(r"CINEMATIC_\d+", const))


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--stage", required=True)
    ap.add_argument("--var", required=True, help="e.g. 0x15")
    ap.add_argument("--diff", nargs=2, metavar=("A", "B"))
    args = ap.parse_args()

    if args.diff:
        a, b = (rungs(x, args.stage, args.var) for x in args.diff)
        n = max(len(a), len(b))
        bad = 0
        print(f"  {'rung':<6}{args.diff[0]:<44}{args.diff[1]}")
        for i in range(n):
            ra = a[i] if i < len(a) else ("--", "--")
            rb = b[i] if i < len(b) else ("--", "--")
            why = ""
            if ra[0] != rb[0]:
                why = "   <-- threshold differs"
            elif (numbered(ra[1]) or numbered(rb[1])):
                pass                        # one side simply not named yet
            elif ra[1] != rb[1]:
                why = "   <-- two names for one rung (#0118)"
            bad += bool(why)
            print(f"  {i:<6}{ra[0]:>6}  {ra[1]:<36}{rb[0]:>6}  {rb[1]}{why}")
        if len(a) != len(b):
            bad += 1
        print(f"\n  {len(a)} vs {len(b)} rung(s); {bad} disagree")
        print(f"  {'PASS' if not bad and a else 'FAIL'}: ladders on [{args.var}]"
              f" in {args.stage} are rung-for-rung the same")
        return 0 if not bad and a else 1

    for br in BRANCHES:
        r = rungs(br, args.stage, args.var)
        if not r:
            continue
        print(f"\n{br}  --  {len(r)} rung(s) on [{args.var}]")
        for i, (t, c) in enumerate(r):
            print(f"  {i:<4}{t:>6}   {c}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
