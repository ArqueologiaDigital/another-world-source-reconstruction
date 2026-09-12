TANK_FIREFIGHT_PAIR_FIRE_AND_STEP_PRELUDE:
	mov [0x06], 0x0002
	mov [0x04], 0x0002
	break
	break
	mov [0x06], 0x0003
	break
	mov [0x04], 0x0001
	break
	mov [0x06], 0x0004
	break
	break
	mov [0x06], 0x0001
	break
	mov [0x04], 0x0002
	break
	break
	mov [0x06], 0x0002
	mov [0x04], 0x0003
	break
	break
	mov [0x06], 0x0004
	mov [0x04], 0x0004
	sub [0x07], 0x0001
	break
	sub [0x07], 0x0004
	break
	mov [0x06], 0x0001
	sub [0x07], 0x0001
	sub [0x05], 0x0002
	break
	break
	mov [0x04], 0x0001
	sub [0x05], 0x0002
	break
	mov [0x06], 0x0002
	sub [0x05], 0x0002
	break
	jmp TANK_FIREFIGHT_PAIR_POSE_PRELUDE
LABEL_16D3:
	db 0x11

TANK_BACKDROP_SWAY_ANIM_LOOP:
	video offset=CINEMATIC_169, x=[0x0a], y=100
	break
	video offset=CINEMATIC_169, x=[0x0a], y=100
	break
	video offset=CINEMATIC_169, x=[0x0a], y=100
	break
	video offset=CINEMATIC_169, x=[0x0a], y=100
	break
	video offset=CINEMATIC_170, x=[0x0a], y=100
	break
	video offset=CINEMATIC_170, x=[0x0a], y=100
	break
	video offset=CINEMATIC_170, x=[0x0a], y=100
	break
	video offset=CINEMATIC_170, x=[0x0a], y=100
	break
	video offset=CINEMATIC_171, x=[0x0a], y=100
	break
	video offset=CINEMATIC_171, x=[0x0a], y=100
	break
	video offset=CINEMATIC_171, x=[0x0a], y=100
	break
	video offset=CINEMATIC_171, x=[0x0a], y=100
	break
	video offset=CINEMATIC_172, x=[0x0a], y=100
	break
	video offset=CINEMATIC_172, x=[0x0a], y=100
	break
	video offset=CINEMATIC_172, x=[0x0a], y=100
	break
	video offset=CINEMATIC_172, x=[0x0a], y=100
	break
	video offset=CINEMATIC_171, x=[0x0a], y=100
	break
	video offset=CINEMATIC_171, x=[0x0a], y=100
	break
	video offset=CINEMATIC_171, x=[0x0a], y=100
	break
	video offset=CINEMATIC_171, x=[0x0a], y=100
	break
	video offset=CINEMATIC_170, x=[0x0a], y=100
	break
	video offset=CINEMATIC_170, x=[0x0a], y=100
	break
	video offset=CINEMATIC_170, x=[0x0a], y=100
	break
	jmp TANK_BACKDROP_SWAY_ANIM_LOOP
