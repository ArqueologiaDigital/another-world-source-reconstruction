# CAVES: the screen-91 backdrop, read with its layers placed

The first CAVES batch read with `compose_run.py --routine`, which puts every
layer at its own `x, y` instead of at the renderer's anchor. `CAVES` has never
been read that way, and `CAVES_SCREEN_91_BACKDROP_DRAW` is the densest target
in the stage: **9 of its 13 draws are still numbers**.

Rendered at palette 0x10 and built up in draw order, the screen is a domed
cavern: a wall-and-floor shell, a dome across the top, four glowing mounds
along the dome's base, four columns standing on the floor band, a broken ring,
and a long diagonal girder entering from the top right.

## Scope first

Three of the nine are drawn by other screens too, so they take no screen
number:

```
  606  screens 91, 92, 93, 94, 95        -> no screen word
  346  screens 4F and 91                 -> no screen word
  334  screens 4C and 91                 -> no screen word
  348  screen 91 and one generated label -> no screen word
  607, 608, 609, 610, 611  screen 91 only -> CAVES_SCREEN_91_*
```

This follows the stage's better existing names -- `CAVES_SCREEN_4C_CAVERN_ARCH`,
`..._4C_CAVERN_COLUMNS`, `..._4D_ARCHES` -- rather than the mechanical
`..._BACKDROP_LAYER_<n>` form that `../cross-port-art/align_draw_sites.py`
refuses to transfer precisely because it says nothing about the picture.

## The layers

```
  606  0xB3A2  437.5x247.5   6 paths   drawn first, straight after the page fill
  348  0x8174  255.0x 90.0   5 paths   a dome spanning the top
  607  0xE9D0   59.0x 15.0   8 paths   drawn FOUR times along the dome's base
  346  0xE8AC   36.5x 38.0   2 paths   a broken ring, two arcs with gaps
  608  0xF3F8   20.0x 70.0   1 path    a plain filled column
  609  0xF400   29.0x 65.5   3 paths   a column drawn as an outline
  610  0x80F8   13.0x 70.0   1 path    the narrowest column
  611  0xF528   26.0x 71.0   6 paths   a column with a lighter inset
  334  0xE8BA  133.0x100.0  11 paths   a long diagonal band in two shades
```

The four columns are all 65.5-71.0 tall and stand in the same floor band
(y[113.0, 184.0] wherever they are drawn), and they differ only in width and
construction: 1, 3, 1 and 6 paths. That is a set, not an animation, so they get
a bare numeric suffix in draw order, the way `CITY_GANTRY_BRACE_0..3` does.

`334` is worth seeing whole. At screen 91 it is drawn at `x=481, y=-80` -- the
y reads as -80 signed (`../coordinate-signedness/`) -- and lands at
x[217.5, 350.5] y[-74.0, 26.0], so only its lower-left corner is in frame.
Drawn at its other site it is a broad diagonal strip in two shades with two
small discs at one end.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_606 | CINEMATIC_CAVES_CAVERN_WALL_AND_FLOOR | medium | 0xB3A2, 6 paths, 437.5x247.5, the first thing drawn after `fill page=0x00` and the only one of the nine drawn by **five** screens (91 through 95): a dark field split by a lighter horizontal band |
| CINEMATIC_348 | CINEMATIC_CAVES_CAVERN_DOME | medium | 0x8174, 5 paths, 255.0x90.0, drawn second and spanning the top of the screen as a single arch |
| CINEMATIC_607 | CINEMATIC_CAVES_SCREEN_91_GLOW_MOUND | medium | 0xE9D0, 8 paths, 59.0x15.0, drawn **four times** in a row along the dome's base at y[93.5, 109.5]: a low mound with a bright spot on it |
| CINEMATIC_346 | CINEMATIC_CAVES_RING_OUTLINE | medium | 0xE8AC, **2 paths**, 36.5x38.0: two arc strokes forming a ring with gaps in it. Drawn by screen 4F as well as 91 |
| CINEMATIC_608 | CINEMATIC_CAVES_SCREEN_91_COLUMN_0 | medium | 0xF3F8, **1 path**, 20.0x70.0, standing in the floor band at y[114.0, 184.0]. First column drawn |
| CINEMATIC_609 | CINEMATIC_CAVES_SCREEN_91_COLUMN_1 | medium | 0xF400, 3 paths, 29.0x65.5 -- an outline rather than a filled block -- drawn twice, at x[96.5, 125.5] and x[268.5, 297.5] |
| CINEMATIC_610 | CINEMATIC_CAVES_SCREEN_91_COLUMN_2 | medium | 0x80F8, **1 path**, 13.0x70.0, the narrowest of the four |
| CINEMATIC_611 | CINEMATIC_CAVES_SCREEN_91_COLUMN_3 | medium | 0xF528, **6 paths**, 26.0x71.0, a column with a lighter inset. Drawn last, and only when `[0xB1] & 0x04` is zero |
| CINEMATIC_334 | CINEMATIC_CAVES_DIAGONAL_GIRDER | medium | 0xE8BA, 11 paths, 133.0x100.0: a broad diagonal strip in two shades with two small discs at one end. Drawn by screen 4C as well as 91, and at 91 only its corner is on the page |

## What these names do not claim

Every row is `medium`. They rest on a placed composite and on the stage's own
`CAVERN`/`COLUMN` vocabulary, not on anything structural, and none of them
claims a material or a function -- `GLOW_MOUND` says a low mound with a bright
spot, `DIAGONAL_GIRDER` says a long diagonal band with two discs on it.

The four columns are numbered in draw order because nothing else separates
them; the index is not a frame index and they are all on screen at once.
