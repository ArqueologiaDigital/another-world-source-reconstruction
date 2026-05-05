ANIM_CIN_532_LOOP_VAR29:
	video offset=CINEMATIC_532, x=[BUDDY_X], y=[BUDDY_Y]
	break
	djnz [0x29], ANIM_CIN_532_LOOP_VAR29
	video offset=CINEMATIC_533, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_534, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_535, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_536, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_537, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_538, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_539, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_540, x=[BUDDY_X], y=[BUDDY_Y]
	play id=0x005E, freq=0x14, vol=0x40, channel=0x01
	play id=0x0079, freq=0x19, vol=0x40, channel=0x00
	add [BUDDY_X], 0x0007
	setup channel=0x14, address=LABEL_1995
	mov [0x29], 0x0014
	break
	video offset=CINEMATIC_541, x=[BUDDY_X], y=[BUDDY_Y]
	add [BUDDY_X], 0x0008

LABEL_1AD1:
	break
	call GUARDED_ALIEN_ANIM_CV_128
	djnz [0x29], LABEL_1AD1
	break
	mov [0x29], 0x00C6
	mov [0x2F], 0x0018
	jmp DISPATCH_VAR2F_STATE
LABEL_1AE5:
	db 0x11

STATE_VAR12_BIG_DISPATCH_CASE_28:
	call GUARDED_ALIEN_ANIM_CV_128
	break
	video offset=CINEMATIC_114, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_169, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xE8], 0x0001
	break
	video offset=CINEMATIC_115, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_173, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	break
	add [BUDDY_X], 0x0002
	video offset=CINEMATIC_116, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_129, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	play id=0x005E, freq=0x14, vol=0x40, channel=0x01
	play id=0x0079, freq=0x19, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_117, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_181, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	break
	video offset=CINEMATIC_118, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=COMMON_VIDEO_189, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0x12], 0x0030
	mov [0x29], 0x000A

LABEL_1B3C:
	break
	call GUARDED_ALIEN_ANIM_CV_128
	djnz [0x29], LABEL_1B3C
	break
	call LABEL_35B9
	mov [0x29], 0x014A
	mov [0x2F], 0x0018
	jmp DISPATCH_VAR2F_STATE
LABEL_1B53:
	db 0x11

STATE_VAR12_BIG_DISPATCH_CASE_30:
	je [0x10], 0x92, LABEL_1B71
	mov [HERO_X], 0x015E
	mov [BUDDY_X], 0x000A
	mov [0x10], 0x0092
	mov [0x2F], 0x0018
	mov [0x29], 0x0050
	jmp DISPATCH_VAR2F_STATE

LABEL_1B71:
	mov [0x2F], 0x0012
	jmp LABEL_1297
	jmp DISPATCH_VAR2F_STATE
