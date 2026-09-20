#!/usr/bin/env python3
"""One picture, several names -- across STAGES, which no audit was checking.

Question answered
-----------------
`notes/crossport-transfer/ --duplicates` enforces one name per picture
**between ports**, and it has caught real errors this week. Nothing enforced
anything **between stages of one port**, and the cinematic banks share a lot
of art.

    CAPSULE/CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_5
    CAVES/CINEMATIC_CAVES_LASER_BLAST_8
    PRISON/CINEMATIC_PRISON_SHOT_IMPACT_8

Byte-identical (`canonical_md5` over the whole parsed tree), three stages,
three names -- and three different index bases, CAPSULE running three behind
the other two. The whole fade runs that way, frame for frame.

    amiga  1914 named pictures, 60 carry two or more different names
    msdos  1889 named pictures, 59

What this is NOT
----------------
It is not automatically an error, and the probe says so rather than calling
everything a defect. Identical art at two *different offsets* can legitimately
carry two names: the same blank frame reused as two props is two things. What
makes a group suspect is that the names describe **the same subject
differently** -- a charged blast, a laser blast and a shot impact are one
event seen from three stages -- which is the `de-prefix` situation with no
unnamed member to give the game away.

So this reports and does not rewrite. Reconciling three earned names means
choosing among them, and #0120 says a tool must not: a person has to decide
whether CAPSULE's fade, CAVES' blast and PRISON's impact are one name.

What it does decide is the *shape* of each group, because that is
measurable and it separates the cases:

  `same-stage`   two names for one picture inside one stage. If the offsets
                 also match this is #0118 outright; if they differ it may be
                 a reused frame.
  `family`       every member is `<stem>_<n>` and the stems differ -- the
                 charged-blast case, a whole animation named twice.
  `singleton`    one-off pictures sharing art.

Usage
-----
    python3 notes/crossstage-duplicates/one_picture_many_names.py
    python3 notes/crossstage-duplicates/one_picture_many_names.py --list
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
RE_FAM = re.compile(r"^(.*?)_(\d+)$")


def shape(members: set) -> str:
    stages = {s for s, _n, _o in members}
    if len(stages) < len({(s, n) for s, n, _o in members}) - 0 and \
            len(stages) != len(members):
        return "same-stage"
    fams = {RE_FAM.match(n[len("CINEMATIC_"):]) for _s, n, _o in members}
    if all(fams) and len({m.group(1) for m in fams if m}) > 1:
        return "family"
    return "singleton"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--list", action="store_true")
    args = ap.parse_args()

    rc = 0
    for port, br in PORTS.items():
        by: dict[str, set] = collections.defaultdict(set)
        total = 0
        for stage, sid in SID.items():
            f = SRC / "src" / "levels" / br / f"{stage}.asm"
            if not f.is_file():
                continue
            try:
                bank = slab("cinematic", port, sid)
            except BaseException:
                continue
            for k, v in RE_EQU.findall(f.read_text(errors="replace")):
                if not k.startswith("CINEMATIC_") or RE_NUM.match(k):
                    continue
                tree = parse_polygon_tree(bank, int(v, 16))
                if tree is None:
                    continue
                total += 1
                by[canonical_md5(tree)].add((stage, k, v))
        multi = {m: v for m, v in by.items()
                 if len({n for _s, n, _o in v}) > 1}
        kinds = collections.Counter(shape(v) for v in multi.values())
        print(f"{port}: {total} named pictures, {len(multi)} carry two or "
              f"more different names")
        for k, n in sorted(kinds.items()):
            print(f"    {n:4d}  {k}")
        if args.list:
            for m, v in sorted(multi.items(),
                               key=lambda kv: (shape(kv[1]), -len(kv[1]))):
                print(f"  [{shape(v)}] " + " | ".join(
                    f"{s}/{n}" for s, n, _o in sorted(v)))
        same = kinds.get("same-stage", 0)
        if same:
            rc = 1
    print("\nReported, not rewritten. Reconciling earned names means choosing "
          "among them (#0120).\nIdentical art at different offsets may "
          "legitimately be two props; the shape column\nis what separates "
          "those from one animation named twice.")
    return rc


if __name__ == "__main__":
    sys.exit(main())
