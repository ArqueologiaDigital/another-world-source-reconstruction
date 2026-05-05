LABEL_371F:
	sub [0xE9], 0x0008
	mov [0x21], [0xE9]
	call LABEL_3745
	break
	djnz [0xE8], LABEL_371F
	mov [0xE8], 0x002F

LABEL_3732:
	add [0xE9], 0x0008
	mov [0x21], [0xE9]
	call LABEL_3745
	break
	djnz [0xE8], LABEL_3732
	jmp INLINE_SET_VARE8_TO_2F
LABEL_3744:
	db 0x11

LABEL_3745:
	video offset=CINEMATIC_013, x=[0x21], y=100
	sub [0x21], 0x0064
	video offset=CINEMATIC_013, x=[0x21], y=100
	add [0x21], 0x00AA
	video offset=CINEMATIC_013, x=[0x21], y=100
	ret
LABEL_375D:
	db 0x11

LABEL_375E:
	setup channel=0x06, address=INIT_VARS_EB_EC_ED
	selectVideoPage 0x03
	video offset=CINEMATIC_824, x=160, y=100
	selectVideoPage 0xFF
	video offset=CINEMATIC_825, x=160, y=100
	break
	video offset=CINEMATIC_826, x=160, y=100
	break
	video offset=CINEMATIC_827, x=160, y=100
	break
	video offset=CINEMATIC_828, x=160, y=100
	break
	video offset=CINEMATIC_829, x=160, y=100
	break
	video offset=CINEMATIC_828, x=160, y=100
	selectVideoPage 0x03
	video offset=CINEMATIC_830, x=169, y=136
	video offset=CINEMATIC_830, x=169, y=160
	selectVideoPage 0xFF
	killChannel
