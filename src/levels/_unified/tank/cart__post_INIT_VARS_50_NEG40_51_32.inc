LABEL_150A:
	break
	call LABEL_151A
	add [0x50], 0x000A
	djnz [0x51], LABEL_150A
	jmp INIT_VARS_50_NEG40_51_32
LABEL_1519:
	db 0x11

LABEL_151A:
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
	video type=1, offset=CINEMATIC_201, x=[0x4b], y=[0x4c], zoom=[0x4d]
	break
	video type=1, offset=CINEMATIC_202, x=[0x4b], y=[0x4c], zoom=[0x4d]
	break
	video type=1, offset=CINEMATIC_203, x=[0x4b], y=[0x4c], zoom=[0x4d]
	selectVideoPage 0x03
	video type=1, offset=CINEMATIC_204, x=[0x4b], y=[0x4c], zoom=[0x4d]
	selectVideoPage 0xFF
	mov [0x4E], 0x0000
	jmp WAIT_VAR4E_PLAY_8C_DRAW_CIN_201
LABEL_158A:
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
	video type=1, offset=CINEMATIC_205, x=[0x3c], y=[0x3d], zoom=0x40
	selectVideoPage 0x03
	call SUM_HASH_VARS_TO_VAR_64
	mov [0xF8], [0x64]
	and [0xF8], 0x0003
	jne [0xF8], 0x00, LABEL_15CD
	video type=1, offset=CINEMATIC_208, x=[0x3c], y=[0x3d], zoom=0x40

LABEL_15CD:
	jne [0xF8], 0x01, LABEL_15D8
	video type=1, offset=CINEMATIC_207, x=[0x3c], y=[0x3d], zoom=0x40

LABEL_15D8:
	jl [0xF8], 0x02, LABEL_15E3
	video type=1, offset=CINEMATIC_206, x=[0x3c], y=[0x3d], zoom=0x40

LABEL_15E3:
	selectVideoPage 0xFF
	jmp WAIT_VAR3E_DEC_AND_RANDOMIZE
LABEL_15E8:
	db 0x11

HANG_DRAW_CIN_089:
	video type=1, offset=CINEMATIC_089, x=[0x0f], y=[0x10], zoom=0x40
	break
	jmp HANG_DRAW_CIN_089

HANG_DRAW_CIN_090:
	video type=1, offset=CINEMATIC_090, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp HANG_DRAW_CIN_090

WAIT_VAR46_PLAY_8E_DRAW_CIN_056:
	break
	je [0x46], 0x00, WAIT_VAR46_PLAY_8E_DRAW_CIN_056
	play id=0x008E, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_056, x=160, y=100
	break
	video type=1, offset=CINEMATIC_056, x=160, y=100
	break
	video type=1, offset=CINEMATIC_057, x=160, y=100
	break
	video type=1, offset=CINEMATIC_058, x=160, y=100
	break
	video type=1, offset=CINEMATIC_059, x=160, y=100
	break
	break
	break
	killChannel

WAIT_VAR56_PLAY_8E_DRAW_CIN_020:
	break
	je [0x56], 0x00, WAIT_VAR56_PLAY_8E_DRAW_CIN_020
	play id=0x008E, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_020, x=195, y=79
	break
	video type=1, offset=CINEMATIC_020, x=202, y=75
	break
	video type=1, offset=CINEMATIC_021, x=212, y=66
	break
	video type=1, offset=CINEMATIC_020, x=220, y=58
	break
	video type=1, offset=CINEMATIC_019, x=235, y=55
	break
	video type=1, offset=CINEMATIC_001, x=247, y=61
	break
	video type=1, offset=CINEMATIC_002, x=258, y=73, zoom=0x40
	break
	video type=1, offset=CINEMATIC_022, x=269, y=80, zoom=0x40
	break
	video type=1, offset=CINEMATIC_022, x=272, y=77, zoom=[0x3c]	;@enc=alt
	break
	video type=1, offset=CINEMATIC_022, x=275, y=74, zoom=[0x32]	;@enc=alt
	break
	video type=1, offset=CINEMATIC_022, x=278, y=71, zoom=[0x2d]	;@enc=alt
	break
	video type=1, offset=CINEMATIC_022, x=278, y=68, zoom=[0x22]	;@enc=alt
	break
	video type=1, offset=CINEMATIC_022, x=280, y=65, zoom=[0x1f]	;@enc=alt
	break
	selectVideoPage 0x00
	play id=0x008C, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_045, x=264, y=103, zoom=0x40
	selectVideoPage 0x03
	video type=1, offset=CINEMATIC_045, x=264, y=103, zoom=0x40
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_046, x=264, y=105, zoom=0x40
	break
	video type=1, offset=CINEMATIC_047, x=264, y=105, zoom=0x40
	break
	video type=1, offset=CINEMATIC_048, x=264, y=103, zoom=0x40
	break
	video type=1, offset=CINEMATIC_049, x=264, y=103, zoom=0x40
	break
	video type=1, offset=CINEMATIC_050, x=264, y=103, zoom=0x40
	break
	video type=1, offset=CINEMATIC_051, x=264, y=103, zoom=0x40
	break
	video type=1, offset=CINEMATIC_052, x=264, y=103, zoom=0x40
	killChannel

LABEL_16BF:
	jg [0x41], 0x00, LABEL_16C9
	break
	jmp LABEL_16BF

LABEL_16C9:
	video type=1, offset=CINEMATIC_053, x=135, y=100
	video type=1, offset=CINEMATIC_054, x=160, y=100
	video type=1, offset=CINEMATIC_054, x=145, y=100
	break
	video type=1, offset=CINEMATIC_053, x=137, y=100
	video type=1, offset=CINEMATIC_054, x=160, y=100
	video type=1, offset=CINEMATIC_054, x=145, y=100
	break
	video type=1, offset=CINEMATIC_053, x=140, y=100
	video type=1, offset=CINEMATIC_054, x=160, y=100
	video type=1, offset=CINEMATIC_054, x=145, y=100
	break
	video type=1, offset=CINEMATIC_053, x=143, y=100
	video type=1, offset=CINEMATIC_054, x=160, y=100
	video type=1, offset=CINEMATIC_054, x=145, y=100
	break
	video type=1, offset=CINEMATIC_053, x=146, y=100
	video type=1, offset=CINEMATIC_054, x=160, y=100
	break
	video type=1, offset=CINEMATIC_053, x=149, y=100
	video type=1, offset=CINEMATIC_054, x=160, y=100
	break
	video type=1, offset=CINEMATIC_053, x=152, y=100
	video type=1, offset=CINEMATIC_054, x=160, y=100
	break
	video type=1, offset=CINEMATIC_053, x=155, y=100
	video type=1, offset=CINEMATIC_054, x=160, y=100
	break
	video type=1, offset=CINEMATIC_053, x=157, y=100
	video type=1, offset=CINEMATIC_054, x=160, y=100
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_053, x=160, y=100
	selectVideoPage 0xFF

LABEL_1731:
	break
	jle [0x41], 0x00, LABEL_1731
	sub [0x41], 0x0001
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_054, x=189, y=100
	video type=1, offset=CINEMATIC_054, x=176, y=100
	selectVideoPage 0xFF
	video type=1, offset=CINEMATIC_054, x=189, y=100
	video type=1, offset=CINEMATIC_054, x=176, y=100
	video type=1, offset=CINEMATIC_053, x=155, y=100
	video type=1, offset=CINEMATIC_054, x=160, y=100
	play id=0x0052, freq=0x1E, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_055, x=247, y=91
	break
	video type=1, offset=CINEMATIC_053, x=159, y=100
	video type=1, offset=CINEMATIC_054, x=160, y=100
	video type=1, offset=CINEMATIC_055, x=300, y=91, zoom=0x40
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_053, x=160, y=100
	selectVideoPage 0xFF
	break
	jmp LABEL_1731
	killChannel

LABEL_177D:
	video type=1, offset=CINEMATIC_261, x=239, y=123
	play id=0x0052, freq=0x1E, vol=0x10, channel=0x01
	break
	video type=1, offset=CINEMATIC_055, x=240, y=123
	break
	break
	jmp LABEL_177D
LABEL_1791:
	db 0x11
