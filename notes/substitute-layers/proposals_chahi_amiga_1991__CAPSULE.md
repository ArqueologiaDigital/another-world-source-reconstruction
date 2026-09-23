# The charged-blast fade in CAPSULE -- chahi_amiga_1991

The fade is a `jne [0x13], 0x<case>` ladder running 0x81..0x89, nine cases,
and the LEFT and RIGHT ladders draw the SAME constants -- which is why the
family carries no direction. Six were named 0..5 and the first three cases
were never named, so the family began three frames late.

All nine hold identical art in amiga and msdos, case for case by
`canonical_md5`, and the geometry reads as one blast: widths 2, 10, 19, 28,
36, 36, 35, 28, 30 against heights 64, 68, 63, 61, 52, 47, 34, 22, 7.

The index is the machine's: case 0x81 is frame 0. Applied branch-scoped,
because the constants differ per port -- amiga 480/479/478, msdos
627/626/625, cartridge 636..628 -- which is exactly what forced the revert
of 36139804 when this was first attempted on amiga's numbers.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_480 | CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_0 | high | drawn at case 0x81, the first case of the ladder and never named |
| CINEMATIC_479 | CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_1 | high | drawn at case 0x82, the second case of the ladder and never named |
| CINEMATIC_478 | CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_2 | high | drawn at case 0x83, the third case of the ladder and never named |
| CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_0 | CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_3 | high | renumbered: it is drawn at case 0x84, which is frame 3 of nine |
| CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_1 | CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_4 | high | renumbered: it is drawn at case 0x85, which is frame 4 of nine |
| CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_2 | CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_5 | high | renumbered: it is drawn at case 0x86, which is frame 5 of nine |
| CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_3 | CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_6 | high | renumbered: it is drawn at case 0x87, which is frame 6 of nine |
| CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_4 | CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_7 | high | renumbered: it is drawn at case 0x88, which is frame 7 of nine |
| CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_5 | CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_8 | high | renumbered: it is drawn at case 0x89, which is frame 8 of nine |
