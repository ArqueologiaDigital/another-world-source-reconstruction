LABEL_4585:
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
	jmp LABEL_4585
LABEL_45A4:
	db 0x11

LABEL_45A5:
	call LABEL_455C
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
	jmp LABEL_45A5
LABEL_45DF:
	db 0x11

LABEL_45E0:
	call LABEL_455C
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
	jmp LABEL_45E0
LABEL_461A:
	db 0x11

LABEL_461B:
	call LABEL_455C
	mov [0x78], [0x07]
	mov [0x79], [0x08]
	mov [0x7A], [0x10]
	mov [0x7B], [0x11]
	mov [0x7D], [0x09]
	mov [0x7C], [0x12]
	mov [0x7E], [0x13]
	mov [0x7F], [0x29]
	break
	jmp LABEL_461B
LABEL_463A:
	db 0x11

COMPUTE_OFFSET_VAR21_22:
	call LABEL_89BB
	mov [0x21], [0x07]
	mov [0x22], [0x08]
	sub [0x21], 0x0023
	sub [0x22], 0x0026
	ret

COMPUTE_OFFSET_PLUS21_MINUS22:
	call LABEL_8C7D
	mov [0x21], [0x07]
	mov [0x22], [0x08]
	add [0x21], 0x0023
	sub [0x22], 0x0026
	ret

LABEL_465F:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_4670
	mov [0x2F], 0x0005
	jmp LABEL_4A6A

LABEL_4670:
	jl [0xF8], 0x1000, LABEL_46BB
	jmp LABEL_467B
LABEL_467A:
	db 0x11

LABEL_467B:
	call LABEL_8CD5
	break
	call LABEL_8C8F
	break
	call LABEL_8CC3
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_058, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_059, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_060, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_075, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_062, x=[0x21], y=[0x08]
	call LABEL_666C
	break
	jmp LABEL_4AC8
LABEL_46BA:
	db 0x11

LABEL_46BB:
	call LABEL_8A3F
	break
	call LABEL_89D8
	break
	call LABEL_8A22
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_058, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_059, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_060, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_061, x=[0x21], y=[0x22]
	break
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_062, x=[0x21], y=[0x08]
	call LABEL_666C
	break
	jmp LABEL_4AA8
	killChannel

LABEL_46FB:
	break
	mov [0x33], 0xFFF6
	jne [0x72], 0x03, LABEL_46FB
	jl [0x70], 0xC8, LABEL_46FB

LABEL_470C:
	jne [HACK_VAR_67], 0x04, LABEL_4720
	call LABEL_477F
	je [0x23], 0x00, LABEL_4763
	video offset=CINEMATIC_064, x=[0x21], y=[0x08]

LABEL_4720:
	break
	jne [HACK_VAR_67], 0x04, LABEL_4735
	call LABEL_477F
	je [0x23], 0x00, LABEL_4763
	video offset=CINEMATIC_065, x=[0x21], y=[0x08]

LABEL_4735:
	break
	jne [HACK_VAR_67], 0x04, LABEL_474A
	call LABEL_477F
	je [0x23], 0x00, LABEL_4763
	video offset=CINEMATIC_066, x=[0x21], y=[0x08]

LABEL_474A:
	break
	jne [HACK_VAR_67], 0x04, LABEL_475F
	call LABEL_477F
	je [0x23], 0x00, LABEL_4763
	video offset=CINEMATIC_065, x=[0x21], y=[0x08]

LABEL_475F:
	break
	jmp LABEL_470C

LABEL_4763:
	call LABEL_477F
	video offset=CINEMATIC_075, x=[0x21], y=[0x08]
	break
	call LABEL_477F
	video offset=CINEMATIC_062, x=[0x21], y=[0x71]
	mov [0x08], [0x71]
	mov [0x10], 0x0004
	call LABEL_666C
	killChannel

LABEL_477F:
	mov [0x08], [0x71]
	sub [0x08], 0x0028
	mov [0x21], [0x33]
	mov [0x23], 0x0001
	jg [0x33], 0x14, LABEL_4798
	add [0x33], 0x0003
	ret

LABEL_4798:
	jl [0x70], 0x0140, SHARED_RET
	mov [0x23], 0x0000
	ret

LABEL_47A4:
	je [0x08], [0x52], LABEL_47D2
	jmp LABEL_47BE

LABEL_47AD:
	break
	mov [0xF8], [0x11]
	and [0xF8], 0x1000
	je [0xF8], 0x00, LABEL_4AE8
	jmp LABEL_4B2A

LABEL_47BE:
	mov [0x08], [0x52]
	sub [0x08], 0x001E
	call LABEL_89AF
	break
	mov [0x08], [0x52]
	call LABEL_89AF
	jmp LABEL_47AD

LABEL_47D2:
	mov [0x08], [0x51]
	add [0x08], 0x001E
	call LABEL_89A3
	break
	mov [0x08], [0x51]
	call LABEL_89A3
	jmp LABEL_47AD
LABEL_47E6:
	db 0x11

LABEL_47E7:
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_058, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_059, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_060, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_061, x=[0x21], y=[0x22]
	break
	mov [0x29], 0x0003

LABEL_4821:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_064, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_065, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_066, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_065, x=[0x21], y=[0x22]
	break
	djnz [0x29], LABEL_4821

LABEL_4861:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_067, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_068, x=[0x21], y=[0x22]
	break
	mov [0x29], 0x0002

LABEL_4883:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_069, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_070, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_071, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_072, x=[0x21], y=[0x22]
	break
	djnz [0x29], LABEL_4883
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	mov [0x96], [0x21]
	mov [0x97], [0x22]
	mov [0x8B], 0x0064
	or [0x8B], 0x8000
	or [0x97], 0x4000

JUMP_TO_LABEL_4AA8:
	jmp LABEL_4AA8
LABEL_48E1:
	db 0x11

LABEL_48E2:
	mov [0xF8], [0x11]
	and [0xF8], 0x1000
	jne [0xF8], 0x00, LABEL_496D
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_058, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_059, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_060, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_061, x=[0x21], y=[0x22]
	break
	mov [0x29], 0x0001

LABEL_4929:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_064, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_065, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_066, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AA8
	call COMPUTE_OFFSET_VAR21_22
	video offset=CINEMATIC_065, x=[0x21], y=[0x22]
	break
	djnz [0x29], LABEL_4929
	jmp LABEL_4861
LABEL_496C:
	db 0x11

LABEL_496D:
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_058, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AC8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_059, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AC8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_060, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AC8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_061, x=[0x21], y=[0x22]
	break
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x29], [0x38]
	add [0x29], 0x0001

LABEL_49AD:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AC8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_064, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AC8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_065, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AC8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_066, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AC8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_065, x=[0x21], y=[0x22]
	break
	djnz [0x29], LABEL_49AD
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AC8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_067, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AC8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_068, x=[0x21], y=[0x22]
	break
	mov [0x29], 0x0001

LABEL_4A0F:
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AC8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_069, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AC8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_070, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AC8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_071, x=[0x21], y=[0x22]
	break
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AC8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	video offset=CINEMATIC_072, x=[0x21], y=[0x22]
	break
	djnz [0x29], LABEL_4A0F
	jne [HACK_VAR_67], [0x10], JUMP_TO_LABEL_4AC8
	call COMPUTE_OFFSET_PLUS21_MINUS22
	mov [0x96], [0x21]
	mov [0x97], [0x22]
	mov [0x8B], 0x0064
	or [0x8B], 0x8000

JUMP_TO_LABEL_4AC8:
	jmp LABEL_4AC8
LABEL_4A69:
	db 0x11

LABEL_4A6A:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_4A78
	sub [0xF8], 0x2000

LABEL_4A78:
	jl [0xF8], 0x1000, LABEL_4A8C
	je [0x2F], 0x05, LABEL_4AB9
	je [0x2F], 0x0F, LABEL_4B1B
	killChannel

LABEL_4A8C:
	je [0x2F], 0x05, LABEL_4A99
	je [0x2F], 0x0F, LABEL_4AD9
	killChannel

LABEL_4A99:
	jl [0x11], 0x2000, LABEL_4AA8
	sub [0x11], 0x2000
	call LABEL_8A6A
	break

LABEL_4AA8:
	call LABEL_8A3F
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_4AA8
LABEL_4AB8:
	db 0x11

LABEL_4AB9:
	jl [0x11], 0x2000, LABEL_4AC8
	sub [0x11], 0x2000
	call LABEL_8CFB
	break

LABEL_4AC8:
	call LABEL_8CD5
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_4AC8
LABEL_4AD8:
	db 0x11

LABEL_4AD9:
	jge [0x11], 0x2000, LABEL_4AE8
	add [0x11], 0x2000
	call LABEL_8A6A
	break

LABEL_4AE8:
	call GUARDED_DRAW_CV_304_305
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_4AE8
LABEL_4AF8:
	db 0x11

GAME_LOOP_CV_304_305:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CV_304_305
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp GAME_LOOP_CV_304_305
LABEL_4B09:
	db 0x11

LABEL_4B0A:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CV_304_305
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp LABEL_4B0A
LABEL_4B1A:
	db 0x11

LABEL_4B1B:
	jge [0x11], 0x2000, LABEL_4B2A
	add [0x11], 0x2000
	call LABEL_8CFB
	break

LABEL_4B2A:
	call GUARDED_ALIEN_ANIM_CV_128
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	jmp LABEL_4B2A
LABEL_4B3A:
	db 0x11

GAME_LOOP_ALIEN_CV128:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_ALIEN_ANIM_CV_128
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp GAME_LOOP_ALIEN_CV128
LABEL_4B4B:
	db 0x11

LABEL_4B4C:
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_ALIEN_ANIM_CV_128
	break
	call STATE_VAR12_BIG_DISPATCH
	jmp LABEL_4B4C
LABEL_4B5C:
	db 0x11

LABEL_4B5D:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_4B74
	je [0x2F], 0x10, LABEL_8F6A
	jmp LABEL_8E78

LABEL_4B74:
	je [0x2F], 0x10, LABEL_7DAC
	jmp LABEL_80C2
LABEL_4B7D:
	db 0x11

LABEL_4B7E:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_4B95
	je [0x2F], 0x01, LABEL_8F6A
	jmp LABEL_4F34

LABEL_4B95:
	je [0x2F], 0x02, LABEL_7DAC
	jmp LABEL_4F5F
LABEL_4B9E:
	db 0x11

LABEL_4B9F:
	mov [0x2F], 0x0001
	jg [0x29], [0x07], LABEL_4B7E
	mov [0x2F], 0x0002
	jmp LABEL_4B7E

LABEL_4BB0:
	jg [0x29], [0x07], LABEL_8E78
	jmp LABEL_80C2
LABEL_4BB9:
	db 0x11

LABEL_4BBA:
	mov [0xF8], [0x11]
	and [0xF8], 0x1000
	jl [0xF8], 0x2000, LABEL_4BD6
	sub [0xF8], 0x2000
	jl [0xF8], 0x1000, LABEL_4A99
	jmp LABEL_4AB9

LABEL_4BD6:
	jl [0xF8], 0x1000, LABEL_4BE1
	jmp LABEL_4C34
LABEL_4BE0:
	db 0x11

LABEL_4BE1:
	call LABEL_8AC7
	mov [0x29], 0x0005
	mov [0x0E], 0x0004

LABEL_4BEC:
	break
	call LABEL_8AF6
	djnz [0x29], LABEL_4BEC
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	mov [0x22], 0x4008
	jne [HACK_VAR_67], [0x10], LABEL_4C07
	call LABEL_5877

LABEL_4C07:
	break
	call LABEL_8B37
	break
	call LABEL_8B37
	break
	call LABEL_8B10
	mov [0x29], 0x0005

LABEL_4C17:
	break
	call LABEL_8AF6
	djnz [0x29], LABEL_4C17
	mov [0x0E], 0x0000

LABEL_4C23:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_8A3F
	jmp LABEL_4C23
LABEL_4C33:
	db 0x11

LABEL_4C34:
	call LABEL_8D3E
	mov [0x29], 0x0005
	mov [0x0E], 0x0004

LABEL_4C3F:
	break
	call LABEL_8D6D
	djnz [0x29], LABEL_4C3F
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	mov [0x22], 0x0008
	jne [HACK_VAR_67], [0x10], LABEL_4C5A
	call LABEL_5877

LABEL_4C5A:
	break
	call LABEL_8DAE
	break
	call LABEL_8DAE
	break
	call LABEL_8D87
	mov [0x29], 0x0005

LABEL_4C6A:
	break
	call LABEL_8D6D
	djnz [0x29], LABEL_4C6A
	mov [0x0E], 0x0000

LABEL_4C76:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_8CD5
	jmp LABEL_4C76
LABEL_4C86:
	db 0x11

LABEL_4C87:
	mov [0xF8], [0x11]
	jl [0xF8], 0x2000, LABEL_4CAE
	sub [0xF8], 0x2000
	jl [0xF8], 0x1000, LABEL_4CA5
	je [0x2F], 0x07, LABEL_4E60
	jmp LABEL_4AB9

LABEL_4CA5:
	je [0x2F], 0x07, LABEL_4CD4
	jmp LABEL_4A99

LABEL_4CAE:
	jl [0xF8], 0x1000, LABEL_4CC4
	je [0x2F], 0x08, LABEL_4E91
	je [0x2F], 0x09, LABEL_4EC2
	jmp LABEL_4B1B

LABEL_4CC4:
	je [0x2F], 0x08, LABEL_4D05
	je [0x2F], 0x09, LABEL_4D44
	jmp LABEL_4AD9
LABEL_4CD3:
	db 0x11

LABEL_4CD4:
	call LABEL_8B87
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0028
	sub [0x27], 0x0036
	call LABEL_5B5C
	break
	call LABEL_8BA4
	break
	call LABEL_8BEA
	break
	call LABEL_8B87

LABEL_4CF4:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CV_304_305
	jmp LABEL_4CF4
LABEL_4D04:
	db 0x11

LABEL_4D05:
	call LABEL_89BB
	je [0x29], 0x00, LABEL_4D16
	break
	sub [0x29], 0x0001
	jmp LABEL_4D05

LABEL_4D16:
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0028
	sub [0x27], 0x0029
	call LABEL_5B5C
	break
	call LABEL_89D8
	break
	call LABEL_8A22
	break
	call LABEL_89BB

LABEL_4D33:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_8A3F
	jmp LABEL_4D33
LABEL_4D43:
	db 0x11

LABEL_4D44:
	call LABEL_8A05
	je [0x29], 0x00, LABEL_4D55
	break
	sub [0x29], 0x0001
	jmp LABEL_4D44

LABEL_4D55:
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x21], 0x0019
	sub [0x27], 0x001E
	call LABEL_5B5C
	break
	call LABEL_8A79
	break
	call LABEL_8AA8
	break
	call LABEL_8A05

LABEL_4D72:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_8A3F
	jmp LABEL_4D72
	killChannel
	call LABEL_88F2
	add [0x07], 0x0002
	deleteChannels first=0x14, last=0x16
	setup channel=0x15, address=LABEL_6051
	mov [0x01], [0x07]
	add [0x01], 0x0010
	break
	call JUNK__8913
	add [0x07], 0x0002
	break
	call LABEL_8952
	add [0x07], 0x0002
	break
	call LABEL_8952
	add [0x07], 0x0001
	break
	call LABEL_8952
	add [0x07], 0x0001
	break
	call LABEL_8952
	sub [0x07], 0x0002
	break
	call LABEL_893D
	sub [0x07], 0x0003
	break
	call LABEL_8928
	break
	mov [0x29], [0x07]
	add [0x29], 0x003C
	mov [0x2F], 0x0019
	jmp DISPATCH_VAR2F_STATE
LABEL_4DDC:
	db 0x11

LABEL_4DDD:
	jg [0x01], 0x07, LABEL_4E21
	call LABEL_89BB
	deleteChannels first=0x14, last=0x16
	setup channel=0x3F, address=BREAK_5X_THEN_INIT_VAR03_14
	or [0x04], 0x4000
	mov [0x29], 0x0001

LABEL_4DF6:
	break
	video offset=CINEMATIC_267, x=[0x07], y=[0x08]
	djnz [0x29], LABEL_4DF6
	break
	video offset=CINEMATIC_268, x=[0x07], y=[0x08]
	play id=0x005E, freq=0x14, vol=0x40, channel=0x00
	mov [0x29], 0x0003

LABEL_4E10:
	break
	video offset=CINEMATIC_268, x=[0x07], y=[0x08]
	djnz [0x29], LABEL_4E10
	mov [0x29], 0x0002
	jmp LABEL_4DF6

LABEL_4E21:
	call LABEL_8C7D

LABEL_4E24:
	deleteChannels first=0x14, last=0x16
	setup channel=0x3F, address=BREAK_5X_THEN_INIT_VAR03_14
	or [0x04], 0x4000
	mov [0x29], 0x0001

LABEL_4E34:
	break
	video offset=CINEMATIC_265, x=[0x07], y=[0x08]
	djnz [0x29], LABEL_4E34
	break
	video offset=CINEMATIC_266, x=[0x07], y=[0x08]
	play id=0x005E, freq=0x14, vol=0x40, channel=0x00
	mov [0x29], 0x0003

LABEL_4E4E:
	break
	video offset=CINEMATIC_266, x=[0x07], y=[0x08]
	djnz [0x29], LABEL_4E4E
	mov [0x29], 0x0002
	jmp LABEL_4E34
LABEL_4E5F:
	db 0x11

LABEL_4E60:
	call LABEL_8DDD
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	add [0x21], 0x0028
	sub [0x27], 0x0036
	call LABEL_5B75
	break
	call LABEL_8DF7
	break
	call LABEL_8E33
	break
	call LABEL_8DDD

LABEL_4E80:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_ALIEN_ANIM_CV_128
	jmp LABEL_4E80
LABEL_4E90:
	db 0x11

LABEL_4E91:
	call LABEL_8C7D
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	add [0x21], 0x0028
	sub [0x27], 0x0029
	call LABEL_5B75
	break
	call LABEL_8C8F
	break
	call LABEL_8CC3
	break
	call LABEL_8C7D

LABEL_4EB1:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_8CD5
	jmp LABEL_4EB1
LABEL_4EC1:
	db 0x11

LABEL_4EC2:
	call LABEL_8CB1
	je [0x29], 0x00, LABEL_4ED3
	break
	sub [0x29], 0x0001
	jmp LABEL_4EC2

LABEL_4ED3:
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	add [0x21], 0x0019
	sub [0x27], 0x001E
	call LABEL_5B75
	break
	call LABEL_8D0A
	break
	call LABEL_8D2C
	break
	call LABEL_8CB1

LABEL_4EF0:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call LABEL_8CD5
	jmp LABEL_4EF0
LABEL_4F00:
	db 0x11

LABEL_4F01:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_4F5F
	jmp LABEL_4F34
LABEL_4F12:
	db 0x11

LABEL_4F13:
	mov [0xF8], [0x11]
	and [0xF8], 0x1FFF
	jl [0xF8], 0x1000, LABEL_4F2A
	je [0x2F], 0x13, LABEL_4F34
	jmp LABEL_4B2A

LABEL_4F2A:
	je [0x2F], 0x12, LABEL_4F5F
	jmp LABEL_4AE8
LABEL_4F33:
	db 0x11

LABEL_4F34:
	call LABEL_88F2
	add [0x07], 0x0001
	break
	call LABEL_8C2A
	sub [0x07], 0x0001
	break
	call LABEL_7CDA
	call AND_VAR11_WITH_EFFF
	sub [0x07], 0x0001

LABEL_4F4E:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_DRAW_CV_304_305
	jmp LABEL_4F4E
LABEL_4F5E:
	db 0x11

LABEL_4F5F:
	call LABEL_7CF8
	sub [0x07], 0x0001
	break
	call LABEL_8C2A
	add [0x07], 0x0001
	break
	call LABEL_88D1
	call INLINE_OR_VAR11_WITH_1000
	add [0x07], 0x0001

LABEL_4F79:
	break
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	call GUARDED_ALIEN_ANIM_CV_128
	jmp LABEL_4F79
LABEL_4F89:
	db 0x11
