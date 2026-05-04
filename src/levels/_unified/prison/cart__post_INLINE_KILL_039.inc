LABEL_0210:
	or [HERO_ACTION_POS_MASK], 0x0004
	and [HERO_ACTION_POS_MASK], 0x0007
	break
	jmp LABEL_0210
LABEL_021C:
	db 0x11

LABEL_021D:
	break
	jl [0x01], 0xF0, LABEL_021D
	fill page=0xFF, color=0x00
	setPalette 0x19
	setup channel=0x3C, address=LABEL_04E7
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
	video type=1, offset=CINEMATIC_244, x=160, y=100
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0x03
	copyVideoPage src=0x03, dst=0xFF
	load id=0x0049
	setup channel=0x3C, address=LABEL_04E7
	setPalette 0x19
	play id=0x0068, freq=0x14, vol=0x20, channel=0x00
	play id=0x0068, freq=0x14, vol=0x20, channel=0x01
	play id=0x0066, freq=0x0A, vol=0x30, channel=0x02
	play id=0x0066, freq=0x08, vol=0x30, channel=0x03
	call LABEL_005E
	song id=0x0BC2, delay=0x0000, pos=0x00
	video type=1, offset=CINEMATIC_245, x=160, y=100
	video type=1, offset=CINEMATIC_246, x=160, y=100
	video type=1, offset=CINEMATIC_247, x=160, y=100
	mov [SCROLL_Y], 0x0000
	mov [PAUSE_SLICES], 0x0002
	mov [0xE6], 0x0014

LABEL_02A0:
	break
	video type=1, offset=CINEMATIC_245, x=160, y=100
	video type=1, offset=CINEMATIC_246, x=160, y=100
	video type=1, offset=CINEMATIC_247, x=160, y=100
	djnz [0xE6], LABEL_02A0
	play id=0x0066, freq=0x05, vol=0x20, channel=0x02
	mov [PAUSE_SLICES], 0x0004
	mov [0xE6], 0x0007
	mov [0xE7], 0x0040

LABEL_02C3:
	break
	add [SCROLL_Y], 0x0002
	video type=1, offset=CINEMATIC_245, x=160, y=100, zoom=[0xe7]
	video type=1, offset=CINEMATIC_248, x=160, y=100, zoom=[0xe7]
	video type=1, offset=CINEMATIC_249, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0001
	djnz [0xE6], LABEL_02C3
	mov [0xE6], 0x0007

LABEL_02E6:
	break
	add [SCROLL_Y], 0x0002
	video type=1, offset=CINEMATIC_245, x=160, y=100, zoom=[0xe7]
	video type=1, offset=CINEMATIC_248, x=160, y=100, zoom=[0xe7]
	video type=1, offset=CINEMATIC_249, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0001
	djnz [0xE6], LABEL_02E6
	mov [0xE6], 0x0007

LABEL_0309:
	break
	add [SCROLL_Y], 0x0002
	video type=1, offset=CINEMATIC_245, x=160, y=100, zoom=[0xe7]
	video type=1, offset=CINEMATIC_250, x=160, y=100, zoom=[0xe7]
	video type=1, offset=CINEMATIC_251, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0001
	djnz [0xE6], LABEL_0309
	mov [0xE6], 0x0007

LABEL_032C:
	break
	add [SCROLL_Y], 0x0002
	video type=1, offset=CINEMATIC_245, x=160, y=100, zoom=[0xe7]
	video type=1, offset=CINEMATIC_252, x=160, y=100, zoom=[0xe7]
	video type=1, offset=CINEMATIC_253, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0001
	djnz [0xE6], LABEL_032C
	play id=0x0066, freq=0x16, vol=0x14, channel=0x02
	mov [0xE6], 0x0007

LABEL_0355:
	break
	add [SCROLL_Y], 0x0002
	video type=1, offset=CINEMATIC_254, x=160, y=100, zoom=[0xe7]
	video type=1, offset=CINEMATIC_255, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0001
	djnz [0xE6], LABEL_0355
	mov [0xE6], 0x0007

LABEL_0372:
	break
	add [SCROLL_Y], 0x0002
	video type=1, offset=CINEMATIC_256, x=160, y=100, zoom=[0xe7]
	video type=1, offset=CINEMATIC_257, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0001
	djnz [0xE6], LABEL_0372
	play id=0x0066, freq=0x0A, vol=0x14, channel=0x02
	play id=0x0069, freq=0x14, vol=0x20, channel=0x03
	play id=0x0069, freq=0x14, vol=0x20, channel=0x01
	mov [0xE6], 0x0007

LABEL_03A1:
	break
	add [SCROLL_Y], 0x0002
	video type=1, offset=CINEMATIC_258, x=160, y=100, zoom=[0xe7]
	video type=1, offset=CINEMATIC_259, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0001
	djnz [0xE6], LABEL_03A1
	mov [0xE6], 0x0007

LABEL_03BE:
	break
	add [SCROLL_Y], 0x0002
	video type=1, offset=CINEMATIC_260, x=160, y=100, zoom=[0xe7]
	video type=1, offset=CINEMATIC_261, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0002
	djnz [0xE6], LABEL_03BE
	mov [0xE6], 0x0007

LABEL_03DB:
	break
	add [SCROLL_Y], 0x0002
	video type=1, offset=CINEMATIC_262, x=160, y=100, zoom=[0xe7]
	video type=1, offset=CINEMATIC_263, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0002
	djnz [0xE6], LABEL_03DB
	mov [0xE6], 0x0007

LABEL_03F8:
	break
	add [SCROLL_Y], 0x0002
	video type=1, offset=CINEMATIC_264, x=160, y=100, zoom=[0xe7]
	video type=1, offset=CINEMATIC_265, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0002
	djnz [0xE6], LABEL_03F8
	play id=0x0066, freq=0x0A, vol=0x0F, channel=0x02
	mov [0xE6], 0x0007

LABEL_041B:
	break
	add [SCROLL_Y], 0x0002
	video type=1, offset=CINEMATIC_266, x=160, y=100, zoom=[0xe7]
	video type=1, offset=CINEMATIC_267, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0003
	djnz [0xE6], LABEL_041B
	mov [0xE6], 0x0007

LABEL_0438:
	break
	add [SCROLL_Y], 0x0002
	video type=1, offset=CINEMATIC_268, x=160, y=100, zoom=[0xe7]
	video type=1, offset=CINEMATIC_269, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0003
	djnz [0xE6], LABEL_0438
	play id=0x0066, freq=0x09, vol=0x0A, channel=0x02
	mov [0xE6], 0x0007

LABEL_045B:
	break
	add [SCROLL_Y], 0x0002
	video type=1, offset=CINEMATIC_270, x=160, y=100, zoom=[0xe7]
	video type=1, offset=CINEMATIC_271, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0003
	djnz [0xE6], LABEL_045B
	mov [0xE6], 0x0007

LABEL_0478:
	break
	add [SCROLL_Y], 0x0002
	video type=1, offset=CINEMATIC_272, x=160, y=100, zoom=[0xe7]
	video type=1, offset=CINEMATIC_273, x=160, y=100, zoom=[0xe7]
	add [0xE7], 0x0002
	djnz [0xE6], LABEL_0478
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
	call LABEL_82D1
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	call LABEL_7CE1
	selectVideoPage 0xFF
	setup channel=0x3C, address=BLIT_PAGE_00_TO_FF_AND_BREAK
	call LABEL_0054
	song id=0x0BC3, delay=0x0000, pos=0x00
	break
	fill page=0xFF, color=0x00
	setPalette 0x1A
	killChannel

LABEL_04E7:
	call INCREMENT_VAR31
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x83, dst=0xFF
	sub [SCROLL_Y], 0x00C8
	copyVideoPage src=0x80, dst=0xFF
	add [SCROLL_Y], 0x00C8
	break
	jmp LABEL_04E7
LABEL_0500:
	db 0x11

LABEL_0501:
	mov [0x01], 0x0091
	add [0x02], 0x0014
	video type=1, offset=CINEMATIC_415, x=[0x01], y=[0x02], zoom=0x40
	break
	setup channel=0x3A, address=LABEL_0583
	add [0x02], 0x0018
	video type=1, offset=CINEMATIC_415, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x02], 0x0020
	video type=1, offset=CINEMATIC_415, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_212, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_211, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_418, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_419, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_420, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_421, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_422, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_423, x=[0x01], y=[0x02], zoom=0x40
	setup channel=0x00, address=LABEL_0210
	break
	jmp LABEL_8DF6
LABEL_055E:
	db 0x11

LABEL_055F:
	mov [0x01], 0x0041
	add [0x02], 0x0016
	video type=1, offset=CINEMATIC_414, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x001A
	break
	add [0x02], 0x0020
	video type=1, offset=CINEMATIC_415, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x00], 0x001E
	bankSwitch 4;  TODO - Name this stage (bank number #4)
	killChannel

LABEL_0583:
	unfreezeChannels first=0x00, last=0x39
	setup channel=0x3C, address=LABEL_0711
	mov [0x14], 0x0006
	mov [SCROLL_Y], 0x00CA
	sub [0x02], 0x0001

LABEL_0597:
	break
	copyVideoPage src=0x83, dst=0xFF
	sub [SCROLL_Y], 0x00C8
	copyVideoPage src=0x80, dst=0xFF
	add [SCROLL_Y], 0x00B8
	sub [SCROLL_Y], 0x000A
	video type=1, offset=CINEMATIC_416, x=160, y=[0xf9], zoom=0x40
	add [SCROLL_Y], 0x000A
	video type=1, offset=CINEMATIC_415, x=[0x01], y=[0x02], zoom=0x40
	djnz [0x14], LABEL_0597
	add [0x02], 0x0001
	selectVideoPage 0x00
	copyVideoPage src=0xFF, dst=0x00
	video type=1, offset=CINEMATIC_410, x=160, y=22
	video type=1, offset=CINEMATIC_417, x=160, y=96
	video type=1, offset=CINEMATIC_413, x=160, y=22
	selectVideoPage 0xFF
	setup channel=0x3C, address=BLIT_PAGE_00_TO_FF_AND_BREAK
	freezeChannels first=0x00, last=0x39
	mov [0xF8], 0x004E
	sub [0x41], [0xF8]
	sub [0x44], [0xF8]
	sub [0x45], [0xF8]
	sub [0x69], [0xF8]
	sub [0x79], [0xF8]
	killChannel

LABEL_05EF:
	call LABEL_66DF
	call LABEL_66DF
	call LABEL_66DF
	mov [0x10], [HACK_VAR_67]
	mov [0x0D], 0x0001
	mov [0x0E], 0x0000
	break
	jmp LABEL_05EF

LABEL_0607:
	sub [0x02], 0x0009
	video type=1, offset=CINEMATIC_422, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	mov [0x03], 0x000B

LABEL_0618:
	break
	video type=1, offset=CINEMATIC_422, x=[0x01], y=[0x02], zoom=0x40
	djnz [0x03], LABEL_0618
	break
	video type=1, offset=CINEMATIC_421, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_420, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_419, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_418, x=[0x01], y=[0x02], zoom=0x40
	mov [0x03], 0x0009

LABEL_063E:
	break
	video type=1, offset=CINEMATIC_215, x=[0x01], y=[0x02], zoom=0x40
	djnz [0x03], LABEL_063E
	break
	video type=1, offset=CINEMATIC_212, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_211, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0002
	break
	play id=0x0060, freq=0x14, vol=0x1E, channel=0x00
	call LABEL_6D9D
	setup channel=0x15, address=INLINE_SET_VAR03_TO_7
	break
	jmp LABEL_97A4
LABEL_066A:
	db 0x11
