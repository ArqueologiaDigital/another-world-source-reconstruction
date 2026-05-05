DRAW_SPRITE_CIN_164_167_BY_VAR09:
	mov [0xF8], [0x09]
	shr [0xF8], 0x0004
	jne [0x0E], 0x00, LABEL_5F8C
	je [0xF8], 0x00, DRAW_CIN_164
	je [0xF8], 0x01, DRAW_CIN_165
	je [0xF8], 0x02, DRAW_CIN_166
	je [0xF8], 0x03, DRAW_CIN_167
	ret

LABEL_5F8C:
	jne [0x0E], 0x01, LABEL_5F95
	jmp DRAW_CIN_163

LABEL_5F95:
	jne [0x0E], 0x02, LABEL_5F9E
	jmp DRAW_CIN_162

LABEL_5F9E:
	jne [0x0E], 0x03, LABEL_5FA7
	jmp DRAW_CIN_161

LABEL_5FA7:
	jne [0x0E], 0x04, LABEL_5FB6
	je [0xF8], 0x01, DRAW_CIN_159
	jmp DRAW_CIN_160

LABEL_5FB6:
	jne [0x0E], 0x05, LABEL_5FBF
	jmp DRAW_CIN_158

LABEL_5FBF:
	jne [0x0E], 0x07, LABEL_5FCC
	je [0xF8], 0x01, DRAW_CIN_157
	ret

LABEL_5FCC:
	ret

DRAW_CIN_164:
	video offset=CINEMATIC_164, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_165:
	video offset=CINEMATIC_165, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_166:
	video offset=CINEMATIC_166, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_167:
	video offset=CINEMATIC_167, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_163:
	video offset=CINEMATIC_163, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_162:
	video offset=CINEMATIC_162, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_161:
	video offset=CINEMATIC_161, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_160:
	video offset=CINEMATIC_160, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_159:
	video offset=CINEMATIC_159, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_158:
	video offset=CINEMATIC_158, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_157:
	video offset=CINEMATIC_157, x=[0x07], y=[0x08], zoom=0x40
	ret
LABEL_600F:
	db 0x11

DRAW_CIN_168_IF_VAR09_EQ_1:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_168
	ret

DRAW_CIN_168:
	video offset=CINEMATIC_168, x=[0x07], y=[0x08], zoom=0x40
	ret

DISPATCH_VAR09_LOW_NIBBLE:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_169
	ret

DRAW_CIN_169:
	video offset=CINEMATIC_169, x=[0xf5], y=[0x08], zoom=0x40
	ret

LABEL_6038:
	video type=0, offset=COMMON_VIDEO_202, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DISPATCH_VAR09_LOW_NIBBLE
	video type=0, offset=COMMON_VIDEO_203, x=[0x07], y=[0x08], zoom=0x40
	jmp DISPATCH_VAR09_LOW_NIBBLE

LABEL_604E:
	video type=0, offset=COMMON_VIDEO_169, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DISPATCH_VAR09_LOW_NIBBLE
	video type=0, offset=COMMON_VIDEO_170, x=[0x07], y=[0x08], zoom=0x40
	jmp DISPATCH_VAR09_LOW_NIBBLE

LABEL_6064:
	video type=0, offset=COMMON_VIDEO_173, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DISPATCH_VAR09_LOW_NIBBLE
	video type=0, offset=COMMON_VIDEO_174, x=[0x07], y=[0x08], zoom=0x40
	jmp DISPATCH_VAR09_LOW_NIBBLE

LABEL_607E:
	video type=0, offset=COMMON_VIDEO_176, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DISPATCH_VAR09_LOW_NIBBLE
	video type=0, offset=COMMON_VIDEO_177, x=[0x07], y=[0x08], zoom=0x40
	jmp DISPATCH_VAR09_LOW_NIBBLE

LABEL_6094:
	video type=0, offset=COMMON_VIDEO_129, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DISPATCH_VAR09_LOW_NIBBLE
	video type=0, offset=COMMON_VIDEO_130, x=[0x07], y=[0x08], zoom=0x40
	jmp DISPATCH_VAR09_LOW_NIBBLE

LABEL_60AE:
	video type=0, offset=COMMON_VIDEO_181, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DISPATCH_VAR09_LOW_NIBBLE
	video type=0, offset=COMMON_VIDEO_182, x=[0x07], y=[0x08], zoom=0x40
	jmp DISPATCH_VAR09_LOW_NIBBLE

LABEL_60C8:
	video type=0, offset=COMMON_VIDEO_185, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DISPATCH_VAR09_LOW_NIBBLE
	video type=0, offset=COMMON_VIDEO_186, x=[0x07], y=[0x08], zoom=0x40
	jmp DISPATCH_VAR09_LOW_NIBBLE

LABEL_60E2:
	video type=0, offset=COMMON_VIDEO_189, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DISPATCH_VAR09_LOW_NIBBLE
	video type=0, offset=COMMON_VIDEO_190, x=[0x07], y=[0x08], zoom=0x40
	jmp DISPATCH_VAR09_LOW_NIBBLE

LABEL_60FC:
	video type=0, offset=COMMON_VIDEO_193, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DISPATCH_VAR09_LOW_NIBBLE
	video type=0, offset=COMMON_VIDEO_194, x=[0x07], y=[0x08], zoom=0x40
	jmp DISPATCH_VAR09_LOW_NIBBLE

LABEL_6116:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_167, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_168, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6138
	call LABEL_5D23
	jmp LABEL_613B

LABEL_6138:
	call LABEL_604E

LABEL_613B:
	ret

LABEL_613C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	sub [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_167, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_171, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6166
	call LABEL_5D23
	jmp LABEL_6169

LABEL_6166:
	call LABEL_604E

LABEL_6169:
	ret

LABEL_616A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_172, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6187
	call LABEL_5D2F
	jmp LABEL_618A

LABEL_6187:
	call LABEL_6064

LABEL_618A:
	ret

LABEL_618B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x01
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_175, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_61AE
	call LABEL_5D2F
	jmp LABEL_61B1

LABEL_61AE:
	call LABEL_607E

LABEL_61B1:
	ret

LABEL_61B2:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_178, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_61CF
	call LABEL_5D2F
	jmp LABEL_61D2

LABEL_61CF:
	call LABEL_6094

LABEL_61D2:
	ret

LABEL_61D3:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_179, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_180, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_61F5
	call LABEL_5D52
	jmp LABEL_61F8

LABEL_61F5:
	call LABEL_60AE

LABEL_61F8:
	ret

LABEL_61F9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_183, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_184, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_621B
	call LABEL_5D5E
	jmp LABEL_621E

LABEL_621B:
	call LABEL_60C8

LABEL_621E:
	ret

LABEL_621F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_187, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_188, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6241
	call LABEL_5D81
	jmp LABEL_6244

LABEL_6241:
	call LABEL_60E2

LABEL_6244:
	ret

LABEL_6245:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_191, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_192, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6267
	call LABEL_5DA4
	jmp LABEL_626A

LABEL_6267:
	call LABEL_60FC

LABEL_626A:
	ret

LABEL_626B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_191, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_195, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_628D
	call LABEL_5DA4
	jmp LABEL_6298

LABEL_628D:
	sub [0x07], 0x0001
	call LABEL_60FC
	add [0x07], 0x0001

LABEL_6298:
	ret

LABEL_6299:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_183, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_196, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_62BB
	call LABEL_5D81
	jmp LABEL_62BE

LABEL_62BB:
	call LABEL_60C8

LABEL_62BE:
	ret

LABEL_62BF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x01
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_179, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_197, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_62E7
	call LABEL_5D81
	jmp LABEL_62EA

LABEL_62E7:
	call LABEL_60AE

LABEL_62EA:
	ret

LABEL_62EB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_198, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6308
	call LABEL_5D81
	jmp LABEL_630B

LABEL_6308:
	call LABEL_6094

LABEL_630B:
	ret

LABEL_630C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_199, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6329
	call LABEL_5D5E
	jmp LABEL_632C

LABEL_6329:
	call LABEL_607E

LABEL_632C:
	ret

LABEL_632D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_200, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_634A
	call LABEL_5D52
	jmp LABEL_634D

LABEL_634A:
	call LABEL_6064

LABEL_634D:
	ret

LABEL_634E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_201, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_636B
	call LABEL_5D2F
	jmp LABEL_636E

LABEL_636B:
	call LABEL_6038

LABEL_636E:
	ret

GUARDED_HERO_ANIM_CV_128:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_638C
	call LABEL_5D2F
	jmp LABEL_638F

LABEL_638C:
	call LABEL_6094

LABEL_638F:
	ret

LABEL_6390:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_63AD
	call LABEL_5D52
	jmp LABEL_63B0

LABEL_63AD:
	call LABEL_60AE

LABEL_63B0:
	ret

LABEL_63B1:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_63CE
	call LABEL_5D5E
	jmp LABEL_63D1

LABEL_63CE:
	call LABEL_60C8

LABEL_63D1:
	ret

JUNK__63D2:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video offset=CINEMATIC_691, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	call LABEL_5D5E
	ret

LABEL_63E7:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video offset=CINEMATIC_699, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	call LABEL_5D5E
	ret

LABEL_63FC:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video offset=CINEMATIC_698, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	call LABEL_5D5E
	ret

LABEL_6411:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video offset=CINEMATIC_697, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	call LABEL_5D5E
	ret

LABEL_6426:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_424, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_6432:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_425, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_643E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_5CC9
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_5466
	sub [0x08], 0x000D
	ret

LABEL_645B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x0001
	call LABEL_5CE7
	add [0x08], 0x0001
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_286, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_547C
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_6488:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_5D05
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_5466
	sub [0x08], 0x000D
	ret

LABEL_64A5:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_5CE7
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_5466
	sub [0x08], 0x000D
	ret

LABEL_64C2:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_64D9
	add [0x08], 0x000D
	call DRAW_CIN_242_THEN_243
	sub [0x08], 0x000D

LABEL_64D9:
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_547C
	sub [0x08], 0x000D
	ret

LABEL_64ED:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_350, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_64C2
	ret

LABEL_64FC:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x0001
	video type=0, offset=COMMON_VIDEO_287, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x0001
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video offset=CINEMATIC_349, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_547C
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_652B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=0, offset=COMMON_VIDEO_287, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_5466
	sub [0x08], 0x000D
	ret

LABEL_654A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	add [0x07], 0x0004
	video type=0, offset=COMMON_VIDEO_275, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x0004
	sub [0x08], 0x000D
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_5492
	sub [0x08], 0x000D
	ret

LABEL_6579:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_5492
	sub [0x08], 0x000D
	ret

LABEL_6593:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	video offset=CINEMATIC_388, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_5492
	sub [0x08], 0x000D
	ret

LABEL_65BA:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	add [0x08], 0x000D
	video offset=CINEMATIC_387, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_286, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_547C
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_65E9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_5CC9
	add [0x08], 0x000D
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_54C2
	ret

LABEL_6606:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x000E
	call LABEL_5CE7
	add [0x08], 0x000E
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_290, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	call LABEL_54C2
	sub [0x07], 0x0002
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_5D05
	add [0x08], 0x000D
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_54C2
	ret

LABEL_664C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_5CE7
	add [0x08], 0x000D
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_54C2
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_6678:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_CIN_390
	video offset=CINEMATIC_692, x=[0x07], y=[0x08], zoom=0x40
	video offset=CINEMATIC_389, x=[0x07], y=[0x08], zoom=0x40
	ret

GUARDED_DRAW_CIN_342:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_342, x=[0x07], y=[0x08], zoom=0x40
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_CIN_390
	video offset=CINEMATIC_389, x=[0x07], y=[0x08], zoom=0x40
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_689, x=[0x07], y=[0x08], zoom=0x40
	video offset=CINEMATIC_690, x=[0x07], y=[0x08], zoom=0x40
	call JUNK__66D3
	ret

DRAW_SPRITE_164_167_Y_PLUS_E:
	add [0x08], 0x000E
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	sub [0x08], 0x000E
	ret

DRAW_SPRITE_236_239_Y_PLUS_D:
	add [0x08], 0x000D
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	sub [0x08], 0x000D
	ret

JUNK__66D3:
	video offset=CINEMATIC_688, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_390:
	video offset=CINEMATIC_390, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_66DF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_5337
	ret

LABEL_66F1:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_289, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x0001
	call LABEL_5365
	add [0x08], 0x0001
	add [0x07], 0x0001
	ret

LABEL_6713:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_5397
	ret

LABEL_6725:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_5365
	ret

LABEL_6737:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	je [0x0D], 0x00, LABEL_6755
	call LABEL_5D81
	jmp DECREMENT_VAR08_BY_D

LABEL_6755:
	call LABEL_6038
