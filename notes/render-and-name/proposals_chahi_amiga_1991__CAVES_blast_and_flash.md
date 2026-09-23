# CAVES: the superblast beam tiles, and the wide flash

Two families CAVES holds that PRISON and CAPSULE have already named, each found
by `same_widget.py --hash` and each confirmed by a routine that matches line for
line.

## The superblast beam tiles

Three tiles of one beam, 15, 47 and 111 wide and all 5 tall, drawn longest
first at `x=[0x2b], y=[0x27]`:

```
  amiga CAVES.asm:11532   video 751, x=[0x2b], y=[0x27]
                 :11539   video 750, x=[0x2b], y=[0x27]
                 :11546   video 749, x=[0x2b], y=[0x27]

  amiga PRISON.asm:7381   video PRISON_SUPERBLAST_BEAM_TILE_2, x=[0x2b], y=[0x27]
                  :7388   video PRISON_SUPERBLAST_BEAM_TILE_1, x=[0x2b], y=[0x27]
                  :7395   video PRISON_SUPERBLAST_BEAM_TILE_0, x=[0x2b], y=[0x27]
```

Same anchors, same descending order, and the art is the same art in all three
stages: `44ca9852d86f`, `902f4d185b75`, `a18878ca2753`. The stage word follows
PRISON's and CAPSULE's, which both carry one.

## The wide flash

Four frames at `x=160`, drawn F0, F1, F2, F3 at `y=[0xe7]` and then again at
`y=[0xe8]` -- in CAVES at `CAVES.asm:3851..3871` and in CAPSULE at
`CAPSULE.asm:2999..3015`, the same eight draws in the same order at the same two
variables. The four are `c15b5cfed03b`, `0ab6d71d84fd`, `aa17f2933319`,
`fed99a5479bb` in both stages, and their sizes rise then fall --
261.0x16.0, 475.0x22.0, 403.0x15.0, 201.0x6.0 -- which is a flash, not a ladder.

Bare `CINEMATIC_WIDE_FLASH_F*`, no stage word, because that is the name CAPSULE
carries and the drawing is identical; the same choice as
`CINEMATIC_SHIELD_DEPLOY_PHASE_*` in `proposals_chahi_amiga_1991__CAVES_shield_deploy.md`.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_749 | CINEMATIC_CAVES_SUPERBLAST_BEAM_TILE_0 | high | 0x2862, 15.0x5.0 in 2 leaves, `44ca9852d86f` -- the same drawing as PRISON's and CAPSULE's TILE_0, drawn last of the three at `x=[0x2b], y=[0x27]` exactly as theirs is |
| CINEMATIC_750 | CINEMATIC_CAVES_SUPERBLAST_BEAM_TILE_1 | high | 0x287A, 47.0x5.0, `902f4d185b75` == TILE_1, drawn second |
| CINEMATIC_751 | CINEMATIC_CAVES_SUPERBLAST_BEAM_TILE_2 | high | 0x2892, 111.0x5.0, `a18878ca2753` == TILE_2, drawn first and longest |
| CINEMATIC_008 | CINEMATIC_WIDE_FLASH_F0 | high | 0xB68E, 261.0x16.0 in 3 leaves, `c15b5cfed03b` == CAPSULE's `WIDE_FLASH_F0`, first of four at `x=160, y=[0xe7]` and again at `y=[0xe8]` |
| CINEMATIC_009 | CINEMATIC_WIDE_FLASH_F1 | high | 0xB6BC, **475.0x22.0**, `0ab6d71d84fd` == `WIDE_FLASH_F1`, second and widest |
| CINEMATIC_010 | CINEMATIC_WIDE_FLASH_F2 | high | 0xB6D0, 403.0x15.0 in 5 leaves, `aa17f2933319` == `WIDE_FLASH_F2`, third |
| CINEMATIC_011 | CINEMATIC_WIDE_FLASH_F3 | high | 0xB6F0, 201.0x6.0, `fed99a5479bb` == `WIDE_FLASH_F3`, fourth and smallest |
