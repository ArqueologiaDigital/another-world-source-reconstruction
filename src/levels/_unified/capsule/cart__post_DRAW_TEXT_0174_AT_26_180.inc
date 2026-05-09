LABEL_1572:
	video offset=CINEMATIC_712, x=160, y=100
	djnz [HERO_X], LABEL_1572
	break
	setPalette 0x0C

;@include "../_helpers/KILL_CHANNEL_LANDING.inc"

KILL_CHAN_AT_157F:
	killChannel

LABEL_1580:
	or [HERO_ACTION_POS_MASK], 0x0004
	and [HERO_ACTION_POS_MASK], 0x0007
	break
	jmp LABEL_1580
LABEL_158C:
	db 0x11

LABEL_158D:
	video offset=CINEMATIC_186, x=[HERO_X], y=[HERO_Y]
	break
	je [HERO_ACTION], 0x01, LABEL_15FA
	je [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_18E2
	je [HERO_POS_LEFT_RIGHT], 0x00, LABEL_158D
	add [HERO_X], 0x0002
	video offset=CINEMATIC_201, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0002
	video offset=CINEMATIC_200, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_199, x=[HERO_X], y=[HERO_Y]
	break
	mov [0xE6], 0x0006

ANIM_CIN_198_LOOP_VARE6_AT_15C8:
	video offset=CINEMATIC_198, x=[HERO_X], y=[HERO_Y]
	break
	djnz [0xE6], ANIM_CIN_198_LOOP_VARE6_AT_15C8
	add [HERO_X], 0x0000
	video offset=CINEMATIC_197, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_196, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0000
	video offset=CINEMATIC_195, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_186, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_158D
LABEL_15F9:
	db 0x11

LABEL_15FA:
	video offset=CINEMATIC_187, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_185, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_184, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_183, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_182, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_188, x=[HERO_X], y=[HERO_Y]
	break
	jl [HERO_X], 0x0107, LABEL_18C7
	jg [0xB7], 0x01, LABEL_18C7
	je [0xB7], 0x01, LABEL_166C
	mov [0xB7], 0x0001
	mov [HERO_X], 0x010A
	selectVideoPage 0x00
	video offset=CINEMATIC_189, x=160, y=100
	selectVideoPage 0xFF
	video offset=CINEMATIC_190, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_213, x=160, y=100
	video offset=CINEMATIC_192, x=[HERO_X], y=[HERO_Y]
	selectVideoPage 0x00
	video offset=CINEMATIC_214, x=160, y=100
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_194, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_183, x=[HERO_X], y=[HERO_Y]
	setup channel=0x01, address=LABEL_16A7
	break
	jmp LABEL_18E2

LABEL_166C:
	mov [HERO_X], 0x010C
	mov [0xB7], 0x0002
	selectVideoPage 0x00
	video offset=CINEMATIC_189, x=163, y=100
	selectVideoPage 0xFF
	video offset=CINEMATIC_190, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_191, x=160, y=100
	video offset=CINEMATIC_192, x=[HERO_X], y=[HERO_Y]
	selectVideoPage 0x00
	video offset=CINEMATIC_193, x=160, y=100
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_194, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_183, x=[HERO_X], y=[HERO_Y]
	setup channel=0x01, address=LABEL_16F2
	break
	jmp LABEL_18E2

LABEL_16A7:
	setPalette 0x0E
	setup channel=0x3C, address=LABEL_3148
	play id=0x005D, freq=0x14, vol=0x40, channel=0x02
	play id=0x005D, freq=0x0A, vol=0x40, channel=0x01
	play id=0x0057, freq=0x0A, vol=0x40, channel=0x03
	jl [0x70], 0x78, LABEL_16D6
	jg [0x70], 0xB4, LABEL_16D6
	mov [0x1D], 0x0029
	call LABEL_5FA8
	jmp LABEL_16E2

LABEL_16D6:
	video offset=CINEMATIC_215, x=160, y=100
	break
	video offset=CINEMATIC_215, x=160, y=100
	break
	break
	killChannel

LABEL_16E2:
	video offset=CINEMATIC_215, x=160, y=100
	break
	video offset=CINEMATIC_215, x=160, y=100
	break
	break
	or [0x73], 0x4000
	killChannel

LABEL_16F2:
	selectVideoPage 0x00
	setPalette 0x0C
	video offset=CINEMATIC_202, x=160, y=100
	selectVideoPage 0xFF
	play id=0x0066, freq=0x07, vol=0x20, channel=0x02
	play id=0x0066, freq=0x05, vol=0x20, channel=0x03
	video offset=CINEMATIC_203, x=160, y=100
	break
	video offset=CINEMATIC_203, x=160, y=98
	break
	video offset=CINEMATIC_203, x=160, y=96
	break
	video offset=CINEMATIC_203, x=160, y=94
	break
	video offset=CINEMATIC_204, x=160, y=100
	break
	video offset=CINEMATIC_205, x=160, y=100
	break
	video offset=CINEMATIC_206, x=160, y=100
	break
	video offset=CINEMATIC_207, x=160, y=100
	break
	video offset=CINEMATIC_208, x=160, y=100
	break
	video offset=CINEMATIC_209, x=160, y=100
	selectVideoPage 0x00
	video offset=CINEMATIC_209, x=160, y=100
	selectVideoPage 0xFF
	setup channel=0x04, address=LABEL_1747
	killChannel

LABEL_1747:
	jl [HERO_X], 0x78, LABEL_176E
	jg [HERO_X], 0xB4, LABEL_176E
	jg [HERO_X], 0xA5, LABEL_1760
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_176E

LABEL_1760:
	jge [0x04], 0x4000, LABEL_176E
	setup channel=0x07, address=KILL_CHANNEL_LANDING
	jmp LABEL_1772

LABEL_176E:
	break
	jmp LABEL_1747

LABEL_1772:
	deleteChannels first=0x14, last=0x16
	break
	play id=0x0057, freq=0x14, vol=0x40, channel=0x00
	play id=0x0057, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_210, x=162, y=100
	break
	video offset=CINEMATIC_211, x=162, y=100
	break
	video offset=CINEMATIC_212, x=162, y=100
	break
	load id=0x3E87
	killChannel

LABEL_1796:
	mov [0xE8], 0x00B4
	mov [0xE9], 0x0064
	video offset=CINEMATIC_136, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_136, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_136, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_136, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_137, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_137, x=[0xe8], y=[0xe9]
	break
	setup channel=0x07, address=INLINE_SET_VAREC_TO_AF

LABEL_17C6:
	video offset=CINEMATIC_138, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_138, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_139, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_139, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_140, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_140, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_141, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_141, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_142, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_142, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_143, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_143, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_144, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_144, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_145, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_145, x=[0xe8], y=[0xe9]
	break
	add [0xE8], 0x000D
	jmp LABEL_17C6

LABEL_182D:
	video offset=CINEMATIC_230, x=[0xea], y=157
	play id=0x0052, freq=0x1C, vol=0x40, channel=0x01
	break
	video offset=CINEMATIC_231, x=[0xea], y=157
	break
	video offset=CINEMATIC_232, x=[0xea], y=157
	break
	video offset=CINEMATIC_233, x=[0xea], y=157
	killChannel

LABEL_184B:
	video offset=CINEMATIC_230, x=[0xeb], y=157
	play id=0x0052, freq=0x18, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_231, x=[0xeb], y=157
	break
	video offset=CINEMATIC_232, x=[0xeb], y=157
	break
	video offset=CINEMATIC_233, x=[0xeb], y=157
	killChannel
