# CAPSULE (amiga) — the third tiler

`LABEL_4DDE` completes the LONG/MEDIUM/SHORT trio: it is the 0x70-step arm,
guarded by `jl [0x2C], 0x70, CAPSULE_SHOT_BEAM_TILE_MEDIUM`, drawing the 111 px
tile and stepping `[0x2B]` by 0x70. Its two siblings already carry the
`CAPSULE_SHOT_BEAM_TILE_` stem.

| routine | new name | confidence |
|---|---|---|
| LABEL_4DDE | CAPSULE_SHOT_BEAM_TILE_LONG | high |
