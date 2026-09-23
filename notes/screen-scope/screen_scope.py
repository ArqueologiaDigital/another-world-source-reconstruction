#!/usr/bin/env python3
"""Which screen is a routine reachable under? A forward dataflow on SCREEN_NUM.

Question answered
-----------------
`../remaining-art/` found 42 backdrop composites -- `fill`, then N pictures at
one anchor, then `ret` -- and showed that naming their layers needs one fact
none of them carries: **which screen the backdrop is for**. Three ways of
reading it off the text were tested and all failed. The label's hex token is
not the screen (0 of 54 match a `[SCREEN_NUM]` guard), the draw count matches
only 42 of 74, and the call site carries no guard at all. There is no single
dispatcher to read either: `[SCREEN_NUM]` is compared 182 times across 52
distinct values in CAVES alone, scattered through the stage as guards.

So the screen is not a lookup. It is a *reachability* property: a routine
belongs to screen NN when every path that can reach it has already tested
`[SCREEN_NUM]` and found NN. That is a forward dataflow problem, and this
computes it.

The lattice
-----------
Each program point carries either a frozenset of possible screen values or
`None` meaning **unconstrained** -- no test has pinned it down on this path.
`None` is top, and merging is the conservative choice:

    None  |  anything   ->  None
    {a}   |  {b}        ->  {a, b}

So one path that reaches a routine without the screen being known poisons it,
which is what we want: the claim "this is screen NN's backdrop" must be true
of every way in, not of one convenient way.

How a guard refines it
----------------------
Only the two forms that yield a positive fact are used:

    je  [SCREEN_NUM], 0xNN, T     -> at T, the screen IS NN
    jne [SCREEN_NUM], 0xNN, T     -> on the FALLTHROUGH, the screen IS NN

The other arm of each is a negative fact (`!= NN`), which over 52 possible
values is nearly worthless, so those edges keep the incoming context.
Inequalities (`jl`, `jge`, ...) on `[SCREEN_NUM]` are treated the same way:
they constrain nothing here.

Entry points
------------
A label with no incoming edge, and any label installed by a `setup`, starts
`None`. That is deliberately pessimistic -- a thread the scheduler can start
at any time really is reachable under any screen.

The control that makes this believable
--------------------------------------
CAVES already contains six routines whose names carry a screen, written by a
human from other evidence: `CAVES_SCREEN_92_BACKDROP_DRAW`,
`CAVES_SCREEN_93_BACKDROP_DRAW` and kin. This module is not told about them.
If the dataflow independently derives 0x92 for the first and 0x93 for the
second, it is reading the same thing the person read. `--control` checks
exactly that and exits 1 on a disagreement.

Usage
-----
    python3 notes/screen-scope/screen_scope.py --control
    python3 notes/screen-scope/screen_scope.py --stage CAVES --port amiga
    python3 notes/screen-scope/screen_scope.py --backdrops
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]

# Branch keyed by a short name. The analysis reads only source, never a ROM,
# so cartridge_1992 and gba_2004 are covered exactly like the priority ports.
PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992",
         "cart": "cartridge_1992", "gba": "gba_2004"}
STAGES = ("PRISON", "CAVES", "CAPSULE", "LAKE", "TANK", "INTRO", "ENDING")

RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
RE_COND = re.compile(r"^\s*(je|jne|jl|jle|jg|jge)\s+\[([A-Za-z0-9_]+)\],\s*"
                     r"(0x[0-9A-Fa-f]+|\[[A-Za-z0-9_]+\]),\s*"
                     r"([A-Za-z_][A-Za-z0-9_]*)")
RE_JMP = re.compile(r"^\s*jmp\s+([A-Za-z_][A-Za-z0-9_]*)")
RE_CALL = re.compile(r"^\s*call\s+([A-Za-z_][A-Za-z0-9_]*)")
RE_SETUP = re.compile(r"^\s*setup\s+.*address=([A-Za-z_][A-Za-z0-9_]*)")
RE_STOP = re.compile(r"^\s*(ret|killChannel)\b")
# A `db` line is raw bytes, and the ones that pad between routines are a
# single terminating opcode written as data. tools/redisasm_db.py:784 has
# TERMINATING_OPCODES = {0x05, 0x07, 0x11} -- ret, jmp, killChannel -- and
# `LABEL_A627: db 0x11` is killChannel. Falling through those chained
# unrelated routines together and poisoned every context downstream with
# top, which is why the first run of this module could not pin a single
# backdrop to a screen.
RE_DB = re.compile(r"^\s*db\s+(0x[0-9A-Fa-f]{2})")
TERMINATING_BYTES = {0x05, 0x07, 0x11}
SCREEN = "SCREEN_NUM"


def merge(a, b):
    """None is top: unconstrained beats any concrete set."""
    if a is None or b is None:
        return None
    return a | b


def analyse(lines: list[str]):
    """label -> the screen values it can be entered under (None = any)."""
    labels: dict[str, int] = {}
    for i, line in enumerate(lines):
        if m := RE_LBL.match(line):
            labels[m.group(1)] = i
    at = {i: n for n, i in labels.items()}

    # successors(i, ctx) -> [(j, ctx_j)]
    def succ(i: int, ctx):
        line = lines[i]
        if RE_LBL.match(line) or not line.strip():
            return [(i + 1, ctx)] if i + 1 < len(lines) else []
        if m := RE_COND.match(line):
            op, var, val, tgt = m.groups()
            taken = labels.get(tgt)
            out = []
            if op == "je" and var == SCREEN and val.startswith("0x"):
                hit = frozenset({int(val, 16)})
                if taken is not None:
                    out.append((taken, hit))
                out.append((i + 1, ctx))
            elif op == "jne" and var == SCREEN and val.startswith("0x"):
                hit = frozenset({int(val, 16)})
                if taken is not None:
                    out.append((taken, ctx))
                out.append((i + 1, hit))
            else:
                if taken is not None:
                    out.append((taken, ctx))
                out.append((i + 1, ctx))
            return [(j, c) for j, c in out if j < len(lines)]
        if m := RE_JMP.match(line):
            t = labels.get(m.group(1))
            return [(t, ctx)] if t is not None else []
        if m := RE_CALL.match(line):
            t = labels.get(m.group(1))
            out = [(i + 1, ctx)] if i + 1 < len(lines) else []
            if t is not None:
                out.append((t, ctx))
            return out
        if m := RE_SETUP.match(line):
            # A thread the scheduler may start at any time.
            t = labels.get(m.group(1))
            out = [(i + 1, ctx)] if i + 1 < len(lines) else []
            if t is not None:
                out.append((t, None))
            return out
        if RE_STOP.match(line):
            return []
        if m := RE_DB.match(line):
            if int(m.group(1), 16) in TERMINATING_BYTES:
                return []
        return [(i + 1, ctx)] if i + 1 < len(lines) else []

    state: dict[int, object] = {}
    work = collections.deque()

    # Seeds: file start, every setup target, and every label with no
    # incoming edge once the graph is walked. The last is handled by a
    # second pass below.
    def push(i, ctx):
        if i is None or i >= len(lines):
            return
        old = state.get(i, "unset")
        new = ctx if old == "unset" else merge(old, ctx)
        if old == "unset" or new != old:
            state[i] = new
            work.append(i)

    push(0, None)
    for line in lines:
        if m := RE_SETUP.match(line):
            push(labels.get(m.group(1)), None)

    rounds = 0
    while work:
        rounds += 1
        if rounds > 4_000_000:
            raise RuntimeError("dataflow did not converge")
        i = work.popleft()
        for j, c in succ(i, state[i]):
            push(j, c)

    # A label the walk never reached is seeded top ONLY if something
    # mentions it. An unreferenced label cannot be entered except by
    # fallthrough, which the walk already models, so seeding it is not
    # caution -- it invents an entry point.
    #
    # That distinction is what pinned amiga's CAVES_SCREEN_92_BACKDROP_DRAW.
    # It is preceded by `LABEL_D3B8: db 0x78, 0x7A, 0x94, 0x4C, 0x7B, 0x11`,
    # a data blob nothing references and that nothing falls into either (the
    # routine before it ends in `ret`). Seeding it top sent top straight
    # through the blob into the backdrop, and the backdrop came back
    # unconstrained while msdos, whose equivalent gap is real code ending in
    # `killChannel`, came back 0x92.
    #
    # Multi-byte blobs are NOT treated as terminating: of 1,396 of them only
    # 191 even end in a terminating byte, so "it ends in killChannel" is not
    # a rule, and assuming termination would make labels look MORE pinned
    # than they are -- an error in the unsafe direction for naming.
    mentioned = set()
    for i, line in enumerate(lines):
        if RE_LBL.match(line):
            continue
        for tok in re.findall(r"[A-Za-z_][A-Za-z0-9_]*", line):
            if tok in labels:
                mentioned.add(tok)
    unseen = [i for n, i in labels.items()
              if i not in state and n in mentioned]
    if unseen:
        for i in unseen:
            push(i, None)
        while work:
            i = work.popleft()
            for j, c in succ(i, state[i]):
                push(j, c)

    return {n: state.get(i) for n, i in labels.items()}, at


def install_context(lines: list[str], sites: list[int]):
    """The screen pinned at each `setup` line that installs a routine.

    Re-runs the analysis and reads the context of the *line* rather than of
    a label, because the install site is usually mid-block: in CAVES it is
    the fallthrough of `jne [SCREEN_NUM], 0xNN, ...`, a few instructions in.
    """
    labels = {}
    for i, line in enumerate(lines):
        if m := RE_LBL.match(line):
            labels[m.group(1)] = i
    ctx = None
    for i in sites:
        # walk back to the nearest enclosing label, then forward, tracking
        # the one guard form that pins a screen on the fallthrough.
        j, found = i, None
        while j >= 0:
            line = lines[j]
            if m := RE_COND.match(line):
                op, var, val, _t = m.groups()
                if var == SCREEN and val.startswith("0x") and op == "jne":
                    found = frozenset({int(val, 16)})
                    break
                if var == SCREEN and val.startswith("0x") and op == "je":
                    break
            if RE_LBL.match(line) and j != i:
                break
            j -= 1
        ctx = found if ctx is None else (
            None if found is None else ctx | found)
        if found is None:
            return None
    return ctx


def load(port: str, stage: str):
    f = SRC / "src" / "levels" / PORTS[port] / f"{stage}.asm"
    if not f.is_file():
        return None
    return f.read_text(errors="replace").splitlines()


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", choices=sorted(PORTS), default="amiga")
    ap.add_argument("--stage", choices=STAGES)
    ap.add_argument("--control", action="store_true",
                    help="check the derived screen against the six routines "
                         "whose names already carry one")
    ap.add_argument("--proposals", action="store_true",
                    help="emit a correction for every routine whose name "
                         "states a screen the dataflow contradicts")
    ap.add_argument("--backdrops", action="store_true")
    args = ap.parse_args()

    if args.control:
        bad = ok = viasetup = 0
        for port in sorted(PORTS):
            for stage in STAGES:
                lines = load(port, stage)
                if lines is None:
                    continue
                scoped, _at = analyse(lines)
                # A routine installed only by `setup` is a scheduler
                # thread, and top is the right answer for it -- it keeps
                # running across screen changes. Its INSTALL SITE still has
                # a screen, and that is the fact its name is making a claim
                # about, so compare against that instead.
                installed_at = {}
                for i, line in enumerate(lines):
                    if m := RE_SETUP.match(line):
                        installed_at.setdefault(m.group(1), []).append(i)
                for name, ctx in sorted(scoped.items()):
                    m = re.search(rf"{stage}_SCREEN_([0-9A-F]{{2}})", name)
                    if not m:
                        continue
                    want = int(m.group(1), 16)
                    via = ""
                    if ctx is None and name in installed_at:
                        ctx = install_context(lines, installed_at[name])
                        via = " (via its setup site)"
                        viasetup += 1
                    got = ("any" if ctx is None
                           else ", ".join(f"0x{v:02X}" for v in sorted(ctx)))
                    agree = ctx is not None and set(ctx) == {want}
                    ok += agree
                    bad += not agree
                    print(f"  {port:<6}{stage:<9}{name:<44}"
                          f"name says 0x{want:02X}, dataflow says {got}{via}"
                          f"   {'AGREE' if agree else '**'}")
        print(f"\n  {ok} agree, {bad} do not "
              f"({viasetup} compared against their setup site)")
        return 1 if bad else 0

    if args.proposals:
        by: dict[tuple, list] = {}
        for port, branch in sorted(PORTS.items()):
            for stage in STAGES:
                lines = load(port, stage)
                if lines is None:
                    continue
                scoped, _at = analyse(lines)
                installed_at: dict[str, list] = {}
                for i, line in enumerate(lines):
                    if m := RE_SETUP.match(line):
                        installed_at.setdefault(m.group(1), []).append(i)
                for name, ctx in sorted(scoped.items()):
                    m = re.search(rf"{stage}_SCREEN_([0-9A-F]{{2}})", name)
                    if not m:
                        continue
                    how = "every path that reaches it"
                    if ctx is None and name in installed_at:
                        ctx = install_context(lines, installed_at[name])
                        how = "the `setup` that installs it"
                    if ctx is None or len(ctx) != 1:
                        continue
                    got = next(iter(ctx))
                    if got == int(m.group(1), 16):
                        continue
                    new = name.replace(f"_SCREEN_{m.group(1)}_",
                                       f"_SCREEN_{got:02X}_")
                    by.setdefault((branch, stage), []).append(
                        (name, new, m.group(1), got, how))
        for (branch, stage), rows in sorted(by.items()):
            print(f"\n----- {branch} / {stage} -----")
            print("| routine | proposed name | confidence | evidence |")
            print("| --- | --- | --- | --- |")
            for name, new, said, got, how in rows:
                print(f"| {name} | {new} | high | {how} tests "
                      f"`[SCREEN_NUM]` and finds 0x{got:02X}, not the "
                      f"0x{said} the name states |")
        if not by:
            print("no routine's name contradicts the derived screen")
        return 0

    stages = [args.stage] if args.stage else list(STAGES)
    for stage in stages:
        lines = load(args.port, stage)
        if lines is None:
            continue
        scoped, _at = analyse(lines)
        n_single = sum(1 for c in scoped.values()
                       if c is not None and len(c) == 1)
        n_few = sum(1 for c in scoped.values()
                    if c is not None and 1 < len(c) <= 4)
        n_any = sum(1 for c in scoped.values() if c is None)
        print(f"  {args.port}/{stage:<9}{len(scoped):>5} labels: "
              f"{n_single:>4} pinned to one screen, {n_few:>4} to 2-4, "
              f"{n_any:>5} unconstrained")
    return 0


if __name__ == "__main__":
    sys.exit(main())
