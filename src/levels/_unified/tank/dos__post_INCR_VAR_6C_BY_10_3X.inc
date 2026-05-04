LABEL_0612:
	setup channel=0x34, address=RESET_PAGES_AND_SETUP_CH_0A
	mov [0x6B], 0x0019
	killChannel
	jmp INLINE_SET_VAR6B_TO_50

LABEL_061E:
	video type=1, offset=CINEMATIC_120, x=160, y=100
	video type=1, offset=CINEMATIC_121, x=160, y=100
	break
	video type=1, offset=CINEMATIC_120, x=160, y=100
	video type=1, offset=CINEMATIC_122, x=160, y=100
	break
	video type=1, offset=CINEMATIC_120, x=160, y=100
	video type=1, offset=CINEMATIC_123, x=160, y=100
	break
	video type=1, offset=CINEMATIC_124, x=160, y=100
	break
	setup channel=0x2F, address=LABEL_0782
	setup channel=0x3C, address=PALETTE_FLASH_1F_TO_01
	setup channel=0x39, address=RESET_PAGES_AND_SETUP_CH_0A
	setup channel=0x3B, address=RESET_PAGES_AND_SETUP_CH_0A
	setup channel=0x01, address=RESET_PAGES_AND_SETUP_CH_0A
	mov [0x37], 0x0000
	mov [0x41], 0x0000
	break
	video type=1, offset=CINEMATIC_125, x=160, y=100
	killChannel

LABEL_0660:
	video type=1, offset=CINEMATIC_126, x=110, y=150
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_127, x=160, y=100
	selectVideoPage 0xFF
	selectVideoPage 0x03
	video type=1, offset=CINEMATIC_127, x=160, y=100
	selectVideoPage 0xFF
	killChannel

LABEL_0675:
	video type=1, offset=CINEMATIC_126, x=155, y=151
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_128, x=160, y=100
	selectVideoPage 0xFF
	selectVideoPage 0x03
	video type=1, offset=CINEMATIC_128, x=160, y=100
	selectVideoPage 0xFF
	killChannel

HANG_DRAW_CIN_119:
	video type=1, offset=CINEMATIC_119, x=160, y=100
	break
	jmp HANG_DRAW_CIN_119

LABEL_0692:
	video type=1, offset=CINEMATIC_106, x=160, y=100
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x00
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x01
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x02
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_107, x=160, y=100
	break
	video type=1, offset=CINEMATIC_108, x=160, y=100
	break
	video type=1, offset=CINEMATIC_107, x=160, y=100
	break
	video type=1, offset=CINEMATIC_109, x=160, y=100
	video type=1, offset=CINEMATIC_110, x=160, y=100
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x00
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x01
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x02
	play id=0x005B, freq=0x12, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_107, x=160, y=100
	video type=1, offset=CINEMATIC_111, x=160, y=100
	play id=0x0059, freq=0x12, vol=0x3F, channel=0x00
	play id=0x0059, freq=0x14, vol=0x3F, channel=0x01
	play id=0x0059, freq=0x14, vol=0x3F, channel=0x02
	play id=0x0059, freq=0x12, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_108, x=160, y=100
	video type=1, offset=CINEMATIC_112, x=160, y=100
	break
	video type=1, offset=CINEMATIC_113, x=160, y=100
	video type=1, offset=CINEMATIC_114, x=160, y=100
	break
	video type=1, offset=CINEMATIC_115, x=160, y=100
	video type=1, offset=CINEMATIC_112, x=160, y=100
	break
	video type=1, offset=CINEMATIC_116, x=160, y=100
	video type=1, offset=CINEMATIC_117, x=160, y=100
	break
	video type=1, offset=CINEMATIC_115, x=160, y=100
	video type=1, offset=CINEMATIC_112, x=160, y=100
	break
	video type=1, offset=CINEMATIC_118, x=160, y=100
	video type=1, offset=CINEMATIC_114, x=160, y=100
	break
	video type=1, offset=CINEMATIC_115, x=160, y=100
	video type=1, offset=CINEMATIC_112, x=160, y=100
	break
	jmp LABEL_0757
LABEL_0742:
	db 0x11

LABEL_0743:
	break
	sub [0x69], 0x0001
	jg [0x69], 0x00, LABEL_0743
	setup channel=0x37, address=HANG_DRAW_CIN_119
	setup channel=0x35, address=LABEL_0692
	killChannel

LABEL_0757:
	je [0x63], 0x01, RESET_PAGES_AND_SETUP_CH_0A
	video type=1, offset=CINEMATIC_088, x=160, y=100
	video type=1, offset=CINEMATIC_089, x=160, y=100
	setup channel=0x39, address=RESET_PAGES_AND_SETUP_CH_0A
	setup channel=0x3B, address=RESET_PAGES_AND_SETUP_CH_0A
	setup channel=0x01, address=RESET_PAGES_AND_SETUP_CH_0A
	mov [0x37], 0x0000
	mov [0x41], 0x0000
	break
	setup channel=0x3C, address=PALETTE_FLASH_1F_TO_01
	video type=1, offset=CINEMATIC_090, x=160, y=100

LABEL_0782:
	play id=0x008C, freq=0x14, vol=0x3F, channel=0x00
	play id=0x008C, freq=0x07, vol=0x3F, channel=0x01
	play id=0x008C, freq=0x14, vol=0x3F, channel=0x02
	play id=0x008C, freq=0x07, vol=0x3F, channel=0x03
	selectVideoPage 0x03
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_091, x=160, y=100
	video type=1, offset=CINEMATIC_092, x=160, y=100
	selectVideoPage 0xFF
	selectVideoPage 0x03
	video type=1, offset=CINEMATIC_091, x=160, y=100
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_093, x=160, y=100
	selectVideoPage 0xFF
	setup channel=0x02, address=RESET_PAGES_AND_SETUP_CH_0A
	break
	setPalette 0x01
	video type=1, offset=CINEMATIC_094, x=160, y=100
	break
	video type=1, offset=CINEMATIC_095, x=160, y=100
	break
	video type=1, offset=CINEMATIC_096, x=160, y=100
	break
	video type=1, offset=CINEMATIC_097, x=160, y=100
	break
	video type=1, offset=CINEMATIC_098, x=160, y=100
	break
	video type=1, offset=CINEMATIC_099, x=160, y=100
	break
	video type=1, offset=CINEMATIC_100, x=160, y=100
	break
	video type=1, offset=CINEMATIC_101, x=160, y=100
	break
	video type=1, offset=CINEMATIC_102, x=160, y=100
	break
	video type=1, offset=CINEMATIC_103, x=160, y=100
	break
	video type=1, offset=CINEMATIC_104, x=160, y=100
	break
	video type=1, offset=CINEMATIC_105, x=160, y=100
	break
	setup channel=0x3F, address=LABEL_07FF
	killChannel

LABEL_07FF:
	break
	freezeChannels first=0x00, last=0x3F
	deleteChannels first=0x00, last=0x3F
	mov [SCROLL_Y], 0x0064
	copyVideoPage src=0x80, dst=0x03
	setup channel=0x00, address=LABEL_0818
	mov [0x6D], 0x0001
	killChannel

LABEL_0818:
	fill page=0x00, color=0x00
	fill page=0xFF, color=0x00
	mov [PAUSE_SLICES], 0x0005
	setup channel=0x3C, address=HANG_BLITTING_PAGE_FF

LABEL_0826:
	break
	call LABEL_0854
	jne [HERO_ACTION], 0x00, LABEL_0826
	setPalette 0x1D

LABEL_0833:
	text id=0x013D, x=5, y=80, color=0x0C ; "PRESS BUTTON OR RETURN TO CONTINUE"
	text id=0x013C, x=5, y=180, color=0x0D ; "        ACCESS CODE:"
	text id=0x016A, x=26, y=180, color=0x0E ; "CKJL"
	break
	call LABEL_0854
	je [HERO_ACTION], 0x00, LABEL_0833
	setup channel=0x00, address=LABEL_0004
	killChannel

LABEL_0854:
	je [0xDB], 0x00, SHARED_RET
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, SHARED_RET
	mov [HERO_ACTION], 0x0001
	ret

LABEL_0866:
	break
	je [0x63], 0x00, LABEL_0866
	setup channel=0x35, address=RESET_PAGES_AND_SETUP_CH_0A
	setup channel=0x01, address=RESET_PAGES_AND_SETUP_CH_0A
	unfreezeChannels first=0x00, last=0x22
	deleteChannels first=0x39, last=0x3B
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_135, x=160, y=100
	selectVideoPage 0xFF
	break
	play id=0x008E, freq=0x18, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_136, x=160, y=100
	break
	play id=0x008E, freq=0x14, vol=0x40, channel=0x00
	video type=1, offset=CINEMATIC_137, x=160, y=100
	break
	video type=1, offset=CINEMATIC_138, x=160, y=100
	break
	video type=1, offset=CINEMATIC_139, x=160, y=100
	break
	video type=1, offset=CINEMATIC_140, x=160, y=100
	break
	video type=1, offset=CINEMATIC_141, x=160, y=100
	break
	video type=1, offset=CINEMATIC_142, x=160, y=100
	break
	video type=1, offset=CINEMATIC_143, x=160, y=100
	break
	video type=1, offset=CINEMATIC_144, x=160, y=100
	break
	video type=1, offset=CINEMATIC_145, x=160, y=100
	freezeChannels first=0x00, last=0x27
	deleteChannels first=0x00, last=0x27
	deleteChannels first=0x29, last=0x3B
	fill page=0x03, color=0x01
	break
	play id=0x0057, freq=0x14, vol=0x40, channel=0x02
	video type=1, offset=CINEMATIC_146, x=77, y=201, zoom=0x40
	video type=1, offset=CINEMATIC_147, x=137, y=220, zoom=0x40
	break
	play id=0x0057, freq=0x14, vol=0x40, channel=0x03
	mov [PAUSE_SLICES], 0x0008
	video type=1, offset=CINEMATIC_148, x=97, y=146
	video type=1, offset=CINEMATIC_149, x=185, y=172
	break
	video type=1, offset=CINEMATIC_146, x=117, y=85
	video type=1, offset=CINEMATIC_147, x=237, y=126
	break
	video type=1, offset=CINEMATIC_148, x=138, y=24
	video type=1, offset=CINEMATIC_149, x=287, y=79, zoom=0x40
	break
	video type=1, offset=CINEMATIC_146, x=148, y=65533, zoom=0x40
	video type=1, offset=CINEMATIC_147, x=336, y=32, zoom=0x40
	break
	break
	je [0xDB], 0x00, BANKSWITCH_6_FOR_CODE_ENTRY
	mov [0x03], 0x000F

DELAY_LOOP_VAR03_AT_0921:
	break
	djnz [0x03], DELAY_LOOP_VAR03_AT_0921
