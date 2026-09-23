# PRISON (chahi_amiga_1991): the charge blast

Argument, render and draw sites in `correction_capsule_6a_layer0.md`.
PRISON holds the same widget (`proposals_chahi_amiga_1991__PRISON_widget.md`)
and the same terminal draw: `PRISON_INLINE_SUB_VAR22_BY_23_L7`, the target of
every `je [0x09], 0x01` guard in the glow loop, draws it at
`[BUDDY_X], [BUDDY_Y]` at `zoom=0x96`, exactly where CAPSULE's `LABEL_411F`
draws CAPSULE's copy. It is the only draw of this constant in the stage.

`prison_var2f_state_machine.inc` has no `.if BRANCH`, so all three branches
take the row together.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_384 | CINEMATIC_PRISON_CHARGE_BLAST | medium | 0x875A, 26.0x22.0 in 3 leaves, `f5c16106ac46` -- the same drawing as CAPSULE's blast, in the same slot of the same loop |
