LABEL_8193:
	jne [0x0A], 0x00, LABEL_82CC
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_81B6
	video offset=CINEMATIC_186, x=258, y=181
	jl [HERO_X], 0xFA, LABEL_81B6
	video offset=CINEMATIC_186, x=257, y=181

LABEL_81B6:
	jl [HERO_X], 0xF0, LABEL_82CC
	jg [HERO_X], 0x0104, LABEL_82CC
	jge [0x04], 0x20, LABEL_82CC
	break
	jge [0x04], 0x4000, KILL_CHANNEL_LANDING
	setup channel=0x3C, address=BLIT_PAGE_00_TO_FF_AND_BREAK
	break
	jge [0x04], 0x4000, KILL_CHANNEL_LANDING
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
	setup channel=0x3C, address=BLIT_PAGE_00_TO_FF_AND_BREAK
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

LABEL_8240:
	video offset=CINEMATIC_175, x=160, y=100
	video offset=CINEMATIC_177, x=160, y=100
	break
	djnz [0xC8], LABEL_8240
	mov [0xC8], 0x0005

LABEL_8251:
	video offset=CINEMATIC_175, x=160, y=100
	video offset=CINEMATIC_176, x=160, y=100
	break
	djnz [0xC8], LABEL_8251
	mov [0xC8], 0x0005

LABEL_8262:
	video offset=CINEMATIC_175, x=160, y=100
	video offset=CINEMATIC_177, x=160, y=100
	break
	djnz [0xC8], LABEL_8262
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
	mov [0xC8], 0x0009

DELAY_LOOP_VARC8:
	break
	djnz [0xC8], DELAY_LOOP_VARC8
	setup channel=0x3C, address=BLIT_PAGE_00_TO_FF_AND_BREAK
	break
	freezeChannels first=0x00, last=0x3A
	copyVideoPage src=0x03, dst=0x00
	add [0x68], 0x0014
	break
	setPalette 0x02

LABEL_82CC:
	break
	jmp LABEL_8193
LABEL_82D0:
	db 0x11

LABEL_82D1:
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

LABEL_831C:
	setup channel=0x3B, address=LABEL_8193
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
	setup channel=0x29, address=LABEL_2BF4
	je [0x66], 0x01, VAR66_RANGE_DISPATCH_BY_VAR01
	call LABEL_1D63
	setup channel=0x34, address=HANG_DRAW_CIN_275
	je [0x65], 0x01, COPY_PAGE3_TO_PAGE0
	selectVideoPage 0x00
	call FILL_AND_DRAW_CIN_24_28
	selectVideoPage 0xFF
	mov [0x65], 0x0001
	jmp LABEL_8370
