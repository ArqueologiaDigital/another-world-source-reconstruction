PTERANODON_HEAD_RAISE_ANIM:
	video offset=CINEMATIC_PTERANODON_HEAD_RAISE_F0, x=160, y=100
	break
	video offset=CINEMATIC_PTERANODON_HEAD_RAISE_F0, x=160, y=100
	break
	video offset=CINEMATIC_PTERANODON_HEAD_RAISE_F0, x=160, y=100
	break
	video offset=CINEMATIC_PTERANODON_HEAD_RAISE_F1, x=160, y=100
	break
	video offset=CINEMATIC_PTERANODON_HEAD_RAISE_F1, x=160, y=100
	break
	video offset=CINEMATIC_PTERANODON_HEAD_RAISE_F2, x=160, y=100
	break
	video offset=CINEMATIC_PTERANODON_HEAD_RAISE_F2, x=160, y=100

LABEL_04B5:
	break
	video offset=CINEMATIC_PTERANODON_HEAD_RAISED, x=160, y=100
	jmp LABEL_04B5
LABEL_04BD:
	db 0x06

PTERANODON_HEAD_LOWERED_HOLD_LOOP:
	video offset=CINEMATIC_PTERANODON_HEAD_RAISE_F0, x=160, y=100
	break
	jmp PTERANODON_HEAD_LOWERED_HOLD_LOOP

PTERANODON_HEAD_BEAK_OPEN_ANIM:
	video offset=CINEMATIC_PTERANODON_BEAK_OPEN_F0, x=160, y=100
	break
	video offset=CINEMATIC_PTERANODON_BEAK_OPEN_F0, x=160, y=100
	break
	play id=0x0057, freq=0x22, vol=0x20, channel=0x03
	video offset=CINEMATIC_PTERANODON_BEAK_OPEN_F1, x=160, y=100
	break
	video offset=CINEMATIC_PTERANODON_BEAK_OPEN_F1, x=160, y=100
	break
	video offset=CINEMATIC_PTERANODON_BEAK_OPEN_F1, x=160, y=100
	break
	video offset=CINEMATIC_PTERANODON_BEAK_OPEN_F1, x=160, y=100
	break
	video offset=CINEMATIC_PTERANODON_BEAK_OPEN_F0, x=160, y=100

LABEL_04EE:
	break
	video offset=CINEMATIC_PTERANODON_HEAD_RAISED, x=160, y=100
	jmp LABEL_04EE
LABEL_04F6:
	db 0x11

ENDING_CLOSEUP_SHOT_ZOOM_RAMP_DRIVER_LOOP:
	video offset=CINEMATIC_ENDING_CLOSEUP_ZOOM_TARGET, x=160, y=100
	add [0x03], 0x0002
	break
	jmp ENDING_CLOSEUP_SHOT_ZOOM_RAMP_DRIVER_LOOP
LABEL_0503:
	db 0x11

ENDING_PTERANODON_RIDER_HOLD_LOOP:
	video offset=CINEMATIC_PTERANODON_RIDER, x=[0x01], y=[0x02], zoom=[0x03]
	add [0x03], 0x0000
	break
	jmp ENDING_PTERANODON_RIDER_HOLD_LOOP

DRAW_CIN_086_087_SEQ:
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
	jmp DRAW_CIN_086_087_SEQ
LABEL_058C:
	db 0x11

DRAW_CIN_075_076_SEQ:
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
	jmp DRAW_CIN_075_076_SEQ
LABEL_0607:
	db 0x11
