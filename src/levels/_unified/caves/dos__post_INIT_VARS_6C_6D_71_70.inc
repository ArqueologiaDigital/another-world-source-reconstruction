DELAY_LOOP_VAR70:
	break
	djnz [0x70], DELAY_LOOP_VAR70
	mov [0x71], 0xFFFF
	mov [0x70], 0x0004

LABEL_0D77:
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
	djnz [0x70], LABEL_0D77
	mov [0x70], 0x0006

LABEL_0DA4:
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
	djnz [0x70], LABEL_0DA4
	mov [0x70], 0x0005

LABEL_0DD1:
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
	djnz [0x70], LABEL_0DD1
	mov [0x70], 0x0002

LABEL_0DFE:
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
	djnz [0x70], LABEL_0DFE
	mov [0x71], 0x0001
	mov [0x70], 0x0002

LABEL_0E2F:
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
	djnz [0x70], LABEL_0E2F
	mov [0x70], 0x0003

LABEL_0E5C:
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
	djnz [0x70], LABEL_0E5C
	mov [0x70], 0x0010

LABEL_0E89:
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
	djnz [0x70], LABEL_0E89
	mov [0x70], 0x0006

LABEL_0EB6:
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
	djnz [0x70], LABEL_0EB6
	mov [0x70], 0x0006

LABEL_0EE3:
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
	djnz [0x70], LABEL_0EE3
	mov [0x71], 0xFFFF
	mov [0x70], 0x0006

LABEL_0F14:
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
	djnz [0x70], LABEL_0F14
	mov [0x70], 0x0008

LABEL_0F41:
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
	djnz [0x70], LABEL_0F41
	mov [0x6D], 0x0006
	mov [0x71], 0x0064
	killChannel

LABEL_0F73:
	deleteChannels first=0x00, last=0x3B
	setup channel=0x01, address=LABEL_0F80
	setup channel=0x3C, address=LABEL_DD4D
	break

LABEL_0F80:
	setPalette 0x07
	fill page=0x00, color=0x00
	fill page=0xFF, color=0x00
	video offset=CINEMATIC_688, x=160, y=100
	video offset=CINEMATIC_689, x=160, y=100
	break
	play id=0x007B, freq=0x05, vol=0x10, channel=0x00
	video offset=CINEMATIC_688, x=160, y=100, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_689, x=160, y=100, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_690, x=160, y=100
	video offset=CINEMATIC_691, x=160, y=100
	play id=0x007C, freq=0x22, vol=0x18, channel=0x01
	break
	video offset=CINEMATIC_692, x=160, y=100, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_693, x=160, y=100, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_692, x=160, y=100
	video offset=CINEMATIC_693, x=160, y=100
	break
	play id=0x007C, freq=0x1C, vol=0x20, channel=0x03
	video offset=CINEMATIC_688, x=160, y=100, zoom=[0x22]	;@enc=alt
	video offset=CINEMATIC_689, x=160, y=100, zoom=[0x22]	;@enc=alt
	video offset=CINEMATIC_694, x=160, y=100
	video offset=CINEMATIC_695, x=160, y=100
	break
	video offset=CINEMATIC_690, x=160, y=100, zoom=[0x22]	;@enc=alt
	video offset=CINEMATIC_691, x=160, y=100, zoom=[0x22]	;@enc=alt
	video offset=CINEMATIC_696, x=160, y=100
	video offset=CINEMATIC_697, x=160, y=100
	break
	video offset=CINEMATIC_692, x=160, y=100, zoom=[0x24]	;@enc=alt
	video offset=CINEMATIC_693, x=160, y=100, zoom=[0x24]	;@enc=alt
	video offset=CINEMATIC_698, x=160, y=100
	video offset=CINEMATIC_699, x=160, y=100
	break
	play id=0x007C, freq=0x22, vol=0x18, channel=0x01
	video offset=CINEMATIC_694, x=160, y=100, zoom=[0x24]	;@enc=alt
	video offset=CINEMATIC_695, x=160, y=100, zoom=[0x24]	;@enc=alt
	video offset=CINEMATIC_700, x=160, y=100
	video offset=CINEMATIC_701, x=160, y=100
	break
	video offset=CINEMATIC_696, x=160, y=100, zoom=[0x28]	;@enc=alt
	video offset=CINEMATIC_697, x=160, y=100, zoom=[0x28]	;@enc=alt
	video offset=CINEMATIC_698, x=160, y=100, zoom=[0x64]	;@enc=alt
	break
	play id=0x007B, freq=0x05, vol=0x10, channel=0x00
	play id=0x007C, freq=0x22, vol=0x18, channel=0x01
	video offset=CINEMATIC_698, x=160, y=100, zoom=[0x2d]	;@enc=alt
	video offset=CINEMATIC_699, x=160, y=100, zoom=[0x2d]	;@enc=alt
	video offset=CINEMATIC_694, x=160, y=100, zoom=[0xb4]	;@enc=alt
	break
	video offset=CINEMATIC_696, x=160, y=100, zoom=[0x32]	;@enc=alt
	video offset=CINEMATIC_697, x=160, y=100, zoom=[0x32]	;@enc=alt
	video offset=CINEMATIC_692, x=160, y=100, zoom=[0xc8]	;@enc=alt
	jmp LABEL_107C
	break
	video offset=CINEMATIC_690, x=160, y=100, zoom=[0x36]	;@enc=alt
	video offset=CINEMATIC_690, x=160, y=100, zoom=[0xfa]	;@enc=alt

LABEL_107C:
	break
	play id=0x007C, freq=0x22, vol=0x40, channel=0x01
	play id=0x0077, freq=0x22, vol=0x20, channel=0x00
	video offset=CINEMATIC_688, x=120, y=100, zoom=[0xff]	;@enc=alt
	video offset=CINEMATIC_689, x=120, y=100, zoom=[0xff]	;@enc=alt
	setup channel=0x3C, address=LABEL_3FAD
	break
	fill page=0x03, color=0x00
	setPalette 0x07
	break
	setPalette 0x07
	mov [0x03], 0x000A
	setup channel=0x3F, address=LABEL_0184
	killChannel
	video offset=CINEMATIC_688, x=160, y=100
	break
	video offset=CINEMATIC_690, x=160, y=100
	video offset=CINEMATIC_691, x=160, y=100
	break
	video offset=CINEMATIC_692, x=160, y=100
	video offset=CINEMATIC_693, x=160, y=100
	break
	video offset=CINEMATIC_694, x=160, y=100
	video offset=CINEMATIC_695, x=160, y=100
	break
	video offset=CINEMATIC_696, x=160, y=100
	video offset=CINEMATIC_697, x=160, y=100
	break
	video offset=CINEMATIC_698, x=160, y=100
	video offset=CINEMATIC_699, x=160, y=100
	break
	video offset=CINEMATIC_700, x=160, y=100
	video offset=CINEMATIC_701, x=160, y=100
	break
	video offset=CINEMATIC_698, x=160, y=100, zoom=[0x50]	;@enc=alt
	break
	video offset=CINEMATIC_696, x=160, y=100, zoom=[0x78]	;@enc=alt
	break
	video offset=CINEMATIC_694, x=160, y=100, zoom=[0xdc]	;@enc=alt
	break
	video offset=CINEMATIC_690, x=160, y=100, zoom=[0xfa]	;@enc=alt

LABEL_1103:
	break
	video offset=CINEMATIC_688, x=120, y=100, zoom=[0xff]	;@enc=alt
	jmp LABEL_1103
LABEL_110D:
	db 0x11

LABEL_110E:
	video offset=CINEMATIC_267, x=160, y=100
	video offset=CINEMATIC_268, x=164, y=100
	video offset=CINEMATIC_269, x=168, y=100
	video offset=CINEMATIC_270, x=172, y=100
	break
	video offset=CINEMATIC_268, x=160, y=100
	video offset=CINEMATIC_269, x=164, y=100
	video offset=CINEMATIC_270, x=168, y=100
	video offset=CINEMATIC_267, x=172, y=100
	break
	video offset=CINEMATIC_269, x=160, y=100
	video offset=CINEMATIC_270, x=164, y=100
	video offset=CINEMATIC_267, x=168, y=100
	video offset=CINEMATIC_268, x=172, y=100
	break
	video offset=CINEMATIC_270, x=160, y=100
	video offset=CINEMATIC_267, x=164, y=100
	video offset=CINEMATIC_268, x=168, y=100
	video offset=CINEMATIC_269, x=172, y=100
	break
	jmp LABEL_110E
LABEL_1155:
	db 0x11
