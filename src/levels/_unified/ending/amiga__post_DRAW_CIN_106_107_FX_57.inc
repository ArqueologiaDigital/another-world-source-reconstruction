PTERANODON_HEAD_POST_CRY_HOLD_LOOP:
	break
	video offset=CINEMATIC_074, x=160, y=100
	jmp PTERANODON_HEAD_POST_CRY_HOLD_LOOP
LABEL_03D8:
	db 0x11

ENDING_CLOSEUP_SHOT_ZOOM_RAMP_DRIVER_LOOP:
	video offset=CINEMATIC_105, x=160, y=100
	add [0x03], 0x0002
	break
	jmp ENDING_CLOSEUP_SHOT_ZOOM_RAMP_DRIVER_LOOP
LABEL_03E5:
	db 0x11

ENDING_PTERANODON_RIDER_HOLD_LOOP:
	video offset=CINEMATIC_066, x=[0x01], y=[0x02], zoom=[0x03]
	add [0x03], 0x0000
	break
	jmp ENDING_PTERANODON_RIDER_HOLD_LOOP

PTERANODON_WING_LEFT_FLAP_LOOP:
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
	jmp PTERANODON_WING_LEFT_FLAP_LOOP
LABEL_046E:
	db 0x11

PTERANODON_WING_RIGHT_FLAP_LOOP:
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
	jmp PTERANODON_WING_RIGHT_FLAP_LOOP
LABEL_04E9:
	db 0x11
