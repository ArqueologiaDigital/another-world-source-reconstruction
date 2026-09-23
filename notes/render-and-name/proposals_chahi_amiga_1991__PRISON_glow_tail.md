# PRISON: the two glow frames the first widget batch stopped short of

The widget batch named PRISON's `SEGMENT_BAR_F0..F3`,
`DISCHARGE_FLASH_F0, F1` and `CHARGE_GLOW_F0, F1`. CAPSULE's copy has **four**
glow frames, and so does PRISON's -- they are in the loop one label further on.

`PRISON_INLINE_SUB_VAR22_BY_23_L6` and CAPSULE's `LABEL_40B6` are line for
line the same body, guard for guard:

```
  PRISON  L6                            CAPSULE  LABEL_40B6
    je [0x09],1 -> L7                     je [0x09],1 -> LABEL_411F
    video 385                             video CAPSULE_CHARGE_GLOW_F2
    video 386                             video CAPSULE_CHARGE_GLOW_F3
    video PRISON_CHARGE_GLOW_F1           video CAPSULE_CHARGE_GLOW_F1
    sub [BUDDY_Y],1; video ..._F1         sub [BUDDY_Y],1; video ..._F1
    video 386                             video CAPSULE_CHARGE_GLOW_F3
    video 385                             video CAPSULE_CHARGE_GLOW_F2
    djnz [0x29], L5                       djnz [0x29], LABEL_4098
```

and the art is identical, which the probe reports both ways round:

    python3 notes/cross-stage-widget/same_widget.py --port amiga --pairs PRISON:CAPSULE
    python3 notes/cross-stage-widget/same_widget.py --port msdos --pairs PRISON:CAPSULE

```
  PRISON 385  0x819E  7.0x6.0  2 leaf  11b3b1ff13b9  ==  CAPSULE_CHARGE_GLOW_F2
  PRISON 386  0x81CA  8.0x6.0  2 leaf  49433443f716  ==  CAPSULE_CHARGE_GLOW_F3
```

Both ports agree: msdos holds 385 and 386 at the same offsets with the same
hashes, against its own CAPSULE copies at 0x3638 and 0x3664.

Two leaves is a weak identity on its own (`../cross-stage-widget/README.md` on
colour-blindness), which is why the routine comparison is the evidence and the
hash is the corroboration rather than the other way round.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_385 | CINEMATIC_PRISON_CHARGE_GLOW_F2 | high | 0x819E, 7.0x6.0 in 2 leaves, `11b3b1ff13b9` -- the same drawing as `CAPSULE_CHARGE_GLOW_F2`, drawn first and last in a loop whose CAPSULE twin draws F2 first and last |
| CINEMATIC_386 | CINEMATIC_PRISON_CHARGE_GLOW_F3 | high | 0x81CA, 8.0x6.0 in 2 leaves, `49433443f716` -- the same drawing as `CAPSULE_CHARGE_GLOW_F3`, in CAPSULE's F3 slot |

This closes the family: PRISON now has `CHARGE_GLOW_F0..F3` with no gap, as
`docs/NAMING.md` §2 requires and as CAPSULE has.
