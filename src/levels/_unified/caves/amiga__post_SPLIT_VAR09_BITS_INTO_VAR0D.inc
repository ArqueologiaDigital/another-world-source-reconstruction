LABEL_4DEA:
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
	jmp LABEL_4DEA
LABEL_4E09:
	db 0x11

LABEL_4E0A:
	call LABEL_4DC1
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
	jmp LABEL_4E0A
LABEL_4E44:
	db 0x11

LABEL_4E45:
	call LABEL_4DC1
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
	jmp LABEL_4E45
LABEL_4E7F:
	db 0x11

LABEL_4E80:
	call LABEL_4DC1
	mov [0x78], [0x07]
	mov [0x79], [0x08]
	mov [0x7A], [0x10]
	mov [0x7B], [0x11]
	mov [0x7D], [0x09]
	mov [0x7C], [0x12]
	mov [0x7E], [0x13]
	mov [0x7F], [0x29]
	break
	jmp LABEL_4E80
LABEL_4E9F:
	db 0x11

COMPUTE_OFFSET_VAR21_22:
	call LABEL_8F78
	mov [0x21], [0x07]
	mov [0x22], [0x08]
	sub [0x21], 0x0023
	sub [0x22], 0x0026
	ret

COMPUTE_OFFSET_PLUS21_MINUS22:
	call LABEL_923A
	mov [0x21], [0x07]
	mov [0x22], [0x08]
	add [0x21], 0x0023
	sub [0x22], 0x0026
	ret

LABEL_4EC4:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_4ED5
	mov [0x2F], 0x0005
	jmp LABEL_52CF

LABEL_4ED5:
	jl [0xF8], 0x1000, LABEL_4F20
	jmp LABEL_4EE0
LABEL_4EDF:
	db 0x11

LABEL_4EE0:
	call LABEL_9292
	break
	call LABEL_924C
	break
	call LABEL_9280
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_063, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_064, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_065, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_067, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_037, x=[0x21], y=[0x08]
	call LABEL_6D6D
	break
	jmp LABEL_532D
LABEL_4F1F:
	db 0x11

LABEL_4F20:
	call LABEL_8FFC
	break
	call LABEL_8F95
	break
	call LABEL_8FDF
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_063, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_064, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_065, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_066, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_037, x=[0x21], y=[0x08]
	call LABEL_6D6D
	break
	jmp LABEL_530D
LABEL_4F5F:
	db 0x11, 0x06, 0x00, 0x33, 0xFF, 0xF6, 0x0A, 0x01
	db 0x72, 0x03, 0x4F, 0x60, 0x0A, 0x04, 0x70, 0xC8
	db 0x4F, 0x60, 0x0A, 0x01, 0x67, 0x04, 0x4F, 0x85
	db 0x04, 0x4F, 0xE4, 0x0A, 0x00, 0x23, 0x00, 0x4F
	db 0xC8, 0x54, 0x0F, 0xFB, 0x21, 0x08, 0x06, 0x0A
	db 0x01, 0x67, 0x04, 0x4F, 0x9A, 0x04, 0x4F, 0xE4
	db 0x0A, 0x00, 0x23, 0x00, 0x4F, 0xC8, 0x54, 0x10
	db 0x11, 0x21, 0x08, 0x06, 0x0A, 0x01, 0x67, 0x04
	db 0x4F, 0xAF, 0x04, 0x4F, 0xE4, 0x0A, 0x00, 0x23
	db 0x00, 0x4F, 0xC8, 0x54, 0x10, 0x29, 0x21, 0x08
	db 0x06, 0x0A, 0x01, 0x67, 0x04, 0x4F, 0xC4, 0x04
	db 0x4F, 0xE4, 0x0A, 0x00, 0x23, 0x00, 0x4F, 0xC8
	db 0x54, 0x10, 0x11, 0x21, 0x08, 0x06, 0x07, 0x4F
	db 0x71, 0x04, 0x4F, 0xE4, 0x54, 0x0B, 0xDC, 0x21
	db 0x08, 0x06, 0x04, 0x4F, 0xE4, 0x54, 0x0C, 0x06
	db 0x21, 0x71, 0x01, 0x08, 0x71, 0x00, 0x10, 0x00
	db 0x04, 0x04, 0x6D, 0x6D, 0x11, 0x01, 0x08, 0x71
	db 0x03, 0x08, 0xFF, 0xD8, 0x01, 0x21, 0x33, 0x00
	db 0x23, 0x00, 0x01, 0x0A, 0x02, 0x33, 0x14, 0x4F
	db 0xFD, 0x03, 0x33, 0x00, 0x03, 0x05, 0x0A, 0x44
	db 0x70, 0x01, 0x40, 0x7F, 0xB2, 0x00, 0x23, 0x00
	db 0x00, 0x05

LABEL_5009:
	je [0x08], [0x52], LABEL_5037
	jmp LABEL_5023

LABEL_5012:
	break
	mov [0xF8], [0x11]
	and [0xF8], 0x1000
	je [0xF8], 0x00, LABEL_534D
	jmp GAME_LOOP_HERO_DISPATCH_LAST

LABEL_5023:
	mov [0x08], [0x52]
	sub [0x08], 0x001E
	call LABEL_8F6C
	break
	mov [0x08], [0x52]
	call LABEL_8F6C
	jmp LABEL_5012

LABEL_5037:
	mov [0x08], [0x51]
	add [0x08], 0x001E
	call LABEL_8F60
	break
	mov [0x08], [0x51]
	call LABEL_8F60
	jmp LABEL_5012
LABEL_504B:
	db 0x11

LABEL_504C:
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_063, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_064, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_065, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_066, x=[0x21], y=[0x22]
	break
	mov [0x29], 0x0003

LABEL_5086:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_033, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_034, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_035, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_034, x=[0x21], y=[0x22]
	break
	djnz [0x29], LABEL_5086

LABEL_50C6:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_068, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_069, x=[0x21], y=[0x22]
	break
	mov [0x29], 0x0002

LABEL_50E8:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_070, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_071, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_072, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_073, x=[0x21], y=[0x22]
	break
	djnz [0x29], LABEL_50E8
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	mov [0x96], [0x21]
	mov [0x97], [0x22]
	mov [0x8B], 0x0064
	or [0x8B], 0x8000
	or [0x97], 0x4000

JUMP_TO_LABEL_530D:
	jmp LABEL_530D
LABEL_5146:
	db 0x11

LABEL_5147:
	mov [0xF8], [0x11]
	and [0xF8], 0x1000
	jne [0xF8], 0x00, LABEL_51D2
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_063, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_064, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_065, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_066, x=[0x21], y=[0x22]
	break
	mov [0x29], 0x0001

LABEL_518E:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_033, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_034, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_035, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_530D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_034, x=[0x21], y=[0x22]
	break
	djnz [0x29], LABEL_518E
	jmp LABEL_50C6
LABEL_51D1:
	db 0x11

LABEL_51D2:
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_063, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_532D
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_064, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_532D
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_065, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_532D
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_066, x=[0x21], y=[0x22]
	break
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x29], [0x38]
	add [0x29], 0x0001

LABEL_5212:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_532D
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_033, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_532D
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_034, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_532D
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_035, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_532D
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_034, x=[0x21], y=[0x22]
	break
	djnz [0x29], LABEL_5212
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_532D
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_068, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_532D
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_069, x=[0x21], y=[0x22]
	break
	mov [0x29], 0x0001

LABEL_5274:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_532D
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_070, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_532D
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_071, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_532D
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_072, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_532D
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_073, x=[0x21], y=[0x22]
	break
	djnz [0x29], LABEL_5274
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_532D
	call COMPUTE_OFFSET_PLUS21_MINUS22
	mov [0x96], [0x21]
	mov [0x97], [0x22]
	mov [0x8B], 0x0064
	or [0x8B], 0x8000

JUMP_TO_LABEL_532D:
	jmp LABEL_532D
LABEL_52CE:
	db 0x11

LABEL_52CF:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_52DD
	sub [0xF8], 0x2000

LABEL_52DD:
	jl [0xF8], 0x1000, LABEL_52F1
	je [0x2F], 0x05, LABEL_531E
	je [0x2F], 0x0F, LABEL_5380
	killChannel

LABEL_52F1:
	je [0x2F], 0x05, LABEL_52FE
	je [0x2F], 0x0F, LABEL_533E
	killChannel

LABEL_52FE:
	jl [0x11], 0x2000, LABEL_530D
	sub [0x11], 0x2000
	call LABEL_9027
	break

LABEL_530D:
	call LABEL_8FFC
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_530D
LABEL_531D:
	db 0x11

LABEL_531E:
	jl [0x11], 0x2000, LABEL_532D
	sub [0x11], 0x2000
	call LABEL_92B8
	break

LABEL_532D:
	call LABEL_9292
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_532D
LABEL_533D:
	db 0x11

LABEL_533E:
	jge [0x11], 0x2000, LABEL_534D
	add [0x11], 0x2000
	call LABEL_9027
	break

LABEL_534D:
	call GUARDED_DRAW_CV_304_305
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_534D
LABEL_535D:
	db 0x11

GAME_LOOP_CV_304_305:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CV_304_305
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp GAME_LOOP_CV_304_305
LABEL_536E:
	db 0x11

LABEL_536F:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CV_304_305
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp LABEL_536F
LABEL_537F:
	db 0x11

LABEL_5380:
	jge [0x11], 0x2000, GAME_LOOP_HERO_DISPATCH_LAST
	add [0x11], 0x2000
	call LABEL_92B8
	break

GAME_LOOP_HERO_DISPATCH_LAST:
	call GUARDED_HERO_ANIM_CV_009
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp GAME_LOOP_HERO_DISPATCH_LAST
LABEL_539F:
	db 0x11

GAME_LOOP_HERO_DISPATCH_FIRST:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_009
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp GAME_LOOP_HERO_DISPATCH_FIRST
LABEL_53B0:
	db 0x11

LABEL_53B1:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_009
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp LABEL_53B1
LABEL_53C1:
	db 0x11

LABEL_53C2:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_53D9
	je [0x2F], 0x10, LABEL_9527
	jmp LABEL_9435

LABEL_53D9:
	je [0x2F], 0x10, LABEL_8429
	jmp LABEL_8733
LABEL_53E2:
	db 0x11

LABEL_53E3:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_53FA
	je [0x2F], 0x01, LABEL_9527
	jmp LABEL_5751

LABEL_53FA:
	je [0x2F], 0x02, LABEL_8429
	jmp LABEL_577C
LABEL_5403:
	db 0x11

LABEL_5404:
	mov [0x2F], 0x0001
	jg [0x29], [0x07], LABEL_53E3
	mov [0x2F], 0x0002
	jmp LABEL_53E3

LABEL_5415:
	jg [0x29], [0x07], LABEL_9435
	jmp LABEL_8733
LABEL_541E:
	db 0x11

LABEL_541F:
	mov [0xF8], [0x11]
	and [0xF8], 0x1000
	jl [0xF8], 0x2000, LABEL_543B
	sub [0xF8], 0x2000
	jl [0xF8], 0x1000, LABEL_52FE
	jmp LABEL_531E

LABEL_543B:
	jl [0xF8], 0x1000, LABEL_5446
	jmp LABEL_54BD
LABEL_5445:
	db 0x11

LABEL_5446:
	call LABEL_9084
	mov [0x29], 0x0005
	mov [0x0E], 0x0004

LABEL_5451:
	break
	call LABEL_90B3
	call LABEL_5D81
	jl [0x26], 0x32, LABEL_55DE
	djnz [0x29], LABEL_5451
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	mov [0x22], 0x4008
	jne [HACK_VAR_67], [0x10], LABEL_5475
	call LABEL_5F87

LABEL_5475:
	break
	call LABEL_90F4
	call LABEL_5D81
	jl [0x26], 0x32, LABEL_55DE
	break
	call LABEL_90F4
	call LABEL_5D81
	jl [0x26], 0x32, LABEL_55DE
	break
	call LABEL_90CD
	mov [0x29], 0x0005

LABEL_5497:
	break
	call LABEL_90B3
	call LABEL_5D81
	jl [0x26], 0x32, LABEL_55DE
	djnz [0x29], LABEL_5497
	mov [0x0E], 0x0000

LABEL_54AC:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_8FFC
	jmp LABEL_54AC
LABEL_54BC:
	db 0x11

LABEL_54BD:
	call LABEL_92FB
	mov [0x29], 0x0005
	mov [0x0E], 0x0004

LABEL_54C8:
	break
	call LABEL_932A
	djnz [0x29], LABEL_54C8
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	mov [0x22], 0x0008
	jne [HACK_VAR_67], [0x10], LABEL_54E3
	call LABEL_5F87

LABEL_54E3:
	break
	call LABEL_936B
	break
	call LABEL_936B
	break
	call LABEL_9344
	mov [0x29], 0x0005

LABEL_54F3:
	break
	call LABEL_932A
	djnz [0x29], LABEL_54F3
	mov [0x0E], 0x0000

LABEL_54FF:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_9292
	jmp LABEL_54FF
LABEL_550F:
	db 0x11

LABEL_5510:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_5537
	sub [0xF8], 0x2000
	jl [0xF8], 0x1000, LABEL_552E
	je [0x2F], 0x07, LABEL_568B
	jmp LABEL_531E

LABEL_552E:
	je [0x2F], 0x07, LABEL_555D
	jmp LABEL_52FE

LABEL_5537:
	jl [0xF8], 0x1000, LABEL_554D
	je [0x2F], 0x08, LABEL_56BC
	je [0x2F], 0x09, LABEL_56ED
	jmp LABEL_5380

LABEL_554D:
	je [0x2F], 0x08, LABEL_558E
	je [0x2F], 0x09, LABEL_55CD
	jmp LABEL_533E
LABEL_555C:
	db 0x11

LABEL_555D:
	call LABEL_9144
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0028
	sub [0x27], 0x0036
	call LABEL_625D
	break
	call LABEL_9161
	break
	call LABEL_91A7
	break
	call LABEL_9144

LABEL_557D:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CV_304_305
	jmp LABEL_557D
LABEL_558D:
	db 0x11

LABEL_558E:
	call LABEL_8F78
	je [0x29], 0x00, LABEL_559F
	break
	sub [0x29], 0x0001
	jmp LABEL_558E

LABEL_559F:
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0028
	sub [0x27], 0x0029
	call LABEL_625D
	break
	call LABEL_8F95
	break
	call LABEL_8FDF
	break
	call LABEL_8F78

LABEL_55BC:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_8FFC
	jmp LABEL_55BC
LABEL_55CC:
	db 0x11

LABEL_55CD:
	call LABEL_8FC2
	je [0x29], 0x00, LABEL_55DE
	break
	sub [0x29], 0x0001
	jmp LABEL_55CD

LABEL_55DE:
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0019
	sub [0x27], 0x001E
	call LABEL_625D
	break
	mov [0x0E], 0x0000
	call LABEL_9036
	break
	call LABEL_9065
	break
	call LABEL_8FC2

LABEL_55FF:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_8FFC
	jmp LABEL_55FF
LABEL_560F:
	db 0x11

LABEL_5610:
	or [0x04], 0x4000
	call LABEL_8F78
	deleteChannels first=0x14, last=0x16
	mov [0x03], 0x0032
	setup channel=0x3F, address=LABEL_016F
	mov [0x29], 0x0001

LABEL_5627:
	break
	sub [0x07], 0x000A
	add [0x08], 0x0015
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	add [0x07], 0x000A
	sub [0x08], 0x0015
	video offset=CINEMATIC_190, x=[0x07], y=[0x08]
	djnz [0x29], LABEL_5627
	break
	sub [0x07], 0x000B
	add [0x08], 0x0015
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	add [0x07], 0x000B
	sub [0x08], 0x0015
	video offset=CINEMATIC_141, x=[0x07], y=[0x08]
	play id=0x005E, freq=0x14, vol=0x40, channel=0x00
	mov [0x29], 0x0003

LABEL_5667:
	break
	sub [0x07], 0x000B
	add [0x08], 0x0015
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	add [0x07], 0x000B
	sub [0x08], 0x0015
	video offset=CINEMATIC_141, x=[0x07], y=[0x08]
	djnz [0x29], LABEL_5667
	mov [0x29], 0x0002
	jmp LABEL_5627

LABEL_568B:
	call LABEL_939A
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	add [0x21], 0x0028
	sub [0x27], 0x0036
	call LABEL_6276
	break
	call LABEL_93B4
	break
	call LABEL_93F0
	break
	call LABEL_939A

LABEL_56AB:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_009
	jmp LABEL_56AB
LABEL_56BB:
	db 0x11

LABEL_56BC:
	call LABEL_923A
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	add [0x21], 0x0028
	sub [0x27], 0x0029
	call LABEL_6276
	break
	call LABEL_924C
	break
	call LABEL_9280
	break
	call LABEL_923A

LABEL_56DC:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_9292
	jmp LABEL_56DC
LABEL_56EC:
	db 0x11

LABEL_56ED:
	call LABEL_926E
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	add [0x21], 0x0019
	sub [0x27], 0x001E
	call LABEL_6276
	break
	call LABEL_92C7
	break
	call LABEL_92E9
	break
	call LABEL_926E

LABEL_570D:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_9292
	jmp LABEL_570D
LABEL_571D:
	db 0x11

LABEL_571E:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_577C
	jmp LABEL_5751
LABEL_572F:
	db 0x11

LABEL_5730:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_5747
	je [0x2F], 0x13, LABEL_5751
	jmp GAME_LOOP_HERO_DISPATCH_LAST

LABEL_5747:
	je [0x2F], 0x12, LABEL_577C
	jmp LABEL_534D
LABEL_5750:
	db 0x11

LABEL_5751:
	call LABEL_8F3F
	add [0x07], 0x0001
	break
	call LABEL_91E7
	sub [0x07], 0x0001
	break
	call LABEL_83CB
	call AND_VAR11_WITH_EFFF
	sub [0x07], 0x0001

LABEL_576B:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CV_304_305
	jmp LABEL_576B
LABEL_577B:
	db 0x11

LABEL_577C:
	call LABEL_83E9
	sub [0x07], 0x0001
	break
	call LABEL_91E7
	add [0x07], 0x0001
	break
	call LABEL_8F1E
	call INLINE_OR_VAR11_WITH_1000
	add [0x07], 0x0001

LABEL_5796:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_HERO_ANIM_CV_009
	jmp LABEL_5796
LABEL_57A6:
	db 0x11
