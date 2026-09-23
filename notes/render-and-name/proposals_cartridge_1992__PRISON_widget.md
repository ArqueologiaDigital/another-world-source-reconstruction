# PRISON (cartridge): the same slots, forced by a shared routine

Argument and measurements in `proposals_chahi_amiga_1991__PRISON_widget.md`.

**This one is not read off cartridge's art.** `prison_var2f_state_machine.inc`
carries no `.if BRANCH` arm at these draws: the routine is one shared body, so
renaming amiga's and msdos's references renames cartridge's too, and cartridge's
`cart__entry.inc` must define the same names or the stage stops assembling
(`undefined_symbols.py`: 8 undefined in PRISON / cartridge_1992).

What that shared body settles is exactly the slot: cartridge's constant is the
one drawn at that point in that cycle, at its own bank offset. Cartridge art is
unrenderable (#0106), so no drawing was compared -- if a later pass can render
the cartridge bank and finds different art in a slot, the name to fix is this
one, not amiga's.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_361 | CINEMATIC_PRISON_SEGMENT_BAR_F0 | medium | 0x7A68 in cartridge's bank; drawn in the same slot of the shared `PRISON_INLINE_SUB_VAR22_BY_23_L1`/`_L3` body as amiga's `CINEMATIC_361`. Art not compared (#0106) |
| CINEMATIC_362 | CINEMATIC_PRISON_SEGMENT_BAR_F1 | medium | 0x7B1A in cartridge's bank; drawn in the same slot of the shared `PRISON_INLINE_SUB_VAR22_BY_23_L1`/`_L3` body as amiga's `CINEMATIC_362`. Art not compared (#0106) |
| CINEMATIC_363 | CINEMATIC_PRISON_SEGMENT_BAR_F2 | medium | 0x7B30 in cartridge's bank; drawn in the same slot of the shared `PRISON_INLINE_SUB_VAR22_BY_23_L1`/`_L3` body as amiga's `CINEMATIC_363`. Art not compared (#0106) |
| CINEMATIC_364 | CINEMATIC_PRISON_SEGMENT_BAR_F3 | medium | 0x7B48 in cartridge's bank; drawn in the same slot of the shared `PRISON_INLINE_SUB_VAR22_BY_23_L1`/`_L3` body as amiga's `CINEMATIC_364`. Art not compared (#0106) |
| CINEMATIC_380 | CINEMATIC_PRISON_DISCHARGE_FLASH_F0 | medium | 0x7A96 in cartridge's bank; drawn in the same slot of the shared `PRISON_INLINE_SUB_VAR22_BY_23_L1`/`_L3` body as amiga's `CINEMATIC_380`. Art not compared (#0106) |
| CINEMATIC_381 | CINEMATIC_PRISON_DISCHARGE_FLASH_F1 | medium | 0x7AEE in cartridge's bank; drawn in the same slot of the shared `PRISON_INLINE_SUB_VAR22_BY_23_L1`/`_L3` body as amiga's `CINEMATIC_381`. Art not compared (#0106) |
| CINEMATIC_382 | CINEMATIC_PRISON_CHARGE_GLOW_F0 | medium | 0x7AC2 in cartridge's bank; drawn in the same slot of the shared `PRISON_INLINE_SUB_VAR22_BY_23_L1`/`_L3` body as amiga's `CINEMATIC_382`. Art not compared (#0106) |
| CINEMATIC_383 | CINEMATIC_PRISON_CHARGE_GLOW_F1 | medium | 0x7BA8 in cartridge's bank; drawn in the same slot of the shared `PRISON_INLINE_SUB_VAR22_BY_23_L1`/`_L3` body as amiga's `CINEMATIC_383`. Art not compared (#0106) |
