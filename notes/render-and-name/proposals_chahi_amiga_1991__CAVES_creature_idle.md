# CAVES: the creature standing still, with and without its collar

`notes/mirror-families/mirror_candidates.py` flagged `CINEMATIC_314, 315, 316`
as measuring like `CINEMATIC_CAVES_CREATURE_WALK_RIGHT_*` -- 51.0x29.5 in twelve
leaves, three times over. It is not a mirror; it is the **same creature** in a
different routine, which is the caveat that probe's own docstring carries
("two figures of the same build measure alike").

`CAVES_BUDDY_IDLE_HOLD_PHASE_2` through `_14` draw seven constants at
`x=[0x68], y=[0x69]`, each held in a `djnz` loop:

```
  P2  311   P3  312   P4  311   P5  312   P6  311   P7  313   P8  311   P9  313
  P11 310   P12 314   P13 315   P14 316   then 314 again
```

Rendered at palette 9 and cropped to each frame's extent: a four-legged
creature, dark body, tan legs, pale head at the right. The first three carry a
**blue hoop around the neck** and the last four do not, and the leaf counts say
the same thing without the render --

```
  311  54.5x30.0  17 leaf      310  51.0x30.0  12 leaf
  312  53.5x29.0  17 leaf      314  51.0x29.5  12 leaf
  313  54.5x30.0  17 leaf      315  51.0x29.5  12 leaf
                               316  51.0x29.0  12 leaf
```

-- five extra leaves and three or four extra pixels of width, in exactly the
three frames where the hoop is drawn. Twelve leaves at 51.0 wide is also what
`CAVES_CREATURE_WALK_RIGHT_F0..F5` measures, so the uncollared four are that
same creature and take that same word.

The index in each family is first appearance across the phase series, which is
the rule the crowd cloaks and the robed figure were named under.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_311 | CINEMATIC_CAVES_CREATURE_IDLE_COLLARED_F0 | medium | 0xB878, 54.5x30.0 in **17** leaves, the hoop present; first of the seven to be drawn, at `PHASE_2`, and again at P4, P6 and P8 |
| CINEMATIC_312 | CINEMATIC_CAVES_CREATURE_IDLE_COLLARED_F1 | medium | 0xB958, 53.5x29.0 in 17 leaves; `PHASE_3`, alternating with the last through P5 |
| CINEMATIC_313 | CINEMATIC_CAVES_CREATURE_IDLE_COLLARED_F2 | medium | 0xB8C4, 54.5x30.0 in 17 leaves; `PHASE_7`, taking over the alternation through P9 |
| CINEMATIC_310 | CINEMATIC_CAVES_CREATURE_IDLE_F0 | medium | 0xB7E2, 51.0x30.0 in **12** leaves, no hoop; `PHASE_11`, where the collared half of the sequence ends |
| CINEMATIC_314 | CINEMATIC_CAVES_CREATURE_IDLE_F1 | medium | 0xB7B8, 51.0x29.5 in 12 leaves; `PHASE_12`, and the frame the sequence finally rests on |
| CINEMATIC_315 | CINEMATIC_CAVES_CREATURE_IDLE_F2 | medium | 0xB904, 51.0x29.5 in 12 leaves; `PHASE_13` |
| CINEMATIC_316 | CINEMATIC_CAVES_CREATURE_IDLE_F3 | medium | 0xB92E, 51.0x29.0 in 12 leaves; `PHASE_14` |

`medium`: the leaf counts and the hoop are measured and rendered; that the hoop
is a collar rather than some other ring around the neck is the reading, and the
name says only that it is there.
