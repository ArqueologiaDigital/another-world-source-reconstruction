ANIM_CIN_433_LOOP_VAR29:
	video offset=CINEMATIC_433, x=[BUDDY_X], y=[BUDDY_Y]
	break
	djnz [0x29], ANIM_CIN_433_LOOP_VAR29
	video offset=CINEMATIC_434, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_435, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_436, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_437, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_438, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_439, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_440, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_441, x=[BUDDY_X], y=[BUDDY_Y]
	play id=0x005E, freq=0x14, vol=0x40, channel=0x01
	play id=0x0079, freq=0x19, vol=0x40, channel=0x00
	add [BUDDY_X], 0x0007
	setup channel=0x14, address=LABEL_08D9
	mov [0x29], 0x0014
	break
	video offset=CINEMATIC_442, x=[BUDDY_X], y=[BUDDY_Y]
	add [BUDDY_X], 0x0008

LABEL_0A15:
	break
	call LABEL_6F95
	djnz [0x29], LABEL_0A15
	break
	mov [0x29], 0x00C6
	mov [0x2F], 0x0018
	jmp DISPATCH_VAR2F_STATE
LABEL_0A29:
	db 0x11

STATE_VAR12_BIG_DISPATCH_CASE_28:
	call LABEL_6F95
	break
	video offset=CINEMATIC_334, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_125, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xE8], 0x0001
	break
	video offset=CINEMATIC_335, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_129, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	break
	add [BUDDY_X], 0x0002
	video offset=CINEMATIC_336, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_010, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	play id=0x005E, freq=0x14, vol=0x40, channel=0x01
	play id=0x0079, freq=0x19, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_337, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_137, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	break
	video offset=CINEMATIC_338, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_145, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0x12], 0x0030
	mov [0x29], 0x000A

LABEL_0A80:
	break
	call LABEL_6F95
	djnz [0x29], LABEL_0A80
	break
	call LABEL_2497
	mov [0x29], 0x014A
	mov [0x2F], 0x0018
	jmp DISPATCH_VAR2F_STATE
LABEL_0A97:
	db 0x11

STATE_VAR12_BIG_DISPATCH_CASE_30:
	je [0x10], 0x92, LABEL_0AB5
	mov [HERO_X], 0x015E
	mov [BUDDY_X], 0x000A
	mov [0x10], 0x0092
	mov [0x2F], 0x0018
	mov [0x29], 0x0050
	jmp DISPATCH_VAR2F_STATE

LABEL_0AB5:
	mov [0x2F], 0x0012
	jmp SET_VAREF_TO_6
LABEL_0ABC:
	db 0x07, 0x39, 0x71
