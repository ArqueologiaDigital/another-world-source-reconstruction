# PRISON: four hero stances and a lunge, with three signals agreeing

Six pictures at `[HERO_X],[HERO_Y]`. **#0138** applies, so the names come from
the art -- but here three independent things say the same thing about the
direction, which is worth writing down because a fourth appears to disagree.

## Three signals

**1. The signed bounding box**, the project's rule for a standing figure whose
anchor is at the feet:

```
  556  x[-17.5,   9.0]        561  x[ -9.0,  16.5]
  560  x[-17.5,  10.5]        567  x[-10.5,  17.5]     exact mirror
  222  x[-32.0,   8.0]        213  x[ -8.0,  32.0]     exact mirror
```

**2. `[0x04]`, set on the line before each.** The four stance routines open
with `SET_VAR04_TO_0000`, `_0010`, `_0020` and `_0030`:

```
  556  0x00      561  0x10        pose A, left and right
  560  0x20      567  0x30        pose B, left and right
```

`0x20` per pose and `0x10` per direction, which pairs the four and orients
them without reference to any picture.

**3. The named neighbour.** `DRAW_CIN_187_TO_222_2F_AT_8E66E193` draws
`CINEMATIC_PRISON_HERO_CROUCH_DOWN_LEFT` and then 222, and ends
`jmp HERO_WALK_LEFT_LOOP`. `DRAW_CIN_212_TO_213_2F_AT_6B0D0A47` draws
`CINEMATIC_PRISON_HERO_CROUCH_DOWN_RIGHT` and then 213.

## The signal that looks like it disagrees, and does not

The line immediately before `video offset=CINEMATIC_222` is
`add [HERO_X], 0x0001`, which would make it a rightward frame. It is not: its
routine opens with `sub [HERO_X], 0x0004` and the `add 0x0001` is a sub-step
inside a leftward move. Reading the adjacent arithmetic instead of the whole
routine is the mistake that had to be reverted once in this project already,
on six `BUDDY_<DIR>_FIRE_*` names whose signed bounding boxes pointed the
other way. The bounding box, the state variable and the named neighbour all
say left.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_556 | CINEMATIC_PRISON_HERO_STAND_LEFT | high | 26.5x49.0, 11 paths: the hero mid-stride, legs apart, both arms down, facing left. x[-17.5, 9.0]. Its routine sets `[0x04]` to 0x00 and moves `[HERO_X]` by -4, then holds the pose in a `je [HERO_ACTION_POS_MASK], 0x84` loop |
| CINEMATIC_561 | CINEMATIC_PRISON_HERO_STAND_RIGHT | high | 25.5x48.5, 11 paths, x[-9.0, 16.5]: the same pose facing right. `[0x04]` = 0x10, `[HERO_X]` +4 |
| CINEMATIC_560 | CINEMATIC_PRISON_HERO_ARM_OUT_LEFT | high | 28.0x49.0, **12 paths** -- one more than `STAND_LEFT` -- and the extra one is an arm held out horizontally, hand open, on the left. x[-17.5, 10.5], the exact mirror of `_RIGHT` about x = 0. `[0x04]` = 0x20 |
| CINEMATIC_567 | CINEMATIC_PRISON_HERO_ARM_OUT_RIGHT | high | 28.0x48.5, 12 paths, x[-10.5, 17.5]: the mirror, arm out to the right. `[0x04]` = 0x30. Held under `je [HERO_ACTION_POS_MASK], 0x88`, the only one of the four with 0x88 rather than 0x84 |
| CINEMATIC_222 | CINEMATIC_PRISON_HERO_LUNGE_LEFT | high | 40.0x34.0, 11 paths: a deep low stance, one leg stretched far out to the left. **40.0 wide against the stand's 26.5 and 34.0 tall against 49.0** -- the proportions are the pose. x[-32.0, 8.0]. Drawn immediately after `CINEMATIC_PRISON_HERO_CROUCH_DOWN_LEFT` and held in its own loop |
| CINEMATIC_213 | CINEMATIC_PRISON_HERO_LUNGE_RIGHT | high | 40.0x33.5, 11 paths, x[-8.0, 32.0]: the exact mirror. Drawn immediately after `CINEMATIC_PRISON_HERO_CROUCH_DOWN_RIGHT` |

## What these names do not claim

`ARM_OUT` is the twelfth path: one arm horizontal with an open hand. It does
not say what the hero is reaching for, or that he is reaching at all.

`LUNGE` is the proportion -- half again as wide as the standing pose and two
thirds as tall, with one leg extended. It does not claim a jump, a dodge or a
fall.

`CINEMATIC_134` and `CINEMATIC_280` are **left numbered**. They are white
bodies inside blue edges at 31.0x34.0 and 29.5x34.0, five paths each -- the
same treatment as `CINEMATIC_PRISON_XRAY_FLASH_LEFT/RIGHT` and the same 34.0
height as the lunge, but neither their width nor their signed box matches the
lunge's, so which pose they flash is not settled.
