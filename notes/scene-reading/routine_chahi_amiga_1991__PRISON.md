# The tiled backdrop builder -- chahi_amiga_1991

| routine | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| LABEL_80AA | PRISON_BACKDROP_TILE_REPEAT_DOWN | high | it clears pages 0x00 and 0x03, draws the pattern once into page 0x03, then blits page 0x83 to page 0x00 five times while adding 0x20 to [SCROLL_Y] between blits -- a vertically repeating backdrop built by page copy, not by repeated `video` draws |
