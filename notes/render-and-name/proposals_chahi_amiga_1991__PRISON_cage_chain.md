# PRISON: the cage's chain, at fifteen tilt angles

## A fifteen-way dispatch on a signed variable

`LABEL_72F2` tests `[0x06]` and falls through a chain of fifteen one-line
routines, each drawing one constant at `x=[0x03], y=[0x04]`:

```
  [0x06] == 0x0000 -> 595      == 0xFFFF (-1) -> 587
            0x0001 -> 594         0xFFFE (-2) -> 586
            0x0002 -> 593         0xFFFD (-3) -> 585
            0x0003 -> 592         0xFFFC (-4) -> 584
            0x0004 -> 591         0xFFFB (-5) -> 583
            0x0005 -> 590         0xFFFA (-6) -> 582
            0x0006 -> 589         otherwise   -> 581
            otherwise -> 588
```

`[0x06]` is the cage's swing tilt: the routines immediately above this chain are
`PRISON_CAGE_SWING_TILT_OFFSET_CASE_FFFB` and `..._CASE_FFFA`, which adjust
`[0x1A]` and `[0x1B]` by the same values. The fifteen constants are laid out
contiguously in the bank at `0x2190 + 0x14k`, in descending number order.

## The measurement that gives the name

Each is **one leaf**, about 102 tall, and the widths are symmetric about zero
while the lean reverses:

```
  tilt   width   top-x   foot-x   lean
    +0     2.0   156.0    156.0   vertical
    +1     3.0   154.5    155.5   top left of the foot
    +2     5.0   152.5    155.5      "
    +3     9.0   148.5    155.5      "
    +4    10.0   148.0    156.0      "
    +5    12.0   146.0    156.0      "
    +6    17.0   140.5    155.5      "
    +7    21.0   136.5    155.5      "
    -1     3.0   156.5    155.5   top RIGHT of the foot
    -2     5.0   158.5    155.5      "
    -3     9.0   162.5    155.5      "
    -4    10.0   164.0    156.0      "
    -5    12.0   166.0    156.0      "
    -6    17.0   170.5    155.5      "
    -7    21.0   174.5    155.5      "
```

3, 5, 9, 10, 12, 17, 21 on both sides, to the pixel. The **foot stays put** at
x~155.5 and the top swings, which is what a chain looks like when the drawing is
anchored on the cage: in cage-relative coordinates the cage end is fixed and the
pivot end appears to move.

It is a chain and not the cage: `CINEMATIC_PRISON_CAGE_BARS_TILT_PLUS_1` is
56.0x55.5 in **18** leaves and these are 102 tall in **one**, so this element
runs well above the box the bars draw.

## The names

The stage already names a ladder of this exact shape --
`CINEMATIC_PRISON_CAGE_BARS_TILT_{PLUS,MINUS}_1..6` -- so these take the same
form, with the dispatch value as the index.

The two ends of the existing family are `..._TILT_FROM_07` and
`..._TILT_LEFT_LIMIT`, and those words are **not** borrowed here: `LEFT_LIMIT`
sits at the negative end, where this element leans to the **right**, and nothing
measured says which way the cage itself goes. `_7` says what the dispatch says
and no more.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_595 | CINEMATIC_PRISON_CAGE_CHAIN_TILT_ZERO | high | 0x2190, 102 tall in one leaf and **2.0 wide** -- vertical, top over foot; the `[0x06] == 0` arm |
| CINEMATIC_594 | CINEMATIC_PRISON_CAGE_CHAIN_TILT_PLUS_1 | high | 0x21A4, 3.0 wide, top **left** of the foot; the `[0x06] == 1` arm |
| CINEMATIC_593 | CINEMATIC_PRISON_CAGE_CHAIN_TILT_PLUS_2 | high | 0x21B8, 5.0 wide, top **left** of the foot; the `[0x06] == 2` arm |
| CINEMATIC_592 | CINEMATIC_PRISON_CAGE_CHAIN_TILT_PLUS_3 | high | 0x21CC, 9.0 wide, top **left** of the foot; the `[0x06] == 3` arm |
| CINEMATIC_591 | CINEMATIC_PRISON_CAGE_CHAIN_TILT_PLUS_4 | high | 0x21E0, 10.0 wide, top **left** of the foot; the `[0x06] == 4` arm |
| CINEMATIC_590 | CINEMATIC_PRISON_CAGE_CHAIN_TILT_PLUS_5 | high | 0x21F4, 12.0 wide, top **left** of the foot; the `[0x06] == 5` arm |
| CINEMATIC_589 | CINEMATIC_PRISON_CAGE_CHAIN_TILT_PLUS_6 | high | 0x2208, 17.0 wide, top **left** of the foot; the `[0x06] == 6` arm |
| CINEMATIC_588 | CINEMATIC_PRISON_CAGE_CHAIN_TILT_PLUS_7 | high | 0x221C, 21.0 wide, top **left** of the foot; the arm every value of 7 or more falls through to |
| CINEMATIC_587 | CINEMATIC_PRISON_CAGE_CHAIN_TILT_MINUS_1 | high | 0x2230, 3.0 wide -- the same width as `..._PLUS_1` -- top **right** of the foot; the `[0x06] == -1` arm |
| CINEMATIC_586 | CINEMATIC_PRISON_CAGE_CHAIN_TILT_MINUS_2 | high | 0x2244, 5.0 wide -- the same width as `..._PLUS_2` -- top **right** of the foot; the `[0x06] == -2` arm |
| CINEMATIC_585 | CINEMATIC_PRISON_CAGE_CHAIN_TILT_MINUS_3 | high | 0x2258, 9.0 wide -- the same width as `..._PLUS_3` -- top **right** of the foot; the `[0x06] == -3` arm |
| CINEMATIC_584 | CINEMATIC_PRISON_CAGE_CHAIN_TILT_MINUS_4 | high | 0x226C, 10.0 wide -- the same width as `..._PLUS_4` -- top **right** of the foot; the `[0x06] == -4` arm |
| CINEMATIC_583 | CINEMATIC_PRISON_CAGE_CHAIN_TILT_MINUS_5 | high | 0x2280, 12.0 wide -- the same width as `..._PLUS_5` -- top **right** of the foot; the `[0x06] == -5` arm |
| CINEMATIC_582 | CINEMATIC_PRISON_CAGE_CHAIN_TILT_MINUS_6 | high | 0x2294, 17.0 wide -- the same width as `..._PLUS_6` -- top **right** of the foot; the `[0x06] == -6` arm |
| CINEMATIC_581 | CINEMATIC_PRISON_CAGE_CHAIN_TILT_MINUS_7 | high | 0x22A8, 21.0 wide -- the same width as `..._PLUS_7` -- top **right** of the foot; the arm every value of -7 or less falls through to |
