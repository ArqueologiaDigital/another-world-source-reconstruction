# PRISON (amiga) — two trampolines whose names carry a raw address

A one-line `jmp X` routine has no body to name it from, but it does have a
target, and where that target is uniquely named the trampoline can take its
name. Worth doing here because the current names end in a raw address, which
NAMING.md §1 forbids outright and which `resync_address_labels.py` cannot keep
honest — it only tracks the `LABEL_<hex>` and `JUNK__<hex>` forms, so
`JUMP_TO_LABEL_4161` is a claim about an address that nothing checks.

PRISON's other three trampolines (`TRAMP_8290`, `TRAMP_82FD`, `TRAMP_848D`) all
jump to `PRISON_REPAINT_BACKDROP_IF_SCREEN_CHANGED`, so this form would give
three labels one name — forbidden by #0118. They need distinguishing by caller
and are left alone.

| routine | new name | confidence |
|---|---|---|
| JUMP_TO_LABEL_414F | JUMP_TO_PRISON_SHIELD_SPAWN_SLOT_1 | high |
| JUMP_TO_LABEL_4161 | JUMP_TO_PRISON_SHIELD_SPAWN_SLOT_2 | high |
