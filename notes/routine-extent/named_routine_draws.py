#!/usr/bin/env python3
"""What does a named routine actually draw? Follow its control flow, not the
nearest label.

Question answered
-----------------
Probes across this repo answer "which routines draw picture X" by scanning
lines and crediting each `video offset=` to the **nearest preceding label**.
That is wrong whenever a routine spans more than one label, and routines here
routinely do:

    PRISON_HERO_STAND_LEFT_DRAW:
        jne [0x0A], 0x00, LABEL_6DBF
        video offset=CV_3322, ...          <- credited correctly
        jmp LABEL_6DC2
    LABEL_6DBF:
        call GUARDED_DRAW_CV_126
    LABEL_6DC2:
        call LABEL_6D1E
        video offset=CV_0358, ...          <- credited to LABEL_6DC2

Nothing but `PRISON_HERO_STAND_LEFT_DRAW` reaches that second draw, and the
routine unconditionally performs it, but the nearest-label rule files it under
an address placeholder. The effect is one-directional: **named sources are
undercounted, never overcounted**, so conclusions built on "at least N
independent sources" stay sound while conclusions built on "only one source,
so reject" are sometimes wrong. This probe was written after the shared-bank
consensus pass rejected `CV_0358` for having one source when it has two.

What it does
------------
Builds the intra-file control-flow graph — fallthrough, `jmp`, conditional
jumps, and `call` — and computes, for each unnamed block, the **set of named
routines that can reach it** without passing through another named label. A
block's draws are credited to that routine only when the set has exactly one
member.

The exclusivity rule is the whole design, and the first version did not have
it. Walking forward from each named routine and crediting everything reachable
took msdos/CAPSULE from 297 (routine, picture) pairs to 10,402 — 21 pictures
per named routine — because a forward walk floods through the large unnamed
regions those stages still have, and every named routine that can reach a
shared helper gets credited with everything the helper draws. That is not
"what this routine draws", it is "what is downstream of it".

With exclusivity, a block reachable from two named routines is a shared helper
and is attributed to neither; `--shared` lists those. What remains is the part
a routine's name can honestly be said to cover.

Stopping at the next named label matters for the same reason. A named routine
is an identified thing; falling into one means the code has moved on to that
thing, and its draws belong to it.

`call` edges are followed into unnamed targets, and the return needs no
modelling because a callee's draws genuinely are part of what the caller
draws — subject to the same exclusivity test, which is what keeps a
much-called helper out of everyone's total.

Signals read
------------
`src/levels/<branch>/<STAGE>.asm`. Labels, `video ... offset=<sym>` operands,
and the operands of `jmp`, `jne`, `je`, `jl`, `jg`, `jle`, `jge`, `dbra` and
`call`. `naming_census.classify` decides which labels count as named.

Usage
-----
    python3 notes/routine-extent/named_routine_draws.py --symbol CV_0358
    python3 notes/routine-extent/named_routine_draws.py --routine \
        PRISON_HERO_STAND_LEFT_DRAW
    python3 notes/routine-extent/named_routine_draws.py --compare
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
SRC = HERE.parents[2]
ARCH = SRC.parent / "another-world-archaeology"
sys.path.insert(0, str(ARCH / "tools"))
from naming_census import classify                    # noqa: E402

PORTS = {"amiga": "chahi_amiga_1991", "msdos": "dos_1992",
         "snes_eu": "cartridge_1992", "gba_2004": "gba_2004"}
STAGES = ["CODE_WHEEL", "INTRO", "LAKE", "PRISON", "CAVES", "TANK",
          "CAPSULE", "ENDING", "PASSCODE"]

RE_LABEL = re.compile(r"^([A-Za-z_]\w*):")
RE_DRAW = re.compile(r"\bvideo\b[^;]*?offset=([A-Za-z_]\w*)")
RE_JUMP = re.compile(r"^\s*(jmp|jne|je|jl|jg|jle|jge|dbra|call)\b[^;]*?"
                     r"\b([A-Za-z_]\w*)\s*$")
RE_UNCOND = re.compile(r"^\s*(jmp|ret|break|kill)\b")


def blocks_of(text: str):
    """label -> (draws in this block, successors, falls through?)"""
    order: list[str] = []
    draws: dict[str, list[str]] = {}
    succ: dict[str, list[str]] = {}
    fall: dict[str, bool] = {}
    cur = None
    for line in text.splitlines():
        m = RE_LABEL.match(line)
        if m:
            cur = m.group(1)
            order.append(cur)
            draws.setdefault(cur, [])
            succ.setdefault(cur, [])
            fall[cur] = True
            continue
        if cur is None:
            continue
        code = line.split(";", 1)[0]
        if not code.strip():
            continue
        for s in RE_DRAW.findall(code):
            draws[cur].append(s)
        j = RE_JUMP.match(code)
        if j:
            succ[cur].append(j.group(2))
        if RE_UNCOND.match(code):
            fall[cur] = False
    return order, draws, succ, fall


def _reaching(order, succ, fall, named, idx):
    """block -> set of named routines that reach it through unnamed blocks.

    A fixpoint, not a per-routine walk: a block joined by two named routines
    must end up with both, and a per-routine walk cannot see that.
    """
    reach: dict[str, set] = {lab: set() for lab in order}
    work = collections.deque()
    for lab in named:
        reach[lab] = {lab}
        work.append(lab)
    while work:
        lab = work.popleft()
        nxt = list(succ.get(lab, []))
        if fall.get(lab, False):
            i = idx.get(lab)
            if i is not None and i + 1 < len(order):
                nxt.append(order[i + 1])
        for n in nxt:
            if n not in idx or n in named:
                continue          # a named routine owns its own draws
            before = len(reach[n])
            reach[n] |= reach[lab]
            if len(reach[n]) != before:
                work.append(n)
    return reach


def routine_draws(text: str, with_shared: bool = False):
    """Named label -> the pictures only it reaches (see module docstring)."""
    order, draws, succ, fall = blocks_of(text)
    named = {lab for lab in order if classify(lab) == "semantic"}
    idx = {lab: i for i, lab in enumerate(order)}
    reach = _reaching(order, succ, fall, named, idx)
    out: dict[str, list[str]] = {lab: list(draws.get(lab, [])) for lab in named}
    shared: dict[str, set] = {}
    for lab in order:
        if lab in named:
            continue
        owners = reach.get(lab, set())
        if len(owners) == 1:
            out[next(iter(owners))].extend(draws.get(lab, []))
        elif len(owners) > 1 and draws.get(lab):
            shared[lab] = owners
    return (out, shared) if with_shared else out


def scan(ports: list[str]):
    per_file = {}
    for port in ports:
        for stage in STAGES:
            p = SRC / "src" / "levels" / PORTS[port] / f"{stage}.asm"
            if p.is_file():
                per_file[(port, stage)] = routine_draws(
                    p.read_text(errors="replace"))
    return per_file


def nearest_label_draws(text: str) -> dict[str, list[str]]:
    out: dict[str, list[str]] = collections.defaultdict(list)
    cur = None
    for line in text.splitlines():
        m = RE_LABEL.match(line)
        if m:
            cur = m.group(1)
            continue
        if cur:
            for s in RE_DRAW.findall(line.split(";", 1)[0]):
                out[cur].append(s)
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--symbol")
    ap.add_argument("--routine")
    ap.add_argument("--compare", action="store_true")
    ap.add_argument("--shared", action="store_true",
                    help="blocks that draw and are reached by "
                         "more than one named routine")
    ap.add_argument("--port", action="append", choices=sorted(PORTS))
    args = ap.parse_args()
    ports = args.port or ["amiga", "msdos"]

    if args.compare:
        gained = collections.Counter()
        tot_old = tot_new = 0
        print(f"{'port/stage':<18}{'named routines':>15}"
              f"{'(routine,art) old':>19}{'new':>8}{'gained':>8}")
        for port in ports:
            for stage in STAGES:
                p = SRC / "src" / "levels" / PORTS[port] / f"{stage}.asm"
                if not p.is_file():
                    continue
                text = p.read_text(errors="replace")
                new = routine_draws(text)
                old = nearest_label_draws(text)
                o = sum(len(set(v)) for k, v in old.items()
                        if classify(k) == "semantic")
                n = sum(len(set(v)) for v in new.values())
                tot_old += o
                tot_new += n
                gained[(port, stage)] = n - o
                print(f"{port + '/' + stage:<18}{len(new):>15}{o:>19}"
                      f"{n:>8}{n - o:>8}")
        print(f"\n{'TOTAL':<18}{'':>15}{tot_old:>19}{tot_new:>8}"
              f"{tot_new - tot_old:>8}")
        print("\nThe nearest-label rule credits a routine only with the "
              "draws in its first\nblock. Following control flow, with a "
              "block attributed only when exactly one\nnamed routine reaches "
              "it, credits it with the rest of its own body and with\nno one "
              "else's. Blocks several routines reach are shared helpers and go "
              "to\nneither; see --shared.")
        return 0

    if args.shared:
        for port in ports:
            for stage in STAGES:
                p = SRC / "src" / "levels" / PORTS[port] / f"{stage}.asm"
                if not p.is_file():
                    continue
                _out, shared = routine_draws(p.read_text(errors="replace"),
                                             with_shared=True)
                if shared:
                    big = sorted(shared.items(),
                                 key=lambda kv: -len(kv[1]))[:3]
                    print(f"{port}/{stage:<10} {len(shared):4d} drawing "
                          f"block(s) reached by 2+ named routines; most "
                          f"shared: "
                          + ", ".join(f"{k}({len(v)})" for k, v in big))
        return 0

    per_file = scan(ports)
    if args.symbol:
        print(f"named routines that draw {args.symbol}, by control flow:")
        n = 0
        for (port, stage), rds in sorted(per_file.items()):
            for r, art in sorted(rds.items()):
                if args.symbol in art:
                    n += 1
                    print(f"  {port}/{stage:<10} {r}")
        print(f"\n{n} (routine, file) pair(s); "
              f"{len({r for rds in per_file.values() for r, a in rds.items() if args.symbol in a})}"
              f" distinct routine name(s)")
        return 0
    if args.routine:
        for (port, stage), rds in sorted(per_file.items()):
            if args.routine in rds:
                art = list(dict.fromkeys(rds[args.routine]))
                print(f"  {port}/{stage:<10} draws {len(art)}: "
                      f"{', '.join(art)}")
        return 0
    print("need --symbol, --routine or --compare", file=sys.stderr)
    return 2


if __name__ == "__main__":
    sys.exit(main())
