LABEL_4E94:
	break
	add [0x14], 0x0001
	add [0x17], 0x0002
	djnz [0x16], LABEL_4E94
	mov [PAUSE_SLICES], 0x0009
	break
	add [0x17], 0x0001
	mov [PAUSE_SLICES], 0x0007
	break
	mov [0x16], 0x0006
	add [0x17], 0x0000

LABEL_4EB7:
	break
	sub [0x14], 0x0001
	sub [0x17], 0x0002
	djnz [0x16], LABEL_4EB7
	mov [PAUSE_SLICES], 0x0009
	break
	sub [0x17], 0x0001
	mov [PAUSE_SLICES], 0x0007
	break
	add [0x17], 0x0000
	jmp FILL_PFF_PLAY_SFX_0061_AT_C0D45EFA
LABEL_4ED9:
	db 0x11

LABEL_4EDA:
	setup channel=0x3C, address=LABEL_88F6
	break
	setPalette 0x09
	fill page=0xFF, color=0x00
	mov [0x15], 0x0014

LABEL_4EE9:
	video offset=CINEMATIC_PRISON_PRISONER_BEHIND_BARS, x=[0x14], y=100
	video offset=CINEMATIC_635, x=[0x17], y=100
	video offset=CINEMATIC_PRISON_CELL_BARS, x=[0x17], y=100
	break
	djnz [0x15], LABEL_4EE9
	play id=0x0061, freq=0x07, vol=0x07, channel=0x00
	video offset=CINEMATIC_PRISON_PRISONER_BEHIND_BARS, x=[0x14], y=100
	video offset=CINEMATIC_635, x=[0x17], y=100
	video offset=CINEMATIC_PRISON_CELL_BARS, x=[0x17], y=100
	setup channel=0x3C, address=LABEL_069F
	setup channel=0x01, address=PRISON_WAKE_CLOSEUP_PAINT_BACKDROP
	setup channel=0x02, address=INIT_VARS_16_17
	setup channel=0x03, address=PRISON_WAKE_CLOSEUP_DRAW_FRAME
	killChannel

LABEL_4F23:
	mov [0x14], 0x0042
	add [0x14], [0x15]
	add [0x14], [0x15]
	add [0x14], [0x15]
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_NECK_0, x=172, y=110, zoom=[0x14]
	sub [0x14], [0x15]
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_HEAD_0, x=183, y=40, zoom=[0x14]
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_ARM_LEFT_0, x=88, y=146, zoom=[0x14]
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_ARM_RIGHT_0, x=289, y=148, zoom=[0x14]
	mov [0x14], 0x0040
	add [0x14], [0x15]
	add [0x14], [0x15]
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_NECK_1, x=172, y=110, zoom=[0x14]
	sub [0x14], [0x15]
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_HEAD_1, x=182, y=40, zoom=[0x14]
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_ARM_LEFT_1, x=88, y=147, zoom=[0x14]
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_ARM_RIGHT_1, x=289, y=147, zoom=[0x14]
	mov [0x14], 0x0040
	sub [0x14], [0x15]
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_NECK_2, x=171, y=110, zoom=[0x14]
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_HEAD_2, x=182, y=40, zoom=[0x14]
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_ARM_LEFT_2, x=88, y=146, zoom=[0x14]
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_ARM_RIGHT_2, x=289, y=147, zoom=[0x14]
	mov [0x14], 0x0040
	add [0x14], [0x15]
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_ARM_RIGHT_EDGE_0, x=272, y=133, zoom=[0x14]
	sub [0x14], [0x15]
	sub [0x14], [0x15]
	sub [0x14], [0x15]
	sub [0x14], [0x15]
	sub [0x14], [0x15]
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_ARM_RIGHT_EDGE_1, x=272, y=133, zoom=[0x14]
	jne [0x15], 0x00, LABEL_4FBE
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_FACE_DETAIL_0, x=160, y=100
	jmp LABEL_4FEF

LABEL_4FBE:
	jne [0x15], 0x01, LABEL_4FCB
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_FACE_DETAIL_1, x=160, y=100
	jmp LABEL_4FEF

LABEL_4FCB:
	jne [0x15], 0x02, LABEL_4FD8
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_FACE_DETAIL_2, x=160, y=100
	jmp LABEL_4FEF

LABEL_4FD8:
	jne [0x15], 0x03, LABEL_4FE5
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_FACE_DETAIL_3, x=160, y=100
	jmp LABEL_4FEF

LABEL_4FE5:
	jne [0x15], 0x04, LABEL_4FEF
	video offset=CINEMATIC_PRISON_WAKE_FIGURE_FACE_DETAIL_4, x=160, y=100

LABEL_4FEF:
	break
	jmp LABEL_4F23
LABEL_4FF3:
	db 0x11
