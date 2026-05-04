LABEL_4561:
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
	jmp LABEL_4561
LABEL_4580:
	db 0x11

LABEL_4581:
	call LABEL_4538
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
	jmp LABEL_4581
LABEL_45BB:
	db 0x11

LABEL_45BC:
	call LABEL_4538
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
	jmp LABEL_45BC
LABEL_45F6:
	db 0x11

LABEL_45F7:
	call LABEL_4538
	mov [0x78], [0x07]
	mov [0x79], [0x08]
	mov [0x7A], [0x10]
	mov [0x7B], [0x11]
	mov [0x7D], [0x09]
	mov [0x7C], [0x12]
	mov [0x7E], [0x13]
	mov [0x7F], [0x29]
	break
	jmp LABEL_45F7
LABEL_4616:
	db 0x11

COMPUTE_OFFSET_VAR21_22:
	call LABEL_8A24
	mov [0x21], [0x07]
	mov [0x22], [0x08]
	sub [0x21], 0x0023
	sub [0x22], 0x0026
	ret

COMPUTE_OFFSET_PLUS21_MINUS22:
	call LABEL_8CE6
	mov [0x21], [0x07]
	mov [0x22], [0x08]
	add [0x21], 0x0023
	sub [0x22], 0x0026
	ret

LABEL_463B:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_464C
	mov [0x2F], 0x0005
	jmp LABEL_4A46

LABEL_464C:
	jl [0xF8], 0x1000, LABEL_4697
	jmp LABEL_4657
LABEL_4656:
	db 0x11

LABEL_4657:
	call LABEL_8D3E
	break
	call LABEL_8CF8
	break
	call LABEL_8D2C
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_058, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_059, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_060, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_075, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_062, x=[0x21], y=[0x08], zoom=0x40
	call LABEL_6675
	break
	jmp LABEL_4AA4
LABEL_4696:
	db 0x11

LABEL_4697:
	call LABEL_8AA8
	break
	call LABEL_8A41
	break
	call LABEL_8A8B
	break
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_058, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_059, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_060, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_061, x=[0x21], y=[0x22], zoom=0x40
	break
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_062, x=[0x21], y=[0x08], zoom=0x40
	call LABEL_6675
	break
	jmp LABEL_4A84
	killChannel

LABEL_46D7:
	break
	mov [0x33], 0xFFF6
	jne [0x72], 0x03, LABEL_46D7
	jl [0x70], 0xC8, LABEL_46D7

LABEL_46E8:
	jne [HACK_VAR_67], 0x04, LABEL_46FC
	call LABEL_475B
	je [0x23], 0x00, LABEL_473F
	video type=1, offset=CINEMATIC_064, x=[0x21], y=[0x08], zoom=0x40

LABEL_46FC:
	break
	jne [HACK_VAR_67], 0x04, LABEL_4711
	call LABEL_475B
	je [0x23], 0x00, LABEL_473F
	video type=1, offset=CINEMATIC_065, x=[0x21], y=[0x08], zoom=0x40

LABEL_4711:
	break
	jne [HACK_VAR_67], 0x04, LABEL_4726
	call LABEL_475B
	je [0x23], 0x00, LABEL_473F
	video type=1, offset=CINEMATIC_066, x=[0x21], y=[0x08], zoom=0x40

LABEL_4726:
	break
	jne [HACK_VAR_67], 0x04, LABEL_473B
	call LABEL_475B
	je [0x23], 0x00, LABEL_473F
	video type=1, offset=CINEMATIC_065, x=[0x21], y=[0x08], zoom=0x40

LABEL_473B:
	break
	jmp LABEL_46E8

LABEL_473F:
	call LABEL_475B
	video type=1, offset=CINEMATIC_075, x=[0x21], y=[0x08], zoom=0x40
	break
	call LABEL_475B
	video type=1, offset=CINEMATIC_062, x=[0x21], y=[0x71], zoom=0x40
	mov [0x08], [0x71]
	mov [0x10], 0x0004
	call LABEL_6675
	killChannel

LABEL_475B:
	mov [0x08], [0x71]
	sub [0x08], 0x0028
	mov [0x21], [0x33]
	mov [0x23], 0x0001
	jg [0x33], 0x14, LABEL_4774
	add [0x33], 0x0003
	ret

LABEL_4774:
	jl [0x70], 0x0140, SHARED_RET
	mov [0x23], 0x0000
	ret

LABEL_4780:
	je [0x08], [0x52], LABEL_47AE
	jmp LABEL_479A

LABEL_4789:
	break
	mov [0xF8], [0x11]
	and [0xF8], 0x1000
	je [0xF8], 0x00, LABEL_4AC4
	jmp LABEL_4B06

LABEL_479A:
	mov [0x08], [0x52]
	sub [0x08], 0x001E
	call LABEL_8A18
	break
	mov [0x08], [0x52]
	call LABEL_8A18
	jmp LABEL_4789

LABEL_47AE:
	mov [0x08], [0x51]
	add [0x08], 0x001E
	call LABEL_8A0C
	break
	mov [0x08], [0x51]
	call LABEL_8A0C
	jmp LABEL_4789
LABEL_47C2:
	db 0x11

LABEL_47C3:
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_058, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_059, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_060, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_061, x=[0x21], y=[0x22], zoom=0x40
	break
	mov [0x29], 0x0003

LABEL_47FD:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_064, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_065, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_066, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_065, x=[0x21], y=[0x22], zoom=0x40
	break
	djnz [0x29], LABEL_47FD

LABEL_483D:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_067, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_068, x=[0x21], y=[0x22], zoom=0x40
	break
	mov [0x29], 0x0002

LABEL_485F:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_069, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_070, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_071, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_072, x=[0x21], y=[0x22], zoom=0x40
	break
	djnz [0x29], LABEL_485F
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	mov [0x96], [0x21]
	mov [0x97], [0x22]
	mov [0x8B], 0x0064
	or [0x8B], 0x8000
	or [0x97], 0x4000

JUMP_TO_LABEL_4A84:
	jmp LABEL_4A84
LABEL_48BD:
	db 0x11

LABEL_48BE:
	mov [0xF8], [0x11]
	and [0xF8], 0x1000
	jne [0xF8], 0x00, LABEL_4949
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_058, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_059, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_060, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_061, x=[0x21], y=[0x22], zoom=0x40
	break
	mov [0x29], 0x0001

LABEL_4905:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_064, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_065, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_066, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4A84
	call COMPUTE_OFFSET_VAR21_22
	video type=1, offset=CINEMATIC_065, x=[0x21], y=[0x22], zoom=0x40
	break
	djnz [0x29], LABEL_4905
	jmp LABEL_483D
LABEL_4948:
	db 0x11

LABEL_4949:
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_058, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA4
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_059, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA4
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_060, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA4
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_061, x=[0x21], y=[0x22], zoom=0x40
	break
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x29], [0x38]
	add [0x29], 0x0001

LABEL_4989:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA4
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_064, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA4
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_065, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA4
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_066, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA4
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_065, x=[0x21], y=[0x22], zoom=0x40
	break
	djnz [0x29], LABEL_4989
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA4
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_067, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA4
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_068, x=[0x21], y=[0x22], zoom=0x40
	break
	mov [0x29], 0x0001

LABEL_49EB:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA4
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_069, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA4
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_070, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA4
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_071, x=[0x21], y=[0x22], zoom=0x40
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA4
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video type=1, offset=CINEMATIC_072, x=[0x21], y=[0x22], zoom=0x40
	break
	djnz [0x29], LABEL_49EB
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA4
	call COMPUTE_OFFSET_PLUS21_MINUS22
	mov [0x96], [0x21]
	mov [0x97], [0x22]
	mov [0x8B], 0x0064
	or [0x8B], 0x8000

JUMP_TO_LABEL_4AA4:
	jmp LABEL_4AA4
LABEL_4A45:
	db 0x11

LABEL_4A46:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_4A54
	sub [0xF8], 0x2000

LABEL_4A54:
	jl [0xF8], 0x1000, LABEL_4A68
	je [0x2F], 0x05, LABEL_4A95
	je [0x2F], 0x0F, LABEL_4AF7
	killChannel

LABEL_4A68:
	je [0x2F], 0x05, LABEL_4A75
	je [0x2F], 0x0F, LABEL_4AB5
	killChannel

LABEL_4A75:
	jl [0x11], 0x2000, LABEL_4A84
	sub [0x11], 0x2000
	call LABEL_8AD3
	break

LABEL_4A84:
	call LABEL_8AA8
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_4A84
LABEL_4A94:
	db 0x11

LABEL_4A95:
	jl [0x11], 0x2000, LABEL_4AA4
	sub [0x11], 0x2000
	call LABEL_8D64
	break

LABEL_4AA4:
	call LABEL_8D3E
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_4AA4
LABEL_4AB4:
	db 0x11

LABEL_4AB5:
	jge [0x11], 0x2000, LABEL_4AC4
	add [0x11], 0x2000
	call LABEL_8AD3
	break

LABEL_4AC4:
	call GUARDED_DRAW_CV_304_305
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_4AC4
LABEL_4AD4:
	db 0x11

GAME_LOOP_CV_304_305:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CV_304_305
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp GAME_LOOP_CV_304_305
LABEL_4AE5:
	db 0x11

LABEL_4AE6:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CV_304_305
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp LABEL_4AE6
LABEL_4AF6:
	db 0x11

LABEL_4AF7:
	jge [0x11], 0x2000, LABEL_4B06
	add [0x11], 0x2000
	call LABEL_8D64
	break

LABEL_4B06:
	call GUARDED_ALIEN_ANIM_CV_128
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_4B06
LABEL_4B16:
	db 0x11

GAME_LOOP_ALIEN_CV128:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_ALIEN_ANIM_CV_128
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp GAME_LOOP_ALIEN_CV128
LABEL_4B27:
	db 0x11

LABEL_4B28:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_ALIEN_ANIM_CV_128
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp LABEL_4B28
LABEL_4B38:
	db 0x11

LABEL_4B39:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_4B50
	je [0x2F], 0x10, LABEL_8FD3
	jmp LABEL_8EE1

LABEL_4B50:
	je [0x2F], 0x10, LABEL_7E15
	jmp LABEL_812B
LABEL_4B59:
	db 0x11

LABEL_4B5A:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_4B71
	je [0x2F], 0x01, LABEL_8FD3
	jmp LABEL_4F10

LABEL_4B71:
	je [0x2F], 0x02, LABEL_7E15
	jmp LABEL_4F3B
LABEL_4B7A:
	db 0x11

LABEL_4B7B:
	mov [0x2F], 0x0001
	jg [0x29], [0x07], LABEL_4B5A
	mov [0x2F], 0x0002
	jmp LABEL_4B5A

LABEL_4B8C:
	jg [0x29], [0x07], LABEL_8EE1
	jmp LABEL_812B
LABEL_4B95:
	db 0x11

LABEL_4B96:
	mov [0xF8], [0x11]
	and [0xF8], 0x1000
	jl [0xF8], 0x2000, LABEL_4BB2
	sub [0xF8], 0x2000
	jl [0xF8], 0x1000, LABEL_4A75
	jmp LABEL_4A95

LABEL_4BB2:
	jl [0xF8], 0x1000, LABEL_4BBD
	jmp LABEL_4C10
LABEL_4BBC:
	db 0x11

LABEL_4BBD:
	call LABEL_8B30
	mov [0x29], 0x0005
	mov [0x0E], 0x0004

LABEL_4BC8:
	break
	call LABEL_8B5F
	djnz [0x29], LABEL_4BC8
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	mov [0x22], 0x4008
	jne [HACK_VAR_67], [0x10], LABEL_4BE3
	call LABEL_5867

LABEL_4BE3:
	break
	call LABEL_8BA0
	break
	call LABEL_8BA0
	break
	call LABEL_8B79
	mov [0x29], 0x0005

LABEL_4BF3:
	break
	call LABEL_8B5F
	djnz [0x29], LABEL_4BF3
	mov [0x0E], 0x0000

LABEL_4BFF:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_8AA8
	jmp LABEL_4BFF
LABEL_4C0F:
	db 0x11

LABEL_4C10:
	call LABEL_8DA7
	mov [0x29], 0x0005
	mov [0x0E], 0x0004

LABEL_4C1B:
	break
	call LABEL_8DD6
	djnz [0x29], LABEL_4C1B
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	mov [0x22], 0x0008
	jne [HACK_VAR_67], [0x10], LABEL_4C36
	call LABEL_5867

LABEL_4C36:
	break
	call LABEL_8E17
	break
	call LABEL_8E17
	break
	call LABEL_8DF0
	mov [0x29], 0x0005

LABEL_4C46:
	break
	call LABEL_8DD6
	djnz [0x29], LABEL_4C46
	mov [0x0E], 0x0000

LABEL_4C52:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_8D3E
	jmp LABEL_4C52
LABEL_4C62:
	db 0x11

LABEL_4C63:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_4C8A
	sub [0xF8], 0x2000
	jl [0xF8], 0x1000, LABEL_4C81
	je [0x2F], 0x07, LABEL_4E3C
	jmp LABEL_4A95

LABEL_4C81:
	je [0x2F], 0x07, LABEL_4CB0
	jmp LABEL_4A75

LABEL_4C8A:
	jl [0xF8], 0x1000, LABEL_4CA0
	je [0x2F], 0x08, LABEL_4E6D
	je [0x2F], 0x09, LABEL_4E9E
	jmp LABEL_4AF7

LABEL_4CA0:
	je [0x2F], 0x08, LABEL_4CE1
	je [0x2F], 0x09, LABEL_4D20
	jmp LABEL_4AB5
LABEL_4CAF:
	db 0x11

LABEL_4CB0:
	call LABEL_8BF0
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0028
	sub [0x27], 0x0036
	call LABEL_5B5D
	break
	call LABEL_8C0D
	break
	call LABEL_8C53
	break
	call LABEL_8BF0

LABEL_4CD0:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CV_304_305
	jmp LABEL_4CD0
LABEL_4CE0:
	db 0x11

LABEL_4CE1:
	call LABEL_8A24
	je [0x29], 0x00, LABEL_4CF2
	break
	sub [0x29], 0x0001
	jmp LABEL_4CE1

LABEL_4CF2:
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0028
	sub [0x27], 0x0029
	call LABEL_5B5D
	break
	call LABEL_8A41
	break
	call LABEL_8A8B
	break
	call LABEL_8A24

LABEL_4D0F:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_8AA8
	jmp LABEL_4D0F
LABEL_4D1F:
	db 0x11

LABEL_4D20:
	call LABEL_8A6E
	je [0x29], 0x00, LABEL_4D31
	break
	sub [0x29], 0x0001
	jmp LABEL_4D20

LABEL_4D31:
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0019
	sub [0x27], 0x001E
	call LABEL_5B5D
	break
	call LABEL_8AE2
	break
	call LABEL_8B11
	break
	call LABEL_8A6E

LABEL_4D4E:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_8AA8
	jmp LABEL_4D4E
	killChannel
	call LABEL_895B
	add [0x07], 0x0002
	deleteChannels first=0x14, last=0x16
	setup channel=0x15, address=LABEL_605A
	mov [0x01], [0x07]
	add [0x01], 0x0010
	break
	call JUNK__897C
	add [0x07], 0x0002
	break
	call LABEL_89BB
	add [0x07], 0x0002
	break
	call LABEL_89BB
	add [0x07], 0x0001
	break
	call LABEL_89BB
	add [0x07], 0x0001
	break
	call LABEL_89BB
	sub [0x07], 0x0002
	break
	call LABEL_89A6
	sub [0x07], 0x0003
	break
	call LABEL_8991
	break
	mov [0x29], [0x07]
	add [0x29], 0x003C
	mov [0x2F], 0x0019
	jmp DISPATCH_VAR2F_STATE
LABEL_4DB8:
	db 0x11

LABEL_4DB9:
	jg [0x01], 0x07, LABEL_4DFD
	call LABEL_8A24
	deleteChannels first=0x14, last=0x16
	setup channel=0x3F, address=BREAK_5X_THEN_INIT_VAR03_14
	or [0x04], 0x4000
	mov [0x29], 0x0001

LABEL_4DD2:
	break
	video type=1, offset=CINEMATIC_268, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x29], LABEL_4DD2
	break
	video type=1, offset=CINEMATIC_269, x=[0x07], y=[0x08], zoom=0x40
	play id=0x005E, freq=0x14, vol=0x40, channel=0x00
	mov [0x29], 0x0003

LABEL_4DEC:
	break
	video type=1, offset=CINEMATIC_269, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x29], LABEL_4DEC
	mov [0x29], 0x0002
	jmp LABEL_4DD2

LABEL_4DFD:
	call LABEL_8CE6

LABEL_4E00:
	deleteChannels first=0x14, last=0x16
	setup channel=0x3F, address=BREAK_5X_THEN_INIT_VAR03_14
	or [0x04], 0x4000
	mov [0x29], 0x0001

LABEL_4E10:
	break
	video type=1, offset=CINEMATIC_266, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x29], LABEL_4E10
	break
	video type=1, offset=CINEMATIC_267, x=[0x07], y=[0x08], zoom=0x40
	play id=0x005E, freq=0x14, vol=0x40, channel=0x00
	mov [0x29], 0x0003

LABEL_4E2A:
	break
	video type=1, offset=CINEMATIC_267, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x29], LABEL_4E2A
	mov [0x29], 0x0002
	jmp LABEL_4E10
LABEL_4E3B:
	db 0x11

LABEL_4E3C:
	call LABEL_8E46
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	add [0x21], 0x0028
	sub [0x27], 0x0036
	call LABEL_5B54
	break
	call LABEL_8E60
	break
	call LABEL_8E9C
	break
	call LABEL_8E46

LABEL_4E5C:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_ALIEN_ANIM_CV_128
	jmp LABEL_4E5C
LABEL_4E6C:
	db 0x11

LABEL_4E6D:
	call LABEL_8CE6
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	add [0x21], 0x0028
	sub [0x27], 0x0029
	call LABEL_5B54
	break
	call LABEL_8CF8
	break
	call LABEL_8D2C
	break
	call LABEL_8CE6

LABEL_4E8D:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_8D3E
	jmp LABEL_4E8D
LABEL_4E9D:
	db 0x11

LABEL_4E9E:
	call LABEL_8D1A
	je [0x29], 0x00, LABEL_4EAF
	break
	sub [0x29], 0x0001
	jmp LABEL_4E9E

LABEL_4EAF:
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	add [0x21], 0x0019
	sub [0x27], 0x001E
	call LABEL_5B54
	break
	call LABEL_8D73
	break
	call LABEL_8D95
	break
	call LABEL_8D1A

LABEL_4ECC:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_8D3E
	jmp LABEL_4ECC
LABEL_4EDC:
	db 0x11

LABEL_4EDD:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_4F3B
	jmp LABEL_4F10
LABEL_4EEE:
	db 0x11

LABEL_4EEF:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_4F06
	je [0x2F], 0x13, LABEL_4F10
	jmp LABEL_4B06

LABEL_4F06:
	je [0x2F], 0x12, LABEL_4F3B
	jmp LABEL_4AC4
LABEL_4F0F:
	db 0x11

LABEL_4F10:
	call LABEL_895B
	add [0x07], 0x0001
	break
	call LABEL_8C93
	sub [0x07], 0x0001
	break
	call LABEL_7D43
	call AND_VAR11_WITH_EFFF
	sub [0x07], 0x0001

LABEL_4F2A:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CV_304_305
	jmp LABEL_4F2A
LABEL_4F3A:
	db 0x11

LABEL_4F3B:
	call LABEL_7D61
	sub [0x07], 0x0001
	break
	call LABEL_8C93
	add [0x07], 0x0001
	break
	call LABEL_893A
	call INLINE_OR_VAR11_WITH_1000
	add [0x07], 0x0001

LABEL_4F55:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_ALIEN_ANIM_CV_128
	jmp LABEL_4F55
LABEL_4F65:
	db 0x11
