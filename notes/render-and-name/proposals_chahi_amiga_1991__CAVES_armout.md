# CAVES: the arm-out cycle going the other way, and the frame both directions share

## One routine, two directions

`LABEL_24CF` draws `CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F0` and then branches:

```
  video CAVES_HERO_ARM_OUT_LEFT_F0, x=[HERO_X], y=[HERO_Y]
  je [0x63], 0x02, LABEL_2551          <- the right-hand version
  sub [HERO_X], 0x0001  video ..._LEFT_F1
  sub [HERO_X], 0x0009  video ..._LEFT_F2
  sub [HERO_X], 0x0005  video ..._LEFT_F3
  ...
```

`LABEL_2551` is the same body with every `sub [HERO_X]` a matching
`add [HERO_X]`, step for step:

```
  LEFT   -1  -9  -5  -8  -7  -4  -1        RIGHT   +1  +9  +5  +8  +7  +4  +1
```

and the frames it draws are the mirror images, which `polygon_extent` confirms
frame for frame:

```
  LEFT_F2  35.0x40.0  10 leaf     645  35.0x40.0  10 leaf
  LEFT_F3  32.5x42.5  11 leaf     646  32.0x42.5  11 leaf
  LEFT_F4  23.0x43.0  11 leaf     647  23.0x43.0  11 leaf
  LEFT_F5  19.0x39.0  10 leaf     648  19.0x39.0  10 leaf
  LEFT_F6  12.5x38.0   9 leaf     649  12.5x38.0   9 leaf
```

## Two things the correspondence shows

**The left family has an eighth frame.** After `LEFT_F6` the routine draws
`CINEMATIC_657` (16.0x36.5, 9 leaves) and the right routine draws
`CINEMATIC_650` at the same step with the same measurements. 657 is `LEFT_F7`.

**`..._LEFT_F0` is not left-facing.** It is drawn once before the branch, by
both paths, and again at the very end of *both* loops before each jumps to
`LABEL_2416`. It is the rest pose the cycle starts and finishes on, and its
`LEFT` is wrong. Correcting it means renumbering `LEFT_F1..F7` down to
`F0..F6`, which is a chained rename and wants its own pass -- recorded in
`../HANDOFF.md` rather than smuggled in here.

Because of that, the right family is indexed on **its own** routine order,
0 to 6, and not aligned to the left family's current numbering. Both are
gapless, which is what `docs/NAMING.md` §2 asks; the frame-for-frame
correspondence is in this table so the later renumber can use it.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_644 | CINEMATIC_CAVES_HERO_ARM_OUT_RIGHT_F0 | high | 0xBBFC, 19.5x36.0 in 9 leaves; first draw of `LABEL_2551`, after `add [HERO_X], 1` where the left routine does `sub [HERO_X], 1` |
| CINEMATIC_645 | CINEMATIC_CAVES_HERO_ARM_OUT_RIGHT_F1 | high | 0xBC40, **35.0x40.0 in 10 leaves -- the same measurements as `..._LEFT_F2`**, at the matching `+9` step |
| CINEMATIC_646 | CINEMATIC_CAVES_HERO_ARM_OUT_RIGHT_F2 | high | 0xBCB0, 32.0x42.5 in 11 leaves against `LEFT_F3`'s 32.5x42.5 in 11, at the matching `+5` step |
| CINEMATIC_647 | CINEMATIC_CAVES_HERO_ARM_OUT_RIGHT_F3 | high | 0xBD1C, 23.0x43.0 in 11 leaves -- `LEFT_F4` exactly -- at the matching `+8` step |
| CINEMATIC_648 | CINEMATIC_CAVES_HERO_ARM_OUT_RIGHT_F4 | high | 0xBD88, 19.0x39.0 in 10 leaves -- `LEFT_F5` exactly -- at the matching `+7` step |
| CINEMATIC_649 | CINEMATIC_CAVES_HERO_ARM_OUT_RIGHT_F5 | high | 0xBDDC, 12.5x38.0 in 9 leaves -- `LEFT_F6` exactly -- at the matching `+4` step |
| CINEMATIC_650 | CINEMATIC_CAVES_HERO_ARM_OUT_RIGHT_F6 | high | 0xBE1C, 16.0x36.5 in 9 leaves, the last before the loop returns to the rest pose |
| CINEMATIC_657 | CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F7 | high | 0xA1E2, 16.0x36.5 in 9 leaves, the same measurements as 650 and at the mirror step; it closes the left family, which had stopped at F6 |
