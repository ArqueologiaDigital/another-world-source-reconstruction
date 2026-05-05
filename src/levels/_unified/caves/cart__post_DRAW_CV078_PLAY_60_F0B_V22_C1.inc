LABEL_9DCF:
	jne [0x0A], 0x00, LABEL_9DDD
	video type=0, offset=COMMON_VIDEO_079, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_080

LABEL_9DDD:
	call GUARDED_DRAW_CV_126
