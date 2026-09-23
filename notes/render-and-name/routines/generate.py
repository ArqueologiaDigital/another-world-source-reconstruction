#!/usr/bin/env python3
"""Regenerate the PRISON wake-closeup routine tables from the bytecode.

Question answered
-----------------
Twenty of the twenty-four labels in this scene are rungs of a `jg [var], N`
ladder, and the only honest name for such a label is its own guard: the arm
handles `[var] <= N`, so it is `..._UPTO_<N>`. Writing twenty of those by
hand is how a threshold gets transcribed wrong, and
`apply_routine_renames.py` would reject the row but only after someone had
read a table that looked right.

So the tables are not written, they are **read off the disassembly** by
`../ladder_rungs.py`, whose `rungs(..., with_label=True)` returns, per rung,
the threshold guarded on, the picture drawn and the label heading the arm.
This script turns that into the four-column proposal tables beside it, one
per branch.

Signal read
-----------
Per row: the label (column 1) is the one `ladder_rungs` reports for that rung,
and the `_UPTO_` tail (column 2) is `int(threshold, 16)` of that same rung.
`apply_routine_renames.py` re-derives the guard independently, from the
routine's own first line, and rejects any row where the two disagree -- so a
mistake here cannot reach the tree. Four rows are not ladder rungs and carry
hand-written evidence: the backdrop painter, the frame routine, the join after
the pupil ladder and the frame tail.

Run it
------
    python3 notes/render-and-name/routines/generate.py

It overwrites `proposals_<branch>__PRISON.md` in this directory. Re-running
after the labels have been applied yields tables whose left column no longer
matches anything, which the applier reports as "not a routine" -- that is the
expected state once the batch has landed, not a failure.
"""

from __future__ import annotations

import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))
from ladder_rungs import rungs                                  # noqa: E402

# (frame routine, pupil-ladder join, frame tail, backdrop painter) per branch.
# These four are not ladder rungs, so they cannot be read off a `jg` chain.
HEAD = {
    "chahi_amiga_1991": ("LABEL_4D31", "LABEL_4D8F", "LABEL_4E75",
                         "DRAW_CIN_683_TO_685_3F_AT_1EB7324B"),
    "dos_1992": ("PRISON_DRAW_CIN_656_AND_682_OR_VARIANT_PER_VAR16",
                 "LABEL_4E38",
                 "PRISON_BREAK_THEN_JMP_TO_PRISON_DRAW_CIN_656_AND_682_"
                 "OR_VARIANT_PER_VAR16",
                 "DRAW_CIN_683_TO_685_3F_AT_1EB7324B"),
    "cartridge_1992": ("LABEL_4EDA", "LABEL_4F38", "LABEL_501E",
                       "DRAW_CIN_683_TO_685_3F_AT_1EB7324B"),
}
P = "PRISON_WAKE_CLOSEUP_"
# First rung to propose a name for. Earlier rungs of each ladder are either
# the routine head (named above) or already carry an earned name.
FIRST = {"0x16": 2, "0x15": 1}


def table(branch: str) -> list[tuple[str, str, str]]:
    head, join, tail, paint = HEAD[branch]
    rows = [
        (paint, f"{P}PAINT_BACKDROP",
         "sets palette 0x0B, fills page 0, draws `FACE_HALF_0`, `_HALF_1` "
         "and `_IRIS_STRIATIONS` at 160,100, copies page 0 to 0xFF and "
         "selects it. It paints the held backdrop of the closeup and nothing "
         "else; the old name listed the three picture numbers, which are now "
         "names"),
        (head, f"{P}DRAW_FRAME",
         "the routine the whole closeup loops on: it draws `PUPIL_BASE`, "
         "then picks one pupil off the `[0x16]` ladder, then the glint, then "
         "one eyelid off the `[0x15]` ladder. `setup channel=0x03` points at "
         "it and its own tail jumps back to it"),
        (join, f"{P}DRAW_GLINT_THEN_EYELID",
         "every rung of the `[0x16]` pupil ladder jumps here. It draws "
         "`EYE_GLINT` on top of whichever pupil was chosen and falls into "
         "rung 0 of the `[0x15]` eyelid ladder"),
        (tail, f"{P}NEXT_FRAME",
         f"`break` then `jmp {head}`: every rung of the eyelid ladder jumps "
         "here, so it is the end of one frame of the closeup"),
    ]
    for var, fam in (("0x16", "PUPIL"), ("0x15", "EYELID")):
        rr = rungs(branch, "PRISON", var, with_label=True)
        anchor = head if var == "0x16" else join
        i0 = next(i for i, r in enumerate(rr) if r[2] == anchor)
        run = rr[i0:]
        end = next((i for i, r in enumerate(run[1:], 1) if r[0] == "else"),
                   len(run) - 1)
        run = run[:end + 1]
        for k, (thr, const, lab) in enumerate(run):
            # A rung already carrying an earned name is left alone.
            if k < FIRST[var] or not lab.startswith(("LABEL_", "INLINE_")):
                continue
            pic = const.replace("CINEMATIC_", "")
            if thr == "else":
                word = "RAISED" if fam == "EYELID" else "WIDE"
                rows.append((lab, f"{P}{fam}_FULLY_{word}",
                             f"the `else` block of the `[{var}]` ladder, rung "
                             f"{k} of {len(run)}: reached when no threshold "
                             f"matched, and it draws `{pic}`"))
            else:
                rows.append((lab, f"{P}{fam}_UPTO_{int(thr, 16):02X}",
                             f"rung {k} of {len(run)} of the `[{var}]` "
                             f"ladder. Its own first line is `jg [{var}], "
                             f"{thr}`, so the arm handles `[{var}] <= {thr}` "
                             f"and draws `{pic}`"))
    return rows


def main() -> int:
    for branch in HEAD:
        rows = table(branch)
        out = HERE / f"proposals_{branch}__PRISON.md"
        body = [
            f"# PRISON wake closeup -- routine labels, {branch}",
            "",
            "Generated by `generate.py` beside this file, which reads the",
            f"`jg [var], N` chains out of `{branch}/PRISON.asm` through",
            "`../ladder_rungs.py`. Every `_UPTO_<hex>` tail is that label's",
            "**own first-line guard immediate**, which is exactly what",
            "`apply_routine_renames.py` re-derives and checks it against.",
            "",
            "| routine | proposed name | confidence | evidence |",
            "| --- | --- | --- | --- |",
        ]
        body += [f"| {o} | {n} | high | {e} |" for o, n, e in rows]
        out.write_text("\n".join(body) + "\n")
        print(f"  {out.name}: {len(rows)} row(s)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
