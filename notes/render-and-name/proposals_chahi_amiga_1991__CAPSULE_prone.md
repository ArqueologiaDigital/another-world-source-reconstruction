# CAPSULE: two figures, one on the ground, in two phases

`LABEL_0145` and `LABEL_01B2` are the same shape of routine at
`[BUDDY_X],[BUDDY_Y]`, the second reached from the first through four
transition frames, each looping on `[0x29]`. **Every frame is two draws with
no `break` between them:**

```
LABEL_0145:                       LABEL_01B2:
   345 346  break                    415 354  break
   347 346  break                    416 354  break
   348 349  break   (+ a sound)      417 418  break
   350 349  break                    419 418  break
   347 346  djnz [0x29]              416 354  djnz [0x29]
```

So each routine has a four-member layer and a two-member layer, and the
four-member one is always drawn **first**, underneath.

## Which layer is which

```
  drawn first, four members        drawn second, two members
  345  73.5x31.5  10 paths         346  47.0x37.0  10 paths
  347  70.5x32.5  11 paths         349  54.5x37.0  10 paths
  348  52.5x34.5  11 paths
  350  68.5x31.0  11 paths

  415  73.5x31.5  10 paths         354  47.0x36.0  10 paths
  416  70.5x32.5  11 paths         418  54.5x36.0  10 paths
  417  50.5x34.5  11 paths
  419  66.5x31.0  11 paths
```

The first layer is 50 to 73 wide and 31 to 34 tall -- **wider than it is tall
in every frame**. The second is 47 to 54 wide and 36 to 37 tall, taller than
wide. Rendered, the first is a figure lying flat with its legs coming up in
two of the four frames, and the second is a figure bent forward over it. The
composite is one figure crouched over another on the ground.

The two routines' extents match almost frame for frame -- 73.5x31.5 against
73.5x31.5, 70.5x32.5 against 70.5x32.5 -- but `canonical_md5` separates every
pair, so they are two phases of one scene and not one animation stored twice.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_345 | CINEMATIC_CAPSULE_PRONE_FIGURE_0_F0 | medium | 73.5x31.5, 10 paths, the widest of its layer: a figure flat on the ground. Drawn first in its frame, so it is underneath |
| CINEMATIC_347 | CINEMATIC_CAPSULE_PRONE_FIGURE_0_F1 | medium | 70.5x32.5, 11 paths. Drawn twice per loop, more than any other frame of its layer |
| CINEMATIC_348 | CINEMATIC_CAPSULE_PRONE_FIGURE_0_F2 | medium | 52.5x34.5, 11 paths -- 21 narrower and 3 taller than F0, which is the legs coming up. A sound plays on this frame |
| CINEMATIC_350 | CINEMATIC_CAPSULE_PRONE_FIGURE_0_F3 | medium | 68.5x31.0, 11 paths, back to flat |
| CINEMATIC_346 | CINEMATIC_CAPSULE_KNEELING_FIGURE_0_F0 | medium | 47.0x37.0, 10 paths: taller than wide, unlike every frame of the layer under it. A figure bent forward. Drawn second, over the prone one |
| CINEMATIC_349 | CINEMATIC_CAPSULE_KNEELING_FIGURE_0_F1 | medium | 54.5x37.0, 10 paths: 7.5 wider at the same height |
| CINEMATIC_415 | CINEMATIC_CAPSULE_PRONE_FIGURE_1_F0 | medium | 73.5x31.5, 10 paths -- the same extent as phase 0's F0 and a different `canonical_md5`. Phase 1 is reached through four transition frames after phase 0's loop ends |
| CINEMATIC_416 | CINEMATIC_CAPSULE_PRONE_FIGURE_1_F1 | medium | 70.5x32.5, 11 paths, drawn twice per loop |
| CINEMATIC_417 | CINEMATIC_CAPSULE_PRONE_FIGURE_1_F2 | medium | 50.5x34.5, 11 paths, the narrowest of its layer |
| CINEMATIC_419 | CINEMATIC_CAPSULE_PRONE_FIGURE_1_F3 | medium | 66.5x31.0, 11 paths |
| CINEMATIC_354 | CINEMATIC_CAPSULE_KNEELING_FIGURE_1_F0 | medium | 47.0x36.0, 10 paths, taller than wide |
| CINEMATIC_418 | CINEMATIC_CAPSULE_KNEELING_FIGURE_1_F1 | medium | 54.5x36.0, 10 paths |

## What these names do not claim

`PRONE` and `KNEELING` are the aspect ratios and what the renders show: one
layer wider than tall in every frame, the other taller than wide in every
frame, the second drawn over the first. **Nothing here says what either figure
is doing to the other**, or which of them the scene is about. Both run at the
buddy slot, so #0138 bars taking an answer from the scene.

The phase index `_0` and `_1` is control-flow order: `LABEL_0145` loops first,
then four frames, then `LABEL_01B2` loops. It is not a frame index and the two
phases are not claimed to be the same motion.

`CINEMATIC_411` to `414`, the four transition frames between the phases, are
**left numbered**; they were not rendered for this batch.
