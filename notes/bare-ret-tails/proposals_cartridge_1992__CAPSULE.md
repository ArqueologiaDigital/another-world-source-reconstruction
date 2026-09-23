# Bare-ret tails in CAPSULE -- cartridge_1992

Derived by notes/bare-ret-tails/owner_ret.py.

| routine | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| LABEL_947C | DRAW_HERO_WATER_DEPTH_LEFT_CASE_03_RET | high | its entire body is a bare `ret`, and the only thing that reaches it is a jump from inside `DRAW_HERO_WATER_DEPTH_LEFT_CASE_03` -- not a `call` or a `setup`, so it is that routine's return tail and not an entry point. 112 labels in the tree already carry `<owner>_RET` in exactly this position |
| LABEL_921B | DRAW_HERO_WATER_DEPTH_RIGHT_CASE_03_RET | high | its entire body is a bare `ret`, and the only thing that reaches it is a jump from inside `DRAW_HERO_WATER_DEPTH_RIGHT_CASE_03` -- not a `call` or a `setup`, so it is that routine's return tail and not an entry point. 112 labels in the tree already carry `<owner>_RET` in exactly this position |
