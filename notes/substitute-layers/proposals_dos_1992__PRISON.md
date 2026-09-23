# The teleport beams in PRISON -- dos_1992

The teleport beams, both facings. `PRISON_TELEPORT_UP_POSE_BY_FACING` picks
between two pictures on `[0x04] & 0x0010`, and the signed bounding boxes show
they are a mirror pair: the left one spans x -4.0..+1.5 and the right one
-1.5..+5.0, reflected about +0.5, with identical y. The DOWN pair mirrors the
same way at y -108.0..-27.5.

The left-facing pictures were already named, inconsistently -- UP as
`CINEMATIC_TELEPORT_UP_BEAM` with no facing, DOWN as
`CINEMATIC_CAVES_TELEPORT_DOWN_BEAM` in CAVES only and numbered elsewhere.
All four members now carry their facing, so the bare name no longer implies
there is only one.

Every member was matched by `canonical_md5` across three stages and both
priority ports, never by index.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_TELEPORT_UP_BEAM | CINEMATIC_TELEPORT_UP_BEAM_LEFT | high | matched by canonical_md5 to the left-facing arm of the teleport-up pair; its signed bbox is x -4.0..+1.5 (biased left of the draw anchor), the mirror of its partner |
| CINEMATIC_552 | CINEMATIC_TELEPORT_UP_BEAM_RIGHT | high | matched by canonical_md5 to the right-facing arm of the teleport-up pair; its signed bbox is x -1.5..+5.0 (biased right of the draw anchor), the mirror of its partner |
| CINEMATIC_551 | CINEMATIC_TELEPORT_DOWN_BEAM_LEFT | high | matched by canonical_md5 to the left-facing arm of the teleport-down pair; its signed bbox is x -4.0..+1.5 (biased left of the draw anchor), the mirror of its partner |
| CINEMATIC_550 | CINEMATIC_TELEPORT_DOWN_BEAM_RIGHT | high | matched by canonical_md5 to the right-facing arm of the teleport-down pair; its signed bbox is x -1.5..+5.0 (biased right of the draw anchor), the mirror of its partner |
