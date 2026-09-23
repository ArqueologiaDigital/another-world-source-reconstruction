# PRISON (cartridge): the same two rungs, by the array stride

Cartridge's ROM is not extracted (#0106), so nothing was measured. Two facts
carry the rows instead, and both are in the tree: the routine draws these
constants in the same rungs of the same dispatch, and cartridge holds the same
two contiguous arrays -- right rungs at `0x4960 + 0x14k`, left rungs at
`0x7992 + 8k`, six members each, `_0..3` already named at k = 0..3.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_514 | CINEMATIC_PRISON_SHOT_BEAM_SPAN_RIGHT_4 | medium | 0x49B0, member 4 of cartridge's own six-member array, drawn in the same rung of the same dispatch. Art not measured (#0106) |
| CINEMATIC_515 | CINEMATIC_PRISON_SHOT_BEAM_SPAN_LEFT_4 | medium | 0x79B2, member 4 of cartridge's own six-member array, drawn in the same rung of the same dispatch. Art not measured (#0106) |
| CINEMATIC_520 | CINEMATIC_PRISON_SHOT_BEAM_SPAN_RIGHT_5 | medium | 0x49C4, member 5 of cartridge's own six-member array, drawn in the same rung of the same dispatch. Art not measured (#0106) |
| CINEMATIC_521 | CINEMATIC_PRISON_SHOT_BEAM_SPAN_LEFT_5 | medium | 0x79BA, member 5 of cartridge's own six-member array, drawn in the same rung of the same dispatch. Art not measured (#0106) |
