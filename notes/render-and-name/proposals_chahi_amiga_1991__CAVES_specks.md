# CAVES: small blue specks rising, five frames

`LABEL_DD5E` is set up on channel 0x0F and draws five pictures at
`[0x1A],[0x1B]`, the first followed by `play id=0x006D` at vol 0x20. The
anchor is nudged by the routine above it (`add [0x1B], 0x001B` or
`sub [0x1B], 0x000A`, chosen on `[0x63]`), so the five sit wherever that put
them.

## They rise and they thin out

```
        extent      y range          fills
  504   2.0x 3.0   [ -0.5,   2.5]   #0064cb x1  #0097fb x1
  505   3.5x 6.5   [ -4.5,   2.0]   #0097fb x3  #0064cb x2
  506   3.5x12.5   [-12.5,   0.0]   #0097fb x3  #0064cb x2
  507   4.5x16.0   [-19.5,  -3.5]   #0064cb x5  #004497 x1
  508   2.0x19.0   [-26.5,  -7.5]   #0064cb x3
```

Height rises 3.0 to 19.0 while width stays between 2.0 and 4.5, and the whole
band climbs: the bottom edge goes from +2.5 to -7.5 and the top from -0.5 to
-26.5, so by F4 nothing is left where F0 was. The path count rises 2, 5, 5, 6
and then falls to 3.

Every path is one of three blues -- `#0064cb`, `#0097fb`, `#004497` -- and
nothing else, at palette 0x05. Rendered, they are small rectangles, never more
than a few pixels across, spreading apart as they go up.

`frame_runs.py --stages` reports **CAPSULE 5/5**: byte-identical twins there,
still numbered. Not CAVES art, so no stage word.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_504 | CINEMATIC_RISING_SPECKS_0 | medium | 2.0x3.0, two paths, y[-0.5, 2.5]: the lowest and smallest, at the anchor. The `play` follows it |
| CINEMATIC_505 | CINEMATIC_RISING_SPECKS_1 | medium | 3.5x6.5, five paths, y[-4.5, 2.0] |
| CINEMATIC_506 | CINEMATIC_RISING_SPECKS_2 | medium | 3.5x12.5, five paths, y[-12.5, 0.0]: the band's bottom edge reaches the anchor and stops going lower |
| CINEMATIC_507 | CINEMATIC_RISING_SPECKS_3 | medium | 4.5x16.0, **six paths**, the most of the five, and the widest at 4.5 |
| CINEMATIC_508 | CINEMATIC_RISING_SPECKS_4 | medium | 2.0x19.0, three paths, y[-26.5, -7.5]: the tallest band, the fewest specks, and entirely above where F0 was |

## What these names do not claim

`SPECKS` is the measurement: two to six paths, none more than 4.5 across, in
three blues and no other colour. `RISING` is the y range, which moves from
[-0.5, 2.5] to [-26.5, -7.5] without overlapping.

Nothing here says whether they are bubbles, sparks or droplets. The stage has
`CINEMATIC_DROPLET_FALL_TRAIL` and `CINEMATIC_DROPLET_SPRINKLE_DOT` already,
and this batch does **not** claim these are the same subject: it did not check,
and `transfer_across_stages.py` holds those two under "art matches two or more
names" for unrelated reasons.
