CAPSULE_HERO_INPUT_RUN_JUMP_RIGHT_DISPATCH:
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
	jmp CAPSULE_WALK_LEFT_DRAW_CV140_MULTISTEP_L9
LABEL_B913:
	db 0x11

CAPSULE_WALK_RIGHT_DRAW_CV142_MULTISTEP_L5:
	break
	video type=0, offset=HERO_CRAWL_POSE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0003
	break
	jmp HERO_WALK_RIGHT_STOP_TO_GUN_READY
