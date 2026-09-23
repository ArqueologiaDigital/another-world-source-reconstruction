# PRISON: the last two rungs of the beam-span ladder

## The ladder, and why the rung index is not a guess

`<branch>__post_COPY_VAR27_TO_VAR07.inc` -- the same file name in PRISON, CAVES
and CAPSULE -- draws a shot as a pair of 1-pixel-tall horizontal bars, one
extending right from `[0x21]` and one extending left from `[0x22]`, chosen from
a ladder by the span between them:

    [0x26] = [0x22] - [0x21]
    jl [0x26], 0x7E -> ...        ; 126
    ...
    jl [0x26], 0x1E -> ...        ; 30
      video SPAN_RIGHT_3, x=[0x21]
      video SPAN_LEFT_3,  x=[0x22]

The thresholds are `0x02, 0x06, 0x0E, 0x1E, 0x3E, 0x7E` = 2, 6, 14, 30, 62, 126,
each `2n + 2` of the one below, and **each equals the drawn width of the pair it
selects**. PRISON's `_0..3` are already named and all four measure exactly their
threshold. The two rungs above them are still numbered.

    python3 notes/beam-span-ladder/rung_thresholds.py --port amiga --stage PRISON

```
  span >= 0x7e    bit 0  R CINEMATIC_520  ok   L CINEMATIC_521  ok
  span >= 0x64    bit 0  R CINEMATIC_514  ok   L CINEMATIC_515  ok
  span >= 0x3e           R CINEMATIC_514  ok   L CINEMATIC_515  ok
  span >= 0x1e           R ..._SPAN_RIGHT_3  ok   L ..._SPAN_LEFT_3  ok
```

(`ok` is that measurement: 520 and 521 are 126.0x1.0, 514 and 515 are 62.0x1.0.
The `0x64` rung reuses the 62 pair, there being no 100-wide art.)

Three further agreements, each independent of the others:

**The offsets are one array.** amiga and msdos hold the right-hand rungs at
`0x4D72, 0x4D86, 0x4D9A, 0x4DAE, 0x4DC2, 0x4DD6` -- stride 0x14, six in a row --
and the left-hand rungs at `0x7FD0 .. 0x7FF8`, stride 8. 514 and 520 are members
4 and 5 of the first; 515 and 521 of the second. Cartridge has the same two
arrays at `0x4960 + 0x14k` and `0x7992 + 8k`, which is why its rows are here too
although its ROM is not extracted (#0106).

**Two other stages already made the same call.** `same_widget.py --hash` finds
514's drawing under `CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_4` and
`CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_RIGHT_4`, and 515's under both stages'
`..._LEFT_4`, at those stages' own offsets. Same for the `_0..3` rungs, all
eight byte-identical across the three stages.

**The sides.** 514 and 520 are drawn at `x=[0x21]` and extend right from the
anchor (`M222 99.5 ... L160 100.5`); 515 and 521 at `x=[0x22]` and extend left
(`M160 99.5 ... L98 100.5`), matching `_0..3`.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_514 | CINEMATIC_PRISON_SHOT_BEAM_SPAN_RIGHT_4 | high | 0x4DC2, 62.0x1.0 in 1 leaf, drawn at `x=[0x21]` by the `jl [0x26], 0x3E` rung -- threshold 62, width 62. Fifth of the six-member array at 0x4D72 + 0x14k, and the same drawing as CAVES' and CAPSULE's `..._SPAN_RIGHT_4` |
| CINEMATIC_515 | CINEMATIC_PRISON_SHOT_BEAM_SPAN_LEFT_4 | high | 0x7FF0, 62.0x1.0, drawn at `x=[0x22]` in the same rung, extending left. Fifth of the array at 0x7FD0 + 8k |
| CINEMATIC_520 | CINEMATIC_PRISON_SHOT_BEAM_SPAN_RIGHT_5 | high | 0x4DD6, 126.0x1.0, drawn at `x=[0x21]` by the `jl [0x26], 0x7E` rung -- threshold 126, width 126. Sixth of the same array |
| CINEMATIC_521 | CINEMATIC_PRISON_SHOT_BEAM_SPAN_LEFT_5 | high | 0x7FF8, 126.0x1.0, drawn at `x=[0x22]` in the same rung. Sixth of the left array |

## What is left numbered, and why

`CINEMATIC_516, 517, 518, 519` are a **second set at 62 and 126 only**, selected
when bit 0x2000 of the shot's state word `[0x12]` is set --
`amiga__post_STEP_VAR29_DOWN10_SET_VAR2F_11.inc` sets it for the scripted beam
drawn between `[BUDDY_X]` and `[HERO_X]`. They are the same two widths in a
different colour index (`#fb6487` against `#a74400` at palette 2), and they sit
outside both arrays, at 0x800C, 0x8002, 0x9A38 and 0x9A40.

That much is established. What the bit *means* is not, and a colour word under a
palette that varies is not a name, so they keep their numbers. Naming them wants
the meaning of `[0x12]`'s bit 0x2000, which is a different job.
