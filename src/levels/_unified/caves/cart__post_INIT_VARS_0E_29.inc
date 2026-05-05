LABEL_152A:
	call GUARDED_BEAST_OR_CV_304_305
	break
	djnz [0x29], LABEL_152A
	mov [0x0E], 0x0000
	mov [0x29], 0x0005

LABEL_153A:
	call LABEL_86A0
	break
	djnz [0x29], LABEL_153A
	play id=0x0070, freq=0x0D, vol=0x40, channel=0x03
	mov [0x0E], 0x0003
	call GUARDED_BEAST_OR_CV_304_305
	break
	call LABEL_86A0
	break
	mov [0x0E], 0x0005
	call LABEL_86BE
	break
	mov [0x0E], 0x000A
	call LABEL_86A0
	jmp LABEL_1567
LABEL_1566:
	db 0x11

LABEL_1567:
	setup channel=0x34, address=LABEL_15B5
	play id=0x0072, freq=0x0D, vol=0x40, channel=0x03

LABEL_1571:
	mov [0x0E], 0x0000
	mov [0x29], 0x0005

LABEL_1579:
	call LABEL_86BE
	break
	call LABEL_86BE
	break
	call LABEL_86BE
	break
	call LABEL_86BE
	break
	call LABEL_86BE
	break
	mov [0x0E], 0x0007
	call GUARDED_BEAST_OR_CV_304_305
	break
	call LABEL_86A0
	break
	mov [0x0E], 0x0007
	call LABEL_86BE
	break
	mov [0x0E], 0x0004
	call LABEL_86A0
	break
	djnz [0x29], LABEL_1579
	setup channel=0x34, address=LABEL_15E5
	jmp LABEL_1571
LABEL_15B4:
	db 0x11

LABEL_15B5:
	video offset=CINEMATIC_179, x=[0x78], y=[0x79]
	break
	video offset=CINEMATIC_180, x=[0x78], y=[0x79]
	mov [0xB7], 0x0001

LABEL_15C4:
	break
	video offset=CINEMATIC_181, x=[0x78], y=[0x79]
	jne [HERO_ACTION], 0x01, LABEL_15C4
	and [0x04], 0x3FFF
	setup channel=0x14, address=LABEL_1606
	setup channel=0x27, address=LABEL_1669

LABEL_15DC:
	break
	video offset=CINEMATIC_142, x=[0x78], y=[0x79]
	jmp LABEL_15DC

LABEL_15E5:
	video offset=CINEMATIC_142, x=[0x78], y=[0x79]
	and [0x04], 0x3FFF
	setup channel=0x27, address=LABEL_1649
	setup channel=0x16, address=SETUP_CHAN_14_BY_VAR63
	setup channel=0x14, address=LABEL_EBC2
	mov [0x01], [0x78]
	sub [0x01], 0x001E
	sub [0x02], 0x0014
	killChannel

LABEL_1606:
	video offset=CINEMATIC_143, x=[0x78], y=[0x79]
	mov [PAUSE_SLICES], 0x0004
	video offset=CINEMATIC_144, x=[0x78], y=[0x79]
	break
	song id=0x0BCD, delay=0x0000, pos=0x00
	video offset=CINEMATIC_145, x=[0x78], y=[0x79]
	video offset=CINEMATIC_146, x=[0x78], y=[0x79]
	break
	video offset=CINEMATIC_147, x=[0x78], y=[0x79]
	setup channel=0x16, address=SETUP_CHAN_14_BY_VAR63
	break
	play id=0x005E, freq=0x14, vol=0x40, channel=0x01
	and [0x04], 0x3FFF
	mov [0x01], [0x78]
	sub [0x01], 0x001E
	sub [0x02], 0x0014
	jmp LABEL_EBC2
LABEL_1648:
	db 0x11

LABEL_1649:
	call GUARDED_BEAST_OR_CV_304_305
	deleteChannels first=0x34, last=0x35
	and [0x09], 0xFBFF
	break
	or [0x11], 0x2000
	call LABEL_86A0
	break
	mov [0x12], 0x2010
	mov [0x2F], 0x0008
	jmp DISPATCH_VAR2F_STATE
LABEL_1668:
	db 0x11

LABEL_1669:
	mov [0x29], 0x0002
	call GUARDED_BEAST_OR_CV_304_305

LABEL_1670:
	break
	call GUARDED_BEAST_OR_CV_304_305
	djnz [0x29], LABEL_1670
	deleteChannels first=0x34, last=0x35
	and [0x09], 0xFBFF
	break
	play id=0x0075, freq=0x0F, vol=0x40, channel=0x03
	video offset=CINEMATIC_182, x=[0x78], y=[0x79]
	break
	video offset=CINEMATIC_183, x=[0x78], y=[0x79]
	mov [0x29], 0x0003

LABEL_1696:
	break
	call LABEL_173C
	video offset=CINEMATIC_184, x=[0x78], y=[0x79]
	djnz [0x29], LABEL_1696
	mov [0x29], 0x0005

LABEL_16A7:
	break
	call LABEL_173C
	video offset=CINEMATIC_185, x=[0x78], y=[0x79]
	djnz [0x29], LABEL_16A7
	play id=0x0088, freq=0x0A, vol=0x40, channel=0x03
	mov [0x29], 0x0004

LABEL_16BE:
	break
	call LABEL_173C
	video offset=CINEMATIC_184, x=[0x78], y=[0x79]
	djnz [0x29], LABEL_16BE
	mov [0x29], 0x0003

LABEL_16CF:
	break
	call LABEL_173C
	video offset=CINEMATIC_185, x=[0x78], y=[0x79]
	djnz [0x29], LABEL_16CF
	mov [0x29], [0x78]

LABEL_16DF:
	break
	call LABEL_173C
	call LABEL_93F8
	break
	call LABEL_93F8
	call LABEL_173C
	break
	call LABEL_173C
	jne [HACK_VAR_67], [0x10], LABEL_1748
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
	jl [0x29], 0x32, LABEL_1649
	jg [0x01], [0x29], LABEL_1735
	call LABEL_648D
	jmp LABEL_16DF

LABEL_1735:
	call LABEL_6495
	jmp LABEL_16DF
LABEL_173B:
	db 0x11

LABEL_173C:
	jl [0x01], 0x0105, SHARED_RET
	setup channel=0x27, address=LABEL_1748
	ret

LABEL_1748:
	mov [0x12], 0x4010
	call STATE_VAR12_BIG_DISPATCH
	jmp DISPATCH_VAR2F_STATE
LABEL_1752:
	db 0x11

LABEL_1753:
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
	jmp LABEL_1753
LABEL_177E:
	db 0x11

HANG_DRAW_CIN_186:
	video offset=CINEMATIC_186, x=[0x78], y=[0x79]
	break
	jmp HANG_DRAW_CIN_186
LABEL_1788:
	db 0x11

LABEL_1789:
	mov [0x0E], 0x0000
	call GUARDED_BEAST_OR_CV_304_305
	break
	mov [0x0E], 0x0004
	call LABEL_86A0
	break
	mov [0x0E], 0x0000
	call LABEL_86BE
	break
	mov [0x29], 0x0002

LABEL_17A5:
	mov [0x0E], 0x0003
	call LABEL_86BE
	break
	djnz [0x29], LABEL_17A5
	mov [0x29], 0x0002

LABEL_17B5:
	mov [0x0E], 0x0000
	call LABEL_86A0
	break
	djnz [0x29], LABEL_17B5
	mov [0xF8], [0x07]
	sub [0xF8], [0x01]
	jl [0xF8], 0x64, LABEL_17DC
	call LABEL_5E1F
	jne [0x12], 0x28, LABEL_17DC
	je [0x21], 0x00, LABEL_1789

LABEL_17DC:
	mov [0x12], 0x2010
	mov [0x2F], 0x0008
	mov [0x29], 0x0002
	jmp DISPATCH_VAR2F_STATE
LABEL_17EB:
	db 0x11

LABEL_17EC:
	video type=0, offset=COMMON_VIDEO_133, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_134, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0006
	break
	setup channel=0x02, address=KILL_CHANNEL_LANDING
	video type=0, offset=COMMON_VIDEO_135, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	call SET_VAR04_TO_0008
	break
	video type=0, offset=COMMON_VIDEO_136, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_137, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_138, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0005
	break
	mov [0xB7], 0x0000
	mov [0x50], 0x0119
	mov [0x0A], 0x0001
	video type=0, offset=COMMON_VIDEO_140, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_149, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_150, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_151, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_152, x=[0x01], y=[0x02], zoom=0x40
	mov [0x2A], 0x000F
	call SET_VAR04_TO_0010
	jmp LABEL_F4E0
LABEL_1866:
	db 0x11
