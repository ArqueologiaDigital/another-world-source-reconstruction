# The cell-block painter -- chahi_amiga_1991

| routine | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| LABEL_4A2B | PRISON_SCREEN_04_BACKDROP_DRAW | high | PRISON_SCREEN_04_ENTRY calls it between `selectVideoPage 0x00` and the first `setup`, and it paints the whole cell block in seven layers at x=160, y=100; it is called from nowhere else. Matches the CAVES_SCREEN_<NN>_BACKDROP_DRAW form already in the tree |
