DELAY_LOOP_VAR66:
	break
	djnz [0x66], DELAY_LOOP_VAR66
	play id=0x0052, freq=0x1E, vol=0x20, channel=0x01
	video offset=CINEMATIC_046, x=160, y=100
	break
	video offset=CINEMATIC_047, x=160, y=100
	break
	video offset=CINEMATIC_048, x=160, y=100
	break
	play id=0x0052, freq=0x1E, vol=0x20, channel=0x01
	video offset=CINEMATIC_049, x=160, y=100
	break
	video offset=CINEMATIC_050, x=160, y=100
	break
	video offset=CINEMATIC_051, x=160, y=100
	break
	video offset=CINEMATIC_052, x=160, y=100
	break
	video offset=CINEMATIC_053, x=160, y=100
	break
	play id=0x0052, freq=0x18, vol=0x20, channel=0x01
	video offset=CINEMATIC_054, x=160, y=100
	break
	video offset=CINEMATIC_055, x=160, y=100
	break
	video offset=CINEMATIC_056, x=160, y=100
	break
	play id=0x0052, freq=0x1C, vol=0x20, channel=0x01
	video offset=CINEMATIC_057, x=160, y=100
	break
	video offset=CINEMATIC_058, x=160, y=100
	break
	mov [0x66], 0x0005
	jmp DELAY_LOOP_VAR66

LABEL_0D41:
	break
	je [0x47], 0x00, LABEL_0D41
	mov [0x47], 0x0000
	mov [0x48], 0x00AC
	mov [0x49], 0x0064
	mov [0x4A], 0x0018

LABEL_0D58:
	video offset=CINEMATIC_124, x=[0x48], y=[0x49]
	add [0x48], 0x0001
	break
	djnz [0x4A], LABEL_0D58
	mov [0x4A], 0x0005

ANIM_CIN_124_LOOP_VAR4A:
	video offset=CINEMATIC_124, x=[0x48], y=[0x49]
	break
	djnz [0x4A], ANIM_CIN_124_LOOP_VAR4A
	add [0x48], 0x0010
	add [0x49], 0x0004
	video offset=CINEMATIC_124, x=[0x48], y=[0x49]
	break
	add [0x48], 0x001A
	add [0x49], 0x0001
	video offset=CINEMATIC_124, x=[0x48], y=[0x49]
	break
	add [0x48], 0x001E
	sub [0x49], 0x0001
	video offset=CINEMATIC_124, x=[0x48], y=[0x49]
	break
	add [0x48], 0x0028
	add [0x49], 0x0001
	video offset=CINEMATIC_124, x=[0x48], y=[0x49]
	mov [0x4A], 0x000A

DELAY_LOOP_VAR4A_AT_0DAF:
	break
	djnz [0x4A], DELAY_LOOP_VAR4A_AT_0DAF
	setup channel=0x38, address=LABEL_0C53
	killChannel
