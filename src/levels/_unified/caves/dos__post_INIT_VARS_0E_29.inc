LABEL_1585:
	call GUARDED_DRAW_CV_304_305
	break
	djnz [0x29], LABEL_1585
	mov [0x0E], 0x0000
	mov [0x29], 0x0005

LABEL_1595:
	call LABEL_8729
	break
	djnz [0x29], LABEL_1595
	play id=0x0070, freq=0x0D, vol=0x40, channel=0x03
	mov [0x0E], 0x0003
	call GUARDED_DRAW_CV_304_305
	break
	call LABEL_8729
	break
	mov [0x0E], 0x0005
	call LABEL_8747
	break
	mov [0x0E], 0x000A
	call LABEL_8729
	jmp LABEL_15C2
LABEL_15C1:
	db 0x11

LABEL_15C2:
	setup channel=0x34, address=LABEL_1610
	play id=0x0072, freq=0x0D, vol=0x40, channel=0x03

LABEL_15CC:
	mov [0x0E], 0x0000
	mov [0x29], 0x0005

LABEL_15D4:
	call LABEL_8747
	break
	call LABEL_8747
	break
	call LABEL_8747
	break
	call LABEL_8747
	break
	call LABEL_8747
	break
	mov [0x0E], 0x0007
	call GUARDED_DRAW_CV_304_305
	break
	call LABEL_8729
	break
	mov [0x0E], 0x0007
	call LABEL_8747
	break
	mov [0x0E], 0x0004
	call LABEL_8729
	break
	djnz [0x29], LABEL_15D4
	setup channel=0x34, address=LABEL_1640
	jmp LABEL_15CC
LABEL_160F:
	db 0x11

LABEL_1610:
	video offset=CINEMATIC_179, x=[0x78], y=[0x79]
	break
	video offset=CINEMATIC_180, x=[0x78], y=[0x79]
	mov [0xB7], 0x0001

LABEL_161F:
	break
	video offset=CINEMATIC_181, x=[0x78], y=[0x79]
	jne [HERO_ACTION], 0x01, LABEL_161F
	and [0x04], 0x3FFF
	setup channel=0x14, address=LABEL_1661
	setup channel=0x27, address=LABEL_16BE

LABEL_1637:
	break
	video offset=CINEMATIC_142, x=[0x78], y=[0x79]
	jmp LABEL_1637

LABEL_1640:
	video offset=CINEMATIC_142, x=[0x78], y=[0x79]
	and [0x04], 0x3FFF
	setup channel=0x27, address=LABEL_169E
	setup channel=0x16, address=SETUP_CHAN_14_BY_VAR63
	setup channel=0x14, address=LABEL_EB39
	mov [HERO_X], [0x78]
	sub [HERO_X], 0x001E
	sub [HERO_Y], 0x0014
	killChannel

LABEL_1661:
	video offset=CINEMATIC_143, x=[0x78], y=[0x79]
	mov [PAUSE_SLICES], 0x0004
	video offset=CINEMATIC_144, x=[0x78], y=[0x79]
	break
	video offset=CINEMATIC_145, x=[0x78], y=[0x79]
	video offset=CINEMATIC_146, x=[0x78], y=[0x79]
	break
	video offset=CINEMATIC_147, x=[0x78], y=[0x79]
	setup channel=0x16, address=SETUP_CHAN_14_BY_VAR63
	break
	play id=0x005E, freq=0x14, vol=0x40, channel=0x01
	and [0x04], 0x3FFF
	mov [HERO_X], [0x78]
	sub [HERO_X], 0x001E
	sub [HERO_Y], 0x0014
	jmp LABEL_EB39
LABEL_169D:
	db 0x11

LABEL_169E:
	call GUARDED_DRAW_CV_304_305
	deleteChannels first=0x34, last=0x35
	and [0x09], 0xFBFF
	break
	or [0x11], 0x2000
	call LABEL_8729
	break
	mov [0x12], 0x2010
	mov [0x2F], 0x0008
	jmp DISPATCH_VAR2F_STATE
LABEL_16BD:
	db 0x11

LABEL_16BE:
	mov [0x29], 0x0002
	call GUARDED_DRAW_CV_304_305

LABEL_16C5:
	break
	call GUARDED_DRAW_CV_304_305
	djnz [0x29], LABEL_16C5
	deleteChannels first=0x34, last=0x35
	and [0x09], 0xFBFF
	break
	play id=0x0075, freq=0x0F, vol=0x40, channel=0x03
	video offset=CINEMATIC_182, x=[0x78], y=[0x79]
	break
	video offset=CINEMATIC_183, x=[0x78], y=[0x79]
	mov [0x29], 0x0003

LABEL_16EB:
	break
	call LABEL_1791
	video offset=CINEMATIC_184, x=[0x78], y=[0x79]
	djnz [0x29], LABEL_16EB
	mov [0x29], 0x0005

LABEL_16FC:
	break
	call LABEL_1791
	video offset=CINEMATIC_185, x=[0x78], y=[0x79]
	djnz [0x29], LABEL_16FC
	play id=0x0088, freq=0x0A, vol=0x40, channel=0x03
	mov [0x29], 0x0004

LABEL_1713:
	break
	call LABEL_1791
	video offset=CINEMATIC_184, x=[0x78], y=[0x79]
	djnz [0x29], LABEL_1713
	mov [0x29], 0x0003

LABEL_1724:
	break
	call LABEL_1791
	video offset=CINEMATIC_185, x=[0x78], y=[0x79]
	djnz [0x29], LABEL_1724
	mov [0x29], [0x78]

LABEL_1734:
	break
	call LABEL_1791
	call LABEL_9481
	break
	call LABEL_9481
	call LABEL_1791
	break
	call LABEL_1791
	jne [HACK_VAR_67], [0x10], LABEL_179D
	sub [0x78], 0x0007
	add [0x79], 0x0006
	video type=0, offset=COMMON_VIDEO_287, x=[0x78], y=[0x79], zoom=0x40
	sub [0x79], 0x0006
	add [0x78], 0x0007
	video offset=CINEMATIC_184, x=[0x78], y=[0x79]
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0023
	sub [0x27], 0x0018
	sub [0x29], 0x0011
	jl [0x29], 0x32, LABEL_169E
	jg [HERO_X], [0x29], LABEL_178A
	call LABEL_6578
	jmp LABEL_1734

LABEL_178A:
	call LABEL_6580
	jmp LABEL_1734
LABEL_1790:
	db 0x11

LABEL_1791:
	jl [HERO_X], 0x0105, SHARED_RET
	setup channel=0x27, address=LABEL_179D
	ret

LABEL_179D:
	mov [0x12], 0x4010
	call STATE_VAR12_BIG_DISPATCH
	jmp DISPATCH_VAR2F_STATE
LABEL_17A7:
	db 0x11

LABEL_17A8:
	video offset=CINEMATIC_187, x=[0x78], y=[0x79]
	mov [PAUSE_SLICES], 0x0008
	break
	video offset=CINEMATIC_188, x=[0x78], y=[0x79]
	break
	video offset=CINEMATIC_189, x=[0x78], y=[0x79]
	break
	video offset=CINEMATIC_189, x=[0x78], y=[0x79]
	break
	video offset=CINEMATIC_188, x=[0x78], y=[0x79]
	break
	video offset=CINEMATIC_187, x=[0x78], y=[0x79]
	break
	jmp LABEL_17A8
LABEL_17D3:
	db 0x11

HANG_DRAW_CIN_186:
	video offset=CINEMATIC_186, x=[0x78], y=[0x79]
	break
	jmp HANG_DRAW_CIN_186
LABEL_17DD:
	db 0x11

LABEL_17DE:
	mov [0x0E], 0x0000
	call GUARDED_DRAW_CV_304_305
	break
	mov [0x0E], 0x0004
	call LABEL_8729
	break
	mov [0x0E], 0x0000
	call LABEL_8747
	break
	mov [0x29], 0x0002

LABEL_17FA:
	mov [0x0E], 0x0003
	call LABEL_8747
	break
	djnz [0x29], LABEL_17FA
	mov [0x29], 0x0002

LABEL_180A:
	mov [0x0E], 0x0000
	call LABEL_8729
	break
	djnz [0x29], LABEL_180A
	mov [0xF8], [0x07]
	sub [0xF8], [HERO_X]
	jl [0xF8], 0x64, LABEL_1831
	call LABEL_5F0A
	jne [0x12], 0x28, LABEL_1831
	je [0x21], 0x00, LABEL_17DE

LABEL_1831:
	mov [0x12], 0x2010
	mov [0x2F], 0x0008
	mov [0x29], 0x0002
	jmp DISPATCH_VAR2F_STATE
LABEL_1840:
	db 0x11

LABEL_1841:
	video type=0, offset=COMMON_VIDEO_133, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_134, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0006
	break
	setup channel=0x02, address=KILL_CHANNEL_LANDING
	video type=0, offset=COMMON_VIDEO_135, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	call SET_VAR04_TO_0008
	break
	video type=0, offset=COMMON_VIDEO_136, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_137, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_138, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0005
	break
	mov [0x0A], 0x0001
	video type=0, offset=COMMON_VIDEO_140, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_149, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_150, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_151, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_152, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x2A], 0x000F
	call SET_VAR04_TO_0010
	jmp LABEL_F457
LABEL_18B3:
	db 0x11
