# CAVES: a bullet drawn at fourteen angles

`DRAW_BULLET_FROM_VAR_E7_E8_E9` loads `[0x21], [0x22], [0x23]` from
`[0xE7], [0xE8], [0xE9]` -- position and **zoom** -- calls
`DRAW_CIN_387_IF_VAR_E6_VALID`, and then does `sub [0xE6], 0x0001`. So `[0xE6]`
is an angle that steps down by one every frame while the projectile flies, and
the routine it calls is a fourteen-way dispatch on it, from -7 to +6.

The heights are symmetric about the middle and every member is **two leaves**:

```
  angle   -7  -6  -5  -4  -3  -2  -1   0  +1  +2  +3  +4  +5  +6
  height   8   8   6   6   4   4   3   3   4   4   6   6   8   8
  width    6   6   7   7   7   7   7   7   7   7   7   7   6   6
```

Rendered at palette 9 and cropped to their own extents: one dark wedge with a
pale stripe down its length, pivoting about its centre -- steeply tilted one way
at -7, flat at 0, steeply tilted the other at +6. Fourteen angles of one object,
which is exactly what a height that falls to 3 and climbs back to 8 means when
the width never moves.

`CINEMATIC_354` (2.0x4.0 in 2 leaves, paler than the rest) is drawn **with** the
bullet at angles +3, +4, +5 and +6 and at no other angle. A small bright mark
that appears only on one half of the rotation is a glint, and that is the one
`medium` row here.

The two ends are guards rather than equalities -- `jg [0xE6], 0xFFF9` catches
everything at -7 or below and `jg [0xE6], 0x05` everything at +6 or above -- so
`_7` and `_6` name the arm, not a single value.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_367 | CINEMATIC_CAVES_BULLET_ANGLE_MINUS_7 | high | 0x7BA0, 6.0x8.0 in 2 leaves; the `jg [0xE6], 0xFFF9` guard: every value of -7 or less |
| CINEMATIC_366 | CINEMATIC_CAVES_BULLET_ANGLE_MINUS_6 | high | 0xC210, 6.0x8.0 in 2 leaves; `[0xE6] == 0xFFFA` |
| CINEMATIC_365 | CINEMATIC_CAVES_BULLET_ANGLE_MINUS_5 | high | 0x7CC8, 7.0x6.0 in 2 leaves; `[0xE6] == 0xFFFB` |
| CINEMATIC_364 | CINEMATIC_CAVES_BULLET_ANGLE_MINUS_4 | high | 0xC21C, 7.0x6.0 in 2 leaves; `[0xE6] == 0xFFFC` |
| CINEMATIC_363 | CINEMATIC_CAVES_BULLET_ANGLE_MINUS_3 | high | 0x7CE4, 7.0x4.0 in 2 leaves; `[0xE6] == 0xFFFD` |
| CINEMATIC_362 | CINEMATIC_CAVES_BULLET_ANGLE_MINUS_2 | high | 0xC228, 7.0x4.0 in 2 leaves; `[0xE6] == 0xFFFE` |
| CINEMATIC_361 | CINEMATIC_CAVES_BULLET_ANGLE_MINUS_1 | high | 0xC234, 7.0x3.0 in 2 leaves; `[0xE6] == 0xFFFF` |
| CINEMATIC_360 | CINEMATIC_CAVES_BULLET_ANGLE_ZERO | high | 0x7D00, 7.0x3.0 in 2 leaves; `[0xE6] == 0` |
| CINEMATIC_359 | CINEMATIC_CAVES_BULLET_ANGLE_PLUS_1 | high | 0xC240, 7.0x4.0 in 2 leaves; `[0xE6] == 1` |
| CINEMATIC_358 | CINEMATIC_CAVES_BULLET_ANGLE_PLUS_2 | high | 0x7D1C, 7.0x4.0 in 2 leaves; `[0xE6] == 2` |
| CINEMATIC_357 | CINEMATIC_CAVES_BULLET_ANGLE_PLUS_3 | high | 0xC24C, 7.0x6.0 in 2 leaves; `[0xE6] == 3` |
| CINEMATIC_356 | CINEMATIC_CAVES_BULLET_ANGLE_PLUS_4 | high | 0x7D38, 7.0x6.0 in 2 leaves; `[0xE6] == 4` |
| CINEMATIC_355 | CINEMATIC_CAVES_BULLET_ANGLE_PLUS_5 | high | 0xC258, 6.0x8.0 in 2 leaves; `[0xE6] == 5` |
| CINEMATIC_353 | CINEMATIC_CAVES_BULLET_ANGLE_PLUS_6 | high | 0x7D54, 6.0x8.0 in 2 leaves; the `jg [0xE6], 0x05` fall-through: every value of 6 or more |
| CINEMATIC_354 | CINEMATIC_CAVES_BULLET_GLINT | medium | 0xC264, 2.0x4.0 in 2 leaves and paler than the wedge; drawn beside the bullet at angles +3, +4, +5 and +6 and nowhere else |
