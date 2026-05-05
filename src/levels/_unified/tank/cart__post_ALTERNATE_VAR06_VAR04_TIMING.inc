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

HANG_DRAW_CIN_225:
	video offset=CINEMATIC_225, x=[0x0a], y=100, zoom=0x40
	break
	jmp HANG_DRAW_CIN_225

DRAW_CIN_224_MULTI_FRAME:
	video offset=CINEMATIC_224, x=[0x0a], y=100, zoom=0x40
	je [0xDB], 0x01, HANG_DRAW_CIN_225
	break
	video offset=CINEMATIC_224, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_224, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_224, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_226, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_226, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_226, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_226, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_227, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_227, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_227, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_227, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_228, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_228, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_228, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_228, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_227, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_227, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_227, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_227, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_226, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_226, x=[0x0a], y=100, zoom=0x40
	break
	video offset=CINEMATIC_226, x=[0x0a], y=100, zoom=0x40
	break
	jmp DRAW_CIN_224_MULTI_FRAME
