LABEL_9F5F:
	video type=0, offset=COMMON_VIDEO_081, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x01
	jne [0x0A], 0x00, DRAW_CV_295
	video type=0, offset=COMMON_VIDEO_082, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9F76:
	video type=0, offset=COMMON_VIDEO_083, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_296
	video type=0, offset=COMMON_VIDEO_084, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9F87:
	video type=0, offset=COMMON_VIDEO_116, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_299
	video type=0, offset=COMMON_VIDEO_117, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9F98:
	video type=0, offset=COMMON_VIDEO_118, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_300
	video type=0, offset=COMMON_VIDEO_119, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9FA9:
	video type=0, offset=COMMON_VIDEO_120, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_300
	video type=0, offset=COMMON_VIDEO_121, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9FBA:
	video type=0, offset=COMMON_VIDEO_086, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0A, vol=0x2A, channel=0x01
	jne [0x0A], 0x00, DRAW_CV_295
	video type=0, offset=COMMON_VIDEO_087, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9FD1:
	video type=0, offset=COMMON_VIDEO_088, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_295
	video type=0, offset=COMMON_VIDEO_089, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9FE2:
	video type=0, offset=COMMON_VIDEO_090, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_296
	video type=0, offset=COMMON_VIDEO_091, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_9FF3:
	video type=0, offset=COMMON_VIDEO_092, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_297
	video type=0, offset=COMMON_VIDEO_093, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_A004:
	video type=0, offset=COMMON_VIDEO_094, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_297
	video type=0, offset=COMMON_VIDEO_095, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret
