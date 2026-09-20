LABEL_6BF4:
	sub [0x0A], 0x0001
	break
	jne [0x0A], 0x02, LABEL_6C00
	break

LABEL_6C00:
	jg [0x0A], [0x0C], LABEL_6BF4
	killChannel

LABEL_6C07:
	sub [0x0B], 0x0001
	jg [0x0B], 0x00, LABEL_6C3C
	je [HERO_POS_MASK], 0x00, LABEL_6C2A
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	mov [0x0B], [RANDOM_SEED]
	add [0x0B], 0x0006
	mov [0x0C], 0x0004
	setup channel=0x15, address=LABEL_6BD5
	ret


LABEL_6C2A:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	mov [0x0B], [0x3A]
	add [0x0B], 0x0006
	mov [0x0C], 0x0001
	setup channel=0x15, address=LABEL_6BD5

LABEL_6C3C:
	ret


LABEL_6C3D:
	video offset=CINEMATIC_206, x=[HERO_X], y=[HERO_Y]
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video offset=CINEMATIC_207, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6C5B:
	video offset=CINEMATIC_563, x=[HERO_X], y=[HERO_Y]
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video offset=CINEMATIC_564, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6C79:
	jne [0x05], 0x00, LABEL_6C85
	video offset=CINEMATIC_219, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6C85:
	jne [0x05], 0x01, LABEL_6C91
	video offset=CINEMATIC_218, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6C91:
	jne [0x05], 0x02, LABEL_6C9D
	video offset=CINEMATIC_217, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6C9D:
	jne [0x05], 0x03, LABEL_6CA9
	video offset=CINEMATIC_216, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6CA9:
	ret


LABEL_6CAA:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video offset=CINEMATIC_220, x=[HERO_X], y=[HERO_Y]
	ret


GUARDED_DRAW_CV_159:
	call LABEL_6C07
	jne [0x0A], 0x01, LABEL_6CE2
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_01_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6CE2:
	jne [0x0A], 0x02, LABEL_6D06
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_02_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6D06:
	jne [0x0A], 0x03, LABEL_6D2A
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_03_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6D2A:
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_04_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6D48:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video offset=CINEMATIC_221, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6D59:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6D6A:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6D7B:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F13, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F13, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6D8C:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6D9D:
	call LABEL_6C79
	video type=0, offset=CV_0F90, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_338E, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_STAND_LEFT_DRAW:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6DC2:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6DD3:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6DE4:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6DF5:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6E06:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6E17:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6E28:
	call LABEL_6C79
	video type=0, offset=HERO_WALK_RIGHT_BODY_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6E3C:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6E4D:
	video type=0, offset=CV_39A2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C94, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6E6B:
	video type=0, offset=CV_3A64, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C9C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


GUARDED_DRAW_CV_126:
	call LABEL_6C07
	jne [0x0A], 0x01, LABEL_6E98
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6E98:
	jne [0x0A], 0x02, LABEL_6EA4
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6EA4:
	jne [0x0A], 0x03, LABEL_6EB0
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6EB0:
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_04_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_DRAW_CV_071_L1:
	jne [0x05], 0x00, LABEL_6EDA
	video type=0, offset=HERO_WATER_DEPTH_LEFT_CASE_00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6EDA:
	jne [0x05], 0x01, LABEL_6EE6
	video offset=CINEMATIC_129, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6EE6:
	jne [0x05], 0x02, LABEL_6EF2
	video type=0, offset=HERO_WATER_DEPTH_LEFT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_6EF2:
	jne [0x05], 0x03, LABEL_6EFE
	video offset=CINEMATIC_128, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_6EFE:
	ret


LABEL_6EFF:
	je [0x0A], 0x00, DRAW_CV_074
	call GUARDED_DRAW_CV_126
