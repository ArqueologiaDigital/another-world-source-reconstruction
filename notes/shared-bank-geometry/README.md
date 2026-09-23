# What the shared bank actually is

Two probes, run in this order. Together they answer a question that had been
open since the shared bank was first counted: **not where it sits, but what it
holds.**

## Background: why the usual levers don't reach it

`docs/NAMING.md` §2 forbids hand-naming the bank "until an identification is
actually made from a render", and T7's re-key (2026-09-19) made that possible in
principle by keying it as `CV_<OFFSET4>`, port-invariant, so one identification
names it in every file and on both priority ports. 1,147 routines are gated on
it.

The lever that works on the cinematic banks is `notes/sole-named-drawer/`: name
a picture from the one semantically-named routine that draws it. Applied here it
yields **1 candidate out of 352**, because **349 of the 352 offsets the tree
draws are drawn from more than one stage**. A shared-bank name cannot come from
a scene. Whatever `CV_1B14` is, it is that same thing in PRISON and in ENDING.

## 1. `bank_shape_census.py` — how far the shape gets

Measures extent, leaf count and colour set at every offset, from
`resource-0x11.bin`, before looking at any picture.

It also re-proves T7's premise per symbol: all 352 offsets parse as polygons and
the amiga and msdos copies agree on **every one** by `canonical_md5` over the
whole expanded tree. The sibling `notes/shared-bank-probes/` proved the file is
byte-identical; this proves the 352 offsets the tree names are all valid heads in
both, which is the form the one-name-per-offset premise is actually used in.

    $ python3 notes/shared-bank-geometry/bank_shape_census.py --classes
    class            count  multi-stage  median leaves   what a name could assert
    small-cluster      162          161              6   needs a render
    large               78           78              5   needs a render
    single-shape        62           62              1   shape alone, if recognisable
    particle            40           40              1   shape alone: spark/speck
    figure              10            8             13   NOT settled by shape

For 250 of 352 the honest verdict is "needs a render", and for the 10 articulated
figures it is worse: a render shows a figure and the question was *which* figure.
**That is where shape stops.** The classes are there so effort goes to the rows
where a name is earnable, not so they can be named from the table.

> **Corrected 2026-09-20.** This table first read 143 large / 94 small-cluster /
> 13 figure. Those counts came from the group-pivot bug that measuring *this*
> bank exposed an hour later: nested art was reported larger than it is, which
> pushed rows up the size classes. See `../polygon-extent-correction/`. The
> 250-needs-a-render total and every conclusion below are unchanged -- the
> classes shifted, the verdict per row did not.

## 2. `bank_draw_position.py` — what the call site settles

The draw *position operand* is stage-invariant in exactly the way a scene is not.
`HERO_X`/`HERO_Y` lives in `src/levels/_common_vars.inc`, and NAMING.md §3's
scoping rule for that file is "a name belongs here only if it means the same
thing in every stage and every port". So an offset drawn only at the hero is hero
art, and saying so is true at every reference.

    $ python3 notes/shared-bank-geometry/bank_draw_position.py
    191  only [HERO_X],[HERO_Y]
    148  only the actor slot (#0138)
     13  mixed
      0  other fixed position
    No offset is drawn at both the hero and the actor slot.

**The shared bank is, in the main, the hero's sprite sheet plus a generic
actor's.** That is why it is shared and why no stage owns it: the hero is in
every stage, so his art cannot live in a stage's cinematic bank. The split is
clean — no offset serves both subjects — so one name per offset survives.

It sharpens #0138 rather than dissolving it. For the 148 actor-slot offsets the
position is the shared actor record, loaded from a different record before each
draw; it says *an* actor and refuses to say which. Those stay blocked. The
aliases are resolved through `notes/actor_slot.py`; the literal `[0x07],[0x08]`
test under-reports them badly, because PRISON, CAPSULE and ENDING spell it
`[BUDDY_X],[BUDDY_Y]`.

## What this licenses

The **subject** of 191 offsets, not their **pose**. `CV_34BA` being hero art is
settled; whether it is a running frame or a falling one is not, and NAMING.md
still requires a render before any name is written. What changed is that the
render now only has to answer "which pose", with the subject fixed and
independently checkable — instead of "who is this", which no render of a 6x8
blob in an unknown palette was ever going to answer.

## Regenerating the input

The bank dumps live in `another-world-archaeology/tmp/output/<port>/resources/`,
which is volatile and not in git:

    cd another-world-archaeology && python3 tools/aw_unpacker.py

Baseline: resource `0x11` is 25,108 bytes on both ports and sha256
`ee98e9d5cca18a4fd0c3d0dac884e38a11533cd8fd88825cd503eeb0658494b0`
(`notes/shared-bank-probes/shared_bank_bytes_identical.py` checks it).

## Exit status

Both exit 1 on a result that would invalidate one-name-per-offset: the census if
any offset's two ports disagree, the position probe if any offset is drawn at
both the hero and the actor slot. Neither should pass silently.

## 3. The actor half: the probe reaches it, the names do not — yet

`hero_pose_consensus.py --subject actor` runs the same consensus over the 148
offsets drawn at the shared actor record. #0138 bars saying **which
character** they are, not what pose they are in; the existing
`CV_FIGURE_CROUCH_FACING_LEFT` names are that distinction already applied.

The evidence that no character may be claimed is in the tree, not assumed. One
eight-frame run is called `CAPSULE_BUDDY_WALK_RIGHT_DRAW_0`,
`CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_1` **and** `CAVES_HERO_WALK_RIGHT_PHASE_2`
— buddy, actor and hero, for one picture. The stages disagree about the
character and agree about the motion, the direction and the frame. So the name
would be `CV_FIGURE_WALK_RIGHT_BODY_F00`, claiming only what they agree on.

**Nothing was applied.** 22 offsets reach consensus and every family has holes:

    RUN_RIGHT_BODY   0,2,3,5,7,8          WALK_LEFT_BODY  2,3,4,9,11,12,13,14,15
    RUN_LEFT_BODY    4,6,9                WALK_RIGHT_BODY (no parseable index)

NAMING.md §2 forbids a gap in a family's index run, and here the gaps are
parse failures rather than missing art: the unclaimed frames are named
`_PHASE_<n>` with no ordinal this probe accepts.

**Correction.** An earlier version of this paragraph said that spelling
"carries yet another base convention". That was a guess and it was wrong.
`phase_base_calibration.py` measures it, by placing each bare-`_PHASE_` offset
between neighbours whose frame is already known and reading the base off the
gap — only unambiguous single gaps, so nothing has to be assumed about how
many frames fill a hole:

    CAPSULE counts from 0 · PRISON counts from 0 · CAVES counts from 1

Unanimous per stage, and the same split those stages already show in their
`_DRAW_PHASE_` names. The base follows the **stage**, not the spelling.

So the base is not the obstacle, and the spelling still stays out — but the
reason is now identified rather than mysterious, and it is not a regex
problem.

### What actually blocks the actor half

Admitting bare `_PHASE_` with the base calibrated gives `RUN_RIGHT_BODY` as
`0,1,2,3,4,5,6,7,8,8` and `WALK_LEFT_BODY` an index 16 inside a 0..15 run.
Chasing those produced two findings and one dead end, and the dead end is the
important one.

**Finding 1: one offset is often several frames.** Counting (offset, stage)
pairs where a single stage's routines claim that offset as more than one
frame: **35 of 203, 17 %.** `CV_2D56` is `BUDDY_WALK_LEFT_DRAW_8` *and*
`DRAW_9` in CAPSULE. These are shared sub-pieces — one small polygon reused
across several frames of the run. They are not errors and they are not
nameable with a frame index at all.

**Finding 2: a terminal word hides the ordinal.** `BUDDY_WALK_LEFT_DRAW_3_DONE`
and `ACTOR_RUN_RIGHT_PHASE_1_FRAME` are frames 3 and 1, but requiring the
digits at end-of-string drops them. In the actor walk-left family that
dropped *every* CAPSULE and PRISON claim, leaving CAVES — the only 1-based
stage — as the sole source, so it became its own calibration reference and
was never corrected. That is where the index 16 came from.

**The dead end: fixing finding 2 alone makes things worse.** Admitting the
terminal words feeds the finding-1 offsets into the calibration, where a
last-write-wins map over multi-frame claims corrupts the pairwise difference
and the whole walk-left family is rejected. The two findings have to be
handled together: multi-frame offsets must be excluded from calibration *and*
from indexed naming before the extra parses can help.

That is a change to what the probe models, not a regex tweak, and it is the
next concrete step. The tree is left at the last verified state — bare
`_PHASE_` excluded, 22 proposals, stable across runs — rather than at the
best-looking intermediate.

The calibration probe also has to parse with **its own** regex rather than
borrowing `hero_pose_consensus.parse_claim`. Borrowing it makes the
measurement circular the instant anyone admits `_PHASE_` there — the names
being calibrated join the trusted input — and the first run after that
experiment duly reported CAVES using bases 0 *and* 1.

### Three defects this attempt found in the probe

**The index base differs by stage under one spelling.**
`PRISON_HERO_WALK_LEFT_DRAW_PHASE_00` is 0-based;
`CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_1` is 1-based. The base is now calibrated
pairwise against a reference stage over the offsets both name, and a
non-constant difference is left as the real disagreement it is.

**The reference stage must start at 0, not merely be well attested.** CAPSULE,
CAVES and PRISON each claim 16 frames of the actor walk, so choosing by claim
count was a coin toss — and landing on CAVES shifted the other two *up* to
1-based while PRISON, whose calibration fails on two genuine outliers, stayed
at 0. A family all three stages agree about was reported as a 0-vs-1 conflict.

**The probe was not reproducible.** It iterated an offset *set*; Python
randomises string set order per process, so the tie-break for the reference
varied and three consecutive runs of one command returned 22, 21 and 22
proposals. Every iteration is now over a sorted sequence. A naming probe that
is not reproducible cannot be evidence for anything, and this one had been
quoted in the same session.

The 52 hero names applied earlier do not depend on any of this: that map was
built from the co-draw pairing (15/15 and 10/10) and the complete index runs,
not from `--proposals`, and `bank_name_offset_consistent.py --map
hero_sprite_sheet.map` still reports all 52 correct.

## 4. Walk-left body: 15 more, after one contaminated source was found

`WALK_LEFT_BODY` had been stuck at 13 of 15 frames, then briefly collapsed to
7 with a duplicate index 14. The cause was a single mis-typed source.

`CAVES_HERO_WALK_LEFT_STOP_AFTER_PHASE_10` draws the offset CAPSULE calls
`DRAW_8`. Its 10 is **the phase it stops after**, not the frame it draws — so
it contributed a difference of +2 where every other CAVES claim in that
family differs by +1. The pairwise base calibration needs one constant
difference, saw `{1, 2}`, gave up, and left CAVES uncorrected. The whole
family then read as a disagreement between 14 and 15, 0 and 1, 2 and 3, all
the way down.

**One mis-typed source poisons a family, not just its own offset.** Rule 4
now excludes `_STOP_AFTER_PHASE_<n>` alongside `_FOOTSTEP_PHASE_<n>`, for the
same reason: the number counts something that is not frames.

### The two absences, both explained

    F00..F08  12x49/10 20x49 24x49 26x49 26x49 22x49/11 18x49/11 14x41/7 14x49/11
    F09       --
    F10..F14  24x49/10 26x49 26x49 22x49/10 18x49/10

**F07** (`CV_0874`, 14x41/7) has one naming source, but two other things put
it there: it is the only offset in the gap between F06 and F08, and it is
**short** — 41 tall where its family is 49. Walk-*right*'s F07, named earlier
from the bundle co-draw, is `12x41/5`: also the short frame, in the same slot,
in the other direction. A property shared by both directions at the same
index is not a coincidence in a mirrored animation.

**F09** is not a walk frame. `CV_09F6` (15x50/11) is drawn **alone** — with no
arm, unlike every frame here — by `HERO_WALK_LEFT_ENTRY` *and*
`HERO_WALK_RIGHT_ENTRY`. It is the direction-neutral standing frame both
cycles start from, and it is named `HERO_STAND_NEUTRAL_BODY`. The gap at 9 is
where a shared frame sits, which is what §2 asks a gap to be explained as.

The width curve corroborates the numbering independently: 12, 20, 24, 26, 26,
22, 18, 14, 14 … 24, 26, 26, 22, 18 — a stride opening and closing twice, for
a two-step cycle.

Applied: `HERO_WALK_LEFT_BODY_F00..F14` less `F09`, plus
`HERO_STAND_NEUTRAL_BODY`. 15 names, `make test` 29/29 and 29/29,
`--duplicates` still one name per picture.

## 5. Walk-left arm: six frames, and why the other nine do not exist

Walk-**right** has a dedicated arm for all fifteen frames. Walk-left has six,
and that is not an omission. Reading each named frame of the cycle in CAPSULE,
on both ports, and asking whether it draws its own arm or calls the guarded
shared one:

    DRAW_0  CV_332A      dedicated        DRAW_8   guarded + CV_356E, CV_352C
    DRAW_1  CV_3332      dedicated        DRAW_9   guarded + CV_0020
    DRAW_2  CV_333A      dedicated        DRAW_10  guarded
    DRAW_3  CV_3342      dedicated        DRAW_11  guarded
    DRAW_4  CV_334A      dedicated        DRAW_12  guarded
    DRAW_14 CV_331A      dedicated        DRAW_13  guarded

Frames 5, 6 and 10 to 13 draw **no arm of their own**: they `call` the
`[0x0A]` weapon-state switch (`GUARDED_DRAW_CV_126`, now
`HERO_GUN_ARM_POSE_LEFT_CASE_01`), which supplies the arm. Identical on both
ports, frame for frame.

So `HERO_WALK_LEFT_ARM` is a six-member family — F00..F04 and F14 — and the
missing nine are frames that use the shared arm instead. Same kind of
explained absence as `HERO_RUN_LEFT_ARM`'s F04, which draws no arm at all,
and `HERO_WALK_LEFT_BODY`'s F09, which is the shared neutral frame.

Three absences, three different reasons, each read off the code rather than
assumed:

| family | absent | why |
|---|---|---|
| `HERO_WALK_LEFT_BODY` | F09 | a direction-neutral frame both cycles share |
| `HERO_WALK_LEFT_ARM` | F05..F13 | those frames call the weapon-state arm |
| `HERO_RUN_LEFT_ARM` | F04 | that frame draws no arm when unarmed |

`make test` 29/29 and 29/29 after each.

## The standing aim pose, and the six still held

Nine of the 77 shared-bank keys still called `CV_<hex>` are drawn at
`[HERO_X],[HERO_Y]`, so they are the hero. Two are 0x1 single points; the
other seven are figures. `unknown_vs_named_sheet.py` renders all of them in
one grid beside named hero pieces of comparable height, and what they are is
not in doubt as a class:

```
CV_15DC  14x48/11     CV_36D2  34x48/12     CV_3858  40x48/12
CV_391A  34x49/12     CV_3A64  40x49/12     CV_3A96  40x49/12
CV_367C   7x18/3
```

48–49 tall where a crouch is 33–34 (`pose_height.py` measured 49.0 upright
against 33.0 crouched), and 34–40 wide where `HERO_STAND_ARMED_*` is 16. So:
**standing, arm extended** — the standing counterpart of the already-named
`HERO_CROUCH_AIM_*` and `HERO_CROUCH_SHOOT_*`. `CV_367C` at 7x18 with 3 leaves
is a separate gun-arm layer, the same shape as every
`HERO_GUN_ARM_RIGHT_CASE_*` (8x17/3, 6x17/3, 8x18/3).

Every routine that draws them is a placeholder, so `hero_pose_consensus.py`
reports 0 of 9 with two stages agreeing — there is no name anywhere to
inherit. One is settled anyway, by structure:

```
LABEL_99EB:
        video type=0, offset=CV_3A64, ...
        je [0xBE], 0x03, DRAW_CIN_172
        jg [0x06], [0x30], SHARED_RET
        mov [0xF8], [0x31]
        and [0xF8], 0x0004          <- the charge blink
        je [0xF8], 0x00, SHARED_RET
        video type=0, offset=CV_5C9C, ...
```

That is exactly how `HERO_CROUCH_AIM_LEFT` pairs with
`HERO_CROUCH_AIM_LEFT_CHARGE_DOT`, and the offsets corroborate it: the crouch
dots are `0x5C4C` (right) and `0x5C94` (left), and these two sit **exactly 8
bytes after each**, at `0x5C54` and `0x5C9C`. A pose that blinks a charge dot
is the one held while the gun charges — an aim, not a shot. So `CV_3A64` is
`HERO_STAND_AIM_LEFT` and `CV_5C9C` its charge dot.

### And then the other six, from the fire path

The width analogy was never used. Reading the routine that *calls* these
stubs settles all of them:

```
LABEL_E87C:                      <- the aim loop
    break
    je [HERO_ACTION_POS_MASK], 0x80, LABEL_E8AA
    call LABEL_99EB              <- HERO_STAND_AIM_LEFT + its charge dot
    je [HERO_ACTION_POS_MASK], 0x00, LABEL_E87C
LABEL_E8AA:                      <- the fire button
    call LABEL_9A15              <- CV_3A96, drawn AT the shot
    mov [0x21], [HERO_X] / mov [0x27], [HERO_Y]
    sub [0x21], 0x001E           <- the muzzle, to the LEFT
    call LABEL_6265              <- the projectile is spawned
    break
    call LABEL_99D9              <- CV_391A, the frame after
```

The right is the same routine mirrored, with `add [0x21], 0x001E`: `CV_3858`
at the shot, `CV_36D2` after it. The muzzle offset carrying the direction is
what makes it a reading rather than an inference.

`mirror_match.py` then agrees independently — `CV_3A96`↔`CV_3858` at 0.592
and `CV_391A`↔`CV_36D2` at 0.530, both inside the 0.520–0.923 band its
control measures for pairs a person named from other evidence, against 1.768
and 2.250 for the cross pairings.

`CV_5C54` turned out to be the right aim's charge dot after all: the right
aim loop is `LABEL_9763`, which draws `CINEMATIC_176` — the right aim pose is
cinematic art in CAVES, not a bank key — and then blinks `CV_5C54` under the
identical test. The `CINEMATIC_118` pairing seen in CAPSULE is the same role
in that stage.

`CV_15DC` is drawn leaving the right aim loop, after `CV_36D2` and
immediately before `jmp HERO_WALK_RIGHT_LOOP`: 14 wide against the aim's 40,
the arm back down.

**One of the nine is left.** `CV_367C`, 7x18 with 3 leaves, is a gun-arm
layer of exactly the shape of every `HERO_GUN_ARM_RIGHT_CASE_*`, and nothing
says which pose it belongs to.

## The actor's armed layers, read off the [0x0D] branch

The hero slot was nine keys. The actor slot is 65, and the same method opens
it: a gait frame picks its top layer on `[0x0D]`.

```
CAPSULE_ACTOR_RUN_RIGHT_DRAW_2:
        video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F02, ...
        je [0x0D], 0x00, LABEL_6A11
        call LABEL_691B                                      <- armed
        jmp LABEL_6A16
LABEL_6A11:
        video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_02, ...   <- unarmed
```

So every one of these is the **armed substitute for an already-named layer**,
and the geometry says the same: armed is unarmed plus the gun.

| armed | | unarmed it substitutes for | |
| --- | --- | --- | --- |
| `CV_3B44` | 19x23, 6 leaves | `CV_FIGURE_WALK_RIGHT_UPPER_POSE_00` | 18x30, 2 |
| `CV_3C3A` | 12x23, 2 leaves | `CV_FIGURE_WALK_LEFT_LIMB_POSE_03` | 11x17, 1 |

The right-facing three replace **UPPER** layers and the left-facing three
replace **LIMB** layers, which is why their leaf counts differ — the names
follow the layer each substitutes for rather than being forced to match.

**None is the armed form of one frame.** Each substitutes across four to eight
walk *and* run frames, so like the shared sub-pieces in `subpiece_poses.py`
they take a `POSE` ordinal rather than an `F` index. The ordinal is measured,
not chosen: ascending offset is descending arm height, in both directions —
right 23, 20, 16 and left 23, 20, 14.

Each is paired with one 0x1 single-point piece from the blink array at
0x5C5C..0x5CB4, drawn under the same `and [0xF8], 0x0004` test that gates
every other `*_CHARGE_BLINK` in the bank, and the pairing is identical in
CAPSULE and CAVES.

Twelve names. Held back: `CV_41A8`, `CV_41E0`, `CV_4218` (35x7, 36x10, 28x7 —
wide and flat, a different thing), `CV_4058`, and the two blinks `CV_5CBC` and
`CV_5CC4` whose drawers paint nothing else to pair them with.

## `blocked_by_bank.py` — how much waits on the bank

The shared bank is one file, so naming one key names the art in every port.
That makes the remaining `CV_<OFFSET4>` keys the highest-leverage item left,
and this measures the leverage rather than guessing:

    53 still-numbered keys drawn in the priority ports
    302 distinct drawing labels wait on them

— about seven labels per key. It was 57 and 378 before the four
`CV_FIGURE_RUN_RIGHT_LIMB_POSE_*` names. The dependency is real, not a
coincidence of spelling: `CAVES_DRAW_CV_355_L2` carries the key's raw index in
its own name, which `docs/NAMING.md` §1 forbids, and it cannot be fixed until
the key has a name.

`--claims` is the control on the evidence the neighbouring probes run on: a
named key whose drawers unanimously say one (motion, direction) should carry
both in its own name. **152 of 158.** The 6 are printed, and none is a
contradiction — three names carry no direction at all, two are drawn by crawl
routines under the name `PRONE_TRANSITION`, and one is a wading pose drawn by
a walk routine.

## `mirror_exact.py` — a yes/no mirror where the scored one could not decide

`mirror_match.py` pairs facings by a similarity score and its own control
fails where it matters: a wrong aim-vs-shoot pairing scores 0.451 against true
pairs at 0.520-0.923. This asks a narrower question and gets a clean answer.

Two pieces are an **exact mirror** when leaf count, width, top edge and bottom
edge all match and the x spans are reflected about one axis within half a unit
of the draw anchor. Every named key containing `_LEFT`/`_RIGHT` whose flip also
exists is a test case:

| leaves | exact mirror | not |
| --- | --- | --- |
| 1 (limb) | 8 | **0** |
| 2 (body) | 24 | **0** |
| 3 | 2 | 2 |
| 4 | 0 | 2 |
| 5 (body) | 28 | 26 |

Exact for simple pieces, unreliable for complex bodies, where the two facings
are drawn at different widths rather than reflected —
`CV_FIGURE_WALK_RIGHT_BODY_F00` spans −17.0..+15.5 against its twin's
−16.5..+17.0. `--max-leaves` bounds it; the default of 2 is where the control
is exact.

A flipped *name* is only right if the families correspond member by member,
and they do: the committed `CV_FIGURE_WALK_{LEFT,RIGHT}_LIMB_POSE_00..03`
pairs are exact mirrors **at the same index, 4 for 4**.

**5 named**, and one of them overturns an earlier hold of mine.
`../actor-sprite-sheet/subpiece_poses.py` held RUN_LEFT because `CV_3200` is
attested at phases 8 and 9 and never at 1, where its right-hand twin is
attested at both — so bank order and phase order disagreed and I would not
place it on the mirror alone. The mirror is no longer *alone*: it is exact,
one-to-one, at a leaf count where the control has no failures, and it agrees
with the descending-offset order that `subpiece_poses.py --control` reproduces
16 times out of 16. The phase attestation says *when* a piece is drawn; the
slot is what the name asserts, and three independent things now fix it.

`CV_2276` came with the same batch: an exact mirror of
`CV_FIGURE_RUN_LEFT_UPPER_POSE_06`, sitting at 0x2276 immediately above
`..._RIGHT_UPPER_POSE_05` at 0x224C, continuing that family's ascending run.

### `--same-signature`, and the control that stopped a name

Two keys share a *signature* when their group box and the multiset of their
leaf sizes are equal — the same parts in a box of the same size. It looks like
what two adjacent frames of one animation would share. It is not: **of 48
consecutive pairs in named `_F` families, 0 share a leaf-shape multiset.** A
cycle redraws its parts between frames rather than moving them.

Six groups contain both a numbered and a named key, and one of them is very
tempting. `CV_4324` shares a signature with `CV_FIGURE_CROUCH_FACING_LEFT`,
has three of its five children at identical positions with identical vertices,
and is drawn only by `BUDDY_RIGHT_FIRE_RECOIL_PHASE_3` where the named one is
drawn by `BUDDY_RIGHT_FIRE_AIM_PHASE_1` and `..._RECOVER_PHASE_4` — the same
`BUDDY_<D>` token, differing only in the phase word. `CV_42BA` pairs with
`CV_FIGURE_CROUCH_FACING_RIGHT` the same way.

The obvious name is `..._RECOIL`, and it is not available. That word comes
from the same label family whose direction token `hero_pose_consensus.py
--token-order` shows wrong **six times out of six**. Having discredited
`<DIR>` in those labels this session, taking `RECOIL` from them on trust is
not something I can do. Held, reported, and the association recorded so the
next reader starts from it rather than rediscovering it.

The art was rendered and looked at first, per the standing
render-before-naming convention: all four are a crouching figure in profile
built from the same five parts. The render is what prompted the measurement
and it is not what decided it — the two "facings" are **not** mirror images
(group boxes 158x157 against 98x157, child positions unrelated), which the
thumbnails alone would not have told me.
