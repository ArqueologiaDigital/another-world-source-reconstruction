LABEL_606C:
	ret
LABEL_606D:
	db 0x11

LABEL_606E:
	call LABEL_6262
	sub [0x08], 0x000A
	video type=1, offset=CINEMATIC_076, x=[0x07], y=[0x08], zoom=0x40
	break
	call LABEL_6262
	sub [0x08], 0x0006
	video type=1, offset=CINEMATIC_077, x=[0x07], y=[0x08], zoom=0x40
	break
	call LABEL_6262
	video type=1, offset=CINEMATIC_078, x=[0x07], y=[0x08], zoom=0x40
	break
	call LABEL_6262
	sub [0x08], 0x0001
	video type=1, offset=CINEMATIC_079, x=[0x07], y=[0x08], zoom=0x40
	break
	call LABEL_6262
	sub [0x08], 0x0002
	video type=1, offset=CINEMATIC_078, x=[0x07], y=[0x08], zoom=0x40
	mov [0x29], 0x0001

LABEL_60AE:
	call LABEL_623B
	break
	call LABEL_6262
	video type=1, offset=CINEMATIC_077, x=[0x07], y=[0x08], zoom=0x40
	break
	call LABEL_6262
	video type=1, offset=CINEMATIC_078, x=[0x07], y=[0x08], zoom=0x40
	break
	call LABEL_6262
	video type=1, offset=CINEMATIC_079, x=[0x07], y=[0x08], zoom=0x40
	break
	call LABEL_6262
	video type=1, offset=CINEMATIC_076, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x29], LABEL_60AE
	break
	call ADVANCE_VAR0D_RESTORE_STATE__CART__POST_INLINE_SUB_VAR22_BY_23__CART__POST_INLINE_SUB_VAR22_BY_23
	play id=0x0059, freq=0x14, vol=0x20, channel=0x02
	video type=1, offset=CINEMATIC_130, x=[0x07], y=[0x08], zoom=0x40
	break
	call ADVANCE_VAR0D_RESTORE_STATE__CART__POST_INLINE_SUB_VAR22_BY_23__CART__POST_INLINE_SUB_VAR22_BY_23
	play id=0x0059, freq=0x16, vol=0x20, channel=0x00
	video type=1, offset=CINEMATIC_131, x=[0x07], y=[0x08], zoom=0x40
	break
	call ADVANCE_VAR0D_RESTORE_STATE__CART__POST_INLINE_SUB_VAR22_BY_23__CART__POST_INLINE_SUB_VAR22_BY_23
	video type=1, offset=CINEMATIC_132, x=[0x07], y=[0x08], zoom=0x40
	break
	call ADVANCE_VAR0D_RESTORE_STATE__CART__POST_INLINE_SUB_VAR22_BY_23__CART__POST_INLINE_SUB_VAR22_BY_23
	sub [0x08], 0x0003
	video type=1, offset=CINEMATIC_133, x=[0x07], y=[0x08], zoom=0x40
	break
	call ADVANCE_VAR0D_RESTORE_STATE__CART__POST_INLINE_SUB_VAR22_BY_23__CART__POST_INLINE_SUB_VAR22_BY_23
	video type=1, offset=CINEMATIC_132, x=[0x07], y=[0x08], zoom=0x40
	mov [0x29], 0x000A

LABEL_611A:
	mov [0xF8], [0x2B]
	and [0xF8], 0x00FF
	jl [0xF8], 0x02, LABEL_6138
	mov [0xF8], [0x29]
	and [0xF8], 0x0001
	je [0xF8], 0x01, LABEL_6138
	sub [0x2B], 0x0001

LABEL_6138:
	call LABEL_623B
	break
	call ADVANCE_VAR0D_RESTORE_STATE__CART__POST_INLINE_SUB_VAR22_BY_23__CART__POST_INLINE_SUB_VAR22_BY_23
	je [0x09], 0x01, LABEL_61A1
	video type=1, offset=CINEMATIC_135, x=[0x07], y=[0x08], zoom=0x40
	break
	call ADVANCE_VAR0D_RESTORE_STATE__CART__POST_INLINE_SUB_VAR22_BY_23__CART__POST_INLINE_SUB_VAR22_BY_23
	je [0x09], 0x01, LABEL_61A1
	video type=1, offset=CINEMATIC_136, x=[0x07], y=[0x08], zoom=0x40
	break
	call ADVANCE_VAR0D_RESTORE_STATE__CART__POST_INLINE_SUB_VAR22_BY_23__CART__POST_INLINE_SUB_VAR22_BY_23
	je [0x09], 0x01, LABEL_61A1
	video type=1, offset=CINEMATIC_133, x=[0x07], y=[0x08], zoom=0x40
	break
	call ADVANCE_VAR0D_RESTORE_STATE__CART__POST_INLINE_SUB_VAR22_BY_23__CART__POST_INLINE_SUB_VAR22_BY_23
	je [0x09], 0x01, LABEL_61A1
	sub [0x08], 0x0001
	video type=1, offset=CINEMATIC_133, x=[0x07], y=[0x08], zoom=0x40
	break
	call ADVANCE_VAR0D_RESTORE_STATE__CART__POST_INLINE_SUB_VAR22_BY_23__CART__POST_INLINE_SUB_VAR22_BY_23
	je [0x09], 0x01, LABEL_61A1
	video type=1, offset=CINEMATIC_136, x=[0x07], y=[0x08], zoom=0x40
	break
	call ADVANCE_VAR0D_RESTORE_STATE__CART__POST_INLINE_SUB_VAR22_BY_23__CART__POST_INLINE_SUB_VAR22_BY_23
	je [0x09], 0x01, LABEL_61A1
	video type=1, offset=CINEMATIC_135, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x29], LABEL_611A
	break
	call ADVANCE_VAR0D_RESTORE_STATE__CART__POST_INLINE_SUB_VAR22_BY_23__CART__POST_INLINE_SUB_VAR22_BY_23

LABEL_61A1:
	video type=1, offset=CINEMATIC_134, x=[0x07], y=[0x08], zoom=[0x96]	;@enc=alt
	play id=0x005B, freq=0x14, vol=0x40, channel=0x02
	play id=0x005B, freq=0x07, vol=0x40, channel=0x00
	mov [0x2B], 0x0FA0
	call LABEL_623B
	break
	jmp LABEL_6232
LABEL_61BE:
	db 0x11

LABEL_61BF:
	jg [0x27], [0x44], LABEL_61C9
	or [0x22], 0x1000

LABEL_61C9:
	jne [0x5B], 0x0FA0, LABEL_61EA
	jne [0x5E], 0x0FA0, LABEL_61EA
	jne [0x61], 0x0FA0, LABEL_61EA
	setup channel=0x30, address=LABEL_6229
	setup channel=0x31, address=LABEL_6232
	setup channel=0x32, address=LABEL_6232

LABEL_61EA:
	jne [0x5B], 0x0FA0, LABEL_61FF
	mov [0x5A], [0x21]
	mov [0x5B], [0x22]
	mov [0x5C], [0x29]
	setup channel=0x31, address=LABEL_606E
	ret

LABEL_61FF:
	jne [0x5E], 0x0FA0, LABEL_6214
	mov [0x5D], [0x21]
	mov [0x5E], [0x22]
	mov [0x5F], [0x29]
	setup channel=0x32, address=LABEL_606E
	ret

LABEL_6214:
	jne [0x61], 0x0FA0, LABEL_6228
	mov [0x60], [0x21]
	mov [0x61], [0x22]
	mov [0x62], [0x29]
	setup channel=0x33, address=LABEL_606E

LABEL_6228:
	ret

LABEL_6229:
	mov [0x0D], 0x0000
	break
	jmp LABEL_6229
LABEL_6231:
	db 0x11

LABEL_6232:
	add [0x0D], 0x0001
	break
	jmp LABEL_6232
LABEL_623A:
	db 0x11

LABEL_623B:
	jne [0x0D], 0x01, LABEL_6248
	mov [0x5C], [0x29]
	mov [0x5B], [0x2B]
	ret

LABEL_6248:
	jne [0x0D], 0x02, LABEL_6255
	mov [0x5F], [0x29]
	mov [0x5E], [0x2B]
	ret

LABEL_6255:
	jne [0x0D], 0x03, LABEL_6261
	mov [0x62], [0x29]
	mov [0x61], [0x2B]

LABEL_6261:
	ret

LABEL_6262:
	add [0x0D], 0x0001
	jne [0x0D], 0x01, LABEL_627F
	mov [0x21], [0x5A]
	mov [0x2B], [0x5B]
	mov [0x29], [0x5C]
	call LABEL_6300
	mov [0x5A], [0x07]
	mov [0x5B], [0x2B]
	ret

LABEL_627F:
	jne [0x0D], 0x02, LABEL_6298
	mov [0x21], [0x5D]
	mov [0x2B], [0x5E]
	mov [0x29], [0x5F]
	call LABEL_6300
	mov [0x5D], [0x07]
	mov [0x5E], [0x2B]
	ret

LABEL_6298:
	jne [0x0D], 0x03, LABEL_62B0
	mov [0x21], [0x60]
	mov [0x2B], [0x61]
	mov [0x29], [0x62]
	call LABEL_6300
	mov [0x60], [0x07]
	mov [0x61], [0x2B]

LABEL_62B0:
	ret

ADVANCE_VAR0D_RESTORE_STATE__CART__POST_INLINE_SUB_VAR22_BY_23__CART__POST_INLINE_SUB_VAR22_BY_23:
	add [0x0D], 0x0001
	jne [0x0D], 0x01, LABEL_62CE
	mov [0x21], [0x5A]
	mov [0x2B], [0x5B]
	mov [0x29], [0x5C]
	call LABEL_632A
	mov [0x5A], [0x07]
	mov [0x5B], [0x2B]
	ret

LABEL_62CE:
	jne [0x0D], 0x02, LABEL_62E7
	mov [0x21], [0x5D]
	mov [0x2B], [0x5E]
	mov [0x29], [0x5F]
	call LABEL_632A
	mov [0x5D], [0x07]
	mov [0x5E], [0x2B]
	ret

LABEL_62E7:
	jne [0x0D], 0x03, LABEL_62FF
	mov [0x21], [0x60]
	mov [0x2B], [0x61]
	mov [0x29], [0x62]
	call LABEL_632A
	mov [0x60], [0x07]
	mov [0x61], [0x2B]

LABEL_62FF:
	ret

LABEL_6300:
	call LABEL_638B
	mov [0x1D], 0x0000
	call LABEL_7E89
	je [0x1D], 0x00, SET_VARS_07_08
	jl [0x2B], 0x4000, INLINE_OR_VAR2B_WITH_4000
	and [0x2B], 0x3FFF
	jmp SET_VARS_07_08
