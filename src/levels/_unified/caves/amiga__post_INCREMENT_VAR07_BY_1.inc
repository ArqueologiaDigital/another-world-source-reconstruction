DRAW_HERO_SPRITE_BY_VAR09_0E:
	mov [0xF8], [0x09]
	shr [0xF8], 0x0004
	and [0xF8], 0x000F
	jne [0x0E], 0x00, LABEL_8AEA
	je [0xF8], 0x00, DRAW_CV_298__AMIGA__POST_INCREMENT_VAR07_BY_1__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0xF8], 0x01, DRAW_CIN_022__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0xF8], 0x02, DRAW_CIN_023__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0xF8], 0x03, DRAW_CIN_024__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0xF8], 0x04, DRAW_CIN_025__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0xF8], 0x05, DRAW_CIN_026
	je [0xF8], 0x06, DRAW_CIN_027__AMIGA__POST_INCREMENT_VAR07_BY_1
	ret

LABEL_8AEA:
	jne [0x0E], 0x01, LABEL_8AF3
	jmp DRAW_CIN_021__AMIGA__POST_INCREMENT_VAR07_BY_1

LABEL_8AF3:
	jne [0x0E], 0x02, LABEL_8AFC
	jmp DRAW_CIN_020__AMIGA__POST_INCREMENT_VAR07_BY_1

LABEL_8AFC:
	jne [0x0E], 0x03, LABEL_8B05
	jmp DRAW_CIN_019__AMIGA__POST_INCREMENT_VAR07_BY_1

LABEL_8B05:
	jne [0x0E], 0x04, LABEL_8B14
	je [0xF8], 0x01, DRAW_CIN_017__AMIGA__POST_INCREMENT_VAR07_BY_1
	jmp DRAW_CIN_018__AMIGA__POST_INCREMENT_VAR07_BY_1

LABEL_8B14:
	jne [0x0E], 0x05, LABEL_8B1D
	jmp DRAW_CIN_016__AMIGA__POST_INCREMENT_VAR07_BY_1

LABEL_8B1D:
	jne [0x0E], 0x07, LABEL_8B2A
	je [0xF8], 0x01, DRAW_CIN_015__AMIGA__POST_INCREMENT_VAR07_BY_1
	ret

LABEL_8B2A:
	ret

DRAW_CV_298__AMIGA__POST_INCREMENT_VAR07_BY_1__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=0, offset=COMMON_VIDEO_298, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_022__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_022, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_023__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_023, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_024__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_024, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_025__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_025, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_027__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_027, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_021__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_021, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_020__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_020, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_019__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_019, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_018__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_018, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_017__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_017, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_016__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_016, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_015__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_015, x=[0x07], y=[0x08], zoom=0x40
	ret
LABEL_8B79:
	db 0x11

DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_028__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0xF8], 0x02, DRAW_CIN_029__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0xF8], 0x03, DRAW_CIN_030__AMIGA__POST_INCREMENT_VAR07_BY_1
	ret

DRAW_CIN_028__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_028, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_029__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_029, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_030__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_030, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_031_032_VAR09_LOW:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_031__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0xF8], 0x02, DRAW_CIN_032__AMIGA__POST_INCREMENT_VAR07_BY_1
	ret

DRAW_CIN_031__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_031, x=[0xf5], y=[0x08], zoom=0x40
	ret

DRAW_CIN_032__AMIGA__POST_INCREMENT_VAR07_BY_1:
	video type=1, offset=CINEMATIC_032, x=[0xf5], y=[0x08], zoom=0x40
	ret

LABEL_8BC6:
	video type=0, offset=COMMON_VIDEO_158, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_159, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8BDC:
	video type=0, offset=COMMON_VIDEO_125, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_126, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8BF2:
	video type=0, offset=COMMON_VIDEO_129, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_130, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8C0C:
	video type=0, offset=COMMON_VIDEO_132, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_133, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8C22:
	video type=0, offset=COMMON_VIDEO_010, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_011, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8C3C:
	video type=0, offset=COMMON_VIDEO_137, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_138, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8C56:
	video type=0, offset=COMMON_VIDEO_141, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_142, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8C70:
	video type=0, offset=COMMON_VIDEO_145, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_146, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8C8A:
	video type=0, offset=COMMON_VIDEO_149, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_150, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8CA4:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_123, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_124, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8CC6
	call LABEL_8877
	jmp LABEL_8CC9

LABEL_8CC6:
	call LABEL_8BDC

LABEL_8CC9:
	ret

LABEL_8CCA:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	sub [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_123, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	video type=0, offset=COMMON_VIDEO_127, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8CF4
	call LABEL_8877
	jmp LABEL_8CF7

LABEL_8CF4:
	call LABEL_8BDC

LABEL_8CF7:
	ret

GUARDED_HERO_ANIM_CV_128:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8D15
	call LABEL_8883
	jmp LABEL_8D18

LABEL_8D15:
	call LABEL_8BF2

LABEL_8D18:
	ret

LABEL_8D19:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_131, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8D3C
	call LABEL_8883
	jmp LABEL_8D3F

LABEL_8D3C:
	call LABEL_8C0C

LABEL_8D3F:
	ret

LABEL_8D40:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_134, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8D5D
	call LABEL_8883
	jmp LABEL_8D60

LABEL_8D5D:
	call LABEL_8C22

LABEL_8D60:
	ret

LABEL_8D61:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_135, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_136, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8D83
	call LABEL_88A6
	jmp LABEL_8D86

LABEL_8D83:
	call LABEL_8C3C

LABEL_8D86:
	ret

LABEL_8D87:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_139, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_140, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8DA9
	call LABEL_88B2
	jmp LABEL_8DAC

LABEL_8DA9:
	call LABEL_8C56

LABEL_8DAC:
	ret

LABEL_8DAD:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_143, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_144, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8DCF
	call LABEL_88D5
	jmp LABEL_8DD2

LABEL_8DCF:
	call LABEL_8C70

LABEL_8DD2:
	ret

LABEL_8DD3:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_147, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_148, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8DF5
	call LABEL_88F8
	jmp LABEL_8DF8

LABEL_8DF5:
	call LABEL_8C8A

LABEL_8DF8:
	ret

LABEL_8DF9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_147, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_151, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8E1B
	call LABEL_88F8
	jmp LABEL_8E26

LABEL_8E1B:
	sub [0x07], 0x0001
	call LABEL_8C8A
	add [0x07], 0x0001

LABEL_8E26:
	ret

LABEL_8E27:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_139, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_152, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8E49
	call LABEL_88D5
	jmp LABEL_8E4C

LABEL_8E49:
	call LABEL_8C56

LABEL_8E4C:
	ret

LABEL_8E4D:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_135, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_153, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8E75
	call LABEL_88D5
	jmp LABEL_8E78

LABEL_8E75:
	call LABEL_8C3C

LABEL_8E78:
	ret

LABEL_8E79:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_154, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8E96
	call LABEL_88D5
	jmp LABEL_8E99

LABEL_8E96:
	call LABEL_8C22

LABEL_8E99:
	ret

LABEL_8E9A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_155, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8EB7
	call LABEL_88B2
	jmp LABEL_8EBA

LABEL_8EB7:
	call LABEL_8C0C

LABEL_8EBA:
	ret

LABEL_8EBB:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_156, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8ED8
	call LABEL_88A6
	jmp LABEL_8EDB

LABEL_8ED8:
	call LABEL_8BF2

LABEL_8EDB:
	ret

LABEL_8EDC:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_157, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8EF9
	call LABEL_8883
	jmp LABEL_8EFC

LABEL_8EF9:
	call LABEL_8BC6

LABEL_8EFC:
	ret

GUARDED_HERO_ANIM_CV_009:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_009, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8F1A
	call LABEL_8883
	jmp LABEL_8F1D

LABEL_8F1A:
	call LABEL_8C22

LABEL_8F1D:
	ret

LABEL_8F1E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_009, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8F3B
	call LABEL_88A6
	jmp LABEL_8F3E

LABEL_8F3B:
	call LABEL_8C3C

LABEL_8F3E:
	ret

LABEL_8F3F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_009, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_028_029_030_VAR09__AMIGA__POST_INCREMENT_VAR07_BY_1
	je [0x0D], 0x00, LABEL_8F5C
	call LABEL_88B2
	jmp LABEL_8F5F

LABEL_8F5C:
	call LABEL_8C56

LABEL_8F5F:
	ret

LABEL_8F60:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_139, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8F6C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_140, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8F78:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_881D
	call DRAW_BEAST_Y_PLUS_D__AMIGA__POST_INCREMENT_VAR07_BY_1
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_7FFF
	sub [0x08], 0x000D
	ret

LABEL_8F95:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x0001
	call LABEL_883B
	add [0x08], 0x0001
	call DRAW_BEAST_Y_PLUS_D__AMIGA__POST_INCREMENT_VAR07_BY_1
	video type=0, offset=COMMON_VIDEO_242, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_801C
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_8FC2:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_8859
	call DRAW_BEAST_Y_PLUS_D__AMIGA__POST_INCREMENT_VAR07_BY_1
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_7FFF
	sub [0x08], 0x000D
	ret

LABEL_8FDF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call LABEL_883B
	call DRAW_BEAST_Y_PLUS_D__AMIGA__POST_INCREMENT_VAR07_BY_1
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_7FFF
	sub [0x08], 0x000D
	ret

LABEL_8FFC:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_9013
	add [0x08], 0x000D
	call LABEL_7F88
	sub [0x08], 0x000D

LABEL_9013:
	call DRAW_BEAST_Y_PLUS_D__AMIGA__POST_INCREMENT_VAR07_BY_1
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_801C
	sub [0x08], 0x000D
	ret

LABEL_9027:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_060, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_8FFC
	ret

LABEL_9036:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x0001
	video type=0, offset=COMMON_VIDEO_243, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x0001
	call DRAW_BEAST_Y_PLUS_D__AMIGA__POST_INCREMENT_VAR07_BY_1
	video type=0, offset=COMMON_VIDEO_242, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_801C
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_9065:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=0, offset=COMMON_VIDEO_243, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_Y_PLUS_D__AMIGA__POST_INCREMENT_VAR07_BY_1
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_7FFF
	sub [0x08], 0x000D
	ret

LABEL_9084:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	add [0x07], 0x0004
	video type=0, offset=COMMON_VIDEO_231, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x0004
	sub [0x08], 0x000D
	call DRAW_BEAST_Y_PLUS_D__AMIGA__POST_INCREMENT_VAR07_BY_1
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8039
	sub [0x08], 0x000D
	ret

LABEL_90B3:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_BEAST_Y_PLUS_D__AMIGA__POST_INCREMENT_VAR07_BY_1
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8039
	sub [0x08], 0x000D
	ret

LABEL_90CD:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x000D
	video type=1, offset=CINEMATIC_075, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call DRAW_BEAST_Y_PLUS_D__AMIGA__POST_INCREMENT_VAR07_BY_1
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8039
	sub [0x08], 0x000D
	ret

LABEL_90F4:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	add [0x08], 0x000D
	video type=1, offset=CINEMATIC_074, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call DRAW_BEAST_Y_PLUS_D__AMIGA__POST_INCREMENT_VAR07_BY_1
	video type=0, offset=COMMON_VIDEO_242, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_801C
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret

LABEL_9123:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x78], 0x000A
	add [0x79], 0x0005
	video type=0, offset=COMMON_VIDEO_243, x=[0x78], y=[0x79], zoom=0x40
	sub [0x79], 0x0005
	add [0x78], 0x000A
	video type=1, offset=CINEMATIC_184, x=[0x78], y=[0x79], zoom=0x40
	ret

LABEL_9144:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_881D
	add [0x08], 0x000D
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_120, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_8077
	ret

LABEL_9161:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x000E
	call LABEL_883B
	add [0x08], 0x000E
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_246, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	call LABEL_8077
	sub [0x07], 0x0002
	ret
LABEL_918A:
	db 0x0A, 0x81, 0x67, 0x10, 0x7F, 0xB2, 0x03, 0x08
	db 0xFF, 0xF3, 0x04, 0x88, 0x59, 0x03, 0x08, 0x00
	db 0x0D, 0x04, 0x7D, 0x50, 0x57, 0x20, 0x76, 0x07
	db 0x08, 0x04, 0x80, 0x77, 0x05

LABEL_91A7:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_883B
	add [0x08], 0x000D
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_120, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_8077
	ret
LABEL_91C4:
	db 0x0A, 0x81, 0x67, 0x10, 0x7F, 0xB2, 0x04, 0x7D
	db 0x50, 0x57, 0x20, 0x76, 0x07, 0x08, 0x05, 0x0A
	db 0x81, 0x67, 0x10, 0x7F, 0xB2, 0x04, 0x92, 0x34
	db 0x57, 0x20, 0x5F, 0x07, 0x08, 0x57, 0x1F, 0xEA
	db 0x07, 0x08, 0x05

LABEL_91E7:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	video type=1, offset=CINEMATIC_059, x=[0x07], y=[0x08], zoom=0x40
	ret
LABEL_91F3:
	db 0x0A, 0x81, 0x67, 0x10, 0x7F, 0xB2, 0x04, 0x92
	db 0x34, 0x57, 0x1F, 0xEA, 0x07, 0x08, 0x05, 0x0A
	db 0x81, 0x67, 0x10, 0x7F, 0xB2, 0x57, 0x1F, 0xD4
	db 0x07, 0x08, 0x57, 0x1F, 0xC6, 0x07, 0x08, 0x04
	db 0x92, 0x2E, 0x05

DRAW_HERO_Y_PLUS_E:
	add [0x08], 0x000E
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	sub [0x08], 0x000E
	ret

DRAW_BEAST_Y_PLUS_D__AMIGA__POST_INCREMENT_VAR07_BY_1:
	add [0x08], 0x000D
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	sub [0x08], 0x000D
	ret
LABEL_922E:
	db 0x54, 0x0A, 0xDD, 0x07, 0x08, 0x05, 0x57, 0x1F
	db 0xDC, 0x07, 0x08, 0x05

LABEL_923A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_7EAC
	ret

LABEL_924C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_245, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x0001
	call LABEL_7EDA
	add [0x08], 0x0001
	add [0x07], 0x0001
	ret

LABEL_926E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_7F0C
	ret

LABEL_9280:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_7EDA
	ret

LABEL_9292:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	je [0x0D], 0x00, LABEL_92B0
	call LABEL_88D5
	jmp DECREMENT_VAR08_BY_D

LABEL_92B0:
	call LABEL_8BC6
