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

$ python3 notes/actor-anchors/anchor_identity.py
  72 conflict(s) [all stages, both priority ports]
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

## What settled it: CAVES

An earlier draft of this note said the question would be decided by which pair
the script **writes**, on the theory that the engine maintains the player's.
That was tried and it decides nothing: amiga/PRISON writes `HERO_X` 273 times
and `BUDDY_X` 196, amiga/CAPSULE 289 and 132. Both are script-driven.

**CAVES decides it.** There is no companion in CAVES -- Lester is alone --
and yet:

```
  === chahi/CAVES
      x=[HERO_X], y=[HERO_Y]    298 draw(s), 137 named / 68 still numbered
      x=[BUDDY_X], y=[BUDDY_Y]  194 draw(s),  60 named / 83 still numbered
          CONFLICT  CINEMATIC_CAVES_HERO_COLLAPSE_F0 says HERO, anchor says BUDDY
          ... F1 through F6
```

194 draws at `[0x07]` in a stage with only one character in it, seven of them
named `CAVES_HERO_COLLAPSE_*` by an earlier pass. So `[0x07]` is not "the
companion's position". It is a second coordinate slot a script may use for
anything, including the player.

`HERO_X` and `BUDDY_X` are the VM's conventional names for variable slots.
They are useful and they are not identities, and no constant name should be
built on them.

## A spelling trap in the same place

A stage only spells a variable `HERO_X` if its own file defines that EQU, and
the files do not agree. CAVES defines `HERO_X` and **not** `BUDDY_X`, then
draws 403 times at a raw `[0x07]`; ENDING defines `BUDDY_X` and not `HERO_X`,
then draws 73 times at `[0x01]`. A scan that groups on the spelling reports
those stages as single-actor, which is how the first version of this probe
missed CAVES entirely and nearly produced the opposite conclusion.
`anchor_identity.py` now normalises `0x01/0x02/0x07/0x08` before grouping.

## 2026-09-25: a person who played the game says the PRISON slot holds two

The note above argues from the tree that an anchor does not identify an actor.
A play session has now supplied the other kind of evidence, and it agrees --
from someone who had never read any of this.

Annotating `dos_1992/PRISON` frame by frame, the same person called the figure
drawn at `[BUDDY_X],[BUDDY_Y]`:

| frames | what they called it | constants |
| --- | --- | --- |
| 118 - 2546 | **the main guard** | 633, 342, 240, 241, 168, 169, 162, 231, 228, 227, 629 |
| 3073 - 3136 | **Buddy** | 438, 440, 441, 447 |

with sentences that leave no doubt which they meant -- "full body of the main
guard, standing with his back to the camera right after removing and storing his
cloak" against "buddy's right arm while tapping lester's back/shoulder".

The two sets are drawn from two separate regions of the bytecode:

    guard set   PRISON.asm:8849 - 10045
    Buddy set   PRISON.asm:3631 -  3757

and the changeover falls at the cage collapse, which the same session annotates
at frames 3069-3075 -- the gun knocked away (`..._GUARD_GUN_KNOCKED_F0..F5`),
the debris passing the camera, the wreck at rest, and then "frame of buddy
starting to wake up from the fallen cage" at 3073.

**So `BUDDY_X`/`BUDDY_Y` in PRISON is a slot, and the scene decides who stands
in it.** That is this directory's thesis, stated by a witness instead of a probe.

### What it puts in question

`dos_1992/PRISON.asm` defines **9** `CINEMATIC_PRISON_BUDDY_*` constants and
**98** routine labels containing `BUDDY`. None of them is retracted here --
nothing above shows any particular one is wrong, and this is not the place to
adjudicate. What it does mean is that the actor word in any PRISON name anchored
on `BUDDY_*` needs the scene it is drawn in, not the anchor, and an audit should
start from the two line ranges above.

### Why nothing was renamed from these sentences

The rule in `docs/NAMING.md` is that an actor word the person used enters a name
only where that stage's already-earned names use it at that anchor. Here they
do -- `DRAW_PRISON_BUDDY_POSE_3` draws `CINEMATIC_231`, which the person calls
the guard's head -- so the person and the tree **disagree about the same
constant**. `#0120` says not to pick between earned names, so the eleven guard
constants are held, one verdict each in
`../play-and-describe/verdicts.tsv`, with this section as what would settle them.
