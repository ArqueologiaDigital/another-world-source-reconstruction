#!/usr/bin/env python3
"""A stage's own copy of a picture the shared bank already names.

Question answered
-----------------
`../substitute-layers/fire_frames.py` found that PRISON and CAPSULE draw the
hero's shot from their **own cinematic banks**, with art byte-identical to
the shared-bank pieces named in `../shared-bank-geometry/`. The name did not
have to be re-derived; it was read off the `canonical_md5` match.

That is a general axis, and one this project had not swept. Cross-port
(`transfer_by_art.py`) and cross-stage matching were both tried; **cinematic
against shared bank** was not.

Measured over both priority ports: of the still-numbered cinematic constants
that are actually drawn, **95 are byte-identical to exactly one named
shared-bank picture**, most of them in PRISON.

Why the name transfers
----------------------
The bank names describe a *pose* -- `HERO_CROUCH_DOWN_LEFT`,
`CV_FIGURE_GUN_UPPER_RIGHT_POSE_00`. A byte-identical picture is that pose,
whatever the stage does with it, so the subject carries over even though the
scene does not. The stage prefix keeps the two apart:
`CINEMATIC_PRISON_HERO_CROUCH_DOWN_LEFT` is PRISON's copy, and the bare
`HERO_CROUCH_DOWN_LEFT` is the bank's.

What it refuses
---------------
A constant drawn from a **unified chunk every branch reads** is not
transferred at all. Renaming its EQU in two branches leaves their copies of
that shared draw line pointing at the old name, so the symbol goes undefined
for exactly those two — which is what happened to PRISON's `CINEMATIC_555`
here, taking verify-unified to 27/29 before it was put back. Such a constant
needs a rename in every branch at once, and that needs cartridge's art, which
needs a ROM it does not have.

A bank name ending in `_CASE_<n>` is not transferred. That index is the value
of the *dispatch that selects it in the bank*, not a property of the picture,
so it means nothing in a stage that reaches the same art another way -- the
same reason `transfer_by_art.py` refuses `_BACKDROP_LAYER_<i>`. A picture
matching more than one bank name is skipped too: identical art under two
names is a question for #0120, not an opportunity.

Pass/fail
---------
Exits 0. `--proposals` emits one table per (branch, stage).

Usage
-----
    python3 notes/cross-port-art/bank_copy_in_stage.py
    python3 notes/cross-port-art/bank_copy_in_stage.py --proposals
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
sys.path.insert(0, str(SRC / "notes" / "polygon-extent-correction"))
from polygon_tree import parse_polygon_tree, canonical_md5   # noqa: E402
from extent_matches_renderer import slab                     # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGE_ID = {"CODE_WHEEL": 0, "INTRO": 1, "LAKE": 2, "PRISON": 3, "CAVES": 4,
            "TANK": 5, "CAPSULE": 6, "ENDING": 7, "PASSCODE": 8}
RE_EQU = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s+(0x[0-9A-Fa-f]+)",
                    re.M)
RE_NUM = re.compile(r"^CINEMATIC_\d+$")
RE_CVHEX = re.compile(r"^CV_[0-9A-F]{4}$")
RE_SUBJECT = re.compile(r"^(HERO|CV_FIGURE|BUDDY|BEAST)_")
RE_CASE = re.compile(r"_CASE_[0-9A-F]+$")
# A unified chunk whose filename has no `<port>__` prefix is emitted for
# EVERY branch. A constant referenced from one cannot be renamed
# branch-scoped: rename the EQU in two branches and their copies of the
# shared draw line still say the old name, so the symbol goes undefined for
# exactly those two. PRISON's CINEMATIC_555 is drawn from
# prison/prison_step_draws_and_breaks.inc, which PRISON.asm.in includes
# unconditionally; naming it in amiga and msdos took verify-unified to 27/29
# and it had to be put back. Renaming it needs every branch at once, which
# needs cartridge's art, which needs a ROM it does not have.
RE_PORT_CHUNK = re.compile(r"^(amiga|dos|cart|gba)__")


def shared_chunk_constants(stage: str) -> set:
    d = SRC / "src" / "levels" / "_unified" / stage.lower()
    out: set = set()
    if not d.is_dir():
        return out
    for f in d.rglob("*.inc"):
        if RE_PORT_CHUNK.match(f.name):
            continue
        for m in re.finditer(r"offset=(CINEMATIC_\d+)\b",
                             f.read_text(errors="replace")):
            out.add(m.group(1))
    return out


def bank_table():
    """canonical_md5 -> [named shared-bank pictures]."""
    vb = slab("video2", "amiga", 0)
    off: dict[str, int] = {}
    for branch in PORTS.values():
        for f in sorted((SRC / "src" / "levels" / branch).glob("[A-Z]*.asm")):
            for n, v in RE_EQU.findall(f.read_text(errors="replace")):
                off.setdefault(n, int(v, 16))
    out: dict[str, list] = collections.defaultdict(list)
    for n, v in off.items():
        if n.startswith("CINEMATIC_") or RE_CVHEX.match(n):
            continue
        if not RE_SUBJECT.match(n):
            continue
        try:
            out[canonical_md5(parse_polygon_tree(vb, v))].append(n)
        except BaseException:
            pass
    return out


def scan():
    bank = bank_table()
    rows, stats = [], collections.Counter()
    stats["named shared-bank pictures"] = len(bank)
    for port, branch in PORTS.items():
        for stage, sid in STAGE_ID.items():
            f = SRC / "src" / "levels" / branch / f"{stage}.asm"
            if not f.is_file():
                continue
            text = f.read_text(errors="replace")
            equ = {n: int(v, 16) for n, v in RE_EQU.findall(text)}
            b = slab("cinematic", port, sid)
            shared = shared_chunk_constants(stage)
            for n, v in equ.items():
                if not RE_NUM.match(n) or f"offset={n}," not in text:
                    continue
                if n in shared:
                    stats["drawn from a chunk every branch reads"] += 1
                    continue
                try:
                    h = canonical_md5(parse_polygon_tree(b, v))
                except BaseException:
                    continue
                names = bank.get(h)
                if not names:
                    stats["no bank match"] += 1
                    continue
                if len(set(names)) > 1:
                    stats["matches several bank names (#0120)"] += 1
                    continue
                subject = names[0]
                if RE_CASE.search(subject):
                    stats["bank name ends in a dispatch case index"] += 1
                    continue
                new = f"CINEMATIC_{stage}_{subject}"
                if new in equ:
                    stats["derived name already in the stage"] += 1
                    continue
                stats["** transferable"] += 1
                rows.append((branch, stage, n, new, subject))
    return rows, stats


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--proposals", action="store_true")
    args = ap.parse_args()
    rows, stats = scan()

    if args.proposals:
        by: dict[tuple, list] = {}
        for branch, stage, old, new, subject in rows:
            by.setdefault((branch, stage), []).append((old, new, subject))
        for (branch, stage), rs in sorted(by.items()):
            print(f"\n----- {branch} / {stage} -----")
            print("| constant | proposed name | confidence | evidence |")
            print("| --- | --- | --- | --- |")
            for old, new, subject in sorted(rs):
                print(f"| {old} | {new} | high | its `canonical_md5` equals "
                      f"the shared bank's `{subject}`, which names a pose "
                      f"rather than a scene, so the subject carries into "
                      f"this stage's own copy |")
        return 0

    for k, v in stats.most_common():
        print(f"  {v:>5}  {k}")
    by = collections.Counter(f"{b.split('_')[0]}/{s}" for b, s, *_ in rows)
    print()
    for k, v in by.most_common():
        print(f"    {v:>4}  {k}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
