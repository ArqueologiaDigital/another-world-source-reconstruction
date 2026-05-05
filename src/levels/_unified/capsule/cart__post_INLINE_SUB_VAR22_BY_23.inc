LABEL_56F8:
	ret
LABEL_56F9:
	db 0x11

LABEL_56FA:
	call LABEL_590A
	sub [BUDDY_Y], 0x000A
	video offset=CINEMATIC_251, x=[BUDDY_X], y=[BUDDY_Y]
	break
	call LABEL_590A
	sub [BUDDY_Y], 0x0006
	video offset=CINEMATIC_252, x=[BUDDY_X], y=[BUDDY_Y]
	break
	call LABEL_590A
	video offset=CINEMATIC_253, x=[BUDDY_X], y=[BUDDY_Y]
	break
	call LABEL_590A
	sub [BUDDY_Y], 0x0001
	video offset=CINEMATIC_254, x=[BUDDY_X], y=[BUDDY_Y]
	break
	call LABEL_590A
	sub [BUDDY_Y], 0x0002
	video offset=CINEMATIC_253, x=[BUDDY_X], y=[BUDDY_Y]
	mov [0x29], 0x0001

LABEL_573A:
	call LABEL_58E3
	break
	call LABEL_590A
	video offset=CINEMATIC_252, x=[BUDDY_X], y=[BUDDY_Y]
	break
	call LABEL_590A
	video offset=CINEMATIC_253, x=[BUDDY_X], y=[BUDDY_Y]
	break
	call LABEL_590A
	video offset=CINEMATIC_254, x=[BUDDY_X], y=[BUDDY_Y]
	break
	call LABEL_590A
	video offset=CINEMATIC_251, x=[BUDDY_X], y=[BUDDY_Y]
	djnz [0x29], LABEL_573A
	break
	play id=0x0059, freq=0x14, vol=0x20, channel=0x02
	call LABEL_5959
	video offset=CINEMATIC_255, x=[BUDDY_X], y=[BUDDY_Y]
	break
	call LABEL_5959
	video offset=CINEMATIC_256, x=[BUDDY_X], y=[BUDDY_Y]
	break
	call LABEL_5959
	video offset=CINEMATIC_257, x=[BUDDY_X], y=[BUDDY_Y]
	break
	call LABEL_5959
	sub [BUDDY_Y], 0x0003
	video offset=CINEMATIC_258, x=[BUDDY_X], y=[BUDDY_Y]
	break
	call LABEL_5959
	video offset=CINEMATIC_257, x=[BUDDY_X], y=[BUDDY_Y]
	mov [0x29], 0x000A

LABEL_57A0:
	mov [0xF8], [0x2B]
	and [0xF8], 0x00FF
	jl [0xF8], 0x02, LABEL_57BE
	mov [0xF8], [0x29]
	and [0xF8], 0x0001
	je [0xF8], 0x01, LABEL_57BE
	sub [0x2B], 0x0001

LABEL_57BE:
	call LABEL_58E3
	break
	call LABEL_5959
	je [0x09], 0x01, LABEL_5827
	video offset=CINEMATIC_260, x=[BUDDY_X], y=[BUDDY_Y]
	break
	call LABEL_5959
	je [0x09], 0x01, LABEL_5827
	video offset=CINEMATIC_261, x=[BUDDY_X], y=[BUDDY_Y]
	break
	call LABEL_5959
	je [0x09], 0x01, LABEL_5827
	video offset=CINEMATIC_258, x=[BUDDY_X], y=[BUDDY_Y]
	break
	call LABEL_5959
	je [0x09], 0x01, LABEL_5827
	sub [BUDDY_Y], 0x0001
	video offset=CINEMATIC_258, x=[BUDDY_X], y=[BUDDY_Y]
	break
	call LABEL_5959
	je [0x09], 0x01, LABEL_5827
	video offset=CINEMATIC_261, x=[BUDDY_X], y=[BUDDY_Y]
	break
	call LABEL_5959
	je [0x09], 0x01, LABEL_5827
	video offset=CINEMATIC_260, x=[BUDDY_X], y=[BUDDY_Y]
	djnz [0x29], LABEL_57A0
	break
	call LABEL_5959

LABEL_5827:
	video offset=CINEMATIC_259, x=[BUDDY_X], y=[BUDDY_Y], zoom=[0x96]	;@enc=alt
	play id=0x005B, freq=0x02, vol=0x40, channel=0x03
	play id=0x005B, freq=0x14, vol=0x40, channel=0x02
	play id=0x005B, freq=0x02, vol=0x40, channel=0x01
	play id=0x005B, freq=0x14, vol=0x40, channel=0x00
	call LABEL_5854
	mov [0x2B], 0x0FA0
	call LABEL_58E3
	break
	jmp LABEL_58DA
LABEL_5853:
	db 0x11

LABEL_5854:
	mov [0xF8], [0xB9]
	and [0xF8], 0x0700
	jge [0xF8], 0x0400, SHARED_RET
	add [0xB9], 0x0100
	ret

LABEL_5867:
	jg [0x27], [0x44], LABEL_5871
	or [0x22], 0x1000

LABEL_5871:
	jne [0x5B], 0x0FA0, LABEL_5892
	jne [0x5E], 0x0FA0, LABEL_5892
	jne [0x61], 0x0FA0, LABEL_5892
	setup channel=0x30, address=LABEL_58D1
	setup channel=0x31, address=LABEL_58DA
	setup channel=0x32, address=LABEL_58DA

LABEL_5892:
	jne [0x5B], 0x0FA0, LABEL_58A7
	mov [0x5A], [0x21]
	mov [0x5B], [0x22]
	mov [0x5C], [0x29]
	setup channel=0x31, address=LABEL_56FA
	ret

LABEL_58A7:
	jne [0x5E], 0x0FA0, LABEL_58BC
	mov [0x5D], [0x21]
	mov [0x5E], [0x22]
	mov [0x5F], [0x29]
	setup channel=0x32, address=LABEL_56FA
	ret

LABEL_58BC:
	jne [0x61], 0x0FA0, LABEL_58D0
	mov [0x60], [0x21]
	mov [0x61], [0x22]
	mov [0x62], [0x29]
	setup channel=0x33, address=LABEL_56FA

LABEL_58D0:
	ret

LABEL_58D1:
	mov [0x0D], 0x0000
	break
	jmp LABEL_58D1
LABEL_58D9:
	db 0x11

LABEL_58DA:
	add [0x0D], 0x0001
	break
	jmp LABEL_58DA
LABEL_58E2:
	db 0x11

LABEL_58E3:
	jne [0x0D], 0x01, LABEL_58F0
	mov [0x5C], [0x29]
	mov [0x5B], [0x2B]
	ret

LABEL_58F0:
	jne [0x0D], 0x02, LABEL_58FD
	mov [0x5F], [0x29]
	mov [0x5E], [0x2B]
	ret

LABEL_58FD:
	jne [0x0D], 0x03, LABEL_5909
	mov [0x62], [0x29]
	mov [0x61], [0x2B]

LABEL_5909:
	ret

LABEL_590A:
	add [0x0D], 0x0001
	jne [0x0D], 0x01, LABEL_5927
	mov [0x21], [0x5A]
	mov [0x2B], [0x5B]
	mov [0x29], [0x5C]
	call LABEL_59B1
	mov [0x5A], [BUDDY_X]
	mov [0x5B], [0x2B]
	ret

LABEL_5927:
	jne [0x0D], 0x02, LABEL_5940
	mov [0x21], [0x5D]
	mov [0x2B], [0x5E]
	mov [0x29], [0x5F]
	call LABEL_59B1
	mov [0x5D], [BUDDY_X]
	mov [0x5E], [0x2B]
	ret

LABEL_5940:
	jne [0x0D], 0x03, LABEL_5958
	mov [0x21], [0x60]
	mov [0x2B], [0x61]
	mov [0x29], [0x62]
	call LABEL_59B1
	mov [0x60], [BUDDY_X]
	mov [0x61], [0x2B]

LABEL_5958:
	ret

LABEL_5959:
	add [0x0D], 0x0001
	jne [0x0D], 0x01, LABEL_5979
	mov [0x21], [0x5A]
	mov [0x2B], [0x5B]
	mov [0x29], [0x5C]
	call LABEL_59DB
	mov [0x5A], [BUDDY_X]
	mov [0x5B], [0x2B]
	call LABEL_73AE
	ret

LABEL_5979:
	jne [0x0D], 0x02, LABEL_5995
	mov [0x21], [0x5D]
	mov [0x2B], [0x5E]
	mov [0x29], [0x5F]
	call LABEL_59DB
	mov [0x5D], [BUDDY_X]
	mov [0x5E], [0x2B]
	call LABEL_73AE
	ret

LABEL_5995:
	jne [0x0D], 0x03, LABEL_59B0
	mov [0x21], [0x60]
	mov [0x2B], [0x61]
	mov [0x29], [0x62]
	call LABEL_59DB
	mov [0x60], [BUDDY_X]
	mov [0x61], [0x2B]
	call LABEL_73AE

LABEL_59B0:
	ret

LABEL_59B1:
	call LABEL_5A42
	mov [0x1D], 0x0000
	call LABEL_7514
	je [0x1D], 0x00, SET_VARS_07_08
	jl [0x2B], 0x4000, INLINE_OR_VAR2B_WITH_4000
	and [0x2B], 0x3FFF
	jmp SET_VARS_07_08
