DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_054__AMIGA__POST_SHARED_RET
	je [0xF8], 0x02, DRAW_CIN_055__AMIGA__POST_SHARED_RET
	je [0xF8], 0x03, DRAW_CIN_056__AMIGA__POST_SHARED_RET
	ret

DRAW_CIN_054__AMIGA__POST_SHARED_RET:
	video type=1, offset=CINEMATIC_054, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_055__AMIGA__POST_SHARED_RET:
	video type=1, offset=CINEMATIC_055, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_056__AMIGA__POST_SHARED_RET:
	video type=1, offset=CINEMATIC_056, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_057__AMIGA__POST_SHARED_RET
	je [0xF8], 0x02, DRAW_CIN_058__AMIGA__POST_SHARED_RET
	ret

DRAW_CIN_057__AMIGA__POST_SHARED_RET:
	video type=1, offset=CINEMATIC_057, x=[0xf5], y=[0x08], zoom=0x40
	ret

DRAW_CIN_058__AMIGA__POST_SHARED_RET:
	video type=1, offset=CINEMATIC_058, x=[0xf5], y=[0x08], zoom=0x40
	ret

LABEL_7FFF:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_195, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET
	video type=0, offset=COMMON_VIDEO_196, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET

LABEL_801C:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_162, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET
	video type=0, offset=COMMON_VIDEO_163, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET

LABEL_8039:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_121, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET
	video type=0, offset=COMMON_VIDEO_122, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET

LABEL_805A:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_167, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET
	video type=0, offset=COMMON_VIDEO_168, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET

LABEL_8077:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_170, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET
	video type=0, offset=COMMON_VIDEO_171, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET

LABEL_8098:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_174, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET
	video type=0, offset=COMMON_VIDEO_175, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET

LABEL_80B9:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_178, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET
	video type=0, offset=COMMON_VIDEO_179, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET

LABEL_80DA:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_182, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET
	video type=0, offset=COMMON_VIDEO_183, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET

LABEL_80FB:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_186, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET
	video type=0, offset=COMMON_VIDEO_187, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET

LABEL_811C:
	video type=0, offset=COMMON_VIDEO_224, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET

LABEL_8127:
	video type=0, offset=COMMON_VIDEO_227, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET

LABEL_8132:
	video type=0, offset=COMMON_VIDEO_230, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET

LABEL_813D:
	video type=0, offset=COMMON_VIDEO_233, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET

LABEL_8148:
	video type=0, offset=COMMON_VIDEO_237, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET

LABEL_8153:
	video type=0, offset=COMMON_VIDEO_239, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET

LABEL_815E:
	video type=0, offset=COMMON_VIDEO_221, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_057_058_VAR09_LOW__AMIGA__POST_SHARED_RET

LABEL_8169:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_817B
	call LABEL_7FA6
	jmp LABEL_8180

LABEL_817B:
	video type=0, offset=COMMON_VIDEO_160, x=[0x07], y=[0x08], zoom=0x40

LABEL_8180:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_161, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	call LABEL_801C
	ret

LABEL_818F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_81A1
	call LABEL_7FA6
	jmp BEAST_FULL_ANIM_FRAME

LABEL_81A1:
	add [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_160, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x0001

BEAST_FULL_ANIM_FRAME:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	call LABEL_801C
	ret

LABEL_81BD:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_81CC
	call LABEL_7F88

LABEL_81CC:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_165, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	call LABEL_8039
	ret

LABEL_81DB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	je [0x0D], 0x00, LABEL_81F0
	call LABEL_7F88

LABEL_81F0:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_166, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	call LABEL_805A
	ret

LABEL_81FF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_820E
	call LABEL_7F88

LABEL_820E:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_169, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	call LABEL_8077
	ret

LABEL_821D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_822F
	call LABEL_7F6A
	jmp LABEL_8234

LABEL_822F:
	video type=0, offset=COMMON_VIDEO_172, x=[0x07], y=[0x08], zoom=0x40

LABEL_8234:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_173, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	call LABEL_8098
	ret

LABEL_8243:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_8255
	call LABEL_7F5E
	jmp LABEL_825A

LABEL_8255:
	video type=0, offset=COMMON_VIDEO_176, x=[0x07], y=[0x08], zoom=0x40

LABEL_825A:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_177, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	call LABEL_80B9
	ret

LABEL_8269:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_827B
	call LABEL_7F40
	jmp LABEL_8280

LABEL_827B:
	video type=0, offset=COMMON_VIDEO_180, x=[0x07], y=[0x08], zoom=0x40

LABEL_8280:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_181, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	call LABEL_80DA
	ret

LABEL_828F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_82A1
	call LABEL_7F34
	jmp LABEL_82A6

LABEL_82A1:
	video type=0, offset=COMMON_VIDEO_184, x=[0x07], y=[0x08], zoom=0x40

LABEL_82A6:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_185, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	call LABEL_80FB
	ret

LABEL_82B5:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_82C7
	call LABEL_7F34
	jmp LABEL_82CC

LABEL_82C7:
	video type=0, offset=COMMON_VIDEO_184, x=[0x07], y=[0x08], zoom=0x40

LABEL_82CC:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_188, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	add [0x07], 0x0001
	call LABEL_80FB
	sub [0x07], 0x0001
	ret

LABEL_82E3:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_82F5
	call LABEL_7F40
	jmp LABEL_82FA

LABEL_82F5:
	video type=0, offset=COMMON_VIDEO_176, x=[0x07], y=[0x08], zoom=0x40

LABEL_82FA:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_189, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	call LABEL_80B9
	ret

LABEL_8309:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	je [0x0D], 0x00, LABEL_8321
	call LABEL_7F40
	jmp LABEL_8326

LABEL_8321:
	video type=0, offset=COMMON_VIDEO_172, x=[0x07], y=[0x08], zoom=0x40

LABEL_8326:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_190, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	call LABEL_8098
	ret

LABEL_8335:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_8344
	call LABEL_7F40

LABEL_8344:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_191, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	call LABEL_8077
	ret

LABEL_8353:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_8362
	call LABEL_7F5E

LABEL_8362:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_192, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	call LABEL_805A
	ret

LABEL_8371:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_8380
	call LABEL_7F6A

LABEL_8380:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_193, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	call LABEL_8039
	ret

LABEL_838F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_839E
	call LABEL_7F88

LABEL_839E:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_194, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	call LABEL_7FFF
	ret

GUARDED_DRAW_CV_304_305:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_83BC
	call LABEL_7F88

LABEL_83BC:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_120, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	call LABEL_8039
	ret

LABEL_83CB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_83DA
	call LABEL_7F6A

LABEL_83DA:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_120, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	call LABEL_805A
	ret

LABEL_83E9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_83F8
	call LABEL_7F5E

LABEL_83F8:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_120, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09__AMIGA__POST_SHARED_RET
	call LABEL_8077
	ret
LABEL_8407:
	db 0x0A, 0x81, 0x67, 0x10, 0x7F, 0xB2, 0x54, 0x0D
	db 0x2B, 0x07, 0x08, 0x04, 0x7D, 0x50, 0x57, 0x20
	db 0x76, 0x07, 0x08, 0x04, 0x7F, 0xB3, 0x04, 0x80
	db 0x5A, 0x05, 0x04, 0x91, 0xD3, 0x06, 0x07, 0x84
	db 0x21, 0x11

LABEL_8429:
	call AND_VAR11_WITH_EFFF
	jmp LABEL_8438
LABEL_842F:
	db 0x04, 0x59, 0xB4, 0x0A, 0x01, 0x2F, 0x02, 0x53
	db 0x5E

LABEL_8438:
	call LABEL_8169
	sub [0x07], 0x0002
	break
	jg [0x07], [0x29], LABEL_844F
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_CV_304_305

LABEL_844F:
	call LABEL_818F
	sub [0x07], 0x0002
	break
	jg [0x07], [0x29], LABEL_8466
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_CV_304_305

LABEL_8466:
	call LABEL_81BD
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_847D
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_CV_304_305

LABEL_847D:
	call LABEL_81DB
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_8494
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_CV_304_305

LABEL_8494:
	call LABEL_81FF
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_84AB
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_CV_304_305

LABEL_84AB:
	call LABEL_821D
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_84C2
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_CV_304_305

LABEL_84C2:
	call LABEL_8243
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_84D9
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_CV_304_305

LABEL_84D9:
	call LABEL_8269
	sub [0x07], 0x0002
	break
	jg [0x07], [0x29], LABEL_84F0
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_CV_304_305

LABEL_84F0:
	call LABEL_828F
	sub [0x07], 0x0002
	break
	jg [0x07], [0x29], LABEL_8507
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_CV_304_305

LABEL_8507:
	call LABEL_82B5
	sub [0x07], 0x0002
	break
	jg [0x07], [0x29], LABEL_851E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_CV_304_305

LABEL_851E:
	call LABEL_82E3
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_8535
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_CV_304_305

LABEL_8535:
	call LABEL_8309
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_854C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_CV_304_305

LABEL_854C:
	call LABEL_8335
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_8563
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_CV_304_305

LABEL_8563:
	call LABEL_8353
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_857A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_CV_304_305

LABEL_857A:
	call LABEL_8371
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_8591
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_CV_304_305

LABEL_8591:
	call LABEL_838F
	sub [0x07], 0x0002
	break
	jmp LABEL_8429
LABEL_859C:
	db 0x11

LABEL_859D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x0001
	je [0x0D], 0x00, LABEL_85B3
	call LABEL_7F5E
	jmp LABEL_85B8

LABEL_85B3:
	video type=0, offset=COMMON_VIDEO_219, x=[0x07], y=[0x08], zoom=0x40

LABEL_85B8:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_220, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_815E
	add [0x08], 0x0001
	ret

LABEL_85C8:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_85DA
	call LABEL_7F5E
	jmp LABEL_85DF

LABEL_85DA:
	video type=0, offset=COMMON_VIDEO_222, x=[0x07], y=[0x08], zoom=0x40

LABEL_85DF:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_223, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_811C
	ret

LABEL_85EB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, LABEL_8601
	call LABEL_7F88
	jmp LABEL_8606

LABEL_8601:
	video type=0, offset=COMMON_VIDEO_225, x=[0x07], y=[0x08], zoom=0x40

LABEL_8606:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_226, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_8127
	sub [0x08], 0x0001
	ret

LABEL_8616:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, LABEL_862C
	call LABEL_7F88
	jmp LABEL_8631

LABEL_862C:
	video type=0, offset=COMMON_VIDEO_228, x=[0x07], y=[0x08], zoom=0x40

LABEL_8631:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_229, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_8132
	sub [0x08], 0x0001
	ret

LABEL_8641:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_8653
	call LABEL_7F88
	jmp LABEL_8658

LABEL_8653:
	video type=0, offset=COMMON_VIDEO_231, x=[0x07], y=[0x08], zoom=0x40

LABEL_8658:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_232, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_813D
	ret

LABEL_8664:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x0001
	je [0x0D], 0x00, LABEL_867A
	call LABEL_7F5E
	jmp LABEL_867F

LABEL_867A:
	video type=0, offset=COMMON_VIDEO_228, x=[0x07], y=[0x08], zoom=0x40

LABEL_867F:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_234, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_813D
	add [0x08], 0x0001
	ret

LABEL_868F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_86A1
	call LABEL_7F5E
	jmp LABEL_86A6

LABEL_86A1:
	video type=0, offset=COMMON_VIDEO_228, x=[0x07], y=[0x08], zoom=0x40

LABEL_86A6:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_235, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_8132
	ret

LABEL_86B2:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, LABEL_86C8
	call LABEL_7F40
	jmp LABEL_86CD

LABEL_86C8:
	video type=0, offset=COMMON_VIDEO_225, x=[0x07], y=[0x08], zoom=0x40

LABEL_86CD:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_236, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_8148
	sub [0x08], 0x0001
	ret

LABEL_86DD:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, LABEL_86F3
	call LABEL_7F34
	jmp LABEL_86F8

LABEL_86F3:
	video type=0, offset=COMMON_VIDEO_225, x=[0x07], y=[0x08], zoom=0x40

LABEL_86F8:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_238, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_8153
	sub [0x08], 0x0001
	ret

LABEL_8708:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_871A
	call LABEL_7F40
	jmp LABEL_871F

LABEL_871A:
	video type=0, offset=COMMON_VIDEO_222, x=[0x07], y=[0x08], zoom=0x40

LABEL_871F:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_240, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	call LABEL_815E
	sub [0x07], 0x0001
	ret

LABEL_8733:
	call AND_VAR11_WITH_EFFF
	jmp LABEL_8742
LABEL_8739:
	db 0x04, 0x59, 0xB4, 0x0A, 0x01, 0x2F, 0x04, 0x53
	db 0x6F

LABEL_8742:
	call LABEL_859D
	sub [0x07], 0x0007
	break
	jg [0x07], [0x29], LABEL_8759
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_536F

LABEL_8759:
	call LABEL_85C8
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_8770
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_536F

LABEL_8770:
	call LABEL_85EB
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_8787
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_536F

LABEL_8787:
	call LABEL_8616
	sub [0x07], 0x0008
	break
	jg [0x07], [0x29], LABEL_879E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_536F

LABEL_879E:
	call LABEL_8641
	sub [0x07], 0x000A
	break
	jg [0x07], [0x29], LABEL_87B5
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_536F

LABEL_87B5:
	call LABEL_8664
	sub [0x07], 0x0007
	break
	jg [0x07], [0x29], LABEL_87CC
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_536F

LABEL_87CC:
	call LABEL_868F
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_87E3
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_536F

LABEL_87E3:
	call LABEL_86B2
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_87FA
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_536F

LABEL_87FA:
	call LABEL_86DD
	sub [0x07], 0x0008
	break
	jg [0x07], [0x29], LABEL_8811
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_536F

LABEL_8811:
	call LABEL_8708
	sub [0x07], 0x000A
	break
	jmp LABEL_8733
LABEL_881C:
	db 0x11

LABEL_881D:
	video type=0, offset=COMMON_VIDEO_311, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_312, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_883B:
	video type=0, offset=COMMON_VIDEO_313, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_314, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8859:
	video type=0, offset=COMMON_VIDEO_315, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_316, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8877:
	add [0x07], 0x0001
	call LABEL_8883
	sub [0x07], 0x0001
	ret

LABEL_8883:
	video type=0, offset=COMMON_VIDEO_299, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_CIN_031_032_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_300, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_88A6:
	add [0x07], 0x0001
	call LABEL_88B2
	sub [0x07], 0x0001
	ret

LABEL_88B2:
	video type=0, offset=COMMON_VIDEO_307, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_CIN_031_032_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_308, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_88D5:
	video type=0, offset=COMMON_VIDEO_309, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_CIN_031_032_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_310, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_88F8:
	sub [0x07], 0x0001
	call LABEL_88A6
	add [0x07], 0x0001
	ret

LABEL_8904:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_197, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_198, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_8927
	call LABEL_88A6
	jmp DEDUP_CAVES_5B_020__HELPER_DEDUP_CAVES_5B_020

LABEL_8927:
	video type=0, offset=COMMON_VIDEO_199, x=[0x07], y=[0x08], zoom=0x40
