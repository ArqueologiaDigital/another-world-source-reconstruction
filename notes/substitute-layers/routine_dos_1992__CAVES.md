# The CAVES trap-column draw threads -- dos_1992

The CAVES trap columns. `CAVES_TRAP_COLUMN_WATCH_SLOT_0_LOOP` and
`..._SLOT_1_LOOP` are already named, and each is installed immediately before
its own draw thread on the next channel -- 0x22/0x23 for slot 0 and 0x24/0x25
for slot 1 -- after that slot's position variables are set. The thread draws
its frames in order at `[0x07],[0x08]`, each guarded by `jne [0x09], 0x00` so
the whole animation aborts when the column is cleared.

The two slots use entirely different art: zero frames shared by
`canonical_md5`, 8 frames for slot 0 and 6 for slot 1. All three branches
have the identical structure at different constant numbers, and amiga and
msdos agree frame for frame.

| routine | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CAVES_ANIM_CIN_718_719_GUARDED_BY_VAR09 | CAVES_TRAP_COLUMN_SLOT_0_DRAW_LOOP | high | set up on channel 0x23 immediately after `CAVES_TRAP_COLUMN_WATCH_SLOT_0_LOOP`, and draws that column's 8 frames in order |
| LABEL_302F | CAVES_TRAP_COLUMN_SLOT_1_DRAW_LOOP | high | set up on channel 0x25 immediately after `CAVES_TRAP_COLUMN_WATCH_SLOT_1_LOOP`, and draws that column's 6 frames in order |
