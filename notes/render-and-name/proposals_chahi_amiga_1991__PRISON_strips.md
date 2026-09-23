# PRISON: the lower half of the lift-shaft strip ladder

One routine picks a strip by the y it is drawn at:

```
  ... video LIFT_SHAFT_STRIP_4 ... STRIP_3 ... STRIP_2 ... STRIP_1
  jg [0x22], 0x6E, LABEL_7929
  video LIFT_SHAFT_STRIP_0            <- y <= 0x6E, 1 pixel tall
LABEL_7929:
  video CINEMATIC_096                 <- 3 tall
  video CINEMATIC_095                 <- 5 tall
  jg [0x22], 0xB0, LABEL_7953
  video CINEMATIC_094                 <- 7 tall
LABEL_7953:
  jg [0x22], 0xC8, out
  video CINEMATIC_093                 <- 8 tall
```

All nine are **60.0 wide in ten leaves**, and the height is the whole content:
1, 3, 5, 7, 9 for `STRIP_0..4` and 3, 5, 7, 8 for the four numbered ones. The
existing family's index runs on height, so 3, 5 and 7 are already taken and
these four cannot extend it -- they are a second run of the same construction,
selected by the y bands **below** the ones that reach `STRIP_0`, which is a
shaft narrowing to a vanishing point and widening again beneath it.

They are a separate gapless family indexed on height, in the order the y bands
reach them.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_096 | CINEMATIC_PRISON_LIFT_SHAFT_STRIP_LOWER_0 | medium | 0x6DD6, 60.0x**3.0** in 10 leaves, the first band past `jg [0x22], 0x6E`; a different drawing from `STRIP_1` at the same size (`74e981ceaeea` against `791325c8e881`) |
| CINEMATIC_095 | CINEMATIC_PRISON_LIFT_SHAFT_STRIP_LOWER_1 | medium | 0x6E02, 60.0x**5.0** in 10 leaves, the next band; a different drawing from `STRIP_2` at the same size |
| CINEMATIC_094 | CINEMATIC_PRISON_LIFT_SHAFT_STRIP_LOWER_2 | medium | 0x6E2E, 60.0x**7.0** in 10 leaves, the band below `jg [0x22], 0xB0`; a different drawing from `STRIP_3` |
| CINEMATIC_093 | CINEMATIC_PRISON_LIFT_SHAFT_STRIP_LOWER_3 | medium | 0x6E5A, 60.0x**8.0** in 10 leaves, the lowest band, `jg [0x22], 0xC8`; the tallest of the nine after `STRIP_4` |
