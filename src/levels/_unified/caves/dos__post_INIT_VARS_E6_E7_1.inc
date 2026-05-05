LABEL_1193:
	mov [0x22], 0x0003
	mov [0x21], 0xFFF6
	mov [0x23], 0x0007
	sub [0x23], [0xE7]
	video offset=CINEMATIC_768, x=[0x23], y=120, zoom=0x40
	add [0x23], 0x0028
	video offset=CINEMATIC_768, x=[0x23], y=120, zoom=0x40
	add [0x21], [0xE7]

LABEL_11B3:
	video offset=CINEMATIC_769, x=[0xe6], y=[0x21], zoom=0x40
	add [0x21], 0x0028
	djnz [0x22], LABEL_11B3
	break
	djnz [0xE7], LABEL_1193
	jmp INIT_VARS_E6_E7_1

LABEL_11C8:
	selectVideoPage 0x00
	video offset=CINEMATIC_191, x=[0xe6], y=[0xe7], zoom=0x40
	selectVideoPage 0xFF
	ret

LABEL_11D2:
	selectVideoPage 0x00
	video offset=CINEMATIC_209, x=[0xe6], y=[0xe7], zoom=0x40
	selectVideoPage 0xFF
	ret

LABEL_11DC:
	selectVideoPage 0x00
	video offset=CINEMATIC_210, x=[0xe6], y=[0xe7], zoom=0x40
	selectVideoPage 0xFF
	ret

LABEL_11E6:
	selectVideoPage 0x00
	video offset=CINEMATIC_211, x=[0xe6], y=[0xe7], zoom=0x40
	selectVideoPage 0xFF
	ret

LABEL_11F0:
	selectVideoPage 0x00
	video offset=CINEMATIC_212, x=[0xe6], y=[0xe7], zoom=0x40
	selectVideoPage 0xFF
	ret

LABEL_11FA:
	selectVideoPage 0x00
	video offset=CINEMATIC_213, x=[0xe6], y=[0xe7], zoom=0x40
	selectVideoPage 0xFF
	ret
