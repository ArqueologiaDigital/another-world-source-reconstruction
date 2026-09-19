LABEL_00AE:
	db 0x11

ENDING_CLOSEUP_SHOT_CUT_TO_FLY_AWAY_ENTRY:
	mov [0x01], 0x00A0
	mov [0x02], 0x0064
	mov [0x03], 0x0040
	video offset=CINEMATIC_052, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_053, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_054, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_055, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_056, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_054, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_057, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_053, x=[0x01], y=[0x02], zoom=[0x03]
	deleteChannels first=0x0A, last=0x0E
	copyVideoPage src=0x03, dst=0x00
	setup channel=0x0A, address=ENDING_PTERANODON_FLY_AWAY_SHOT_ENTRY
	setup channel=0x0B, address=ENDING_LEDGE_SWELL_DRAW_LOOP
	setup channel=0x0E, address=ENDING_PTERANODON_RIDER_HOLD_LOOP
	setup channel=0x0F, address=PTERANODON_LEG_DANGLE_LOOP
	killChannel
