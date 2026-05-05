LABEL_34F6:
	sub [0xE9], 0x0008
	mov [0x21], [0xE9]
	call LABEL_351C
	break
	djnz [0xE8], LABEL_34F6
	mov [0xE8], 0x002F

LABEL_3509:
	add [0xE9], 0x0008
	mov [0x21], [0xE9]
	call LABEL_351C
	break
	djnz [0xE8], LABEL_3509
	jmp INLINE_SET_VARE8_TO_2F
LABEL_351B:
	db 0x11

LABEL_351C:
	video offset=CINEMATIC_013, x=[0x21], y=100, zoom=0x40
	sub [0x21], 0x0064
	video offset=CINEMATIC_013, x=[0x21], y=100, zoom=0x40
	add [0x21], 0x00AA
	video offset=CINEMATIC_013, x=[0x21], y=100, zoom=0x40
	ret
LABEL_3534:
	db 0x11

LABEL_3535:
	setup channel=0x06, address=INIT_VARS_EB_EC_ED
	selectVideoPage 0x03
	video offset=CINEMATIC_800, x=160, y=100
	selectVideoPage 0xFF
	video offset=CINEMATIC_801, x=160, y=100
	break
	video offset=CINEMATIC_802, x=160, y=100
	break
	video offset=CINEMATIC_803, x=160, y=100
	break
	video offset=CINEMATIC_804, x=160, y=100
	break
	video offset=CINEMATIC_805, x=160, y=100
	break
	video offset=CINEMATIC_804, x=160, y=100
	selectVideoPage 0x03
	video offset=CINEMATIC_806, x=169, y=136
	video offset=CINEMATIC_806, x=169, y=160
	selectVideoPage 0xFF
	killChannel
