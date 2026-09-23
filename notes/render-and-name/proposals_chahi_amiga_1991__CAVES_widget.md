# CAVES: the third copy of the charge widget

CAVES holds the same widget PRISON and CAPSULE do, in its own bank, played by
`CAVES_INCREMENT_VAR21_BY_F_L1` at `x=[0x07], y=[0x08]` -- the same anchor pair
the other two use, which CAVES reaches raw because it defines no `BUDDY_*`
(`../actor-anchors/`).

The routine is the same routine, slot for slot:

```
  bar cycle    076 077 078 079 078   then loop  077 078 079 076
  flash        130 131
  glow         132 133 132           then loop  135 136 133 133 136 135
  blast        134  at zoom=0x96
```

against CAPSULE's `LABEL_4038` / `LABEL_4098` / `LABEL_411F` and PRISON's
`PRISON_INLINE_SUB_VAR22_BY_23_L1` / `_L5` / `_L7`, which play their own
constants in exactly those positions.

## Every one of the eleven is the same drawing as CAPSULE's

    python3 notes/cross-stage-widget/same_widget.py --port amiga --pairs CAVES:CAPSULE
    python3 notes/cross-stage-widget/same_widget.py --port amiga --show CAVES:CINEMATIC_076,...

```
  076  e9becc375d3d   4.0x3.0  4 leaf  ==  CAPSULE_SEGMENT_BAR_F0
  077  7b2153dabea2   4.0x3.0  4 leaf  ==  CAPSULE_SEGMENT_BAR_F1
  078  9036ef793af3   4.0x3.0  4 leaf  ==  CAPSULE_SEGMENT_BAR_F2
  079  dc38687a8d05   4.0x3.0  4 leaf  ==  CAPSULE_SEGMENT_BAR_F3
  130  109ffa65fd9c   8.0x3.0  2 leaf  ==  CAPSULE_DISCHARGE_FLASH_F0
  131  7668429ade26  28.0x3.0  2 leaf  ==  CAPSULE_DISCHARGE_FLASH_F1
  132  7f2494dbe630   8.0x6.0  2 leaf  ==  CAPSULE_CHARGE_GLOW_F0
  133  febfeac8ef14   7.0x6.0  2 leaf  ==  CAPSULE_CHARGE_GLOW_F1
  135  11b3b1ff13b9   7.0x6.0  2 leaf  ==  CAPSULE_CHARGE_GLOW_F2
  136  49433443f716   8.0x6.0  2 leaf  ==  CAPSULE_CHARGE_GLOW_F3
  134  f5c16106ac46  26.0x22.0 3 leaf  ==  CAPSULE_CHARGE_BLAST
```

Eleven of eleven, where PRISON's copy matched on eight and redrew three bar
frames. So CAVES and CAPSULE share the widget outright; the bar's lit segments
are not stage-specific here. msdos holds the same eleven under the same
constant numbers at its own offsets, with the same hashes.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_076 | CINEMATIC_CAVES_SEGMENT_BAR_F0 | high | 0x3876, `e9becc375d3d` -- the same drawing as `CAPSULE_SEGMENT_BAR_F0`, and played last in the bar cycle exactly as CAPSULE's F0 is |
| CINEMATIC_077 | CINEMATIC_CAVES_SEGMENT_BAR_F1 | high | 0x3928, `7b2153dabea2` == `CAPSULE_SEGMENT_BAR_F1`, first in the cycle |
| CINEMATIC_078 | CINEMATIC_CAVES_SEGMENT_BAR_F2 | high | 0x393E, `9036ef793af3` == `CAPSULE_SEGMENT_BAR_F2`, second in the cycle |
| CINEMATIC_079 | CINEMATIC_CAVES_SEGMENT_BAR_F3 | high | 0x3956, `dc38687a8d05` == `CAPSULE_SEGMENT_BAR_F3`, third in the cycle |
| CINEMATIC_130 | CINEMATIC_CAVES_DISCHARGE_FLASH_F0 | high | 0x38A4, 8.0x3.0, `109ffa65fd9c` == `CAPSULE_DISCHARGE_FLASH_F0`, first of the two-frame flash |
| CINEMATIC_131 | CINEMATIC_CAVES_DISCHARGE_FLASH_F1 | high | 0x38FC, **28.0x3.0**, `7668429ade26` == `CAPSULE_DISCHARGE_FLASH_F1` |
| CINEMATIC_132 | CINEMATIC_CAVES_CHARGE_GLOW_F0 | high | 0x38D0, `7f2494dbe630` == `CAPSULE_CHARGE_GLOW_F0`, drawn twice in the run as CAPSULE's is |
| CINEMATIC_133 | CINEMATIC_CAVES_CHARGE_GLOW_F1 | high | 0x39B6, `febfeac8ef14` == `CAPSULE_CHARGE_GLOW_F1`, and drawn twice in the inner loop where CAPSULE draws F1 twice |
| CINEMATIC_135 | CINEMATIC_CAVES_CHARGE_GLOW_F2 | high | 0x396E, `11b3b1ff13b9` == `CAPSULE_CHARGE_GLOW_F2`, first and last of the inner loop as CAPSULE's F2 is |
| CINEMATIC_136 | CINEMATIC_CAVES_CHARGE_GLOW_F3 | high | 0x399A, `49433443f716` == `CAPSULE_CHARGE_GLOW_F3` |
| CINEMATIC_134 | CINEMATIC_CAVES_CHARGE_BLAST | high | 0x3B16, 26.0x22.0 in 3 leaves, `f5c16106ac46` == `CAPSULE_CHARGE_BLAST`, drawn at `zoom=0x96` where the cycle ends, the same slot in all three stages |
