# PRISON: the gun on the ground, read from a render at palette 6

`GUN_PICKUP_SCENE` fires when `[HERO_X]` is between 0xF0 and 0x104. It draws
one picture into the world view, copies the page away, fills page 0 and cuts
to a close-up:

```
	video offset=CINEMATIC_172, x=253, y=181     <- into the world view
	copyVideoPage src=0x00, dst=0x03
	fill page=0x00, color=0x05
	video offset=CINEMATIC_173, x=160, y=100     <- the close-up
	video offset=CINEMATIC_174, x=160, y=100
	video offset=CINEMATIC_THE_GUN, x=160, y=100
```

`CINEMATIC_THE_GUN` and `CINEMATIC_LESTER_HAND_GRABBING_GUN_F0..F5` are
already named, so the subject of the close-up is settled and these five fill
it in.

## The backdrop is two pictures that do not overlap

```
  CINEMATIC_173   190.5x182.0   32 paths   x[-159.5,  31.0]
  CINEMATIC_174   106.5x182.0    2 paths   x[  54.0, 160.5]
```

The x ranges are disjoint -- 173 ends at +31.0 and 174 starts at +54.0 -- so
they are the left and right of one image, not two layers. 173 is the floor,
scattered with small pale marks; 174 is two tall pale wedges at the right
edge, and it is two paths because that is all it is.

## The two flicker frames are one picture in two colours

`GUN_FLICKER_HOLD_177` and `GUN_FLICKER_HOLD_176` each redraw
`CINEMATIC_THE_GUN` and then one of these, five `break`s at a time. Both are
5x5, three paths, at the same place -- x[-25.0,-20.0] y[47.0,52.0], which is
on the gun's body. Their path data is **identical to the coordinate**:

```
  176   #101020  M137 147 L140 151 L139 151 L136 147 Z
        #101020  M136 147 L139 151 L138 151 L135 147 Z
        #005400  M137 148 L140 152 L139 152 L136 148 Z

  177   #309700  M137 147 L140 151 L139 151 L136 147 Z
        #309700  M136 147 L139 151 L138 151 L135 147 Z
        #74db00  M137 148 L140 152 L139 152 L136 148 Z
```

Three one-pixel diagonal strokes, drawn once near black over dark green and
once green over bright green. Same geometry, two brightness states, alternating
on a timer. `canonical_md5` separates them (819e63ac / 1bccc05f), so they are
two constants and not one drawn twice.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_173 | CINEMATIC_PRISON_GUN_CLOSEUP_BACKDROP_0 | high | 190.5x182.0, 32 paths, x[-159.5, 31.0]: the floor of the close-up, a broad field with small pale marks scattered over it. Drawn first of the two, and its x range does not reach `_1`'s. Redrawn once more with `_1` when the scene repaints after the palette fade |
| CINEMATIC_174 | CINEMATIC_PRISON_GUN_CLOSEUP_BACKDROP_1 | high | 106.5x182.0, **2 paths**, x[54.0, 160.5]: two tall pale wedges at the right edge and nothing else -- the path count says so. Disjoint from `_0`, so the pair is one image cut in two, not a layer over a layer |
| CINEMATIC_176 | CINEMATIC_PRISON_GUN_INDICATOR_DARK | medium | 5x5, three one-pixel diagonal strokes on the gun's body at x[-25.0,-20.0] y[47.0,52.0], filled `#101020`, `#101020`, `#005400`. Identical in geometry to `_LIT` and different only in colour, and the two alternate in five-`break` hold loops. `INDICATOR` is the weakest word that explains a mark switching between near-black and bright green; a reflection would not go dark |
| CINEMATIC_177 | CINEMATIC_PRISON_GUN_INDICATOR_LIT | medium | the same three strokes, filled `#309700`, `#309700`, `#74db00`. It is also the frame held under `CINEMATIC_LESTER_HAND_GRABBING_GUN_F0`, the moment the hand closes on the gun |
| CINEMATIC_172 | CINEMATIC_PRISON_GUN_ON_GROUND | medium | 15.0x3.0, one path. Drawn **once**, at the literal position 253,181 -- low on the screen, inside the `[HERO_X]` 0xF0..0x104 window this scene tests for -- into page 0, which is then copied to page 3 and kept. It is what the room shows where the close-up is about to show a gun lying on a floor. A 15x3 bar carries no detail of its own, so this is `medium` and rests on the draw: one picture, one fixed floor position, immediately before the cut |

## What these names do not claim

`BACKDROP_0` and `_1` are the left and right of one image. The index is draw
order and the evidence says which is which; neither is a layer over the other,
and neither is a facing direction.

`INDICATOR` says the mark has two states and that one is lit. It does not say
what it indicates.
