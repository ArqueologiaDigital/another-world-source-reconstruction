DELAY_LOOP_VAR66__DOS__POST_INLINE_SET_VAR66_TO_32:
	break
	djnz [0x66], DELAY_LOOP_VAR66__DOS__POST_INLINE_SET_VAR66_TO_32
	play id=0x0052, freq=0x1E, vol=0x20, channel=0x01
	video type=1, offset=CINEMATIC_048, x=160, y=100
	break
	video type=1, offset=CINEMATIC_049, x=160, y=100
	break
	video type=1, offset=CINEMATIC_050, x=160, y=100
	break
	play id=0x0052, freq=0x1E, vol=0x20, channel=0x01
	video type=1, offset=CINEMATIC_051, x=160, y=100
	break
	video type=1, offset=CINEMATIC_052, x=160, y=100
	break
	video type=1, offset=CINEMATIC_053, x=160, y=100
	break
	video type=1, offset=CINEMATIC_054, x=160, y=100
	break
	video type=1, offset=CINEMATIC_055, x=160, y=100
	break
	play id=0x0052, freq=0x18, vol=0x20, channel=0x01
	video type=1, offset=CINEMATIC_056, x=160, y=100
	break
	video type=1, offset=CINEMATIC_057, x=160, y=100
	break
	video type=1, offset=CINEMATIC_058, x=160, y=100
	break
	play id=0x0052, freq=0x1C, vol=0x20, channel=0x01
	video type=1, offset=CINEMATIC_059, x=160, y=100
	break
	video type=1, offset=CINEMATIC_060, x=160, y=100
	break
	mov [0x66], 0x0005
	jmp DELAY_LOOP_VAR66__DOS__POST_INLINE_SET_VAR66_TO_32

LABEL_121F:
	break
	je [0x47], 0x00, LABEL_121F
	mov [0x47], 0x0000
	mov [0x48], 0x00AC
	mov [0x49], 0x0064
	mov [0x4A], 0x0018

LABEL_1236:
	video type=1, offset=CINEMATIC_176, x=[0x48], y=[0x49], zoom=0x40
	add [0x48], 0x0001
	break
	djnz [0x4A], LABEL_1236
	mov [0x4A], 0x0005

ANIM_CIN_176_LOOP_VAR4A:
	video type=1, offset=CINEMATIC_176, x=[0x48], y=[0x49], zoom=0x40
	break
	djnz [0x4A], ANIM_CIN_176_LOOP_VAR4A
	add [0x48], 0x0010
	add [0x49], 0x0004
	video type=1, offset=CINEMATIC_176, x=[0x48], y=[0x49], zoom=0x40
	break
	add [0x48], 0x001A
	add [0x49], 0x0001
	video type=1, offset=CINEMATIC_176, x=[0x48], y=[0x49], zoom=0x40
	break
	add [0x48], 0x001E
	sub [0x49], 0x0001
	video type=1, offset=CINEMATIC_176, x=[0x48], y=[0x49], zoom=0x40
	break
	add [0x48], 0x0028
	add [0x49], 0x0001
	video type=1, offset=CINEMATIC_176, x=[0x48], y=[0x49], zoom=0x40
	mov [0x4A], 0x000A

DELAY_LOOP_VAR4A_AT_128D:
	break
	djnz [0x4A], DELAY_LOOP_VAR4A_AT_128D
	setup channel=0x38, address=LABEL_1131
	killChannel
