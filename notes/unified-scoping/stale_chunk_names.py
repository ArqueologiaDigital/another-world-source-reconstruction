#!/usr/bin/env python3
"""How many unified chunk files are named after a label that no longer exists?

Question answered
-----------------
A branch-scoped chunk is filed as `<prefix>__post_<LABEL>.inc`, where `<LABEL>`
is the label the chunk follows in emission order:

    .if BRANCH == "chahi_amiga_1991"
    .include "amiga__post_INLINE_DRAW_CIN_659_AT_160_100.inc"

Nothing renames that file when the label is renamed. `INLINE_DRAW_CIN_659_AT_160_100`
became `PRISON_WAKE_CLOSEUP_EYELID_FULLY_RAISED` on 2026-09-23 and the file
kept the old spelling, which now appears nowhere else in the tree.

This costs nothing at build time -- the `.include` is by filename, and
`make test` cannot see it -- but the filename is the only record of *where* a
chunk sits, so a stale one sends a reader looking for a label that is gone.
Several also embed picture indices (`DRAW_CIN657_AT_X1A_Y1B`) that
`docs/NAMING.md` bars from names.

Signal read
-----------
Every `*__post_<LABEL>.inc` under `src/levels/_unified/`, against the set of
label definitions (`^NAME:`) anywhere in that tree. A file is stale when its
`<LABEL>` is defined nowhere. That is deliberately the weakest possible test:
it cannot tell a chunk whose anchor MOVED from one whose anchor was renamed,
and it says nothing about `<prefix>__entry.inc`, which carries no label name.

Measured 2026-09-23: **237 of 889** chunk files, 27%, across every stage. It
is the residue of every routine rename the project has ever applied, not of
any one of them.

Run it
------
    python3 notes/unified-scoping/stale_chunk_names.py
    python3 notes/unified-scoping/stale_chunk_names.py --list
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

UNI = Path(__file__).resolve().parents[2] / "src" / "levels" / "_unified"
RE_DEF = re.compile(r"^([A-Za-z_]\w*):\s*$", re.M)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--list", action="store_true",
                    help="print every stale file, not just the counts")
    args = ap.parse_args()

    defs: set[str] = set()
    for f in UNI.rglob("*.inc"):
        defs.update(RE_DEF.findall(f.read_text(errors="replace")))

    chunks = sorted(UNI.rglob("*__post_*.inc"))
    stale = [f for f in chunks
             if f.name.split("__post_", 1)[1][:-4] not in defs]

    per: dict[str, list[int]] = collections.defaultdict(lambda: [0, 0])
    for f in chunks:
        per[f.parent.name][0] += 1
    for f in stale:
        per[f.parent.name][1] += 1

    print(f"  {'stage':<12}{'chunks':>8}{'stale':>8}{'':>4}")
    for stage in sorted(per):
        n, s = per[stage]
        print(f"  {stage:<12}{n:>8}{s:>8}    {100 * s / n:5.1f}%")
    print(f"\n  {len(stale)} of {len(chunks)} chunk file(s) name a label that "
          f"is defined nowhere in the unified tree"
          f"  ({100 * len(stale) / len(chunks):.0f}%)")

    if args.list:
        print()
        for f in stale:
            print(f"    {f.relative_to(UNI)}")
    else:
        print("  --list to see them")
    return 0


if __name__ == "__main__":
    sys.exit(main())
