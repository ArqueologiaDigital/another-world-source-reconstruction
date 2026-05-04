LABEL_B859:
	je [HACK_VAR_67], 0x25, LABEL_B893
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
	jmp LABEL_C5E3
LABEL_B892:
	db 0x11

LABEL_B893:
	video type=0, offset=COMMON_VIDEO_140, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_B8A9
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_BA6F
	jmp LABEL_B893
LABEL_B8A8:
	db 0x11

LABEL_B8A9:
	video type=0, offset=COMMON_VIDEO_140, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_BA59

LABEL_B8B9:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_B859
	video type=0, offset=COMMON_VIDEO_163, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_POS_MASK], 0x06, LABEL_BA4D

LABEL_B8CB:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_B859
	video type=0, offset=COMMON_VIDEO_139, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_BB1F

LABEL_B8E1:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_B859
	video type=0, offset=COMMON_VIDEO_141, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_BB09

LABEL_B8F7:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_B859
	video type=0, offset=COMMON_VIDEO_142, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0004
	break
	je [HERO_POS_MASK], 0x06, LABEL_BAF3

LABEL_B90D:
	video type=0, offset=COMMON_VIDEO_143, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [0x01], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_BADD

LABEL_B923:
	video type=0, offset=COMMON_VIDEO_144, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_BAC7

LABEL_B939:
	video type=0, offset=COMMON_VIDEO_145, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [0x01], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_BAB1

LABEL_B94F:
	video type=0, offset=COMMON_VIDEO_146, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_B830
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_BA9B

LABEL_B965:
	video type=0, offset=COMMON_VIDEO_148, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_B830
	add [0x01], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_BA85

LABEL_B97B:
	video type=0, offset=COMMON_VIDEO_147, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_BA6F
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_B859
	jmp LABEL_B8A9
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
	jmp LABEL_BA4D
LABEL_B9D3:
	db 0x11

LABEL_B9D4:
	break
	video type=0, offset=COMMON_VIDEO_143, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0003
	break
	jmp LABEL_B9FD
