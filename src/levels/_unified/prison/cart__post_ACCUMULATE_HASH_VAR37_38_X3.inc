COPY_HASH_AND_SPLIT_VAR38_3F_3E:
	call COPY_HASH_VAR_37_TO_RANGE
	call ACCUMULATE_HASH_INTO_VAR37_38
	and [0x38], 0x00FF
	mov [0x3F], [0x38]
	and [0x38], 0x007F
	mov [0x3E], [0x38]
	and [0x38], 0x003F
	mov [0x3D], [0x38]
	and [0x38], 0x001F
	mov [RANDOM_SEED], [0x38]
	and [0x38], 0x000F
	mov [0x3B], [0x38]
	and [0x38], 0x0007
	mov [0x3A], [0x38]
	and [0x38], 0x0003
	mov [0x39], [0x38]
	and [0x38], 0x0001
	ret

LABEL_0860:
	mov [HACK_VAR_67], 0x0001
	mov [0x66], 0x0001
	mov [0x65], 0x0001
	mov [0x68], 0x00C8
	mov [0x69], 0x00B6
	mov [0x6A], 0x0001
	mov [0x6B], 0x3000
	mov [0x6C], 0x0000
	mov [0x6D], 0x0000
	mov [0x30], 0x0064
	mov [0xB0], 0x0001
	mov [0xB1], 0x0000
	mov [0xB2], 0x0000
	mov [0xB3], 0x03DB
	mov [0xB4], 0x0000
	mov [0xB9], 0x0000
	mov [0x70], 0x0118
	mov [0x71], 0x00B6
	mov [0x72], 0x0003
	mov [0x73], 0x2000
	mov [0x74], 0x2008
	mov [0x75], 0x0811
	mov [0x78], 0x0122
	mov [0x79], 0x00B6
	mov [0x7A], 0x000A
	mov [0x7B], 0x2000
	mov [0x7C], 0x2000
	mov [0x7D], 0x0800
	ret
	call LABEL_0860
	setup channel=0x3C, address=LABEL_06ED
	mov [PAUSE_SLICES], 0x0004
	mov [0x65], 0x0000
	mov [0x66], 0x0000
	setup channel=0x3F, address=LABEL_08E9
	killChannel

LABEL_08E9:
	deleteChannels first=0x00, last=0x02
	deleteChannels first=0x04, last=0x3B
	deleteChannels first=0x3D, last=0x3E
	setup channel=0x01, address=SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01
	jmp LABEL_8A17
LABEL_08FC:
	db 0x11

LABEL_08FD:
	mov [0xE8], 0xFF9C
	mov [0xE9], 0x0064
	setup channel=0x39, address=LABEL_091E

LABEL_0909:
	break
	add [0xE8], 0x000C
	video offset=CINEMATIC_310, x=[0xe8], y=[0xe9], zoom=0x40
	jl [0xE8], 0x0190, LABEL_0909
	jmp LABEL_093A
LABEL_091D:
	db 0x11

LABEL_091E:
	break
	break
	play id=0x0063, freq=0x1E, vol=0x0A, channel=0x02
	break
	break
	break
	break
	play id=0x0063, freq=0x1E, vol=0x08, channel=0x02
	break
	break
	break
	break
	break
	break
	jmp LABEL_091E
LABEL_0939:
	db 0x11

LABEL_093A:
	mov [0xE6], 0x0190
	mov [0xE7], 0x0078
	setup channel=0x39, address=LABEL_0957

LABEL_0946:
	break
	sub [0xE6], 0x0008
	jl [0xE6], 0x0190, LABEL_0946
	setup channel=0x39, address=KILL_CHANNEL_LANDING
	killChannel

LABEL_0957:
	add [0xE7], 0x0003
	call LABEL_0A20
	break
	add [0xE7], 0x0001
	call LABEL_0A33
	break
	add [0xE7], 0x0001
	call LABEL_0A46
	break
	sub [0xE7], 0x0001
	add [0xE6], 0x0002
	call LABEL_0A46
	break
	sub [0xE7], 0x0002
	add [0xE6], 0x0003
	call LABEL_0A46
	break
	sub [0xE7], 0x0002
	add [0xE6], 0x0002
	play id=0x0055, freq=0x14, vol=0x10, channel=0x02
	call LABEL_0A59
	break
	call LABEL_0A46
	break
	call LABEL_0A33
	break
	add [0xE7], 0x0003
	call LABEL_0A20
	break
	add [0xE7], 0x0001
	call LABEL_0A0D
	break
	add [0xE7], 0x0001
	call LABEL_09FA
	break
	sub [0xE7], 0x0001
	add [0xE6], 0x0002
	call DRAW_CIN_311_THEN_CIN_314
	break
	sub [0xE7], 0x0002
	add [0xE6], 0x0003
	play id=0x0055, freq=0x14, vol=0x10, channel=0x01
	call DRAW_CIN_311_THEN_CIN_314
	break
	sub [0xE7], 0x0002
	add [0xE6], 0x0002
	call DRAW_CIN_311_THEN_CIN_314
	break
	call LABEL_09FA
	break
	call LABEL_0A0D
	break
	jmp LABEL_0957
LABEL_09EE:
	db 0x11

DRAW_CIN_311_THEN_CIN_314:
	video offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40
	video offset=CINEMATIC_314, x=[0xe6], y=[0xe7], zoom=0x40
	ret

LABEL_09FA:
	video offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40
	add [0xE6], 0x0001
	video offset=CINEMATIC_313, x=[0xe6], y=[0xe7], zoom=0x40
	sub [0xE6], 0x0001
	ret

LABEL_0A0D:
	video offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40
	add [0xE6], 0x0002
	video offset=CINEMATIC_312, x=[0xe6], y=[0xe7], zoom=0x40
	sub [0xE6], 0x0002
	ret

LABEL_0A20:
	video offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40
	add [0xE6], 0x0003
	video offset=CINEMATIC_312, x=[0xe6], y=[0xe7], zoom=0x40
	sub [0xE6], 0x0003
	ret

LABEL_0A33:
	video offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40
	add [0xE6], 0x0004
	video offset=CINEMATIC_312, x=[0xe6], y=[0xe7], zoom=0x40
	sub [0xE6], 0x0004
	ret

LABEL_0A46:
	video offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40
	add [0xE6], 0x0006
	video offset=CINEMATIC_312, x=[0xe6], y=[0xe7], zoom=0x40
	sub [0xE6], 0x0006
	ret

LABEL_0A59:
	video offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40
	add [0xE6], 0x0008
	video offset=CINEMATIC_312, x=[0xe6], y=[0xe7], zoom=0x40
	sub [0xE6], 0x0008
	ret

LABEL_0A6C:
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [RANDOM_SEED], 0x00, LABEL_0B03
	jmp LABEL_0A6C

LABEL_0A79:
	mov [0xF8], 0x0000
	call DRAW_CIN_315_PROGRESSIVE
	mov [0xF8], 0x0000
	call LABEL_0AED
	break
	break
	mov [0xF8], 0x0001
	call DRAW_CIN_315_PROGRESSIVE
	mov [0xF8], 0x0001
	call LABEL_0AED
	break
	break
	mov [0xF8], 0x0002
	call DRAW_CIN_315_PROGRESSIVE
	mov [0xF8], 0x0002
	call LABEL_0AED
	break
	break
	mov [0xF8], 0x0001
	call DRAW_CIN_315_PROGRESSIVE
	mov [0xF8], 0x0001
	call LABEL_0AED
	break
	break
	jmp LABEL_0A79
LABEL_0ABC:
	db 0x11

DRAW_CIN_315_PROGRESSIVE:
	add [0xF8], 0x004B
	selectVideoPage 0x00
	video offset=CINEMATIC_315, x=[0xf8], y=187, zoom=0x40
	add [0xF8], 0x0055
	video offset=CINEMATIC_315, x=[0xf8], y=186, zoom=0x40
	add [0xF8], 0x002C
	video offset=CINEMATIC_315, x=[0xf8], y=186, zoom=0x40
	add [0xF8], 0x0003
	video offset=CINEMATIC_315, x=[0xf8], y=187, zoom=0x40
	add [0xF8], 0x0004
	video offset=CINEMATIC_315, x=[0xf8], y=93, zoom=0x40
	ret

LABEL_0AED:
	add [0xF8], 0x0038
	video offset=CINEMATIC_316, x=[0xf8], y=186, zoom=0x40
	add [0xF8], 0x0029
	video offset=CINEMATIC_316, x=[0xf8], y=186, zoom=0x40
	selectVideoPage 0xFF
	ret
LABEL_0B02:
	db 0x11

LABEL_0B03:
	video offset=CINEMATIC_317, x=160, y=100
	play id=0x0058, freq=0x14, vol=0x20, channel=0x02
	setPalette 0x05
	break
	setPalette 0x02
	jmp LABEL_0A6C

LABEL_0B17:
	video offset=CINEMATIC_319, x=53, y=141
	video offset=CINEMATIC_319, x=153, y=141
	video offset=CINEMATIC_319, x=208, y=141
	video offset=CINEMATIC_319, x=302, y=141, zoom=0x40

LABEL_0B28:
	break
	mov [0xF8], [0x31]
	and [0xF8], 0x0007
	jne [0xF8], 0x00, LABEL_0B28
	jmp LABEL_0B17
LABEL_0B39:
	db 0x11

LABEL_0B3A:
	selectVideoPage 0x00
	video offset=CINEMATIC_318, x=225, y=50
	video offset=CINEMATIC_318, x=278, y=50, zoom=0x40
	selectVideoPage 0xFF

LABEL_0B47:
	break
	mov [0xF8], [0x31]
	and [0xF8], 0x0007
	jne [0xF8], 0x00, LABEL_0B47
	selectVideoPage 0x00
	video offset=CINEMATIC_319, x=225, y=50
	video offset=CINEMATIC_319, x=278, y=50, zoom=0x40
	selectVideoPage 0xFF

LABEL_0B62:
	break
	mov [0xF8], [0x31]
	and [0xF8], 0x0003
	jne [0xF8], 0x00, LABEL_0B62
	jmp LABEL_0B3A
	killChannel

LABEL_0B74:
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_186, x=101, y=158
	video offset=CINEMATIC_457, x=105, y=154
	selectVideoPage 0xFF
	break
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_186, x=103, y=156
	video offset=CINEMATIC_457, x=101, y=158
	selectVideoPage 0xFF
	break
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_186, x=105, y=154
	video offset=CINEMATIC_457, x=103, y=156
	selectVideoPage 0xFF
	break
	jmp LABEL_0B74
	killChannel

LABEL_0BA2:
	selectVideoPage 0x00
	video offset=CINEMATIC_457, x=109, y=167
	video offset=CINEMATIC_703, x=108, y=167
	selectVideoPage 0xFF
	break
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_186, x=110, y=166
	video offset=CINEMATIC_703, x=109, y=167
	selectVideoPage 0xFF
	break
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_186, x=108, y=167
	video offset=CINEMATIC_703, x=110, y=166
	selectVideoPage 0xFF
	break
	break
	jmp LABEL_0BA2
LABEL_0BCF:
	db 0x11
