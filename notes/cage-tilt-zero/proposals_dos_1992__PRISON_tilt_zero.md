# PRISON (msdos): the tilt-zero members of the cage families

Derived from control flow; see `README.md` in this directory for the two
independent arms and the geometry that corroborates them.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_078 | CINEMATIC_PRISON_CAGE_HERO_TILT_ZERO | high | 0x1ADE, drawn first at x=[0x03],y=[0x04] in the `jne [0x06], 0x00` arm at PRISON.asm:13210-13212, whose `== 1` and `== -1` arms draw CINEMATIC_PRISON_CAGE_HERO_TILT_PLUS_1 / _MINUS_1 first at the same anchor. 11 leaves, 23.5 x 49.5, matching HERO_TILT_MINUS_1 (0x1C2E) exactly. TILT_ZERO is the spelling the sibling CHAIN family already uses for the same arm |
| CINEMATIC_079 | CINEMATIC_PRISON_CAGE_BARS_TILT_ZERO | high | 0x0EDA, drawn second at x=[0x03],y=[0x04] in the same `jne [0x06], 0x00` arm at PRISON.asm:13210-13212, whose `== 1` and `== -1` arms draw CINEMATIC_PRISON_CAGE_BARS_TILT_PLUS_1 / _MINUS_1 second at the same anchor. 18 leaves, 57.0 x 55.5, against BARS_TILT_MINUS_1 (0x132A) 18 leaves, 56.0 x 55.5. Second, independent arm: PRISON.asm:13190-13191 draws it in the `jne [0x06], 0x00` arm of a bars-only ladder whose siblings are already labelled PRISON_DRAW_CAGE_BARS_TILT_PLUS_1_ELSE_MINUS_1 and PRISON_DRAW_CAGE_BARS_TILT_MINUS_1 |
