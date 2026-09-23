# A label that only draws one picture should say which picture

## What is here

| file | question it answers | command |
| --- | --- | --- |
| `label_vs_constant.py` | Which labels do nothing but draw one already-named picture, and so can take its name? And which semantic labels disagree with the picture they draw? | `python3 notes/draw-label-follows-constant/label_vs_constant.py` |

`--proposals` emits one `apply_routine_renames.py` table per (branch, stage);
`--branches` limits the scan.

## Why

Renaming the shot-impact frames in `../laser-impact-anim/` left twelve labels
like this behind:

```
DRAW_CIN_776:
    video offset=CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_3, x=[0x21], y=[0x27]
    ret
```

`776` was a resource index, and after the rename it pointed at a constant that
no longer exists anywhere in the file. That is a general shape: the label has
exactly one job, the constant already names it, and the name transfers without
any new claim being made. `naming_census.classify` scores `DRAW_CIN_776` as
`res_index` and `CAVES_DRAW_LASER_IMPACT_ANIM_RIGHT_3` as `semantic`, so the
transfer is also a measurable gain.

The proposed name is `<STAGE>_DRAW_<constant>`, with `CINEMATIC_` and any
leading `<STAGE>_` stripped off the constant.

## Four ways the first version of this was wrong

Each of these was caught by reading the source the probe claimed to describe,
and each one would have written a false name into the tree.

**A dispatch is not a draw stub.** PRISON's rightward ladder entry ends
`video offset=..._RIGHT_5 / mov [0x13], 0xFFFE / ret`, so it looked like a
one-picture label — and it is the entry of a six-way binary search whose other
five frames live in the labels it branches to. Naming it after its fallthrough
frame would have been flatly wrong. Any body containing `call`, `jmp` or a
conditional jump is now excluded.

**There are two draw instructions, not one.** `video offset=` reads the stage's
own cinematic bank; `video type=0, offset=` reads the shared video2 bank. The
first pattern matched only the former, so

```
DRAW_VIDEO_036_037_AND_HERO_STOP_RIGHT_FRAME_2_RET:
    video type=0, offset=HERO_WALK_RIGHT_BODY_F09, ...
    video type=0, offset=HERO_WALK_RIGHT_ARM_F09, ...
    video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, ...
    ret
```

counted as a one-picture label and would have been renamed after the *shadow*,
dropping the body and the arm. Fixing the pattern took the pool from 779 labels
to 910 and removed that whole class.

**A picture can still be a placeholder.** `CV_<hex>` is the shared bank's
unnamed form, as `CINEMATIC_<index>` is the cinematic bank's, and the first
version excluded only the latter — proposing `CAPSULE_DRAW_CV_3FB8`, which
moves a placeholder instead of retiring one. Both forms are excluded now, and
the constant's own name must additionally pass `classify` as semantic.

**Drawing is not always all it does.** 30 of the one-draw labels also play a
sound, and their current names record its operands exactly:

```
DRAW_CV108_PLAY_60_F0F_V2A_C1:
    video type=0, offset=HERO_RUN_LEFT_BODY_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
    play id=0x0060, freq=0x0F, vol=0x2A, channel=0x01
    ret
```

`CV108_PLAY_60_F0F_V2A_C1` is that `play` line spelled out. Others `fill`,
`selectVideoPage` or do arithmetic. A picture does not name a routine that also
makes a noise, so the body must now contain *nothing* but the one draw and the
`ret` — which is why the count is 210 and not 223.

## What it finds

Measured 2026-09-23:

```
793 label(s) whose body draws exactly one picture and rets

    465  constant still unnamed
    210  nameable
    116  label semantic and shares a subject word
      1  label semantic, no shared word (reported, not failed)
      1  label already agrees
```

The 210 break down 83 `chahi_amiga_1991`, 81 `dos_1992`, 46 `cartridge_1992`,
and the forms being retired are `DRAW_CV_<n>`, `LABEL_<hex>` and
`DRAW_CIN_<n>`.

## The word-overlap test is a prompt, not a verdict

The same comparison run the other way asks whether a *semantic* label shares a
subject word with the picture it draws. That is deliberately not a failure
condition. `CODEWHEEL_SYMBOL_DISPATCH_CASE_02` draws `CINEMATIC_ALIEN_GLYPH_01`
and shares nothing with it, and both names are right — one is the mechanism,
the other the subject. `HERO` and `LESTER` name the same character
(`docs/NAMING.md` §176), so those look like disagreements too.

With dispatches excluded, exactly one case survives across the whole tree:

```
dos_1992/CAVES    CAVES_DRAW_HERO_IDLE_LEFT_1    draws CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_0
```

and that one is settled by other evidence — `../laser-impact-anim/` shows the
picture is a 2.0 x 5.0 six-leaf spark, `canonical_md5` 80fe8a4c, identical to
amiga's first impact frame, and its only reference is the `jle [0x13], 0x01`
arm of the impact ladder. The label is the wrong one.

## Collisions are held, not resolved

Two labels in one file can draw the same picture — LAKE has a stand pose and a
walk frame that both finish on the same shadow — and they cannot both take its
name. Choosing between them is not this module's call (#0120), so neither is
proposed and both are listed under "the derived name is not free". The same
applies when the derived name already exists in the file.
