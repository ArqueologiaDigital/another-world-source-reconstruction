# CAVES (cartridge): the wide flash, forced by a shared routine

`caves_inline_setters_and_init.inc` carries no `.if BRANCH` at these draws --
`CAVES_INLINE_SET_VAR01_TO_E_L2` is one shared body -- so naming amiga's and
msdos's four renamed cartridge's references too and left its definitions behind
(`undefined_symbols.py`: 4 undefined in CAVES / cartridge_1992). The same thing
happened at PRISON's charge widget.

Argument in `proposals_chahi_amiga_1991__CAVES_blast_and_flash.md`. Cartridge's
ROM is not extracted (#0106), so no drawing was compared: the claim is the slot
in the shared body, which is identical for every port by construction.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_008 | CINEMATIC_WIDE_FLASH_F0 | medium | 0xADDE, first of the four in the shared `CAVES_INLINE_SET_VAR01_TO_E_L2`, at `x=160, y=[0xe7]`. Art not compared (#0106) |
| CINEMATIC_009 | CINEMATIC_WIDE_FLASH_F1 | medium | 0xAE0C, second, after `setPalette 0x0D` and `play id=0x0052` |
| CINEMATIC_010 | CINEMATIC_WIDE_FLASH_F2 | medium | 0xAE20, third, after `setPalette 0x08` |
| CINEMATIC_011 | CINEMATIC_WIDE_FLASH_F3 | medium | 0xAE40, fourth and last, before `killChannel` |
