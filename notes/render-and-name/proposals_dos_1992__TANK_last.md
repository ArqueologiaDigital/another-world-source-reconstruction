# TANK (msdos): the last thirteen

Three are amiga's three at the same offsets -- argument in
`proposals_chahi_amiga_1991__TANK_last.md`. The other ten are msdos-only and
every one of them has a routine that names it.

## The arena wrecks

```
TANK_ARENA_STAMP_WRECK_LEFT_ONTO_BACKDROP:    TANK_ARENA_STAMP_WRECK_CENTRE_ONTO_BACKDROP:
    video 126, x=110, y=150                       video 126, x=155, y=151
    video 127, x=160, y=100   (to page 0)         video 128, x=160, y=100   (to page 0)
    video 127, x=160, y=100   (to page 3)         video 128, x=160, y=100   (to page 3)
```

`126` is drawn by **both**, at two different arena positions; `127` only by the
left one and `128` only by the centre one, each stamped onto two pages so it
becomes part of the backdrop. 126 is 92.0x45.0 in **3 paths**, 127 is
63.0x19.5 in 9 and 128 is 72.5x42.5 in 21 -- the shared one is the simplest.

## The console lamps

Four 2.0x5.0 two-path lamps in two columns, and the routines say which is which:

```
  TANK_CONSOLE_UPPER_GREEN_LAMP_ON  ->  170 at x=39
  TANK_CONSOLE_UPPER_RED_LAMP_ON    ->  172 at x=35
  TANK_CONSOLE_BUTTON_ACTION_CASE_08 -> 171 at x=35 (twice), 174 at x=39
```

`171` is only ever drawn at **x=35**, the red lamp's column, and the arm that
draws it at the red lamp's own `y=31` sets `[0x71]` back to `0` where
`..._RED_LAMP_ON` had set it to `1`. `174` is only ever drawn at **x=39**, the
green lamp's column. So each column has a lit picture and a dark one, and the
colour words come from the routines rather than from a palette.

`175` is the other half of a blink: `TANK_CONSOLE_ALL_SWITCHES_BLINK_LOOP`
alternates `CINEMATIC_TANK_CONSOLE_BUTTON_FLASH` and `175` at the **same**
`x=43, y=40`, two breaks apart, forever.

## The two in generated labels

`276` is 59.0x1.0 in **one path** at y[99.5, 100.5], and `LABEL_1869`
alternates it with `CINEMATIC_TANK_BEAM_VOLLEY_SEGMENT_2` at `(239,123)` and
`(240,123)`. The three named segments are 18.0x3.0, 26.0x3.0 and 151.0x2.0,
all thin horizontal bars in the same band. It is a fourth.

`277` is 32.0x20.0 in 4 paths at y[103.5, 123.5]; `TANK_CREATURE_RUN_F4` is
37.0x20.0 in 4 at y[103.5, 123.5] and `F5` is 23.5x19.5 in 4. Same
construction, and `LABEL_13EA` draws it at the same `x=[0x52], y=[0x53],
zoom=[0x54]` as the rest of that family. Its offset 0x2002 is the **tenth slot
of a perfectly regular 0x50 stride** whose other nine are F0..F8.

It is appended as F9 and **not** slotted in at its bank position, because
`TANK_ARENA_CREATURE_RUN_ACROSS_LOOP` plays `F0 F1 F2 F3 F4 F5 F6 F7 F8`
consecutively and renumbering by bank order would put a gap in the middle of
that cycle. The repo indexes `_F` families by order of appearance, not by
offset, and this is a case where the two genuinely disagree.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_087 | CINEMATIC_TANK_FALLING_STREAK | medium | 0x548A, `e6ed01ed7a79` -- identical to amiga's `CINEMATIC_100` |
| CINEMATIC_204 | CINEMATIC_TANK_AMBIENT_IMPACT_FLASH | high | 0x27CA, `0b33b655fdb2` -- identical to amiga's `CINEMATIC_152` |
| CINEMATIC_207 | CINEMATIC_TANK_AMBIENT_IMPACT_SCAR | high | 0x27F6, `0a9341a571c1` -- identical to amiga's `CINEMATIC_155` |
| CINEMATIC_126 | CINEMATIC_TANK_ARENA_WRECK_BASE | high | 0x6FF6, **3 paths**, 92.0x45.0, the only picture both wreck routines draw, at two different arena positions |
| CINEMATIC_127 | CINEMATIC_TANK_ARENA_WRECK_LEFT | high | 0x706E, 9 paths, 63.0x19.5, stamped onto pages 0 and 3 by `..._WRECK_LEFT_ONTO_BACKDROP` and nothing else |
| CINEMATIC_128 | CINEMATIC_TANK_ARENA_WRECK_CENTRE | high | 0x7036, **21 paths**, 72.5x42.5, stamped onto pages 0 and 3 by `..._WRECK_CENTRE_ONTO_BACKDROP` and nothing else |
| CINEMATIC_170 | CINEMATIC_TANK_CONSOLE_LAMP_GREEN_LIT | high | 0x430E, 2 paths, 2.0x5.0, the only picture `TANK_CONSOLE_UPPER_GREEN_LAMP_ON` draws, at x=39 |
| CINEMATIC_174 | CINEMATIC_TANK_CONSOLE_LAMP_GREEN_OFF | medium | 0x42FE, 2 paths, 2.0x5.0, drawn only at **x=39** -- the green lamp's column -- by the button-action arm |
| CINEMATIC_172 | CINEMATIC_TANK_CONSOLE_LAMP_RED_LIT | high | 0x431E, 2 paths, 2.0x5.0, the only picture `TANK_CONSOLE_UPPER_RED_LAMP_ON` draws, at x=35, and it sets `[0x71]` to 1 |
| CINEMATIC_171 | CINEMATIC_TANK_CONSOLE_LAMP_RED_OFF | high | 0x2348, 2 paths, 2.0x5.0, drawn only at **x=35**, and the arm that draws it at the red lamp's own y=31 sets `[0x71]` back to 0 |
| CINEMATIC_175 | CINEMATIC_TANK_CONSOLE_BUTTON_UNLIT | high | 0x720C, 2 paths, 2.0x8.0, alternated with `..._CONSOLE_BUTTON_FLASH` at the same `x=43, y=40` two breaks apart, forever |
| CINEMATIC_276 | CINEMATIC_TANK_BEAM_VOLLEY_SEGMENT_3 | medium | 0x279C, **1 path**, 59.0x1.0 in the same y band as the three named segments (18.0x3.0, 26.0x3.0, 151.0x2.0), alternated with `..._SEGMENT_2` one pixel apart |
| CINEMATIC_277 | CINEMATIC_TANK_CREATURE_RUN_F9 | medium | 0x2002, 4 paths, 32.0x20.0 at y[103.5, 123.5] -- the same construction and band as `..._RUN_F4` (4 paths, 37.0x20.0) -- drawn at the family's own `x=[0x52], y=[0x53], zoom=[0x54]`. Tenth slot of the family's 0x50 stride; appended rather than inserted, see above |

## What these names do not claim

`GREEN` and `RED` are the routines' words, not a palette reading -- the console
renders differently at every palette tried, which is exactly why the column
each lamp is drawn in is the evidence instead.

`WRECK_BASE` says the one picture both wreck stamps share; it does not claim it
is rubble rather than a scorch or a shadow.
