LABEL_6A44:
	sub [0x0A], 0x0001
	break
	jne [0x0A], 0x02, LABEL_6A50
	break

LABEL_6A50:
	jg [0x0A], [0x0C], LABEL_6A44
	killChannel

LABEL_6A57:
	sub [0x0B], 0x0001
	jg [0x0B], 0x00, LABEL_6A8C
	je [HERO_POS_MASK], 0x00, LABEL_6A7A
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	mov [0x0B], [RANDOM_SEED]
	add [0x0B], 0x0006
	mov [0x0C], 0x0004
	setup channel=0x15, address=LABEL_6A25
	ret


LABEL_6A7A:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	mov [0x0B], [0x3A]
	add [0x0B], 0x0006
	mov [0x0C], 0x0001
	setup channel=0x15, address=LABEL_6A25

LABEL_6A8C:
	ret


LABEL_6A8D:
	video offset=CINEMATIC_206, x=[HERO_X], y=[HERO_Y]
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video offset=CINEMATIC_207, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6AAB:
	video offset=CINEMATIC_563, x=[HERO_X], y=[HERO_Y]
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video offset=CINEMATIC_564, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6AC9:
	jne [0x05], 0x00, LABEL_6AD5
	video offset=CINEMATIC_219, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6AD5:
	jne [0x05], 0x01, LABEL_6AE1
	video offset=CINEMATIC_218, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6AE1:
	jne [0x05], 0x02, LABEL_6AED
	video offset=CINEMATIC_217, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6AED:
	jne [0x05], 0x03, LABEL_6AF9
	video offset=CINEMATIC_216, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6AF9:
	ret


LABEL_6AFA:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video offset=CINEMATIC_220, x=[HERO_X], y=[HERO_Y]
	ret


HERO_GUN_ARM_POSE_CASE_01:
	call LABEL_6A57
	jne [0x0A], 0x01, HERO_GUN_ARM_POSE_CASE_02
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_01_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


HERO_GUN_ARM_POSE_CASE_02:
	jne [0x0A], 0x02, HERO_GUN_ARM_POSE_CASE_03
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_02_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


HERO_GUN_ARM_POSE_CASE_03:
	jne [0x0A], 0x03, HERO_GUN_ARM_POSE_CASE_04
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_03_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


HERO_GUN_ARM_POSE_CASE_04:
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_04_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6B98:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video offset=CINEMATIC_221, x=[HERO_X], y=[HERO_Y]
	ret


PRISON_HERO_WALK_RIGHT_POSE_11:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_12:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_13:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F13, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F13, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_14:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_DRAW_CIN_422_WITH_POS_STEP_AT_C7A1BFCB_L2:
	call LABEL_6AC9
	video type=0, offset=HERO_STAND_RIGHT_BODY, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_STAND_RIGHT_ARM, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_00:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_01:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_02:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_03:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_04:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_05:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_06:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WALK_RIGHT_F07:
	call LABEL_6AC9
	video type=0, offset=HERO_WALK_RIGHT_BODY_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_08:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6C9D:
	video type=0, offset=HERO_CROUCH_AIM_LEFT, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_CROUCH_AIM_LEFT_CHARGE_DOT, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6CBB:
	video type=0, offset=HERO_STAND_AIM_LEFT, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_STAND_AIM_LEFT_CHARGE_DOT, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


HERO_GUN_ARM_POSE_LEFT_CASE_01:
	call LABEL_6A57
	jne [0x0A], 0x01, HERO_GUN_ARM_POSE_LEFT_CASE_02
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


HERO_GUN_ARM_POSE_LEFT_CASE_02:
	jne [0x0A], 0x02, HERO_GUN_ARM_POSE_LEFT_CASE_03
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


HERO_GUN_ARM_POSE_LEFT_CASE_03:
	jne [0x0A], 0x03, HERO_GUN_ARM_POSE_LEFT_CASE_04
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


HERO_GUN_ARM_POSE_LEFT_CASE_04:
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_04_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WATER_DEPTH_LEFT_CASE_00:
	jne [0x05], 0x00, LABEL_6D2A
	video type=0, offset=HERO_WATER_DEPTH_LEFT_CASE_00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6D2A:
	jne [0x05], 0x01, DRAW_HERO_WATER_DEPTH_LEFT_CASE_02
	video offset=CINEMATIC_129, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_WATER_DEPTH_LEFT_CASE_02:
	jne [0x05], 0x02, LABEL_6D42
	video type=0, offset=HERO_WATER_DEPTH_LEFT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6D42:
	jne [0x05], 0x03, LABEL_6D4E
	video offset=CINEMATIC_128, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6D4E:
	ret


LABEL_6D4F:
	je [0x0A], 0x00, DRAW_CV_113
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

.include "../_helpers/DRAW_CV_113.inc"

LABEL_6D5E:
	je [0x0A], 0x00, DRAW_CV_114
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

DRAW_CV_114:
	video type=0, offset=HERO_WALK_LEFT_BODY_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6D6D:
	je [0x0A], 0x00, DRAW_CV_115
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

DRAW_CV_115:
	video type=0, offset=HERO_WALK_LEFT_BODY_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6D7C:
	je [0x0A], 0x00, DRAW_CV_116
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

.include "../_helpers/DRAW_CV_116.inc"

LABEL_6D8B:
	je [0x0A], 0x00, DRAW_HERO_WALK_LEFT_F13
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

DRAW_HERO_WALK_LEFT_F13:
	video type=0, offset=HERO_WALK_LEFT_BODY_F13, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_LEFT_DRAW_PHASE_14:
	jne [0x0A], 0x00, LABEL_6DA8
	video type=0, offset=HERO_WALK_LEFT_ARM_F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_118

LABEL_6DA8:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

.include "../_helpers/DRAW_CV_118.inc"

PRISON_HERO_STAND_LEFT_DRAW:
	jne [0x0A], 0x00, LABEL_6DBF
	video type=0, offset=HERO_STAND_LEFT_ARM, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_HERO_STAND_LEFT

LABEL_6DBF:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

DRAW_HERO_STAND_LEFT:
	call DRAW_HERO_WATER_DEPTH_LEFT_CASE_00
	video type=0, offset=HERO_STAND_LEFT_BODY, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_LEFT_DRAW_PHASE_00:
	jne [0x0A], 0x00, LABEL_6DD9
	video type=0, offset=HERO_WALK_LEFT_ARM_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_099

LABEL_6DD9:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

.include "../_helpers/DRAW_CV_099.inc"

PRISON_HERO_WALK_LEFT_DRAW_PHASE_01:
	jne [0x0A], 0x00, LABEL_6DF0
	video type=0, offset=HERO_WALK_LEFT_ARM_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_101

LABEL_6DF0:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

.include "../_helpers/DRAW_CV_101.inc"

PRISON_HERO_WALK_LEFT_DRAW_PHASE_02:
	jne [0x0A], 0x00, LABEL_6E07
	video type=0, offset=HERO_WALK_LEFT_ARM_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_103

LABEL_6E07:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

.include "../_helpers/DRAW_CV_103.inc"

PRISON_HERO_WALK_LEFT_DRAW_PHASE_03:
	jne [0x0A], 0x00, LABEL_6E1E
	video type=0, offset=HERO_WALK_LEFT_ARM_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_105

LABEL_6E1E:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

.include "../_helpers/DRAW_CV_105.inc"

PRISON_HERO_WALK_LEFT_DRAW_PHASE_04:
	jne [0x0A], 0x00, LABEL_6E35
	video type=0, offset=HERO_WALK_LEFT_ARM_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_107

LABEL_6E35:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

.include "../_helpers/DRAW_CV_107.inc"

LABEL_6E3E:
	je [0x0A], 0x00, DRAW_HERO_WALK_LEFT_F05
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

DRAW_HERO_WALK_LEFT_F05:
	video type=0, offset=HERO_WALK_LEFT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6E4D:
	je [0x0A], 0x00, DRAW_CV_110
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

DRAW_CV_110:
	video type=0, offset=HERO_WALK_LEFT_BODY_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6E5C:
	call DRAW_HERO_WATER_DEPTH_LEFT_CASE_00
	je [0x0A], 0x00, DRAW_CV_111
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

.include "../_helpers/DRAW_CV_111.inc"

LABEL_6E6E:
	je [0x0A], 0x00, DRAW_CV_112
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

DRAW_CV_112:
	video type=0, offset=HERO_WALK_LEFT_BODY_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


.include "../_helpers/DRAW_CV_273.inc"

.include "../_helpers/DRAW_CV_270.inc"

.include "../_helpers/DRAW_CV_252.inc"

.include "../_helpers/DRAW_CV_255.inc"

.include "../_helpers/DRAW_CV_265.inc"

DRAW_HERO_RUN_RIGHT_F00:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x00
	jne [0x0A], 0x00, DRAW_CV_252
	video type=0, offset=HERO_RUN_RIGHT_ARM_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_RUN_RIGHT_POSE_01:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_255
	video type=0, offset=HERO_RUN_RIGHT_ARM_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_RUN_RIGHT_POSE_02:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_270
	video type=0, offset=HERO_RUN_RIGHT_ARM_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_RUN_RIGHT_POSE_03:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_273
	video type=0, offset=HERO_RUN_RIGHT_ARM_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_RUN_RIGHT_POSE_04:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_273
	video type=0, offset=HERO_RUN_RIGHT_ARM_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F05:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x00
	jne [0x0A], 0x00, DRAW_CV_252
	video type=0, offset=HERO_RUN_RIGHT_ARM_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_RUN_RIGHT_POSE_06:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_252
	video type=0, offset=HERO_RUN_RIGHT_ARM_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_RUN_RIGHT_POSE_07:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_255
	video type=0, offset=HERO_RUN_RIGHT_ARM_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_RUN_RIGHT_POSE_08:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_265
	video type=0, offset=HERO_RUN_RIGHT_ARM_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_RUN_RIGHT_POSE_09:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_265
	video type=0, offset=HERO_RUN_RIGHT_ARM_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


.include "../_helpers/DRAW_CV_279.inc"

PRISON_HERO_RUN_LEFT_DRAW_PHASE_00:
	je [0x0A], 0x00, DRAW_HERO_RUN_LEFT_F00
	call DRAW_CV_279
	jmp LABEL_6F68

DRAW_HERO_RUN_LEFT_F00:
	video type=0, offset=HERO_RUN_LEFT_ARM_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40

LABEL_6F68:
	video type=0, offset=HERO_RUN_LEFT_BODY_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x00
	ret


PRISON_HERO_RUN_LEFT_DRAW_PHASE_01:
	je [0x0A], 0x00, DRAW_HERO_RUN_LEFT_F01
	call DRAW_CV_279
	jmp DRAW_CV_281

DRAW_HERO_RUN_LEFT_F01:
	video type=0, offset=HERO_RUN_LEFT_ARM_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40

.include "../_helpers/DRAW_CV_281.inc"

PRISON_HERO_RUN_LEFT_DRAW_PHASE_02:
	je [0x0A], 0x00, DRAW_HERO_RUN_LEFT_F02
	call DRAW_CV_279
	jmp DRAW_CV_294

DRAW_HERO_RUN_LEFT_F02:
	video type=0, offset=HERO_RUN_LEFT_ARM_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40

.include "../_helpers/DRAW_CV_294.inc"

PRISON_HERO_RUN_LEFT_DRAW_PHASE_03:
	je [0x0A], 0x00, DRAW_HERO_RUN_LEFT_F03
	call DRAW_CV_279
	jmp DRAW_CV_296

DRAW_HERO_RUN_LEFT_F03:
	video type=0, offset=HERO_RUN_LEFT_ARM_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40

DRAW_CV_296:
	video type=0, offset=HERO_RUN_LEFT_BODY_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6FB9:
	je [0x0A], 0x00, DRAW_CV_297
	call DRAW_CV_279

DRAW_CV_297:
	video type=0, offset=HERO_RUN_LEFT_BODY_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_RUN_LEFT_DRAW_PHASE_05:
	je [0x0A], 0x00, DRAW_HERO_RUN_LEFT_F05
	call DRAW_CV_279
	jmp LABEL_6FD9

DRAW_HERO_RUN_LEFT_F05:
	video type=0, offset=HERO_RUN_LEFT_ARM_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40

LABEL_6FD9:
	video type=0, offset=HERO_RUN_LEFT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x00
	ret


PRISON_HERO_RUN_LEFT_DRAW_PHASE_06:
	je [0x0A], 0x00, DRAW_HERO_RUN_LEFT_F06
	call DRAW_CV_279
	jmp DRAW_CV_286

DRAW_HERO_RUN_LEFT_F06:
	video type=0, offset=HERO_RUN_LEFT_ARM_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40

.include "../_helpers/DRAW_CV_286.inc"

PRISON_HERO_RUN_LEFT_DRAW_PHASE_07:
	je [0x0A], 0x00, DRAW_HERO_RUN_LEFT_F07
	call DRAW_CV_279
	jmp DRAW_CV_288

DRAW_HERO_RUN_LEFT_F07:
	video type=0, offset=HERO_RUN_LEFT_ARM_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40

.include "../_helpers/DRAW_CV_288.inc"

PRISON_HERO_RUN_LEFT_DRAW_PHASE_08:
	je [0x0A], 0x00, DRAW_HERO_RUN_LEFT_F08
	call DRAW_CV_279
	jmp DRAW_CV_290

DRAW_HERO_RUN_LEFT_F08:
	video type=0, offset=HERO_RUN_LEFT_ARM_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40

.include "../_helpers/DRAW_CV_290.inc"

PRISON_HERO_RUN_LEFT_DRAW_PHASE_09:
	je [0x0A], 0x00, DRAW_HERO_RUN_LEFT_F09
	call DRAW_CV_279
	jmp DRAW_CV_292

DRAW_HERO_RUN_LEFT_F09:
	video type=0, offset=HERO_RUN_LEFT_ARM_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40

.include "../_helpers/DRAW_CV_292.inc"

LABEL_7041:
	je [0x1F], 0x00, LABEL_7070
	jl [0x1E], 0x00, INLINE_SET_VAR20_TO_1
	mov [0x20], 0xFFFF

LABEL_7051:
	sub [0x1E], [0x1F]
	add [0x20], 0x0001
	jge [0x1E], 0x00, LABEL_7051
	ret
