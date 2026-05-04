LABEL_00AE:
	db 0x11

LABEL_00AF:
	mov [0x01], 0x00A0
	mov [0x02], 0x0064
	mov [0x03], 0x0040
	video type=1, offset=CINEMATIC_052, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_053, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_054, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_055, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_056, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_054, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_057, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_053, x=[0x01], y=[0x02], zoom=[0x03]
	deleteChannels first=0x0A, last=0x0E
	copyVideoPage src=0x03, dst=0x00
	setup channel=0x0A, address=LABEL_0149
	setup channel=0x0B, address=DRAW_CIN_58_ANIM_LOOP
	setup channel=0x0E, address=HANG_DRAWING_CIN_066_VAR03
	setup channel=0x0F, address=DRAW_CIN_59_TO_64_VAR_POS
	killChannel
