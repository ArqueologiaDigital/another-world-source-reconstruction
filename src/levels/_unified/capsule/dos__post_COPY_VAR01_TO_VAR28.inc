LABEL_7491:
	mov [0x21], [0x28]
	sub [0x22], [0x2A]
	call LABEL_74B9
	add [0x22], [0x2A]
	jle [0x22], [HERO_X], COPY_VAR01_TO_VAR28
	mov [HERO_X], [0x22]
	mov [0x28], [HERO_X]
	ret
LABEL_74AA:
	db 0x11

LABEL_74AB:
	mov [0x23], 0x0000
	jg [0x27], [0x44], LABEL_74B9
	mov [0x23], 0x0001

LABEL_74B9:
	jl [0x22], [0x21], LABEL_750A
	je [0x23], 0x00, LABEL_74D5
	jg [0x47], [0x22], LABEL_74E2
	mov [0x22], [0x47]
	mov [0x1D], 0x0004
	jmp LABEL_74E2

LABEL_74D5:
	jg [0x43], [0x22], LABEL_74E2
	mov [0x22], [0x43]
	mov [0x1D], 0x0002

LABEL_74E2:
	mov [0x24], [0x48]
	mov [0x25], [0x49]
	mov [0x1C], 0x000A
	call LABEL_75D9
	mov [0x24], [0x4A]
	mov [0x25], [0x4B]
	mov [0x1C], 0x000B
	call LABEL_75D9
	mov [0x24], [0x4C]
	mov [0x25], [0x4D]
	mov [0x1C], 0x000C
	call LABEL_75D9
	ret

LABEL_750A:
	je [0x23], 0x00, LABEL_7520
	jl [0x46], [0x22], LABEL_752D
	mov [0x22], [0x46]
	mov [0x1D], 0x0003
	jmp LABEL_752D

LABEL_7520:
	jl [0x42], [0x22], LABEL_752D
	mov [0x22], [0x42]
	mov [0x1D], 0x0001

LABEL_752D:
	mov [0x24], [0x48]
	mov [0x25], [0x49]
	mov [0x1C], 0x000A
	call LABEL_7555
	mov [0x24], [0x4A]
	mov [0x25], [0x4B]
	mov [0x1C], 0x000B
	call LABEL_7555
	mov [0x24], [0x4C]
	mov [0x25], [0x4D]
	mov [0x1C], 0x000C
	call LABEL_7555
	ret

LABEL_7555:
	jge [0x25], 0x2000, LABEL_75D8
	jge [0x25], 0x1000, LABEL_756C
	je [0x23], 0x01, LABEL_75D8
	jmp LABEL_7576

LABEL_756C:
	sub [0x25], 0x1000
	je [0x23], 0x00, LABEL_75D8

LABEL_7576:
	add [0x24], 0x0008
	jl [0x25], 0x0200, LABEL_7597
	sub [0x25], 0x0200
	jg [0x24], [0x21], LABEL_75D8
	jl [0x24], [0x22], LABEL_7597
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

LABEL_7597:
	add [0x24], 0x000A
	jl [0x25], 0x0100, LABEL_75B8
	sub [0x25], 0x0100
	jg [0x24], [0x21], LABEL_75D8
	jl [0x24], [0x22], LABEL_75B8
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

LABEL_75B8:
	add [0x24], 0x000A
	jl [0x25], 0x80, LABEL_75D8
	sub [0x25], 0x0080
	jg [0x24], [0x21], LABEL_75D8
	jl [0x24], [0x22], LABEL_75D8
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

LABEL_75D8:
	ret

LABEL_75D9:
	jge [0x25], 0x2000, LABEL_7646
	jge [0x25], 0x1000, LABEL_75F0
	je [0x23], 0x01, LABEL_7646
	jmp LABEL_75FA

LABEL_75F0:
	sub [0x25], 0x1000
	je [0x23], 0x00, LABEL_7646

LABEL_75FA:
	jl [0x25], 0x0200, LABEL_7610
	jl [0x24], [0x21], LABEL_7610
	jg [0x24], [0x22], LABEL_7610
	jmp LABEL_7640

LABEL_7610:
	add [0x24], 0x000A
	jl [0x25], 0x0100, LABEL_762A
	jl [0x24], [0x21], LABEL_762A
	jg [0x24], [0x22], LABEL_762A
	jmp LABEL_7640

LABEL_762A:
	add [0x24], 0x000A
	jl [0x25], 0x80, LABEL_7646
	jl [0x24], [0x21], LABEL_7646
	jg [0x24], [0x22], LABEL_7646

LABEL_7640:
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

LABEL_7646:
	ret

DRAW_HERO_SPRITE_BY_VAR09_0E:
	mov [0xF8], [0x09]
	shr [0xF8], 0x0004
	and [0xF8], 0x000F
	jne [0x0E], 0x00, LABEL_7689
	je [0xF8], 0x00, DRAW_CIN_022
	je [0xF8], 0x01, DRAW_CIN_023
	je [0xF8], 0x02, DRAW_CIN_024
	je [0xF8], 0x03, DRAW_CIN_025
	je [0xF8], 0x04, DRAW_CIN_026
	je [0xF8], 0x05, DRAW_CIN_027
	je [0xF8], 0x06, DRAW_CIN_028
	je [0xF8], 0x07, DRAW_CIN_029
	ret

LABEL_7689:
	jne [0x0E], 0x01, LABEL_7692
	jmp DRAW_CIN_021

LABEL_7692:
	jne [0x0E], 0x02, LABEL_769B
	jmp DRAW_CIN_020

LABEL_769B:
	jne [0x0E], 0x03, LABEL_76AA
	je [0xF8], 0x03, DRAW_CIN_015
	jmp DRAW_CIN_019

LABEL_76AA:
	jne [0x0E], 0x04, LABEL_76B9
	je [0xF8], 0x03, DRAW_CIN_017
	jmp DRAW_CIN_018

LABEL_76B9:
	jne [0x0E], 0x05, LABEL_76C8
	je [0xF8], 0x03, DRAW_CIN_015
	jmp DRAW_CIN_016

LABEL_76C8:
	jne [0x0E], 0x06, LABEL_76D4
	video offset=CINEMATIC_014, x=[0x07], y=[0x08]
	ret

LABEL_76D4:
	jne [0x0E], 0x07, LABEL_76E7
	je [0xF8], 0x00, DRAW_CIN_012
	je [0xF8], 0x01, DRAW_CIN_013
	ret

LABEL_76E7:
	ret
LABEL_76E8:
	db 0x11

DRAW_CIN_022:
	video offset=CINEMATIC_022, x=[0x07], y=[0x08]
	ret

DRAW_CIN_023:
	video offset=CINEMATIC_023, x=[0x07], y=[0x08]
	ret

DRAW_CIN_024:
	video offset=CINEMATIC_024, x=[0x07], y=[0x08]
	ret

DRAW_CIN_025:
	video offset=CINEMATIC_025, x=[0x07], y=[0x08]
	ret

DRAW_CIN_026:
	video offset=CINEMATIC_026, x=[0x07], y=[0x08]
	ret

DRAW_CIN_027:
	video offset=CINEMATIC_027, x=[0x07], y=[0x08]
	ret

DRAW_CIN_028:
	video offset=CINEMATIC_028, x=[0x07], y=[0x08]
	ret

DRAW_CIN_029:
	video offset=CINEMATIC_029, x=[0x07], y=[0x08]
	ret

DRAW_CIN_021:
	video offset=CINEMATIC_021, x=[0x07], y=[0x08]
	ret

DRAW_CIN_020:
	video offset=CINEMATIC_020, x=[0x07], y=[0x08]
	ret

DRAW_CIN_019:
	video offset=CINEMATIC_019, x=[0x07], y=[0x08]
	ret

DRAW_CIN_015:
	video offset=CINEMATIC_015, x=[0x07], y=[0x08]
	ret

DRAW_CIN_018:
	video offset=CINEMATIC_018, x=[0x07], y=[0x08]
	ret

DRAW_CIN_017:
	video offset=CINEMATIC_017, x=[0x07], y=[0x08]
	ret

DRAW_CIN_016:
	video offset=CINEMATIC_016, x=[0x07], y=[0x08]
	ret

DRAW_CIN_012:
	video offset=CINEMATIC_012, x=[0x07], y=[0x08]
	ret

DRAW_CIN_013:
	video offset=CINEMATIC_013, x=[0x07], y=[0x08]
	ret

LABEL_774F:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_246
	je [0xF8], 0x02, DRAW_CIN_247
	ret

DRAW_CIN_246:
	video offset=CINEMATIC_246, x=[0xf5], y=[0x08]
	ret

DRAW_CIN_247:
	video offset=CINEMATIC_247, x=[0xf5], y=[0x08]
	ret

LABEL_776F:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, LABEL_7783
	je [0xF8], 0x02, LABEL_7799
	ret

LABEL_7783:
	add [0x08], 0x000D
	sub [0x07], 0x0002
	video offset=CINEMATIC_111, x=[0x07], y=[0x08]
	add [0x07], 0x0002
	sub [0x08], 0x000D
	ret

LABEL_7799:
	add [0x08], 0x000D
	sub [0x07], 0x0002
	video offset=CINEMATIC_112, x=[0x07], y=[0x08]
	add [0x07], 0x0002
	sub [0x08], 0x000D
	ret

LABEL_77AF:
	video type=0, offset=COMMON_VIDEO_320, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, LABEL_77C2
	video type=0, offset=COMMON_VIDEO_322, x=[0x07], y=[0x08], zoom=0x40

LABEL_77C2:
	jg [0x13], [0x30], LABEL_774F
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_774F
	video type=0, offset=COMMON_VIDEO_321, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_774F

LABEL_77DD:
	video type=0, offset=COMMON_VIDEO_323, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, LABEL_77F4
	video type=0, offset=COMMON_VIDEO_325, x=[0x07], y=[0x08], zoom=0x40

LABEL_77F4:
	jg [0x13], [0x30], LABEL_774F
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_774F
	video type=0, offset=COMMON_VIDEO_324, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_774F

LABEL_780F:
	video type=0, offset=COMMON_VIDEO_326, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], LABEL_776F
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_776F
	video type=0, offset=COMMON_VIDEO_327, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_776F

LABEL_782F:
	video type=0, offset=COMMON_VIDEO_328, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_776F

LABEL_7837:
	sub [0x07], 0x0001
	call LABEL_7843
	add [0x07], 0x0001
	ret

LABEL_7843:
	video type=0, offset=COMMON_VIDEO_308, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_309, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_7861:
	sub [0x07], 0x0001
	call LABEL_786D
	add [0x07], 0x0001
	ret

LABEL_786D:
	video type=0, offset=COMMON_VIDEO_306, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_307, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CV_304_THEN_305:
	video type=0, offset=COMMON_VIDEO_304, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_305, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_78A9:
	add [0x07], 0x0001
	call DRAW_CV_304_THEN_305
	sub [0x07], 0x0001
	ret

SHARED_RET:
	ret

DRAW_CIN_030_031_032_VAR09:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_030
	je [0xF8], 0x02, DRAW_CIN_031
	je [0xF8], 0x03, DRAW_CIN_032
	ret

DRAW_CIN_030:
	video offset=CINEMATIC_030, x=[0x07], y=[0x08]
	ret

DRAW_CIN_031:
	video offset=CINEMATIC_031, x=[0x07], y=[0x08]
	ret

DRAW_CIN_032:
	video offset=CINEMATIC_032, x=[0x07], y=[0x08]
	ret

DRAW_CIN_033_034_VAR09_LOW:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_033
	je [0xF8], 0x02, DRAW_CIN_034
	ret

DRAW_CIN_033:
	video offset=CINEMATIC_033, x=[0xf5], y=[0x08]
	ret

DRAW_CIN_034:
	video offset=CINEMATIC_034, x=[0xf5], y=[0x08]
	ret

LABEL_7902:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_239, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_033_034_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_240, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_033_034_VAR09_LOW

LABEL_791F:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_206, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_033_034_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_207, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_033_034_VAR09_LOW

LABEL_793C:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_165, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_033_034_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_166, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_033_034_VAR09_LOW

LABEL_795D:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_211, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_033_034_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_212, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_033_034_VAR09_LOW

LABEL_797A:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_214, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_033_034_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_215, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_033_034_VAR09_LOW

LABEL_799B:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_218, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_033_034_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_219, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_033_034_VAR09_LOW

LABEL_79BC:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_222, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_033_034_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_223, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_033_034_VAR09_LOW

LABEL_79DD:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_226, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_033_034_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_227, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_033_034_VAR09_LOW

LABEL_79FE:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_230, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_033_034_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_231, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_033_034_VAR09_LOW

LABEL_7A1F:
	video type=0, offset=COMMON_VIDEO_268, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_033_034_VAR09_LOW

LABEL_7A2A:
	video type=0, offset=COMMON_VIDEO_271, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_033_034_VAR09_LOW

LABEL_7A35:
	video type=0, offset=COMMON_VIDEO_274, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_033_034_VAR09_LOW

LABEL_7A40:
	video type=0, offset=COMMON_VIDEO_277, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_033_034_VAR09_LOW

LABEL_7A4B:
	video type=0, offset=COMMON_VIDEO_281, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_033_034_VAR09_LOW

LABEL_7A56:
	video type=0, offset=COMMON_VIDEO_283, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_033_034_VAR09_LOW

LABEL_7A61:
	video type=0, offset=COMMON_VIDEO_265, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_033_034_VAR09_LOW

LABEL_7A6C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV204_AT_X07_Y08
	call LABEL_78A9
	jmp LABEL_7A83
