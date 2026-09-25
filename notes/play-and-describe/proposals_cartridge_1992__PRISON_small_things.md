# PRISON (cartridge): the glint, carried because the chunk is shared

Only one row. `CINEMATIC_186`'s draw sites live in
`src/levels/_unified/prison/prison_inline_setters_and_init.inc`, a **shared**
chunk that `cartridge_1992` reads as well, so renaming it for the two priority
ports left cartridge referencing a name it did not define --
`undefined_symbols.py` caught it and `make test` failed at verify-unified.

Cartridge holds the constant at the **same offset**, 0x0068, and draws it at the
same literals, so the row carries by construction rather than by judgement.

Cartridge's ROM is not extracted (#0106), so no extent was measured there. It
does not need to be: the name is earned on msdos and the identity is the shared
chunk plus the identical offset.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_186 | CINEMATIC_PRISON_PIXEL_GLINT | high | 0x0068, the same offset the two priority ports hold it at, drawn at the same literals (101,158) (103,156) (105,154) from the shared chunk prison_inline_setters_and_init.inc. Named on msdos as a one-pixel mark -- 0.0x1.0, one leaf -- scattered across seven positions forming no run. Carried here because the chunk is shared, not because the art was measured (#0106) |
