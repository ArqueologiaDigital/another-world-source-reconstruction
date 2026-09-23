# The CAVES trap columns -- chahi_amiga_1991

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

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_697 | CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F0 | high | frame 0 of the 8 that `LABEL_2DAC` draws in order at `[0x07],[0x08]`, the thread set up on channel 0x23 right after `CAVES_TRAP_COLUMN_WATCH_SLOT_0_LOOP` |
| CINEMATIC_698 | CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F1 | high | frame 1 of the 8 that `LABEL_2DAC` draws in order at `[0x07],[0x08]`, the thread set up on channel 0x23 right after `CAVES_TRAP_COLUMN_WATCH_SLOT_0_LOOP` |
| CINEMATIC_699 | CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F2 | high | frame 2 of the 8 that `LABEL_2DAC` draws in order at `[0x07],[0x08]`, the thread set up on channel 0x23 right after `CAVES_TRAP_COLUMN_WATCH_SLOT_0_LOOP` |
| CINEMATIC_700 | CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F3 | high | frame 3 of the 8 that `LABEL_2DAC` draws in order at `[0x07],[0x08]`, the thread set up on channel 0x23 right after `CAVES_TRAP_COLUMN_WATCH_SLOT_0_LOOP` |
| CINEMATIC_701 | CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F4 | high | frame 4 of the 8 that `LABEL_2DAC` draws in order at `[0x07],[0x08]`, the thread set up on channel 0x23 right after `CAVES_TRAP_COLUMN_WATCH_SLOT_0_LOOP` |
| CINEMATIC_702 | CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F5 | high | frame 5 of the 8 that `LABEL_2DAC` draws in order at `[0x07],[0x08]`, the thread set up on channel 0x23 right after `CAVES_TRAP_COLUMN_WATCH_SLOT_0_LOOP` |
| CINEMATIC_703 | CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F6 | high | frame 6 of the 8 that `LABEL_2DAC` draws in order at `[0x07],[0x08]`, the thread set up on channel 0x23 right after `CAVES_TRAP_COLUMN_WATCH_SLOT_0_LOOP` |
| CINEMATIC_704 | CINEMATIC_CAVES_TRAP_COLUMN_SLOT_0_F7 | high | frame 7 of the 8 that `LABEL_2DAC` draws in order at `[0x07],[0x08]`, the thread set up on channel 0x23 right after `CAVES_TRAP_COLUMN_WATCH_SLOT_0_LOOP` |
| CINEMATIC_691 | CINEMATIC_CAVES_TRAP_COLUMN_SLOT_1_F0 | high | frame 0 of the 6 that `LABEL_2E0C` draws in order at `[0x07],[0x08]`, the thread set up on channel 0x25 right after `CAVES_TRAP_COLUMN_WATCH_SLOT_1_LOOP` |
| CINEMATIC_692 | CINEMATIC_CAVES_TRAP_COLUMN_SLOT_1_F1 | high | frame 1 of the 6 that `LABEL_2E0C` draws in order at `[0x07],[0x08]`, the thread set up on channel 0x25 right after `CAVES_TRAP_COLUMN_WATCH_SLOT_1_LOOP` |
| CINEMATIC_693 | CINEMATIC_CAVES_TRAP_COLUMN_SLOT_1_F2 | high | frame 2 of the 6 that `LABEL_2E0C` draws in order at `[0x07],[0x08]`, the thread set up on channel 0x25 right after `CAVES_TRAP_COLUMN_WATCH_SLOT_1_LOOP` |
| CINEMATIC_694 | CINEMATIC_CAVES_TRAP_COLUMN_SLOT_1_F3 | high | frame 3 of the 6 that `LABEL_2E0C` draws in order at `[0x07],[0x08]`, the thread set up on channel 0x25 right after `CAVES_TRAP_COLUMN_WATCH_SLOT_1_LOOP` |
| CINEMATIC_695 | CINEMATIC_CAVES_TRAP_COLUMN_SLOT_1_F4 | high | frame 4 of the 6 that `LABEL_2E0C` draws in order at `[0x07],[0x08]`, the thread set up on channel 0x25 right after `CAVES_TRAP_COLUMN_WATCH_SLOT_1_LOOP` |
| CINEMATIC_696 | CINEMATIC_CAVES_TRAP_COLUMN_SLOT_1_F5 | high | frame 5 of the 6 that `LABEL_2E0C` draws in order at `[0x07],[0x08]`, the thread set up on channel 0x25 right after `CAVES_TRAP_COLUMN_WATCH_SLOT_1_LOOP` |
