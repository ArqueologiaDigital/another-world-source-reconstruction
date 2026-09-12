CAVES_COPY_VAR01_TO_VAR28_L16:
	ret


DRAW_BEAST_SPRITE_BY_VAR09_0E:
	mov [0xF8], [0x09]
	shr [0xF8], 0x0004
	and [0xF8], 0x000F
	jne [0x0E], 0x00, LABEL_7D8C
	je [0xF8], 0x00, DRAW_BEAST_POSE_0_0
	je [0xF8], 0x01, DRAW_BEAST_POSE_0_1
	je [0xF8], 0x02, DRAW_BEAST_POSE_0_2
	je [0xF8], 0x03, DRAW_BEAST_POSE_0_3
	je [0xF8], 0x04, DRAW_BEAST_POSE_0_4
	je [0xF8], 0x05, DRAW_BEAST_POSE_0_5
	je [0xF8], 0x06, DRAW_BEAST_POSE_0_6
	ret


LABEL_7D8C:
	jne [0x0E], 0x01, LABEL_7D95
	jmp DRAW_BEAST_POSE_1

LABEL_7D95:
	jne [0x0E], 0x02, LABEL_7D9E
	jmp DRAW_BEAST_POSE_2

LABEL_7D9E:
	jne [0x0E], 0x03, LABEL_7DAD
	je [0xF8], 0x03, DRAW_CIN_041
	jmp DRAW_CIN_045

LABEL_7DAD:
	jne [0x0E], 0x04, LABEL_7DBC
	je [0xF8], 0x03, DRAW_CIN_043
	jmp DRAW_CIN_044

LABEL_7DBC:
	jne [0x0E], 0x05, LABEL_7DCB
	je [0xF8], 0x03, DRAW_CIN_041
	jmp DRAW_CIN_042

LABEL_7DCB:
	jne [0x0E], 0x06, LABEL_7DD7
	video offset=CINEMATIC_040, x=[0x07], y=[0x08]
	ret


LABEL_7DD7:
	jne [0x0E], 0x07, LABEL_7DEA
	je [0xF8], 0x00, DRAW_CIN_038
	je [0xF8], 0x01, DRAW_CIN_039
	ret


LABEL_7DEA:
	ret


LABEL_7DEB:
	db 0x11

DRAW_BEAST_POSE_0_0:
	video offset=CINEMATIC_048, x=[0x07], y=[0x08]
	ret


DRAW_BEAST_POSE_0_1:
	video offset=CINEMATIC_049, x=[0x07], y=[0x08]
	ret


DRAW_BEAST_POSE_0_2:
	video offset=CINEMATIC_050, x=[0x07], y=[0x08]
	ret


DRAW_BEAST_POSE_0_3:
	video offset=CINEMATIC_051, x=[0x07], y=[0x08]
	ret


DRAW_BEAST_POSE_0_4:
	video offset=CINEMATIC_052, x=[0x07], y=[0x08]
	ret


DRAW_BEAST_POSE_0_5:
	video offset=CINEMATIC_026, x=[0x07], y=[0x08]
	ret


DRAW_BEAST_POSE_0_6:
	video offset=CINEMATIC_053, x=[0x07], y=[0x08]
	ret


DRAW_BEAST_POSE_1:
	video offset=CINEMATIC_047, x=[0x07], y=[0x08]
	ret


DRAW_BEAST_POSE_2:
	video offset=CINEMATIC_046, x=[0x07], y=[0x08]
	ret


DRAW_CIN_045:
	video offset=CINEMATIC_045, x=[0x07], y=[0x08]
	ret


DRAW_CIN_041:
	video offset=CINEMATIC_041, x=[0x07], y=[0x08]
	ret


DRAW_CIN_044:
	video offset=CINEMATIC_044, x=[0x07], y=[0x08]
	ret


DRAW_CIN_043:
	video offset=CINEMATIC_043, x=[0x07], y=[0x08]
	ret


DRAW_CIN_042:
	video offset=CINEMATIC_042, x=[0x07], y=[0x08]
	ret


DRAW_CIN_038:
	video offset=CINEMATIC_038, x=[0x07], y=[0x08]
	ret


DRAW_CIN_039:
	video offset=CINEMATIC_039, x=[0x07], y=[0x08]
	ret


DRAW_CIN_061_062_VAR09_LOW:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_061
	je [0xF8], 0x02, DRAW_CIN_062
	ret


DRAW_CIN_061:
	video offset=CINEMATIC_061, x=[0xf5], y=[0x08]
	ret


DRAW_CIN_062:
	video offset=CINEMATIC_062, x=[0xf5], y=[0x08]
	ret


DRAW_HERO_SUBFRAME_2_VAR09_LOW_OFFSET:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_HERO_SUBFRAME_2_OFFSET_CASE_01
	je [0xF8], 0x02, DRAW_HERO_SUBFRAME_2_OFFSET_CASE_02
	ret


DRAW_HERO_SUBFRAME_2_OFFSET_CASE_01:
	add [0x08], 0x000D
	sub [0x07], 0x0002
	video offset=CINEMATIC_031, x=[0x07], y=[0x08]
	add [0x07], 0x0002
	sub [0x08], 0x000D
	ret


DRAW_HERO_SUBFRAME_2_OFFSET_CASE_02:
	add [0x08], 0x000D
	sub [0x07], 0x0002
	video offset=CINEMATIC_032, x=[0x07], y=[0x08]
	add [0x07], 0x0002
	sub [0x08], 0x000D
	ret


LABEL_7EAC:
	video type=0, offset=COMMON_VIDEO_317, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, LABEL_7EBF
	video type=0, offset=COMMON_VIDEO_319, x=[0x07], y=[0x08], zoom=0x40

LABEL_7EBF:
	jg [0x13], [0x30], DRAW_CIN_061_062_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_061_062_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_318, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_061_062_VAR09_LOW

LABEL_7EDA:
	video type=0, offset=COMMON_VIDEO_320, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, LABEL_7EF1
	video type=0, offset=COMMON_VIDEO_322, x=[0x07], y=[0x08], zoom=0x40

LABEL_7EF1:
	jg [0x13], [0x30], DRAW_CIN_061_062_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_061_062_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_321, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_061_062_VAR09_LOW

LABEL_7F0C:
	video type=0, offset=COMMON_VIDEO_323, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], DRAW_HERO_SUBFRAME_2_VAR09_LOW_OFFSET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW_OFFSET
	video type=0, offset=COMMON_VIDEO_324, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW_OFFSET

LABEL_7F2C:
	video type=0, offset=COMMON_VIDEO_325, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW_OFFSET

LABEL_7F34:
	sub [0x07], 0x0001
	call LABEL_7F40
	add [0x07], 0x0001
	ret


LABEL_7F40:
	video type=0, offset=COMMON_VIDEO_305, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_306, x=[0x07], y=[0x08], zoom=0x40
	ret


LABEL_7F5E:
	sub [0x07], 0x0001
	call LABEL_7F6A
	add [0x07], 0x0001
	ret


LABEL_7F6A:
	video type=0, offset=COMMON_VIDEO_303, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_304, x=[0x07], y=[0x08], zoom=0x40
	ret


LABEL_7F88:
	video type=0, offset=COMMON_VIDEO_301, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_302, x=[0x07], y=[0x08], zoom=0x40
	ret


LABEL_7FA6:
	add [0x07], 0x0001
	call LABEL_7F88
	sub [0x07], 0x0001
	ret