# The PRISON zoom ladder's first two loop heads -- chahi_amiga_1991

Derived by `notes/placeholder-census/placeholder_roles.py --loops`, which
reports candidates rather than proposing them: tree-wide the `<STEM>_DONE`
-> `<STEM>_LOOP` pairing holds only 9 times out of 16. These two are taken
because the convention is proved twice inside this same ladder, twelve lines
away, rather than tree-wide.

| routine | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| LABEL_0236 | PRISON_CUTSCENE_ZOOM_IN_PHASE_00_LOOP | high | it is the backward target of `djnz [0xE6], LABEL_0236`, and the label carrying that `djnz` is `PRISON_CUTSCENE_ZOOM_IN_PHASE_00_DONE`. Phases 04 and 05 of the same ladder, in this same file, already spell the identical shape `PRISON_CUTSCENE_ZOOM_IN_PHASE_<nn>_LOOP` closed by `..._PHASE_<nn>_DONE`, and every block of the ladder is `break`, `add [SCROLL_Y], 0x0002`, `je [0xDB], 0x01, <the DONE label>`, three zoomed draws, `add [0xE7], 0x0001` |
| LABEL_025F | PRISON_CUTSCENE_ZOOM_IN_PHASE_01_LOOP | high | the backward target of `djnz [0xE6], LABEL_025F`, carried by `PRISON_CUTSCENE_ZOOM_IN_PHASE_01_DONE`; same block shape and same two in-file precedents as the row above |
