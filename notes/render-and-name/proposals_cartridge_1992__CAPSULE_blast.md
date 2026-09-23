# CAPSULE (cartridge): the charge blast

Argument in `correction_capsule_6a_layer0.md`. Cartridge art is unrenderable
and its ROM is not extracted (#0106), so no drawing was compared: the claim is
the slot, and cartridge's routines hold it in exactly the same two places.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_259 | CINEMATIC_CAPSULE_CHARGE_BLAST | medium | 0x3536. Drawn at `zoom=0x96` at the end of `cart__post_INLINE_SUB_VAR22_BY_23.inc`'s charge loop and three times at `zoom=0x5a` in the three actor-deletion routines -- the same two situations as amiga and msdos. Art not compared (#0106). Note cartridge's `CINEMATIC_258` is a *different* constant (0x33D6, drawn inside the glow loop) and is left alone |
