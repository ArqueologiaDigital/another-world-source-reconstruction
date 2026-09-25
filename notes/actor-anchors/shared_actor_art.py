#!/usr/bin/env python3
"""Two characters stand in one anchor slot. Do they share any art?

Question answered
-----------------
`anchor_identity.py` beside this asks whether an anchor's name agrees with the
names drawn at it. This asks the question that comes next, and it comes up
whenever a stage has two characters of one kind: when the same anchor draws
character A in one scene and character B in another, **is it the same art?**

The answer decides what kind of problem you have.

  * Shared art means one figure reused, and an actor word in its name is simply
    wrong -- the asset belongs to neither character in particular.
  * No shared art means two characters with two sets of pictures and a shared
    slot. The names can carry an actor word, but only one taken from the SCENE,
    because the anchor does not say which and -- when the two are the same
    species -- neither does looking at them.

That second case is PRISON's, and it was measured with this after the owner
pointed out that Buddy and the guards are aliens of one species: they resemble
each other on screen and share nothing in the bank.

Signal read
-----------
  * every `video offset=NAME, x=[<AX>], y=[<AY>]` line in the branch's `.asm`,
    with its line number, so a scene can be given as a line range;
  * `canonical_md5` of each constant's parsed polygon tree, which is the
    project's legitimate way to say two pictures are the same one;
  * optionally the shared bank, where a constant drawn at two different anchors
    is a figure serving two actors.

Ranges are line numbers on purpose. A scene boundary in this repository is
found by reading the listing, not by a marker in it, so the caller states what
they found and this measures it.

Run it
    python3 notes/actor-anchors/shared_actor_art.py \
        --branch dos_1992 --stage PRISON --anchor ACTOR \
        --scene guard:8800-10100 --scene buddy:3600-3800
    ... --cross-anchor HERO,BUDDY   # constants drawn at BOTH anchors
    ... --romset <dir>              # default: msdos, for canonical_md5
"""
from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ARCH = ROOT.parent / "another-world-archaeology"
sys.path.insert(0, str(ARCH / "tools"))

STAGE_ID = {"CODE_WHEEL": 0, "INTRO": 1, "LAKE": 2, "PRISON": 3, "CAVES": 4,
            "TANK": 5, "CAPSULE": 6, "ENDING": 7, "PASSCODE": 8}
RE_EQU = re.compile(r"^(\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)\s*$", re.M)


def draws(text: str, ax: str, ay: str):
    """[(line, constant)] for every draw at exactly this anchor pair."""
    pat = re.compile(
        rf"^\tvideo (?:type=\d+, )?offset=(\w+), x=\[{ax}\], y=\[{ay}\]")
    out = []
    for i, ln in enumerate(text.splitlines(), 1):
        m = pat.match(ln)
        if m:
            out.append((i, m.group(1)))
    return out


def any_anchor(text: str):
    """{constant: {anchor variable used for x}} over every draw in the file."""
    pat = re.compile(r"^\tvideo (?:type=\d+, )?offset=(\w+), x=\[(\w+)\]")
    out = collections.defaultdict(set)
    for ln in text.splitlines():
        m = pat.match(ln)
        if m:
            out[m.group(1)].add(m.group(2))
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--branch", required=True)
    ap.add_argument("--stage", required=True)
    ap.add_argument("--anchor", default="ACTOR",
                    help="the variable stem: ACTOR means ACTOR_X/ACTOR_Y")
    ap.add_argument("--scene", action="append", default=[],
                    metavar="NAME:FIRST-LAST",
                    help="a scene, as a line range in the .asm")
    ap.add_argument("--cross-anchor", metavar="A,B",
                    help="also report constants drawn at both anchors")
    ap.add_argument("--romset", default=None)
    a = ap.parse_args()

    asm = ROOT / "src" / "levels" / a.branch / f"{a.stage}.asm"
    if not asm.is_file():
        print(f"no {asm}", file=sys.stderr)
        return 2
    text = asm.read_text(errors="replace")
    ax, ay = f"{a.anchor}_X", f"{a.anchor}_Y"
    d = draws(text, ax, ay)
    print(f"{a.branch}/{a.stage}, anchored [{ax}],[{ay}]: "
          f"{len(d)} draw(s), {len({n for _, n in d})} distinct constant(s)")

    scenes = {}
    for spec in a.scene:
        name, _, rng = spec.partition(":")
        lo, _, hi = rng.partition("-")
        scenes[name] = range(int(lo), int(hi))
    if len(scenes) < 2:
        print("\n  give at least two --scene NAME:FIRST-LAST to compare")
        return 0

    members = {k: sorted({n for i, n in d if i in r}) for k, r in scenes.items()}
    for k, ns in members.items():
        print(f"  scene {k:<10} {len(ns)} constant(s)")
    keys = list(members)
    overlap = set(members[keys[0]])
    for k in keys[1:]:
        overlap &= set(members[k])
    print(f"\n  drawn in EVERY scene: {len(overlap)}"
          + (f"  {sorted(overlap)[:10]}" if overlap else ""))

    # the art question
    try:
        from polygon_tree import parse_polygon_tree, canonical_md5
    except ImportError:
        print("  (no polygon_tree on the path -- art comparison skipped)")
        return 0
    romset = Path(a.romset) if a.romset else (
        ARCH / "tmp" / "output" / "msdos" / "romset")
    rom = romset / "cinematic.rom"
    if not rom.is_file():
        print(f"  (no {rom} -- art comparison skipped)")
        return 0
    lvl = STAGE_ID[a.stage]
    slab = rom.read_bytes()[lvl * 0x10000:(lvl + 1) * 0x10000]
    equ = dict(RE_EQU.findall(text))

    def h(n):
        if n not in equ:
            return None
        try:
            return canonical_md5(parse_polygon_tree(slab, int(equ[n], 16)))
        except Exception:
            return None

    hashes = {k: {n: h(n) for n in ns} for k, ns in members.items()}
    first = keys[0]
    inv = collections.defaultdict(list)
    for n, x in hashes[first].items():
        if x:
            inv[x].append(n)
    total = 0
    for k in keys[1:]:
        same = [(n, inv[x]) for n, x in hashes[k].items() if x and x in inv]
        # A constant drawn in both scenes matches ITSELF, which is not art
        # shared between two subjects -- it is one asset appearing twice. Only a
        # match to a DIFFERENT constant says two subjects were drawn from one
        # picture, so the two cases are counted apart.
        selfm = [(n, o) for n, o in same if o == [n]]
        cross = [(n, o) for n, o in same if o != [n]]
        total += len(cross)
        print(f"  scene {k} constants whose ART matches a DIFFERENT one in "
              f"{first}: {len(cross)}")
        for n, others in cross:
            print(f"      {n} == {', '.join(others)}")
        if selfm:
            print(f"      (plus {len(selfm)} constant(s) drawn in both scenes: "
                  f"{', '.join(n for n, _ in selfm[:4])}"
                  f"{' ...' if len(selfm) > 4 else ''})")
    if total == 0:
        print("\n  No shared art. Two characters, two sets of pictures, one\n"
              "  anchor -- so an actor word is admissible, but only from the\n"
              "  scene. The anchor does not say which, and if the two are the\n"
              "  same species neither does looking at them.")
    else:
        print("\n  Shared art. The asset belongs to neither character in\n"
              "  particular, and an actor word in its name is wrong.")

    if a.cross_anchor:
        p, q = a.cross_anchor.split(",")
        anch = any_anchor(text)
        both = sorted(n for n, s in anch.items()
                      if {f"{p}_X", f"{q}_X"} <= s)
        print(f"\n  constants drawn at BOTH {p}_X and {q}_X: {len(both)}")
        for n in both[:20]:
            print(f"      {n}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
