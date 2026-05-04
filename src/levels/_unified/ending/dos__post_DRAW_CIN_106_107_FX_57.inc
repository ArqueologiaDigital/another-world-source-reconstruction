LABEL_04DA:
	break
	video type=1, offset=CINEMATIC_074, x=160, y=100
	jmp LABEL_04DA
LABEL_04E2:
	db 0x11

ZOOM_LOOP_CIN_105:
	video type=1, offset=CINEMATIC_105, x=160, y=100
	add [0x03], 0x0002
	break
	jmp ZOOM_LOOP_CIN_105
LABEL_04EF:
	db 0x11

HANG_DRAWING_CIN_066_VAR03:
	video type=1, offset=CINEMATIC_066, x=[0x01], y=[0x02], zoom=[0x03]
	add [0x03], 0x0000
	break
	jmp HANG_DRAWING_CIN_066_VAR03

DRAW_CIN_086_087_088_SEQ:
	video type=1, offset=CINEMATIC_086, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_087, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_088, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_089, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_090, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_091, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_092, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_093, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_094, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_092, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_091, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_090, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_089, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_088, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_087, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_095, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_096, x=[0x01], y=[0x02], zoom=[0x03]
	break
	jmp DRAW_CIN_086_087_088_SEQ
LABEL_0578:
	db 0x11

DRAW_CIN_075_076_077_SEQ:
	video type=1, offset=CINEMATIC_075, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_076, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_077, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_078, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_079, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_080, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_081, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_082, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_083, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_081, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_080, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_079, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_078, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_077, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_076, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_084, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_085, x=[0x01], y=[0x02], zoom=[0x03]
	break
	jmp DRAW_CIN_075_076_077_SEQ
LABEL_05F3:
	db 0x11
