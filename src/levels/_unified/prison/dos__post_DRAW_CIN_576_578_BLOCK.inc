LABEL_1F98:
	call LABEL_62AE
	add [BUDDY_X], 0x0001
	break
	call LABEL_628D
	add [BUDDY_X], 0x0001
	break
	call GUARDED_HERO_ANIM_CV_128
	break
	call GUARDED_DRAW_CIN_342
	sub [HERO_X], 0x0001
	break
	call GUARDED_DRAW_CIN_242_243
	sub [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_242_243
	break
	jmp LABEL_5902
LABEL_1FC3:
	db 0x11

LABEL_1FC4:
	call LABEL_570E
	sub [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_338_339
	sub [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_242_243
	break
	call GUARDED_DRAW_CIN_342
	add [BUDDY_X], 0x0001
	break
	call GUARDED_HERO_ANIM_CV_128
	add [BUDDY_X], 0x0001
	break
	call GUARDED_HERO_ANIM_CV_128
	break
	jmp LABEL_6A8E
LABEL_1FEF:
	db 0x11

LABEL_1FF0:
	mov [0x29], 0x0002
	call LABEL_570E
	sub [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_338_339
	sub [BUDDY_X], 0x0001
	break
	mov [0x29], 0x000A
	mov [0x0E], 0x0002

LABEL_200C:
	call GUARDED_DRAW_CIN_242_243
	break
	djnz [0x29], LABEL_200C
	mov [0x0E], 0x0000
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x29], 0x0003

LABEL_2020:
	call LABEL_570E
	break
	djnz [0x29], LABEL_2020
	mov [0x0E], 0x0004
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x29], 0x00FF
	jmp LABEL_5902
LABEL_2037:
	db 0x11

LABEL_2038:
	call LABEL_570E
	mov [0x0E], 0x0005
	sub [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_338_339
	sub [BUDDY_X], 0x0001

LABEL_204B:
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [0x3A], 0x00, LABEL_2150
	jl [0x3A], 0x02, LABEL_2124
	jl [0x3A], 0x04, LABEL_2192
	je [0x3A], 0x04, LABEL_209A
	je [0x3A], 0x05, LABEL_20C6
	je [0x3A], 0x06, LABEL_20F8
	jmp LABEL_2076

LABEL_2076:
	call GUARDED_DRAW_CIN_242_243
	play id=0x0071, freq=0x0F, vol=0x40, channel=0x01
	break
	mov [0x0E], 0x0006
	call GUARDED_DRAW_CIN_242_243
	break
	mov [0x0E], 0x0005
	call GUARDED_DRAW_CIN_338_339
	break
	call GUARDED_DRAW_CIN_338_339
	break
	call GUARDED_DRAW_CIN_338_339
	jmp LABEL_204B

LABEL_209A:
	call GUARDED_DRAW_CIN_242_243
	play id=0x0070, freq=0x0F, vol=0x40, channel=0x01
	break
	mov [0x0E], 0x0006
	call GUARDED_DRAW_CIN_242_243
	break
	mov [0x0E], 0x0005
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x0E], 0x0006
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x0E], 0x0005
	call GUARDED_DRAW_CIN_338_339
	jmp LABEL_204B

LABEL_20C6:
	call GUARDED_DRAW_CIN_242_243
	play id=0x0072, freq=0x11, vol=0x40, channel=0x01
	break
	mov [0x0E], 0x0006
	call GUARDED_DRAW_CIN_242_243
	break
	mov [0x0E], 0x0005
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x0E], 0x0006
	call GUARDED_DRAW_CIN_338_339
	break
	play id=0x0071, freq=0x0F, vol=0x40, channel=0x01
	mov [0x0E], 0x0005
	call GUARDED_DRAW_CIN_338_339
	jmp LABEL_204B

LABEL_20F8:
	call GUARDED_DRAW_CIN_242_243
	play id=0x0070, freq=0x0F, vol=0x40, channel=0x01
	break
	mov [0x0E], 0x0006
	call GUARDED_DRAW_CIN_242_243
	break
	mov [0x0E], 0x0005
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x0E], 0x0006
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x0E], 0x0005
	call GUARDED_DRAW_CIN_338_339
	jmp LABEL_204B

LABEL_2124:
	call GUARDED_DRAW_CIN_242_243
	play id=0x0072, freq=0x0F, vol=0x40, channel=0x01
	mov [0x0E], 0x0003
	break
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x0E], 0x0005
	call LABEL_570E
	break
	call GUARDED_DRAW_CIN_338_339
	mov [0x29], 0x000A

LABEL_2145:
	break
	call GUARDED_DRAW_CIN_242_243
	djnz [0x29], LABEL_2145
	jmp LABEL_204B

LABEL_2150:
	call LABEL_572C
	break
	call LABEL_572C
	jl [0x15], 0x1E, LABEL_204B
	break
	setPalette 0x0F
	play id=0x0052, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_630, x=[BUDDY_X], y=110
	call LABEL_572C
	break
	setPalette 0x02
	video offset=CINEMATIC_631, x=[BUDDY_X], y=80
	call GUARDED_DRAW_CIN_338_339
	break
	video offset=CINEMATIC_630, x=[BUDDY_X], y=65516
	call GUARDED_DRAW_CIN_242_243
	je [0x57], 0x02, LABEL_204B
	setup channel=0x11, address=DRAW_CIN_570_574_BLOCK
	jmp LABEL_204B

LABEL_2192:
	mov [0x29], 0x0004
	call GUARDED_DRAW_CIN_338_339

LABEL_2199:
	break
	call LABEL_570E
	djnz [0x29], LABEL_2199
	jmp LABEL_204B
LABEL_21A4:
	db 0x11

LABEL_21A5:
	mov [0x0E], 0x0003
	call GUARDED_DRAW_CIN_338_339
	mov [0x0E], 0x0000
	break
	mov [0x0E], 0x0005
	call GUARDED_DRAW_CIN_338_339
	mov [0x0E], 0x0000

LABEL_21BC:
	break
	call GUARDED_DRAW_CIN_338_339
	jmp LABEL_21BC
LABEL_21C3:
	db 0x11

LABEL_21C4:
	call LABEL_628D
	add [BUDDY_X], 0x0001
	break
	mov [0x0E], 0x0001
	call GUARDED_HERO_ANIM_CV_128
	add [BUDDY_X], 0x0001
	break
	mov [0x0D], 0x0001
	mov [0x0E], 0x0000
	call LABEL_628D
	break
	mov [0x0E], 0x0002
	mov [0x29], 0x0003

LABEL_21EC:
	call LABEL_62AE
	break
	djnz [0x29], LABEL_21EC
	call GUARDED_DRAW_CIN_342
	break
	mov [0x0E], 0x0000
	sub [BUDDY_X], 0x0001
	call GUARDED_DRAW_CIN_242_243
	break

LABEL_2204:
	sub [BUDDY_X], 0x0001
	mov [0x0D], 0x0001
	mov [0x0E], 0x0003
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x0E], 0x0005
	mov [0x29], 0x00FF
	jmp LABEL_5902
LABEL_221F:
	db 0x11

COMPUTE_OFFSET_VAR21_22:
	call LABEL_633B
	mov [0x21], [BUDDY_X]
	mov [0x22], [BUDDY_Y]
	sub [0x21], 0x0023
	sub [0x22], 0x0026
	ret

LABEL_2232:
	call LABEL_65DC
	mov [0x21], [BUDDY_X]
	mov [0x22], [BUDDY_Y]
	add [0x21], 0x0023
	sub [0x22], 0x0026
	ret

LABEL_2244:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_2255
	mov [0x2F], 0x0005
	jmp LABEL_2519

LABEL_2255:
	jl [0xF8], 0x1000, LABEL_22BE
	jmp LABEL_2260
LABEL_225F:
	db 0x11

LABEL_2260:
	call LABEL_6634
	break
	call LABEL_65EE
	break
	call LABEL_6622
	break
	call LABEL_2232
	jne [0x10], [HACK_VAR_67], LABEL_227A
	video offset=CINEMATIC_196, x=[0x21], y=[0x22]

LABEL_227A:
	break
	call LABEL_2232
	jne [0x10], [HACK_VAR_67], LABEL_2289
	video offset=CINEMATIC_197, x=[0x21], y=[0x22]

LABEL_2289:
	break
	call LABEL_2232
	jne [0x10], [HACK_VAR_67], LABEL_2298
	video offset=CINEMATIC_198, x=[0x21], y=[0x22]

LABEL_2298:
	break
	call LABEL_2232
	jne [0x10], [HACK_VAR_67], LABEL_22A7
	video offset=CINEMATIC_210, x=[0x21], y=[0x22]

LABEL_22A7:
	break
	call LABEL_2232
	jne [0x10], [HACK_VAR_67], LABEL_22B9
	video offset=CINEMATIC_200, x=[0x21], y=[BUDDY_Y]
	call LABEL_4137

LABEL_22B9:
	break
	jmp LABEL_2577
LABEL_22BD:
	db 0x11

LABEL_22BE:
	call LABEL_63BF
	break
	call LABEL_6358
	break
	call LABEL_63A2
	break
	call COMPUTE_OFFSET_VAR21_22
	play id=0x005B, freq=0x14, vol=0x40, channel=0x01
	jne [0x10], [HACK_VAR_67], LABEL_22DE
	video offset=CINEMATIC_196, x=[0x21], y=[0x22]

LABEL_22DE:
	break
	call COMPUTE_OFFSET_VAR21_22
	jne [0x10], [HACK_VAR_67], LABEL_22ED
	video offset=CINEMATIC_197, x=[0x21], y=[0x22]

LABEL_22ED:
	break
	call COMPUTE_OFFSET_VAR21_22
	jne [0x10], [HACK_VAR_67], LABEL_2302
	video offset=CINEMATIC_198, x=[0x21], y=[0x22]
	play id=0x0059, freq=0x14, vol=0x40, channel=0x01

LABEL_2302:
	break
	call COMPUTE_OFFSET_VAR21_22
	jne [0x10], [HACK_VAR_67], LABEL_2311
	video offset=CINEMATIC_199, x=[0x21], y=[0x22]

LABEL_2311:
	break
	call COMPUTE_OFFSET_VAR21_22
	jne [0x10], [HACK_VAR_67], LABEL_2323
	video offset=CINEMATIC_200, x=[0x21], y=[BUDDY_Y]
	call LABEL_4137

LABEL_2323:
	break
	jmp LABEL_2557
LABEL_2327:
	db 0x11

LABEL_2328:
	break
	mov [0x33], 0xFFF6
	jne [0x72], 0x03, LABEL_2328
	jl [0x70], 0xC8, LABEL_2328

LABEL_2339:
	jne [HACK_VAR_67], 0x04, LABEL_234D
	call LABEL_23AC
	je [0x23], 0x00, LABEL_2390
	video offset=CINEMATIC_202, x=[0x21], y=[BUDDY_Y]

LABEL_234D:
	break
	jne [HACK_VAR_67], 0x04, LABEL_2362
	call LABEL_23AC
	je [0x23], 0x00, LABEL_2390
	video offset=CINEMATIC_203, x=[0x21], y=[BUDDY_Y]

LABEL_2362:
	break
	jne [HACK_VAR_67], 0x04, LABEL_2377
	call LABEL_23AC
	je [0x23], 0x00, LABEL_2390
	video offset=CINEMATIC_204, x=[0x21], y=[BUDDY_Y]

LABEL_2377:
	break
	jne [HACK_VAR_67], 0x04, LABEL_238C
	call LABEL_23AC
	je [0x23], 0x00, LABEL_2390
	video offset=CINEMATIC_203, x=[0x21], y=[BUDDY_Y]

LABEL_238C:
	break
	jmp LABEL_2339

LABEL_2390:
	call LABEL_23AC
	video offset=CINEMATIC_210, x=[0x21], y=[BUDDY_Y]
	break
	call LABEL_23AC
	video offset=CINEMATIC_200, x=[0x21], y=[0x71]
	mov [BUDDY_Y], [0x71]
	mov [0x10], 0x0004
	call LABEL_4137
	killChannel

LABEL_23AC:
	mov [BUDDY_Y], [0x71]
	sub [BUDDY_Y], 0x0028
	mov [0x21], [0x33]
	mov [0x23], 0x0001
	jg [0x33], 0x14, LABEL_23C5
	add [0x33], 0x0003
	ret

LABEL_23C5:
	jl [0x70], 0x0140, SHARED_RET
	mov [0x23], 0x0000
	ret

LABEL_23D1:
	je [BUDDY_Y], [0x52], LABEL_246B
	jmp LABEL_23EB

LABEL_23DA:
	break
	mov [0xF8], [0x11]
	and [0xF8], 0x1000
	je [0xF8], 0x00, LABEL_2597
	jmp LABEL_25D9

LABEL_23EB:
	mov [BUDDY_Y], [0x52]
	sub [BUDDY_Y], 0x001E
	call LABEL_632F
	break
	mov [BUDDY_Y], [0x52]
	call LABEL_632F
	jmp LABEL_23DA

LABEL_23FF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_202, x=[0x21], y=[0x22]
	ret

LABEL_240B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_203, x=[0x21], y=[0x22]
	ret

LABEL_2417:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_204, x=[0x21], y=[0x22]
	ret

LABEL_2423:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_190, x=[0x21], y=[0x22]
	ret

LABEL_242F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_191, x=[0x21], y=[0x22]
	ret

LABEL_243B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_192, x=[0x21], y=[0x22]
	ret

LABEL_2447:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_193, x=[0x21], y=[0x22]
	ret

LABEL_2453:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_194, x=[0x21], y=[0x22]
	ret

LABEL_245F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_195, x=[0x21], y=[0x22]
	ret

LABEL_246B:
	mov [BUDDY_Y], [0x51]
	add [BUDDY_Y], 0x001E
	call LABEL_6323
	break
	mov [BUDDY_Y], [0x51]
	call LABEL_6323
	jmp LABEL_23DA
LABEL_247F:
	db 0x11

LABEL_2480:
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_196, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_197, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_198, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_199, x=[0x21], y=[0x22]
	break
	mov [0x29], 0x0003

LABEL_24A8:
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_23FF
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_240B
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_2417
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_240B
	break
	djnz [0x29], LABEL_24A8
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_2423
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_242F
	break
	mov [0x29], 0x0002

LABEL_24DA:
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_243B
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_2447
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_2453
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_245F
	break
	djnz [0x29], LABEL_24DA
	jne [HACK_VAR_67], [0x10], LABEL_2557
	call COMPUTE_OFFSET_VAR21_22
	mov [0x96], [0x21]
	mov [0x97], [0x22]
	mov [0x8B], 0x0064
	or [0x8B], 0x8000
	or [0x97], 0x4000
	jmp LABEL_2557
LABEL_2518:
	db 0x11

LABEL_2519:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_2527
	sub [0xF8], 0x2000

LABEL_2527:
	jl [0xF8], 0x1000, LABEL_253B
	je [0x2F], 0x05, LABEL_2568
	je [0x2F], 0x0F, LABEL_25CA
	killChannel

LABEL_253B:
	je [0x2F], 0x05, LABEL_2548
	je [0x2F], 0x0F, LABEL_2588
	killChannel

LABEL_2548:
	jl [0x11], 0x2000, LABEL_2557
	sub [0x11], 0x2000
	call LABEL_63EA
	break

LABEL_2557:
	call LABEL_63BF
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_2557
LABEL_2567:
	db 0x11

LABEL_2568:
	jl [0x11], 0x2000, LABEL_2577
	sub [0x11], 0x2000
	call LABEL_665A
	break

LABEL_2577:
	call LABEL_6634
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_2577
LABEL_2587:
	db 0x11

LABEL_2588:
	jge [0x11], 0x2000, LABEL_2597
	add [0x11], 0x2000
	call LABEL_63EA
	break

LABEL_2597:
	call GUARDED_DRAW_CIN_242_243
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_2597
LABEL_25A7:
	db 0x11

GAME_LOOP_DRAW_CIN_242_243:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CIN_242_243
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp GAME_LOOP_DRAW_CIN_242_243
LABEL_25B8:
	db 0x11

LABEL_25B9:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CIN_242_243
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp LABEL_25B9
LABEL_25C9:
	db 0x11

LABEL_25CA:
	jge [0x11], 0x2000, LABEL_25D9
	add [0x11], 0x2000
	call LABEL_665A
	break

LABEL_25D9:
	call GUARDED_HERO_ANIM_CV_128
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_25D9
LABEL_25E9:
	db 0x11

MAIN_GAME_LOOP_HERO_128:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_128
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp MAIN_GAME_LOOP_HERO_128
LABEL_25FA:
	db 0x11

LABEL_25FB:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_128
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp LABEL_25FB
LABEL_260B:
	db 0x11

LABEL_260C:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_2623
	je [0x2F], 0x10, LABEL_68DA
	jmp LABEL_67D7

LABEL_2623:
	je [0x2F], 0x10, LABEL_574E
	jmp LABEL_5ADC
LABEL_262C:
	db 0x11

LABEL_262D:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_2644
	je [0x2F], 0x01, LABEL_68DA
	jmp LABEL_29B4

LABEL_2644:
	je [0x2F], 0x02, LABEL_574E
	jmp LABEL_29DF
LABEL_264D:
	db 0x11

LABEL_264E:
	mov [0x2F], 0x0001
	jg [0x29], [BUDDY_X], LABEL_262D
	mov [0x2F], 0x0002
	jmp LABEL_262D

LABEL_265F:
	jg [0x29], [BUDDY_X], LABEL_67D7
	jmp LABEL_5ADC
	killChannel
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_2681
	sub [0xF8], 0x2000
	jl [0xF8], 0x1000, LABEL_2548
	jmp LABEL_2568

LABEL_2681:
	jl [0xF8], 0x1000, LABEL_268C
	jmp LABEL_26D9
LABEL_268B:
	db 0x11

LABEL_268C:
	call LABEL_6447
	mov [0x29], 0x0005
	mov [0x0E], 0x0004

LABEL_2697:
	break
	call LABEL_6476
	djnz [0x29], LABEL_2697
	mov [0x21], [BUDDY_X]
	mov [0x27], [BUDDY_Y]
	mov [0x22], 0x4008
	call LABEL_34BD
	break
	call LABEL_64B7
	break
	call LABEL_64B7
	break
	call LABEL_6490
	mov [0x29], 0x0005

LABEL_26BC:
	break
	call LABEL_6476
	djnz [0x29], LABEL_26BC
	mov [0x0E], 0x0000

LABEL_26C8:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_63BF
	jmp LABEL_26C8
	killChannel

LABEL_26D9:
	call JUNK__669D
	mov [0x29], 0x0005
	mov [0x0E], 0x0004

LABEL_26E4:
	break
	call LABEL_66CC
	djnz [0x29], LABEL_26E4
	mov [0x21], [BUDDY_X]
	mov [0x27], [BUDDY_Y]
	mov [0x22], 0x0008
	call LABEL_34BD
	break
	call LABEL_670D
	break
	call LABEL_670D
	break
	call LABEL_66E6
	mov [0x29], 0x0005

LABEL_2709:
	break
	call LABEL_66CC
	djnz [0x29], LABEL_2709
	mov [0x0E], 0x0000

LABEL_2715:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6634
	jmp LABEL_2715
LABEL_2725:
	db 0x11

LABEL_2726:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_274D
	sub [0xF8], 0x2000
	jl [0xF8], 0x1000, LABEL_2744
	je [0x2F], 0x07, LABEL_28C6
	jmp LABEL_2568

LABEL_2744:
	je [0x2F], 0x07, LABEL_2773
	jmp LABEL_2548

LABEL_274D:
	jl [0xF8], 0x1000, LABEL_2763
	je [0x2F], 0x08, LABEL_28F7
	je [0x2F], 0x09, LABEL_293C
	jmp LABEL_25CA

LABEL_2763:
	je [0x2F], 0x08, LABEL_27A4
	je [0x2F], 0x09, LABEL_27E9
	jmp LABEL_2588
LABEL_2772:
	db 0x11

LABEL_2773:
	call LABEL_64E6
	mov [0x21], [BUDDY_X]
	mov [0x27], [BUDDY_Y]
	sub [0x21], 0x0028
	sub [0x27], 0x0036
	call LABEL_378D
	break
	call LABEL_6503
	break
	call LABEL_6549
	break
	call LABEL_64E6

LABEL_2793:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CIN_242_243
	jmp LABEL_2793
LABEL_27A3:
	db 0x11

LABEL_27A4:
	call LABEL_633B
	je [0x29], 0x00, LABEL_27B5
	break
	sub [0x29], 0x0001
	jmp LABEL_27A4

LABEL_27B5:
	jne [HACK_VAR_67], [0x10], LABEL_27CC
	mov [0x21], [BUDDY_X]
	mov [0x27], [BUDDY_Y]
	sub [0x21], 0x0028
	sub [0x27], 0x0029
	call LABEL_378D

LABEL_27CC:
	break
	call LABEL_6358
	break
	call LABEL_63A2
	break
	call LABEL_633B

LABEL_27D8:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_63BF
	jmp LABEL_27D8
LABEL_27E8:
	db 0x11

LABEL_27E9:
	call LABEL_6385
	je [0x29], 0x00, LABEL_27FA
	break
	sub [0x29], 0x0001
	jmp LABEL_27E9

LABEL_27FA:
	jne [HACK_VAR_67], [0x10], LABEL_2811
	mov [0x21], [BUDDY_X]
	mov [0x27], [BUDDY_Y]
	sub [0x21], 0x0019
	sub [0x27], 0x001E
	call LABEL_378D

LABEL_2811:
	break
	call LABEL_63F9
	break
	call LABEL_6428
	break
	call LABEL_6385

LABEL_281D:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_63BF
	jmp LABEL_281D
	killChannel
	call LABEL_62AE
	add [BUDDY_X], 0x0002
	deleteChannels first=0x14, last=0x16
	setup channel=0x15, address=DRAW_CIN_694_695_PROGRESSIVE
	mov [HERO_X], [BUDDY_X]
	add [HERO_X], 0x0010
	break
	call JUNK__62CF
	add [BUDDY_X], 0x0002
	break
	call LABEL_630E
	add [BUDDY_X], 0x0002
	break
	call LABEL_630E
	add [BUDDY_X], 0x0001
	break
	call LABEL_630E
	add [BUDDY_X], 0x0001
	break
	call LABEL_630E
	sub [BUDDY_X], 0x0002
	break
	call LABEL_62F9
	sub [BUDDY_X], 0x0003
	break
	call LABEL_62E4
	break
	mov [0x29], [BUDDY_X]
	add [0x29], 0x003C
	mov [0x2F], 0x0019
	jmp DISPATCH_VAR2F_STATE
LABEL_2887:
	db 0x11

LABEL_2888:
	call LABEL_633B
	deleteChannels first=0x14, last=0x16
	mov [0x03], 0x0014
	setup channel=0x3F, address=DELAY_4_QUANTUMS
	mov [0x29], 0x0001

LABEL_289B:
	break
	video offset=CINEMATIC_426, x=[BUDDY_X], y=[BUDDY_Y]
	djnz [0x29], LABEL_289B
	break
	video offset=CINEMATIC_427, x=[BUDDY_X], y=[BUDDY_Y]
	play id=0x005E, freq=0x14, vol=0x40, channel=0x01
	mov [0x29], 0x0003

LABEL_28B5:
	break
	video offset=CINEMATIC_427, x=[BUDDY_X], y=[BUDDY_Y]
	djnz [0x29], LABEL_28B5
	mov [0x29], 0x0002
	jmp LABEL_289B

LABEL_28C6:
	call LABEL_673C
	mov [0x21], [BUDDY_X]
	mov [0x27], [BUDDY_Y]
	add [0x21], 0x0028
	sub [0x27], 0x0036
	call LABEL_37A6
	break
	call LABEL_6756
	break
	call LABEL_6792
	break
	call LABEL_673C

LABEL_28E6:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_128
	jmp LABEL_28E6
LABEL_28F6:
	db 0x11

LABEL_28F7:
	call LABEL_65DC
	je [0x29], 0x00, LABEL_2908
	break
	sub [0x29], 0x0001
	jmp LABEL_28F7

LABEL_2908:
	jne [HACK_VAR_67], [0x10], LABEL_291F
	mov [0x21], [BUDDY_X]
	mov [0x27], [BUDDY_Y]
	add [0x21], 0x0028
	sub [0x27], 0x0029
	call LABEL_37A6

LABEL_291F:
	break
	call LABEL_65EE
	break
	call LABEL_6622
	break
	call LABEL_65DC

LABEL_292B:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6634
	jmp LABEL_292B
LABEL_293B:
	db 0x11

LABEL_293C:
	call LABEL_6610
	je [0x29], 0x00, LABEL_294D
	break
	sub [0x29], 0x0001
	jmp LABEL_293C

LABEL_294D:
	jne [HACK_VAR_67], [0x10], LABEL_2964
	mov [0x21], [BUDDY_X]
	mov [0x27], [BUDDY_Y]
	add [0x21], 0x0019
	sub [0x27], 0x001E
	call LABEL_37A6

LABEL_2964:
	break
	call LABEL_6669
	break
	call LABEL_668B
	break
	call LABEL_6610

LABEL_2970:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6634
	jmp LABEL_2970
LABEL_2980:
	db 0x11

LABEL_2981:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_29DF
	jmp LABEL_29B4
LABEL_2992:
	db 0x11

LABEL_2993:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_29AA
	je [0x2F], 0x13, LABEL_29B4
	jmp LABEL_25D9

LABEL_29AA:
	je [0x2F], 0x12, LABEL_29DF
	jmp LABEL_2597
LABEL_29B3:
	db 0x11

LABEL_29B4:
	call LABEL_62AE
	add [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_342
	sub [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_338_339
	call AND_VAR11_WITH_EFFF
	sub [BUDDY_X], 0x0001

LABEL_29CE:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CIN_242_243
	jmp LABEL_29CE
LABEL_29DE:
	db 0x11

LABEL_29DF:
	call LABEL_570E
	sub [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_342
	add [BUDDY_X], 0x0001
	break
	call LABEL_628D
	call INLINE_OR_VAR11_WITH_1000
	add [BUDDY_X], 0x0001

LABEL_29F9:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_128
	jmp LABEL_29F9
LABEL_2A09:
	db 0x11
