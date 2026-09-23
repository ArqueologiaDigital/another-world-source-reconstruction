# The death animation has four versions, and only one was named

## The dispatch

PRISON, CAVES and CAPSULE each hold the same four-way choice:

```
  mov [0xF8], [0x04]
  and [0xF8], 0x00FF
  jl  [0xF8], 0x20, <low>
  sub [0xF8], 0x0020
  setup channel=0x14, address=<A>          ; CINEMATIC_HERO_DEATH_F0, F1, F2
  jl  [0xF8], 0x10, SHARED_RET
  setup channel=0x14, address=<B>          ; three numbered
  ret
<low>:
  setup channel=0x14, address=<C>          ; three numbered
  jl  [0xF8], 0x10, SHARED_RET
  setup channel=0x14, address=<D>          ; three numbered
  ret
```

Four routines, each `F0, F1, F2, F1` and then the same blast block
(`CINEMATIC_BLAST_MARK`, `CINEMATIC_BLAST_DEBRIS_F0, F1`, `play id=0x005A`).
One of the four was named `CINEMATIC_HERO_DEATH_F0..F2`; the other nine
constants per stage were left numbered, in every stage and both ports.

## What the four are

Rendered at palette 14 and cropped to each frame's own extent, F0 of each is a
white figure inside a blue flash outline and F1/F2 are the same figure as a
**skeleton**, white then dark. The four differ in exactly two ways:

```
                       F0           F1           F2       posture   facing
  HERO_DEATH_F*     20.0x49.5   18.5x47.0    18.5x47.0    standing   left
  the second        20.0x49.5   22.5x47.0    23.5x47.0    standing   right
  the third         29.5x34.0   24.5x32.0    23.5x32.0    kneeling   right
  the fourth        31.0x34.0   27.5x32.0    27.5x32.0    kneeling   left
```

Two heights, 47-49 against 32-34, and two facings. The standing pair renders as
an exact mirror of each other, and so does the kneeling pair: the outstretched
gun arm is on the left in one and the right in the other.

**The facing has a second witness for the kneeling pair.** The routine that
draws the right-facing one does `sub [HERO_X]` between frames and the
left-facing one does `add [HERO_X]` -- each is driven away from the side it
faces, which is what being shot does. The standing pair does not move, so its
facing rests on the render alone.

## The rename that comes with it

`CINEMATIC_HERO_DEATH_F0..F2` cannot stay undirected once its mirror is named,
so it becomes `CINEMATIC_HERO_DEATH_STANDING_LEFT_F0..F2`. The name has no stage
word in any of the three stages -- the art is byte-identical across all of them
-- and the four new families keep that.

In PRISON the rename must include cartridge: `prison_inline_setters_and_init.inc`
carries no `.if BRANCH` at its reference. In CAVES and CAPSULE every reference is
inside a branch arm.

## The twelve names

    CINEMATIC_HERO_DEATH_STANDING_LEFT_F0..F2     (renamed from HERO_DEATH_F*)
    CINEMATIC_HERO_DEATH_STANDING_RIGHT_F0..F2
    CINEMATIC_HERO_DEATH_KNEELING_RIGHT_F0..F2
    CINEMATIC_HERO_DEATH_KNEELING_LEFT_F0..F2

The per-stage, per-port constant numbers are in the `proposals_*__*_death.md`
tables beside this file. Every row is anchored on `canonical_md5`: the twelve
drawings are byte-identical in PRISON, CAVES and CAPSULE and in both ports, so
the map from picture to name is made once and each table just says which
constant holds it.
