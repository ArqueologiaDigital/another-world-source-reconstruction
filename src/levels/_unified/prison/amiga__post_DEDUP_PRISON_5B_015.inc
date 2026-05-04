LABEL_5CB2:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_209, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_210, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_5CD1
	call LABEL_5B7F
	jmp LABEL_5CD6

LABEL_5CD1:
	video type=0, offset=COMMON_VIDEO_211, x=[0x07], y=[0x08], zoom=0x40

LABEL_5CD6:
	ret

LABEL_5CD7:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x1C, vol=0x0A, channel=0x01
	sub [0x08], 0x0001
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_206, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_212, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_5D00
	call LABEL_5BA2
	jmp DEDUP_CAVES_5B_020	;@raw=0x07,0x5D,0x05

LABEL_5D00:
	video type=0, offset=COMMON_VIDEO_211, x=[0x07], y=[0x08], zoom=0x40
