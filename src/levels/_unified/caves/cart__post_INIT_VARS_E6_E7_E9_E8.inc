DELAY_LOOP_VARE8_AT_11D5:
	break
	djnz [0xE8], DELAY_LOOP_VARE8_AT_11D5
	mov [0xE8], 0x000F

DELAY_LOOP_VARE8_AT_11DE:
	break
	djnz [0xE8], DELAY_LOOP_VARE8_AT_11DE
	jl [HERO_X], 0x78, INIT_VARS_E6_E7_E9_E8

LABEL_11E9:
	mov [0xE6], 0x009B
	mov [0xE7], 0x0064
	mov [0xE9], 0x0000
	mov [0xE8], 0x0008

DELAY_LOOP_VARE8_AT_11F9:
	break
	djnz [0xE8], DELAY_LOOP_VARE8_AT_11F9
	mov [0xE6], 0x00B4
	mov [0xE7], 0x0064
	mov [0xE9], 0x0000
	mov [0xE8], 0x0008

DELAY_LOOP_VARE8_AT_120E:
	break
	djnz [0xE8], DELAY_LOOP_VARE8_AT_120E
	jmp LABEL_11E9
LABEL_1216:
	db 0x11

LABEL_1217:
	video offset=CINEMATIC_198, x=[HERO_X], y=[HERO_Y]
	play id=0x0075, freq=0x15, vol=0x40, channel=0x00
	play id=0x007A, freq=0x14, vol=0x40, channel=0x03
	play id=0x0057, freq=0x14, vol=0x10, channel=0x01
	break
	video offset=CINEMATIC_199, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_200, x=[HERO_X], y=[HERO_Y]
	song id=0x0BDD, delay=0x0000, pos=0x00
	break
	video offset=CINEMATIC_201, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_202, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_203, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_202, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_204, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_202, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_205, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_202, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_206, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_202, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_207, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_202, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_208, x=[HERO_X], y=[HERO_Y]
	setup channel=0x3F, address=LABEL_0211
	break
	video offset=CINEMATIC_202, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_208, x=[HERO_X], y=[HERO_Y]
	mov [0x03], 0x000A

LABEL_129B:
	break
	video offset=CINEMATIC_202, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_207, x=[HERO_X], y=[HERO_Y]
	jmp LABEL_129B

LABEL_12A9:
	video offset=CINEMATIC_192, x=[0xe6], y=[HERO_Y]
	break
	video offset=CINEMATIC_193, x=[0xe6], y=[HERO_Y]
	break
	video offset=CINEMATIC_194, x=[0xe6], y=[HERO_Y]
	break
	video offset=CINEMATIC_195, x=[0xe6], y=[HERO_Y]
	break
	video offset=CINEMATIC_196, x=[0xe6], y=[HERO_Y]
	break
	video offset=CINEMATIC_197, x=[0xe6], y=[HERO_Y]
	killChannel

LABEL_12CD:
	selectVideoPage 0x00
	mov [0xE9], 0xFFFF
	play id=0x0057, freq=0x19, vol=0x20, channel=0x02
	video offset=CINEMATIC_191, x=[0xe6], y=[0xe7]
	call BOUNDS_CHECK_VARE7_VS_VAR02
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_209, x=[0xe6], y=[0xe7]
	call BOUNDS_CHECK_VARE7_VS_VAR02
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_210, x=[0xe6], y=[0xe7]
	call BOUNDS_CHECK_VARE7_VS_VAR02
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_211, x=[0xe6], y=[0xe7]
	call BOUNDS_CHECK_VARE7_VS_VAR02
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_212, x=[0xe6], y=[0xe7]
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_213, x=[0xe6], y=[0xe7]
	selectVideoPage 0xFF
	jmp LABEL_139C

LABEL_1321:
	selectVideoPage 0x00
	play id=0x0057, freq=0x19, vol=0x20, channel=0x03
	video offset=CINEMATIC_214, x=[0xe6], y=[0xe7]
	call BOUNDS_CHECK_VARE7_VS_VAR02
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_215, x=[0xe6], y=[0xe7]
	call BOUNDS_CHECK_VARE7_VS_VAR02
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_216, x=[0xe6], y=[0xe7]
	call BOUNDS_CHECK_VARE7_VS_VAR02
	selectVideoPage 0xFF
	break

LABEL_134E:
	sub [0xE9], 0x0001
	play id=0x0057, freq=0x19, vol=0x0A, channel=0x02
	call LABEL_115D
	call LABEL_118F
	call BOUNDS_CHECK_VARE7_VS_VAR02
	break
	call LABEL_1167
	call BOUNDS_CHECK_VARE7_VS_VAR02
	break
	call LABEL_115D
	call LABEL_1171
	call BOUNDS_CHECK_VARE7_VS_VAR02
	break
	call LABEL_1167
	call LABEL_117B
	call BOUNDS_CHECK_VARE7_VS_VAR02
	break
	call LABEL_1171
	call LABEL_1185
	call BOUNDS_CHECK_VARE7_VS_VAR02
	break
	jg [0xE9], 0x00, LABEL_134E
	mov [0xE9], 0xFFFF
	call LABEL_117B
	break
	call LABEL_1185
	break
	call LABEL_118F

LABEL_139C:
	break
	je [0xE9], 0x00, LABEL_12CD
	jg [0xE9], 0x00, LABEL_1321
	jmp LABEL_139C

BOUNDS_CHECK_VARE7_VS_VAR02:
	mov [0xF8], [HERO_Y]
	sub [0xF8], 0x000A
	jl [0xE7], [0xF8], SHARED_RET
	add [0xF8], 0x0014
	jg [0xE7], [0xF8], SHARED_RET
	mov [0xF8], [0xE6]
	sub [0xF8], 0x0009
	jl [HERO_X], [0xF8], SHARED_RET
	add [0xF8], 0x0012
	jg [HERO_X], [0xF8], SHARED_RET
	jge [0x04], 0x4000, SHARED_RET
	or [0x04], 0x4000
	setup channel=0x14, address=LABEL_1217
	setup channel=0x15, address=LABEL_12A9
	setPalette 0x1B
	ret

JUNK__13F1:
	mov [0xE6], 0x0008
	mov [0xE7], 0x0003
	mov [0xE8], 0x0064

LABEL_13FD:
	mov [0x1D], [0xE7]
	mov [0x21], 0x00A0
	mov [0x22], [0xE8]
	mov [0x23], 0x0040
	call LABEL_1429
	add [0x22], 0x00C8
	call LABEL_1429
	add [0x22], 0x00C8
	call LABEL_1429
	break
	sub [0xE8], 0x0019
	djnz [0xE6], LABEL_13FD
	jmp JUNK__13F1
LABEL_1428:
	db 0x11

LABEL_1429:
	ret

LABEL_142A:
	break
	jl [HERO_X], 0xB4, LABEL_142A
	or [0x74], 0x4000
	setPalette 0x09
	killChannel

LABEL_1439:
	setup channel=0x22, address=LABEL_4FD4
	setup channel=0x23, address=KILL_CHANNEL_LANDING
	setup channel=0x24, address=LABEL_4FF4
	setup channel=0x25, address=KILL_CHANNEL_LANDING
	setup channel=0x26, address=LABEL_502F
	setup channel=0x27, address=KILL_CHANNEL_LANDING
	setup channel=0x28, address=LABEL_506A
	ret

LABEL_1456:
	jl [HACK_VAR_67], 0x4A, LABEL_147B
	jg [HACK_VAR_67], 0x50, LABEL_147B
	mov [0xF8], [0xB2]
	and [0xF8], 0x0001
	je [0xF8], 0x01, LABEL_1472
	call LABEL_455C

LABEL_1472:
	je [0xB3], 0x00, LABEL_147B
	call LABEL_45FD

LABEL_147B:
	jl [HACK_VAR_67], 0x6A, LABEL_14BC
	jg [HACK_VAR_67], 0x70, LABEL_14BC
	mov [0xF8], [0xB2]
	and [0xF8], 0x0002
	jne [0xF8], 0x00, LABEL_14A0
	jne [HACK_VAR_67], 0x70, LABEL_14A0
	call LABEL_461D
	jmp LABEL_14B3

LABEL_14A0:
	je [0xB6], 0x00, LABEL_14AA
	mov [0x7A], 0x00FA

LABEL_14AA:
	je [0xB4], 0x00, LABEL_14B3
	call LABEL_45BE

LABEL_14B3:
	je [0xB5], 0x00, LABEL_14BC
	call LABEL_459E

LABEL_14BC:
	ret

JUNK__14BD:
	setPalette 0x15
	break
	setPalette 0x16
	break
	setPalette 0x17
	break
	setPalette 0x18
	break
	jmp JUNK__14BD
LABEL_14D0:
	db 0x11

LABEL_14D1:
	mov [0x29], 0x0005
	call LABEL_92D1

LABEL_14D8:
	break
	call LABEL_92D1
	djnz [0x29], LABEL_14D8
	mov [0x0E], 0x0004
	mov [0x29], 0x0005

LABEL_14E8:
	break
	sub [0x07], 0x000A
	add [0x08], 0x0015
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	add [0x07], 0x000A
	sub [0x08], 0x0015
	video offset=CINEMATIC_141, x=[0x07], y=[0x08]
	djnz [0x29], LABEL_14E8
	mov [0x0E], 0x0000
	and [0x11], 0xF7FF
	or [0x09], 0x0400
	setup channel=0x14, address=KILL_CHANNEL_LANDING
	setup channel=0x34, address=LABEL_1753
	setup channel=0x35, address=HANG_DRAW_CIN_186
	break
	jmp INIT_VARS_0E_29
LABEL_1521:
	db 0x11
