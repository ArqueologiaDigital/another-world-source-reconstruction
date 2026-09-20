# The actor's sprite sheet: 40 names, and no character claimed

The 148 shared-bank offsets drawn at the shared actor record. #0138 bars
saying **which character** they are; it does not bar saying what pose they are
in, and the older `CV_FIGURE_CROUCH_FACING_LEFT` names are that distinction
already applied.

## Why no character may be claimed — in the tree, not by precaution

One eight-frame run is called, by three stages that did not consult each
other:

    CAPSULE_BUDDY_WALK_RIGHT_DRAW_0
    CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_1
    CAVES_HERO_WALK_RIGHT_PHASE_2

Buddy, actor and hero — for one picture. The stages **disagree about the
character and agree about the motion, the direction and the frame**. The names
carry what they agree on: `CV_FIGURE_WALK_RIGHT_BODY_F00`.

Rendered, the run is a lower body walking in profile: five leaves, 57 units
tall, width swinging 16→38 as the stride opens and closes.

## What it took, in order

Four things had to be right together. Each was tried alone first and each
alone made the tables *worse*, which is why they are listed as one step.

1. **The index base follows the stage** — CAPSULE 0, PRISON 0, CAVES 1 —
   measured by `../shared-bank-geometry/phase_base_calibration.py`, not
   guessed from the spelling.
2. **The calibration reference must start at 0**, not merely be well
   attested. Three stages each claim 16 frames, so picking by count was a
   coin toss, and landing on the 1-based one shifted the others up.
3. **A terminal word does not stop digits being an ordinal.**
   `BUDDY_WALK_LEFT_DRAW_3_DONE` and `ACTOR_RUN_RIGHT_PHASE_1_FRAME` are
   frames 3 and 1. Anchoring at end-of-string dropped every CAPSULE and
   PRISON claim in walk-left, leaving CAVES as its own reference — which is
   where an index 16 inside a 0..15 run came from.
4. **An offset one stage calls several frames is a shared sub-piece.** 35 of
   203 (offset, stage) pairs, 17 %: `CV_2D56` is `BUDDY_WALK_LEFT_DRAW_8`
   *and* `DRAW_9` in CAPSULE. One small polygon reused across frames is not a
   frame. They are excluded from the calibration and from any indexed name;
   without that, admitting (3) feeds them into the pairwise difference and
   the whole walk-left family is rejected.

## Two frames placed by position, and why that is safe here

`WALK_LEFT` and `WALK_RIGHT` each came out complete but for frame 7.

| family | gap | candidates in the gap | chosen |
|---|---|---|---|
| WALK_LEFT | F07, between `0x287E` and `0x296E` | **one**: `CV_28F8`, 24x57/5 | forced |
| WALK_RIGHT | F07, between `0x19C4` and `0x1D78` | eleven, but only one at 5 leaves / 57 tall: `CV_1A0E`, 24x57/5 | forced by geometry |

The other ten candidates in walk-right's gap are a different series entirely —
2-leaf shapes 30 to 33 tall — so the family's own geometry picks one offset
without ambiguity.

## What was refused

- `CV_FIGURE_RUN_RIGHT_BODY_F08`, claimed by `CV_2364` (40x54/5) **and**
  `CV_2380` (41x56/5). Two interleaved naming series overlap at exactly that
  frame and nothing measured says which is right, so **both** are dropped
  (#0120). The family is applied as 0..7, contiguous.
- All three LIMB families: `WALK_RIGHT_LIMB` has only frames 0 and 5,
  `WALK_LEFT_LIMB` 5 and 7, `RUN_RIGHT_LIMB` 0, 1 and 4. Gaps inside a run
  are barred by NAMING.md §2, and these are mostly shared sub-pieces that
  have no frame number at all.

## The 40

    CV_FIGURE_WALK_RIGHT_BODY_F00..F15    16
    CV_FIGURE_WALK_LEFT_BODY_F00..F15     16
    CV_FIGURE_RUN_RIGHT_BODY_F00..F07      8

Applied with `../shared-bank-naming/apply_bank_names.py --map`.

Verified: `make test` 29/29 and 29/29; `undefined_symbols.py` clean;
`bank_name_offset_consistent.py --map actor_walk_run.map` reports all 40 at
the offset their key encoded, and 0 actionable duplicate names; `--sides` and
`--duplicates` unchanged. Shared-bank offset keys 279 → **239**. Asset layer
43.6 % → **46.3 %**.
