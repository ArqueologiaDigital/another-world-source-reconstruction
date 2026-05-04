LABEL_6B46:
	mov [0xF8], [0x09]
	shr [0xF8], 0x0004
	and [0xF8], 0x000F
	jne [0x0E], 0x00, LABEL_6B82
	je [0xF8], 0x00, DRAW_CV_298__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0xF8], 0x01, DRAW_CIN_174
	je [0xF8], 0x02, DRAW_CIN_175__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0xF8], 0x03, DRAW_CIN_176
	je [0xF8], 0x04, DRAW_CIN_177__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0xF8], 0x05, DRAW_CIN_178
	je [0xF8], 0x06, DRAW_CIN_179
	ret

LABEL_6B82:
	jne [0x0E], 0x01, LABEL_6B8B
	jmp DRAW_CIN_173__AMIGA__POST_INCREMENT_VAR07_BY_1

LABEL_6B8B:
	jne [0x0E], 0x02, LABEL_6B94
	jmp DRAW_CIN_172__AMIGA__POST_INCREMENT_VAR07_BY_1

LABEL_6B94:
	jne [0x0E], 0x03, LABEL_6B9D
	jmp DRAW_CIN_171__AMIGA__POST_INCREMENT_VAR07_BY_1

LABEL_6B9D:
	jne [0x0E], 0x04, LABEL_6BAC
	je [0xF8], 0x01, DRAW_CIN_169__AMIGA__POST_INCREMENT_VAR07_BY_1
	jmp DRAW_CIN_170

LABEL_6BAC:
	jne [0x0E], 0x05, LABEL_6BB5
	jmp DRAW_CIN_168__AMIGA__POST_INCREMENT_VAR07_BY_1

LABEL_6BB5:
	jne [0x0E], 0x07, LABEL_6BC2
	je [0xF8], 0x01, DRAW_CIN_167__AMIGA__POST_INCREMENT_VAR07_BY_1
	ret

LABEL_6BC2:
	ret

DRAW_CV_298__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=0, offset=COMMON_VIDEO_298, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_174:
	video type=1, offset=CINEMATIC_174, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_175__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_175, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_176:
	video type=1, offset=CINEMATIC_176, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_177__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_177, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_179:
	video type=1, offset=CINEMATIC_179, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_173__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_173, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_172__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_172, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_171__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_171, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_170:
	video type=1, offset=CINEMATIC_170, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_169__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_169, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_168__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_168, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_167__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_167, x=[0x07], y=[0x08], zoom=0x40
	ret
LABEL_6C11:
	db 0x11

DRAW_CIN_180_181_182_VAR09:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_180
	je [0xF8], 0x02, DRAW_CIN_181
	je [0xF8], 0x03, DRAW_CIN_182
	ret

DRAW_CIN_180:
	video type=1, offset=CINEMATIC_180, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_181:
	video type=1, offset=CINEMATIC_181, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_182:
	video type=1, offset=CINEMATIC_182, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_183_184_VAR09_LOW:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_183
	je [0xF8], 0x02, DRAW_CIN_184
	ret

DRAW_CIN_183:
	video type=1, offset=CINEMATIC_183, x=[0xf5], y=[0x08], zoom=0x40
	ret

DRAW_CIN_184:
	video type=1, offset=CINEMATIC_184, x=[0xf5], y=[0x08], zoom=0x40
	ret

LABEL_6C5E:
	video type=0, offset=COMMON_VIDEO_158, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_183_184_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_159, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_183_184_VAR09_LOW

LABEL_6C74:
	video type=0, offset=COMMON_VIDEO_125, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_183_184_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_126, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_183_184_VAR09_LOW

LABEL_6C8A:
	video type=0, offset=COMMON_VIDEO_129, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_183_184_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_130, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_183_184_VAR09_LOW

LABEL_6CA4:
	video type=0, offset=COMMON_VIDEO_132, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_183_184_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_133, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_183_184_VAR09_LOW

LABEL_6CBA:
	video type=0, offset=COMMON_VIDEO_010, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_183_184_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_011, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_183_184_VAR09_LOW

LABEL_6CD4:
	video type=0, offset=COMMON_VIDEO_137, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_183_184_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_138, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_183_184_VAR09_LOW

LABEL_6CEE:
	video type=0, offset=COMMON_VIDEO_141, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_183_184_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_142, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_183_184_VAR09_LOW

LABEL_6D08:
	video type=0, offset=COMMON_VIDEO_145, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_183_184_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_146, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_183_184_VAR09_LOW

LABEL_6D22:
	video type=0, offset=COMMON_VIDEO_149, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_183_184_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_150, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_183_184_VAR09_LOW

LABEL_6D3C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_123, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_124, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	je [0x0D], 0x00, LABEL_6D5E
	call LABEL_690F
	jmp LABEL_6D61

LABEL_6D5E:
	call LABEL_6C74

LABEL_6D61:
	ret

LABEL_6D62:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	sub [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_123, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_127, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	je [0x0D], 0x00, LABEL_6D8C
	call LABEL_690F
	jmp LABEL_6D8F

LABEL_6D8C:
	call LABEL_6C74

LABEL_6D8F:
	ret

LABEL_6D90:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	je [0x0D], 0x00, LABEL_6DAD
	call LABEL_691B
	jmp LABEL_6DB0

LABEL_6DAD:
	call LABEL_6C8A

LABEL_6DB0:
	ret

LABEL_6DB1:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_131, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	je [0x0D], 0x00, LABEL_6DD4
	call LABEL_691B
	jmp LABEL_6DD7

LABEL_6DD4:
	call LABEL_6CA4

LABEL_6DD7:
	ret

LABEL_6DD8:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_134, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	je [0x0D], 0x00, LABEL_6DF5
	call LABEL_691B
	jmp LABEL_6DF8

LABEL_6DF5:
	call LABEL_6CBA

LABEL_6DF8:
	ret

LABEL_6DF9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_135, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_136, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	je [0x0D], 0x00, LABEL_6E1B
	call LABEL_693E
	jmp LABEL_6E1E

LABEL_6E1B:
	call LABEL_6CD4

LABEL_6E1E:
	ret

LABEL_6E1F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_139, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_140, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	je [0x0D], 0x00, LABEL_6E41
	call LABEL_694A
	jmp LABEL_6E44

LABEL_6E41:
	call LABEL_6CEE

LABEL_6E44:
	ret

LABEL_6E45:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_143, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_144, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	je [0x0D], 0x00, LABEL_6E67
	call LABEL_696D
	jmp LABEL_6E6A

LABEL_6E67:
	call LABEL_6D08

LABEL_6E6A:
	ret

LABEL_6E6B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_147, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_148, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	je [0x0D], 0x00, LABEL_6E8D
	call LABEL_6990
	jmp LABEL_6E90

LABEL_6E8D:
	call LABEL_6D22

LABEL_6E90:
	ret

LABEL_6E91:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_147, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_151, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	je [0x0D], 0x00, LABEL_6EB3
	call LABEL_6990
	jmp LABEL_6EBE

LABEL_6EB3:
	sub [0x07], 0x0001
	call LABEL_6D22
	add [0x07], 0x0001

LABEL_6EBE:
	ret

LABEL_6EBF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_139, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_152, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	je [0x0D], 0x00, LABEL_6EE1
	call LABEL_696D
	jmp LABEL_6EE4

LABEL_6EE1:
	call LABEL_6CEE

LABEL_6EE4:
	ret

LABEL_6EE5:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_135, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_153, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	je [0x0D], 0x00, LABEL_6F0D
	call LABEL_696D
	jmp LABEL_6F10

LABEL_6F0D:
	call LABEL_6CD4

LABEL_6F10:
	ret

LABEL_6F11:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_154, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	je [0x0D], 0x00, LABEL_6F2E
	call LABEL_696D
	jmp LABEL_6F31

LABEL_6F2E:
	call LABEL_6CBA

LABEL_6F31:
	ret

LABEL_6F32:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_155, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	je [0x0D], 0x00, LABEL_6F4F
	call LABEL_694A
	jmp LABEL_6F52

LABEL_6F4F:
	call LABEL_6CA4

LABEL_6F52:
	ret

LABEL_6F53:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_156, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	je [0x0D], 0x00, LABEL_6F70
	call LABEL_693E
	jmp LABEL_6F73

LABEL_6F70:
	call LABEL_6C8A

LABEL_6F73:
	ret

LABEL_6F74:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_157, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	je [0x0D], 0x00, LABEL_6F91
	call LABEL_691B
	jmp LABEL_6F94

LABEL_6F91:
	call LABEL_6C5E

LABEL_6F94:
	ret

LABEL_6F95:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_009, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	je [0x0D], 0x00, LABEL_6FB2
	call LABEL_691B
	jmp LABEL_6FB5

LABEL_6FB2:
	call LABEL_6CBA

LABEL_6FB5:
	ret

LABEL_6FB6:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_009, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	je [0x0D], 0x00, LABEL_6FD3
	call LABEL_693E
	jmp LABEL_6FD6

LABEL_6FD3:
	call LABEL_6CD4

LABEL_6FD6:
	ret

LABEL_6FD7:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_6B46
	video type=0, offset=COMMON_VIDEO_009, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_180_181_182_VAR09
	je [0x0D], 0x00, LABEL_6FF4
	call LABEL_694A
	jmp LABEL_6FF7

LABEL_6FF4:
	call LABEL_6CEE

LABEL_6FF7:
	ret
LABEL_6FF8:
	db 0x0A, 0x81, 0x67, 0x10, 0x60, 0x4A, 0x04, 0x6B
	db 0x46, 0x54, 0x28, 0x9C, 0x07, 0x08, 0x04, 0x6C
	db 0x12, 0x04, 0x69, 0x4A, 0x05, 0x0A, 0x81, 0x67
	db 0x10, 0x60, 0x4A, 0x04, 0x6B, 0x46, 0x54, 0x28
	db 0xAC, 0x07, 0x08, 0x04, 0x6C, 0x12, 0x04, 0x69
	db 0x4A, 0x05, 0x0A, 0x81, 0x67, 0x10, 0x60, 0x4A
	db 0x04, 0x6B, 0x46, 0x54, 0x28, 0xBC, 0x07, 0x08
	db 0x04, 0x6C, 0x12, 0x04, 0x69, 0x4A, 0x05, 0x0A
	db 0x81, 0x67, 0x10, 0x60, 0x4A, 0x04, 0x6B, 0x46
	db 0x54, 0x28, 0xCC, 0x07, 0x08, 0x04, 0x6C, 0x12
	db 0x04, 0x69, 0x4A, 0x05

LABEL_704C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_274, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_7058:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_275, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_7064:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_68B5
	call LABEL_730E
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_6097
	sub [0x08], 0x000D
	ret

LABEL_7081:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x0001
	call LABEL_68D3
	add [0x08], 0x0001
	call LABEL_730E
	video type=0, offset=COMMON_VIDEO_242, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_60B4
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_70AE:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_68F1
	call LABEL_730E
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_6097
	sub [0x08], 0x000D
	ret

LABEL_70CB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_68D3
	call LABEL_730E
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_6097
	sub [0x08], 0x000D
	ret

LABEL_70E8:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_70FF
	add [0x08], 0x000D
	call LABEL_6020
	sub [0x08], 0x000D

LABEL_70FF:
	call LABEL_730E
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_60B4
	sub [0x08], 0x000D
	ret

LABEL_7113:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_207, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_70E8
	ret

LABEL_7122:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x0001
	video type=0, offset=COMMON_VIDEO_243, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x0001
	call LABEL_730E
	video type=0, offset=COMMON_VIDEO_242, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_60B4
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_7151:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=0, offset=COMMON_VIDEO_243, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_730E
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_6097
	sub [0x08], 0x000D
	ret

LABEL_7170:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	add [0x07], 0x0004
	video type=0, offset=COMMON_VIDEO_231, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x0004
	sub [0x08], 0x000D
	call LABEL_730E
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_60D1
	sub [0x08], 0x000D
	ret

LABEL_719F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_730E
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_60D1
	sub [0x08], 0x000D
	ret

LABEL_71B9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	video type=1, offset=CINEMATIC_211, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_730E
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_60D1
	sub [0x08], 0x000D
	ret

LABEL_71E0:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	add [0x08], 0x000D
	video type=1, offset=CINEMATIC_210, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_730E
	video type=0, offset=COMMON_VIDEO_242, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_60B4
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret
LABEL_720F:
	db 0x0A, 0x81, 0x67, 0x10, 0x60, 0x4A, 0x03, 0x78
	db 0xFF, 0xF6, 0x03, 0x79, 0x00, 0x05, 0x57, 0x21
	db 0x8A, 0x78, 0x79, 0x03, 0x79, 0xFF, 0xFB, 0x03
	db 0x78, 0x00, 0x0A, 0x54, 0x3F, 0x49, 0x78, 0x79
	db 0x05

LABEL_7230:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_68B5
	add [0x08], 0x000D
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_120, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_610F
	ret

LABEL_724D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x000E
	call LABEL_68D3
	add [0x08], 0x000E
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_246, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	call LABEL_610F
	sub [0x07], 0x0002
	ret
LABEL_7276:
	db 0x0A, 0x81, 0x67, 0x10, 0x60, 0x4A, 0x03, 0x08
	db 0xFF, 0xF3, 0x04, 0x68, 0xF1, 0x03, 0x08, 0x00
	db 0x0D, 0x04, 0x5D, 0xE8, 0x57, 0x20, 0x76, 0x07
	db 0x08, 0x04, 0x61, 0x0F, 0x05

LABEL_7293:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_68D3
	add [0x08], 0x000D
	call LABEL_5DE8
	video type=0, offset=COMMON_VIDEO_120, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_610F
	ret
LABEL_72B0:
	db 0x0A, 0x81, 0x67, 0x10, 0x60, 0x4A, 0x04, 0x5D
	db 0xE8, 0x57, 0x20, 0x76, 0x07, 0x08, 0x05, 0x0A
	db 0x81, 0x67, 0x10, 0x60, 0x4A, 0x04, 0x73, 0x20
	db 0x57, 0x20, 0x5F, 0x07, 0x08, 0x57, 0x1F, 0xEA
	db 0x07, 0x08, 0x05

LABEL_72D3:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_206, x=[0x07], y=[0x08], zoom=0x40
	ret
LABEL_72DF:
	db 0x0A, 0x81, 0x67, 0x10, 0x60, 0x4A, 0x04, 0x73
	db 0x20, 0x57, 0x1F, 0xEA, 0x07, 0x08, 0x05, 0x0A
	db 0x81, 0x67, 0x10, 0x60, 0x4A, 0x57, 0x1F, 0xD4
	db 0x07, 0x08, 0x57, 0x1F, 0xC6, 0x07, 0x08, 0x04
	db 0x73, 0x1A, 0x05

LABEL_7302:
	add [0x08], 0x000E
	call LABEL_6B46
	sub [0x08], 0x000E
	ret

LABEL_730E:
	add [0x08], 0x000D
	call LABEL_5DE8
	sub [0x08], 0x000D
	ret
LABEL_731A:
	db 0x54, 0x0B, 0xB1, 0x07, 0x08, 0x05, 0x57, 0x1F
	db 0xDC, 0x07, 0x08, 0x05

LABEL_7326:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_7302
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_5F44
	ret

LABEL_7338:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call LABEL_7302
	video type=0, offset=COMMON_VIDEO_245, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x0001
	call LABEL_5F72
	add [0x08], 0x0001
	add [0x07], 0x0001
	ret

LABEL_735A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_7302
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_5FA4
	ret

LABEL_736C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_7302
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_5F72
	ret

LABEL_737E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_7302
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	je [0x0D], 0x00, LABEL_739C
	call LABEL_696D
	jmp DECREMENT_VAR08_BY_D

LABEL_739C:
	call LABEL_6C5E
