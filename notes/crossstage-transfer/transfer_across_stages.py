#!/usr/bin/env python3
"""Name a constant from the same picture already named in another STAGE.

Question answered
-----------------
`notes/crossport-transfer/` carries a name between **ports** when the art is
byte-identical. The same move works between **stages** of one port, and
nothing was doing it: the cinematic banks share art -- a droplet, a teleport
beam, the hero lifting off -- and a picture identified in CAVES is the same
picture in PRISON.

`notes/shot-hit-burst/` is the case that prompted this. CAPSULE's five-frame
spark was stuck behind a routine-family gap while PRISON had the identical
five frames under a complete constant family; transferring by
`canonical_md5` named all ten in each port. That was done by hand. This
generalises it.

The filters, and how much each removes
--------------------------------------
Matching alone gives 49 candidates on amiga and 46 on msdos. Most are not
usable and the reasons are worth the counts:

  36 / 34  **the name carries another stage's prefix.**
           `CINEMATIC_CAVES_TELEPORT_DOWN_BEAM` moved into PRISON asserts
           CAVES inside PRISON. The art travels between stages; the stage
           word does not. Held, not rewritten -- stripping `CAVES_` and
           re-prefixing would invent a name nobody earned.
   6 / 7   **several constants in the target stage match one name** (#0118).
           Six amiga/INTRO constants are byte-identical to
           `CINEMATIC_DROPLET_FALL_TRAIL`; one name cannot go on six.
   0 / 0   the name is already used in the target stage.
  35 / 36  the art matches two or more *different* names elsewhere, so there
           is nothing to transfer (#0120).

  7 / 5    nameable.

A constant **referenced from an all-branch chunk** is held too. The EQU is
renamed per branch, and an unprefixed `_unified/<stage>/*.inc` is read by
every branch -- so renaming amiga's and msdos's definitions while cartridge
keeps `CINEMATIC_555` leaves that shared reference undefined for the two
that moved. `prison_step_draws_and_breaks.inc` naming `CINEMATIC_555` is the
case that found this: verify-unified 27/29 with two undefined references,
while verify-stages stayed 29/29 because each canonical file was internally
consistent.

A name on `disputed.txt` is skipped whatever its evidence:
`CINEMATIC_BUDDY_SMASHING_WINDOW_F8` is recorded in
`../render-attempts/README.md` as art whose own subject is in doubt -- the
routine tiles a beam while the polygon claims to be the alien breaking a
window -- and transferring it would spread a disputed claim.

Signals read
------------
`CINEMATIC_* EQU 0x...` in `src/levels/<branch>/<STAGE>.asm`, and
`canonical_md5(parse_polygon_tree(...))` over that stage's slice of
`cinematic.rom`. Ports without an extracted ROM are skipped and named.

Usage
-----
    python3 notes/crossstage-transfer/transfer_across_stages.py
    python3 notes/crossstage-transfer/transfer_across_stages.py --proposals DIR
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
sys.path.insert(0, str(SRC.parent / "another-world-archaeology" / "tools"))
sys.path.insert(0, str(HERE.parents[1] / "polygon-extent-correction"))
from polygon_tree import parse_polygon_tree, canonical_md5   # noqa: E402
from extent_matches_renderer import slab                     # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
SID = {"CODE_WHEEL": 0, "INTRO": 1, "LAKE": 2, "PRISON": 3, "CAVES": 4,
       "TANK": 5, "CAPSULE": 6, "ENDING": 7, "PASSCODE": 8}
RE_EQU = re.compile(r"^(\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)
RE_NUM = re.compile(r"^CINEMATIC_\d+$")
DISPUTED = HERE.parent / "disputed.txt"

EVIDENCE = (
    "Cross-stage transfer by art identity. The same picture is already "
    "named in another stage of this port, matched by canonical_md5 over the "
    "whole parsed tree, not by index. The carried name has no foreign stage "
    "prefix, no other constant in this stage matches it, and the art matches "
    "exactly one named constant anywhere -- so there is one subject and one "
    "target.")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--proposals", type=Path)
    args = ap.parse_args()

    disputed = set()
    if DISPUTED.is_file():
        disputed = {l.split("#")[0].strip()
                    for l in DISPUTED.read_text().splitlines()
                    if l.split("#")[0].strip()}

    why = collections.Counter()
    out: list[tuple] = []
    for port, br in PORTS.items():
        named: dict[str, set] = {}
        unnamed: list = []
        taken: dict[str, set] = collections.defaultdict(set)
        for stage, sid in SID.items():
            f = SRC / "src" / "levels" / br / f"{stage}.asm"
            if not f.is_file():
                continue
            try:
                bank = slab("cinematic", port, sid)
            except BaseException:
                why[f"{port}: no extracted ROM"] += 1
                continue
            for k, v in RE_EQU.findall(f.read_text(errors="replace")):
                if not k.startswith("CINEMATIC_"):
                    continue
                taken[stage].add(k)
                tree = parse_polygon_tree(bank, int(v, 16))
                if tree is None:
                    continue
                m = canonical_md5(tree)
                if RE_NUM.match(k):
                    unnamed.append((stage, k, m))
                else:
                    named.setdefault(m, set()).add((stage, k))
        prop: dict[tuple, list] = collections.defaultdict(list)
        for stage, k, m in unnamed:
            cand = {n for s2, n in named.get(m, ()) if s2 != stage}
            if len(cand) != 1:
                if cand:
                    why[f"{port}: art matches two or more names"] += 1
                continue
            name = next(iter(cand))
            body = name[len("CINEMATIC_"):]
            if any(body.startswith(s + "_") and s != stage for s in SID):
                why[f"{port}: name carries another stage's prefix"] += 1
                continue
            if name in taken[stage]:
                why[f"{port}: name already used in the target stage"] += 1
                continue
            if name in disputed:
                why[f"{port}: name is on disputed.txt"] += 1
                continue
            arms = SRC / "src" / "levels" / "_unified" / stage.lower()
            shared = [f for f in arms.rglob("*.inc")] if arms.is_dir() else []
            if any("__" not in f.name
                   and re.search(rf"\b{re.escape(k)}\b",
                                 f.read_text(errors="replace"))
                   for f in shared):
                why[f"{port}: referenced from an all-branch chunk"] += 1
                continue
            prop[(stage, name)].append(k)
        for (stage, name), ks in prop.items():
            if len(ks) > 1:
                why[f"{port}: several constants would take one name "
                    f"(#0118)"] += len(ks)
                continue
            out.append((port, stage, ks[0], name))

    print(f"{len(out)} constant(s) nameable by cross-stage art identity\n")
    for k, v in sorted(why.items()):
        print(f"  {v:4d}  held: {k}")
    print()
    for port, stage, k, name in sorted(out):
        print(f"  {port}/{stage:<10}{k:<18} -> {name}")

    if args.proposals:
        args.proposals.mkdir(parents=True, exist_ok=True)
        per: dict[tuple, list] = collections.defaultdict(list)
        for port, stage, k, name in out:
            per[(port, stage)].append((k, name))
        for (port, stage), rows in per.items():
            f = args.proposals / f"xstage_{port}_{stage}.md"
            with f.open("w") as fh:
                fh.write("| constant | proposed name | confidence | "
                         "evidence |\n| --- | --- | --- | --- |\n")
                for k, name in rows:
                    fh.write(f"| {k} | {name} | high | {EVIDENCE} |\n")
            print(f"wrote {f}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
