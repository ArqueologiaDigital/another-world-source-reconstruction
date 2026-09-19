#!/usr/bin/env python3
"""T7, first half: re-key the shared bank from encounter order to offset.

What this does
--------------
`docs/NAMING.md` §2 forbids hand-naming `COMMON_VIDEO_NNN` and says why:

    Its numbering is worse than arbitrary: it is the order the disassembler
    happened to encounter entries across a whole `all_levels` run, so level
    N's header lists every entry seen in levels <= N. Before these can be
    named, the emitter must key them by offset (plan item T7) and the existing
    names must move to an interim port-invariant `CV_<OFFSET4>` -- the bank is
    byte-identical between Amiga and MS-DOS, so one name per offset is
    correct.

That premise is now proven rather than assumed: `notes/shared-bank-probes/`
shows resource 0x11 is one file, 25,108 bytes, identical sha256 on both
priority ports. So `CV_<OFFSET4>` is safe, and this performs the rename.

`COMMON_VIDEO_074 EQU 0x0020` becomes `CV_0020 EQU 0x0020`, and every
reference in that file follows.

Why it must be per file
-----------------------
The index is per-port, per-`all_levels`-run encounter order, so
`COMMON_VIDEO_074` is a **different offset in different files**. A global
search-and-replace would be catastrophic and would still pass a careless eye.
Every file is therefore rewritten against its own EQU table, and a reference
to a name the file does not define is left alone and reported.

Why it is byte-neutral
----------------------
An EQU's value is unchanged; only the identifier moves. `make test` must stay
at 29/29 and 29/29, and that is the check that this did not silently break
anything.

Both trees
----------
Per-branch `.asm` files are rewritten against their own EQU table. Unified
chunks are rewritten against a map built by **include-graph reachability**:
`cv_refs_by_reaching_branch.py` walks `_unified/<STAGE>.asm.in` once per
branch, honouring `.if BRANCH`, and records which branches actually reach each
chunk. Every (chunk, token) pair in the tree resolves to exactly one offset
across every reaching (branch, stage) -- checked, 0 exceptions of 2,963 -- so
the rewrite is unambiguous.

What it does NOT do
-------------------
This is half of T7. The other half is the **emitter**: until the disassembler
keys the bank by offset itself, a regeneration would reintroduce
`COMMON_VIDEO_NNN`. The source tree is the artefact of record and is
hand-maintained, so the rename stands on its own, but the emitter work is
still open.

It also does not make anything semantic. `CV_0020` is an interim
port-invariant key, and `naming_census.classify` correctly calls it
`addr_suffixed` -- still unnamed. The gain is that a name now means the same
art in every file and on both priority ports, so **one** act of identification
can name it everywhere, which `COMMON_VIDEO_NNN` made impossible.

Safety
------
Refuses, before writing anything, if in any file
  * two different `COMMON_VIDEO_*` names share one offset (the rename would
    collapse them into a duplicate definition), or
  * the target `CV_<OFFSET4>` is already taken by an unrelated identifier.

Usage
-----
    python3 notes/t7-cv-offset-rekey/rekey_common_video_by_offset.py --stage LAKE
    python3 notes/t7-cv-offset-rekey/rekey_common_video_by_offset.py --stage LAKE --apply
    python3 notes/t7-cv-offset-rekey/rekey_common_video_by_offset.py --all --apply
"""
from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

SRC = Path(__file__).resolve().parents[2] / "src" / "levels"
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]

RE_CV_EQU = re.compile(
    r"^(COMMON_VIDEO_[A-Za-z0-9_]+)(\s+EQU\s+)(0x[0-9A-Fa-f]+)\s*$")
RE_ANY_EQU = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s+EQU\s+")
RE_CV_TOKEN = re.compile(r"\bCOMMON_VIDEO_[A-Za-z0-9_]+\b")


def files_for(stages: list[str]) -> list[Path]:
    out: list[Path] = []
    for p in sorted(list(SRC.rglob("*.asm")) + list(SRC.rglob("*.asm.in"))):
        if p.stem.split(".")[0] in stages:
            out.append(p)
    return out


def unified_maps(stages: list[str]) -> dict[Path, dict[str, str]]:
    """chunk file -> {COMMON_VIDEO_name: CV_xxxx}, from reachability."""
    import importlib.util
    here = Path(__file__).resolve().parent
    spec = importlib.util.spec_from_file_location(
        "cv_reach", here / "cv_refs_by_reaching_branch.py")
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)

    seen_off: dict[tuple, set[int]] = collections.defaultdict(set)
    for stage in stages:
        top = mod.UNI / f"{stage}.asm.in"
        if not top.is_file():
            continue
        for br in mod.BRANCHES:
            hits: list = []
            mod.walk(top, br, set(), hits)
            if not hits:
                continue
            offs = mod.offsets(br, stage)
            for f, tok in hits:
                o = offs.get(tok)
                if o is not None:
                    seen_off[(f, tok)].add(o)

    out: dict[Path, dict[str, str]] = collections.defaultdict(dict)
    ambiguous = []
    for (f, tok), offs in seen_off.items():
        if len(offs) != 1:
            ambiguous.append((f, tok, sorted(offs)))
            continue
        out[f][tok] = f"CV_{next(iter(offs)):04X}"
    # EQU definitions carry their own offset and need no reachability
    for f in sorted(mod.UNI.rglob("*.inc")) + sorted(mod.UNI.rglob("*.asm.in")):
        for line in f.read_text(errors="replace").splitlines():
            m = RE_CV_EQU.match(line)
            if m:
                out[f][m.group(1)] = f"CV_{int(m.group(3), 16):04X}"
    return out, ambiguous


def plan_file(path: Path):
    """-> (mapping name->CV_xxxx, problems, n_refs)"""
    text = path.read_text(errors="replace")
    lines = text.splitlines()
    by_off: dict[int, set[str]] = collections.defaultdict(set)
    defined: dict[str, int] = {}
    others: set[str] = set()
    for line in lines:
        m = RE_CV_EQU.match(line)
        if m:
            off = int(m.group(3), 16)
            by_off[off].add(m.group(1))
            defined[m.group(1)] = off
            continue
        m2 = RE_ANY_EQU.match(line)
        if m2:
            others.add(m2.group(1))
    problems = []
    for off, names in sorted(by_off.items()):
        if len(names) > 1:
            problems.append(f"offset 0x{off:04X} defined under "
                            f"{len(names)} names: {sorted(names)}")
    mapping = {n: f"CV_{off:04X}" for n, off in defined.items()}
    for n, new in mapping.items():
        if new in others:
            problems.append(f"target {new} already used by another EQU")
    refs = len(RE_CV_TOKEN.findall(text))
    return mapping, problems, refs


def rewrite(path: Path, mapping: dict[str, str]) -> tuple[str, int]:
    text = path.read_text(errors="replace")
    unknown: collections.Counter = collections.Counter()

    def sub(m):
        tok = m.group(0)
        if tok in mapping:
            return mapping[tok]
        unknown[tok] += 1
        return tok

    new = RE_CV_TOKEN.sub(sub, text)
    if unknown:
        print(f"    {sum(unknown.values())} reference(s) to "
              f"{len(unknown)} name(s) this file does not define, left alone: "
              + ", ".join(sorted(unknown)[:4]))
    return new, sum(unknown.values())


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--stage", action="append")
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--apply", action="store_true")
    args = ap.parse_args()
    stages = args.stage or (STAGES if args.all else ["LAKE"])

    targets = files_for(stages)
    plans, problems, tot_defs, tot_refs = {}, [], 0, 0
    for p in targets:
        mapping, probs, refs = plan_file(p)
        if not mapping:
            continue
        plans[p] = mapping
        problems += [f"{p.relative_to(SRC)}: {x}" for x in probs]
        tot_defs += len(mapping)
        tot_refs += refs

    umaps, ambiguous = unified_maps(stages)
    for f, tok, offs in ambiguous:
        problems.append(f"{f.relative_to(SRC)}: {tok} resolves to "
                        + ", ".join(f"0x{o:04X}" for o in offs)
                        + " depending on which branch reaches it")
    for f, mapping in umaps.items():
        if f in plans:
            plans[f].update(mapping)
        else:
            plans[f] = mapping
            tot_refs += len(RE_CV_TOKEN.findall(f.read_text(errors="replace")))

    print(f"{len(plans)} file(s), {tot_defs} COMMON_VIDEO definition(s), "
          f"{tot_refs} token(s) to rewrite")
    if problems:
        print(f"\nREFUSING -- {len(problems)} problem(s):")
        for x in problems[:20]:
            print(f"  {x}")
        return 1
    if not args.apply:
        for p, mapping in list(plans.items())[:2]:
            ex = sorted(mapping.items())[:3]
            print(f"  {p.relative_to(SRC)}: "
                  + ", ".join(f"{a} -> {b}" for a, b in ex) + " ...")
        print("dry run -- re-run with --apply")
        return 0

    left = 0
    for p, mapping in plans.items():
        new, unknown = rewrite(p, mapping)
        left += unknown
        p.write_text(new)
    print(f"written. {left} reference(s) left alone as undefined here.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
