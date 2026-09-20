# Gaps in routine index families

One probe, `routine_family_gaps.py`, and a measurement I had to throw away
once before it meant anything.

NAMING.md §2 forbids a gap in a family's index run, and the validator enforces
it on polygon families. Nothing measured it on **routine** families — and it
bites there, downstream: the sole-named-drawer pass derives constant names
from routine names, and 32 otherwise-good constants were rejected because
their routine family was gapped (`CAPSULE_SHOT_STATE_FRAME_RIGHT_ABOVE_01`,
`_02`, `_04`, no `_03` in the file). A hole in the routine layer stops the
polygon layer.

## The measurement that did not work

Treating every `<base>_<digits>` label as a family gives **130 gapped of
366**, and it is wrong. Most trailing numbers are values:

    PRISON_LIFT_LANDING_IN_VIEW_FROM_2008   a Y coordinate
    CAPSULE_SHOT_BEAM_SPAN_DRAW_FROM_64     a span length
    PRISON_LIFT_SHAFT_STRIP_TILT_UPTO_16    a tilt threshold

`{2008, 2198, 2328, 2648, 2968}` read as a family is five frames with 955
missing. It is five thresholds. **Density** separates them: a frame family
fills most of the range it spans, thresholds fill almost none. At 60 %:

    309  dense index families      73 with an interior gap      57 thresholds

## The 73 are two piles, not one

Many are **spelling splits**. `CAPSULE_HERO_WALK_RIGHT_DRAW` is missing 5, 7
and 13 — and frame 5 exists, as
`CAPSULE_HERO_WALK_RIGHT_FOOTSTEP_PHASE_1`. The frame is present under another
word. That is the problem
`../caller-derived-naming/name_routines_from_art.spelling` already solves for
the gun arms, by pinning a derived name onto an earned sibling's spelling.

Asking that question per gap splits the 73:

    17  the gap slot IS drawn by a named routine
    16  members draw more than one constant each, so the slot cannot be
        located from the art
     5  the slot has art and no named drawer — genuine backlog
     2  no art between the neighbours; the family may simply skip
    33  no neighbour on one side

### The parallel-layer reading was wrong

I first read the 17 as a second series interleaved with the first — two
layers of one animation, the shape of the hero's body-and-arm pairing — and
said so. **The measurement refutes it.** The test that separated body from
arm is co-draw plus a size split; applied here:

    family                                gap  neighbour  gap art   co-drawn
    CAPSULE_SHOT_STATE_FRAME_RIGHT_ABOVE    3  17x12/7    17x17/6      0
    PRISON_SHOT_HIT_BURST_LEFT_ABOVE        3  17x12/7    17x17/6      0
    CAVES_BUDDY_IDLE_HOLD_PHASE            10  54x30/17   54x30/17     0

**17 of 17**: same size class, and *never* drawn together by any routine. A
body and an arm are drawn together and differ in size by an order of
magnitude. These do neither. They are not layers.

### What they actually are — two different things again

`CAPSULE_SHOT_STATE_FRAME_RIGHT_ABOVE_{01,02,04}` and
`CAPSULE_SHOT_IMPACT_SPARK_RIGHT_PHASE_{1,4}` are **one animation under two
naming conventions, neither complete** — five routines for one burst, split
across two spellings with independent index runs. Unifying them means
overriding a name someone earned, which is a heavier step than adding one.

`CAVES_BUDDY_IDLE_HOLD_PHASE` is different again: the routine occupying the
gap at 10 is `..._PHASE_6`, a member of *the same family*. So that family's
index order is not its offset order — which is the assumption the slot test
rests on. For that one the gap is an artefact of the test, not a fact about
the tree.

So the 17 remain unmerged, now for stated reasons rather than a guess, and
the slot test is known to assume something one family violates.
