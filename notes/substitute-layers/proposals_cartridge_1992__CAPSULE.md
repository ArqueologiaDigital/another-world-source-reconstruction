# The charged-blast fade in CAPSULE -- cartridge_1992

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
| CINEMATIC_636 | CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_0 | high | drawn at case 0x81 of the fade ladder |
| CINEMATIC_635 | CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_1 | high | drawn at case 0x82 of the fade ladder |
| CINEMATIC_634 | CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_2 | high | drawn at case 0x83 of the fade ladder |
| CINEMATIC_633 | CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_3 | high | drawn at case 0x84 of the fade ladder |
| CINEMATIC_632 | CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_4 | high | drawn at case 0x85 of the fade ladder |
| CINEMATIC_631 | CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_5 | high | drawn at case 0x86 of the fade ladder |
| CINEMATIC_630 | CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_6 | high | drawn at case 0x87 of the fade ladder |
| CINEMATIC_629 | CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_7 | high | drawn at case 0x88 of the fade ladder |
| CINEMATIC_628 | CINEMATIC_CAPSULE_CHARGED_BLAST_FADE_8 | high | drawn at case 0x89 of the fade ladder |
