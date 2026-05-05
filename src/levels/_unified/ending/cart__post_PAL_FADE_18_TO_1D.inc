DRAW_CIN_71_72_FADE:
	video offset=CINEMATIC_071, x=160, y=100
	break
	video offset=CINEMATIC_071, x=160, y=100
	break
	video offset=CINEMATIC_071, x=160, y=100
	break
	video offset=CINEMATIC_072, x=160, y=100
	break
	video offset=CINEMATIC_072, x=160, y=100
	break
	video offset=CINEMATIC_073, x=160, y=100
	break
	video offset=CINEMATIC_073, x=160, y=100

LABEL_04B5:
	break
	video offset=CINEMATIC_074, x=160, y=100
	jmp LABEL_04B5
LABEL_04BD:
	db 0x06

HANG_DRAWING_CIN_071:
	video offset=CINEMATIC_071, x=160, y=100
	break
	jmp HANG_DRAWING_CIN_071

DRAW_CIN_106_107_FX_57:
	video offset=CINEMATIC_106, x=160, y=100
	break
	video offset=CINEMATIC_106, x=160, y=100
	break
	play id=0x0057, freq=0x22, vol=0x20, channel=0x03
	video offset=CINEMATIC_107, x=160, y=100
	break
	video offset=CINEMATIC_107, x=160, y=100
	break
	video offset=CINEMATIC_107, x=160, y=100
	break
	video offset=CINEMATIC_107, x=160, y=100
	break
	video offset=CINEMATIC_106, x=160, y=100

LABEL_04EE:
	break
	video offset=CINEMATIC_074, x=160, y=100
	jmp LABEL_04EE
LABEL_04F6:
	db 0x11

ZOOM_LOOP_CIN_105:
	video offset=CINEMATIC_105, x=160, y=100
	add [0x03], 0x0002
	break
	jmp ZOOM_LOOP_CIN_105
LABEL_0503:
	db 0x11

HANG_DRAWING_CIN_066_VAR03:
	video offset=CINEMATIC_066, x=[0x01], y=[0x02], zoom=[0x03]
	add [0x03], 0x0000
	break
	jmp HANG_DRAWING_CIN_066_VAR03

DRAW_CIN_086_087_SEQ:
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
	jmp DRAW_CIN_086_087_SEQ
LABEL_058C:
	db 0x11

DRAW_CIN_075_076_SEQ:
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
	jmp DRAW_CIN_075_076_SEQ
LABEL_0607:
	db 0x11
