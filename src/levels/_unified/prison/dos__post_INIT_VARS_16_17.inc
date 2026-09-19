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

; mirrors CAVES/CAPSULE
PRISON_DRAW_CIN_656_AND_682_OR_VARIANT_PER_VAR16:
	video offset=CINEMATIC_656, x=[0x1a], y=[0x1b]
	jg [0x16], 0x01, PRISON_WAKE_CLOSEUP_PUPIL_UPTO_02
	video offset=CINEMATIC_682, x=[0x1a], y=[0x1b]
	jmp LABEL_4E38

PRISON_WAKE_CLOSEUP_PUPIL_UPTO_02:
	jg [0x16], 0x02, LABEL_4DFB
	video offset=CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_0, x=[0x1a], y=[0x1b]
	jmp LABEL_4E38

LABEL_4DFB:
	jg [0x16], 0x03, LABEL_4E09
	video offset=CINEMATIC_680, x=[0x1a], y=[0x1b]
	jmp LABEL_4E38

LABEL_4E09:
	jg [0x16], 0x04, LABEL_4E17
	video offset=CINEMATIC_679, x=[0x1a], y=[0x1b]
	jmp LABEL_4E38

LABEL_4E17:
	jg [0x16], 0x05, PRISON_WAKE_CLOSEUP_PUPIL_UPTO_06
	video offset=CINEMATIC_678, x=[0x1a], y=[0x1b]
	jmp LABEL_4E38

PRISON_WAKE_CLOSEUP_PUPIL_UPTO_06:
	jg [0x16], 0x06, PRISON_WAKE_CLOSEUP_PUPIL_WIDEST
	video offset=CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_1, x=[0x1a], y=[0x1b]
	jmp LABEL_4E38
