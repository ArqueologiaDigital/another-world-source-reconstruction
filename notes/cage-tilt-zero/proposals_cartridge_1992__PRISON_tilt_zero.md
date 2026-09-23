# PRISON (cartridge): the same two rows, by control flow alone

Cartridge's ROM is not extracted (#0106), so no extent and no leaf count was
measured for these two. The rows rest entirely on the arm they are drawn in,
which is identical to the other two ports'.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_078 | CINEMATIC_PRISON_CAGE_HERO_TILT_ZERO | medium | 0x1810, drawn first at x=[0x03],y=[0x04] in the `jne [0x06], 0x00` arm at LABEL_7576 (PRISON.asm:13224-13226), whose `== 1` and `== -1` arms draw CINEMATIC_PRISON_CAGE_HERO_TILT_PLUS_1 (0x1836) / _MINUS_1 (0x1960) first at the same anchor. Art not measured (#0106) |
| CINEMATIC_079 | CINEMATIC_PRISON_CAGE_BARS_TILT_ZERO | medium | 0x0CE4, drawn second in the same arm; and independently at PRISON.asm:13204-13205, the `jne [0x06], 0x00` arm of a bars-only ladder whose siblings are already labelled DRAW_PRISON_CAGE_BARS_TILT_PLUS and DRAW_PRISON_CAGE_BARS_TILT_MINUS. Art not measured (#0106) |
