#!/usr/bin/env python3
"""A label that draws only frame <nn> is named the way its siblings are.

Question answered
-----------------
`../placeholder-census/` counts 7,594 placeholder labels and shows that 828 of
them are a position inside a named routine. This is a different and much
sharper slice of the same pile: **a label whose entire body draws frames of
one family, all carrying the same index**.

    LABEL_6B98:
            video type=0, offset=HERO_WALK_RIGHT_BODY_F10, x=[HERO_X], ...
            jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
            video offset=CINEMATIC_PRISON_HERO_WALK_RIGHT_ARM_F10, x=[HERO_X], ...
            ret

Both pictures say `F10`. Twelve lines below,
`PRISON_HERO_WALK_RIGHT_POSE_11` has the identical body with `F11`, and so do
POSE_12, 13, 14, 00..06 and 08. The label's name is not a judgement about what
the art depicts -- the art is already named -- it is the sibling convention
applied at the index the art states. That is `../draw-label-follows-constant/`
for the two-draw case, with the frame index doing the work the single picture
did there.

How the template is derived, not chosen
---------------------------------------
For a candidate drawing family `<FAM>` at index `nn`, collect every *other*
label in the same file whose body is the same shape and whose art is `<FAM>`
at some index `mm`, and which already has a semantic name. Split each of those
names into a prefix and a trailing index. If every sibling agrees on one
prefix **and** one zero-padding width, that template is the file's convention
for this family and it is applied at `nn`. If they disagree, nothing is
proposed -- there is no convention to follow.

The control
-----------
Every sibling is also a test of the template: hide a named sibling, derive the
template from the rest, and check it reproduces that sibling's actual name.
`--control` does exactly that for all of them and exits 1 on a disagreement.
It is the same shape of check as `../backdrop-drawer/ --control`: re-derive
what a person already wrote, from evidence they did not use. **127 of 127.**

The control is also what settled a design question rather than leaving it to
taste. Siblings are grouped by family *and* by the opcode shape of the body,
which looked like it might be over-strict. Dropping the shape from the key
takes the control from 127/127 to **21 of 27** -- PRISON holds both
`DRAW_HERO_WALK_RIGHT_F07` and `PRISON_HERO_WALK_RIGHT_POSE_07`-style names
for bodies of different shapes, and merging them makes each convention
contradict the other -- and it yields no extra proposals. The shape stays.

What it refuses
---------------
- a body whose art carries two different frame indices -- 41 of those exist
  and none of them is one frame;
- a family with fewer than two named siblings in that file, because one
  sibling is a coincidence, not a convention;
- a derived name already used in that file (#0118);
- a template whose prefix is itself a placeholder or carries a raw index or
  hex tail, reusing `../sole-named-drawer/`'s filters.

Usage
-----
    python3 notes/frame-label-siblings/sibling_template.py --control
    python3 notes/frame-label-siblings/sibling_template.py
    python3 notes/frame-label-siblings/sibling_template.py --proposals
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(SRC / "notes" / "sole-named-drawer"))
import nameable_from_drawer as N                             # noqa: E402

BRANCHES = ("chahi_amiga_1991", "dos_1992", "cartridge_1992", "gba_2004")

RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
PH = re.compile(r"^(LABEL_|JUNK__|RET_TARGET_|ADDR_AT_|KILL_CHAN_AT_)")
RE_V = re.compile(r"^\s*video\s+(?:type=\d+,\s*)?offset=([A-Za-z_]\w*)")
RE_END = re.compile(r"^\s*(ret\s*$|jmp\s|db 0x11\s*$)")
RE_F = re.compile(r"^(.*)_F(\d{1,2})$")
RE_TAIL = re.compile(r"^(.*?)_(\d{1,2})$")
STAGES = ("PRISON", "CAVES", "CAPSULE", "LAKE", "TANK", "INTRO", "ENDING",
          "CODE_WHEEL", "PASSCODE")


def art_role(family: str) -> str:
    """The family with its bank and stage scoping stripped off.

    A stage keeps its own copy of some shared-bank art, and the copy is named
    for the stage: `CINEMATIC_PRISON_HERO_WALK_RIGHT_ARM_F10` is the same
    limb, in the same pose slot, as `HERO_WALK_RIGHT_ARM_F11` one routine
    below. Grouping on the raw family string put those in different groups and
    the probe proposed nothing at all -- the very case that motivated it.
    `../cross-port-art/` already treats a stage-scoped copy as the same art;
    this is the same identity, applied to the name.
    """
    f = family
    for pre in ("CINEMATIC_", "CV_"):
        if f.startswith(pre):
            f = f[len(pre):]
    for st in STAGES:
        if f.startswith(st + "_"):
            f = f[len(st) + 1:]
            break
    return f


def parse(path: Path):
    """-> {label: (pictures, opcode shape)}, body ending at a terminator."""
    lines = path.read_text(errors="replace").splitlines()
    out: dict[str, tuple] = {}
    pics: list[str] = []
    ops: list[str] = []
    cur = None
    done = False
    for line in lines:
        m = RE_LBL.match(line)
        if m:
            if cur is not None:
                out[cur] = (pics, tuple(ops))
            cur, pics, ops, done = m.group(1), [], [], False
            continue
        if cur is None or done:
            continue
        s = line.strip()
        if not s:
            continue
        ops.append(s.split()[0])
        v = RE_V.match(line)
        if v:
            pics.append(v.group(1))
        if RE_END.match(line):
            done = True
    if cur is not None:
        out[cur] = (pics, tuple(ops))
    return out


def one_frame(pics):
    """(family, index) when every picture is that family at one index."""
    if not pics:
        return None
    fams, idxs = set(), set()
    for p in pics:
        m = RE_F.match(p)
        if not m:
            return None
        fams.add(art_role(m.group(1)))
        idxs.add(int(m.group(2)))
    if len(idxs) != 1:
        return None
    return (tuple(sorted(fams)), next(iter(idxs)))


def usable_prefix(prefix: str) -> bool:
    if PH.match(prefix) or not prefix:
        return False
    if any(m in prefix for m in N.MECHANISM):
        return False
    return not (N.RE_RAWINDEX.search(prefix) or N.RE_HEXTAIL.search(prefix)
                or N.RE_THRESHOLD.search(prefix))


def template(siblings):
    """One (prefix, width) if every sibling agrees, else None.

    `siblings` is [(label name, index)]. A convention has to be unanimous:
    two labels of the same family named `X_10` and `Y_11` state no rule, and
    `X_1` beside `X_02` states no padding.
    """
    seen = set()
    for name, idx in siblings:
        m = RE_TAIL.match(name)
        if not m or int(m.group(2)) != idx:
            return None
        seen.add((m.group(1), len(m.group(2))))
    if len(seen) != 1:
        return None
    prefix, width = next(iter(seen))
    return (prefix, width) if usable_prefix(prefix) else None


def collect():
    """-> per file, the frame-labels grouped by (family, body shape)."""
    for branch in BRANCHES:
        for path in sorted((SRC / "src" / "levels" / branch).glob("*.asm")):
            groups: dict[tuple, list] = collections.defaultdict(list)
            taken = set()
            for lab, (pics, shape) in parse(path).items():
                taken.add(lab)
                k = one_frame(pics)
                if k is None:
                    continue
                groups[(k[0], shape)].append((lab, k[1]))
            yield branch, path, groups, taken


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--control", action="store_true",
                    help="hide each named sibling in turn and check the "
                         "template derived from the rest reproduces its name")
    ap.add_argument("--proposals", action="store_true")
    args = ap.parse_args()

    if args.control:
        ok = bad = 0
        misses = []
        for branch, path, groups, _taken in collect():
            for (fam, _shape), members in groups.items():
                named = [(n, i) for n, i in members if not PH.match(n)]
                if len(named) < 3:
                    continue
                for held_out in named:
                    rest = [m for m in named if m is not held_out]
                    t = template(rest)
                    if t is None:
                        continue
                    got = f"{t[0]}_{held_out[1]:0{t[1]}d}"
                    if got == held_out[0]:
                        ok += 1
                    else:
                        bad += 1
                        misses.append((branch, path.stem, fam[0],
                                       held_out[0], got))
        for m in misses[:20]:
            print(f"  {m[0]:<18}{m[1]:<9}{m[2]:<34}is {m[3]}, template "
                  f"says {m[4]}")
        print(f"\n  {ok} sibling(s) reproduced, {bad} not")
        return 1 if bad else 0

    props: dict[tuple, list] = collections.defaultdict(list)
    held = collections.Counter()
    for branch, path, groups, taken in collect():
        for (fam, _shape), members in groups.items():
            ph = [(n, i) for n, i in members if PH.match(n)]
            named = [(n, i) for n, i in members if not PH.match(n)]
            if not ph:
                continue
            if len(named) < 2:
                held["fewer than two named siblings of the same shape"] += len(ph)
                continue
            t = template(named)
            if t is None:
                held["the named siblings agree on no one template"] += len(ph)
                continue
            for lab, idx in ph:
                new = f"{t[0]}_{idx:0{t[1]}d}"
                if new in taken:
                    held["the derived name is already used in that file"] += 1
                    continue
                props[(branch, path.stem)].append(
                    (lab, new, fam, idx, len(named)))
                taken.add(new)

    if args.proposals:
        for (branch, stage), rows in sorted(props.items()):
            print(f"\n----- {branch} / {stage} -----")
            print("| routine | proposed name | confidence | evidence |")
            print("| --- | --- | --- | --- |")
            for lab, new, fam, idx, n in sorted(rows, key=lambda r: r[1]):
                print(f"| {lab} | {new} | high | every picture it draws is "
                      f"frame {idx} of {' + '.join(fam)}, and {n} other "
                      f"label(s) in this file with the same body shape draw "
                      f"other frames of it and are all named "
                      f"`<prefix>_<index>` on one prefix; the index is the "
                      f"one the art itself states |")
        return 0

    n = sum(len(v) for v in props.values())
    print(f"{n} placeholder(s) nameable from their siblings\n")
    for k, v in sorted(props.items()):
        print(f"  {k[0]:<18}{k[1]:<10}{len(v):>3}")
    print()
    for why, c in held.most_common():
        print(f"  held: {c:>4}  {why}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
