LABEL_10F4:
	break
	call LABEL_1104
	add [0x50], 0x000A
	djnz [0x51], LABEL_10F4
	jmp INIT_VARS_50_NEG40_51_32
LABEL_1103:
	db 0x11

LABEL_1104:
	jle [0x4F], 0x00, SHARED_RET
	jne [0x4E], 0x00, SHARED_RET
	sub [0x4F], 0x0001
	mov [0x4E], 0x0001
	call SUM_HASH_VARS_TO_VAR_64
	mov [0x4B], [0x64]
	and [0x4B], 0x001F
	add [0x4B], [0x50]
	call SUM_HASH_VARS_TO_VAR_64
	mov [0x4C], [0x64]
	and [0x4C], 0x0007
	add [0x4C], 0x0089
	call SUM_HASH_VARS_TO_VAR_64
	mov [0x4D], [0x64]
	and [0x4D], 0x000F
	add [0x4D], 0x0037
	ret

WAIT_VAR4E_PLAY_8C_DRAW_CIN_201:
	break
	je [0x4E], 0x00, WAIT_VAR4E_PLAY_8C_DRAW_CIN_201
	play id=0x008C, freq=0x1E, vol=0x14, channel=0x01
	video type=1, offset=CINEMATIC_148, x=[0x4b], y=[0x4c], zoom=[0x4d]
	break
	video type=1, offset=CINEMATIC_149, x=[0x4b], y=[0x4c], zoom=[0x4d]
	break
	video type=1, offset=CINEMATIC_150, x=[0x4b], y=[0x4c], zoom=[0x4d]
	selectVideoPage 0x03
	video type=1, offset=CINEMATIC_151, x=[0x4b], y=[0x4c], zoom=[0x4d]
	selectVideoPage 0xFF
	mov [0x4E], 0x0000
	jmp WAIT_VAR4E_PLAY_8C_DRAW_CIN_201
LABEL_1174:
	db 0x11

WAIT_VAR3E_DEC_AND_RANDOMIZE:
	break
	jle [0x3E], 0x00, WAIT_VAR3E_DEC_AND_RANDOMIZE
	sub [0x3E], 0x0001
	call SUM_HASH_VARS_TO_VAR_64
	mov [RANDOM_SEED], [0x65]
	mov [0x3D], [0x64]
	shr [0x3D], 0x0008
	and [0x3D], 0x001F
	add [0x3D], 0x005A
	play id=0x008C, freq=0x19, vol=0x0D, channel=0x00
	video type=1, offset=CINEMATIC_152, x=[0x3c], y=[0x3d], zoom=0x40
	selectVideoPage 0x03
	call SUM_HASH_VARS_TO_VAR_64
	mov [0xF8], [0x64]
	and [0xF8], 0x0003
	jne [0xF8], 0x00, LABEL_11B7
	video type=1, offset=CINEMATIC_155, x=[0x3c], y=[0x3d], zoom=0x40

LABEL_11B7:
	jne [0xF8], 0x01, LABEL_11C2
	video type=1, offset=CINEMATIC_154, x=[0x3c], y=[0x3d], zoom=0x40

LABEL_11C2:
	jl [0xF8], 0x02, LABEL_11CD
	video type=1, offset=CINEMATIC_153, x=[0x3c], y=[0x3d], zoom=0x40

LABEL_11CD:
	selectVideoPage 0xFF
	jmp WAIT_VAR3E_DEC_AND_RANDOMIZE
LABEL_11D2:
	db 0x11

HANG_DRAW_CIN_123:
	video type=1, offset=CINEMATIC_123, x=[0x0f], y=[0x10], zoom=0x40
	break
	jmp HANG_DRAW_CIN_123

HANG_DRAW_CIN_115:
	video type=1, offset=CINEMATIC_115, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp HANG_DRAW_CIN_115

WAIT_VAR46_PLAY_8E_DRAW_CIN_056:
	break
	je [0x46], 0x00, WAIT_VAR46_PLAY_8E_DRAW_CIN_056
	play id=0x008E, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_059, x=160, y=100
	break
	video type=1, offset=CINEMATIC_059, x=160, y=100
	break
	video type=1, offset=CINEMATIC_060, x=160, y=100
	break
	video type=1, offset=CINEMATIC_061, x=160, y=100
	break
	video type=1, offset=CINEMATIC_062, x=160, y=100
	break
	break
	break
	killChannel

WAIT_VAR56_PLAY_8E_DRAW_CIN_020:
	break
	je [0x56], 0x00, WAIT_VAR56_PLAY_8E_DRAW_CIN_020
	play id=0x008E, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_063, x=195, y=79
	break
	video type=1, offset=CINEMATIC_063, x=202, y=75
	break
	video type=1, offset=CINEMATIC_064, x=212, y=66
	break
	video type=1, offset=CINEMATIC_063, x=220, y=58
	break
	video type=1, offset=CINEMATIC_065, x=235, y=55
	break
	video type=1, offset=CINEMATIC_066, x=247, y=61
	break
	video type=1, offset=CINEMATIC_067, x=258, y=73, zoom=0x40
	break
	video type=1, offset=CINEMATIC_068, x=269, y=80, zoom=0x40
	break
	video type=1, offset=CINEMATIC_068, x=272, y=77, zoom=[0x3c]	;@enc=alt
	break
	video type=1, offset=CINEMATIC_068, x=275, y=74, zoom=[0x32]	;@enc=alt
	break
	video type=1, offset=CINEMATIC_068, x=278, y=71, zoom=[0x2d]	;@enc=alt
	break
	video type=1, offset=CINEMATIC_068, x=278, y=68, zoom=[0x22]	;@enc=alt
	break
	video type=1, offset=CINEMATIC_068, x=280, y=65, zoom=[0x1f]	;@enc=alt
	break
	selectVideoPage 0x00
	play id=0x008C, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_069, x=264, y=103, zoom=0x40
	selectVideoPage 0x03
	video type=1, offset=CINEMATIC_069, x=264, y=103, zoom=0x40
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_070, x=264, y=105, zoom=0x40
	break
	video type=1, offset=CINEMATIC_071, x=264, y=105, zoom=0x40
	break
	video type=1, offset=CINEMATIC_072, x=264, y=103, zoom=0x40
	break
	video type=1, offset=CINEMATIC_073, x=264, y=103, zoom=0x40
	break
	video type=1, offset=CINEMATIC_074, x=264, y=103, zoom=0x40
	break
	video type=1, offset=CINEMATIC_075, x=264, y=103, zoom=0x40
	break
	video type=1, offset=CINEMATIC_076, x=264, y=103, zoom=0x40
	killChannel

LABEL_12A9:
	jg [0x41], 0x00, LABEL_12B3
	break
	jmp LABEL_12A9

LABEL_12B3:
	video type=1, offset=CINEMATIC_077, x=135, y=100
	video type=1, offset=CINEMATIC_078, x=160, y=100
	video type=1, offset=CINEMATIC_078, x=145, y=100
	break
	video type=1, offset=CINEMATIC_077, x=137, y=100
	video type=1, offset=CINEMATIC_078, x=160, y=100
	video type=1, offset=CINEMATIC_078, x=145, y=100
	break
	video type=1, offset=CINEMATIC_077, x=140, y=100
	video type=1, offset=CINEMATIC_078, x=160, y=100
	video type=1, offset=CINEMATIC_078, x=145, y=100
	break
	video type=1, offset=CINEMATIC_077, x=143, y=100
	video type=1, offset=CINEMATIC_078, x=160, y=100
	video type=1, offset=CINEMATIC_078, x=145, y=100
	break
	video type=1, offset=CINEMATIC_077, x=146, y=100
	video type=1, offset=CINEMATIC_078, x=160, y=100
	break
	video type=1, offset=CINEMATIC_077, x=149, y=100
	video type=1, offset=CINEMATIC_078, x=160, y=100
	break
	video type=1, offset=CINEMATIC_077, x=152, y=100
	video type=1, offset=CINEMATIC_078, x=160, y=100
	break
	video type=1, offset=CINEMATIC_077, x=155, y=100
	video type=1, offset=CINEMATIC_078, x=160, y=100
	break
	video type=1, offset=CINEMATIC_077, x=157, y=100
	video type=1, offset=CINEMATIC_078, x=160, y=100
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_077, x=160, y=100
	selectVideoPage 0xFF

LABEL_131B:
	break
	jle [0x41], 0x00, LABEL_131B
	sub [0x41], 0x0001
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_078, x=189, y=100
	video type=1, offset=CINEMATIC_078, x=176, y=100
	selectVideoPage 0xFF
	video type=1, offset=CINEMATIC_078, x=189, y=100
	video type=1, offset=CINEMATIC_078, x=176, y=100
	video type=1, offset=CINEMATIC_077, x=155, y=100
	video type=1, offset=CINEMATIC_078, x=160, y=100
	play id=0x0052, freq=0x1E, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_079, x=247, y=91
	break
	video type=1, offset=CINEMATIC_077, x=159, y=100
	video type=1, offset=CINEMATIC_078, x=160, y=100
	video type=1, offset=CINEMATIC_079, x=300, y=91, zoom=0x40
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_077, x=160, y=100
	selectVideoPage 0xFF
	break
	jmp LABEL_131B
LABEL_1366:
	db 0x11, 0x93, 0xCE, 0xEF, 0x7B, 0x18, 0x00, 0x52
	db 0x1E, 0x10, 0x01, 0x06, 0x93, 0xD8, 0xF0, 0x7B
	db 0x06, 0x06, 0x07, 0x13, 0x67, 0x11

LABEL_137C:
	mov [0x01], 0xFFCE
	mov [0x02], 0x0064
	mov [0x03], 0x0040
	mov [0x2B], 0x0023
	play id=0x008B, freq=0x22, vol=0x40, channel=0x01
	play id=0x008B, freq=0x14, vol=0x40, channel=0x00

LABEL_1398:
	mov [0xF8], [0x2B]
	and [0xF8], 0x000D
	add [0x01], [0xF8]
	sub [0x2B], 0x0001
	jg [0x2B], 0x20, LABEL_1398

LABEL_13AC:
	break
	play id=0x008B, freq=0x22, vol=0x40, channel=0x01
	play id=0x008C, freq=0x0A, vol=0x40, channel=0x00
	call DRAW_CIN_093_TO_097_VAR
	mov [0xF8], [0x2B]
	and [0xF8], 0x000D
	add [0x01], [0xF8]
	djnz [0x2B], LABEL_13AC
	play id=0x008B, freq=0x22, vol=0x00, channel=0x01
	play id=0x0084, freq=0x14, vol=0x20, channel=0x02
	play id=0x0084, freq=0x0F, vol=0x10, channel=0x03
	setup channel=0x39, address=HANG_DRAW_CIN_123
	setup channel=0x01, address=LABEL_083D
	setup channel=0x3B, address=WAIT_LOOP_VAR_5C
	selectVideoPage 0x03
	call DRAW_CIN_093_TO_097_VAR
	selectVideoPage 0x00
	call DRAW_CIN_113_114_AND_RET
	call DRAW_CIN_093_TO_097_VAR
	call DRAW_CIN_113_114_AND_RET
	selectVideoPage 0xFF
	jmp HANG_DRAW_CIN_115
LABEL_13FD:
	db 0x00, 0x3E, 0x00, 0x14, 0x00, 0x41, 0x00, 0x0A
	db 0x00, 0x37, 0x00, 0x14, 0x00, 0x46, 0x00, 0x01
	db 0x00, 0x47, 0x00, 0x01, 0x00, 0x4F, 0x00, 0x64
	db 0x00, 0x56, 0x00, 0x01, 0x00, 0x57, 0x00, 0x01
	db 0x11

LABEL_141E:
	setup channel=0x14, address=LABEL_14A1
	setup channel=0x15, address=LABEL_166F
	setup channel=0x16, address=LABEL_14B8
	setup channel=0x17, address=ALTERNATE_VAR06_VAR04_TIMING
	setup channel=0x18, address=LABEL_14E4
	setup channel=0x19, address=LABEL_15D4
	setup channel=0x1A, address=LABEL_1510
	mov [0x14], 0x0028
	mov [0x15], 0x0071
	mov [0x16], 0x0040
	mov [0x17], 0x0001
	mov [0x18], 0x0039
	mov [0x19], 0x0001
	mov [0x1A], 0x0104
	mov [0x1B], 0x006C
	mov [0x1C], 0x0055
	mov [0x1D], 0x0001
	mov [0x1E], 0x0118
	mov [0x1F], 0x0001
	mov [0x20], 0x00DC
	mov [0x21], 0x0071
	mov [0x22], 0x0040
	mov [0x23], 0x0001
	mov [0x24], 0x00ED
	mov [0x25], 0x0001
	mov [0x68], 0x0032

DELAY_LOOP_VAR68__AMIGA__POST_INIT_VARS_50_NEG40_51_32:
	break
	djnz [0x68], DELAY_LOOP_VAR68__AMIGA__POST_INIT_VARS_50_NEG40_51_32
	setup channel=0x37, address=LABEL_0E21
	killChannel

PROJECT_AND_DRAW_TWICE_Y_PLUS_9__AMIGA__POST_INIT_VARS_50_NEG40_51_32:
	call LABEL_152A
	mov [0x07], [0x05]
	mov [0x06], [0x04]
	add [0x06], 0x0009
	call LABEL_152A
	ret

LABEL_14A1:
	mov [0x07], [0x14]
	mov [0x08], [0x15]
	mov [0x09], [0x16]
	mov [0x06], [0x17]
	mov [0x05], [0x18]
	mov [0x04], [0x19]
	break
	jmp LABEL_14A1
LABEL_14B7:
	db 0x11

LABEL_14B8:
	mov [0x14], [0x07]
	mov [0x15], [0x08]
	mov [0x16], [0x09]
	mov [0x17], [0x06]
	mov [0x18], [0x05]
	mov [0x19], [0x04]
	call PROJECT_AND_DRAW_TWICE_Y_PLUS_9__AMIGA__POST_INIT_VARS_50_NEG40_51_32
	mov [0x07], [0x1A]
	mov [0x08], [0x1B]
	mov [0x09], [0x1C]
	mov [0x06], [0x1D]
	mov [0x05], [0x1E]
	mov [0x04], [0x1F]
	break
	jmp LABEL_14B8
LABEL_14E3:
	db 0x11

LABEL_14E4:
	mov [0x1A], [0x07]
	mov [0x1B], [0x08]
	mov [0x1C], [0x09]
	mov [0x1D], [0x06]
	mov [0x1E], [0x05]
	mov [0x1F], [0x04]
	call PROJECT_AND_DRAW_TWICE_Y_PLUS_9__AMIGA__POST_INIT_VARS_50_NEG40_51_32
	mov [0x07], [0x20]
	mov [0x08], [0x21]
	mov [0x09], [0x22]
	mov [0x06], [0x23]
	mov [0x05], [0x24]
	mov [0x04], [0x25]
	break
	jmp LABEL_14E4
LABEL_150F:
	db 0x11

LABEL_1510:
	mov [0x20], [0x07]
	mov [0x21], [0x08]
	mov [0x22], [0x09]
	mov [0x23], [0x06]
	mov [0x24], [0x05]
	mov [0x25], [0x04]
	call PROJECT_AND_DRAW_TWICE_Y_PLUS_9__AMIGA__POST_INIT_VARS_50_NEG40_51_32
	break
	jmp LABEL_1510
LABEL_1529:
	db 0x11

LABEL_152A:
	jne [0x06], 0x01, LABEL_1537
	video type=1, offset=CINEMATIC_168, x=[0x07], y=[0x08], zoom=[0x09]
	ret

LABEL_1537:
	jne [0x06], 0x02, LABEL_1544
	video type=1, offset=CINEMATIC_167, x=[0x07], y=[0x08], zoom=[0x09]
	ret

LABEL_1544:
	jne [0x06], 0x03, LABEL_1551
	video type=1, offset=CINEMATIC_166, x=[0x07], y=[0x08], zoom=[0x09]
	ret

LABEL_1551:
	jne [0x06], 0x04, LABEL_155E
	video type=1, offset=CINEMATIC_165, x=[0x07], y=[0x08], zoom=[0x09]
	ret

LABEL_155E:
	jne [0x06], 0x05, LABEL_156B
	video type=1, offset=CINEMATIC_164, x=[0x07], y=[0x08], zoom=[0x09]
	ret

LABEL_156B:
	jne [0x06], 0x06, LABEL_1578
	video type=1, offset=CINEMATIC_163, x=[0x07], y=[0x08], zoom=[0x09]
	ret

LABEL_1578:
	jne [0x06], 0x07, LABEL_1585
	video type=1, offset=CINEMATIC_162, x=[0x07], y=[0x08], zoom=[0x09]
	ret

LABEL_1585:
	jne [0x06], 0x08, LABEL_1592
	video type=1, offset=CINEMATIC_161, x=[0x07], y=[0x08], zoom=[0x09]
	ret

LABEL_1592:
	jne [0x06], 0x09, LABEL_159F
	video type=1, offset=CINEMATIC_160, x=[0x07], y=[0x08], zoom=[0x09]
	ret

LABEL_159F:
	jne [0x06], 0x0A, LABEL_15AC
	video type=1, offset=CINEMATIC_159, x=[0x07], y=[0x08], zoom=[0x09]
	ret

LABEL_15AC:
	jne [0x06], 0x0B, LABEL_15B9
	video type=1, offset=CINEMATIC_158, x=[0x07], y=[0x08], zoom=[0x09]
	ret

LABEL_15B9:
	jne [0x06], 0x0C, LABEL_15C6
	video type=1, offset=CINEMATIC_157, x=[0x07], y=[0x08], zoom=[0x09]
	ret

LABEL_15C6:
	jne [0x06], 0x0D, SHARED_RET
	video type=1, offset=CINEMATIC_156, x=[0x07], y=[0x08], zoom=[0x09]
	ret
