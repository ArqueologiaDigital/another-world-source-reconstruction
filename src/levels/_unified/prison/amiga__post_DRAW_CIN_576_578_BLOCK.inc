LABEL_1FA0:
	call LABEL_6201
	add [BUDDY_X], 0x0001
	break
	call LABEL_61E0
	add [BUDDY_X], 0x0001
	break
	call GUARDED_HERO_ANIM_CV_009
	break
	call GUARDED_DRAW_CIN_342
	sub [HERO_X], 0x0001
	break
	call GUARDED_DRAW_CIN_242_243
	sub [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_242_243
	break
	jmp LABEL_5855
LABEL_1FCB:
	db 0x11

LABEL_1FCC:
	call LABEL_5661
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
	call GUARDED_HERO_ANIM_CV_009
	add [BUDDY_X], 0x0001
	break
	call GUARDED_HERO_ANIM_CV_009
	break
	jmp LABEL_69E1
LABEL_1FF7:
	db 0x11

LABEL_1FF8:
	mov [0x29], 0x0002
	call LABEL_5661
	sub [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_338_339
	sub [BUDDY_X], 0x0001
	break
	mov [0x29], 0x000A
	mov [0x0E], 0x0002

LABEL_2014:
	call GUARDED_DRAW_CIN_242_243
	break
	djnz [0x29], LABEL_2014
	mov [0x0E], 0x0000
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x29], 0x0003

LABEL_2028:
	call LABEL_5661
	break
	djnz [0x29], LABEL_2028
	mov [0x0E], 0x0004
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x29], 0x00FF
	jmp LABEL_5855
LABEL_203F:
	db 0x11

LABEL_2040:
	call LABEL_5661
	mov [0x0E], 0x0005
	sub [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_338_339
	sub [BUDDY_X], 0x0001

LABEL_2053:
	break
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [0x3A], 0x00, LABEL_2158
	jl [0x3A], 0x02, LABEL_212C
	jl [0x3A], 0x04, LABEL_219A
	je [0x3A], 0x04, LABEL_20A2
	je [0x3A], 0x05, LABEL_20CE
	je [0x3A], 0x06, LABEL_2100
	jmp LABEL_207E

LABEL_207E:
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
	jmp LABEL_2053

LABEL_20A2:
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
	jmp LABEL_2053

LABEL_20CE:
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
	jmp LABEL_2053

LABEL_2100:
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
	jmp LABEL_2053

LABEL_212C:
	call GUARDED_DRAW_CIN_242_243
	play id=0x0072, freq=0x0F, vol=0x40, channel=0x01
	mov [0x0E], 0x0003
	break
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x0E], 0x0005
	call LABEL_5661
	break
	call GUARDED_DRAW_CIN_338_339
	mov [0x29], 0x000A

LABEL_214D:
	break
	call GUARDED_DRAW_CIN_242_243
	djnz [0x29], LABEL_214D
	jmp LABEL_2053

LABEL_2158:
	call LABEL_567F
	break
	call LABEL_567F
	jl [0x15], 0x1E, LABEL_2053
	break
	setPalette 0x0F
	play id=0x0052, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_630, x=[BUDDY_X], y=110
	call LABEL_567F
	break
	setPalette 0x02
	video offset=CINEMATIC_631, x=[BUDDY_X], y=80
	call GUARDED_DRAW_CIN_338_339
	break
	video offset=CINEMATIC_630, x=[BUDDY_X], y=65516
	call GUARDED_DRAW_CIN_242_243
	je [0x57], 0x02, LABEL_2053
	setup channel=0x11, address=DRAW_CIN_570_574_BLOCK
	jmp LABEL_2053

LABEL_219A:
	mov [0x29], 0x0004
	call GUARDED_DRAW_CIN_338_339

LABEL_21A1:
	break
	call LABEL_5661
	djnz [0x29], LABEL_21A1
	jmp LABEL_2053
LABEL_21AC:
	db 0x11

LABEL_21AD:
	mov [0x0E], 0x0003
	call GUARDED_DRAW_CIN_338_339
	mov [0x0E], 0x0000
	break
	mov [0x0E], 0x0005
	call GUARDED_DRAW_CIN_338_339
	mov [0x0E], 0x0000

LABEL_21C4:
	break
	call GUARDED_DRAW_CIN_338_339
	jmp LABEL_21C4
LABEL_21CB:
	db 0x11

LABEL_21CC:
	call LABEL_61E0
	add [BUDDY_X], 0x0001
	break
	mov [0x0E], 0x0001
	call GUARDED_HERO_ANIM_CV_009
	add [BUDDY_X], 0x0001
	break
	mov [0x0D], 0x0001
	mov [0x0E], 0x0000
	call LABEL_61E0
	break
	mov [0x0E], 0x0002
	mov [0x29], 0x0003

LABEL_21F4:
	call LABEL_6201
	break
	djnz [0x29], LABEL_21F4
	call GUARDED_DRAW_CIN_342
	break
	mov [0x0E], 0x0000
	sub [BUDDY_X], 0x0001
	call GUARDED_DRAW_CIN_242_243
	break

LABEL_220C:
	sub [BUDDY_X], 0x0001
	mov [0x0D], 0x0001
	mov [0x0E], 0x0003
	call GUARDED_DRAW_CIN_338_339
	break
	mov [0x0E], 0x0005
	mov [0x29], 0x00FF
	jmp LABEL_5855
LABEL_2227:
	db 0x11

COMPUTE_OFFSET_VAR21_22:
	call LABEL_628E
	mov [0x21], [BUDDY_X]
	mov [0x22], [BUDDY_Y]
	sub [0x21], 0x0023
	sub [0x22], 0x0026
	ret

LABEL_223A:
	call LABEL_652F
	mov [0x21], [BUDDY_X]
	mov [0x22], [BUDDY_Y]
	add [0x21], 0x0023
	sub [0x22], 0x0026
	ret

LABEL_224C:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_225D
	mov [0x2F], 0x0005
	jmp LABEL_24E5

LABEL_225D:
	jl [0xF8], 0x1000, LABEL_22A8
	jmp LABEL_2268
LABEL_2267:
	db 0x11

LABEL_2268:
	call LABEL_6587
	break
	call LABEL_6541
	break
	call LABEL_6575
	break
	call LABEL_223A
	video offset=CINEMATIC_196, x=[0x21], y=[0x22]
	break
	call LABEL_223A
	video offset=CINEMATIC_197, x=[0x21], y=[0x22]
	break
	call LABEL_223A
	video offset=CINEMATIC_198, x=[0x21], y=[0x22]
	break
	call LABEL_223A
	video offset=CINEMATIC_210, x=[0x21], y=[0x22]
	break
	call LABEL_223A
	video offset=CINEMATIC_200, x=[0x21], y=[BUDDY_Y]
	call LABEL_40D5
	break
	jmp LABEL_2543
LABEL_22A7:
	db 0x11

LABEL_22A8:
	call LABEL_6312
	break
	call LABEL_62AB
	break
	call LABEL_62F5
	break
	call COMPUTE_OFFSET_VAR21_22
	play id=0x005B, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_196, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_197, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_198, x=[0x21], y=[0x22]
	play id=0x0059, freq=0x14, vol=0x40, channel=0x01
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_199, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_200, x=[0x21], y=[BUDDY_Y]
	call LABEL_40D5
	break
	jmp LABEL_2523
LABEL_22F3:
	db 0x11

LABEL_22F4:
	break
	mov [0x33], 0xFFF6
	jne [0x72], 0x03, LABEL_22F4
	jl [0x70], 0xC8, LABEL_22F4

LABEL_2305:
	jne [HACK_VAR_67], 0x04, LABEL_2319
	call LABEL_2378
	je [0x23], 0x00, LABEL_235C
	video offset=CINEMATIC_202, x=[0x21], y=[BUDDY_Y]

LABEL_2319:
	break
	jne [HACK_VAR_67], 0x04, LABEL_232E
	call LABEL_2378
	je [0x23], 0x00, LABEL_235C
	video offset=CINEMATIC_203, x=[0x21], y=[BUDDY_Y]

LABEL_232E:
	break
	jne [HACK_VAR_67], 0x04, LABEL_2343
	call LABEL_2378
	je [0x23], 0x00, LABEL_235C
	video offset=CINEMATIC_204, x=[0x21], y=[BUDDY_Y]

LABEL_2343:
	break
	jne [HACK_VAR_67], 0x04, LABEL_2358
	call LABEL_2378
	je [0x23], 0x00, LABEL_235C
	video offset=CINEMATIC_203, x=[0x21], y=[BUDDY_Y]

LABEL_2358:
	break
	jmp LABEL_2305

LABEL_235C:
	call LABEL_2378
	video offset=CINEMATIC_210, x=[0x21], y=[BUDDY_Y]
	break
	call LABEL_2378
	video offset=CINEMATIC_200, x=[0x21], y=[0x71]
	mov [BUDDY_Y], [0x71]
	mov [0x10], 0x0004
	call LABEL_40D5
	killChannel

LABEL_2378:
	mov [BUDDY_Y], [0x71]
	sub [BUDDY_Y], 0x0028
	mov [0x21], [0x33]
	mov [0x23], 0x0001
	jg [0x33], 0x14, LABEL_2391
	add [0x33], 0x0003
	ret

LABEL_2391:
	jl [0x70], 0x0140, SHARED_RET
	mov [0x23], 0x0000
	ret

LABEL_239D:
	je [BUDDY_Y], [0x52], LABEL_2437
	jmp LABEL_23B7

LABEL_23A6:
	break
	mov [0xF8], [0x11]
	and [0xF8], 0x1000
	je [0xF8], 0x00, LABEL_2563
	jmp LABEL_25A5

LABEL_23B7:
	mov [BUDDY_Y], [0x52]
	sub [BUDDY_Y], 0x001E
	call LABEL_6282
	break
	mov [BUDDY_Y], [0x52]
	call LABEL_6282
	jmp LABEL_23A6

LABEL_23CB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_202, x=[0x21], y=[0x22]
	ret

LABEL_23D7:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_203, x=[0x21], y=[0x22]
	ret

LABEL_23E3:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_204, x=[0x21], y=[0x22]
	ret

LABEL_23EF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_190, x=[0x21], y=[0x22]
	ret

LABEL_23FB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_191, x=[0x21], y=[0x22]
	ret

LABEL_2407:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_192, x=[0x21], y=[0x22]
	ret

LABEL_2413:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_193, x=[0x21], y=[0x22]
	ret

LABEL_241F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_194, x=[0x21], y=[0x22]
	ret

LABEL_242B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video offset=CINEMATIC_195, x=[0x21], y=[0x22]
	ret

LABEL_2437:
	mov [BUDDY_Y], [0x51]
	add [BUDDY_Y], 0x001E
	call LABEL_6276
	break
	mov [BUDDY_Y], [0x51]
	call LABEL_6276
	jmp LABEL_23A6
LABEL_244B:
	db 0x11

LABEL_244C:
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

LABEL_2474:
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_23CB
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_23D7
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_23E3
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_23D7
	break
	djnz [0x29], LABEL_2474
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_23EF
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_23FB
	break
	mov [0x29], 0x0002

LABEL_24A6:
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_2407
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_2413
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_241F
	break
	call COMPUTE_OFFSET_VAR21_22
	call LABEL_242B
	break
	djnz [0x29], LABEL_24A6
	jne [HACK_VAR_67], [0x10], LABEL_2523
	call COMPUTE_OFFSET_VAR21_22
	mov [0x96], [0x21]
	mov [0x97], [0x22]
	mov [0x8B], 0x0064
	or [0x8B], 0x8000
	or [0x97], 0x4000
	jmp LABEL_2523
LABEL_24E4:
	db 0x11

LABEL_24E5:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_24F3
	sub [0xF8], 0x2000

LABEL_24F3:
	jl [0xF8], 0x1000, LABEL_2507
	je [0x2F], 0x05, LABEL_2534
	je [0x2F], 0x0F, LABEL_2596
	killChannel

LABEL_2507:
	je [0x2F], 0x05, LABEL_2514
	je [0x2F], 0x0F, LABEL_2554
	killChannel

LABEL_2514:
	jl [0x11], 0x2000, LABEL_2523
	sub [0x11], 0x2000
	call LABEL_633D
	break

LABEL_2523:
	call LABEL_6312
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_2523
LABEL_2533:
	db 0x11

LABEL_2534:
	jl [0x11], 0x2000, LABEL_2543
	sub [0x11], 0x2000
	call LABEL_65AD
	break

LABEL_2543:
	call LABEL_6587
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_2543
LABEL_2553:
	db 0x11

LABEL_2554:
	jge [0x11], 0x2000, LABEL_2563
	add [0x11], 0x2000
	call LABEL_633D
	break

LABEL_2563:
	call GUARDED_DRAW_CIN_242_243
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_2563
LABEL_2573:
	db 0x11

GAME_LOOP_DRAW_CIN_242_243:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CIN_242_243
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp GAME_LOOP_DRAW_CIN_242_243
LABEL_2584:
	db 0x11

LABEL_2585:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CIN_242_243
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp LABEL_2585
LABEL_2595:
	db 0x11

LABEL_2596:
	jge [0x11], 0x2000, LABEL_25A5
	add [0x11], 0x2000
	call LABEL_65AD
	break

LABEL_25A5:
	call GUARDED_HERO_ANIM_CV_009
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_25A5
LABEL_25B5:
	db 0x11

MAIN_GAME_LOOP_HERO_009:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_009
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp MAIN_GAME_LOOP_HERO_009
LABEL_25C6:
	db 0x11

LABEL_25C7:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_009
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp LABEL_25C7
LABEL_25D7:
	db 0x11

LABEL_25D8:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_25EF
	je [0x2F], 0x10, LABEL_682D
	jmp LABEL_672A

LABEL_25EF:
	je [0x2F], 0x10, LABEL_56A1
	jmp LABEL_5A2F
LABEL_25F8:
	db 0x11

LABEL_25F9:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_2610
	je [0x2F], 0x01, LABEL_682D
	jmp LABEL_2980

LABEL_2610:
	je [0x2F], 0x02, LABEL_56A1
	jmp LABEL_29AB
LABEL_2619:
	db 0x11

LABEL_261A:
	mov [0x2F], 0x0001
	jg [0x29], [BUDDY_X], LABEL_25F9
	mov [0x2F], 0x0002
	jmp LABEL_25F9

LABEL_262B:
	jg [0x29], [BUDDY_X], LABEL_672A
	jmp LABEL_5A2F
LABEL_2634:
	db 0x11, 0x01, 0xF8, 0x11, 0x0A, 0x44, 0xF8, 0x20
	db 0x00, 0x26, 0x4D, 0x03, 0xF8, 0xE0, 0x00, 0x0A
	db 0x44, 0xF8, 0x10, 0x00, 0x25, 0x14, 0x07, 0x25
	db 0x34, 0x0A, 0x44, 0xF8, 0x10, 0x00, 0x26, 0x58
	db 0x07, 0x26, 0xA5, 0x11

LABEL_2658:
	call LABEL_639A
	mov [0x29], 0x0005
	mov [0x0E], 0x0004

LABEL_2663:
	break
	call LABEL_63C9
	djnz [0x29], LABEL_2663
	mov [0x21], [BUDDY_X]
	mov [0x27], [BUDDY_Y]
	mov [0x22], 0x4008
	call LABEL_345B
	break
	call LABEL_640A
	break
	call LABEL_640A
	break
	call LABEL_63E3
	mov [0x29], 0x0005

LABEL_2688:
	break
	call LABEL_63C9
	djnz [0x29], LABEL_2688
	mov [0x0E], 0x0000

LABEL_2694:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6312
	jmp LABEL_2694
LABEL_26A4:
	db 0x11, 0x04, 0x65, 0xF0, 0x00, 0x29, 0x00, 0x05
	db 0x00, 0x0E, 0x00, 0x04, 0x06, 0x04, 0x66, 0x1F
	db 0x09, 0x29, 0x26, 0xB0, 0x01, 0x21, 0x07, 0x01
	db 0x27, 0x08, 0x00, 0x22, 0x00, 0x08, 0x04, 0x34
	db 0x5B, 0x06, 0x04, 0x66, 0x60, 0x06, 0x04, 0x66
	db 0x60, 0x06, 0x04, 0x66, 0x39, 0x00, 0x29, 0x00
	db 0x05, 0x06, 0x04, 0x66, 0x1F, 0x09, 0x29, 0x26
	db 0xD5, 0x00, 0x0E, 0x00, 0x00, 0x06, 0x04, 0x30
	db 0x69, 0x0A, 0x01, 0x2F, 0x00, 0x29, 0xE0, 0x04
	db 0x65, 0x87, 0x07, 0x26, 0xE1, 0x11

LABEL_26F2:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_2719
	sub [0xF8], 0x2000
	jl [0xF8], 0x1000, LABEL_2710
	je [0x2F], 0x07, LABEL_2892
	jmp LABEL_2534

LABEL_2710:
	je [0x2F], 0x07, LABEL_273F
	jmp LABEL_2514

LABEL_2719:
	jl [0xF8], 0x1000, LABEL_272F
	je [0x2F], 0x08, LABEL_28C3
	je [0x2F], 0x09, LABEL_2908
	jmp LABEL_2596

LABEL_272F:
	je [0x2F], 0x08, LABEL_2770
	je [0x2F], 0x09, LABEL_27B5
	jmp LABEL_2554
LABEL_273E:
	db 0x11

LABEL_273F:
	call LABEL_6439
	mov [0x21], [BUDDY_X]
	mov [0x27], [BUDDY_Y]
	sub [0x21], 0x0028
	sub [0x27], 0x0036
	call LABEL_372B
	break
	call LABEL_6456
	break
	call LABEL_649C
	break
	call LABEL_6439

LABEL_275F:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CIN_242_243
	jmp LABEL_275F
LABEL_276F:
	db 0x11

LABEL_2770:
	call LABEL_628E
	je [0x29], 0x00, LABEL_2781
	break
	sub [0x29], 0x0001
	jmp LABEL_2770

LABEL_2781:
	jne [HACK_VAR_67], [0x10], LABEL_2798
	mov [0x21], [BUDDY_X]
	mov [0x27], [BUDDY_Y]
	sub [0x21], 0x0028
	sub [0x27], 0x0029
	call LABEL_372B

LABEL_2798:
	break
	call LABEL_62AB
	break
	call LABEL_62F5
	break
	call LABEL_628E

LABEL_27A4:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6312
	jmp LABEL_27A4
LABEL_27B4:
	db 0x11

LABEL_27B5:
	call LABEL_62D8
	je [0x29], 0x00, LABEL_27C6
	break
	sub [0x29], 0x0001
	jmp LABEL_27B5

LABEL_27C6:
	jne [HACK_VAR_67], [0x10], LABEL_27DD
	mov [0x21], [BUDDY_X]
	mov [0x27], [BUDDY_Y]
	sub [0x21], 0x0019
	sub [0x27], 0x001E
	call LABEL_372B

LABEL_27DD:
	break
	call LABEL_634C
	break
	call LABEL_637B
	break
	call LABEL_62D8

LABEL_27E9:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6312
	jmp LABEL_27E9
LABEL_27F9:
	db 0x11, 0x04, 0x62, 0x01, 0x03, 0x07, 0x00, 0x02
	db 0x0C, 0x14, 0x16, 0x02, 0x08, 0x15, 0x3B, 0x08
	db 0x01, 0x01, 0x07, 0x03, 0x01, 0x00, 0x10, 0x06
	db 0x04, 0x62, 0x22, 0x03, 0x07, 0x00, 0x02, 0x06
	db 0x04, 0x62, 0x61, 0x03, 0x07, 0x00, 0x02, 0x06
	db 0x04, 0x62, 0x61, 0x03, 0x07, 0x00, 0x01, 0x06
	db 0x04, 0x62, 0x61, 0x03, 0x07, 0x00, 0x01, 0x06
	db 0x04, 0x62, 0x61, 0x03, 0x07, 0xFF, 0xFE, 0x06
	db 0x04, 0x62, 0x4C, 0x03, 0x07, 0xFF, 0xFD, 0x06
	db 0x04, 0x62, 0x37, 0x06, 0x01, 0x29, 0x07, 0x03
	db 0x29, 0x00, 0x3C, 0x00, 0x2F, 0x00, 0x19, 0x07
	db 0x29, 0xE0, 0x11

LABEL_2854:
	call LABEL_628E
	deleteChannels first=0x14, last=0x16
	mov [0x03], 0x0014
	setup channel=0x3F, address=DELAY_4_QUANTUMS
	mov [0x29], 0x0001

LABEL_2867:
	break
	video offset=CINEMATIC_426, x=[BUDDY_X], y=[BUDDY_Y]
	djnz [0x29], LABEL_2867
	break
	video offset=CINEMATIC_427, x=[BUDDY_X], y=[BUDDY_Y]
	play id=0x005E, freq=0x14, vol=0x40, channel=0x01
	mov [0x29], 0x0003

LABEL_2881:
	break
	video offset=CINEMATIC_427, x=[BUDDY_X], y=[BUDDY_Y]
	djnz [0x29], LABEL_2881
	mov [0x29], 0x0002
	jmp LABEL_2867

LABEL_2892:
	call LABEL_668F
	mov [0x21], [BUDDY_X]
	mov [0x27], [BUDDY_Y]
	add [0x21], 0x0028
	sub [0x27], 0x0036
	call LABEL_3744
	break
	call LABEL_66A9
	break
	call LABEL_66E5
	break
	call LABEL_668F

LABEL_28B2:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_009
	jmp LABEL_28B2
LABEL_28C2:
	db 0x11

LABEL_28C3:
	call LABEL_652F
	je [0x29], 0x00, LABEL_28D4
	break
	sub [0x29], 0x0001
	jmp LABEL_28C3

LABEL_28D4:
	jne [HACK_VAR_67], [0x10], LABEL_28EB
	mov [0x21], [BUDDY_X]
	mov [0x27], [BUDDY_Y]
	add [0x21], 0x0028
	sub [0x27], 0x0029
	call LABEL_3744

LABEL_28EB:
	break
	call LABEL_6541
	break
	call LABEL_6575
	break
	call LABEL_652F

LABEL_28F7:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6587
	jmp LABEL_28F7
LABEL_2907:
	db 0x11

LABEL_2908:
	call LABEL_6563
	je [0x29], 0x00, LABEL_2919
	break
	sub [0x29], 0x0001
	jmp LABEL_2908

LABEL_2919:
	jne [HACK_VAR_67], [0x10], LABEL_2930
	mov [0x21], [BUDDY_X]
	mov [0x27], [BUDDY_Y]
	add [0x21], 0x0019
	sub [0x27], 0x001E
	call LABEL_3744

LABEL_2930:
	break
	call LABEL_65BC
	break
	call LABEL_65DE
	break
	call LABEL_6563

LABEL_293C:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6587
	jmp LABEL_293C
LABEL_294C:
	db 0x11

LABEL_294D:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_29AB
	jmp LABEL_2980
LABEL_295E:
	db 0x11

LABEL_295F:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_2976
	je [0x2F], 0x13, LABEL_2980
	jmp LABEL_25A5

LABEL_2976:
	je [0x2F], 0x12, LABEL_29AB
	jmp LABEL_2563
LABEL_297F:
	db 0x11

LABEL_2980:
	call LABEL_6201
	add [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_342
	sub [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_338_339
	call AND_VAR11_WITH_EFFF
	sub [BUDDY_X], 0x0001

LABEL_299A:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CIN_242_243
	jmp LABEL_299A
LABEL_29AA:
	db 0x11

LABEL_29AB:
	call LABEL_5661
	sub [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_342
	add [BUDDY_X], 0x0001
	break
	call LABEL_61E0
	call INLINE_OR_VAR11_WITH_1000
	add [BUDDY_X], 0x0001

LABEL_29C5:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_009
	jmp LABEL_29C5
LABEL_29D5:
	db 0x11
