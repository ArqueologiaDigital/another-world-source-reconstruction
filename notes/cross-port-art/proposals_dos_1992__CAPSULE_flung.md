# CAPSULE (msdos): the flung-figure run, completed by draw position

`transfer_by_art.py` reported 11 transferable names into dos/CAPSULE. Four of
them are this family and they are taken here; the other seven are refused, for
a reason worth writing down.

## The four the hash found, and the fifth it could not

amiga's `LABEL_098B` and msdos's `LABEL_1939` open with the same run:

```
  amiga   FLUNG_F0  FLUNG_F1  FLUNG_F2  FLUNG_F3  FLUNG_F4  CINEMATIC_433
  msdos       547       516       517       548       549   CINEMATIC_526
```

Position for position. The hash matched 547, 516, 548 and 549 to F0, F1, F3 and
F4 but not 517 to F2, so a transfer alone would have left the run
`{0, 1, 3, 4}` -- a family with a hole in it. The draw position supplies the
missing member, and the run closes.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_547 | CINEMATIC_CAPSULE_FIGURE_FLUNG_F0 | high | same `canonical_md5` as amiga's `..._FLUNG_F0`, and first in `LABEL_1939` where amiga's `LABEL_098B` draws F0 |
| CINEMATIC_516 | CINEMATIC_CAPSULE_FIGURE_FLUNG_F1 | high | same `canonical_md5` as amiga's `..._FLUNG_F1`, and second in the same run |
| CINEMATIC_517 | CINEMATIC_CAPSULE_FIGURE_FLUNG_F2 | high | **no hash twin**; third in the run where amiga draws F2, between two constants the hash confirms as F1 and F3 |
| CINEMATIC_548 | CINEMATIC_CAPSULE_FIGURE_FLUNG_F3 | high | same `canonical_md5` as amiga's `..._FLUNG_F3`, fourth in the run |
| CINEMATIC_549 | CINEMATIC_CAPSULE_FIGURE_FLUNG_F4 | high | same `canonical_md5` as amiga's `..._FLUNG_F4`, fifth in the run |

## Why the other seven are refused

They are pose names -- `CINEMATIC_CAPSULE_FIGURE_POSE_0_1`,
`..._POSE_RIGHT_4_1` and five more -- and **a pose name must never be
transferred by art.** It records the `(group, index)` slot *that port's own
dispatcher* selects the picture with (`notes/pose-dispatch/`), which is a fact
about the port's bytecode, not a property of the drawing. msdos already has its
own constants in those slots, named from its own dispatcher; giving the same
names to different constants that merely share amiga's art would put one name
on two pictures in one stage.

`transfer_by_art.py` cannot see this -- it reasons about art, and by art the
match is real. The rule belongs with the reader: **transfer a name only if it
describes the picture. A dispatch index does not.**
