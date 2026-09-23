# INTRO (msdos): the same lift interior

Argument and measurements in `proposals_chahi_amiga_1991__INTRO_lift_interior.md`.
msdos holds all five at the **same offsets** and draws them at the same five
positions. Note the index shift: msdos's `CINEMATIC_531` is amiga's `530`,
and msdos's `532` is amiga's `531` -- #0107 with a one-step offset.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_529 | CINEMATIC_LIFT_INTERIOR | high | 0x22BC, `1974e5c54f8b` -- identical to amiga's `CINEMATIC_528` |
| CINEMATIC_531 | CINEMATIC_LIFT_DOORWAY_PANEL_LIT | medium | 0x23EC, drawn at `x=287, y=118` exactly as amiga draws its `CINEMATIC_530`. The pair shares one hash, so the match is the offset and the draw order |
| CINEMATIC_532 | CINEMATIC_LIFT_DOORWAY_PANEL_SHADE | medium | 0x2542, drawn at `x=287, y=101`, the second of the pair |
| CINEMATIC_533 | CINEMATIC_LIFT_DOORWAY_SEAM | high | 0x2536, `583e5c75d806` -- identical to amiga's `CINEMATIC_532` |
| CINEMATIC_534 | CINEMATIC_LIFT_SHAFT_LATTICE | medium | 0x2562, `a506a10afdfc` -- identical to amiga's `CINEMATIC_533` |
