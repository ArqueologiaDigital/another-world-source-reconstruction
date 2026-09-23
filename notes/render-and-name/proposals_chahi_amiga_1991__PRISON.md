# PRISON -- the actor charge glow, read from a render

Numbered densely from 0 in ascending routine-frame order, because
`PRISON_ACTOR_CHARGE_GLOW_FRAME_02` **does not exist** -- the gap is in the
routine family, and copying it into the art family would be an interior hole
that `docs/NAMING.md` §2 bars. The mapping is
`FRAME_01,03,04,05,06,07,08 -> F0..F6`.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_203 | CINEMATIC_PRISON_ACTOR_CHARGE_GLOW_F0 | medium | rendered in frame order the seven are a small, vertically symmetric blob that **grows monotonically**: 5x6, 6x8, 12x8, 12x12, 12x14, then 12x12 and 12x14 again, every one of them two paths. Growth then alternation is what a charge and its flicker look like, and it is what orders the family. Each is the sole picture of one `PRISON_ACTOR_CHARGE_GLOW_FRAME_<n>` routine; seven separately written names agree on the subject. The word `GLOW` is supported by the shape, `CHARGE` comes from those routines |
| CINEMATIC_190 | CINEMATIC_PRISON_ACTOR_CHARGE_GLOW_F1 | medium | 6x8, sole picture of `PRISON_ACTOR_CHARGE_GLOW_FRAME_03` |
| CINEMATIC_191 | CINEMATIC_PRISON_ACTOR_CHARGE_GLOW_F2 | medium | 12x8, sole picture of `PRISON_ACTOR_CHARGE_GLOW_FRAME_04` |
| CINEMATIC_192 | CINEMATIC_PRISON_ACTOR_CHARGE_GLOW_F3 | medium | 12x12, sole picture of `PRISON_ACTOR_CHARGE_GLOW_FRAME_05` |
| CINEMATIC_193 | CINEMATIC_PRISON_ACTOR_CHARGE_GLOW_F4 | medium | 12x14, sole picture of `PRISON_ACTOR_CHARGE_GLOW_FRAME_06` |
| CINEMATIC_194 | CINEMATIC_PRISON_ACTOR_CHARGE_GLOW_F5 | medium | 12x12, sole picture of `PRISON_ACTOR_CHARGE_GLOW_FRAME_07` |
| CINEMATIC_195 | CINEMATIC_PRISON_ACTOR_CHARGE_GLOW_F6 | medium | 12x14, sole picture of `PRISON_ACTOR_CHARGE_GLOW_FRAME_08` |
