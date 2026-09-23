# INTRO (msdos): the same two halves, at msdos's own indices

Argument, render and measurements in
`proposals_chahi_amiga_1991__INTRO_door_leaves.md`. Both pictures have the
identical `canonical_md5` in the two priority ports, so the measurements carry
across unchanged; only the constant names and offsets differ.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_126 | CINEMATIC_LAB_DOOR_LEAF_UPPER | high | 0x43DE, `1b30ec6e3902` -- identical to amiga's `CINEMATIC_121` at 0x446C. Drawn at `y=[0x01]`, the variable `LAB_DOOR_LEAVES_PARTING_LOOP` decrements |
| CINEMATIC_127 | CINEMATIC_LAB_DOOR_LEAF_LOWER | high | 0x4422, `cc283e630a08` -- identical to amiga's `CINEMATIC_122` at 0x44B0. Drawn at `y=[0x02]`, the variable the same loop increments |
