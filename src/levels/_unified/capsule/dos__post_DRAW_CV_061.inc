LABEL_94AD:
	jne [0x0A], 0x00, LABEL_94BB
	video type=0, offset=COMMON_VIDEO_062, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CV_063

LABEL_94BB:
	call GUARDED_DRAW_CV_126
