# Six INTRO names restored to their numbers -- dos_1992

Each of these sits on art that is not what the name says; `name_art_agreement.py`
finds amiga's copy of that art under a bare number, and amiga's named art on a
different msdos constant. Step one of the fix: give each wrong holder back the
index its EQU table position gives.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_ACCELERATOR_TUNNEL_VIEW_FAR | CINEMATIC_379 | high | its art is amiga's CINEMATIC_378, not amiga's ACCELERATOR_TUNNEL_VIEW_FAR; restored to its table position |
| CINEMATIC_ACCELERATOR_TUNNEL_VIEW_NEAR | CINEMATIC_249 | high | its art is amiga's CINEMATIC_243, not amiga's ACCELERATOR_TUNNEL_VIEW_NEAR; restored to its table position |
| CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F2 | CINEMATIC_523 | high | its art is amiga's CINEMATIC_517, while amiga's art for this name is msdos' own CINEMATIC_517 -- the two ports hold each other's picture at that index |
| CINEMATIC_LIFT_SCENE_BG | CINEMATIC_534 | high | its art is amiga's CINEMATIC_533, not amiga's LIFT_SCENE_BG; restored to its table position |
| CINEMATIC_LIFT_SCENE_VIEW | CINEMATIC_529 | high | its art is amiga's CINEMATIC_528, not amiga's LIFT_SCENE_VIEW; restored to its table position |
| CINEMATIC_PARTICLE_LAB_HOLO_CONSOLE | CINEMATIC_177 | high | its art is amiga's CINEMATIC_171, not amiga's PARTICLE_LAB_HOLO_CONSOLE; restored to its table position |
