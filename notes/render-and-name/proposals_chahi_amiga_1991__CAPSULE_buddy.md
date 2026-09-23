# CAPSULE: ten pictures drawn at the buddy's own coordinates

## The query that found them

CAPSULE draws the companion at `[BUDDY_X], [BUDDY_Y]`, and **73 still-numbered
constants in amiga/CAPSULE are drawn at exactly that anchor**. Anything drawn
there is on the buddy, which narrows a 302-constant stage to a pool where the
subject is known before anything is rendered. Grouping that pool by routine
gives the runs:

```
  LABEL_3FF8   212 213 214 215 214
  LABEL_4038   213 214 215 212  266 267 268 269 268
  LABEL_40B6   270 271 269 269 271 270
```

Three cycles: a four-frame one, a two-frame burst, and a four-frame flicker
played as a palindrome.

## What they are

At palette 0x0E, cropped to the ten-pixel box they occupy:

```
  212  0x3B7C   6.0x3.0   4 paths     215  0x3C5C   6.0x3.0   4 paths
  213  0x3C2E   6.0x3.0   4 paths     266  0x3BAA   8.0x3.0   2 paths
  214  0x3C44   6.0x3.0   4 paths     267  0x3C02  28.0x3.0   2 paths
  268  0x3BD6   8.0x6.0   2 paths     270  0x3C74   7.0x6.0   2 paths
  269  0x3CBC   7.0x6.0   2 paths     271  0x3CA0   8.0x6.0   2 paths
```

**212..215** are a 6.0x3.0 horizontal bar in **four** paths -- a dark block with
red, white and cyan segments beside it -- and the segments move between the
four frames. Nothing else in the pool is four paths.

**268..271** are 7-8 x 6 in **two** paths: a cyan hexagon around a white core.
That is the same construction as `CINEMATIC_ACTOR_CHARGE_GLOW_F0` (5.0x6.0, 2
paths) and `_F6` (12.0x14.0, 2 paths), which are drawn at `[0x21], [0x22]` --
the actor's anchor. The same effect on the other character, at the other
anchor.

**266 and 267** are also two paths, but flat and wide: 8.0x3.0 then
**28.0x3.0**, three and a half times wider in one step, a cyan lens around a
white centre. They are drawn once each, immediately before the glow frames.

## Cross-port

Six of the ten match msdos by `canonical_md5`. The other four -- 213, 214, 215
-- do not, and are matched by draw site instead, which is unambiguous here:
msdos's `LABEL_570A` draws `250 251 252 253 252` where amiga's `LABEL_3FF8`
draws `212 213 214 215 214`, and msdos's `LABEL_574A` draws
`251 252 253 250 254 255 256 257 256` where amiga's `LABEL_4038` draws
`213 214 215 212 266 267 268 269 268`. Position for position, in both routines,
with 250, 254, 255, 256 and 257 confirmed by hash as the anchors of that
alignment.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_212 | CINEMATIC_BUDDY_SEGMENT_BAR_F0 | medium | 0x3B7C, 6.0x3.0 in **4 paths**, drawn at `[BUDDY_X], [BUDDY_Y]`: a dark block with coloured segments beside it. Last of the four in `LABEL_4038`'s order, first in `LABEL_3FF8`'s |
| CINEMATIC_213 | CINEMATIC_BUDDY_SEGMENT_BAR_F1 | medium | 0x3C2E, same 6.0x3.0 / 4 paths, different segment layout |
| CINEMATIC_214 | CINEMATIC_BUDDY_SEGMENT_BAR_F2 | medium | 0x3C44, same construction; the frame both routines return to |
| CINEMATIC_215 | CINEMATIC_BUDDY_SEGMENT_BAR_F3 | medium | 0x3C5C, same construction |
| CINEMATIC_266 | CINEMATIC_BUDDY_DISCHARGE_FLASH_F0 | medium | 0x3BAA, **2 paths**, 8.0x3.0: a cyan lens around a white centre, drawn once, immediately after the bar cycle |
| CINEMATIC_267 | CINEMATIC_BUDDY_DISCHARGE_FLASH_F1 | medium | 0x3C02, 2 paths, **28.0x3.0** -- three and a half times wider in one frame, and the widest thing in the pool |
| CINEMATIC_268 | CINEMATIC_BUDDY_CHARGE_GLOW_F0 | medium | 0x3BD6, 2 paths, 8.0x6.0: a cyan hexagon around a white core, the construction `ACTOR_CHARGE_GLOW_*` uses at the actor's anchor |
| CINEMATIC_269 | CINEMATIC_BUDDY_CHARGE_GLOW_F1 | medium | 0x3CBC, 2 paths, 7.0x6.0. Drawn by both `LABEL_4038` and `LABEL_40B6` |
| CINEMATIC_270 | CINEMATIC_BUDDY_CHARGE_GLOW_F2 | medium | 0x3C74, 2 paths, 7.0x6.0, first and last of `LABEL_40B6`'s palindrome |
| CINEMATIC_271 | CINEMATIC_BUDDY_CHARGE_GLOW_F3 | medium | 0x3CA0, 2 paths, 8.0x6.0 |

## What these names do not claim

`BUDDY` is the stage's own word (`CINEMATIC_BUDDY_SMASHING_WINDOW_F0..F8`) and
here it is not a reading at all -- it is the anchor these ten are drawn at.

`CHARGE_GLOW` is borrowed from `ACTOR_CHARGE_GLOW_*` on the strength of the
same two-path hexagon-around-a-core construction at the other character's
anchor, and is graded `medium` for that reason. `DISCHARGE_FLASH` rests on two
flat two-path lenses, the second three and a half times the width of the first,
drawn once each between the bar cycle and the glow.

`SEGMENT_BAR` says a small horizontal bar whose coloured segments move across
four frames. What it measures -- charge, ammunition, health, nothing -- is not
claimed.
