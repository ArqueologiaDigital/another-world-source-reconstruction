#!/usr/bin/env python3
"""Settle T7's premise at the byte level, not by inference.

Question answered
-----------------
`cv_offset_is_port_invariant.py` next to this file tests T7's premise from the
**assembly**: it pairs routines across ports by identical body and checks they
draw the shared bank at the same offsets. That gave 71 strong agreements
amiga-vs-msdos and 0 disagreements -- but only **24.1% coverage**, because it
can only see offsets that shared routines actually draw from. Its README says
so, and says the migration should diff the ROM bytes instead.

This is that diff. `docs/NAMING.md` §5 identifies the bank:

    Also: resource `0x11`, typed "UNKNOWN", is the shared video2 bank. It is
    bound by the engine's part table rather than by any `load`, and the
    highest `COMMON_VIDEO` EQU value (`0x61B0` = 25,008) fits inside its
    25,108 bytes with 100 to spare, which no other resource does.

So the premise -- "the bank is byte-identical between Amiga and MS-DOS, so one
name per offset is correct" -- is a statement about one file per port, and is
answerable exactly rather than statistically.

Result, 2026-09-19
------------------
Both ports' resource 0x11 are 25,108 bytes and hash to

    ee98e9d5cca18a4fd0c3d0dac884e38a11533cd8fd88825cd503eeb0658494b0

`cmp` reports no difference. **T7's premise is proven for the two priority
ports at 100% coverage**, not merely unrefuted over a quarter of the bank.
The size also matches the figure NAMING.md §5 quotes independently.

snes_eu and gba_usa are NOT covered: neither has a resource 0x11 in the
extracted tree, and the GBA release packages its art differently (it ships a
`cinematic.rom` the others do not). For snes_eu the only evidence remains the
61 assembly-level agreements from the sibling probe.

Where the bytes come from, and why the hash is here
---------------------------------------------------
The resource dumps live under `another-world-archaeology/tmp/output/<port>/`,
which is **volatile** -- regenerable, and not in git. So the baseline hash is
written into this file, and the recipe to regenerate the input is:

    cd another-world-archaeology
    python3 tools/aw_unpacker.py            # writes tmp/output/<port>/resources/

Run this probe against a fresh extraction and it will tell you whether the
bank still hashes to the recorded baseline. A mismatch means either the
extraction changed or the claim needs revisiting; either way it should not
pass silently.

Exit status
-----------
0 when every available port's bank matches the baseline hash and each other.
1 on any mismatch. 2 when fewer than two ports have the resource, since then
there is nothing to compare and reporting success would be a lie.

Usage
-----
    python3 notes/shared-bank-probes/shared_bank_bytes_identical.py
"""
from __future__ import annotations

import hashlib
import sys
from pathlib import Path

ARCH = Path(__file__).resolve().parents[3] / "another-world-archaeology"
OUT = ARCH / "tmp" / "output"
RESOURCE = "resource-0x11.bin"

BASELINE_SHA256 = ("ee98e9d5cca18a4fd0c3d0dac884e38a"
                   "11533cd8fd88825cd503eeb0658494b0")
BASELINE_SIZE = 25108


def main() -> int:
    if not OUT.is_dir():
        print(f"no extraction at {OUT}")
        print("regenerate with:  cd another-world-archaeology && "
              "python3 tools/aw_unpacker.py")
        return 2

    found = {}
    for port_dir in sorted(OUT.iterdir()):
        f = port_dir / "resources" / RESOURCE
        if f.is_file():
            data = f.read_bytes()
            found[port_dir.name] = (len(data),
                                    hashlib.sha256(data).hexdigest())

    print(f"resource 0x11 -- the shared video2 bank (NAMING.md §5)")
    print(f"baseline: {BASELINE_SIZE} bytes, sha256 {BASELINE_SHA256}")
    print()
    bad = False
    for port, (size, digest) in found.items():
        ok = (size == BASELINE_SIZE and digest == BASELINE_SHA256)
        bad |= not ok
        print(f"  {port:<10}{size:>8} bytes  {digest[:32]}...  "
              f"{'matches baseline' if ok else 'DIFFERS FROM BASELINE'}")
    missing = [p.name for p in sorted(OUT.iterdir())
               if p.is_dir() and p.name not in found]
    for port in missing:
        print(f"  {port:<10}{'':>8}         (no {RESOURCE}; not covered)")

    if len(found) < 2:
        print(f"\nonly {len(found)} port(s) have the bank extracted -- "
              f"nothing to compare")
        return 2
    if bad:
        print("\nA BANK DIFFERS FROM THE RECORDED BASELINE")
        return 1
    ports = ", ".join(found)
    print(f"\nIdentical across {ports}, and equal to the recorded baseline.")
    print("T7's premise -- one name per offset is correct because the bank is "
          "the same\nfile -- holds for those ports at 100% coverage.")
    if missing:
        print(f"Not covered: {', '.join(missing)}.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
