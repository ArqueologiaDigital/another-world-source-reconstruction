# Naming the shared bank, now that a name can mean one thing

`docs/NAMING.md` §2 forbade hand-naming the shared bank "until that lands",
where "that" is plan item **T7**. T7's source half landed on 2026-09-19: the
bank is re-keyed from per-port encounter order to `CV_<OFFSET4>`, which is
port-invariant because the bank is literally one file — resource 0x11, 25,108
bytes, identical sha256 on amiga and msdos.

That is what makes naming worth doing at all. Before, identifying a picture
told you about `COMMON_VIDEO_099` on amiga and **nothing** about msdos,
because that same label is a different picture there: 346 of 353 names denoted
different art across the two ports. Now one identification names the art
everywhere, so these renames are global rather than per branch.

## The pipeline, which is the actual unlock

The renderer takes the bank directly and **names its output by offset** —
which is exactly the key T7 created:

```bash
cd another-world-archaeology
~/compartilhado/AnotherWorld_VMTools/target/release/awvm-render-polygons \
    --port amiga --stage 3 --bank video2 \
    --romset tmp/output/amiga/romset --out /tmp/cv_svg --palette 2
# -> /tmp/cv_svg/amiga_stage3_group_0x40CA.svg, one file per offset
```

`--bank video2` is the shared bank; the default `cinematic` is the per-stage
one. For amiga that walked 1,212 polygons (822 solid, 390 group) and wrote
1,212 SVGs.

Contact sheet, ranked by how many references each key carries — naming a
heavily-referenced one is worth more:

```bash
cd another-world-source-reconstruction
grep -rho '\bCV_[0-9A-F]\{4\}\b' src/levels/chahi_amiga_1991/ \
  | sort | uniq -c | sort -rn | head -12 | awk '{print $2}' \
  | while read k; do off=${k#CV_}
      magick -background '#909090' -density 600 /tmp/cv_svg/*_0x$off.svg \
        -trim +repage -resize 240x240 -bordercolor '#909090' -border 12 \
        /tmp/lab_$off.png
    done
magick montage -label '%t' /tmp/lab_*.png -tile 6x -geometry +8+8 \
    -background '#101010' -fill white -pointsize 20 /tmp/sheet.png
```

Two details that cost a round each: **trim before resizing** or every shape is
a speck in a 320×200 frame, and put the label **outside** the image
(`montage -label`) rather than annotating over it, or the text covers the art
you are trying to identify.

## First six names

| key | offset | what the render shows |
|---|---|---|
| `CV_FIGURE_CROUCH_FACING_LEFT` | 0x3E4E | low crouched body, boot pointing left |
| `CV_FIGURE_FRONT_STANCE_WIDE` | 0x3F8C | front-on, legs apart, boots splayed |
| `CV_FIGURE_FRONT_STANCE_NARROW` | 0x3FD4 | front-on, legs closer, knees bent |
| `CV_FIGURE_PROFILE_STANCE` | 0x40CA | profile, legs together, standing |
| `CV_FIGURE_PROFILE_STRIDE` | 0x40EC | profile, one leg forward, mid-stride |
| `CV_FIGURE_CROUCH_FACING_RIGHT` | 0x4132 | mirror of 0x3E4E, boot pointing right |

588 tokens across 48 files, on three branches and the unified tree, from six
renames — which is the point of the port-invariant key.

## What the names deliberately do not say

**Whose** body it is. These draw at `x=[0x07], y=[0x08]`, the actor-context
slot whose occupant is set by whichever channel filled it (#0138, and
`notes/draw-slot-probes/`). `CAVES_HERO_PER_FRAME_TICK` and
`CAPSULE_BUDDY_PER_FRAME_TICK` are parallel routines that both draw
`CV_FIGURE_PROFILE_STANCE` right after calling the same sprite dispatcher —
each animating whoever its stage has. That is correct, not a conflict, and it
is exactly why the polygon cannot carry a character.

The offset is not lost: the EQU keeps it
(`CV_FIGURE_PROFILE_STANCE EQU 0x40CA`), so anything can be re-rendered.

## `asset_naming_share.py` — the metric that was missing

Naming six assets moved the lint's per-stage percentage by **zero**, and that
is correct: its docstring says it counts "strict-semantic **labels**", and the
code divides by `len(labels)`. Labels are routines. The goal is bytecode *and
assets*, and the asset layer had counts but no denominator, so there was no
number to put beside PRISON's 32.0 %.

```
port/stage          assets   named  numbered  offset-key  named %
amiga/LAKE             742     741         0           1    99.9%
amiga/CODE_WHEEL        54      53         1           0    98.1%
amiga/INTRO            569     459       110           0    80.7%
amiga/PRISON           986     138       554         294    14.0%
amiga/CAPSULE          892      72       479         341     8.1%
amiga/CAVES           1218      78       794         346     6.4%
amiga/TANK             224       0       224           0     0.0%
amiga/ENDING           133       0       108          25     0.0%
...
TOTAL                10145    2818      5176        2151    27.8%
```

`CV_<4 hex>` counts as **unnamed**. It is a real improvement — the same art on
every port, so one identification serves all — but it is not an
identification.

The distribution is the useful part, and the label percentage hides it: LAKE
and CODE_WHEEL are effectively finished, INTRO is 80.7 % on amiga and 33.9 %
on msdos, and TANK-amiga and ENDING have not been started at all.

---

# The hero's sprite sheet, 2026-09-20: 52 names

The six names above were earned one render at a time. This pass found the
structure they sit in, which made 52 more earnable at once, and the method is
different enough to be worth stating separately.

## Why one-at-a-time had to stop

`../shared-bank-geometry/bank_shape_census.py` measured all 352 offsets before
looking at any picture. 250 of them "need a render", and for the articulated
figures a render does not settle it: it shows a figure, and *which* figure was
the question. The sole-named-drawer lever that works on the cinematic banks
yields **1 candidate out of 352** here, because 349 of the 352 are drawn from
more than one stage, so no scene can name them.

## What the call site settles

`../shared-bank-geometry/bank_draw_position.py`: **191 offsets are drawn at
`[HERO_X],[HERO_Y]` and nowhere else**, in any stage or port. 148 are drawn
only at the actor slot, 13 are mixed, and none are drawn at both — so the
subject split is clean. `HERO_X` lives in `src/levels/_common_vars.inc`, whose
scoping rule (NAMING.md §3) is "a name belongs here only if it means the same
thing in every stage and every port", which is exactly the invariant a
shared-bank name needs.

**The bank is the hero's sprite sheet plus a generic actor's.** That is why no
stage owns it.

## What the render settles

Rendered as a filmstrip in offset order
(`../shared-bank-geometry/bank_filmstrip.py`), the 191 are unmistakable: a
58-frame run of human figures in profile, walking and running, and a parallel
series of small bent limbs. The limb series is an **arm** — some frames forked
at the end around a gun, and the independently-earned
`HERO_GUN_ARM_POSE_CASE_02` draws one of exactly those forked variants, which
is the cross-check that the geometry split found the right thing.

## What the other stages settle

`../shared-bank-geometry/hero_pose_consensus.py`. The same offset is drawn by
routines in CAPSULE, CAVES and PRISON whose names were earned separately:

    CV_331A   CAPSULE_HERO_WALK_LEFT_DRAW_14
              CAVES_HERO_WALK_LEFT_STRIDE_PHASE_15     (CAVES is 1-based)
              PRISON_HERO_WALK_LEFT_DRAW_PHASE_14
              DRAW_HERO_WALK_LEFT_F14

Four derivations that never consulted each other. The probe requires at least
two *independent stages* — two names for one routine, or two ports of one
stage, count once — and unanimity rather than a majority (#0120: a tool must
not pick a winner between two semantic names). It excludes `_BUNDLE_`,
`_SHADOW_` and `_2NDSCR_` names, which carry raw index runs and describe a
draw mechanism, and it reads `_FOOTSTEP_PHASE_n` for motion and direction but
never as a frame ordinal.

59 offsets clear that bar. Three checks then corroborate the result rather
than assume it:

- **Offset order.** In every family the consensus indices are cyclically
  monotone in offset order — walk-right body and walk-right arm give the
  *identical* sequence 9,10,…,14,0,…,6,8. A sprite sheet stores frames
  consecutively, and this was not used to derive anything.
- **Body/arm co-draw.** 15 of 15 walk-right and 10 of 10 run-right frames have
  their body and their arm drawn together by the same routine, 5 to 7 routines
  per frame. The pairing is in the code, not inferred from size.
- **Footfalls land where footfalls should.** The `_FOOTSTEP_PHASE_1/2` names,
  deliberately barred from supplying an index, fall at frames 0 and 5 of the
  ten-frame run cycle and 5 and 13 of the fifteen-frame walk cycle.

## The 52

`hero_sprite_sheet.map`, applied with `apply_bank_names.py --map`:

| family | frames | names |
|---|---|---|
| `HERO_WALK_RIGHT_BODY_F00..F14` | 15 | 15 |
| `HERO_WALK_RIGHT_ARM_F00..F14` | 15 | 15 |
| `HERO_RUN_RIGHT_BODY_F00..F09` | 10 | 10 |
| `HERO_RUN_RIGHT_ARM_F00..F09` | 10 | 10 |
| `HERO_STAND_LEFT_BODY`, `_ARM` | — | 2 |

No gaps in any index run (NAMING.md §2). Two frames were completed from a
weaker grade of evidence and are flagged here rather than buried: walk-right
frame 7 (`CV_115C` body, `CV_33DE` arm) has no two-stage consensus, and is
placed by sitting between the offsets consensus-labelled 6 and 8 *and* by
being co-drawn as a body/arm pair by the same routine as every other frame.
Run-right frames 0 and 5 come from `_FOOTSTEP_PHASE_1/2` names, which attest
motion and direction but not the ordinal; the ordinal is their offset
position.

Verified: `bank_name_offset_consistent.py --map hero_sprite_sheet.map` — all
52 denote exactly one offset in every file; 300 keys remain, none resolving to
anything but its own offset. `make test` 29/29 and 29/29, `--sides` clean,
`--duplicates` clean at 1,842.

**158 routines that previously drew only shared-bank placeholders now draw only
named pictures.** 1,407 still draw nothing but placeholders.

## A name this pass found to be over-specific

`CINEMATIC_HERO_SHADOW_STOP_RIGHT_2` (dos/LAKE, `EQU 0xDFF2`) was tried as an
independent check on the motion claims, since the shadow is drawn next to the
body and arm in each frame block. It cannot serve: that one polygon is drawn
beside **29 different frames**, spanning walk-right, run-right and left-facing
art. A shadow shared by 29 poses cannot assert "stop, facing right, frame 2".

This does not contradict the names applied here — a shadow that says nothing
says nothing either way — and the sibling `DRAW_HERO_STOP_R_BUNDLE_*` routine
names are *compatible*, since a stop animation decelerating through walk frames
really does draw them. But the shadow EQU itself asserts a specificity its art
does not have, which is the #0107 failure mode, and it is recorded here for
whoever revisits the LAKE shadow family.
