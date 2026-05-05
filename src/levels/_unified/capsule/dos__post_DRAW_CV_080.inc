LABEL_947C:
	jne [0x0A], 0x00, LABEL_948A
	video type=0, offset=COMMON_VIDEO_001, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp LABEL_948D

LABEL_948A:
	call GUARDED_DRAW_CV_126

LABEL_948D:
	call LABEL_93E3
	video type=0, offset=COMMON_VIDEO_002, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9496:
	jne [0x0A], 0x00, LABEL_94A4
	video type=0, offset=COMMON_VIDEO_060, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_061

LABEL_94A4:
	call GUARDED_DRAW_CV_126
