# Hero fire frames in CAPSULE -- chahi_amiga_1991

Derived by notes/substitute-layers/fire_frames.py: the frame drawn at the shot and the frame after it, with the name read off the shared bank piece each matches by canonical_md5.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_116 | CINEMATIC_CAPSULE_HERO_STAND_SHOOT_LEFT_F0 | high | drawn at the shot, immediately before the muzzle is set and `LABEL_440F` spawns the projectile; the muzzle offset `sub [0x21], 0x001E` puts the shot to the left, and its `canonical_md5` equals the shared bank's `HERO_STAND_SHOOT_LEFT_F0` |
| CINEMATIC_115 | CINEMATIC_CAPSULE_HERO_STAND_SHOOT_LEFT_F1 | high | drawn immediately after `LABEL_440F` spawns the projectile, the frame the hero returns through; the muzzle offset `sub [0x21], 0x001E` puts the shot to the left, and its `canonical_md5` equals the shared bank's `HERO_STAND_SHOOT_LEFT_F1` |
