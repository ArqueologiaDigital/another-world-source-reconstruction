LABEL_0004:
	call CLEAR_PAGES_1_2_AND_BLIT
	mov [PAUSE_SLICES], 0x0002
	setup channel=0x3C, address=HANG_BLITTING_PAGE_FF
	setup channel=0x14, address=CAPSULE_DOME_CLOSING_REENTRY
	call LABEL_009D
	killChannel
	setup channel=0x09, address=LABEL_0E2F
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
	setup channel=0x04, address=TANK_WAIT_DECREMENT_VAR4F_LOOP
	setup channel=0x0A, address=TANK_INIT_PROJECTILE_POOL_CHANNELS_14_TO_25
	setup channel=0x0B, address=WAIT_VAR3E_DEC_AND_RANDOMIZE
	setup channel=0x0E, address=WAIT_VAR4E_PLAY_8C_DRAW_CIN_201
	setup channel=0x1C, address=LABEL_136E
	setup channel=0x1F, address=TANK_SHOT_ANIM_CIN_069_AT_205_118_TRIGGER_VAR57
	setup channel=0x20, address=TANK_WAIT_VAR57_THEN_SETUP_SHOT_CHANNELS_22_31
	setup channel=0x21, address=TANK_WAIT_FOR_VAR47_SET_CLEAR_AND_INIT_VAR48_49
	setup channel=0x22, address=WAIT_VAR56_PLAY_8E_DRAW_CIN_020
	setup channel=0x23, address=INIT_VAR1_NEG50_PLAY_8B_TWICE
	setup channel=0x24, address=TANK_WAIT_UNTIL_VAR41_POSITIVE_LOOP
	setup channel=0x25, address=TANK_DEC_VAR37_THEN_SET_VAR39_40_RESET_POSITION
	setup channel=0x28, address=TANK_WAIT_VAR63_THEN_RESET_PAGES_AND_UNFREEZE
	setup channel=0x2A, address=INLINE_SET_VAR6B_TO_50
	setup channel=0x2F, address=TANK_DEC_VAR69_THEN_SETUP_CIN_119_CH37
	setup channel=0x30, address=WAIT_VAR45_PLAY_8C_DRAW_CIN_011
	setup channel=0x31, address=WAIT_VAR46_PLAY_8E_DRAW_CIN_056
	setup channel=0x35, address=INLINE_SET_VAR66_TO_32
	setup channel=0x37, address=TANK_BG_DRAW_CIN_038_AT_6_126_AFTER_3_BREAKS
	call INIT_TANK_DRIVE_VARS
	call LABEL_1CA7
	setup channel=0x00, address=INIT_VARS_A_B_PAL_1
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
	setup channel=0x20, address=HANG_DRAW_CIN_037
	setup channel=0x28, address=HANG_DRAW_CIN_036
	setup channel=0x23, address=SETUP_TANK_HERO_VARS_PLAY_4SFX
	call INIT_TANK_DRIVE_VARS
	killChannel
	call TANK_SCENE_INIT_FILL_COLOR_0C_DRAW_BG

LABEL_009D:
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
