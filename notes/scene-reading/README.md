# Reading a screen: one look instead of seven

| file | question it answers | command |
| --- | --- | --- |
| `contact_sheet.py` | What does every layer of a screen look like, in one image? | `python3 notes/scene-reading/contact_sheet.py --stage PRISON --screen 65` |
| | Which screens still have unnamed layers, worst first? | `... --stage PRISON --list` |
| | …with the layers also drawn at their real anchors | `... --screen 4D --composite` |

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

## `--composite`, and what it settled and did not

The grid shows each shape; `--composite` draws them at their real anchors into
a 320x200 panel above it. The arrangement is most of what identifies a shape,
and having both in one image means one look does the work of the composite and
the six single renders that naming PRISON screen 0x04 took.

It is self-contained, which the archaeology repo's `render_scene_composite.py`
is not: that one reads pre-rendered SVGs from a directory you have to build
first, and it wants the **painter** routine rather than the entry.

### Worked example: CAPSULE screen 0x4D

```
python3 notes/scene-reading/contact_sheet.py --stage CAPSULE --screen 4D --composite
```

Five layers, all at `x=160, y=100` — stacked depth, not tiled:

| | constant | extent | paths | |
| --- | --- | --- | --- | --- |
| 0 | `CINEMATIC_422` | 299x234 | 17 | arched wall, the back pass |
| 1 | `CINEMATIC_423` | 323x234 | 22 | arched wall, the front pass |
| 2 | `CINEMATIC_123` | 292x5 | 64 | a thin horizontal strip across the middle |
| 3 | `CINEMATIC_424` | 242x207 | 19 | sparse thin spikes and dots |
| 4 | `CINEMATIC_425` | 240x88 | 14 | the same, lower |

**No names were applied from this.** What the sheet settles is the *structure*
— two architectural passes at different depths, a strip between them, two
sparse detail layers in front — and that is worth recording. What it does not
settle is what the arches depict, and between a colonnade, a cavern mouth and
a row of cell arches the render is genuinely ambiguous. Naming them would be
guessing at the fiction, which is the failure this project has recorded twice
over LAKE.

The positional scheme already describes these correctly and is blocked only by
`CINEMATIC_123`: it is painted in three screens' phases (0x4B, 0x4C, 0x4D), so
it belongs to none of them, and the hole it leaves at index 2 makes the whole
screen's family non-contiguous. That is the same shape as the footstep holes
in `../draw-label-follows-constant/` — the gap is the information, and the
applier is right to refuse.

So the honest reading of this screen is: **structure recorded, most names
withheld, and the reason is in the art rather than in the tooling.**

### What the tree's own vocabulary then settled

Two of the five were nameable after all, and what settled them was not the
render — it was the names already next door. Screen 0x4B calls
`DRAW_FINAL_ESCAPE_LESTER_RUNNING_BG` and screen 0x4C installs
`BUDDY_SMASHING_WINDOW_ANIMATION`, and a prior dossier
(`another-world-archaeology/docs/.../big-three-singletons/dossiers/amiga_CAPSULE`)
records the three painters as one family. So the locale is known, and the two
large layers are what the render plainly shows — a wall of rounded arches,
painted twice at one anchor, back pass then front:

```
CINEMATIC_422  299x234, 17 paths  ->  CINEMATIC_CAPSULE_ARCH_WALL_FAR
CINEMATIC_423  323x234, 22 paths  ->  CINEMATIC_CAPSULE_ARCH_WALL_NEAR
```

No story is claimed: the name says arched wall, and far/near is the paint
order. `CINEMATIC_123`, `424` and `425` stay numbered.

### And it closed a loop from earlier in the session

Looking for msdos' twins **by `canonical_md5` rather than by index** turned up
`CINEMATIC_478` and `CINEMATIC_479` — the very constants that forced the
blast-fade revert (`36139804`), where msdos' 478/479/480 were known only as
"unrelated art" drawn by `JUNK__9DD7` and `LABEL_9DF3`. They are the arched
wall. msdos' *own* `CINEMATIC_422`/`423` in CAPSULE are 100x19 and 12x2 and
have nothing to do with it, which is hazard #0107 in miniature and exactly
why the index must never be the bridge.

So both ports carry the same two names on different numbers, applied
branch-scoped. `cartridge_1992` draws these constants too but has no extracted
ROM, so its art cannot be checked and it was left alone.
