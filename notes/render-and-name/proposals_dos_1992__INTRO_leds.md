# INTRO (msdos): the last four, and an LED family that is one index out

## The panel routines line up draw for draw

`DRAW_HOLO_CONSOLE_DISPLAY_PANEL` exists in both priority ports and draws the
same five pictures at the same five positions, in the same order, fourteen
times over:

```
  position       (221,123) (219,125) (217,127) (131,109) (134,107)
  amiga            LED_0     LED_1     LED_2     LED_3     LED_4
  msdos            LED_1     LED_2      444      LED_4      446
```

and the correspondence holds at every one of the fourteen draws, not just the
first five -- amiga `LED_2, LED_1, LED_0, LED_4, LED_3, LED_0, LED_1, LED_2,
LED_3` against msdos `444, LED_2, LED_1, 446, LED_4, LED_1, LED_2, 444, LED_4`.
Fourteen of fourteen.

So msdos's names are **one index high**: its `LED_1` is the picture amiga calls
`LED_0`, and the two pictures it never named are amiga's `LED_2` and `LED_4`.
amiga's run is 0-based and gapless and is the one to match; `docs/NAMING.md`
wants 0-based anyway.

This is a chained rename and therefore one batch and one file, applied **once**.
`dos_1992`, `cartridge_1992` and `gba_2004` share a single `.else` arm in
`src/levels/_unified/intro/intro_lake_transition.inc` and use the **same
constant names**, so applying it for msdos fixes the arm for all three -- and
applying it again for either of the others would shift the arm a second time,
which is the failure `notes/render-and-name/README.md` records from the walk
renumber. It is deliberately not run for them; their own `.asm` files keep the
old spellings and the tree they build from does not.

## The other three

**`CINEMATIC_318`** is drawn by `DRAW_INTRO_DECOR_318` at `x=176, y=157`, in
the `.else` arm of the very line whose amiga arm draws
`CINEMATIC_EXPERIMENT_SPARK_LONG_F0` at the same position. Its hash collides
with two amiga sparks, so the hash is not the evidence here -- the paired arm
is. The `_F1` of that family is already shared, so this closes the run at F0.

**`CINEMATIC_466`** is 4.0x437.5 -- four pixels wide and twice the height of
the page -- and is `a5352cf5004c`, the same art amiga uses as one of the four
tiles of `LIFT_SHAFT_SCROLL_LOOP`. msdos does not scroll it: it draws it twice
at a fixed `x=153, y=114`, to page 0 and to page 0xFF, and waits for input. So
it takes the shape's name without the family index it does not belong to here.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_PARTICLE_LAB_HOLO_CONSOLE_LED_1 | CINEMATIC_PARTICLE_LAB_HOLO_CONSOLE_LED_0 | high | 0x077C, drawn at (221,123) where amiga draws its `LED_0`, at all four of its occurrences |
| CINEMATIC_PARTICLE_LAB_HOLO_CONSOLE_LED_2 | CINEMATIC_PARTICLE_LAB_HOLO_CONSOLE_LED_1 | high | 0x07D0, drawn at (219,125) where amiga draws its `LED_1` |
| CINEMATIC_444 | CINEMATIC_PARTICLE_LAB_HOLO_CONSOLE_LED_2 | high | 0x0818, drawn at (217,127) where amiga draws its `LED_2` -- and amiga's `LED_2` is 0x0818 too |
| CINEMATIC_PARTICLE_LAB_HOLO_CONSOLE_LED_4 | CINEMATIC_PARTICLE_LAB_HOLO_CONSOLE_LED_3 | high | 0x0624, drawn at (131,109) where amiga draws its `LED_3` -- and amiga's `LED_3` is 0x0624 too |
| CINEMATIC_446 | CINEMATIC_PARTICLE_LAB_HOLO_CONSOLE_LED_4 | high | 0x0678, drawn at (134,107) where amiga draws its `LED_4` -- and amiga's `LED_4` is 0x0678 too |
| CINEMATIC_318 | CINEMATIC_EXPERIMENT_SPARK_LONG_F0 | high | 0xEEBC, drawn by `DRAW_INTRO_DECOR_318` at `x=176, y=157` in the `.else` arm of the line whose amiga arm draws `..._SPARK_LONG_F0` at the same position. `_F1` of that family is already shared |
| CINEMATIC_466 | CINEMATIC_LIFT_SHAFT_BAND | medium | 0x4082, `a5352cf5004c`: **4.0 x 437.5**, four pixels wide and more than twice the page height. The same art amiga tiles as `..._LIFT_SHAFT_SCROLL_BAND_F3`; msdos draws it twice at a fixed `x=153, y=114` and does not scroll it, so it takes no family index |

## What this does not claim

The three offsets that already agree with amiga -- 0x0818, 0x0624, 0x0678 for
`LED_2`, `LED_3`, `LED_4` after the shift -- are a check on the reading, not
its basis. The basis is the fourteen paired draws.

`LIFT_SHAFT_BAND` says a four-pixel vertical band of the shape amiga uses in
its shaft loop, and nothing about what msdos's wait screen is showing.
