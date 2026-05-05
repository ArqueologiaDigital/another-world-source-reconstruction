LABEL_6F61:
	jne [0x0A], 0x00, LABEL_6F6F
	video type=0, offset=COMMON_VIDEO_001, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp LABEL_6F72

LABEL_6F6F:
	call GUARDED_DRAW_CV_126

LABEL_6F72:
	call LABEL_6ECE
	video type=0, offset=COMMON_VIDEO_002, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6F7B:
	jne [0x0A], 0x00, LABEL_6F89
	video type=0, offset=COMMON_VIDEO_060, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_061

LABEL_6F89:
	call GUARDED_DRAW_CV_126
