LABEL_B7A3:
	je [0x63], 0x01, LABEL_B7CF
	je [0x63], 0x05, LABEL_B7CF
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_B7BE
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_C364

LABEL_B7BE:
	jne [HERO_ACTION_POS_MASK], 0x84, JUMP_TO_LABEL_B7EC_AT_B7CC
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_C4CB

JUMP_TO_LABEL_B7EC_AT_B7CC:
	jmp LABEL_B7EC

LABEL_B7CF:
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_B7DE
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_C1F0

LABEL_B7DE:
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_B7EC
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_C4B6

LABEL_B7EC:
	break
	jmp LABEL_B666
	killChannel
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
	jmp LABEL_B8A9
LABEL_B82F:
	db 0x11

LABEL_B830:
	break
	video type=0, offset=COMMON_VIDEO_147, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0003
	break
	jmp LABEL_B859
