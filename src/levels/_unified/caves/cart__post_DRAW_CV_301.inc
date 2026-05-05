DRAW_CIN_022:
	video offset=CINEMATIC_022, x=[0x07], y=[0x08]
	ret

DRAW_CIN_023:
	video offset=CINEMATIC_023, x=[0x07], y=[0x08]
	ret

DRAW_CIN_024:
	video offset=CINEMATIC_024, x=[0x07], y=[0x08]
	ret

DRAW_CIN_025:
	video offset=CINEMATIC_025, x=[0x07], y=[0x08]
	ret

DRAW_CIN_027:
	video offset=CINEMATIC_027, x=[0x07], y=[0x08]
	ret

DRAW_CIN_021:
	video offset=CINEMATIC_021, x=[0x07], y=[0x08]
	ret

DRAW_CIN_020:
	video offset=CINEMATIC_020, x=[0x07], y=[0x08]
	ret

DRAW_CIN_019:
	video offset=CINEMATIC_019, x=[0x07], y=[0x08]
	ret

DRAW_CIN_018:
	video offset=CINEMATIC_018, x=[0x07], y=[0x08]
	ret

DRAW_CIN_017:
	video offset=CINEMATIC_017, x=[0x07], y=[0x08]
	ret

DRAW_CIN_016:
	video offset=CINEMATIC_016, x=[0x07], y=[0x08]
	ret

DRAW_CIN_015:
	video offset=CINEMATIC_015, x=[0x07], y=[0x08]
	ret
LABEL_8E4E:
	db 0x11

DRAW_CIN_028_029_030_VAR09:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_028
	je [0xF8], 0x02, DRAW_CIN_029
	je [0xF8], 0x03, DRAW_CIN_030
	ret

DRAW_CIN_028:
	video offset=CINEMATIC_028, x=[0x07], y=[0x08]
	ret

DRAW_CIN_029:
	video offset=CINEMATIC_029, x=[0x07], y=[0x08]
	ret

DRAW_CIN_030:
	video offset=CINEMATIC_030, x=[0x07], y=[0x08]
	ret

DRAW_CIN_031_032_VAR09_LOW:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_031
	je [0xF8], 0x02, DRAW_CIN_032
	ret

DRAW_CIN_031:
	video offset=CINEMATIC_031, x=[0xf5], y=[0x08]
	ret

DRAW_CIN_032:
	video offset=CINEMATIC_032, x=[0xf5], y=[0x08]
	ret

LABEL_8E9B:
	video type=0, offset=COMMON_VIDEO_202, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_203, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8EB1:
	video type=0, offset=COMMON_VIDEO_169, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_170, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8EC7:
	video type=0, offset=COMMON_VIDEO_173, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_174, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8EE1:
	video type=0, offset=COMMON_VIDEO_176, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_177, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8EF7:
	video type=0, offset=COMMON_VIDEO_129, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_130, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8F11:
	video type=0, offset=COMMON_VIDEO_181, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_182, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8F2B:
	video type=0, offset=COMMON_VIDEO_185, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_186, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8F45:
	video type=0, offset=COMMON_VIDEO_189, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_190, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8F5F:
	video type=0, offset=COMMON_VIDEO_193, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_194, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8F79:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_167, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_168, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_8F9B
	call LABEL_8B4C
	jmp LABEL_8F9E

LABEL_8F9B:
	call LABEL_8EB1

LABEL_8F9E:
	ret

LABEL_8F9F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	sub [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_167, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_171, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_8FC9
	call LABEL_8B4C
	jmp LABEL_8FCC

LABEL_8FC9:
	call LABEL_8EB1

LABEL_8FCC:
	ret

LABEL_8FCD:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_172, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_8FEA
	call LABEL_8B58
	jmp LABEL_8FED

LABEL_8FEA:
	call LABEL_8EC7

LABEL_8FED:
	ret

LABEL_8FEE:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_175, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_9011
	call LABEL_8B58
	jmp LABEL_9014

LABEL_9011:
	call LABEL_8EE1

LABEL_9014:
	ret

LABEL_9015:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_178, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_9032
	call LABEL_8B58
	jmp LABEL_9035

LABEL_9032:
	call LABEL_8EF7

LABEL_9035:
	ret

LABEL_9036:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_179, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_180, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_9058
	call LABEL_8B7B
	jmp LABEL_905B

LABEL_9058:
	call LABEL_8F11

LABEL_905B:
	ret

LABEL_905C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_183, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_184, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_907E
	call LABEL_8B87
	jmp LABEL_9081

LABEL_907E:
	call LABEL_8F2B

LABEL_9081:
	ret

LABEL_9082:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_187, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_188, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_90A4
	call LABEL_8BAA
	jmp LABEL_90A7

LABEL_90A4:
	call LABEL_8F45

LABEL_90A7:
	ret

LABEL_90A8:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_191, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_192, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_90CA
	call LABEL_8BCD
	jmp LABEL_90CD

LABEL_90CA:
	call LABEL_8F5F

LABEL_90CD:
	ret

LABEL_90CE:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_191, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_195, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_90F0
	call LABEL_8BCD
	jmp LABEL_90FB

LABEL_90F0:
	sub [0x07], 0x0001
	call LABEL_8F5F
	add [0x07], 0x0001

LABEL_90FB:
	ret

LABEL_90FC:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_183, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_196, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_911E
	call LABEL_8BAA
	jmp LABEL_9121

LABEL_911E:
	call LABEL_8F2B

LABEL_9121:
	ret

LABEL_9122:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_179, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_197, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_914A
	call LABEL_8BAA
	jmp LABEL_914D

LABEL_914A:
	call LABEL_8F11

LABEL_914D:
	ret

LABEL_914E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_198, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_916B
	call LABEL_8BAA
	jmp LABEL_916E

LABEL_916B:
	call LABEL_8EF7

LABEL_916E:
	ret

LABEL_916F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_199, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_918C
	call LABEL_8B87
	jmp LABEL_918F

LABEL_918C:
	call LABEL_8EE1

LABEL_918F:
	ret

LABEL_9190:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_200, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_91AD
	call LABEL_8B7B
	jmp LABEL_91B0

LABEL_91AD:
	call LABEL_8EC7

LABEL_91B0:
	ret

LABEL_91B1:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_201, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_91CE
	call LABEL_8B58
	jmp LABEL_91D1

LABEL_91CE:
	call LABEL_8E9B

LABEL_91D1:
	ret

GUARDED_HERO_ANIM_CV_128:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_91EF
	call LABEL_8B58
	jmp LABEL_91F2

LABEL_91EF:
	call LABEL_8EF7

LABEL_91F2:
	ret

LABEL_91F3:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_9210
	call LABEL_8B7B
	jmp LABEL_9213

LABEL_9210:
	call LABEL_8F11

LABEL_9213:
	ret

LABEL_9214:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_9231
	call LABEL_8B87
	jmp LABEL_9234

LABEL_9231:
	call LABEL_8F2B

LABEL_9234:
	ret

LABEL_9235:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_139, x=[0x07], y=[0x08]
	ret

LABEL_9241:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_140, x=[0x07], y=[0x08]
	ret

LABEL_924D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8AF2
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_82D4
	sub [0x08], 0x000D
	ret

LABEL_926A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x0001
	call LABEL_8B10
	add [0x08], 0x0001
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_286, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_82F1
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_9297:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8B2E
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_82D4
	sub [0x08], 0x000D
	ret

LABEL_92B4:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8B10
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_82D4
	sub [0x08], 0x000D
	ret

LABEL_92D1:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_92E8
	add [0x08], 0x000D
	call DRAW_CV_304_THEN_305
	sub [0x08], 0x000D

LABEL_92E8:
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_82F1
	sub [0x08], 0x000D
	ret

LABEL_92FC:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_060, x=[0x07], y=[0x08]
	call LABEL_92D1
	ret

LABEL_930B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x0001
	video type=0, offset=COMMON_VIDEO_287, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x0001
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_286, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_82F1
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_933A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=0, offset=COMMON_VIDEO_287, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_82D4
	sub [0x08], 0x000D
	ret

LABEL_9359:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	add [0x07], 0x0004
	video type=0, offset=COMMON_VIDEO_275, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x0004
	sub [0x08], 0x000D
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call DRAW_BEAST_HEAD_CV165_166
	sub [0x08], 0x000D
	ret

LABEL_9388:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call DRAW_BEAST_HEAD_CV165_166
	sub [0x08], 0x000D
	ret

LABEL_93A2:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	video offset=CINEMATIC_075, x=[0x07], y=[0x08]
	sub [0x08], 0x000D
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call DRAW_BEAST_HEAD_CV165_166
	sub [0x08], 0x000D
	ret

LABEL_93C9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	add [0x08], 0x000D
	video offset=CINEMATIC_074, x=[0x07], y=[0x08]
	sub [0x08], 0x000D
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_286, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_82F1
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_93F8:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x78], 0x000A
	add [0x79], 0x0005
	video type=0, offset=COMMON_VIDEO_287, x=[0x78], y=[0x79], zoom=0x40
	sub [0x79], 0x0005
	add [0x78], 0x000A
	video offset=CINEMATIC_184, x=[0x78], y=[0x79]
	ret

LABEL_9419:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_8AF2
	add [0x08], 0x000D
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_HEAD_CV214_215
	ret

LABEL_9436:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x000E
	call LABEL_8B10
	add [0x08], 0x000E
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_290, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	call DRAW_BEAST_HEAD_CV214_215
	sub [0x07], 0x0002
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_8B2E
	add [0x08], 0x000D
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_HEAD_CV214_215
	ret

LABEL_947C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_8B10
	add [0x08], 0x000D
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_HEAD_CV214_215
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	ret

JUNK__94A8:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_CV_355
	video type=0, offset=COMMON_VIDEO_357, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_356, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_94BC:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_059, x=[0x07], y=[0x08]
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_CV_355
	video type=0, offset=COMMON_VIDEO_356, x=[0x07], y=[0x08], zoom=0x40
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=0, offset=COMMON_VIDEO_353, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_354, x=[0x07], y=[0x08], zoom=0x40
	call JUNK__9503
	ret

DRAW_HERO_Y_PLUS_E:
	add [0x08], 0x000E
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	sub [0x08], 0x000E
	ret

DRAW_BEAST_Y_PLUS_D:
	add [0x08], 0x000D
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	sub [0x08], 0x000D
	ret

JUNK__9503:
	video offset=CINEMATIC_882, x=[0x07], y=[0x08]
	ret
