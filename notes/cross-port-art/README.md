# The art is the bridge between ports, never the index

| file | question it answers | command |
| --- | --- | --- |
| `transfer_by_art.py` | Which pictures are named in one priority port and still numbered in the other? | `python3 notes/cross-port-art/transfer_by_art.py` |
| `name_art_agreement.py` | Does a name shared by both ports sit on the **same picture** in each? | `python3 notes/cross-port-art/name_art_agreement.py` |

`docs/NAMING.md` records hazard #0107: the two releases index their art
differently, so a name moved **by index** lands on whatever the other port
keeps at that number. Both modules here bridge on `canonical_md5` instead.

## Transferring

Where one port has a semantic name and the other a bare index on the same
picture, the name transfers. One guard makes it safe: a name carrying a screen
number is only transferred when the receiving port draws that picture **on
that same screen**, checked through `../screen-scope/`. That is not
hypothetical — amiga installs `CAVES_SCREEN_ED_EVENT_PALETTE_FLASH_FRAME` on
screen 0xED and msdos on 0xEE.

It caught three, one of them sharp: amiga's `CINEMATIC_424` is drawn on screen
**0x4D**, and msdos' name for that picture says `SCREEN_6D`. Transferring on
art alone would have written the wrong screen into the tree.

### What it will not transfer, and the one thing left blocked

A `_BACKDROP_LAYER_<i>` name is **never** transferred. That index is the
position in the receiving port's *own* paint sequence, computed by
`../screen-scope/backdrop_phase.py` from that port's entry routine, and it is
not a property of the picture. msdos proves it: amiga's
`CAVES_SCREEN_ED_BACKDROP_LAYER_5` and `_6` are msdos'
`CAVES_SCREEN_EE_BACKDROP_LAYER_4` and `_5` — a different screen *and* a
different position, because msdos has a screen amiga does not. Nine names were
held back on that rule.

After it, six remained: `CINEMATIC_BUDDY_SMASHING_WINDOW_F0..F4` and `F8` in
CAPSULE, refused by the applier as a new family-index gap. That was a guard
doing its job on a case it read slightly wrong — **amiga's own family has
exactly that shape**, F0 through F4 and F8 with no F5, F6 or F7 anywhere,
because the 1991 release has frames the 1992 ports dropped. Transferring it
reproduces a family the tree already accepts.

The fix went into the guard rather than round it
(`another-world-archaeology`, `apply_cinematic_renames.py`): the gaps a
proposal is judged against now include those of the **same family name in the
other branches of the stage**. Reproducing a sibling's shape is not inventing
a gap. The existing `inherited` mechanism could not cover this — it only fires
when every proposed member comes from one source family at the same index, and
a transfer's sources are bare `CINEMATIC_<n>` constants.

Cross-port transfers then went **6 -> 0**, and the fix reached further than
this directory: `../screen-scope/backdrop_phase.py`'s permanently-blocked
batches went **107 -> 70**, because several of those families exist in a
sibling branch with the same holes.

## And the audit that came out of it

The transfer probe kept proposing names the applier refused as *already in
use*, and the reason was worth more than the transfers: msdos already had the
name — on the wrong constant.

`name_art_agreement.py` checks every name that exists in both ports for the
same stage. Measured 2026-09-23:

```
2064  same art in both ports
   6  ** name on the wrong constant
   4  different art, no counterpart -- per-port divergence
```

The six are all in INTRO, and the pattern is unmistakable. For each, msdos'
named constant holds art that amiga calls by a bare number, and amiga's art
sits on a different msdos number a few indices away:

| name | msdos' holder is amiga's | amiga's art is msdos' |
| --- | --- | --- |
| `CINEMATIC_LIFT_SCENE_BG` | `CINEMATIC_533` | `CINEMATIC_535` |
| `CINEMATIC_LIFT_SCENE_VIEW` | `CINEMATIC_528` | `CINEMATIC_530` |
| `CINEMATIC_ACCELERATOR_TUNNEL_VIEW_FAR` | `CINEMATIC_378` | `CINEMATIC_380` |
| `CINEMATIC_ACCELERATOR_TUNNEL_VIEW_NEAR` | `CINEMATIC_243` | `CINEMATIC_255` |
| `CINEMATIC_PARTICLE_LAB_HOLO_CONSOLE` | `CINEMATIC_171` | `CINEMATIC_183` |
| `CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F2` | `CINEMATIC_517` | `CINEMATIC_517` |

A consistent small index offset is the signature of a transfer done on the
number. The last row is the same fault seen from both ends at once — the two
ports' `CINEMATIC_517` hold each other's art.

The other four, in CAPSULE and PASSCODE, are **not** defects: the amiga name's
art is absent from msdos altogether and vice versa, so the ports genuinely
drew different pictures for one role, which is the documented case where the
shared name is the role and the per-port value is that port's art.

Telling the two apart is why the report names the *counterpart* rather than
just the mismatch. A defect has a twin somewhere in the other port; a
divergence does not.
