LABEL_9EE5:
	jne [0x0A], 0x00, LABEL_9EF3
	video type=0, offset=COMMON_VIDEO_068, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_069

LABEL_9EF3:
	call GUARDED_DRAW_CV_126
