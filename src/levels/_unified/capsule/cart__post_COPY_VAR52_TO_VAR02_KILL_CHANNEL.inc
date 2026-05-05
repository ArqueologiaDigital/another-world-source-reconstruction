LABEL_97EC:
	mov [0x63], 0x0064
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x00
	je [HACK_VAR_67], 0x8E, LABEL_9821
	je [HACK_VAR_67], 0x8A, LABEL_991F
	je [HACK_VAR_67], 0xAA, LABEL_9821
	mov [0x02], [0x52]
	sub [0x02], 0x001E
	call LABEL_9A4B
	break
	mov [0x02], [0x52]
	call LABEL_9A4B
	setup channel=0x1A, address=LABEL_97DD
	jmp LABEL_9A64
LABEL_9820:
	db 0x11

LABEL_9821:
	mov [0x63], 0x0064
	sub [0x02], 0x0050
	mov [0x32], 0x0001
	jne [HACK_VAR_67], 0xAA, LABEL_983F
	video offset=CINEMATIC_090, x=[0x01], y=160
	break
	video offset=CINEMATIC_090, x=[0x01], y=200
	break

LABEL_983F:
	video offset=CINEMATIC_090, x=[0x01], y=240
	mov [0x02], 0x012C
	setup channel=0x17, address=KILL_CHANNEL_LANDING
	break
	mov [0x0F], 0x0000
	mov [0x32], 0x0001
	break
	mov [0x32], 0x0001
	mov [0x02], [0x52]
	break
	je [HACK_VAR_67], 0xCE, INIT_VARS_03_32_02
	mov [0x32], 0x0001
	video offset=CINEMATIC_090, x=[0x01], y=77
	mov [0x02], [0x52]
	break
	mov [0x32], 0x0001
	video offset=CINEMATIC_090, x=[0x01], y=146
	break
	video offset=CINEMATIC_090, x=[0x01], y=189
	mov [0x02], [0x52]
	setup channel=0x1A, address=LABEL_97DD
	jmp LABEL_9A64

LABEL_988A:
	mov [0x63], 0x0064
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x00
	je [HACK_VAR_67], 0xEE, LABEL_98BF
	je [HACK_VAR_67], 0xAA, LABEL_996E
	je [HACK_VAR_67], 0xC8, LABEL_98BF
	mov [0x02], [0x51]
	add [0x02], 0x001E
	call LABEL_9A31
	break
	mov [0x02], [0x51]
	call LABEL_9A31
	setup channel=0x1A, address=LABEL_97CE
	jmp LABEL_9A64
LABEL_98BE:
	db 0x11

LABEL_98BF:
	mov [0x63], 0x0064
	sub [0x02], 0x0064
	je [HACK_VAR_67], 0xAA, LABEL_98D7
	mov [0x32], 0x0001
	video offset=CINEMATIC_092, x=[0x01], y=115
	break

LABEL_98D7:
	mov [0x32], 0x0001
	video offset=CINEMATIC_092, x=[0x01], y=60
	setup channel=0x17, address=KILL_CHANNEL_LANDING
	break
	mov [0x0F], 0x0000
	mov [0x32], 0x0001
	video offset=CINEMATIC_092, x=[0x01], y=65529
	break
	mov [0x02], [0x51]
	break
	je [HACK_VAR_67], 0xCE, INIT_VARS_03_32_02_1
	video offset=CINEMATIC_092, x=[0x01], y=180
	jne [HACK_VAR_67], 0xAA, LABEL_9915
	break
	video offset=CINEMATIC_092, x=[0x01], y=130
	break
	video offset=CINEMATIC_092, x=[0x01], y=70

LABEL_9915:
	mov [0x02], [0x51]
	setup channel=0x1A, address=LABEL_97CE
	jmp LABEL_9A64

LABEL_991F:
	mov [0x63], 0x0064
	sub [0x02], 0x001E
	mov [0x32], 0x0001
	video offset=CINEMATIC_090, x=[0x01], y=240
	mov [0x02], 0x012C
	break
	setup channel=0x17, address=KILL_CHANNEL_LANDING
	mov [0x32], 0x0001
	break
	mov [0x0F], 0x0000
	mov [0x32], 0x0001
	mov [0x02], [0x52]
	break
	mov [0x01], 0x0036
	mov [0x32], 0x0009
	video offset=CINEMATIC_090, x=[0x01], y=40
	mov [0x02], [0x52]
	break
	mov [0x32], 0x0009
	video offset=CINEMATIC_090, x=[0x01], y=80
	mov [0x02], [0x52]
	setup channel=0x1A, address=LABEL_97DD
	jmp LABEL_9A64

LABEL_996E:
	mov [0x63], 0x0064
	sub [0x02], 0x0064
	mov [0x32], 0x0001
	video offset=CINEMATIC_092, x=[0x01], y=40
	break
	mov [0x32], 0x0001
	video offset=CINEMATIC_092, x=[0x01], y=65524
	break
	mov [0x02], [0x51]
	break
	mov [0x32], 0x0009
	mov [0x01], 0x0029
	video offset=CINEMATIC_092, x=[0x01], y=180
	mov [0x02], [0x51]
	setup channel=0x1A, address=LABEL_97CE
	jmp LABEL_9A64
