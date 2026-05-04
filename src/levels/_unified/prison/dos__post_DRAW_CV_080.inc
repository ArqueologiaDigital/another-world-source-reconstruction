LABEL_6E5E:
	jne [0x0A], 0x00, LABEL_6E6C
	video type=0, offset=COMMON_VIDEO_001, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_6E6F

LABEL_6E6C:
	call GUARDED_DRAW_CV_126

LABEL_6E6F:
	call LABEL_6DCB
	video type=0, offset=COMMON_VIDEO_002, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6E78:
	jne [0x0A], 0x00, LABEL_6E86
	video type=0, offset=COMMON_VIDEO_060, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CV_061

LABEL_6E86:
	call GUARDED_DRAW_CV_126
