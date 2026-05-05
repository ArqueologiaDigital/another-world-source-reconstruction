LABEL_13C5:
	call GUARDED_DRAW_CV_304_305
	break
	djnz [0x29], LABEL_13C5
	mov [0x0E], 0x0000
	mov [0x29], 0x0005

LABEL_13D5:
	call LABEL_83CB
	break
	djnz [0x29], LABEL_13D5
	play id=0x0070, freq=0x0D, vol=0x40, channel=0x03
	mov [0x0E], 0x0003
	call GUARDED_DRAW_CV_304_305
	break
	call LABEL_83CB
	break
	mov [0x0E], 0x0005
	call LABEL_83E9
	break
	mov [0x0E], 0x000A
	call LABEL_83CB
	jmp LABEL_1402
LABEL_1401:
	db 0x11

LABEL_1402:
	setup channel=0x34, address=LABEL_1450
	play id=0x0072, freq=0x0D, vol=0x40, channel=0x03

LABEL_140C:
	mov [0x0E], 0x0000
	mov [0x29], 0x0005

LABEL_1414:
	call LABEL_83E9
	break
	call LABEL_83E9
	break
	call LABEL_83E9
	break
	call LABEL_83E9
	break
	call LABEL_83E9
	break
	mov [0x0E], 0x0007
	call GUARDED_DRAW_CV_304_305
	break
	call LABEL_83CB
	break
	mov [0x0E], 0x0007
	call LABEL_83E9
	break
	mov [0x0E], 0x0004
	call LABEL_83CB
	break
	djnz [0x29], LABEL_1414
	setup channel=0x34, address=LABEL_1480
	jmp LABEL_140C
LABEL_144F:
	db 0x11

LABEL_1450:
	video offset=CINEMATIC_179, x=[0x78], y=[0x79], zoom=0x40
	break
	video offset=CINEMATIC_180, x=[0x78], y=[0x79], zoom=0x40
	mov [0xB7], 0x0001

LABEL_145F:
	break
	video offset=CINEMATIC_181, x=[0x78], y=[0x79], zoom=0x40
	jne [HERO_ACTION], 0x01, LABEL_145F
	and [0x04], 0x3FFF
	setup channel=0x14, address=LABEL_14A1
	setup channel=0x27, address=LABEL_14FE

LABEL_1477:
	break
	video offset=CINEMATIC_142, x=[0x78], y=[0x79], zoom=0x40
	jmp LABEL_1477

LABEL_1480:
	video offset=CINEMATIC_142, x=[0x78], y=[0x79], zoom=0x40
	and [0x04], 0x3FFF
	setup channel=0x27, address=LABEL_14DE
	setup channel=0x16, address=LABEL_DF3B
	setup channel=0x14, address=LABEL_E54E
	mov [0x01], [0x78]
	sub [0x01], 0x001E
	sub [0x02], 0x0014
	killChannel

LABEL_14A1:
	video offset=CINEMATIC_143, x=[0x78], y=[0x79], zoom=0x40
	mov [PAUSE_SLICES], 0x0004
	video offset=CINEMATIC_144, x=[0x78], y=[0x79], zoom=0x40
	break
	video offset=CINEMATIC_145, x=[0x78], y=[0x79], zoom=0x40
	video offset=CINEMATIC_146, x=[0x78], y=[0x79], zoom=0x40
	break
	video offset=CINEMATIC_147, x=[0x78], y=[0x79], zoom=0x40
	setup channel=0x16, address=LABEL_DF3B
	break
	play id=0x005E, freq=0x14, vol=0x40, channel=0x01
	and [0x04], 0x3FFF
	mov [0x01], [0x78]
	sub [0x01], 0x001E
	sub [0x02], 0x0014
	jmp LABEL_E54E
LABEL_14DD:
	db 0x11

LABEL_14DE:
	call GUARDED_DRAW_CV_304_305
	deleteChannels first=0x34, last=0x35
	and [0x09], 0xFBFF
	break
	or [0x11], 0x2000
	call LABEL_83CB
	break
	mov [0x12], 0x2010
	mov [0x2F], 0x0008
	jmp DISPATCH_VAR2F_STATE
LABEL_14FD:
	db 0x11

LABEL_14FE:
	mov [0x29], 0x0002
	call GUARDED_DRAW_CV_304_305

LABEL_1505:
	break
	call GUARDED_DRAW_CV_304_305
	djnz [0x29], LABEL_1505
	deleteChannels first=0x34, last=0x35
	and [0x09], 0xFBFF
	break
	play id=0x0075, freq=0x0F, vol=0x40, channel=0x03
	video offset=CINEMATIC_182, x=[0x78], y=[0x79], zoom=0x40
	break
	video offset=CINEMATIC_183, x=[0x78], y=[0x79], zoom=0x40
	mov [0x29], 0x0003

LABEL_152B:
	break
	call LABEL_15D1
	video offset=CINEMATIC_184, x=[0x78], y=[0x79], zoom=0x40
	djnz [0x29], LABEL_152B
	mov [0x29], 0x0005

LABEL_153C:
	break
	call LABEL_15D1
	video offset=CINEMATIC_185, x=[0x78], y=[0x79], zoom=0x40
	djnz [0x29], LABEL_153C
	play id=0x0088, freq=0x0A, vol=0x40, channel=0x03
	mov [0x29], 0x0004

LABEL_1553:
	break
	call LABEL_15D1
	video offset=CINEMATIC_184, x=[0x78], y=[0x79], zoom=0x40
	djnz [0x29], LABEL_1553
	mov [0x29], 0x0003

LABEL_1564:
	break
	call LABEL_15D1
	video offset=CINEMATIC_185, x=[0x78], y=[0x79], zoom=0x40
	djnz [0x29], LABEL_1564
	mov [0x29], [0x78]

LABEL_1574:
	break
	call LABEL_15D1
	call LABEL_9123
	break
	call LABEL_9123
	call LABEL_15D1
	break
	call LABEL_15D1
	jne [HACK_VAR_67], [0x10], LABEL_15DD
	sub [0x78], 0x0007
	add [0x79], 0x0006
	video type=0, offset=COMMON_VIDEO_243, x=[0x78], y=[0x79], zoom=0x40
	sub [0x79], 0x0006
	add [0x78], 0x0007
	video offset=CINEMATIC_184, x=[0x78], y=[0x79], zoom=0x40
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0023
	sub [0x27], 0x0018
	sub [0x29], 0x0011
	jl [0x29], 0x32, LABEL_14DE
	jg [0x01], [0x29], LABEL_15CA
	call LABEL_6255
	jmp LABEL_1574

LABEL_15CA:
	call LABEL_625D
	jmp LABEL_1574
LABEL_15D0:
	db 0x11

LABEL_15D1:
	jl [0x01], 0x0105, SHARED_RET
	setup channel=0x27, address=LABEL_15DD
	ret

LABEL_15DD:
	mov [0x12], 0x4010
	call STATE_VAR12_BIG_DISPATCH
	jmp DISPATCH_VAR2F_STATE
LABEL_15E7:
	db 0x11

LABEL_15E8:
	video offset=CINEMATIC_187, x=[0x78], y=[0x79], zoom=0x40
	mov [PAUSE_SLICES], 0x0008
	break
	video offset=CINEMATIC_188, x=[0x78], y=[0x79], zoom=0x40
	break
	video offset=CINEMATIC_189, x=[0x78], y=[0x79], zoom=0x40
	break
	video offset=CINEMATIC_189, x=[0x78], y=[0x79], zoom=0x40
	break
	video offset=CINEMATIC_188, x=[0x78], y=[0x79], zoom=0x40
	break
	video offset=CINEMATIC_187, x=[0x78], y=[0x79], zoom=0x40
	break
	jmp LABEL_15E8
LABEL_1613:
	db 0x11

HANG_DRAW_CIN_186:
	video offset=CINEMATIC_186, x=[0x78], y=[0x79], zoom=0x40
	break
	jmp HANG_DRAW_CIN_186
LABEL_161D:
	db 0x11

LABEL_161E:
	mov [0x0E], 0x0000
	call GUARDED_DRAW_CV_304_305
	break
	mov [0x0E], 0x0004
	call LABEL_83CB
	break
	mov [0x0E], 0x0000
	call LABEL_83E9
	break
	mov [0x29], 0x0002

LABEL_163A:
	mov [0x0E], 0x0003
	call LABEL_83E9
	break
	djnz [0x29], LABEL_163A
	mov [0x29], 0x0002

LABEL_164A:
	mov [0x0E], 0x0000
	call LABEL_83CB
	break
	djnz [0x29], LABEL_164A
	mov [0xF8], [0x07]
	sub [0xF8], [0x01]
	jl [0xF8], 0x64, LABEL_1671
	call LABEL_5BE7
	jne [0x12], 0x28, LABEL_1671
	je [0x21], 0x00, LABEL_161E

LABEL_1671:
	mov [0x12], 0x2010
	mov [0x2F], 0x0008
	mov [0x29], 0x0002
	jmp DISPATCH_VAR2F_STATE
LABEL_1680:
	db 0x11

LABEL_1681:
	video type=0, offset=COMMON_VIDEO_014, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_015, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0006
	break
	setup channel=0x02, address=KILL_CHANNEL_LANDING
	video type=0, offset=COMMON_VIDEO_016, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	call SET_VAR04_TO_0008
	break
	video type=0, offset=COMMON_VIDEO_017, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_018, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_019, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0005
	break
	mov [0x0A], 0x0001
	video type=0, offset=COMMON_VIDEO_021, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_030, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_031, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_032, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_033, x=[0x01], y=[0x02], zoom=0x40
	mov [0x2A], 0x000F
	call SET_VAR04_TO_0010
	jmp LABEL_EDDA
LABEL_16F3:
	db 0x11
