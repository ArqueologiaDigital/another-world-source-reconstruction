CAPSULE_HERO_INPUT_RUN_JUMP_RIGHT_DISPATCH:
	je [0x63], 0x01, LABEL_B7CF
	je [0x63], 0x05, LABEL_B7CF
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_B7BE
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_C364

LABEL_B7BE:
	jne [HERO_ACTION_POS_MASK], 0x84, JUMP_TO_LABEL_B7EC_AT_B7CC
	mov [0x63], 0x0064
	setup channel=0x14, address=HERO_FIRE_SHOT_ENTRY_FACING_RIGHT

JUMP_TO_LABEL_B7EC_AT_B7CC:
	jmp CAPSULE_BREAK_JMP_TO_B666_THEN_KILL

LABEL_B7CF:
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_B7DE
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_C1F0

LABEL_B7DE:
	jne [HERO_ACTION_POS_MASK], 0x84, CAPSULE_BREAK_JMP_TO_B666_THEN_KILL
	mov [0x63], 0x0064
	setup channel=0x14, address=HERO_FIRE_SHOT_ENTRY_FACING_LEFT

CAPSULE_BREAK_JMP_TO_B666_THEN_KILL:
	break
	jmp LABEL_B666
	killChannel
	video type=0, offset=CV_448C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=CV_4528, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0006
	break
	video type=0, offset=CV_45C0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001
	call SET_VAR04_TO_0008
	break
	video type=0, offset=CV_4650, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=CV_46D4, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0003
	break
	video type=0, offset=CV_4C40, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0005
	break
	mov [0x2A], 0x000F
	jmp CAPSULE_WALK_LEFT_DRAW_CV140_MULTISTEP_L9
LABEL_B82F:
	db 0x11

CAPSULE_WALK_RIGHT_DRAW_CV142_MULTISTEP_L5:
	break
	video type=0, offset=CV_48D8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0003
	break
	jmp HERO_WALK_RIGHT_STOP_TO_GUN_READY
