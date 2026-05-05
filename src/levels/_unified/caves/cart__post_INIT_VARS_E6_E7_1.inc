LABEL_1128:
	mov [0x22], 0x0003
	mov [0x21], 0xFFF6
	mov [0x23], 0x0007
	sub [0x23], [0xE7]
	video offset=CINEMATIC_759, x=[0x23], y=120, zoom=0x40
	add [0x23], 0x0028
	video offset=CINEMATIC_759, x=[0x23], y=120, zoom=0x40
	add [0x21], [0xE7]

LABEL_1148:
	video offset=CINEMATIC_760, x=[0xe6], y=[0x21], zoom=0x40
	add [0x21], 0x0028
	djnz [0x22], LABEL_1148
	break
	djnz [0xE7], LABEL_1128
	jmp INIT_VARS_E6_E7_1

LABEL_115D:
	selectVideoPage 0x00
	video offset=CINEMATIC_191, x=[0xe6], y=[0xe7], zoom=0x40
	selectVideoPage 0xFF
	ret

LABEL_1167:
	selectVideoPage 0x00
	video offset=CINEMATIC_209, x=[0xe6], y=[0xe7], zoom=0x40
	selectVideoPage 0xFF
	ret

LABEL_1171:
	selectVideoPage 0x00
	video offset=CINEMATIC_210, x=[0xe6], y=[0xe7], zoom=0x40
	selectVideoPage 0xFF
	ret

LABEL_117B:
	selectVideoPage 0x00
	video offset=CINEMATIC_211, x=[0xe6], y=[0xe7], zoom=0x40
	selectVideoPage 0xFF
	ret

LABEL_1185:
	selectVideoPage 0x00
	video offset=CINEMATIC_212, x=[0xe6], y=[0xe7], zoom=0x40
	selectVideoPage 0xFF
	ret

LABEL_118F:
	selectVideoPage 0x00
	video offset=CINEMATIC_213, x=[0xe6], y=[0xe7], zoom=0x40
	selectVideoPage 0xFF
	ret
