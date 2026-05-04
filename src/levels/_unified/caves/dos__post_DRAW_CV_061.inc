LABEL_9EA0:
	jne [0x0A], 0x00, LABEL_9EAE
	video type=0, offset=COMMON_VIDEO_062, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CV_063

LABEL_9EAE:
	call GUARDED_DRAW_CV_126
