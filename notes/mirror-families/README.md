# The same drawing turned over

## What question this directory answers

`canonical_md5` finds art that is *the same*. It cannot find art that is the
same **reflected**, and a reflection is the commonest thing a stage holds twice:
every walk, every aim, every death has a left and a right, and again and again
one of the two was named and the other left numbered.

A mirrored frame is not the same polygon tree. *Where the artist reflected the
drawing*, it keeps two properties exactly: the **leaf count**, because
reflecting removes no polygon, and the **height**, with the width to within the
half-pixel the renderer's rounding can move.

**Where the artist drew the second facing by hand, it does not**, and this
probe cannot see those at all. amiga's `CAPSULE_FIGURE_POSE_LEFT_0_1` is 4
leaves and its `RIGHT_0_1` is 5; rendered, they are one alien head in profile
facing two ways, drawn twice. So the leaf count is how this finds a mirror, not
a property every mirror has: **precision, not recall**. A family it does not
report may still have a twin.

    python3 notes/mirror-families/mirror_candidates.py
    python3 notes/mirror-families/mirror_candidates.py --port msdos --stage CAPSULE

It reports only where a **run** of consecutive numbered constants matches a run
of one named family's members, because a single size match is a coincidence and
a run of five is not.

## What it is not

Proof. Two figures of the same build measure alike, and the probe proved that
against itself on its first run: it offered `CINEMATIC_314, 315, 316` as
mirrors of `CAVES_CREATURE_WALK_RIGHT_*`, three times 51.0x29.5 in twelve
leaves. They are not mirrors. They are the **same creature standing still**,
drawn by `CAVES_BUDDY_IDLE_HOLD_PHASE_12..14`, and they became
`CINEMATIC_CAVES_CREATURE_IDLE_F1..F3`.

That miss was worth more than a hit. The measurement said "same build", which
was true; only the routine could say whether the second family was the first one
reflected, standing still, or something else of the same size.

> The probe says where to look. The routine says what it is: a mirror family is
> drawn by the other family's routine with its x steps negated.

## What it found

**`CAVES_HERO_ARM_OUT_RIGHT_F0..F6`.** `LABEL_24CF` draws
`..._LEFT_F0` and branches on `[0x63] == 2` to `LABEL_2551`, which is the same
body with every `sub [HERO_X]` an `add [HERO_X]`:

    LEFT   -1  -9  -5  -8  -7  -4  -1        RIGHT   +1  +9  +5  +8  +7  +4  +1

and five of the frames measure exactly alike, leaf for leaf. See
`../render-and-name/proposals_chahi_amiga_1991__CAVES_armout.md`, which also
records the eighth frame the left family had been missing and the fact that its
`F0` is not left-facing at all.

**`PRISON_LIFT_SHAFT_STRIP_LOWER_0..3`**, offered as matching
`..._STRIP_1..3`. Also not a mirror: 60.0 wide in ten leaves at heights 3, 5 and
7 that the named family already has, in a routine that picks a strip by the `y`
it will be drawn at. The four numbered ones are the bands **below** the ones
that reach `STRIP_0`, so they are a second run of the same construction rather
than a reflection of the first.

Two of three first-run candidates turned out not to be mirrors, and all three
turned into names anyway. That is the probe working: it finds *related* art, and
relatedness is what a name needs.

**The four-way death families** and the **beam-span rungs** were found by the
same reasoning before this existed, by hand.
