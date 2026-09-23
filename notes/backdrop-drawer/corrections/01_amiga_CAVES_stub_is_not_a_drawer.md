# amiga CAVES: the stub that is not a background drawer

| routine | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| DRAW_CAVES_FIRST_ROOM_BG | CAVES_DRAW_CRAWLING_BG_AND_PICK_BY_HERO_X_LOOP | high | Its whole body is `break` then `jmp CAVES_DRAW_CRAWLING_BG_AND_PICK_BY_HERO_X`; it draws nothing at all. It is the join of that routine's two-way assignment to `[0x42]` -- reached by falling through, or by the `jl [HERO_X], 0x35` that skips the else-arm -- followed by the yield and the loop back to the top. The msdos counterpart of this exact position is the unnamed `LABEL_D1E3` |
