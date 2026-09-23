#!/usr/bin/env python3
"""A placeholder whose whole body is `ret` takes its one caller's name.

Question answered
-----------------
`../placeholder-census/` counts 7,594 placeholder labels and shows 828 of them
are a *position* inside a routine that already has a name. It then declines to
name them, because a positional role vocabulary would have to be invented --
of 3,384 named forward-conditional targets only 67 end in `DONE` and 58 in
`RET`, so a positional suffix is allowed by the tree but is not what the tree
mostly does.

That is true of the 828 as a whole and **false of one slice of it**, which
this module takes. Measured over every label in the tree that ends `_RET`, is
reached only from inside one named routine, and whose entire body is a bare
`ret`:

    112  the stem is exactly the owning routine's name
     13  the stem is something else

So `<OWNER>_RET` is not a vocabulary anyone has to invent. It is what the tree
already does, 112 times, for exactly this position. The 13 exceptions are
shared tails that several routines fall into -- `SHARED_RET`,
`CACHE_SCREEN_NUM_RET` -- and they are excluded here by the one-owner rule
before the name is ever derived.

    PRISON_HERO_FRONT_X_BY_FACING:
            ...
            jne [0x0E], 0x00, LABEL_XXXX
            ...
    LABEL_XXXX:                       <- becomes PRISON_HERO_FRONT_X_BY_FACING_RET
            ret

What it refuses
---------------
- a body that is anything but a single `ret`, which is the whole claim;
- a label reached by `call` or `setup`: that is an entry point, a routine in
  its own right, and `ret` is its whole implementation rather than a tail;
- a label reached from more than one routine, or from a routine that is
  itself a placeholder -- there is then no one name to take;
- an owner whose own name is mechanical or carries a raw index or hex tail,
  because `FILL_PAGE_00_COLOR_08_RET` propagates a placeholder rather than
  removing one. Two filters run: `../sole-named-drawer/`'s, and
  `naming_census`'s own generated-form patterns, which the applier uses. The
  second was added because the applier rejected `CHECK_HERO_Y_LT_VAR41_RET`
  as `operand_mech` after the first had passed it -- a probe that proposes
  rows its applier throws away is measuring the wrong thing;
- a derived name already used in that file (#0118).

The control
-----------
`--control` re-derives the stem of every label already named `<X>_RET` in this
position and checks it against the owner the reachability gives. It is the
same shape of check as `../backdrop-drawer/ --control`: reproduce what a
person wrote, from evidence they did not use.

Usage
-----
    python3 notes/bare-ret-tails/owner_ret.py --control
    python3 notes/bare-ret-tails/owner_ret.py
    python3 notes/bare-ret-tails/owner_ret.py --proposals
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(SRC / "notes" / "placeholder-census"))
sys.path.insert(0, str(SRC / "notes" / "sole-named-drawer"))
import placeholder_roles as P                                # noqa: E402
import nameable_from_drawer as N                             # noqa: E402
sys.path.insert(0, str(SRC.parent / "another-world-archaeology" / "tools"))
import naming_census as NC                                   # noqa: E402

# The applier runs `naming_census`'s classifier and refuses a name that is
# still a generated form. Reusing the same classifier here means the probe
# and the applier agree instead of the probe proposing rows the applier
# throws away: it rejected `CHECK_HERO_Y_LT_VAR41_RET` as `operand_mech`,
# which `nameable_from_drawer`'s filters alone do not catch.
GENERATED = {"operand_mech", "addr_suffixed", "res_index", "placeholder",
             "hex_word", "fold_local"}

BRANCHES = ("chahi_amiga_1991", "dos_1992", "cartridge_1992", "gba_2004")


def usable_owner(name: str) -> bool:
    if P.PH.match(name):
        return False
    if any(m in name for m in N.MECHANISM):
        return False
    if NC.classify(name) in GENERATED:
        return False
    return not (N.RE_RAWINDEX.search(name) or N.RE_HEXTAIL.search(name)
                or N.RE_THRESHOLD.search(name))


def sole_owner(refs, at, name):
    """The one named routine that jumps to `name`, or None."""
    r = refs.get(name, [])
    if not r:
        return None
    if {o for _i, _c, o in r} & {"call", "setup"}:
        return None
    owners = {c for _i, c, _o in r}
    if len(owners) != 1:
        return None
    own = next(iter(owners))
    if own is None or P.PH.match(own):
        return None
    return own


def scan():
    for branch in BRANCHES:
        for stage in P.ALL_STAGES:
            lines = P.read(branch, stage)
            if lines is None:
                continue
            at, refs = P.index(lines)
            # list(): the caller adds its derived names to `at` to catch
            # collisions inside one file, so the dict must not be iterated
            # lazily while that happens.
            for name, i in list(at.items()):
                if P.body_ops(lines, i) != ["ret"]:
                    continue
                own = sole_owner(refs, at, name)
                if own is None:
                    continue
                yield branch, stage, name, own, at


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--control", action="store_true")
    ap.add_argument("--proposals", action="store_true")
    args = ap.parse_args()

    if args.control:
        ok = refine = bad = 0
        seen = set()
        for branch, stage, name, own, _at in scan():
            if P.PH.match(name) or not name.endswith("_RET"):
                continue
            stem = name[:-4]
            if stem == own:
                ok += 1
            elif own.startswith(stem + "_"):
                # The person dropped a trailing qualifier the return does not
                # need -- PRISON_HERO_FRONT_X_RET off
                # PRISON_HERO_FRONT_X_BY_FACING. That is the same rule applied
                # with more judgement, not a different one, and #0120 says
                # leave it alone.
                refine += 1
                if (name, own) not in seen:
                    seen.add((name, own))
                    print(f"  refines : {name:<46}owner {own}")
            else:
                bad += 1
                if (name, own) not in seen:
                    seen.add((name, own))
                    print(f"  differs : {name:<46}owner {own}")
        print(f"\n  {ok} name(s) are exactly <owner>_RET, {refine} are the "
              f"owner with a trailing qualifier dropped,\n  {bad} are "
              f"something else")
        return 0

    props: dict[tuple, list] = collections.defaultdict(list)
    held = collections.Counter()
    for branch, stage, name, own, at in scan():
        if not P.PH.match(name):
            continue
        if not usable_owner(own):
            held["the owning routine's own name is mechanical or a "
                 "placeholder"] += 1
            continue
        new = f"{own}_RET"
        if new in at:
            held["that name is already on another label in the file"] += 1
            continue
        props[(branch, stage)].append((name, new, own))
        at[new] = -1

    if args.proposals:
        for (branch, stage), rows in sorted(props.items()):
            print(f"\n----- {branch} / {stage} -----")
            print("| routine | proposed name | confidence | evidence |")
            print("| --- | --- | --- | --- |")
            for name, new, own in sorted(rows, key=lambda r: r[1]):
                print(f"| {name} | {new} | high | its entire body is a bare "
                      f"`ret`, and the only thing that reaches it is a jump "
                      f"from inside `{own}` -- not a `call` or a `setup`, so "
                      f"it is that routine's return tail and not an entry "
                      f"point. 112 labels in the tree already carry "
                      f"`<owner>_RET` in exactly this position |")
        return 0

    n = sum(len(v) for v in props.values())
    print(f"{n} bare-`ret` tail(s) nameable\n")
    for k, v in sorted(props.items()):
        print(f"  {k[0]:<18}{k[1]:<10}{len(v):>4}")
    print()
    for why, c in held.most_common():
        print(f"  held: {c:>4}  {why}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
