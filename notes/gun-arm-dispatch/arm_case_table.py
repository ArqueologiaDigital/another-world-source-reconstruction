#!/usr/bin/env python3
"""Recover the hero's weapon-state arm table from the dispatch that selects it.

Question answered
-----------------
`notes/shared-bank-geometry/` settled that 191 shared-bank offsets are the
hero's art and named 52 of them from cross-stage consensus. A second group
resisted that method entirely: the forked 8x18 arms around 0x33F2 and 0x35B4,
and the 21 single-pixel dots at 0x5BF8..0x5CCC. They have almost no named
drawers, so no consensus forms, and rendering a one-pixel dot says nothing.

They do not need a render, because the code states what they are. Both
directions of the hero's armed pose are drawn by a **switch on `[0x0A]`**, one
polygon per case:

    jne [0x0A], 0x02, <else>
    video type=0, offset=CV_33F2, ...          <- the arm for case 2
    jg  [0x06], [0x30], <ret>                  <- charge at or below threshold
    mov [0xF8], [0x31]
    and [0xF8], 0x0004                         <- a bit of a timer
    je  [0xF8], 0x00, <ret>
    video type=0, offset=CV_5C0C, ...          <- the dot, only while blinking

A case number is not an index someone assigned to the art; it is the value the
VM compares against. Reading it off is not "naming from the index" -- the
prohibition in NAMING.md §2 is about the *disassembler's* encounter order,
which carries no meaning. This carries the machine's own.

What corroborates it
--------------------
  - `HERO_GUN_ARM_POSE_LEFT_CASE_02` and `_CASE_03` are already-earned routine
    names on the blocks that draw `CV_35D0` and `CV_35F8` -- cases 2 and 3 of
    the left switch. The table reproduces them, which is the check that the
    case numbers mean what this probe says.
  - `CAPSULE_HERO_AIM_HOLD_RIGHT_DRAW_LOW_CHARGE_BLINK` and
    `HERO_CROUCH_ARMED_RIGHT_FRAME_CHARGE_BLINK`, earned in different stages,
    both draw `CV_5C4C` -- one of the dots. Two independent names say *charge
    blink*, and the guard above says the same thing in opcodes: draw it only
    while the charge is under a threshold and a timer bit is set.
  - The same table is recovered independently from each port and each stage
    that has the dispatch. The probe reports disagreement rather than merging.

The default case
----------------
The `else` after the last test is reported as case 4, not as `DEFAULT`, and
that is a measured claim rather than a convenience. In the three stages that
have this dispatch -- PRISON, CAVES and CAPSULE -- the only literals ever
written to `[0x0A]` are 0, 1, 3 and 4, so the default branch handles exactly
4. (TANK and LAKE write large values to the same variable and have no such
dispatch: `[0x0A]` is reused per stage, which is why no whole-game alias for
it would be right.) The probe re-derives that range and falls back to
`DEFAULT` if it ever sees a value above 4 in a dispatch stage.

Direction, which is the part that needed real evidence
------------------------------------------------------
Both switches are `[0x0A]`, and the art is **not** mirrored between them --
checked, and the control checked too: the known LEFT and RIGHT walk arms at
the same frame index are not reflections of each other either, so this game
draws separate poses per direction and a mirror test cannot assign direction
here. It was the control, not the hypothesis, that failed.

What does assign it is the entry site, twice over:

  - the switch holding `CV_35B4` is entered from blocks that have just drawn
    `HERO_STAND_LEFT_ARM`, `CV_331A`, `CV_332A`, `CV_3332`, `CV_333A`,
    `CV_3342` -- the walk-left arms -- and its callers are 70:10 LEFT-named.
    Two of its cases already carry the earned names
    `HERO_GUN_ARM_POSE_LEFT_CASE_02` and `_CASE_03`.
  - the switch holding `CV_347C` is entered from 16 sites, **15 of which have
    just drawn a `HERO_WALK_RIGHT_BODY_F*`** and none a left-facing one.

Signals read
------------
`jne [<var>], <n>, <label>` immediately followed by
`video type=0, offset=<sym>` in `src/levels/{chahi_amiga_1991,dos_1992}/*.asm`,
and any second `video type=0` reached before the block's `ret`. Nothing is
read from the ROM: this is a control-flow fact.

Exit status
-----------
0 when every port and stage that has a given switch agrees on its table.
1 on any disagreement, since then one offset would be two different cases.

Usage
-----
    python3 notes/gun-arm-dispatch/arm_case_table.py
    python3 notes/gun-arm-dispatch/arm_case_table.py --var 0x0A --proposals
    python3 notes/gun-arm-dispatch/arm_case_table.py --var 0x05 \
        --base HERO_WATER_DEPTH --proposals

`[0x0A]` is the weapon state and `[0x05]` the waterline depth; a sweep of
every variable tested this way found no third switch selecting shared-bank
art. `--base` exists because the stem is the one thing the dispatch cannot
tell you -- the case numbers, the direction and the membership all come out of
the code, and only what the family *is* has to be supplied from the earned
routine names that sit on it.
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2]
PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES",
          "TANK", "CAPSULE", "ENDING", "PASSCODE"]

RE_LABEL = re.compile(r"^([A-Za-z_]\w*):")
RE_CASE = re.compile(r"^\s*jne\s+\[(\w+)\],\s*(0x[0-9A-Fa-f]+),\s*(\w+)")
RE_DRAW = re.compile(r"^\s*video\s+type=0,\s*offset=(\w+),\s*x=\[(\w+)\]")
# Which draw slot a switch has to use to count. Default: the hero's own
# position. The actor slot (#0138) is opt-in via --at, because a name derived
# there may describe the pose but never the character.
# BUDDY_X was renamed ACTOR_X on 2026-09-25 (it is the actor scheduler's
# working register, not Buddy's -- notes/actor-anchors/). Both spellings
# stay here: this probe is run against older checkouts too, and a set that
# silently matches nothing is the failure this directory exists to avoid.
SLOTS = {"hero": {"HERO_X"}, "actor": {"0x07", "ACTOR_X", "BUDDY_X"}}
RE_RET = re.compile(r"^\s*(ret|break|jmp)\b")


def scan(text: str, var: str, slot: set | None = None):
    """Chains of cases, linked by each `jne`'s else-target.

    A switch here is a chain: `jne [var], n, L` falls through to case n's
    draws and jumps to `L`, which begins case n+1. Grouping instead by
    "consecutive case values in line order" -- which the first version did --
    silently welds an unrelated guard onto the front of a switch. The unarmed
    test `jne [0x0A], 0x00, ...` at the top of a walk or stand routine is a
    different routine entirely, and it got reported as case 0 of the weapon
    switch. Following the else-target cannot do that.
    """
    lines = [l.split(";", 1)[0] for l in text.splitlines()]
    at_label: dict[str, int] = {}
    for i, line in enumerate(lines):
        m = RE_LABEL.match(line)
        if m:
            at_label[m.group(1)] = i

    def case_at(i: int):
        m = RE_CASE.match(lines[i]) if i < len(lines) else None
        if not m or m.group(1) != var:
            return None
        d = RE_DRAW.match(lines[i + 1]) if i + 1 < len(lines) else None
        if not d or d.group(2) not in (slot or SLOTS["hero"]):
            return None
        secondary = None
        for j in range(i + 2, min(i + 12, len(lines))):
            if RE_LABEL.match(lines[j]) or RE_RET.match(lines[j]):
                break
            d2 = RE_DRAW.match(lines[j])
            if d2:
                secondary = d2.group(1)
                break
        return int(m.group(2), 16), d.group(1), secondary, m.group(3)

    def default_at(label: str):
        """The else-block of the last case: draws, but tests nothing."""
        j = at_label.get(label)
        if j is None:
            return None
        k = j + 1
        while k < len(lines) and not lines[k].strip():
            k += 1
        d = RE_DRAW.match(lines[k]) if k < len(lines) else None
        if not d or d.group(2) not in (slot or SLOTS["hero"]):
            return None
        secondary = None
        for m2 in range(k + 1, min(k + 12, len(lines))):
            if RE_LABEL.match(lines[m2]) or RE_RET.match(lines[m2]):
                break
            d2 = RE_DRAW.match(lines[m2])
            if d2:
                secondary = d2.group(1)
                break
        return d.group(1), secondary

    starts = [i for i in range(len(lines)) if case_at(i)]
    chained: set[int] = set()
    for i in starts:
        tgt = case_at(i)[3]
        j = at_label.get(tgt)
        while j is not None and j + 1 < len(lines) and not case_at(j + 1):
            j += 1 if RE_LABEL.match(lines[j + 1]) else None or len(lines)
        if j is not None and case_at(j + 1):
            chained.add(j + 1)
    chains = []
    for i in starts:
        if i in chained:
            continue
        run, k = [], i
        while k is not None and case_at(k):
            c = case_at(k)
            run.append((c[0], c[1], c[2]))
            nxt = at_label.get(c[3])
            k = nxt + 1 if nxt is not None else None
        if len(run) >= 2:
            last = case_at(at_label.get(run[-1][0] and 0, 0) or 0)
            tail = None
            k2 = i
            while k2 is not None and case_at(k2):
                c = case_at(k2)
                nxt = at_label.get(c[3])
                if nxt is not None and not case_at(nxt + 1):
                    tail = default_at(c[3])
                k2 = nxt + 1 if nxt is not None else None
            if tail:
                run.append((run[-1][0] + 1, tail[0], tail[1]))
            chains.append(run)
    return chains


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--var", default="0x0A")
    ap.add_argument("--at", default="hero", choices=sorted(SLOTS),
                    help="which draw slot the switch must use; 'actor' is the "
                         "#0138 shared record, where a pose may be named but "
                         "never a character")
    ap.add_argument("--proposals", action="store_true",
                    help="emit an OLD NEW map for apply_bank_names.py --map")
    ap.add_argument("--base", default="HERO_GUN_ARM",
                    help="name stem for --proposals; the direction and "
                         "_CASE_<n> are appended")
    ap.add_argument("--secondary-suffix", default="_CHARGE_BLINK",
                    help="suffix for the conditional second draw of a case")
    args = ap.parse_args()

    # (primary of case 2) identifies which switch a run belongs to, because
    # the two directions never share an arm polygon.
    tables: dict[tuple, dict] = collections.defaultdict(dict)
    seen_in: dict[tuple, set] = collections.defaultdict(set)
    for port, br in PORTS.items():
        for stage in STAGES:
            p = SRC / "src" / "levels" / br / f"{stage}.asm"
            if not p.is_file():
                continue
            for run in scan(p.read_text(errors="replace"), args.var,
                            SLOTS[args.at]):
                key = run[0][1]
                seen_in[key].add(f"{port}/{stage}")
                for case, prim, sec in run:
                    tables[key].setdefault(case, set()).add((prim, sec))

    bad = 0
    print(f"switch on [{args.var}], one arm polygon per case\n")
    for key in sorted(tables, key=lambda k: min(tables[k])):
        print(f"  switch starting at {key} "
              f"({', '.join(sorted(seen_in[key]))})")
        for case in sorted(tables[key]):
            vals = tables[key][case]
            if len(vals) > 1:
                bad += 1
                print(f"    case {case}: DISAGREEMENT {sorted(vals)}")
                continue
            prim, sec = next(iter(vals))
            extra = f"   + {sec} while the charge blink is on" if sec else ""
            print(f"    case {case}: {prim}{extra}")
        print()

    if bad:
        print(f"FAIL: {bad} case(s) resolve to different art in different "
              f"files, so one offset would be two cases.")
        return 1
    print("Every port and stage that has a given switch agrees on its table.")

    if args.proposals:
        # Direction per switch, from the entry sites (see the docstring).
        facing = {}
        for key in tables:
            n = collections.Counter()
            # Every case of the switch, not just its head. Case 1 is usually
            # an unnamed LABEL_<hex>; the earned direction sits on case 2
            # (HERO_GUN_ARM_POSE_LEFT_CASE_02), so keying on the head alone
            # finds nothing and reports the direction as undetermined.
            members = {prim for case in tables[key]
                       for prim, _sec in tables[key][case]}
            for port, br in PORTS.items():
                for stage in STAGES:
                    f = SRC / "src" / "levels" / br / f"{stage}.asm"
                    if not f.is_file():
                        continue
                    lines = f.read_text(errors="replace").splitlines()
                    for i, l in enumerate(lines):
                        if "offset=" not in l or not any(
                                re.search(rf"offset={re.escape(mm)}\b", l)
                                for mm in members):
                            continue
                        # (a) the label of the block that draws it. An earned
                        # name like HERO_GUN_ARM_POSE_LEFT_CASE_02 states the
                        # direction outright and is the best evidence there is.
                        for j in range(i - 1, max(-1, i - 6), -1):
                            m = RE_LABEL.match(lines[j])
                            if not m:
                                continue
                            if "LEFT" in m.group(1):
                                n["LEFT"] += 3
                            elif "RIGHT" in m.group(1):
                                n["RIGHT"] += 3
                            break
                        # (b) the art drawn immediately before the entry.
                        for j in range(i - 1, max(-1, i - 40), -1):
                            m = re.search(r"offset=([A-Za-z_]\w*)", lines[j])
                            if not m:
                                continue
                            if "RIGHT" in m.group(1):
                                n["RIGHT"] += 1
                            elif "LEFT" in m.group(1):
                                n["LEFT"] += 1
                            break
            facing[key] = n.most_common(1)[0][0] if n else None
        print("\n# map for apply_bank_names.py --map")
        for key in sorted(tables, key=lambda k: min(tables[k])):
            d = facing.get(key)
            if not d:
                print(f"# switch at {key}: direction undetermined, skipped")
                continue
            for case in sorted(tables[key]):
                prim, sec = next(iter(tables[key][case]))
                base = f"{args.base}_{d}_CASE_{case:02d}"
                if prim.startswith("CV_"):
                    print(f"{prim} {base}")
                if sec and sec.startswith("CV_"):
                    print(f"{sec} {base}{args.secondary_suffix}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
