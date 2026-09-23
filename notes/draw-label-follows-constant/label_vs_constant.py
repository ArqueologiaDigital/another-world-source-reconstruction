#!/usr/bin/env python3
"""A label whose only job is to draw one picture should say which picture.

Question answered
-----------------
Two things, from the same reading.

**Which draw-only labels can be named for free.** A label of the form

    DRAW_CIN_776:
        video offset=CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_3, x=.., y=..
        ret

is classified `res_index` by `naming_census.classify`, i.e. not semantic, and
the number in it is a *resource index*. Once the constant it draws has earned a
name, the label's number is worse than useless: it points at an index that no
longer exists anywhere in the file. The label has exactly one job and the
constant already names it, so the name transfers with no new claim.

**Which labels contradict the constant they draw.** The same comparison run the
other way finds labels that *are* semantic and disagree with their own picture.
`CAVES_DRAW_HERO_IDLE_LEFT_1` in msdos drew the constant that
`../laser-impact-anim/` identified as frame 0 of the rightward shot-impact
burst -- a 2.0 x 5.0 six-leaf spark, `canonical_md5` 80fe8a4c. One of the two
names is wrong, and a disagreement is worth surfacing even when this module
cannot say which side lost.

The rule, and what it will not do
---------------------------------
A label qualifies only when its body draws **exactly one** `video offset=`, that
operand is a constant with a semantic name, and the body reaches a `ret`
without calling anything. Anything that draws twice, draws nothing, or calls
out is left alone: a label over a sequence is not named by one of its frames.

The proposed name is `<STAGE>_DRAW_<constant>`, where `<constant>` is the
constant's name with `CINEMATIC_` and any leading `<STAGE>_` removed, so
`CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_3` in CAVES gives
`CAVES_DRAW_LASER_IMPACT_ANIM_RIGHT_3`. `naming_census.classify` calls that
`semantic`; it calls `DRAW_CIN_776` `res_index`.

Pass/fail
---------
Neither list is a failure, and the word-overlap test is deliberately not one.
It asks only whether a semantic label and its picture share a subject word, and
that is a prompt rather than a verdict: `CODEWHEEL_SYMBOL_DISPATCH_CASE_02`
draws `CINEMATIC_ALIEN_GLYPH_01` and shares nothing with it, yet both names are
correct -- one describes the mechanism, the other the subject. Only a case
settled by other evidence should be acted on, as `CAVES_DRAW_HERO_IDLE_LEFT_1`
was, by the `canonical_md5` in `../laser-impact-anim/`.

Usage
-----
    python3 notes/draw-label-follows-constant/label_vs_constant.py
    python3 notes/draw-label-follows-constant/label_vs_constant.py --proposals
    python3 notes/draw-label-follows-constant/label_vs_constant.py \
        --branches chahi_amiga_1991 dos_1992
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
from naming_census import classify                      # noqa: E402

RE_LBL = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
# BOTH draw forms. `video offset=` reads the stage's own cinematic bank and
# `video type=0, offset=` reads the shared video2 bank, and a label that draws
# a body, an arm and a shadow uses all of them. Matching only the first form
# made DRAW_VIDEO_036_037_AND_HERO_STOP_RIGHT_FRAME_2_RET -- which draws
# HERO_WALK_RIGHT_BODY_F09, HERO_WALK_RIGHT_ARM_F09 and then the shadow --
# look like a one-picture label, and it would have been renamed after the
# shadow alone.
RE_VID = re.compile(r"^\s*video\s+(?:type=\d+,\s*)?offset="
                    r"([A-Za-z_][A-Za-z0-9_]*)")
# A body that branches away is a DISPATCH, not a draw stub. PRISON's
# LABEL_3BB3 ends `video offset=..._RIGHT_5 / mov [0x13], 0xFFFE / ret` and
# would otherwise look like a one-picture label, when in fact it is the entry
# of the six-way ladder and the other five frames live in the labels it jumps
# to. Naming it after its fallthrough frame would be flatly wrong.
RE_CALL = re.compile(r"^\s*(call|jmp|je|jne|jl|jle|jg|jge)\s")
RE_RET = re.compile(r"^\s*ret\s*$")
# Both placeholder forms a picture can still be wearing: CINEMATIC_<index> in
# a stage's own bank, and CV_<hex> in the shared video2 bank. Transferring
# either to a label moves a placeholder rather than a name.
RE_NUMERIC = re.compile(r"^(CINEMATIC_\d+|CV_[0-9A-F]{4})$")
# Words that carry no subject, so two names sharing only these are not
# actually agreeing about anything.
FILLER = {"DRAW", "CIN", "AT", "THEN", "AND", "TO", "OF", "THE", "L", "F"}


def bodies(lines: list[str]):
    """Yield (label, body_lines) for every label, up to the next label."""
    cur, start = None, 0
    for i, line in enumerate(lines):
        if m := RE_LBL.match(line):
            if cur is not None:
                yield cur, lines[start:i]
            cur, start = m.group(1), i + 1
    if cur is not None:
        yield cur, lines[start:]


def sole_draw(body: list[str]) -> str | None:
    """The one constant a label draws, if drawing it is ALL the label does.

    "All" is meant strictly. 30 of the one-draw labels also `play` a sound and
    their current names record its operands --
    `DRAW_CV108_PLAY_60_F0F_V2A_C1` is `play id=0x0060, freq=0x0F, vol=0x2A,
    channel=0x01` spelled out -- and others `fill`, `selectVideoPage` or do
    arithmetic. A picture does not name a routine that also makes a noise, so
    taking the constant's name there would lose what the old name knew.
    Only a body that draws once and rets qualifies.
    """
    drawn, saw_ret = [], False
    for line in body:
        if RE_RET.match(line):
            saw_ret = True
            break
        if not line.strip() or line.lstrip().startswith(";"):
            continue
        if m := RE_VID.match(line):
            drawn.append(m.group(1))
            continue
        return None
    return drawn[0] if saw_ret and len(drawn) == 1 else None


def words(name: str, stage: str) -> set[str]:
    name = re.sub(r"^CINEMATIC_", "", name)
    name = re.sub(rf"^{stage}_", "", name)
    return {w for w in name.split("_") if w and not w.isdigit()} - FILLER


def proposed(const: str, stage: str) -> str:
    base = re.sub(r"^CINEMATIC_", "", const)
    base = re.sub(rf"^{stage}_", "", base)
    return f"{stage}_DRAW_{base}"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--branches", nargs="+")
    ap.add_argument("--proposals", action="store_true")
    args = ap.parse_args()

    nameable, conflicts, collided = [], [], []
    stats = collections.Counter()
    for f in sorted((SRC / "src" / "levels").glob("*/[A-Z]*.asm")):
        branch, stage = f.parent.name, f.stem
        if args.branches and branch not in args.branches:
            continue
        lines = f.read_text(errors="replace").splitlines()
        here: list = []
        for label, body in bodies(lines):
            const = sole_draw(body)
            if const is None:
                continue
            stats["draw-one-picture labels"] += 1
            if RE_NUMERIC.match(const):
                stats["constant still unnamed"] += 1
                continue
            if classify(re.sub(r"^CINEMATIC_", "", const)) != "semantic":
                stats["constant's own name is not semantic either"] += 1
                continue
            want = proposed(const, stage)
            if label == want:
                stats["label already agrees"] += 1
                continue
            kind = classify(label)
            if kind != "semantic":
                here.append((branch, stage, label, const, want))
            elif words(label, stage) & words(const, stage):
                stats["label semantic and shares a subject word"] += 1
            else:
                stats["label semantic, no shared word (reported, not "
                      "failed)"] += 1
                conflicts.append((branch, stage, label, const, want))
        # Two labels in one file can draw the same picture -- LAKE has a
        # stand pose and a walk frame that both finish on the same shadow.
        # They cannot both take its name, and choosing between them is not
        # this module's call (#0120), so neither is proposed.
        seen = collections.Counter(w for *_r, w in here)
        existing = {m.group(1) for line in lines
                    if (m := RE_LBL.match(line))}
        for row in here:
            if seen[row[4]] > 1:
                collided.append(row)
                stats["** two labels draw it; neither named"] += 1
            elif row[4] in existing:
                collided.append(row)
                stats["** proposed name already exists in the file"] += 1
            else:
                stats["nameable"] += 1
                nameable.append(row)

    if args.proposals:
        by: dict[tuple, list] = {}
        for branch, stage, label, const, want in nameable + conflicts:
            by.setdefault((branch, stage), []).append((label, const, want))
        for (branch, stage), rows in sorted(by.items()):
            print(f"\n----- {branch} / {stage} -----")
            print("| routine | proposed name | confidence | evidence |")
            print("| --- | --- | --- | --- |")
            for label, const, want in rows:
                print(f"| {label} | {want} | high | its body draws "
                      f"`{const}` and nothing else, then rets; the constant "
                      f"already carries the name |")
        return 0

    print(f"{stats['draw-one-picture labels']} label(s) whose body draws "
          f"exactly one picture and rets\n")
    for k, v in stats.most_common():
        if k != "draw-one-picture labels":
            print(f"  {v:>5}  {k}")

    if conflicts:
        print(f"\n{len(conflicts)} semantic label(s) share no subject word "
              f"with the picture they draw.\nThis is a PROMPT, not a verdict: "
              f"a label may name the mechanism (CODEWHEEL_SYMBOL_DISPATCH_"
              f"CASE_02)\nwhile the constant names the subject "
              f"(CINEMATIC_ALIEN_GLYPH_01), and both are right.")
        for branch, stage, label, const, _w in conflicts:
            print(f"  {branch}/{stage:<9}{label:<38}draws {const}")
    if collided:
        print(f"\n{len(collided)} held back -- the derived name is not free:")
        for branch, stage, label, const, want in collided[:12]:
            print(f"  {branch}/{stage:<9}{label:<40}-> {want}")
        if len(collided) > 12:
            print(f"  ... and {len(collided) - 12} more")
    if nameable:
        print(f"\n{len(nameable)} label(s) nameable from their own picture:")
        for branch, stage, label, const, want in nameable:
            print(f"  {branch}/{stage:<9}{label:<18}-> {want}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
