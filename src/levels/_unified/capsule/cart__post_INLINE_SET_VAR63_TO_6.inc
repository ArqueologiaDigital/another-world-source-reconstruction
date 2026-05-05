LABEL_B887:
	je [0x63], 0x01, LABEL_B8B3
	je [0x63], 0x05, LABEL_B8B3
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_B8A2
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_C448

LABEL_B8A2:
	jne [HERO_ACTION_POS_MASK], 0x84, JUMP_TO_LABEL_B8D0_AT_B8B0
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_C5AF

JUMP_TO_LABEL_B8D0_AT_B8B0:
	jmp LABEL_B8D0

LABEL_B8B3:
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_B8C2
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_C2D4

LABEL_B8C2:
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_B8D0
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_C59A

LABEL_B8D0:
	break
	jmp LABEL_B74A
	killChannel
	video type=0, offset=COMMON_VIDEO_152, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_151, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_150, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001
	call SET_VAR04_TO_0008
	break
	video type=0, offset=COMMON_VIDEO_161, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_149, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_162, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0005
	break
	mov [0x2A], 0x000F
	jmp LABEL_B98D
LABEL_B913:
	db 0x11

LABEL_B914:
	break
	video type=0, offset=COMMON_VIDEO_147, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0003
	break
	jmp LABEL_B93D
