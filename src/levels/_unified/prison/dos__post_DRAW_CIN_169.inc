LABEL_5F35:
	video type=0, offset=COMMON_VIDEO_202, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jg [0xF6], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_203, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5F4B:
	video type=0, offset=COMMON_VIDEO_169, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jg [0xF6], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_170, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5F61:
	video type=0, offset=COMMON_VIDEO_173, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_174, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5F7B:
	video type=0, offset=COMMON_VIDEO_176, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jg [0xF6], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_177, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5F91:
	video type=0, offset=COMMON_VIDEO_129, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_130, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5FAB:
	video type=0, offset=COMMON_VIDEO_181, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_182, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5FC5:
	video type=0, offset=COMMON_VIDEO_185, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_186, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5FDF:
	video type=0, offset=COMMON_VIDEO_189, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_190, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5FF9:
	video type=0, offset=COMMON_VIDEO_193, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_194, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_6013:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_167, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_168, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6035
	call LABEL_5C20
	jmp LABEL_6038

LABEL_6035:
	call LABEL_5F4B

LABEL_6038:
	ret

LABEL_6039:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	sub [BUDDY_X], 0x0001
	video type=0, offset=COMMON_VIDEO_167, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_X], 0x0001
	video type=0, offset=COMMON_VIDEO_171, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6063
	call LABEL_5C20
	jmp LABEL_6066

LABEL_6063:
	call LABEL_5F4B

LABEL_6066:
	ret

LABEL_6067:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_172, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6084
	call LABEL_5C2C
	jmp LABEL_6087

LABEL_6084:
	call LABEL_5F61

LABEL_6087:
	ret

LABEL_6088:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x01
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_175, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_60AB
	call LABEL_5C2C
	jmp LABEL_60AE

LABEL_60AB:
	call LABEL_5F7B

LABEL_60AE:
	ret

LABEL_60AF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_178, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_60CC
	call LABEL_5C2C
	jmp LABEL_60CF

LABEL_60CC:
	call LABEL_5F91

LABEL_60CF:
	ret

LABEL_60D0:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_179, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_180, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_60F2
	call LABEL_5C4F
	jmp LABEL_60F5

LABEL_60F2:
	call LABEL_5FAB

LABEL_60F5:
	ret

LABEL_60F6:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_183, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_184, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6118
	call LABEL_5C5B
	jmp LABEL_611B

LABEL_6118:
	call LABEL_5FC5

LABEL_611B:
	ret

LABEL_611C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_187, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_188, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_613E
	call LABEL_5C7E
	jmp LABEL_6141

LABEL_613E:
	call LABEL_5FDF

LABEL_6141:
	ret

LABEL_6142:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_191, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_192, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6164
	call LABEL_5CA1
	jmp LABEL_6167

LABEL_6164:
	call LABEL_5FF9

LABEL_6167:
	ret

LABEL_6168:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_191, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_195, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_618A
	call LABEL_5CA1
	jmp LABEL_6195

LABEL_618A:
	sub [BUDDY_X], 0x0001
	call LABEL_5FF9
	add [BUDDY_X], 0x0001

LABEL_6195:
	ret

LABEL_6196:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_183, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_196, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_61B8
	call LABEL_5C7E
	jmp LABEL_61BB

LABEL_61B8:
	call LABEL_5FC5

LABEL_61BB:
	ret

LABEL_61BC:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x01
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_179, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_197, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_61E4
	call LABEL_5C7E
	jmp LABEL_61E7

LABEL_61E4:
	call LABEL_5FAB

LABEL_61E7:
	ret

LABEL_61E8:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_198, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6205
	call LABEL_5C7E
	jmp LABEL_6208

LABEL_6205:
	call LABEL_5F91

LABEL_6208:
	ret

LABEL_6209:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_199, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6226
	call LABEL_5C5B
	jmp LABEL_6229

LABEL_6226:
	call LABEL_5F7B

LABEL_6229:
	ret

LABEL_622A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_200, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6247
	call LABEL_5C4F
	jmp LABEL_624A

LABEL_6247:
	call LABEL_5F61

LABEL_624A:
	ret

LABEL_624B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_201, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6268
	call LABEL_5C2C
	jmp LABEL_626B

LABEL_6268:
	call LABEL_5F35

LABEL_626B:
	ret

GUARDED_HERO_ANIM_CV_128:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_128, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6289
	call LABEL_5C2C
	jmp LABEL_628C

LABEL_6289:
	call LABEL_5F91

LABEL_628C:
	ret

LABEL_628D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_128, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_62AA
	call LABEL_5C4F
	jmp LABEL_62AD

LABEL_62AA:
	call LABEL_5FAB

LABEL_62AD:
	ret

LABEL_62AE:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_128, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_62CB
	call LABEL_5C5B
	jmp LABEL_62CE

LABEL_62CB:
	call LABEL_5FC5

LABEL_62CE:
	ret

JUNK__62CF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video offset=CINEMATIC_691, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_168_IF_VAR09_EQ_1
	call LABEL_5C5B
	ret

LABEL_62E4:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video offset=CINEMATIC_699, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_168_IF_VAR09_EQ_1
	call LABEL_5C5B
	ret

LABEL_62F9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video offset=CINEMATIC_698, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_168_IF_VAR09_EQ_1
	call LABEL_5C5B
	ret

LABEL_630E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video offset=CINEMATIC_697, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_168_IF_VAR09_EQ_1
	call LABEL_5C5B
	ret

LABEL_6323:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_424, x=[BUDDY_X], y=[BUDDY_Y]
	ret

LABEL_632F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_425, x=[BUDDY_X], y=[BUDDY_Y]
	ret

LABEL_633B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_5BC6
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	call LABEL_5363
	sub [BUDDY_Y], 0x000D
	ret

LABEL_6358:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [BUDDY_X], 0x0001
	sub [BUDDY_Y], 0x0001
	call LABEL_5BE4
	add [BUDDY_Y], 0x0001
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_286, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	call LABEL_5379
	sub [BUDDY_Y], 0x000D
	sub [BUDDY_X], 0x0001
	ret

LABEL_6385:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_5C02
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	call LABEL_5363
	sub [BUDDY_Y], 0x000D
	ret

LABEL_63A2:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_5BE4
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	call LABEL_5363
	sub [BUDDY_Y], 0x000D
	ret

LABEL_63BF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_63D6
	add [BUDDY_Y], 0x000D
	call DRAW_CIN_242_THEN_243
	sub [BUDDY_Y], 0x000D

LABEL_63D6:
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	call LABEL_5379
	sub [BUDDY_Y], 0x000D
	ret

LABEL_63EA:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_350, x=[BUDDY_X], y=[BUDDY_Y]
	call LABEL_63BF
	ret

LABEL_63F9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [BUDDY_X], 0x0001
	sub [BUDDY_Y], 0x0001
	video type=0, offset=COMMON_VIDEO_287, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x0001
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video offset=CINEMATIC_349, x=[BUDDY_X], y=[BUDDY_Y]
	add [BUDDY_Y], 0x000D
	call LABEL_5379
	sub [BUDDY_Y], 0x000D
	sub [BUDDY_X], 0x0001
	ret

LABEL_6428:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=0, offset=COMMON_VIDEO_287, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	call LABEL_5363
	sub [BUDDY_Y], 0x000D
	ret

LABEL_6447:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [BUDDY_Y], 0x000D
	add [BUDDY_X], 0x0004
	video type=0, offset=COMMON_VIDEO_275, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	sub [BUDDY_X], 0x0004
	sub [BUDDY_Y], 0x000D
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	call LABEL_538F
	sub [BUDDY_Y], 0x000D
	ret

LABEL_6476:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	call LABEL_538F
	sub [BUDDY_Y], 0x000D
	ret

LABEL_6490:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [BUDDY_Y], 0x000D
	video offset=CINEMATIC_388, x=[BUDDY_X], y=[BUDDY_Y]
	sub [BUDDY_Y], 0x000D
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	call LABEL_538F
	sub [BUDDY_Y], 0x000D
	ret

LABEL_64B7:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [BUDDY_X], 0x0001
	add [BUDDY_Y], 0x000D
	video offset=CINEMATIC_387, x=[BUDDY_X], y=[BUDDY_Y]
	sub [BUDDY_Y], 0x000D
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_286, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	call LABEL_5379
	sub [BUDDY_Y], 0x000D
	sub [BUDDY_X], 0x0001
	ret

LABEL_64E6:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [BUDDY_Y], 0x000D
	call LABEL_5BC6
	add [BUDDY_Y], 0x000D
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_164, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_53BF
	ret

LABEL_6503:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [BUDDY_X], 0x0001
	sub [BUDDY_Y], 0x000E
	call LABEL_5BE4
	add [BUDDY_Y], 0x000E
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_290, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_X], 0x0001
	call LABEL_53BF
	sub [BUDDY_X], 0x0002
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [BUDDY_Y], 0x000D
	call LABEL_5C02
	add [BUDDY_Y], 0x000D
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_164, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_53BF
	ret

LABEL_6549:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [BUDDY_Y], 0x000D
	call LABEL_5BE4
	add [BUDDY_Y], 0x000D
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_164, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_53BF
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_164, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	ret

LABEL_6575:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_CIN_390
	video offset=CINEMATIC_692, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_389, x=[BUDDY_X], y=[BUDDY_Y]
	ret

GUARDED_DRAW_CIN_342:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_342, x=[BUDDY_X], y=[BUDDY_Y]
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_CIN_390
	video offset=CINEMATIC_389, x=[BUDDY_X], y=[BUDDY_Y]
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_689, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_690, x=[BUDDY_X], y=[BUDDY_Y]
	call JUNK__65D0
	ret

DRAW_SPRITE_164_167_Y_PLUS_E:
	add [BUDDY_Y], 0x000E
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	sub [BUDDY_Y], 0x000E
	ret

DRAW_SPRITE_236_239_Y_PLUS_D:
	add [BUDDY_Y], 0x000D
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	sub [BUDDY_Y], 0x000D
	ret

JUNK__65D0:
	video offset=CINEMATIC_688, x=[BUDDY_X], y=[BUDDY_Y]
	ret

DRAW_CIN_390:
	video offset=CINEMATIC_390, x=[BUDDY_X], y=[BUDDY_Y]
	ret

LABEL_65DC:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_5234
	ret

LABEL_65EE:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [BUDDY_X], 0x0001
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_289, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	sub [BUDDY_Y], 0x0001
	call LABEL_5262
	add [BUDDY_Y], 0x0001
	add [BUDDY_X], 0x0001
	ret

LABEL_6610:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_5294
	ret

LABEL_6622:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_5262
	ret

LABEL_6634:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	je [0x0D], 0x00, LABEL_6652
	call LABEL_5C7E
	jmp DECREMENT_VAR08_BY_D

LABEL_6652:
	call LABEL_5F35
