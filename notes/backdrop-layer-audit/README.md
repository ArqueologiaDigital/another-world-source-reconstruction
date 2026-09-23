# A backdrop layer name promises two things

## What question this answers

`notes/backdrop-drawer/` names a screen's pieces from the routine that paints
it: `<STAGE>_SCREEN_<HH>_BACKDROP_DRAW` is a `fill` followed by N pictures, so
picture i is `CINEMATIC_<STAGE>_SCREEN_<HH>_BACKDROP_LAYER_i`. The name claims
**this routine draws it**, and **its siblings run in order**.

    python3 notes/backdrop-layer-audit/layer_claims.py
    python3 notes/backdrop-layer-audit/layer_claims.py --kind MISSING

Neither claim is checked by the byte gate, because a rename moves no bytes.

## Why it exists

`../render-and-name/correction_capsule_6a_layer0.md` found one such name on the
wrong constant by accident. Then the cross-port transfer probe offered to copy
`CAPSULE_SCREEN_8A_BACKDROP_LAYER_2` from msdos into amiga on a byte-identical
polygon tree -- correct by that probe's own criterion, and wrong, because msdos'
routine is

    CAPSULE_SCREEN_8A_BACKDROP_DRAW:
        fill page=0x00, color=0x00
        video offset=CINEMATIC_CAPSULE_SCREEN_8A_BACKDROP_LAYER_0, x=160, y=100
        ret

one layer, not three.

> A transfer probe propagates a name without ever asking whether the name is
> right. Audit the family before spreading it.

The offered transfer was reverted rather than applied.

## The index is deliberately not checked against position

`PRISON_SCREEN_24_BACKDROP_DRAW` draws `LAYER_8, 9, 10, 11` and nothing else --
its first eight come from the `PRISON_BACKDROP_TILE_REPEAT_DOWN` it calls first
-- so position 0 legitimately carries index 8. A first version of this probe
compared index to position and called **30** such rows wrong. What a name really
claims about order is that siblings run increasing, and that is what
`OUT OF ORDER` tests.

## Run of 2026-09-23

```
   253  ok
     0  OUT OF ORDER
     3  MISSING
    62  NO ROUTINE
```

`NO ROUTINE` is 62 screens whose painter is still a bare `LABEL_xxxx`: a
labelling job, not a wrong name.

The three defects, all msdos, all open:

| name | what it really is |
|---|---|
| `CAPSULE_SCREEN_8A_BACKDROP_LAYER_1` | 0x285E, 6.0x70.0 in 5 leaves; the 8A routine does not draw it |
| `CAPSULE_SCREEN_8A_BACKDROP_LAYER_2` | 0x1C0C, 6.0x70.0 in **1** leaf, drawn five times at actor anchors -- `[0x26], [BUDDY_Y]` and `[BUDDY_X], [BUDDY_Y]`, once into page 0 and once into the visible page |
| `CAVES_SCREEN_ED_BACKDROP_LAYER_0` | 0xF246; the ED routine's first draw is `CINEMATIC_759` |

The CAVES ED row is not a one-line fix, and finding that out is worth as much as
fixing it would have been. amiga's routine draws nine layers -- five at
`160, 100` then four placed at `(309,42), (308,57), (303,72), (296,23)`. msdos'
draws **four** at `160, 100`, then `(296,23), (298,66), (260,88), (326,82)` and a
fifth at `160, 100`. Same screen, different composition, so `LAYER_n` does not
mean the same n in both ports and the art-identity transfer that offered
`760 -> LAYER_1, 761 -> LAYER_2, 762 -> LAYER_3, 764 -> LAYER_7, 763 -> LAYER_8`
would have put position 4 under the name `LAYER_8`. The rename validator's
family-gap rule refused the batch, which was the right answer for a reason
neither probe knew.

`notes/backdrop-drawer/README.md` had already recorded this shape for msdos
CAVES' ED layers as an observation about one screen -- "those names already
claim an exclusivity they do not have". This makes it a measurement over all
288 of them.
