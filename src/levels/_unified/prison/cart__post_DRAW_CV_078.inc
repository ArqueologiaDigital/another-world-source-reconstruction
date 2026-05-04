LABEL_6F4A:
	jne [0x0A], 0x00, LABEL_6F58
	video type=0, offset=COMMON_VIDEO_079, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CV_080

LABEL_6F58:
	call GUARDED_DRAW_CV_126
