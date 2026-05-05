LABEL_9E17:
	jne [0x0A], 0x00, LABEL_9E25
	video type=0, offset=COMMON_VIDEO_062, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_063

LABEL_9E25:
	call GUARDED_DRAW_CV_126
