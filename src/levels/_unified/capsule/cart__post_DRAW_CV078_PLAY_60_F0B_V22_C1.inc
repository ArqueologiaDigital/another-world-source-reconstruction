LABEL_94CE:
	jne [0x0A], 0x00, LABEL_94DC
	video type=0, offset=COMMON_VIDEO_079, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CV_080

LABEL_94DC:
	call GUARDED_DRAW_CV_126
