#!/usr/bin/env python3
"""A name earned in one port belongs on the other port's copy of that picture.

Question answered
-----------------
The two priority ports draw much of the same art at different constant
indices. When a picture is named in one and still numbered in the other, the
name transfers -- but the bridge has to be the **art**, never the index.
`#0107` is that hazard: msdos' `CINEMATIC_422` in CAPSULE is 100x19 while
amiga's is 299x234, and `notes/scene-reading/` found the real msdos twin of
amiga's arched wall four constants away, at 478/479.

So: build `canonical_md5` -> constant for each (port, stage), and where one
side has a semantic name and the other a bare index, propose the transfer.

The guard that makes it safe
----------------------------
A name that carries a screen number cannot be transferred on art alone,
because the same picture can sit on a different screen in the other port.
That is not hypothetical: `notes/screen-scope/` found amiga installing
`CAVES_SCREEN_ED_EVENT_PALETTE_FLASH_FRAME` on the fallthrough of
`jne [SCREEN_NUM], 0xED` while msdos and cartridge use **0xEE**, msdos having
three CAVES screens amiga does not. So a name matching `_SCREEN_<NN>_` is only
transferred when the receiving port draws the picture on that same screen,
checked through `../screen-scope/`; otherwise it is reported and held.

A `_BACKDROP_LAYER_<i>` name is never transferred at all: that index is the
position in the *receiving* port's own paint sequence and has to be earned
there. amiga's `CAVES_SCREEN_ED_BACKDROP_LAYER_5` and `_6` are msdos'
`CAVES_SCREEN_EE_BACKDROP_LAYER_4` and `_5` -- a different screen *and* a
different position, because msdos has a screen amiga does not.

A picture whose md5 appears more than once in either port is skipped too --
two constants holding one picture make the correspondence ambiguous, and
choosing between them is not this module's call (#0120).

Pass/fail
---------
Exits 0. `--proposals` emits one table per (branch, stage).

Usage
-----
    python3 notes/cross-port-art/transfer_by_art.py
    python3 notes/cross-port-art/transfer_by_art.py --proposals
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
sys.path.insert(0, str(SRC / "notes" / "screen-scope"))

from polygon_tree import parse_polygon_tree, canonical_md5   # noqa: E402
from extent_matches_renderer import slab                     # noqa: E402
import screen_scope as S                                     # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGE_ID = {"CODE_WHEEL": 0, "INTRO": 1, "LAKE": 2, "PRISON": 3, "CAVES": 4,
            "TANK": 5, "CAPSULE": 6, "ENDING": 7, "PASSCODE": 8}
RE_EQU = re.compile(r"^(CINEMATIC_[A-Za-z0-9_]+)\s+EQU\s+(0x[0-9A-Fa-f]+)",
                    re.M)
RE_NUM = re.compile(r"^CINEMATIC_\d+$")
RE_SCREEN = re.compile(r"_SCREEN_([0-9A-F]{2})_")
# A `_BACKDROP_LAYER_<i>` index is the position in THAT PORT'S OWN paint
# sequence, computed by ../screen-scope/backdrop_phase.py from that port's
# entry routine. It is not a property of the picture, so it cannot ride along
# with the art. msdos proves it: amiga's CAVES_SCREEN_ED_BACKDROP_LAYER_5 and
# _6 correspond to msdos' CAVES_SCREEN_EE_BACKDROP_LAYER_4 and _5 -- a
# different screen AND a different position, because msdos has a screen amiga
# does not. Such a name must be earned from the receiving port's own phase.
RE_POSITIONAL = re.compile(r"_BACKDROP_LAYER_\d+$")
RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
RE_V = re.compile(r"^\s*video\s+(?:type=\d+,\s*)?offset="
                  r"([A-Za-z_][A-Za-z0-9_]*)")


def art_table(port: str, branch: str, stage: str):
    """canonical_md5 -> [constants drawn in this file]."""
    f = SRC / "src" / "levels" / branch / f"{stage}.asm"
    if not f.is_file():
        return None
    text = f.read_text(errors="replace")
    bank = slab("cinematic", port, STAGE_ID[stage])
    out: dict[str, list[str]] = {}
    for name, val in RE_EQU.findall(text):
        if f"offset={name}," not in text:
            continue
        try:
            h = canonical_md5(parse_polygon_tree(bank, int(val, 16)))
        except BaseException:
            continue
        out.setdefault(h, []).append(name)
    return out


def screens_drawing(port: str, stage: str) -> dict[str, set]:
    """constant -> the screens whose entry can reach a draw of it."""
    lines = S.load(port, stage)
    if lines is None:
        return {}
    scoped, _at = S.analyse(lines)
    out: dict[str, set] = collections.defaultdict(set)
    cur = None
    for line in lines:
        if m := RE_LBL.match(line):
            cur = m.group(1)
        elif cur and (v := RE_V.match(line)):
            ctx = scoped.get(cur)
            if ctx is not None:
                out[v.group(1)] |= set(ctx)
    return out


def scan():
    rows, held, stats = [], [], collections.Counter()
    for stage in STAGE_ID:
        ta = art_table("amiga", PORTS["amiga"], stage)
        tm = art_table("msdos", PORTS["msdos"], stage)
        if not ta or not tm:
            continue
        screens = {}
        for h in set(ta) & set(tm):
            A, M = ta[h], tm[h]
            if len(A) != 1 or len(M) != 1:
                stats["one md5, several constants -- ambiguous"] += 1
                continue
            a, m = A[0], M[0]
            na, nm = bool(RE_NUM.match(a)), bool(RE_NUM.match(m))
            if na and nm:
                stats["both still numbered"] += 1
                continue
            if not na and not nm:
                stats["both already named"] += 1
                continue
            giver, taker = (a, m) if nm else (m, a)
            tport = "msdos" if nm else "amiga"
            gport = "amiga" if nm else "msdos"
            if RE_POSITIONAL.search(giver):
                stats["name is a paint position, not a property of the "
                      "art"] += 1
                continue
            sm = RE_SCREEN.search(giver)
            if sm:
                for p in (gport, tport):
                    if (p, stage) not in screens:
                        screens[(p, stage)] = screens_drawing(p, stage)
                want = int(sm.group(1), 16)
                got = screens[(tport, stage)].get(taker, set())
                if got != {want}:
                    stats["** name carries a screen the other port does "
                          "not draw it on"] += 1
                    held.append((PORTS[tport], stage, taker, giver,
                                 f"0x{want:02X}",
                                 sorted(f"0x{v:02X}" for v in got) or ["any"]))
                    continue
                stats["name carries a screen, and it matches"] += 1
            stats["** transferable"] += 1
            rows.append((PORTS[tport], stage, taker, giver))
    return rows, held, stats


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--proposals", action="store_true")
    args = ap.parse_args()
    rows, held, stats = scan()

    if args.proposals:
        by: dict[tuple, list] = {}
        for branch, stage, taker, giver in rows:
            by.setdefault((branch, stage), []).append((taker, giver))
        for (branch, stage), rs in sorted(by.items()):
            print(f"\n----- {branch} / {stage} -----")
            print("| constant | proposed name | confidence | evidence |")
            print("| --- | --- | --- | --- |")
            for taker, giver in rs:
                print(f"| {taker} | {giver} | high | the other priority port "
                      f"draws a picture with the same `canonical_md5` in this "
                      f"same stage and has already earned this name for it; "
                      f"matched on the art, never on the index |")
        return 0

    for k, v in stats.most_common():
        print(f"  {v:>5}  {k}")
    if held:
        print(f"\n{len(held)} held -- the name names a screen the receiving "
              f"port does not draw the picture on:")
        for branch, stage, taker, giver, want, got in held:
            print(f"  {branch.split('_')[0]:<6}{stage:<9}{taker:<16}"
                  f"{giver:<46}wants {want}, drawn on {got}")
    print(f"\n{len(rows)} transferable")
    return 0


if __name__ == "__main__":
    sys.exit(main())
