#!/usr/bin/env python3
"""Two ports name one routine differently. Are the bodies even the same?

Question answered
-----------------
`another-world-archaeology/tools/align_branch_names.py` pairs routines between
two branches by instruction stream and sorts each pair into agree / gain /
backport / conflict. **conflict** means both sides carry a semantic name and
the names differ, and the tool deliberately refuses to arbitrate -- #0120: a
tool must not pick a winner between two names a person wrote.

Run amiga -> gba_2004 on LAKE it reports 26 of them, and some of the pairs look
like nonsense: `FIRST_SCREEN_R_BEAST_TRIGGER` against `CYCLE_VIDEO_PAGES_2WAY`,
`IF_BEAST_NEAR_THEN_REACT_ELSE_KILL_THREAD` against
`SLUG_DISPATCH_PHASE1_F6_DEATH`. Two readings, with opposite consequences:

  * the **alignment** is wrong -- the matcher paired routines that are not
    counterparts, and the conflicts are an artefact. Then nothing is wrong
    with the names and the tool needs fixing.
  * the alignment is right and **one of the two names is wrong**. Then there
    are wrong names in the tree that the byte gate cannot see, because a
    label name is not a byte.

Those are distinguished by one cheap fact: whether the two bodies are the
same. This prints, per conflicting pair, the two bodies and whether they are
identical after masking operands that are allowed to differ between ports
(polygon symbols, which each branch keys to its own offset).

The trap it now flags: STRUCTURAL, not synonymous
--------------------------------------------------
An identical body does **not** mean an identical role, and that mistake cost
one wrong rename on 2026-09-19 before it was caught.

amiga's `HERO_AI_DISPATCH` has byte-for-byte the body that cartridge, dos and
gba call `HERO_AI_DISPATCH_AIRBORNE`, so it looks like amiga is using a name
that is too general. It is not.
`src/levels/_unified/lake/hero_ai_dispatch_airborne.inc` puts
`HERO_AI_DISPATCH:` *before* a `.if BRANCH in ("cartridge_1992", "dos_1992",
"gba_2004")` block ending in the label `HERO_AI_DISPATCH_AIRBORNE:`. amiga
skips that block, so its single label falls straight through to the airborne
body. The other ports have two labels because they have an extra ground arm,
not because amiga's is misnamed -- and all four ports do
`setup channel=0x16, address=<the AI entry>`, which on amiga is this code. On
amiga the routine **is** the dispatcher.

So the probe reports a pair as `STRUCTURAL` when the other side also defines
the name in question -- the target also defines the ref's name, or the ref
also defines the target's. That means the two ports disagree about which
routine wears the name, or one port has a routine the other lacks, and the
pair cannot be settled by looking at the shared body alone. It is a warning to
go and read the other definition, which is exactly the step that was skipped.

What it does not do
-------------------
It does not choose. Choosing is reading each body and asking which name the
code supports, which is the thing #0120 reserves for a person. This gets the
pairs onto one page with the evidence attached so that reading is possible at
all.

Usage
-----
    python3 notes/cross-port-name-conflicts/conflict_dossier.py
    python3 notes/cross-port-name-conflicts/conflict_dossier.py \
        --ref amiga --target gba_usa --stage LAKE --bodies
"""
from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels"
PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992",
         "snes_eu": "cartridge_1992", "gba_usa": "gba_2004"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]

RE_LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
RE_POLY = re.compile(r"\b(?:CINEMATIC|COMMON_VIDEO)_[A-Za-z0-9_]+\b")


def bodies(path: Path) -> dict[str, list[str]]:
    out: dict[str, list[str]] = {}
    cur = None
    for raw in path.read_text(errors="replace").splitlines():
        line = raw.split(";", 1)[0]
        m = RE_LABEL.match(line)
        if m:
            cur = m.group(1)
            out.setdefault(cur, [])
            continue
        if cur is not None and line.strip():
            out[cur].append(" ".join(line.split()))
    return out


def norm(body: list[str]) -> tuple[str, ...]:
    """Body with polygon symbols masked -- those legitimately differ."""
    return tuple(RE_POLY.sub("<poly>", l) for l in body)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--ref", default="amiga", choices=sorted(PORTS))
    ap.add_argument("--target", default="gba_usa", choices=sorted(PORTS))
    ap.add_argument("--stage", action="append")
    ap.add_argument("--bodies", action="store_true")
    args = ap.parse_args()
    stages = args.stage or STAGES

    for stage in stages:
        rp = SRC / PORTS[args.ref] / f"{stage}.asm"
        tp = SRC / PORTS[args.target] / f"{stage}.asm"
        if not (rp.is_file() and tp.is_file()):
            continue
        rb, tb = bodies(rp), bodies(tp)

        # Pair by identical normalised body. Only bodies that occur exactly
        # once on each side are safe to pair this way; anything ambiguous is
        # reported as such rather than guessed.
        ridx: dict[tuple, list[str]] = collections.defaultdict(list)
        tidx: dict[tuple, list[str]] = collections.defaultdict(list)
        for n, b in rb.items():
            if b:
                ridx[norm(b)].append(n)
        for n, b in tb.items():
            if b:
                tidx[norm(b)].append(n)

        same = diff = ambig = 0
        rows = []
        for key, rnames in ridx.items():
            tnames = tidx.get(key)
            if not tnames:
                continue
            if len(rnames) != 1 or len(tnames) != 1:
                ambig += 1
                continue
            r, t = rnames[0], tnames[0]
            if r == t:
                same += 1
                continue
            diff += 1
            structural = (r in tb and tb[r]) or (t in rb and rb[t])
            rows.append((r, t, key, bool(structural)))

        print(f"\n=== {args.ref} vs {args.target} / {stage}")
        print(f"  {same} routine(s) with an identical body AND the same name")
        print(f"  {diff} with an identical body and DIFFERENT names")
        print(f"  {ambig} body shape(s) not uniquely pairable, skipped")
        nstruct = sum(1 for _r, _t, _k, st in rows if st)
        if nstruct:
            print(f"  of those, {nstruct} STRUCTURAL -- the other port also "
                  f"defines the name, so\n    the ports differ in shape, not "
                  f"just in wording; read both definitions")
        for r, t, key, st in sorted(rows):
            print(f"\n  {args.ref:>8}: {r}")
            print(f"  {args.target:>8}: {t}")
            tag = "  STRUCTURAL" if st else ""
            print(f"            bodies identical, {len(key)} line(s){tag}")
            if st:
                where = []
                if r in tb and tb[r]:
                    where.append(f"{args.target} also defines {r}")
                if t in rb and rb[t]:
                    where.append(f"{args.ref} also defines {t}")
                print(f"            {'; '.join(where)}")
            if args.bodies:
                for l in key:
                    print(f"              {l}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
