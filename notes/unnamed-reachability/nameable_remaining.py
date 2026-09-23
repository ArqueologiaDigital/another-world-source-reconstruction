#!/usr/bin/env python3
"""Of the assets still unnamed, how many can be named at all?

Question answered
-----------------
`shared-bank-naming/asset_naming_share.py` gives one number -- how many
`CINEMATIC_*` / `CV_*` EQUs carry a semantic name -- and treats every unnamed
one as work remaining. Some of it is not work. Three kinds of constant cannot
honestly be given a name that says what they draw:

  NEVER_DRAWN   the EQU exists and no `video` in the branch references it. It
                has no draw site, no palette, no neighbours: nothing to read it
                against except the art, and nothing to check a reading against.
  UNREACHABLE   every draw of it sits in bytes control cannot get to -- inside
                an `.if INCLUDE_UNREACHABLE_CODE == on` guard, or after a `ret`,
                `jmp` or `killChannel` with no label between. #0126 is explicit
                that a role name does not go on unreachable bytes.
  DRAWN         at least one draw is reachable. This is the real queue.

Found while finishing ENDING and PASSCODE: msdos/ENDING's last three unnamed
assets are all drawn on the three lines after a `killChannel` that follows a
`jmp`, and dos/CODE_WHEEL's single one sits inside a guard the disassembler
itself annotated "Nothing references this address."

How reachability is decided
---------------------------
Deliberately conservatively, so the answer never overstates how much is dead:

* a draw inside `.if INCLUDE_UNREACHABLE_CODE` is unreachable -- the tree says so;
* otherwise, walk back from the draw to the nearest label. If a `ret`,
  `killChannel` or unconditional `jmp` lies between that label and the draw,
  with no label in between, the draw is unreachable.
* anything else counts as reachable, including draws behind conditionals.

A constant with one reachable draw is `DRAWN` however many unreachable ones it
also has.

Run it
------
    python3 notes/unnamed-reachability/nameable_remaining.py
    python3 notes/unnamed-reachability/nameable_remaining.py --stage PASSCODE --list
"""
from __future__ import annotations

import argparse
import collections
import pathlib
import re

SRC = pathlib.Path(__file__).resolve().parents[2] / "src" / "levels"
BRANCHES = ["chahi_amiga_1991", "dos_1992"]
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]

RE_EQU = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s+0x[0-9A-Fa-f]+")
RE_UNNAMED = re.compile(r"^(CINEMATIC_\d+|CV_[0-9A-F]{4})$")
RE_LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
RE_DRAW = re.compile(r"video\s+(?:type=\d+,\s*)?offset=([A-Za-z_][A-Za-z0-9_]*)")
RE_TERM = re.compile(r"^\s*(ret|killChannel|jmp\s)")
RE_GUARD_ON = re.compile(r"^\s*\.if\s+INCLUDE_UNREACHABLE_CODE")
RE_ENDIF = re.compile(r"^\s*\.endif")


def classify(branch: str, stage: str):
    f = SRC / branch / f"{stage}.asm"
    if not f.is_file():
        return {}
    lines = f.read_text().splitlines()

    unnamed = {n for n in (m.group(1) for m in map(RE_EQU.match, lines) if m)
               if RE_UNNAMED.match(n)}
    if not unnamed:
        return {}

    status = {n: "NEVER_DRAWN" for n in unnamed}
    dead_depth = 0          # >0 while inside an INCLUDE_UNREACHABLE_CODE guard
    if_depth = 0
    since_label_terminated = False

    for line in lines:
        if RE_GUARD_ON.match(line):
            dead_depth = if_depth + 1
            if_depth += 1
            continue
        if re.match(r"^\s*\.if\b", line):
            if_depth += 1
            continue
        if RE_ENDIF.match(line):
            if dead_depth and if_depth == dead_depth:
                dead_depth = 0
            if_depth = max(0, if_depth - 1)
            continue
        if RE_LABEL.match(line):
            since_label_terminated = False
            continue
        d = RE_DRAW.search(line)
        if d and d.group(1) in unnamed:
            n = d.group(1)
            if dead_depth or since_label_terminated:
                if status[n] == "NEVER_DRAWN":
                    status[n] = "UNREACHABLE"
            else:
                status[n] = "DRAWN"
        if RE_TERM.match(line):
            since_label_terminated = True
    return status


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--stage", choices=STAGES)
    ap.add_argument("--branch", choices=BRANCHES)
    ap.add_argument("--list", action="store_true",
                    help="name every NEVER_DRAWN and UNREACHABLE constant")
    args = ap.parse_args()

    grand = collections.Counter()
    print(f"  {'port/stage':<28}{'unnamed':>9}{'DRAWN':>8}"
          f"{'UNREACH':>9}{'NEVER':>8}")
    for branch in BRANCHES:
        if args.branch and branch != args.branch:
            continue
        for stage in STAGES:
            if args.stage and stage != args.stage:
                continue
            st = classify(branch, stage)
            if not st:
                continue
            c = collections.Counter(st.values())
            grand.update(c)
            print(f"  {branch.split('_')[0] + '/' + stage:<28}{len(st):>9}"
                  f"{c['DRAWN']:>8}{c['UNREACHABLE']:>9}{c['NEVER_DRAWN']:>8}")
            if args.list:
                for n, v in sorted(st.items()):
                    if v != "DRAWN":
                        print(f"        {v:<12} {n}")
    tot = sum(grand.values())
    print(f"\n  {'TOTAL':<28}{tot:>9}{grand['DRAWN']:>8}"
          f"{grand['UNREACHABLE']:>9}{grand['NEVER_DRAWN']:>8}")
    print(f"\n  {grand['DRAWN']} of {tot} still-unnamed assets have a reachable")
    print("  draw site. The rest have nothing to read a name against, and #0126")
    print("  forbids putting a role name on the unreachable ones.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
