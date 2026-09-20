#!/usr/bin/env python3
"""How much of the ASSET layer is named? The lint's percentage does not say.

Question answered
-----------------
`lint_naming.py` reports a per-stage "semantic share", and it is the number
every progress report quotes -- PRISON 32.0 %, CAVES 26.3 %, CAPSULE 25.9 %.
Its own docstring says what it covers: "strict-semantic **labels** as a
percentage", and the code divides by `len(labels)`.

Labels are routines. The goal is "bytecode **and assets**", and the asset
layer -- the `CINEMATIC_*` and shared-bank EQUs that say what is drawn -- is
not in that ratio at all. Naming six shared-bank polygons on 2026-09-19 moved
it by exactly zero, which is correct and also means the number cannot be read
as coverage of the whole job.

The lint does count unnamed assets, as `numeric-cinematic` violations, but as
raw counts with no denominator, so there is no asset-side percentage to put
beside the routine-side one. This supplies it.

What is counted
---------------
Per port and stage, every `EQU` that names a polygon, split by whether the
name is still a key or has become a description.

**An asset is identified by use, not by prefix.** A symbol counts if it
appears as a `video ... offset=<symbol>` operand in the file, or still carries
one of the placeholder prefixes. Selecting on `^(CINEMATIC|CV|COMMON_VIDEO)_`
alone, as this did until 2026-09-20, silently *removed* a polygon from the
population the moment it was named something that did not start with one of
those — so naming 52 shared-bank offsets dropped the denominator by 360
(each key is defined in several stages) and moved the headline from 38.9 % to
40.3 % with the numerator frozen at 3,947. Counting by use instead, the same
batch reads **3,949/10,147 = 38.9 % before and 4,309/10,147 = 42.5 % after**:
the numerator carries all of the movement and the denominator does not move
at all, which is what a coverage metric has to do.

  numbered    `CINEMATIC_<digits>` -- disassembler encounter order
  offset-key  `CV_<4 hex>` -- T7's interim port-invariant key, which says
              where the art is and not what it is
  named       anything else: a description earned from a render

`CV_<4 hex>` is deliberately counted as **unnamed**. It is an improvement on
`COMMON_VIDEO_NNN` -- it means the same art on every port, so one
identification can serve all of them -- but it is not an identification.

Exit status
-----------
0 always.

Usage
-----
    python3 notes/shared-bank-naming/asset_naming_share.py
    python3 notes/shared-bank-naming/asset_naming_share.py --all
"""
from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels"
PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992",
         "snes_eu": "cartridge_1992", "gba_usa": "gba_2004"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]

RE_EQU = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s+0x[0-9A-Fa-f]+")
RE_NUMBERED = re.compile(r"^CINEMATIC_\d+$")
RE_OFFKEY = re.compile(r"^CV_[0-9A-F]{4}$")
RE_POLY = re.compile(r"^(CINEMATIC|CV|COMMON_VIDEO)_")
RE_USE = re.compile(r"offset=([A-Za-z_][A-Za-z0-9_]*)")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", action="append", choices=sorted(PORTS))
    ap.add_argument("--all", action="store_true")
    args = ap.parse_args()
    ports = args.port or (sorted(PORTS) if args.all else ["amiga", "msdos"])

    grand = collections.Counter()
    print(f"{'port/stage':<18}{'assets':>8}{'named':>8}{'numbered':>10}"
          f"{'offset-key':>12}{'named %':>9}")
    for port in ports:
        for stage in STAGES:
            p = SRC / PORTS[port] / f"{stage}.asm"
            if not p.is_file():
                continue
            c = collections.Counter()
            text = p.read_text(errors="replace")
            drawn = set(RE_USE.findall(text))
            for line in text.splitlines():
                m = RE_EQU.match(line)
                if not m:
                    continue
                n = m.group(1)
                if not (RE_POLY.match(n) or n in drawn):
                    continue
                c["assets"] += 1
                if RE_NUMBERED.match(n) or n.startswith("COMMON_VIDEO_"):
                    c["numbered"] += 1
                elif RE_OFFKEY.match(n):
                    c["offset-key"] += 1
                else:
                    c["named"] += 1
            if not c["assets"]:
                continue
            pct = 100.0 * c["named"] / c["assets"]
            print(f"{port + '/' + stage:<18}{c['assets']:>8}{c['named']:>8}"
                  f"{c['numbered']:>10}{c['offset-key']:>12}{pct:>8.1f}%")
            grand.update(c)

    if grand["assets"]:
        pct = 100.0 * grand["named"] / grand["assets"]
        print(f"\n{'TOTAL':<18}{grand['assets']:>8}{grand['named']:>8}"
              f"{grand['numbered']:>10}{grand['offset-key']:>12}{pct:>8.1f}%")
        print(f"\nThe lint's per-stage percentage counts LABELS (routines) and "
              f"says nothing\nabout these. Both halves are the goal.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
