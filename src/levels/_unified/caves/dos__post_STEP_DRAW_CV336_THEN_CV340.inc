LABEL_F3E0:
	break
	video type=0, offset=COMMON_VIDEO_340, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_F3E0
	break
	sub [HERO_X], 0x0002
	video type=0, offset=COMMON_VIDEO_339, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_F3FD:
	db 0x11

LABEL_F3FE:
	jne [0x0F], 0x00, LABEL_F436
	add [HERO_X], 0x0003
	call LABEL_7EBC
	call LABEL_9A9D
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	add [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_6600
	break
	sub [HERO_X], 0x0002
	call LABEL_9A61
	sub [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_F457
	setup channel=0x17, address=LABEL_7523
