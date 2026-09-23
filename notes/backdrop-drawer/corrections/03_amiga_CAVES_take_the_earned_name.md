# amiga CAVES: the painter takes the other port's earned name

| routine | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CAVES_SCREEN_67_BACKDROP_DRAW | DRAW_CAVES_FIRST_ROOM_BG | high | `align_branch_names.py` pairs this routine with the msdos routine of that name by aligned instruction stream, and the two bodies match: `fill page=0x00`, the two screen-0x67 backdrop layers, then the page-3 scroll backdrop. The msdos name is older and carries a human comment describing the composition, so the ports are made to agree on it rather than on the one this session derived |
