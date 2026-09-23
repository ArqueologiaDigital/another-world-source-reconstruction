# CAVES laser-impact flash -- chahi_amiga_1991

Derived by `notes/laser-impact-anim/impact_ladder.py`, which evaluates the
impact dispatch ladder at each value of the timer `[0x13]` rather than reading
its labels. See that directory's README for why the label names are not frames.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_773 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_F01 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 1 |
| CINEMATIC_774 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_F02 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 2 |
| CINEMATIC_775 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_F03 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 3 |
| CINEMATIC_776 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_F04 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 4 |
| CINEMATIC_777 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_F05 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 5 |
| CINEMATIC_778 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_F06 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 6 |
| CINEMATIC_816 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_F01 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 1 |
| CINEMATIC_817 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_F02 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 2 |
| CINEMATIC_818 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_F03 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 3 |
| CINEMATIC_819 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_F04 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 4 |
| CINEMATIC_820 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_F05 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 5 |
| CINEMATIC_821 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_F06 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT` draws it when the impact timer `[0x13]` (masked with 0x7FFF, incremented once per tick) holds 6 |
