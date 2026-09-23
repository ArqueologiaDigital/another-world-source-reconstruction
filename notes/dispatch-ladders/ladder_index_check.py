#!/usr/bin/env python3
"""Do the named families agree with the dispatch ladders that select them?

Question answered
-----------------
A ladder is a run of routines named `<something>_CASE_<hex>`, each guarding
one value of one variable and drawing one picture. The case number is the
value the VM compares against, so it is the machine's own index -- reading it
is not "naming from the index", which is the argument
`../gun-arm-dispatch/README.md` makes at length.

When the art a ladder selects is named as a family, the family's index and
the ladder's case number should agree up to a constant offset. Two things go
wrong when they do not, and both are invisible in any count of unnamed
constants:

  * **the family starts late.** CAPSULE's charged-blast fade is a contiguous
    nine-case ladder, 0x81..0x89, and the committed family covers 0x84..0x89
    as indices 0..5 -- so `FADE_0` is the fourth frame of the fade, and the
    three earliest frames are unnamed. Adding them as `_6.._8` would put the
    earliest frames at the highest indices.

    **Fixing this is not a plain rename, and one attempt has already failed.**
    The three unnamed arms are `CINEMATIC_480/479/478` in amiga and
    `CINEMATIC_627/626/625` in msdos -- different numbers for the same role,
    which is the ordinary case. A rename keyed on the amiga numbers put the
    new names onto msdos's `CINEMATIC_480/479/478`, which are unrelated art
    drawn from `LABEL_9DF3` and `JUNK__9DD7`. `make test` stayed at 29/29
    throughout, because a name cannot move a byte. The attempt was reverted
    (see git history around this file's addition) and the family still needs
    `apply_branch_scoped_names.py`, or a per-port proposal pair, so each port
    gets the right offset under one name.
  * **the run has a hole.** An unnamed arm in the middle of a named family is
    a missing name, not an absence, because the ladder proves the case exists.

What it reports
---------------
Per ladder: the variable, the case range, whether the cases are contiguous,
how many arms draw a still-numbered constant, and -- where the drawn names
share a family with a numeric tail -- whether `index - case` is the same for
every arm.

`MISMATCH` means the family and the ladder disagree about order, which is the
CAPSULE defect. `unnamed arms` inside an otherwise named family is the other.

Usage
-----
    python3 notes/dispatch-ladders/ladder_index_check.py
    python3 notes/dispatch-ladders/ladder_index_check.py --all
"""
from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels"
PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]
RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
RE_CASE = re.compile(r"^(.*)_CASE_([0-9A-F]+)$")
RE_GUARD = re.compile(r"^\s*(?:jne|je)\s+\[(0x[0-9A-Fa-f]+)\],\s*(0x[0-9A-Fa-f]+),")
RE_DRAW = re.compile(r"video (?:type=0, )?offset=([A-Za-z_][A-Za-z0-9_]*),")
RE_NUM = re.compile(r"^(?:CINEMATIC_\d+|CV_[0-9A-F]{4})$")
RE_FAM = re.compile(r"^(.*?)_(\d+)$")


def ladders(port: str, stage: str):
    p = SRC / PORTS[port] / f"{stage}.asm"
    if not p.is_file():
        return {}
    out: dict = collections.defaultdict(dict)
    cur, buf = None, []

    def flush(cur, buf):
        if not cur:
            return
        m = RE_CASE.match(cur)
        if not m:
            return
        var = None
        draws = []
        for line in buf:
            g = RE_GUARD.match(line)
            if g and var is None:
                var = g.group(1)
                continue
            d = RE_DRAW.search(line)
            if d:
                draws.append(d.group(1))
        if var and len(draws) == 1:
            out[(m.group(1), var)][int(m.group(2), 16)] = draws[0]

    for line in p.read_text(errors="replace").splitlines():
        mm = RE_LBL.match(line)
        if mm:
            flush(cur, buf)
            cur, buf = mm.group(1), []
        elif cur is not None:
            buf.append(line)
    flush(cur, buf)
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--all", action="store_true",
                    help="show every ladder, not only the ones with a finding")
    args = ap.parse_args()

    findings = 0
    for port in sorted(PORTS):
        for stage in STAGES:
            for (base, var), arms in sorted(ladders(port, stage).items()):
                if len(arms) < 3:
                    continue
                cases = sorted(arms)
                contig = cases == list(range(min(cases), max(cases) + 1))
                unnamed = [c for c in cases if RE_NUM.match(arms[c])]
                offs = set()
                for c in cases:
                    if RE_NUM.match(arms[c]):
                        continue
                    # A `_CASE_<hex>` tail is the ladder's own case number in
                    # HEX, not a decimal family index. Reading it as decimal
                    # made this checker report PASSCODE's alphanum ladder as a
                    # MISMATCH purely because `_CASE_10` is case 0x10: the
                    # "index" 10 minus the case 16 gave -6 where every other
                    # arm gave 0. That is the checker misreading a name, not
                    # the name disagreeing with the ladder.
                    if RE_CASE.match(arms[c]):
                        continue
                    m = RE_FAM.match(arms[c])
                    if m:
                        offs.add(int(m.group(2)) - c)
                mismatch = len(offs) > 1
                note = []
                if unnamed and len(unnamed) < len(cases):
                    note.append(f"{len(unnamed)} unnamed arm(s) inside a "
                                f"named family")
                if mismatch:
                    note.append(f"MISMATCH: index-case takes {len(offs)} "
                                f"different values {sorted(offs)}")
                if not note and not args.all:
                    continue
                findings += bool(note)
                print(f"\n{port}/{stage}  {base}_CASE_*  on [{var}]")
                print(f"  cases 0x{min(cases):02X}..0x{max(cases):02X}, "
                      f"{len(cases)} arm(s), contiguous={contig}")
                for c in cases:
                    flag = "  <- unnamed" if RE_NUM.match(arms[c]) else ""
                    print(f"    0x{c:02X}  {arms[c]}{flag}")
                for n in note:
                    print(f"  ** {n}")
    print(f"\n{findings} ladder(s) with a finding.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
