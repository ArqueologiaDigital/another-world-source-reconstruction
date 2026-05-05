LABEL_14B0:
	call LABEL_88DA
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
	jmp LABEL_14B0
LABEL_14D2:
	db 0x11

LABEL_14D3:
	call LABEL_1487
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
	jmp LABEL_14D3
LABEL_150D:
	db 0x11

LABEL_150E:
	call LABEL_1487
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
	jmp LABEL_150E
LABEL_1548:
	db 0x11

LABEL_1549:
	call LABEL_1487
	mov [0x78], [0x07]
	mov [0x79], [0x08]
	mov [0x7A], [0x10]
	mov [0x7B], [0x11]
	mov [0x7D], [0x09]
	mov [0x7C], [0x12]
	mov [0x7E], [0x13]
	mov [0x7F], [0x29]
	break
	jmp LABEL_1549
LABEL_1568:
	db 0x11

DRAW_CIN_393_IF_VAR1_LE_EB:
	jg [0x01], 0xEB, DRAW_CIN_389
	video offset=CINEMATIC_393, x=[0x07], y=[0x08]
	ret

DRAW_CIN_389:
	video offset=CINEMATIC_389, x=[0x07], y=[0x08]
	ret

LABEL_157B:
	call GUARDED_HERO_ANIM_CV_128
	add [0x07], 0x0001
	mov [0x29], 0x0005

LABEL_1586:
	break
	call GUARDED_HERO_ANIM_CV_128
	djnz [0x29], LABEL_1586
	break
	call GUARDED_DRAW_CIN_342
	selectVideoPage 0x00
	video offset=CINEMATIC_389, x=[0x07], y=[0x08]
	video offset=CINEMATIC_390, x=[0x07], y=[0x08]
	selectVideoPage 0xFF
	mov [0x29], 0x000F

LABEL_15A4:
	break
	video offset=CINEMATIC_391, x=[0x07], y=[0x08]
	video offset=CINEMATIC_392, x=[0x07], y=[0x08]
	call DRAW_CIN_393_IF_VAR1_LE_EB
	djnz [0x29], LABEL_15A4
	break
	video offset=CINEMATIC_394, x=[0x07], y=[0x08]
	video offset=CINEMATIC_392, x=[0x07], y=[0x08]
	call DRAW_CIN_393_IF_VAR1_LE_EB
	break
	video offset=CINEMATIC_395, x=[0x07], y=[0x08]
	video offset=CINEMATIC_392, x=[0x07], y=[0x08]
	call DRAW_CIN_393_IF_VAR1_LE_EB
	mov [0x29], 0x0014

LABEL_15D6:
	break
	video offset=CINEMATIC_397, x=[0x07], y=[0x08]
	video offset=CINEMATIC_396, x=[0x07], y=[0x08]
	call DRAW_CIN_393_IF_VAR1_LE_EB
	djnz [0x29], LABEL_15D6
	break
	video offset=CINEMATIC_395, x=[0x07], y=[0x08]
	video offset=CINEMATIC_396, x=[0x07], y=[0x08]
	call DRAW_CIN_393_IF_VAR1_LE_EB
	break
	video offset=CINEMATIC_400, x=[0x07], y=[0x08]
	video offset=CINEMATIC_396, x=[0x07], y=[0x08]
	call DRAW_CIN_393_IF_VAR1_LE_EB
	break
	video offset=CINEMATIC_401, x=[0x07], y=[0x08]
	video offset=CINEMATIC_396, x=[0x07], y=[0x08]
	video offset=CINEMATIC_393, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_402, x=[0x07], y=[0x08]
	video offset=CINEMATIC_396, x=[0x07], y=[0x08]
	call DRAW_CIN_393_IF_VAR1_LE_EB
	mov [0x29], 0x0020

LABEL_1626:
	break
	video offset=CINEMATIC_403, x=[0x07], y=[0x08]
	video offset=CINEMATIC_392, x=[0x07], y=[0x08]
	call DRAW_CIN_393_IF_VAR1_LE_EB
	djnz [0x29], LABEL_1626
	break
	video offset=CINEMATIC_404, x=[0x07], y=[0x08]
	video offset=CINEMATIC_396, x=[0x07], y=[0x08]
	call DRAW_CIN_393_IF_VAR1_LE_EB
	selectVideoPage 0x00
	video offset=CINEMATIC_405, x=160, y=[0x44]
	selectVideoPage 0xFF
	break
	call GUARDED_DRAW_CIN_342
	break
	call GUARDED_HERO_ANIM_CV_128
	or [0x49], 0x0040
	je [0xB6], 0x00, LABEL_166D
	break
	mov [0x29], 0x0082
	mov [0x12], 0x0028
	jmp LABEL_69DD

LABEL_166D:
	mov [0x12], 0x1008
	jmp LABEL_267B
LABEL_1674:
	db 0x11
