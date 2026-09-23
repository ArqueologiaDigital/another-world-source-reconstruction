# Reading a screen: one look instead of seven

| file | question it answers | command |
| --- | --- | --- |
| `contact_sheet.py` | What does every layer of a screen look like, in one image? | `python3 notes/scene-reading/contact_sheet.py --stage PRISON --screen 65` |
| | Which screens still have unnamed layers, worst first? | `... --stage PRISON --list` |

## Why

`../prison-cell-block/` named PRISON screen 0x04 by rendering it, and the cost
was one composite plus six single-layer renders looked at **one at a time**.
At four names a screen and fifty screens a stage, the bottleneck is the
looking, not the rendering.

So render every layer of a screen into one labelled grid. A single look covers
the whole screen, and the tiles sit side by side, which is how you see that
five tiles are variants of one object, or that one is a mirror of its
neighbour.

Each tile is scaled to **its own bounding box**, not the 320x200 canvas: a
6x70 sliver is invisible at canvas scale and obvious at tile scale. Under each
tile go the constant, its extent and its path count, so the picture and the
numbers are read together. Tiles are in paint order, and layers that are
already named are included and marked green — knowing what sits next to a
thing is most of identifying it.

Colours are `polygon_render.synthetic_palette`, not the stage's real palette,
on purpose: the synthetic palette gives adjacent indices contrasting colours
and separates a shape from its neighbours, where the real palette often paints
a whole object in two near-identical dark blues. The cell bars in
`../prison-cell-block/` were read this way and were unmistakable.

## What the first sheet found: the tiling is in the page blits

`../screen-scope/README.md` recorded that there is **no tiling structure in
the backdrop phase** — 0 pictures painted three or more times with a constant
step. That measurement was right and the conclusion drawn from it was too
broad, and the sheet for PRISON screen 0x65 is what showed it.

Its seven layers are two plain solid slabs and five clusters of small blobs
and scattered streaks. Nothing there repeats at the draw level. But the
routine that paints them does this:

```
fill page=0x03, color=0x00
fill page=0x00, color=0x00
selectVideoPage 0x03
call DRAW_CIN_SEQ_085_085_086          <- the pattern, drawn ONCE
selectVideoPage 0xFF
mov [SCROLL_Y], 0x0000
copyVideoPage src=0x83, dst=0x00       <- and blitted down,
add [SCROLL_Y], 0x0020                    five times, 0x20 apart
copyVideoPage src=0x83, dst=0x00
...
```

The repetition is a **page blit with a scroll offset**, not a repeated `video`
draw. So a draw-level tile test can never see it, and "no tiling structure"
should have read "no tiling *at the draw level*".

Measured across both priority ports, exactly two routines do this — one per
port, and msdos had already half-named its own
`PRISON_SCENE_INIT_DRAW_CIN_085_086_TO_PAGE_3`, which names the mechanism and
confirms the reading. Both are now `PRISON_BACKDROP_TILE_REPEAT_DOWN`.

It is a small class. The finding that matters is the shape of the blind spot:
**a backdrop can be built by page operations that no polygon-level probe will
ever attribute**, and any future count of "pictures that make up a screen"
has to reckon with `copyVideoPage` and `SCROLL_Y`.
