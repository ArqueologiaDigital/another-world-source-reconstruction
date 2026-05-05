DELAY_LOOP_VAR70:
	break
	djnz [0x70], DELAY_LOOP_VAR70
	mov [0x71], 0xFFFF
	mov [0x70], 0x0004

LABEL_0CFD:
	break
	add [0x6E], 0x0580
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x0700
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	add [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], LABEL_0CFD
	mov [0x70], 0x0006

LABEL_0D2A:
	break
	add [0x6E], 0x0BAA
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x01AA
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	add [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], LABEL_0D2A
	mov [0x70], 0x0005

LABEL_0D57:
	break
	add [0x6E], 0x0CCC
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x0199
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], LABEL_0D57
	mov [0x70], 0x0002

LABEL_0D84:
	break
	add [0x6E], 0x0500
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x0500
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], LABEL_0D84
	mov [0x71], 0x0001
	mov [0x70], 0x0002

LABEL_0DB5:
	break
	add [0x6E], 0x0280
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	add [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x0A00
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], LABEL_0DB5
	mov [0x70], 0x0003

LABEL_0DE2:
	break
	add [0x6E], 0x0A00
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	add [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x0155
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], LABEL_0DE2
	mov [0x70], 0x0010

LABEL_0E0F:
	break
	add [0x6E], 0x0CE0
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	add [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x03B0
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	add [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], LABEL_0E0F
	mov [0x70], 0x0006

LABEL_0E3C:
	break
	add [0x6E], 0x082A
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	add [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x0055
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], LABEL_0E3C
	mov [0x70], 0x0006

LABEL_0E69:
	break
	add [0x6E], 0x01AA
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	add [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x0300
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], LABEL_0E69
	mov [0x71], 0xFFFF
	mov [0x70], 0x0006

LABEL_0E9A:
	break
	add [0x6E], 0x0180
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x0155
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], LABEL_0E9A
	mov [0x70], 0x0008

LABEL_0EC7:
	break
	add [0x6E], 0x1000
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x01E0
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], LABEL_0EC7
	mov [0x6D], 0x0006
	mov [0x71], 0x0064
	killChannel

LABEL_0EF9:
	deleteChannels first=0x00, last=0x3B
	setup channel=0x01, address=LABEL_0F0C
	setup channel=0x3C, address=LABEL_DDD6
	break
	song id=0x0BDD, delay=0x0000, pos=0x00

LABEL_0F0C:
	setPalette 0x07
	jne [0xDB], 0x01, LABEL_0F18
	setPalette 0x1C

LABEL_0F18:
	fill page=0x00, color=0x00
	fill page=0xFF, color=0x00
	video offset=CINEMATIC_677, x=160, y=100
	video offset=CINEMATIC_678, x=160, y=100
	break
	play id=0x007B, freq=0x05, vol=0x10, channel=0x00
	video offset=CINEMATIC_677, x=160, y=100, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_678, x=160, y=100, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_679, x=160, y=100
	video offset=CINEMATIC_680, x=160, y=100
	play id=0x007C, freq=0x22, vol=0x18, channel=0x01
	break
	video offset=CINEMATIC_681, x=160, y=100, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_682, x=160, y=100, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_681, x=160, y=100
	video offset=CINEMATIC_682, x=160, y=100
	break
	play id=0x007C, freq=0x1C, vol=0x20, channel=0x03
	video offset=CINEMATIC_677, x=160, y=100, zoom=[0x22]	;@enc=alt
	video offset=CINEMATIC_678, x=160, y=100, zoom=[0x22]	;@enc=alt
	video offset=CINEMATIC_683, x=160, y=100
	video offset=CINEMATIC_684, x=160, y=100
	break
	video offset=CINEMATIC_679, x=160, y=100, zoom=[0x22]	;@enc=alt
	video offset=CINEMATIC_680, x=160, y=100, zoom=[0x22]	;@enc=alt
	video offset=CINEMATIC_685, x=160, y=100
	video offset=CINEMATIC_686, x=160, y=100
	break
	video offset=CINEMATIC_681, x=160, y=100, zoom=[0x24]	;@enc=alt
	video offset=CINEMATIC_682, x=160, y=100, zoom=[0x24]	;@enc=alt
	video offset=CINEMATIC_687, x=160, y=100
	video offset=CINEMATIC_688, x=160, y=100
	break
	play id=0x007C, freq=0x22, vol=0x18, channel=0x01
	video offset=CINEMATIC_683, x=160, y=100, zoom=[0x24]	;@enc=alt
	video offset=CINEMATIC_684, x=160, y=100, zoom=[0x24]	;@enc=alt
	video offset=CINEMATIC_689, x=160, y=100
	video offset=CINEMATIC_690, x=160, y=100
	break
	video offset=CINEMATIC_685, x=160, y=100, zoom=[0x28]	;@enc=alt
	video offset=CINEMATIC_686, x=160, y=100, zoom=[0x28]	;@enc=alt
	video offset=CINEMATIC_687, x=160, y=100, zoom=[0x64]	;@enc=alt
	break
	play id=0x007B, freq=0x05, vol=0x10, channel=0x00
	play id=0x007C, freq=0x22, vol=0x18, channel=0x01
	video offset=CINEMATIC_687, x=160, y=100, zoom=[0x2d]	;@enc=alt
	video offset=CINEMATIC_688, x=160, y=100, zoom=[0x2d]	;@enc=alt
	video offset=CINEMATIC_683, x=160, y=100, zoom=[0xb4]	;@enc=alt
	break
	video offset=CINEMATIC_685, x=160, y=100, zoom=[0x32]	;@enc=alt
	video offset=CINEMATIC_686, x=160, y=100, zoom=[0x32]	;@enc=alt
	video offset=CINEMATIC_681, x=160, y=100, zoom=[0xc8]	;@enc=alt
	jmp LABEL_1011
	break
	video offset=CINEMATIC_679, x=160, y=100, zoom=[0x36]	;@enc=alt
	video offset=CINEMATIC_679, x=160, y=100, zoom=[0xfa]	;@enc=alt

LABEL_1011:
	break
	play id=0x007C, freq=0x22, vol=0x40, channel=0x01
	play id=0x0077, freq=0x22, vol=0x20, channel=0x00
	video offset=CINEMATIC_677, x=120, y=100, zoom=[0xff]	;@enc=alt
	video offset=CINEMATIC_678, x=120, y=100, zoom=[0xff]	;@enc=alt
	setup channel=0x3C, address=LABEL_3F97
	break
	fill page=0x03, color=0x00
	setPalette 0x07
	break
	setPalette 0x07
	mov [0x03], 0x000A
	setup channel=0x3F, address=LABEL_0211
	killChannel
	video offset=CINEMATIC_677, x=160, y=100
	break
	video offset=CINEMATIC_679, x=160, y=100
	video offset=CINEMATIC_680, x=160, y=100
	break
	video offset=CINEMATIC_681, x=160, y=100
	video offset=CINEMATIC_682, x=160, y=100
	break
	video offset=CINEMATIC_683, x=160, y=100
	video offset=CINEMATIC_684, x=160, y=100
	break
	video offset=CINEMATIC_685, x=160, y=100
	video offset=CINEMATIC_686, x=160, y=100
	break
	video offset=CINEMATIC_687, x=160, y=100
	video offset=CINEMATIC_688, x=160, y=100
	break
	video offset=CINEMATIC_689, x=160, y=100
	video offset=CINEMATIC_690, x=160, y=100
	break
	video offset=CINEMATIC_687, x=160, y=100, zoom=[0x50]	;@enc=alt
	break
	video offset=CINEMATIC_685, x=160, y=100, zoom=[0x78]	;@enc=alt
	break
	video offset=CINEMATIC_683, x=160, y=100, zoom=[0xdc]	;@enc=alt
	break
	video offset=CINEMATIC_679, x=160, y=100, zoom=[0xfa]	;@enc=alt

LABEL_1098:
	break
	video offset=CINEMATIC_677, x=120, y=100, zoom=[0xff]	;@enc=alt
	jmp LABEL_1098
LABEL_10A2:
	db 0x11

LABEL_10A3:
	video offset=CINEMATIC_266, x=160, y=100
	video offset=CINEMATIC_267, x=164, y=100
	video offset=CINEMATIC_268, x=168, y=100
	video offset=CINEMATIC_269, x=172, y=100
	break
	video offset=CINEMATIC_267, x=160, y=100
	video offset=CINEMATIC_268, x=164, y=100
	video offset=CINEMATIC_269, x=168, y=100
	video offset=CINEMATIC_266, x=172, y=100
	break
	video offset=CINEMATIC_268, x=160, y=100
	video offset=CINEMATIC_269, x=164, y=100
	video offset=CINEMATIC_266, x=168, y=100
	video offset=CINEMATIC_267, x=172, y=100
	break
	video offset=CINEMATIC_269, x=160, y=100
	video offset=CINEMATIC_266, x=164, y=100
	video offset=CINEMATIC_267, x=168, y=100
	video offset=CINEMATIC_268, x=172, y=100
	break
	jmp LABEL_10A3
LABEL_10EA:
	db 0x11
