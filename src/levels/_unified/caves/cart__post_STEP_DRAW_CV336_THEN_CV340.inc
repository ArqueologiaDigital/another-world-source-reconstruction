LABEL_F469:
	break
	video type=0, offset=COMMON_VIDEO_340, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_F469
	break
	sub [0x01], 0x0002
	video type=0, offset=COMMON_VIDEO_339, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_F486:
	db 0x11

LABEL_F487:
	jne [0x0F], 0x00, LABEL_F4BF
	add [0x01], 0x0003
	call LABEL_7E33
	call LABEL_9A14
	mov [0x21], [0x01]
	mov [0x27], [0x02]
	add [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_6527
	break
	sub [0x01], 0x0002
	call LABEL_99D8
	sub [0x01], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_F4E0
	setup channel=0x17, address=LABEL_7462
