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
	video offset=CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_0, x=[0x07], y=[0x08]
	ret


DRAW_BEAST_POSE_0_1:
	video offset=CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_1, x=[0x07], y=[0x08]
	ret


DRAW_BEAST_POSE_0_2:
	video offset=CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_2, x=[0x07], y=[0x08]
	ret


DRAW_BEAST_POSE_0_3:
	video offset=CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_3, x=[0x07], y=[0x08]
	ret


DRAW_BEAST_POSE_0_4:
	video offset=CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_4, x=[0x07], y=[0x08]
	ret


DRAW_BEAST_POSE_0_5:
	video offset=CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_5, x=[0x07], y=[0x08]
	ret


DRAW_BEAST_POSE_0_6:
	video offset=CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_6, x=[0x07], y=[0x08]
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
	video offset=CINEMATIC_CAVES_FIGURE_POSE_LEFT_4_3, x=[0x07], y=[0x08]
	ret


DRAW_CIN_042:
	video offset=CINEMATIC_042, x=[0x07], y=[0x08]
	ret


DRAW_CIN_038:
	video offset=CINEMATIC_CAVES_FIGURE_POSE_LEFT_7_0, x=[0x07], y=[0x08]
	ret


DRAW_CIN_039:
	video offset=CINEMATIC_CAVES_FIGURE_POSE_LEFT_7_1, x=[0x07], y=[0x08]
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
	video type=0, offset=CV_3EEC, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, LABEL_7EBF
	video type=0, offset=CV_6004, x=[0x07], y=[0x08], zoom=0x40

LABEL_7EBF:
	jg [0x13], [0x30], DRAW_CIN_061_062_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_061_062_VAR09_LOW
	video type=0, offset=CV_5CBC, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_061_062_VAR09_LOW

LABEL_7EDA:
	video type=0, offset=CV_3F4A, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, LABEL_7EF1
	video type=0, offset=CV_6010, x=[0x07], y=[0x08], zoom=0x40

LABEL_7EF1:
	jg [0x13], [0x30], DRAW_CIN_061_062_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_061_062_VAR09_LOW
	video type=0, offset=CV_5CC4, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_061_062_VAR09_LOW

LABEL_7F0C:
	video type=0, offset=CV_4058, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], DRAW_HERO_SUBFRAME_2_VAR09_LOW_OFFSET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW_OFFSET
	video type=0, offset=CV_5CCC, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW_OFFSET

LABEL_7F2C:
	video type=0, offset=CV_4416, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW_OFFSET

LABEL_7F34:
	sub [0x07], 0x0001
	call LABEL_7F40
	add [0x07], 0x0001
	ret


LABEL_7F40:
	video type=0, offset=CV_FIGURE_GUN_LIMB_LEFT_POSE_00, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_FIGURE_GUN_LIMB_LEFT_POSE_00_CHARGE_BLINK, x=[0x07], y=[0x08], zoom=0x40
	ret


LABEL_7F5E:
	sub [0x07], 0x0001
	call LABEL_7F6A
	add [0x07], 0x0001
	ret


LABEL_7F6A:
	video type=0, offset=CV_FIGURE_GUN_LIMB_LEFT_POSE_01, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_FIGURE_GUN_LIMB_LEFT_POSE_01_CHARGE_BLINK, x=[0x07], y=[0x08], zoom=0x40
	ret


LABEL_7F88:
	video type=0, offset=CV_FIGURE_GUN_LIMB_LEFT_POSE_02, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_FIGURE_GUN_LIMB_LEFT_POSE_02_CHARGE_BLINK, x=[0x07], y=[0x08], zoom=0x40
	ret


LABEL_7FA6:
	add [0x07], 0x0001
	call LABEL_7F88
	sub [0x07], 0x0001
	ret
