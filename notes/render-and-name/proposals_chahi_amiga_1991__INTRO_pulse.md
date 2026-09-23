# INTRO: the pulse that shrinks to a point, and the two names caught wearing it

Rendered at **palette 0x16**, the palette this routine sets four lines before
the first of these frames. Composited over the tunnel the routine itself
copies to page 0 immediately before (`CINEMATIC_243` +
`..._TUNNEL_FLOOR_DETAIL` + `..._TUNNEL_WALL_DETAIL`), because none of these
pictures is legible on its own background.

## The beat is fifteen frames, one per `break`

`INTRO_COMPOSE_PAGE3_THEN_RECEDE_DOWN_ACCELERATOR_TUNNEL` draws fifteen
pictures at `x=160, y=100`, each separated from the next by a `break` and a
`play`. dos names the same routine
**`ACCELERATOR_TUNNEL_PULSE_SHRINKS_TO_POINT`**, and that earned label is where
`PULSE` comes from; it is not invented here.

Measured from the renderer's own SVG output, whole picture and the two core
colours (`#fb7474` salmon, `#fbdbb7` cream):

```
  F   offset   whole picture                       paths  salmon core  cream inner
  F0  0x887C   398.0x227.0  x[ -16.5, 381.5]         4    125.0x84.0   93.0x57.0
  F1  0x8890   251.5x146.5  x[  39.5, 291.0]         8     42.0x24.0   28.0x17.0
  F2  0x8958   127.0x147.0  x[ 100.5, 227.5]         8     32.0x17.0   21.0x12.0
  F3  0x8A24    92.0x 76.0  x[ 122.0, 214.0]         8     21.0x10.0   14.0x 7.0
  F4  0x8AE0    60.0x 56.5  x[ 137.0, 197.0]         8     12.0x 6.0    9.0x 4.0
  F5  0x8B90    44.5x 35.5  x[ 143.5, 188.0]         6      7.0x 5.0    2.0x 3.0
  F6  0x8C04    46.0x 45.5  x[ 140.5, 186.5]         5     10.0x 7.0      -
  F7  0x8C68    37.5x 48.5  x[ 141.0, 178.5]         5        -          -
  F8  0x8CD8    42.5x 40.0  x[ 143.0, 185.5]         5        -          -
  F9  0x8D4A    29.0x 35.5  x[ 160.0, 189.0]         5        -          -
  F10 0x8DA0    27.0x 23.0  x[ 157.5, 184.5]         4        -          -
  F11 0x8DF0    11.0x 10.0  x[ 161.5, 172.5]         1        -          -
  F12 0x8E10     7.0x  7.0  x[ 163.5, 170.5]         1        -          -
  F13 0x8E30     7.0x  7.0  x[ 163.5, 170.5]         2      2.0x 3.0     -
  F14 0x8E3E     2.0x  3.0  x[ 166.0, 168.0]         1        -          -
```

Three things make this one animation and not a set of unrelated pictures:

- **It converges.** 398x227 down to 2x3, and the box closes on `x[166, 168]
  y[82.5, 85.5]` -- the tunnel's vanishing point in the composite, 7 right and
  16 above the anchor every frame. The pictures do not move; they shrink in
  place onto that point.
- **The core carries through.** The same two fills, salmon over cream, at
  125x84, then 42x24, 32x17, 21x10, 12x6, 7x5 -- and F0's black is not a
  backdrop, it is the same black rim as F1's, grown past the screen edge (two
  quads spanning x[-16.5, 381.5], y[-15.5, 211.5] over a 320x200 page).
- **The art is contiguous.** 0x887C, 0x8890, 0x8958, 0x8A24, 0x8AE0 ... 0x8E3E,
  in the bank, in routine order, with nothing between.

Not perfectly monotone: F5 -> F6 grows 44.5x35.5 -> 46.0x45.5, and F13 puts
back a 2x3 salmon speck that F7..F12 do not have. Two frames of flicker in a
fifteen-frame collapse.

## Two of the fifteen already had names, and both were wrong

`CINEMATIC_LESTER_SEATED_AT_HOLO_CONSOLE_F1` (0x8958) and
`CINEMATIC_ACCELERATOR_TUNNEL_VIEW_NEAR` (0x8A24) are slots F2 and F3 above.
Each has **exactly one draw site in the whole branch** and it is this one.

- F2 is not a person. Its salmon core at 32x17 sits between F1's 42x24 and
  F3's 21x10, and its cream inner at 21x12 between 28x17 and 14x7. The
  misnamed frame interpolates the sequence on both measures.
- F3 is not a view of the tunnel. The tunnel is `CINEMATIC_243` at 0x3052,
  which is what it is being given below.

Both names came from `_AMIGA_EXTRA` collisions, and
`notes/amiga-extra-suffix/` measures which way each of those went. For
`LESTER_SEATED_AT_HOLO_CONSOLE_F1` the flip went the wrong way: `gba_2004`
gives the un-suffixed name to `b07528b7eb2e`, which amiga calls
`..._F1_AMIGA_EXTRA` at 0xFB26 and which renders as a seated figure from
behind with one arm raised -- between `_F0` (arm out to the right) and `_F2`
(arms down). So the name goes back where it came from, and the F1 slot never
opens a gap.

## Cross-port

All fifteen frames and the tunnel have the identical `canonical_md5` in amiga
and msdos -- 15 of 15, fifteen distinct hashes, no repeats:

```
  F0 41ea1c15e4a6  F1 164cb14d5f6d  F2 47c2ee5cfacc  F3 9b2f903b9cb1
  F4 4110b1ffab18  F5 9bade8223d66  F6 06c1cf01dd7a  F7 c1971bc9ed3c
  F8 b9cfba50634c  F9 2104a11d15d4  F10 1638ddc6fbfa F11 83d29ca64d2e
  F12 000946802289 F13 4946f17187de F14 3659eca60e4a
  tunnel 07f2de537d9c
```

The tunnel hash is the reason `VIEW_NEAR` moves rather than disappears:
`gba_2004` already calls `07f2de537d9c` `CINEMATIC_ACCELERATOR_TUNNEL_VIEW_NEAR`,
at its own 0x3052. amiga and msdos were the two branches that had it on the
wrong polygon.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_243 | CINEMATIC_ACCELERATOR_TUNNEL_VIEW_NEAR | high | 0x3052, `07f2de537d9c`: the ringed accelerator bore seen down its axis, 104 paths across 320x211.5. `gba_2004` gives this exact art that exact name. Drawn to page 0xFF with `_TUNNEL_FLOOR_DETAIL` and `_TUNNEL_WALL_DETAIL` and copied to page 0 as the backdrop the whole beat plays over |
| CINEMATIC_246 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F0 | high | 0x887C, 4 paths: two black quads spanning x[-16.5, 381.5] y[-15.5, 211.5] over a 320x200 page -- the rim of F1's core grown past every screen edge -- with the salmon/cream core at 125.0x84.0, the largest it ever is |
| CINEMATIC_247 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F1 | high | 0x8890, 8 paths, 251.5x146.5: the core down to 42.0x24.0 with the black rim broken into wide angular shards reaching most of the tunnel's width |
| CINEMATIC_LESTER_SEATED_AT_HOLO_CONSOLE_F1 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F2 | high | 0x8958, 8 paths, 127.0x147.0. Core 32.0x17.0 and inner 21.0x12.0, both strictly between F1's and F3's. Its only draw site in the branch is between F1's and F3's, and no part of it is a figure |
| CINEMATIC_ACCELERATOR_TUNNEL_VIEW_NEAR | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F3 | high | 0x8A24, 8 paths, 92.0x76.0, core 21.0x10.0. Its only draw site is the fourth `break` of this run. The tunnel view it was named for is 0x3052, above |
| CINEMATIC_250 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F4 | high | 0x8AE0, 8 paths, 60.0x56.5, core 12.0x6.0: the shards now thin spokes, all inside the tunnel's second ring |
| CINEMATIC_251 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F5 | high | 0x8B90, 6 paths, 44.5x35.5, core 7.0x5.0, inner down to 2.0x3.0 |
| CINEMATIC_252 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F6 | high | 0x8C04, 5 paths, 46.0x45.5, core 10.0x7.0: the one frame that grows, by 1.5 wide and 10 tall |
| CINEMATIC_253 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F7 | high | 0x8C68, 5 paths, 37.5x48.5. The last salmon is gone; from here it is black spokes on the lit tunnel |
| CINEMATIC_254 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F8 | high | 0x8CD8, 5 paths, 42.5x40.0 |
| CINEMATIC_255 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F9 | high | 0x8D4A, 5 paths, 29.0x35.5, x[160.0, 189.0] -- the box has closed to within 30 pixels of the convergence point |
| CINEMATIC_256 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F10 | high | 0x8DA0, 4 paths, 27.0x23.0 |
| CINEMATIC_257 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F11 | high | 0x8DF0, **1 path**, 11.0x10.0: the spokes are gone, a single blob left |
| CINEMATIC_258 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F12 | high | 0x8E10, 1 path, 7.0x7.0 at x[163.5, 170.5] y[81.5, 88.5] |
| CINEMATIC_259 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F13 | high | 0x8E30, 2 paths, same 7.0x7.0 box as F12 with a 2.0x3.0 salmon speck back inside it |
| CINEMATIC_260 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F14 | high | 0x8E3E, 1 path, 2.0x3.0 at x[166.0, 168.0] y[82.5, 85.5]: the point the whole run converges on |
| CINEMATIC_LESTER_SEATED_AT_HOLO_CONSOLE_F1_AMIGA_EXTRA | CINEMATIC_LESTER_SEATED_AT_HOLO_CONSOLE_F1 | high | 0xFB26, `b07528b7eb2e`: a seated figure from behind, one arm raised to the head, between `_F0`'s arm-out and `_F2`'s arms-down. `gba_2004` gives this exact art this exact name. The suffix was a collision record (`notes/amiga-extra-suffix/`), and the collision went the wrong way |

## What these names do not claim

`PULSE` and `ACCELERATOR_TUNNEL` are both the repo's own words, from
`ACCELERATOR_TUNNEL_PULSE_SHRINKS_TO_POINT` (dos) and
`INTRO_COMPOSE_PAGE3_THEN_RECEDE_DOWN_ACCELERATOR_TUNNEL` (amiga). Nothing
here claims what the pulse *is* -- whether a particle, a discharge or a beam.
It is a salmon-and-cream core inside a black rim that breaks into spokes and
shrinks onto the tunnel's vanishing point, and that is all the name says.

`RECEDE` is deliberately not reused. `CINEMATIC_ACCELERATOR_TUNNEL_RECEDE_F0..F6`
already exists, is drawn by the next routine at palette 0x15, and is a
different set of pictures: black shards around **cyan and white** cores that
open out into a ring. Whether `RECEDE` describes those is not settled here --
see `notes/HANDOFF.md`.

`VIEW_NEAR` keeps whatever `VIEW_FAR` meant when the pair was coined; this
only moves it onto the polygon the other branches already agree it names.
