#!/usr/bin/env python3
"""What are the 7,594 placeholder labels in the three big stages, structurally?

Question answered
-----------------
The asset half of the backlog has a map -- `../remaining-art/by_anchor.py`
sorts still-numbered art by how it is drawn. The label half had none. The lint
says amiga/CAVES is 32.6% semantic and msdos/CAPSULE 24.0%, which tells you
there is a lot left and nothing about what it is.

This is that map. It classifies every `LABEL_`, `JUNK__`, `RET_TARGET_`,
`ADDR_AT_` and `KILL_CHAN_AT_` label in PRISON, CAVES and CAPSULE across both
priority ports by **how control reaches it**, because that is what decides
which evidence could name it.

Measured 2026-09-23:

    14503  labels
     7594  placeholders
       2360  its only jumper is itself a placeholder
       2253  unreferenced (a dead byte, or a fall-through-only join)
       1690  reached by call/setup: it is an entry point
        828  INTERNAL to one named routine
        287  jumped to from 2 routines
        ...  and a thin tail out to 9

The 828 are the tractable ones: a placeholder jumped to only from inside a
single routine that already has a name is a *position* in that routine, and a
position can be named without knowing what the art depicts.

Why the obvious rule for them is not applied
--------------------------------------------
Their roles sort cleanly -- 629 forward-jump targets, 127 backward (loop
heads), 44 short tails, 28 bare `ret` -- and 549 of the 649 owning routines,
counted per (branch, stage, routine), have exactly one, so `<OWNER>_<ROLE>`
would be unambiguous for those. It is
not applied, because the role vocabulary would have to be invented. Measured over the labels already
named in each position, the final token is a content word or a phase number
far more often than a positional one: forward-conditional targets end in
`DONE` 67 times and `RET` 58 times out of 3,384, and backward targets end in
`LOOP` 38 times out of 433. A positional suffix is *allowed* by the tree, but
it is not what the tree mostly does, and 828 of them would make it what the
tree mostly does.

Two rules that were derived from the tree, measured, and rejected
----------------------------------------------------------------
**Frames by first appearance.** A routine that draws a complete
`CINEMATIC_<STEM>_F*` family numbers it by order of first appearance in its
body. That is exact -- **159 of 159** families whose whole index run is drawn
by one routine obey it, and the 19 that do not are every family the routine
only partly draws, where the ordinal is over a partial view. `--frames`
re-derives it.

What cannot be derived is the STEM. Of those 159, **82** have a stem unrelated
to the routine's name (`ENDING_CLOSEUP_SIDE_SILHOUETTE_RISE_FALL_LOOP` draws
`CINEMATIC_ENDING_CLOSEUP_SILHOUETTE_F*`); only 77 are the routine's name, or the routine's name with
a suffix removed. Using the routine's name anyway yields 10 families and 37
pictures, and inspection kills most of them -- one would be
`CINEMATIC_PRISON_DRAW_CIN505_AT_X21_Y27_L35_F0`, a name carrying both a raw
index and two coordinates. Not worth a module.

**`_DONE` names its loop head `_LOOP`.** In the PRISON zoom ladder,
`PRISON_CUTSCENE_ZOOM_IN_PHASE_04_DONE` closes a `djnz` onto
`PRISON_CUTSCENE_ZOOM_IN_PHASE_04_LOOP`, and phase 05 does the same. Tree-wide
the pairing holds 9 times out of 16, which is not a rule. `--loops` prints
both sides. It does produce two certain names inside that one ladder, where
phases 04 and 05 prove the convention in the same file, and those were taken
by hand.

Usage
-----
    python3 notes/placeholder-census/placeholder_roles.py
    python3 notes/placeholder-census/placeholder_roles.py --roles
    python3 notes/placeholder-census/placeholder_roles.py --frames
    python3 notes/placeholder-census/placeholder_roles.py --loops
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2]
BRANCHES = ("chahi_amiga_1991", "dos_1992")
BIG = ("PRISON", "CAVES", "CAPSULE")
ALL_STAGES = ("PRISON", "CAVES", "CAPSULE", "LAKE", "TANK", "INTRO", "ENDING",
              "CODE_WHEEL", "PASSCODE")

RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
# The lint's own list: tools/lint_naming.py, the `placeholders` rule.
PH = re.compile(r"^(LABEL_|JUNK__|RET_TARGET_|ADDR_AT_|KILL_CHAN_AT_)")
RE_END = re.compile(r"^\s*(ret\s*$|jmp\s|db 0x11\s*$)")
RE_V = re.compile(r"^\s*video\s+(?:type=\d+,\s*)?offset=([A-Za-z_]\w*)")
RE_FAM = re.compile(r"^CINEMATIC_([A-Z0-9_]+?)_F(\d+)$")
RE_BACK = re.compile(r"^\s*(djnz\s+\[[^\]]+\],|jmp)\s+([A-Za-z_]\w*)\s*$")


def read(branch: str, stage: str):
    f = SRC / "src" / "levels" / branch / f"{stage}.asm"
    return f.read_text(errors="replace").splitlines() if f.is_file() else None


def index(lines):
    """-> (label -> line number, label -> [(line, jumper, opcode)])."""
    at = {}
    for i, l in enumerate(lines):
        m = RE_LBL.match(l)
        if m:
            at[m.group(1)] = i
    refs = collections.defaultdict(list)
    cur = None
    for i, l in enumerate(lines):
        m = RE_LBL.match(l)
        if m:
            cur = m.group(1)
            continue
        s = l.strip()
        if not s:
            continue
        op = s.split()[0]
        # A bare token scan, not an operand parse: `setup channel=0x39,
        # address=X` and `je [V], 0x01, X` put the label in different
        # positions, and every one of them counts as a reference.
        for tok in re.findall(r"\b([A-Z_][A-Za-z0-9_]{2,})\b", l):
            if tok in at and tok != cur:
                refs[tok].append((i, cur, op))
    return at, refs


def body_ops(lines, i):
    """The opcodes from just after line `i` to the label's end."""
    out = []
    for l in lines[i + 1:]:
        if RE_LBL.match(l):
            break
        s = l.strip()
        if s:
            out.append(s.split()[0])
        if RE_END.match(l):
            break
    return out


def census():
    tot = collections.Counter()
    internal = []
    for br in BRANCHES:
        for st in BIG:
            lines = read(br, st)
            if lines is None:
                continue
            at, refs = index(lines)
            tot["labels"] += len(at)
            for n, i in at.items():
                if not PH.match(n):
                    continue
                tot["placeholders"] += 1
                r = refs.get(n, [])
                if not r:
                    tot["  unreferenced (a dead byte, or a fall-through-only "
                        "join)"] += 1
                    continue
                ops = {o for _i, _c, o in r}
                owners = {c for _i, c, _o in r}
                if ops & {"call", "setup"}:
                    tot["  reached by call/setup: it is an entry point"] += 1
                    continue
                if len(owners) != 1:
                    tot[f"  jumped to from {min(len(owners), 9)} routines"] += 1
                    continue
                own = next(iter(owners))
                if own is None or PH.match(own):
                    tot["  its only jumper is itself a placeholder"] += 1
                    continue
                tot["  INTERNAL to one named routine"] += 1
                back = any(j > i for j, _c, _o in r)
                fwd = any(j < i for j, _c, _o in r)
                b = body_ops(lines, i)
                if back and not fwd:
                    role = "LOOP (backward target: a loop head)"
                elif fwd and not back:
                    role = ("RET (the body is a bare `ret`)" if b == ["ret"]
                            else "DONE (a two-instruction tail)"
                            if len(b) <= 2 and b and b[-1] in ("ret", "jmp")
                            else "SKIP (a forward target with a real body)")
                else:
                    role = "MIXED (reached both ways)"
                internal.append(((br, st, own), n, role))
    return tot, internal


def frames():
    """Control: is a complete _F family indexed by order of first appearance?"""
    agree = dis = skipped = 0
    unrelated = prefixed = same = 0
    bad = []
    for f in sorted((SRC / "src" / "levels").glob("*/*.asm")):
        if f.parent.name == "_canonicalized":
            continue
        lines = f.read_text(errors="replace").splitlines()
        body = collections.OrderedDict()
        cur, done = None, {}
        for l in lines:
            m = RE_LBL.match(l)
            if m:
                cur = m.group(1)
                body.setdefault(cur, [])
                done[cur] = False
                continue
            if cur is None or done.get(cur):
                continue
            if RE_END.match(l):
                done[cur] = True
                continue
            v = RE_V.match(l)
            if v:
                body[cur].append(v.group(1))
        drawn_by = collections.defaultdict(set)
        for lab, pics in body.items():
            for p in pics:
                drawn_by[p].add(lab)
        fams = collections.defaultdict(dict)
        for p in drawn_by:
            m = RE_FAM.match(p)
            if m:
                fams[m.group(1)][int(m.group(2))] = p
        for stem, members in fams.items():
            labs = {l for p in members.values() for l in drawn_by[p]}
            if len(labs) != 1:
                continue
            if sorted(members) != list(range(len(members))):
                skipped += 1
                continue
            lab = next(iter(labs))
            mine = set(members.values())
            order = []
            for p in body[lab]:
                if p in mine and p not in order:
                    order.append(p)
            want = {p: i for i, p in enumerate(order)}
            ok = all(want.get(p) == i for i, p in members.items())
            agree += ok
            dis += not ok
            if not ok:
                bad.append((f.parent.name, f.stem, stem, lab))
            L = lab[5:] if lab.startswith("DRAW_") else lab
            if L == stem:
                same += 1
            elif L.startswith(stem + "_"):
                prefixed += 1
            else:
                unrelated += 1
    print(f"  complete families drawn by one routine: {agree} indexed by "
          f"order of first appearance, {dis} not")
    print(f"  ({skipped} partial families skipped -- the routine draws only "
          f"some of the run, so the ordinal is over a partial view and "
          f"cannot match)")
    print(f"\n  and the stem, which is what stops this being usable:")
    print(f"    {same:>4}  stem == the routine's name")
    print(f"    {prefixed:>4}  the routine's name is the stem plus a suffix")
    print(f"    {unrelated:>4}  unrelated -- a person's reading of the art")
    for b in bad:
        print("   disagree:", b)
    return 1 if dis else 0


def loops():
    """`<STEM>_DONE` closes a backward jump; is its target `<STEM>_LOOP`?"""
    ok = other = 0
    cand, taken = [], 0
    for f in sorted((SRC / "src" / "levels").glob("*/*.asm")):
        if f.parent.name == "_canonicalized":
            continue
        lines = f.read_text(errors="replace").splitlines()
        at = {}
        for i, l in enumerate(lines):
            m = RE_LBL.match(l)
            if m:
                at[m.group(1)] = i
        cur = None
        for i, l in enumerate(lines):
            m = RE_LBL.match(l)
            if m:
                cur = m.group(1)
                continue
            b = RE_BACK.match(l)
            if not b or cur is None or not cur.endswith("_DONE"):
                continue
            tgt = b.group(2)
            if tgt not in at or at[tgt] >= i:
                continue
            want = cur[:-5] + "_LOOP"
            if PH.match(tgt):
                if want in at:
                    taken += 1
                else:
                    cand.append((f.parent.name, f.stem, tgt, want))
            elif tgt == want:
                ok += 1
            else:
                other += 1
    print(f"  control: {ok} backward targets of a `_DONE` label are named "
          f"`<STEM>_LOOP`, {other} are named something else")
    print(f"  -> {ok}/{ok + other} is not a rule; this is reported, not "
          f"applied\n")
    for c in cand:
        print(f"    candidate: {c[0]}/{c[1]} {c[2]} -> {c[3]}")
    if taken:
        print(f"    ({taken} more where `<STEM>_LOOP` is already taken)")
    return 0


RE_CALL = re.compile(r"^\s*call\s+([A-Za-z_][A-Za-z0-9_]*)")


def shapes() -> int:
    """Is there an attested `<owner>_<suffix>` name for this body shape?

    `../bare-ret-tails/` names a placeholder whose body is a bare `ret` after
    the one routine that jumps to it, because the tree already spells that
    `<owner>_RET` 174 times. The obvious next question is which OTHER body
    shapes have such a form, and the answer, measured rather than assumed, is
    **none of them**.

    For every shape with four or more placeholders in that position, this
    counts how many already-named labels of the same shape are spelled
    `<owner>_<something>`. Bare `ret` is the only shape where that count is
    not zero -- every other row is a flat **0**. The nearest thing to a
    second is `call+video+call+...`, at 55 of 129, and that is one family
    ending in `DONE` rather than a convention for the shape.

    The two largest shapes are blocked for reasons of their own:

    * **a body of one `video`** (70 placeholders, 129 named) is
      `../draw-label-follows-constant/`'s case, waiting on the picture.
    * **a body of one `call`** (89 placeholders) has no rule to apply. Of the
      29 named labels in that shape, **29** carry a name unrelated to their
      callee: `SETUP_HASH_AND_DERIVE_BUCKETS` calls
      `COPY_HASH_VAR_37_TO_RANGE`, and
      `CAPSULE_HERO_WALK_LEFT_DRAW_14_GUN_RAISED` calls
      `HERO_GUN_ARM_POSE_LEFT_CASE_01`. The label says why the call is made,
      which the call itself does not. Worse, 98 of the 114 single-`call`
      placeholders call a routine that is **also** a placeholder, so there is
      nothing there to inherit even if there were a rule.

    So the positional-naming approach is closed, not open: it was worth
    exactly one slice, that slice is taken, and this is the measurement that
    says there is no second one.
    """
    ph = collections.Counter()
    named: dict[tuple, collections.Counter] = collections.defaultdict(
        collections.Counter)
    call_rel = collections.Counter()
    sys.path.insert(0, str(SRC / "notes" / "bare-ret-tails"))
    import owner_ret as O                                    # noqa: E402
    for br in BRANCHES:
        for st in ALL_STAGES:
            lines = read(br, st)
            if lines is None:
                continue
            at, refs = index(lines)
            for n, i in list(at.items()):
                own = O.sole_owner(refs, at, n)
                if own is None:
                    continue
                b = tuple(body_ops(lines, i))
                key = b if len(b) <= 3 else b[:3] + ("...",)
                if PH.match(n):
                    if O.usable_owner(own):
                        ph[key] += 1
                    if b == ("call",):
                        m = RE_CALL.match(lines[i + 1])
                        if m:
                            call_rel["placeholder, callee named"
                                     if not PH.match(m.group(1)) else
                                     "placeholder, callee also a placeholder"] += 1
                    continue
                tail = n.rsplit("_", 1)[-1]
                named[key]["owner-form" if n == f"{own}_{tail}"
                           else "other"] += 1
                if b == ("call",):
                    m = RE_CALL.match(lines[i + 1])
                    if m:
                        c = m.group(1)
                        call_rel["named, == callee" if n == c else
                                 "named, prefix of the callee or vice versa"
                                 if c.startswith(n + "_") or n.startswith(c + "_")
                                 else "named, unrelated to the callee"] += 1
    print(f"  {'body shape':<34}{'placeholders':>12}{'named, owner-form':>19}"
          f"{'named, other':>14}")
    for b, c in sorted(ph.items(), key=lambda kv: -kv[1]):
        if c < 4:
            continue
        a = named.get(b, collections.Counter())
        print(f"  {'+'.join(b)[:33]:<34}{c:>12}{a['owner-form']:>19}"
              f"{a['other']:>14}")
    print("\n  A body of one `call`, the largest shape, has no rule to "
          "apply:")
    for k, c in call_rel.most_common():
        print(f"    {c:>5}  {k}")
    print("\n  Bare `ret` is the only shape with a non-zero owner-form "
          "count; see ../bare-ret-tails/.")
    return 0


FORBIDDEN = (
    (re.compile(r"_L\d+$"), "bare fold-local suffix _L<n>"),
    (re.compile(r"FOLD_BODY"), "FOLD_BODY, a consolidation artefact"),
    (re.compile(r"DEDUP"), "DEDUP, a consolidation artefact"),
    (re.compile(r"__HELPER"), "__HELPER, a placeholder suffix (#0093)"),
)


def forbidden() -> int:
    """Names that exist and break `docs/NAMING.md` §1, sized and diagnosed.

    These looked like the cheap half of the label backlog: a name that is the
    wrong *shape* needs no knowledge of what the code does, only a rewrite.
    **They are not.** `_L<n>` is the largest class by a wide margin, and it is
    a uniquifier, not a description:

        CAVES_INIT_VARS_6D_71_70_L7:   break / add [0x6E], 0x0292 / ...
        CAVES_INIT_VARS_6D_71_70_L11:  break / add [0x6E], 0x07AA / ...

    Two different routines that the mechanical namer gave the same base, with
    a counter appended to keep them apart. Dropping the suffix would collide;
    keeping it is meaningless. What is actually wrong is the **base** --
    `INIT_VARS_6D_71_70` describes which variables are written, not what for
    -- and fixing that needs the same understanding the rest of the backlog
    needs. The suffix is a symptom.

    The draw-shaped ones (`PRISON_DRAW_CIN<n>_AT_X<x>_Y<y>_L<k>`) are blocked
    one step further along: they are `../draw-label-follows-constant/`'s case,
    waiting on the picture they draw to be named first.

    So this is a census entry and not a task. It is here so the next reader
    does not spend an hour discovering the same thing.
    """
    per: dict[str, collections.Counter] = collections.defaultdict(
        collections.Counter)
    shapes: dict[str, collections.Counter] = collections.defaultdict(
        collections.Counter)
    ALL_BRANCHES = ("chahi_amiga_1991", "dos_1992", "cartridge_1992",
                    "gba_2004")
    for branch in ALL_BRANCHES:
        for stage in ALL_STAGES:
            lines = read(branch, stage)
            if lines is None:
                continue
            for l in lines:
                m = RE_LBL.match(l)
                if not m:
                    continue
                n = m.group(1)
                for rx, label in FORBIDDEN:
                    if rx.search(n):
                        per[label][branch] += 1
                        shapes[label][re.sub(r"\d+", "#", n)] += 1
    # Counted as label DEFINITIONS per branch. The totals reproduce
    # `lint_naming.py`'s own figures exactly -- 1238 for `_L<n>`, 93 for
    # DEDUP -- so the two are measuring the same population and the split is
    # only there to show where it sits. `gba_2004` ships none of these
    # because it ships only the four short stages.
    print("  label definitions that break NAMING.md §1, per branch:\n")
    print(f"  {'class':<44}" + "".join(f"{b.split('_')[0]:>10}"
                                       for b in ALL_BRANCHES) + f"{'all':>8}")
    for _rx, label in FORBIDDEN:
        tot = sum(per[label].values())
        print(f"  {label:<44}" +
              "".join(f"{per[label][b]:>10}" for b in ALL_BRANCHES) +
              f"{tot:>8}")
    print("\n  the commonest shapes of the largest class, over all "
          "branches:\n")
    for shape, c in shapes["bare fold-local suffix _L<n>"].most_common(8):
        print(f"    {c:>4}  {shape}")
    print("\n  This is a census entry, not a task -- see the docstring. The "
          "suffix is a\n  uniquifier on a base that is itself mechanical, so "
          "the fix needs what the\n  rest of the backlog needs.")
    return 0


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--roles", action="store_true",
                    help="list the 828 placeholders internal to one named "
                         "routine, with the role their position gives them")
    ap.add_argument("--frames", action="store_true")
    ap.add_argument("--loops", action="store_true")
    ap.add_argument("--shapes", action="store_true",
                    help="per body shape: how many placeholders sit in it, "
                         "and what the tree already calls labels of that "
                         "shape in the same position")
    ap.add_argument("--forbidden", action="store_true",
                    help="the lint's forbidden-FORM classes: names that exist "
                         "but break NAMING.md §1, sized and diagnosed")
    args = ap.parse_args()

    if args.frames:
        return frames()
    if args.loops:
        return loops()
    if args.shapes:
        return shapes()
    if args.forbidden:
        return forbidden()

    tot, internal = census()
    if args.roles:
        per = collections.Counter(r for _k, _n, r in internal)
        # Keyed by (branch, stage, owner): the same routine name exists in
        # both ports and often in more than one stage, and counting those as
        # one owner made "has exactly one internal placeholder" read 549
        # instead of 124.
        owners = collections.Counter(k for k, _n, _r in internal)
        print(f"{len(internal)} placeholder(s) internal to one named routine\n")
        for r, c in per.most_common():
            print(f"  {c:>4}  {r}")
        one = sum(1 for c in owners.values() if c == 1)
        print(f"\n  {one} of {len(owners)} owners have exactly one, so "
              f"`<OWNER>_<ROLE>` would need no index")
        print("\n  the vocabulary that would have to be invented is the "
              "reason this is a census and not a renamer; see the docstring.")
        return 0

    for k, c in tot.most_common():
        print(f"{c:>7}  {k}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
