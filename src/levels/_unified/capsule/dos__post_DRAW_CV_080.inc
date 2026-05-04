LABEL_947C:
	jne [0x0A], 0x00, LABEL_948A
	video type=0, offset=COMMON_VIDEO_001, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_948D

LABEL_948A:
	call GUARDED_DRAW_CV_126

LABEL_948D:
	call LABEL_93E3
	video type=0, offset=COMMON_VIDEO_002, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_9496:
	jne [0x0A], 0x00, LABEL_94A4
	video type=0, offset=COMMON_VIDEO_060, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CV_061

LABEL_94A4:
	call GUARDED_DRAW_CV_126
