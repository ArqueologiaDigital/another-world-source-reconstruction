DELAY_LOOP_VARE8_AT_1240:
	break
	djnz [0xE8], DELAY_LOOP_VARE8_AT_1240
	mov [0xE8], 0x000F

DELAY_LOOP_VARE8_AT_1249:
	break
	djnz [0xE8], DELAY_LOOP_VARE8_AT_1249
	jl [0x01], 0x78, INIT_VARS_E6_E7_E9_E8

LABEL_1254:
	mov [0xE6], 0x009B
	mov [0xE7], 0x0064
	mov [0xE9], 0x0000
	mov [0xE8], 0x0007

DELAY_LOOP_VARE8_AT_1264:
	break
	djnz [0xE8], DELAY_LOOP_VARE8_AT_1264
	mov [0xE6], 0x00B4
	mov [0xE7], 0x0064
	mov [0xE9], 0x0000
	mov [0xE8], 0x0007

DELAY_LOOP_VARE8_AT_1279:
	break
	djnz [0xE8], DELAY_LOOP_VARE8_AT_1279
	jmp LABEL_1254
LABEL_1281:
	db 0x11

LABEL_1282:
	video type=1, offset=CINEMATIC_198, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0075, freq=0x15, vol=0x40, channel=0x00
	play id=0x007A, freq=0x14, vol=0x40, channel=0x03
	play id=0x0057, freq=0x14, vol=0x10, channel=0x01
	break
	video type=1, offset=CINEMATIC_199, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_200, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_201, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_202, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_203, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_202, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_204, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_202, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_205, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_202, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_206, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_202, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_207, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_202, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_208, x=[0x01], y=[0x02], zoom=0x40
	setup channel=0x3F, address=LABEL_0184
	break
	video type=1, offset=CINEMATIC_202, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_208, x=[0x01], y=[0x02], zoom=0x40
	mov [0x03], 0x000A

LABEL_1300:
	break
	video type=1, offset=CINEMATIC_202, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_207, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_1300

LABEL_130E:
	video type=1, offset=CINEMATIC_192, x=[0xe6], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_193, x=[0xe6], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_194, x=[0xe6], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_195, x=[0xe6], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_196, x=[0xe6], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_197, x=[0xe6], y=[0x02], zoom=0x40
	killChannel

LABEL_1332:
	selectVideoPage 0x00
	mov [0xE9], 0xFFFF
	play id=0x0057, freq=0x19, vol=0x20, channel=0x02
	video type=1, offset=CINEMATIC_191, x=[0xe6], y=[0xe7], zoom=0x40
	call BOUNDS_CHECK_VARE7_VS_VAR02
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_209, x=[0xe6], y=[0xe7], zoom=0x40
	call BOUNDS_CHECK_VARE7_VS_VAR02
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_210, x=[0xe6], y=[0xe7], zoom=0x40
	call BOUNDS_CHECK_VARE7_VS_VAR02
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_211, x=[0xe6], y=[0xe7], zoom=0x40
	call BOUNDS_CHECK_VARE7_VS_VAR02
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_212, x=[0xe6], y=[0xe7], zoom=0x40
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_213, x=[0xe6], y=[0xe7], zoom=0x40
	selectVideoPage 0xFF
	jmp LABEL_1401

LABEL_1386:
	selectVideoPage 0x00
	play id=0x0057, freq=0x19, vol=0x20, channel=0x03
	video type=1, offset=CINEMATIC_214, x=[0xe6], y=[0xe7], zoom=0x40
	call BOUNDS_CHECK_VARE7_VS_VAR02
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_215, x=[0xe6], y=[0xe7], zoom=0x40
	call BOUNDS_CHECK_VARE7_VS_VAR02
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_216, x=[0xe6], y=[0xe7], zoom=0x40
	call BOUNDS_CHECK_VARE7_VS_VAR02
	selectVideoPage 0xFF
	break

LABEL_13B3:
	sub [0xE9], 0x0001
	play id=0x0057, freq=0x19, vol=0x0A, channel=0x02
	call LABEL_11C8
	call LABEL_11FA
	call BOUNDS_CHECK_VARE7_VS_VAR02
	break
	call LABEL_11D2
	call BOUNDS_CHECK_VARE7_VS_VAR02
	break
	call LABEL_11C8
	call LABEL_11DC
	call BOUNDS_CHECK_VARE7_VS_VAR02
	break
	call LABEL_11D2
	call LABEL_11E6
	call BOUNDS_CHECK_VARE7_VS_VAR02
	break
	call LABEL_11DC
	call LABEL_11F0
	call BOUNDS_CHECK_VARE7_VS_VAR02
	break
	jg [0xE9], 0x00, LABEL_13B3
	mov [0xE9], 0xFFFF
	call LABEL_11E6
	break
	call LABEL_11F0
	break
	call LABEL_11FA

LABEL_1401:
	break
	je [0xE9], 0x00, LABEL_1332
	jg [0xE9], 0x00, LABEL_1386
	jmp LABEL_1401

BOUNDS_CHECK_VARE7_VS_VAR02:
	mov [0xF8], [0x02]
	sub [0xF8], 0x000A
	jl [0xE7], [0xF8], SHARED_RET
	add [0xF8], 0x0014
	jg [0xE7], [0xF8], SHARED_RET
	mov [0xF8], [0xE6]
	sub [0xF8], 0x0009
	jl [0x01], [0xF8], SHARED_RET
	add [0xF8], 0x0012
	jg [0x01], [0xF8], SHARED_RET
	jge [0x04], 0x4000, SHARED_RET
	or [0x04], 0x4000
	setup channel=0x14, address=LABEL_1282
	setup channel=0x15, address=LABEL_130E
	setPalette 0x1B
	ret

JUNK__1456:
	mov [0xE6], 0x0008
	mov [0xE7], 0x0003
	mov [0xE8], 0x0064

LABEL_1462:
	mov [0x1D], [0xE7]
	mov [0x21], 0x00A0
	mov [0x22], [0xE8]
	mov [0x23], 0x0040
	call LABEL_148E
	add [0x22], 0x00C8
	call LABEL_148E
	add [0x22], 0x00C8
	call LABEL_148E
	break
	sub [0xE8], 0x0019
	djnz [0xE6], LABEL_1462
	jmp JUNK__1456
LABEL_148D:
	db 0x11

LABEL_148E:
	ret

LABEL_148F:
	break
	jl [0x01], 0xB4, LABEL_148F
	or [0x74], 0x4000
	setPalette 0x09
	killChannel

LABEL_149E:
	setup channel=0x22, address=LABEL_510D
	setup channel=0x23, address=KILL_CHANNEL_LANDING
	setup channel=0x24, address=LABEL_512D
	setup channel=0x25, address=KILL_CHANNEL_LANDING
	setup channel=0x26, address=LABEL_5168
	setup channel=0x27, address=KILL_CHANNEL_LANDING
	setup channel=0x28, address=LABEL_51A3
	ret

LABEL_14BB:
	jl [HACK_VAR_67], 0x4A, LABEL_14E0
	jg [HACK_VAR_67], 0x50, LABEL_14E0
	mov [0xF8], [0xB2]
	and [0xF8], 0x0001
	je [0xF8], 0x01, LABEL_14D7
	call LABEL_455C

LABEL_14D7:
	je [0xB3], 0x00, LABEL_14E0
	call LABEL_45FD

LABEL_14E0:
	jl [HACK_VAR_67], 0x6A, LABEL_1517
	jg [HACK_VAR_67], 0x70, LABEL_1517
	mov [0xF8], [0xB2]
	and [0xF8], 0x0002
	jne [0xF8], 0x00, LABEL_1505
	jne [HACK_VAR_67], 0x70, LABEL_1505
	call LABEL_461D
	jmp LABEL_150E

LABEL_1505:
	je [0xB4], 0x00, LABEL_150E
	call LABEL_45BE

LABEL_150E:
	je [0xB5], 0x00, LABEL_1517
	call LABEL_459E

LABEL_1517:
	ret

JUNK__1518:
	setPalette 0x15
	break
	setPalette 0x16
	break
	setPalette 0x17
	break
	setPalette 0x18
	break
	jmp JUNK__1518
LABEL_152B:
	db 0x11

LABEL_152C:
	mov [0x29], 0x0005
	call LABEL_935A

LABEL_1533:
	break
	call LABEL_935A
	djnz [0x29], LABEL_1533
	mov [0x0E], 0x0004
	mov [0x29], 0x0005

LABEL_1543:
	break
	sub [0x07], 0x000A
	add [0x08], 0x0015
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	add [0x07], 0x000A
	sub [0x08], 0x0015
	video type=1, offset=CINEMATIC_141, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x29], LABEL_1543
	mov [0x0E], 0x0000
	and [0x11], 0xF7FF
	or [0x09], 0x0400
	setup channel=0x14, address=KILL_CHANNEL_LANDING
	setup channel=0x34, address=LABEL_17A8
	setup channel=0x35, address=HANG_DRAW_CIN_186
	break
	jmp INIT_VARS_0E_29
LABEL_157C:
	db 0x11
