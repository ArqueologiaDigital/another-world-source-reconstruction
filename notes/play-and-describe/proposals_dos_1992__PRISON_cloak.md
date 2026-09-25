# PRISON: the layer called an arm is below where an arm reaches

`ann:625b42e22a04` on `CINEMATIC_PRISON_STANDING_FIGURE_ARM_F1` (f138): "this
seems to be the cloak while being held by the guard while storing it".

This overturns an earned name, so the grounds are set out in full. **It is not
overturned by the sentence** -- `#0120` forbids picking between two readings --
but by a measurement the original derivation did not take.

## What the name rests on now

`notes/render-and-name/proposals_chahi_amiga_1991__PRISON*.md`:

> `CINEMATIC_615` -> `..._STANDING_FIGURE_ARM_F0` | high | 17.0x25.0, **one
> path**, at the figure's screen-left side. Drawn first of its pair, so it sits
> behind the torso. The five narrow from 17.0 wide and swung out to 6.0 and
> hanging straight

Every geometric fact there re-measures correctly. The word ARM is the part that
was read off a render.

## The measurement that contradicts it

    CINEMATIC_PRISON_STANDING_FIGURE_F0      33.0 x 59.0  13 leaves  y[-58.0, +1.0]
    CINEMATIC_PRISON_STANDING_FIGURE_ARM_F0  17.0 x 25.0   1 leaf    y[-25.5, -0.5]

The figure stands 59 tall with its feet at y = +1. The layer spans
y[-25.5, -0.5] -- **from mid-thigh to the feet**, the lowest 43% of the figure.
A shoulder on a 59-tall figure sits near y = -45 and a hanging hand near y = -25.
**This layer begins where a hand ends and continues to the ground.** Whatever it
is, an arm cannot be it, and no render was needed to say so.

## What the scene puts there instead

The tree already names the cloak, and the transition is in the listing
(PRISON.asm:8846-8866):

    video CINEMATIC_PRISON_CLOAKED_FIGURE_F18   <- the last of a 19-frame family
    video CINEMATIC_342                          <- the uncloaked body
    video ..._STANDING_FIGURE_ARM_F0 + ..._STANDING_FIGURE_F0
    video ..._STANDING_FIGURE_ARM_F1 + ..._STANDING_FIGURE_F1
    ... F2, F3, F4, then the body alone reversing F3 F2 F1 F2 F3 F3 F1 F0 F0

and the two silhouettes differ the way a cloak coming off should:

    CLOAKED_FIGURE_F18   25.5 x 51.0   4 leaves   y[-51.5, -0.5]
    STANDING_FIGURE_F0   33.0 x 59.0  13 leaves   y[-58.0, +1.0]

The cloaked figure is shorter, narrower and far simpler -- a drape over a shape.
The uncloaked one is taller, wider and thirteen leaves of detail. So the scene is
a figure leaving a 19-frame cloaked family, standing revealed, with a
**one-polygon** layer at its side for five frames, narrowing 17.0 -> 13.0 -> 12.0
-> 7.0 -> 6.0 and rising off the floor as its bottom edge goes -0.5 -> -9.0.

One polygon, held at the side, gathered upward, in the frames right after a cloak
comes off, reaching the ground where no arm does. The person says it twice, the second time on `CINEMATIC_633`, whose own
annotation stays held for the actor-word question and is therefore quoted below
rather than cited: "as if he's undressing his 'cape' prior to
starting a work shift".

CLOAK is the subject word from the annotation; the stem, the pairing and the
index are unchanged, so the five keep their positions in the family they already
belong to. No actor word is taken.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_PRISON_STANDING_FIGURE_ARM_F0 | CINEMATIC_PRISON_STANDING_FIGURE_CLOAK_F0 | high | 0x5262, ONE leaf, 17.0x25.0 at x[-13.5,3.5] y[-25.5,-0.5] -- the lowest 43% of a figure that stands y[-58.0,+1.0], beginning below where a hanging hand ends, so not an arm; drawn immediately before STANDING_FIGURE_F0 so it lies behind the body, in the frames right after the 19-frame CLOAKED_FIGURE family ends; widest of the five; and the same session's sentence on CINEMATIC_633 -- still held, so quoted here and deliberately not cited -- says "as if he's undressing his 'cape' prior to starting a work shift" |
| CINEMATIC_PRISON_STANDING_FIGURE_ARM_F1 | CINEMATIC_PRISON_STANDING_FIGURE_CLOAK_F1 | high | 0x527A, one leaf, 13.0x28.0 at y[-29.0,-1.0]; second of the five, paired with STANDING_FIGURE_F1; annot:625b42e22a04 frame 138, "this seems to be the cloak while being held by the guard while storing it" |
| CINEMATIC_PRISON_STANDING_FIGURE_ARM_F2 | CINEMATIC_PRISON_STANDING_FIGURE_CLOAK_F2 | high | 0x5292, one leaf, 12.0x27.0 at y[-28.5,-1.5]; third of the five, paired with STANDING_FIGURE_F2 |
| CINEMATIC_PRISON_STANDING_FIGURE_ARM_F3 | CINEMATIC_PRISON_STANDING_FIGURE_CLOAK_F3 | high | 0x52AA, one leaf, 7.0x24.0 at y[-28.0,-4.0]; fourth, paired with STANDING_FIGURE_F3, and the bottom edge has lifted 3.5px off the floor |
| CINEMATIC_PRISON_STANDING_FIGURE_ARM_F4 | CINEMATIC_PRISON_STANDING_FIGURE_CLOAK_F4 | high | 0x52C2, one leaf, 6.0x20.0 at y[-29.0,-9.0] -- narrowest and highest of the five, bottom edge 9px off the floor: gathered up. Last of the run, after which only the body is drawn |
