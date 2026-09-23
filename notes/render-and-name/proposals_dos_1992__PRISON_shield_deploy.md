# PRISON (msdos): the same four shield phases

Argument in `proposals_chahi_amiga_1991__PRISON_shield_deploy.md`. msdos holds
all four at the same offsets with the same `canonical_md5`, against its own
CAPSULE copies at 0x13FE, 0x13C6, 0x1CDE and 0x1D3A, and
`dos__post_DECREMENT_VAR22.inc` draws them in the same order.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_202 | CINEMATIC_PRISON_SHIELD_DEPLOY_PHASE_0 | high | same offset and `canonical_md5` as amiga's `CINEMATIC_202`, same slot in the same loop |
| CINEMATIC_204 | CINEMATIC_PRISON_SHIELD_DEPLOY_PHASE_1 | high | same offset and `canonical_md5` as amiga's `CINEMATIC_204`, same slot in the same loop |
| CINEMATIC_201 | CINEMATIC_PRISON_SHIELD_DEPLOY_PHASE_2 | high | same offset and `canonical_md5` as amiga's `CINEMATIC_201`, same slot in the same loop |
| CINEMATIC_200 | CINEMATIC_PRISON_SHIELD_DEPLOY_PHASE_3 | high | same offset and `canonical_md5` as amiga's `CINEMATIC_200`, same slot in the same loop |
