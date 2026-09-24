# PRISON (amiga): Buddy gets up and tells Lester to follow him

Four sentences, frames 3073 to 3136:

- `ann:48092eb64dcc` on `CINEMATIC_438`: "frame of buddy starting to wake up
  from the fallen cage"
- `ann:3f4ea0707174` on `CINEMATIC_440`: "buddy waking up from the fallen cage"
- `ann:120e9175b6a3` on `CINEMATIC_441`: "buddy's right arm while tapping
  lester's back/shoulder"
- `ann:8a0eb8f7128f` on `CINEMATIC_447`: "buddy's right arm pointing forward --
  to the right -- as if indicating that lester must following him that way"

**The actor word is admissible here and it was not for the guard set.** Per
`../actor-anchors/README.md` it must come from the scene, and this scene is
fixed three independent ways: the routine follows the cage collapse, the owner
states that Buddy is jailed with Lester and wakes after the cage falls to help
him escape, and a published walkthrough gives the same order -- the cage falls
on the guard, the friend says something and runs off, and Lester then runs
right. The tree agrees rather than disagreeing: the body under these arms is
drawn by `PRISON_BUDDY_SIMPLE_DRAW_CIN164_167_CV291`.

**Getting up is measured, not looked at.** `ANIM_CIN_438_LOOP_VAR29`
(PRISON.asm:3630-3639) holds 438 for ten frames (`mov [0x29], 0x000A` then
`djnz`), then does `add [BUDDY_Y], 0x0005` and draws 439 and 440:

    438   39.0 x 35.0   10 leaves    widest, lowest    sprawled
    439   33.0 x 48.0    9 leaves
    440   27.0 x 56.0    9 leaves    narrowest, tallest  standing

Width falls 39 -> 33 -> 27 while height rises 35 -> 48 -> 56. That is a figure
getting off the floor, and 27.0 is the width
`CINEMATIC_PRISON_LIFT_BUDDY_SILHOUETTE` gives Buddy (29.0) rather than the
15.0 it gives Lester.

**The two arms are arms.** Both are drawn immediately after a call that lays the
body down, and their proportions say which is which:

    441   24.0 x 21.0   4 leaves   compact, and `play id=0x0073` fires on it
    447   35.0 x 11.5   6 leaves   wide and flat -- an arm held out straight

The routine also does `add [BUDDY_X], 0x0003` twice and calls
`PRISON_ACTOR_WALK_RIGHT_DRAW_PHASE_06`, so the figure is moving **right** --
the direction the pointing sentence gives and the walkthrough confirms.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_438 | CINEMATIC_PRISON_BUDDY_RISE_F0 | high | 0x8A2E, held ten frames by `mov [0x29], 0x000A` + `djnz` at the head of ANIM_CIN_438_LOOP_VAR29; 39.0x35.0, the widest and lowest of the three; annot:48092eb64dcc frame 3073, "buddy starting to wake up from the fallen cage" |
| CINEMATIC_439 | CINEMATIC_PRISON_BUDDY_RISE_F1 | high | 0x2A88, drawn after `add [BUDDY_Y], 0x0005`; 33.0x48.0, between F0 and F2 on both axes. No annotation of its own: it is the middle of a three-frame rise whose ends are annotated |
| CINEMATIC_440 | CINEMATIC_PRISON_BUDDY_RISE_F2 | high | 0x2AE8, last of the three; 27.0x56.0, the narrowest and tallest -- upright -- and 27.0 is the width CINEMATIC_PRISON_LIFT_BUDDY_SILHOUETTE gives Buddy (29.0) against Lester's 15.0; annot:3f4ea0707174 frame 3084, "buddy waking up from the fallen cage" |
| CINEMATIC_441 | CINEMATIC_PRISON_BUDDY_ARM_TAP | high | 0x8BAE, 24.0x21.0 in 4 leaves, drawn over the body laid down by PRISON_BUDDY_SIMPLE_DRAW_CIN164_167_CV291 at PRISON.asm:3706 and again at 3744, with `play id=0x0073, freq=0x14, vol=0x30` fired on the second; a compact limb, not a figure; annot:120e9175b6a3 frame 3114, "buddy's right arm while tapping lester's back/shoulder" |
| CINEMATIC_447 | CINEMATIC_PRISON_BUDDY_ARM_POINT_RIGHT | high | 0x882A, 35.0x11.5 in 6 leaves -- three times wider than tall, an arm held out straight, against the tap's compact 24.0x21.0; drawn twice at the end of the same sequence, in which the routine adds 0x0003 to BUDDY_X twice and calls PRISON_ACTOR_WALK_RIGHT_DRAW_PHASE_06, so the figure is moving right; annot:8a0eb8f7128f frame 3136, "pointing forward -- to the right -- as if indicating that lester must following him that way" |
