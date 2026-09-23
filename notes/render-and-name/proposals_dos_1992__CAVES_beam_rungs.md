# CAVES (msdos): the beam ladder's top rung and its single dot

Same ladder, same routine, same measurement as
`proposals_chahi_amiga_1991__PRISON_beam_rungs.md` -- CAVES holds it under its
own family word, `CINEMATIC_CAVES_LASER_BOLT_SPAN_*`, with `_0..4` already named
and `_5` and the below-ladder dot still numbered.

    python3 notes/beam-span-ladder/rung_thresholds.py --port msdos --stage CAVES

The `0x7E` rung's pair measures 126.0x1.0 against a threshold of 126, and the
fallback below `0x02` is 0.0x1.0 -- a single point on the right slot only, which
PRISON already names `..._SINGLE_DOT`. `same_widget.py --hash` puts all three
drawings in PRISON, CAVES and CAPSULE alike: `f255ec0fe650` and `af939a63c5d8`
are the 126 pair everywhere, `a67e39b01c82` the dot.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_861 | CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_5 | high | 0x15B6, 126.0x1.0 in 1 leaf at `x=[0x21]`, the `jl [0x26], 0x7E` rung; same `canonical_md5` as amiga's `CINEMATIC_837` |
| CINEMATIC_862 | CINEMATIC_CAVES_LASER_BOLT_SPAN_LEFT_5 | high | 0x361C, 126.0x1.0 at `x=[0x22]`, extending left; same `canonical_md5` as amiga's `CINEMATIC_838` |
| CINEMATIC_846 | CINEMATIC_CAVES_LASER_BOLT_SINGLE_DOT | high | 0x153E, 0.0x1.0 in 1 leaf, `a67e39b01c82`, in the same fallback slot |
