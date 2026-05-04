LABEL_9E5C:
	jne [0x0A], 0x00, LABEL_9E6A
	video type=0, offset=COMMON_VIDEO_068, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CV_069

LABEL_9E6A:
	call GUARDED_DRAW_CV_126
