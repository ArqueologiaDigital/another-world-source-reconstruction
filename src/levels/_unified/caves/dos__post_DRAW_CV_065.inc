LABEL_9ECE:
	jne [0x0A], 0x00, LABEL_9EDC
	video type=0, offset=COMMON_VIDEO_066, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_067

LABEL_9EDC:
	call GUARDED_DRAW_CV_126
