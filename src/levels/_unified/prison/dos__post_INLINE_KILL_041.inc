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
	video offset=CINEMATIC_206, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video offset=CINEMATIC_207, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6B58:
	video offset=CINEMATIC_563, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video offset=CINEMATIC_564, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6B76:
	jne [0x05], 0x00, LABEL_6B82
	video offset=CINEMATIC_219, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6B82:
	jne [0x05], 0x01, LABEL_6B8E
	video offset=CINEMATIC_218, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6B8E:
	jne [0x05], 0x02, LABEL_6B9A
	video offset=CINEMATIC_217, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6B9A:
	jne [0x05], 0x03, LABEL_6BA6
	video offset=CINEMATIC_216, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6BA6:
	ret

LABEL_6BA7:
	video type=0, offset=COMMON_VIDEO_036, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video offset=CINEMATIC_220, x=[0x01], y=[0x02], zoom=0x40
	ret

GUARDED_DRAW_CV_159:
	call LABEL_6B04
	jne [0x0A], 0x01, LABEL_6BDF
	video type=0, offset=COMMON_VIDEO_159, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_160, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6BDF:
	jne [0x0A], 0x02, LABEL_6C03
	video type=0, offset=COMMON_VIDEO_157, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_158, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6C03:
	jne [0x0A], 0x03, LABEL_6C27
	video type=0, offset=COMMON_VIDEO_155, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_156, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6C27:
	video type=0, offset=COMMON_VIDEO_153, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_154, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6C45:
	video type=0, offset=COMMON_VIDEO_038, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video offset=CINEMATIC_221, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6C56:
	video type=0, offset=COMMON_VIDEO_040, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_041, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6C67:
	video type=0, offset=COMMON_VIDEO_042, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_043, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6C78:
	video type=0, offset=COMMON_VIDEO_044, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_045, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6C89:
	video type=0, offset=COMMON_VIDEO_046, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_047, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6C9A:
	call LABEL_6B76
	video type=0, offset=COMMON_VIDEO_016, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_017, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6CAE:
	video type=0, offset=COMMON_VIDEO_018, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_019, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6CBF:
	video type=0, offset=COMMON_VIDEO_020, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_021, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6CD0:
	video type=0, offset=COMMON_VIDEO_022, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_023, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6CE1:
	video type=0, offset=COMMON_VIDEO_024, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_025, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6CF2:
	video type=0, offset=COMMON_VIDEO_026, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_027, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6D03:
	video type=0, offset=COMMON_VIDEO_028, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_029, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6D14:
	video type=0, offset=COMMON_VIDEO_030, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_031, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6D25:
	call LABEL_6B76
	video type=0, offset=COMMON_VIDEO_032, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_033, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6D39:
	video type=0, offset=COMMON_VIDEO_034, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_035, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6D4A:
	video type=0, offset=COMMON_VIDEO_131, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_132, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6D68:
	video type=0, offset=COMMON_VIDEO_293, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_294, x=[0x01], y=[0x02], zoom=0x40
	ret

GUARDED_DRAW_CV_126:
	call LABEL_6B04
	jne [0x0A], 0x01, LABEL_6D95
	video type=0, offset=COMMON_VIDEO_126, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6D95:
	jne [0x0A], 0x02, LABEL_6DA1
	video type=0, offset=COMMON_VIDEO_125, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6DA1:
	jne [0x0A], 0x03, LABEL_6DAD
	video type=0, offset=COMMON_VIDEO_124, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6DAD:
	video type=0, offset=COMMON_VIDEO_122, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_123, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6DCB:
	jne [0x05], 0x00, LABEL_6DD7
	video type=0, offset=COMMON_VIDEO_000, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6DD7:
	jne [0x05], 0x01, LABEL_6DE3
	video offset=CINEMATIC_129, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6DE3:
	jne [0x05], 0x02, LABEL_6DEF
	video type=0, offset=COMMON_VIDEO_127, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6DEF:
	jne [0x05], 0x03, LABEL_6DFB
	video offset=CINEMATIC_128, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6DFB:
	ret

LABEL_6DFC:
	je [0x0A], 0x00, DRAW_CV_074
	call GUARDED_DRAW_CV_126
