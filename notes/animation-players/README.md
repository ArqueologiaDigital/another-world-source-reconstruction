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

## The run-left arm: nine frames, and a tenth that has no arm

`HERO_RUN_RIGHT_ARM_F00..F09` was named earlier from cross-stage consensus.
The left counterpart sat unnamed with what looked like a hole at frame 4.

Two stages name every member, independently, and agree nine for nine:

    F00 CAPSULE_HERO_RUN_LEFT_DRAW_0_GUN_LOWERED  CAVES_..._NO_GUN_ARM_PHASE_1   CV_3630
    F01                             _1_           PHASE_2                        CV_3638
    F02                             _2_           PHASE_3                        CV_3640
    F03                             _3_           PHASE_4                        CV_3648
    F04                     (absent)              (absent)                       —
    F05                             _5_           PHASE_6                        CV_3650
    F06                             _6_           PHASE_7                        CV_3674
    F07                             _7_           PHASE_8                        CV_3658
    F08                             _8_           PHASE_9                        CV_3660
    F09                             _9_           PHASE_10                       CV_366C

Note F06: `CV_3674` sits *after* `CV_366C` in the sheet while being frame 6.
Index order is not offset order here, and it is the two stages agreeing —
not the offsets — that fixes the numbering.

**Frame 4 is not missing; it has no arm.** The routine exists and the code
says why:

    CAPSULE_HERO_RUN_LEFT_DRAW_4:
        je [0x0A], 0x00, DRAW_CV_297     ; gun lowered -> straight to the body
        call DRAW_CV_279                 ; armed -> the gun arm
    DRAW_CV_297:
        video offset=CV_1474             ; the body

Every other frame has a `..._DRAW_n_GUN_LOWERED` label marking where its
unarmed arm is drawn. Frame 4 has none, because in the unarmed case it draws
no arm at all — it jumps past that point to the body. The hole in the index
run is a fact about the animation, not a frame anyone missed, which is what
NAMING.md §2's rule asks a gap to be explained as.

Applied: `HERO_RUN_LEFT_ARM_F00..F09` less `F04`, nine names. `make test`
29/29 and 29/29, all nine verified at the offset their key encoded.
