LABEL_C91D:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	djnz [0xEA], LABEL_C91D
	mov [0xEA], 0x000E

LABEL_C929:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	play id=0x0055, freq=0x18, vol=0x14, channel=0x00
	play id=0x0055, freq=0x14, vol=0x14, channel=0x02
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	add [0xE6], 0x0001
	break
	djnz [0xEA], LABEL_C929
	mov [0xEA], 0x0004

LABEL_C94D:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	djnz [0xEA], LABEL_C94D
	mov [0xEA], 0x000E

LABEL_C959:
	sub [0xE6], 0x0001
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	play id=0x0055, freq=0x1C, vol=0x14, channel=0x00
	play id=0x0055, freq=0x14, vol=0x14, channel=0x02
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	djnz [0xEA], LABEL_C959
	mov [0xEA], 0x0004

LABEL_C97D:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	djnz [0xEA], LABEL_C97D
	mov [0xE6], 0xFFF9
	mov [0xEA], 0x0007

LABEL_C98D:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	play id=0x0055, freq=0x16, vol=0x14, channel=0x00
	play id=0x0055, freq=0x1C, vol=0x14, channel=0x02
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	add [0xE6], 0x0001
	break
	djnz [0xEA], LABEL_C98D
	mov [0xEA], 0x0014

LABEL_C9B1:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	djnz [0xEA], LABEL_C9B1
	mov [0xEA], 0x0007

LABEL_C9BD:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	play id=0x0055, freq=0x16, vol=0x14, channel=0x00
	play id=0x0055, freq=0x18, vol=0x14, channel=0x02
	break
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	sub [0xE6], 0x0001
	break
	djnz [0xEA], LABEL_C9BD
	jmp INIT_VARS_E6_EA
LABEL_C9E0:
	db 0x11

DRAW_CIN_387_IF_VAR_E6_VALID:
	jg [0xE6], 0xFFF9, LABEL_C9EF
	video offset=CINEMATIC_367, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_C9EF:
	jne [0xE6], 0xFFFA, LABEL_C9FD
	video offset=CINEMATIC_366, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_C9FD:
	jne [0xE6], 0xFFFB, LABEL_CA0B
	video offset=CINEMATIC_365, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CA0B:
	jne [0xE6], 0xFFFC, LABEL_CA19
	video offset=CINEMATIC_364, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CA19:
	jne [0xE6], 0xFFFD, LABEL_CA27
	video offset=CINEMATIC_363, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CA27:
	jne [0xE6], 0xFFFE, LABEL_CA35
	video offset=CINEMATIC_362, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CA35:
	jne [0xE6], 0xFFFF, LABEL_CA43
	video offset=CINEMATIC_361, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CA43:
	jne [0xE6], 0x00, LABEL_CA50
	video offset=CINEMATIC_360, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CA50:
	jne [0xE6], 0x01, LABEL_CA5D
	video offset=CINEMATIC_359, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CA5D:
	jne [0xE6], 0x02, LABEL_CA6A
	video offset=CINEMATIC_358, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CA6A:
	jne [0xE6], 0x03, LABEL_CA7D
	video offset=CINEMATIC_357, x=[0x21], y=[0x22], zoom=[0x23]
	video offset=CINEMATIC_354, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CA7D:
	jne [0xE6], 0x04, LABEL_CA90
	video offset=CINEMATIC_356, x=[0x21], y=[0x22], zoom=[0x23]
	video offset=CINEMATIC_354, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CA90:
	jg [0xE6], 0x05, DRAW_CIN_353_THEN_CIN_354
	video offset=CINEMATIC_355, x=[0x21], y=[0x22], zoom=[0x23]
	video offset=CINEMATIC_354, x=[0x21], y=[0x22], zoom=[0x23]
	ret

DRAW_CIN_353_THEN_CIN_354:
	video offset=CINEMATIC_353, x=[0x21], y=[0x22], zoom=[0x23]
	video offset=CINEMATIC_354, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CAB0:
	video offset=CINEMATIC_403, x=169, y=94
	break
	video offset=CINEMATIC_404, x=169, y=94
	break
	video offset=CINEMATIC_405, x=169, y=94
	break
	jmp LABEL_CAB0
LABEL_CAC2:
	db 0x11

DRAW_CIN_SEQ_402_402_402_AT_CAC3:
	video offset=CINEMATIC_402, x=158, y=70
	video offset=CINEMATIC_402, x=158, y=59
	video offset=CINEMATIC_402, x=159, y=51
	video offset=CINEMATIC_402, x=158, y=40
	video offset=CINEMATIC_402, x=158, y=27
	ret

DRAW_CIN_SEQ_402_402_402_AT_CAD8:
	video offset=CINEMATIC_402, x=157, y=70
	video offset=CINEMATIC_402, x=158, y=59
	video offset=CINEMATIC_402, x=159, y=51
	video offset=CINEMATIC_402, x=158, y=40
	video offset=CINEMATIC_402, x=158, y=27
	ret

DRAW_CIN_SEQ_402_402_402_AT_CAED:
	video offset=CINEMATIC_402, x=156, y=70
	video offset=CINEMATIC_402, x=157, y=59
	video offset=CINEMATIC_402, x=158, y=51
	video offset=CINEMATIC_402, x=158, y=40
	video offset=CINEMATIC_402, x=158, y=27
	ret

DRAW_CIN_SEQ_402_402_402_AT_CB02:
	video offset=CINEMATIC_402, x=155, y=70
	video offset=CINEMATIC_402, x=156, y=59
	video offset=CINEMATIC_402, x=157, y=51
	video offset=CINEMATIC_402, x=157, y=40
	video offset=CINEMATIC_402, x=157, y=27
	ret

DRAW_CIN_SEQ_402_402_402_AT_CB17:
	video offset=CINEMATIC_402, x=159, y=70
	video offset=CINEMATIC_402, x=159, y=59
	video offset=CINEMATIC_402, x=159, y=51
	video offset=CINEMATIC_402, x=158, y=40
	video offset=CINEMATIC_402, x=158, y=27
	ret

DRAW_CIN_SEQ_402_402_402_AT_CB2C:
	video offset=CINEMATIC_402, x=160, y=70
	video offset=CINEMATIC_402, x=159, y=59
	video offset=CINEMATIC_402, x=160, y=51
	video offset=CINEMATIC_402, x=158, y=40
	video offset=CINEMATIC_402, x=158, y=27
	ret

DRAW_CIN_SEQ_402_402_402_AT_CB41:
	video offset=CINEMATIC_402, x=161, y=70
	video offset=CINEMATIC_402, x=160, y=59
	video offset=CINEMATIC_402, x=161, y=51
	video offset=CINEMATIC_402, x=159, y=40
	video offset=CINEMATIC_402, x=159, y=27
	ret
LABEL_CB56:
	db 0x11

LABEL_CB57:
	call DRAW_CIN_SEQ_402_402_402_AT_CB02
	break
	call DRAW_CIN_SEQ_402_402_402_AT_CAED
	break
	call DRAW_CIN_SEQ_402_402_402_AT_CAD8
	break
	call DRAW_CIN_SEQ_402_402_402_AT_CAC3
	break
	call DRAW_CIN_SEQ_402_402_402_AT_CB17
	break
	call DRAW_CIN_SEQ_402_402_402_AT_CB2C
	break
	call DRAW_CIN_SEQ_402_402_402_AT_CB41
	break
	call DRAW_CIN_SEQ_402_402_402_AT_CB41
	break
	call DRAW_CIN_SEQ_402_402_402_AT_CB2C
	break
	call DRAW_CIN_SEQ_402_402_402_AT_CB17
	break
	call DRAW_CIN_SEQ_402_402_402_AT_CAC3
	break
	call DRAW_CIN_SEQ_402_402_402_AT_CAD8
	break
	call DRAW_CIN_SEQ_402_402_402_AT_CAED
	break
	call DRAW_CIN_SEQ_402_402_402_AT_CB02
	break
	jmp LABEL_CB57
LABEL_CB92:
	db 0x11

DRAW_CIN_424_426_VERTICAL:
	video offset=CINEMATIC_403, x=169, y=94
	break
	video offset=CINEMATIC_404, x=169, y=110
	break
	video offset=CINEMATIC_405, x=169, y=130
	break
	video offset=CINEMATIC_403, x=169, y=154
	video offset=CINEMATIC_134, x=144, y=147
	play id=0x005B, freq=0x14, vol=0x40, channel=0x03
	break
	play id=0x005B, freq=0x14, vol=0x40, channel=0x02
	video offset=CINEMATIC_404, x=169, y=180
	video offset=CINEMATIC_134, x=178, y=173
	break
	video offset=CINEMATIC_401, x=169, y=178
	break
	video offset=CINEMATIC_401, x=169, y=180
	selectVideoPage 0x00
	video offset=CINEMATIC_401, x=169, y=180
	selectVideoPage 0xFF
	break
	killChannel

LABEL_CBD3:
	video offset=CINEMATIC_397, x=104, y=49
	video offset=CINEMATIC_397, x=234, y=49
	break
	video offset=CINEMATIC_398, x=104, y=49
	video offset=CINEMATIC_399, x=234, y=49
	break
	video offset=CINEMATIC_399, x=104, y=49
	video offset=CINEMATIC_398, x=234, y=49
	break
	jmp LABEL_CBD3
LABEL_CBF1:
	db 0x11

LABEL_CBF2:
	break
	jl [HERO_Y], 0x8C, LABEL_CBF2
	add [HERO_X], 0x000A
	jl [HERO_X], 0xA0, LABEL_CC07
	sub [HERO_X], 0x000F

LABEL_CC07:
	setup channel=0x3C, address=LABEL_3D88
	mov [SCROLL_Y], 0xFFF0

LABEL_CC0F:
	break
	mov [HACK_VAR_67], 0x0028
	setup channel=0x36, address=LABEL_27B9
	mov [0x35], 0x0010
	sub [SCROLL_Y], [0x35]
	sub [HERO_Y], [0x35]
	mov [0x44], 0x0135
	add [0x44], [SCROLL_Y]
	mov [0x41], [0x44]
	add [0x41], 0x0014
	jg [SCROLL_Y], 0xFF38, LABEL_CC0F
	copyVideoPage src=0x03, dst=0x00
	setup channel=0x3C, address=LABEL_3D25
	setup channel=0x37, address=HANG_DRAW_CIN_269
	mov [SCROLL_Y], 0xFF38
	mov [0x44], 0x005D
	mov [0x41], 0x0078
	mov [0x47], 0x00FD
	mov [0x48], 0x00E0
	mov [0x49], 0x1216
	deleteChannels first=0x22, last=0x28
	killChannel

HANG_DRAW_CIN_269:
	video offset=CINEMATIC_269, x=160, y=100
	break
	jmp HANG_DRAW_CIN_269
LABEL_CC67:
	db 0x11

LABEL_CC68:
	video offset=CINEMATIC_338, x=114, y=140
	video offset=CINEMATIC_276, x=91, y=146
	video offset=CINEMATIC_338, x=242, y=145
	break
	jmp LABEL_CC68
LABEL_CC78:
	db 0x11

LABEL_CC79:
	video offset=CINEMATIC_338, x=181, y=144
	video offset=CINEMATIC_276, x=121, y=203, zoom=0x40
	video offset=CINEMATIC_338, x=262, y=145
	video offset=CINEMATIC_338, x=85, y=145
	jl [HERO_Y], 0xD2, LABEL_CC96
	video offset=CINEMATIC_277, x=203, y=208, zoom=0x40

LABEL_CC96:
	break
	jmp LABEL_CC79
LABEL_CC9A:
	db 0x11

LABEL_CC9B:
	video offset=CINEMATIC_276, x=99, y=160
	video offset=CINEMATIC_277, x=192, y=168
	break
	jmp LABEL_CC9B
LABEL_CCA7:
	db 0x11

LABEL_CCA8:
	jg [HERO_Y], 0x65, LABEL_CCC2
	video offset=CINEMATIC_389, x=112, y=69
	video offset=CINEMATIC_277, x=37, y=31
	video offset=CINEMATIC_277, x=149, y=11
	video offset=CINEMATIC_389, x=59, y=15
	video offset=CINEMATIC_277, x=76, y=76

LABEL_CCC2:
	break
	jmp LABEL_CCA8

HANG_DRAW_CIN_300:
	video offset=CINEMATIC_300, x=160, y=100
	break
	jmp HANG_DRAW_CIN_300
LABEL_CCCE:
	db 0x11

LABEL_CCCF:
	jg [HERO_Y], 0x78, LABEL_CCE1
	video offset=CINEMATIC_389, x=226, y=87
	video offset=CINEMATIC_389, x=150, y=27
	video offset=CINEMATIC_425, x=226, y=136

LABEL_CCE1:
	break
	jmp LABEL_CCCF

LABEL_CCE5:
	video offset=CINEMATIC_412, x=184, y=143
	video offset=CINEMATIC_412, x=278, y=150
	video offset=CINEMATIC_412, x=80, y=147
	break
	jmp LABEL_CCE5
LABEL_CCF6:
	db 0x11

LABEL_CCF7:
	video offset=CINEMATIC_412, x=79, y=119
	video offset=CINEMATIC_412, x=279, y=117
	break
	jmp LABEL_CCF7
LABEL_CD04:
	db 0x11

LABEL_CD05:
	video offset=CINEMATIC_412, x=230, y=151
	video offset=CINEMATIC_412, x=270, y=183
	video offset=CINEMATIC_412, x=77, y=168
	video offset=CINEMATIC_541, x=265, y=138
	break
	jmp LABEL_CD05
LABEL_CD1B:
	db 0x11

HANG_DRAW_CIN_412:
	video offset=CINEMATIC_412, x=178, y=140
	break
	jmp HANG_DRAW_CIN_412
LABEL_CD24:
	db 0x11

LABEL_CD25:
	video offset=CINEMATIC_276, x=46, y=139
	mov [0x42], 0xF060
	jl [HERO_X], 0x35, LABEL_CD37
	mov [0x42], 0x001D

LABEL_CD37:
	break
	jmp LABEL_CD25
LABEL_CD3B:
	db 0x11

LABEL_CD3C:
	break
	mov [0xF8], [0x04]
	and [0xF8], 0x0020
	mov [0x47], 0x0040
	jne [0xF8], 0x00, LABEL_CD3C
	mov [0xF8], [0xB1]
	and [0xF8], 0x0002
	mov [0x47], 0x010A
	jne [0xF8], 0x00, LABEL_CD3C
	mov [0x47], 0x008C
	jmp LABEL_CD3C
LABEL_CD66:
	db 0x11

LABEL_CD67:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_200, x=160, y=100
	video offset=CINEMATIC_201, x=160, y=100
	video offset=CINEMATIC_202, x=160, y=100
	video offset=CINEMATIC_203, x=160, y=100
	video offset=CINEMATIC_204, x=160, y=100
	ret

LABEL_CD7F:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_206, x=160, y=100
	video offset=CINEMATIC_207, x=160, y=100
	video offset=CINEMATIC_208, x=160, y=100
	video offset=CINEMATIC_209, x=169, y=164
	ret

LABEL_CD93:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_258, x=160, y=100
	video offset=CINEMATIC_259, x=160, y=70
	video offset=CINEMATIC_260, x=160, y=100
	ret
LABEL_CDA3:
	db 0x11
