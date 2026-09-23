# CAVES laser-impact flash -- dos_1992

Derived by `notes/laser-impact-anim/impact_ladder.py`, which evaluates the
impact dispatch ladder at each value of the timer `[0x13]` rather than reading
its labels. See that directory's README for why the label names are not frames.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_CAVES_DRAW_HERO_IDLE_LEFT_1 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_F01 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 1 |
| CINEMATIC_799 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_F02 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 2 |
| CINEMATIC_800 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_F03 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 3 |
| CINEMATIC_801 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_F04 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 4 |
| CINEMATIC_802 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_F05 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 5 |
| CINEMATIC_803 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_F06 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 6 |
| CINEMATIC_840 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_F01 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 1 |
| CINEMATIC_841 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_F02 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 2 |
| CINEMATIC_842 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_F03 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 3 |
| CINEMATIC_843 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_F04 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 4 |
| CINEMATIC_844 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_F05 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 5 |
| CINEMATIC_845 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_F06 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 6 |
