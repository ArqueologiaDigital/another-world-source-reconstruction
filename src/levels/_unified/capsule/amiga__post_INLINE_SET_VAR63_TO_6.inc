LABEL_8C3F:
	je [0x63], 0x01, LABEL_8C6B
	je [0x63], 0x05, LABEL_8C6B
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_8C5A
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_9716

LABEL_8C5A:
	jne [HERO_ACTION_POS_MASK], 0x84, JUMP_TO_LABEL_8C88_AT_8C68
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_9877

JUMP_TO_LABEL_8C88_AT_8C68:
	jmp LABEL_8C88

LABEL_8C6B:
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_8C7A
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_95B4

LABEL_8C7A:
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_8C88
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_9862

LABEL_8C88:
	break
	jmp LABEL_8B45
LABEL_8C8C:
	db 0x11, 0x57, 0x22, 0x46, 0x01, 0x02, 0x06, 0x57
	db 0x22, 0x94, 0x01, 0x02, 0x03, 0x01, 0x00, 0x06
	db 0x06, 0x57, 0x22, 0xE0, 0x01, 0x02, 0x03, 0x01
	db 0x00, 0x01, 0x04, 0x87, 0x4B, 0x06, 0x57, 0x23
	db 0x28, 0x01, 0x02, 0x06, 0x57, 0x23, 0x6A, 0x01
	db 0x02, 0x03, 0x01, 0x00, 0x03, 0x06, 0x57, 0x26
	db 0x20, 0x01, 0x02, 0x03, 0x01, 0x00, 0x05, 0x06
	db 0x00, 0x2A, 0x00, 0x0F, 0x07, 0x8D, 0x45, 0x11

LABEL_8CCC:
	break
	video type=0, offset=COMMON_VIDEO_028, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0003
	break
	jmp LABEL_8CF5

LABEL_8CDA:
	add [HERO_X], 0x0002
	add [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_023, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	add [HERO_X], 0x0001
	add [HERO_X], 0x0002
	break

LABEL_8CF5:
	je [HACK_VAR_67], 0x25, LABEL_8D2F
	video type=0, offset=COMMON_VIDEO_021, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_030, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_031, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_032, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_033, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x2A], 0x000F
	call SET_VAR04_TO_0010
	jmp LABEL_998F
LABEL_8D2E:
	db 0x11

LABEL_8D2F:
	video type=0, offset=COMMON_VIDEO_021, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_8D45
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_8F0B
	jmp LABEL_8D2F
LABEL_8D44:
	db 0x11

LABEL_8D45:
	video type=0, offset=COMMON_VIDEO_021, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8EF5

LABEL_8D55:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8CF5
	video type=0, offset=COMMON_VIDEO_086, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_POS_MASK], 0x06, LABEL_8EE9

LABEL_8D67:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8CF5
	video type=0, offset=COMMON_VIDEO_020, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_8FBB

LABEL_8D7D:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8CF5
	video type=0, offset=COMMON_VIDEO_022, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8FA5

LABEL_8D93:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8CF5
	video type=0, offset=COMMON_VIDEO_023, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	break
	je [HERO_POS_MASK], 0x06, LABEL_8F8F

LABEL_8DA9:
	video type=0, offset=COMMON_VIDEO_024, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8CDA
	add [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_8F79

LABEL_8DBF:
	video type=0, offset=COMMON_VIDEO_025, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8CDA
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8F63

LABEL_8DD5:
	video type=0, offset=COMMON_VIDEO_026, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8CDA
	add [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_8F4D

LABEL_8DEB:
	video type=0, offset=COMMON_VIDEO_027, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8CCC
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8F37

LABEL_8E01:
	video type=0, offset=COMMON_VIDEO_029, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8CCC
	add [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_8F21

LABEL_8E17:
	video type=0, offset=COMMON_VIDEO_028, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8F0B
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8CF5
	jmp LABEL_8D45
LABEL_8E30:
	db 0x11, 0x57, 0x2B, 0xE2, 0x01, 0x02, 0x06, 0x57
	db 0x2C, 0x3C, 0x01, 0x02, 0x03, 0x01, 0xFF, 0xFA
	db 0x06, 0x57, 0x2C, 0xA2, 0x01, 0x02, 0x03, 0x01
	db 0xFF, 0xFF, 0x04, 0x87, 0x4B, 0x06, 0x57, 0x2D
	db 0x04, 0x01, 0x02, 0x06, 0x57, 0x2D, 0x56, 0x01
	db 0x02, 0x03, 0x01, 0xFF, 0xFD, 0x06, 0x57, 0x2D
	db 0xA6, 0x01, 0x02, 0x03, 0x01, 0xFF, 0xFB, 0x06
	db 0x00, 0x2A, 0x00, 0x0F, 0x07, 0x8E, 0xE9, 0x11

LABEL_8E70:
	break
	video type=0, offset=COMMON_VIDEO_024, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0003
	break
	jmp LABEL_8E99

LABEL_8E7E:
	sub [HERO_X], 0x0002
	sub [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_021, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	sub [HERO_X], 0x0001
	sub [HERO_X], 0x0002
	break

LABEL_8E99:
	je [HACK_VAR_67], 0x25, LABEL_8ED3
	video type=0, offset=COMMON_VIDEO_022, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_018, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_016, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_015, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_014, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x2A], 0x000F
	call SET_VAR04_TO_0000
	jmp LABEL_98EF
LABEL_8ED2:
	db 0x11

LABEL_8ED3:
	video type=0, offset=COMMON_VIDEO_022, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_8D7D
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_8EE9
	jmp LABEL_8ED3
LABEL_8EE8:
	db 0x11

LABEL_8EE9:
	video type=0, offset=COMMON_VIDEO_020, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_POS_MASK], 0x05, LABEL_8D55

LABEL_8EF5:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8E99
	video type=0, offset=COMMON_VIDEO_086, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8D45

LABEL_8F0B:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8E99
	video type=0, offset=COMMON_VIDEO_021, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8E17

LABEL_8F21:
	video type=0, offset=COMMON_VIDEO_028, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8E7E
	sub [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x05, LABEL_8E01

LABEL_8F37:
	video type=0, offset=COMMON_VIDEO_029, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8E7E
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8DEB

LABEL_8F4D:
	video type=0, offset=COMMON_VIDEO_027, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8E7E
	sub [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x05, LABEL_8DD5

LABEL_8F63:
	video type=0, offset=COMMON_VIDEO_026, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8E70
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8DBF

LABEL_8F79:
	video type=0, offset=COMMON_VIDEO_025, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8E70
	sub [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x05, LABEL_8DA9

LABEL_8F8F:
	video type=0, offset=COMMON_VIDEO_024, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8E70
	sub [HERO_X], 0x0004
	break
	je [HERO_POS_MASK], 0x05, LABEL_8D93

LABEL_8FA5:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8E99
	video type=0, offset=COMMON_VIDEO_023, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8D7D

LABEL_8FBB:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8E99
	video type=0, offset=COMMON_VIDEO_022, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x05, LABEL_8D67
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8E99
	jmp LABEL_8EE9
LABEL_8FDA:
	db 0x11, 0x06, 0x03, 0x01, 0x00, 0x02, 0x04, 0x7B
	db 0x6D

LABEL_8FE3:
	break
	add [HERO_X], 0x0002
	call LABEL_7B56

LABEL_8FEB:
	break
	add [HERO_X], 0x0002
	call LABEL_7B3F

LABEL_8FF3:
	add [HERO_X], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_8FFA:
	db 0x06, 0x03, 0x01, 0x00, 0x02, 0x04, 0x7A, 0xCC

LABEL_9002:
	break
	add [HERO_X], 0x0002
	call LABEL_7ABD

LABEL_900A:
	break
	add [HERO_X], 0x0002
	call LABEL_7BE8

LABEL_9012:
	add [HERO_X], 0x0001
	jmp LABEL_9080
LABEL_9019:
	db 0x11
