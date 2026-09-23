# CAPSULE (amiga): the beam ladder's top rung and its single dot

Same ladder, same routine, same measurement as
`proposals_chahi_amiga_1991__PRISON_beam_rungs.md` -- CAPSULE holds it under its
own family word, `CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_*`, with `_0..4` already named
and `_5` and the below-ladder dot still numbered.

    python3 notes/beam-span-ladder/rung_thresholds.py --port amiga --stage CAPSULE

The `0x7E` rung's pair measures 126.0x1.0 against a threshold of 126, and the
fallback below `0x02` is 0.0x1.0 -- a single point on the right slot only, which
PRISON already names `..._SINGLE_DOT`. `same_widget.py --hash` puts all three
drawings in PRISON, CAVES and CAPSULE alike: `f255ec0fe650` and `af939a63c5d8`
are the 126 pair everywhere, `a67e39b01c82` the dot.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_528 | CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_RIGHT_5 | high | 0x196A, 126.0x1.0 in 1 leaf at `x=[0x21]`, the `jl [0x26], 0x7E` rung; sixth of the array at 0x1906 + 0x14k |
| CINEMATIC_529 | CINEMATIC_CAPSULE_SHOT_BEAM_SPAN_LEFT_5 | high | 0x3ACE, 126.0x1.0 at `x=[0x22]`, extending left in the same rung; sixth of the array at 0x3AA6 + 8k |
| CINEMATIC_513 | CINEMATIC_CAPSULE_SHOT_BEAM_SINGLE_DOT | high | 0x18F2, 0.0x1.0 in 1 leaf, `a67e39b01c82` -- the same drawing as `CINEMATIC_PRISON_SHOT_BEAM_SINGLE_DOT`, in the same fallback slot |
