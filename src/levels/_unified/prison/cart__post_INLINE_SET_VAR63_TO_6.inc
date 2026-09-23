PRISON_HERO_INPUT_UNARMED_ACTION_UP_DOWN:
	jne [0x0A], 0x00, LABEL_8D4F
	je [0x63], 0x01, LABEL_8D33
	je [0x63], 0x05, LABEL_8D33
	jne [HERO_ACTION_POS_MASK], 0x88, LABEL_8D22
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_9964

LABEL_8D22:
	jne [HERO_ACTION_POS_MASK], 0x84, JUMP_TO_LABEL_8D4F_AT_8D30
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_99F6

JUMP_TO_LABEL_8D4F_AT_8D30:
	jmp LABEL_8D4F

LABEL_8D33:
	jne [HERO_ACTION_POS_MASK], 0x88, LABEL_8D41
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_9636

LABEL_8D41:
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_8D4F
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_99AD

LABEL_8D4F:
	break
	jmp LABEL_8BC5
LABEL_8D53:
	db 0x11

PRISON_HERO_WALK_RIGHT_PHASE_08:
	video type=0, offset=HERO_PRONE_TRANSITION_RIGHT_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=HERO_PRONE_TRANSITION_RIGHT_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0006
	break
	video type=0, offset=HERO_PRONE_TRANSITION_RIGHT_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001
	call SET_VAR04_TO_0008
	break
	video type=0, offset=HERO_PRONE_TRANSITION_RIGHT_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=HERO_PRONE_TRANSITION_RIGHT_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0003
	break
	video type=0, offset=HERO_PRONE_TRANSITION_RIGHT_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0005
	break
	mov [0x2A], 0x000F
	jmp LABEL_8E10
PRISON_HERO_CRAWL_LEFT_PHASE_05:
	db 0x11

LABEL_8D93:
	break
	video type=0, offset=HERO_CRAWL_POSE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0003
	break
	jmp PRISON_HERO_CRAWL_RIGHT_STOP
