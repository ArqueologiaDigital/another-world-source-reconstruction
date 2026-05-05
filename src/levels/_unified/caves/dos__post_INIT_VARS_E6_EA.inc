LABEL_CDC3:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	djnz [0xEA], LABEL_CDC3
	mov [0xEA], 0x000E

LABEL_CDCF:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	play id=0x0055, freq=0x18, vol=0x14, channel=0x00
	play id=0x0055, freq=0x14, vol=0x14, channel=0x02
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	add [0xE6], 0x0001
	break
	djnz [0xEA], LABEL_CDCF
	mov [0xEA], 0x0004

LABEL_CDF3:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	djnz [0xEA], LABEL_CDF3
	mov [0xEA], 0x000E

LABEL_CDFF:
	sub [0xE6], 0x0001
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	play id=0x0055, freq=0x1C, vol=0x14, channel=0x00
	play id=0x0055, freq=0x14, vol=0x14, channel=0x02
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	djnz [0xEA], LABEL_CDFF
	mov [0xEA], 0x0004

LABEL_CE23:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	djnz [0xEA], LABEL_CE23
	mov [0xE6], 0xFFF9
	mov [0xEA], 0x0007

LABEL_CE33:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	play id=0x0055, freq=0x16, vol=0x14, channel=0x00
	play id=0x0055, freq=0x1C, vol=0x14, channel=0x02
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	add [0xE6], 0x0001
	break
	djnz [0xEA], LABEL_CE33
	mov [0xEA], 0x0014

LABEL_CE57:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	djnz [0xEA], LABEL_CE57
	mov [0xEA], 0x0007

LABEL_CE63:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	play id=0x0055, freq=0x16, vol=0x14, channel=0x00
	play id=0x0055, freq=0x18, vol=0x14, channel=0x02
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	sub [0xE6], 0x0001
	break
	djnz [0xEA], LABEL_CE63
	jmp INIT_VARS_E6_EA
LABEL_CE86:
	db 0x11

DRAW_CIN_387_IF_VAR_E6_VALID:
	jg [0xE6], 0xFFF9, LABEL_CE95
	video offset=CINEMATIC_388, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CE95:
	jne [0xE6], 0xFFFA, LABEL_CEA3
	video offset=CINEMATIC_387, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CEA3:
	jne [0xE6], 0xFFFB, LABEL_CEB1
	video offset=CINEMATIC_386, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CEB1:
	jne [0xE6], 0xFFFC, LABEL_CEBF
	video offset=CINEMATIC_385, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CEBF:
	jne [0xE6], 0xFFFD, LABEL_CECD
	video offset=CINEMATIC_384, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CECD:
	jne [0xE6], 0xFFFE, LABEL_CEDB
	video offset=CINEMATIC_383, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CEDB:
	jne [0xE6], 0xFFFF, LABEL_CEE9
	video offset=CINEMATIC_382, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CEE9:
	jne [0xE6], 0x00, LABEL_CEF6
	video offset=CINEMATIC_381, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CEF6:
	jne [0xE6], 0x01, LABEL_CF03
	video offset=CINEMATIC_380, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CF03:
	jne [0xE6], 0x02, LABEL_CF10
	video offset=CINEMATIC_379, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CF10:
	jne [0xE6], 0x03, LABEL_CF23
	video offset=CINEMATIC_378, x=[0x21], y=[0x22], zoom=[0x23]
	video offset=CINEMATIC_375, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CF23:
	jne [0xE6], 0x04, LABEL_CF36
	video offset=CINEMATIC_377, x=[0x21], y=[0x22], zoom=[0x23]
	video offset=CINEMATIC_375, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CF36:
	jg [0xE6], 0x05, DRAW_CIN_374_THEN_CIN_375
	video offset=CINEMATIC_376, x=[0x21], y=[0x22], zoom=[0x23]
	video offset=CINEMATIC_375, x=[0x21], y=[0x22], zoom=[0x23]
	ret

DRAW_CIN_374_THEN_CIN_375:
	video offset=CINEMATIC_374, x=[0x21], y=[0x22], zoom=[0x23]
	video offset=CINEMATIC_375, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CF56:
	video offset=CINEMATIC_424, x=169, y=94
	break
	video offset=CINEMATIC_425, x=169, y=94
	break
	video offset=CINEMATIC_426, x=169, y=94
	break
	jmp LABEL_CF56
LABEL_CF68:
	db 0x11

DRAW_CIN_SEQ_423_423_423_AT_CF69:
	video offset=CINEMATIC_423, x=158, y=70
	video offset=CINEMATIC_423, x=158, y=59
	video offset=CINEMATIC_423, x=159, y=51
	video offset=CINEMATIC_423, x=158, y=40
	video offset=CINEMATIC_423, x=158, y=27
	ret

DRAW_CIN_SEQ_423_423_423_AT_CF7E:
	video offset=CINEMATIC_423, x=157, y=70
	video offset=CINEMATIC_423, x=158, y=59
	video offset=CINEMATIC_423, x=159, y=51
	video offset=CINEMATIC_423, x=158, y=40
	video offset=CINEMATIC_423, x=158, y=27
	ret

DRAW_CIN_SEQ_423_423_423_AT_CF93:
	video offset=CINEMATIC_423, x=156, y=70
	video offset=CINEMATIC_423, x=157, y=59
	video offset=CINEMATIC_423, x=158, y=51
	video offset=CINEMATIC_423, x=158, y=40
	video offset=CINEMATIC_423, x=158, y=27
	ret

DRAW_CIN_SEQ_423_423_423_AT_CFA8:
	video offset=CINEMATIC_423, x=155, y=70
	video offset=CINEMATIC_423, x=156, y=59
	video offset=CINEMATIC_423, x=157, y=51
	video offset=CINEMATIC_423, x=157, y=40
	video offset=CINEMATIC_423, x=157, y=27
	ret

DRAW_CIN_SEQ_423_423_423_AT_CFBD:
	video offset=CINEMATIC_423, x=159, y=70
	video offset=CINEMATIC_423, x=159, y=59
	video offset=CINEMATIC_423, x=159, y=51
	video offset=CINEMATIC_423, x=158, y=40
	video offset=CINEMATIC_423, x=158, y=27
	ret

DRAW_CIN_SEQ_423_423_423_AT_CFD2:
	video offset=CINEMATIC_423, x=160, y=70
	video offset=CINEMATIC_423, x=159, y=59
	video offset=CINEMATIC_423, x=160, y=51
	video offset=CINEMATIC_423, x=158, y=40
	video offset=CINEMATIC_423, x=158, y=27
	ret

DRAW_CIN_SEQ_423_423_423_AT_CFE7:
	video offset=CINEMATIC_423, x=161, y=70
	video offset=CINEMATIC_423, x=160, y=59
	video offset=CINEMATIC_423, x=161, y=51
	video offset=CINEMATIC_423, x=159, y=40
	video offset=CINEMATIC_423, x=159, y=27
	ret
LABEL_CFFC:
	db 0x11

LABEL_CFFD:
	call DRAW_CIN_SEQ_423_423_423_AT_CFA8
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CF93
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CF7E
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CF69
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CFBD
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CFD2
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CFE7
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CFE7
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CFD2
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CFBD
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CF69
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CF7E
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CF93
	break
	call DRAW_CIN_SEQ_423_423_423_AT_CFA8
	break
	jmp LABEL_CFFD
LABEL_D038:
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

LABEL_D079:
	video offset=CINEMATIC_418, x=104, y=49
	video offset=CINEMATIC_418, x=234, y=49
	break
	video offset=CINEMATIC_419, x=104, y=49
	video offset=CINEMATIC_420, x=234, y=49
	break
	video offset=CINEMATIC_420, x=104, y=49
	video offset=CINEMATIC_419, x=234, y=49
	break
	jmp LABEL_D079
LABEL_D097:
	db 0x11

LABEL_D098:
	break
	jl [HERO_Y], 0x8C, LABEL_D098
	add [HERO_X], 0x000A
	jl [HERO_X], 0xA0, LABEL_D0AD
	sub [HERO_X], 0x000F

LABEL_D0AD:
	setup channel=0x3C, address=LABEL_3FCA
	mov [SCROLL_Y], 0xFFF0

LABEL_D0B5:
	break
	mov [HACK_VAR_67], 0x0028
	setup channel=0x36, address=LABEL_298E
	mov [0x35], 0x0010
	sub [SCROLL_Y], [0x35]
	sub [HERO_Y], [0x35]
	mov [0x44], 0x0135
	add [0x44], [SCROLL_Y]
	mov [0x41], [0x44]
	add [0x41], 0x0014
	jg [SCROLL_Y], 0xFF38, LABEL_D0B5
	copyVideoPage src=0x03, dst=0x00
	setup channel=0x3C, address=LABEL_3F5C
	setup channel=0x37, address=HANG_DRAW_CIN_288
	mov [SCROLL_Y], 0xFF38
	mov [0x44], 0x005D
	mov [0x41], 0x0078
	mov [0x47], 0x00FD
	deleteChannels first=0x22, last=0x28
	jl [0xB1], 0x00, KILL_CHAN_AT_016E
	mov [0x48], 0x00E0
	mov [0x49], 0x1216
	killChannel

HANG_DRAW_CIN_288:
	video offset=CINEMATIC_288, x=160, y=100
	break
	jmp HANG_DRAW_CIN_288
LABEL_D113:
	db 0x11

LABEL_D114:
	video offset=CINEMATIC_359, x=114, y=140
	video offset=CINEMATIC_297, x=91, y=146
	video offset=CINEMATIC_359, x=242, y=145
	break
	jmp LABEL_D114
LABEL_D124:
	db 0x11

LABEL_D125:
	video offset=CINEMATIC_359, x=181, y=144
	video offset=CINEMATIC_297, x=121, y=203, zoom=0x40
	video offset=CINEMATIC_359, x=262, y=145
	video offset=CINEMATIC_359, x=85, y=145
	jl [HERO_Y], 0xD2, LABEL_D142
	video offset=CINEMATIC_298, x=203, y=208, zoom=0x40

LABEL_D142:
	break
	jmp LABEL_D125
LABEL_D146:
	db 0x11

LABEL_D147:
	video offset=CINEMATIC_297, x=99, y=160
	video offset=CINEMATIC_298, x=192, y=168
	break
	jmp LABEL_D147
LABEL_D153:
	db 0x11

LABEL_D154:
	jg [HERO_Y], 0x65, LABEL_D16E
	video offset=CINEMATIC_410, x=112, y=69
	video offset=CINEMATIC_298, x=37, y=31
	video offset=CINEMATIC_298, x=149, y=11
	video offset=CINEMATIC_410, x=59, y=15
	video offset=CINEMATIC_298, x=76, y=76

LABEL_D16E:
	break
	jmp LABEL_D154

HANG_DRAW_CIN_321:
	video offset=CINEMATIC_321, x=160, y=100
	break
	jmp HANG_DRAW_CIN_321
LABEL_D17A:
	db 0x11

LABEL_D17B:
	jg [HERO_Y], 0x78, LABEL_D18D
	video offset=CINEMATIC_410, x=226, y=87
	video offset=CINEMATIC_410, x=150, y=27
	video offset=CINEMATIC_446, x=226, y=136

LABEL_D18D:
	break
	jmp LABEL_D17B

LABEL_D191:
	video offset=CINEMATIC_433, x=184, y=143
	video offset=CINEMATIC_433, x=278, y=150
	video offset=CINEMATIC_433, x=80, y=147
	break
	jmp LABEL_D191
LABEL_D1A2:
	db 0x11

LABEL_D1A3:
	video offset=CINEMATIC_433, x=79, y=119
	video offset=CINEMATIC_433, x=279, y=117
	break
	jmp LABEL_D1A3
LABEL_D1B0:
	db 0x11

LABEL_D1B1:
	video offset=CINEMATIC_433, x=230, y=151
	video offset=CINEMATIC_433, x=270, y=183
	video offset=CINEMATIC_433, x=77, y=168
	video offset=CINEMATIC_562, x=265, y=138
	break
	jmp LABEL_D1B1
LABEL_D1C7:
	db 0x11

HANG_DRAW_CIN_433:
	video offset=CINEMATIC_433, x=178, y=140
	break
	jmp HANG_DRAW_CIN_433
LABEL_D1D0:
	db 0x11

LABEL_D1D1:
	video offset=CINEMATIC_297, x=46, y=139
	mov [0x42], 0xF060
	jl [HERO_X], 0x35, LABEL_D1E3
	mov [0x42], 0x001D

LABEL_D1E3:
	break
	jmp LABEL_D1D1
LABEL_D1E7:
	db 0x11

LABEL_D1E8:
	break
	mov [0xF8], [0x04]
	and [0xF8], 0x0020
	mov [0x47], 0x0040
	jne [0xF8], 0x00, LABEL_D1E8
	mov [0xF8], [0xB1]
	and [0xF8], 0x0002
	mov [0x47], 0x010A
	jne [0xF8], 0x00, LABEL_D1E8
	mov [0x47], 0x008C
	jmp LABEL_D1E8
LABEL_D212:
	db 0x11

LABEL_D213:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_217, x=160, y=100
	video offset=CINEMATIC_218, x=160, y=100
	video offset=CINEMATIC_219, x=160, y=100
	video offset=CINEMATIC_220, x=160, y=100
	video offset=CINEMATIC_221, x=160, y=100
	ret

LABEL_D22B:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_223, x=160, y=100
	video offset=CINEMATIC_224, x=160, y=100
	video offset=CINEMATIC_225, x=160, y=100
	video offset=CINEMATIC_226, x=169, y=164
	ret

LABEL_D23F:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_276, x=160, y=100
	video offset=CINEMATIC_277, x=160, y=70
	video offset=CINEMATIC_278, x=160, y=100
	ret
LABEL_D24F:
	db 0x11
