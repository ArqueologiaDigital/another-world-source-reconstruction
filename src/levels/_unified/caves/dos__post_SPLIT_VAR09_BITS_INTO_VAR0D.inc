LABEL_510D:
	mov [0x07], [0x68]
	mov [0x08], [0x69]
	mov [0x10], [0x6A]
	mov [0x11], [0x6B]
	mov [0x09], [0x6D]
	mov [0x12], [0x6C]
	mov [0x13], [0x6E]
	mov [0x29], [0x6F]
	call SPLIT_VAR09_BITS_INTO_VAR0D
	break
	jmp LABEL_510D
LABEL_512C:
	db 0x11

LABEL_512D:
	call LABEL_50E4
	mov [0x68], [0x07]
	mov [0x69], [0x08]
	mov [0x6A], [0x10]
	mov [0x6B], [0x11]
	mov [0x6D], [0x09]
	mov [0x6C], [0x12]
	mov [0x6E], [0x13]
	mov [0x6F], [0x29]
	mov [0x07], [0x70]
	mov [0x08], [0x71]
	mov [0x10], [0x72]
	mov [0x11], [0x73]
	mov [0x09], [0x75]
	mov [0x12], [0x74]
	mov [0x13], [0x76]
	mov [0x29], [0x77]
	call SPLIT_VAR09_BITS_INTO_VAR0D
	break
	jmp LABEL_512D
LABEL_5167:
	db 0x11

LABEL_5168:
	call LABEL_50E4
	mov [0x70], [0x07]
	mov [0x71], [0x08]
	mov [0x72], [0x10]
	mov [0x73], [0x11]
	mov [0x75], [0x09]
	mov [0x74], [0x12]
	mov [0x76], [0x13]
	mov [0x77], [0x29]
	mov [0x07], [0x78]
	mov [0x08], [0x79]
	mov [0x10], [0x7A]
	mov [0x11], [0x7B]
	mov [0x09], [0x7D]
	mov [0x12], [0x7C]
	mov [0x13], [0x7E]
	mov [0x29], [0x7F]
	call SPLIT_VAR09_BITS_INTO_VAR0D
	break
	jmp LABEL_5168
LABEL_51A2:
	db 0x11

LABEL_51A3:
	call LABEL_50E4
	mov [0x78], [0x07]
	mov [0x79], [0x08]
	mov [0x7A], [0x10]
	mov [0x7B], [0x11]
	mov [0x7D], [0x09]
	mov [0x7C], [0x12]
	mov [0x7E], [0x13]
	mov [0x7F], [0x29]
	break
	jmp LABEL_51A3
LABEL_51C2:
	db 0x11

COMPUTE_OFFSET_VAR21_22:
	call LABEL_92D6
	mov [0x21], [0x07]
	mov [0x22], [0x08]
	sub [0x21], 0x0023
	sub [0x22], 0x0026
	ret

COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D:
	call LABEL_9598
	mov [0x21], [0x07]
	mov [0x22], [0x08]
	add [0x21], 0x0023
	sub [0x22], 0x0026
	ret

LABEL_51E7:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_51F8
	mov [0x2F], 0x0005
	jmp LABEL_55F2

LABEL_51F8:
	jl [0xF8], 0x1000, LABEL_5243
	jmp LABEL_5203
LABEL_5202:
	db 0x11

LABEL_5203:
	call LABEL_95F0
	break
	call LABEL_95AA
	break
	call LABEL_95DE
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_063, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_064, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_065, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_067, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_037, x=[0x21], y=[0x08], zoom=0x40
	call LABEL_7087
	break
	jmp LABEL_5650
LABEL_5242:
	db 0x11

LABEL_5243:
	call LABEL_935A
	break
	call LABEL_92F3
	break
	call LABEL_933D
	break
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_063, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_064, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_065, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_066, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_037, x=[0x21], y=[0x08], zoom=0x40
	call LABEL_7087
	break
	jmp LABEL_5630
	killChannel

LABEL_5283:
	break
	mov [0x33], 0xFFF6
	jne [0x72], 0x03, LABEL_5283
	jl [0x70], 0xC8, LABEL_5283

LABEL_5294:
	jne [HACK_VAR_67], 0x04, LABEL_52A8
	call LABEL_5307
	je [0x23], 0x00, LABEL_52EB
	video type=1, offset=CINEMATIC_033, x=[0x21], y=[0x08], zoom=0x40

LABEL_52A8:
	break
	jne [HACK_VAR_67], 0x04, LABEL_52BD
	call LABEL_5307
	je [0x23], 0x00, LABEL_52EB
	video type=1, offset=CINEMATIC_034, x=[0x21], y=[0x08], zoom=0x40

LABEL_52BD:
	break
	jne [HACK_VAR_67], 0x04, LABEL_52D2
	call LABEL_5307
	je [0x23], 0x00, LABEL_52EB
	video type=1, offset=CINEMATIC_035, x=[0x21], y=[0x08], zoom=0x40

LABEL_52D2:
	break
	jne [HACK_VAR_67], 0x04, LABEL_52E7
	call LABEL_5307
	je [0x23], 0x00, LABEL_52EB
	video type=1, offset=CINEMATIC_034, x=[0x21], y=[0x08], zoom=0x40

LABEL_52E7:
	break
	jmp LABEL_5294

LABEL_52EB:
	call LABEL_5307
	video type=1, offset=CINEMATIC_067, x=[0x21], y=[0x08], zoom=0x40
	break
	call LABEL_5307
	video type=1, offset=CINEMATIC_037, x=[0x21], y=[0x71], zoom=0x40
	mov [0x08], [0x71]
	mov [0x10], 0x0004
	call LABEL_7087
	killChannel

LABEL_5307:
	mov [0x08], [0x71]
	sub [0x08], 0x0028
	mov [0x21], [0x33]
	mov [0x23], 0x0001
	jg [0x33], 0x14, LABEL_5320
	add [0x33], 0x0003
	ret

LABEL_5320:
	jl [0x70], 0x0140, SHARED_RET
	mov [0x23], 0x0000
	ret

LABEL_532C:
	je [0x08], [0x52], LABEL_535A
	jmp LABEL_5346

LABEL_5335:
	break
	mov [0xF8], [0x11]
	and [0xF8], 0x1000
	je [0xF8], 0x00, LABEL_5670
	jmp GAME_LOOP_HERO_DISPATCH_LAST

LABEL_5346:
	mov [0x08], [0x52]
	sub [0x08], 0x001E
	call LABEL_92CA
	break
	mov [0x08], [0x52]
	call LABEL_92CA
	jmp LABEL_5335

LABEL_535A:
	mov [0x08], [0x51]
	add [0x08], 0x001E
	call LABEL_92BE
	break
	mov [0x08], [0x51]
	call LABEL_92BE
	jmp LABEL_5335
LABEL_536E:
	db 0x11

LABEL_536F:
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_063, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_064, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_065, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_066, x=[0x21], y=[0x22], zoom=0x40
	break
	mov [0x29], 0x0003

LABEL_53A9:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_033, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_034, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_035, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_034, x=[0x21], y=[0x22], zoom=0x40
	break
	djnz [0x29], LABEL_53A9

LABEL_53E9:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_068, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_069, x=[0x21], y=[0x22], zoom=0x40
	break
	mov [0x29], 0x0002

LABEL_540B:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_070, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_071, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_072, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_073, x=[0x21], y=[0x22], zoom=0x40
	break
	djnz [0x29], LABEL_540B
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	mov [0x96], [0x21]
	mov [0x97], [0x22]
	mov [0x8B], 0x0064
	or [0x8B], 0x8000
	or [0x97], 0x4000

JUMP_TO_LABEL_5630:
	jmp LABEL_5630
LABEL_5469:
	db 0x11

LABEL_546A:
	mov [0xF8], [0x11]
	and [0xF8], 0x1000
	jne [0xF8], 0x00, LABEL_54F5
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_063, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_064, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_065, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_066, x=[0x21], y=[0x22], zoom=0x40
	break
	mov [0x29], 0x0001

LABEL_54B1:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_033, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_034, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_035, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5630
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_034, x=[0x21], y=[0x22], zoom=0x40
	break
	djnz [0x29], LABEL_54B1
	jmp LABEL_53E9
LABEL_54F4:
	db 0x11

LABEL_54F5:
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_063, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5650
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_064, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5650
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_065, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5650
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_066, x=[0x21], y=[0x22], zoom=0x40
	break
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x29], [0x38]
	add [0x29], 0x0001

LABEL_5535:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5650
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_033, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5650
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_034, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5650
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_035, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5650
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_034, x=[0x21], y=[0x22], zoom=0x40
	break
	djnz [0x29], LABEL_5535
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5650
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_068, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5650
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_069, x=[0x21], y=[0x22], zoom=0x40
	break
	mov [0x29], 0x0001

LABEL_5597:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5650
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_070, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5650
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_071, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5650
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_072, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5650
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	video type=1, offset=CINEMATIC_073, x=[0x21], y=[0x22], zoom=0x40
	break
	djnz [0x29], LABEL_5597
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_5650
	call COMPUTE_OFFSET_PLUS21_MINUS22__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D__DOS__POST_SPLIT_VAR09_BITS_INTO_VAR0D
	mov [0x96], [0x21]
	mov [0x97], [0x22]
	mov [0x8B], 0x0064
	or [0x8B], 0x8000

JUMP_TO_LABEL_5650:
	jmp LABEL_5650
LABEL_55F1:
	db 0x11

LABEL_55F2:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_5600
	sub [0xF8], 0x2000

LABEL_5600:
	jl [0xF8], 0x1000, LABEL_5614
	je [0x2F], 0x05, LABEL_5641
	je [0x2F], 0x0F, LABEL_56A3
	killChannel

LABEL_5614:
	je [0x2F], 0x05, LABEL_5621
	je [0x2F], 0x0F, LABEL_5661
	killChannel

LABEL_5621:
	jl [0x11], 0x2000, LABEL_5630
	sub [0x11], 0x2000
	call LABEL_9385
	break

LABEL_5630:
	call LABEL_935A
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_5630
LABEL_5640:
	db 0x11

LABEL_5641:
	jl [0x11], 0x2000, LABEL_5650
	sub [0x11], 0x2000
	call LABEL_9616
	break

LABEL_5650:
	call LABEL_95F0
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_5650
LABEL_5660:
	db 0x11

LABEL_5661:
	jge [0x11], 0x2000, LABEL_5670
	add [0x11], 0x2000
	call LABEL_9385
	break

LABEL_5670:
	call GUARDED_DRAW_CV_304_305
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_5670
LABEL_5680:
	db 0x11

GAME_LOOP_CV_304_305:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CV_304_305
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp GAME_LOOP_CV_304_305
LABEL_5691:
	db 0x11

LABEL_5692:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CV_304_305
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp LABEL_5692
LABEL_56A2:
	db 0x11

LABEL_56A3:
	jge [0x11], 0x2000, GAME_LOOP_HERO_DISPATCH_LAST
	add [0x11], 0x2000
	call LABEL_9616
	break

GAME_LOOP_HERO_DISPATCH_LAST:
	call GUARDED_HERO_ANIM_CV_128
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp GAME_LOOP_HERO_DISPATCH_LAST
LABEL_56C2:
	db 0x11

GAME_LOOP_HERO_DISPATCH_FIRST:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_128
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp GAME_LOOP_HERO_DISPATCH_FIRST
LABEL_56D3:
	db 0x11

LABEL_56D4:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_128
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp LABEL_56D4
LABEL_56E4:
	db 0x11

LABEL_56E5:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_56FC
	je [0x2F], 0x10, LABEL_9885
	jmp LABEL_9793

LABEL_56FC:
	je [0x2F], 0x10, LABEL_8787
	jmp LABEL_8A91
LABEL_5705:
	db 0x11

LABEL_5706:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_571D
	je [0x2F], 0x01, LABEL_9885
	jmp LABEL_5A74

LABEL_571D:
	je [0x2F], 0x02, LABEL_8787
	jmp LABEL_5A9F
LABEL_5726:
	db 0x11

LABEL_5727:
	mov [0x2F], 0x0001
	jg [0x29], [0x07], LABEL_5706
	mov [0x2F], 0x0002
	jmp LABEL_5706

LABEL_5738:
	jg [0x29], [0x07], LABEL_9793
	jmp LABEL_8A91
LABEL_5741:
	db 0x11

LABEL_5742:
	mov [0xF8], [0x11]
	and [0xF8], 0x1000
	jl [0xF8], 0x2000, LABEL_575E
	sub [0xF8], 0x2000
	jl [0xF8], 0x1000, LABEL_5621
	jmp LABEL_5641

LABEL_575E:
	jl [0xF8], 0x1000, LABEL_5769
	jmp LABEL_57E0
LABEL_5768:
	db 0x11

LABEL_5769:
	call LABEL_93E2
	mov [0x29], 0x0005
	mov [0x0E], 0x0004

LABEL_5774:
	break
	call LABEL_9411
	call LABEL_60A4
	jl [0x26], 0x32, LABEL_5901
	djnz [0x29], LABEL_5774
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	mov [0x22], 0x4008
	jne [HACK_VAR_67], [0x10], LABEL_5798
	call LABEL_62AA

LABEL_5798:
	break
	call LABEL_9452
	call LABEL_60A4
	jl [0x26], 0x32, LABEL_5901
	break
	call LABEL_9452
	call LABEL_60A4
	jl [0x26], 0x32, LABEL_5901
	break
	call LABEL_942B
	mov [0x29], 0x0005

LABEL_57BA:
	break
	call LABEL_9411
	call LABEL_60A4
	jl [0x26], 0x32, LABEL_5901
	djnz [0x29], LABEL_57BA
	mov [0x0E], 0x0000

LABEL_57CF:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_935A
	jmp LABEL_57CF
LABEL_57DF:
	db 0x11

LABEL_57E0:
	call LABEL_9659
	mov [0x29], 0x0005
	mov [0x0E], 0x0004

LABEL_57EB:
	break
	call LABEL_9688
	djnz [0x29], LABEL_57EB
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	mov [0x22], 0x0008
	jne [HACK_VAR_67], [0x10], LABEL_5806
	call LABEL_62AA

LABEL_5806:
	break
	call LABEL_96C9
	break
	call LABEL_96C9
	break
	call LABEL_96A2
	mov [0x29], 0x0005

LABEL_5816:
	break
	call LABEL_9688
	djnz [0x29], LABEL_5816
	mov [0x0E], 0x0000

LABEL_5822:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_95F0
	jmp LABEL_5822
LABEL_5832:
	db 0x11

LABEL_5833:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_585A
	sub [0xF8], 0x2000
	jl [0xF8], 0x1000, LABEL_5851
	je [0x2F], 0x07, LABEL_59AE
	jmp LABEL_5641

LABEL_5851:
	je [0x2F], 0x07, LABEL_5880
	jmp LABEL_5621

LABEL_585A:
	jl [0xF8], 0x1000, LABEL_5870
	je [0x2F], 0x08, LABEL_59DF
	je [0x2F], 0x09, LABEL_5A10
	jmp LABEL_56A3

LABEL_5870:
	je [0x2F], 0x08, LABEL_58B1
	je [0x2F], 0x09, LABEL_58F0
	jmp LABEL_5661
LABEL_587F:
	db 0x11

LABEL_5880:
	call LABEL_94A2
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0028
	sub [0x27], 0x0036
	call LABEL_6580
	break
	call LABEL_94BF
	break
	call LABEL_9505
	break
	call LABEL_94A2

LABEL_58A0:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CV_304_305
	jmp LABEL_58A0
LABEL_58B0:
	db 0x11

LABEL_58B1:
	call LABEL_92D6
	je [0x29], 0x00, LABEL_58C2
	break
	sub [0x29], 0x0001
	jmp LABEL_58B1

LABEL_58C2:
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0028
	sub [0x27], 0x0029
	call LABEL_6580
	break
	call LABEL_92F3
	break
	call LABEL_933D
	break
	call LABEL_92D6

LABEL_58DF:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_935A
	jmp LABEL_58DF
LABEL_58EF:
	db 0x11

LABEL_58F0:
	call LABEL_9320
	je [0x29], 0x00, LABEL_5901
	break
	sub [0x29], 0x0001
	jmp LABEL_58F0

LABEL_5901:
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0019
	sub [0x27], 0x001E
	call LABEL_6580
	break
	mov [0x0E], 0x0000
	call LABEL_9394
	break
	call LABEL_93C3
	break
	call LABEL_9320

LABEL_5922:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_935A
	jmp LABEL_5922
LABEL_5932:
	db 0x11

LABEL_5933:
	or [0x04], 0x4000
	call LABEL_92D6
	deleteChannels first=0x14, last=0x16
	mov [0x03], 0x0032
	setup channel=0x3F, address=LABEL_0184
	mov [0x29], 0x0001

LABEL_594A:
	break
	sub [0x07], 0x000A
	add [0x08], 0x0015
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	add [0x07], 0x000A
	sub [0x08], 0x0015
	video type=1, offset=CINEMATIC_190, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x29], LABEL_594A
	break
	sub [0x07], 0x000B
	add [0x08], 0x0015
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	add [0x07], 0x000B
	sub [0x08], 0x0015
	video type=1, offset=CINEMATIC_141, x=[0x07], y=[0x08], zoom=0x40
	play id=0x005E, freq=0x14, vol=0x40, channel=0x00
	mov [0x29], 0x0003

LABEL_598A:
	break
	sub [0x07], 0x000B
	add [0x08], 0x0015
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	add [0x07], 0x000B
	sub [0x08], 0x0015
	video type=1, offset=CINEMATIC_141, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x29], LABEL_598A
	mov [0x29], 0x0002
	jmp LABEL_594A

LABEL_59AE:
	call LABEL_96F8
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	add [0x21], 0x0028
	sub [0x27], 0x0036
	call LABEL_6599
	break
	call LABEL_9712
	break
	call LABEL_974E
	break
	call LABEL_96F8

LABEL_59CE:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_128
	jmp LABEL_59CE
LABEL_59DE:
	db 0x11

LABEL_59DF:
	call LABEL_9598
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	add [0x21], 0x0028
	sub [0x27], 0x0029
	call LABEL_6599
	break
	call LABEL_95AA
	break
	call LABEL_95DE
	break
	call LABEL_9598

LABEL_59FF:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_95F0
	jmp LABEL_59FF
LABEL_5A0F:
	db 0x11

LABEL_5A10:
	call LABEL_95CC
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	add [0x21], 0x0019
	sub [0x27], 0x001E
	call LABEL_6599
	break
	call LABEL_9625
	break
	call LABEL_9647
	break
	call LABEL_95CC

LABEL_5A30:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_95F0
	jmp LABEL_5A30
LABEL_5A40:
	db 0x11

LABEL_5A41:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_5A9F
	jmp LABEL_5A74
LABEL_5A52:
	db 0x11

LABEL_5A53:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_5A6A
	je [0x2F], 0x13, LABEL_5A74
	jmp GAME_LOOP_HERO_DISPATCH_LAST

LABEL_5A6A:
	je [0x2F], 0x12, LABEL_5A9F
	jmp LABEL_5670
LABEL_5A73:
	db 0x11

LABEL_5A74:
	call LABEL_929D
	add [0x07], 0x0001
	break
	call LABEL_9545
	sub [0x07], 0x0001
	break
	call LABEL_8729
	call AND_VAR11_WITH_EFFF
	sub [0x07], 0x0001

LABEL_5A8E:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CV_304_305
	jmp LABEL_5A8E
LABEL_5A9E:
	db 0x11

LABEL_5A9F:
	call LABEL_8747
	sub [0x07], 0x0001
	break
	call LABEL_9545
	add [0x07], 0x0001
	break
	call LABEL_927C
	call INLINE_OR_VAR11_WITH_1000
	add [0x07], 0x0001

LABEL_5AB9:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_128
	jmp LABEL_5AB9
LABEL_5AC9:
	db 0x11
