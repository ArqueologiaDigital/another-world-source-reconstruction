# PRISON: a green streak crossing, and a dark burst at each end of its path

Three routines, all drawing at `160,[0x19]` -- a fixed x with a variable y --
and all in pictures of one or two paths, 1 to 18 pixels across.

```
LABEL_0E0C   113 114 115 116 117 118   `play id=0x005B, freq=0x05, vol=0x0A`
LABEL_0E3A   107 108 109 110 111 112   `play id=0x005B, freq=0x07, vol=0x0A`
LABEL_0E68   119 120 121 122 123 124 125 126   (no sound)
```

## The fills sort them without any judgement

```
  119..126   #202044 and #54db54 -- four frames green only, two dark only,
                                    two carrying both
  113..118   #202044 x1 in every frame, no green at all
  107..112   #202044 x1 in every frame, no green at all
```

Only the crossing run has `#54db54`. The other two are a single dark path per
frame, six frames each.

## The geometry ties the three together

The crossing run's x centres march one way and do not turn back:

```
  119  -24.0    121  -10.0    123  +10.0    125  +24.0
  120  -20.0    122    0.0    124  +19.0    126  +32.0
```

and its widths are 4, 4, 18, 18, 9, 18, 18, 4 -- a dot at each end and
streaks in between.

The two silent-coloured runs sit **at those two ends**: `113..118` spans
x -32.5 to -21.5, around the crossing run's first centre of -24.0, and
`107..112` spans +27.5 to +38.5, around its last of +32.0. Neither moves
sideways; both bob vertically, y from about +5 up to -2 and back.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_119 | CINEMATIC_PRISON_GREEN_TRACER_F0 | medium | 4.0x2.0, 1 path(s), centred at x -24.0 |
| CINEMATIC_120 | CINEMATIC_PRISON_GREEN_TRACER_F1 | medium | 4.0x2.0, 1 path(s), centred at x -20.0 |
| CINEMATIC_121 | CINEMATIC_PRISON_GREEN_TRACER_F2 | medium | 18.0x3.0, 2 path(s), centred at x -10.0 |
| CINEMATIC_122 | CINEMATIC_PRISON_GREEN_TRACER_F3 | medium | 18.0x3.0, 2 path(s), centred at x +0.0 |
| CINEMATIC_123 | CINEMATIC_PRISON_GREEN_TRACER_F4 | medium | 9.0x2.0, 1 path(s), centred at x +10.0 |
| CINEMATIC_124 | CINEMATIC_PRISON_GREEN_TRACER_F5 | medium | 18.0x2.0, 1 path(s), centred at x +19.0 |
| CINEMATIC_125 | CINEMATIC_PRISON_GREEN_TRACER_F6 | medium | 18.0x3.0, 1 path(s), centred at x +24.0 |
| CINEMATIC_126 | CINEMATIC_PRISON_GREEN_TRACER_F7 | medium | 4.0x2.0, 1 path(s), centred at x +32.0 |
| CINEMATIC_113 | CINEMATIC_PRISON_TRACER_BURST_LEFT_F0 | medium | 11.0x5.0, 1 path(s), centred at x -27.0 |
| CINEMATIC_114 | CINEMATIC_PRISON_TRACER_BURST_LEFT_F1 | medium | 7.0x4.0, 1 path(s), centred at x -28.0 |
| CINEMATIC_115 | CINEMATIC_PRISON_TRACER_BURST_LEFT_F2 | medium | 9.0x1.0, 1 path(s), centred at x -28.0 |
| CINEMATIC_116 | CINEMATIC_PRISON_TRACER_BURST_LEFT_F3 | medium | 8.0x5.0, 1 path(s), centred at x -27.0 |
| CINEMATIC_117 | CINEMATIC_PRISON_TRACER_BURST_LEFT_F4 | medium | 2.0x7.0, 1 path(s), centred at x -26.0 |
| CINEMATIC_118 | CINEMATIC_PRISON_TRACER_BURST_LEFT_F5 | medium | 6.0x4.0, 1 path(s), centred at x -26.0 |
| CINEMATIC_107 | CINEMATIC_PRISON_TRACER_BURST_RIGHT_F0 | medium | 10.0x6.0, 1 path(s), centred at x +33.0 |
| CINEMATIC_108 | CINEMATIC_PRISON_TRACER_BURST_RIGHT_F1 | medium | 5.0x4.0, 1 path(s), centred at x +32.0 |
| CINEMATIC_109 | CINEMATIC_PRISON_TRACER_BURST_RIGHT_F2 | medium | 9.0x3.0, 1 path(s), centred at x +32.0 |
| CINEMATIC_110 | CINEMATIC_PRISON_TRACER_BURST_RIGHT_F3 | medium | 5.0x3.0, 1 path(s), centred at x +32.0 |
| CINEMATIC_111 | CINEMATIC_PRISON_TRACER_BURST_RIGHT_F4 | medium | 5.0x5.0, 1 path(s), centred at x +33.0 |
| CINEMATIC_112 | CINEMATIC_PRISON_TRACER_BURST_RIGHT_F5 | medium | 4.0x4.0, 1 path(s), centred at x +33.0 |

## What these names do not claim

`GREEN_TRACER` is `#54db54` on a shape whose x centre goes from -24.0 to
+32.0 without turning back, widening to 18-pixel streaks in the middle and
narrowing to 4-pixel dots at both ends. It does not say what fired it.

`TRACER_BURST_LEFT` and `_RIGHT` say only that each cluster of dark fragments
sits at one end of that path and stays there. **Which end is the source and
which the target is not claimed**: the two sound at different frequencies,
0x05 and 0x07, and nothing here says which comes first.

All three runs draw at `160,[0x19]`, so their height is whatever the caller
sets and no frame here states it.
