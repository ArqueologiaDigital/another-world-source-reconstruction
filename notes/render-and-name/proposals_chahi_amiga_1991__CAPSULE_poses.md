# CAPSULE: pictures named by the index their dispatcher selects them with

## The index is in the bytecode

`DRAW_HERO_SPRITE_BY_VAR09_0E` decodes a selector and then dispatches:

```
    mov [0xF8], [0x09]
    shr [0xF8], 0x0004        ; the HIGH NIBBLE of [0x09] is the sub-index
    and [0xF8], 0x000F
    jne [0x0E], 0x00, <next group>
    je  [0xF8], 0x01, DRAW_HERO_POSE_0_1
    je  [0xF8], 0x02, DRAW_HERO_POSE_0_2
    ...
```

`[0x0E]` chooses a group, the high nibble of `[0x09]` chooses a frame in it, and
each target is a one-line routine that draws exactly one constant. So every
picture the dispatcher can reach has a `(group, index)` **out of the bytecode**
-- no render, no palette, no judgement.

That matters because these are otherwise the least tractable constants in the
stage: each is drawn by its own generated `DRAW_CIN_<n>` routine and nothing
else, so there is no run to read, no neighbour to compare with and no earned
routine word.

`notes/pose-dispatch/pose_index.py` extracts the mapping and checks that every
`(dispatcher, group, index)` triple is unique before any of it is used.

The existing routine names already encode the same pair -- `DRAW_HERO_POSE_0_1`
is group 0, index 1 -- so these names only put on the constant what the tree
already says about the routine.

## Why `FIGURE` and not `HERO`

`notes/actor-anchors/` measures 20 places where an actor word contradicts the
anchor it is drawn at, including these very routines: all eight of these draw at
`[BUDDY_X], [BUDDY_Y]` while their routines say HERO, and msdos calls the
identical (0, 5) slot `DRAW_ALIEN_POSE_0_5`. Three different actor words for one
dispatcher. The stage's own practice for figure art is the neutral `FIGURE`.

## One ambiguity, recorded rather than resolved

CAPSULE has **two** dispatchers with identical prologues, `LABEL_5DE8` and
`DRAW_HERO_SPRITE_BY_VAR09_0E`, and `LABEL_5DE8` assigns its own
`(0,0)..(0,6)` to `CINEMATIC_195..200`. So the stage has two pictures for
"group 0 index 1", one per dispatcher. Only the second dispatcher's targets are
named here, because its routine names already commit to the `POSE_<g>_<i>`
reading and the first's do not. `LABEL_5DE8`'s twelve remain numbered and want a
word that distinguishes the two sheets -- `DRAW_HERO_SUBFRAME_2_VAR09_LOW_OFFSET`
nearby suggests a sub-piece, which is not established enough to use yet.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_174 | CINEMATIC_CAPSULE_FIGURE_POSE_0_1 | high | 0x4C4E, the only picture `DRAW_HERO_POSE_0_1` draws, reached by `je [0xF8], 0x01` inside the `[0x0E] == 0` arm |
| CINEMATIC_175 | CINEMATIC_CAPSULE_FIGURE_POSE_0_2 | high | 0x4C7E, `DRAW_HERO_POSE_0_2`, `je [0xF8], 0x02` |
| CINEMATIC_176 | CINEMATIC_CAPSULE_FIGURE_POSE_0_3 | high | 0x4C98, `DRAW_HERO_POSE_0_3`, `je [0xF8], 0x03` |
| CINEMATIC_177 | CINEMATIC_CAPSULE_FIGURE_POSE_0_4 | high | 0x9660, `DRAW_HERO_POSE_0_4`, `je [0xF8], 0x04` |
| CINEMATIC_178 | CINEMATIC_CAPSULE_FIGURE_POSE_0_5 | high | 0x86FE, `je [0xF8], 0x05`. **Both** dispatchers give this picture group 0 index 5, and it is the one slot whose art msdos shares exactly (`ded0af914f4c`) |
| CINEMATIC_179 | CINEMATIC_CAPSULE_FIGURE_POSE_0_6 | high | 0x96AC, `DRAW_HERO_POSE_0_6`, `je [0xF8], 0x06` |
| CINEMATIC_169 | CINEMATIC_CAPSULE_FIGURE_POSE_4_1 | high | 0x4CCC, reached by `je [0xF8], 0x01` inside the `[0x0E] == 4` arm |
| CINEMATIC_167 | CINEMATIC_CAPSULE_FIGURE_POSE_7_1 | high | 0x4CFA, reached by `je [0xF8], 0x01` inside the `[0x0E] == 7` arm |

## What these names do not claim

They do not say what any pose looks like -- none of these was rendered, and
none needs to be. `POSE_<g>_<i>` restates the two numbers the dispatcher tests,
and those numbers are the only thing being asserted.

They do not say whose figure it is. Three actor words are in play for this one
dispatcher and `notes/actor-anchors/` explains why none of them may be used.

The index is a **dispatch** index, not a frame index: nothing plays these in
sequence, and `group 0 index 0` has no picture at all (`DRAW_HERO_POSE_0_0`
draws nothing), which is why the run starts at 1.
