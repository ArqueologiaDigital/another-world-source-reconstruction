#!/usr/bin/env python3
"""A stage prefix the art itself falsifies: strip it, and share the name.

Question answered
-----------------
`transfer_across_stages.py` holds its largest category -- 36 candidates on
amiga, 34 on msdos -- because the name it would carry has another stage's
prefix. `CINEMATIC_CAVES_TELEPORT_DOWN_BEAM` moved into PRISON would assert
CAVES inside PRISON.

Held is right for a *transfer*. But the situation is not a transfer problem,
it is a **wrong name**. `docs/NAMING.md` scopes a name to a stage when it
means something there and not elsewhere; if the identical picture is drawn in
CAVES, PRISON and CAPSULE, then `CAVES_` is false about it. The fix is to
take the prefix off and let every stage that draws the picture use the one
name -- which also names the siblings that had none.

This corrects earned names. Among them, three from earlier the same day:
`CINEMATIC_PRISON_HERO_DEATH_F0..F2`, named in PRISON from the scene that
kills the hero, is byte-identical art in CAVES and CAPSULE. The hero dies in
every stage. The frames were right and the prefix was not.

Identity is `canonical_md5` over the whole parsed tree, per port, never the
index -- the constant numbers differ between stages and between ports.

Guards
------
  - the de-prefixed name must be unused anywhere in that port;
  - exactly one constant per stage in the group, or it would put one name on
    two pictures in a stage (#0118);
  - no member may be referenced from an **all-branch** `_unified` chunk: the
    `EQU` is renamed per branch, so a shared reference would dangle for the
    branches that moved. `transfer_across_stages.py` learned this the
    expensive way -- verify-unified 27/29 with two undefined;
  - nothing on `disputed.txt`;
  - **a family is de-prefixed whole or not at all.** The script works per
    picture, and a picture is one member of a family. `CINEMATIC_CAVES_
    HERO_IDLE_DOWN_0`'s art appears in CAPSULE while `_1` to `_4`'s does
    not, so de-prefixing that one member left
    `CINEMATIC_HERO_IDLE_DOWN_0` beside `CINEMATIC_CAVES_HERO_IDLE_DOWN_1..4`
    -- two families with a hole each, and the ports disagreeing about one
    picture. Caught by `--duplicates` and reverted. A member whose
    stage-prefixed siblings are not all in the group is now held.

Usage
-----
    python3 notes/crossstage-transfer/deprefix_shared_art.py
    python3 notes/crossstage-transfer/deprefix_shared_art.py --proposals DIR
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
    "The stage prefix is falsified by the art. This picture is byte-identical "
    "(canonical_md5 over the whole parsed tree) in {n} stages of this port: "
    "{where}. NAMING.md scopes a name to a stage only when it means something "
    "there and not elsewhere, so the prefix was a claim the art contradicts. "
    "Matched by art and not by index -- the constant numbers differ per stage "
    "and per port. No member is referenced from an all-branch unified chunk, "
    "and the de-prefixed name is unused elsewhere in this port.")


def shared_refs(stage: str) -> set:
    d = SRC / "src" / "levels" / "_unified" / stage.lower()
    out: set = set()
    if not d.is_dir():
        return out
    for f in d.rglob("*.inc"):
        if "__" in f.name:
            continue
        out |= set(re.findall(r"\bCINEMATIC_\w+\b",
                              f.read_text(errors="replace")))
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--proposals", type=Path)
    args = ap.parse_args()

    disputed = {l.split("#")[0].strip()
                for l in (DISPUTED.read_text().splitlines()
                          if DISPUTED.is_file() else [])
                if l.split("#")[0].strip()}
    shared = {st: shared_refs(st) for st in SID}

    why = collections.Counter()
    groups: list = []
    for port, br in PORTS.items():
        by_md5: dict[str, list] = collections.defaultdict(list)
        allnames: set = set()
        for stage, sid in SID.items():
            f = SRC / "src" / "levels" / br / f"{stage}.asm"
            if not f.is_file():
                continue
            try:
                bank = slab("cinematic", port, sid)
            except BaseException:
                continue
            for k, v in RE_EQU.findall(f.read_text(errors="replace")):
                if not k.startswith("CINEMATIC_"):
                    continue
                allnames.add(k)
                tree = parse_polygon_tree(bank, int(v, 16))
                if tree is not None:
                    by_md5[canonical_md5(tree)].append((stage, k))
        for m, members in by_md5.items():
            named = [(s, k) for s, k in members if not RE_NUM.match(k)]
            blank = [(s, k) for s, k in members if RE_NUM.match(k)]
            if len(named) != 1 or not blank:
                continue
            src_stage, old = named[0]
            body = old[len("CINEMATIC_"):]
            pre = next((s for s in SID if body.startswith(s + "_")), None)
            if pre is None or pre != src_stage:
                continue
            new = "CINEMATIC_" + body[len(pre) + 1:]
            if new in allnames:
                why[f"{port}: de-prefixed name already in use"] += 1
                continue
            if old in disputed:
                why[f"{port}: on disputed.txt"] += 1
                continue
            stages = [s for s, _ in members]
            if len(stages) != len(set(stages)):
                why[f"{port}: two constants in one stage (#0118)"] += 1
                continue
            if any(k in shared[s] for s, k in members):
                why[f"{port}: a member is referenced from an all-branch "
                    f"chunk"] += 1
                continue
            # Whole family or none: a stage-prefixed sibling left behind
            # splits the index run in two.
            fam = re.match(r"^(.*?)_(\d+)$", body)
            if fam:
                sib = re.compile(
                    rf"^CINEMATIC_{re.escape(pre)}_"
                    rf"{re.escape(fam.group(1)[len(pre) + 1:])}_\d+$")
                if any(sib.match(n2) for n2 in allnames
                       if n2 != old):
                    why[f"{port}: would split a family, siblings keep the "
                        f"prefix"] += 1
                    continue
            groups.append((port, old, new, members))

    print(f"{len(groups)} group(s); "
          f"{sum(len(g[3]) for g in groups)} constant(s) affected\n")
    for k, v in sorted(why.items()):
        print(f"  {v:4d}  held: {k}")
    print()
    for port, old, new, members in sorted(groups):
        print(f"  {port}  {old}\n        -> {new}   "
              f"({', '.join(f'{s}/{k}' for s, k in sorted(members))})")

    if args.proposals:
        args.proposals.mkdir(parents=True, exist_ok=True)
        per: dict[tuple, list] = collections.defaultdict(list)
        for port, old, new, members in groups:
            where = ", ".join(sorted({s for s, _ in members}))
            ev = EVIDENCE.format(n=len(members), where=where)
            for s, k in members:
                per[(port, s)].append((k, new, ev))
        for (port, stage), rows in sorted(per.items()):
            f = args.proposals / f"deprefix_{port}_{stage}.md"
            with f.open("w") as fh:
                fh.write("| constant | proposed name | confidence | "
                         "evidence |\n| --- | --- | --- | --- |\n")
                for k, new, ev in rows:
                    fh.write(f"| {k} | {new} | high | {ev} |\n")
            print(f"wrote {f} ({len(rows)})")
    return 0


if __name__ == "__main__":
    sys.exit(main())
