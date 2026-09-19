DELAY_LOOP_VAR70:
	break
	djnz [0x70], DELAY_LOOP_VAR70
	mov [0x71], 0xFFFF
	mov [0x70], 0x0004

CAVES_AMBIENT_DRIFT_PATH_HERO_LOW_PHASE_1:
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
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_LOW_PHASE_1
	mov [0x70], 0x0006

CAVES_AMBIENT_DRIFT_PATH_HERO_LOW_PHASE_2:
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
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_LOW_PHASE_2
	mov [0x70], 0x0005

CAVES_AMBIENT_DRIFT_PATH_HERO_LOW_PHASE_3:
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
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_LOW_PHASE_3
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

CAVES_AMBIENT_DRIFT_PATH_HERO_LOW_PHASE_5:
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
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_LOW_PHASE_5
	mov [0x70], 0x0003

CAVES_AMBIENT_DRIFT_PATH_HERO_LOW_PHASE_6:
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
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_LOW_PHASE_6
	mov [0x70], 0x0010

CAVES_AMBIENT_DRIFT_PATH_HERO_LOW_PHASE_7:
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
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_LOW_PHASE_7
	mov [0x70], 0x0006

CAVES_AMBIENT_DRIFT_PATH_HERO_LOW_PHASE_8:
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
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_LOW_PHASE_8
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

CAVES_AMBIENT_DRIFT_PATH_HERO_LOW_PHASE_10:
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
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_LOW_PHASE_10
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
	video offset=CINEMATIC_676, x=160, y=100
	video offset=CINEMATIC_677, x=160, y=100
	break
	play id=0x007B, freq=0x05, vol=0x10, channel=0x00
	video offset=CINEMATIC_676, x=160, y=100, zoom=0x20
	video offset=CINEMATIC_677, x=160, y=100, zoom=0x20
	video offset=CINEMATIC_678, x=160, y=100
	video offset=CINEMATIC_679, x=160, y=100
	play id=0x007C, freq=0x22, vol=0x18, channel=0x01
	break
	video offset=CINEMATIC_680, x=160, y=100, zoom=0x20
	video offset=CINEMATIC_681, x=160, y=100, zoom=0x20
	video offset=CINEMATIC_680, x=160, y=100
	video offset=CINEMATIC_681, x=160, y=100
	break
	play id=0x007C, freq=0x1C, vol=0x20, channel=0x03
	video offset=CINEMATIC_676, x=160, y=100, zoom=0x22
	video offset=CINEMATIC_677, x=160, y=100, zoom=0x22
	video offset=CINEMATIC_682, x=160, y=100
	video offset=CINEMATIC_683, x=160, y=100
	break
	video offset=CINEMATIC_678, x=160, y=100, zoom=0x22
	video offset=CINEMATIC_679, x=160, y=100, zoom=0x22
	video offset=CINEMATIC_684, x=160, y=100
	video offset=CINEMATIC_685, x=160, y=100
	break
	video offset=CINEMATIC_680, x=160, y=100, zoom=0x24
	video offset=CINEMATIC_681, x=160, y=100, zoom=0x24
	video offset=CINEMATIC_686, x=160, y=100
	video offset=CINEMATIC_687, x=160, y=100
	break
	play id=0x007C, freq=0x22, vol=0x18, channel=0x01
	video offset=CINEMATIC_682, x=160, y=100, zoom=0x24
	video offset=CINEMATIC_683, x=160, y=100, zoom=0x24
	video offset=CINEMATIC_688, x=160, y=100
	video offset=CINEMATIC_689, x=160, y=100
	break
	video offset=CINEMATIC_684, x=160, y=100, zoom=0x28
	video offset=CINEMATIC_685, x=160, y=100, zoom=0x28
	video offset=CINEMATIC_686, x=160, y=100, zoom=0x64
	break
	play id=0x007B, freq=0x05, vol=0x10, channel=0x00
	play id=0x007C, freq=0x22, vol=0x18, channel=0x01
	video offset=CINEMATIC_686, x=160, y=100, zoom=0x2d
	video offset=CINEMATIC_687, x=160, y=100, zoom=0x2d
	video offset=CINEMATIC_682, x=160, y=100, zoom=0xb4
	break
	video offset=CINEMATIC_684, x=160, y=100, zoom=0x32
	video offset=CINEMATIC_685, x=160, y=100, zoom=0x32
	video offset=CINEMATIC_680, x=160, y=100, zoom=0xc8
	jmp LABEL_105B
LABEL_104E:
	db 0x06, 0x6A, 0x68, 0xFE, 0xA0, 0x64, 0x36, 0x6A
	db 0x68, 0xFE, 0xA0, 0x64, 0xFA

LABEL_105B:
	break
	play id=0x007C, freq=0x22, vol=0x40, channel=0x01
	play id=0x0077, freq=0x22, vol=0x20, channel=0x00
	video offset=CINEMATIC_676, x=120, y=100, zoom=0xff
	video offset=CINEMATIC_677, x=120, y=100, zoom=0xff
	setup channel=0x3C, address=LABEL_3D6B
	break
	fill page=0x03, color=0x00
	setPalette 0x07
	break
	setPalette 0x07
	mov [0x03], 0x000A
	setup channel=0x3F, address=CAVES_INLINE_SET_VAR01_TO_E_L1
	killChannel
	video offset=CINEMATIC_676, x=160, y=100
	break
	video offset=CINEMATIC_678, x=160, y=100
	video offset=CINEMATIC_679, x=160, y=100
	break
	video offset=CINEMATIC_680, x=160, y=100
	video offset=CINEMATIC_681, x=160, y=100
	break
	video offset=CINEMATIC_682, x=160, y=100
	video offset=CINEMATIC_683, x=160, y=100
	break
	video offset=CINEMATIC_684, x=160, y=100
	video offset=CINEMATIC_685, x=160, y=100
	break
	video offset=CINEMATIC_686, x=160, y=100
	video offset=CINEMATIC_687, x=160, y=100
	break
	video offset=CINEMATIC_688, x=160, y=100
	video offset=CINEMATIC_689, x=160, y=100
	break
	video offset=CINEMATIC_686, x=160, y=100, zoom=0x50
	break
	video offset=CINEMATIC_684, x=160, y=100, zoom=0x78
	break
	video offset=CINEMATIC_682, x=160, y=100, zoom=0xdc
	break
	video offset=CINEMATIC_678, x=160, y=100, zoom=0xfa

CAVES_BURST_CHUNKS_FINAL_HOLD_LOOP:
	break
	video offset=CINEMATIC_676, x=120, y=100, zoom=0xff
	jmp CAVES_BURST_CHUNKS_FINAL_HOLD_LOOP
LABEL_10EC:
	db 0x11

LABEL_10ED:
	video offset=CINEMATIC_249, x=160, y=100
	video offset=CINEMATIC_250, x=164, y=100
	video offset=CINEMATIC_251, x=168, y=100
	video offset=CINEMATIC_252, x=172, y=100
	break
	video offset=CINEMATIC_250, x=160, y=100
	video offset=CINEMATIC_251, x=164, y=100
	video offset=CINEMATIC_252, x=168, y=100
	video offset=CINEMATIC_249, x=172, y=100
	break
	video offset=CINEMATIC_251, x=160, y=100
	video offset=CINEMATIC_252, x=164, y=100
	video offset=CINEMATIC_249, x=168, y=100
	video offset=CINEMATIC_250, x=172, y=100
	break
	video offset=CINEMATIC_252, x=160, y=100
	video offset=CINEMATIC_249, x=164, y=100
	video offset=CINEMATIC_250, x=168, y=100
	video offset=CINEMATIC_251, x=172, y=100
	break
	jmp LABEL_10ED
LABEL_1134:
	db 0x11
