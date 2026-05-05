LABEL_1BAF:
	sub [0x6B], 0x0008
	mov [0x21], [0x6B]
	call LABEL_1BD5
	break
	djnz [0x6A], LABEL_1BAF
	mov [0x6A], 0x002F

LABEL_1BC2:
	add [0x6B], 0x0008
	mov [0x21], [0x6B]
	call LABEL_1BD5
	break
	djnz [0x6A], LABEL_1BC2
	jmp INLINE_SET_VAR6A_TO_2F
LABEL_1BD4:
	db 0x11

LABEL_1BD5:
	video offset=CINEMATIC_013, x=[0x21], y=100
	sub [0x21], 0x0064
	video offset=CINEMATIC_013, x=[0x21], y=100
	add [0x21], 0x00AA
	video offset=CINEMATIC_013, x=[0x21], y=100
	ret
LABEL_1BED:
	db 0x11

LABEL_1BEE:
	add [0x02], 0x0019
	or [0x04], 0x4000
	video offset=CINEMATIC_000, x=[0x01], y=[0x02]
	break
	jg [0x02], 0xC8, LABEL_1C15
	add [0x02], 0x0019
	video offset=CINEMATIC_014, x=[0x01], y=[0x02]
	break
	jg [0x02], 0xC8, LABEL_1C15
	jmp LABEL_1BEE

LABEL_1C15:
	or [0x04], 0x4000
	deleteChannels first=0x00, last=0x3B
	setup channel=0x3F, address=KILL_CHANNEL_LANDING
	setup channel=0x13, address=LABEL_1C26
	killChannel

LABEL_1C26:
	mov [0xE6], 0x005F
	mov [0xE7], 0x0064
	mov [0xE8], [0xE6]
	mov [0xE9], 0x00B4
	mov [0xEA], [0xE8]
	mov [0xEB], [0xE9]
	mov [0xEC], [0xE8]
	mov [0xED], [0xE9]
	mov [0xEE], [0xE8]
	mov [0xEF], [0xE9]
	deleteChannels first=0x14, last=0x3B
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	fill page=0xFF, color=0x00
	setPalette 0x13
	setup channel=0x3C, address=LABEL_3F67
	break
	setup channel=0x01, address=INLINE_SET_VAR68_TO_32
	setup channel=0x02, address=INLINE_SET_VAR6A_TO_2F
	mov [0x69], 0x0000
	mov [0x6B], 0x0000
	fill page=0x00, color=0x03
	fill page=0x03, color=0x03
	selectVideoPage 0x00
	add [0xE6], 0x0001
	video offset=CINEMATIC_001, x=[0xe6], y=[0xe7]
	video offset=CINEMATIC_002, x=[0xe6], y=[0xe7]
	sub [0xE6], 0x0001
	selectVideoPage 0x03
	video offset=CINEMATIC_001, x=[0xe6], y=[0xe7]
	video offset=CINEMATIC_002, x=[0xe6], y=[0xe7]
	song id=0x0BDF, delay=0x0000, pos=0x00
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_003, x=[0xe6], y=[0xe7]
	play id=0x006D, freq=0x0A, vol=0x40, channel=0x01
	play id=0x006D, freq=0x10, vol=0x40, channel=0x00
	play id=0x006D, freq=0x07, vol=0x40, channel=0x02
	setup channel=0x14, address=INLINE_SET_VAR01_TO_E
	break
	video offset=CINEMATIC_004, x=[0xe6], y=[0xe7]
	video offset=CINEMATIC_005, x=[0xe8], y=[0xe9], zoom=[0x20]	;@enc=alt
	play id=0x006D, freq=0x0A, vol=0x40, channel=0x03
	video offset=CINEMATIC_005, x=[0xea], y=[0xeb], zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_005, x=[0xec], y=[0xed]
	video offset=CINEMATIC_005, x=[0xee], y=[0xef], zoom=[0x20]	;@enc=alt
	break
	play id=0x006D, freq=0x07, vol=0x40, channel=0x02
	video offset=CINEMATIC_006, x=[0xe6], y=[0xe7]
	selectVideoPage 0x03
	video offset=CINEMATIC_007, x=[0xe6], y=[0xe7]
	selectVideoPage 0x00
	video offset=CINEMATIC_007, x=[0xe6], y=[0xe7], zoom=[0x42]	;@enc=alt
	selectVideoPage 0xFF
	play id=0x006D, freq=0x18, vol=0x40, channel=0x00
	video offset=CINEMATIC_005, x=[0xe8], y=[0xe9], zoom=[0x2c]	;@enc=alt
	video offset=CINEMATIC_005, x=[0xea], y=[0xeb], zoom=[0x14]	;@enc=alt
	video offset=CINEMATIC_005, x=[0xec], y=[0xed]
	video offset=CINEMATIC_005, x=[0xee], y=[0xef], zoom=[0x28]	;@enc=alt
	break
	video offset=CINEMATIC_005, x=[0xe8], y=[0xe9], zoom=[0x32]	;@enc=alt
	video offset=CINEMATIC_005, x=[0xea], y=[0xeb], zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_005, x=[0xec], y=[0xed]
	play id=0x006D, freq=0x0F, vol=0x40, channel=0x02
	video offset=CINEMATIC_005, x=[0xee], y=[0xef], zoom=[0x32]	;@enc=alt

LABEL_1D31:
	break
	video offset=CINEMATIC_005, x=[0xe8], y=[0xe9], zoom=[0x46]	;@enc=alt
	video offset=CINEMATIC_005, x=[0xea], y=[0xeb], zoom=[0x50]	;@enc=alt
	video offset=CINEMATIC_005, x=[0xec], y=[0xed]
	video offset=CINEMATIC_005, x=[0xee], y=[0xef], zoom=[0x32]	;@enc=alt
	jmp LABEL_1D31
	break
	video offset=CINEMATIC_891, x=[0xe8], y=[0xe9], zoom=[0x46]	;@enc=alt
	video offset=CINEMATIC_005, x=[0xea], y=[0xeb], zoom=[0x50]	;@enc=alt
	video offset=CINEMATIC_005, x=[0xec], y=[0xed]
	video offset=CINEMATIC_892, x=[0xee], y=[0xef], zoom=[0x32]	;@enc=alt
	break
	video offset=CINEMATIC_005, x=[0xe8], y=[0xe9], zoom=[0x46]	;@enc=alt
	video offset=CINEMATIC_892, x=[0xea], y=[0xeb], zoom=[0x50]	;@enc=alt
	video offset=CINEMATIC_891, x=[0xec], y=[0xed]
	video offset=CINEMATIC_005, x=[0xee], y=[0xef], zoom=[0x32]	;@enc=alt
	break
	video offset=CINEMATIC_892, x=[0xe8], y=[0xe9], zoom=[0x46]	;@enc=alt
	video offset=CINEMATIC_005, x=[0xea], y=[0xeb], zoom=[0x50]	;@enc=alt
	video offset=CINEMATIC_005, x=[0xec], y=[0xed]
	video offset=CINEMATIC_891, x=[0xee], y=[0xef], zoom=[0x32]	;@enc=alt
	jmp LABEL_1D31
LABEL_1D97:
	db 0x11
