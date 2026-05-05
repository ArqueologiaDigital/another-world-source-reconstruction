LABEL_94C4:
	jne [0x0A], 0x00, LABEL_94D2
	video type=0, offset=COMMON_VIDEO_064, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_065

LABEL_94D2:
	call GUARDED_DRAW_CV_126
