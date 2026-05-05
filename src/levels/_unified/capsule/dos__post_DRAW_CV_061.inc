LABEL_94AD:
	jne [0x0A], 0x00, LABEL_94BB
	video type=0, offset=COMMON_VIDEO_062, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_063

LABEL_94BB:
	call GUARDED_DRAW_CV_126
