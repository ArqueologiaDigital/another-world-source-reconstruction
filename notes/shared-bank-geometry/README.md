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
    large              143          142             10   needs a render
    small-cluster       94           94              3   needs a render
    single-shape        62           62              1   shape alone, if recognisable
    particle            40           40              1   shape alone: spark/speck
    figure              13           11             13   NOT settled by shape

For 250 of 352 the honest verdict is "needs a render", and for the 13 articulated
figures it is worse: a render shows a figure and the question was *which* figure.
**That is where shape stops.** The classes are there so effort goes to the rows
where a name is earnable, not so they can be named from the table.

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
