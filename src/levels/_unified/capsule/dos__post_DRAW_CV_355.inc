LABEL_8C7D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8C59
	video type=0, offset=COMMON_VIDEO_288, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_77AF
	ret

LABEL_8C8F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [BUDDY_X], 0x0001
	call LABEL_8C59
	video type=0, offset=COMMON_VIDEO_289, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	sub [BUDDY_Y], 0x0001
	call LABEL_77DD
	add [BUDDY_Y], 0x0001
	add [BUDDY_X], 0x0001
	ret

LABEL_8CB1:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8C59
	video type=0, offset=COMMON_VIDEO_288, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_780F
	ret

LABEL_8CC3:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8C59
	video type=0, offset=COMMON_VIDEO_288, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_77DD
	ret

LABEL_8CD5:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8C59
	video type=0, offset=COMMON_VIDEO_288, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	je [0x0D], 0x00, LABEL_8CF3
	call LABEL_8264
	jmp DECREMENT_VAR08_BY_D

LABEL_8CF3:
	call LABEL_856D
