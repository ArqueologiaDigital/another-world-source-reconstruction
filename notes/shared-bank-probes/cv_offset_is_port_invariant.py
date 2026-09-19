#!/usr/bin/env python3
"""Is the shared video bank really the same on every port?

Question answered
-----------------
Plan item **T7** is the largest single blocker in the routine backlog.
`notes/caller-derived-naming/what_blocks_the_rest.py` measures it: 900
reachable unnamed routines draw only shared-bank art and 247 more do that and
hit #0138 as well. `docs/NAMING.md` §2 says why they cannot be named and what
would unblock them:

    **The shared bank (`COMMON_VIDEO_NNN`) has no semantic names at all** ...
    Its numbering is worse than arbitrary: it is the order the disassembler
    happened to encounter entries across a whole `all_levels` run ... Before
    these can be named, the emitter must key them by offset (plan item T7) and
    the existing names must move to an interim port-invariant `CV_<OFFSET4>` --
    **the bank is byte-identical between Amiga and MS-DOS, so one name per
    offset is correct.** Until that lands, do not hand-name `COMMON_VIDEO_NNN`.

The whole design rests on the sentence in bold. If it is false, keying by
offset produces a name that means different art on different ports, and T7
would bake in the very error #0107 exists to prevent -- at the scale of the
entire bank.

It had not been checked. This checks it.

How
---
Indices are per-port encounter order, so `COMMON_VIDEO_074` on amiga and on
msdos are unrelated labels. **Offsets** are the claim. So:

1. Pair routines between two ports by **identical body**, with every
   `CINEMATIC_*` and `COMMON_VIDEO_*` symbol masked, and keep only bodies that
   occur exactly once on each side. Those pairs are the same routine.
2. For each pair, walk the `video ... offset=COMMON_VIDEO_<n>` operands in
   order and resolve each side's symbol through its own port's EQU table.
3. The two offset sequences must be equal, position by position.

A pair whose sequences differ is a counterexample to the bold sentence -- **if
the pairing is trustworthy**. That qualifier is load-bearing and was nearly
skipped. A two-line body like

    video type=0, offset=<poly>, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
    ret

is the most generic shape in the tree; two routines sharing it are not thereby
the same routine, even when the body happens to be unique on each side. So
pairs are split by body length and only those of **three lines or more** count
as evidence either way. Run over amiga vs msdos that is 71 agreements and no
disagreement; the sole disagreement in the whole tree is a two-line pair
(`DRAW_HERO_POSE_0_0` against `DRAW_CV_298` in CAPSULE), which is reported as
an untrustworthy pairing rather than as a refutation.

The test only sees offsets both ports actually draw from a shared routine, so
it cannot prove the whole bank identical -- it can only fail to refute it over
the part the game uses. That is stated rather than glossed: `--coverage`
prints how many distinct offsets the agreeing pairs touch, against how many
the port defines.

Exit status
-----------
0 if no **load-bearing** pair disagrees, 1 otherwise. Short-body
disagreements are always printed, and never fail the run.

Usage
-----
    python3 notes/shared-bank-probes/cv_offset_is_port_invariant.py
    python3 notes/shared-bank-probes/cv_offset_is_port_invariant.py --coverage
    python3 notes/shared-bank-probes/cv_offset_is_port_invariant.py \
        --ref amiga --target snes_eu
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
RE_EQU = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s+(0x[0-9A-Fa-f]+)\s*$")
RE_POLY = re.compile(r"\b(?:CINEMATIC|COMMON_VIDEO)_[A-Za-z0-9_]+\b")
RE_CV_OPERAND = re.compile(r"offset=(COMMON_VIDEO_[A-Za-z0-9_]+)")

# Below this, "same body" does not establish "same routine": a lone
# `video ...; ret` is the most generic shape in the tree.
MIN_BODY = 3


def parse(path: Path):
    equs, bodies, cur = {}, {}, None
    for raw in path.read_text(errors="replace").splitlines():
        line = raw.split(";", 1)[0]
        m = RE_EQU.match(line)
        if m:
            equs[m.group(1)] = int(m.group(2), 16)
            continue
        m = RE_LABEL.match(line)
        if m:
            cur = m.group(1)
            bodies.setdefault(cur, [])
            continue
        if cur is not None and line.strip():
            bodies[cur].append(" ".join(line.split()))
    return equs, bodies


def norm(body): return tuple(RE_POLY.sub("<poly>", l) for l in body)


def cv_offsets(body, equs):
    out = []
    for l in body:
        for sym in RE_CV_OPERAND.findall(l):
            out.append(equs.get(sym))
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--ref", default="amiga", choices=sorted(PORTS))
    ap.add_argument("--target", action="append", choices=sorted(PORTS))
    ap.add_argument("--stage", action="append")
    ap.add_argument("--coverage", action="store_true")
    args = ap.parse_args()
    targets = args.target or [p for p in ("msdos", "snes_eu", "gba_usa")
                              if p != args.ref]
    stages = args.stage or STAGES

    bad = 0
    for tgt in targets:
        agree = disagree = pairs = unresolved = 0
        strong_agree = weak_disagree = 0
        touched: set[int] = set()
        defined: set[int] = set()
        for stage in stages:
            rp = SRC / PORTS[args.ref] / f"{stage}.asm"
            tp = SRC / PORTS[tgt] / f"{stage}.asm"
            if not (rp.is_file() and tp.is_file()):
                continue
            re_, rb = parse(rp)
            te_, tb = parse(tp)
            defined |= {v for k, v in re_.items()
                        if k.startswith("COMMON_VIDEO_")}
            ri, ti = collections.defaultdict(list), collections.defaultdict(list)
            for n, b in rb.items():
                if b:
                    ri[norm(b)].append(n)
            for n, b in tb.items():
                if b:
                    ti[norm(b)].append(n)
            for key, rn in ri.items():
                tn = ti.get(key)
                if not tn or len(rn) != 1 or len(tn) != 1:
                    continue
                ro = cv_offsets(rb[rn[0]], re_)
                to = cv_offsets(tb[tn[0]], te_)
                if not ro:
                    continue
                pairs += 1
                if None in ro or None in to:
                    unresolved += 1
                    continue
                strong = len(key) >= MIN_BODY
                if ro == to:
                    agree += 1
                    if strong:
                        strong_agree += 1
                    touched |= set(ro)
                else:
                    disagree += 1
                    if strong:
                        bad += 1
                    else:
                        weak_disagree += 1
                    tag = "" if strong else "  (WEAK: short body, the "
                    tag += "" if strong else "pairing is not trustworthy)"
                    print(f"  DISAGREE {stage} {args.ref}:{rn[0]} "
                          f"/ {tgt}:{tn[0]}{tag}")
                    print(f"    {args.ref:>8} offsets "
                          + " ".join(f"0x{o:04X}" for o in ro))
                    print(f"    {tgt:>8} offsets "
                          + " ".join(f"0x{o:04X}" for o in to))
        print(f"\n=== {args.ref} vs {tgt}: {pairs} body-identical pair(s) "
              f"drawing shared-bank art")
        print(f"    {agree} agree on every offset ({strong_agree} of them "
              f"with a body of {MIN_BODY}+ lines), {disagree} disagree "
              f"({weak_disagree} of those short-bodied and so not evidence), "
              f"{unresolved} had an unresolvable symbol")
        if args.coverage:
            print(f"    those pairs touch {len(touched)} distinct offset(s); "
                  f"{args.ref} defines {len(defined)}")
            if defined:
                print(f"    coverage {100.0 * len(touched) / len(defined):.1f}%"
                      f" -- the rest is untested, not proven equal")

    print("\n" + ("A LOAD-BEARING PAIR DISAGREES -- T7's premise is false "
                  "as stated" if bad else
                  "No routine paired on a body of 3+ lines draws the shared "
                  "bank at a different\noffset on two ports. T7's premise "
                  "survives over the part of the bank the game\nuses -- which "
                  "is not the whole bank; see --coverage."))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
