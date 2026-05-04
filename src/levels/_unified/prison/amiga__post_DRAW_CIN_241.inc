LABEL_52B6:
	video type=0, offset=COMMON_VIDEO_195, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_196, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_52CC:
	video type=0, offset=COMMON_VIDEO_162, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_163, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_52E2:
	video type=0, offset=COMMON_VIDEO_121, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_122, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_52FC:
	video type=0, offset=COMMON_VIDEO_167, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_168, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5312:
	video type=0, offset=COMMON_VIDEO_170, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_171, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_532C:
	video type=0, offset=COMMON_VIDEO_174, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_175, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5346:
	video type=0, offset=COMMON_VIDEO_178, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_179, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5360:
	video type=0, offset=COMMON_VIDEO_182, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_183, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_537A:
	video type=0, offset=COMMON_VIDEO_186, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_187, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5394:
	video type=0, offset=COMMON_VIDEO_224, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_539F:
	video type=0, offset=COMMON_VIDEO_227, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_53AA:
	video type=0, offset=COMMON_VIDEO_230, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_53B5:
	video type=0, offset=COMMON_VIDEO_233, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_53C0:
	video type=0, offset=COMMON_VIDEO_237, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_53CB:
	video type=0, offset=COMMON_VIDEO_239, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_53D6:
	video type=0, offset=COMMON_VIDEO_221, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_53E1:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_53F3
	call LABEL_5281
	jmp LABEL_53F8

LABEL_53F3:
	video type=0, offset=COMMON_VIDEO_160, x=[0x07], y=[0x08], zoom=0x40

LABEL_53F8:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_161, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_52CC
	ret

LABEL_5407:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_5419
	call LABEL_5281
	jmp LABEL_5426

LABEL_5419:
	add [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_160, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x0001

LABEL_5426:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_164, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_52CC
	ret

LABEL_5435:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_5444
	call DRAW_CIN_242_THEN_243

LABEL_5444:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_165, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_52E2
	ret

LABEL_5453:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x01
	je [0x0D], 0x00, LABEL_5468
	call DRAW_CIN_242_THEN_243

LABEL_5468:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_166, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_52FC
	ret

LABEL_5477:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_5486
	call DRAW_CIN_242_THEN_243

LABEL_5486:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_169, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_5312
	ret

LABEL_5495:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_54A7
	call DRAW_CIN_338_THEN_339
	jmp LABEL_54AC

LABEL_54A7:
	video type=0, offset=COMMON_VIDEO_172, x=[0x07], y=[0x08], zoom=0x40

LABEL_54AC:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_173, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_532C
	ret

LABEL_54BB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_54CD
	call LABEL_5239
	jmp LABEL_54D2

LABEL_54CD:
	video type=0, offset=COMMON_VIDEO_176, x=[0x07], y=[0x08], zoom=0x40

LABEL_54D2:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_177, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_5346
	ret

LABEL_54E1:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_54F3
	call LABEL_521B
	jmp LABEL_54F8

LABEL_54F3:
	video type=0, offset=COMMON_VIDEO_180, x=[0x07], y=[0x08], zoom=0x40

LABEL_54F8:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_181, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_5360
	ret

LABEL_5507:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_5519
	call LABEL_520F
	jmp LABEL_551E

LABEL_5519:
	video type=0, offset=COMMON_VIDEO_184, x=[0x07], y=[0x08], zoom=0x40

LABEL_551E:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_185, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_537A
	ret

LABEL_552D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_553F
	call LABEL_520F
	jmp LABEL_5544

LABEL_553F:
	video type=0, offset=COMMON_VIDEO_184, x=[0x07], y=[0x08], zoom=0x40

LABEL_5544:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_188, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	add [0x07], 0x0001
	call LABEL_537A
	sub [0x07], 0x0001
	ret

LABEL_555B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_556D
	call LABEL_521B
	jmp LABEL_5572

LABEL_556D:
	video type=0, offset=COMMON_VIDEO_176, x=[0x07], y=[0x08], zoom=0x40

LABEL_5572:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_189, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_5346
	ret

LABEL_5581:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x01
	je [0x0D], 0x00, LABEL_5599
	call LABEL_521B
	jmp LABEL_559E

LABEL_5599:
	video type=0, offset=COMMON_VIDEO_172, x=[0x07], y=[0x08], zoom=0x40

LABEL_559E:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_190, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_532C
	ret

LABEL_55AD:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_55BC
	call LABEL_521B

LABEL_55BC:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_191, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_5312
	ret

LABEL_55CB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_55DA
	call LABEL_5239

LABEL_55DA:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_192, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_52FC
	ret

GUARDED_DRAW_CIN_338_339:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_55F8
	call DRAW_CIN_338_THEN_339

LABEL_55F8:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_193, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_52E2
	ret

LABEL_5607:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_5616
	call DRAW_CIN_242_THEN_243

LABEL_5616:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_194, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_52B6
	ret

GUARDED_DRAW_CIN_242_243:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_5634
	call DRAW_CIN_242_THEN_243

LABEL_5634:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_120, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_52E2
	ret

GUARDED_DRAW_CIN_338_339:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_5652
	call DRAW_CIN_338_THEN_339

LABEL_5652:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_120, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_52FC
	ret

LABEL_5661:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_5670
	call LABEL_5239

LABEL_5670:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_120, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_5312
	ret

LABEL_567F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_629, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_120, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_52FC
	ret
LABEL_5699:
	db 0x04, 0x64, 0xC8, 0x06, 0x07, 0x56, 0x99, 0x11

LABEL_56A1:
	call AND_VAR11_WITH_EFFF
	jmp LABEL_56B0
LABEL_56A7:
	db 0x04, 0x30, 0x69, 0x0A, 0x01, 0x2F, 0x02, 0x25
	db 0x74

LABEL_56B0:
	call LABEL_53E1
	sub [0x07], 0x0002
	break
	jg [0x07], [0x29], LABEL_56C7
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_DRAW_CIN_242_243

LABEL_56C7:
	call LABEL_5407
	sub [0x07], 0x0002
	break
	jg [0x07], [0x29], LABEL_56DE
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_DRAW_CIN_242_243

LABEL_56DE:
	call LABEL_5435
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_56F5
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_DRAW_CIN_242_243

LABEL_56F5:
	call LABEL_5453
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_570C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_DRAW_CIN_242_243

LABEL_570C:
	call LABEL_5477
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_5723
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_DRAW_CIN_242_243

LABEL_5723:
	call LABEL_5495
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_573A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_DRAW_CIN_242_243

LABEL_573A:
	call LABEL_54BB
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_5751
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_DRAW_CIN_242_243

LABEL_5751:
	call LABEL_54E1
	sub [0x07], 0x0002
	break
	jg [0x07], [0x29], LABEL_5768
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_DRAW_CIN_242_243

LABEL_5768:
	call LABEL_5507
	sub [0x07], 0x0002
	break
	jg [0x07], [0x29], LABEL_577F
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_DRAW_CIN_242_243

LABEL_577F:
	call LABEL_552D
	sub [0x07], 0x0002
	break
	jg [0x07], [0x29], LABEL_5796
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_DRAW_CIN_242_243

LABEL_5796:
	call LABEL_555B
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_57AD
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_DRAW_CIN_242_243

LABEL_57AD:
	call LABEL_5581
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_57C4
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_DRAW_CIN_242_243

LABEL_57C4:
	call LABEL_55AD
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_57DB
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_DRAW_CIN_242_243

LABEL_57DB:
	call LABEL_55CB
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_57F2
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_DRAW_CIN_242_243

LABEL_57F2:
	call GUARDED_DRAW_CIN_338_339	;@raw=0x04,0x55,0xE9
	sub [0x07], 0x0003
	break
	jg [0x07], [0x29], LABEL_5809
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x02, GAME_LOOP_DRAW_CIN_242_243

LABEL_5809:
	call LABEL_5607
	sub [0x07], 0x0002
	break
	jmp LABEL_56A1
LABEL_5814:
	db 0x11

LABEL_5815:
	call LABEL_53E1
	sub [0x07], 0x0002
	break
	call LABEL_5407
	sub [0x07], 0x0002
	break
	call LABEL_5435
	sub [0x07], 0x0003
	break
	call LABEL_5453
	sub [0x07], 0x0003
	break
	call LABEL_5477
	sub [0x07], 0x0003
	break
	call LABEL_5495
	sub [0x07], 0x0003
	break
	call LABEL_54BB
	sub [0x07], 0x0003
	break
	call LABEL_54E1
	sub [0x07], 0x0002
	break

LABEL_5855:
	call LABEL_5507
	sub [0x07], 0x0002
	break
	call LABEL_552D
	sub [0x07], 0x0002
	break
	call LABEL_555B
	sub [0x07], 0x0003
	break
	call LABEL_5581
	sub [0x07], 0x0003
	break
	call LABEL_55AD
	sub [0x07], 0x0003
	break
	call LABEL_55CB
	sub [0x07], 0x0003
	break
	call GUARDED_DRAW_CIN_338_339	;@raw=0x04,0x55,0xE9
	sub [0x07], 0x0003
	break
	call LABEL_5607
	sub [0x07], 0x0002
	break
	jmp LABEL_5815
LABEL_5898:
	db 0x11

LABEL_5899:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x0001
	je [0x0D], 0x00, LABEL_58AF
	call LABEL_5239
	jmp LABEL_58B4

LABEL_58AF:
	video type=0, offset=COMMON_VIDEO_219, x=[0x07], y=[0x08], zoom=0x40

LABEL_58B4:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_220, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_53D6
	add [0x08], 0x0001
	ret

LABEL_58C4:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_58D6
	call LABEL_5239
	jmp LABEL_58DB

LABEL_58D6:
	video type=0, offset=COMMON_VIDEO_222, x=[0x07], y=[0x08], zoom=0x40

LABEL_58DB:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_223, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_5394
	ret

LABEL_58E7:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, LABEL_58FD
	call DRAW_CIN_242_THEN_243
	jmp LABEL_5902

LABEL_58FD:
	video type=0, offset=COMMON_VIDEO_225, x=[0x07], y=[0x08], zoom=0x40

LABEL_5902:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_226, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_539F
	sub [0x08], 0x0001
	ret

LABEL_5912:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, LABEL_5928
	call DRAW_CIN_242_THEN_243
	jmp LABEL_592D

LABEL_5928:
	video type=0, offset=COMMON_VIDEO_228, x=[0x07], y=[0x08], zoom=0x40

LABEL_592D:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_229, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_53AA
	sub [0x08], 0x0001
	ret

LABEL_593D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_594F
	call DRAW_CIN_242_THEN_243
	jmp LABEL_5954

LABEL_594F:
	video type=0, offset=COMMON_VIDEO_231, x=[0x07], y=[0x08], zoom=0x40

LABEL_5954:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_232, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_53B5
	ret

LABEL_5960:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x0001
	je [0x0D], 0x00, LABEL_5976
	call LABEL_5239
	jmp LABEL_597B

LABEL_5976:
	video type=0, offset=COMMON_VIDEO_228, x=[0x07], y=[0x08], zoom=0x40

LABEL_597B:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_234, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_53B5
	add [0x08], 0x0001
	ret

LABEL_598B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_599D
	call LABEL_5239
	jmp LABEL_59A2

LABEL_599D:
	video type=0, offset=COMMON_VIDEO_228, x=[0x07], y=[0x08], zoom=0x40

LABEL_59A2:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_235, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_53AA
	ret

LABEL_59AE:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, LABEL_59C4
	call LABEL_521B
	jmp LABEL_59C9

LABEL_59C4:
	video type=0, offset=COMMON_VIDEO_225, x=[0x07], y=[0x08], zoom=0x40

LABEL_59C9:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_236, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_53C0
	sub [0x08], 0x0001
	ret

LABEL_59D9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, LABEL_59EF
	call LABEL_520F
	jmp LABEL_59F4

LABEL_59EF:
	video type=0, offset=COMMON_VIDEO_225, x=[0x07], y=[0x08], zoom=0x40

LABEL_59F4:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_238, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_53CB
	sub [0x08], 0x0001
	ret

LABEL_5A04:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_5A16
	call LABEL_521B
	jmp LABEL_5A1B

LABEL_5A16:
	video type=0, offset=COMMON_VIDEO_222, x=[0x07], y=[0x08], zoom=0x40

LABEL_5A1B:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_240, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	call LABEL_53D6
	sub [0x07], 0x0001
	ret

LABEL_5A2F:
	call AND_VAR11_WITH_EFFF
	jmp LABEL_5A3E
LABEL_5A35:
	db 0x04, 0x30, 0x69, 0x0A, 0x01, 0x2F, 0x04, 0x25
	db 0x85

LABEL_5A3E:
	call LABEL_5899
	sub [0x07], 0x0007
	break
	jg [0x07], [0x29], LABEL_5A55
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_2585

LABEL_5A55:
	call LABEL_58C4
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_5A6C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_2585

LABEL_5A6C:
	call LABEL_58E7
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_5A83
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_2585

LABEL_5A83:
	call LABEL_5912
	sub [0x07], 0x0008
	break
	jg [0x07], [0x29], LABEL_5A9A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_2585

LABEL_5A9A:
	call LABEL_593D
	sub [0x07], 0x000A
	break
	jg [0x07], [0x29], LABEL_5AB1
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_2585

LABEL_5AB1:
	call LABEL_5960
	sub [0x07], 0x0007
	break
	jg [0x07], [0x29], LABEL_5AC8
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_2585

LABEL_5AC8:
	call LABEL_598B
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_5ADF
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_2585

LABEL_5ADF:
	call LABEL_59AE
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_5AF6
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_2585

LABEL_5AF6:
	call LABEL_59D9
	sub [0x07], 0x0008
	break
	jg [0x07], [0x29], LABEL_5B0D
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_2585

LABEL_5B0D:
	call LABEL_5A04
	sub [0x07], 0x000A
	break
	jmp LABEL_5A2F
LABEL_5B18:
	db 0x11

LABEL_5B19:
	video type=1, offset=CINEMATIC_343, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=1, offset=CINEMATIC_344, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_5B37:
	video type=1, offset=CINEMATIC_345, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=1, offset=CINEMATIC_346, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_5B55:
	video type=1, offset=CINEMATIC_347, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=1, offset=CINEMATIC_348, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_5B73:
	add [0x07], 0x0001
	call LABEL_5B7F
	sub [0x07], 0x0001
	ret

LABEL_5B7F:
	video type=1, offset=CINEMATIC_170, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_CIN_169_IF_VAR09_EQ_1
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=1, offset=CINEMATIC_171, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5BA2:
	add [0x07], 0x0001
	call LABEL_5BAE
	sub [0x07], 0x0001
	ret

LABEL_5BAE:
	video type=1, offset=CINEMATIC_334, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_CIN_169_IF_VAR09_EQ_1
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=1, offset=CINEMATIC_335, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5BD1:
	video type=1, offset=CINEMATIC_336, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_CIN_169_IF_VAR09_EQ_1
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=1, offset=CINEMATIC_337, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5BF4:
	sub [0x07], 0x0001
	call LABEL_5BA2
	add [0x07], 0x0001
	ret

LABEL_5C00:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x19, vol=0x0A, channel=0x01
	sub [0x08], 0x0001
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_197, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_198, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_5C29
	call LABEL_5BA2
	jmp DEDUP_CAVES_5B_020	;@raw=0x07,0x5C,0x2E

LABEL_5C29:
	video type=0, offset=COMMON_VIDEO_199, x=[0x07], y=[0x08], zoom=0x40
