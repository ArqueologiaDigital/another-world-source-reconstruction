#!/usr/bin/env python3
"""Find the still-numbered pictures a routine plays as a straight-line run.

Question answered
-----------------
`sheet.py` lists what is left to name, biggest first, and that is the wrong
order to work in. A 438x248 screen backdrop drawn six times across two screens
is one of the hardest things in the stage to name honestly; a run of eight
pictures drawn one per `break` at one anchor is one of the easiest, because
the routine states the frame order itself and the extents then have a motion
to agree or disagree with.

This finds the second kind. Every PRISON batch of 2026-09-23 that produced
`high` confidence names came from a run this reports -- the cage landing
(5), the falling debris (8), the blast (9), the cloaked figure (19), the
lifting bar (6) -- and they were found by reading the file by hand.

What counts as a run
--------------------
Consecutive `video offset=<constant>, x=<expr>, y=<expr>` lines that

* share the **same anchor expression**, literal or variable, and
* are separated by nothing but `break`, `play`, `setPalette`,
  `selectVideoPage`, `jne [0x10], [SCREEN_NUM], ...` and the like -- never by
  a label, a `call`, a `jmp` or a `ret`, any of which can bring control from
  somewhere else and break the claim that the order on the page is the order
  on the screen,

and a run is only reported when at least `--min` of its members are still
spelled `CINEMATIC_<index>`. A picture drawn twice in one run counts once;
repeats are how these animations play back and forth.

Control
-------
`--control` asks the inverse question: of the runs whose members are **all**
named already, how many did a person treat as ONE family?

Measured on PRISON 2026-09-23, after a day of naming its runs by hand:
**11 of 19**. That is the number this probe has to be read against, and it is
the reason the output above says "work queue" and not "family".

The eight that split are not mistakes. `FILL_AND_DRAW_CIN_24_28` is a run of
five pictures that is a screen **composition** -- a pillar, a grating, a
highlight pass, a shadow pass, a corner -- and a person correctly gave it five
names. `GUN_PICKUP_SCENE` is a backdrop, a gun and an indicator.
`DRAW_CIN_137_138_BLOCK` is a debris animation and the deposits it leaves, and
they were split on which video page each draw goes to.

The anchor does not separate the two cases either, which is worth knowing
before trusting it: the body-and-limb splits
(`..._BUDDY_FIGURE_BASE` with `..._BUDDY_TYPING_ARM`, `HERO_CRAWL_POSE` with
`HERO_PRONE_TRANSITION`) are at actor slots, and the composition splits are at
literal ones. `--control` prints the breakdown both ways so the ratio can be
re-derived rather than believed.

Signal read
-----------
Per run: the routine label it sits in, the anchor, the members in draw order
with repeats marked, and how many are still numbered. Nothing here is a name
or a proposal -- it is a work queue, and the naming still needs the render.

Usage
-----
    python3 notes/render-and-name/frame_runs.py --stage CAVES
    python3 notes/render-and-name/frame_runs.py --stage CAVES --min 5
    python3 notes/render-and-name/frame_runs.py --stage CAVES --anchor actor
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels"
PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
RE_NUM = re.compile(r"^CINEMATIC_\d+$")
RE_LBL = re.compile(r"^([A-Za-z_]\w*):\s*$")
RE_V = re.compile(r"^\s*video\s+(?:type=\d+,\s*)?offset=([A-Za-z_]\w*),"
                  r"\s*x=([^,]+),\s*y=([^,\s]+)")
# Opcodes that may sit between two frames of one animation without breaking it.
RE_OK = re.compile(r"^\s*(break|play\s|setPalette\s|selectVideoPage\s|"
                   r"copyVideoPage\s|fill\s|mov\s|add\s|sub\s|and\s|or\s|"
                   r"jne\s|je\s|jg\s|jl\s|jge\s|jle\s|setup\s|"
                   r"unfreezeChannels|deleteChannels|freezeChannels)")


def runs(branch: str, stage: str):
    f = SRC / branch / f"{stage}.asm"
    if not f.is_file():
        return []
    out, cur, label, anchor = [], [], None, None

    def flush():
        nonlocal cur
        if len(cur) >= 2:
            out.append((label, anchor, list(cur)))
        cur = []

    for line in f.read_text(errors="replace").splitlines():
        if RE_LBL.match(line):
            # A label can be jumped to, so the run cannot cross it.
            flush()
            label = RE_LBL.match(line).group(1)
            anchor = None
            continue
        v = RE_V.match(line)
        if v:
            a = f"{v.group(2).strip()},{v.group(3).strip()}"
            if cur and a != anchor:
                flush()
            anchor = a
            cur.append(v.group(1))
            continue
        if line.strip() and not RE_OK.match(line):
            flush()
            anchor = None
    flush()
    return out


def family_of(name: str) -> str:
    """The name with a trailing index, `_F<n>`, or a two-word tail removed."""
    n = re.sub(r"_F?\d+$", "", name)
    return re.sub(r"_(LIT|DARK|LEFT|RIGHT|SETTLED)$", "", n)


def control(branch: str, stage: str, least: int) -> int:
    whole, split = [], []
    whole_a, split_a = [], []
    for label, anchor, members in runs(branch, stage):
        uniq = list(dict.fromkeys(members))
        if len(uniq) < least or any(RE_NUM.match(m) for m in uniq):
            continue
        fams = {family_of(m) for m in uniq}
        var = "[" in anchor
        if len(fams) == 1:
            whole.append((label, uniq, fams))
            whole_a.append((label, uniq, fams, var))
        else:
            split.append((label, uniq, fams))
            split_a.append((label, uniq, fams, var))
    print(f"  runs of {least}+ distinct pictures in {branch}/{stage} where "
          f"every member is already named\n")
    for label, uniq, fams in whole:
        print(f"  one family   {len(uniq):>3}  {next(iter(fams))}")
    for label, uniq, fams in split:
        print(f"  {len(fams)} families  {len(uniq):>3}  {label}")
        for f in sorted(fams):
            print(f"                    {f}")
    n = len(whole) + len(split)
    print(f"\n  {len(whole)} of {n} fully-named run(s) carry ONE family prefix")
    for kind, want in (("actor slot", True), ("literal anchor", False)):
        w = sum(1 for lab, u, f, v in whole_a if v is want)
        t = w + sum(1 for lab, u, f, v in split_a if v is want)
        if t:
            print(f"      at a {kind:<16} {w} of {t}")
    print("  A run is a candidate to look at, not a family: the rest are "
          "compositions,\n  or a body drawn with its limb. See the module "
          "docstring.")
    return 0


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--stage", required=True)
    ap.add_argument("--port", default="amiga", choices=sorted(PORTS))
    ap.add_argument("--min", type=int, default=3,
                    help="least still-numbered members to report a run")
    ap.add_argument("--control", action="store_true",
                    help="of the runs whose members are ALL named, how many "
                         "carry one family prefix?")
    ap.add_argument("--anchor", choices=["actor", "literal", "any"],
                    default="any",
                    help="actor = a variable pair, literal = fixed x and y")
    args = ap.parse_args()

    if args.control:
        return control(PORTS[args.port], args.stage, args.min)

    rows = []
    for label, anchor, members in runs(PORTS[args.port], args.stage):
        num = [m for m in dict.fromkeys(members) if RE_NUM.match(m)]
        if len(num) < args.min:
            continue
        var = "[" in anchor
        if args.anchor == "actor" and not var:
            continue
        if args.anchor == "literal" and var:
            continue
        rows.append((len(num), label, anchor, members, num))
    rows.sort(reverse=True)

    print(f"  {len(rows)} run(s) in {args.port}/{args.stage} with at least "
          f"{args.min} still-numbered member(s)\n")
    for n, label, anchor, members, num in rows:
        order = []
        for m in members:
            order.append(m.replace("CINEMATIC_", "")
                         if RE_NUM.match(m) else "<named>")
        print(f"  {n:>3} numbered   at {anchor:<22} {label}")
        print(f"        {' '.join(order)}")
    total = sum(n for n, *_ in rows)
    print(f"\n  {total} still-numbered picture(s) sit in a run, "
          f"{len(set(m for _n, _l, _a, _m, num in rows for m in num))} "
          f"distinct")
    return 0


if __name__ == "__main__":
    sys.exit(main())
