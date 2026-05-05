LABEL_3320:
	ret
LABEL_3321:
	db 0x11

LABEL_3322:
	call LABEL_34FE
	sub [0x08], 0x000A
	video offset=CINEMATIC_361, x=[0x07], y=[0x08]
	break
	call LABEL_34FE
	sub [0x08], 0x0006
	video offset=CINEMATIC_362, x=[0x07], y=[0x08]
	break
	call LABEL_34FE
	video offset=CINEMATIC_363, x=[0x07], y=[0x08]
	break
	call LABEL_34FE
	sub [0x08], 0x0001
	video offset=CINEMATIC_364, x=[0x07], y=[0x08]
	break
	call LABEL_34FE
	sub [0x08], 0x0002
	video offset=CINEMATIC_363, x=[0x07], y=[0x08]
	mov [0x29], 0x0001

LABEL_3362:
	call LABEL_34D7
	break
	call LABEL_34FE
	video offset=CINEMATIC_362, x=[0x07], y=[0x08]
	break
	call LABEL_34FE
	video offset=CINEMATIC_363, x=[0x07], y=[0x08]
	break
	call LABEL_34FE
	video offset=CINEMATIC_364, x=[0x07], y=[0x08]
	break
	call LABEL_34FE
	video offset=CINEMATIC_361, x=[0x07], y=[0x08]
	djnz [0x29], LABEL_3362
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	video offset=CINEMATIC_380, x=[0x07], y=[0x08]
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	video offset=CINEMATIC_381, x=[0x07], y=[0x08]
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	video offset=CINEMATIC_382, x=[0x07], y=[0x08]
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	sub [0x08], 0x0003
	video offset=CINEMATIC_383, x=[0x07], y=[0x08]
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	video offset=CINEMATIC_382, x=[0x07], y=[0x08]
	mov [0x29], 0x000A

LABEL_33C2:
	mov [0xF8], [0x2B]
	and [0xF8], 0x00FF
	jl [0xF8], 0x02, LABEL_33E0
	mov [0xF8], [0x29]
	and [0xF8], 0x0001
	je [0xF8], 0x01, LABEL_33E0
	sub [0x2B], 0x0001

LABEL_33E0:
	call LABEL_34D7
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	je [0x09], 0x01, LABEL_3449
	video offset=CINEMATIC_385, x=[0x07], y=[0x08]
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	je [0x09], 0x01, LABEL_3449
	video offset=CINEMATIC_386, x=[0x07], y=[0x08]
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	je [0x09], 0x01, LABEL_3449
	video offset=CINEMATIC_383, x=[0x07], y=[0x08]
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	je [0x09], 0x01, LABEL_3449
	sub [0x08], 0x0001
	video offset=CINEMATIC_383, x=[0x07], y=[0x08]
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	je [0x09], 0x01, LABEL_3449
	video offset=CINEMATIC_386, x=[0x07], y=[0x08]
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	je [0x09], 0x01, LABEL_3449
	video offset=CINEMATIC_385, x=[0x07], y=[0x08]
	djnz [0x29], LABEL_33C2
	break
	call ADVANCE_VAR0D_RESTORE_STATE

LABEL_3449:
	video offset=CINEMATIC_384, x=[0x07], y=[0x08], zoom=[0x96]	;@enc=alt
	mov [0x2B], 0x0FA0
	call LABEL_34D7
	break
	jmp LABEL_34CE
LABEL_345A:
	db 0x11

LABEL_345B:
	jg [0x27], [0x44], LABEL_3465
	or [0x22], 0x1000

LABEL_3465:
	jne [0x5B], 0x0FA0, LABEL_3486
	jne [0x5E], 0x0FA0, LABEL_3486
	jne [0x61], 0x0FA0, LABEL_3486
	setup channel=0x30, address=LABEL_34C5
	setup channel=0x31, address=LABEL_34CE
	setup channel=0x32, address=LABEL_34CE

LABEL_3486:
	jne [0x5B], 0x0FA0, LABEL_349B
	mov [0x5A], [0x21]
	mov [0x5B], [0x22]
	mov [0x5C], [0x29]
	setup channel=0x31, address=LABEL_3322
	ret

LABEL_349B:
	jne [0x5E], 0x0FA0, LABEL_34B0
	mov [0x5D], [0x21]
	mov [0x5E], [0x22]
	mov [0x5F], [0x29]
	setup channel=0x32, address=LABEL_3322
	ret

LABEL_34B0:
	jne [0x61], 0x0FA0, LABEL_34C4
	mov [0x60], [0x21]
	mov [0x61], [0x22]
	mov [0x62], [0x29]
	setup channel=0x33, address=LABEL_3322

LABEL_34C4:
	ret

LABEL_34C5:
	mov [0x0D], 0x0000
	break
	jmp LABEL_34C5
LABEL_34CD:
	db 0x11

LABEL_34CE:
	add [0x0D], 0x0001
	break
	jmp LABEL_34CE
LABEL_34D6:
	db 0x11

LABEL_34D7:
	jne [0x0D], 0x01, LABEL_34E4
	mov [0x5C], [0x29]
	mov [0x5B], [0x2B]
	ret

LABEL_34E4:
	jne [0x0D], 0x02, LABEL_34F1
	mov [0x5F], [0x29]
	mov [0x5E], [0x2B]
	ret

LABEL_34F1:
	jne [0x0D], 0x03, LABEL_34FD
	mov [0x62], [0x29]
	mov [0x61], [0x2B]

LABEL_34FD:
	ret

LABEL_34FE:
	add [0x0D], 0x0001
	jne [0x0D], 0x01, LABEL_351B
	mov [0x21], [0x5A]
	mov [0x2B], [0x5B]
	mov [0x29], [0x5C]
	call LABEL_359C
	mov [0x5A], [0x07]
	mov [0x5B], [0x2B]
	ret

LABEL_351B:
	jne [0x0D], 0x02, LABEL_3534
	mov [0x21], [0x5D]
	mov [0x2B], [0x5E]
	mov [0x29], [0x5F]
	call LABEL_359C
	mov [0x5D], [0x07]
	mov [0x5E], [0x2B]
	ret

LABEL_3534:
	jne [0x0D], 0x03, LABEL_354C
	mov [0x21], [0x60]
	mov [0x2B], [0x61]
	mov [0x29], [0x62]
	call LABEL_359C
	mov [0x60], [0x07]
	mov [0x61], [0x2B]

LABEL_354C:
	ret

ADVANCE_VAR0D_RESTORE_STATE:
	add [0x0D], 0x0001
	jne [0x0D], 0x01, LABEL_356A
	mov [0x21], [0x5A]
	mov [0x2B], [0x5B]
	mov [0x29], [0x5C]
	call LABEL_35C3
	mov [0x5A], [0x07]
	mov [0x5B], [0x2B]
	ret

LABEL_356A:
	jne [0x0D], 0x02, LABEL_3583
	mov [0x21], [0x5D]
	mov [0x2B], [0x5E]
	mov [0x29], [0x5F]
	call LABEL_35C3
	mov [0x5D], [0x07]
	mov [0x5E], [0x2B]
	ret

LABEL_3583:
	jne [0x0D], 0x03, LABEL_359B
	mov [0x21], [0x60]
	mov [0x2B], [0x61]
	mov [0x29], [0x62]
	call LABEL_35C3
	mov [0x60], [0x07]
	mov [0x61], [0x2B]

LABEL_359B:
	ret

LABEL_359C:
	call LABEL_3621
	mov [0x1D], 0x0000
	call LABEL_482D
	je [0x1D], 0x00, COPY_VAR22_TO_VAR07
	jl [0x2B], 0x4000, INLINE_OR_VAR2B_WITH_4000
	and [0x2B], 0x3FFF
	jmp COPY_VAR22_TO_VAR07
