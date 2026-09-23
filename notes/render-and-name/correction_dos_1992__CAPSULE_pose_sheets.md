# CAPSULE (msdos): the two pose sheets are the wrong way round

## What the tree says today

msdos CAPSULE has **two** sprite dispatchers, and `pose_index.py` prints them
side by side:

```
  DRAW_HERO_SPRITE_BY_VAR09_0E     group 0 index 0..7 -> ..._FIGURE_POSE_RIGHT_0_0..0_7
  DRAW_ALIEN_SPRITE_BY_VAR09_0E    group 0 index 0..7 -> CINEMATIC_101 .. 107
```

amiga has the same two, and there the first one draws `..._RIGHT_0_*` while the
other draws `..._LEFT_0_*`. So one of the two ports has the sheets swapped, and
`canonical_md5` says which.

## Every constant, checked against amiga

The sheet msdos calls RIGHT is amiga's LEFT, slot for slot:

```
  msdos RIGHT_0_0  59cd2acdd559  ==  amiga LEFT_0_0        RIGHT_0_4  0304675ea1fe  ==  amiga LEFT_0_4
  msdos RIGHT_0_1  efff81c288d3  ==  amiga LEFT_0_1        RIGHT_0_5  ded0af914f4c  ==  amiga LEFT_0_5
  msdos RIGHT_0_2  2684267c3225  ==  amiga LEFT_0_2        RIGHT_0_6  9e88875b5e70  ==  amiga LEFT_0_6
  msdos RIGHT_0_3  5f2c6239c153  ==  amiga LEFT_0_3        RIGHT_0_7  efff81c288d3  ==  amiga LEFT_0_1
```

and the numbered sheet is amiga's RIGHT:

```
  102  3c3dc6efc02a  ==  amiga RIGHT_0_1        105  0f44eaa8dcbd  ==  amiga RIGHT_0_4
  103  5ba45a9ff42e  ==  amiga RIGHT_0_2        106  ccf854b75fb2  ==  amiga RIGHT_0_6
  104  7d636087d59f  ==  amiga RIGHT_0_3
```

101 and 107 have no amiga twin -- amiga's right sheet has no slot 0 or 7 -- but
101 is PRISON's and CAVES' `..._RIGHT_0_0` and 107 is their `..._RIGHT_0_1`,
which is the same repeat msdos' left sheet makes at its own slot 7.

Groups 4 and 7 go the same way: msdos `RIGHT_7_0` is `a0e2157ee3a9`, amiga's
`LEFT_7_0`; `RIGHT_7_1` is `d239bdc0e993`, amiga's `LEFT_7_1`; `RIGHT_4_3` is
`9217449b78f4`, amiga's `LEFT_4_3`. And the numbered `094` (`df32e229a4b5`) and
`096` (`80efa54fd2bf`) are amiga's `RIGHT_7_1` and `RIGHT_4_1`, which is also
what the ALIEN dispatcher's group 7 index 1 and group 4 index 1 say.

This is six of the eleven rows `../cross-port-art/name_art_agreement.py` has
been reporting as "name on the wrong constant".

## What this batch does not settle

amiga's `LEFT_0_1` is **4 leaves** and its `RIGHT_0_1` is **5**. Two drawings of
one figure mirrored have the same leaf count -- that is the whole basis of
`../mirror-families/` -- so these two sheets are not one figure facing two ways.
They are two different figures, which is exactly what msdos' own labels say:
`DRAW_HERO_SPRITE_BY_VAR09_0E` and `DRAW_ALIEN_SPRITE_BY_VAR09_0E`.

So `LEFT`/`RIGHT` is probably the wrong axis for this family in all three
stages. That is a much larger correction than this one and is recorded in
`../HANDOFF.md`. **This batch only makes msdos agree with amiga**, which is what
the audit is measuring and what the record needs either way: whatever the pair
of sheets turns out to be called, the two ports must call the same art the same
thing.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_0 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_0_0 | high | `59cd2acdd559` -- amiga's `..._LEFT_0_0`; drawn by `DRAW_HERO_SPRITE_BY_VAR09_0E` group 0 index 0, the dispatcher amiga's left sheet hangs off |
| CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_1 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_0_1 | high | `efff81c288d3` -- amiga's `..._LEFT_0_1`; drawn by `DRAW_HERO_SPRITE_BY_VAR09_0E` group 0 index 1, the dispatcher amiga's left sheet hangs off |
| CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_2 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_0_2 | high | `2684267c3225` -- amiga's `..._LEFT_0_2`; drawn by `DRAW_HERO_SPRITE_BY_VAR09_0E` group 0 index 2, the dispatcher amiga's left sheet hangs off |
| CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_3 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_0_3 | high | `5f2c6239c153` -- amiga's `..._LEFT_0_3`; drawn by `DRAW_HERO_SPRITE_BY_VAR09_0E` group 0 index 3, the dispatcher amiga's left sheet hangs off |
| CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_4 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_0_4 | high | `0304675ea1fe` -- amiga's `..._LEFT_0_4`; drawn by `DRAW_HERO_SPRITE_BY_VAR09_0E` group 0 index 4, the dispatcher amiga's left sheet hangs off |
| CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_5 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_0_5 | high | `ded0af914f4c` -- amiga's `..._LEFT_0_5`; drawn by `DRAW_HERO_SPRITE_BY_VAR09_0E` group 0 index 5, the dispatcher amiga's left sheet hangs off |
| CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_6 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_0_6 | high | `9e88875b5e70` -- amiga's `..._LEFT_0_6`; drawn by `DRAW_HERO_SPRITE_BY_VAR09_0E` group 0 index 6, the dispatcher amiga's left sheet hangs off |
| CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_7 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_0_7 | high | `efff81c288d3` -- amiga's `..._LEFT_0_1`; drawn by `DRAW_HERO_SPRITE_BY_VAR09_0E` group 0 index 7, the dispatcher amiga's left sheet hangs off |
| CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_7_0 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_7_0 | high | `a0e2157ee3a9` -- amiga's `..._LEFT_7_0`; same dispatcher, group 7 index 0 |
| CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_7_1 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_7_1 | high | `d239bdc0e993` -- amiga's `..._LEFT_7_1`; same dispatcher, group 7 index 1 |
| CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_4_3 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_4_3 | high | `9217449b78f4` -- amiga's `..._LEFT_4_3`; same dispatcher, group 4 index 3 |
| CINEMATIC_101 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_0 | high | `c05a8bca995a` -- PRISON's and CAVES' `..._FIGURE_POSE_RIGHT_0_0`; drawn by `DRAW_ALIEN_SPRITE_BY_VAR09_0E` group 0 index 0 |
| CINEMATIC_102 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_1 | high | `3c3dc6efc02a` -- amiga's `..._RIGHT_0_1`; drawn by `DRAW_ALIEN_SPRITE_BY_VAR09_0E` group 0 index 1 |
| CINEMATIC_103 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_2 | high | `5ba45a9ff42e` -- amiga's `..._RIGHT_0_2`; drawn by `DRAW_ALIEN_SPRITE_BY_VAR09_0E` group 0 index 2 |
| CINEMATIC_104 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_3 | high | `7d636087d59f` -- amiga's `..._RIGHT_0_3`; drawn by `DRAW_ALIEN_SPRITE_BY_VAR09_0E` group 0 index 3 |
| CINEMATIC_105 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_4 | high | `0f44eaa8dcbd` -- amiga's `..._RIGHT_0_4`; drawn by `DRAW_ALIEN_SPRITE_BY_VAR09_0E` group 0 index 4 |
| CINEMATIC_106 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_6 | high | `ccf854b75fb2` -- amiga's `..._RIGHT_0_6`; drawn by `DRAW_ALIEN_SPRITE_BY_VAR09_0E` group 0 index 6 |
| CINEMATIC_107 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_7 | high | `30ce99b13408` -- PRISON's and CAVES' `..._FIGURE_POSE_RIGHT_0_1`; drawn by `DRAW_ALIEN_SPRITE_BY_VAR09_0E` group 0 index 7 |
| CINEMATIC_094 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_7_1 | high | `df32e229a4b5` -- amiga's `..._RIGHT_7_1`; `DRAW_ALIEN_SPRITE_BY_VAR09_0E` group 7 index 1 |
| CINEMATIC_096 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_4_1 | high | `80efa54fd2bf` -- amiga's `..._RIGHT_4_1`; `DRAW_ALIEN_SPRITE_BY_VAR09_0E` group 4 index 1 |
