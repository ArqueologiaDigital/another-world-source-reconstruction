# Find the branch that chooses between a named thing and an unnamed one

| file | question it answers | command |
| --- | --- | --- |
| `alternative_of.py` | Which unnamed pictures sit opposite a named one across a conditional? | `python3 notes/substitute-layers/alternative_of.py` |

## Why this works where rendering does not

The shared bank went from 77 unnamed keys to 57 in two passes, and neither
pass looked at the art to decide. Both found the conditional that picks
between the unknown and something already named:

```
CAPSULE_ACTOR_RUN_RIGHT_DRAW_2:
        video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F02, ...
        je [0x0D], 0x00, LABEL_6A11
        call LABEL_691B                                      <- the unknown
        jmp LABEL_6A16
LABEL_6A11:
        video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_02, ...  <- named
```

Whatever `[0x0D]` means, the two arms draw the same thing in two states. The
unknown is a **variant of the named one** and inherits everything but the
variance — and that survives not knowing what the picture depicts, which is
where every render-based attempt in this project has failed.

Measured over both priority ports: **64** unnamed pictures sit opposite a
named one, 36 with exactly one counterpart and 28 with several. The 28 are
shared variants — a piece that substitutes for eight different frames cannot
take any one of their names — and reporting that count is the point, because
it is what stops the rule overreaching.

## What it does not claim

The pairing says "these two are alternatives", never what the difference is.
`CV_3B44` became `CV_FIGURE_GUN_UPPER_RIGHT_POSE_00` only because a second
line of evidence said what the variance *was*: 6 leaves against its
counterpart's 2, the gun added. This module stops at the pairing.

## The lead it found that closed a loop

`CINEMATIC_478` sits opposite `CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_0` on
`[0x13]` — the shot timer decoded in `../laser-impact-anim/` at the start of
the same session. Following it: the fade is a `jne [0x13], 0x<case>` ladder
over **nine** cases, 0x81..0x89, and the LEFT and RIGHT ladders draw the same
constants, which is why the family carries no direction. Six were named 0..5
and the first three cases had never been named, so the family began three
frames late.

That is precisely what commit `36139804` found and what `9824e569` reverted —
not because the reading was wrong, but because the rename was keyed on amiga's
indices and would have put those names on unrelated msdos art. The constants
differ per port: amiga 480/479/478, msdos 627/626/625, cartridge 636..628.

Redone correctly: all nine verified identical across amiga and msdos case for
case by `canonical_md5`, geometry reading as one blast (widths 2, 10, 19, 28,
36, 36, 35, 28, 30 against heights 64, 68, 63, 61, 52, 47, 34, 22, 7), and
applied branch-scoped to all three branches with the index taken from the case
value — 0x81 is frame 0. 27 renames. Re-reading the ladder afterwards, every
case in every branch maps to `FADE_<case - 0x81>`.

## The fire frames, found by their muzzle

`fire_frames.py` looks for one shape wherever it occurs:

```
video offset=<F0>, ...               <- drawn AT the shot
mov [0x21], [HERO_X]
mov [0x27], [HERO_Y]
sub [0x21], 0x001E                   <- the muzzle, left of the hero
call <spawn the projectile>
break
video offset=<F1>, ...               <- the frame after
```

The **muzzle offset carries the direction** — `sub` puts the shot to the
hero's left, `add` to the right — so the direction is read rather than
guessed from which way a sprite appears to face.

It finds 24 such sites, and **9 of them were already named** before the probe
existed: the `HERO_STAND_SHOOT_*` applied from
`../shared-bank-geometry/stand_shoot.map` and the pre-existing
`HERO_CROUCH_SHOOT_*`. Re-deriving nine correct namings is the control.

The other 15 are per-stage cinematic art rather than bank pieces, and they do
not need their geometry re-read either: each one's `canonical_md5` **equals a
named bank piece**, so the name is read off the match. That also keeps stand
and crouch apart with no height threshold —
`HERO_CROUCH_SHOOT_LEFT_F0` is 44x34 and `HERO_STAND_SHOOT_LEFT_F0` is 40x49,
and the md5 says which without one.

20 applied across the two priority ports: all eight of PRISON's, in both
stand and crouch and both directions, and CAPSULE's left pair. The port shift
shows plainly in that last one — amiga's is `CINEMATIC_116`/`115` and msdos'
is `CINEMATIC_329`/`328`, and msdos' own 116/115 is 40x60 art with nothing to
do with it.

`cartridge_1992`'s five sites are found but not named: it has no extracted
ROM, so the md5 that carries the name cannot be computed, and its constant
numbers are not evidence.
