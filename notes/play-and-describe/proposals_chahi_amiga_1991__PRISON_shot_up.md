# PRISON (amiga): the shot fired upward, and the arm that fires it

`ann:f5afac8bce1c` on `CINEMATIC_629` (f2546): "right arm of the guard point a
gun upwards". `ann:3741a938d032` on `CINEMATIC_630` (f2799): "laser ray when the
gun is shot upwards after lester shakes the cell too much".

## The sequence is one routine, start to finish

`LABEL_2150` (PRISON.asm:4408-4429) is the whole event:

    call LABEL_572C            <- the figure, arm raised
    jl [0x15], 0x1E, ...       <- only once the cage-swing counter passes 30
    setPalette 0x0F            <- the muzzle flash
    play id=0x0052             <- the shot
    video CINEMATIC_630, x=[ACTOR_X], y=110
    setPalette 0x02            <- back to the scene's palette
    video CINEMATIC_631, x=[ACTOR_X], y=80
    video CINEMATIC_630, x=[ACTOR_X], y=65516        <- 65516 is -20 signed
    setup channel=0x11, address=PRISON_BACKGROUND_GUARD_RUN_IN

`[0x15]` is the cage-swing counter the `CINEMATIC_PRISON_CAGE_*_TILT_*` family
also reads, so "after lester shakes the cell too much" is in the bytecode as a
threshold. And the routine ends by installing
`PRISON_BACKGROUND_GUARD_RUN_IN` -- named earlier today from the annotation "a
guard in the background runs to take a look ... after he heard the sounds of
shots". The shot summoning the runner closes that loop from the other side.

## The beams measure as beams

    CINEMATIC_630   0.0 x  62.0   3 leaves   colours 15, 15, 13
    CINEMATIC_631   1.0 x 132.0   4 leaves   colours 15, 15, 15, 13

Zero and one pixel wide against 62 and 132 tall: vertical lines, nothing else.
Their y anchors run 110, 80, then -20, so the beam climbs and leaves the top of
the screen. Colour 15 with 13 beneath is the same pairing the beam-span ladder
uses (`../beam-span-ladder/`), which is corroboration that these are shots and
not, say, a lamp.

The index is first-draw order: 630 is drawn first and again last, 631 between.

## The arm is above the head

`CINEMATIC_629` is 19.5x29.0 in 3 leaves spanning y[-71.0,-42.0], and it is drawn
in `LABEL_572C` **before** the head dispatcher and before
`CV_FIGURE_PROFILE_STRIDE` lays the body. Every member of the head family sits
at y[-60,-48]; this reaches to -71, above all of them. A limb layer that extends
higher than the head is an arm raised over it, which is measured rather than
seen.

No actor word: the person says guard, `../actor-anchors/` records why that is not
admissible from this anchor, and the adversarial pass refuted `GUARD` here on
exactly that ground while confirming every other component.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_629 | CINEMATIC_PRISON_FIGURE_ARM_GUN_UP | high | 0x5356, 19.5x29.0 in 3 leaves at y[-71.0,-42.0] -- above the whole head family's y[-60,-48]; sole draw site PRISON.asm:10045 in LABEL_572C, drawn BEFORE the head dispatcher and before CV_FIGURE_PROFILE_STRIDE lays the body, so it is a limb layer over both; annot:f5afac8bce1c frame 2546, "right arm of the guard point a gun upwards" |
| CINEMATIC_630 | CINEMATIC_PRISON_SHOT_UP_BEAM_F0 | high | 0x539E, 0.0x62.0 in 3 leaves at colours 15,15,13 -- a zero-width vertical line; drawn first in LABEL_2150 at y=110 immediately after `setPalette 0x0F` and `play id=0x0052`, and again at y=-20 as the beam leaves the screen; annot:3741a938d032 frame 2799, "laser ray when the gun is shot upwards after lester shakes the cell too much" -- the shaking is `jl [0x15], 0x1E`, the cage-swing counter passing 30 |
| CINEMATIC_631 | CINEMATIC_PRISON_SHOT_UP_BEAM_F1 | high | 0x53C8, 1.0x132.0 in 4 leaves at colours 15,15,15,13 -- the same vertical line twice as long; drawn between the two 630 draws, at y=80, after the flash palette is restored. No annotation of its own; it is the middle frame of a three-draw climb whose ends are annotated |
