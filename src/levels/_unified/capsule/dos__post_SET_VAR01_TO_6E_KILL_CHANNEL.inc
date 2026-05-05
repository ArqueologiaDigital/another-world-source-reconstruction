LABEL_1A72:
	copyVideoPage src=0x03, dst=0x00
	mov [PAUSE_SLICES], 0x0004
	setPalette 0x03
	selectVideoPage 0x00
	video offset=CINEMATIC_044, x=160, y=100
	selectVideoPage 0xFF
	fill page=0xFF, color=0x0E
	break
	play id=0x0066, freq=0x05, vol=0x40, channel=0x03
	play id=0x0066, freq=0x07, vol=0x40, channel=0x02
	mov [0xE6], 0x00A0
	mov [0xE7], 0x0078
	mov [0xE8], 0x00FA
	video offset=CINEMATIC_045, x=[0xe6], y=[0xe7], zoom=[0x91]	;@enc=alt
	break
	video offset=CINEMATIC_045, x=[0xe6], y=[0xe7], zoom=[0x54]	;@enc=alt
	break
	video offset=CINEMATIC_046, x=[0xe6], y=[0xe7], zoom=[0xfa]	;@enc=alt
	break
	video offset=CINEMATIC_046, x=[0xe6], y=[0xe7], zoom=[0xc8]	;@enc=alt
	break
	mov [0xE8], 0x00C8
	mov [0xE9], 0x0003

LABEL_1AC4:
	sub [0xE8], 0x0016
	video offset=CINEMATIC_046, x=[0xe6], y=[0xe7], zoom=[0xe8]
	break
	djnz [0xE9], LABEL_1AC4
	mov [0xE9], 0x0002

LABEL_1AD7:
	sub [0xE8], 0x0014
	video offset=CINEMATIC_046, x=[0xe6], y=[0xe7], zoom=[0xe8]
	break
	djnz [0xE9], LABEL_1AD7
	mov [0xE9], 0x0005

LABEL_1AEA:
	sub [0xE8], 0x000A
	video offset=CINEMATIC_046, x=[0xe6], y=[0xe7], zoom=[0xe8]
	break
	djnz [0xE9], LABEL_1AEA
	sub [0xE8], 0x000A
	video offset=CINEMATIC_046, x=[0xe6], y=[0xe7], zoom=[0xe8]
	video offset=CINEMATIC_047, x=160, y=100
	setup channel=0x06, address=TWEEN_VARE8_DOWN_8_STEPS
	break
	mov [0xE8], 0x0040
	sub [0xE7], 0x0028
	mov [0xE7], 0x0064
	video offset=CINEMATIC_048, x=[0xe6], y=[0xe7], zoom=[0xe8]
	play id=0x005E, freq=0x1C, vol=0x40, channel=0x00
	play id=0x005E, freq=0x14, vol=0x40, channel=0x01
	play id=0x0079, freq=0x1C, vol=0x40, channel=0x02
	break
	sub [0xE8], 0x0003
	add [0xE7], 0x000A
	mov [0xE7], 0x0064
	video offset=CINEMATIC_049, x=[0xe6], y=100, zoom=[0xe8]
	video offset=CINEMATIC_050, x=[0xe6], y=[0xe7], zoom=[0xe8]
	break
	mov [0xE7], 0x0064
	video offset=CINEMATIC_049, x=[0xe6], y=100, zoom=[0xe8]
	video offset=CINEMATIC_050, x=[0xe6], y=[0xe7], zoom=[0xe8]
	break
	video offset=CINEMATIC_049, x=[0xe6], y=100, zoom=[0xe8]
	video offset=CINEMATIC_050, x=[0xe6], y=[0xe7], zoom=[0xe8]
	break
	video offset=CINEMATIC_051, x=[0xe6], y=92, zoom=[0xe8]
	video offset=CINEMATIC_050, x=[0xe6], y=[0xe7], zoom=[0xe8]
	setup channel=0x02, address=LABEL_1CBC
	mov [0xEA], 0x000A
	mov [0xE9], 0x005A

LABEL_1B80:
	break
	mov [0xE7], 0x0064
	video offset=CINEMATIC_051, x=[0xe6], y=[0xe9], zoom=[0xe8]
	video offset=CINEMATIC_050, x=[0xe6], y=[0xe7], zoom=[0xe8]
	add [0xE9], 0x0001
	djnz [0xEA], LABEL_1B80
	fill page=0x00, color=0x00
	call LABEL_3514
	mov [HACK_VAR_67], 0x0091
	setup channel=0x14, address=KILL_CHANNEL_LANDING
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	call LABEL_26AC
	call LABEL_B2CA
	setup channel=0x3F, address=LABEL_B53C
	killChannel
