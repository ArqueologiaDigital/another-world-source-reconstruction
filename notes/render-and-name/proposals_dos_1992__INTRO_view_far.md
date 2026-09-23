# INTRO (msdos): `ACCELERATOR_TUNNEL_VIEW_FAR` is on a debris field, and the view is next door

This is the second half of the pair. `..._VIEW_NEAR` was found on a frame of
the pulse run and moved to the tunnel at 0x3052, where cartridge and gba
already had it. `..._VIEW_FAR` has gone wrong the same way, in the same two
branches, and the same third branch has it right.

## The hashes

```
  0x2BF2   8e7eeac946be   amiga CINEMATIC_378      msdos CINEMATIC_379
                          cartridge & gba CINEMATIC_ACCELERATOR_TUNNEL_VIEW_FAR
  0xCB2E   607639c52ec8   amiga CINEMATIC_ACCELERATOR_TUNNEL_VIEW_FAR
  0xCB2E   607639c52ec8   msdos CINEMATIC_ACCELERATOR_TUNNEL_VIEW_FAR
                          cartridge & gba CINEMATIC_380
```

Two pictures, one name, split across four branches -- #0118 exactly.

## Which one is the view

Rendered at palette 0x16, the palette the beat that uses them runs at:

```
  0x2BF2  302.0x207.0   65 paths   x[ 15.5, 317.5] y[ -7.0, 200.0]
  0xCB2E  191.5x101.0   72 paths   x[103.5, 295.0] y[ 94.5, 195.5]
  0xCBCC  241.5x184.5   93 paths   x[ 14.5, 256.0] y[ -7.0, 177.5]   (..._DEBRIS)
```

**0x2BF2 is the tunnel**: concentric rings receding to a vanishing point, with
a dark mass across the lower half. It is what the far pulse run composites
over, and it is the only one of the three that is a view of anything.

**0xCB2E is not.** 72 paths of tiny scattered specks confined to the lower half
of the frame -- the same kind of picture as `..._TUNNEL_DEBRIS` at 0xCBCC, 93
paths of specks across nearly the whole frame. Two debris layers, and one of
them wearing the view's name.

`INTRO_TRANSITION_TO_LAKE_SETUP` draws all three in that order: the view, then
the lower specks, then the rest of them.

## Proposals

This is a chained rename -- 378 takes the name `..._VIEW_FAR` releases -- so it
is one batch and one file per branch, and it is not idempotent.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_ACCELERATOR_TUNNEL_VIEW_FAR | CINEMATIC_ACCELERATOR_TUNNEL_DEBRIS_LOWER | high | 0xCB2E, `607639c52ec8`: **72 paths** of scattered specks confined to y[94.5, 195.5], the lower half. Distinguished from `..._TUNNEL_DEBRIS` (0xCBCC, 93 paths, y[-7.0, 177.5]) by the band it occupies, and drawn immediately before it |
| CINEMATIC_379 | CINEMATIC_ACCELERATOR_TUNNEL_VIEW_FAR | high | 0x2BF2, `8e7eeac946be`: concentric rings receding to a vanishing point, 65 paths across 302.0x207.0. `cartridge_1992` and `gba_2004` already give this exact art this exact name, and it is the backdrop the far pulse run plays over |

## What this does not claim

`_LOWER` distinguishes the two debris layers by the band each occupies and
nothing else; it does not claim one is nearer the camera.

Nothing here revisits what `FAR` means relative to `NEAR` -- that pair was
coined elsewhere. This only puts the name on the picture the other two
branches already agree it belongs to.
