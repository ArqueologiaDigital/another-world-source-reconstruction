# CAPSULE (dos_1992): the death animation's other three versions

Argument, dispatch and render in `hero_death_four_ways.md`.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_HERO_DEATH_F0 | CINEMATIC_HERO_DEATH_STANDING_LEFT_F0 | high | the already-named family, given the facing its newly-named mirror forces on it; unchanged art, the rename is the whole row |
| CINEMATIC_HERO_DEATH_F1 | CINEMATIC_HERO_DEATH_STANDING_LEFT_F1 | high | the already-named family, given the facing its newly-named mirror forces on it; unchanged art, the rename is the whole row |
| CINEMATIC_HERO_DEATH_F2 | CINEMATIC_HERO_DEATH_STANDING_LEFT_F2 | high | the already-named family, given the facing its newly-named mirror forces on it; unchanged art, the rename is the whole row |
| CINEMATIC_158 | CINEMATIC_HERO_DEATH_STANDING_RIGHT_F0 | high | `1669ee072adc` -- standing, 20.0x49.5 then 22.5x47.0 and 23.5x47.0; the exact mirror of `HERO_DEATH_STANDING_LEFT_*`, drawn by the routine the dispatch reaches when `[0x04] & 0xFF` is at least 0x30, frame 0 of the `F0, F1, F2, F1` run that ends in the shared blast block |
| CINEMATIC_159 | CINEMATIC_HERO_DEATH_STANDING_RIGHT_F1 | high | `d18d577e69a1` -- standing, 20.0x49.5 then 22.5x47.0 and 23.5x47.0; the exact mirror of `HERO_DEATH_STANDING_LEFT_*`, drawn by the routine the dispatch reaches when `[0x04] & 0xFF` is at least 0x30, frame 1 of the `F0, F1, F2, F1` run that ends in the shared blast block |
| CINEMATIC_160 | CINEMATIC_HERO_DEATH_STANDING_RIGHT_F2 | high | `bc64be7c12ba` -- standing, 20.0x49.5 then 22.5x47.0 and 23.5x47.0; the exact mirror of `HERO_DEATH_STANDING_LEFT_*`, drawn by the routine the dispatch reaches when `[0x04] & 0xFF` is at least 0x30, frame 2 of the `F0, F1, F2, F1` run that ends in the shared blast block |
| CINEMATIC_145 | CINEMATIC_HERO_DEATH_KNEELING_RIGHT_F0 | high | `19e8d88ea46f` -- kneeling, 29.5x34.0 then 24.5x32.0 and 23.5x32.0; the gun arm points right, and its routine does `sub [HERO_X]` between frames -- driven left, away from the side it faces, frame 0 of the `F0, F1, F2, F1` run that ends in the shared blast block |
| CINEMATIC_146 | CINEMATIC_HERO_DEATH_KNEELING_RIGHT_F1 | high | `2ee75df360c9` -- kneeling, 29.5x34.0 then 24.5x32.0 and 23.5x32.0; the gun arm points right, and its routine does `sub [HERO_X]` between frames -- driven left, away from the side it faces, frame 1 of the `F0, F1, F2, F1` run that ends in the shared blast block |
| CINEMATIC_147 | CINEMATIC_HERO_DEATH_KNEELING_RIGHT_F2 | high | `a197e68e3334` -- kneeling, 29.5x34.0 then 24.5x32.0 and 23.5x32.0; the gun arm points right, and its routine does `sub [HERO_X]` between frames -- driven left, away from the side it faces, frame 2 of the `F0, F1, F2, F1` run that ends in the shared blast block |
| CINEMATIC_175 | CINEMATIC_HERO_DEATH_KNEELING_LEFT_F0 | high | `c657b2b63209` -- kneeling, 31.0x34.0 then 27.5x32.0 and 27.5x32.0; the mirror of the above, and its routine does `add [HERO_X]`, frame 0 of the `F0, F1, F2, F1` run that ends in the shared blast block |
| CINEMATIC_176 | CINEMATIC_HERO_DEATH_KNEELING_LEFT_F1 | high | `365a9b43cece` -- kneeling, 31.0x34.0 then 27.5x32.0 and 27.5x32.0; the mirror of the above, and its routine does `add [HERO_X]`, frame 1 of the `F0, F1, F2, F1` run that ends in the shared blast block |
| CINEMATIC_177 | CINEMATIC_HERO_DEATH_KNEELING_LEFT_F2 | high | `f54dd78d207c` -- kneeling, 31.0x34.0 then 27.5x32.0 and 27.5x32.0; the mirror of the above, and its routine does `add [HERO_X]`, frame 2 of the `F0, F1, F2, F1` run that ends in the shared blast block |
