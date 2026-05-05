LABEL_11B2:
	video offset=CINEMATIC_124, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_125, x=[BUDDY_X], y=[BUDDY_Y]
	play id=0x005E, freq=0x1C, vol=0x40, channel=0x01
	break
	video offset=CINEMATIC_126, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_125, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_127, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_128, x=[BUDDY_X], y=[BUDDY_Y]
	play id=0x005E, freq=0x14, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_129, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_128, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_126, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_125, x=[BUDDY_X], y=[BUDDY_Y]
	break
	djnz [0x29], LABEL_11B2
	sub [0xEF], 0x0001
	jl [0xEF], 0x00, LABEL_127C
	video offset=CINEMATIC_233, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_234, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_235, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_236, x=[BUDDY_X], y=[BUDDY_Y]
	break
	mov [0x29], 0x0004

LABEL_121F:
	video offset=CINEMATIC_237, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_133, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_238, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_133, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_239, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_240, x=[BUDDY_X], y=[BUDDY_Y]
	play id=0x005E, freq=0x14, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_241, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_240, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_238, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_133, x=[BUDDY_X], y=[BUDDY_Y]
	break
	djnz [0x29], LABEL_121F
	video offset=CINEMATIC_242, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_132, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_131, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_130, x=[BUDDY_X], y=[BUDDY_Y]
	break
	jmp INLINE_SET_VAR29_TO_4
LABEL_127B:
	db 0x11

LABEL_127C:
	video offset=CINEMATIC_130, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_131, x=[BUDDY_X], y=[BUDDY_Y]
	break
	play id=0x0075, freq=0x0A, vol=0x40, channel=0x01
	video offset=CINEMATIC_132, x=[BUDDY_X], y=[BUDDY_Y]
	setup channel=0x23, address=LABEL_133E
	setup channel=0x25, address=LABEL_129C
	killChannel

LABEL_129C:
	video offset=CINEMATIC_133, x=[BUDDY_X], y=[BUDDY_Y]
	break
	mov [0x12], 0x0038
	mov [0x29], [HERO_X]
	sub [0x29], 0x001A
	mov [0x2F], 0x0018
	jmp DISPATCH_VAR2F_STATE
LABEL_12B4:
	db 0x11

STATE_VAR12_BIG_DISPATCH_CASE_38:
	call GUARDED_ALIEN_ANIM_CV_128
	break
	video offset=CINEMATIC_113, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_169, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	break
	video offset=CINEMATIC_114, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_173, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	play id=0x005E, freq=0x11, vol=0x40, channel=0x01
	setup channel=0x37, address=LABEL_130E
	deleteChannels first=0x14, last=0x16
	break
	add [BUDDY_X], 0x0002
	video offset=CINEMATIC_115, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_129, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	break
	video offset=CINEMATIC_116, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_181, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	break
	video offset=CINEMATIC_117, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_189, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	break
	mov [0x29], 0x000A
	mov [0x2F], 0x0018
	jmp DISPATCH_VAR2F_STATE
LABEL_130D:
	db 0x11

LABEL_130E:
	mov [0x32], 0x0001
	video offset=CINEMATIC_243, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x000E
	video offset=CINEMATIC_243, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x0012
	video offset=CINEMATIC_243, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x0018
	video offset=CINEMATIC_243, x=[HERO_X], y=[HERO_Y]
	deleteChannels first=0x00, last=0x3B
	setup channel=0x14, address=PLAY_3SFX_PAL_3_PAUSE_4
	killChannel

LABEL_133E:
	or [0x11], 0x0200
	video offset=CINEMATIC_134, x=[BUDDY_X], y=[BUDDY_Y]
	add [BUDDY_Y], 0x000C
	break
	video offset=CINEMATIC_134, x=[BUDDY_X], y=[BUDDY_Y]
	add [BUDDY_Y], 0x0010
	break
	video offset=CINEMATIC_134, x=[BUDDY_X], y=[BUDDY_Y]
	add [BUDDY_Y], 0x0012
	break
	play id=0x005E, freq=0x14, vol=0x40, channel=0x01
	jmp LABEL_1688
LABEL_1369:
	db 0x11
