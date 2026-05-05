ANIM_CIN_526_LOOP_VAR29:
	video offset=CINEMATIC_526, x=[0x07], y=[0x08]
	break
	djnz [0x29], ANIM_CIN_526_LOOP_VAR29
	video offset=CINEMATIC_527, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_528, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_529, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_530, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_531, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_532, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_533, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_534, x=[0x07], y=[0x08]
	play id=0x005E, freq=0x14, vol=0x40, channel=0x01
	play id=0x0079, freq=0x19, vol=0x40, channel=0x00
	add [0x07], 0x0007
	setup channel=0x14, address=LABEL_1887
	mov [0x29], 0x0014
	break
	video offset=CINEMATIC_535, x=[0x07], y=[0x08]
	add [0x07], 0x0008

LABEL_19C3:
	break
	call GUARDED_ALIEN_ANIM_CV_128
	djnz [0x29], LABEL_19C3
	break
	mov [0x29], 0x00C6
	mov [0x2F], 0x0018
	jmp DISPATCH_VAR2F_STATE
LABEL_19D7:
	db 0x11

STATE_VAR12_BIG_DISPATCH_CASE_28:
	call GUARDED_ALIEN_ANIM_CV_128
	break
	video offset=CINEMATIC_113, x=[0x07], y=[0x08]
	video type=0, offset=COMMON_VIDEO_169, x=[0x07], y=[0x08], zoom=0x40
	mov [0xE8], 0x0001
	break
	video offset=CINEMATIC_114, x=[0x07], y=[0x08]
	video type=0, offset=COMMON_VIDEO_173, x=[0x07], y=[0x08], zoom=0x40
	break
	add [0x07], 0x0002
	video offset=CINEMATIC_115, x=[0x07], y=[0x08]
	video type=0, offset=COMMON_VIDEO_129, x=[0x07], y=[0x08], zoom=0x40
	play id=0x005E, freq=0x14, vol=0x40, channel=0x01
	play id=0x0079, freq=0x19, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_116, x=[0x07], y=[0x08]
	video type=0, offset=COMMON_VIDEO_181, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_117, x=[0x07], y=[0x08]
	video type=0, offset=COMMON_VIDEO_189, x=[0x07], y=[0x08], zoom=0x40
	mov [0x12], 0x0030
	mov [0x29], 0x000A

LABEL_1A2E:
	break
	call GUARDED_ALIEN_ANIM_CV_128
	djnz [0x29], LABEL_1A2E
	break
	call LABEL_342A
	mov [0x29], 0x014A
	mov [0x2F], 0x0018
	jmp DISPATCH_VAR2F_STATE
LABEL_1A45:
	db 0x11

STATE_VAR12_BIG_DISPATCH_CASE_30:
	je [0x10], 0x92, LABEL_1A63
	mov [0x01], 0x015E
	mov [0x07], 0x000A
	mov [0x10], 0x0092
	mov [0x2F], 0x0018
	mov [0x29], 0x0050
	jmp DISPATCH_VAR2F_STATE

LABEL_1A63:
	mov [0x2F], 0x0012
	jmp LABEL_11AA
	jmp DISPATCH_VAR2F_STATE
