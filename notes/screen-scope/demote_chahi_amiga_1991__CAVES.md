# Conditional draws demoted in CAVES -- chahi_amiga_1991

These were named as backdrop layers before backdrop_phase.py truncated the
phase at the first conditional jump. Each is painted only when a branch
lets it through, so it is a state overlay and not a layer of the backdrop.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_CAVES_SCREEN_68_BACKDROP_LAYER_3 | CINEMATIC_386 | high | a conditional jump before its draw can skip it, so it is not unconditionally painted; restored to the index its EQU table position gives |
