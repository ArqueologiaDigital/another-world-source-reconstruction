# Correction: the ten CAPSULE names that picked a winner

`proposals_chahi_amiga_1991__CAPSULE_buddy.md` named ten constants
`CINEMATIC_BUDDY_*` because they are drawn at `x=[BUDDY_X], y=[BUDDY_Y]`, and
said in its own "does not claim" section that `BUDDY` "is not a reading at all
-- it is the anchor these ten are drawn at". That was wrong, and
`notes/actor-anchors/` measures why: in the same stage
`CINEMATIC_BUDDY_SMASHING_WINDOW_F0` is drawn at `[HERO_X]`, and nine
`DRAW_HERO_POSE_*` routines draw at `[BUDDY_X]`. 20 such conflicts across the
two priority ports.

The anchor is good evidence that pictures belong to the **same** actor. It is
not evidence of **which**, and every other figure name in the stage uses the
neutral word `FIGURE` rather than answer it.

Nothing about the pictures changes -- the four-path segment bar, the two flat
lenses 8.0x3.0 then 28.0x3.0, and the four two-path hexagons around a white
core are all as measured. Only the actor word goes.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_BUDDY_SEGMENT_BAR_F0 | CINEMATIC_CAPSULE_SEGMENT_BAR_F0 | high | correction; the anchor does not name an actor (`notes/actor-anchors/`) |
| CINEMATIC_BUDDY_SEGMENT_BAR_F1 | CINEMATIC_CAPSULE_SEGMENT_BAR_F1 | high | correction |
| CINEMATIC_BUDDY_SEGMENT_BAR_F2 | CINEMATIC_CAPSULE_SEGMENT_BAR_F2 | high | correction |
| CINEMATIC_BUDDY_SEGMENT_BAR_F3 | CINEMATIC_CAPSULE_SEGMENT_BAR_F3 | high | correction |
| CINEMATIC_BUDDY_DISCHARGE_FLASH_F0 | CINEMATIC_CAPSULE_DISCHARGE_FLASH_F0 | high | correction |
| CINEMATIC_BUDDY_DISCHARGE_FLASH_F1 | CINEMATIC_CAPSULE_DISCHARGE_FLASH_F1 | high | correction |
| CINEMATIC_BUDDY_CHARGE_GLOW_F0 | CINEMATIC_CAPSULE_CHARGE_GLOW_F0 | high | correction |
| CINEMATIC_BUDDY_CHARGE_GLOW_F1 | CINEMATIC_CAPSULE_CHARGE_GLOW_F1 | high | correction |
| CINEMATIC_BUDDY_CHARGE_GLOW_F2 | CINEMATIC_CAPSULE_CHARGE_GLOW_F2 | high | correction |
| CINEMATIC_BUDDY_CHARGE_GLOW_F3 | CINEMATIC_CAPSULE_CHARGE_GLOW_F3 | high | correction |
