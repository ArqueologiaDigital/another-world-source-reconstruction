#!/usr/bin/env python3
"""Which palette was set last before this picture is drawn?

Question answered
-----------------
Every render-and-name batch starts by choosing a palette, and choosing wrong
is not a small error: `README.md` records a run that sat in the held list as
"unreadable" purely because it had been rendered at palette 0 instead of the
0x16 its own routine sets, and the INTRO pulse run renders as black on black
at palette 0. The palette was being found by reading the listing backwards by
hand, once per batch. This does it, and shows its working.

Three sources of a palette, reported separately because they are not equally
strong:

  IN-ROUTINE   a `setPalette` earlier in the same routine body than the draw.
               The strongest: no control flow can get between them.
  INSTALLED    a `setup channel=NN, address=SET_PALETTE_<n>` in the same body,
               which arms a coroutine that sets it a few `break`s later. Real,
               but it takes effect after a delay the routine does not control,
               so early frames of a run may still be under the previous one.
  PRECEDING    the nearest `setPalette` above the routine in **file order**.
               This is a guess and is labelled one: file order is not control
               flow, and a routine reached by `jmp` from elsewhere can run
               under a palette set anywhere. Confirm it against the caller
               before quoting it.

When IN-ROUTINE and PRECEDING agree, that agreement is itself the check -- it
is what settled palette 0x18 for `FILL_PAGE_FF_COLOR_8_ONCE`, whose own
`SET_PALETTE_18` coroutine and whose preceding `DELAY_1_THEN_PLAY_FX_0A_PAL_18`
say the same thing.

The renderer takes decimal, the bytecode is written in hex, and that mismatch
has cost a re-render before, so both are printed.

Run it
------
    python3 notes/render-and-name/palette_in_force.py --branch chahi_amiga_1991 \\
        --stage INTRO --const CINEMATIC_LIFT_DOORS_OPENING_F33_AMIGA_EXTRA
    python3 notes/render-and-name/palette_in_force.py --branch chahi_amiga_1991 \\
        --stage INTRO --routine LIFT_SHAFT_SCROLL_LOOP
    python3 notes/render-and-name/palette_in_force.py --branch chahi_amiga_1991 \\
        --stage INTRO --all-suffixed
"""
from __future__ import annotations

import argparse
import pathlib
import re

SRC = pathlib.Path(__file__).resolve().parents[2] / "src" / "levels"

RE_LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
RE_PAL = re.compile(r"^\s*setPalette\s+(0x[0-9A-Fa-f]+)")
RE_SETUP_PAL = re.compile(r"^\s*setup\s+channel=0x[0-9A-Fa-f]+,\s*address=(SET_PALETTE_(\w+))")


def lines_of(branch: str, stage: str) -> list[str]:
    return (SRC / branch / f"{stage}.asm").read_text().splitlines()


def routine_of(lines: list[str], idx: int) -> tuple[str, int]:
    """The label heading line `idx`, and that label's line number."""
    for i in range(idx, -1, -1):
        m = RE_LABEL.match(lines[i])
        if m:
            return m.group(1), i
    return "<file start>", 0


def report(lines: list[str], draw_idx: int, what: str) -> None:
    routine, head = routine_of(lines, draw_idx)

    in_routine = None
    installed = None
    for i in range(head, draw_idx):
        m = RE_PAL.match(lines[i])
        if m:
            in_routine = (int(m.group(1), 16), i + 1)
        m = RE_SETUP_PAL.match(lines[i])
        if m:
            installed = (m.group(1), i + 1)

    preceding = None
    for i in range(head - 1, -1, -1):
        m = RE_PAL.match(lines[i])
        if m:
            preceding = (int(m.group(1), 16), i + 1)
            break

    print(f"  {what}")
    print(f"      routine  {routine}  (line {head + 1}), draw at line {draw_idx + 1}")
    if in_routine:
        v, ln = in_routine
        print(f"      IN-ROUTINE   0x{v:02X}  = --palette {v}   (line {ln})")
    if installed:
        name, ln = installed
        n = name.rsplit("_", 1)[1]
        val = int(n) if n.isdigit() else None
        extra = f"  = --palette {val}" if val is not None else ""
        print(f"      INSTALLED    {name}{extra}   (line {ln}, takes effect after a few breaks)")
    if preceding:
        v, ln = preceding
        print(f"      PRECEDING    0x{v:02X}  = --palette {v}   (line {ln}) -- file order, not control flow")
    if not (in_routine or installed or preceding):
        print("      none found above this point in the file")
    if in_routine and preceding and in_routine[0] != preceding[0]:
        print("      note: IN-ROUTINE and PRECEDING disagree; IN-ROUTINE wins")
    print()


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--branch", default="chahi_amiga_1991")
    ap.add_argument("--stage", default="INTRO")
    ap.add_argument("--const")
    ap.add_argument("--routine")
    ap.add_argument("--all-suffixed", action="store_true",
                    help="every `_AMIGA_EXTRA` constant in this stage")
    args = ap.parse_args()

    lines = lines_of(args.branch, args.stage)

    targets: list[tuple[int, str]] = []
    if args.const:
        targets = [(i, args.const) for i, l in enumerate(lines)
                   if f"offset={args.const}," in l]
        if not targets:
            raise SystemExit(f"{args.const} is never drawn in {args.branch}/{args.stage}")
    elif args.routine:
        for i, l in enumerate(lines):
            m = RE_LABEL.match(l)
            if m and m.group(1) == args.routine:
                targets = [(i + 1, args.routine)]
                break
        if not targets:
            raise SystemExit(f"no routine {args.routine}")
    elif args.all_suffixed:
        seen = set()
        for n in sorted(set(re.findall(r"CINEMATIC_[A-Za-z0-9_]*_AMIGA_EXTRA(?:_\d+)?", "\n".join(lines)))):
            for i, l in enumerate(lines):
                if f"offset={n}," in l and n not in seen:
                    targets.append((i, n))
                    seen.add(n)
                    break
    else:
        raise SystemExit("pass --const, --routine or --all-suffixed")

    print(f"  {args.branch}/{args.stage}: {len(targets)} draw site(s)\n")
    for idx, what in targets:
        report(lines, idx, what)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
