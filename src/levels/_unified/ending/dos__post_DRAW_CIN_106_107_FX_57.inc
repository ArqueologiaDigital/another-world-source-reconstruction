PTERANODON_HEAD_POST_CRY_HOLD_LOOP:
	break
	video offset=CINEMATIC_PTERANODON_HEAD_RAISED, x=160, y=100
	jmp PTERANODON_HEAD_POST_CRY_HOLD_LOOP
LABEL_04E2:
	db 0x11

ENDING_CLOSEUP_SHOT_ZOOM_RAMP_DRIVER_LOOP:
	video offset=CINEMATIC_ENDING_CLOSEUP_ZOOM_TARGET, x=160, y=100
	add [0x03], 0x0002
	break
	jmp ENDING_CLOSEUP_SHOT_ZOOM_RAMP_DRIVER_LOOP
LABEL_04EF:
	db 0x11

ENDING_PTERANODON_RIDER_HOLD_LOOP:
	video offset=CINEMATIC_PTERANODON_RIDER, x=[0x01], y=[0x02], zoom=[0x03]
	add [0x03], 0x0000
	break
	jmp ENDING_PTERANODON_RIDER_HOLD_LOOP

PTERANODON_WING_LEFT_FLAP_LOOP:
	video offset=CINEMATIC_PTERANODON_WING_LEFT_F0, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_LEFT_F1, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_LEFT_F2, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_LEFT_F3, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_LEFT_F4, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_LEFT_F5, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_LEFT_F6, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_LEFT_F7, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_LEFT_F8, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_LEFT_F6, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_LEFT_F5, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_LEFT_F4, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_LEFT_F3, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_LEFT_F2, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_LEFT_F1, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_LEFT_F9, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_LEFT_F10, x=[0x01], y=[0x02], zoom=[0x03]
	break
	jmp PTERANODON_WING_LEFT_FLAP_LOOP
LABEL_0578:
	db 0x11

PTERANODON_WING_RIGHT_FLAP_LOOP:
	video offset=CINEMATIC_PTERANODON_WING_RIGHT_F0, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_RIGHT_F1, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_RIGHT_F2, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_RIGHT_F3, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_RIGHT_F4, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_RIGHT_F5, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_RIGHT_F6, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_RIGHT_F7, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_RIGHT_F8, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_RIGHT_F6, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_RIGHT_F5, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_RIGHT_F4, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_RIGHT_F3, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_RIGHT_F2, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_RIGHT_F1, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_RIGHT_F9, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_PTERANODON_WING_RIGHT_F10, x=[0x01], y=[0x02], zoom=[0x03]
	break
	jmp PTERANODON_WING_RIGHT_FLAP_LOOP
LABEL_05F3:
	db 0x11
