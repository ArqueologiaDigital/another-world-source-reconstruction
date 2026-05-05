LABEL_E035:
	je [0x63], 0x01, LABEL_E061
	je [0x63], 0x05, LABEL_E061
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_E050
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_EB1E

LABEL_E050:
	jne [HERO_ACTION_POS_MASK], 0x84, JUMP_TO_LABEL_E07E_AT_E05E
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_EC94

JUMP_TO_LABEL_E07E_AT_E05E:
	jmp LABEL_E07E

LABEL_E061:
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_E070
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_E9BC

LABEL_E070:
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_E07E
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_EC7C

LABEL_E07E:
	break
	jmp LABEL_DF3B
LABEL_E082:
	db 0x11, 0x57, 0x22, 0x46, 0x01, 0x02, 0x06, 0x57
	db 0x22, 0x94, 0x01, 0x02, 0x03, 0x01, 0x00, 0x06
	db 0x06, 0x57, 0x22, 0xE0, 0x01, 0x02, 0x03, 0x01
	db 0x00, 0x01, 0x04, 0xD8, 0x85, 0x06, 0x57, 0x23
	db 0x28, 0x01, 0x02, 0x06, 0x57, 0x23, 0x6A, 0x01
	db 0x02, 0x03, 0x01, 0x00, 0x03, 0x06, 0x57, 0x26
	db 0x20, 0x01, 0x02, 0x03, 0x01, 0x00, 0x05, 0x06
	db 0x00, 0x2A, 0x00, 0x0F, 0x07, 0xE1, 0x3B, 0x11

LABEL_E0C2:
	break
	video type=0, offset=COMMON_VIDEO_028, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0003
	break
	jmp LABEL_E0EB

LABEL_E0D0:
	add [HERO_X], 0x0002
	add [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_023, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	add [HERO_X], 0x0001
	add [HERO_X], 0x0002
	break

LABEL_E0EB:
	je [HACK_VAR_67], 0x25, LABEL_E125
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
	jmp LABEL_EDDA
LABEL_E124:
	db 0x11

LABEL_E125:
	video type=0, offset=COMMON_VIDEO_021, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_E13B
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_E301
	jmp LABEL_E125
LABEL_E13A:
	db 0x11

LABEL_E13B:
	video type=0, offset=COMMON_VIDEO_021, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_E2EB

LABEL_E14B:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E0EB
	video type=0, offset=COMMON_VIDEO_086, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_POS_MASK], 0x06, LABEL_E2DF

LABEL_E15D:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E0EB
	video type=0, offset=COMMON_VIDEO_020, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_E3B1

LABEL_E173:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E0EB
	video type=0, offset=COMMON_VIDEO_022, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_E39B

LABEL_E189:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E0EB
	video type=0, offset=COMMON_VIDEO_023, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	break
	je [HERO_POS_MASK], 0x06, LABEL_E385

LABEL_E19F:
	video type=0, offset=COMMON_VIDEO_024, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E0D0
	add [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_E36F

LABEL_E1B5:
	video type=0, offset=COMMON_VIDEO_025, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E0D0
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_E359

LABEL_E1CB:
	video type=0, offset=COMMON_VIDEO_026, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E0D0
	add [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_E343

LABEL_E1E1:
	video type=0, offset=COMMON_VIDEO_027, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E0C2
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_E32D

LABEL_E1F7:
	video type=0, offset=COMMON_VIDEO_029, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E0C2
	add [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_E317

LABEL_E20D:
	video type=0, offset=COMMON_VIDEO_028, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_E301
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_E0EB
	jmp LABEL_E13B
LABEL_E226:
	db 0x11, 0x57, 0x2B, 0xE2, 0x01, 0x02, 0x06, 0x57
	db 0x2C, 0x3C, 0x01, 0x02, 0x03, 0x01, 0xFF, 0xFA
	db 0x06, 0x57, 0x2C, 0xA2, 0x01, 0x02, 0x03, 0x01
	db 0xFF, 0xFF, 0x04, 0xD8, 0x85, 0x06, 0x57, 0x2D
	db 0x04, 0x01, 0x02, 0x06, 0x57, 0x2D, 0x56, 0x01
	db 0x02, 0x03, 0x01, 0xFF, 0xFD, 0x06, 0x57, 0x2D
	db 0xA6, 0x01, 0x02, 0x03, 0x01, 0xFF, 0xFB, 0x06
	db 0x00, 0x2A, 0x00, 0x0F, 0x07, 0xE2, 0xDF, 0x11

LABEL_E266:
	break
	video type=0, offset=COMMON_VIDEO_024, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0003
	break
	jmp LABEL_E28F

LABEL_E274:
	sub [HERO_X], 0x0002
	sub [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_021, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	sub [HERO_X], 0x0001
	sub [HERO_X], 0x0002
	break

LABEL_E28F:
	je [HACK_VAR_67], 0x25, LABEL_E2C9
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
	jmp LABEL_ED09
LABEL_E2C8:
	db 0x11

LABEL_E2C9:
	video type=0, offset=COMMON_VIDEO_022, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_E173
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_E2DF
	jmp LABEL_E2C9
LABEL_E2DE:
	db 0x11

LABEL_E2DF:
	video type=0, offset=COMMON_VIDEO_020, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_POS_MASK], 0x05, LABEL_E14B

LABEL_E2EB:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E28F
	video type=0, offset=COMMON_VIDEO_086, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_E13B

LABEL_E301:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E28F
	video type=0, offset=COMMON_VIDEO_021, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_E20D

LABEL_E317:
	video type=0, offset=COMMON_VIDEO_028, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E274
	sub [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x05, LABEL_E1F7

LABEL_E32D:
	video type=0, offset=COMMON_VIDEO_029, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E274
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_E1E1

LABEL_E343:
	video type=0, offset=COMMON_VIDEO_027, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E274
	sub [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x05, LABEL_E1CB

LABEL_E359:
	video type=0, offset=COMMON_VIDEO_026, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E266
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_E1B5

LABEL_E36F:
	video type=0, offset=COMMON_VIDEO_025, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E266
	sub [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x05, LABEL_E19F

LABEL_E385:
	video type=0, offset=COMMON_VIDEO_024, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E266
	sub [HERO_X], 0x0004
	break
	je [HERO_POS_MASK], 0x05, LABEL_E189

LABEL_E39B:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E28F
	video type=0, offset=COMMON_VIDEO_023, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_E173

LABEL_E3B1:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E28F
	video type=0, offset=COMMON_VIDEO_022, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x05, LABEL_E15D
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E28F
	jmp LABEL_E2DF
LABEL_E3D0:
	db 0x11, 0x06, 0x03, 0x01, 0x00, 0x02, 0x04, 0x9B
	db 0x59

LABEL_E3D9:
	break
	add [HERO_X], 0x0002
	call LABEL_9B42

LABEL_E3E1:
	break
	add [HERO_X], 0x0002
	call LABEL_9B2B

LABEL_E3E9:
	add [HERO_X], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_E3F0:
	db 0x06, 0x03, 0x01, 0x00, 0x02, 0x04, 0x9A, 0xB8

LABEL_E3F8:
	break
	add [HERO_X], 0x0002
	call LABEL_9AA9

LABEL_E400:
	break
	add [HERO_X], 0x0002
	call LABEL_9BD4

LABEL_E408:
	add [HERO_X], 0x0001
	jmp LABEL_E476
LABEL_E40F:
	db 0x11
