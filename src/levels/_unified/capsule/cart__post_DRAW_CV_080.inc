LABEL_94E5:
	jne [0x0A], 0x00, LABEL_94F3
	video type=0, offset=COMMON_VIDEO_001, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp LABEL_94F6

LABEL_94F3:
	call GUARDED_DRAW_CV_126

LABEL_94F6:
	call LABEL_944C
	video type=0, offset=COMMON_VIDEO_002, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_94FF:
	jne [0x0A], 0x00, LABEL_950D
	video type=0, offset=COMMON_VIDEO_060, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_061

LABEL_950D:
	call GUARDED_DRAW_CV_126
