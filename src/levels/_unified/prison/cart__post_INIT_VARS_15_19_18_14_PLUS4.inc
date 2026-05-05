LABEL_7A01:
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_7A36
	je [0x19], 0x01, LABEL_7A36
	jne [0x18], 0x00, LABEL_7A36
	add [0x15], 0x0003
	je [0xE2], 0x00, LABEL_7A21
	add [0x15], 0x0002

LABEL_7A21:
	mov [0xF8], [0x15]
	shr [0xF8], 0x0004
	add [0x15], [0xF8]
	mov [0x19], 0x0001
	mov [0x14], 0x0001
	call LABEL_774F

LABEL_7A36:
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_7A6D
	je [0x19], 0xFFFF, LABEL_7A6D
	je [0x18], 0x00, LABEL_7A6D
	add [0x15], 0x0003
	je [0xE2], 0x00, LABEL_7A58
	add [0x15], 0x0002

LABEL_7A58:
	mov [0xF8], [0x15]
	shr [0xF8], 0x0004
	add [0x15], [0xF8]
	mov [0x14], 0xFFFF
	mov [0x19], 0xFFFF
	call LABEL_774F

LABEL_7A6D:
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_7A77
	mov [0x14], 0x0000

LABEL_7A77:
	call LABEL_7222
	call LABEL_73D7
	video offset=CINEMATIC_035, x=[0x1a], y=[0x1b]
	call LABEL_74A2
	call LABEL_7576
	break
	jmp LABEL_7A01
LABEL_7A8C:
	db 0x11

LABEL_7A8D:
	mov [0x19], 0x0081
	setup channel=0x02, address=LABEL_0E74
	setup channel=0x03, address=LABEL_0EA2
	setPalette 0x04
	ret

LABEL_7A9D:
	mov [0x19], 0x0081
	setup channel=0x35, address=LABEL_0E74
	setup channel=0x36, address=LABEL_0EA2
	setup channel=0x37, address=LABEL_0ED0
	setPalette 0x04
	ret

LABEL_7AB1:
	jg [0x22], 0x16, LABEL_7ABF
	video offset=CINEMATIC_101, x=[0x21], y=[0x22]
	jmp LABEL_7B2C

LABEL_7ABF:
	jg [0x22], 0x2C, LABEL_7ACD
	video offset=CINEMATIC_100, x=[0x21], y=[0x22]
	jmp LABEL_7B2C

LABEL_7ACD:
	jg [0x22], 0x42, LABEL_7ADB
	video offset=CINEMATIC_099, x=[0x21], y=[0x22]
	jmp LABEL_7B2C

LABEL_7ADB:
	jg [0x22], 0x58, LABEL_7AE9
	video offset=CINEMATIC_098, x=[0x21], y=[0x22]
	jmp LABEL_7B2C

LABEL_7AE9:
	jg [0x22], 0x6E, LABEL_7AF7
	video offset=CINEMATIC_097, x=[0x21], y=[0x22]
	jmp LABEL_7B2C

LABEL_7AF7:
	jg [0x22], 0x84, LABEL_7B05
	video offset=CINEMATIC_096, x=[0x21], y=[0x22]
	jmp LABEL_7B2C

LABEL_7B05:
	jg [0x22], 0x9A, LABEL_7B13
	video offset=CINEMATIC_095, x=[0x21], y=[0x22]
	jmp LABEL_7B2C

LABEL_7B13:
	jg [0x22], 0xB0, LABEL_7B21
	video offset=CINEMATIC_094, x=[0x21], y=[0x22]
	jmp LABEL_7B2C

LABEL_7B21:
	jg [0x22], 0xC8, LABEL_7B2C
	video offset=CINEMATIC_093, x=[0x21], y=[0x22]

LABEL_7B2C:
	ret
LABEL_7B2D:
	db 0x11

LABEL_7B2E:
	mov [0x14], 0x1F40
	jne [HACK_VAR_67], 0x05, LABEL_7B3C
	mov [0x14], 0x2710

LABEL_7B3C:
	jne [HACK_VAR_67], 0x25, LABEL_7B46
	mov [0x14], 0x23F0

LABEL_7B46:
	jne [HACK_VAR_67], 0x45, LABEL_7B56
	mov [0x14], 0x2260
	je [HERO_POS_UP_DOWN], 0x01, LABEL_810A

LABEL_7B56:
	jne [HACK_VAR_67], 0x65, LABEL_7B67
	mov [0x14], 0x28A0
	je [HERO_POS_UP_DOWN], 0xFFFF, LABEL_810A

LABEL_7B67:
	setup channel=0x3C, address=LABEL_0711
	setPalette 0x04
	mov [0x0F], 0x0000
	setup channel=0x17, address=KILL_CHANNEL_LANDING
	unfreezeChannels first=0x00, last=0x33
	unfreezeChannels first=0x3D, last=0x3F
	deleteChannels first=0x35, last=0x3B
	freezeChannels first=0x01, last=0x01
	call LABEL_7A9D
	mov [0x63], [HERO_POS_UP_DOWN]
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	video offset=CINEMATIC_127, x=160, y=100
	je [HACK_VAR_67], 0x65, LABEL_7B9F
	video offset=CINEMATIC_106, x=218, y=100

LABEL_7B9F:
	jne [HACK_VAR_67], 0x65, LABEL_7BB1
	video offset=CINEMATIC_090, x=160, y=100
	video offset=CINEMATIC_091, x=160, y=100
	video offset=CINEMATIC_104, x=200, y=100

LABEL_7BB1:
	mov [0x2A], 0x000F
	mov [0x01], [0x28]
	call LABEL_6F61
	mov [0x11], 0x0000
	jne [0x6A], [HACK_VAR_67], LABEL_7BE6
	mov [0x07], [0x68]
	mov [0x08], [0x69]
	mov [0x0E], 0x0000
	mov [0x0D], 0x0000
	mov [0x10], [0x6A]
	mov [0x09], 0x0000
	jge [0x68], 0x91, LABEL_7C00

LABEL_7BE0:
	call LABEL_7E2C
	jmp LABEL_7C0D

LABEL_7BE6:
	jle [0x68], 0x91, LABEL_7C0D
	mov [0xF8], [0x6A]
	and [0xF8], 0x001F
	jne [0xF8], 0x05, LABEL_7C0D
	mov [0x68], 0x0073
	jmp LABEL_7C0D

LABEL_7C00:
	jg [0x68], 0xB8, LABEL_7BE0
	call GUARDED_DRAW_CIN_242_243
	mov [0x11], 0x0001

LABEL_7C0D:
	video offset=CINEMATIC_105, x=160, y=129
	selectVideoPage 0xFF
	mov [SCROLL_Y], 0x0000
	mov [0x17], 0x0000
	mov [0x18], 0x0000
	selectVideoPage 0x03
	video offset=CINEMATIC_130, x=160, y=100
	selectVideoPage 0xFF
	call LABEL_7D8F
	jmp LABEL_7DB0
LABEL_7C2D:
	db 0x11

LABEL_7C2E:
	jg [SCROLL_Y], 0xFF38, LABEL_7C41
	add [0x17], 0x0001
	and [0x17], 0x0001
	add [SCROLL_Y], 0x00C8

LABEL_7C41:
	jl [SCROLL_Y], 0xC8, LABEL_7C53
	add [0x17], 0x0001
	and [0x17], 0x0001
	sub [SCROLL_Y], 0x00C8

LABEL_7C53:
	call LABEL_7C8A
	jl [SCROLL_Y], 0x00, LABEL_7C68
	sub [SCROLL_Y], 0x00C8
	call LABEL_7C75
	add [SCROLL_Y], 0x00C8
	ret

LABEL_7C68:
	add [SCROLL_Y], 0x00C8
	call LABEL_7C75
	sub [SCROLL_Y], 0x00C8
	ret
LABEL_7C74:
	db 0x11

LABEL_7C75:
	je [0x16], 0x00, DEDUP_PRISON_4B_033
	je [0x17], 0x00, DEDUP_PRISON_4B_033
	copyVideoPage src=0x80, dst=0xFF
	ret
