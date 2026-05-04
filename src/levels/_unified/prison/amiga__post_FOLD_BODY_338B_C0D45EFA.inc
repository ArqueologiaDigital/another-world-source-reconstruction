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
	video type=1, offset=CINEMATIC_634, x=[0x14], y=100, zoom=0x40
	video type=1, offset=CINEMATIC_635, x=[0x17], y=100, zoom=0x40
	video type=1, offset=CINEMATIC_636, x=[0x17], y=100, zoom=0x40
	break
	djnz [0x15], LABEL_4EE9
	play id=0x0061, freq=0x07, vol=0x07, channel=0x00
	video type=1, offset=CINEMATIC_634, x=[0x14], y=100, zoom=0x40
	video type=1, offset=CINEMATIC_635, x=[0x17], y=100, zoom=0x40
	video type=1, offset=CINEMATIC_636, x=[0x17], y=100, zoom=0x40
	setup channel=0x3C, address=LABEL_069F
	setup channel=0x01, address=DRAW_CIN_683_TO_685_3F_AT_1EB7324B
	setup channel=0x02, address=INIT_VARS_16_17
	setup channel=0x03, address=LABEL_4D31
	killChannel

LABEL_4F23:
	mov [0x14], 0x0042
	add [0x14], [0x15]
	add [0x14], [0x15]
	add [0x14], [0x15]
	video type=1, offset=CINEMATIC_637, x=172, y=110, zoom=[0x14]
	sub [0x14], [0x15]
	video type=1, offset=CINEMATIC_638, x=183, y=40, zoom=[0x14]
	video type=1, offset=CINEMATIC_639, x=88, y=146, zoom=[0x14]
	video type=1, offset=CINEMATIC_640, x=289, y=148, zoom=[0x14]
	mov [0x14], 0x0040
	add [0x14], [0x15]
	add [0x14], [0x15]
	video type=1, offset=CINEMATIC_641, x=172, y=110, zoom=[0x14]
	sub [0x14], [0x15]
	video type=1, offset=CINEMATIC_642, x=182, y=40, zoom=[0x14]
	video type=1, offset=CINEMATIC_643, x=88, y=147, zoom=[0x14]
	video type=1, offset=CINEMATIC_644, x=289, y=147, zoom=[0x14]
	mov [0x14], 0x0040
	sub [0x14], [0x15]
	video type=1, offset=CINEMATIC_645, x=171, y=110, zoom=[0x14]
	video type=1, offset=CINEMATIC_646, x=182, y=40, zoom=[0x14]
	video type=1, offset=CINEMATIC_647, x=88, y=146, zoom=[0x14]
	video type=1, offset=CINEMATIC_648, x=289, y=147, zoom=[0x14]
	mov [0x14], 0x0040
	add [0x14], [0x15]
	video type=1, offset=CINEMATIC_649, x=272, y=133, zoom=[0x14]
	sub [0x14], [0x15]
	sub [0x14], [0x15]
	sub [0x14], [0x15]
	sub [0x14], [0x15]
	sub [0x14], [0x15]
	video type=1, offset=CINEMATIC_650, x=272, y=133, zoom=[0x14]
	jne [0x15], 0x00, LABEL_4FBE
	video type=1, offset=CINEMATIC_655, x=160, y=100
	jmp LABEL_4FEF

LABEL_4FBE:
	jne [0x15], 0x01, LABEL_4FCB
	video type=1, offset=CINEMATIC_654, x=160, y=100
	jmp LABEL_4FEF

LABEL_4FCB:
	jne [0x15], 0x02, LABEL_4FD8
	video type=1, offset=CINEMATIC_653, x=160, y=100
	jmp LABEL_4FEF

LABEL_4FD8:
	jne [0x15], 0x03, LABEL_4FE5
	video type=1, offset=CINEMATIC_652, x=160, y=100
	jmp LABEL_4FEF

LABEL_4FE5:
	jne [0x15], 0x04, LABEL_4FEF
	video type=1, offset=CINEMATIC_651, x=160, y=100

LABEL_4FEF:
	break
	jmp LABEL_4F23
LABEL_4FF3:
	db 0x11
