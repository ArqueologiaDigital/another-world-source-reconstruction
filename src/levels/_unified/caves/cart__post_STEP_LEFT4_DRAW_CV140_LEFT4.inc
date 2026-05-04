LABEL_E89F:
	je [HACK_VAR_67], 0x25, LABEL_E8D9
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
	jmp LABEL_F40F
LABEL_E8D8:
	db 0x11

LABEL_E8D9:
	video type=0, offset=COMMON_VIDEO_141, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_E78F
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_E8EF
	jmp LABEL_E8D9
LABEL_E8EE:
	db 0x11

LABEL_E8EF:
	video type=0, offset=COMMON_VIDEO_139, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_POS_MASK], 0x05, LABEL_E767

LABEL_E8FB:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E89F
	video type=0, offset=COMMON_VIDEO_163, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_E757

LABEL_E911:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E89F
	video type=0, offset=COMMON_VIDEO_140, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_E829

LABEL_E927:
	video type=0, offset=COMMON_VIDEO_147, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, STEP_LEFT4_DRAW_CV140_LEFT4
	sub [0x01], 0x0003
	break
	je [HERO_POS_MASK], 0x05, LABEL_E813

LABEL_E93D:
	video type=0, offset=COMMON_VIDEO_148, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, STEP_LEFT4_DRAW_CV140_LEFT4
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_E7FD

LABEL_E953:
	video type=0, offset=COMMON_VIDEO_146, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, STEP_LEFT4_DRAW_CV140_LEFT4
	sub [0x01], 0x0001
	break
	je [HERO_POS_MASK], 0x05, LABEL_E7E7

LABEL_E969:
	video type=0, offset=COMMON_VIDEO_145, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E882
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_E7D1

LABEL_E97F:
	video type=0, offset=COMMON_VIDEO_144, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E882
	sub [0x01], 0x0003
	break
	je [HERO_POS_MASK], 0x05, LABEL_E7BB

LABEL_E995:
	video type=0, offset=COMMON_VIDEO_143, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E882
	sub [0x01], 0x0004
	break
	je [HERO_POS_MASK], 0x05, LABEL_E7A5

LABEL_E9AB:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E89F
	video type=0, offset=COMMON_VIDEO_142, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_E78F

LABEL_E9C1:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E89F
	video type=0, offset=COMMON_VIDEO_141, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	break
	je [HERO_POS_MASK], 0x05, LABEL_E779
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E89F
	jmp LABEL_E8EF
	killChannel
	break
	add [0x01], 0x0002
	call LABEL_9E2E

LABEL_E9E9:
	break
	add [0x01], 0x0002
	call LABEL_9E17

LABEL_E9F1:
	break
	add [0x01], 0x0002
	call LABEL_9E00

LABEL_E9F9:
	add [0x01], 0x0001
	jmp HERO_WALK_LEFT_LOOP
	break
	add [0x01], 0x0002
	call LABEL_9D8D

LABEL_EA08:
	break
	add [0x01], 0x0002
	call LABEL_9D7E

LABEL_EA10:
	break
	add [0x01], 0x0002
	call LABEL_9EA9

LABEL_EA18:
	add [0x01], 0x0001
	jmp LABEL_EAB8
LABEL_EA1F:
	db 0x11
