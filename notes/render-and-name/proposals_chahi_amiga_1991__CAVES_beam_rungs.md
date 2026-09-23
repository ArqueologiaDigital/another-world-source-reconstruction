# CAVES: the beam ladder's top rung and its single dot

Same ladder, same routine, same measurement as
`proposals_chahi_amiga_1991__PRISON_beam_rungs.md` -- CAVES holds it under its
own family word, `CINEMATIC_CAVES_LASER_BOLT_SPAN_*`, with `_0..4` already
named and `_5` and the below-ladder dot still numbered.

    python3 notes/beam-span-ladder/rung_thresholds.py --port amiga --stage CAVES

```
  span >= 0x7e    bit 0  R CINEMATIC_837  ok   L CINEMATIC_838  ok
  span >= 0x3e           R ..._SPAN_RIGHT_4  ok   L ..._SPAN_LEFT_4  ok
  ...
  span >=   --           R CINEMATIC_822  w=0  (below the ladder)
```

`ok` is the measurement: the `0x7E` rung's pair is 126.0x1.0, matching its
threshold of 126, and the fallback below `0x02` is 0.0x1.0 -- a single point,
drawn on the right slot only, which PRISON already names `..._SINGLE_DOT`.

`same_widget.py --hash` puts all three drawings in PRISON and CAPSULE as well,
at those stages' own offsets: `f255ec0fe650` and `af939a63c5d8` are the 126 pair
everywhere, `a67e39b01c82` the dot.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_837 | CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_5 | high | 0x1762, 126.0x1.0 in 1 leaf, drawn at `x=[0x21]` by the `jl [0x26], 0x7E` rung -- threshold 126, width 126. Sixth of the array at 0x16FE + 0x14k |
| CINEMATIC_838 | CINEMATIC_CAVES_LASER_BOLT_SPAN_LEFT_5 | high | 0x37C8, 126.0x1.0, drawn at `x=[0x22]` in the same rung, extending left. Sixth of the array at 0x37A0 + 8k |
| CINEMATIC_822 | CINEMATIC_CAVES_LASER_BOLT_SINGLE_DOT | high | 0x16EA, 0.0x1.0 in 1 leaf, `a67e39b01c82` -- the same drawing as `CINEMATIC_PRISON_SHOT_BEAM_SINGLE_DOT`, drawn in the same fallback slot below the ladder's lowest threshold |
