LABEL_8BA4:
	jne [0x0A], 0x00, LABEL_8BF1
	je [0x63], 0x01, LABEL_8BD5
	je [0x63], 0x05, LABEL_8BD5
	jne [HERO_ACTION_POS_MASK], 0x88, LABEL_8BC4
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_97F2

LABEL_8BC4:
	jne [HERO_ACTION_POS_MASK], 0x84, JUMP_TO_LABEL_8BF1_AT_8BD2
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_9884

JUMP_TO_LABEL_8BF1_AT_8BD2:
	jmp LABEL_8BF1

LABEL_8BD5:
	jne [HERO_ACTION_POS_MASK], 0x88, LABEL_8BE3
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_94D0

LABEL_8BE3:
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_8BF1
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_983B

LABEL_8BF1:
	break
	jmp LABEL_8A67
LABEL_8BF5:
	db 0x11

LABEL_8BF6:
	video type=0, offset=COMMON_VIDEO_152, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_151, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_150, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	call SET_VAR04_TO_0008
	break
	video type=0, offset=COMMON_VIDEO_161, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_149, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_162, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0005
	break
	mov [0x2A], 0x000F
	jmp LABEL_8CAE
LABEL_8C34:
	db 0x11

LABEL_8C35:
	break
	video type=0, offset=COMMON_VIDEO_147, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0003
	break
	jmp LABEL_8C5E
