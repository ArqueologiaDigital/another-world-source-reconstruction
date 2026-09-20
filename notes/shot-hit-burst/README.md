# CAPSULE's hit-burst: 20 names, taken from PRISON's answer

Closing one of the 73 family gaps in `../family-gaps/`, at the constant
layer.

## What was stuck

`CAPSULE_SHOT_STATE_FRAME_RIGHT_ABOVE_{01,02,04}` and
`CAPSULE_SHOT_IMPACT_SPARK_RIGHT_PHASE_{1,4}` — five routines for one
animation under two naming conventions, each with holes. The validator
refused every constant derived from them, because a gapped family may not
propagate (NAMING.md §2).

## PRISON had already solved it

The same five frames in PRISON carry a complete, gap-free constant family,
`CINEMATIC_PRISON_SHOT_HIT_BURST_{LEFT,RIGHT}_0..4` — even though *its*
routine names are split the same way (`FRAME_1`, `ABOVE_01`, `ABOVE_02`,
`FRAME_4`, `ABOVE_04`). The constants were unified there and the routines
were left alone, which is the pattern to copy.

Measured, in offset order, identically in both stages:

    2x5/6  ->  9x10/6  ->  17x12/7  ->  17x17/6  ->  16x17/4

A spark expanding and then thinning — the leaf count rises to 7 and falls to
4 as it fades.

## Matched by art, not by index

`canonical_md5` over the whole parsed tree, against PRISON's earned family:
**10 of 10 in each priority port**. The indices are not transferable and
would have been wrong in one port:

    amiga   RIGHT 492..496   LEFT 507..511
    msdos   RIGHT 638..642   LEFT 654..658

At amiga's numbers msdos holds unrelated art — `CINEMATIC_492` there is
404x114/6, not a 2x5 spark — which is #0107 exactly, and why the match is
made on the bytes.

## Distinct from the burst already named

CAPSULE already has `CINEMATIC_CAPSULE_SHOT_IMPACT_BURST_{LEFT,RIGHT}_0..8`:
a *large* burst, 54x68 down to 20x1, 7 to 26 leaves, living at 0x2EEE and
after. These five are the small spark at 0x2DBC. Two animations, two
families, and the new name follows PRISON's word (`HIT_BURST`) so the
distinction survives.

## Applied

`CINEMATIC_CAPSULE_SHOT_HIT_BURST_{LEFT,RIGHT}_0..4` in amiga and msdos, 20
names, both runs complete 0..4. `make test` 29/29 and 29/29,
`undefined_symbols.py` clean, `--duplicates` still one name per picture.

The **routine** families stay split — `..._ABOVE_01` beside
`..._IMPACT_SPARK_PHASE_1` — exactly as PRISON leaves them. Unifying those
overrides earned names and is a separate decision; naming the constants does
not require it, which is the point PRISON's example makes.
