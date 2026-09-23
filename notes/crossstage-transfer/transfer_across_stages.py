#!/usr/bin/env python3
"""Name a constant from the same picture already named in another STAGE.

Question answered
-----------------
`notes/crossport-transfer/` carries a name between **ports** when the art is
byte-identical. The same move works between **stages** of one port, and
nothing was doing it: the cinematic banks share art -- a droplet, a teleport
beam, the hero lifting off -- and a picture identified in CAVES is the same
picture in PRISON.

`notes/shot-hit-burst/` is the case that prompted this. CAPSULE's five-frame
spark was stuck behind a routine-family gap while PRISON had the identical
five frames under a complete constant family; transferring by
`canonical_md5` named all ten in each port. That was done by hand. This
generalises it.

The filters, and how much each removes
--------------------------------------
Matching alone gives 49 candidates on amiga and 46 on msdos. Most are not
usable and the reasons are worth the counts. (These counts are from
2026-09-19 and the tree has moved; re-run rather than cite them.)

  36 / 34  **the name carries another stage's prefix.**
           `CINEMATIC_CAVES_TELEPORT_DOWN_BEAM` moved into PRISON asserts
           CAVES inside PRISON. The art travels between stages; the stage
           word does not. Held, not rewritten -- stripping `CAVES_` and
           re-prefixing would invent a name nobody earned.
   6 / 7   **several constants in the target stage match one name** (#0118).
           Six amiga/INTRO constants are byte-identical to
           `CINEMATIC_DROPLET_FALL_TRAIL`; one name cannot go on six.
   0 / 0   the name is already used in the target stage.
  35 / 36  the art matches two or more *different* names elsewhere, so there
           is nothing to transfer (#0120).

  7 / 5    nameable.

A constant **referenced from an all-branch chunk** is held too. The EQU is
renamed per branch, and an unprefixed `_unified/<stage>/*.inc` is read by
every branch -- so renaming amiga's and msdos's definitions while cartridge
keeps `CINEMATIC_555` leaves that shared reference undefined for the two
that moved. `prison_step_draws_and_breaks.inc` naming `CINEMATIC_555` is the
case that found this: verify-unified 27/29 with two undefined references,
while verify-stages stayed 29/29 because each canonical file was internally
consistent.

**The check reads the guard, not the filename (fixed 2026-09-23).** An
unprefixed chunk is *read* by every branch, but the lines inside it are
usually fenced:

    .if BRANCH in ("chahi_amiga_1991", "dos_1992")
    DRAW_CIN_284_BLOCK_95B:
            video offset=CINEMATIC_284, x=[HERO_X], y=[HERO_Y]

Judging by the filename alone held **36 constants** that no other branch ever
compiles -- PRISON's 28 copies of `CINEMATIC_TUMBLING_CHUNK_*` and CAVES' 8 of
`CINEMATIC_WIDE_FLASH_*`. `guarded_branches()` now walks the `.if` / `.elif` /
`.endif` nesting down to the line and returns the branch set in force.

The two cases are one command apart:

    python3 notes/crossstage-transfer/transfer_across_stages.py --guards CINEMATIC_284
    #   prison/prison_inline_setters_and_init.inc:466
    #       SHARED chunk -> compiled for: chahi_amiga_1991, dos_1992

    python3 notes/crossstage-transfer/transfer_across_stages.py --guards CINEMATIC_008
    #   caves/caves_inline_setters_and_init.inc:570
    #       SHARED chunk -> compiled for: cartridge_1992, chahi_amiga_1991, dos_1992

284 is safe for the priority ports and 008 is not, and the 8 CAVES ones stay
held. The control is the gate itself: after renaming the 28, `make test` was
29/29 on **both** halves. A wrong guard walk would have shown up exactly as
the 27/29-unified-with-29/29-canonical split described above.

A name on `disputed.txt` is skipped whatever its evidence:
`CINEMATIC_BUDDY_SMASHING_WINDOW_F8` is recorded in
`../render-attempts/README.md` as art whose own subject is in doubt -- the
routine tiles a beam while the polygon claims to be the alien breaking a
window -- and transferring it would spread a disputed claim.

Signals read
------------
`CINEMATIC_* EQU 0x...` in `src/levels/<branch>/<STAGE>.asm`, and
`canonical_md5(parse_polygon_tree(...))` over that stage's slice of
`cinematic.rom`. Ports without an extracted ROM are skipped and named.

Usage
-----
    python3 notes/crossstage-transfer/transfer_across_stages.py
    python3 notes/crossstage-transfer/transfer_across_stages.py --proposals DIR
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
sys.path.insert(0, str(HERE.parents[1] / "polygon-extent-correction"))
from polygon_tree import parse_polygon_tree, canonical_md5   # noqa: E402
from extent_matches_renderer import slab                     # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992"}
SID = {"CODE_WHEEL": 0, "INTRO": 1, "LAKE": 2, "PRISON": 3, "CAVES": 4,
       "TANK": 5, "CAPSULE": 6, "ENDING": 7, "PASSCODE": 8}
RE_EQU = re.compile(r"^(\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)", re.M)
RE_NUM = re.compile(r"^CINEMATIC_\d+$")
DISPUTED = HERE.parent / "disputed.txt"

EVIDENCE = (
    "Cross-stage transfer by art identity. The same picture is already "
    "named in another stage of this port, matched by canonical_md5 over the "
    "whole parsed tree, not by index. The carried name has no foreign stage "
    "prefix, no other constant in this stage matches it, and the art matches "
    "exactly one named constant anywhere -- so there is one subject and one "
    "target.")


PRIORITY = {"chahi_amiga_1991", "dos_1992"}
RE_IF = re.compile(r'^\.(if|elif|endif)\b(.*)$')
RE_BRANCHNAME = re.compile(r'"([a-z_0-9]+)"')


def guarded_branches(lines: list[str], i: int) -> set | None:
    """Which branches compile line `i`? None means "every branch".

    A chunk with no `__` in its name is read by every branch, but the lines
    INSIDE it are usually fenced:

        .if BRANCH in ("chahi_amiga_1991", "dos_1992")
        DRAW_CIN_284_BLOCK_95B:
                video offset=CINEMATIC_284, x=[HERO_X], y=[HERO_Y]

    Judging such a reference by its file alone calls it all-branch and holds
    the constant. Measured 2026-09-23 that was **36 constants** -- PRISON's 28
    copies of the tumbling chunk and CAVES' 8 of the wide flash -- every one
    of them fenced to amiga and dos, with the other branches drawing their own
    copies from their own `cart__*` and `gba__*` chunks.

    This walks the `.if` / `.elif` / `.endif` nesting down to the line and
    returns the branch set in force, or None where nothing fences it.
    """
    stack: list = []
    for n, line in enumerate(lines):
        if n >= i:
            break
        m = RE_IF.match(line.strip())
        if not m:
            continue
        kind, rest = m.group(1), m.group(2)
        if kind == "endif":
            if stack:
                stack.pop()
            continue
        names = set(RE_BRANCHNAME.findall(rest))
        if kind == "elif" and stack:
            stack.pop()
        stack.append(names or None)
    out = None
    for s_ in stack:
        if s_ is None:
            continue
        out = s_ if out is None else (out & s_)
    return out


def reaches_other_branches(f, const: str) -> bool:
    """Does any line of `f` naming `const` compile for a non-priority branch?"""
    lines = f.read_text(errors="replace").splitlines()
    pat = re.compile(rf"\b{re.escape(const)}\b")
    for i, line in enumerate(lines):
        if not pat.search(line):
            continue
        g = guarded_branches(lines, i)
        if g is None or (g - PRIORITY):
            return True
    return False


def show_guards(const: str) -> int:
    root = SRC / "src" / "levels" / "_unified"
    pat = re.compile(rf"\b{re.escape(const)}\b")
    n = 0
    for f in sorted(root.rglob("*.inc")):
        lines = f.read_text(errors="replace").splitlines()
        for i, line in enumerate(lines):
            if not pat.search(line):
                continue
            g = guarded_branches(lines, i)
            own = "__" in f.name
            scope = ("every branch" if g is None else
                     ", ".join(sorted(g)) if g else "(empty guard)")
            print(f"  {f.relative_to(root)}:{i + 1}")
            print(f"      {'branch chunk ' if own else 'SHARED chunk '}"
                  f"-> compiled for: {scope}")
            n += 1
    print(f"\n  {n} reference(s). A SHARED chunk line compiled for anything "
          f"outside\n  {sorted(PRIORITY)} is what holds the constant.")
    return 0


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--proposals", type=Path)
    ap.add_argument("--guards", metavar="CONST",
                    help="print, for every shared chunk naming this constant, "
                         "the branch set that compiles the line -- the check "
                         "the all-branch hold is made on")
    ap.add_argument("--held", action="store_true",
                    help="name every held candidate, not just count it")
    args = ap.parse_args()

    if args.guards:
        return show_guards(args.guards)

    disputed = set()
    if DISPUTED.is_file():
        disputed = {l.split("#")[0].strip()
                    for l in DISPUTED.read_text().splitlines()
                    if l.split("#")[0].strip()}

    why = collections.Counter()
    # Every hold also records WHICH candidate was held. Counting alone made a
    # real finding invisible: an audit went looking for
    # `CINEMATIC_555 -> CINEMATIC_HERO_FALL_PRELUDE_FRAME` in a scratch file
    # because this probe computed it from HEAD and then dropped the name on
    # the floor, leaving only "1 held: referenced from an all-branch chunk".
    # A reason with no subject cannot be acted on or checked.
    held: list[tuple[str, str, str, str, str]] = []
    out: list[tuple] = []
    for port, br in PORTS.items():
        named: dict[str, set] = {}
        unnamed: list = []
        taken: dict[str, set] = collections.defaultdict(set)
        for stage, sid in SID.items():
            f = SRC / "src" / "levels" / br / f"{stage}.asm"
            if not f.is_file():
                continue
            try:
                bank = slab("cinematic", port, sid)
            except BaseException:
                held.append((f"{port}: no extracted ROM", port, stage, k, ""))
                why[f"{port}: no extracted ROM"] += 1
                continue
            for k, v in RE_EQU.findall(f.read_text(errors="replace")):
                if not k.startswith("CINEMATIC_"):
                    continue
                taken[stage].add(k)
                tree = parse_polygon_tree(bank, int(v, 16))
                if tree is None:
                    continue
                m = canonical_md5(tree)
                if RE_NUM.match(k):
                    unnamed.append((stage, k, m))
                else:
                    named.setdefault(m, set()).add((stage, k))
        prop: dict[tuple, list] = collections.defaultdict(list)
        for stage, k, m in unnamed:
            cand = {n for s2, n in named.get(m, ()) if s2 != stage}
            if len(cand) != 1:
                if cand:
                    held.append((f"{port}: art matches two or more names", port, stage, k, "/".join(sorted(cand))))
                    why[f"{port}: art matches two or more names"] += 1
                continue
            name = next(iter(cand))
            body = name[len("CINEMATIC_"):]
            if any(body.startswith(s + "_") and s != stage for s in SID):
                held.append((f"{port}: name carries another stage's prefix", port, stage, k, name))
                why[f"{port}: name carries another stage's prefix"] += 1
                continue
            if name in taken[stage]:
                held.append((f"{port}: name already used in the target stage", port, stage, k, name))
                why[f"{port}: name already used in the target stage"] += 1
                continue
            if name in disputed:
                held.append((f"{port}: name is on disputed.txt", port, stage, k, name))
                why[f"{port}: name is on disputed.txt"] += 1
                continue
            arms = SRC / "src" / "levels" / "_unified" / stage.lower()
            shared = [f for f in arms.rglob("*.inc")] if arms.is_dir() else []
            if any(not "__" in f.name and reaches_other_branches(f, k)
                   for f in shared):
                held.append((f"{port}: referenced from an all-branch chunk", port, stage, k, name))
                why[f"{port}: referenced from an all-branch chunk"] += 1
                continue
            prop[(stage, name)].append(k)
        for (stage, name), ks in prop.items():
            if len(ks) > 1:
                for kk in ks:
                    held.append((f"{port}: several constants would take one "
                                 f"name (#0118)", port, stage, kk, name))
                why[f"{port}: several constants would take one name "
                    f"(#0118)"] += len(ks)
                continue
            out.append((port, stage, ks[0], name))

    print(f"{len(out)} constant(s) nameable by cross-stage art identity\n")
    for k, v in sorted(why.items()):
        print(f"  {v:4d}  held: {k}")
    if args.held:
        print("\nheld candidates, named (--held):")
        for reason, port, stage, k, name in sorted(held):
            print(f"  {port}/{stage:<10}{k:<18} -> {name or '(no candidate)':<44}"
                  f"  {reason.split(': ', 1)[1]}")
    print()
    for port, stage, k, name in sorted(out):
        print(f"  {port}/{stage:<10}{k:<18} -> {name}")

    if args.proposals:
        args.proposals.mkdir(parents=True, exist_ok=True)
        per: dict[tuple, list] = collections.defaultdict(list)
        for port, stage, k, name in out:
            per[(port, stage)].append((k, name))
        for (port, stage), rows in per.items():
            f = args.proposals / f"xstage_{port}_{stage}.md"
            with f.open("w") as fh:
                fh.write("| constant | proposed name | confidence | "
                         "evidence |\n| --- | --- | --- | --- |\n")
                for k, name in rows:
                    fh.write(f"| {k} | {name} | high | {EVIDENCE} |\n")
            print(f"wrote {f}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
