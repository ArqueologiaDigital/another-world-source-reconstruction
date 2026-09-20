# LAKE: the rest of the coordinate group -- the drifting reed

Second and final batch. Evidence from `shooting_scene_geometry.py` (slots),
`composite_at_anchor.py` (the shared-anchor render) and the raw bank bytes.

| constant | proposed name | confidence | evidence |
| CINEMATIC_DECOR_AT_305_155_F7 | CINEMATIC_LAKE_REED_TIP_SPECK_F0 | high | degenerate 0x1 hairline at (-14,-42.5) from the anchor, inside CINEMATIC_LAKE_REED's box (x-16..4, y-48.5..20.5), near its top. Drawn at [0x32],[0x33], the reed's own multiplexed anchor. |
| CINEMATIC_DECOR_AT_305_155_F8 | CINEMATIC_LAKE_REED_TIP_SPECK_F1 | high | the SAME picture as F0: both are 10-byte records `02 80 80 00 ec 35 72 56 04 ..` differing only in the byte the VM fetches and discards after a colour override. Identical canonical_md5, identical colour 4, same child at 0xD86A. |
| CINEMATIC_DECOR_AT_305_155_F9 | CINEMATIC_LAKE_REED_SWAY_F0 | high | 21.5x47.5/5 stalk with two fronds, drawn over the reed at its anchor. The rest frame: the cycle returns to it between the two excursions. |
| CINEMATIC_DECOR_AT_305_155_F10 | CINEMATIC_LAKE_REED_SWAY_F1 | high | first excursion, frame 1 of 2; played 9,10,11,10,9 then the other way. |
| CINEMATIC_DECOR_AT_305_155_F11 | CINEMATIC_LAKE_REED_SWAY_F2 | high | far point of the first excursion -- the cycle turns around here. |
| CINEMATIC_DECOR_AT_305_155_F12 | CINEMATIC_LAKE_REED_SWAY_F3 | high | second excursion, frame 1 of 2, played after the return through F0. |
| CINEMATIC_DECOR_AT_305_155_F13 | CINEMATIC_LAKE_REED_SWAY_F4 | high | far point of the second excursion; the cycle turns around and loops. |
