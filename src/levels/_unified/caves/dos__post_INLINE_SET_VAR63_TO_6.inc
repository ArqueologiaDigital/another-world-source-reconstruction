CAVES_HERO_INPUT_RUN_JUMP_RIGHT_DISPATCH:
	je [0x63], 0x01, LABEL_E5F4
	je [0x63], 0x05, LABEL_E5F4
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_E5E3
	mov [0x63], 0x0064
	setup channel=0x14, address=HERO_JUMP_RIGHT_FROM_RUN

LABEL_E5E3:
	jne [HERO_ACTION_POS_MASK], 0x84, JUMP_TO_LABEL_E611_AT_E5F1
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_F311

JUMP_TO_LABEL_E611_AT_E5F1:
	jmp LABEL_E611

LABEL_E5F4:
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_E603
	mov [0x63], 0x0064
	setup channel=0x14, address=HERO_JUMP_LEFT_FROM_RUN

LABEL_E603:
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_E611
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_F2F9

LABEL_E611:
	break
	jmp SETUP_CHAN_14_BY_VAR63
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
	jmp CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L9
LABEL_E654:
	db 0x11

CAVES_WALK_RIGHT_DRAW_CV142_MULTISTEP_L4:
	break
	video type=0, offset=CV_48D8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0003
	break
	jmp HERO_PRONE_RISE_RIGHT
