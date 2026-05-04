LABEL_E651:
	je [0x63], 0x01, LABEL_E67D
	je [0x63], 0x05, LABEL_E67D
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_E66C
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_F21E

LABEL_E66C:
	jne [HERO_ACTION_POS_MASK], 0x84, JUMP_TO_LABEL_E69A_AT_E67A
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_F39A

JUMP_TO_LABEL_E69A_AT_E67A:
	jmp LABEL_E69A

LABEL_E67D:
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_E68C
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_F0AA

LABEL_E68C:
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_E69A
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_F382

LABEL_E69A:
	break
	jmp SETUP_CHAN_14_BY_VAR63
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
	jmp LABEL_E757
LABEL_E6DD:
	db 0x11

LABEL_E6DE:
	break
	video type=0, offset=COMMON_VIDEO_147, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0003
	break
	jmp LABEL_E707
