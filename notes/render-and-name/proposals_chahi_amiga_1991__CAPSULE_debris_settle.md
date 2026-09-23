# CAPSULE: four frames of debris settling, after the rain stops

`notes/bank-locality/offset_runs.py` puts these four at the head of CAPSULE's
longest contiguous run of still-numbered constants, `0xA8E6..0xAC82`. The
routine draws them at `x=160, y=100` -- the full-screen anchor -- one per frame,
immediately after `CINEMATIC_CAPSULE_FALLING_MASS_LANDED_F3` and
`CINEMATIC_CAPSULE_DEBRIS_RAIN_F5`:

```
  video CAPSULE_FALLING_MASS_LANDED_F3 / CAPSULE_DEBRIS_RAIN_F5
  video 073, x=144, y=127   video 074, x=160, y=100
  video 073, x=143, y=127   video 075, x=160, y=100
  video 073, x=142, y=127   video 076, x=160, y=100
  video 073, x=142, y=127   video 077, x=160, y=100
```

Rendered at palette 1 and cropped to their own extents, each is a **scatter of
small marks strung along one horizontal band**, and the four thin out
monotonically in both measures at once:

```
  074  123.5x21.5  28 leaf
  075  119.5x22.5  18 leaf
  076  100.5x19.0  12 leaf
  077   11.5x2.0    3 leaf
```

28 pieces down to 3, and 123.5 pixels of spread down to 11.5. Nothing else in
the run behaves like that, and it is what the tail of a fall looks like once the
rain has stopped: the last pieces coming to rest.

`DEBRIS` is the stage's own word -- `CINEMATIC_CAPSULE_DEBRIS_RAIN_F0..F5` plays
immediately before these -- so this is the same debris settling.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_074 | CINEMATIC_CAPSULE_DEBRIS_SETTLE_F0 | medium | 0xA8E6, 123.5x21.5 in **28** leaves, the widest and busiest; drawn the frame after `DEBRIS_RAIN_F5` |
| CINEMATIC_075 | CINEMATIC_CAPSULE_DEBRIS_SETTLE_F1 | medium | 0xA912, 119.5x22.5 in 18 leaves |
| CINEMATIC_076 | CINEMATIC_CAPSULE_DEBRIS_SETTLE_F2 | medium | 0xA92E, 100.5x19.0 in 12 leaves |
| CINEMATIC_077 | CINEMATIC_CAPSULE_DEBRIS_SETTLE_F3 | medium | 0xA942, **11.5x2.0 in 3 leaves** -- what is left at the end |

## The rest of the run, left numbered

`073, 078, 079, 080, 081, 082, 083, 119` are the other half of the same routine:
a round mass about 33x34 drawn at `x=141..144, y=127`, with a small figure at
its upper right in the first five and none in the last three, and a blue region
that changes size across them. 083 and 119 are drawn by two `HANG_DRAW_CIN_*`
loops on separate channels, so they alternate forever once the sequence ends.

Composited into the scene they are legible as a shape and not as a thing: the
blue shrinks through 073 to 081 and then the disc is entirely blue in 083, which
no single reading of "water", "hatch" or "boulder" accounts for. Palette 1 is a
`PRECEDING` guess from `palette_in_force.py`, not a control-flow fact, and that
is the first thing to settle before this run is worth a name.
