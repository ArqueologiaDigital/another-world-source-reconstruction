FIRST_SCREEN_TO_THE_RIGHT:
	mov [HACK_VAR_67], 0x0003
;@if BRANCH in ("cartridge_1992", "gba_2004")
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
;@endif
;@if BRANCH == "dos_1992"
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
;@endif
	call CYCLE_VIDEO_PAGES_3WAY
	setPalette 0x05
	je [0x66], 0x03, FIRST_SCREEN_R_BEAST_TRIGGER
	mov [0x66], 0x0003
	fill page=0x00, color=0x0E
	selectVideoPage 0x00
	call DRAW_SCENARIO_OF_FIRST_SCREEN_TO_THE_RIGHT
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF

FIRST_SCREEN_R_BEAST_TRIGGER:
	jne [0x2A], 0x01, FIRST_SCREEN_R_SETUP_CHANNELS
	mov [0x2A], 0x0002
	call COMPUTE_RANDOM_BIT_MASKS
	je [0x38], 0x00, FIRST_SCREEN_R_SETUP_CHANNELS
	mov [0x2A], 0x0003
	setup channel=0x07, address=THE_BEAST_WANDERS_ON_THE_FIRST_SCREEN_TO_THE_RIGHT

FIRST_SCREEN_R_SETUP_CHANNELS:
	setup channel=0x0B, address=MULTIPLEX_ANIM_RING1_SLOT_0
	setup channel=0x0C, address=BEAST_AI_DISPATCH_BY_X_AND_VAR_0D
	setup channel=0x0D, address=MULTIPLEX_ANIM_RING1_SLOT_1
	setup channel=0x0E, address=BEAST_AI_DISPATCH_BY_X_AND_VAR_0D
	setup channel=0x0F, address=MULTIPLEX_ANIM_RING1_SLOT_2
	setup channel=0x10, address=BEAST_AI_DISPATCH_BY_X_AND_VAR_0D
	setup channel=0x11, address=MULTIPLEX_ANIM_RING1_SLOT_3
	setup channel=0x12, address=BEAST_AI_DISPATCH_BY_X_AND_VAR_0D
	setup channel=0x13, address=MULTIPLEX_RING3_SAVE_LOOP
	setup channel=0x35, address=SCATTER_3DOT_BURST_LEFT
	setup channel=0x36, address=DRAW_8_SCATTER_DOTS_CYCLE
;@if BRANCH in ("cartridge_1992", "chahi_amiga_1991")
	setup channel=0x37, address=PARTICLE_BURST_7X_ENTRY
;@elif BRANCH in ("dos_1992", "gba_2004")
	setup channel=0x37, address=PARTICLE_BURST_7X_ENTRY
;@endif
	setup channel=0x38, address=PARTICLE_BURST_7X_LOOP
	call CLAMP_SCENE_INIT_X_VARS
	jmp CHECK_HERO_FIRST_SCR_R_EDGE
	killChannel

CLAMP_SCENE_INIT_X_VARS:
	mov [0x0C], [0x46]
	call CLAMP_HERO_X_TO_PLAYABLE_AREA
	mov [0x46], [0x0C]
	mov [0x0C], [0x49]
	call CLAMP_HERO_X_TO_PLAYABLE_AREA
	mov [0x49], [0x0C]
	mov [0x0C], [0x4C]
	call CLAMP_HERO_X_TO_PLAYABLE_AREA
	mov [0x4C], [0x0C]
	mov [0x0C], [0x4F]
	call CLAMP_HERO_X_TO_PLAYABLE_AREA
	mov [0x4F], [0x0C]
	mov [0x0C], [0x52]
	call CLAMP_HERO_X_TO_PLAYABLE_AREA
	mov [0x52], [0x0C]
	mov [0x0C], [0x55]
	call CLAMP_HERO_X_TO_PLAYABLE_AREA
	mov [0x55], [0x0C]
	mov [0x0C], [0x58]
	call CLAMP_HERO_X_TO_PLAYABLE_AREA
	mov [0x58], [0x0C]
	mov [0x0C], [0x5B]
	call CLAMP_HERO_X_TO_PLAYABLE_AREA
	mov [0x5B], [0x0C]
	ret

CLAMP_HERO_X_TO_PLAYABLE_AREA:
	jg [0x0C], 0x28, CLAMP_VAR_0C_HIGH
	mov [0x0C], 0x0028
	ret

CLAMP_VAR_0C_HIGH:
	jl [0x0C], 0x0118, RET_TARGET_1A88
	mov [0x0C], 0x0118

RET_TARGET_1A88:
	ret

SECOND_SCREEN_TO_THE_RIGHT:
	mov [HACK_VAR_67], 0x0004
;@if BRANCH in ("cartridge_1992", "gba_2004")
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
;@endif
;@if BRANCH == "dos_1992"
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
;@endif
	call CYCLE_VIDEO_PAGES_3WAY
	setPalette 0x05
	je [0x66], 0x04, SECOND_SCREEN_R_BEAST_TRIGGER
	mov [0x66], 0x0004
	fill page=0x00, color=0x0E
	selectVideoPage 0x00
	call DRAW_SCENARIO_OF_SECOND_SCREEN_TO_THE_RIGHT
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF

SECOND_SCREEN_R_BEAST_TRIGGER:
	jne [0x2A], 0x02, SECOND_SCREEN_R_SETUP_CHANNELS
	mov [0x2A], 0x0003
	setup channel=0x07, address=THE_BEAST_WANDERS_ON_THE_SECOND_SCREEN_TO_THE_RIGHT

SECOND_SCREEN_R_SETUP_CHANNELS:
	setup channel=0x0B, address=MULTIPLEX_ANIM_RING2_SLOT_0
	setup channel=0x0C, address=BEAST_AI_DISPATCH_BY_X_AND_VAR_0D
	setup channel=0x0D, address=MULTIPLEX_ANIM_RING2_SLOT_1
	setup channel=0x0E, address=BEAST_AI_DISPATCH_BY_X_AND_VAR_0D
	setup channel=0x0F, address=MULTIPLEX_ANIM_RING2_SLOT_2
	setup channel=0x10, address=BEAST_AI_DISPATCH_BY_X_AND_VAR_0D
	setup channel=0x11, address=MULTIPLEX_RING4_SAVE_LOOP
	setup channel=0x12, address=BEAST_AI_DISPATCH_BY_X_AND_VAR_0D
	setup channel=0x13, address=MULTIPLEX_RING5_SAVE_LOOP
	setup channel=0x36, address=SCATTER_3DOT_BURST_RIGHT
	setup channel=0x37, address=DRAW_8_SCATTER_DOTS_CYCLE
	setup channel=0x38, address=LOOP_DRAW_LAKE_018_AT_CENTER
	call CLAMP_SCENE_INIT_X_VARS
	jmp CHECK_HERO_SECOND_SCR_R_EDGE
	killChannel

THIRD_SCREEN_TO_THE_RIGHT:
	mov [HACK_VAR_67], 0x0005
;@if BRANCH in ("cartridge_1992", "gba_2004")
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
;@endif
;@if BRANCH == "dos_1992"
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
;@endif
	call CYCLE_VIDEO_PAGES_3WAY
	setPalette 0x07
	je [0x66], 0x05, THIRD_SCREEN_R_BEAST_TRIGGER
	mov [0x66], 0x0005
	fill page=0x00, color=0x0E
	selectVideoPage 0x00
	call DRAW_SCENARIO_OF_THIRD_SCREEN_TO_THE_RIGHT
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF

THIRD_SCREEN_R_BEAST_TRIGGER:
	jne [0x2A], 0x03, THIRD_SCREEN_R_SETUP_CHANNELS
	setup channel=0x28, address=WAIT_BEAST_TRIGGER_THEN_INIT

THIRD_SCREEN_R_SETUP_CHANNELS:
	setup channel=0x01, address=DROPLET_DRIP_LOOP_RANDOM_X
	jmp CHECK_HERO_THIRD_SCR_R_EDGE
	killChannel

