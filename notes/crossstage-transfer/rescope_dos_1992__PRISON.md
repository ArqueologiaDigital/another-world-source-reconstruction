# PRISON: drop `PRISON_` from art that is in three stages

Twenty-four names given a few hours ago by `../render-and-name/` turn out to
describe art that is **byte-identical in PRISON, CAVES and CAPSULE**, in both
priority ports. `notes/crossstage-transfer/transfer_across_stages.py --held`
lists 56 amiga and 59 msdos candidates it will not transfer because "name
carries another stage's prefix", and these are most of them:

```
  CINEMATIC_PRISON_BLAST_DEBRIS          -> CAPSULE CAVES
  CINEMATIC_PRISON_BLAST_DEBRIS_SETTLED  -> CAPSULE CAVES
  CINEMATIC_PRISON_BLAST_MARK            -> CAPSULE CAVES
  CINEMATIC_PRISON_FALLING_DEBRIS        -> CAPSULE CAVES
  CINEMATIC_PRISON_HERO_STAND_AIM_RIGHT  -> CAPSULE CAVES
  CINEMATIC_PRISON_XRAY_*                -> CAPSULE CAVES
```

`../crossstage-transfer/README.md` sets out the three conditions for removing
a stage word rather than re-prefixing it, and every row below meets them:

1. **The stage word is not part of the subject.** Falling debris, a blast
   mark, an x-ray flash and a hero's aim pose are not places. Compare
   `CINEMATIC_CAVES_FIRST_ROOM_BG`, which is held for exactly this reason.
2. **No screen number.** The three `CAPSULE_SCREEN_*_BACKDROP_LAYER` and one
   `CAVES_SCREEN_EE_BACKDROP_LAYER` candidates in the same list are held on
   this condition and stay held.
3. **The prefix being dropped is not an earned name.** Every one of these is
   mine, from this session, given before the CAVES and CAPSULE copies were
   looked for. `CINEMATIC_PRISON_SHOT_BEAM_SINGLE_DOT` is in the same list,
   qualifies on 1 and 2, and is **held** because its `PRISON_` is somebody
   else's.

Dropping the word invents nothing: the evidence for every one of these names
is unchanged and is in the batch that gave it, and `PRISON_` was a claim about
scope that the art has now refuted.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_PRISON_BLAST_DEBRIS_F0 | CINEMATIC_BLAST_DEBRIS_F0 | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_BLAST_DEBRIS_F1 | CINEMATIC_BLAST_DEBRIS_F1 | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_BLAST_DEBRIS_F2 | CINEMATIC_BLAST_DEBRIS_F2 | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_BLAST_DEBRIS_F3 | CINEMATIC_BLAST_DEBRIS_F3 | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_BLAST_DEBRIS_F4 | CINEMATIC_BLAST_DEBRIS_F4 | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_BLAST_DEBRIS_F5 | CINEMATIC_BLAST_DEBRIS_F5 | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_BLAST_DEBRIS_SETTLED_0 | CINEMATIC_BLAST_DEBRIS_SETTLED_0 | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_BLAST_DEBRIS_SETTLED_1 | CINEMATIC_BLAST_DEBRIS_SETTLED_1 | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_BLAST_MARK | CINEMATIC_BLAST_MARK | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_FALLING_DEBRIS_F0 | CINEMATIC_FALLING_DEBRIS_F0 | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_FALLING_DEBRIS_F1 | CINEMATIC_FALLING_DEBRIS_F1 | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_FALLING_DEBRIS_F2 | CINEMATIC_FALLING_DEBRIS_F2 | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_FALLING_DEBRIS_F3 | CINEMATIC_FALLING_DEBRIS_F3 | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_FALLING_DEBRIS_F4 | CINEMATIC_FALLING_DEBRIS_F4 | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_FALLING_DEBRIS_F5 | CINEMATIC_FALLING_DEBRIS_F5 | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_FALLING_DEBRIS_F6 | CINEMATIC_FALLING_DEBRIS_F6 | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_FALLING_DEBRIS_F7 | CINEMATIC_FALLING_DEBRIS_F7 | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_HERO_STAND_AIM_RIGHT | CINEMATIC_HERO_STAND_AIM_RIGHT | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_XRAY_FLASH_LEFT | CINEMATIC_XRAY_FLASH_LEFT | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_XRAY_FLASH_RIGHT | CINEMATIC_XRAY_FLASH_RIGHT | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_XRAY_SKELETON_LEFT_DARK | CINEMATIC_XRAY_SKELETON_LEFT_DARK | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_XRAY_SKELETON_LEFT_LIT | CINEMATIC_XRAY_SKELETON_LEFT_LIT | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_XRAY_SKELETON_RIGHT_DARK | CINEMATIC_XRAY_SKELETON_RIGHT_DARK | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |
| CINEMATIC_PRISON_XRAY_SKELETON_RIGHT_LIT | CINEMATIC_XRAY_SKELETON_RIGHT_LIT | high | `canonical_md5` matches a constant in CAVES **and** in CAPSULE, both priority ports. The art is not stage-specific, so the stage word is wrong rather than merely untransferable |

## What this does not do

It does not re-prefix. No name here gains `CAVES_` or `CAPSULE_`; the stage
word is removed and not replaced, which is the only move that invents nothing.

It does not rescope anyone else's name.
`CINEMATIC_PRISON_SHOT_BEAM_SINGLE_DOT`, `CINEMATIC_CAVES_CREATURE_WALK_RIGHT`
and `CINEMATIC_CAVES_DROPPED_GUN` are in the same held list and stay there.
