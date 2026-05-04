LABEL_6E8F:
	jne [0x0A], 0x00, LABEL_6E9D
	video type=0, offset=COMMON_VIDEO_062, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CV_063

LABEL_6E9D:
	call GUARDED_DRAW_CV_126
