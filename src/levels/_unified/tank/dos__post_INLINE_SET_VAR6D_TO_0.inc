LABEL_0004:
	call CLEAR_PAGES_1_2_AND_BLIT
	mov [PAUSE_SLICES], 0x0002
	setup channel=0x3C, address=HANG_BLITTING_PAGE_FF
	setup channel=0x14, address=LABEL_03FF
	call LABEL_009D
	killChannel
	setup channel=0x09, address=LABEL_0E2F
	killChannel
	jmp LABEL_03FF

LABEL_001F:
	setup channel=0x3C, address=BLITTER_LOOP_COPY_PAGE_03
	setup channel=0x02, address=LABEL_1BDA
	setup channel=0x04, address=LABEL_15E3
	setup channel=0x0A, address=LABEL_1924
	setup channel=0x0B, address=WAIT_VAR3E_DEC_AND_RANDOMIZE
	setup channel=0x0E, address=WAIT_VAR4E_PLAY_8C_DRAW_CIN_201
	setup channel=0x1C, address=LABEL_136E
	setup channel=0x1F, address=LABEL_10C7
	setup channel=0x20, address=LABEL_105D
	setup channel=0x21, address=LABEL_121F
	setup channel=0x22, address=WAIT_VAR56_PLAY_8E_DRAW_CIN_020
	setup channel=0x23, address=INIT_VAR1_NEG50_PLAY_8B_TWICE
	setup channel=0x24, address=LABEL_17AB
	setup channel=0x25, address=LABEL_1421
	setup channel=0x28, address=LABEL_0866
	setup channel=0x2A, address=INLINE_SET_VAR6B_TO_50
	setup channel=0x2F, address=LABEL_0743
	setup channel=0x30, address=WAIT_VAR45_PLAY_8C_DRAW_CIN_011
	setup channel=0x31, address=WAIT_VAR46_PLAY_8E_DRAW_CIN_056
	setup channel=0x35, address=INLINE_SET_VAR66_TO_32
	setup channel=0x37, address=LABEL_1323
	call INIT_TANK_DRIVE_VARS
	call LABEL_1CA7
	setup channel=0x00, address=INIT_VARS_A_B_PAL_1
	killChannel

LABEL_007E:
	setup channel=0x3C, address=BLITTER_LOOP_COPY_PAGE_03
	setup channel=0x02, address=LABEL_1BDA
	setup channel=0x00, address=LABEL_1CDC
	setup channel=0x20, address=HANG_DRAW_CIN_037
	setup channel=0x28, address=HANG_DRAW_CIN_036
	setup channel=0x23, address=SETUP_TANK_HERO_VARS_PLAY_4SFX
	call INIT_TANK_DRIVE_VARS
	killChannel
	call LABEL_1CC1

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
