# The tilt-zero members of PRISON's cage families

**Found by screen time, not by structure.** `../on-screen-priority/` ranks the
still-numbered art of a stage by how many frames a player actually sees it.
`CINEMATIC_079` and `CINEMATIC_078` sat at 24% of a PRISON run each, and pulling
on them landed two names with no render involved at all.

## What they are

PRISON opens with the hero hanging in a cage that swings when the player shifts
weight. The picture is assembled from three stacked families, each with one
member per tilt step:

    CINEMATIC_PRISON_CAGE_BARS_TILT_*     the cage itself
    CINEMATIC_PRISON_CAGE_HERO_TILT_*     the hero inside it
    CINEMATIC_PRISON_CAGE_CHAIN_TILT_*    the chain above it

The CHAIN family has a `_TILT_ZERO`. BARS and HERO did not — their named
members run `LEFT_LIMIT, MINUS_6..MINUS_1, FROM_07, PLUS_6..PLUS_1`, with the
upright pose missing from both. The two most-seen unnamed constants in the
stage are exactly that hole.

## The evidence, and there is no picture in it

**1. The three-way tilt arm.** The cage-with-hero drawer is a ladder on
`[0x06]`. Its `== 1` and `== -1` arms are already named, and they draw hero then
bars at `x=[0x03], y=[0x04]`:

    PRISON_CAGE_WITH_HERO_TILT_CASE_01:            (dos_1992/PRISON.asm)
        video CINEMATIC_PRISON_CAGE_HERO_TILT_PLUS_1,  x=[0x03], y=[0x04]
        video CINEMATIC_PRISON_CAGE_BARS_TILT_PLUS_1,  x=[0x03], y=[0x04]

    PRISON_CAGE_SWING_POSE_CASE_FFFF:
        video CINEMATIC_PRISON_CAGE_HERO_TILT_MINUS_1, x=[0x03], y=[0x04]
        video CINEMATIC_PRISON_CAGE_BARS_TILT_MINUS_1, x=[0x03], y=[0x04]

The `== 0` arm is `LABEL_7473`, and it is the same shape, same anchor, same
order:

        jne [0x06], 0x00, PRISON_CAGE_WITH_HERO_TILT_CASE_01
        video CINEMATIC_078, x=[0x03], y=[0x04]
        video CINEMATIC_079, x=[0x03], y=[0x04]

So 078 is the hero member and 079 the bars member of the `[0x06] == 0` step.

**2. A second ladder, whose own routine names say which is which.** msdos and
cartridge carry a bars-only drawer as well, and its already-earned labels name
the family outright:

        jne [0x06], 0x00, PRISON_DRAW_CAGE_BARS_TILT_PLUS_1_ELSE_MINUS_1
        video CINEMATIC_079, x=[0x03], y=[0x04]

`CINEMATIC_079` is the tilt-zero arm of a ladder someone else already labelled
BARS. This is independent of point 1 — a different routine, reached from a
different caller.

**3. The geometry agrees, and is the weakest of the three.** Leaf counts match
the family exactly, and extents match to within a pixel:

    CINEMATIC_078  0x1ADE  23.5 x 49.5  11 leaves    HERO_TILT_MINUS_1  0x1C2E  23.5 x 49.5  11 leaves
    CINEMATIC_079  0x0EDA  57.0 x 55.5  18 leaves    BARS_TILT_MINUS_1  0x132A  56.0 x 55.5  18 leaves

Equal leaf count is how a family member is *found*, not a property every member
must have (`../mirror-families/README.md` records why). It is quoted here as
corroboration of a conclusion points 1 and 2 already carry.

## The spelling

`_TILT_ZERO`, because the sibling CHAIN family already spells that same
`[0x06] == 0` arm `CINEMATIC_PRISON_CAGE_CHAIN_TILT_ZERO`. Not `_TILT_0`, which
would make one of the three families disagree with the other two.

## Ports

amiga and msdos hold both constants at the same offsets (0x1ADE, 0x0EDA);
cartridge holds them at 0x1810 and 0x0CE4 with the identical `[0x06] == 0` arm
at `LABEL_7576`. The cartridge rows rest on control flow only, as they must
(#0106: its ROM is not extracted, so nothing there can be measured).

## What was NOT named

`CINEMATIC_035` (0x23B4, 27.5 x 34.5, 10 leaves) is the highest-ranked unnamed
constant in the whole stage -- on screen for **284** of 400 frames, nearly three
times longer than anything in PRISON that has a name. It is drawn once per
iteration of the swing loop at `x=[0x1a], y=[0x1b]`, the tilt-shifted anchor, by
`LABEL_795A`, before both the chain and the cage. That makes it a tilt-invariant
part of the assembly, and no more than that: nothing here says *which* part, so
it is left numbered. It is the best-value single target left in PRISON and it
wants a render.
