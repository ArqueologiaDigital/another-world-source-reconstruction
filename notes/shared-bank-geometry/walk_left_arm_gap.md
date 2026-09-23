# Why `HERO_WALK_LEFT_ARM` stops at F04 and resumes at F14

`HERO_WALK_LEFT_BODY` is complete 0..14. Its arm family is not:

    HERO_WALK_LEFT_ARM   F00 F01 F02 F03 F04 ............ F14
    HERO_WALK_RIGHT_ARM  F00 .................................. F14   (complete)

Nine missing indices in a family whose twin is complete is exactly the shape
of a naming gap, and NAMING.md §2 treats an interior gap as a defect. It is
not one here. **The art does not exist**, and three independent checks say so.

## 1. No companion in the frame routines

Sweeping every routine that draws exactly one `HERO_WALK_LEFT_BODY_F<n>` and
collecting what else it draws, directly or one `call` deep:

    F00..F04   HERO_WALK_LEFT_ARM_F00..F04
    F05..F13   nothing
    F14        HERO_WALK_LEFT_ARM_F14

## 2. The unarmed path draws no arm

Both directions branch on `[0x0A]`, the weapon state, and all 15 frames of
both reference `HERO_GUN_ARM_POSE_*`. The difference is what the UNARMED path
does. Walk-right keeps a per-frame arm:

    DRAW_HERO_WALK_RIGHT_F07:
        video type=0, offset=HERO_WALK_RIGHT_BODY_F07, ...
        jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01   <- armed: gun arm
        video type=0, offset=HERO_WALK_RIGHT_ARM_F07  <- unarmed: walk arm

Walk-left frame 5 has no such draw -- the unarmed path jumps straight to the
body:

        je [0x0A], 0x00, DRAW_HERO_WALK_LEFT_F05      <- unarmed: skip
        call HERO_GUN_ARM_POSE_LEFT_CASE_01           <- armed: gun arm
    DRAW_HERO_WALK_LEFT_F05:
        video type=0, offset=HERO_WALK_LEFT_BODY_F05, ...

## 3. There is no room in the bank for the missing pieces

The known walk-left arms run at stride 8 from `0x331A`:

    F14 0x331A   F00 0x332A   F01 0x3332   F02 0x333A
    F03 0x3342   F04 0x334A

so F05 would fall at `0x3352`. That offset is **`HERO_WALK_RIGHT_ARM_F09`**,
and `0x335C`, `0x3366`, `0x3370` are F10, F11, F12 of the same right-facing
family. The two arm families interleave in one region, and the slots a
left-facing F05..F13 would occupy are already spoken for.

Only one live unnamed piece sits anywhere in `0x3300..0x33A0`: `CV_338E`,
16.0x3.0 with one leaf -- a single thin piece, not a nine-member family.

## Conclusion

The gap is an **absence**, not a missing name, and it is the third of the
three absence reasons this project has recorded for hero families -- a frame
that draws no arm. It should not be counted as outstanding naming work, and
a future pass that sees `F04 ... F14` should read this file rather than go
looking for nine pieces that were never drawn.

Reproduce with the sweep in `../gun-arm-dispatch/guarded_companions.py` and
with `grep -n 'HERO_WALK_\(LEFT\|RIGHT\)_ARM_F[0-9]*.*EQU' src/levels/_unified`.
