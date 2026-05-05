DRAW_CIN_022:
	video offset=CINEMATIC_022, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_023:
	video offset=CINEMATIC_023, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_024:
	video offset=CINEMATIC_024, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_025:
	video offset=CINEMATIC_025, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_027:
	video offset=CINEMATIC_027, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_021:
	video offset=CINEMATIC_021, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_020:
	video offset=CINEMATIC_020, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_019:
	video offset=CINEMATIC_019, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_018:
	video offset=CINEMATIC_018, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_017:
	video offset=CINEMATIC_017, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_016:
	video offset=CINEMATIC_016, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_015:
	video offset=CINEMATIC_015, x=[0x07], y=[0x08], zoom=0x40
	ret
LABEL_8ED7:
	db 0x11

DRAW_CIN_028_029_030_VAR09:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_028
	je [0xF8], 0x02, DRAW_CIN_029
	je [0xF8], 0x03, DRAW_CIN_030
	ret

DRAW_CIN_028:
	video offset=CINEMATIC_028, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_029:
	video offset=CINEMATIC_029, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_030:
	video offset=CINEMATIC_030, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_031_032_VAR09_LOW:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_031
	je [0xF8], 0x02, DRAW_CIN_032
	ret

DRAW_CIN_031:
	video offset=CINEMATIC_031, x=[0xf5], y=[0x08], zoom=0x40
	ret

DRAW_CIN_032:
	video offset=CINEMATIC_032, x=[0xf5], y=[0x08], zoom=0x40
	ret

LABEL_8F24:
	video type=0, offset=COMMON_VIDEO_202, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_203, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8F3A:
	video type=0, offset=COMMON_VIDEO_169, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_170, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8F50:
	video type=0, offset=COMMON_VIDEO_173, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_174, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8F6A:
	video type=0, offset=COMMON_VIDEO_176, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_177, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8F80:
	video type=0, offset=COMMON_VIDEO_129, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_130, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8F9A:
	video type=0, offset=COMMON_VIDEO_181, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_182, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8FB4:
	video type=0, offset=COMMON_VIDEO_185, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_186, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8FCE:
	video type=0, offset=COMMON_VIDEO_189, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_190, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8FE8:
	video type=0, offset=COMMON_VIDEO_193, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_194, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_9002:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_167, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_168, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_9024
	call LABEL_8BD5
	jmp LABEL_9027

LABEL_9024:
	call LABEL_8F3A

LABEL_9027:
	ret

LABEL_9028:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	sub [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_167, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_171, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_9052
	call LABEL_8BD5
	jmp LABEL_9055

LABEL_9052:
	call LABEL_8F3A

LABEL_9055:
	ret

LABEL_9056:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_172, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_9073
	call LABEL_8BE1
	jmp LABEL_9076

LABEL_9073:
	call LABEL_8F50

LABEL_9076:
	ret

LABEL_9077:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_175, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_909A
	call LABEL_8BE1
	jmp LABEL_909D

LABEL_909A:
	call LABEL_8F6A

LABEL_909D:
	ret

LABEL_909E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_178, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_90BB
	call LABEL_8BE1
	jmp LABEL_90BE

LABEL_90BB:
	call LABEL_8F80

LABEL_90BE:
	ret

LABEL_90BF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_179, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_180, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_90E1
	call LABEL_8C04
	jmp LABEL_90E4

LABEL_90E1:
	call LABEL_8F9A

LABEL_90E4:
	ret

LABEL_90E5:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_183, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_184, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_9107
	call LABEL_8C10
	jmp LABEL_910A

LABEL_9107:
	call LABEL_8FB4

LABEL_910A:
	ret

LABEL_910B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_187, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_188, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_912D
	call LABEL_8C33
	jmp LABEL_9130

LABEL_912D:
	call LABEL_8FCE

LABEL_9130:
	ret

LABEL_9131:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_191, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_192, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_9153
	call LABEL_8C56
	jmp LABEL_9156

LABEL_9153:
	call LABEL_8FE8

LABEL_9156:
	ret

LABEL_9157:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_191, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_195, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_9179
	call LABEL_8C56
	jmp LABEL_9184

LABEL_9179:
	sub [0x07], 0x0001
	call LABEL_8FE8
	add [0x07], 0x0001

LABEL_9184:
	ret

LABEL_9185:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_183, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_196, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_91A7
	call LABEL_8C33
	jmp LABEL_91AA

LABEL_91A7:
	call LABEL_8FB4

LABEL_91AA:
	ret

LABEL_91AB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_179, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_197, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_91D3
	call LABEL_8C33
	jmp LABEL_91D6

LABEL_91D3:
	call LABEL_8F9A

LABEL_91D6:
	ret

LABEL_91D7:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_198, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_91F4
	call LABEL_8C33
	jmp LABEL_91F7

LABEL_91F4:
	call LABEL_8F80

LABEL_91F7:
	ret

LABEL_91F8:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_199, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_9215
	call LABEL_8C10
	jmp LABEL_9218

LABEL_9215:
	call LABEL_8F6A

LABEL_9218:
	ret

LABEL_9219:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_200, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_9236
	call LABEL_8C04
	jmp LABEL_9239

LABEL_9236:
	call LABEL_8F50

LABEL_9239:
	ret

LABEL_923A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_201, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_9257
	call LABEL_8BE1
	jmp LABEL_925A

LABEL_9257:
	call LABEL_8F24

LABEL_925A:
	ret

GUARDED_HERO_ANIM_CV_128:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_9278
	call LABEL_8BE1
	jmp LABEL_927B

LABEL_9278:
	call LABEL_8F80

LABEL_927B:
	ret

LABEL_927C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_9299
	call LABEL_8C04
	jmp LABEL_929C

LABEL_9299:
	call LABEL_8F9A

LABEL_929C:
	ret

LABEL_929D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09
	je [0x0D], 0x00, LABEL_92BA
	call LABEL_8C10
	jmp LABEL_92BD

LABEL_92BA:
	call LABEL_8FB4

LABEL_92BD:
	ret

LABEL_92BE:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_139, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_92CA:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_140, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_92D6:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8B7B
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_835D
	sub [0x08], 0x000D
	ret

LABEL_92F3:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x0001
	call LABEL_8B99
	add [0x08], 0x0001
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_286, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_837A
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_9320:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8BB7
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_835D
	sub [0x08], 0x000D
	ret

LABEL_933D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8B99
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_835D
	sub [0x08], 0x000D
	ret

LABEL_935A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_9371
	add [0x08], 0x000D
	call DRAW_CV_304_THEN_305
	sub [0x08], 0x000D

LABEL_9371:
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_837A
	sub [0x08], 0x000D
	ret

LABEL_9385:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_060, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_935A
	ret

LABEL_9394:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x0001
	video type=0, offset=COMMON_VIDEO_287, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x0001
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_286, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_837A
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_93C3:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=0, offset=COMMON_VIDEO_287, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_835D
	sub [0x08], 0x000D
	ret

LABEL_93E2:
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

LABEL_9411:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call DRAW_BEAST_HEAD_CV165_166
	sub [0x08], 0x000D
	ret

LABEL_942B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	video offset=CINEMATIC_075, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_285, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call DRAW_BEAST_HEAD_CV165_166
	sub [0x08], 0x000D
	ret

LABEL_9452:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	add [0x08], 0x000D
	video offset=CINEMATIC_074, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=COMMON_VIDEO_286, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_837A
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_9481:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x78], 0x000A
	add [0x79], 0x0005
	video type=0, offset=COMMON_VIDEO_287, x=[0x78], y=[0x79], zoom=0x40
	sub [0x79], 0x0005
	add [0x78], 0x000A
	video offset=CINEMATIC_184, x=[0x78], y=[0x79], zoom=0x40
	ret

LABEL_94A2:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_8B7B
	add [0x08], 0x000D
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_HEAD_CV214_215
	ret

LABEL_94BF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x000E
	call LABEL_8B99
	add [0x08], 0x000E
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_290, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	call DRAW_BEAST_HEAD_CV214_215
	sub [0x07], 0x0002
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_8BB7
	add [0x08], 0x000D
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_HEAD_CV214_215
	ret

LABEL_9505:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_8B99
	add [0x08], 0x000D
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_HEAD_CV214_215
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	ret

JUNK__9531:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_CV_355
	video type=0, offset=COMMON_VIDEO_357, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_356, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_9545:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_059, x=[0x07], y=[0x08], zoom=0x40
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_CV_355
	video type=0, offset=COMMON_VIDEO_356, x=[0x07], y=[0x08], zoom=0x40
	ret
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=0, offset=COMMON_VIDEO_353, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_354, x=[0x07], y=[0x08], zoom=0x40
	call JUNK__958C
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

JUNK__958C:
	video offset=CINEMATIC_891, x=[0x07], y=[0x08], zoom=0x40
	ret
