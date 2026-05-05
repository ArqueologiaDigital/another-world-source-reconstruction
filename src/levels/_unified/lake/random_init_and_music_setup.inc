COMPUTE_RANDOM_BIT_MASKS:
	add [0x37], [HERO_X]
	add [0x37], [HERO_ACTION_POS_MASK]
	add [0x37], [0x0C]
	add [0x37], [0x04]
	mov [0x38], [0x37]
	mov [0x3F], [0x38]
	mov [0x3E], [0x38]
	mov [0x3D], [0x38]
	mov [RANDOM_SEED], [0x38]
	mov [0x3B], [0x38]
	mov [0x3A], [0x38]
	mov [0x39], [0x38]
	and [0x3F], 0x00FF
	and [0x3E], 0x007F
	and [0x3D], 0x003F
	and [RANDOM_SEED], 0x001F
	and [0x3B], 0x000F
	and [0x3A], 0x0007
	and [0x39], 0x0003
	and [0x38], 0x0001
	ret

INIT_LAKE_VARS:
	mov [0x2A], 0x0000
	mov [0x2B], 0x0000
	mov [0x5E], 0x0000
	mov [0x1B], 0x0000
	mov [0x2C], 0x0002
	mov [0x2D], 0x0004
	mov [0x46], 0x00AA
	mov [0x47], 0x00B7
	mov [0x4A], 0x0000
	mov [0x4D], 0x0000
	mov [0x50], 0x0000
	mov [0x52], 0x00A0
	mov [0x53], 0x00B7
	mov [0x55], 0x0064
	mov [0x56], 0x00B7
	mov [0x58], 0x00C8
	mov [0x59], 0x00B7
	mov [0x5C], 0x0000
	mov [SCROLL_Y], 0x0002
	mov [0x1C], 0x0001
	mov [0x6E], 0x0000
;@if BRANCH in ("cartridge_1992", "gba_2004")
	je [0xE2], 0x00, RET_TARGET_1A88
	mov [0x2C], 0x0001
	mov [0x2D], 0x0001
	mov [0x49], 0x00C8
	mov [0x4A], 0x00B7
;@endif
	ret

INIT_CODEWHEEL_PROTECTION_SCENE:
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
	call VERIFY_INTEGRITY_OR_HALT
	mov [PAUSE_SLICES], 0x0004
	mov [0x65], 0x0000
	mov [0x66], 0x0000
	setup channel=0x3F, address=START_LAKE_BG_MUSIC_AND_DELETE_CH_0_2
	killChannel

START_LAKE_BG_MUSIC_AND_DELETE_CH_0_2:
	call INIT_LAKE_VARS
;@if BRANCH == "gba_2004"
	song id=0x0FA2, delay=0x0000, pos=0x03
;@endif
;@if BRANCH in ("cartridge_1992", "gba_2004")
	song id=0x0BB9, delay=0x0000, pos=0x00
;@endif
	deleteChannels first=0x00, last=0x02
	deleteChannels first=0x04, last=0x3B
	deleteChannels first=0x3D, last=0x3E
	setup channel=0x01, address=INIT_HERO_AT_POOL_EXIT
	setup channel=0x14, address=GETTING_OUT_OF_THE_POOL__ANIMATION_PART_4
	setup channel=0x09, address=BEETLE_INIT_POS_THEN_WALK_LEFT
;@if BRANCH in ("cartridge_1992", "gba_2004")
	setup channel=0x09, address=KILL_CHANNEL_ROUTINE
;@endif
;@if BRANCH == "dos_1992"
	setup channel=0x09, address=KILL_CHANNEL_ROUTINE
;@endif
	setup channel=0x2E, address=BEETLE_KICK_DETECTOR
	setup channel=0x2E, address=WAIT_FOR_BEETLE_OFFSCREEN_THEN_KILL
	setup channel=0x2F, address=INC_VAR_6E_PER_TICK_LOOP
	setup channel=0x30, address=WAIT_FOR_TIMER_AND_HACK_67_THEN_SETUP_31
	setup channel=0x24, address=AMBIENT_LOOP_CH24
	setup channel=0x25, address=AMBIENT_LOOP_CH25
	jmp OUTSIDE_POOL_SCREEN
	killChannel

RANDOM_AMBIENT_SOUND_LOOP:
	call COMPUTE_RANDOM_BIT_MASKS
	mov [0x24], [0x3A]
	add [0x24], 0x0028
	call PLAY_RANDOM_AMBIENT_SOUND

