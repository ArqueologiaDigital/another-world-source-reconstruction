# The storm particles: naming what two ports agree on

Ten constants — five frames, in each of the two priority ports.

## How they surfaced

`../sole-named-drawer/nameable_from_drawer.py --animations` lists routines
that draw several constants from **one fixed anchor**, i.e. frames of one
animation rather than props scattered along a path. It found five, and three
of them were already on the rejected list in `../render-attempts/README.md`:
the TANK blast routines re-blit some constants as layers, which the
fixed-anchor test cannot see.

Measured directly — draws against distinct constants inside each routine:

    TANK_ARENA_ATTACK_BLAST_SEQUENCE        22 draws, 13 distinct
                                            CINEMATIC_112 drawn 4x, 107 3x, 115 3x
    TANK_STAGE_EXIT_CAPSULE_LAUNCH_TO_BATHS 12 draws,  6 distinct  (130 drawn 6x)
    TANK_DESTROYED_CUTSCENE_BLAST_ENTRY      8 draws,  6 distinct  (120 drawn 3x)
    STORM_AMBIENT_DRIFT_DRAW_LOOP            5 draws,  5 distinct
    STORM_PARTICLE_TUMBLE_ANIM_LOOP          5 draws,  5 distinct

**A frame is drawn once; a layer is drawn again.** That one count separates
the two clean sequences from the three that would have taken a frame index
they do not have.

## Naming the intersection, again

The two clean routines are the same animation in two ports:
`canonical_md5` over the whole tree matches **frame for frame**, at different
constant numbers — amiga 352..356 against msdos 353..357, the off-by-one this
project has documented before. So the name travels with the art and not the
index.

Their names disagree about the verb: amiga says *ambient drift*, msdos says
*particle tumble*. Both say **storm**. The name takes what both claim and
drops what only one does: `CINEMATIC_STORM_PARTICLE_F00..F04`. The art
corroborates *particle* independently — five specks, 5x8 to 8x8, two leaves
each.

This is the same move as `../animation-players/` made for the prone
transition: where two earned names disagree, name their intersection rather
than pick a winner (#0120).

## The draw slot

`[0x07],[0x09]`. `0x07` is the actor-record X in this file, but the pair that
#0138 bars is `[0x07],[0x08]`; this is `0x07` reused with a different Y for a
particle position. The actor rule does not apply, and the probe's
`actor_slot` matcher — which requires both halves — correctly let it through.

## Verification

`make test` 29/29 and 29/29, `undefined_symbols.py` clean, and the
`--duplicates` audit still reports one name per picture, which is the check
that matters here: the same name now sits on the same art in both ports,
which is what it should do.
