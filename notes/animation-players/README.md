# Frame order from the routine that plays the animation

`sequence_order.py`, and the 12 names it led to.

## The idea

`hero_pose_consensus.py` needs a frame ordinal spelled in a drawer's name.
Whole families have none. But the routine that draws them is often a
straight-line player:

    HERO_JUMP_RIGHT_FROM_STAND:
        video type=0, offset=CV_4D98, ...
        break
        video type=0, offset=CV_4DE4, ...
        break
        ...

Draw, `break`, draw. **The draw order is the frame order**, stated by the code.

That is different from a dispatcher, which selects one of N with a `jne`
chain, and the difference is why these were invisible: `hero_pose_consensus`
rule 8 rejects any routine drawing more than two pictures, correctly, because
a per-frame dispatcher would otherwise assert its own name over eight frames.
A player draws twelve and is excluded by the same rule. A dispatcher *branches
to* one frame; a player *draws all of them in order*.

## What it found: six players, four of them contested

    JUMP_RIGHT   HERO_JUMP_RIGHT_FROM_STAND    12   0x4D98..0x514C
    WALK_RIGHT   HERO_WALK_RIGHT_LOOP          12   0x4D98..0x514C   <- same sheet
    JUMP_LEFT    HERO_JUMP_LEFT_FROM_STAND     12   0x52C0..0x5444
    RUN_LEFT     HERO_RUN_LEFT_BURST_LOOP      12   0x52C0..0x5444   <- same sheet
    CRAWL_RIGHT  PRISON_HERO_CRAWL_RIGHT_START  6   0x448C..0x4C40
    CRAWL_LEFT   PRISON_HERO_CRAWL_LEFT_START   6   0x57C4..0x5B4C

**The jump sheets are held.** One thirteen-frame sheet per direction is played
as a jump by CAVES, as a walk-jump and run-jump by PRISON, and as a walk or
run loop by LAKE and CAPSULE. Measured, to see whether the code decides it:
the net X step per frame is **identical** in the CAVES and LAKE versions — 5,
7, 13, 12, 2, 7, 4, 7, the extra ±15 and ±12 pairs in CAVES bracketing a
`CAVES_SCREEN_STEP_UP_ONE_ROW_L4` call and cancelling — and **neither writes
`HERO_Y` at all**. Same motion, two names, and nothing in the code to choose
between them. #0120 says a tool must not pick a winner; neither may its
author. The probe reports it and stops.

Their internal structure *is* settled, and is recorded for whoever resolves
the name: the thirteen frames are one animation with two entry points.
`HERO_JUMP_RIGHT_FROM_STAND` plays twelve of them, skipping `CV_4FBC`;
`HERO_JUMP_RIGHT_FROM_RUN` plays eight, entering at F05 and including
`CV_4FBC`. Both are subsequences of the same ascending thirteen.

## The crawl sheets: named, by what the disagreeing names agree on

These looked contested too — `PRISON_HERO_CRAWL_LEFT_START` in PRISON,
`HERO_PRONE_RISE_LEFT` in CAVES, `HERO_WALK_LEFT_STOP_TO_GUN_READY` in
CAPSULE. The probe's "play order is not sheet order" rejection is what
explained it:

    PRISON_HERO_CRAWL_LEFT_START  57C4 5878 5944 5A08 5AAC 5B4C   ascending
    PRISON_HERO_CRAWL_LEFT_STOP   4BC4 5AAC 5944 5878 57C4        descending
    HERO_PRONE_RISE_LEFT          4BC4 5AAC 5944 5878 57C4        descending

**The same frames, played backwards.** Forward the hero lies down; backward he
gets up. Neither "crawl start" nor "prone rise" names the art — they name the
*direction of play*. (`CRAWL_LEFT_STOP` and `PRONE_RISE_LEFT` draw byte-for-byte
the same sequence, so they are two names for one body.) The right side is
identical in structure.

So the art is named for what both claims contain and neither disputes: the
transition between standing and prone. `HERO_PRONE_TRANSITION_{LEFT,RIGHT}_F00..F05`,
numbered in the forward (lie-down) order, 12 names, both runs complete 0..5.
That is not picking a winner — it is naming the intersection of the two
claims.

## Verification

`make test` 29/29 and 29/29; `undefined_symbols.py` clean;
`bank_name_offset_consistent.py --map prone_transition.map` reports all 12 at
the offset their key encoded.

## What this says about what is left

The hero art still unnamed is not art nobody has looked at. It is the art the
stages **disagree about**, and the disagreement is over what to call the
motion, not over which picture it is. The crawl case shows one such
disagreement can be dissolved by measurement. The jump case shows another
cannot, at least not from the source — that one needs the game running.
