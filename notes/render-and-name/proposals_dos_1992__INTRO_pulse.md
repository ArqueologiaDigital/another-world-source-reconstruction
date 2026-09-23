# INTRO (msdos): the same fifteen frames, at msdos's own indices

The evidence, the renders and the reasoning are in
`proposals_chahi_amiga_1991__INTRO_pulse.md`. This file carries the same names
to `dos_1992`, where every one of the sixteen polygons has the **identical
`canonical_md5`** as amiga's and a different index -- #0107 in its plainest
form: msdos's numbering runs six ahead, so amiga's `CINEMATIC_250` and msdos's
`CINEMATIC_256` are one picture, while amiga's `CINEMATIC_252` (0x8C04, frame
F6) and msdos's `CINEMATIC_252` (0x87EE, frame F0) are two different ones.

msdos is also where the family word comes from: its routine is called
`ACCELERATOR_TUNNEL_PULSE_SHRINKS_TO_POINT`.

| frame | amiga const / offset | msdos const / offset | canonical_md5 |
|---|---|---|---|
| F0 | CINEMATIC_246 0x887C | CINEMATIC_252 0x87EE | 41ea1c15e4a6 |
| F1 | CINEMATIC_247 0x8890 | CINEMATIC_253 0x8802 | 164cb14d5f6d |
| F2 | ..._HOLO_CONSOLE_F1 0x8958 | ..._HOLO_CONSOLE_F1 0x88CA | 47c2ee5cfacc |
| F3 | ..._TUNNEL_VIEW_NEAR 0x8A24 | ..._TUNNEL_VIEW_NEAR 0x8996 | 9b2f903b9cb1 |
| F4 | CINEMATIC_250 0x8AE0 | CINEMATIC_256 0x8A52 | 4110b1ffab18 |
| F5 | CINEMATIC_251 0x8B90 | CINEMATIC_257 0x8B02 | 9bade8223d66 |
| F6 | CINEMATIC_252 0x8C04 | CINEMATIC_258 0x8B76 | 06c1cf01dd7a |
| F7 | CINEMATIC_253 0x8C68 | CINEMATIC_259 0x8BDA | c1971bc9ed3c |
| F8 | CINEMATIC_254 0x8CD8 | CINEMATIC_260 0x8C4A | b9cfba50634c |
| F9 | CINEMATIC_255 0x8D4A | CINEMATIC_261 0x8CBC | 2104a11d15d4 |
| F10 | CINEMATIC_256 0x8DA0 | CINEMATIC_262 0x8D12 | 1638ddc6fbfa |
| F11 | CINEMATIC_257 0x8DF0 | CINEMATIC_263 0x8D62 | 83d29ca64d2e |
| F12 | CINEMATIC_258 0x8E10 | CINEMATIC_264 0x8D82 | 000946802289 |
| F13 | CINEMATIC_259 0x8E30 | CINEMATIC_265 0x8DA2 | 4946f17187de |
| F14 | CINEMATIC_260 0x8E3E | CINEMATIC_266 0x8DB0 | 3659eca60e4a |
| tunnel | CINEMATIC_243 0x3052 | CINEMATIC_249 0x3052 | 07f2de537d9c |

Sixteen pairs, sixteen distinct hashes, sixteen exact matches.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_249 | CINEMATIC_ACCELERATOR_TUNNEL_VIEW_NEAR | high | 0x3052, `07f2de537d9c` -- identical to amiga's `CINEMATIC_243` and to the art `gba_2004` already calls `..._TUNNEL_VIEW_NEAR` |
| CINEMATIC_252 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F0 | high | 0x87EE, `41ea1c15e4a6` = amiga F0. Note msdos's 252 is not amiga's 252 |
| CINEMATIC_253 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F1 | high | 0x8802, `164cb14d5f6d` = amiga F1 |
| CINEMATIC_LESTER_SEATED_AT_HOLO_CONSOLE_F1 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F2 | high | 0x88CA, `47c2ee5cfacc` = amiga F2. Same wrong name, same single draw site, same slot in the run |
| CINEMATIC_ACCELERATOR_TUNNEL_VIEW_NEAR | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F3 | high | 0x8996, `9b2f903b9cb1` = amiga F3 |
| CINEMATIC_256 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F4 | high | 0x8A52, `4110b1ffab18` = amiga F4 |
| CINEMATIC_257 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F5 | high | 0x8B02, `9bade8223d66` = amiga F5 |
| CINEMATIC_258 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F6 | high | 0x8B76, `06c1cf01dd7a` = amiga F6 |
| CINEMATIC_259 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F7 | high | 0x8BDA, `c1971bc9ed3c` = amiga F7 |
| CINEMATIC_260 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F8 | high | 0x8C4A, `b9cfba50634c` = amiga F8 |
| CINEMATIC_261 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F9 | high | 0x8CBC, `2104a11d15d4` = amiga F9 |
| CINEMATIC_262 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F10 | high | 0x8D12, `1638ddc6fbfa` = amiga F10 |
| CINEMATIC_263 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F11 | high | 0x8D62, `83d29ca64d2e` = amiga F11 |
| CINEMATIC_264 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F12 | high | 0x8D82, `000946802289` = amiga F12 |
| CINEMATIC_265 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F13 | high | 0x8DA2, `4946f17187de` = amiga F13 |
| CINEMATIC_266 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F14 | high | 0x8DB0, `3659eca60e4a` = amiga F14 |
| CINEMATIC_LESTER_SEATED_AT_HOLO_CONSOLE_F1_AMIGA_EXTRA | CINEMATIC_LESTER_SEATED_AT_HOLO_CONSOLE_F1 | high | 0xFA98, `b07528b7eb2e` -- the same art `gba_2004` gives this name to, and the second of the two `RESTORE` rows in `notes/amiga-extra-suffix/` |
