LABEL_9DE6:
	jne [0x0A], 0x00, LABEL_9DF4
	video type=0, offset=COMMON_VIDEO_001, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp LABEL_9DF7

LABEL_9DF4:
	call GUARDED_DRAW_CV_126

LABEL_9DF7:
	call LABEL_9D4D
	video type=0, offset=COMMON_VIDEO_002, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9E00:
	jne [0x0A], 0x00, LABEL_9E0E
	video type=0, offset=COMMON_VIDEO_060, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_061

LABEL_9E0E:
	call GUARDED_DRAW_CV_126
