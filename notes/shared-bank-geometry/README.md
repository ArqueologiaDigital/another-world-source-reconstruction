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

So the base is not the obstacle, and the spelling still stays out. Admitting
it with the base calibrated gives `RUN_RIGHT_BODY` as `0,1,2,3,4,5,6,7,8,8` —
two offsets claiming frame 8 — and `WALK_LEFT_BODY` with an index 16 inside a
0..15 run. Something about these names is not a re-based frame ordinal. That
is the open question the actor half now waits on, and it is a narrower one
than before.

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
