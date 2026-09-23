# PRISON: the same charge widget CAPSULE has, in PRISON's own bank

## How it was found

`PRISON_INLINE_SUB_VAR22_BY_23_L3` is the densest still-numbered routine in the
stage, and it plays eight constants at `[BUDDY_X], [BUDDY_Y]`:

```
  362  363  364  361   380  381  382  383  382
```

`CAPSULE`'s `LABEL_4038` plays its own widget in exactly that shape:

```
  213  214  215  212   266  267  268  269  268
```

Four bar frames ending on the one that opens the other routine, then a
two-frame flash and a three-draw glow. Slot for slot.

## Two independent confirmations

**The measurements match, piece for piece.**

    python3 notes/cross-stage-widget/same_widget.py --port amiga --show PRISON:...
    python3 notes/cross-stage-widget/same_widget.py --port amiga --show CAPSULE:...

```
                     PRISON              CAPSULE (already named)
  bar frames      4.0x3.0, 4 leaf      4.0x3.0, 4 leaf    SEGMENT_BAR_F0..F3
  flash 0         8.0x3.0, 2 leaf      8.0x3.0, 2 leaf    DISCHARGE_FLASH_F0
  flash 1        28.0x3.0, 2 leaf     28.0x3.0, 2 leaf    DISCHARGE_FLASH_F1
  glow 0/1     8.0x6.0 / 7.0x6.0, 2   same                CHARGE_GLOW_F0/F1
```

(The bar reads 6 px wide in the renderer and 4.0 here. Both are right: a leaf
whose header bbox is 0 or 1 wide is inflated to two pixels by the rasteriser,
which `polygon_extent.extent`'s docstring records; this table is the polygon
extent, not the drawn one.)

**And five of the eight are literally the same drawing.** Comparing PRISON's
bank slab against CAPSULE's:

```
  361  e9becc375d3d  ==  CAPSULE_SEGMENT_BAR_F0
  380  109ffa65fd9c  ==  CAPSULE_DISCHARGE_FLASH_F0
  381  7668429ade26  ==  CAPSULE_DISCHARGE_FLASH_F1
  382  7f2494dbe630  ==  CAPSULE_CHARGE_GLOW_F0
  383  febfeac8ef14  ==  CAPSULE_CHARGE_GLOW_F1
```

362, 363 and 364 differ from CAPSULE's F1, F2 and F3, which is what a bar whose
lit segments mean something stage-specific would do. Same widget, same slots,
three frames redrawn.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_361 | CINEMATIC_PRISON_SEGMENT_BAR_F0 | high | 0x80A6, 4.0x3.0 in 4 leaves, `e9becc375d3d` -- **the same drawing** as `CAPSULE_SEGMENT_BAR_F0`, and played last in the bar cycle exactly as CAPSULE's F0 is |
| CINEMATIC_362 | CINEMATIC_PRISON_SEGMENT_BAR_F1 | high | 0x8158, same 4.0x3.0 / 4-leaf construction, first in the cycle, CAPSULE's F1 slot. Art differs from CAPSULE's F1 |
| CINEMATIC_363 | CINEMATIC_PRISON_SEGMENT_BAR_F2 | high | 0x816E, same construction, second in the cycle |
| CINEMATIC_364 | CINEMATIC_PRISON_SEGMENT_BAR_F3 | high | 0x8186, same construction, third in the cycle |
| CINEMATIC_380 | CINEMATIC_PRISON_DISCHARGE_FLASH_F0 | high | 0x80D4, 8.0x3.0 in 2 leaves, `109ffa65fd9c` -- the same drawing as `CAPSULE_DISCHARGE_FLASH_F0`, in the same slot |
| CINEMATIC_381 | CINEMATIC_PRISON_DISCHARGE_FLASH_F1 | high | 0x812C, **28.0x3.0**, `7668429ade26` -- the same drawing as `CAPSULE_DISCHARGE_FLASH_F1` |
| CINEMATIC_382 | CINEMATIC_PRISON_CHARGE_GLOW_F0 | high | 0x8100, 8.0x6.0 in 2 leaves, `7f2494dbe630` -- the same drawing as `CAPSULE_CHARGE_GLOW_F0`, and drawn twice in the run as CAPSULE's is |
| CINEMATIC_383 | CINEMATIC_PRISON_CHARGE_GLOW_F1 | high | 0x81E6, 7.0x6.0 in 2 leaves, `febfeac8ef14` -- the same drawing as `CAPSULE_CHARGE_GLOW_F1` |

## What these names do not claim

They inherit CAPSULE's words, and CAPSULE's words were themselves `medium`
sight-readings: `CHARGE_GLOW` was borrowed from `ACTOR_CHARGE_GLOW_*` on a
two-path hexagon-around-a-core construction, and `SEGMENT_BAR` says only that
a small bar's coloured segments move. What is `high` here is that **this is the
same widget** -- five identical drawings and an identical play order -- not that
the widget's purpose is known.

The stage prefix follows CAPSULE's: these are PRISON's own constants at
PRISON's own offsets, and a future pass that finds the widget in a third stage
should do the same rather than reach for a shared name.
