LABEL_CDBC:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	djnz [0xEA], LABEL_CDBC
	mov [0xEA], 0x0007

LABEL_CDC8:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	play id=0x0055, freq=0x1C, vol=0x14, channel=0x02
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	add [0xE6], 0x0001
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	add [0xE6], 0x0001
	break
	djnz [0xEA], LABEL_CDC8
	mov [0xEA], 0x0004

LABEL_CDF6:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	djnz [0xEA], LABEL_CDF6
	mov [0xEA], 0x0007

LABEL_CE02:
	sub [0xE6], 0x0001
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	sub [0xE6], 0x0001
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	play id=0x0055, freq=0x1C, vol=0x14, channel=0x02
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	djnz [0xEA], LABEL_CE02
	mov [0xEA], 0x0004

LABEL_CE30:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	djnz [0xEA], LABEL_CE30
	mov [0xE6], 0xFFF9
	mov [0xEA], 0x0004

LABEL_CE40:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	play id=0x0055, freq=0x1C, vol=0x14, channel=0x02
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	add [0xE6], 0x0001
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	add [0xE6], 0x0001
	break
	djnz [0xEA], LABEL_CE40
	sub [0xE6], 0x0001
	mov [0xEA], 0x0014

LABEL_CE72:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	djnz [0xEA], LABEL_CE72
	mov [0xEA], 0x0003

LABEL_CE7E:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	sub [0xE6], 0x0001
	break
	play id=0x0055, freq=0x1C, vol=0x14, channel=0x02
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	sub [0xE6], 0x0001
	break
	djnz [0xEA], LABEL_CE7E
	sub [0xE6], 0x0001
	jmp INIT_VARS_E6_EA
LABEL_CEAF:
	db 0x11

DRAW_CIN_387_IF_VAR_E6_VALID:
	jg [0xE6], 0xFFF9, LABEL_CEBE
	video offset=CINEMATIC_387, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CEBE:
	jne [0xE6], 0xFFFA, LABEL_CECC
	video offset=CINEMATIC_386, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CECC:
	jne [0xE6], 0xFFFB, LABEL_CEDA
	video offset=CINEMATIC_385, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CEDA:
	jne [0xE6], 0xFFFC, LABEL_CEE8
	video offset=CINEMATIC_384, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CEE8:
	jne [0xE6], 0xFFFD, LABEL_CEF6
	video offset=CINEMATIC_383, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CEF6:
	jne [0xE6], 0xFFFE, LABEL_CF04
	video offset=CINEMATIC_382, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CF04:
	jne [0xE6], 0xFFFF, LABEL_CF12
	video offset=CINEMATIC_381, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CF12:
	jne [0xE6], 0x00, LABEL_CF1F
	video offset=CINEMATIC_380, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CF1F:
	jne [0xE6], 0x01, LABEL_CF2C
	video offset=CINEMATIC_379, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CF2C:
	jne [0xE6], 0x02, LABEL_CF39
	video offset=CINEMATIC_378, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CF39:
	jne [0xE6], 0x03, LABEL_CF4C
	video offset=CINEMATIC_377, x=[0x21], y=[0x22], zoom=[0x23]
	video offset=CINEMATIC_374, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CF4C:
	jne [0xE6], 0x04, LABEL_CF5F
	video offset=CINEMATIC_376, x=[0x21], y=[0x22], zoom=[0x23]
	video offset=CINEMATIC_374, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CF5F:
	jg [0xE6], 0x05, DRAW_CIN_373_THEN_CIN_374
	video offset=CINEMATIC_375, x=[0x21], y=[0x22], zoom=[0x23]
	video offset=CINEMATIC_374, x=[0x21], y=[0x22], zoom=[0x23]
	ret

DRAW_CIN_373_THEN_CIN_374:
	video offset=CINEMATIC_373, x=[0x21], y=[0x22], zoom=[0x23]
	video offset=CINEMATIC_374, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CF7F:
	video offset=CINEMATIC_424, x=169, y=94
	break
	video offset=CINEMATIC_425, x=169, y=94
	break
	video offset=CINEMATIC_426, x=169, y=94
	break
	jmp LABEL_CF7F
LABEL_CF91:
	db 0x11

DRAW_CIN_SEQ_423_423_423_AT_CF92:
	video offset=CINEMATIC_423, x=158, y=70
	video offset=CINEMATIC_423, x=158, y=59
	video offset=CINEMATIC_423, x=159, y=51
	video offset=CINEMATIC_423, x=158, y=40
	video offset=CINEMATIC_423, x=158, y=27
	ret

DRAW_CIN_SEQ_423_423_423_AT_CFA7:
	video offset=CINEMATIC_423, x=157, y=70
	video offset=CINEMATIC_423, x=158, y=59
	video offset=CINEMATIC_423, x=159, y=51
	video offset=CINEMATIC_423, x=158, y=40
	video offset=CINEMATIC_423, x=158, y=27
	ret

DRAW_CIN_SEQ_423_423_423_AT_CFBC:
	video offset=CINEMATIC_423, x=156, y=70
	video offset=CINEMATIC_423, x=157, y=59
	video offset=CINEMATIC_423, x=158, y=51
	video offset=CINEMATIC_423, x=158, y=40
	video offset=CINEMATIC_423, x=158, y=27
	ret

DRAW_CIN_SEQ_423_423_423_AT_CFD1:
	video offset=CINEMATIC_423, x=155, y=70
	video offset=CINEMATIC_423, x=156, y=59
	video offset=CINEMATIC_423, x=157, y=51
	video offset=CINEMATIC_423, x=157, y=40
	video offset=CINEMATIC_423, x=157, y=27
	ret

DRAW_CIN_SEQ_423_423_423_AT_CFE6:
	video offset=CINEMATIC_423, x=159, y=70
	video offset=CINEMATIC_423, x=159, y=59
	video offset=CINEMATIC_423, x=159, y=51
	video offset=CINEMATIC_423, x=158, y=40
	video offset=CINEMATIC_423, x=158, y=27
	ret

DRAW_CIN_SEQ_423_423_423_AT_CFFB:
	video offset=CINEMATIC_423, x=160, y=70
	video offset=CINEMATIC_423, x=159, y=59
	video offset=CINEMATIC_423, x=160, y=51
	video offset=CINEMATIC_423, x=158, y=40
	video offset=CINEMATIC_423, x=158, y=27
	ret

DRAW_CIN_SEQ_423_423_423_AT_D010:
	video offset=CINEMATIC_423, x=161, y=70
	video offset=CINEMATIC_423, x=160, y=59
	video offset=CINEMATIC_423, x=161, y=51
	video offset=CINEMATIC_423, x=159, y=40
	video offset=CINEMATIC_423, x=159, y=27
	ret
LABEL_D025:
	db 0x11

LABEL_D026:
	call DRAW_CIN_SEQ_423_423_423_AT_CFD1
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CFBC
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CFA7
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CF92
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CFE6
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CFFB
	break
	call DRAW_CIN_SEQ_423_423_423_AT_D010
	break
	call DRAW_CIN_SEQ_423_423_423_AT_D010
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CFFB
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CFE6
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CF92
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CFA7
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CFBC
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CFD1
	break
	jmp LABEL_D026
LABEL_D061:
	db 0x11

DRAW_CIN_424_426_VERTICAL:
	video offset=CINEMATIC_424, x=169, y=94
	break
	video offset=CINEMATIC_425, x=169, y=110
	break
	video offset=CINEMATIC_426, x=169, y=130
	break
	video offset=CINEMATIC_424, x=169, y=154
	video offset=CINEMATIC_134, x=144, y=147
	play id=0x005B, freq=0x14, vol=0x40, channel=0x03
	break
	play id=0x005B, freq=0x14, vol=0x40, channel=0x02
	video offset=CINEMATIC_425, x=169, y=180
	video offset=CINEMATIC_134, x=178, y=173
	break
	video offset=CINEMATIC_422, x=169, y=178
	break
	video offset=CINEMATIC_422, x=169, y=180
	selectVideoPage 0x00
	video offset=CINEMATIC_422, x=169, y=180
	selectVideoPage 0xFF
	break
	killChannel

LABEL_D0A2:
	video offset=CINEMATIC_418, x=104, y=49
	video offset=CINEMATIC_418, x=234, y=49
	break
	video offset=CINEMATIC_419, x=104, y=49
	video offset=CINEMATIC_420, x=234, y=49
	break
	video offset=CINEMATIC_420, x=104, y=49
	video offset=CINEMATIC_419, x=234, y=49
	break
	jmp LABEL_D0A2
LABEL_D0C0:
	db 0x11

LABEL_D0C1:
	break
	jl [HERO_Y], 0x8C, LABEL_D0C1
	add [HERO_X], 0x000A
	jl [HERO_X], 0xA0, LABEL_D0D6
	sub [HERO_X], 0x000F

LABEL_D0D6:
	setup channel=0x3C, address=LABEL_3FB4
	mov [SCROLL_Y], 0xFFF0

LABEL_D0DE:
	break
	mov [HACK_VAR_67], 0x0028
	setup channel=0x36, address=LABEL_2955
	mov [0x35], 0x0010
	sub [SCROLL_Y], [0x35]
	sub [HERO_Y], [0x35]
	mov [0x44], 0x0135
	add [0x44], [SCROLL_Y]
	mov [0x41], [0x44]
	add [0x41], 0x0014
	jg [SCROLL_Y], 0xFF38, LABEL_D0DE
	copyVideoPage src=0x03, dst=0x00
	setup channel=0x3C, address=LABEL_3F46
	setup channel=0x37, address=HANG_DRAW_CIN_287
	mov [SCROLL_Y], 0xFF38
	mov [0x44], 0x005D
	mov [0x41], 0x0078
	mov [0x47], 0x00FD
	deleteChannels first=0x22, last=0x28
	jl [0xB1], 0x00, KILL_CHAN_AT_01FB
	mov [0x48], 0x00E0
	mov [0x49], 0x1216
	killChannel

HANG_DRAW_CIN_287:
	video offset=CINEMATIC_287, x=160, y=100
	break
	jmp HANG_DRAW_CIN_287
LABEL_D13C:
	db 0x11

LABEL_D13D:
	video offset=CINEMATIC_321, x=114, y=140
	video offset=CINEMATIC_296, x=91, y=146
	video offset=CINEMATIC_321, x=242, y=145
	jl [HERO_X], 0x52, LABEL_D159
	jg [HERO_Y], 0xA8, LABEL_D159
	video offset=CINEMATIC_321, x=114, y=102

LABEL_D159:
	break
	jmp LABEL_D13D
LABEL_D15D:
	db 0x11

LABEL_D15E:
	video offset=CINEMATIC_321, x=181, y=144
	video offset=CINEMATIC_296, x=121, y=203, zoom=0x40
	video offset=CINEMATIC_321, x=262, y=145
	video offset=CINEMATIC_321, x=85, y=145
	jl [HERO_Y], 0xD2, LABEL_D17B
	video offset=CINEMATIC_297, x=203, y=208, zoom=0x40

LABEL_D17B:
	break
	jmp LABEL_D15E
LABEL_D17F:
	db 0x11

LABEL_D180:
	video offset=CINEMATIC_296, x=99, y=160
	video offset=CINEMATIC_297, x=193, y=168
	jl [HERO_Y], 0x8F, LABEL_D192
	video offset=CINEMATIC_297, x=197, y=163

LABEL_D192:
	break
	jmp LABEL_D180
LABEL_D196:
	db 0x11

LABEL_D197:
	jg [HERO_Y], 0x65, LABEL_D1B1
	video offset=CINEMATIC_410, x=112, y=69
	video offset=CINEMATIC_297, x=37, y=31
	video offset=CINEMATIC_297, x=149, y=11
	video offset=CINEMATIC_410, x=59, y=15
	video offset=CINEMATIC_297, x=76, y=76

LABEL_D1B1:
	break
	jmp LABEL_D197

LABEL_D1B5:
	video offset=CINEMATIC_320, x=160, y=100
	jg [HERO_X], 0x1C, LABEL_D1C5
	video offset=CINEMATIC_321, x=65535, y=92

LABEL_D1C5:
	break
	jmp LABEL_D1B5
LABEL_D1C9:
	db 0x11

LABEL_D1CA:
	jg [HERO_Y], 0x78, LABEL_D1EA
	video offset=CINEMATIC_410, x=150, y=27
	mov [0x46], 0x00C8
	jg [HERO_X], 0x0106, LABEL_D1EA
	mov [0x46], [HERO_X]
	sub [0x46], 0x0032
	video offset=CINEMATIC_447, x=225, y=83

LABEL_D1EA:
	jl [0xA1], 0x00, LABEL_D1F6
	jl [0xA2], 0x00, LABEL_D20E

LABEL_D1F6:
	jl [0xA4], 0x00, LABEL_D202
	jl [0xA5], 0x00, LABEL_D20E

LABEL_D202:
	jl [0xA7], 0x00, LABEL_D212
	jge [0xA8], 0x00, LABEL_D212

LABEL_D20E:
	video offset=CINEMATIC_446, x=163, y=63

LABEL_D212:
	break
	jmp LABEL_D1CA

LABEL_D216:
	video offset=CINEMATIC_433, x=184, y=143
	video offset=CINEMATIC_433, x=278, y=150
	video offset=CINEMATIC_433, x=80, y=147
	break
	jmp LABEL_D216
LABEL_D227:
	db 0x11

LABEL_D228:
	video offset=CINEMATIC_433, x=79, y=119
	video offset=CINEMATIC_433, x=279, y=117
	break
	jmp LABEL_D228
LABEL_D235:
	db 0x11

LABEL_D236:
	video offset=CINEMATIC_433, x=230, y=151
	video offset=CINEMATIC_433, x=270, y=183
	video offset=CINEMATIC_433, x=77, y=168
	video offset=CINEMATIC_564, x=265, y=138
	break
	jmp LABEL_D236
LABEL_D24C:
	db 0x11

HANG_DRAW_CIN_433:
	video offset=CINEMATIC_433, x=178, y=140
	break
	jmp HANG_DRAW_CIN_433
LABEL_D255:
	db 0x11

LABEL_D256:
	video offset=CINEMATIC_296, x=46, y=139
	mov [0x42], 0xF060
	jl [HERO_X], 0x35, LABEL_D268
	mov [0x42], 0x001D

LABEL_D268:
	break
	jmp LABEL_D256
LABEL_D26C:
	db 0x11

LABEL_D26D:
	break
	mov [0xF8], [0x04]
	and [0xF8], 0x0020
	mov [0x47], 0x0040
	jne [0xF8], 0x00, LABEL_D26D
	mov [0xF8], [0xB1]
	and [0xF8], 0x0002
	mov [0x47], 0x010A
	jne [0xF8], 0x00, LABEL_D26D
	mov [0x47], 0x008C
	jmp LABEL_D26D
LABEL_D297:
	db 0x11

LABEL_D298:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_217, x=160, y=100
	video offset=CINEMATIC_218, x=160, y=100
	video offset=CINEMATIC_219, x=160, y=100
	video offset=CINEMATIC_220, x=160, y=100
	video offset=CINEMATIC_221, x=160, y=100
	ret

LABEL_D2B0:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_223, x=160, y=100
	video offset=CINEMATIC_224, x=160, y=100
	video offset=CINEMATIC_225, x=160, y=100
	video offset=CINEMATIC_226, x=169, y=164
	ret

LABEL_D2C4:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_275, x=160, y=100
	video offset=CINEMATIC_276, x=160, y=70
	video offset=CINEMATIC_277, x=160, y=100
	ret
LABEL_D2D4:
	db 0x11
