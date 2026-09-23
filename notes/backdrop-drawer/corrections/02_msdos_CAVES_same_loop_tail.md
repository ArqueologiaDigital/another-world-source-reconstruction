# msdos CAVES: the same loop tail

| routine | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| LABEL_D1E3 | CAVES_DRAW_CRAWLING_BG_AND_PICK_BY_HERO_X_LOOP | high | `break` then `jmp CAVES_DRAW_CRAWLING_BG_AND_PICK_BY_HERO_X`, reached by falling through or by that routine's `jl [HERO_X], 0x35`; the yield-and-restart tail of the crawling-background thread, and the position `align_branch_names.py` pairs with the amiga label of the same name |
