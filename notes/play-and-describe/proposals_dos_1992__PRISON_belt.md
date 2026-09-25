# PRISON: the belt, and the actor word that did not survive

`ann:f655cd1b6433` on `CINEMATIC_240` (f151): "red belt around the waist of the
guard". `ann:399cb78b12a6` on `CINEMATIC_168` (f203): "red belt of the guard".

Six agents derived names for eleven held constants and thirteen independent
verifiers tried to refute them; ten of thirteen rows fell. These two are what
survived, **minus the word the verifiers split on**.

## What is measured, and re-measured

    CINEMATIC_240  0xC4FA  x[-2.0, 8.0]  y[-37.5, -34.5]  10.0 x 3.0  1 leaf
    CINEMATIC_168  0xC408  x[-8.0, 2.0]  y[-37.5, -34.5]  10.0 x 3.0  1 leaf

An exact mirror about the anchor, at one y-band. Waist height is measured, not
asserted: `CINEMATIC_PRISON_FIGURE_POSE_LEFT_0_1` puts the head at y[-59.5,-48.5]
with feet at 0, so a bar at y[-37.5,-34.5] sits about sixty per cent up the
figure.

**The direction is forced and there is no crossover.** Every caller of
`DRAW_CIN_240_IF_VAR09_EQ_1` is a LEFT-facing draw phase and every caller of
`DRAW_CIN_168_IF_VAR09_EQ_1` is a RIGHT-facing one -- 16 and 16 by the
`call` sites, zero either way. The human's own sentences agree independently:
f183 "while he's walking to the left" with 240 on screen, f214 and f220 "walks
to the right" with 168.

**No index is forced, so none is proposed.** 0xC408, 0xC476, 0xC4DE, 0xC4FA is
not a contiguous run and `CINEMATIC_352` sits inside it.

## Why the name says FIGURE and not GUARD

Two reasons, and the first is the stronger.

**The belt is an appearance class, not a character's prop.** Both constants are
reachable only through `and [0xF8], 0x000F` / `je [0xF8], 0x01` on `[0x09]`,
which is word 5 of the eight-word actor record the scheduler rotates through
`ACTOR_X`/`ACTOR_Y` (`../actor-anchors/README.md`, "the uniform is a field in
the actor record"). Any actor whose record carries nibble 1 wears it. Which
characters are in that class is a different question from what the picture is.

**And the verifiers split on it.** Of a mirror pair whose every other component
re-measured identically, one verifier could not refute `GUARD_BELT_LEFT` and
another refuted `GUARD_BELT_RIGHT` on that single word, proposing
`FIGURE_BELT_RIGHT`. A word two independent attempts disagree about, on two
halves of one object, is not established.

The guard reading is not discarded -- it is in the evidence column, which is
where `docs/NAMING.md` puts a subject word that a measurement has not confirmed.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_240 | CINEMATIC_PRISON_FIGURE_BELT_LEFT | high | 0xC4FA, one leaf, 10.0x3.0 at x[-2.0,8.0] y[-37.5,-34.5] -- the exact mirror of CINEMATIC_168 about the anchor, at waist height on a figure whose head measures y[-59.5,-48.5]; sole draw site PRISON.asm:9625 in DRAW_CIN_240, reached only through DRAW_CIN_240_IF_VAR09_EQ_1 which gates on the low nibble of [0x09], word 5 of the actor record, so this is an appearance class and not one character's prop; all 16 call sites are LEFT-facing draw phases with zero crossover; annot:f655cd1b6433 frame 151, "red belt around the waist of the guard" -- the guard reading is recorded here and deliberately not in the name, because two independent verifiers split on that word |
| CINEMATIC_168 | CINEMATIC_PRISON_FIGURE_BELT_RIGHT | high | 0xC408, one leaf, 10.0x3.0 at x[-8.0,2.0] y[-37.5,-34.5] -- same y-band, mirrored x; sole draw site PRISON.asm:10874 in DRAW_CIN_168, reached only through DRAW_CIN_168_IF_VAR09_EQ_1 on the same nibble gate; all 16 call sites are RIGHT-facing draw phases with zero crossover, and the human's f214 and f220 sentences say "walks to the right" with this constant on screen; annot:399cb78b12a6 frame 203, "red belt of the guard" |
