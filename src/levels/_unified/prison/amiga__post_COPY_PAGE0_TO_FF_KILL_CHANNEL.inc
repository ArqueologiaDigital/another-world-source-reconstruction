LABEL_7F92:
	jne [0x0A], 0x00, LABEL_80A5
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_7FAA
	video offset=CINEMATIC_186, x=258, y=181

LABEL_7FAA:
	jl [HERO_X], 0xF0, LABEL_80A5
	jg [HERO_X], 0x0104, LABEL_80A5
	jge [0x04], 0x20, LABEL_80A5
	break
	break
	mov [0x0A], 0x0001
	selectVideoPage 0x00
	video offset=CINEMATIC_172, x=253, y=181
	selectVideoPage 0xFF
	unfreezeChannels first=0x00, last=0x3A
	copyVideoPage src=0x00, dst=0x03
	fill page=0x00, color=0x05
	selectVideoPage 0x00
	video offset=CINEMATIC_173, x=160, y=100
	video offset=CINEMATIC_174, x=160, y=100
	video offset=CINEMATIC_175, x=160, y=100
	selectVideoPage 0xFF
	mov [PAUSE_SLICES], 0x0001
	break
	setPalette 0x15
	break
	setPalette 0x14
	break
	setPalette 0x13
	break
	setPalette 0x12
	break
	setPalette 0x06
	video offset=CINEMATIC_176, x=160, y=100
	break
	fill page=0x00, color=0x05
	selectVideoPage 0x00
	video offset=CINEMATIC_173, x=160, y=100
	video offset=CINEMATIC_174, x=160, y=100
	selectVideoPage 0xFF
	video offset=CINEMATIC_176, x=160, y=100
	break
	mov [PAUSE_SLICES], 0x0004
	mov [0xC8], 0x0005

LABEL_801E:
	video offset=CINEMATIC_175, x=160, y=100
	video offset=CINEMATIC_177, x=160, y=100
	break
	djnz [0xC8], LABEL_801E
	mov [0xC8], 0x0005

LABEL_802F:
	video offset=CINEMATIC_175, x=160, y=100
	video offset=CINEMATIC_176, x=160, y=100
	break
	djnz [0xC8], LABEL_802F
	mov [0xC8], 0x0005

LABEL_8040:
	video offset=CINEMATIC_175, x=160, y=100
	video offset=CINEMATIC_177, x=160, y=100
	break
	djnz [0xC8], LABEL_8040
	video offset=CINEMATIC_178, x=160, y=100
	video offset=CINEMATIC_177, x=160, y=100
	break
	play id=0x0055, freq=0x14, vol=0x40, channel=0x00
	video offset=CINEMATIC_179, x=160, y=100
	video offset=CINEMATIC_176, x=160, y=100
	break
	video offset=CINEMATIC_180, x=160, y=100
	video offset=CINEMATIC_176, x=160, y=100
	break
	video offset=CINEMATIC_181, x=160, y=100
	video offset=CINEMATIC_176, x=160, y=100
	break
	video offset=CINEMATIC_182, x=160, y=100
	break
	setPalette 0x08
	video offset=CINEMATIC_183, x=160, y=100
	break
	video offset=CINEMATIC_184, x=160, y=100
	break
	video offset=CINEMATIC_185, x=160, y=100
	mov [0xC8], 0x000A

DELAY_LOOP_VARC8:
	break
	djnz [0xC8], DELAY_LOOP_VARC8
	freezeChannels first=0x00, last=0x3A
	copyVideoPage src=0x03, dst=0x00
	add [0x68], 0x0014
	break
	setPalette 0x02

LABEL_80A5:
	break
	jmp LABEL_7F92
LABEL_80A9:
	db 0x11

LABEL_80AA:
	je [0x65], 0x05, SHARED_RET
	fill page=0x03, color=0x00
	fill page=0x00, color=0x00
	selectVideoPage 0x03
	call DRAW_CIN_SEQ_085_085_086
	selectVideoPage 0xFF
	mov [SCROLL_Y], 0x0000
	copyVideoPage src=0x83, dst=0x00
	add [SCROLL_Y], 0x0020
	copyVideoPage src=0x83, dst=0x00
	copyVideoPage src=0x80, dst=0x03
	add [SCROLL_Y], 0x0020
	copyVideoPage src=0x83, dst=0x00
	add [SCROLL_Y], 0x0020
	copyVideoPage src=0x80, dst=0x03
	mov [0x65], 0x0005
	selectVideoPage 0x03
	video offset=CINEMATIC_087, x=160, y=100
	video offset=CINEMATIC_088, x=160, y=100
	video offset=CINEMATIC_089, x=160, y=100
	video offset=CINEMATIC_089, x=0, y=100
	selectVideoPage 0xFF
	ret

LABEL_80F5:
	setup channel=0x3B, address=LABEL_7F92
	mov [0x42], 0x00BC
	mov [0x43], 0x0FA0
	mov [0x46], 0x0064
	mov [0x47], 0x00C8
	mov [0x40], [0x21]
	mov [0x41], 0x006E
	mov [0x44], [0x22]
	mov [0x45], 0x0014
	mov [0x50], 0x05DC
	mov [0x51], [0x44]
	mov [0x52], [0x40]
	setup channel=0x29, address=LABEL_2B14
	je [0x66], 0x01, VAR66_RANGE_DISPATCH_BY_VAR01
	call LABEL_1CC9
	setup channel=0x34, address=HANG_DRAW_CIN_275
	je [0x65], 0x01, COPY_PAGE3_TO_PAGE0
	selectVideoPage 0x00
	call FILL_AND_DRAW_CIN_24_28
	selectVideoPage 0xFF
	mov [0x65], 0x0001
	jmp LABEL_8149
