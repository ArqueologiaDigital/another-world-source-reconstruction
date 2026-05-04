LABEL_9544:
	jne [0x0A], 0x00, LABEL_9552
	video type=0, offset=COMMON_VIDEO_066, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CV_067

LABEL_9552:
	call GUARDED_DRAW_CV_126
