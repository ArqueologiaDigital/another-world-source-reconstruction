# A row of eleven cloaked figures, in CAVES and in CAPSULE

## How it was found

`frame_runs.py --stage CAVES` reports the same three-constant run at eleven
different fixed positions:

```
    3 numbered   at 75,121     LABEL_1F82    261 265 268
    3 numbered   at 7,116      LABEL_1F82    261 263 268
    3 numbered   at 65506,114  LABEL_1F82    261 262 268
    ... eight more
```

`LABEL_1F82` is one straight run of thirty-three draws with a `break` between
each triple:

```
  x = -30, 7, 43, 75, 119, 153, 190, 223, 266, 301, 331
  y = 114, 116, 120, 121, 116, 118, 120, 117, 112, 114, 114
```

-- eleven figures standing along the floor, left to right, each built from a
shared piece, one of four variants, and a third piece that is the same for the
whole row.

## What they are

Rendered at palette 8 (`palette_in_force.py` on `LABEL_1F82`) and composited at
the row's sixth position, `x=153, y=118`:

- **261** is the head and near shoulder in profile, facing right: pinkish skin
  (`#b79797`, `#dbb7a7`), an eye, and a dark mass below. 96.0x121.5 in 6 leaves.
- **262, 263, 264, 265** are the lower body, 56x80, 41x80, 42x78 and 57x81, two
  leaves each. Four variants dealt out along the row so the eleven are not
  identical: left to right 262, 263, 264, 265, 265, 264, 264, 263, 262, 263, 264.
- **266, 267, 268** are a dark cloak over the back and torso with a dark bar
  held diagonally in front of the figure, 107x68.5, 115x66.5 and 104x62. In 266
  and 267 a dark red slot shows on the back; in 268 it does not, and the bar
  sits higher.

## Three frames, and the order is not the constant order

Four routines paint the identical row. One draws the bare figure; the other
three add one cloak each, and the scene installs them in sequence:

```
  setup channel=0x36, address=LABEL_1E39   ; draws 266
  setup channel=0x38, address=LABEL_1F82   ; draws 268
  setup channel=0x3A, address=LABEL_1EDE   ; draws 267
```

so the cloak sequence is **266, 268, 267** -- and CAPSULE, msdos CAVES and
msdos CAPSULE all install their own three in the same 0x36, 0x38, 0x3A order
with the same relative constants. Four independent confirmations that the
animation runs in that order, and a warning against reading `F1` off the number.

## The bare name

`CINEMATIC_CROWD_FIGURE_*` with no stage word, because CAVES and CAPSULE hold
this row twice and the seven lower-body and cloak drawings are **byte-identical
between the two stages** -- 995d423ff748, 206870e3fdbf, 8db6033e72cc,
fb7c26d93034, d056c137fad7, 545836bc643d, 976191b6b3d8 in both. The head is the
one piece each stage redraws: CAVES' is 96.0x121.5 (`0255fbb6b2e4`), CAPSULE's
97.0x121.5 (`7c2458ef3130`), same six leaves and the same role. One name over
two per-stage drawings is the documented case `name_art_agreement.py` calls a
divergence rather than a defect.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_261 | CINEMATIC_CROWD_FIGURE_UPPER | high | 0xB562, 96.0x121.5 in 6 leaves; the head, eye and near shoulder in profile, drawn first at every one of the eleven positions in all four row routines |
| CINEMATIC_262 | CINEMATIC_CROWD_FIGURE_BODY_0 | high | 0xB66A, 56.0x80.0 in 2 leaves; the lower body, first variant along the row (x=-30) and again at x=266 |
| CINEMATIC_263 | CINEMATIC_CROWD_FIGURE_BODY_1 | high | 0xB646, 41.0x80.0; second along the row (x=7), again at 223 and 301 |
| CINEMATIC_264 | CINEMATIC_CROWD_FIGURE_BODY_2 | high | 0xB622, 42.0x78.0; third along the row (x=43), again at 153, 190 and 331 |
| CINEMATIC_265 | CINEMATIC_CROWD_FIGURE_BODY_3 | high | 0xB5EA, 57.0x81.0; fourth along the row (x=75), again at 124 |
| CINEMATIC_266 | CINEMATIC_CROWD_FIGURE_CLOAK_F0 | high | 0xB70A, 107.0x68.5 in 4 leaves; drawn by `LABEL_1E39`, the first of the three cloak routines installed (channel 0x36) |
| CINEMATIC_268 | CINEMATIC_CROWD_FIGURE_CLOAK_F1 | high | 0xB76A, 104.0x62.0 in 3 leaves; drawn by `LABEL_1F82`, installed second (channel 0x38). The red back slot is absent in this frame and the bar sits higher |
| CINEMATIC_267 | CINEMATIC_CROWD_FIGURE_CLOAK_F2 | high | 0xB756, 115.0x66.5 in 4 leaves; drawn by `LABEL_1EDE`, installed third (channel 0x3A) |
