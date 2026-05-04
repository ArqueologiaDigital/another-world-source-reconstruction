LABEL_74FA:
	mov [0x21], [0x28]
	sub [0x22], [0x2A]
	call LABEL_7522
	add [0x22], [0x2A]
	jle [0x22], [0x01], COPY_VAR01_TO_VAR28
	mov [0x01], [0x22]
	mov [0x28], [0x01]
	ret
LABEL_7513:
	db 0x11

LABEL_7514:
	mov [0x23], 0x0000
	jg [0x27], [0x44], LABEL_7522
	mov [0x23], 0x0001

LABEL_7522:
	jl [0x22], [0x21], LABEL_7573
	je [0x23], 0x00, LABEL_753E
	jg [0x47], [0x22], LABEL_754B
	mov [0x22], [0x47]
	mov [0x1D], 0x0004
	jmp LABEL_754B

LABEL_753E:
	jg [0x43], [0x22], LABEL_754B
	mov [0x22], [0x43]
	mov [0x1D], 0x0002

LABEL_754B:
	mov [0x24], [0x48]
	mov [0x25], [0x49]
	mov [0x1C], 0x000A
	call LABEL_7642
	mov [0x24], [0x4A]
	mov [0x25], [0x4B]
	mov [0x1C], 0x000B
	call LABEL_7642
	mov [0x24], [0x4C]
	mov [0x25], [0x4D]
	mov [0x1C], 0x000C
	call LABEL_7642
	ret

LABEL_7573:
	je [0x23], 0x00, LABEL_7589
	jl [0x46], [0x22], LABEL_7596
	mov [0x22], [0x46]
	mov [0x1D], 0x0003
	jmp LABEL_7596

LABEL_7589:
	jl [0x42], [0x22], LABEL_7596
	mov [0x22], [0x42]
	mov [0x1D], 0x0001

LABEL_7596:
	mov [0x24], [0x48]
	mov [0x25], [0x49]
	mov [0x1C], 0x000A
	call LABEL_75BE
	mov [0x24], [0x4A]
	mov [0x25], [0x4B]
	mov [0x1C], 0x000B
	call LABEL_75BE
	mov [0x24], [0x4C]
	mov [0x25], [0x4D]
	mov [0x1C], 0x000C
	call LABEL_75BE
	ret

LABEL_75BE:
	jge [0x25], 0x2000, LABEL_7641
	jge [0x25], 0x1000, LABEL_75D5
	je [0x23], 0x01, LABEL_7641
	jmp LABEL_75DF

LABEL_75D5:
	sub [0x25], 0x1000
	je [0x23], 0x00, LABEL_7641

LABEL_75DF:
	add [0x24], 0x0008
	jl [0x25], 0x0200, LABEL_7600
	sub [0x25], 0x0200
	jg [0x24], [0x21], LABEL_7641
	jl [0x24], [0x22], LABEL_7600
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

LABEL_7600:
	add [0x24], 0x000A
	jl [0x25], 0x0100, LABEL_7621
	sub [0x25], 0x0100
	jg [0x24], [0x21], LABEL_7641
	jl [0x24], [0x22], LABEL_7621
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

LABEL_7621:
	add [0x24], 0x000A
	jl [0x25], 0x80, LABEL_7641
	sub [0x25], 0x0080
	jg [0x24], [0x21], LABEL_7641
	jl [0x24], [0x22], LABEL_7641
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

LABEL_7641:
	ret

LABEL_7642:
	jge [0x25], 0x2000, LABEL_76AF
	jge [0x25], 0x1000, LABEL_7659
	je [0x23], 0x01, LABEL_76AF
	jmp LABEL_7663

LABEL_7659:
	sub [0x25], 0x1000
	je [0x23], 0x00, LABEL_76AF

LABEL_7663:
	jl [0x25], 0x0200, LABEL_7679
	jl [0x24], [0x21], LABEL_7679
	jg [0x24], [0x22], LABEL_7679
	jmp LABEL_76A9

LABEL_7679:
	add [0x24], 0x000A
	jl [0x25], 0x0100, LABEL_7693
	jl [0x24], [0x21], LABEL_7693
	jg [0x24], [0x22], LABEL_7693
	jmp LABEL_76A9

LABEL_7693:
	add [0x24], 0x000A
	jl [0x25], 0x80, LABEL_76AF
	jl [0x24], [0x21], LABEL_76AF
	jg [0x24], [0x22], LABEL_76AF

LABEL_76A9:
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

LABEL_76AF:
	ret

DRAW_HERO_SPRITE_BY_VAR09_0E:
	mov [0xF8], [0x09]
	shr [0xF8], 0x0004
	and [0xF8], 0x000F
	jne [0x0E], 0x00, LABEL_76F2
	je [0xF8], 0x00, DRAW_CIN_022__CART__POST_COPY_VAR01_TO_VAR28
	je [0xF8], 0x01, DRAW_CIN_023__CART__POST_COPY_VAR01_TO_VAR28
	je [0xF8], 0x02, DRAW_CIN_024__CART__POST_COPY_VAR01_TO_VAR28
	je [0xF8], 0x03, DRAW_CIN_025__CART__POST_COPY_VAR01_TO_VAR28
	je [0xF8], 0x04, DRAW_CIN_026__CART__POST_COPY_VAR01_TO_VAR28
	je [0xF8], 0x05, DRAW_CIN_027
	je [0xF8], 0x06, DRAW_CIN_028__CART__POST_COPY_VAR01_TO_VAR28
	je [0xF8], 0x07, DRAW_CIN_029__CART__POST_COPY_VAR01_TO_VAR28
	ret

LABEL_76F2:
	jne [0x0E], 0x01, LABEL_76FB
	jmp DRAW_CIN_021__CART__POST_COPY_VAR01_TO_VAR28

LABEL_76FB:
	jne [0x0E], 0x02, LABEL_7704
	jmp DRAW_CIN_020__CART__POST_COPY_VAR01_TO_VAR28

LABEL_7704:
	jne [0x0E], 0x03, LABEL_7713
	je [0xF8], 0x03, DRAW_CIN_015__CART__POST_COPY_VAR01_TO_VAR28
	jmp DRAW_CIN_019__CART__POST_COPY_VAR01_TO_VAR28

LABEL_7713:
	jne [0x0E], 0x04, LABEL_7722
	je [0xF8], 0x03, DRAW_CIN_017__CART__POST_COPY_VAR01_TO_VAR28
	jmp DRAW_CIN_018__CART__POST_COPY_VAR01_TO_VAR28

LABEL_7722:
	jne [0x0E], 0x05, LABEL_7731
	je [0xF8], 0x03, DRAW_CIN_015__CART__POST_COPY_VAR01_TO_VAR28
	jmp DRAW_CIN_016__CART__POST_COPY_VAR01_TO_VAR28

LABEL_7731:
	jne [0x0E], 0x06, LABEL_773D
	video type=1, offset=CINEMATIC_014, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_773D:
	jne [0x0E], 0x07, LABEL_7750
	je [0xF8], 0x00, DRAW_CIN_012__CART__POST_COPY_VAR01_TO_VAR28
	je [0xF8], 0x01, DRAW_CIN_013__CART__POST_COPY_VAR01_TO_VAR28
	ret

LABEL_7750:
	ret
LABEL_7751:
	db 0x11

DRAW_CIN_022__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_022, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_023__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_023, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_024__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_024, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_025__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_025, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_026__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_026, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_027:
	video type=1, offset=CINEMATIC_027, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_028__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_028, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_029__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_029, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_021__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_021, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_020__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_020, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_019__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_019, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_015__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_015, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_018__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_018, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_017__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_017, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_016__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_016, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_012__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_012, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_013__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_013, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_77B8:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_247__CART__POST_COPY_VAR01_TO_VAR28
	je [0xF8], 0x02, DRAW_CIN_248
	ret

DRAW_CIN_247__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_247, x=[0xf5], y=[0x08], zoom=0x40
	ret

DRAW_CIN_248:
	video type=1, offset=CINEMATIC_248, x=[0xf5], y=[0x08], zoom=0x40
	ret

LABEL_77D8:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, LABEL_77EC
	je [0xF8], 0x02, LABEL_7802
	ret

LABEL_77EC:
	add [0x08], 0x000D
	sub [0x07], 0x0002
	video type=1, offset=CINEMATIC_112, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0002
	sub [0x08], 0x000D
	ret

LABEL_7802:
	add [0x08], 0x000D
	sub [0x07], 0x0002
	video type=1, offset=CINEMATIC_113, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0002
	sub [0x08], 0x000D
	ret

LABEL_7818:
	video type=0, offset=COMMON_VIDEO_320, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, LABEL_782B
	video type=0, offset=COMMON_VIDEO_322, x=[0x07], y=[0x08], zoom=0x40

LABEL_782B:
	jg [0x13], [0x30], LABEL_77B8
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_77B8
	video type=0, offset=COMMON_VIDEO_321, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_77B8

LABEL_7846:
	video type=0, offset=COMMON_VIDEO_323, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, LABEL_785D
	video type=0, offset=COMMON_VIDEO_325, x=[0x07], y=[0x08], zoom=0x40

LABEL_785D:
	jg [0x13], [0x30], LABEL_77B8
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_77B8
	video type=0, offset=COMMON_VIDEO_324, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_77B8

LABEL_7878:
	video type=0, offset=COMMON_VIDEO_326, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], LABEL_77D8
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_77D8
	video type=0, offset=COMMON_VIDEO_327, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_77D8

LABEL_7898:
	video type=0, offset=COMMON_VIDEO_328, x=[0x07], y=[0x08], zoom=0x40
	jmp LABEL_77D8

LABEL_78A0:
	sub [0x07], 0x0001
	call LABEL_78AC
	add [0x07], 0x0001
	ret

LABEL_78AC:
	video type=0, offset=COMMON_VIDEO_308, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_309, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_78CA:
	sub [0x07], 0x0001
	call LABEL_78D6
	add [0x07], 0x0001
	ret

LABEL_78D6:
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

LABEL_7912:
	add [0x07], 0x0001
	call DRAW_CV_304_THEN_305
	sub [0x07], 0x0001
	ret

SHARED_RET:
	ret

DRAW_CIN_030_031_032_VAR09:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_030__CART__POST_COPY_VAR01_TO_VAR28
	je [0xF8], 0x02, DRAW_CIN_031__CART__POST_COPY_VAR01_TO_VAR28
	je [0xF8], 0x03, DRAW_CIN_032__CART__POST_COPY_VAR01_TO_VAR28
	ret

DRAW_CIN_030__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_030, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_031__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_031, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_032__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_032, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_033__CART__POST_COPY_VAR01_TO_VAR28
	je [0xF8], 0x02, DRAW_CIN_034__CART__POST_COPY_VAR01_TO_VAR28
	ret

DRAW_CIN_033__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_033, x=[0xf5], y=[0x08], zoom=0x40
	ret

DRAW_CIN_034__CART__POST_COPY_VAR01_TO_VAR28:
	video type=1, offset=CINEMATIC_034, x=[0xf5], y=[0x08], zoom=0x40
	ret

LABEL_796B:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_239, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28
	video type=0, offset=COMMON_VIDEO_240, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28

LABEL_7988:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_206, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28
	video type=0, offset=COMMON_VIDEO_207, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28

LABEL_79A5:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_165, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28
	video type=0, offset=COMMON_VIDEO_166, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28

LABEL_79C6:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_211, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28
	video type=0, offset=COMMON_VIDEO_212, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28

LABEL_79E3:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_214, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28
	video type=0, offset=COMMON_VIDEO_215, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28

LABEL_7A04:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_218, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28
	video type=0, offset=COMMON_VIDEO_219, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28

LABEL_7A25:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_222, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28
	video type=0, offset=COMMON_VIDEO_223, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28

LABEL_7A46:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_226, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28
	video type=0, offset=COMMON_VIDEO_227, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28

LABEL_7A67:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_230, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28
	video type=0, offset=COMMON_VIDEO_231, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28

LABEL_7A88:
	video type=0, offset=COMMON_VIDEO_268, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28

LABEL_7A93:
	video type=0, offset=COMMON_VIDEO_271, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28

LABEL_7A9E:
	video type=0, offset=COMMON_VIDEO_274, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28

LABEL_7AA9:
	video type=0, offset=COMMON_VIDEO_277, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28

LABEL_7AB4:
	video type=0, offset=COMMON_VIDEO_281, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28

LABEL_7ABF:
	video type=0, offset=COMMON_VIDEO_283, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28

LABEL_7ACA:
	video type=0, offset=COMMON_VIDEO_265, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_033_034_VAR09_LOW__CART__POST_COPY_VAR01_TO_VAR28

LABEL_7AD5:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV204_AT_X07_Y08
	call LABEL_7912
	jmp LABEL_7AEC
