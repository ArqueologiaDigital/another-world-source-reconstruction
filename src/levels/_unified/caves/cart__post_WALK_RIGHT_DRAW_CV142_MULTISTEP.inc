LABEL_E707:
	je [HACK_VAR_67], 0x25, LABEL_E741
	video type=0, offset=COMMON_VIDEO_140, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_149, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_150, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_151, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_152, x=[0x01], y=[0x02], zoom=0x40
	mov [0x2A], 0x000F
	call SET_VAR04_TO_0010
	jmp LABEL_F4E0
LABEL_E740:
	db 0x11

LABEL_E741:
	video type=0, offset=COMMON_VIDEO_140, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_E757
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_E911
	jmp LABEL_E741
LABEL_E756:
	db 0x11

LABEL_E757:
	video type=0, offset=COMMON_VIDEO_140, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_E8FB

LABEL_E767:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E707
	video type=0, offset=COMMON_VIDEO_163, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_POS_MASK], 0x06, LABEL_E8EF

LABEL_E779:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E707
	video type=0, offset=COMMON_VIDEO_139, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_E9C1

LABEL_E78F:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E707
	video type=0, offset=COMMON_VIDEO_141, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_E9AB

LABEL_E7A5:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E707
	video type=0, offset=COMMON_VIDEO_142, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0004
	break
	je [HERO_POS_MASK], 0x06, LABEL_E995

LABEL_E7BB:
	video type=0, offset=COMMON_VIDEO_143, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [0x01], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_E97F

LABEL_E7D1:
	video type=0, offset=COMMON_VIDEO_144, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_E969

LABEL_E7E7:
	video type=0, offset=COMMON_VIDEO_145, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [0x01], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_E953

LABEL_E7FD:
	video type=0, offset=COMMON_VIDEO_146, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E6DE
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_E93D

LABEL_E813:
	video type=0, offset=COMMON_VIDEO_148, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E6DE
	add [0x01], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_E927

LABEL_E829:
	video type=0, offset=COMMON_VIDEO_147, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_E911
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E707
	jmp LABEL_E757
	killChannel
	video type=0, offset=COMMON_VIDEO_133, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_134, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_135, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	call SET_VAR04_TO_0008
	break
	video type=0, offset=COMMON_VIDEO_136, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_137, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_138, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0005
	break
	mov [0x2A], 0x000F
	jmp LABEL_E8EF
LABEL_E881:
	db 0x11

LABEL_E882:
	break
	video type=0, offset=COMMON_VIDEO_143, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0003
	break
	jmp LABEL_E89F
