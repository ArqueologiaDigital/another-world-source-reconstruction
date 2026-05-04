DELAY_LOOP_VAR70:
	break
	djnz [0x70], DELAY_LOOP_VAR70
	mov [0x71], 0xFFFF
	mov [0x70], 0x0004

LABEL_0D56:
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
	djnz [0x70], LABEL_0D56
	mov [0x70], 0x0006

LABEL_0D83:
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
	djnz [0x70], LABEL_0D83
	mov [0x70], 0x0005

LABEL_0DB0:
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
	djnz [0x70], LABEL_0DB0
	mov [0x70], 0x0002

LABEL_0DDD:
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
	djnz [0x70], LABEL_0DDD
	mov [0x71], 0x0001
	mov [0x70], 0x0002

LABEL_0E0E:
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
	djnz [0x70], LABEL_0E0E
	mov [0x70], 0x0003

LABEL_0E3B:
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
	djnz [0x70], LABEL_0E3B
	mov [0x70], 0x0010

LABEL_0E68:
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
	djnz [0x70], LABEL_0E68
	mov [0x70], 0x0006

LABEL_0E95:
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
	djnz [0x70], LABEL_0E95
	mov [0x70], 0x0006

LABEL_0EC2:
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
	djnz [0x70], LABEL_0EC2
	mov [0x71], 0xFFFF
	mov [0x70], 0x0006

LABEL_0EF3:
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
	djnz [0x70], LABEL_0EF3
	mov [0x70], 0x0008

LABEL_0F20:
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
	djnz [0x70], LABEL_0F20
	mov [0x6D], 0x0006
	mov [0x71], 0x0064
	killChannel

LABEL_0F52:
	deleteChannels first=0x00, last=0x3B
	setup channel=0x01, address=LABEL_0F5F
	setup channel=0x3C, address=LABEL_D839
	break

LABEL_0F5F:
	setPalette 0x07
	fill page=0x00, color=0x00
	fill page=0xFF, color=0x00
	video type=1, offset=CINEMATIC_676, x=160, y=100
	video type=1, offset=CINEMATIC_677, x=160, y=100
	break
	play id=0x007B, freq=0x05, vol=0x10, channel=0x00
	video type=1, offset=CINEMATIC_676, x=160, y=100, zoom=[0x20]	;@enc=alt
	video type=1, offset=CINEMATIC_677, x=160, y=100, zoom=[0x20]	;@enc=alt
	video type=1, offset=CINEMATIC_678, x=160, y=100
	video type=1, offset=CINEMATIC_679, x=160, y=100
	play id=0x007C, freq=0x22, vol=0x18, channel=0x01
	break
	video type=1, offset=CINEMATIC_680, x=160, y=100, zoom=[0x20]	;@enc=alt
	video type=1, offset=CINEMATIC_681, x=160, y=100, zoom=[0x20]	;@enc=alt
	video type=1, offset=CINEMATIC_680, x=160, y=100
	video type=1, offset=CINEMATIC_681, x=160, y=100
	break
	play id=0x007C, freq=0x1C, vol=0x20, channel=0x03
	video type=1, offset=CINEMATIC_676, x=160, y=100, zoom=[0x22]	;@enc=alt
	video type=1, offset=CINEMATIC_677, x=160, y=100, zoom=[0x22]	;@enc=alt
	video type=1, offset=CINEMATIC_682, x=160, y=100
	video type=1, offset=CINEMATIC_683, x=160, y=100
	break
	video type=1, offset=CINEMATIC_678, x=160, y=100, zoom=[0x22]	;@enc=alt
	video type=1, offset=CINEMATIC_679, x=160, y=100, zoom=[0x22]	;@enc=alt
	video type=1, offset=CINEMATIC_684, x=160, y=100
	video type=1, offset=CINEMATIC_685, x=160, y=100
	break
	video type=1, offset=CINEMATIC_680, x=160, y=100, zoom=[0x24]	;@enc=alt
	video type=1, offset=CINEMATIC_681, x=160, y=100, zoom=[0x24]	;@enc=alt
	video type=1, offset=CINEMATIC_686, x=160, y=100
	video type=1, offset=CINEMATIC_687, x=160, y=100
	break
	play id=0x007C, freq=0x22, vol=0x18, channel=0x01
	video type=1, offset=CINEMATIC_682, x=160, y=100, zoom=[0x24]	;@enc=alt
	video type=1, offset=CINEMATIC_683, x=160, y=100, zoom=[0x24]	;@enc=alt
	video type=1, offset=CINEMATIC_688, x=160, y=100
	video type=1, offset=CINEMATIC_689, x=160, y=100
	break
	video type=1, offset=CINEMATIC_684, x=160, y=100, zoom=[0x28]	;@enc=alt
	video type=1, offset=CINEMATIC_685, x=160, y=100, zoom=[0x28]	;@enc=alt
	video type=1, offset=CINEMATIC_686, x=160, y=100, zoom=[0x64]	;@enc=alt
	break
	play id=0x007B, freq=0x05, vol=0x10, channel=0x00
	play id=0x007C, freq=0x22, vol=0x18, channel=0x01
	video type=1, offset=CINEMATIC_686, x=160, y=100, zoom=[0x2d]	;@enc=alt
	video type=1, offset=CINEMATIC_687, x=160, y=100, zoom=[0x2d]	;@enc=alt
	video type=1, offset=CINEMATIC_682, x=160, y=100, zoom=[0xb4]	;@enc=alt
	break
	video type=1, offset=CINEMATIC_684, x=160, y=100, zoom=[0x32]	;@enc=alt
	video type=1, offset=CINEMATIC_685, x=160, y=100, zoom=[0x32]	;@enc=alt
	video type=1, offset=CINEMATIC_680, x=160, y=100, zoom=[0xc8]	;@enc=alt
	jmp LABEL_105B
LABEL_104E:
	db 0x06, 0x6A, 0x68, 0xFE, 0xA0, 0x64, 0x36, 0x6A
	db 0x68, 0xFE, 0xA0, 0x64, 0xFA

LABEL_105B:
	break
	play id=0x007C, freq=0x22, vol=0x40, channel=0x01
	play id=0x0077, freq=0x22, vol=0x20, channel=0x00
	video type=1, offset=CINEMATIC_676, x=120, y=100, zoom=[0xff]	;@enc=alt
	video type=1, offset=CINEMATIC_677, x=120, y=100, zoom=[0xff]	;@enc=alt
	setup channel=0x3C, address=LABEL_3D6B
	break
	fill page=0x03, color=0x00
	setPalette 0x07
	break
	setPalette 0x07
	mov [0x03], 0x000A
	setup channel=0x3F, address=LABEL_016F
	killChannel
	video type=1, offset=CINEMATIC_676, x=160, y=100
	break
	video type=1, offset=CINEMATIC_678, x=160, y=100
	video type=1, offset=CINEMATIC_679, x=160, y=100
	break
	video type=1, offset=CINEMATIC_680, x=160, y=100
	video type=1, offset=CINEMATIC_681, x=160, y=100
	break
	video type=1, offset=CINEMATIC_682, x=160, y=100
	video type=1, offset=CINEMATIC_683, x=160, y=100
	break
	video type=1, offset=CINEMATIC_684, x=160, y=100
	video type=1, offset=CINEMATIC_685, x=160, y=100
	break
	video type=1, offset=CINEMATIC_686, x=160, y=100
	video type=1, offset=CINEMATIC_687, x=160, y=100
	break
	video type=1, offset=CINEMATIC_688, x=160, y=100
	video type=1, offset=CINEMATIC_689, x=160, y=100
	break
	video type=1, offset=CINEMATIC_686, x=160, y=100, zoom=[0x50]	;@enc=alt
	break
	video type=1, offset=CINEMATIC_684, x=160, y=100, zoom=[0x78]	;@enc=alt
	break
	video type=1, offset=CINEMATIC_682, x=160, y=100, zoom=[0xdc]	;@enc=alt
	break
	video type=1, offset=CINEMATIC_678, x=160, y=100, zoom=[0xfa]	;@enc=alt

LABEL_10E2:
	break
	video type=1, offset=CINEMATIC_676, x=120, y=100, zoom=[0xff]	;@enc=alt
	jmp LABEL_10E2
LABEL_10EC:
	db 0x11

LABEL_10ED:
	video type=1, offset=CINEMATIC_249, x=160, y=100
	video type=1, offset=CINEMATIC_250, x=164, y=100
	video type=1, offset=CINEMATIC_251, x=168, y=100
	video type=1, offset=CINEMATIC_252, x=172, y=100
	break
	video type=1, offset=CINEMATIC_250, x=160, y=100
	video type=1, offset=CINEMATIC_251, x=164, y=100
	video type=1, offset=CINEMATIC_252, x=168, y=100
	video type=1, offset=CINEMATIC_249, x=172, y=100
	break
	video type=1, offset=CINEMATIC_251, x=160, y=100
	video type=1, offset=CINEMATIC_252, x=164, y=100
	video type=1, offset=CINEMATIC_249, x=168, y=100
	video type=1, offset=CINEMATIC_250, x=172, y=100
	break
	video type=1, offset=CINEMATIC_252, x=160, y=100
	video type=1, offset=CINEMATIC_249, x=164, y=100
	video type=1, offset=CINEMATIC_250, x=168, y=100
	video type=1, offset=CINEMATIC_251, x=172, y=100
	break
	jmp LABEL_10ED
LABEL_1134:
	db 0x11
