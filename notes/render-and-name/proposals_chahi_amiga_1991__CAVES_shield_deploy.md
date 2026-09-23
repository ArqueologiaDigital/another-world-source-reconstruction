# CAVES: the deploying shield, the third copy

The same four phases CAPSULE named and PRISON took next
(`proposals_chahi_amiga_1991__PRISON_shield_deploy.md`). CAVES holds them under
its own numbers, and `amiga__post_COMPUTE_VAR22_AS_VAR40_MINUS_28.inc` deploys
them from each screen edge inward:

```
  video 033, x=5,   y=[0x22]        video 033, x=315, y=[0x22]
  video 035, x=15,  y=[0x22]        video 035, x=303, y=[0x22]
  video 036, x=16,  y=[0x40]        video 036, x=300, y=[0x40]
  video 037, x=17,  y=[0x40]        video 037, x=299, y=[0x40]
```

-- first and furthest out at x=5 on the left and x=315 on the right, then three
steps inward, which is exactly how CAPSULE's `CAPSULE_SHIELD_DEPLOY_AT_*_EDGE`
routines were read when the family was named. `amiga__post_SPLIT_VAR09_BITS_-
INTO_VAR0D.inc` plays 033 then 035 in the loop that CAPSULE's file **of the same
name** plays PHASE_0 then PHASE_1 in, and `amiga__post_COPY_VAR11_TO_VARAD.inc`
draws 036 twice at `x=[0x21], y=[0x26]` where CAPSULE's file of the same name
draws PHASE_2 twice at the same anchor.

The art settles the mapping:

```
  033  776e41966be4   5.0x6.0  2 leaf  ==  SHIELD_DEPLOY_PHASE_0
  035  62cda0f4a23e   5.0x6.0  2 leaf  ==  SHIELD_DEPLOY_PHASE_1
  036  df98e6b62f36   7.0x42.0 2 leaf  ==  SHIELD_DEPLOY_PHASE_2
  037  1b5b1470c30f   3.0x68.0 2 leaf  ==  SHIELD_DEPLOY_PHASE_3
```

Ascending height is ascending phase, and it agrees with the draw order.

## The prefix, and why this one has none

Bare `CINEMATIC_SHIELD_DEPLOY_PHASE_*`, not `CINEMATIC_CAVES_...`, because CAVES
already carries bare `CINEMATIC_SHIELD_DECAY_PHASE_0..3` -- the same object going
the other way -- and its `PHASE_0` and `PHASE_2` are byte-identical to CAPSULE's
constants of those same bare names (`9773bffc8890`, `a4a0ac863c0e`). Two stages
already share this object's vocabulary without a stage word. PRISON is the
exception and keeps its prefix, because PRISON's decay family was named
`CINEMATIC_PRISON_SHIELD_DECAY_PHASE_*`.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_033 | CINEMATIC_SHIELD_DEPLOY_PHASE_0 | high | 0x1FF6, 5.0x6.0 in 2 leaves, `776e41966be4` -- the same drawing as CAPSULE's PHASE_0, drawn first and furthest out (x=5 at the left edge, x=315 at the right) |
| CINEMATIC_035 | CINEMATIC_SHIELD_DEPLOY_PHASE_1 | high | 0x2052, 5.0x6.0, `62cda0f4a23e` == PHASE_1, one step inward (x=15 / x=303) |
| CINEMATIC_036 | CINEMATIC_SHIELD_DEPLOY_PHASE_2 | high | 0x17D4, **7.0x42.0**, `df98e6b62f36` == PHASE_2, and drawn twice at `x=[0x21], y=[0x26]` by the file of the same name in both stages |
| CINEMATIC_037 | CINEMATIC_SHIELD_DEPLOY_PHASE_3 | high | 0x180C, **3.0x68.0**, `1b5b1470c30f` == PHASE_3, the tallest and the last |

## Cartridge is left out

`cart__post_COMPUTE_VAR22_AS_VAR40_MINUS_28.inc` draws **034** at x=10, between
033 and 035, which amiga and msdos do not -- amiga's CAVES does not even define
the constant. So cartridge deploys in five steps, its mapping onto PHASE_0..3 is
not the one measured here, and its ROM is not extracted (#0106). Every draw is
inside a branch-prefixed file, so nothing forces the rows. The same thing
happened at PRISON's `CINEMATIC_203`.
