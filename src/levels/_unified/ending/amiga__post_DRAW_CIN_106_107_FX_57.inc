LABEL_03D0:
	break
	video offset=CINEMATIC_074, x=160, y=100
	jmp LABEL_03D0
LABEL_03D8:
	db 0x11

ZOOM_LOOP_CIN_105:
	video offset=CINEMATIC_105, x=160, y=100
	add [0x03], 0x0002
	break
	jmp ZOOM_LOOP_CIN_105
LABEL_03E5:
	db 0x11

HANG_DRAWING_CIN_066_VAR03:
	video offset=CINEMATIC_066, x=[0x01], y=[0x02], zoom=[0x03]
	add [0x03], 0x0000
	break
	jmp HANG_DRAWING_CIN_066_VAR03

DRAW_CIN_86_87_88_89:
	video offset=CINEMATIC_086, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_087, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_088, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_089, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_090, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_091, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_092, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_093, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_094, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_092, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_091, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_090, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_089, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_088, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_087, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_095, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_096, x=[0x01], y=[0x02], zoom=[0x03]
	break
	jmp DRAW_CIN_86_87_88_89
LABEL_046E:
	db 0x11

LABEL_046F:
	video offset=CINEMATIC_075, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_076, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_077, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_078, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_079, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_080, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_081, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_082, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_083, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_081, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_080, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_079, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_078, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_077, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_076, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_084, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_085, x=[0x01], y=[0x02], zoom=[0x03]
	break
	jmp LABEL_046F
LABEL_04E9:
	db 0x11
