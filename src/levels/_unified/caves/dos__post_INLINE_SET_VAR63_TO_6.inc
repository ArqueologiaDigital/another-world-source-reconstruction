LABEL_E5C8:
	je [0x63], 0x01, LABEL_E5F4
	je [0x63], 0x05, LABEL_E5F4
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_E5E3
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_F195

LABEL_E5E3:
	jne [HERO_ACTION_POS_MASK], 0x84, JUMP_TO_LABEL_E611_AT_E5F1
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_F311

JUMP_TO_LABEL_E611_AT_E5F1:
	jmp LABEL_E611

LABEL_E5F4:
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_E603
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_F021

LABEL_E603:
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_E611
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_F2F9

LABEL_E611:
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
	jmp LABEL_E6CE
LABEL_E654:
	db 0x11

LABEL_E655:
	break
	video type=0, offset=COMMON_VIDEO_147, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0003
	break
	jmp LABEL_E67E
