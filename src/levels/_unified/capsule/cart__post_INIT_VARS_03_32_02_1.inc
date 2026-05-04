LABEL_99B2:
	video type=1, offset=CINEMATIC_092, x=[0x01], y=[0x02], zoom=0x40
	add [SCROLL_Y], 0x0000
	sub [0x02], 0x0028
	break
	djnz [0x03], LABEL_99B2
	video type=1, offset=CINEMATIC_092, x=[0x01], y=65516, zoom=0x40
	break
	mov [0x02], [0x51]
	break
	video type=1, offset=CINEMATIC_092, x=[0x01], y=180, zoom=0x40
	mov [0x02], [0x51]
	setup channel=0x1A, address=LABEL_97CE
	jmp LABEL_9A64
LABEL_99DE:
	db 0x11
