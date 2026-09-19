ENDING_PTERANODON_FLY_AWAY_SHOT_ENTRY:
	mov [0x01], 0x00A0
	mov [0x02], 0x0064
	mov [0x03], 0x0040
	mov [0x04], 0x0040
	setPalette 0x0B
	add [0x04], 0x0002
	video offset=CINEMATIC_ENDING_PTERANODON_FLY_AWAY_F0, x=[0x01], y=[0x02], zoom=[0x03]
	break
	add [0x04], 0x0005
	video offset=CINEMATIC_ENDING_PTERANODON_FLY_AWAY_F1, x=[0x01], y=[0x02], zoom=[0x03]
	break
	add [0x04], 0x0008
	video offset=CINEMATIC_ENDING_PTERANODON_FLY_AWAY_F2, x=[0x01], y=[0x02], zoom=[0x03]
	setup channel=0x0C, address=PTERANODON_WING_LEFT_FLAP_LOOP
	setup channel=0x0D, address=PTERANODON_WING_RIGHT_FLAP_LOOP
	mov [0x06], 0x000A
