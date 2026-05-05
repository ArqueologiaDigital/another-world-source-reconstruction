LABEL_0503:
	unfreezeChannels first=0x00, last=0x39
	setup channel=0x3C, address=LABEL_0689
	mov [0x14], 0x0006
	mov [SCROLL_Y], 0x00CA

LABEL_0513:
	break
	copyVideoPage src=0x83, dst=0xFF
	sub [SCROLL_Y], 0x00C8
	copyVideoPage src=0x80, dst=0xFF
	add [SCROLL_Y], 0x00B8
	sub [SCROLL_Y], 0x000A
	video offset=CINEMATIC_416, x=160, y=[0xf9], zoom=0x40
	add [SCROLL_Y], 0x000A
	video offset=CINEMATIC_415, x=[0x01], y=[0x02], zoom=0x40
	djnz [0x14], LABEL_0513
	selectVideoPage 0x00
	copyVideoPage src=0xFF, dst=0x00
	video offset=CINEMATIC_410, x=160, y=22
	video offset=CINEMATIC_417, x=160, y=96
	video offset=CINEMATIC_413, x=160, y=22
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

LABEL_0567:
	call LABEL_65DC
	call LABEL_65DC
	call LABEL_65DC
	mov [0x10], [HACK_VAR_67]
	mov [0x0D], 0x0001
	mov [0x0E], 0x0000
	break
	jmp LABEL_0567
