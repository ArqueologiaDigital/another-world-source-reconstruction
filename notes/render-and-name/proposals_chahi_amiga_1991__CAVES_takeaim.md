# CAVES: settling into the firing stance, and the hair that keeps moving

## Two routines, one sequence, played both ways

```
  LABEL_07C8        233+234  ->  235  ->  236  ->  STAND_AIM_LEFT  ->  STAND_SHOOT_LEFT_F1  ->  174
  LABEL_0779   STAND_SHOOT_LEFT_F1  ->  STAND_AIM_LEFT  ->  236  ->  235  ->  233+234
```

all at `x=[HERO_X], y=[HERO_Y]`. Two of the five are already named, and they are
the end of the run: the three numbered ones are what comes before
`CINEMATIC_CAVES_HERO_STAND_AIM_LEFT`, forwards in one routine and backwards in
the other.

`LABEL_0779` does not `ret`. It falls through into

```
  LABEL_07A3:   233+246  ->  233+247  ->  233+248  ->  jmp LABEL_07A3
```

-- an endless loop over the *same body* with a different small piece each time.

## What the render shows

Palette 5, cropped to `x[128,174] y[40,104]` where the frames actually sit
(`polygon_extent` puts them at `x[132,168] y[44,100]`, not centred on the page).

Lester in profile facing left, red hair, dark blue shirt, grey trousers, the
gun arm held straight out. Across 233, 235, 236, `STAND_AIM_LEFT`,
`STAND_SHOOT_LEFT_F1` the **stance opens**: feet together, then apart, then
wider, then a full stride. The measured widths say the same thing and the height
barely moves:

```
  233  31.0x52.5  11 leaf        STAND_AIM_LEFT     39.5x49.0  12 leaf
  235  33.0x51.0  12 leaf        STAND_SHOOT_LEFT_F1 33.5x49.0 12 leaf
  236  36.5x50.0  12 leaf
```

So it is not a crouch rising -- it is the stance widening into the one already
named.

**234 is the hair.** 7.0x7.0 in two leaves, a neat tuft on the crown, and 233 is
the only body frame drawn with a separate head piece; 235 and 236 carry their
own. **246, 247 and 248 are the same tuft drawn as a scatter of orange blocks**
-- 8.0x9.0, 9.0x10.0 and 9.0x9.0 in thirteen, twelve and eleven leaves -- and
the loop cycles them over a body that never moves.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_233 | CINEMATIC_CAVES_HERO_TAKE_AIM_LEFT_F0 | high | 0xED7A, 31.0x52.5 in 11 leaves; feet together, the narrowest of the run, first in `LABEL_07C8` and last in `LABEL_0779` |
| CINEMATIC_235 | CINEMATIC_CAVES_HERO_TAKE_AIM_LEFT_F1 | high | 0xEE2E, 33.0x51.0 in 12 leaves; second in `LABEL_07C8`, feet slightly apart |
| CINEMATIC_236 | CINEMATIC_CAVES_HERO_TAKE_AIM_LEFT_F2 | high | 0xEDF2, 36.5x50.0 in 12 leaves; third, immediately before `CINEMATIC_CAVES_HERO_STAND_AIM_LEFT` at 39.5 wide |
| CINEMATIC_234 | CINEMATIC_CAVES_HERO_HAIR_AT_REST | high | 0xEE66, 7.0x7.0 in **2** leaves, drawn on the crown together with 233 at both of its sites and nowhere else |
| CINEMATIC_246 | CINEMATIC_CAVES_HERO_HAIR_BLOWING_F0 | medium | 0xEE72, 8.0x9.0 in 13 leaves; first of the three the fall-through loop `LABEL_07A3` cycles over the motionless 233 |
| CINEMATIC_247 | CINEMATIC_CAVES_HERO_HAIR_BLOWING_F1 | medium | 0xEEAC, 9.0x10.0 in 12 leaves; second in that loop |
| CINEMATIC_248 | CINEMATIC_CAVES_HERO_HAIR_BLOWING_F2 | medium | 0xEEE2, 9.0x9.0 in 11 leaves; third, then the loop repeats |

`BLOWING` is the `medium` part and the only word here that is a reading rather
than a measurement: what is certain is that these are the same head piece as
`..._HAIR_AT_REST`, redrawn as a spray of separate blocks instead of one tuft,
cycling forever while the body holds a pose. Hair moving in air is the plainest
account of that; a hit or a dissolve would not leave the body untouched.

## Left out

`CINEMATIC_174` (12.5x49.0, 11 leaves) ends `LABEL_07C8` and also appears at the
tail of a walk-left run before `HERO_WALK_LEFT_LOOP`. Twelve pixels wide is the
hero seen nearly edge-on, so it belongs to the walk family rather than this one,
and naming it wants that family's frames beside it.
