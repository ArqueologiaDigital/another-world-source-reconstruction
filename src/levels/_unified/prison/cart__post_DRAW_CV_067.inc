LABEL_6FD7:
	jne [0x0A], 0x00, LABEL_6FE5
	video type=0, offset=COMMON_VIDEO_068, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CV_069

LABEL_6FE5:
	call GUARDED_DRAW_CV_126
