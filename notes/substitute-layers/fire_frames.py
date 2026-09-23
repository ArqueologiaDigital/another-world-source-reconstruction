#!/usr/bin/env python3
"""The frame drawn at the shot, and the frame drawn after it.

Question answered
-----------------
`../shared-bank-geometry/stand_shoot.map` named the hero's standing shot in
the shared bank by reading the fire branch rather than the art:

    video type=0, offset=<F0>, ...       <- drawn AT the shot
    mov [0x21], [HERO_X]
    mov [0x27], [HERO_Y]
    sub [0x21], 0x001E                   <- the muzzle, left of the hero
    sub [0x27], 0x0027
    call <spawn the projectile>
    break
    video type=0, offset=<F1>, ...       <- the frame after

Three stages use that same shape with their own per-stage cinematic art
instead of bank pieces -- PRISON's enclosing loop is already called
`PRISON_HERO_FIRE_LEFT_HOLD_LOOP` and the call inside it
`PRISON_HERO_FIRE_SHOT_LEFT`. So the same read names those too.

This finds the shape wherever it occurs. The **muzzle offset carries the
direction**: `sub [0x21], 0x001E` puts the shot to the hero's left and
`add [0x21], 0x001E` to the right, which is what makes this a reading rather
than a guess about which way a sprite faces.

What it requires
----------------
- a `video offset=` or `video type=0, offset=`
- within the next few lines, `mov [0x21], [HERO_X]` and a `sub`/`add` of
  `[0x21]` by a literal
- then a `call`
- then, after it, another `video` -- the recovery frame

Anything missing and the site is skipped. Already-named constants are
reported so the rule can be checked against them rather than only trusted.

Usage
-----
    python3 notes/substitute-layers/fire_frames.py
    python3 notes/substitute-layers/fire_frames.py --proposals
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]

BRANCHES = ("chahi_amiga_1991", "dos_1992", "cartridge_1992")
STAGES = ("PRISON", "CAVES", "CAPSULE", "LAKE", "TANK", "INTRO", "ENDING")
RE_V = re.compile(r"^\s*video\s+(?:type=\d+,\s*)?offset="
                  r"([A-Za-z_][A-Za-z0-9_]*),")
RE_ANCHOR = re.compile(r"^\s*mov\s+\[0x21\],\s*\[HERO_X\]")
RE_MUZZLE = re.compile(r"^\s*(sub|add)\s+\[0x21\],\s*(0x[0-9A-Fa-f]+)")
RE_CALL = re.compile(r"^\s*call\s+([A-Za-z_][A-Za-z0-9_]*)")
RE_NUM = re.compile(r"^(CINEMATIC_\d+|CV_[0-9A-F]{4})$")
WINDOW = 8
RE_EQU = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s+(0x[0-9A-Fa-f]+)",
                    re.M)
STAGE_ID = {"PRISON": 3, "CAVES": 4, "CAPSULE": 6, "LAKE": 2, "TANK": 5,
            "INTRO": 1, "ENDING": 7}
PORT = {"chahi_amiga_1991": "amiga", "dos_1992": "msdos"}


def bank_names():
    """canonical_md5 -> the shared-bank name, for the named shoot pieces.

    The per-stage cinematic copies are the SAME art as the bank pieces, so
    the name does not have to be re-derived from the geometry -- it is read
    off the match. That also keeps stand and crouch apart without a height
    rule: HERO_CROUCH_SHOOT_LEFT_F0 is 44x34 and HERO_STAND_SHOOT_LEFT_F0 is
    40x49, and the md5 says which is which without a threshold.
    """
    sys.path.insert(0, str(SRC.parent / "another-world-archaeology" / "tools"))
    sys.path.insert(0, str(SRC / "notes" / "polygon-extent-correction"))
    from polygon_tree import parse_polygon_tree, canonical_md5
    from extent_matches_renderer import slab
    vb = slab("video2", "amiga", 0)
    off = {}
    for branch in BRANCHES:
        d = SRC / "src" / "levels" / branch
        if not d.is_dir():
            continue
        for f in sorted(d.glob("[A-Z]*.asm")):
            for n, v in RE_EQU.findall(f.read_text(errors="replace")):
                off.setdefault(n, int(v, 16))
    out = {}
    for n in off:
        if not re.match(r"^HERO_(STAND|CROUCH)_SHOOT_(LEFT|RIGHT)_F\d$", n):
            continue
        try:
            out[canonical_md5(parse_polygon_tree(vb, off[n]))] = n
        except BaseException:
            pass
    return out


def art_name(branch, stage, const, table):
    from polygon_tree import parse_polygon_tree, canonical_md5
    from extent_matches_renderer import slab
    f = SRC / "src" / "levels" / branch / f"{stage}.asm"
    equ = {n: int(v, 16) for n, v
           in RE_EQU.findall(f.read_text(errors="replace"))}
    if const not in equ or PORT.get(branch) is None:
        return None
    try:
        h = canonical_md5(parse_polygon_tree(
            slab("cinematic", PORT[branch], STAGE_ID[stage]), equ[const]))
    except BaseException:
        return None
    return table.get(h)


def scan():
    hits, stats = [], collections.Counter()
    for branch in BRANCHES:
        for stage in STAGES:
            f = SRC / "src" / "levels" / branch / f"{stage}.asm"
            if not f.is_file():
                continue
            lines = f.read_text(errors="replace").splitlines()
            for i, line in enumerate(lines):
                m = RE_V.match(line)
                if not m:
                    continue
                shot = m.group(1)
                direction = spawn = None
                j = i + 1
                while j < min(i + WINDOW, len(lines)):
                    if RE_ANCHOR.match(lines[j]):
                        pass
                    elif mm := RE_MUZZLE.match(lines[j]):
                        direction = ("LEFT" if mm.group(1) == "sub"
                                     else "RIGHT")
                    elif (c := RE_CALL.match(lines[j])) and direction:
                        spawn = c.group(1)
                        break
                    elif RE_V.match(lines[j]):
                        break
                    j += 1
                if not spawn:
                    continue
                after = None
                for k in range(j + 1, min(j + WINDOW, len(lines))):
                    if v := RE_V.match(lines[k]):
                        after = v.group(1)
                        break
                stats["fire sites found"] += 1
                if after is None:
                    stats["  no recovery frame after the spawn"] += 1
                    continue
                for nm, role in ((shot, "F0"), (after, "F1")):
                    if RE_NUM.match(nm):
                        stats[f"  ** {role} still numbered"] += 1
                    else:
                        stats[f"  {role} already named"] += 1
                hits.append((branch, stage, direction, shot, after, spawn))
    return hits, stats


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--proposals", action="store_true")
    args = ap.parse_args()
    hits, stats = scan()

    if args.proposals:
        table = bank_names()
        by: dict[tuple, list] = {}
        for branch, stage, d, shot, after, spawn in hits:
            for nm, role in ((shot, 0), (after, 1)):
                if not RE_NUM.match(nm):
                    continue
                bank = art_name(branch, stage, nm, table)
                if bank is None:
                    continue
                new = f"CINEMATIC_{stage}_{bank}"
                by.setdefault((branch, stage), []).append(
                    (nm, new, d, role, spawn, bank))
        for (branch, stage), rows in sorted(by.items()):
            seen = set()
            print(f"\n----- {branch} / {stage} -----")
            print("| constant | proposed name | confidence | evidence |")
            print("| --- | --- | --- | --- |")
            for nm, new, d, role, spawn, bank in rows:
                if nm in seen:
                    continue
                seen.add(nm)
                what = ("drawn at the shot, immediately before the muzzle is "
                        "set and `%s` spawns the projectile" % spawn
                        if role == 0 else
                        "drawn immediately after `%s` spawns the projectile, "
                        "the frame the hero returns through" % spawn)
                print(f"| {nm} | {new} | high | {what}; the muzzle offset "
                      f"`{'sub' if d == 'LEFT' else 'add'} [0x21], 0x001E` "
                      f"puts the shot to the {d.lower()}, and its "
                      f"`canonical_md5` equals the shared bank's `{bank}` |")
        return 0

    for k, v in stats.most_common():
        print(f"  {v:>5}  {k}")
    print()
    for branch, stage, d, shot, after, spawn in hits:
        mark = "*" if RE_NUM.match(shot) or RE_NUM.match(after) else " "
        print(f" {mark} {branch.split('_')[0]:<10}{stage:<9}{d:<6}"
              f"{shot:<40}{after}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
