LABEL_6AF1:
	sub [0x0A], 0x0001
	break
	jne [0x0A], 0x02, LABEL_6AFD
	break

LABEL_6AFD:
	jg [0x0A], [0x0C], LABEL_6AF1
	killChannel

LABEL_6B04:
	sub [0x0B], 0x0001
	jg [0x0B], 0x00, LABEL_6B39
	je [HERO_POS_MASK], 0x00, LABEL_6B27
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	mov [0x0B], [RANDOM_SEED]
	add [0x0B], 0x0006
	mov [0x0C], 0x0004
	setup channel=0x15, address=LABEL_6AD2
	ret


LABEL_6B27:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	mov [0x0B], [0x3A]
	add [0x0B], 0x0006
	mov [0x0C], 0x0001
	setup channel=0x15, address=LABEL_6AD2

LABEL_6B39:
	ret


LABEL_6B3A:
	video offset=CINEMATIC_206, x=[HERO_X], y=[HERO_Y]
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video offset=CINEMATIC_207, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6B58:
	video offset=CINEMATIC_563, x=[HERO_X], y=[HERO_Y]
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video offset=CINEMATIC_564, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6B76:
	jne [0x05], 0x00, LABEL_6B82
	video offset=CINEMATIC_219, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6B82:
	jne [0x05], 0x01, LABEL_6B8E
	video offset=CINEMATIC_218, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6B8E:
	jne [0x05], 0x02, LABEL_6B9A
	video offset=CINEMATIC_217, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6B9A:
	jne [0x05], 0x03, LABEL_6BA6
	video offset=CINEMATIC_216, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6BA6:
	ret


LABEL_6BA7:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video offset=CINEMATIC_220, x=[HERO_X], y=[HERO_Y]
	ret


GUARDED_DRAW_CV_159:
	call LABEL_6B04
	jne [0x0A], 0x01, LABEL_6BDF
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_01_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6BDF:
	jne [0x0A], 0x02, LABEL_6C03
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_02_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6C03:
	jne [0x0A], 0x03, LABEL_6C27
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_03_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6C27:
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_04_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_04:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video offset=CINEMATIC_221, x=[HERO_X], y=[HERO_Y]
	ret


PRISON_HERO_WALK_RIGHT_POSE_05:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_06:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6C78:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F13, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F13, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_14:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_DRAW_CIN_422_WITH_POS_STEP_AT_C7A1BFCB_L2:
	call LABEL_6B76
	video type=0, offset=CV_0F90, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_338E, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_00:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_01:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_02:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_03:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6CF2:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6D03:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6D14:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6D25:
	call LABEL_6B76
	video type=0, offset=HERO_WALK_RIGHT_BODY_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_RIGHT_POSE_08:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6D4A:
	video type=0, offset=CV_39A2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C94, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6D68:
	video type=0, offset=CV_3A64, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C9C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


GUARDED_DRAW_CV_126:
	call LABEL_6B04
	jne [0x0A], 0x01, LABEL_6D95
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6D95:
	jne [0x0A], 0x02, LABEL_6DA1
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6DA1:
	jne [0x0A], 0x03, LABEL_6DAD
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6DAD:
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_04_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_DRAW_CV_071_L1:
	jne [0x05], 0x00, LABEL_6DD7
	video type=0, offset=HERO_WATER_DEPTH_LEFT_CASE_00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6DD7:
	jne [0x05], 0x01, LABEL_6DE3
	video offset=CINEMATIC_129, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6DE3:
	jne [0x05], 0x02, LABEL_6DEF
	video type=0, offset=HERO_WATER_DEPTH_LEFT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6DEF:
	jne [0x05], 0x03, LABEL_6DFB
	video offset=CINEMATIC_128, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6DFB:
	ret


LABEL_6DFC:
	je [0x0A], 0x00, DRAW_CV_074
	call GUARDED_DRAW_CV_126
