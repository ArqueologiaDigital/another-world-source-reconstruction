# INTRO (msdos): the same five

Argument and measurements in `proposals_chahi_amiga_1991__INTRO_stamps.md`.
Three are matched by `canonical_md5`; the two one-path marks are matched by
their draw sites, because the hash cannot tell a two-pixel mark from nine
others (`notes/cross-port-art/colour_blind_hashes.py`).

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_130 | CINEMATIC_HOLO_CONSOLE_DOT_RISE_SLOW | high | 0x06A8 -- the same offset as amiga's `CINEMATIC_124`, drawn at the same `x=204, y=[0x08]`. Not matched by hash: a 2.0x1.0 one-path mark has nothing to be identical about |
| CINEMATIC_137 | CINEMATIC_LAB_AUTH_DOT | high | drawn twice a pass at `x=280, y=[0x08]` and `x=283, y=[0x0b]`, exactly as amiga draws `CINEMATIC_131`. Matched by draw site, not by hash |
| CINEMATIC_448 | CINEMATIC_HOLO_CONSOLE_RISING_BAR | high | 0xDD1A, `cbcea26b3b30` -- identical art to amiga's `CINEMATIC_447` |
| CINEMATIC_132 | CINEMATIC_LAB_AUTH_CRT_READOUT_ROWS | medium | 0xF4E0, `c6467ae6d71c` -- identical to amiga's `CINEMATIC_126` |
| CINEMATIC_133 | CINEMATIC_LAB_AUTH_CRT_SOLID_ICON | medium | 0xF53C, `6569e3123e0c` -- identical to amiga's `CINEMATIC_127` |
