LABEL_8CE6:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8CC2
	video type=0, offset=COMMON_VIDEO_288, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7818
	ret

LABEL_8CF8:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [BUDDY_X], 0x0001
	call LABEL_8CC2
	video type=0, offset=COMMON_VIDEO_289, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	sub [BUDDY_Y], 0x0001
	call LABEL_7846
	add [BUDDY_Y], 0x0001
	add [BUDDY_X], 0x0001
	ret

LABEL_8D1A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8CC2
	video type=0, offset=COMMON_VIDEO_288, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7878
	ret

LABEL_8D2C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8CC2
	video type=0, offset=COMMON_VIDEO_288, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7846
	ret

LABEL_8D3E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8CC2
	video type=0, offset=COMMON_VIDEO_288, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	je [0x0D], 0x00, LABEL_8D5C
	call LABEL_82CD
	jmp DECREMENT_VAR08_BY_D

LABEL_8D5C:
	call LABEL_85D6
