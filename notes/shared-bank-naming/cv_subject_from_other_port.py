#!/usr/bin/env python3
"""Shared-bank symbols whose subject another port already established.

Question answered
-----------------
`docs/NAMING.md` §2: "**The shared bank (`COMMON_VIDEO_NNN`) has no semantic
names at all** ... Before these can be named, the emitter must key them by
offset (plan item T7)." The re-key half of T7 landed on 2026-09-19 and the
bank is now addressed as `CV_<OFFSET4>`. The naming half still has no
evidence base: 1,260 routines are blocked behind it, and a render of a bank
frame on its own settles no more than a render of any other frame.

This builds the evidence base from something the tree already contains. Where
the two priority ports draw the same scene, one port sometimes keeps the art
in its per-stage cinematic bank -- where it has an earned name -- while the
other draws it from the shared bank. At those sites the shared-bank symbol's
subject is not unknown at all. It is written down in the other port.

How a pair is found, and how it is checked
------------------------------------------
In msdos, a draw of `CV_<hex>` immediately followed by a draw of a
semantically-named `CINEMATIC_*` **at the same x and y** is the signature: the
shared-bank frame plus a small per-frame companion the stage kept locally.
Amiga draws only the `CINEMATIC_*` there.

The pair is then **verified against the art**, which is what keeps this from
being the by-index copying it is meant to help undo: amiga's polygon for that
name, measured in amiga's own cinematic slab, must equal the `CV_` polygon
measured in `video2.rom` in extent and leaf count. Sites where they differ are
counted and dropped -- and most do differ, because usually the companion is
simply a different object.

Result on 2026-09-19
--------------------
67 paired sites, 21 verifying, **15 distinct (CV symbol, name) pairs** -- all
in LAKE, all the hero's walk, run and stop cycle:

    CV_4D98 = HERO_WALK_RIGHT_0   76x66/10      CV_4EC8 = HERO_RUN_RIGHT_0   81x66/10
    CV_4DE4 = HERO_WALK_RIGHT_1   78x66/10      CV_4F68 = HERO_RUN_RIGHT_2   95x66/10
    CV_4E30 = HERO_WALK_RIGHT_2   79x66/10      CV_500C = HERO_RUN_RIGHT_4   94x66/10
    CV_4E7C = HERO_WALK_RIGHT_3   80x66/10      CV_50A8 = HERO_STOP_RIGHT_0  72x66/10

These are not applied here and must not be until T7's naming half opens: the
bank is shared by every stage and a name written onto it is a claim about all
of them. This is the worklist that pass should start from, with the check
already done.

A second finding, which is why this file exists at all
------------------------------------------------------
It also explains a row in `notes/crossport-name-audit/`. msdos/LAKE's
`CINEMATIC_HERO_RUN_LEFT_0` measures 2x5 with one leaf where amiga's measures
17x39 with six. That looked like more by-index copying, but it is not quite:
msdos draws the hero from `CV_5340` and keeps a 2x5 companion locally, and the
name landed on the companion. Sixteen names in that stage are in the same
position, on a contiguous run of 2x5 marks spaced 0x0A apart.

What the companion IS can be read off the run itself, and it is why this was
not "fixed" by demoting. `CINEMATIC_HERO_SHADOW` sits at 0xDFFC **inside that
same run**, correctly named, drawn 28 times in msdos/LAKE and never once in
amiga/LAKE, always in the same shape of site: `DRAW_HERO_WALK_LEFT_F9` draws
`CV_0020` and then `CINEMATIC_HERO_SHADOW` at one x and y. The run is the
hero's per-frame shadow, and seventeen of its eighteen records carry a
hero-frame name they did not earn.

Still not renamed here, for two reasons worth stating rather than working
around:

  * msdos/LAKE has 669 `CINEMATIC_*` EQUs and **no numeric ones** -- it was
    the naming pilot and is fully named -- so "demote to the index" has no
    spelling in that stage. I generated exactly that batch and the family-gap
    rule rejected it, which was the tool being right.
  * the run is 18 group records with only 6 distinct headers, and amiga's own
    `CINEMATIC_HERO_RUN_LEFT_0` measures 17x39 with 6 leaves against its
    neighbours' ~80x66 with 10, so amiga's side may not be uniform either.

The evidence is now stronger than "wants a render". Measured 2026-09-19:
**all 17 names, across all 66 of their draw sites, are immediately preceded
by a `CV_<hex>` draw at the same x and y -- 66 of 66, no exceptions** -- and
all 17 offsets fall inside 0xDFF2..0xE09C, the run holding the already-named
`CINEMATIC_HERO_SHADOW` at 0xDFFC. The frame association is sound even
though the subject was not, because amiga draws its own frame of that name
at the corresponding point. So the fitting rename keeps pose and index and
corrects only the subject: `CINEMATIC_HERO_<pose>_<n>` ->
`CINEMATIC_HERO_SHADOW_<pose>_<n>`. That table is committed un-applied as
`docs/content/research/2026-09-19-caves-hero-direction-machine/`
`proposals_LAKE_shadow_family_NOT_APPLIED.md`.

**Applied 2026-09-19, after four attempts.** The first three were reverted
and each failure mapped the obstacle:

  * branch-scoped to dos_1992: 12 undefined references, because LAKE keeps
    these draw lines in SHARED chunks rather than per-branch arms;
  * with `--arm`, which splits such a line: down to 8. The arms that remain
    are `.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")` -- one
    line serving THREE ports -- so renaming for one strands the other two on
    a name only it defines;
  * applied to all three 1992 ports: one stage still failing, and now it is
    **amiga** that breaks, because LAKE shares the EQU definitions too and
    rewriting them for the 1992 ports removes the one amiga reads.

The cause, once mapped rather than guessed at: LAKE's shared chunk uses the
unconditional block as a DEFAULT that the per-branch blocks override
selectively, and **which port the default belongs to varies by name** --
0xF26C for `WALK_RIGHT_0` is amiga's, 0xE006 for `WINDUP_0` is msdos's. A
branch-scoped rename kept hitting the unconditional definition, which is the
one amiga reads.

The fix was to make every branch's definition explicit first, which is
byte-neutral because EQU lines emit no bytes: nine names whose default was
amiga's value were wrapped in `.if BRANCH == "chahi_amiga_1991"`, and
`STOP_RIGHT_2`, defined in another chunk behind a degenerate
`.if dos_1992 / .else` with the same value in both arms, was given an
amiga-only block of its own. The rename then applied across the three 1992
ports with `--arm` and the tree stayed at 29/29 and 29/29.

`notes/unified-symbol-check/undefined_symbols.py` caught every failed attempt
before the byte gate did -- 12 references, then 8, then 10, then 1 -- which
is what it is for, and the count falling was how the diagnosis was steered.

Usage
-----
    python3 notes/shared-bank-naming/cv_subject_from_other_port.py
    python3 notes/shared-bank-naming/cv_subject_from_other_port.py --all-sites
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT.parent / "another-world-archaeology" / "tools"))
from _paths import REPO_ROOT                       # noqa: E402
from polygon_tree import parse_polygon_tree        # noqa: E402
from polygon_extent import extent                  # noqa: E402

STAGES = {0: "CODE_WHEEL", 1: "INTRO", 2: "LAKE", 3: "PRISON", 4: "CAVES",
          5: "TANK", 6: "CAPSULE", 7: "ENDING", 8: "PASSCODE"}
SLAB = 0x10000
RE_V = re.compile(r"video\s+(?:type=\d+,\s*)?offset=([A-Za-z_]\w*)\s*,"
                  r"\s*x=(\S+?)\s*,\s*y=(\S+?)(?:\s*,|\s*$)")
RE_NUM = re.compile(r"^CINEMATIC_\d+$")
RE_CV = re.compile(r"^CV_([0-9A-F]{4})$")
RE_EQU = re.compile(r"^(CINEMATIC_\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--all-sites", action="store_true",
                    help="also list the paired sites whose art does NOT match")
    args = ap.parse_args()

    cine = REPO_ROOT / "tmp" / "output" / "amiga" / "romset" / "cinematic.rom"
    bank = REPO_ROOT / "tmp" / "output" / "msdos" / "romset" / "video2.rom"
    if not (cine.is_file() and bank.is_file()):
        print("run `make extract` first", file=sys.stderr)
        return 2
    amiga_rom, v2 = cine.read_bytes(), bank.read_bytes()

    def ext(b: bytes, off: int):
        a = extent(parse_polygon_tree(b, off))
        return None if a[4] == 0 else (round(a[2] - a[0]),
                                       round(a[3] - a[1]), a[4])

    counts = collections.Counter()
    pairs: dict[tuple[str, str], tuple] = {}
    misses: list[tuple] = []
    for si, stage in STAGES.items():
        fa = ROOT / "src" / "levels" / "chahi_amiga_1991" / f"{stage}.asm"
        fm = ROOT / "src" / "levels" / "dos_1992" / f"{stage}.asm"
        if not (fa.is_file() and fm.is_file()):
            continue
        tab = {m.group(1): int(m.group(2), 16)
               for m in RE_EQU.finditer(fa.read_text(errors="replace"))}
        slab = amiga_rom[si * SLAB:(si + 1) * SLAB]
        prev = None
        for line in fm.read_text(errors="replace").splitlines():
            m = RE_V.search(line.split(";", 1)[0])
            if not m:
                continue
            name, x, y = m.groups()
            if (prev and RE_CV.match(prev[0])
                    and name.startswith("CINEMATIC_")
                    and not RE_NUM.match(name)
                    and (x, y) == (prev[1], prev[2]) and name in tab):
                counts["paired sites"] += 1
                ea = ext(slab, tab[name])
                ec = ext(v2, int(RE_CV.match(prev[0]).group(1), 16))
                if ea and ec and ea == ec:
                    counts["  art of CV equals art of the other port's name"] += 1
                    pairs[(prev[0], name)] = (stage, ea)
                elif ea and ec:
                    counts["  art differs -- companion is another object"] += 1
                    misses.append((stage, prev[0], name, ea, ec))
                else:
                    counts["  unparsable"] += 1
            prev = (name, x, y)

    for k, v in counts.items():
        print(f"{v:6d}  {k}")
    print(f"\n{len(pairs)} distinct shared-bank symbol(s) with a subject "
          f"established in the other port:\n")
    for (cv, name), (stage, a) in sorted(pairs.items()):
        print(f"  {cv:<10} = {name:<40} {a[0]}x{a[1]}/{a[2]}   ({stage})")
    if args.all_sites and misses:
        print(f"\nnot matched ({len(misses)}) -- the local companion is a "
              f"different object:")
        for stage, cv, name, ea, ec in misses[:30]:
            print(f"  {stage:<9} {cv:<10} {ec[0]}x{ec[1]}/{ec[2]:<5} "
                  f"vs {name} {ea[0]}x{ea[1]}/{ea[2]}")
    print("\nNOT applied. The bank is shared by every stage, so a name written "
          "onto it is a claim\nabout all of them -- that is T7's naming half. "
          "This is the checked worklist for it.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
