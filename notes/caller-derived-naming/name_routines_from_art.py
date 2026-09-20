#!/usr/bin/env python3
"""Name a draw routine from the art it draws, once that art has a name.

Question answered
-----------------
`named_art_only.py` beside this file measures how much of the routine layer
the polygon layer has unblocked. Its point was that the answer was almost
zero: on 2026-09-19, 112 routines drew only identified art and just **12** had
a draw-set no sibling shared, so the other 100 would have collided (#0118).

Naming the shared bank changed that number. It is now **140 unique**, and this
turns them into names.

The rule, and the two ways a name is chosen
-------------------------------------------
A routine whose every `video offset=` operand names an already-identified
polygon has its subject settled by the art rather than by the namer -- the E3
render-before-naming bar was met by whoever named the constant, and the
routine inherits it. For such a routine:

1. **Reuse before invent.** If a routine in *any other* file draws exactly the
   same set and already has a semantic name, take that name. The same block
   exists in several ports and stages, and giving it one name everywhere is
   both more consistent and less invention than deriving a new one. This is
   also how the existing `HERO_GUN_ARM_POSE_LEFT_CASE_02` in CAVES gets
   carried to its counterparts instead of being shadowed by a parallel
   `DRAW_...` spelling.

   **A stage-prefixed name is never carried into another stage.** The first
   version of this rule proposed `CAVES_HERO_WATER_DEPTH_SPRITE_RIGHT_CASE_00`
   for a block in CAPSULE and `CAVES_HERO_WATER_DEPTH_SPRITE_LEFT_CASE_00` for
   one in PRISON, which asserts a stage the routine is not in. The art is
   shared between stages; the routine is not. Where the earned name carries a
   foreign stage prefix, the name is derived instead.

2. **Otherwise derive from the art**, as the longest common underscore-prefix
   of the drawn names, with the layer word (`BODY`, `ARM`) and any per-name
   index dropped -- and then **the shared index put back** if every drawn name
   carries the same one. That last step is not cosmetic. Without it a routine
   drawing `HERO_GUN_ARM_RIGHT_CASE_01` and its `_CHARGE_BLINK` companion, and
   another drawing the `CASE_02` pair, both derive `DRAW_HERO_GUN_ARM_RIGHT`:
   four blocks, one name, which is exactly the collision the probe exists to
   avoid. The index is what distinguishes them and it comes from the art.

Refusals, each of which fires
-----------------------------
  - any operand still `CINEMATIC_<n>`, `COMMON_VIDEO_<n>` or `CV_<hex>`:
    nothing is settled, the routine stays backlog;
  - the draw-set is shared with another unnamed routine in the same file:
    one name would land on several labels (#0118);
  - two candidates in one file derive the same name;
  - the target name already exists in that file;
  - the routine is an unreachable byte (#0126), via `find_dead_tail_bytes`;
  - the routine is listed in `name_routines_from_art.skip`, which records what
    an earlier pass looked at and rejected, with the reason. Without it this
    pass silently re-proposes `LABEL_4CC4` in CAPSULE, whose art
    (`CINEMATIC_BUDDY_SMASHING_WINDOW_F8`) is itself disputed -- the routine
    tiles a beam while the polygon claims to be the alien breaking a window.
    A routine cannot inherit a subject from art whose subject is in doubt.

Family spelling
---------------
`name_routines_from_art.spelling` maps a derived name onto the spelling an
earned sibling already uses. Without it the gun-arm routines come out as
`DRAW_HERO_GUN_ARM_RIGHT_CASE_01` and `_CASE_04` beside the earned
`HERO_GUN_ARM_POSE_CASE_02` and `_CASE_03` -- two families with a hole each
instead of one complete run 01..04, which NAMING.md §2 forbids. Every line in
that file names the earned sibling that justifies it.

Scope note
----------
Some of these labels are interior blocks of a larger named routine -- the
`else` arm of a dispatch, say. Naming them is still an improvement over
`LABEL_6CE8`, and the tree already does it (`DRAW_CV_099` is a jump target
inside a walk phase). The name describes what the block draws, which is true
of an interior block as much as of an entry point.

Usage
-----
    python3 notes/caller-derived-naming/name_routines_from_art.py
    python3 notes/caller-derived-naming/name_routines_from_art.py --proposals
    python3 notes/caller-derived-naming/name_routines_from_art.py --refusals
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
ARCH = SRC.parent / "another-world-archaeology"
sys.path.insert(0, str(ARCH / "tools"))
from naming_census import classify                 # noqa: E402
from find_dead_tail_bytes import analyse           # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES",
          "TANK", "CAPSULE", "ENDING", "PASSCODE"]

RE_LABEL = re.compile(r"^([A-Za-z_]\w*):")
RE_DRAW = re.compile(r"\bvideo\b[^;]*?offset=([A-Za-z_]\w*)")
RE_NUMERIC = re.compile(r"^(CINEMATIC_\d+|COMMON_VIDEO_\d+|CV_[0-9A-F]{4})$")
RE_INDEX = re.compile(r"_((?:CASE_|F)\d+)(?:_|$)")
LAYER_WORDS = {"BODY", "ARM", "CASE"}
# A bank word is not a subject: DRAW_CINEMATIC_X says where the art lives.
BANK_WORDS = {"CINEMATIC", "CV", "COMMON"}
SKIP = HERE.with_suffix(".skip")
SPELLING = HERE.with_suffix(".spelling")


def derive(arts: tuple[str, ...]) -> str:
    parts = [a.split("_") for a in arts]
    out: list[str] = []
    for i in range(min(len(p) for p in parts)):
        col = {p[i] for p in parts}
        if len(col) != 1:
            break
        out.append(parts[0][i])
    while out and (out[-1] in LAYER_WORDS or re.fullmatch(r"F?\d+", out[-1])):
        out.pop()
    while out and out[0] in BANK_WORDS:
        out.pop(0)
    base = "_".join(out)
    idx = {m.group(1) for a in arts if (m := RE_INDEX.search(a))}
    if len(idx) == 1:
        base = f"{base}_{idx.pop()}"
    return base


def collect():
    """per file: {label: draws}, plus the set of labels already taken."""
    files = {}
    for port, br in PORTS.items():
        for stage in STAGES:
            p = SRC / "src" / "levels" / br / f"{stage}.asm"
            if not p.is_file():
                continue
            text = p.read_text(errors="replace")
            dead = {n for n, *_ in analyse(p)}
            cur, body = None, collections.defaultdict(list)
            for line in text.splitlines():
                m = RE_LABEL.match(line)
                if m:
                    cur = m.group(1)
                    body.setdefault(cur, [])
                    continue
                if cur:
                    for s in RE_DRAW.findall(line.split(";", 1)[0]):
                        body[cur].append(s)
            files[(port, stage)] = (p, body, dead, set(body))
    return files


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--proposals", action="store_true")
    ap.add_argument("--refusals", action="store_true")
    args = ap.parse_args()

    files = collect()

    spelling: dict[str, str] = {}
    if SPELLING.is_file():
        for line in SPELLING.read_text().splitlines():
            line = line.split("#", 1)[0].split()
            if len(line) == 2:
                spelling[line[0]] = line[1]

    skip = set()
    if SKIP.is_file():
        for line in SKIP.read_text().splitlines():
            line = line.split("#", 1)[0].split()
            if len(line) == 3:
                skip.add(tuple(line))

    # Rule 1's index: draw-set -> semantic names already carried anywhere.
    earned: dict[tuple, set] = collections.defaultdict(set)
    for (_po, _st), (_p, body, dead, _t) in files.items():
        for lab, art in body.items():
            if not art or lab in dead or classify(lab) != "semantic":
                continue
            earned[tuple(dict.fromkeys(art))].add(lab)

    proposals: dict[tuple, str] = {}
    why = collections.Counter()
    refused: list[str] = []
    reused = 0
    for (port, stage), (_p, body, dead, taken) in sorted(files.items()):
        cand = {}
        for lab, art in body.items():
            if not art or lab in dead or classify(lab) == "semantic":
                continue
            u = tuple(dict.fromkeys(art))
            if any(RE_NUMERIC.match(a) for a in u):
                why["draws art that is still a placeholder"] += 1
                continue
            cand[lab] = u
        shared = collections.Counter(cand.values())
        picked: dict[str, list] = collections.defaultdict(list)
        for lab, u in cand.items():
            if shared[u] > 1:
                why["draw-set shared with another unnamed routine (#0118)"] += 1
                refused.append(f"{port}/{stage} {lab}: shared draw-set")
                continue
            if (port, stage, lab) in skip:
                why["listed in the skip file, with a recorded reason"] += 1
                refused.append(f"{port}/{stage} {lab}: skip file")
                continue
            names = [n for n in sorted(earned.get(u, ()))
                     if not any(n.startswith(s + "_") and s != stage
                                for s in STAGES)]
            name = names[0] if len(names) == 1 else f"DRAW_{derive(u)}"
            name = spelling.get(name, name)
            picked[name].append(lab)
        for name, labs in picked.items():
            if len(labs) > 1:
                why["two candidates in one file derive one name"] += len(labs)
                refused.append(f"{port}/{stage} {', '.join(labs)}: all -> {name}")
                continue
            lab = labs[0]
            if name in taken:
                why["target name already used in this file"] += 1
                refused.append(f"{port}/{stage} {lab} -> {name}: taken")
                continue
            if len(name) < 12:
                why["derived stem too short to mean anything"] += 1
                continue
            proposals[(port, stage, lab)] = name
            if name in {n for s in earned.values() for n in s}:
                reused += 1

    print(f"{len(proposals)} routine(s) can be named from the art they draw "
          f"({reused} reuse a name already earned on the same draw-set "
          f"elsewhere, {len(proposals) - reused} derive a new one).\n")
    for k, v in why.most_common():
        print(f"  {v:5d}  refused: {k}")
    print(f"\n{len(set(proposals.values()))} distinct target name(s).")

    if args.proposals:
        print()
        for (port, stage, lab), name in sorted(proposals.items()):
            print(f"{port} {stage} {lab} {name}")
    if args.refusals:
        print()
        for r in refused[:40]:
            print(f"  {r}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
