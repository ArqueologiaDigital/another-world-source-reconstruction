#!/usr/bin/env python3
"""Does a VM variable mean the same thing everywhere it is used?

Question answered
-----------------
A name like `ACTOR_X` on a VM variable is a claim, and the interpreter makes no
such claim: it has 256 signed words and the bytecode puts whatever it likes in
them. If a stage names `0x07` after a character while another stage uses the same
word to position falling debris, then the name is **stage-local** -- true where it
is asserted and meaningless outside it -- and reading it as a global fact is how
art gets attributed to the wrong actor.

This measures three things that together say whether a name travels:

1. **Which stages name the variable, and which use it raw.** A stage that uses
   it heavily without naming it is using it for something else.
2. **Scarcity**, because it is the reason to expect re-tasking at all: how many
   of the 256 words each stage actually touches. A register file that is nearly
   full has to be reused.
3. **Within one stage**, where the variable is WRITTEN and where it is read as a
   draw anchor, as line clusters -- so a re-tasking inside a single stage shows
   up as two groups of writers with a gap between them.

It does not decide anything. Deciding needs the scene, which a person reads off
the listing; this says where to look and how strong the suspicion should be.

Signal read
-----------
`src/levels/<branch>/<STAGE>.asm`: `[0xNN]` for raw uses, `NAME EQU 0xNN` with a
one- or two-digit value for variable names (art constants are four digits),
`mov`/`add`/`sub`/`and`/`or`/`shl`/`shr`/`djnz` for writes, and
`video ... x=[..], y=[..]` for anchor reads.

Run it
    python3 notes/actor-anchors/var_retasking.py --var ACTOR_X
    python3 notes/actor-anchors/var_retasking.py --var 0x07 --stage PRISON
    python3 notes/actor-anchors/var_retasking.py --scarcity
"""
from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
WRITE = re.compile(
    r"^\t(mov|add|sub|and|or|shl|shr|djnz)\s+\[([0-9A-Za-z_]+)\](?:,\s*(.*))?$")
RE_VAR_EQU = re.compile(r"^(\w+)\s+EQU\s+(0x[0-9A-Fa-f]{1,2})\s*$", re.M)
RE_ANCHOR = re.compile(r"^\tvideo (?:type=\d+, )?offset=(\w+), "
                       r"x=\[(\w+)\], y=\[(\w+)\]", re.M)


def stages(branch: str):
    d = ROOT / "src" / "levels" / branch
    return sorted(p for p in d.glob("*.asm")) if d.is_dir() else []


def var_map(text: str) -> dict[str, int]:
    return {n: int(v, 16) for n, v in RE_VAR_EQU.findall(text)}


def used_vars(text: str) -> set[int]:
    raw = {int(m, 16) for m in re.findall(r"\[0x([0-9A-Fa-f]{1,2})\]", text)}
    vm = var_map(text)
    named = {vm[n] for n in vm if re.search(rf"\[{n}\]", text)}
    return raw | named


def clusters(lines: list[int], gap: int = 400):
    """Group line numbers into runs separated by more than `gap` lines."""
    out = []
    for n in sorted(lines):
        if out and n - out[-1][-1] <= gap:
            out[-1].append(n)
        else:
            out.append([n])
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--branch", default="dos_1992")
    ap.add_argument("--var", help="a name like ACTOR_X, or a number like 0x07")
    ap.add_argument("--stage", help="restrict the within-stage report")
    ap.add_argument("--scarcity", action="store_true")
    a = ap.parse_args()

    if a.scarcity or not a.var:
        print(f"distinct VM variables touched, of 256 ({a.branch})")
        union: set[int] = set()
        for f in stages(a.branch):
            u = used_vars(f.read_text(errors="replace"))
            union |= u
            print(f"  {f.stem:<12} {len(u):3d}")
        print(f"  {'UNION':<12} {len(union):3d}")
        print("\n  A register file this full has to be reused, which is the "
              "reason to\n  expect a variable's meaning to be local to a "
              "stage or even a scene.")
        if not a.var:
            return 0
        print()

    # resolve the variable to a number, using whichever stage names it
    num = None
    namers: dict[str, str] = {}
    if a.var.lower().startswith("0x"):
        num = int(a.var, 16)
    for f in stages(a.branch):
        vm = var_map(f.read_text(errors="replace"))
        if a.var in vm:
            namers[f.stem] = a.var
            num = vm[a.var]
    if num is None:
        print(f"no stage of {a.branch} names {a.var}", file=sys.stderr)
        return 2
    print(f"{a.var} = 0x{num:02X} in {a.branch}")

    # 1. who names it, who uses it raw
    print("\n  stage        names it   uses [0x%02X]   as a draw anchor" % num)
    for f in stages(a.branch):
        t = f.read_text(errors="replace")
        vm = var_map(t)
        names = [n for n, v in vm.items() if v == num]
        raw = len(re.findall(rf"\[0x0*{num:X}\]", t, re.I))
        anch = sum(1 for m in RE_ANCHOR.finditer(t)
                   if num in (vm.get(m.group(2)), vm.get(m.group(3)))
                   or m.group(2).lower() == f"0x{num:02x}"
                   or m.group(3).lower() == f"0x{num:02x}")
        nm = ",".join(names) if names else "-"
        print(f"  {f.stem:<12} {nm:<10} {raw:5d}        {anch:5d}")
    print("\n  A stage that uses it heavily and names it something else -- or "
          "nothing --\n  is using the same word for another purpose. The name "
          "is stage-local.")

    # 3. within one stage
    for f in stages(a.branch):
        if a.stage and f.stem != a.stage:
            continue
        t = f.read_text(errors="replace")
        vm = var_map(t)
        alias = {n for n, v in vm.items() if v == num} | {f"0x{num:02X}",
                                                         f"0x{num:02x}"}
        writes, anchors = [], []
        for i, ln in enumerate(t.splitlines(), 1):
            m = WRITE.match(ln)
            if m and m.group(2) in alias:
                writes.append((i, m.group(1), (m.group(3) or "").strip()))
            m = RE_ANCHOR.match(ln)
            if m and (m.group(2) in alias or m.group(3) in alias):
                anchors.append(i)
        if not writes and not anchors:
            continue
        print(f"\n  {f.stem}: {len(writes)} write(s), "
              f"{len(anchors)} anchor draw(s)")
        cw = clusters([i for i, _, _ in writes])
        ca = clusters(anchors)
        print(f"    write clusters ({len(cw)}):  " +
              ", ".join(f"{c[0]}-{c[-1]}" for c in cw[:8]))
        print(f"    anchor clusters ({len(ca)}): " +
              ", ".join(f"{c[0]}-{c[-1]}" for c in ca[:8]))
        if len(ca) > 1:
            print("    More than one anchor cluster: candidate scenes. Feed "
                  "their ranges to\n    shared_actor_art.py --scene to ask "
                  "whether they share any art.")
        src = collections.Counter(op for _, op, _ in writes)
        print("    written by: " + ", ".join(f"{k} x{v}" for k, v in
                                             src.most_common()))
    return 0


if __name__ == "__main__":
    sys.exit(main())
