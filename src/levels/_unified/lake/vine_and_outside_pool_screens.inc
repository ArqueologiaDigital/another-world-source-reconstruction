VINE_SCREEN:
	mov [HACK_VAR_67], 0x0001
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
;@endif
	call CYCLE_VIDEO_PAGES_3WAY
	setPalette 0x09
	je [0x66], 0x01, VINE_SCREEN_AFTER_BG_INIT
	mov [0x66], 0x0001
	fill page=0x00, color=0x02
	selectVideoPage 0x00
	call DRAW_SCENARIO_OF_VINE_SCREEN
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF

VINE_SCREEN_AFTER_BG_INIT:
	setup channel=0x38, address=LOOP_DRAW_VINE_FG
	je [0x5E], 0x01, VINE_SCREEN_AFTER_VINE_FG
	setup channel=0x04, address=LOOP_DRAW_CINEMATIC_VINE_SCREEN_BG_DECOR_AT_CENTER

VINE_SCREEN_AFTER_VINE_FG:
	jne [0x2A], 0x04, VINE_SCREEN_AFTER_BEAST_AI
	setup channel=0x28, address=BEAST_AI_SPAWN_FAR_RIGHT

VINE_SCREEN_AFTER_BEAST_AI:
	setup channel=0x01, address=DROPLET_FALL_AND_IMPACT_LOOP
	jmp CHECK_HERO_LAKE_EDGE
	killChannel

OUTSIDE_POOL_SCREEN:
	mov [HACK_VAR_67], 0x0002
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
;@endif
	call CYCLE_VIDEO_PAGES_3WAY
	setPalette 0x07
	je [0x66], 0x02, VINE_SCREEN_BEAST_TRIGGER_CHK
	mov [0x66], 0x0002
	fill page=0x00, color=0x0E
	selectVideoPage 0x00
	call DRAW_OUTSIDE_POOL_SCENARIO
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF

VINE_SCREEN_BEAST_TRIGGER_CHK:
	jne [0x2A], 0x00, VINE_SCREEN_SETUP_CHANNELS
	mov [0x2A], 0x0001
	setup channel=0x07, address=THE_BEAST_APPEARS_FOR_THE_FIRST_TIME_IN_THE_BACKGROUND

VINE_SCREEN_SETUP_CHANNELS:
	setup channel=0x02, address=SCATTER_8DOT_LOOP_LEFT
	setup channel=0x03, address=SCATTER_8DOT_LOOP_RIGHT
	setup channel=0x05, address=PLAYBACK_CINEMATIC_TENTACLE_RETREAT_F0_TO_513
	setup channel=0x08, address=SNEAKY_TENTACLE_FROM_THE_POOL
	setup channel=0x33, address=SCATTER_3DOTS_INIT_RIGHT
	setup channel=0x34, address=KILL_CHANNEL_ROUTINE
	setup channel=0x35, address=SCATTER_DOTS_BURST_RIGHT_SEQ
	setup channel=0x36, address=KILL_CHANNEL_ROUTINE
	setup channel=0x37, address=SCATTER_8DOT_F3_BLINK_LOOP
	setup channel=0x38, address=REED_PLANT_ANIMATION
	jmp CHECK_HERO_VINE_SCREEN_EDGE
	killChannel

