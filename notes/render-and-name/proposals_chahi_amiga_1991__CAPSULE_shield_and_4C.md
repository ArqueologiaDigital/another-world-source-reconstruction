# CAPSULE: a shield that deploys, and the arcade screen it deploys in

## The shield, from its two routines

`CAPSULE_SHIELD_DEPLOY_AT_LEFT_EDGE` and `..._AT_RIGHT_EDGE` are mirror images
of each other and draw the same five pictures, one per `break`, marching in
from the screen edge:

```
  left edge     098 @x=5   GLOW @x=10   100 @x=15   097 @x=16   096 @x=17
  right edge    098 @x=315 GLOW @x=307  100 @x=303  097 @x=300  096 @x=? (mirrored)
```

and their measured heights grow in exactly that order:

```
  098  0x22F4   5.0x 6.0   2 paths
  100  0x2350   5.0x 6.0   2 paths
  097  0x19DC   7.0x42.0   2 paths
  096  0x1A14   3.5x68.0   2 paths
```

6, 6, 42, 68 -- a thing opening upward from a spark at the edge. The stage
already has `CINEMATIC_SHIELD_DECAY_PHASE_0..3`, four phases of the same object
going the other way, and these are its counterpart. Two sources agree again:
the routine word `DEPLOY` and the height order.

## Screen 4C

`CAPSULE_SCREEN_4C_BACKDROP_DRAW` fills page 0 and lays five pictures down.
Placed, the screen is an arcade: a wall of arches with a stained window in it,
a cornice across the middle, and spikes hanging inside the arches.

```
  146  0xA040  315.0x234.5  22 paths  x[ 139.0, 454.0]   the right half of the wall
  147  0xA028  303.0x234.5  47 paths  x[-121.5, 181.5]   the left half, with the window
  123  0xDF3E  292.0x  5.0  64 paths  y[  95.5, 100.5]   a 5-pixel band across the width
  148  0xFDF0  248.0x185.0  23 paths                     spikes inside the arches
  149  0xFE2C   23.0x 38.0   2 paths  x[291.5, 314.5]    two more at the top right
```

146 and 147 each run off one edge of the page and together tile its width;
123 is 64 paths confined to a band five pixels tall. Against the frame before
it, 148 puts hanging spikes inside the arch mouths and a small ring at the
left, and 149 adds two more spikes under the ridge at the top right.

`123` is also drawn by screen 4D and by `DRAW_FINAL_ESCAPE_LESTER_RUNNING_BG`,
so it takes no screen word. The other four are screen 4C's alone.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_098 | CINEMATIC_SHIELD_DEPLOY_PHASE_0 | high | 0x22F4, 5.0x6.0 in 2 paths, drawn **first** and furthest out (x=5 at the left edge, x=315 at the right) by both `CAPSULE_SHIELD_DEPLOY_AT_*_EDGE` routines |
| CINEMATIC_100 | CINEMATIC_SHIELD_DEPLOY_PHASE_1 | high | 0x2350, 5.0x6.0 in 2 paths, third draw, one step further in |
| CINEMATIC_097 | CINEMATIC_SHIELD_DEPLOY_PHASE_2 | high | 0x19DC, **7.0x42.0**, seven times the height of the first two |
| CINEMATIC_096 | CINEMATIC_SHIELD_DEPLOY_PHASE_3 | high | 0x1A14, **3.5x68.0**, the tallest and last. `SHIELD_DECAY_PHASE_0..3` is the same object's four phases in the other direction |
| CINEMATIC_147 | CINEMATIC_CAPSULE_SCREEN_4C_ARCADE_LEFT | medium | 0xA028, 47 paths, 303.0x234.5 at x[-121.5, 181.5] -- runs off the left edge -- and carries the stained window |
| CINEMATIC_146 | CINEMATIC_CAPSULE_SCREEN_4C_ARCADE_RIGHT | medium | 0xA040, 22 paths, 315.0x234.5 at x[139.0, 454.0], running off the right edge. With `..._LEFT` it tiles the width |
| CINEMATIC_123 | CINEMATIC_CAPSULE_ARCADE_CORNICE | medium | 0xDF3E, **64 paths** confined to a band 5.0 pixels tall at y[95.5, 100.5], spanning 292 of the 320. Also drawn by screen 4D and `DRAW_FINAL_ESCAPE_LESTER_RUNNING_BG`, so no screen word |
| CINEMATIC_148 | CINEMATIC_CAPSULE_SCREEN_4C_ARCH_SPIKES | medium | 0xFDF0, 23 paths, 248.0x185.0: hanging spikes inside the arch mouths, plus a small ring at the left. Drawn fourth |
| CINEMATIC_149 | CINEMATIC_CAPSULE_SCREEN_4C_RIDGE_SPIKES | medium | 0xFE2C, **2 paths**, 23.0x38.0 at x[291.5, 314.5]: two more spikes hanging under the ridge at the top right. Drawn last |

## What these names do not claim

The four shield phases are `high` because the routine word and the height order
are independent and agree. Nothing else here has two sources, and the rest are
`medium`.

`ARCADE` describes a wall of arches and says nothing about what the room is
for. `CORNICE` rests on 64 paths in a five-pixel band spanning the width, which
is a moulding-shaped fact, not a moulding.
