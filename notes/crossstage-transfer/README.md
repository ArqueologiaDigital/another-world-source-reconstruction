# Carrying a name between stages, not just between ports

`../crossport-transfer/` moves a name between **ports** when the art is
byte-identical. The same move works between **stages of one port**, and
nothing was doing it — the cinematic banks share art, and a picture
identified in CAVES is the same picture in PRISON.

`../shot-hit-burst/` is what prompted it: CAPSULE's five-frame spark was
stuck behind a routine-family gap while PRISON had the identical five frames
under a complete constant family. Transferring by `canonical_md5` named all
ten. That was done by hand; `transfer_across_stages.py` generalises it.

## Most candidates are not usable, and the reasons are the interesting part

Matching alone gives 49 on amiga and 46 on msdos. What survives is 9.

| held | why |
|---:|---|
| 36 / 34 | **the name carries another stage's prefix.** `CINEMATIC_CAVES_TELEPORT_DOWN_BEAM` moved into PRISON asserts CAVES inside PRISON. The art travels between stages; the stage word does not. Held rather than rewritten — stripping `CAVES_` and re-prefixing invents a name nobody earned. |
| 35 / 36 | the art matches two or more *different* names elsewhere, so there is nothing to transfer (#0120) |
| 6 / 7 | **several constants in the target stage match one name** (#0118). Six amiga/INTRO constants are byte-identical to `CINEMATIC_DROPLET_FALL_TRAIL`; one name cannot go on six. |
| 2 | **referenced from an all-branch chunk.** The `EQU` is renamed per branch, and an unprefixed `_unified/<stage>/*.inc` is read by every branch — so renaming amiga's and msdos's definitions while cartridge keeps `CINEMATIC_555` leaves that shared reference undefined for the two that moved. Found by applying it: verify-unified **27/29**, two undefined, while verify-stages stayed 29/29 because each canonical file was internally consistent. |
| 1 | on `disputed.txt` — `CINEMATIC_BUDDY_SMASHING_WINDOW_F8`, whose own subject is unsettled. Transferring it would spread the dispute. |

## The 9

    amiga/CAPSULE   CINEMATIC_114 -> CINEMATIC_HERO_LIFTOFF
    amiga/CAVES     CINEMATIC_170 -> CINEMATIC_HERO_LIFTOFF
    amiga/PASSCODE  CINEMATIC_037 -> CINEMATIC_OK_BUTTON
    amiga/PASSCODE  CINEMATIC_038 -> CINEMATIC_DEL_BUTTON
    amiga/PRISON    CINEMATIC_568 -> CINEMATIC_HERO_LIFTOFF
    msdos/CAVES     CINEMATIC_170 -> CINEMATIC_HERO_LIFTOFF
    msdos/PASSCODE  CINEMATIC_037 -> CINEMATIC_OK_BUTTON
    msdos/PASSCODE  CINEMATIC_038 -> CINEMATIC_DEL_BUTTON
    msdos/PRISON    CINEMATIC_568 -> CINEMATIC_HERO_LIFTOFF

`make test` 29/29 and 29/29, `undefined_symbols.py` clean, `--duplicates`
still one name per picture.

That the same 9 come out of both ports independently, at the same constant
numbers, is itself a check: these are stage-shared pictures in both releases.
