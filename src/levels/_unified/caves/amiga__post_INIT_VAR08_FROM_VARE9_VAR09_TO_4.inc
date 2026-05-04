LABEL_3356:
	mov [0x21], [0xE8]
	mov [0x22], [0x08]
	mov [0x23], [0xEC]
	add [0x23], [0x09]
	call LABEL_32E5
	add [0x08], 0x0014
	djnz [0x09], LABEL_3356
	mov [0x21], [0xE8]
	mov [0x22], [0xE9]
	mov [0x23], [0xEC]
	add [0x22], 0x000A
	add [0x21], 0x0000
	call LABEL_32E5
	break
	jmp INIT_VAR08_FROM_VARE9_VAR09_TO_4
LABEL_3385:
	db 0x11

LABEL_3386:
	jne [HACK_VAR_67], [0x09], SHARED_RET
	jne [0x6D], 0x00, LABEL_3398
	video type=1, offset=CINEMATIC_794, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_3398:
	jne [0x6D], 0x01, LABEL_33A4
	video type=1, offset=CINEMATIC_793, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_33A4:
	jne [0x6D], 0x02, LABEL_33B0
	video type=1, offset=CINEMATIC_792, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_33B0:
	jne [0x6D], 0x03, DRAW_CIN_790
	video type=1, offset=CINEMATIC_791, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_790:
	video type=1, offset=CINEMATIC_790, x=[0x07], y=[0x08], zoom=0x40
	ret

GUARDED_DRAW_CIN_579_786:
	jne [HACK_VAR_67], [0x09], SHARED_RET
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_579, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_786, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0xFF
	add [0x07], 0x000B
	call LABEL_33F7
	sub [0x07], 0x000B
	ret

LABEL_33E2:
	jne [HACK_VAR_67], [0x09], SHARED_RET
	selectVideoPage 0x03
	video type=1, offset=CINEMATIC_579, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_786, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0xFF
	ret

LABEL_33F7:
	jne [0x6D], 0x00, LABEL_3403
	video type=1, offset=CINEMATIC_788, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_3403:
	jne [0x6D], 0x01, LABEL_340F
	video type=1, offset=CINEMATIC_787, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_340F:
	jne [0x6D], 0x02, LABEL_341B
	video type=1, offset=CINEMATIC_789, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_341B:
	jne [0x6D], 0x03, DRAW_CIN_787
	video type=1, offset=CINEMATIC_788, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_787:
	video type=1, offset=CINEMATIC_787, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_342D:
	jg [HACK_VAR_67], [0x09], LABEL_344C
	jne [HACK_VAR_67], [0x09], SHARED_RET
	jl [0x04], 0x4000, LABEL_3446
	mov [0x01], [0x07]
	jmp LABEL_345B

LABEL_3446:
	jl [0x01], [0x07], LABEL_345B

LABEL_344C:
	deleteChannels first=0x14, last=0x16
	setup channel=0x14, address=LABEL_2349
	mov [0x04], 0x4000
	jmp LABEL_1A8C

LABEL_345B:
	jne [0x6D], 0x00, LABEL_3467
	video type=1, offset=CINEMATIC_785, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_3467:
	jne [0x6D], 0x01, LABEL_3473
	video type=1, offset=CINEMATIC_784, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_3473:
	jne [0x6D], 0x02, LABEL_347F
	video type=1, offset=CINEMATIC_783, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_347F:
	jne [0x6D], 0x03, DRAW_CIN_781
	video type=1, offset=CINEMATIC_782, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_781:
	video type=1, offset=CINEMATIC_781, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_3491:
	break
	add [0x6D], 0x0001
	jl [0x6D], 0x05, LABEL_3491
	mov [0x6D], 0x0000
	jmp LABEL_3491
LABEL_34A3:
	db 0x11
