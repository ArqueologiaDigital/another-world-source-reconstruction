LABEL_EDB9:
	call LABEL_9715
	je [HERO_ACTION_POS_MASK], 0x84, INLINE_BREAK_035
	jmp LABEL_EDDA
LABEL_EDC5:
	db 0x11

LABEL_EDC6:
	mov [0x2A], 0x0020
	call LABEL_7B5E
	sub [HERO_X], 0x0002
	video type=0, offset=COMMON_VIDEO_326, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	call LABEL_9703

LABEL_EDDA:
	break
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_ED81
	je [HERO_ACTION_POS_MASK], 0x85, LABEL_ED81
	call LABEL_9715
	je [HERO_POS_MASK], 0x04, LABEL_EDDA
	break
	add [HERO_X], 0x0002
	video type=0, offset=COMMON_VIDEO_331, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x63], 0x0002
	mov [0x0A], 0x0003
	jmp HERO_WALK_RIGHT_LOOP
LABEL_EE05:
	db 0x11

LABEL_EE06:
	mov [0x63], 0x0064
	call SET_VAR04_TO_0010
	jne [0x0A], 0x00, LABEL_EDC6
	jne [HACK_VAR_67], 0x6D, LABEL_EE25
	jl [HERO_X], 0x5A, LABEL_EE25
	jl [HERO_X], 0x82, LABEL_1681

LABEL_EE25:
	sub [HERO_X], 0x0002
	video type=0, offset=COMMON_VIDEO_326, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_332, x=[HERO_X], y=[HERO_Y], zoom=0x40

LABEL_EE34:
	break
	video type=0, offset=COMMON_VIDEO_332, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_EE34
	break
	add [HERO_X], 0x0002
	video type=0, offset=COMMON_VIDEO_331, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_EE51:
	db 0x11, 0x57, 0x04, 0xFB, 0x01, 0x02, 0x11, 0x57
	db 0x05, 0xEF, 0x01, 0x02, 0x11, 0xFF, 0xFF, 0xFF
	FILL(4511, 0xFF)
