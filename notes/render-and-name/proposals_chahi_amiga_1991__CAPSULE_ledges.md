# CAPSULE: a wide shot that assembles itself, seven pieces at a time

`LABEL_0ED5` draws seven still-numbered constants at fixed positions with a
`break` between each, so the picture builds up one piece per frame:

```
  video 034, x=160, y=100
  video 035, x=160, y=100
  video 036, x=78,  y=84
  selectVideoPage 0x00 / video 037, x=107, y=84 / selectVideoPage 0xFF
  video 038, x=160, y=100
  video 039, x=160, y=100
  video 040, x=160, y=100
  killChannel
```

Composited progressively at palette 3 (`palette_in_force.py` on the routine),
each piece is the same construction -- an orange rim over a grey top, a slab in
perspective -- and together they make one wide shot: a long ledge receding from
the right toward a vanishing point at the left, a small platform at its far end
with a tiny figure standing on it, and two large slabs closing the foreground.

```
  034  236.0x37.0  2 leaf   the long middle span, thickest at the right
  035   97.0x15.0  2 leaf   the thinner continuation, further off and higher
  036   42.0x9.0   3 leaf   a small flat platform at the far end
  037    7.5x8.5   4 leaf   a figure, pale and dark, about eight pixels tall
  038  137.0x45.0  2 leaf   a wide slab entering from the lower left
  039  168.0x86.0  2 leaf   the big foreground slab, a triangle across the corner
  040   43.0x26.5  2 leaf   a thin spur off the foreground slab
```

037 is the only one drawn into page 0 behind `selectVideoPage`, which is what a
figure painted into the backdrop rather than animated looks like. It is also
the only one of the seven with four leaves at eight pixels across -- the others
are two- and three-leaf slabs.

Sizes and construction are the evidence for "slab in perspective"; the
composite is the evidence for which slab is where. Names take the relative
position in the assembled shot, which this repository already does
(`CINEMATIC_CITY_FOREGROUND_GIRDER_BOTTOM_BRACE`,
`CINEMATIC_IDENT_SCREEN_EDGE_LEFT_OUTER`), and not the draw coordinates, which
`docs/NAMING.md` §1 forbids.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_034 | CINEMATIC_CAPSULE_LEDGE_MID_SPAN | medium | 0xBCB6, 236.0x37.0 in 2 leaves, orange rim over grey top; the first piece drawn and the longest, crossing the middle of the shot |
| CINEMATIC_035 | CINEMATIC_CAPSULE_LEDGE_FAR_SPAN | medium | 0xBCDA, 97.0x15.0, the same construction at a quarter of the depth, drawn second and continuing the first toward the vanishing point |
| CINEMATIC_036 | CINEMATIC_CAPSULE_LEDGE_FAR_PLATFORM | medium | 0xBC78, 42.0x9.0 in 3 leaves, a small flat slab drawn at `x=78, y=84`, at the far end of the span |
| CINEMATIC_037 | CINEMATIC_CAPSULE_LEDGE_DISTANT_FIGURE | medium | 0xBD76, **7.5x8.5 in 4 leaves** -- the only one that is not a slab -- drawn at `x=107, y=84` into page 0 alone, standing on the platform |
| CINEMATIC_038 | CINEMATIC_CAPSULE_LEDGE_NEAR_SPAN | medium | 0xBCFE, 137.0x45.0, the same construction again, entering from the lower left in front of the first two |
| CINEMATIC_039 | CINEMATIC_CAPSULE_LEDGE_FOREGROUND_SLAB | medium | 0xBD22, 168.0x86.0, the largest, a triangle across the bottom corner and the nearest thing in the shot |
| CINEMATIC_040 | CINEMATIC_CAPSULE_LEDGE_FOREGROUND_SPUR | medium | 0xBD4E, 43.0x26.5, a thin sliver of the same rim-and-top construction, drawn last and against the foreground slab |

`medium` throughout: the construction and the assembly order are measured, the
figure is unmistakable at four leaves and eight pixels, and "ledge" is the
plainest account of an orange-rimmed grey slab drawn in perspective. Nothing
here claims what the place is.
