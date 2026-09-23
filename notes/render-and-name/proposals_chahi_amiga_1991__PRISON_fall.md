# PRISON: debris falling and settling, eight frames

`LABEL_105E` plays a sound and then draws eight pictures, one per `break`, at
`[BUDDY_X],[BUDDY_Y]` -- an actor slot, so per **#0138** the names come from
the art. Every frame is guarded by `jne [0x10], [SCREEN_NUM]`, so the whole
sequence aborts if the player leaves the screen.

```
	play id=0x005A, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_368 ... 374     one per break, to the front page
	selectVideoPage 0x00
	video offset=CINEMATIC_375             the last frame, to page 0
	selectVideoPage 0xFF
```

The last frame is the only one written to **page 0**, the page the room keeps.
The other seven are drawn to the front buffer and vanish with it. Whatever
this is, its final state is meant to stay on the floor.

## Three measurements, one motion

```
         width   height   bottom edge   paths
  368     46.0    77.0        +0.5        35
  369     57.0    76.0        +0.5        35
  370     66.0    65.5        +1.0        35
  371     75.0    50.0        +0.5        34
  372     80.0    40.5        +1.0        31
  373     80.0    37.5        +1.0        25
  374     80.0    26.5        +1.0        23
  375     80.0     4.5        +1.0        21
```

The spread grows 46 to 80 and then **stops** at 80. The height collapses 77 to
**4.5**. The bottom edge never moves: every frame sits on y +0.5 to +1.0. And
the path count falls 35 to 21, so pieces are leaving as it goes.

Rendered, that is exactly what it looks like: a cloud of small bright and dark
fragments high in the frame, spreading outward and dropping, until the last
frame is a single flat row of them lying on the ground.

Eight distinct `canonical_md5`s.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_368 | CINEMATIC_PRISON_FALLING_DEBRIS_F0 | high | 46.0x77.0, 35 paths of small bright and dark fragments, the tallest and narrowest of the eight. Drawn first, immediately after `play id=0x005A` at vol 0x40 |
| CINEMATIC_369 | CINEMATIC_PRISON_FALLING_DEBRIS_F1 | high | 57.0x76.0, 35 paths: wider, barely shorter -- the spread starts before the fall does |
| CINEMATIC_370 | CINEMATIC_PRISON_FALLING_DEBRIS_F2 | high | 66.0x65.5, 35 paths |
| CINEMATIC_371 | CINEMATIC_PRISON_FALLING_DEBRIS_F3 | high | 75.0x50.0, 34 paths: height down by a third since F0 |
| CINEMATIC_372 | CINEMATIC_PRISON_FALLING_DEBRIS_F4 | high | 80.0x40.5, 31 paths. Width reaches 80.0 here and never changes again -- the cloud has spread as far as it will |
| CINEMATIC_373 | CINEMATIC_PRISON_FALLING_DEBRIS_F5 | high | 80.0x37.5, 25 paths |
| CINEMATIC_374 | CINEMATIC_PRISON_FALLING_DEBRIS_F6 | high | 80.0x26.5, 23 paths: the last frame drawn to the front buffer |
| CINEMATIC_375 | CINEMATIC_PRISON_FALLING_DEBRIS_F7 | high | 80.0x**4.5**, 21 paths: a single flat row of fragments on the ground. The only one of the eight drawn to **page 0**, between a `selectVideoPage 0x00` and a `selectVideoPage 0xFF`, so it stays in the room after the sequence ends |

## What these names do not claim

`DEBRIS` is what the pictures show -- small angular fragments, no two alike,
some bright and some dark. Nothing here says what they came off. The sequence
runs at the buddy's slot, and #0138 is the reason that is not taken as an
answer.

The index is the routine's own play order, which is also ascending bank offset
(0x7B94 to 0x7F48).
