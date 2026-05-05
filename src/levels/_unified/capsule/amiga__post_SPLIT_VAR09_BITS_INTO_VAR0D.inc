LABEL_2FB5:
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
	jmp LABEL_2FB5
LABEL_2FD4:
	db 0x11

LABEL_2FD5:
	call LABEL_2F8C
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
	jmp LABEL_2FD5
LABEL_300F:
	db 0x11

LABEL_3010:
	call LABEL_2F8C
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
	jmp LABEL_3010
LABEL_304A:
	db 0x11

LABEL_304B:
	call LABEL_2F8C
	mov [0x78], [0x07]
	mov [0x79], [0x08]
	mov [0x7A], [0x10]
	mov [0x7B], [0x11]
	mov [0x7D], [0x09]
	mov [0x7C], [0x12]
	mov [0x7E], [0x13]
	mov [0x7F], [0x29]
	break
	jmp LABEL_304B
LABEL_306A:
	db 0x11

COMPUTE_OFFSET_VAR21_22:
	call LABEL_7064
	mov [0x21], [0x07]
	mov [0x22], [0x08]
	sub [0x21], 0x0023
	sub [0x22], 0x0026
	ret

COMPUTE_OFFSET_PLUS21_MINUS22:
	call LABEL_7326
	mov [0x21], [0x07]
	mov [0x22], [0x08]
	add [0x21], 0x0023
	sub [0x22], 0x0026
	ret

LABEL_308F:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_30A0
	mov [0x2F], 0x0005
	jmp LABEL_349A

LABEL_30A0:
	jl [0xF8], 0x1000, LABEL_30EB
	jmp LABEL_30AB
LABEL_30AA:
	db 0x11

LABEL_30AB:
	call LABEL_737E
	break
	call LABEL_7338
	break
	call LABEL_736C
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_092, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_093, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_094, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_095, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_096, x=[0x21], y=[0x08]
	call LABEL_4EFE
	break
	jmp LABEL_34F8
LABEL_30EA:
	db 0x11

LABEL_30EB:
	call LABEL_70E8
	break
	call LABEL_7081
	break
	call LABEL_70CB
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_092, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_093, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_094, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_113, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_096, x=[0x21], y=[0x08]
	call LABEL_4EFE
	break
	jmp LABEL_34D8
LABEL_312A:
	db 0x11, 0x06, 0x00, 0x33, 0xFF, 0xF6, 0x0A, 0x01
	db 0x72, 0x03, 0x31, 0x2B, 0x0A, 0x04, 0x70, 0xC8
	db 0x31, 0x2B, 0x0A, 0x01, 0x67, 0x04, 0x31, 0x50
	db 0x04, 0x31, 0xAF, 0x0A, 0x00, 0x23, 0x00, 0x31
	db 0x93, 0x54, 0x11, 0x7A, 0x21, 0x08, 0x06, 0x0A
	db 0x01, 0x67, 0x04, 0x31, 0x65, 0x04, 0x31, 0xAF
	db 0x0A, 0x00, 0x23, 0x00, 0x31, 0x93, 0x54, 0x11
	db 0x90, 0x21, 0x08, 0x06, 0x0A, 0x01, 0x67, 0x04
	db 0x31, 0x7A, 0x04, 0x31, 0xAF, 0x0A, 0x00, 0x23
	db 0x00, 0x31, 0x93, 0x54, 0x11, 0xA8, 0x21, 0x08
	db 0x06, 0x0A, 0x01, 0x67, 0x04, 0x31, 0x8F, 0x04
	db 0x31, 0xAF, 0x0A, 0x00, 0x23, 0x00, 0x31, 0x93
	db 0x54, 0x11, 0x90, 0x21, 0x08, 0x06, 0x07, 0x31
	db 0x3C, 0x04, 0x31, 0xAF, 0x54, 0x0C, 0xE0, 0x21
	db 0x08, 0x06, 0x04, 0x31, 0xAF, 0x54, 0x0D, 0x0A
	db 0x21, 0x71, 0x01, 0x08, 0x71, 0x00, 0x10, 0x00
	db 0x04, 0x04, 0x4E, 0xFE, 0x11, 0x01, 0x08, 0x71
	db 0x03, 0x08, 0xFF, 0xD8, 0x01, 0x21, 0x33, 0x00
	db 0x23, 0x00, 0x01, 0x0A, 0x02, 0x33, 0x14, 0x31
	db 0xC8, 0x03, 0x33, 0x00, 0x03, 0x05, 0x0A, 0x44
	db 0x70, 0x01, 0x40, 0x60, 0x4A, 0x00, 0x23, 0x00
	db 0x00, 0x05

LABEL_31D4:
	je [0x08], [0x52], LABEL_3202
	jmp LABEL_31EE

LABEL_31DD:
	break
	mov [0xF8], [0x11]
	and [0xF8], 0x1000
	je [0xF8], 0x00, LABEL_3518
	jmp LABEL_355A

LABEL_31EE:
	mov [0x08], [0x52]
	sub [0x08], 0x001E
	call LABEL_7058
	break
	mov [0x08], [0x52]
	call LABEL_7058
	jmp LABEL_31DD

LABEL_3202:
	mov [0x08], [0x51]
	add [0x08], 0x001E
	call LABEL_704C
	break
	mov [0x08], [0x51]
	call LABEL_704C
	jmp LABEL_31DD
LABEL_3216:
	db 0x11

LABEL_3217:
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_092, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_093, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_094, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_113, x=[0x21], y=[0x22]
	break
	mov [0x29], 0x0003

LABEL_3251:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_098, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_099, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_100, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_099, x=[0x21], y=[0x22]
	break
	djnz [0x29], LABEL_3251

LABEL_3291:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_101, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_102, x=[0x21], y=[0x22]
	break
	mov [0x29], 0x0002

LABEL_32B3:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_103, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_104, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_105, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_106, x=[0x21], y=[0x22]
	break
	djnz [0x29], LABEL_32B3
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	mov [0x96], [0x21]
	mov [0x97], [0x22]
	mov [0x8B], 0x0064
	or [0x8B], 0x8000
	or [0x97], 0x4000

JUMP_TO_LABEL_34D8:
	jmp LABEL_34D8
LABEL_3311:
	db 0x11

LABEL_3312:
	mov [0xF8], [0x11]
	and [0xF8], 0x1000
	jne [0xF8], 0x00, LABEL_339D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_092, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_093, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_094, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_113, x=[0x21], y=[0x22]
	break
	mov [0x29], 0x0001

LABEL_3359:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_098, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_099, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_100, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34D8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_099, x=[0x21], y=[0x22]
	break
	djnz [0x29], LABEL_3359
	jmp LABEL_3291
LABEL_339C:
	db 0x11

LABEL_339D:
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_092, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34F8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_093, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34F8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_094, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34F8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_113, x=[0x21], y=[0x22]
	break
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x29], [0x38]
	add [0x29], 0x0001

LABEL_33DD:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34F8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_098, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34F8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_099, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34F8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_100, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34F8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_099, x=[0x21], y=[0x22]
	break
	djnz [0x29], LABEL_33DD
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34F8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_101, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34F8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_102, x=[0x21], y=[0x22]
	break
	mov [0x29], 0x0001

LABEL_343F:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34F8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_103, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34F8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_104, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34F8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_105, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34F8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_106, x=[0x21], y=[0x22]
	break
	djnz [0x29], LABEL_343F
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_34F8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	mov [0x96], [0x21]
	mov [0x97], [0x22]
	mov [0x8B], 0x0064
	or [0x8B], 0x8000

JUMP_TO_LABEL_34F8:
	jmp LABEL_34F8
LABEL_3499:
	db 0x11

LABEL_349A:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_34A8
	sub [0xF8], 0x2000

LABEL_34A8:
	jl [0xF8], 0x1000, LABEL_34BC
	je [0x2F], 0x05, LABEL_34E9
	je [0x2F], 0x0F, LABEL_354B
	killChannel

LABEL_34BC:
	je [0x2F], 0x05, LABEL_34C9
	je [0x2F], 0x0F, LABEL_3509
	killChannel

LABEL_34C9:
	jl [0x11], 0x2000, LABEL_34D8
	sub [0x11], 0x2000
	call LABEL_7113
	break

LABEL_34D8:
	call LABEL_70E8
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_34D8
LABEL_34E8:
	db 0x11

LABEL_34E9:
	jl [0x11], 0x2000, LABEL_34F8
	sub [0x11], 0x2000
	call LABEL_73A4
	break

LABEL_34F8:
	call LABEL_737E
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_34F8
LABEL_3508:
	db 0x11

LABEL_3509:
	jge [0x11], 0x2000, LABEL_3518
	add [0x11], 0x2000
	call LABEL_7113
	break

LABEL_3518:
	call LABEL_6445
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_3518
LABEL_3528:
	db 0x11

LABEL_3529:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6445
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp LABEL_3529
LABEL_3539:
	db 0x11

LABEL_353A:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6445
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp LABEL_353A
LABEL_354A:
	db 0x11

LABEL_354B:
	jge [0x11], 0x2000, LABEL_355A
	add [0x11], 0x2000
	call LABEL_73A4
	break

LABEL_355A:
	call LABEL_6F95
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_355A
LABEL_356A:
	db 0x11

LABEL_356B:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6F95
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp LABEL_356B
LABEL_357B:
	db 0x11

LABEL_357C:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6F95
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp LABEL_357C
LABEL_358C:
	db 0x11

LABEL_358D:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_35A4
	je [0x2F], 0x10, LABEL_7613
	jmp LABEL_7521

LABEL_35A4:
	je [0x2F], 0x10, LABEL_64C1
	jmp LABEL_67CB
LABEL_35AD:
	db 0x11

LABEL_35AE:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_35C5
	je [0x2F], 0x01, LABEL_7613
	jmp LABEL_3911

LABEL_35C5:
	je [0x2F], 0x02, LABEL_64C1
	jmp LABEL_393C
LABEL_35CE:
	db 0x11

LABEL_35CF:
	mov [0x2F], 0x0001
	jg [0x29], [0x07], LABEL_35AE
	mov [0x2F], 0x0002
	jmp LABEL_35AE

LABEL_35E0:
	jg [0x29], [0x07], LABEL_7521
	jmp LABEL_67CB
LABEL_35E9:
	db 0x11

LABEL_35EA:
	mov [0xF8], [0x11]
	and [0xF8], 0x1000
	jl [0xF8], 0x2000, LABEL_3606
	sub [0xF8], 0x2000
	jl [0xF8], 0x1000, LABEL_34C9
	jmp LABEL_34E9

LABEL_3606:
	jl [0xF8], 0x1000, LABEL_3611
	jmp LABEL_3664
LABEL_3610:
	db 0x11

LABEL_3611:
	call LABEL_7170
	mov [0x29], 0x0005
	mov [0x0E], 0x0004

LABEL_361C:
	break
	call LABEL_719F
	djnz [0x29], LABEL_361C
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	mov [0x22], 0x4008
	jne [HACK_VAR_67], [0x10], LABEL_3637
	call LABEL_4131

LABEL_3637:
	break
	call LABEL_71E0
	break
	call LABEL_71E0
	break
	call LABEL_71B9
	mov [0x29], 0x0005

LABEL_3647:
	break
	call LABEL_719F
	djnz [0x29], LABEL_3647
	mov [0x0E], 0x0000

LABEL_3653:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_70E8
	jmp LABEL_3653
LABEL_3663:
	db 0x11

LABEL_3664:
	call LABEL_73E7
	mov [0x29], 0x0005
	mov [0x0E], 0x0004

LABEL_366F:
	break
	call LABEL_7416
	djnz [0x29], LABEL_366F
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	mov [0x22], 0x0008
	jne [HACK_VAR_67], [0x10], LABEL_368A
	call LABEL_4131

LABEL_368A:
	break
	call LABEL_7457
	break
	call LABEL_7457
	break
	call LABEL_7430
	mov [0x29], 0x0005

LABEL_369A:
	break
	call LABEL_7416
	djnz [0x29], LABEL_369A
	mov [0x0E], 0x0000

LABEL_36A6:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_737E
	jmp LABEL_36A6
LABEL_36B6:
	db 0x11

LABEL_36B7:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_36DE
	sub [0xF8], 0x2000
	jl [0xF8], 0x1000, LABEL_36D5
	je [0x2F], 0x07, LABEL_384B
	jmp LABEL_34E9

LABEL_36D5:
	je [0x2F], 0x07, LABEL_3704
	jmp LABEL_34C9

LABEL_36DE:
	jl [0xF8], 0x1000, LABEL_36F4
	je [0x2F], 0x08, LABEL_387C
	je [0x2F], 0x09, LABEL_38AD
	jmp LABEL_354B

LABEL_36F4:
	je [0x2F], 0x08, LABEL_3735
	je [0x2F], 0x09, LABEL_3774
	jmp LABEL_3509
LABEL_3703:
	db 0x11

LABEL_3704:
	call LABEL_7230
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0028
	sub [0x27], 0x0036
	call LABEL_4407
	break
	call LABEL_724D
	break
	call LABEL_7293
	break
	call LABEL_7230

LABEL_3724:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6445
	jmp LABEL_3724
LABEL_3734:
	db 0x11

LABEL_3735:
	call LABEL_7064
	je [0x29], 0x00, LABEL_3746
	break
	sub [0x29], 0x0001
	jmp LABEL_3735

LABEL_3746:
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0028
	sub [0x27], 0x0029
	call LABEL_4407
	break
	call LABEL_7081
	break
	call LABEL_70CB
	break
	call LABEL_7064

LABEL_3763:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_70E8
	jmp LABEL_3763
LABEL_3773:
	db 0x11

LABEL_3774:
	call LABEL_70AE
	je [0x29], 0x00, LABEL_3785
	break
	sub [0x29], 0x0001
	jmp LABEL_3774

LABEL_3785:
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0019
	sub [0x27], 0x001E
	call LABEL_4407
	break
	call LABEL_7122
	break
	call LABEL_7151
	break
	call LABEL_70AE

LABEL_37A2:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_70E8
	jmp LABEL_37A2
LABEL_37B2:
	db 0x11, 0x04, 0x6F, 0xD7, 0x03, 0x07, 0x00, 0x02
	db 0x0C, 0x14, 0x16, 0x02, 0x08, 0x15, 0x48, 0xE7
	db 0x01, 0x01, 0x07, 0x03, 0x01, 0x00, 0x10, 0x06
	db 0x04, 0x6F, 0xF8, 0x03, 0x07, 0x00, 0x02, 0x06
	db 0x04, 0x70, 0x37, 0x03, 0x07, 0x00, 0x02, 0x06
	db 0x04, 0x70, 0x37, 0x03, 0x07, 0x00, 0x01, 0x06
	db 0x04, 0x70, 0x37, 0x03, 0x07, 0x00, 0x01, 0x06
	db 0x04, 0x70, 0x37, 0x03, 0x07, 0xFF, 0xFE, 0x06
	db 0x04, 0x70, 0x22, 0x03, 0x07, 0xFF, 0xFD, 0x06
	db 0x04, 0x70, 0x0D, 0x06, 0x01, 0x29, 0x07, 0x03
	db 0x29, 0x00, 0x3C, 0x00, 0x2F, 0x00, 0x19, 0x07
	db 0x39, 0x71, 0x11

LABEL_380D:
	call LABEL_7064
	deleteChannels first=0x14, last=0x16
	setup channel=0x3F, address=BREAK_5X_THEN_INIT_VAR03_14
	or [0x04], 0x4000
	mov [0x29], 0x0001

LABEL_3820:
	break
	video offset=CINEMATIC_276, x=[0x07], y=[0x08]
	djnz [0x29], LABEL_3820
	break
	video offset=CINEMATIC_277, x=[0x07], y=[0x08]
	play id=0x005E, freq=0x14, vol=0x40, channel=0x00
	mov [0x29], 0x0003

LABEL_383A:
	break
	video offset=CINEMATIC_277, x=[0x07], y=[0x08]
	djnz [0x29], LABEL_383A
	mov [0x29], 0x0002
	jmp LABEL_3820

LABEL_384B:
	call LABEL_7486
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	add [0x21], 0x0028
	sub [0x27], 0x0036
	call LABEL_4420
	break
	call LABEL_74A0
	break
	call LABEL_74DC
	break
	call LABEL_7486

LABEL_386B:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6F95
	jmp LABEL_386B
LABEL_387B:
	db 0x11

LABEL_387C:
	call LABEL_7326
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	add [0x21], 0x0028
	sub [0x27], 0x0029
	call LABEL_4420
	break
	call LABEL_7338
	break
	call LABEL_736C
	break
	call LABEL_7326

LABEL_389C:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_737E
	jmp LABEL_389C
LABEL_38AC:
	db 0x11

LABEL_38AD:
	call LABEL_735A
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	add [0x21], 0x0019
	sub [0x27], 0x001E
	call LABEL_4420
	break
	call LABEL_73B3
	break
	call LABEL_73D5
	break
	call LABEL_735A

LABEL_38CD:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_737E
	jmp LABEL_38CD
LABEL_38DD:
	db 0x11

LABEL_38DE:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_393C
	jmp LABEL_3911
LABEL_38EF:
	db 0x11

LABEL_38F0:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_3907
	je [0x2F], 0x13, LABEL_3911
	jmp LABEL_355A

LABEL_3907:
	je [0x2F], 0x12, LABEL_393C
	jmp LABEL_3518
LABEL_3910:
	db 0x11

LABEL_3911:
	call LABEL_6FD7
	add [0x07], 0x0001
	break
	call LABEL_72D3
	sub [0x07], 0x0001
	break
	call LABEL_6463
	call AND_VAR11_WITH_EFFF
	sub [0x07], 0x0001

LABEL_392B:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6445
	jmp LABEL_392B
LABEL_393B:
	db 0x11

LABEL_393C:
	call LABEL_6481
	sub [0x07], 0x0001
	break
	call LABEL_72D3
	add [0x07], 0x0001
	break
	call LABEL_6FB6
	call INLINE_OR_VAR11_WITH_1000
	add [0x07], 0x0001

LABEL_3956:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_6F95
	jmp LABEL_3956
LABEL_3966:
	db 0x11
