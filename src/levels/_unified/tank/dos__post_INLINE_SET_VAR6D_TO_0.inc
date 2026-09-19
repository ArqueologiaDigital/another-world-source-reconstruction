TANK_STAGE_BOOT_ENTRY:
	call CLEAR_PAGES_1_2_AND_BLIT
	mov [PAUSE_SLICES], 0x0002
	setup channel=0x3C, address=HANG_BLITTING_PAGE_FF
	setup channel=0x14, address=CAPSULE_DOME_CLOSING_REENTRY
	call LOAD_TANK_STAGE_SOUND_SAMPLES
	killChannel
	setup channel=0x09, address=TANK_ARRIVAL_CUTSCENE_ENTRY
	killChannel
	jmp CAPSULE_DOME_CLOSING_REENTRY

; The main TANK stage init. Sets up ~10 channels (renderer,
; cinematic players, projectile state machines, sound
; ambient) — the canonical entry point that boots all the
; independent sub-systems running concurrently in the tank
; arena.
TANK_STAGE_BOOT_SETUP_CHANNELS:
	setup channel=0x3C, address=BLITTER_LOOP_COPY_PAGE_03
	setup channel=0x02, address=TANK_BG_ANIM_CIN221_222_BOOT_CHANNEL_02
	setup channel=0x04, address=TANK_GROUND_DEBRIS_WAIT_LOOP
	setup channel=0x0A, address=TANK_INIT_PROJECTILE_POOL_CHANNELS_14_TO_25
	setup channel=0x0B, address=TANK_AMBIENT_RANDOM_DELAY_PLAY_SOUND_8C
	setup channel=0x0E, address=TANK_GROUND_DEBRIS_BURST_LOOP
	setup channel=0x1C, address=TANK_ARENA_CREATURE_RUN_INIT
	setup channel=0x1F, address=TANK_SALVO_TRAIL_CLIMB_THEN_STRIKE
	setup channel=0x20, address=TANK_SALVO_TRAIL_CLIMB_AND_SPAWN_BURSTS
	setup channel=0x21, address=TANK_MISSILE_LAUNCH_TRIGGER_INIT
	setup channel=0x22, address=TANK_PROJECTILE_ARC_AND_EXPLOSION
	setup channel=0x23, address=INIT_VAR1_NEG50_PLAY_8B_TWICE
	setup channel=0x24, address=TANK_BEAM_GUN_WAIT_LOOP
	setup channel=0x25, address=TANK_ARENA_GUN_ACTIVATION_WAIT_INIT
	setup channel=0x28, address=TANK_ARENA_EXIT_CAPSULES_RISE_TO_BATHS
	setup channel=0x2A, address=TANK_ARENA_COUNTDOWN_ENTRY
	setup channel=0x2F, address=TANK_ARENA_ATTACK_ARM_AFTER_DELAY
	setup channel=0x30, address=TANK_CANNON_IMPACT_PLUME_LOOP
	setup channel=0x31, address=TANK_SHOT_LAUNCH_STREAK_ON_FIRE_TRIGGER
	setup channel=0x35, address=TANK_ARENA_AMBIENT_LASER_FIRE_INIT
	setup channel=0x37, address=TANK_ARENA_CREATURE_CHARGE_PAST
	call INIT_TANK_DRIVE_VARS
	call TANK_DRAW_CIN_6_27_28_ON_PAGE_0_AND_3
	setup channel=0x00, address=TANK_BACKDROP_SWAY_CYCLE_INIT
	killChannel

; Sets up the tank-driving scene's channel layout: channel
; 0x3C runs TANK_FRAME_RENDER_FROM_PAGE_3_LOOP, channel
; 0x02 runs the per-tick movement, etc. Called after the
; capsule-dome closes (CAPSULE_DOME_CLOSING_LATE_FRAMES
; ends in jmp TANK_DRIVE_SCENE_INIT).
TANK_DRIVE_SCENE_INIT:
	setup channel=0x3C, address=BLITTER_LOOP_COPY_PAGE_03
	setup channel=0x02, address=TANK_BG_ANIM_CIN221_222_BOOT_CHANNEL_02
	setup channel=0x00, address=TANK_SCENE_INIT_CALL_DRAW_BG_THEN_PAL_1
	setup channel=0x20, address=TANK_ARENA_ENTRY_WALL_REDRAW_LOOP
	setup channel=0x28, address=TANK_ARENA_ENTRY_WALL_OCCLUDER_REDRAW_LOOP
	setup channel=0x23, address=SETUP_TANK_HERO_VARS_PLAY_4SFX
	call INIT_TANK_DRIVE_VARS
	killChannel
	call TANK_SCENE_INIT_FILL_COLOR_0C_DRAW_BG

LOAD_TANK_STAGE_SOUND_SAMPLES:
	load id=0x0052
	load id=0x0084
	load id=0x008B
	load id=0x008C
	load id=0x008E
	load id=0x005C
	load id=0x0058
	load id=0x0057
	load id=0x0059
	load id=0x005B
	ret
