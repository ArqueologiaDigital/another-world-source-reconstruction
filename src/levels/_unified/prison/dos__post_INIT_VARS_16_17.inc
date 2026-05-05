DELAY_LOOP_VAR17:
	break
	djnz [0x17], DELAY_LOOP_VAR17
	mov [0x17], 0x0004

LABEL_4DB6:
	break
	sub [0x16], 0x0001
	djnz [0x17], LABEL_4DB6
	mov [0x17], 0x0002

LABEL_4DC3:
	break
	break
	sub [0x16], 0x0001
	djnz [0x17], LABEL_4DC3
	break
	add [0x16], 0x0001
	break
	break
	break
	add [0x16], 0x0001
	killChannel

LABEL_4DDA:
	video offset=CINEMATIC_656, x=[0x1a], y=[0x1b], zoom=0x40
	jg [0x16], 0x01, LABEL_4DED
	video offset=CINEMATIC_682, x=[0x1a], y=[0x1b], zoom=0x40
	jmp LABEL_4E38

LABEL_4DED:
	jg [0x16], 0x02, LABEL_4DFB
	video offset=CINEMATIC_681, x=[0x1a], y=[0x1b], zoom=0x40
	jmp LABEL_4E38

LABEL_4DFB:
	jg [0x16], 0x03, LABEL_4E09
	video offset=CINEMATIC_680, x=[0x1a], y=[0x1b], zoom=0x40
	jmp LABEL_4E38

LABEL_4E09:
	jg [0x16], 0x04, LABEL_4E17
	video offset=CINEMATIC_679, x=[0x1a], y=[0x1b], zoom=0x40
	jmp LABEL_4E38

LABEL_4E17:
	jg [0x16], 0x05, LABEL_4E25
	video offset=CINEMATIC_678, x=[0x1a], y=[0x1b], zoom=0x40
	jmp LABEL_4E38

LABEL_4E25:
	jg [0x16], 0x06, DRAW_CIN657_AT_X1A_Y1B
	video offset=CINEMATIC_677, x=[0x1a], y=[0x1b], zoom=0x40
	jmp LABEL_4E38
