LABEL_5E88:
	video type=0, offset=COMMON_VIDEO_158, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_159, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5E9E:
	video type=0, offset=COMMON_VIDEO_125, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_126, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5EB4:
	video type=0, offset=COMMON_VIDEO_129, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_130, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5ECE:
	video type=0, offset=COMMON_VIDEO_132, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_133, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5EE4:
	video type=0, offset=COMMON_VIDEO_010, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_011, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5EFE:
	video type=0, offset=COMMON_VIDEO_137, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_138, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5F18:
	video type=0, offset=COMMON_VIDEO_141, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_142, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5F32:
	video type=0, offset=COMMON_VIDEO_145, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_146, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5F4C:
	video type=0, offset=COMMON_VIDEO_149, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_150, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5F66:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_123, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_124, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_5F88
	call LABEL_5B73
	jmp LABEL_5F8B

LABEL_5F88:
	call LABEL_5E9E

LABEL_5F8B:
	ret

LABEL_5F8C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	sub [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_123, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_127, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_5FB6
	call LABEL_5B73
	jmp LABEL_5FB9

LABEL_5FB6:
	call LABEL_5E9E

LABEL_5FB9:
	ret

GUARDED_HERO_ANIM_CV_128:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_5FD7
	call LABEL_5B7F
	jmp LABEL_5FDA

LABEL_5FD7:
	call LABEL_5EB4

LABEL_5FDA:
	ret

LABEL_5FDB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x01
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_131, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_5FFE
	call LABEL_5B7F
	jmp LABEL_6001

LABEL_5FFE:
	call LABEL_5ECE

LABEL_6001:
	ret

LABEL_6002:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_134, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_601F
	call LABEL_5B7F
	jmp LABEL_6022

LABEL_601F:
	call LABEL_5EE4

LABEL_6022:
	ret

LABEL_6023:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_135, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_136, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6045
	call LABEL_5BA2
	jmp LABEL_6048

LABEL_6045:
	call LABEL_5EFE

LABEL_6048:
	ret

LABEL_6049:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_139, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_140, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_606B
	call LABEL_5BAE
	jmp LABEL_606E

LABEL_606B:
	call LABEL_5F18

LABEL_606E:
	ret

LABEL_606F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_143, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_144, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6091
	call LABEL_5BD1
	jmp LABEL_6094

LABEL_6091:
	call LABEL_5F32

LABEL_6094:
	ret

LABEL_6095:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_147, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_148, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_60B7
	call LABEL_5BF4
	jmp LABEL_60BA

LABEL_60B7:
	call LABEL_5F4C

LABEL_60BA:
	ret

LABEL_60BB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_147, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_151, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_60DD
	call LABEL_5BF4
	jmp LABEL_60E8

LABEL_60DD:
	sub [0x07], 0x0001
	call LABEL_5F4C
	add [0x07], 0x0001

LABEL_60E8:
	ret

LABEL_60E9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_139, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_152, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_610B
	call LABEL_5BD1
	jmp LABEL_610E

LABEL_610B:
	call LABEL_5F18

LABEL_610E:
	ret

LABEL_610F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x01
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_135, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_153, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6137
	call LABEL_5BD1
	jmp LABEL_613A

LABEL_6137:
	call LABEL_5EFE

LABEL_613A:
	ret

LABEL_613B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_154, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6158
	call LABEL_5BD1
	jmp LABEL_615B

LABEL_6158:
	call LABEL_5EE4

LABEL_615B:
	ret

LABEL_615C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_155, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_6179
	call LABEL_5BAE
	jmp LABEL_617C

LABEL_6179:
	call LABEL_5ECE

LABEL_617C:
	ret

LABEL_617D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_156, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_619A
	call LABEL_5BA2
	jmp LABEL_619D

LABEL_619A:
	call LABEL_5EB4

LABEL_619D:
	ret

LABEL_619E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_157, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_61BB
	call LABEL_5B7F
	jmp LABEL_61BE

LABEL_61BB:
	call LABEL_5E88

LABEL_61BE:
	ret

GUARDED_HERO_ANIM_CV_009:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_009, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_61DC
	call LABEL_5B7F
	jmp LABEL_61DF

LABEL_61DC:
	call LABEL_5EE4

LABEL_61DF:
	ret

LABEL_61E0:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_009, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_61FD
	call LABEL_5BA2
	jmp LABEL_6200

LABEL_61FD:
	call LABEL_5EFE

LABEL_6200:
	ret

LABEL_6201:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_009, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_168_IF_VAR09_EQ_1
	je [0x0D], 0x00, LABEL_621E
	call LABEL_5BAE
	jmp LABEL_6221

LABEL_621E:
	call LABEL_5F18

LABEL_6221:
	ret
LABEL_6222:
	db 0x0A, 0x81, 0x67, 0x10, 0x52, 0x8D, 0x04, 0x5D
	db 0xB6, 0x54, 0x62, 0x87, 0x07, 0x08, 0x04, 0x5E
	db 0x60, 0x04, 0x5B, 0xAE, 0x05, 0x0A, 0x81, 0x67
	db 0x10, 0x52, 0x8D, 0x04, 0x5D, 0xB6, 0x54, 0x62
	db 0x95, 0x07, 0x08, 0x04, 0x5E, 0x60, 0x04, 0x5B
	db 0xAE, 0x05, 0x0A, 0x81, 0x67, 0x10, 0x52, 0x8D
	db 0x04, 0x5D, 0xB6, 0x54, 0x62, 0xA3, 0x07, 0x08
	db 0x04, 0x5E, 0x60, 0x04, 0x5B, 0xAE, 0x05, 0x0A
	db 0x81, 0x67, 0x10, 0x52, 0x8D, 0x04, 0x5D, 0xB6
	db 0x54, 0x62, 0xB1, 0x07, 0x08, 0x04, 0x5E, 0x60
	db 0x04, 0x5B, 0xAE, 0x05

LABEL_6276:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_424, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_6282:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_425, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_628E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_5B19
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_52B6
	sub [0x08], 0x000D
	ret

LABEL_62AB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x0001
	call LABEL_5B37
	add [0x08], 0x0001
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_242, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_52CC
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_62D8:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_5B55
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_52B6
	sub [0x08], 0x000D
	ret

LABEL_62F5:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_5B37
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_52B6
	sub [0x08], 0x000D
	ret

LABEL_6312:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_6329
	add [0x08], 0x000D
	call DRAW_CIN_242_THEN_243
	sub [0x08], 0x000D

LABEL_6329:
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_52CC
	sub [0x08], 0x000D
	ret

LABEL_633D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_350, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_6312
	ret

LABEL_634C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x0001
	video type=0, offset=COMMON_VIDEO_243, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x0001
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=1, offset=CINEMATIC_349, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_52CC
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_637B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=0, offset=COMMON_VIDEO_243, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_52B6
	sub [0x08], 0x000D
	ret

LABEL_639A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	add [0x07], 0x0004
	video type=0, offset=COMMON_VIDEO_231, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x0004
	sub [0x08], 0x000D
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_52E2
	sub [0x08], 0x000D
	ret

LABEL_63C9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_52E2
	sub [0x08], 0x000D
	ret

LABEL_63E3:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	video type=1, offset=CINEMATIC_388, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_52E2
	sub [0x08], 0x000D
	ret

LABEL_640A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	add [0x08], 0x000D
	video type=1, offset=CINEMATIC_387, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call DRAW_SPRITE_236_239_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_242, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_52CC
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_6439:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_5B19
	add [0x08], 0x000D
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_120, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_5312
	ret

LABEL_6456:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x000E
	call LABEL_5B37
	add [0x08], 0x000E
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_246, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	call LABEL_5312
	sub [0x07], 0x0002
	ret
LABEL_647F:
	db 0x0A, 0x81, 0x67, 0x10, 0x52, 0x8D, 0x03, 0x08
	db 0xFF, 0xF3, 0x04, 0x5B, 0x55, 0x03, 0x08, 0x00
	db 0x0D, 0x04, 0x50, 0x75, 0x57, 0x20, 0x76, 0x07
	db 0x08, 0x04, 0x53, 0x12, 0x05

LABEL_649C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_5B37
	add [0x08], 0x000D
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_120, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_5312
	ret
LABEL_64B9:
	db 0x0A, 0x81, 0x67, 0x10, 0x52, 0x8D, 0x04, 0x50
	db 0x75, 0x57, 0x20, 0x76, 0x07, 0x08, 0x05, 0x0A
	db 0x81, 0x67, 0x10, 0x52, 0x8D, 0x04, 0x65, 0x29
	db 0x54, 0x28, 0x54, 0x07, 0x08, 0x54, 0x24, 0xBB
	db 0x07, 0x08, 0x05

GUARDED_DRAW_CIN_342:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_342, x=[0x07], y=[0x08], zoom=0x40
	ret
LABEL_64E8:
	db 0x0A, 0x81, 0x67, 0x10, 0x52, 0x8D, 0x04, 0x65
	db 0x29, 0x54, 0x24, 0xBB, 0x07, 0x08, 0x05, 0x0A
	db 0x81, 0x67, 0x10, 0x52, 0x8D, 0x54, 0x22, 0x7D
	db 0x07, 0x08, 0x54, 0x22, 0x55, 0x07, 0x08, 0x04
	db 0x65, 0x23, 0x05

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
LABEL_6523:
	db 0x54, 0x22, 0x63, 0x07, 0x08, 0x05, 0x54, 0x22
	db 0x85, 0x07, 0x08, 0x05

LABEL_652F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_5187
	ret

LABEL_6541:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_245, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x0001
	call LABEL_51B5
	add [0x08], 0x0001
	add [0x07], 0x0001
	ret

LABEL_6563:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_51E7
	ret

LABEL_6575:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_51B5
	ret

LABEL_6587:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_164_167_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	je [0x0D], 0x00, LABEL_65A5
	call LABEL_5BD1
	jmp DECREMENT_VAR08_BY_D

LABEL_65A5:
	call LABEL_5E88
