# CAVES: the arm-out cycle's rest pose, and the renumber it forces

`proposals_chahi_amiga_1991__CAVES_armout.md` named the right-hand half of this
cycle and recorded one thing it could not act on in the same breath: **`CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F0`
is not left-facing.**

Nine draw sites in six routines say so, in both ports:

```
  LABEL_23CC   x=[HERO_X], y=[HERO_Y]   twice
  LABEL_23FC   x=198, y=43  and  x=198, y=44
  LABEL_2416   the loop BOTH directions jump back to
  LABEL_2432   x=[HERO_X], y=[HERO_Y]
  LABEL_24CF   before the branch that chooses direction, and again at the end
  LABEL_2551   the RIGHT-hand loop, at its end
```

It is drawn once before `je [0x63], 0x02, LABEL_2551` picks a direction, and
again at the close of *both* loops before each jumps to `LABEL_2416`. A frame
the right-facing routine draws cannot be called left-facing.

So it becomes `CINEMATIC_CAVES_HERO_ARM_OUT_REST`, and the seven directional frames that followed it
close up: `LEFT_F1..F7` become `LEFT_F0..F6`. After this the two halves
correspond index for index --

```
  LEFT_F0 <-> RIGHT_F0 ... LEFT_F6 <-> RIGHT_F6
```

-- which is what the step deltas said all along: the left routine's `-1, -9, -5,
-8, -7, -4, -1` against the right's `+1, +9, +5, +8, +7, +4, +1`, and five of
the seven frames measuring exactly alike.

This is a **chained** rename -- `F1`'s new name is `F0`'s old one -- so every
row goes in one batch, which is the rule
`../render-and-name/README.md` records under "A renumber that touches a shared
draw line is global, not branch-scoped". Nothing here is shared: the family
lives in `amiga__entry.inc` and `amiga__post_INIT_VARS_E6_68_69_6B.inc` for
amiga and the matching `dos__` files for msdos, so each branch takes the batch
on its own.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F0 | CINEMATIC_CAVES_HERO_ARM_OUT_REST | high | nine draw sites in six routines, including `LABEL_2416` -- the loop both directions return to -- and the last draw of the RIGHT-hand `LABEL_2551`. Unchanged art |
| CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F1 | CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F0 | high | the renumber the line above forces: this frame is the first, second, ... of the left-facing run once the rest pose is out of the family |
| CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F2 | CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F1 | high | the renumber the line above forces: this frame is the first, second, ... of the left-facing run once the rest pose is out of the family |
| CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F3 | CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F2 | high | the renumber the line above forces: this frame is the first, second, ... of the left-facing run once the rest pose is out of the family |
| CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F4 | CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F3 | high | the renumber the line above forces: this frame is the first, second, ... of the left-facing run once the rest pose is out of the family |
| CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F5 | CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F4 | high | the renumber the line above forces: this frame is the first, second, ... of the left-facing run once the rest pose is out of the family |
| CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F6 | CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F5 | high | the renumber the line above forces: this frame is the first, second, ... of the left-facing run once the rest pose is out of the family |
| CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F7 | CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F6 | high | the renumber the line above forces: this frame is the first, second, ... of the left-facing run once the rest pose is out of the family |

After it, `CINEMATIC_CAVES_HERO_ARM_OUT_REST` stands alone and `..._LEFT_F0..F6` and `..._RIGHT_F0..F6`
are two gapless runs of seven that answer to each other.
