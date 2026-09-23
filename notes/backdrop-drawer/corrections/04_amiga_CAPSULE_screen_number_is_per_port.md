# amiga CAPSULE: the screen number is the port's own

| routine | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CAPSULE_SCREEN_6C_BACKDROP_DRAW | CAPSULE_SCREEN_4C_BACKDROP_DRAW | high | The 0x6C came from msdos by `align_branch_names.py`, but this stage's screen numbering is not shared: amiga CAPSULE compares `[SCREEN_NUM]` to 0x4C four times and to 0x6C **not once**, while msdos compares it to both. The amiga dataflow pins this routine to 0x4C, which is the only value its own port uses |
