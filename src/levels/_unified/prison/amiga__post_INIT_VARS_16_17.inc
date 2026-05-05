DELAY_LOOP_VAR17:
	break
	djnz [0x17], DELAY_LOOP_VAR17
	mov [0x17], 0x0004

LABEL_4D0D:
	break
	sub [0x16], 0x0001
	djnz [0x17], LABEL_4D0D
	mov [0x17], 0x0002

LABEL_4D1A:
	break
	break
	sub [0x16], 0x0001
	djnz [0x17], LABEL_4D1A
	break
	add [0x16], 0x0001
	break
	break
	break
	add [0x16], 0x0001
	killChannel

LABEL_4D31:
	video offset=CINEMATIC_656, x=[0x1a], y=[0x1b]
	jg [0x16], 0x01, LABEL_4D44
	video offset=CINEMATIC_682, x=[0x1a], y=[0x1b]
	jmp LABEL_4D8F

LABEL_4D44:
	jg [0x16], 0x02, LABEL_4D52
	video offset=CINEMATIC_681, x=[0x1a], y=[0x1b]
	jmp LABEL_4D8F

LABEL_4D52:
	jg [0x16], 0x03, LABEL_4D60
	video offset=CINEMATIC_680, x=[0x1a], y=[0x1b]
	jmp LABEL_4D8F

LABEL_4D60:
	jg [0x16], 0x04, LABEL_4D6E
	video offset=CINEMATIC_679, x=[0x1a], y=[0x1b]
	jmp LABEL_4D8F

LABEL_4D6E:
	jg [0x16], 0x05, LABEL_4D7C
	video offset=CINEMATIC_678, x=[0x1a], y=[0x1b]
	jmp LABEL_4D8F

LABEL_4D7C:
	jg [0x16], 0x06, DRAW_CIN657_AT_X1A_Y1B
	video offset=CINEMATIC_677, x=[0x1a], y=[0x1b]
	jmp LABEL_4D8F
