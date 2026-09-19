#!/usr/bin/env python3
"""Which branches can actually reach each COMMON_VIDEO reference?

Why this exists
---------------
A sibling probe found that 346 of 353 canonical `COMMON_VIDEO` names denote
different art on amiga than on msdos, and concluded that re-keying the bank by
offset (plan item T7) would break the unified tree because **3,205 references
sit outside any `.if`**, so a port-specific name could not serve them.

That count was measured wrongly, and this probe is the correction.

"Outside a `.if`" is not the same as "shared between branches". A reference
can sit at the top level of a file that is *itself* branch-specific:
`_unified/caves/amiga__post_DECREMENT_VAR08_BY_D.inc` has no `.if` in it and
is only ever included by amiga. `_unified/_helpers/DRAW_CV_099.inc` looks like
the most shared thing in the tree -- it is in `_helpers/` and three different
stages include it -- and all three includers are `amiga__*` files. It is a
**cross-stage** helper within one branch, not a cross-branch one.

The right question is reachability through the include graph, per branch.

What it does
------------
For each stage, starts at `_unified/<STAGE>.asm.in` and walks `.include`
directives once per branch, honouring `.if BRANCH ...` so that a branch only
follows the includes it would really see. That gives, for every chunk file,
the set of branches that reach it. Each `COMMON_VIDEO` reference is then
bucketed:

  single-branch      only one branch reaches it -- renaming it to that
                     branch's `CV_<OFFSET4>` is safe and local
  multi-branch, agreeing   several branches reach it and they all resolve the
                     name to the same offset -- one `CV_<OFFSET4>` serves them
                     all, and the rename *unifies* rather than splits
  multi-branch, differing  several branches reach it and disagree on the
                     offset -- these, and only these, need a branch arm or an
                     emitter-level fix

Only the third bucket is a real obstacle to T7.

Exit status
-----------
0 always -- a measurement.

Usage
-----
    python3 notes/t7-cv-offset-rekey/cv_refs_by_reaching_branch.py
    python3 notes/t7-cv-offset-rekey/cv_refs_by_reaching_branch.py --list 15
"""
from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels"
UNI = SRC / "_unified"
BRANCHES = ["chahi_amiga_1991", "dos_1992", "cartridge_1992", "gba_2004"]
BR_DIR = {"chahi_amiga_1991": "chahi_amiga_1991", "dos_1992": "dos_1992",
          "cartridge_1992": "cartridge_1992", "gba_2004": "gba_2004"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]

RE_INC = re.compile(r'^\s*\.include\s+"([^"]+)"')
RE_IF = re.compile(r'^\s*\.if\s+(.*)$')
RE_ELIF = re.compile(r'^\s*\.elif\s+(.*)$')
RE_ELSE = re.compile(r'^\s*\.else\b')
RE_END = re.compile(r'^\s*\.endif\b')
RE_CV = re.compile(r"\bCOMMON_VIDEO_[A-Za-z0-9_]+\b")
RE_EQU = re.compile(r"^(COMMON_VIDEO_[A-Za-z0-9_]+)\s+EQU\s+(0x[0-9A-Fa-f]+)")


def cond_true(expr: str, branch: str) -> bool:
    expr = expr.strip()
    m = re.match(r'BRANCH\s*==\s*"([^"]+)"', expr)
    if m:
        return branch == m.group(1)
    m = re.match(r'BRANCH\s*!=\s*"([^"]+)"', expr)
    if m:
        return branch != m.group(1)
    m = re.match(r'BRANCH\s+in\s*\((.*)\)', expr)
    if m:
        return branch in re.findall(r'"([^"]+)"', m.group(1))
    m = re.match(r'BRANCH\s+not\s+in\s*\((.*)\)', expr)
    if m:
        return branch not in re.findall(r'"([^"]+)"', m.group(1))
    return True          # unknown condition: assume reachable


def walk(path: Path, branch: str, seen: set[Path], hits: list):
    if not path.is_file() or path in seen:
        return
    seen.add(path)
    stack: list[tuple[bool, bool]] = []       # (active, any-arm-taken)

    def active() -> bool:
        return all(a for a, _ in stack)

    for line in path.read_text(errors="replace").splitlines():
        m = RE_IF.match(line)
        if m:
            t = cond_true(m.group(1), branch)
            stack.append((t, t))
            continue
        m = RE_ELIF.match(line)
        if m and stack:
            _, taken = stack[-1]
            t = (not taken) and cond_true(m.group(1), branch)
            stack[-1] = (t, taken or t)
            continue
        if RE_ELSE.match(line) and stack:
            _, taken = stack[-1]
            stack[-1] = (not taken, True)
            continue
        if RE_END.match(line) and stack:
            stack.pop()
            continue
        if not active():
            continue
        m = RE_INC.match(line)
        if m:
            walk((path.parent / m.group(1)).resolve(), branch, seen, hits)
            continue
        if RE_EQU.match(line):
            continue
        for tok in RE_CV.findall(line):
            hits.append((path, tok))


def offsets(branch: str, stage: str) -> dict[str, int]:
    f = SRC / BR_DIR[branch] / f"{stage}.asm"
    out = {}
    if f.is_file():
        for line in f.read_text(errors="replace").splitlines():
            m = RE_EQU.match(line)
            if m:
                out[m.group(1)] = int(m.group(2), 16)
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--list", type=int, default=0)
    args = ap.parse_args()

    tot = collections.Counter()
    problems = []
    for stage in STAGES:
        top = UNI / f"{stage}.asm.in"
        if not top.is_file():
            continue
        per_branch: dict[str, list] = {}
        for br in BRANCHES:
            hits: list = []
            walk(top, br, set(), hits)
            if hits or (SRC / BR_DIR[br] / f"{stage}.asm").is_file():
                per_branch[br] = hits
        # (file, token) -> branches reaching it
        reach: dict[tuple, set[str]] = collections.defaultdict(set)
        count: dict[tuple, int] = collections.Counter()
        for br, hits in per_branch.items():
            for f, tok in hits:
                reach[(f, tok)].add(br)
                count[(f, tok)] += 1
        offs = {br: offsets(br, stage) for br in per_branch}
        for (f, tok), brs in reach.items():
            n = count[(f, tok)] // max(1, len(brs))
            vals = {br: offs[br].get(tok) for br in brs
                    if offs[br].get(tok) is not None}
            if len(brs) == 1:
                tot["single-branch"] += n
            elif len(set(vals.values())) <= 1:
                tot["multi-branch, agreeing"] += n
            else:
                tot["multi-branch, DIFFERING"] += n
                problems.append((stage, f.relative_to(UNI), tok, vals))

    total = sum(tot.values())
    print(f"{total} COMMON_VIDEO reference(s) reachable in the unified tree")
    for k in ("single-branch", "multi-branch, agreeing",
              "multi-branch, DIFFERING"):
        print(f"  {tot[k]:6d}  {k}")
    print(f"\nOnly the last bucket obstructs T7's rename.")
    for stage, f, tok, vals in problems[:args.list]:
        v = " ".join(f"{b.split('_')[0]}=0x{o:04X}" for b, o in vals.items())
        print(f"  {stage:<8} {str(f):<52} {tok:<20} {v}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
