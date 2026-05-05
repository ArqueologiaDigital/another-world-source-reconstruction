DELAY_LOOP_VAR66:
	break
	djnz [0x66], DELAY_LOOP_VAR66
	play id=0x0052, freq=0x1E, vol=0x20, channel=0x01
	video offset=CINEMATIC_032, x=160, y=100
	break
	video offset=CINEMATIC_033, x=160, y=100
	break
	video offset=CINEMATIC_034, x=160, y=100
	break
	play id=0x0052, freq=0x1E, vol=0x20, channel=0x01
	video offset=CINEMATIC_035, x=160, y=100
	break
	video offset=CINEMATIC_036, x=160, y=100
	break
	video offset=CINEMATIC_037, x=160, y=100
	break
	video offset=CINEMATIC_038, x=160, y=100
	break
	video offset=CINEMATIC_039, x=160, y=100
	break
	play id=0x0052, freq=0x18, vol=0x20, channel=0x01
	video offset=CINEMATIC_040, x=160, y=100
	break
	video offset=CINEMATIC_041, x=160, y=100
	break
	video offset=CINEMATIC_042, x=160, y=100
	break
	play id=0x0052, freq=0x1C, vol=0x20, channel=0x01
	video offset=CINEMATIC_043, x=160, y=100
	break
	video offset=CINEMATIC_044, x=160, y=100
	break
	mov [0x66], 0x0005
	jmp DELAY_LOOP_VAR66

LABEL_1133:
	break
	je [0x47], 0x00, LABEL_1133
	mov [0x47], 0x0000
	mov [0x48], 0x00AC
	mov [0x49], 0x0064
	mov [0x4A], 0x0018

LABEL_114A:
	video offset=CINEMATIC_200, x=[0x48], y=[0x49], zoom=0x40
	add [0x48], 0x0001
	break
	djnz [0x4A], LABEL_114A
	mov [0x4A], 0x0005

ANIM_CIN_200_LOOP_VAR4A:
	video offset=CINEMATIC_200, x=[0x48], y=[0x49], zoom=0x40
	break
	djnz [0x4A], ANIM_CIN_200_LOOP_VAR4A
	add [0x48], 0x0010
	add [0x49], 0x0004
	video offset=CINEMATIC_200, x=[0x48], y=[0x49], zoom=0x40
	break
	add [0x48], 0x001A
	add [0x49], 0x0001
	video offset=CINEMATIC_200, x=[0x48], y=[0x49], zoom=0x40
	break
	add [0x48], 0x001E
	sub [0x49], 0x0001
	video offset=CINEMATIC_200, x=[0x48], y=[0x49], zoom=0x40
	break
	add [0x48], 0x0028
	add [0x49], 0x0001
	video offset=CINEMATIC_200, x=[0x48], y=[0x49], zoom=0x40
	mov [0x4A], 0x000A

DELAY_LOOP_VAR4A_AT_11A1:
	break
	djnz [0x4A], DELAY_LOOP_VAR4A_AT_11A1
	setup channel=0x38, address=LABEL_1045
	killChannel
