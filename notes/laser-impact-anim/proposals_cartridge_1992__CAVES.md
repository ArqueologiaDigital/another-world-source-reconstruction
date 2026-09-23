# The shot-impact burst in CAVES -- cartridge_1992

Derived by `notes/laser-impact-anim/impact_ladder.py`, which evaluates
the dispatch ladder at each value of the impact timer `[0x13]` instead
of reading the drawers' labels, and takes each family's stem from the
frames already named for the same (stage, direction) in any branch.
The index is 0-based per `docs/NAMING.md` line 208; the timer is seeded
to 1, so frame n is drawn at timer value n+1.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_789 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_0 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT` draws it when the shot timer `[0x13]` (seeded to 1, masked with 0x7FFF, incremented once per tick) holds 1, the 1th and 1th frame of the burst |
| CINEMATIC_790 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_1 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT` draws it when the shot timer `[0x13]` (seeded to 1, masked with 0x7FFF, incremented once per tick) holds 2, the 2th and 2th frame of the burst |
| CINEMATIC_791 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_2 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT` draws it when the shot timer `[0x13]` (seeded to 1, masked with 0x7FFF, incremented once per tick) holds 3, the 3th and 3th frame of the burst |
| CINEMATIC_792 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_3 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT` draws it when the shot timer `[0x13]` (seeded to 1, masked with 0x7FFF, incremented once per tick) holds 4, the 4th and 4th frame of the burst |
| CINEMATIC_793 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_4 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT` draws it when the shot timer `[0x13]` (seeded to 1, masked with 0x7FFF, incremented once per tick) holds 5, the 5th and 5th frame of the burst |
| CINEMATIC_794 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_5 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT` draws it when the shot timer `[0x13]` (seeded to 1, masked with 0x7FFF, incremented once per tick) holds 6, the 6th and 6th frame of the burst |
| CINEMATIC_831 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_0 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT` draws it when the shot timer `[0x13]` (seeded to 1, masked with 0x7FFF, incremented once per tick) holds 1, the 1th and 1th frame of the burst |
| CINEMATIC_832 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_1 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT` draws it when the shot timer `[0x13]` (seeded to 1, masked with 0x7FFF, incremented once per tick) holds 2, the 2th and 2th frame of the burst |
| CINEMATIC_833 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_2 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT` draws it when the shot timer `[0x13]` (seeded to 1, masked with 0x7FFF, incremented once per tick) holds 3, the 3th and 3th frame of the burst |
| CINEMATIC_834 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_3 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT` draws it when the shot timer `[0x13]` (seeded to 1, masked with 0x7FFF, incremented once per tick) holds 4, the 4th and 4th frame of the burst |
| CINEMATIC_835 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_4 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT` draws it when the shot timer `[0x13]` (seeded to 1, masked with 0x7FFF, incremented once per tick) holds 5, the 5th and 5th frame of the burst |
| CINEMATIC_836 | CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_5 | high | `CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT` draws it when the shot timer `[0x13]` (seeded to 1, masked with 0x7FFF, incremented once per tick) holds 6, the 6th and 6th frame of the burst |
