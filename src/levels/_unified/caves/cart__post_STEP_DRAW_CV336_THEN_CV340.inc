LABEL_F469:
	break
	video type=0, offset=COMMON_VIDEO_340, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_F469
	break
	sub [HERO_X], 0x0002
	video type=0, offset=COMMON_VIDEO_339, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_F486:
	db 0x11

LABEL_F487:
	jne [0x0F], 0x00, LABEL_F4BF
	add [HERO_X], 0x0003
	call LABEL_7E33
	call LABEL_9A14
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	add [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_6527
	break
	sub [HERO_X], 0x0002
	call LABEL_99D8
	sub [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_F4E0
	setup channel=0x17, address=LABEL_7462
