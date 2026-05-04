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
	video type=1, offset=CINEMATIC_206, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=1, offset=CINEMATIC_207, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6C5B:
	video type=1, offset=CINEMATIC_563, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=1, offset=CINEMATIC_564, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6C79:
	jne [0x05], 0x00, LABEL_6C85
	video type=1, offset=CINEMATIC_219, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6C85:
	jne [0x05], 0x01, LABEL_6C91
	video type=1, offset=CINEMATIC_218, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6C91:
	jne [0x05], 0x02, LABEL_6C9D
	video type=1, offset=CINEMATIC_217, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6C9D:
	jne [0x05], 0x03, LABEL_6CA9
	video type=1, offset=CINEMATIC_216, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6CA9:
	ret

LABEL_6CAA:
	video type=0, offset=COMMON_VIDEO_036, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=1, offset=CINEMATIC_220, x=[0x01], y=[0x02], zoom=0x40
	ret

GUARDED_DRAW_CV_159:
	call LABEL_6C07
	jne [0x0A], 0x01, LABEL_6CE2
	video type=0, offset=COMMON_VIDEO_159, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_160, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6CE2:
	jne [0x0A], 0x02, LABEL_6D06
	video type=0, offset=COMMON_VIDEO_157, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_158, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6D06:
	jne [0x0A], 0x03, LABEL_6D2A
	video type=0, offset=COMMON_VIDEO_155, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_156, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6D2A:
	video type=0, offset=COMMON_VIDEO_153, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_154, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6D48:
	video type=0, offset=COMMON_VIDEO_038, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=1, offset=CINEMATIC_221, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6D59:
	video type=0, offset=COMMON_VIDEO_040, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_041, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6D6A:
	video type=0, offset=COMMON_VIDEO_042, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_043, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6D7B:
	video type=0, offset=COMMON_VIDEO_044, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_045, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6D8C:
	video type=0, offset=COMMON_VIDEO_046, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_047, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6D9D:
	call LABEL_6C79
	video type=0, offset=COMMON_VIDEO_016, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_017, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6DB1:
	video type=0, offset=COMMON_VIDEO_018, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_019, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6DC2:
	video type=0, offset=COMMON_VIDEO_020, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_021, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6DD3:
	video type=0, offset=COMMON_VIDEO_022, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_023, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6DE4:
	video type=0, offset=COMMON_VIDEO_024, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_025, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6DF5:
	video type=0, offset=COMMON_VIDEO_026, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_027, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6E06:
	video type=0, offset=COMMON_VIDEO_028, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_029, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6E17:
	video type=0, offset=COMMON_VIDEO_030, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_031, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6E28:
	call LABEL_6C79
	video type=0, offset=COMMON_VIDEO_032, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_033, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6E3C:
	video type=0, offset=COMMON_VIDEO_034, x=[0x01], y=[0x02], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_035, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6E4D:
	video type=0, offset=COMMON_VIDEO_131, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_132, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6E6B:
	video type=0, offset=COMMON_VIDEO_293, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_294, x=[0x01], y=[0x02], zoom=0x40
	ret

GUARDED_DRAW_CV_126:
	call LABEL_6C07
	jne [0x0A], 0x01, LABEL_6E98
	video type=0, offset=COMMON_VIDEO_126, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6E98:
	jne [0x0A], 0x02, LABEL_6EA4
	video type=0, offset=COMMON_VIDEO_125, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6EA4:
	jne [0x0A], 0x03, LABEL_6EB0
	video type=0, offset=COMMON_VIDEO_124, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6EB0:
	video type=0, offset=COMMON_VIDEO_122, x=[0x01], y=[0x02], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_123, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6ECE:
	jne [0x05], 0x00, LABEL_6EDA
	video type=0, offset=COMMON_VIDEO_000, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6EDA:
	jne [0x05], 0x01, LABEL_6EE6
	video type=1, offset=CINEMATIC_129, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6EE6:
	jne [0x05], 0x02, LABEL_6EF2
	video type=0, offset=COMMON_VIDEO_127, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6EF2:
	jne [0x05], 0x03, LABEL_6EFE
	video type=1, offset=CINEMATIC_128, x=[0x01], y=[0x02], zoom=0x40
	ret

LABEL_6EFE:
	ret

LABEL_6EFF:
	je [0x0A], 0x00, DRAW_CV_074
	call GUARDED_DRAW_CV_126
