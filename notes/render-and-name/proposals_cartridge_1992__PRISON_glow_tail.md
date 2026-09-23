# PRISON (cartridge): the same two slots, forced by the shared routine

`prison_var2f_state_machine.inc` has no `.if BRANCH` at these draws, so the
rename reaches cartridge and `cart__entry.inc` must follow it. Cartridge art
is unrenderable (#0106): the claim is the slot in the shared loop, not the
drawing. See `proposals_cartridge_1992__PRISON_widget.md`.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_385 | CINEMATIC_PRISON_CHARGE_GLOW_F2 | medium | drawn in the same slot of the shared `PRISON_INLINE_SUB_VAR22_BY_23_L6` loop as amiga's `CINEMATIC_385`. Art not compared (#0106) |
| CINEMATIC_386 | CINEMATIC_PRISON_CHARGE_GLOW_F3 | medium | drawn in the same slot of the shared `PRISON_INLINE_SUB_VAR22_BY_23_L6` loop as amiga's `CINEMATIC_386`. Art not compared (#0106) |
