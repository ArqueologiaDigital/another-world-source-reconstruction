LABEL_0145:
	video offset=CINEMATIC_345, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_346, x=[BUDDY_X], y=[BUDDY_Y]
	play id=0x005E, freq=0x1C, vol=0x40, channel=0x01
	break
	video offset=CINEMATIC_347, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_346, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_348, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_349, x=[BUDDY_X], y=[BUDDY_Y]
	play id=0x005E, freq=0x14, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_350, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_349, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_347, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_346, x=[BUDDY_X], y=[BUDDY_Y]
	break
	djnz [0x29], LABEL_0145
	sub [0xEF], 0x0001
	jl [0xEF], 0x00, LABEL_020F
	video offset=CINEMATIC_411, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_412, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_413, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_414, x=[BUDDY_X], y=[BUDDY_Y]
	break
	mov [0x29], 0x0004

LABEL_01B2:
	video offset=CINEMATIC_415, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_354, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_416, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_354, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_417, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_418, x=[BUDDY_X], y=[BUDDY_Y]
	play id=0x005E, freq=0x14, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_419, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_418, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_416, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_354, x=[BUDDY_X], y=[BUDDY_Y]
	break
	djnz [0x29], LABEL_01B2
	video offset=CINEMATIC_420, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_353, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_352, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_351, x=[BUDDY_X], y=[BUDDY_Y]
	break
	jmp INLINE_SET_VAR29_TO_4
LABEL_020E:
	db 0x11

LABEL_020F:
	video offset=CINEMATIC_351, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_352, x=[BUDDY_X], y=[BUDDY_Y]
	break
	play id=0x0075, freq=0x0A, vol=0x40, channel=0x01
	video offset=CINEMATIC_353, x=[BUDDY_X], y=[BUDDY_Y]
	setup channel=0x23, address=LABEL_02D1
	setup channel=0x25, address=LABEL_022F
	killChannel

LABEL_022F:
	video offset=CINEMATIC_354, x=[BUDDY_X], y=[BUDDY_Y]
	break
	mov [0x12], 0x0038
	mov [0x29], [HERO_X]
	sub [0x29], 0x001A
	mov [0x2F], 0x0018
	jmp DISPATCH_VAR2F_STATE
LABEL_0247:
	db 0x11

STATE_VAR12_BIG_DISPATCH_CASE_38:
	call LABEL_6F95
	break
	video offset=CINEMATIC_334, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_125, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	break
	video offset=CINEMATIC_335, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_129, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	play id=0x005E, freq=0x11, vol=0x40, channel=0x01
	setup channel=0x37, address=LABEL_02A1
	deleteChannels first=0x14, last=0x16
	break
	add [BUDDY_X], 0x0002
	video offset=CINEMATIC_336, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_010, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	break
	video offset=CINEMATIC_337, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_137, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	break
	video offset=CINEMATIC_338, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_145, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	break
	mov [0x29], 0x000A
	mov [0x2F], 0x0018
	jmp DISPATCH_VAR2F_STATE
LABEL_02A0:
	db 0x11

LABEL_02A1:
	mov [0x32], 0x0001
	video offset=CINEMATIC_421, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x000E
	video offset=CINEMATIC_421, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x0012
	video offset=CINEMATIC_421, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x0018
	video offset=CINEMATIC_421, x=[HERO_X], y=[HERO_Y]
	deleteChannels first=0x00, last=0x3B
	setup channel=0x14, address=PLAY_3SFX_PAL_3_PAUSE_4
	killChannel

LABEL_02D1:
	or [0x11], 0x0200
	video offset=CINEMATIC_355, x=[BUDDY_X], y=[BUDDY_Y]
	add [BUDDY_Y], 0x000C
	break
	video offset=CINEMATIC_355, x=[BUDDY_X], y=[BUDDY_Y]
	add [BUDDY_Y], 0x0010
	break
	video offset=CINEMATIC_355, x=[BUDDY_X], y=[BUDDY_Y]
	add [BUDDY_Y], 0x0012
	break
	play id=0x005E, freq=0x14, vol=0x40, channel=0x01
	jmp LABEL_06DA
LABEL_02FC:
	db 0x11
