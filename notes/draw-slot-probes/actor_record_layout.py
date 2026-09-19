#!/usr/bin/env python3
"""What is the record behind [0x07],[0x08]? Extract its layout from the code.

Question answered
-----------------
Issue #0138 says a routine drawing at `x=[0x07], y=[0x08]` cannot be named for
*who* it draws, because that pair is loaded from "a shared actor-record pair
... from nine different records before the draw". That sentence is the reason
434 CAVES routines on the two priority ports are parked, and it is stated
without a layout: how many records, how wide, which fields, where.

This derives the layout from the bytecode instead of asserting it.

The idiom it keys on is a **swap block**: a straight run of `mov` between the
working registers and consecutive variables at some base. `LABEL_4E0A` in
amiga CAVES is one of each, back to back -- it stores eight working registers
to the record at 0x68 and immediately loads the record at 0x70 into the same
eight registers. A rotation like that pins both the field map and the stride
without anyone having to guess either.

What is measured
----------------
For each port/stage, every maximal run of `mov [A], [B]` where one side is a
working register and the other is a variable, of length >= MIN_FIELDS:

  * the **base** (lowest record address touched) and the **field map**, as
    offset-from-base -> working register;
  * whether the run **loads** (record -> registers) or **stores**;
  * which field maps agree. A map shared by several bases at a constant
    stride is a record array, and the probe prints base, stride and count.

`--blocks` lists every run with its routine, so any claim here can be walked
back to a line of source.

What it establishes, and what it does not
-----------------------------------------
It establishes the *shape* of the thing: how wide a record is, how many there
are, and that `[0x07]`/`[0x08]` are fields 0 and 1 of whichever one is swapped
in. It says nothing about **whose** record any of them is, and finding the
layout does not make the actor knowable -- if anything it is the clearest
statement yet of why it is not. #0138 stands; it is now explicable.

Exit status
-----------
0 always -- a measurement, not a gate.

Usage
-----
    python3 notes/draw-slot-probes/actor_record_layout.py
    python3 notes/draw-slot-probes/actor_record_layout.py --blocks
    python3 notes/draw-slot-probes/actor_record_layout.py --all
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
RE_MOVVV = re.compile(r"^\s*mov\s+\[(\w+)\]\s*,\s*\[(\w+)\]\s*$")
RE_SETUP = re.compile(r"^\s*setup\s+channel=(0x[0-9A-Fa-f]+)\s*,\s*"
                      r"address=([A-Za-z_][A-Za-z0-9_]*)")
RE_LOADVAR = re.compile(r"^\s*mov\s+\[(0x0[789])\]\s*,\s*\[(0x[0-9A-Fa-f]{2})\]")

# Working registers: the low scratch set the swap blocks move through. Taken
# from the blocks themselves, not assumed -- anything below this bound that a
# block touches is treated as a register and anything at or above it as record
# storage. 0x30 sits well above the highest register seen (0x29) and well below
# the lowest record base seen (0x48).
REG_MAX = 0x30
MIN_FIELDS = 4


def resolve(tree: dict[str, int], tok: str) -> int | None:
    if tok.lower().startswith("0x"):
        try:
            return int(tok, 16)
        except ValueError:
            return None
    return tree.get(tok)


def equs(text: str) -> dict[str, int]:
    out = {}
    for m in re.finditer(r"^(\w+)\s+EQU\s+(0x[0-9A-Fa-f]+)\s*$", text,
                         re.MULTILINE):
        out[m.group(1)] = int(m.group(2), 16)
    return out


def channels(path: Path) -> dict[str, set[str]]:
    """routine -> the channel(s) it is installed on by `setup`."""
    out: dict[str, set[str]] = collections.defaultdict(set)
    for raw in path.read_text(errors="replace").splitlines():
        m = RE_SETUP.match(raw.split(";", 1)[0])
        if m:
            out[m.group(2)].add(m.group(1))
    return out


def other_readers(path: Path, lo: int, hi: int) -> dict[str, set[int]]:
    """routine -> record words it loads into 0x07/0x08/0x09 outside a block.

    These are the routines that address the same region under a *different*
    layout. Finding them is the point: see the README.
    """
    out: dict[str, set[int]] = collections.defaultdict(set)
    cur = "<top>"
    for raw in path.read_text(errors="replace").splitlines():
        line = raw.split(";", 1)[0]
        m = RE_LABEL.match(line)
        if m:
            cur = m.group(1)
            continue
        mm = RE_LOADVAR.match(line)
        if mm:
            a = int(mm.group(2), 16)
            if lo <= a <= hi:
                out[cur].add(a)
    return out


def blocks(path: Path):
    """Yield (routine, kind, base, {offset: register}) for each swap run."""
    text = path.read_text(errors="replace")
    alias = equs(text)
    cur = "<top>"
    run: list[tuple[int, int]] = []     # (dst, src)
    out = []

    def direction(d: int, s: int) -> str | None:
        if d < REG_MAX <= s:
            return "load"
        if s < REG_MAX <= d:
            return "store"
        return None

    def emit(seg: list[tuple[int, int]], kind: str):
        """One same-direction segment -> at most one record access."""
        if len(seg) < MIN_FIELDS:
            return
        if kind == "load":
            regs, mem = [d for d, _ in seg], [s for _, s in seg]
        else:
            regs, mem = [s for _, s in seg], [d for d, _ in seg]
        if len(set(mem)) != len(mem):
            return                      # same word twice: not a record
        base, width = min(mem), max(mem) - min(mem) + 1
        # A record is densely packed. A sparse run is unrelated moves that
        # merely sat next to each other, which is how 4-field "records"
        # spanning 21 words appeared before this filter.
        if len(mem) * 2 < width:
            return
        out.append((cur, kind, base,
                    tuple(sorted((m - base, r) for m, r in zip(mem, regs)))))

    def flush():
        """Split the run where the direction changes, then emit each part.

        A rotation writes one record and reads the next in one unbroken run
        of `mov` -- `LABEL_4E0A` stores eight registers to 0x68 and loads
        0x70 into the same eight with nothing in between. Testing the whole
        run for a single direction threw both halves away.
        """
        seg: list[tuple[int, int]] = []
        kind = None
        for d, s in run:
            k = direction(d, s)
            if k is None:
                emit(seg, kind) if kind else None
                seg, kind = [], None
                continue
            if k != kind:
                if kind:
                    emit(seg, kind)
                seg, kind = [], k
            seg.append((d, s))
        if kind:
            emit(seg, kind)
        run.clear()

    for raw in text.splitlines():
        line = raw.split(";", 1)[0]
        m = RE_LABEL.match(line)
        if m:
            flush()
            cur = m.group(1)
            continue
        mm = RE_MOVVV.match(line)
        if mm:
            d = resolve(alias, mm.group(1))
            s = resolve(alias, mm.group(2))
            if d is not None and s is not None:
                run.append((d, s))
                continue
        flush()
    flush()
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", action="append", choices=sorted(PORTS))
    ap.add_argument("--stage", action="append")
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--blocks", action="store_true")
    args = ap.parse_args()
    ports = args.port or (sorted(PORTS) if args.all else ["amiga", "msdos"])
    stages = args.stage or (STAGES if args.all else ["PRISON", "CAVES",
                                                     "CAPSULE"])

    for port in ports:
        for stage in stages:
            p = SRC / PORTS[port] / f"{stage}.asm"
            if not p.is_file():
                continue
            bs = blocks(p)
            if not bs:
                continue
            print(f"\n=== {port}/{stage}: {len(bs)} swap block(s)")
            by_map: dict[tuple, list] = collections.defaultdict(list)
            for routine, kind, base, fmap in bs:
                by_map[fmap].append((base, kind, routine))
            for fmap, uses in sorted(by_map.items(),
                                     key=lambda kv: -len(kv[1])):
                bases = sorted({b for b, _k, _r in uses})
                strides = sorted({b - a for a, b in zip(bases, bases[1:])})
                width = max(o for o, _r in fmap) + 1
                fields = " ".join(f"+{o}->0x{r:02X}" for o, r in fmap)
                print(f"  {len(fmap)} field(s), width {width}: {fields}")
                print(f"    bases {' '.join(f'0x{b:02X}' for b in bases)}"
                      + (f"   stride {strides[0]}" if len(strides) == 1
                         else f"   strides {strides}" if strides else "")
                      + f"   ({len(uses)} use(s): "
                      + ", ".join(sorted({k for _b, k, _r in uses})) + ")")
                if len(strides) == 1 and strides[0] == width:
                    print(f"    -> an array of {len(bases)} record(s) of "
                          f"{width} word(s), 0x{bases[0]:02X}.."
                          f"0x{bases[-1] + width - 1:02X}, packed")
                chans = channels(p)
                for b, k, r in sorted(uses):
                    ch = ", ".join(sorted(chans.get(r, ()))) or "-"
                    if args.blocks:
                        print(f"       0x{b:02X} {k:<5} {r:<34} channel {ch}")

                # Who else addresses these words, and on which channel?
                if len(strides) == 1 and strides[0] == width:
                    lo, hi = bases[0], bases[-1] + width - 1
                    mine = {r for _b, _k, r in uses}
                    others = {r: ws for r, ws in
                              other_readers(p, lo, hi).items()
                              if r not in mine}
                    if others:
                        ochan = collections.Counter()
                        for r in others:
                            for c in chans.get(r, ()):
                                ochan[c] += 1
                        mychan = {c for r in mine for c in chans.get(r, ())}
                        print(f"    {len(others)} other routine(s) load "
                              f"0x{lo:02X}..0x{hi:02X} into the same working "
                              f"registers under a DIFFERENT layout")
                        if ochan:
                            shared = sorted(set(ochan) & mychan)
                            print(f"      their channels: "
                                  f"{', '.join(sorted(ochan))}")
                            print(f"      block channels: "
                                  f"{', '.join(sorted(mychan))}")
                            print(f"      shared channels: "
                                  f"{', '.join(shared) if shared else 'none'}"
                                  + ("   -> mutually exclusive in time; the "
                                     "words are scene-scoped" if shared
                                     else "   -> COULD COEXIST, check"))
                        for r in sorted(others)[:6]:
                            ws = " ".join(f"0x{w:02X}"
                                          for w in sorted(others[r]))
                            print(f"        {r:<44} {ws}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
