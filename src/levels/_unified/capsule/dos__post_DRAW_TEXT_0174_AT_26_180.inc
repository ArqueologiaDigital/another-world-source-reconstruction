LABEL_1464:
	video type=1, offset=CINEMATIC_719, x=160, y=100
	djnz [0x01], LABEL_1464
	break
	setPalette 0x0C

KILL_CHANNEL_LANDING:
	killChannel

KILL_CHAN_AT_1471:
	killChannel

LABEL_1472:
	or [HERO_ACTION_POS_MASK], 0x0004
	and [HERO_ACTION_POS_MASK], 0x0007
	break
	jmp LABEL_1472
LABEL_147E:
	db 0x11

LABEL_147F:
	video type=1, offset=CINEMATIC_185, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_ACTION], 0x01, LABEL_14EC
	je [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_17D4
	je [HERO_POS_LEFT_RIGHT], 0x00, LABEL_147F
	add [0x01], 0x0002
	video type=1, offset=CINEMATIC_200, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0002
	video type=1, offset=CINEMATIC_199, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0001
	video type=1, offset=CINEMATIC_198, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0xE6], 0x0006

ANIM_CIN_197_LOOP_VARE6_AT_14BA:
	video type=1, offset=CINEMATIC_197, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0xE6], ANIM_CIN_197_LOOP_VARE6_AT_14BA
	add [0x01], 0x0000
	video type=1, offset=CINEMATIC_196, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0001
	video type=1, offset=CINEMATIC_195, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0000
	video type=1, offset=CINEMATIC_194, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_185, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp LABEL_147F
LABEL_14EB:
	db 0x11

LABEL_14EC:
	video type=1, offset=CINEMATIC_186, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_184, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_183, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_182, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_181, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_187, x=[0x01], y=[0x02], zoom=0x40
	break
	jl [0x01], 0x0107, LABEL_17B9
	jg [0xB7], 0x01, LABEL_17B9
	je [0xB7], 0x01, LABEL_155E
	mov [0xB7], 0x0001
	mov [0x01], 0x010A
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_188, x=160, y=100
	selectVideoPage 0xFF
	video type=1, offset=CINEMATIC_189, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_212, x=160, y=100
	video type=1, offset=CINEMATIC_191, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_213, x=160, y=100
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_193, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_182, x=[0x01], y=[0x02], zoom=0x40
	setup channel=0x01, address=LABEL_1599
	break
	jmp LABEL_17D4

LABEL_155E:
	mov [0x01], 0x010C
	mov [0xB7], 0x0002
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_188, x=163, y=100
	selectVideoPage 0xFF
	video type=1, offset=CINEMATIC_189, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_190, x=160, y=100
	video type=1, offset=CINEMATIC_191, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_192, x=160, y=100
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_193, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_182, x=[0x01], y=[0x02], zoom=0x40
	setup channel=0x01, address=LABEL_15E4
	break
	jmp LABEL_17D4

LABEL_1599:
	setPalette 0x0E
	setup channel=0x3C, address=LABEL_2FCB
	play id=0x005D, freq=0x14, vol=0x40, channel=0x02
	play id=0x005D, freq=0x0A, vol=0x40, channel=0x01
	play id=0x0057, freq=0x0A, vol=0x40, channel=0x03
	jl [0x70], 0x78, LABEL_15C8
	jg [0x70], 0xB4, LABEL_15C8
	mov [0x1D], 0x0029
	call LABEL_5F9F
	jmp LABEL_15D4

LABEL_15C8:
	video type=1, offset=CINEMATIC_214, x=160, y=100
	break
	video type=1, offset=CINEMATIC_214, x=160, y=100
	break
	break
	killChannel

LABEL_15D4:
	video type=1, offset=CINEMATIC_214, x=160, y=100
	break
	video type=1, offset=CINEMATIC_214, x=160, y=100
	break
	break
	or [0x73], 0x4000
	killChannel

LABEL_15E4:
	selectVideoPage 0x00
	setPalette 0x0C
	video type=1, offset=CINEMATIC_201, x=160, y=100
	selectVideoPage 0xFF
	play id=0x0066, freq=0x07, vol=0x20, channel=0x02
	play id=0x0066, freq=0x05, vol=0x20, channel=0x03
	video type=1, offset=CINEMATIC_202, x=160, y=100
	break
	video type=1, offset=CINEMATIC_202, x=160, y=98
	break
	video type=1, offset=CINEMATIC_202, x=160, y=96
	break
	video type=1, offset=CINEMATIC_202, x=160, y=94
	break
	video type=1, offset=CINEMATIC_203, x=160, y=100
	break
	video type=1, offset=CINEMATIC_204, x=160, y=100
	break
	video type=1, offset=CINEMATIC_205, x=160, y=100
	break
	video type=1, offset=CINEMATIC_206, x=160, y=100
	break
	video type=1, offset=CINEMATIC_207, x=160, y=100
	break
	video type=1, offset=CINEMATIC_208, x=160, y=100
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_208, x=160, y=100
	selectVideoPage 0xFF
	setup channel=0x04, address=LABEL_1639
	killChannel

LABEL_1639:
	jl [0x01], 0x78, LABEL_1660
	jg [0x01], 0xB4, LABEL_1660
	jg [0x01], 0xA5, LABEL_1652
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_1660

LABEL_1652:
	jge [0x04], 0x4000, LABEL_1660
	setup channel=0x07, address=KILL_CHANNEL_LANDING
	jmp LABEL_1664

LABEL_1660:
	break
	jmp LABEL_1639

LABEL_1664:
	deleteChannels first=0x14, last=0x16
	break
	play id=0x0057, freq=0x14, vol=0x40, channel=0x00
	play id=0x0057, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_209, x=162, y=100
	break
	video type=1, offset=CINEMATIC_210, x=162, y=100
	break
	video type=1, offset=CINEMATIC_211, x=162, y=100
	break
	bankSwitch 7;  Game Ending Sequence
	killChannel

LABEL_1688:
	mov [0xE8], 0x00B4
	mov [0xE9], 0x0064
	video type=1, offset=CINEMATIC_135, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_135, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_135, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_135, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_136, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_136, x=[0xe8], y=[0xe9], zoom=0x40
	break
	setup channel=0x07, address=INLINE_SET_VAREC_TO_AF

LABEL_16B8:
	video type=1, offset=CINEMATIC_137, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_137, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_138, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_138, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_139, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_139, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_140, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_140, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_141, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_141, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_142, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_142, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_143, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_143, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_144, x=[0xe8], y=[0xe9], zoom=0x40
	break
	video type=1, offset=CINEMATIC_144, x=[0xe8], y=[0xe9], zoom=0x40
	break
	add [0xE8], 0x000D
	jmp LABEL_16B8

LABEL_171F:
	video type=1, offset=CINEMATIC_229, x=[0xea], y=157, zoom=0x40
	play id=0x0052, freq=0x1C, vol=0x40, channel=0x01
	break
	video type=1, offset=CINEMATIC_230, x=[0xea], y=157, zoom=0x40
	break
	video type=1, offset=CINEMATIC_231, x=[0xea], y=157, zoom=0x40
	break
	video type=1, offset=CINEMATIC_232, x=[0xea], y=157, zoom=0x40
	killChannel

LABEL_173D:
	video type=1, offset=CINEMATIC_229, x=[0xeb], y=157, zoom=0x40
	play id=0x0052, freq=0x18, vol=0x40, channel=0x00
	break
	video type=1, offset=CINEMATIC_230, x=[0xeb], y=157, zoom=0x40
	break
	video type=1, offset=CINEMATIC_231, x=[0xeb], y=157, zoom=0x40
	break
	video type=1, offset=CINEMATIC_232, x=[0xeb], y=157, zoom=0x40
	killChannel
