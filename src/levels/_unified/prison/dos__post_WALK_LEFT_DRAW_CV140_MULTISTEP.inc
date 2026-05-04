LABEL_8E02:
	jne [0xB6], 0x00, LABEL_8E3C
	video type=0, offset=COMMON_VIDEO_141, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_137, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_135, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_134, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_133, x=[0x01], y=[0x02], zoom=0x40
	mov [0x2A], 0x000F
	call SET_VAR04_TO_0000
	jmp LABEL_99AC
LABEL_8E3B:
	db 0x11

LABEL_8E3C:
	video type=0, offset=COMMON_VIDEO_141, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_8CE6
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_8E52
	jmp LABEL_8E3C
LABEL_8E51:
	db 0x11

LABEL_8E52:
	video type=0, offset=COMMON_VIDEO_139, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_POS_MASK], 0x05, LABEL_8CBE

LABEL_8E5E:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8E02
	video type=0, offset=COMMON_VIDEO_163, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8CAE

LABEL_8E74:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8E02
	video type=0, offset=COMMON_VIDEO_140, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8D80

LABEL_8E8A:
	video type=0, offset=COMMON_VIDEO_147, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, WALK_LEFT_DRAW_CV140_MULTISTEP
	sub [0x01], 0x0003
	break
	je [HERO_POS_MASK], 0x05, LABEL_8D6A

LABEL_8EA0:
	video type=0, offset=COMMON_VIDEO_148, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, WALK_LEFT_DRAW_CV140_MULTISTEP
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8D54

LABEL_8EB6:
	video type=0, offset=COMMON_VIDEO_146, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, WALK_LEFT_DRAW_CV140_MULTISTEP
	sub [0x01], 0x0001
	break
	je [HERO_POS_MASK], 0x05, LABEL_8D3E

LABEL_8ECC:
	video type=0, offset=COMMON_VIDEO_145, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8DD9
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8D28

LABEL_8EE2:
	video type=0, offset=COMMON_VIDEO_144, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8DD9
	sub [0x01], 0x0003
	break
	je [HERO_POS_MASK], 0x05, LABEL_8D12

LABEL_8EF8:
	video type=0, offset=COMMON_VIDEO_143, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8DD9
	sub [0x01], 0x0004
	break
	je [HERO_POS_MASK], 0x05, LABEL_8CFC

LABEL_8F0E:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8E02
	video type=0, offset=COMMON_VIDEO_142, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8CE6

LABEL_8F24:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8E02
	video type=0, offset=COMMON_VIDEO_141, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	break
	je [HERO_POS_MASK], 0x05, LABEL_8CD0
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8E02
	jmp LABEL_8E52
	killChannel
	break
	add [0x01], 0x0002
	call LABEL_6EA6

LABEL_8F4C:
	break
	add [0x01], 0x0002
	call LABEL_6E8F

LABEL_8F54:
	break
	add [0x01], 0x0002
	call LABEL_6E78

LABEL_8F5C:
	add [0x01], 0x0001
	jmp HERO_WALK_LEFT_LOOP
	break
	add [0x01], 0x0002
	call LABEL_6E0B

LABEL_8F6B:
	break
	add [0x01], 0x0002
	call LABEL_6DFC

LABEL_8F73:
	break
	add [0x01], 0x0002
	call LABEL_6F1B

LABEL_8F7B:
	add [0x01], 0x0001
	jmp LABEL_9021
LABEL_8F82:
	db 0x11
