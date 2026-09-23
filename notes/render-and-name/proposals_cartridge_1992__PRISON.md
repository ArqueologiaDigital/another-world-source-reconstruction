# PRISON pupil ladder -- cartridge_1992, named from the rung, not from the art

## Why this branch is here at all

The cartridge polygon data **cannot be measured**. Archaeology issue #0106,
"Locate SNES cinematic + video2 polygon-data offsets in the SFC ROM", is open;
`snes.toml` still carries `["cinematic.rom", "?"]`, no romset is produced for
it, and so there is no render, no extent and no `canonical_md5` for any
cartridge picture. Every other name in this batch came from measuring amiga's
art and carrying it to msdos on an md5 match. Neither step is available here.

This file exists anyway because **leaving cartridge alone is not neutral.**
It already carries `CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_0/1/2`, applied when
the ladder was thought to have three rungs. amiga and msdos have now renumbered
to 0..6. Do nothing and `PUPIL_0` means rung 1 on two branches and rung 2 on a
third -- one name, two meanings, hazard #0118. Renumber only the three and
cartridge's family becomes {1, 5, 6}, an index run with holes, which
`docs/NAMING.md` §2 bars. The only consistent states are "all seven" or "none",
and "none" throws away three names that are right about the subject.

## What the names rest on instead

The rung. `ladder_rungs.py --stage PRISON --var 0x16 --diff
chahi_amiga_1991 cartridge_1992` reads the `jg [0x16], N` chain out of each
branch's own `.asm` and compares it: same rung count, same threshold at every
rung, same position for every constant. The eyelid ladder on `[0x15]` passes
the same check at 20 rungs. So `PUPIL_3` here claims exactly one thing --
*the picture this branch's ladder draws when `[0x16]` is at rung 4 of 7* --
and that is in bytecode this session can read, not in art it cannot.

It does **not** claim the cartridge picture looks like amiga's 12x13 pupil.
If the cartridge art is ever extracted and disagrees, these seven rows are the
ones to re-examine, and `--diff` is the check that will say so.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_2 | CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_6 | high | **renumber**: this branch's ladder draws it at rung 7 of 7, the `else` block `PRISON_WAKE_CLOSEUP_PUPIL_WIDEST` |
| CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_1 | CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_5 | high | **renumber**: rung 6 of 7, `jg [0x16], 0x06` |
| CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_0 | CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_1 | high | **renumber**: rung 2 of 7, `jg [0x16], 0x02` |
| CINEMATIC_682 | CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_0 | high | rung 1 of 7, `jg [0x16], 0x01` -- the state the scene starts in |
| CINEMATIC_680 | CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_2 | high | rung 3 of 7, `jg [0x16], 0x03` |
| CINEMATIC_679 | CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_3 | high | rung 4 of 7, `jg [0x16], 0x04` |
| CINEMATIC_678 | CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_4 | high | rung 5 of 7, `jg [0x16], 0x05` |
