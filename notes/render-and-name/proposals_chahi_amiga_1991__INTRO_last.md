# INTRO: a standing pose, a lamp and a pointer

## The walking-towards cycle has a standing frame too, and it was a number

`LESTER_WALKING_TOWARDS_CAMERA_ANIMATION` plays, one per `break`:

```
  466  F0 F1 F2 F3 F4 F5 F6 F5 F4 F3 F2 F1 F0  466  F7
```

which is the same shape as the walking-**away** cycle after its renumber --
`STAND F0..F6 F5..F0 STAND F7` -- with `CINEMATIC_466` in the standing slot.
The sheet says the same thing: 0x180A (F7), **0x187E (466)**, 0x18F6 (F0), then
F1..F6 on a 0x80 stride, exactly the layout the away family has at 0x42A6,
0x42BE, 0x42D6. And 466 measures 98.0x185.0 in **16 paths**, against F0's
99.0x185.0 and F7's 101.0x185.0, also 16 paths each.

So it is that family's standing pose, and it takes the mirror of the name the
away family's carries.

## The other three

```
  176  0x3F6C   30.0x28.5    5 paths    drawn at x=187, y=101
  184  0xF220   29.0x14.0    3 paths    drawn at x=[0x03], y=[0x04]
  430  0xFBB6   16.0x 9.0    2 paths    drawn at x=[0x03], y=[0x04]
```

**176** is a domed head on a short stem -- a blue dome with a cyan highlight
and a dark rim over a narrow dark shaft. It is drawn at `x=187, y=101`, beside
the seated figure at `x=160, y=101`, by both routines that compose the holo
console scene.

**184 and 430 are the same arrow.** 430 is a pale arrowhead with a swept tail,
2 paths. 184 is that arrowhead over a blue parallelogram plate, 3 paths. Each
has a tight redraw loop of its own -- `LABEL_10CA` and `LABEL_10D4`, both
`video ... ; break ; jmp` -- and both draw at the **same two variables**
`[0x03]` and `[0x04]`, so they are two forms of one moving pointer, not two
different things. The routine that installs the scene around them sets up
`DRAW_HOLO_SCREEN_BG_COMPOSITE`.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_466 | CINEMATIC_LESTER_STANDING_FACING_CAMERA | high | 0x187E, 98.0x185.0 in 16 paths, between F7 (0x180A) and F0 (0x18F6) on the towards-camera sheet and played in the standing slot of its cycle, exactly as `..._STANDING_BACK_TO_CAMERA` is on the away sheet |
| CINEMATIC_176 | CINEMATIC_HOLO_CONSOLE_DOME_LAMP | medium | 0x3F6C, 5 paths in 30.0x28.5: a blue dome with a cyan highlight and a dark rim, on a narrow dark shaft. Drawn at `x=187, y=101`, 27 pixels from the seated figure, by both routines that compose the console scene |
| CINEMATIC_430 | CINEMATIC_HOLO_SCREEN_POINTER | medium | 0xFBB6, **2 paths** in 16.0x9.0: a pale arrowhead with a swept tail. Its whole routine is `video ... ; break ; jmp`, redrawing it at `x=[0x03], y=[0x04]` |
| CINEMATIC_184 | CINEMATIC_HOLO_SCREEN_POINTER_ON_PLATE | medium | 0xF220, 3 paths in 29.0x14.0: the same arrowhead over a blue parallelogram. Its routine is the twin of 430's and draws at the **same two variables** |

## What these names do not claim

`DOME_LAMP` is a reading of a dome on a stem next to a console; it is graded
`medium` and nothing depends on it. `POINTER` rests on the shape being an
arrowhead and on both loops redrawing it at a pair of variables -- what it
points at is not claimed, and neither is which of the two forms comes first.

Two of INTRO's remaining numbers were looked at in this pass and **not** named;
`notes/HANDOFF.md` records both with their measurements.
