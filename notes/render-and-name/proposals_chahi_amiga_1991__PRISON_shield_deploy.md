# PRISON: the deploying shield, four phases, from CAPSULE's four

## Two routines that are the same routine

CAPSULE's `amiga__post_SPLIT_VAR09_BITS_INTO_VAR0D.inc` and PRISON's
`amiga__post_DECREMENT_VAR22.inc` hold the same loop, interleaving the shield
phase with `CINEMATIC_ACTOR_CHARGE_GLOW_F0` between every pair:

```
  PRISON                                  CAPSULE
    video 202,        x=[0x21] y=[0x22]     video SHIELD_DEPLOY_PHASE_0, same
    video ACTOR_CHARGE_GLOW_F0, same        video ACTOR_CHARGE_GLOW_F0, same
    video 204,        x=[0x21] y=[0x22]     video SHIELD_DEPLOY_PHASE_1, same
    video ACTOR_CHARGE_GLOW_F0, same        video ACTOR_CHARGE_GLOW_F0, same
    ...loop...                              ...loop...
    video 201,        x=[0x21] y=[HERO_Y]   video SHIELD_DEPLOY_PHASE_2
    video 200,        x=[0x21] y=[HERO_Y]   video SHIELD_DEPLOY_PHASE_3
```

and a second pair of files matches at the file name as well as the anchors:
PRISON's `amiga__post_COPY_VAR11_TO_VARAD.inc` draws 201 twice at
`x=[0x21], y=[0x26]`, CAPSULE's `amiga__post_COPY_VAR11_TO_VARAD.inc` draws
`SHIELD_DEPLOY_PHASE_2` twice at `x=[0x21], y=[0x26]`.

## And the art is the same art

    python3 notes/cross-stage-widget/same_widget.py --port amiga --pairs PRISON:CAPSULE
    python3 notes/cross-stage-widget/same_widget.py --port msdos --pairs PRISON:CAPSULE

```
  202  776e41966be4   5.0x6.0  2 leaf  ==  SHIELD_DEPLOY_PHASE_0
  204  62cda0f4a23e   5.0x6.0  2 leaf  ==  SHIELD_DEPLOY_PHASE_1
  201  df98e6b62f36   7.0x42.0 2 leaf  ==  SHIELD_DEPLOY_PHASE_2
  200  1b5b1470c30f   3.0x68.0 2 leaf  ==  SHIELD_DEPLOY_PHASE_3
```

Both ports, all four, at their own offsets. The phase order is not the
constant order -- 202, 204, 201, 200 -- and the draw order agrees with the art
rather than with the numbering: the two 5x6 sparks first and inside the loop,
then the 42-tall, then the 68-tall, each one drawn once the loop has finished.
Ascending height is ascending phase, which is how CAPSULE's four were read in
the first place.

## The prefix

`CINEMATIC_PRISON_SHIELD_DEPLOY_PHASE_*`, with the stage word, because PRISON
already carries `CINEMATIC_PRISON_SHIELD_DECAY_PHASE_0_CASE_01` and
`..._PHASE_1_CASE_01` -- the same object going the other way, named with the
prefix. CAPSULE's `CINEMATIC_SHIELD_DEPLOY_PHASE_*` keeps its bare form; it is
CAPSULE's symbol in CAPSULE's assembly unit and renaming it is not this
batch's business.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_202 | CINEMATIC_PRISON_SHIELD_DEPLOY_PHASE_0 | high | 0x5D34, 5.0x6.0 in 2 leaves, `776e41966be4` -- the same drawing as `CAPSULE_SHIELD_DEPLOY_PHASE_0`, drawn first in a loop whose CAPSULE twin draws PHASE_0 first, at the same anchor |
| CINEMATIC_204 | CINEMATIC_PRISON_SHIELD_DEPLOY_PHASE_1 | high | 0x5D90, 5.0x6.0 in 2 leaves, `62cda0f4a23e` -- the same drawing as PHASE_1, third draw in the same loop |
| CINEMATIC_201 | CINEMATIC_PRISON_SHIELD_DEPLOY_PHASE_2 | high | 0x4E48, 7.0x42.0 in 2 leaves, `df98e6b62f36` -- the same drawing as PHASE_2, and drawn twice at `x=[0x21], y=[0x26]` by the file of the same name in both stages |
| CINEMATIC_200 | CINEMATIC_PRISON_SHIELD_DEPLOY_PHASE_3 | high | 0x4E80, 3.0x68.0 in 2 leaves, `1b5b1470c30f` -- the same drawing as PHASE_3, the tallest and the last drawn |

## What is left alone

`CINEMATIC_203` is cartridge's, and only cartridge's: `cart__post_DECREMENT_-
VAR22.inc` draws 202, 203, 204, 203 where amiga and msdos draw 202, 204. So
cartridge has a phase the 1991/1992 ports do not, its mapping onto PHASE_0..3
is not the one measured here, and its ROM is not extracted (#0106). Every draw
of 200..204 in this stage is inside a branch-prefixed file, so nothing forces
the cartridge rows and they are not proposed.
