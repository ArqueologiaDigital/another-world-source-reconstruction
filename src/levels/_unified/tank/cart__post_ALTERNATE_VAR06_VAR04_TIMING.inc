LABEL_1A89:
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
	jmp ANIMATE_VAR06_VAR04_REVERSE
LABEL_1AED:
	db 0x11

TANK_ARRIVAL_SIDE_MASK_REDRAW_LOOP:
	video offset=CINEMATIC_TANK_BACKDROP_SWAY, x=[0x0a], y=100
	break
	jmp TANK_ARRIVAL_SIDE_MASK_REDRAW_LOOP

DRAW_CIN_224_MULTI_FRAME:
	video offset=CINEMATIC_224, x=[0x0a], y=100
	je [0xDB], 0x01, TANK_ARRIVAL_SIDE_MASK_REDRAW_LOOP
	break
	video offset=CINEMATIC_224, x=[0x0a], y=100
	break
	video offset=CINEMATIC_224, x=[0x0a], y=100
	break
	video offset=CINEMATIC_224, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F0, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F0, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F0, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F0, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F1, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F1, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F1, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F1, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F2, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F2, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F2, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F2, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F1, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F1, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F1, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F1, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F0, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F0, x=[0x0a], y=100
	break
	video offset=CINEMATIC_CAPSULE_DOME_CLOSING_F0, x=[0x0a], y=100
	break
	jmp DRAW_CIN_224_MULTI_FRAME
