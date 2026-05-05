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
	video type=0, offset=COMMON_VIDEO_074, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video offset=CINEMATIC_220, x=[HERO_X], y=[HERO_Y]
	ret

GUARDED_DRAW_CV_159:
	call LABEL_6A57
	jne [0x0A], 0x01, LABEL_6B32
	video type=0, offset=COMMON_VIDEO_053, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_054, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6B32:
	jne [0x0A], 0x02, LABEL_6B56
	video type=0, offset=COMMON_VIDEO_051, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_052, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6B56:
	jne [0x0A], 0x03, LABEL_6B7A
	video type=0, offset=COMMON_VIDEO_049, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_050, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6B7A:
	video type=0, offset=COMMON_VIDEO_047, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_048, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6B98:
	video type=0, offset=COMMON_VIDEO_075, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video offset=CINEMATIC_221, x=[HERO_X], y=[HERO_Y]
	ret

LABEL_6BA9:
	video type=0, offset=COMMON_VIDEO_076, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_077, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6BBA:
	video type=0, offset=COMMON_VIDEO_078, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_079, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6BCB:
	video type=0, offset=COMMON_VIDEO_080, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_081, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6BDC:
	video type=0, offset=COMMON_VIDEO_082, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_083, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6BED:
	call LABEL_6AC9
	video type=0, offset=COMMON_VIDEO_046, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_055, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6C01:
	video type=0, offset=COMMON_VIDEO_056, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_057, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6C12:
	video type=0, offset=COMMON_VIDEO_058, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_059, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6C23:
	video type=0, offset=COMMON_VIDEO_060, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_061, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6C34:
	video type=0, offset=COMMON_VIDEO_062, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_063, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6C45:
	video type=0, offset=COMMON_VIDEO_064, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_065, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6C56:
	video type=0, offset=COMMON_VIDEO_066, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_067, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6C67:
	video type=0, offset=COMMON_VIDEO_068, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_069, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6C78:
	call LABEL_6AC9
	video type=0, offset=COMMON_VIDEO_070, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_071, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6C8C:
	video type=0, offset=COMMON_VIDEO_072, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=COMMON_VIDEO_073, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6C9D:
	video type=0, offset=COMMON_VIDEO_012, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_013, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6CBB:
	video type=0, offset=COMMON_VIDEO_249, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_250, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

GUARDED_DRAW_CV_126:
	call LABEL_6A57
	jne [0x0A], 0x01, LABEL_6CE8
	video type=0, offset=COMMON_VIDEO_004, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6CE8:
	jne [0x0A], 0x02, LABEL_6CF4
	video type=0, offset=COMMON_VIDEO_003, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6CF4:
	jne [0x0A], 0x03, LABEL_6D00
	video type=0, offset=COMMON_VIDEO_002, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6D00:
	video type=0, offset=COMMON_VIDEO_000, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_001, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6D1E:
	jne [0x05], 0x00, LABEL_6D2A
	video type=0, offset=COMMON_VIDEO_006, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6D2A:
	jne [0x05], 0x01, LABEL_6D36
	video offset=CINEMATIC_129, x=[HERO_X], y=[HERO_Y]
	ret

LABEL_6D36:
	jne [0x05], 0x02, LABEL_6D42
	video type=0, offset=COMMON_VIDEO_005, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6D42:
	jne [0x05], 0x03, LABEL_6D4E
	video offset=CINEMATIC_128, x=[HERO_X], y=[HERO_Y]
	ret

LABEL_6D4E:
	ret

LABEL_6D4F:
	je [0x0A], 0x00, DRAW_CV_113
	call GUARDED_DRAW_CV_126

DRAW_CV_113:
	video type=0, offset=COMMON_VIDEO_113, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6D5E:
	je [0x0A], 0x00, DRAW_CV_114
	call GUARDED_DRAW_CV_126

DRAW_CV_114:
	video type=0, offset=COMMON_VIDEO_114, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6D6D:
	je [0x0A], 0x00, DRAW_CV_115
	call GUARDED_DRAW_CV_126

DRAW_CV_115:
	video type=0, offset=COMMON_VIDEO_115, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6D7C:
	je [0x0A], 0x00, DRAW_CV_116
	call GUARDED_DRAW_CV_126

DRAW_CV_116:
	video type=0, offset=COMMON_VIDEO_116, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6D8B:
	je [0x0A], 0x00, DRAW_CV_117
	call GUARDED_DRAW_CV_126

DRAW_CV_117:
	video type=0, offset=COMMON_VIDEO_117, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6D9A:
	jne [0x0A], 0x00, LABEL_6DA8
	video type=0, offset=COMMON_VIDEO_119, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_118

LABEL_6DA8:
	call GUARDED_DRAW_CV_126

DRAW_CV_118:
	video type=0, offset=COMMON_VIDEO_118, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6DB1:
	jne [0x0A], 0x00, LABEL_6DBF
	video type=0, offset=COMMON_VIDEO_008, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp LABEL_6DC2

LABEL_6DBF:
	call GUARDED_DRAW_CV_126

LABEL_6DC2:
	call LABEL_6D1E
	video type=0, offset=COMMON_VIDEO_007, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6DCB:
	jne [0x0A], 0x00, LABEL_6DD9
	video type=0, offset=COMMON_VIDEO_100, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_099

LABEL_6DD9:
	call GUARDED_DRAW_CV_126

DRAW_CV_099:
	video type=0, offset=COMMON_VIDEO_099, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6DE2:
	jne [0x0A], 0x00, LABEL_6DF0
	video type=0, offset=COMMON_VIDEO_102, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_101

LABEL_6DF0:
	call GUARDED_DRAW_CV_126

DRAW_CV_101:
	video type=0, offset=COMMON_VIDEO_101, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6DF9:
	jne [0x0A], 0x00, LABEL_6E07
	video type=0, offset=COMMON_VIDEO_104, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_103

LABEL_6E07:
	call GUARDED_DRAW_CV_126

DRAW_CV_103:
	video type=0, offset=COMMON_VIDEO_103, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6E10:
	jne [0x0A], 0x00, LABEL_6E1E
	video type=0, offset=COMMON_VIDEO_106, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_105

LABEL_6E1E:
	call GUARDED_DRAW_CV_126

DRAW_CV_105:
	video type=0, offset=COMMON_VIDEO_105, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6E27:
	jne [0x0A], 0x00, LABEL_6E35
	video type=0, offset=COMMON_VIDEO_108, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_107

LABEL_6E35:
	call GUARDED_DRAW_CV_126

DRAW_CV_107:
	video type=0, offset=COMMON_VIDEO_107, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6E3E:
	je [0x0A], 0x00, DRAW_CV_109
	call GUARDED_DRAW_CV_126

DRAW_CV_109:
	video type=0, offset=COMMON_VIDEO_109, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6E4D:
	je [0x0A], 0x00, DRAW_CV_110
	call GUARDED_DRAW_CV_126

DRAW_CV_110:
	video type=0, offset=COMMON_VIDEO_110, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6E5C:
	call LABEL_6D1E
	je [0x0A], 0x00, DRAW_CV_111
	call GUARDED_DRAW_CV_126

DRAW_CV_111:
	video type=0, offset=COMMON_VIDEO_111, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6E6E:
	je [0x0A], 0x00, DRAW_CV_112
	call GUARDED_DRAW_CV_126

DRAW_CV_112:
	video type=0, offset=COMMON_VIDEO_112, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

DRAW_CV_273:
	video type=0, offset=COMMON_VIDEO_273, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

DRAW_CV_270:
	video type=0, offset=COMMON_VIDEO_270, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

DRAW_CV_252:
	video type=0, offset=COMMON_VIDEO_252, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

DRAW_CV_255:
	video type=0, offset=COMMON_VIDEO_255, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

DRAW_CV_265:
	video type=0, offset=COMMON_VIDEO_265, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6E9B:
	video type=0, offset=COMMON_VIDEO_251, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x00
	jne [0x0A], 0x00, DRAW_CV_252
	video type=0, offset=COMMON_VIDEO_253, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6EB2:
	video type=0, offset=COMMON_VIDEO_254, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_255
	video type=0, offset=COMMON_VIDEO_256, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6EC3:
	video type=0, offset=COMMON_VIDEO_269, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_270
	video type=0, offset=COMMON_VIDEO_271, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6ED4:
	video type=0, offset=COMMON_VIDEO_272, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_273
	video type=0, offset=COMMON_VIDEO_274, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6EE5:
	video type=0, offset=COMMON_VIDEO_275, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_273
	video type=0, offset=COMMON_VIDEO_276, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6EF6:
	video type=0, offset=COMMON_VIDEO_258, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x00
	jne [0x0A], 0x00, DRAW_CV_252
	video type=0, offset=COMMON_VIDEO_259, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6F0D:
	video type=0, offset=COMMON_VIDEO_260, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_252
	video type=0, offset=COMMON_VIDEO_261, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6F1E:
	video type=0, offset=COMMON_VIDEO_262, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_255
	video type=0, offset=COMMON_VIDEO_263, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6F2F:
	video type=0, offset=COMMON_VIDEO_264, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_265
	video type=0, offset=COMMON_VIDEO_266, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6F40:
	video type=0, offset=COMMON_VIDEO_267, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_265
	video type=0, offset=COMMON_VIDEO_268, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

DRAW_CV_279:
	video type=0, offset=COMMON_VIDEO_279, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6F57:
	je [0x0A], 0x00, LABEL_6F63
	call DRAW_CV_279
	jmp LABEL_6F68

LABEL_6F63:
	video type=0, offset=COMMON_VIDEO_277, x=[HERO_X], y=[HERO_Y], zoom=0x40

LABEL_6F68:
	video type=0, offset=COMMON_VIDEO_278, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x00
	ret

LABEL_6F74:
	je [0x0A], 0x00, LABEL_6F80
	call DRAW_CV_279
	jmp DRAW_CV_281

LABEL_6F80:
	video type=0, offset=COMMON_VIDEO_280, x=[HERO_X], y=[HERO_Y], zoom=0x40

DRAW_CV_281:
	video type=0, offset=COMMON_VIDEO_281, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6F8B:
	je [0x0A], 0x00, LABEL_6F97
	call DRAW_CV_279
	jmp DRAW_CV_294

LABEL_6F97:
	video type=0, offset=COMMON_VIDEO_293, x=[HERO_X], y=[HERO_Y], zoom=0x40

DRAW_CV_294:
	video type=0, offset=COMMON_VIDEO_294, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6FA2:
	je [0x0A], 0x00, LABEL_6FAE
	call DRAW_CV_279
	jmp DRAW_CV_296

LABEL_6FAE:
	video type=0, offset=COMMON_VIDEO_295, x=[HERO_X], y=[HERO_Y], zoom=0x40

DRAW_CV_296:
	video type=0, offset=COMMON_VIDEO_296, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6FB9:
	je [0x0A], 0x00, DRAW_CV_297
	call DRAW_CV_279

DRAW_CV_297:
	video type=0, offset=COMMON_VIDEO_297, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6FC8:
	je [0x0A], 0x00, LABEL_6FD4
	call DRAW_CV_279
	jmp LABEL_6FD9

LABEL_6FD4:
	video type=0, offset=COMMON_VIDEO_283, x=[HERO_X], y=[HERO_Y], zoom=0x40

LABEL_6FD9:
	video type=0, offset=COMMON_VIDEO_284, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x00
	ret

LABEL_6FE5:
	je [0x0A], 0x00, LABEL_6FF1
	call DRAW_CV_279
	jmp DRAW_CV_286

LABEL_6FF1:
	video type=0, offset=COMMON_VIDEO_285, x=[HERO_X], y=[HERO_Y], zoom=0x40

DRAW_CV_286:
	video type=0, offset=COMMON_VIDEO_286, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_6FFC:
	je [0x0A], 0x00, LABEL_7008
	call DRAW_CV_279
	jmp DRAW_CV_288

LABEL_7008:
	video type=0, offset=COMMON_VIDEO_287, x=[HERO_X], y=[HERO_Y], zoom=0x40

DRAW_CV_288:
	video type=0, offset=COMMON_VIDEO_288, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7013:
	je [0x0A], 0x00, LABEL_701F
	call DRAW_CV_279
	jmp DRAW_CV_290

LABEL_701F:
	video type=0, offset=COMMON_VIDEO_289, x=[HERO_X], y=[HERO_Y], zoom=0x40

DRAW_CV_290:
	video type=0, offset=COMMON_VIDEO_290, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_702A:
	je [0x0A], 0x00, LABEL_7036
	call DRAW_CV_279
	jmp DRAW_CV_292

LABEL_7036:
	video type=0, offset=COMMON_VIDEO_291, x=[HERO_X], y=[HERO_Y], zoom=0x40

DRAW_CV_292:
	video type=0, offset=COMMON_VIDEO_292, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret

LABEL_7041:
	je [0x1F], 0x00, LABEL_7070
	jl [0x1E], 0x00, INLINE_SET_VAR20_TO_1
	mov [0x20], 0xFFFF

LABEL_7051:
	sub [0x1E], [0x1F]
	add [0x20], 0x0001
	jge [0x1E], 0x00, LABEL_7051
	ret
