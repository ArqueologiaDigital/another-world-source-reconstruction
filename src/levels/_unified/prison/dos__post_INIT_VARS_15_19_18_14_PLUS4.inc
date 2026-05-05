LABEL_78F8:
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_7923
	je [0x19], 0x01, LABEL_7923
	jne [0x18], 0x00, LABEL_7923
	add [0x15], 0x0003
	mov [0xF8], [0x15]
	shr [0xF8], 0x0004
	add [0x15], [0xF8]
	mov [0x19], 0x0001
	mov [0x14], 0x0001
	call LABEL_764C

LABEL_7923:
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_7950
	je [0x19], 0xFFFF, LABEL_7950
	je [0x18], 0x00, LABEL_7950
	add [0x15], 0x0003
	mov [0xF8], [0x15]
	shr [0xF8], 0x0004
	add [0x15], [0xF8]
	mov [0x14], 0xFFFF
	mov [0x19], 0xFFFF
	call LABEL_764C

LABEL_7950:
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_795A
	mov [0x14], 0x0000

LABEL_795A:
	call LABEL_711F
	call LABEL_72D4
	video offset=CINEMATIC_035, x=[0x1a], y=[0x1b], zoom=0x40
	call LABEL_739F
	call LABEL_7473
	break
	jmp LABEL_78F8
LABEL_796F:
	db 0x11

LABEL_7970:
	mov [0x19], 0x0081
	setup channel=0x02, address=LABEL_0DEC
	setup channel=0x03, address=LABEL_0E1A
	setPalette 0x04
	ret

LABEL_7980:
	mov [0x19], 0x0081
	setup channel=0x35, address=LABEL_0DEC
	setup channel=0x36, address=LABEL_0E1A
	setup channel=0x37, address=LABEL_0E48
	setPalette 0x04
	ret

LABEL_7994:
	jg [0x22], 0x16, LABEL_79A2
	video offset=CINEMATIC_101, x=[0x21], y=[0x22], zoom=0x40
	jmp LABEL_7A0F

LABEL_79A2:
	jg [0x22], 0x2C, LABEL_79B0
	video offset=CINEMATIC_100, x=[0x21], y=[0x22], zoom=0x40
	jmp LABEL_7A0F

LABEL_79B0:
	jg [0x22], 0x42, LABEL_79BE
	video offset=CINEMATIC_099, x=[0x21], y=[0x22], zoom=0x40
	jmp LABEL_7A0F

LABEL_79BE:
	jg [0x22], 0x58, LABEL_79CC
	video offset=CINEMATIC_098, x=[0x21], y=[0x22], zoom=0x40
	jmp LABEL_7A0F

LABEL_79CC:
	jg [0x22], 0x6E, LABEL_79DA
	video offset=CINEMATIC_097, x=[0x21], y=[0x22], zoom=0x40
	jmp LABEL_7A0F

LABEL_79DA:
	jg [0x22], 0x84, LABEL_79E8
	video offset=CINEMATIC_096, x=[0x21], y=[0x22], zoom=0x40
	jmp LABEL_7A0F

LABEL_79E8:
	jg [0x22], 0x9A, LABEL_79F6
	video offset=CINEMATIC_095, x=[0x21], y=[0x22], zoom=0x40
	jmp LABEL_7A0F

LABEL_79F6:
	jg [0x22], 0xB0, LABEL_7A04
	video offset=CINEMATIC_094, x=[0x21], y=[0x22], zoom=0x40
	jmp LABEL_7A0F

LABEL_7A04:
	jg [0x22], 0xC8, LABEL_7A0F
	video offset=CINEMATIC_093, x=[0x21], y=[0x22], zoom=0x40

LABEL_7A0F:
	ret
LABEL_7A10:
	db 0x11

LABEL_7A11:
	mov [0x14], 0x1F40
	jne [HACK_VAR_67], 0x05, LABEL_7A1F
	mov [0x14], 0x2710

LABEL_7A1F:
	jne [HACK_VAR_67], 0x25, LABEL_7A29
	mov [0x14], 0x23F0

LABEL_7A29:
	jne [HACK_VAR_67], 0x45, LABEL_7A39
	mov [0x14], 0x2260
	je [HERO_POS_UP_DOWN], 0x01, LABEL_7FDB

LABEL_7A39:
	jne [HACK_VAR_67], 0x65, LABEL_7A4A
	mov [0x14], 0x28A0
	je [HERO_POS_UP_DOWN], 0xFFFF, LABEL_7FDB

LABEL_7A4A:
	setup channel=0x3C, address=LABEL_0689
	setPalette 0x04
	unfreezeChannels first=0x00, last=0x33
	unfreezeChannels first=0x3D, last=0x3F
	deleteChannels first=0x35, last=0x3B
	freezeChannels first=0x01, last=0x01
	call LABEL_7980
	mov [0x63], [HERO_POS_UP_DOWN]
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	video offset=CINEMATIC_127, x=160, y=100
	je [HACK_VAR_67], 0x65, LABEL_7A7A
	video offset=CINEMATIC_106, x=218, y=100

LABEL_7A7A:
	jne [HACK_VAR_67], 0x65, LABEL_7A8C
	video offset=CINEMATIC_090, x=160, y=100
	video offset=CINEMATIC_091, x=160, y=100
	video offset=CINEMATIC_104, x=200, y=100

LABEL_7A8C:
	mov [0x2A], 0x000F
	mov [0x01], [0x28]
	call LABEL_6E5E
	mov [0x11], 0x0000
	jne [0x6A], [HACK_VAR_67], LABEL_7AC1
	mov [0x07], [0x68]
	mov [0x08], [0x69]
	mov [0x0E], 0x0000
	mov [0x0D], 0x0000
	mov [0x10], [0x6A]
	mov [0x09], 0x0000
	jge [0x68], 0x91, LABEL_7ADB

LABEL_7ABB:
	call LABEL_7D07
	jmp LABEL_7AE8

LABEL_7AC1:
	jle [0x68], 0x91, LABEL_7AE8
	mov [0xF8], [0x6A]
	and [0xF8], 0x001F
	jne [0xF8], 0x05, LABEL_7AE8
	mov [0x68], 0x0073
	jmp LABEL_7AE8

LABEL_7ADB:
	jg [0x68], 0xB8, LABEL_7ABB
	call GUARDED_DRAW_CIN_242_243
	mov [0x11], 0x0001

LABEL_7AE8:
	video offset=CINEMATIC_105, x=160, y=129
	selectVideoPage 0xFF
	mov [SCROLL_Y], 0x0000
	mov [0x17], 0x0000
	mov [0x18], 0x0000
	selectVideoPage 0x03
	video offset=CINEMATIC_130, x=160, y=100
	selectVideoPage 0xFF
	call LABEL_7C6A
	jmp LABEL_7C8B
LABEL_7B08:
	db 0x11

LABEL_7B09:
	jg [SCROLL_Y], 0xFF38, LABEL_7B1C
	add [0x17], 0x0001
	and [0x17], 0x0001
	add [SCROLL_Y], 0x00C8

LABEL_7B1C:
	jl [SCROLL_Y], 0xC8, LABEL_7B2E
	add [0x17], 0x0001
	and [0x17], 0x0001
	sub [SCROLL_Y], 0x00C8

LABEL_7B2E:
	call LABEL_7B65
	jl [SCROLL_Y], 0x00, LABEL_7B43
	sub [SCROLL_Y], 0x00C8
	call LABEL_7B50
	add [SCROLL_Y], 0x00C8
	ret

LABEL_7B43:
	add [SCROLL_Y], 0x00C8
	call LABEL_7B50
	sub [SCROLL_Y], 0x00C8
	ret
LABEL_7B4F:
	db 0x11

LABEL_7B50:
	je [0x16], 0x00, DEDUP_PRISON_4B_033
	je [0x17], 0x00, DEDUP_PRISON_4B_033
	copyVideoPage src=0x80, dst=0xFF
	ret
