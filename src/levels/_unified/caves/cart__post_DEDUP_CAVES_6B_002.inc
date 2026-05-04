LABEL_8024:
	ret

DRAW_BEAST_SPRITE_BY_VAR09_0E:
	mov [0xF8], [0x09]
	shr [0xF8], 0x0004
	and [0xF8], 0x000F
	jne [0x0E], 0x00, LABEL_8061
	je [0xF8], 0x00, DRAW_CIN_048
	je [0xF8], 0x01, DRAW_CIN_049
	je [0xF8], 0x02, DRAW_CIN_050
	je [0xF8], 0x03, DRAW_CIN_051
	je [0xF8], 0x04, DRAW_CIN_052
	je [0xF8], 0x05, DRAW_CIN_026
	je [0xF8], 0x06, DRAW_CIN_053
	ret

LABEL_8061:
	jne [0x0E], 0x01, LABEL_806A
	jmp DRAW_CIN_047

LABEL_806A:
	jne [0x0E], 0x02, LABEL_8073
	jmp DRAW_CIN_046

LABEL_8073:
	jne [0x0E], 0x03, LABEL_8082
	je [0xF8], 0x03, DRAW_CIN_041
	jmp DRAW_CIN_045

LABEL_8082:
	jne [0x0E], 0x04, LABEL_8091
	je [0xF8], 0x03, DRAW_CIN_043
	jmp DRAW_CIN_044

LABEL_8091:
	jne [0x0E], 0x05, LABEL_80A0
	je [0xF8], 0x03, DRAW_CIN_041
	jmp DRAW_CIN_042

LABEL_80A0:
	jne [0x0E], 0x06, LABEL_80AC
	video type=1, offset=CINEMATIC_040, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_80AC:
	jne [0x0E], 0x07, LABEL_80BF
	je [0xF8], 0x00, DRAW_CIN_038
	je [0xF8], 0x01, DRAW_CIN_039
	ret

LABEL_80BF:
	ret
LABEL_80C0:
	db 0x11

DRAW_CIN_048:
	video type=1, offset=CINEMATIC_048, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_049:
	video type=1, offset=CINEMATIC_049, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_050:
	video type=1, offset=CINEMATIC_050, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_051:
	video type=1, offset=CINEMATIC_051, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_052:
	video type=1, offset=CINEMATIC_052, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_026:
	video type=1, offset=CINEMATIC_026, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_053:
	video type=1, offset=CINEMATIC_053, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_047:
	video type=1, offset=CINEMATIC_047, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_046:
	video type=1, offset=CINEMATIC_046, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_045:
	video type=1, offset=CINEMATIC_045, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_041:
	video type=1, offset=CINEMATIC_041, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_044:
	video type=1, offset=CINEMATIC_044, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_043:
	video type=1, offset=CINEMATIC_043, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_042:
	video type=1, offset=CINEMATIC_042, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_038:
	video type=1, offset=CINEMATIC_038, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_039:
	video type=1, offset=CINEMATIC_039, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8121:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_061
	je [0xF8], 0x02, DRAW_CIN_062
	ret

DRAW_CIN_061:
	video type=1, offset=CINEMATIC_061, x=[0xf5], y=[0x08], zoom=0x40
	ret

DRAW_CIN_062:
	video type=1, offset=CINEMATIC_062, x=[0xf5], y=[0x08], zoom=0x40
	ret

LABEL_8141:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, LABEL_8155
	je [0xF8], 0x02, LABEL_816B
	ret

LABEL_8155:
	add [0x08], 0x000D
	sub [0x07], 0x0002
	video type=1, offset=CINEMATIC_031, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0002
	sub [0x08], 0x000D
	ret

LABEL_816B:
	add [0x08], 0x000D
	sub [0x07], 0x0002
	video type=1, offset=CINEMATIC_032, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0002
	sub [0x08], 0x000D
	ret

LABEL_8181:
	video type=0, offset=COMMON_VIDEO_320, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, LABEL_8194
	video type=0, offset=COMMON_VIDEO_322, x=[0x07], y=[0x08], zoom=0x40

LABEL_8194:
	jg [0x13], [0x30], LABEL_8121
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_8121
	video type=0, offset=COMMON_VIDEO_321, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_8121

LABEL_81AF:
	video type=0, offset=COMMON_VIDEO_323, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, LABEL_81C6
	video type=0, offset=COMMON_VIDEO_325, x=[0x07], y=[0x08], zoom=0x40

LABEL_81C6:
	jg [0x13], [0x30], LABEL_8121
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_8121
	video type=0, offset=COMMON_VIDEO_324, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_8121

LABEL_81E1:
	video type=0, offset=COMMON_VIDEO_326, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], LABEL_8141
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_8141
	video type=0, offset=COMMON_VIDEO_327, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_8141

LABEL_8201:
	video type=0, offset=COMMON_VIDEO_328, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_8141

LABEL_8209:
	sub [0x07], 0x0001
	call LABEL_8215
	add [0x07], 0x0001
	ret

LABEL_8215:
	video type=0, offset=COMMON_VIDEO_308, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_309, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8233:
	sub [0x07], 0x0001
	call LABEL_823F
	add [0x07], 0x0001
	ret

LABEL_823F:
	video type=0, offset=COMMON_VIDEO_306, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_307, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CV_304_THEN_305:
	video type=0, offset=COMMON_VIDEO_304, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_305, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_827B:
	add [0x07], 0x0001
	call DRAW_CV_304_THEN_305
	sub [0x07], 0x0001
	ret
