LABEL_7847:
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_7872
	je [0x19], 0x01, LABEL_7872
	jne [0x18], 0x00, LABEL_7872
	add [0x15], 0x0003
	mov [0xF8], [0x15]
	shr [0xF8], 0x0004
	add [0x15], [0xF8]
	mov [0x19], 0x0001
	mov [0x14], 0x0001
	call LABEL_759F

LABEL_7872:
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_789F
	je [0x19], 0xFFFF, LABEL_789F
	je [0x18], 0x00, LABEL_789F
	add [0x15], 0x0003
	mov [0xF8], [0x15]
	shr [0xF8], 0x0004
	add [0x15], [0xF8]
	mov [0x14], 0xFFFF
	mov [0x19], 0xFFFF
	call LABEL_759F

LABEL_789F:
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_78A9
	mov [0x14], 0x0000

LABEL_78A9:
	call LABEL_7072
	call LABEL_7227
	video offset=CINEMATIC_035, x=[0x1a], y=[0x1b]
	call LABEL_72F2
	call LABEL_73C6
	break
	jmp LABEL_7847
LABEL_78BE:
	db 0x11

LABEL_78BF:
	mov [0x19], 0x0081
	setup channel=0x02, address=LABEL_0E0C
	setup channel=0x03, address=LABEL_0E3A
	setPalette 0x04
	ret

LABEL_78CF:
	mov [0x19], 0x0081
	setup channel=0x35, address=LABEL_0E0C
	setup channel=0x36, address=LABEL_0E3A
	setup channel=0x37, address=LABEL_0E68
	setPalette 0x04
	ret

LABEL_78E3:
	jg [0x22], 0x16, LABEL_78F1
	video offset=CINEMATIC_101, x=[0x21], y=[0x22]
	jmp LABEL_795E

LABEL_78F1:
	jg [0x22], 0x2C, LABEL_78FF
	video offset=CINEMATIC_100, x=[0x21], y=[0x22]
	jmp LABEL_795E

LABEL_78FF:
	jg [0x22], 0x42, LABEL_790D
	video offset=CINEMATIC_099, x=[0x21], y=[0x22]
	jmp LABEL_795E

LABEL_790D:
	jg [0x22], 0x58, LABEL_791B
	video offset=CINEMATIC_098, x=[0x21], y=[0x22]
	jmp LABEL_795E

LABEL_791B:
	jg [0x22], 0x6E, LABEL_7929
	video offset=CINEMATIC_097, x=[0x21], y=[0x22]
	jmp LABEL_795E

LABEL_7929:
	jg [0x22], 0x84, LABEL_7937
	video offset=CINEMATIC_096, x=[0x21], y=[0x22]
	jmp LABEL_795E

LABEL_7937:
	jg [0x22], 0x9A, LABEL_7945
	video offset=CINEMATIC_095, x=[0x21], y=[0x22]
	jmp LABEL_795E

LABEL_7945:
	jg [0x22], 0xB0, LABEL_7953
	video offset=CINEMATIC_094, x=[0x21], y=[0x22]
	jmp LABEL_795E

LABEL_7953:
	jg [0x22], 0xC8, LABEL_795E
	video offset=CINEMATIC_093, x=[0x21], y=[0x22]

LABEL_795E:
	ret
LABEL_795F:
	db 0x11

LABEL_7960:
	mov [0x14], 0x1F40
	jne [HACK_VAR_67], 0x05, LABEL_796E
	mov [0x14], 0x2710

LABEL_796E:
	jne [HACK_VAR_67], 0x25, LABEL_7978
	mov [0x14], 0x23F0

LABEL_7978:
	jne [HACK_VAR_67], 0x45, LABEL_7988
	mov [0x14], 0x2260
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_7F09

LABEL_7988:
	jne [HACK_VAR_67], 0x65, LABEL_7999
	mov [0x14], 0x28A0
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_7F09

LABEL_7999:
	setup channel=0x3C, address=LABEL_06AD
	setPalette 0x04
	unfreezeChannels first=0x00, last=0x33
	unfreezeChannels first=0x3D, last=0x3F
	deleteChannels first=0x35, last=0x3B
	freezeChannels first=0x01, last=0x01
	call LABEL_78CF
	mov [0x63], [HERO_POS_JUMP_DOWN]
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	video offset=CINEMATIC_127, x=160, y=100
	je [HACK_VAR_67], 0x65, LABEL_79C9
	video offset=CINEMATIC_106, x=218, y=100

LABEL_79C9:
	jne [HACK_VAR_67], 0x65, LABEL_79DB
	video offset=CINEMATIC_090, x=160, y=100
	video offset=CINEMATIC_091, x=160, y=100
	video offset=CINEMATIC_104, x=200, y=100

LABEL_79DB:
	mov [0x2A], 0x000F
	mov [HERO_X], [0x28]
	call LABEL_6DB1
	mov [0x11], 0x0000
	jne [0x6A], [HACK_VAR_67], LABEL_7A1D
	mov [BUDDY_X], [0x68]
	mov [BUDDY_Y], [0x69]
	mov [0x0E], 0x0000
	mov [0x0D], 0x0000
	mov [0x10], [0x6A]
	mov [0x09], 0x0000
	jge [0x68], 0x91, LABEL_7A10

LABEL_7A0A:
	call LABEL_7C3C
	jmp LABEL_7A1D

LABEL_7A10:
	jg [0x68], 0xB8, LABEL_7A0A
	call GUARDED_DRAW_CIN_242_243
	mov [0x11], 0x0001

LABEL_7A1D:
	video offset=CINEMATIC_105, x=160, y=129
	selectVideoPage 0xFF
	mov [SCROLL_Y], 0x0000
	mov [0x17], 0x0000
	mov [0x18], 0x0000
	selectVideoPage 0x03
	video offset=CINEMATIC_130, x=160, y=100
	selectVideoPage 0xFF
	call LABEL_7B9F
	jmp LABEL_7BC0
LABEL_7A3D:
	db 0x11

LABEL_7A3E:
	jg [SCROLL_Y], 0xFF38, LABEL_7A51
	add [0x17], 0x0001
	and [0x17], 0x0001
	add [SCROLL_Y], 0x00C8

LABEL_7A51:
	jl [SCROLL_Y], 0xC8, LABEL_7A63
	add [0x17], 0x0001
	and [0x17], 0x0001
	sub [SCROLL_Y], 0x00C8

LABEL_7A63:
	call LABEL_7A9A
	jl [SCROLL_Y], 0x00, LABEL_7A78
	sub [SCROLL_Y], 0x00C8
	call LABEL_7A85
	add [SCROLL_Y], 0x00C8
	ret

LABEL_7A78:
	add [SCROLL_Y], 0x00C8
	call LABEL_7A85
	sub [SCROLL_Y], 0x00C8
	ret
LABEL_7A84:
	db 0x11

LABEL_7A85:
	je [0x16], 0x00, DEDUP_PRISON_4B_033
	je [0x17], 0x00, DEDUP_PRISON_4B_033
	copyVideoPage src=0x80, dst=0xFF
	ret
