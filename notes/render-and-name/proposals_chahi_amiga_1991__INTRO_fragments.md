# INTRO: five pieces that keep their shape and get smaller together

Rendered at **palette 0x18**, which two independent places in the bytecode
agree on: `DELAY_1_THEN_PLAY_FX_0A_PAL_18` sets it on the line before
`FILL_PAGE_FF_COLOR_8_ONCE` begins, and the run's own
`setup channel=0x04, address=SET_PALETTE_18` sets it again three breaks in.
At that palette the scene is two colours on a flat `fill color=0x08` field,
which is why no backdrop is composited under it: there is none.

## The run

Nine pictures at `x=160, y=100`, one per `break`:

```
  f   offset   whole picture                                 paths
  F0  0xCFA8   155.0x102.5  x[141.0, 296.0] y[ -5.5,  97.0]    8
  F1  0xD050   133.5x 89.5  x[152.0, 285.5] y[  0.5,  90.0]    8
  F2  0xD0C0   114.0x 78.5  x[162.0, 276.0] y[  6.5,  85.0]    8
  F3  0xD130    98.0x 71.0  x[168.0, 266.0] y[  9.0,  80.0]    8
  F4  0xD1A0    78.5x 64.5  x[175.0, 253.5] y[ 10.5,  75.0]    8
  F5  0xD210    64.5x 59.5  x[181.0, 245.5] y[ 10.5,  70.0]    8
  F6  0xD280    45.5x 31.0  x[189.0, 234.5] y[ 33.0,  64.0]    8
  F7  0xD2FC    31.0x 24.0  x[197.5, 228.5] y[ 36.0,  60.0]    6
  F8  0xD374    40.0x 38.0  x[191.0, 231.0] y[ 31.0,  69.0]    2
```

**They recede; they do not tumble.** Five separate pieces -- a tall block with
a bevelled top, a flattened lozenge with a lit upper face, a pale trapezoid
with a dark spike off it, and two thin bright streaks -- keep the same
silhouettes from F0 to F6 and only get smaller. Nothing rotates, nothing
changes outline.

**They shrink onto a fixed point, they do not drift.** The box goes from
155.0x102.5 to 31.0x24.0, a factor of five, while its centre moves from
(218.5, 45.75) to (213.0, 48.0) -- under six pixels. That is motion along the
line of sight and nothing else.

**F7 and F8 are the merge.** At F7 the pieces overlap and the count drops 8 to
6; at F8 there are 2 paths and one convex dark octagon where five things were.
F8's box grows back to 40.0x38.0 because the merged mass is drawn solid, and
it is the frame the teardown holds on: the second routine that plays this run
draws F8 **twice**, once at palette 0x18 and again at 0x1A, and then starts
killing channels.

## Drawn twice, and that is what makes it a cycle rather than a prefix

`CINEMATIC_268..276` sit at 0xCFA8..0xD374, immediately before
`CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F0` at 0xD3A4, which is close enough
to invite reading them as that family's missing head. They are not:

- `FILL_PAGE_FF_COLOR_8_ONCE` plays all nine, then the fifteen
  `..._TOWARDS_CAMERA` frames.
- `INTRO_EFFECT_CHANNELS_FADE_AND_TEARDOWN` plays the same nine again, in the
  same order, with the channel-3 volume stepping **0x0C, 0x0A, 0x08, 0x06,
  0x04, 0x02** across F3..F8 -- a fade-out.

A run replayed as the scene fades is a self-contained cycle. And the art says
so too: F0..F8 are 8-path groups of five separate pieces, while
`..._TOWARDS_CAMERA_F0` is **2 paths, 20.0x65.0**, a single tall sliver that
then *grows* to 43.0x75.0. Different construction, opposite direction.

## Cross-port

Nine of nine pair exactly with `dos_1992`, at msdos's own indices, which run
six ahead as everywhere else in this stage:

```
  F0 c5e86060b6b8 = dos 274    F1 c07576105f57 = dos 275
  F2 0c17626e8e97 = dos 276    F3 c86674abae91 = dos 277
  F4 8702f4c6ab21 = dos 278    F5 df9fb17c0f9a = dos 279
  F6 4d49c79220f6 = dos 280    F7 21a46c208511 = dos 281
  F8 ea201c614ecc = dos 282
```

Nine distinct hashes, nine matches. Neither branch's routine names the
subject: both call it `FILL_PAGE_FF_COLOR_8_ONCE`, which is generated. So
unlike the pulse run there is no earned word here, and these are graded
`medium` accordingly -- the action is measured, the noun is read off the
picture.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_268 | CINEMATIC_FRAGMENTS_RECEDING_F0 | medium | 0xCFA8, 8 paths, 155.0x102.5: five separate pieces spread across x[141.0, 296.0], the widest the group ever is |
| CINEMATIC_269 | CINEMATIC_FRAGMENTS_RECEDING_F1 | medium | 0xD050, 8 paths, 133.5x89.5, same five silhouettes |
| CINEMATIC_270 | CINEMATIC_FRAGMENTS_RECEDING_F2 | medium | 0xD0C0, 8 paths, 114.0x78.5 |
| CINEMATIC_271 | CINEMATIC_FRAGMENTS_RECEDING_F3 | medium | 0xD130, 8 paths, 98.0x71.0 |
| CINEMATIC_272 | CINEMATIC_FRAGMENTS_RECEDING_F4 | medium | 0xD1A0, 8 paths, 78.5x64.5 |
| CINEMATIC_273 | CINEMATIC_FRAGMENTS_RECEDING_F5 | medium | 0xD210, 8 paths, 64.5x59.5 |
| CINEMATIC_274 | CINEMATIC_FRAGMENTS_RECEDING_F6 | medium | 0xD280, 8 paths, 45.5x31.0 -- the group is now smaller than its own first piece was |
| CINEMATIC_275 | CINEMATIC_FRAGMENTS_RECEDING_F7 | medium | 0xD2FC, **6 paths**, 31.0x24.0: the pieces have begun to overlap |
| CINEMATIC_276 | CINEMATIC_FRAGMENTS_RECEDING_F8 | medium | 0xD374, **2 paths**, 40.0x38.0: one convex dark mass where five pieces were. Drawn twice by the teardown routine, at palette 0x18 then 0x1A, as the last picture before the channels are killed |

## What these names do not claim

`FRAGMENTS` says five separate angular pieces and no more. Nothing here
identifies them -- they are not recognisable as any object the intro has shown
before, and no routine in either branch names them.

`RECEDING` is the measured part: constant silhouettes, a box shrinking by five
times, and a centre that moves less than six pixels. It is not `TUMBLING`,
which would need a silhouette that changes, and it is deliberately not spelled
`RECEDE` -- `CINEMATIC_ACCELERATOR_TUNNEL_RECEDE_F0..F6` is a different run in
this same stage and the two should not read as one family.

The three pictures `CINEMATIC_292..294` from `BLINK_PAGE_FF_3X_LOOP` were
looked at in the same pass and are **not** named; see `notes/HANDOFF.md` for
the measurement that would settle them.
