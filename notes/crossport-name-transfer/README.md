# 66 names msdos/INTRO has earned and cannot take

amiga/INTRO is **80.7%** named and msdos/INTRO **33.9%**. The names exist; the
question is which of msdos's 377 numeric constants they belong to. This
records the answer for 66 of them, and why applying it is blocked.

## How the 66 were matched

By **offset**, never by index, and with a second condition:

* the msdos constant at the **same offset** in its own cinematic bank, **and**
* a **byte-identical render** at palette 2.

Both, because a shared offset alone is not enough. Three offsets in this stage
are shared and render differently -- `0xF192` (amiga
`CINEMATIC_EXPERIMENT_LIGHTNING_STRIKE_F8`, 1 path, against msdos
`CINEMATIC_190`, 3 paths), `0xAE54` (3 against 2) and `0xE448` (21 against
24). Those three are excluded, and they are the reason the render check is not
ceremony.

## The blocker

**All 66 are referenced from shared chunks** under `src/levels/_unified/intro/`
-- `intro_scene_final.inc`, `intro_particle_channels.inc`,
`intro_lab_decor_late_phase.inc`, `intro_lake_transition.inc`,
`intro_late_pages_fill.inc`, `intro_reset_and_lab_decor.inc` and
`intro_scene_final_fx_phase.inc`. A branch-scoped rename on msdos leaves those
lines resolving to a name only amiga defines, and an undefined symbol
assembles silently (#0073): applying them dropped `verify-unified` from 29/29
to **26/29** and the change was backed out.

`--agreeing` is **not** the way out either, and this is the trap worth naming.
It renames on every branch, which is correct when both ports' constants are
the same art under the same index. Here they are not: a shared chunk says
`CINEMATIC_005`, which on amiga is one picture and on msdos is a different
one -- exactly the "two pictures under one label" structure
`notes/t7-cv-offset-rekey/` documents for the shared video bank. Renaming
everywhere would put msdos's earned name on amiga's unrelated constant.

So these 66 need either per-site branch arms (`apply_branch_scoped_names.py
--arm`), which de-unifies the seven chunks, or the emitter-level fix that T7
also waits on. The decision is the same one, and it is not a naming decision.

## The mapping, so the work is not lost

| msdos constant | amiga name | shared offset |
|---|---|---|
| `CINEMATIC_053` | `CINEMATIC_CARPARK_NEAR_PILLAR` | 0x1742 |
| `CINEMATIC_108` | `CINEMATIC_CARPARK_PILLAR_LIT_FACE` | 0x17BE |
| `CINEMATIC_107` | `CINEMATIC_CARPARK_PILLAR_MID_SHADE` | 0x17A2 |
| `CINEMATIC_106` | `CINEMATIC_CARPARK_PILLAR_OUTER_SHADE` | 0x177E |
| `CINEMATIC_105` | `CINEMATIC_CARPARK_WALL_DOORWAY_RECESS` | 0x1762 |
| `CINEMATIC_104` | `CINEMATIC_CARPARK_WALL_FACE` | 0x1752 |
| `CINEMATIC_006` | `CINEMATIC_CAR_DRIVING_AWAY_FROM_CAMERA_F0` | 0x0404 |
| `CINEMATIC_008` | `CINEMATIC_CAR_DRIVING_AWAY_FROM_CAMERA_F1` | 0x0410 |
| `CINEMATIC_024` | `CINEMATIC_CAR_DRIVING_AWAY_FROM_CAMERA_F10` | 0x04F4 |
| `CINEMATIC_026` | `CINEMATIC_CAR_DRIVING_AWAY_FROM_CAMERA_F11` | 0x0510 |
| `CINEMATIC_027` | `CINEMATIC_CAR_DRIVING_AWAY_FROM_CAMERA_F12` | 0x0548 |
| `CINEMATIC_029` | `CINEMATIC_CAR_DRIVING_AWAY_FROM_CAMERA_F13` | 0x0568 |
| `CINEMATIC_030` | `CINEMATIC_CAR_DRIVING_AWAY_FROM_CAMERA_F14` | 0x0590 |
| `CINEMATIC_032` | `CINEMATIC_CAR_DRIVING_AWAY_FROM_CAMERA_F15` | 0x05B8 |
| `CINEMATIC_010` | `CINEMATIC_CAR_DRIVING_AWAY_FROM_CAMERA_F2` | 0x041C |
| `CINEMATIC_012` | `CINEMATIC_CAR_DRIVING_AWAY_FROM_CAMERA_F3` | 0x0428 |
| `CINEMATIC_014` | `CINEMATIC_CAR_DRIVING_AWAY_FROM_CAMERA_F4` | 0x0438 |
| `CINEMATIC_015` | `CINEMATIC_CAR_DRIVING_AWAY_FROM_CAMERA_F5` | 0x044C |
| `CINEMATIC_017` | `CINEMATIC_CAR_DRIVING_AWAY_FROM_CAMERA_F6` | 0x0460 |
| `CINEMATIC_019` | `CINEMATIC_CAR_DRIVING_AWAY_FROM_CAMERA_F7` | 0x0470 |
| `CINEMATIC_021` | `CINEMATIC_CAR_DRIVING_AWAY_FROM_CAMERA_F8` | 0x048C |
| `CINEMATIC_023` | `CINEMATIC_CAR_DRIVING_AWAY_FROM_CAMERA_F9` | 0x04B0 |
| `CINEMATIC_009` | `CINEMATIC_CAR_SHADOW_F0` | 0x083C |
| `CINEMATIC_011` | `CINEMATIC_CAR_SHADOW_F1` | 0x0858 |
| `CINEMATIC_013` | `CINEMATIC_CAR_SHADOW_F2` | 0x0874 |
| `CINEMATIC_016` | `CINEMATIC_CAR_SHADOW_F3` | 0x088C |
| `CINEMATIC_018` | `CINEMATIC_CAR_SHADOW_F4` | 0x089C |
| `CINEMATIC_020` | `CINEMATIC_CAR_SHADOW_F5` | 0x08B0 |
| `CINEMATIC_022` | `CINEMATIC_CAR_SHADOW_F6` | 0x08C4 |
| `CINEMATIC_025` | `CINEMATIC_CAR_SHADOW_F7` | 0x08D8 |
| `CINEMATIC_028` | `CINEMATIC_CAR_SHADOW_F8` | 0x08EC |
| `CINEMATIC_007` | `CINEMATIC_CAR_TAIL_LIGHT_PAIR` | 0x0938 |
| `CINEMATIC_549` | `CINEMATIC_CITY_DARK_WINDOW` | 0x0D98 |
| `CINEMATIC_562` | `CINEMATIC_CITY_DISTANT_TOWER_0` | 0x0D30 |
| `CINEMATIC_563` | `CINEMATIC_CITY_DISTANT_TOWER_1` | 0x0D64 |
| `CINEMATIC_569` | `CINEMATIC_CITY_FOREGROUND_GIRDER_BOTTOM_BRACE` | 0x17FE |
| `CINEMATIC_005` | `CINEMATIC_CITY_FOREGROUND_GIRDER_MID_ARM` | 0x0CB8 |
| `CINEMATIC_568` | `CINEMATIC_CITY_FOREGROUND_GIRDER_POST_LOWER` | 0x0E26 |
| `CINEMATIC_567` | `CINEMATIC_CITY_FOREGROUND_GIRDER_POST_UPPER` | 0x0E1A |
| `CINEMATIC_566` | `CINEMATIC_CITY_FOREGROUND_GIRDER_TOP_ARM` | 0x0E0E |
| `CINEMATIC_540` | `CINEMATIC_CITY_GANTRY_BRACE_0` | 0x0B4A |
| `CINEMATIC_541` | `CINEMATIC_CITY_GANTRY_BRACE_1` | 0x0B56 |
| `CINEMATIC_542` | `CINEMATIC_CITY_GANTRY_BRACE_2` | 0x0B62 |
| `CINEMATIC_543` | `CINEMATIC_CITY_GANTRY_BRACE_3` | 0x0B6E |
| `CINEMATIC_536` | `CINEMATIC_CITY_GANTRY_CROSS_BRACING` | 0x0C88 |
| `CINEMATIC_538` | `CINEMATIC_CITY_GANTRY_LATTICE` | 0x0BFC |
| `CINEMATIC_539` | `CINEMATIC_CITY_GANTRY_MAST` | 0x0A84 |
| `CINEMATIC_554` | `CINEMATIC_CITY_PYRAMID_TOWER_FAR_EDGE` | 0x0A74 |
| `CINEMATIC_552` | `CINEMATIC_CITY_PYRAMID_TOWER_LIT_EDGE` | 0x09B6 |
| `CINEMATIC_546` | `CINEMATIC_CITY_SKYLINE_BACKDROP_0` | 0x073C |
| `CINEMATIC_547` | `CINEMATIC_CITY_SKYLINE_BACKDROP_1` | 0x071C |
| `CINEMATIC_545` | `CINEMATIC_CITY_SKYLINE_GROUND_LINE` | 0x0704 |
| `CINEMATIC_550` | `CINEMATIC_CITY_SKYLINE_RIDGE_SHADE_0` | 0x0748 |
| `CINEMATIC_551` | `CINEMATIC_CITY_SKYLINE_RIDGE_SHADE_1` | 0x075C |
| `CINEMATIC_537` | `CINEMATIC_CITY_SKY_CLOUD_BANK` | 0x0A90 |
| `CINEMATIC_553` | `CINEMATIC_CITY_SKY_CLOUD_WISP` | 0x0B2A |
| `CINEMATIC_548` | `CINEMATIC_CITY_TOWER_BLOCK` | 0x094C |
| `CINEMATIC_555` | `CINEMATIC_CITY_TOWER_BLOCK_BASE` | 0x0A64 |
| `CINEMATIC_557` | `CINEMATIC_CITY_WINDOW_LIGHTS_0` | 0x09CA |
| `CINEMATIC_558` | `CINEMATIC_CITY_WINDOW_LIGHTS_1` | 0x09F2 |
| `CINEMATIC_559` | `CINEMATIC_CITY_WINDOW_LIGHTS_2` | 0x0A24 |
| `CINEMATIC_535` | `CINEMATIC_LIFT_SCENE_BG` | 0x0830 |
| `CINEMATIC_530` | `CINEMATIC_LIFT_SCENE_VIEW` | 0x2346 |
| `CINEMATIC_182` | `CINEMATIC_PARTICLE_LAB_BG_F3` | 0x3F6C |
| `CINEMATIC_444` | `CINEMATIC_PARTICLE_LAB_HOLO_CONSOLE_LED_2` | 0x0818 |
| `CINEMATIC_446` | `CINEMATIC_PARTICLE_LAB_HOLO_CONSOLE_LED_4` | 0x0678 |
