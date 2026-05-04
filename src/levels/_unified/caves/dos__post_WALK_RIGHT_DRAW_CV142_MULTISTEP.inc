LABEL_E67E:
	je [HACK_VAR_67], 0x25, LABEL_E6B8
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
	jmp LABEL_F457
LABEL_E6B7:
	db 0x11

LABEL_E6B8:
	video type=0, offset=COMMON_VIDEO_140, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_E6CE
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_E888
	jmp LABEL_E6B8
LABEL_E6CD:
	db 0x11

LABEL_E6CE:
	video type=0, offset=COMMON_VIDEO_140, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_E872

LABEL_E6DE:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E67E
	video type=0, offset=COMMON_VIDEO_163, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_POS_MASK], 0x06, LABEL_E866

LABEL_E6F0:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E67E
	video type=0, offset=COMMON_VIDEO_139, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_E938

LABEL_E706:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E67E
	video type=0, offset=COMMON_VIDEO_141, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_E922

LABEL_E71C:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E67E
	video type=0, offset=COMMON_VIDEO_142, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0004
	break
	je [HERO_POS_MASK], 0x06, LABEL_E90C

LABEL_E732:
	video type=0, offset=COMMON_VIDEO_143, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [0x01], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_E8F6

LABEL_E748:
	video type=0, offset=COMMON_VIDEO_144, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_E8E0

LABEL_E75E:
	video type=0, offset=COMMON_VIDEO_145, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [0x01], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_E8CA

LABEL_E774:
	video type=0, offset=COMMON_VIDEO_146, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E655
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_E8B4

LABEL_E78A:
	video type=0, offset=COMMON_VIDEO_148, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E655
	add [0x01], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_E89E

LABEL_E7A0:
	video type=0, offset=COMMON_VIDEO_147, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_E888
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E67E
	jmp LABEL_E6CE
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
	jmp LABEL_E866
LABEL_E7F8:
	db 0x11

LABEL_E7F9:
	break
	video type=0, offset=COMMON_VIDEO_143, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0003
	break
	jmp LABEL_E816
