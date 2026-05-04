LABEL_6EA6:
	jne [0x0A], 0x00, LABEL_6EB4
	video type=0, offset=COMMON_VIDEO_064, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CV_065

LABEL_6EB4:
	call GUARDED_DRAW_CV_126
