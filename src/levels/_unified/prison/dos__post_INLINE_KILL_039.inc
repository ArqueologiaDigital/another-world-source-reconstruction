LABEL_01A2:
	or [HERO_ACTION_POS_MASK], 0x0004
	and [HERO_ACTION_POS_MASK], 0x0007
	break
	jmp LABEL_01A2
LABEL_01AE:
	db 0x11

LABEL_01AF:
	break
	jl [HERO_X], 0xF0, LABEL_01AF
	fill page=0xFF, color=0x00
	setPalette 0x19
	setup channel=0x3C, address=LABEL_0467
	mov [SCROLL_Y], 0x0000
	break
	fill page=0xFF, color=0x00
	fill page=0x00, color=0x00
	fill page=0xFE, color=0x00
	fill page=0x03, color=0x00
	break
	unfreezeChannels first=0x00, last=0x34
	unfreezeChannels first=0x36, last=0x3B
	unfreezeChannels first=0x3D, last=0x3F
	load id=0x0048
	selectVideoPage 0x00
	video offset=CINEMATIC_244, x=160, y=100
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0x03
	copyVideoPage src=0x03, dst=0xFF
	load id=0x0049
	setup channel=0x3C, address=LABEL_0467
	setPalette 0x19
	play id=0x0068, freq=0x14, vol=0x20, channel=0x00
	play id=0x0068, freq=0x14, vol=0x20, channel=0x01
	play id=0x0066, freq=0x0A, vol=0x30, channel=0x02
	play id=0x0066, freq=0x08, vol=0x30, channel=0x03
	video offset=CINEMATIC_245, x=160, y=100
	video offset=CINEMATIC_246, x=160, y=100
	video offset=CINEMATIC_247, x=160, y=100
	mov [SCROLL_Y], 0x0000
	mov [PAUSE_SLICES], 0x0002
	mov [0xE6], 0x0014

LABEL_0229:
	break
	video offset=CINEMATIC_245, x=160, y=100
	video offset=CINEMATIC_246, x=160, y=100
	video offset=CINEMATIC_247, x=160, y=100
	djnz [0xE6], LABEL_0229
	play id=0x0066, freq=0x05, vol=0x20, channel=0x02
	mov [PAUSE_SLICES], 0x0004
	mov [0xE6], 0x0007
	mov [0xE7], 0x0040

LABEL_024C:
	break
	add [SCROLL_Y], 0x0002
	video offset=CINEMATIC_245, x=160, y=100, zoom=[0xe7]
	video offset=CINEMATIC_248, x=160, y=100, zoom=[0xe7]
	video offset=CINEMATIC_249, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0001
	djnz [0xE6], LABEL_024C
	mov [0xE6], 0x0007

LABEL_026F:
	break
	add [SCROLL_Y], 0x0002
	video offset=CINEMATIC_245, x=160, y=100, zoom=[0xe7]
	video offset=CINEMATIC_248, x=160, y=100, zoom=[0xe7]
	video offset=CINEMATIC_249, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0001
	djnz [0xE6], LABEL_026F
	mov [0xE6], 0x0007

LABEL_0292:
	break
	add [SCROLL_Y], 0x0002
	video offset=CINEMATIC_245, x=160, y=100, zoom=[0xe7]
	video offset=CINEMATIC_250, x=160, y=100, zoom=[0xe7]
	video offset=CINEMATIC_251, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0001
	djnz [0xE6], LABEL_0292
	mov [0xE6], 0x0007

LABEL_02B5:
	break
	add [SCROLL_Y], 0x0002
	video offset=CINEMATIC_245, x=160, y=100, zoom=[0xe7]
	video offset=CINEMATIC_252, x=160, y=100, zoom=[0xe7]
	video offset=CINEMATIC_253, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0001
	djnz [0xE6], LABEL_02B5
	play id=0x0066, freq=0x16, vol=0x14, channel=0x02
	mov [0xE6], 0x0007

LABEL_02DE:
	break
	add [SCROLL_Y], 0x0002
	video offset=CINEMATIC_254, x=160, y=100, zoom=[0xe7]
	video offset=CINEMATIC_255, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0001
	djnz [0xE6], LABEL_02DE
	mov [0xE6], 0x0007

LABEL_02FB:
	break
	add [SCROLL_Y], 0x0002
	video offset=CINEMATIC_256, x=160, y=100, zoom=[0xe7]
	video offset=CINEMATIC_257, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0001
	djnz [0xE6], LABEL_02FB
	play id=0x0066, freq=0x0A, vol=0x14, channel=0x02
	play id=0x0069, freq=0x14, vol=0x20, channel=0x03
	play id=0x0069, freq=0x14, vol=0x20, channel=0x01
	mov [0xE6], 0x0007

LABEL_032A:
	break
	add [SCROLL_Y], 0x0002
	video offset=CINEMATIC_258, x=160, y=100, zoom=[0xe7]
	video offset=CINEMATIC_259, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0001
	djnz [0xE6], LABEL_032A
	mov [0xE6], 0x0007

LABEL_0347:
	break
	add [SCROLL_Y], 0x0002
	video offset=CINEMATIC_260, x=160, y=100, zoom=[0xe7]
	video offset=CINEMATIC_261, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0002
	djnz [0xE6], LABEL_0347
	mov [0xE6], 0x0007

LABEL_0364:
	break
	add [SCROLL_Y], 0x0002
	video offset=CINEMATIC_262, x=160, y=100, zoom=[0xe7]
	video offset=CINEMATIC_263, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0002
	djnz [0xE6], LABEL_0364
	mov [0xE6], 0x0007

LABEL_0381:
	break
	add [SCROLL_Y], 0x0002
	video offset=CINEMATIC_264, x=160, y=100, zoom=[0xe7]
	video offset=CINEMATIC_265, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0002
	djnz [0xE6], LABEL_0381
	play id=0x0066, freq=0x0A, vol=0x0F, channel=0x02
	mov [0xE6], 0x0007

LABEL_03A4:
	break
	add [SCROLL_Y], 0x0002
	video offset=CINEMATIC_266, x=160, y=100, zoom=[0xe7]
	video offset=CINEMATIC_267, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0003
	djnz [0xE6], LABEL_03A4
	mov [0xE6], 0x0007

LABEL_03C1:
	break
	add [SCROLL_Y], 0x0002
	video offset=CINEMATIC_268, x=160, y=100, zoom=[0xe7]
	video offset=CINEMATIC_269, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0003
	djnz [0xE6], LABEL_03C1
	play id=0x0066, freq=0x09, vol=0x0A, channel=0x02
	mov [0xE6], 0x0007

LABEL_03E4:
	break
	add [SCROLL_Y], 0x0002
	video offset=CINEMATIC_270, x=160, y=100, zoom=[0xe7]
	video offset=CINEMATIC_271, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0003
	djnz [0xE6], LABEL_03E4
	mov [0xE6], 0x0007

LABEL_0401:
	break
	add [SCROLL_Y], 0x0002
	video offset=CINEMATIC_272, x=160, y=100, zoom=[0xe7]
	video offset=CINEMATIC_273, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0002
	djnz [0xE6], LABEL_0401
	mov [PAUSE_SLICES], 0x0004
	setup channel=0x3C, address=BLIT_PAGE_00_TO_FF_AND_BREAK
	break
	play id=0x0055, freq=0x14, vol=0x00, channel=0x00
	play id=0x0055, freq=0x14, vol=0x00, channel=0x01
	play id=0x0055, freq=0x14, vol=0x00, channel=0x02
	play id=0x0055, freq=0x14, vol=0x00, channel=0x03
	fill page=0xFF, color=0x00
	freezeChannels first=0x00, last=0x34
	freezeChannels first=0x36, last=0x3B
	freezeChannels first=0x3D, last=0x3F
	mov [0x65], 0x0000
	call LABEL_8189
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	call LABEL_7BBC
	selectVideoPage 0xFF
	setup channel=0x3C, address=BLIT_PAGE_00_TO_FF_AND_BREAK
	break
	fill page=0xFF, color=0x00
	setPalette 0x1A
	killChannel

LABEL_0467:
	call INCREMENT_VAR31
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x83, dst=0xFF
	sub [SCROLL_Y], 0x00C8
	copyVideoPage src=0x80, dst=0xFF
	add [SCROLL_Y], 0x00C8
	break
	jmp LABEL_0467
LABEL_0480:
	db 0x11

LABEL_0481:
	mov [HERO_X], 0x0091
	add [HERO_Y], 0x0014
	video offset=CINEMATIC_415, x=[HERO_X], y=[HERO_Y]
	break
	setup channel=0x3A, address=LABEL_0503
	add [HERO_Y], 0x0018
	video offset=CINEMATIC_415, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x0020
	video offset=CINEMATIC_415, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_212, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_211, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_418, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_419, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_420, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_421, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_422, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_423, x=[HERO_X], y=[HERO_Y]
	setup channel=0x00, address=LABEL_01A2
	break
	jmp LABEL_8C98
LABEL_04DE:
	db 0x11
