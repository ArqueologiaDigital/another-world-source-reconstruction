# The anchor does not tell you whose picture it is

## The mistake

`x=[BUDDY_X], y=[BUDDY_Y]` looks like proof that a picture is the companion's,
and `x=[HERO_X], y=[HERO_Y]` like proof it is the player character's. That
reasoning was used in this repo to name ten CAPSULE constants
`CINEMATIC_BUDDY_*`, and it is **not safe**. Those ten have since been renamed;
see below.

## What contradicts it

`anchor_identity.py` lists every anchor that is a pair of named variables, the
named constants drawn there, and any name whose own actor word disagrees with
the anchor's:

```
$ python3 notes/actor-anchors/anchor_identity.py --stage CAPSULE
  === chahi/CAPSULE
      x=[HERO_X], y=[HERO_Y]    170 draw(s), 79 named / 35 still numbered
          CONFLICT  CINEMATIC_BUDDY_SMASHING_WINDOW_F0 says BUDDY, anchor says HERO
      x=[BUDDY_X], y=[BUDDY_Y]  153 draw(s), 51 named / 63 still numbered
          CONFLICT  routine DRAW_HERO_POSE_0_1 says HERO, but draws at the BUDDY anchor
          ... eight more DRAW_HERO_POSE_* routines
  20 conflict(s) [both priority ports]
```

So in one stage, a constant that commits to the companion is drawn at the
hero's anchor, and nine routines that commit to the hero draw at the
companion's. Both namings were earned by earlier passes; both cannot be right.

Nothing in the bytecode settles it. The variable numbers are the VM's own
convention -- `HERO_X EQU 0x01`, `BUDDY_X EQU 0x07` -- and a script may drive
any actor through any variable. An anchor is evidence that two pictures belong
to the **same** actor, which is real and useful; it is not evidence of **which**
actor.

## What the tree already does

Every other figure name at either anchor uses the neutral word **FIGURE**:

```
  at [HERO_X]:   CAPSULE_FIGURE_FLUNG_F0..F4, CAPSULE_FIGURE_PROP_UP_F0..F4
  at [BUDDY_X]:  CAPSULE_FIGURE_THROW_F0..F8, CAPSULE_FIGURE_WALK_RIGHT_BODY_F0..F4,
                 CAPSULE_KNEELING_FIGURE_*, CAPSULE_PRONE_FIGURE_*
```

An earlier pass met this question and declined to answer it, which is exactly
what #0120 asks for when two earned names disagree. The ten `BUDDY_*` names
broke that practice on the strength of a variable name, and are now
`CINEMATIC_CAPSULE_{SEGMENT_BAR,DISCHARGE_FLASH,CHARGE_GLOW}_*`.

## The rule

> Group by the anchor -- it reliably says *the same actor* -- but do not put
> that actor's name in the constant. Say `FIGURE`, or scope by stage, and put
> the anchor in the evidence column where it can be checked.

## What would settle it

Which actor variable pair the CAPSULE script drives for the player is decidable
from the bytecode that **writes** `[0x01]`/`[0x07]`, not from the draws: the
pair the input handler updates is the player's. Nothing in `notes/` has traced
that yet, and until it does, neither word belongs in a name.
