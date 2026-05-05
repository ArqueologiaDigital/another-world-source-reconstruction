LABEL_05EA:
	setup channel=0x34, address=RESET_PAGES_AND_SETUP_CH_0A
	mov [0x6B], 0x0019
	killChannel
	jmp INLINE_SET_VAR6B_TO_50

LABEL_05F6:
	video offset=CINEMATIC_144, x=160, y=100
	video offset=CINEMATIC_145, x=160, y=100
	break
	video offset=CINEMATIC_144, x=160, y=100
	video offset=CINEMATIC_146, x=160, y=100
	break
	video offset=CINEMATIC_144, x=160, y=100
	video offset=CINEMATIC_147, x=160, y=100
	break
	video offset=CINEMATIC_148, x=160, y=100
	break
	setup channel=0x2F, address=LABEL_075A
	setup channel=0x3C, address=PALETTE_FLASH_1F_TO_01
	setup channel=0x39, address=RESET_PAGES_AND_SETUP_CH_0A
	setup channel=0x3B, address=RESET_PAGES_AND_SETUP_CH_0A
	setup channel=0x01, address=RESET_PAGES_AND_SETUP_CH_0A
	mov [0x37], 0x0000
	mov [0x41], 0x0000
	break
	video offset=CINEMATIC_149, x=160, y=100
	killChannel

LABEL_0638:
	video offset=CINEMATIC_150, x=110, y=150
	selectVideoPage 0x00
	video offset=CINEMATIC_151, x=160, y=100
	selectVideoPage 0xFF
	selectVideoPage 0x03
	video offset=CINEMATIC_151, x=160, y=100
	selectVideoPage 0xFF
	killChannel

LABEL_064D:
	video offset=CINEMATIC_150, x=155, y=151
	selectVideoPage 0x00
	video offset=CINEMATIC_152, x=160, y=100
	selectVideoPage 0xFF
	selectVideoPage 0x03
	video offset=CINEMATIC_152, x=160, y=100
	selectVideoPage 0xFF
	killChannel

HANG_DRAW_CIN_143:
	video offset=CINEMATIC_143, x=160, y=100
	break
	jmp HANG_DRAW_CIN_143

LABEL_066A:
	video offset=CINEMATIC_130, x=160, y=100
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x00
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x01
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x02
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_131, x=160, y=100
	break
	video offset=CINEMATIC_132, x=160, y=100
	break
	video offset=CINEMATIC_131, x=160, y=100
	break
	video offset=CINEMATIC_133, x=160, y=100
	video offset=CINEMATIC_134, x=160, y=100
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x00
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x01
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x02
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_131, x=160, y=100
	video offset=CINEMATIC_135, x=160, y=100
	play id=0x0059, freq=0x12, vol=0x3F, channel=0x00
	play id=0x0059, freq=0x14, vol=0x3F, channel=0x01
	play id=0x0059, freq=0x14, vol=0x3F, channel=0x02
	play id=0x0059, freq=0x12, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_132, x=160, y=100
	video offset=CINEMATIC_136, x=160, y=100
	break
	video offset=CINEMATIC_137, x=160, y=100
	video offset=CINEMATIC_138, x=160, y=100
	break
	video offset=CINEMATIC_139, x=160, y=100
	video offset=CINEMATIC_136, x=160, y=100
	break
	video offset=CINEMATIC_140, x=160, y=100
	video offset=CINEMATIC_141, x=160, y=100
	break
	video offset=CINEMATIC_139, x=160, y=100
	video offset=CINEMATIC_136, x=160, y=100
	break
	video offset=CINEMATIC_142, x=160, y=100
	video offset=CINEMATIC_138, x=160, y=100
	break
	video offset=CINEMATIC_139, x=160, y=100
	video offset=CINEMATIC_136, x=160, y=100
	break
	jmp LABEL_072F
LABEL_071A:
	db 0x11

LABEL_071B:
	break
	sub [0x69], 0x0001
	jg [0x69], 0x00, LABEL_071B
	setup channel=0x37, address=HANG_DRAW_CIN_143
	setup channel=0x35, address=LABEL_066A
	killChannel

LABEL_072F:
	je [0x63], 0x01, RESET_PAGES_AND_SETUP_CH_0A
	video offset=CINEMATIC_112, x=160, y=100
	video offset=CINEMATIC_113, x=160, y=100
	setup channel=0x39, address=RESET_PAGES_AND_SETUP_CH_0A
	setup channel=0x3B, address=RESET_PAGES_AND_SETUP_CH_0A
	setup channel=0x01, address=RESET_PAGES_AND_SETUP_CH_0A
	mov [0x37], 0x0000
	mov [0x41], 0x0000
	break
	setup channel=0x3C, address=PALETTE_FLASH_1F_TO_01
	video offset=CINEMATIC_114, x=160, y=100

LABEL_075A:
	play id=0x008C, freq=0x14, vol=0x3F, channel=0x00
	play id=0x008C, freq=0x07, vol=0x3F, channel=0x01
	play id=0x008C, freq=0x14, vol=0x3F, channel=0x02
	play id=0x008C, freq=0x07, vol=0x3F, channel=0x03
	selectVideoPage 0x03
	selectVideoPage 0x00
	video offset=CINEMATIC_115, x=160, y=100
	video offset=CINEMATIC_116, x=160, y=100
	selectVideoPage 0xFF
	selectVideoPage 0x03
	video offset=CINEMATIC_115, x=160, y=100
	selectVideoPage 0x00
	video offset=CINEMATIC_117, x=160, y=100
	selectVideoPage 0xFF
	setup channel=0x02, address=RESET_PAGES_AND_SETUP_CH_0A
	break
	setPalette 0x01
	video offset=CINEMATIC_118, x=160, y=100
	break
	video offset=CINEMATIC_119, x=160, y=100
	break
	video offset=CINEMATIC_120, x=160, y=100
	break
	video offset=CINEMATIC_121, x=160, y=100
	break
	song id=0x0BDD, delay=0x0000, pos=0x00
	video offset=CINEMATIC_122, x=160, y=100
	break
	video offset=CINEMATIC_123, x=160, y=100
	break
	video offset=CINEMATIC_124, x=160, y=100
	break
	video offset=CINEMATIC_125, x=160, y=100
	break
	video offset=CINEMATIC_126, x=160, y=100
	break
	video offset=CINEMATIC_127, x=160, y=100
	break
	video offset=CINEMATIC_128, x=160, y=100
	break
	video offset=CINEMATIC_129, x=160, y=100
	break
	setup channel=0x3F, address=LABEL_07DD
	killChannel

LABEL_07DD:
	break
	freezeChannels first=0x00, last=0x3F
	deleteChannels first=0x00, last=0x3F
	mov [SCROLL_Y], 0x0064
	copyVideoPage src=0x80, dst=0x03
	setup channel=0x00, address=LABEL_07F6
	mov [0x6D], 0x0001
	killChannel

LABEL_07F6:
	fill page=0x00, color=0x00
	fill page=0xFF, color=0x00
	mov [PAUSE_SLICES], 0x0005
	or [0xE3], 0x0001
	setup channel=0x3C, address=HANG_BLITTING_PAGE_FF
	setPalette 0x1D

LABEL_080B:
	break
	text id=0x013D, x=5, y=80, color=0x0C ; "    PRESS BUTTON TO CONTINUE

   PRESS START FOR CODE ENTRY"
	text id=0x013C, x=5, y=180, color=0x0D ; "        ACCESS CODE:"
	text id=0x016A, x=26, y=180, color=0x0E ; "CKJL"
	call LABEL_0848
	jne [HERO_ACTION], 0x00, LABEL_080B

LABEL_0827:
	text id=0x013D, x=5, y=80, color=0x0C ; "    PRESS BUTTON TO CONTINUE

   PRESS START FOR CODE ENTRY"
	text id=0x013C, x=5, y=180, color=0x0D ; "        ACCESS CODE:"
	text id=0x016A, x=26, y=180, color=0x0E ; "CKJL"
	break
	call LABEL_0848
	je [HERO_ACTION], 0x00, LABEL_0827
	setup channel=0x00, address=LABEL_0004
	killChannel

LABEL_0848:
	je [0xDB], 0x00, SHARED_RET
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, SHARED_RET
	mov [HERO_ACTION], 0x0001
	ret

LABEL_085A:
	break
	je [0x63], 0x00, LABEL_085A
	setup channel=0x35, address=RESET_PAGES_AND_SETUP_CH_0A
	setup channel=0x01, address=RESET_PAGES_AND_SETUP_CH_0A
	unfreezeChannels first=0x00, last=0x22
	deleteChannels first=0x39, last=0x3B
	selectVideoPage 0x00
	video offset=CINEMATIC_159, x=160, y=100
	selectVideoPage 0xFF
	break
	play id=0x008E, freq=0x18, vol=0x40, channel=0x01
	video offset=CINEMATIC_160, x=160, y=100
	break
	play id=0x008E, freq=0x14, vol=0x40, channel=0x00
	video offset=CINEMATIC_161, x=160, y=100
	break
	video offset=CINEMATIC_162, x=160, y=100
	break
	video offset=CINEMATIC_163, x=160, y=100
	break
	video offset=CINEMATIC_164, x=160, y=100
	break
	video offset=CINEMATIC_165, x=160, y=100
	break
	video offset=CINEMATIC_166, x=160, y=100
	break
	video offset=CINEMATIC_167, x=160, y=100
	break
	video offset=CINEMATIC_168, x=160, y=100
	break
	video offset=CINEMATIC_169, x=160, y=100
	freezeChannels first=0x00, last=0x27
	deleteChannels first=0x00, last=0x27
	deleteChannels first=0x29, last=0x3B
	fill page=0x03, color=0x01
	break
	fill page=0x03, color=0x01
	setup channel=0x2F, address=RESET_PAGES_AND_SETUP_CH_0A
	play id=0x0057, freq=0x14, vol=0x40, channel=0x02
	video offset=CINEMATIC_170, x=77, y=201, zoom=0x40
	video offset=CINEMATIC_171, x=137, y=220, zoom=0x40
	break
	setup channel=0x2F, address=RESET_PAGES_AND_SETUP_CH_0A
	play id=0x0057, freq=0x14, vol=0x40, channel=0x03
	mov [PAUSE_SLICES], 0x0008
	video offset=CINEMATIC_172, x=97, y=146
	video offset=CINEMATIC_173, x=185, y=172
	break
	video offset=CINEMATIC_170, x=117, y=85
	video offset=CINEMATIC_171, x=237, y=126
	break
	video offset=CINEMATIC_172, x=138, y=24
	video offset=CINEMATIC_173, x=287, y=79
	break
	video offset=CINEMATIC_170, x=148, y=65533
	video offset=CINEMATIC_171, x=336, y=32
	break
	break
	je [0xDB], 0x00, BANKSWITCH_6_FOR_CODE_ENTRY
	mov [0x03], 0x000F

DELAY_LOOP_VAR03_AT_0920:
	break
	djnz [0x03], DELAY_LOOP_VAR03_AT_0920
