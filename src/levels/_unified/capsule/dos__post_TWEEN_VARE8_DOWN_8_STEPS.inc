LABEL_1BD4:
	add [0xE8], 0x0004
	break
	jmp LABEL_1BD4
	break
	sub [0xE8], 0x0001
	break
	break
	add [0xE8], 0x0002
	break
	add [0xE8], 0x0001

LABEL_1BEC:
	break
	add [0xE8], 0x0004
	jmp LABEL_1BEC
LABEL_1BF4:
	db 0x11

PLAY_3SFX_PAL_3_PAUSE_4:
	copyVideoPage src=0x03, dst=0x00
	play id=0x0057, freq=0x05, vol=0x40, channel=0x01
	play id=0x0066, freq=0x07, vol=0x40, channel=0x02
	play id=0x0066, freq=0x0A, vol=0x40, channel=0x03
	mov [PAUSE_SLICES], 0x0004
	setPalette 0x03
	fill page=0xFF, color=0x0E
	break
	mov [0xE6], 0x0083
	mov [0xE7], 0x0078
	mov [0xE8], 0x00FA
	video offset=CINEMATIC_045, x=[0xe6], y=[0xe7], zoom=[0x91]	;@enc=alt
	break
	video offset=CINEMATIC_045, x=[0xe6], y=[0xe7], zoom=[0x54]	;@enc=alt
	break
	video offset=CINEMATIC_046, x=[0xe6], y=[0xe7], zoom=[0xfa]	;@enc=alt
	break
	video offset=CINEMATIC_046, x=[0xe6], y=[0xe7], zoom=[0xc8]	;@enc=alt
	break
	mov [0xE8], 0x00C8
	mov [0xE9], 0x0003

LABEL_1C45:
	sub [0xE8], 0x0016
	video offset=CINEMATIC_046, x=[0xe6], y=[0xe7], zoom=[0xe8]
	break
	djnz [0xE9], LABEL_1C45
	mov [0xE9], 0x0002

LABEL_1C58:
	sub [0xE8], 0x0014
	video offset=CINEMATIC_046, x=[0xe6], y=[0xe7], zoom=[0xe8]
	break
	djnz [0xE9], LABEL_1C58
	mov [0xE9], 0x0005

LABEL_1C6B:
	sub [0xE8], 0x000A
	video offset=CINEMATIC_046, x=[0xe6], y=[0xe7], zoom=[0xe8]
	break
	djnz [0xE9], LABEL_1C6B
	mov [0xE9], 0x0007

LABEL_1C7E:
	sub [0xE8], 0x0005
	video offset=CINEMATIC_046, x=[0xe6], y=[0xe7], zoom=[0xe8]
	break
	djnz [0xE9], LABEL_1C7E
	mov [0xE9], 0x0003

LABEL_1C91:
	sub [0xE8], 0x0003
	video offset=CINEMATIC_046, x=[0xe6], y=[0xe7], zoom=[0xe8]
	break
	djnz [0xE9], LABEL_1C91

LABEL_1CA0:
	sub [0xE8], 0x0001
	jle [0xE8], 0x00, LABEL_1CB4
	video offset=CINEMATIC_046, x=[0xe6], y=[0xe7], zoom=[0xe8]
	break
	jmp LABEL_1CA0

LABEL_1CB4:
	setup channel=0x3F, address=BREAK_5X_THEN_INIT_VAR03_14
	fill page=0x00, color=0x00
	killChannel

LABEL_1CBC:
	video offset=CINEMATIC_093, x=242, y=103
	break
	video offset=CINEMATIC_093, x=216, y=98
	break
	video offset=CINEMATIC_093, x=183, y=100
	break
	video offset=CINEMATIC_093, x=160, y=100

LABEL_1CCF:
	break
	video offset=CINEMATIC_093, x=165, y=102
	jmp LABEL_1CCF
LABEL_1CD7:
	db 0x11
