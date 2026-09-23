# The shot-impact burst in CAPSULE -- chahi_amiga_1991

Derived by `notes/laser-impact-anim/impact_ladder.py`, which evaluates
the dispatch ladder at each value of the impact timer `[0x13]` instead
of reading the drawers' labels, and takes each family's stem from the
frames already named for the same (stage, direction) in any branch.
The index is 0-based per `docs/NAMING.md` line 208; the timer is seeded
to 1, so frame n is drawn at timer value n+1.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_497 | CINEMATIC_CAPSULE_SHOT_HIT_BURST_RIGHT_5 | high | `CAPSULE_SHOT_STATE_FRAME_DISPATCH_RIGHT` draws it when the shot timer `[0x13]` (seeded to 1, masked with 0x7FFF, incremented once per tick) holds 6, the 6th and 6th frame of the burst |
| CINEMATIC_512 | CINEMATIC_CAPSULE_SHOT_HIT_BURST_LEFT_5 | high | `CAPSULE_SHOT_STATE_FRAME_DISPATCH_LEFT` draws it when the shot timer `[0x13]` (seeded to 1, masked with 0x7FFF, incremented once per tick) holds 6, the 6th and 6th frame of the burst |
