# CAPSULE (msdos): the six-frame walk CAVES already named

`same_widget.py --port msdos --pairs CAVES:CAPSULE --min-leaf 3` returns six
consecutive constants whose polygon trees are byte-identical to CAVES'
`CINEMATIC_CAVES_CREATURE_WALK_RIGHT_F0..F5`:

```
  708  edc2594aae0c  51.0x29.5  12 leaf  ==  ..._F0
  709  40c61863d69f  56.5x29.5  12 leaf  ==  ..._F1
  710  dff9abb9436f  67.0x29.5  12 leaf  ==  ..._F2
  711  40e12eccbfc7  51.0x29.5  12 leaf  ==  ..._F3
  712  f155d71bc6b6  56.5x29.5  12 leaf  ==  ..._F4
  713  e6c66e207cd1  67.0x29.5  12 leaf  ==  ..._F5
```

Six of six, in order, twelve leaves each, and the 51 / 56.5 / 67 width cycle
repeating twice is the gait itself.

Each has its own one-line dispatch routine in msdos CAPSULE --
`jne [0x10], [SCREEN_NUM], CAPSULE_NOOP_RET` then one draw at
`x=[BUDDY_X], y=[BUDDY_Y]` then `ret` -- and they run 708, 709, 710, 711, 712,
713 down the file, so the frame order is the routine order as well as the art.

amiga does not hold this art at all: the scene is one of CAPSULE's msdos-only
ones, like `CINEMATIC_CAPSULE_FIGURE_FLUNG_F0..F4`.

The stage word follows CAVES', which carries one. The anchor is not what names
it -- `../actor-anchors/` establishes that `[BUDDY_X]` says "some actor", never
which -- the art does.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_708 | CINEMATIC_CAPSULE_CREATURE_WALK_RIGHT_F0 | high | 0x4DEE, 51.0x29.5 in 12 leaves, `edc2594aae0c` -- byte-identical to CAVES' F0, first of the six down the file |
| CINEMATIC_709 | CINEMATIC_CAPSULE_CREATURE_WALK_RIGHT_F1 | high | 0x4E70, 56.5x29.5, `40c61863d69f` == CAVES' F1 |
| CINEMATIC_710 | CINEMATIC_CAPSULE_CREATURE_WALK_RIGHT_F2 | high | 0x4F80, 67.0x29.5, `dff9abb9436f` == CAVES' F2, the widest of the cycle |
| CINEMATIC_711 | CINEMATIC_CAPSULE_CREATURE_WALK_RIGHT_F3 | high | 0x4FAE, 51.0x29.5, `40e12eccbfc7` == CAVES' F3, the cycle starting over |
| CINEMATIC_712 | CINEMATIC_CAPSULE_CREATURE_WALK_RIGHT_F4 | high | 0x4FDE, 56.5x29.5, `f155d71bc6b6` == CAVES' F4 |
| CINEMATIC_713 | CINEMATIC_CAPSULE_CREATURE_WALK_RIGHT_F5 | high | 0x500E, 67.0x29.5, `e6c66e207cd1` == CAVES' F5 |
