LABEL_8A3E:
	jne [0x0A], 0x00, LABEL_8A8B
	je [0x63], 0x01, LABEL_8A6F
	je [0x63], 0x05, LABEL_8A6F
	jne [HERO_ACTION_POS_MASK], 0x88, LABEL_8A5E
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_9598

LABEL_8A5E:
	jne [HERO_ACTION_POS_MASK], 0x84, JUMP_TO_LABEL_8A8B_AT_8A6C
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_962A

JUMP_TO_LABEL_8A8B_AT_8A6C:
	jmp LABEL_8A8B

LABEL_8A6F:
	jne [HERO_ACTION_POS_MASK], 0x88, LABEL_8A7D
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_92A2

LABEL_8A7D:
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_8A8B
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_95E1

LABEL_8A8B:
	break
	jmp LABEL_8944
LABEL_8A8F:
	db 0x11

LABEL_8A90:
	video type=0, offset=COMMON_VIDEO_033, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_032, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_031, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001
	call SET_VAR04_TO_0008
	break
	video type=0, offset=COMMON_VIDEO_084, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_030, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_085, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0005
	break
	mov [0x2A], 0x000F
	jmp LABEL_8B48
LABEL_8ACE:
	db 0x11

LABEL_8ACF:
	break
	video type=0, offset=COMMON_VIDEO_028, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0003
	break
	jmp LABEL_8AF8

LABEL_8ADD:
	add [HERO_X], 0x0002
	add [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_023, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	add [HERO_X], 0x0001
	add [HERO_X], 0x0002
	break

LABEL_8AF8:
	jne [0xB6], 0x00, LABEL_8B32
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
	jmp LABEL_982D
LABEL_8B31:
	db 0x11

LABEL_8B32:
	video type=0, offset=COMMON_VIDEO_021, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_8B48
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_8D0E
	jmp LABEL_8B32
LABEL_8B47:
	db 0x11

LABEL_8B48:
	video type=0, offset=COMMON_VIDEO_021, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8CF8

LABEL_8B58:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8AF8
	video type=0, offset=COMMON_VIDEO_086, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_POS_MASK], 0x06, LABEL_8CEC

LABEL_8B6A:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8AF8
	video type=0, offset=COMMON_VIDEO_020, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_8DBE

LABEL_8B80:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8AF8
	video type=0, offset=COMMON_VIDEO_022, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8DA8

LABEL_8B96:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8AF8
	video type=0, offset=COMMON_VIDEO_023, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	break
	je [HERO_POS_MASK], 0x06, LABEL_8D92

LABEL_8BAC:
	video type=0, offset=COMMON_VIDEO_024, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8ADD
	add [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_8D7C

LABEL_8BC2:
	video type=0, offset=COMMON_VIDEO_025, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8ADD
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8D66

LABEL_8BD8:
	video type=0, offset=COMMON_VIDEO_026, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8ADD
	add [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_8D50

LABEL_8BEE:
	video type=0, offset=COMMON_VIDEO_027, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8ACF
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8D3A

LABEL_8C04:
	video type=0, offset=COMMON_VIDEO_029, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8ACF
	add [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_8D24

LABEL_8C1A:
	video type=0, offset=COMMON_VIDEO_028, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8D0E
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8AF8
	jmp LABEL_8B48
LABEL_8C33:
	db 0x11

LABEL_8C34:
	video type=0, offset=COMMON_VIDEO_014, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_015, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_016, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	call SET_VAR04_TO_0008
	break
	video type=0, offset=COMMON_VIDEO_017, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_018, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_019, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0005
	break
	mov [0x2A], 0x000F
	jmp LABEL_8CEC
LABEL_8C72:
	db 0x11

LABEL_8C73:
	break
	video type=0, offset=COMMON_VIDEO_024, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0003
	break
	jmp LABEL_8C9C

LABEL_8C81:
	sub [HERO_X], 0x0002
	sub [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_021, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	sub [HERO_X], 0x0001
	sub [HERO_X], 0x0002
	break

LABEL_8C9C:
	jne [0xB6], 0x00, LABEL_8CD6
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
	jmp LABEL_9752
LABEL_8CD5:
	db 0x11

LABEL_8CD6:
	video type=0, offset=COMMON_VIDEO_022, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_8B80
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_8CEC
	jmp LABEL_8CD6
LABEL_8CEB:
	db 0x11

LABEL_8CEC:
	video type=0, offset=COMMON_VIDEO_020, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_POS_MASK], 0x05, LABEL_8B58

LABEL_8CF8:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8C9C
	video type=0, offset=COMMON_VIDEO_086, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8B48

LABEL_8D0E:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8C9C
	video type=0, offset=COMMON_VIDEO_021, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8C1A

LABEL_8D24:
	video type=0, offset=COMMON_VIDEO_028, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8C81
	sub [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x05, LABEL_8C04

LABEL_8D3A:
	video type=0, offset=COMMON_VIDEO_029, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8C81
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8BEE

LABEL_8D50:
	video type=0, offset=COMMON_VIDEO_027, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8C81
	sub [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x05, LABEL_8BD8

LABEL_8D66:
	video type=0, offset=COMMON_VIDEO_026, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8C73
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8BC2

LABEL_8D7C:
	video type=0, offset=COMMON_VIDEO_025, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8C73
	sub [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x05, LABEL_8BAC

LABEL_8D92:
	video type=0, offset=COMMON_VIDEO_024, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8C73
	sub [HERO_X], 0x0004
	break
	je [HERO_POS_MASK], 0x05, LABEL_8B96

LABEL_8DA8:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8C9C
	video type=0, offset=COMMON_VIDEO_023, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8B80

LABEL_8DBE:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8C9C
	video type=0, offset=COMMON_VIDEO_022, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x05, LABEL_8B6A
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8C9C
	jmp LABEL_8CEC
LABEL_8DDD:
	db 0x11, 0x06, 0x03, 0x01, 0x00, 0x02, 0x04, 0x6D
	db 0xF9

LABEL_8DE6:
	break
	add [HERO_X], 0x0002
	call LABEL_6DE2

LABEL_8DEE:
	break
	add [HERO_X], 0x0002
	call LABEL_6DCB

LABEL_8DF6:
	add [HERO_X], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_8DFD:
	db 0x06, 0x03, 0x01, 0x00, 0x02, 0x04, 0x6D, 0x5E

LABEL_8E05:
	break
	add [HERO_X], 0x0002
	call LABEL_6D4F

LABEL_8E0D:
	break
	add [HERO_X], 0x0002
	call LABEL_6E6E

LABEL_8E15:
	add [HERO_X], 0x0001
	jmp LABEL_8E89
LABEL_8E1C:
	db 0x11
