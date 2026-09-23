# CAVES: the right-facing half of a pose sheet, from the dispatcher

`notes/pose-dispatch/pose_index.py --stage CAVES --unnamed` returns five
targets of `DRAW_HERO_SPRITE_BY_VAR09_0E`, all in group 0:

```
  group 0 index 1   DRAW_HERO_POSE_0_1   CINEMATIC_022
  group 0 index 2   DRAW_HERO_POSE_0_2   CINEMATIC_023
  group 0 index 3   DRAW_HERO_POSE_0_3   CINEMATIC_024
  group 0 index 4   DRAW_HERO_POSE_0_4   CINEMATIC_025
  group 0 index 6   DRAW_HERO_POSE_0_6   CINEMATIC_027
```

The dispatcher gives the index out of the bytecode, which is the cheapest and
strongest evidence this repository has for a pose sheet. What it does not give
is the facing, and two other things do.

**The sibling dispatcher.** CAVES' other one, `LABEL_2265`, feeds the family
already named `CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_0..0_6` -- the same seven
slots, the other way. `DRAW_HERO_SPRITE_BY_VAR09_0E` is therefore the right-hand
sheet, exactly as it is in PRISON and CAPSULE, where the same dispatcher's group
0 already draws `..._FIGURE_POSE_RIGHT_0_*`.

**The art, independently.** `same_widget.py --min-leaf 3` matches four of the
five against already-named right-facing poses in the other two stages, at those
stages' own offsets:

```
  022  30ce99b13408  10.0x11.0   4 leaf  ==  PRISON_FIGURE_POSE_RIGHT_0_1
  023  5ba45a9ff42e  19.0x14.0   5 leaf  ==  CAPSULE_FIGURE_POSE_RIGHT_0_2
  024  7d636087d59f  20.5x18.5   7 leaf  ==  CAPSULE_FIGURE_POSE_RIGHT_0_3
  027  ccf854b75fb2  20.5x15.5   5 leaf  ==  CAPSULE_FIGURE_POSE_RIGHT_0_6
```

Index for index. The dispatcher and the art agree on all four without either
knowing about the other, and 025 takes index 4 from the dispatcher alone.

`notes/crossstage-transfer/transfer_across_stages.py` had been holding these
four on "name carries another stage's prefix", which was the right refusal: the
name to give them is CAVES', and it is the dispatcher that says so.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_022 | CINEMATIC_CAVES_FIGURE_POSE_RIGHT_0_1 | high | 0x487C, group 0 index **1** of `DRAW_HERO_SPRITE_BY_VAR09_0E`; 10.0x11.0 in 4 leaves, `30ce99b13408` -- the same drawing as `PRISON_FIGURE_POSE_RIGHT_0_1` |
| CINEMATIC_023 | CINEMATIC_CAVES_FIGURE_POSE_RIGHT_0_2 | high | 0x48A4, group 0 index **2**; 19.0x14.0 in 5 leaves, `5ba45a9ff42e` == `CAPSULE_FIGURE_POSE_RIGHT_0_2` |
| CINEMATIC_024 | CINEMATIC_CAVES_FIGURE_POSE_RIGHT_0_3 | high | 0x48BE, group 0 index **3**; 20.5x18.5 in 7 leaves, `7d636087d59f` == `CAPSULE_FIGURE_POSE_RIGHT_0_3` |
| CINEMATIC_025 | CINEMATIC_CAVES_FIGURE_POSE_RIGHT_0_4 | high | 0xEF7E, group 0 index **4**; 10.0x11.0 in 5 leaves. The one of the five with no cross-stage twin, so the dispatcher carries it alone |
| CINEMATIC_027 | CINEMATIC_CAVES_FIGURE_POSE_RIGHT_0_6 | high | 0xEFCA, group 0 index **6**; 20.5x15.5 in 5 leaves, `ccf854b75fb2` == `CAPSULE_FIGURE_POSE_RIGHT_0_6` |

Index 0 is `DRAW_HERO_POSE_0_0`, which `pose_index.py` reports as a target with
**0 draws** and refuses to guess at; index 5 is the one slot where the
right-hand dispatcher reuses the left sheet's `..._LEFT_0_5`, which is how
CAPSULE's sheet is built too. So the family is 1, 2, 3, 4, 6 by the dispatcher's
own arithmetic rather than by a hole in the naming.
