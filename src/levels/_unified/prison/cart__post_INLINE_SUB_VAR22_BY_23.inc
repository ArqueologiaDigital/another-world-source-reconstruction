LABEL_3464:
	ret
LABEL_3465:
	db 0x11

LABEL_3466:
	call LABEL_3642
	sub [0x08], 0x000A
	video type=1, offset=CINEMATIC_361, x=[0x07], y=[0x08], zoom=0x40
	break
	call LABEL_3642
	sub [0x08], 0x0006
	video type=1, offset=CINEMATIC_362, x=[0x07], y=[0x08], zoom=0x40
	break
	call LABEL_3642
	video type=1, offset=CINEMATIC_363, x=[0x07], y=[0x08], zoom=0x40
	break
	call LABEL_3642
	sub [0x08], 0x0001
	video type=1, offset=CINEMATIC_364, x=[0x07], y=[0x08], zoom=0x40
	break
	call LABEL_3642
	sub [0x08], 0x0002
	video type=1, offset=CINEMATIC_363, x=[0x07], y=[0x08], zoom=0x40
	mov [0x29], 0x0001

LABEL_34A6:
	call LABEL_361B
	break
	call LABEL_3642
	video type=1, offset=CINEMATIC_362, x=[0x07], y=[0x08], zoom=0x40
	break
	call LABEL_3642
	video type=1, offset=CINEMATIC_363, x=[0x07], y=[0x08], zoom=0x40
	break
	call LABEL_3642
	video type=1, offset=CINEMATIC_364, x=[0x07], y=[0x08], zoom=0x40
	break
	call LABEL_3642
	video type=1, offset=CINEMATIC_361, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x29], LABEL_34A6
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	video type=1, offset=CINEMATIC_380, x=[0x07], y=[0x08], zoom=0x40
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	video type=1, offset=CINEMATIC_381, x=[0x07], y=[0x08], zoom=0x40
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	video type=1, offset=CINEMATIC_382, x=[0x07], y=[0x08], zoom=0x40
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	sub [0x08], 0x0003
	video type=1, offset=CINEMATIC_383, x=[0x07], y=[0x08], zoom=0x40
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	video type=1, offset=CINEMATIC_382, x=[0x07], y=[0x08], zoom=0x40
	mov [0x29], 0x000A

LABEL_3506:
	mov [0xF8], [0x2B]
	and [0xF8], 0x00FF
	jl [0xF8], 0x02, LABEL_3524
	mov [0xF8], [0x29]
	and [0xF8], 0x0001
	je [0xF8], 0x01, LABEL_3524
	sub [0x2B], 0x0001

LABEL_3524:
	call LABEL_361B
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	je [0x09], 0x01, LABEL_358D
	video type=1, offset=CINEMATIC_385, x=[0x07], y=[0x08], zoom=0x40
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	je [0x09], 0x01, LABEL_358D
	video type=1, offset=CINEMATIC_386, x=[0x07], y=[0x08], zoom=0x40
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	je [0x09], 0x01, LABEL_358D
	video type=1, offset=CINEMATIC_383, x=[0x07], y=[0x08], zoom=0x40
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	je [0x09], 0x01, LABEL_358D
	sub [0x08], 0x0001
	video type=1, offset=CINEMATIC_383, x=[0x07], y=[0x08], zoom=0x40
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	je [0x09], 0x01, LABEL_358D
	video type=1, offset=CINEMATIC_386, x=[0x07], y=[0x08], zoom=0x40
	break
	call ADVANCE_VAR0D_RESTORE_STATE
	je [0x09], 0x01, LABEL_358D
	video type=1, offset=CINEMATIC_385, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x29], LABEL_3506
	break
	call ADVANCE_VAR0D_RESTORE_STATE

LABEL_358D:
	video type=1, offset=CINEMATIC_384, x=[0x07], y=[0x08], zoom=[0x96]	;@raw=0x56,0x40,0x74,0x07,0x08,0x96
	mov [0x2B], 0x0FA0
	call LABEL_361B
	break
	jmp LABEL_3612
LABEL_359E:
	db 0x11

LABEL_359F:
	jg [0x27], [0x44], LABEL_35A9
	or [0x22], 0x1000

LABEL_35A9:
	jne [0x5B], 0x0FA0, LABEL_35CA
	jne [0x5E], 0x0FA0, LABEL_35CA
	jne [0x61], 0x0FA0, LABEL_35CA
	setup channel=0x30, address=LABEL_3609
	setup channel=0x31, address=LABEL_3612
	setup channel=0x32, address=LABEL_3612

LABEL_35CA:
	jne [0x5B], 0x0FA0, LABEL_35DF
	mov [0x5A], [0x21]
	mov [0x5B], [0x22]
	mov [0x5C], [0x29]
	setup channel=0x31, address=LABEL_3466
	ret

LABEL_35DF:
	jne [0x5E], 0x0FA0, LABEL_35F4
	mov [0x5D], [0x21]
	mov [0x5E], [0x22]
	mov [0x5F], [0x29]
	setup channel=0x32, address=LABEL_3466
	ret

LABEL_35F4:
	jne [0x61], 0x0FA0, LABEL_3608
	mov [0x60], [0x21]
	mov [0x61], [0x22]
	mov [0x62], [0x29]
	setup channel=0x33, address=LABEL_3466

LABEL_3608:
	ret

LABEL_3609:
	mov [0x0D], 0x0000
	break
	jmp LABEL_3609
LABEL_3611:
	db 0x11

LABEL_3612:
	add [0x0D], 0x0001
	break
	jmp LABEL_3612
LABEL_361A:
	db 0x11

LABEL_361B:
	jne [0x0D], 0x01, LABEL_3628
	mov [0x5C], [0x29]
	mov [0x5B], [0x2B]
	ret

LABEL_3628:
	jne [0x0D], 0x02, LABEL_3635
	mov [0x5F], [0x29]
	mov [0x5E], [0x2B]
	ret

LABEL_3635:
	jne [0x0D], 0x03, LABEL_3641
	mov [0x62], [0x29]
	mov [0x61], [0x2B]

LABEL_3641:
	ret

LABEL_3642:
	add [0x0D], 0x0001
	jne [0x0D], 0x01, LABEL_365F
	mov [0x21], [0x5A]
	mov [0x2B], [0x5B]
	mov [0x29], [0x5C]
	call LABEL_36E0
	mov [0x5A], [0x07]
	mov [0x5B], [0x2B]
	ret

LABEL_365F:
	jne [0x0D], 0x02, LABEL_3678
	mov [0x21], [0x5D]
	mov [0x2B], [0x5E]
	mov [0x29], [0x5F]
	call LABEL_36E0
	mov [0x5D], [0x07]
	mov [0x5E], [0x2B]
	ret

LABEL_3678:
	jne [0x0D], 0x03, LABEL_3690
	mov [0x21], [0x60]
	mov [0x2B], [0x61]
	mov [0x29], [0x62]
	call LABEL_36E0
	mov [0x60], [0x07]
	mov [0x61], [0x2B]

LABEL_3690:
	ret

ADVANCE_VAR0D_RESTORE_STATE:
	add [0x0D], 0x0001
	jne [0x0D], 0x01, LABEL_36AE
	mov [0x21], [0x5A]
	mov [0x2B], [0x5B]
	mov [0x29], [0x5C]
	call LABEL_3707
	mov [0x5A], [0x07]
	mov [0x5B], [0x2B]
	ret

LABEL_36AE:
	jne [0x0D], 0x02, LABEL_36C7
	mov [0x21], [0x5D]
	mov [0x2B], [0x5E]
	mov [0x29], [0x5F]
	call LABEL_3707
	mov [0x5D], [0x07]
	mov [0x5E], [0x2B]
	ret

LABEL_36C7:
	jne [0x0D], 0x03, LABEL_36DF
	mov [0x21], [0x60]
	mov [0x2B], [0x61]
	mov [0x29], [0x62]
	call LABEL_3707
	mov [0x60], [0x07]
	mov [0x61], [0x2B]

LABEL_36DF:
	ret

LABEL_36E0:
	call LABEL_3765
	mov [0x1D], 0x0000
	call LABEL_49C8
	je [0x1D], 0x00, COPY_VAR22_TO_VAR07
	jl [0x2B], 0x4000, INLINE_OR_VAR2B_WITH_4000
	and [0x2B], 0x3FFF
	jmp COPY_VAR22_TO_VAR07
