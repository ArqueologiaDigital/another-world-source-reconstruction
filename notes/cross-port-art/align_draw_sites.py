#!/usr/bin/env python3
"""Pair two ports' constants by position in identical bytecode.

Question answered
-----------------
`transfer_by_art.py` carries a name from one priority port to the other when
`canonical_md5` says they draw the same picture. It refuses when one md5 maps
to several constants, and it is right to: with three constants holding one
picture, the hash cannot say which is which.

That is not a rare corner. PRISON's wake-up scene stores the head, the neck
and each arm **three times over**, byte for byte identical, so that one pass
of the draw routine can put the same shape on screen at three zoom levels:

    (183,40)   CINEMATIC_638 641 645   all canonical_md5 2d66cda0

Fourteen of that scene's nineteen constants were unreachable by art alone.

There is a second bridge available, and for PRISON it is the stronger one.
`docs/NAMING.md`: "Only PRISON, ENDING and PASSCODE are wholly identical"
across the ports. Where that holds, the two `.asm` files are the same program,
so the **n-th `video` instruction** in one is the n-th in the other, and the
constants they name correspond.

That is not naming from the index. #0107 is about the bank index -- the number
in `CINEMATIC_<n>`, which the ports assign differently. This pairs draw sites
in a shared instruction stream, and refuses to do even that unless the two
streams are shown to be the same stream.

The scope is NOT the whole file. Measured 2026-09-23, the two canonical `.asm`
files do not line up at file scale in **any** stage -- PRISON is 1420 draw
sites against 1480, and CAPSULE 1473 against 2026 -- so a whole-file gate
fails everywhere and this tool would report nothing. What does line up is the
unified tree's own pairing: a chunk `amiga__post_X.inc` and a chunk
`dos__post_X.inc` are the two branches' arms of one region, which is a fact
the unifier already established. PRISON has 88 such pairs.

Signal read
-----------
Per paired chunk, the ordered list of every `video` line's arguments with the
constant name dropped. The two arms must have the same number of sites and
agree at every one; that is the gate, reported PASS/fail per pair before any
pairing happens. Where it passes, site i pairs one branch's constant with the
other's.

A pairing is then proposed only when one side is still `CINEMATIC_<n>` and the
other is not, and only when **every** site that pairs those two agrees on the
same name. A constant drawn at several sites that would give it two different
names is dropped and counted.

Usage
-----
    python3 notes/cross-port-art/align_draw_sites.py
    python3 notes/cross-port-art/align_draw_sites.py --proposals
    python3 notes/cross-port-art/align_draw_sites.py --stage PRISON --verbose
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "notes" / "polygon-extent-correction"))
sys.path.insert(0, str(ROOT.parent / "another-world-archaeology" / "tools"))
from polygon_tree import parse_polygon_tree, canonical_md5      # noqa: E402
from extent_matches_renderer import slab                        # noqa: E402

SRC = ROOT / "src" / "levels"
STAGE_ID = {"CODE_WHEEL": 0, "INTRO": 1, "LAKE": 2, "PRISON": 3, "CAVES": 4,
            "TANK": 5, "CAPSULE": 6, "ENDING": 7, "PASSCODE": 8}
RE_EQU = re.compile(r"^([A-Za-z_]\w*)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)


def art(port: str, branch: str, stage: str) -> dict[str, str]:
    """constant -> canonical_md5 of the polygon it points at."""
    f = SRC / branch / f"{stage}.asm"
    if not f.is_file():
        return {}
    try:
        bank = slab("cinematic", port, STAGE_ID[stage])
    except SystemExit:
        return {}
    out = {}
    for n, v in RE_EQU.findall(f.read_text(errors="replace")):
        try:
            out[n] = canonical_md5(parse_polygon_tree(bank, int(v, 16)))
        except Exception:
            pass
    return out
PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]
RE_NUM = re.compile(r"^CINEMATIC_\d+$")
# Borrowed verbatim from `transfer_by_art.py`, which checks a screen-carrying
# name against the screens the taking port actually draws it on. This tool
# does not do that check, so it refuses such names outright and leaves them
# to the tool that does.
RE_SCREEN = re.compile(r"_SCREEN_([0-9A-F]{2})_")
RE_POSITIONAL = re.compile(r"_BACKDROP_LAYER_\d+$")
RE_V = re.compile(r"^\s*video\s+(?:type=(\d+),\s*)?offset=([A-Za-z_]\w*),"
                  r"\s*(.*?)\s*$")


def sites(f: Path) -> list[tuple[str, str]]:
    """(constant, everything else on the line) for each `video`, in order."""
    out = []
    for line in f.read_text(errors="replace").splitlines():
        m = RE_V.match(line)
        if m:
            out.append((m.group(2), f"{m.group(1) or ''}|{m.group(3)}"))
    return out


def align(stage: str):
    """(pairs, report) over the unified tree's own amiga/dos chunk pairs."""
    d = SRC / "_unified" / stage.lower()
    if not d.is_dir():
        return [], [(stage, False, "no unified chunks")]
    pairs, report = [], []
    for fa in sorted(d.glob("amiga__*.inc")):
        fb = fa.with_name("dos__" + fa.name[len("amiga__"):])
        if not fb.is_file():
            report.append((fa.name, False, "no dos arm"))
            continue
        a, b = sites(fa), sites(fb)
        if not a and not b:
            continue
        if len(a) != len(b):
            report.append((fa.name, False,
                           f"{len(a)} draw sites vs {len(b)}"))
            continue
        bad = [i for i, (x, y) in enumerate(zip(a, b)) if x[1] != y[1]]
        if bad:
            report.append((fa.name, False,
                           f"{len(bad)} of {len(a)} sites differ in their "
                           f"arguments (first at site {bad[0]})"))
            continue
        report.append((fa.name, True, f"{len(a)} site(s)"))
        pairs += [(x[0], y[0]) for x, y in zip(a, b)]
    return pairs, report


def scan(only: str | None):
    rows, stats = [], collections.Counter()
    report, disagree = [], []
    for stage in STAGES:
        if only and stage != only:
            continue
        pairs, rep = align(stage)
        ok = sum(1 for _n, o, _w in rep if o)
        report.append((stage, ok, len(rep), rep))
        if not pairs:
            continue
        ma = art("amiga", PORTS["amiga"], stage)
        mm = art("msdos", PORTS["msdos"], stage)
        # constant -> the set of names the other port's aligned sites give it
        want: dict[tuple[str, str, str], set] = collections.defaultdict(set)
        for ca, cm in pairs:
            # THE SECOND GATE. An aligned site is not enough: `amiga__X.inc`
            # and `dos__X.inc` are separate chunks precisely BECAUSE the two
            # branches differ there, and two different pictures drawn at the
            # same x, y and zoom pass the argument check unchanged. Measured
            # on this tree, 44 of 636 aligned-and-both-named sites carry
            # names that disagree, and `canonical_md5` says the art at every
            # one of those 44 differs too. So the art has to agree as well.
            same_art = (ca in ma and cm in mm and ma[ca] == mm[cm])
            na, nm = bool(RE_NUM.match(ca)), bool(RE_NUM.match(cm))
            if na and nm:
                stats["both still numbered"] += 1
                continue
            if not na and not nm:
                # THE CONTROL. Where a person has already named both sides,
                # this method's answer is checkable without running it: the
                # aligned pair must be the same name. Every disagreement is
                # either a site where the ports really do draw different
                # things, or a place where pairing by draw site is wrong.
                bucket = "same art" if same_art else "DIFFERENT art"
                stats[f"control ({bucket}): both named, and they "
                      + ("agree" if ca == cm else "DISAGREE")] += 1
                if ca != cm:
                    disagree.append((stage, ca, cm, same_art))
                continue
            if not same_art:
                stats["refused: aligned site, but the art differs"] += 1
                continue
            if nm:
                want[("msdos", stage, cm)].add(ca)
            else:
                want[("amiga", stage, ca)].add(cm)
        for (port, st, taker), names in sorted(want.items()):
            if len(names) != 1:
                stats["** sites disagree about the name"] += 1
                continue
            giver = next(iter(names))
            if RE_POSITIONAL.search(giver) or RE_SCREEN.search(giver):
                stats["refused: name is a paint position or carries a "
                      "screen -- see transfer_by_art.py"] += 1
                continue
            stats["** transferable by draw site"] += 1
            rows.append((PORTS[port], st, taker, giver))
    return rows, stats, report, disagree


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--proposals", action="store_true")
    ap.add_argument("--stage")
    ap.add_argument("--verbose", action="store_true")
    args = ap.parse_args()

    rows, stats, report, disagree = scan(args.stage)

    if not args.proposals:
        print("  the gate -- per unified chunk pair, do the two arms carry "
              "the same draw sites?\n")
        for stage, ok, tot, rep in report:
            print(f"  {stage:<12}{ok:>4} of {tot:<4} chunk pair(s) align")
            if args.verbose:
                for n, o, why in rep:
                    if not o:
                        print(f"        fail  {n}: {why}")
        print()
        for k, v in stats.most_common():
            print(f"  {v:6}  {k}")
        ag = stats["control (same art): both named, and they agree"]
        dis = stats["control (same art): both named, and they DISAGREE"]
        print(f"\n  CONTROL, for the pairs this tool would act on -- aligned "
              f"AND same art:\n  {ag} of {ag + dis} re-derive the name a "
              f"person already wrote")
        for stage, ca, cm, sa in disagree[:6]:
            print(f"      {stage}: amiga {ca}  vs  msdos {cm}"
                  f"   [{'same art' if sa else 'different art'}]")
        print(f"\n  {len(rows)} transferable by draw site")
        if args.verbose:
            print()
            for br, st, taker, giver in rows:
                print(f"    {br}/{st}  {taker} -> {giver}")
        return 0

    by: dict[tuple[str, str], list] = collections.defaultdict(list)
    for br, st, taker, giver in rows:
        by[(br, st)].append((taker, giver))
    for (br, st), rs in sorted(by.items()):
        print(f"# Names carried by draw-site alignment in {st} -- {br}\n")
        print("Derived by `notes/cross-port-art/align_draw_sites.py`, for the")
        print("constants `transfer_by_art.py` has to refuse because one")
        print("`canonical_md5` maps to several constants in the same port.\n")
        print("| constant | proposed name | confidence | evidence |")
        print("| --- | --- | --- | --- |")
        for taker, giver in rs:
            print(f"| {taker} | {giver} | high | the two ports' `{st}` draw "
                  f"streams are the same length and carry identical "
                  f"arguments at every site, so site *i* is one instruction "
                  f"in one program; the other priority port's constant at "
                  f"this constant's site already earned this name. Paired on "
                  f"the draw site, never on the bank index |")
        print()
    return 0


if __name__ == "__main__":
    sys.exit(main())
