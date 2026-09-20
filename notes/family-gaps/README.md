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

The probe does not yet tell the two piles apart. Doing so means asking, per
gap, whether some routine draws the art at that slot under another name —
answerable from `../routine-extent/` — and that is the next step, not a
guess to make now.
