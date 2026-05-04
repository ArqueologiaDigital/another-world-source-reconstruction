LABEL_9E2E:
	jne [0x0A], 0x00, LABEL_9E3C
	video type=0, offset=COMMON_VIDEO_064, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CV_065

LABEL_9E3C:
	call GUARDED_DRAW_CV_126
