TANK_ARENA_COUNTDOWN_CANCEL_AFTER_SALVO:
	setup channel=0x34, address=RESET_PAGES_AND_SETUP_CH_0A
	mov [0x6B], 0x0019
	killChannel
	jmp TANK_ARENA_COUNTDOWN_ENTRY

TANK_DESTROYED_CUTSCENE_BLAST_ENTRY:
	video offset=CINEMATIC_TANK_DESTROYED_READOUT_F0, x=160, y=100
	video offset=CINEMATIC_TANK_DESTROYED_READOUT_F1, x=160, y=100
	break
	video offset=CINEMATIC_TANK_DESTROYED_READOUT_F0, x=160, y=100
	video offset=CINEMATIC_TANK_DESTROYED_READOUT_F2, x=160, y=100
	break
	video offset=CINEMATIC_TANK_DESTROYED_READOUT_F0, x=160, y=100
	video offset=CINEMATIC_TANK_DESTROYED_READOUT_F3, x=160, y=100
	break
	video offset=CINEMATIC_TANK_DESTROYED_READOUT_F4, x=160, y=100
	break
	setup channel=0x2F, address=TANK_DESTROYED_WRECK_AND_DEBRIS_FADE
	setup channel=0x3C, address=PALETTE_FLASH_1F_TO_01
	setup channel=0x39, address=RESET_PAGES_AND_SETUP_CH_0A
	setup channel=0x3B, address=RESET_PAGES_AND_SETUP_CH_0A
	setup channel=0x01, address=RESET_PAGES_AND_SETUP_CH_0A
	mov [0x37], 0x0000
	mov [0x41], 0x0000
	break
	video offset=CINEMATIC_TANK_DESTROYED_SHARDS, x=160, y=100
	killChannel

TANK_ARENA_STAMP_WRECK_LEFT_ONTO_BACKDROP:
	video offset=CINEMATIC_TANK_ARENA_WRECK_BASE, x=110, y=150
	selectVideoPage 0x00
	video offset=CINEMATIC_TANK_ARENA_WRECK_LEFT, x=160, y=100
	selectVideoPage 0xFF
	selectVideoPage 0x03
	video offset=CINEMATIC_TANK_ARENA_WRECK_LEFT, x=160, y=100
	selectVideoPage 0xFF
	killChannel

TANK_ARENA_STAMP_WRECK_CENTRE_ONTO_BACKDROP:
	video offset=CINEMATIC_TANK_ARENA_WRECK_BASE, x=155, y=151
	selectVideoPage 0x00
	video offset=CINEMATIC_TANK_ARENA_WRECK_CENTRE, x=160, y=100
	selectVideoPage 0xFF
	selectVideoPage 0x03
	video offset=CINEMATIC_TANK_ARENA_WRECK_CENTRE, x=160, y=100
	selectVideoPage 0xFF
	killChannel

TANK_ARENA_ATTACK_RIGHT_EDGE_REDRAW_LOOP:
	video offset=CINEMATIC_TANK_ARENA_ATTACK_RIGHT_EDGE_REDRAW, x=160, y=100
	break
	jmp TANK_ARENA_ATTACK_RIGHT_EDGE_REDRAW_LOOP

TANK_ARENA_ATTACK_BLAST_SEQUENCE:
	video offset=CINEMATIC_TANK_ARENA_BLAST_RIGHT_F0, x=160, y=100
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x00
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x01
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x02
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_TANK_ARENA_BLAST_RIGHT_F1, x=160, y=100
	break
	video offset=CINEMATIC_TANK_ARENA_BLAST_RIGHT_F2, x=160, y=100
	break
	video offset=CINEMATIC_TANK_ARENA_BLAST_RIGHT_F1, x=160, y=100
	break
	video offset=CINEMATIC_TANK_ARENA_BLAST_RIGHT_F3, x=160, y=100
	video offset=CINEMATIC_TANK_ARENA_BLAST_LEFT_F0, x=160, y=100
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x00
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x01
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x02
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_TANK_ARENA_BLAST_RIGHT_F1, x=160, y=100
	video offset=CINEMATIC_TANK_ARENA_BLAST_LEFT_F1, x=160, y=100
	play id=0x0059, freq=0x12, vol=0x3F, channel=0x00
	play id=0x0059, freq=0x14, vol=0x3F, channel=0x01
	play id=0x0059, freq=0x14, vol=0x3F, channel=0x02
	play id=0x0059, freq=0x12, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_TANK_ARENA_BLAST_RIGHT_F2, x=160, y=100
	video offset=CINEMATIC_TANK_ARENA_BLAST_LEFT_F2, x=160, y=100
	break
	video offset=CINEMATIC_TANK_ARENA_BLAST_RIGHT_F4, x=160, y=100
	video offset=CINEMATIC_TANK_ARENA_BLAST_LEFT_F3, x=160, y=100
	break
	video offset=CINEMATIC_TANK_ARENA_BLAST_RIGHT_F5, x=160, y=100
	video offset=CINEMATIC_TANK_ARENA_BLAST_LEFT_F2, x=160, y=100
	break
	video offset=CINEMATIC_TANK_ARENA_BLAST_RIGHT_F6, x=160, y=100
	video offset=CINEMATIC_TANK_ARENA_BLAST_LEFT_F4, x=160, y=100
	break
	video offset=CINEMATIC_TANK_ARENA_BLAST_RIGHT_F5, x=160, y=100
	video offset=CINEMATIC_TANK_ARENA_BLAST_LEFT_F2, x=160, y=100
	break
	video offset=CINEMATIC_TANK_ARENA_BLAST_RIGHT_F7, x=160, y=100
	video offset=CINEMATIC_TANK_ARENA_BLAST_LEFT_F3, x=160, y=100
	break
	video offset=CINEMATIC_TANK_ARENA_BLAST_RIGHT_F5, x=160, y=100
	video offset=CINEMATIC_TANK_ARENA_BLAST_LEFT_F2, x=160, y=100
	break
	jmp TANK_ARENA_ATTACK_FINAL_HIT_UNLESS_ESCAPED
LABEL_0742:
	db 0x11

TANK_ARENA_ATTACK_ARM_AFTER_DELAY:
	break
	sub [0x69], 0x0001
	jg [0x69], 0x00, TANK_ARENA_ATTACK_ARM_AFTER_DELAY
	setup channel=0x37, address=TANK_ARENA_ATTACK_RIGHT_EDGE_REDRAW_LOOP
	setup channel=0x35, address=TANK_ARENA_ATTACK_BLAST_SEQUENCE
	killChannel

TANK_ARENA_ATTACK_FINAL_HIT_UNLESS_ESCAPED:
	je [0x63], 0x01, RESET_PAGES_AND_SETUP_CH_0A
	video offset=CINEMATIC_088, x=160, y=100
	video offset=CINEMATIC_089, x=160, y=100
	setup channel=0x39, address=RESET_PAGES_AND_SETUP_CH_0A
	setup channel=0x3B, address=RESET_PAGES_AND_SETUP_CH_0A
	setup channel=0x01, address=RESET_PAGES_AND_SETUP_CH_0A
	mov [0x37], 0x0000
	mov [0x41], 0x0000
	break
	setup channel=0x3C, address=PALETTE_FLASH_1F_TO_01
	video offset=CINEMATIC_090, x=160, y=100

TANK_DESTROYED_WRECK_AND_DEBRIS_FADE:
	play id=0x008C, freq=0x14, vol=0x3F, channel=0x00
	play id=0x008C, freq=0x07, vol=0x3F, channel=0x01
	play id=0x008C, freq=0x14, vol=0x3F, channel=0x02
	play id=0x008C, freq=0x07, vol=0x3F, channel=0x03
	selectVideoPage 0x03
	selectVideoPage 0x00
	video offset=CINEMATIC_091, x=160, y=100
	video offset=CINEMATIC_092, x=160, y=100
	selectVideoPage 0xFF
	selectVideoPage 0x03
	video offset=CINEMATIC_091, x=160, y=100
	selectVideoPage 0x00
	video offset=CINEMATIC_093, x=160, y=100
	selectVideoPage 0xFF
	setup channel=0x02, address=RESET_PAGES_AND_SETUP_CH_0A
	break
	setPalette 0x01
	video offset=CINEMATIC_094, x=160, y=100
	break
	video offset=CINEMATIC_095, x=160, y=100
	break
	video offset=CINEMATIC_096, x=160, y=100
	break
	video offset=CINEMATIC_097, x=160, y=100
	break
	video offset=CINEMATIC_098, x=160, y=100
	break
	video offset=CINEMATIC_099, x=160, y=100
	break
	video offset=CINEMATIC_100, x=160, y=100
	break
	video offset=CINEMATIC_101, x=160, y=100
	break
	video offset=CINEMATIC_102, x=160, y=100
	break
	video offset=CINEMATIC_103, x=160, y=100
	break
	video offset=CINEMATIC_104, x=160, y=100
	break
	video offset=CINEMATIC_105, x=160, y=100
	break
	setup channel=0x3F, address=TANK_DESTROYED_HALT_AND_ARM_CONTINUE_SCREEN
	killChannel

TANK_DESTROYED_HALT_AND_ARM_CONTINUE_SCREEN:
	break
	freezeChannels first=0x00, last=0x3F
	deleteChannels first=0x00, last=0x3F
	mov [SCROLL_Y], 0x0064
	copyVideoPage src=0x80, dst=0x03
	setup channel=0x00, address=TANK_CONTINUE_SCREEN_INIT
	mov [0x6D], 0x0001
	killChannel

TANK_CONTINUE_SCREEN_INIT:
	fill page=0x00, color=0x00
	fill page=0xFF, color=0x00
	mov [PAUSE_SLICES], 0x0005
	setup channel=0x3C, address=HANG_BLITTING_PAGE_FF

TANK_CONTINUE_SCREEN_WAIT_BUTTON_RELEASE:
	break
	call TANK_CONTINUE_SCREEN_AUTO_PRESS_ACTION
	jne [HERO_ACTION], 0x00, TANK_CONTINUE_SCREEN_WAIT_BUTTON_RELEASE
	setPalette 0x1D

TANK_CONTINUE_SCREEN_ACCESS_CODE_WAIT_PRESS:
	text id=0x013D, x=5, y=80, color=0x0C ; "PRESS BUTTON OR RETURN TO CONTINUE"
	text id=0x013C, x=5, y=180, color=0x0D ; "        ACCESS CODE:"
	text id=0x016A, x=26, y=180, color=0x0E ; "CKJL"
	break
	call TANK_CONTINUE_SCREEN_AUTO_PRESS_ACTION
	je [HERO_ACTION], 0x00, TANK_CONTINUE_SCREEN_ACCESS_CODE_WAIT_PRESS
	setup channel=0x00, address=TANK_STAGE_BOOT_ENTRY
	killChannel

TANK_CONTINUE_SCREEN_AUTO_PRESS_ACTION:
	je [0xDB], 0x00, SHARED_RET
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, SHARED_RET
	mov [HERO_ACTION], 0x0001
	ret


TANK_ARENA_EXIT_CAPSULES_RISE_TO_BATHS:
	break
	je [0x63], 0x00, TANK_ARENA_EXIT_CAPSULES_RISE_TO_BATHS
	setup channel=0x35, address=RESET_PAGES_AND_SETUP_CH_0A
	setup channel=0x01, address=RESET_PAGES_AND_SETUP_CH_0A
	unfreezeChannels first=0x00, last=0x22
	deleteChannels first=0x39, last=0x3B
	selectVideoPage 0x00
	video offset=CINEMATIC_135, x=160, y=100
	selectVideoPage 0xFF
	break
	play id=0x008E, freq=0x18, vol=0x40, channel=0x01
	video offset=CINEMATIC_136, x=160, y=100
	break
	play id=0x008E, freq=0x14, vol=0x40, channel=0x00
	video offset=CINEMATIC_137, x=160, y=100
	break
	video offset=CINEMATIC_138, x=160, y=100
	break
	video offset=CINEMATIC_139, x=160, y=100
	break
	video offset=CINEMATIC_140, x=160, y=100
	break
	video offset=CINEMATIC_141, x=160, y=100
	break
	video offset=CINEMATIC_142, x=160, y=100
	break
	video offset=CINEMATIC_143, x=160, y=100
	break
	video offset=CINEMATIC_144, x=160, y=100
	break
	video offset=CINEMATIC_145, x=160, y=100
	freezeChannels first=0x00, last=0x27
	deleteChannels first=0x00, last=0x27
	deleteChannels first=0x29, last=0x3B
	fill page=0x03, color=0x01
	break
	play id=0x0057, freq=0x14, vol=0x40, channel=0x02
	video offset=CINEMATIC_146, x=77, y=201, zoom=0x40
	video offset=CINEMATIC_147, x=137, y=220, zoom=0x40
	break
	play id=0x0057, freq=0x14, vol=0x40, channel=0x03
	mov [PAUSE_SLICES], 0x0008
	video offset=CINEMATIC_148, x=97, y=146
	video offset=CINEMATIC_149, x=185, y=172
	break
	video offset=CINEMATIC_146, x=117, y=85
	video offset=CINEMATIC_147, x=237, y=126
	break
	video offset=CINEMATIC_148, x=138, y=24
	video offset=CINEMATIC_149, x=287, y=79
	break
	video offset=CINEMATIC_146, x=148, y=65533
	video offset=CINEMATIC_147, x=336, y=32
	break
	break
	je [0xDB], 0x00, BANKSWITCH_6_FOR_CODE_ENTRY
	mov [0x03], 0x000F

TANK_EXIT_PRE_BANKSWITCH_DELAY:
	break
	djnz [0x03], TANK_EXIT_PRE_BANKSWITCH_DELAY
