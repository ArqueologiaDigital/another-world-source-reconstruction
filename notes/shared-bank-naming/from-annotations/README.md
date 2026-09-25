# Shared-bank names earned from annotations

The shared bank is one file, byte-identical on both priority ports, so
`../apply_bank_names.py` renames globally rather than per branch. These names
came from a person playing `dos_1992/PRISON` and describing what they clicked,
with the family and the index taken from the bytecode as always
(`../../play-and-describe/README.md`).

**Why these needed a note of their own.** `annotation_queue.py` prints
"SHARED BANK - no applier" beside a `CV_*` target, which is true of
`apply_cinematic_renames.py` and misleading overall: `../apply_bank_names.py`
exists precisely for this. The message is corrected; this directory is where the
tables live.

## 2026-09-25, PRISON

### `CV_2D4E` -> `CV_FIGURE_WALK_LEFT_LIMB_POSE_04`
### `CV_245C` -> `CV_FIGURE_WALK_RIGHT_LIMB_POSE_04`

`ann:c96a942281e4` (f183): "right arm of the guard, while he's walking to the
left." `ann:4824c77baf8a` (f220): "left arm of the guard slightly tilted
forwards while the guard walks to the right".

Both are members of families that already exist, and the geometry says so
without ambiguity:

    CV_FIGURE_WALK_RIGHT_LIMB_POSE_02   11.0 x 17.0  1 leaf  x[-0.5, 10.5] y[-39.5,-22.5]
    CV_245C                             11.0 x 17.0  1 leaf  x[-0.5, 10.5] y[-39.5,-22.5]
    CV_2D4E                             11.0 x 17.0  1 leaf  x[-11.5,-0.5] y[-39.5,-22.5]

`CV_245C` has the **same bounding box, the same one-leaf structure and the same
y-band** as `LIMB_POSE_02` of its own family -- a different picture in an
identical envelope. `CV_2D4E` is that box mirrored, in the left-facing family.

The position in the cycle is mirrored too. On the right, the limb layer drawn
behind the body runs `_00, _01, _02, ?, _03, _03, _02, _01` across walk phases
00, 05, 06, **07**, 08, 09, 10, 11, and `CV_245C` fills the gap at phase 07. On
the left the same gap sits between `_02` (`INLINE_DRAW_CV_220_008`) and `_03`
(`INLINE_DRAW_CV_228_018`), and `CV_2D4E` fills it.

`_04` rather than an insertion: these families index **distinct limb pictures**,
reused across several phases, not phases. `_00.._03` are committed, so the fifth
distinct picture is `_04`. Renumbering to put it "in order" would rename four
committed names to express something the index does not claim.

At walk-left phase 07 the choice is `je [0x0D], 0x00, DRAW_CV224_AT_X07_Y08`, so
`_04` is drawn when `[0x0D]` is zero and `_02` otherwise -- `[0x0D]` being what
`SPLIT_VAR09_BITS_INTO_VAR0D` unpacks from the actor record. So it is a variant
at that phase, which is what a pose id can carry and a phase number could not.

No actor word: the person says guard, `../../actor-anchors/` records why that is
not admissible from this anchor, and the whole shared bank keeps `CV_FIGURE_*`
for the same reason.

### `CV_4346` -> `CV_FIGURE_STAND_BODY`

`ann:7f8c38c5271b` (f3114): "lester's body".

    CV_FIGURE_WALK_LEFT_BODY_F00   33.5 x 57.0  5 leaves  y[-56.0, 1.0]
    CV_4346                        30.5 x 57.0  5 leaves  y[-56.0, 1.0]

The **same height, the same y-band and the same leaf count** as a walk-cycle
body, three pixels narrower: a full standing figure, not a limb. It is drawn at
four sites, three of them in routines that then do
`sub [ACTOR_Y], 0x000D` / `call LABEL_5234` / `add [ACTOR_Y], 0x000D` -- an
upper layer placed thirteen pixels higher -- and in each the head dispatcher runs
first. So it is the body layer of a standing figure with a separate head and
overlay, and it belongs to no walk cycle: four sites, none of them a numbered
phase.

`STAND` against the bank's existing `CV_FIGURE_PROFILE_STANCE` and
`CV_FIGURE_PROFILE_STRIDE`: those two are profile art, this is the body a head
is composited onto, so it takes `BODY` like the walk bodies it measures with.

The person names Lester. That is not in the name, for the reason the whole bank
is generic: one shared-bank picture serves every port and, here, more than one
figure.


## The rows, in the form the queue can read

`annotation_queue.py` derives "consumed" from `annot:<id>` tokens in proposal
**rows** plus the name being defined in the tree. A `.map` file has two columns
and no evidence cell, so a shared-bank name applied from one could never be
marked consumed however well it was argued -- the annotation would sit OPEN
forever beside a constant that already carries its name.

This table is the citation, in the four columns the scanner parses. It is a
record rather than an input: the map above is what `apply_bank_names.py` reads.

| old | new | confidence | evidence |
|---|---|---|---|
| CV_2D4E | CV_FIGURE_WALK_LEFT_LIMB_POSE_04 | high | 0x2D4E, 11.0x17.0 in ONE leaf at x[-11.5,-0.5] y[-39.5,-22.5] -- the mirror of the box CV_FIGURE_WALK_RIGHT_LIMB_POSE_02 occupies, in the left-facing family; fills the phase-07 gap in the left limb run whose neighbours are `_02` (INLINE_DRAW_CV_220_008) and `_03` (INLINE_DRAW_CV_228_018), selected there by `je [0x0D], 0x00`; `_04` because the family indexes distinct limb pictures and `_00.._03` are committed; annot:c96a942281e4 frame 183, "right arm of the guard, while he's walking to the left" -- the guard reading is recorded here and not in the name |
| CV_245C | CV_FIGURE_WALK_RIGHT_LIMB_POSE_04 | high | 0x245C, 11.0x17.0 in ONE leaf at x[-0.5,10.5] y[-39.5,-22.5] -- the same bounding box, leaf count and y-band as CV_FIGURE_WALK_RIGHT_LIMB_POSE_02, a different picture in an identical envelope; drawn immediately before CV_FIGURE_WALK_RIGHT_BODY_F07 in PRISON_ACTOR_WALK_RIGHT_DRAW_PHASE_07, filling the gap in the run _00,_01,_02,?,_03,_03,_02,_01 across phases 00,05,06,07,08,09,10,11; annot:4824c77baf8a frame 220, "left arm of the guard slightly tilted forwards while the guard walks to the right" |
| CV_4346 | CV_FIGURE_STAND_BODY | high | 0x4346, 30.5x57.0 in 5 leaves at y[-56.0,1.0] -- the same height, y-band and leaf count as CV_FIGURE_WALK_LEFT_BODY_F00's 33.5x57.0, three pixels narrower, so a full standing figure and not a limb; four draw sites, three of them followed by `sub [ACTOR_Y], 0x000D` and a call laying an upper layer thirteen pixels higher, with the head dispatcher running first; belongs to no walk cycle, none of its sites being a numbered phase; annot:7f8c38c5271b frame 3114, "lester's body" -- Lester is not in the name because one shared-bank picture serves more than one figure |
