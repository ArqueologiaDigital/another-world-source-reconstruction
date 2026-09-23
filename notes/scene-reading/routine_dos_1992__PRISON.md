# The tiled backdrop builder -- dos_1992

| routine | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| PRISON_SCENE_INIT_DRAW_CIN_085_086_TO_PAGE_3 | PRISON_BACKDROP_TILE_REPEAT_DOWN | high | it clears pages 0x00 and 0x03, draws the pattern once into page 0x03, then blits page 0x83 to page 0x00 five times while adding 0x20 to [SCROLL_Y] between blits -- a vertically repeating backdrop built by page copy, not by repeated `video` draws |
