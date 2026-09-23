# PRISON screen 0x04, read by rendering it

This is the first scene named by the render-and-look method in this line of
work, and it is written up in full because the *method* is what the next
screens need, not the four names it produced.

## The recipe

Everything below regenerates from the repos; no PNG is committed, because
they are regenerable and large.

```
# 1. the bank as a flat file the renderer can take offsets into
python3 - <<'EOF'
import sys; sys.path.insert(0, "notes/polygon-extent-correction")
from extent_matches_renderer import slab
open("/tmp/prison_bank.bin", "wb").write(slab("cinematic", "amiga", 3))
EOF

# 2. the whole backdrop, composited, in the palette the entry sets
python3 ../another-world-archaeology/tools/render_scene_composite.py \
    LABEL_4A2B --port amiga --stage 3 --palette 2 --scale 1 \
    --out /tmp/prison04_bg.png

# 3. one layer on its own (0xA560 is CINEMATIC_431's EQU)
python3 ../another-world-archaeology/tools/polygon_render_png.py \
    /tmp/prison_bank.bin 0xA560 --palette-index 2 \
    --canvas-w 320 --canvas-h 200 -o /tmp/L_431.png
```

Two things cost an hour and are worth writing down. `render_scene_composite.py`
takes a **routine**, and the routine to give it is the *painter*, not the
entry: `PRISON_SCREEN_04_ENTRY` composites 3 draws and looks empty, while the
`LABEL_4A2B` it calls composites all 7. And `polygon_render_png.py` takes an
offset **into the resource you hand it**, so the whole `cinematic.rom` with
`3 * 0x10000 + equ` silently renders nothing — it needs the extracted 64 KB
slab and the raw EQU value.

## What the screen is

A prison cell block seen from the corridor: a row of barred cell fronts along
the bottom, a figure behind one of them, a lit open doorway at the right, a
post, and girders and floating debris in the dark upper half.

`LABEL_4A2B` paints it in seven layers, all at `x=160, y=100`, and every one
of the seven is drawn **exactly once in the whole stage, by this routine**,
which is called only from `PRISON_SCREEN_04_ENTRY`. So they belong to this
scene and to nothing else.

| constant | extent | paths | what the render shows | named |
| --- | --- | --- | --- | --- |
| `CINEMATIC_428` | 114x124 | 21 | crossed diagonal struts, upper right | `..._CELL_BLOCK_GIRDERS` |
| `CINEMATIC_429` | 146x86 | 13 | small quadrilaterals scattered in the dark | `..._CELL_BLOCK_DEBRIS` |
| `CINEMATIC_430` | 390x85 | 7 | a full-width solid slab under a thin lip line | `..._CELL_BLOCK_FLOOR` |
| `CINEMATIC_305` | 494x28 | 130 | — | **held**: shared with other screens |
| `CINEMATIC_431` | 253x67 | 130 | **five barred cell fronts in a row** | `..._CELL_ROW_BARS` |
| `CINEMATIC_432` | 64x70 | 16 | a vertical post with an arm and two highlights | **held**: a post, but of what? |
| `CINEMATIC_433` | 39x39 | 22 | a narrow panel of coloured vertical strips | **held**: bars, or the figure? |

`CINEMATIC_431` is the one the whole reading rests on: 130 paths over 253x67
resolving into five equal barred panels is not ambiguous, and it fixes the
scene as a cell block, which then makes the slab a floor and the scattered
quads debris.

## Three held back, on purpose

`CINEMATIC_305` is drawn by several screens' backdrops, so it is not this
scene's to name. `CINEMATIC_432` is clearly a post and not clearly a post *of
what* — a lamp, a sensor, a door jamb are all consistent with 64x70 and two
highlights. `CINEMATIC_433` is the one I would most like back: it is at the
lower left where the composite shows a figure inside a cell, and coloured
vertical strips are equally consistent with a narrow barred panel and with a
standing figure. Naming either would be guessing, and this project's own
record is that renders mislead — two passes over LAKE misread the same group.

## Cross-port

All seven hold identical art in msdos (`canonical_md5`), painted by
`LABEL_4ACC` from that port's `PRISON_SCREEN_04_ENTRY`, at the same constant
numbers. So the reading transfers and the names are applied to every branch.

## The rate

Four names, from one screen, at the cost of a composite, six single-layer
renders and a cross-port check. There are roughly fifty screens per stage.
That is the honest rate of the method, and it is why every mechanical seam was
exhausted first — see `../sole-named-drawer/README.md` for the ledger of those.
