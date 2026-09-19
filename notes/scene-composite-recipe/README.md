# Composing a scene, and the palette that makes it visible

The captioned work order (`notes/caller-derived-naming/art_with_named_drawers.py`)
runs out at the groups that are **scenes rather than runs**: one routine drawing
a dozen unrelated props in one go. A thumbnail sheet cannot name those — each
prop is a shape with no context. The notes kept saying "needs a composed-scene
render". This is that step, working, with the one thing that stops it working.

## The recipe

```bash
cd another-world-archaeology
# 1. the SVGs, AT THE PALETTE THE SCENE RUNS UNDER (see below)
~/compartilhado/AnotherWorld_VMTools/target/release/awvm-render-polygons \
    --port amiga --stage 3 --romset tmp/output/amiga/romset \
    --out /tmp/awvm_svg/amiga_stage3_pal2 --palette 2
# 2. the composite
python3 tools/render_scene_composite.py FILL_AND_DRAW_CIN_24_28 \
    --port amiga --stage 3 --palette 2 \
    --svg-dir /tmp/awvm_svg/amiga_stage3_pal2 --out /tmp/scene.png
```

Stage numbers: CODE_WHEEL 0, INTRO 1, LAKE 2, PRISON 3, CAVES 4, TANK 5,
CAPSULE 6, ENDING 7, PASSCODE 8.

## The palette is not optional and the default is a trap

`render_scene_composite.py` defaults to `--palette 0` and fills the canvas with
`#000000`. Run the PRISON example that way and it produces **a completely black
image** — not an error, not an empty one, a plausible-looking black frame. Every
polygon in it rendered black on black.

Under palette 2 the same eleven draws are a rock wall with a blast hole through
it, a structural column, and a grating along the bottom edge.

So: **find the palette from the caller, not from the default.** For the PRISON
scene above, `LABEL_1CB8` does `setPalette 0x02` two instructions before
`call FILL_AND_DRAW_CIN_24_28`. Grep back from the call site:

```bash
n=$(grep -n 'call FILL_AND_DRAW_CIN_24_28' src/levels/chahi_amiga_1991/PRISON.asm \
    | head -1 | cut -d: -f1)
sed -n "$((n-15)),${n}p" src/levels/chahi_amiga_1991/PRISON.asm | grep setPalette
```

This is the same caution `docs/NAMING.md` §5 records for screens — "the bytecode
usually loads the bitmap under a black palette and fades up, so the palette live
at the `load` site is often all-black and renders nothing" — reaching the
polygon layer. A black composite means the wrong palette far more often than it
means a black scene.

## What it is good for, and its limit

It answers "what is this a picture of?" for the whole shot. It does **not**, on
its own, tell you which prop in the picture is which constant: the tool paints
them all and gives back one image. To attribute a prop, either

* re-run with one draw removed and diff the two images, or
* read each prop's own box from `polygon_extent.py` and match it by shape and
  relative position against the composite.

`CINEMATIC_PRISON_GRATING_STRIP` was named from its own render before this
composite existed — 186x24, 63 thin vertical bars — and the composite confirms
it afterwards as the strip along the scene's bottom edge. That is the pattern
to copy: identify from the individual render, *confirm* against the composite.

## Draws with variable coordinates are skipped

The tool only places `video offset=X, x=<int>, y=<int>`. A scene drawn at
`[0x01],[0x02]` comes back empty with each skipped line reported. Pass those
explicitly with `--also CINEMATIC_NNN@<x>,<y>`, using the values the caller
seeds — which is how ENDING's fly-away shot was composed in
`notes/ending-fly-away-shot/`.
