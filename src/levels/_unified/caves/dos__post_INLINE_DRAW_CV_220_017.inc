LABEL_8658:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_233, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09
	call LABEL_8417
	ret

LABEL_8667:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	je [0x0D], 0x00, 0x867F
	call LABEL_829E
	jmp LABEL_8684
