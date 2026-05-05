LABEL_9E6F:
	jne [0x0A], 0x00, LABEL_9E7D
	video type=0, offset=COMMON_VIDEO_001, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp LABEL_9E80

LABEL_9E7D:
	call GUARDED_DRAW_CV_126

LABEL_9E80:
	call LABEL_9DD6
	video type=0, offset=COMMON_VIDEO_002, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9E89:
	jne [0x0A], 0x00, LABEL_9E97
	video type=0, offset=COMMON_VIDEO_060, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_061

LABEL_9E97:
	call GUARDED_DRAW_CV_126
