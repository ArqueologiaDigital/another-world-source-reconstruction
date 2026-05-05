LABEL_42A6:
	db 0x11

LABEL_42A7:
	call LABEL_424D
	jne [0x13], [0x0E], LABEL_435D
	mov [0x13], 0x0000
	je [0x0D], 0x00, LABEL_4306
	jg [0x0D], 0x02, LABEL_42ED
	jne [0x6A], [HACK_VAR_67], LABEL_42CF
	mov [0x24], [0x68]
	mov [0x25], [0x69]
	call LABEL_435F

LABEL_42CF:
	jne [0x72], [HACK_VAR_67], LABEL_42DE
	mov [0x24], [0x70]
	mov [0x25], [0x71]
	call LABEL_435F

LABEL_42DE:
	jne [0x7A], [HACK_VAR_67], LABEL_42ED
	mov [0x24], [0x78]
	mov [0x25], [0x79]
	call LABEL_435F

LABEL_42ED:
	jl [0x0D], 0x02, LABEL_4306
	mov [0x24], [HERO_X]
	mov [0x25], [HERO_Y]
	call LABEL_435F
	jne [0x0D], 0x03, LABEL_4306
	mov [0x13], 0x0001

LABEL_4306:
	jne [0x13], 0x01, LABEL_4320
	jge [0x29], 0x2000, LABEL_4331
	play id=0x005F, freq=0x1C, vol=0x40, channel=0x00
	add [0x29], 0x2000
	jmp LABEL_4331

LABEL_4320:
	jl [0x29], 0x2000, LABEL_4331
	sub [0x29], 0x2000
	play id=0x005F, freq=0x14, vol=0x40, channel=0x00

LABEL_4331:
	jl [0x29], 0x2000, LABEL_434C
	jl [0x09], 0x01, LABEL_435D
	sub [0x29], 0x0001
	sub [0x09], 0x0001
	call LABEL_438E
	jmp LABEL_435D

LABEL_434C:
	jg [0x09], 0x04, LABEL_435D
	add [0x29], 0x0001
	add [0x09], 0x0001
	call LABEL_438E

LABEL_435D:
	ret
LABEL_435E:
	db 0x11

LABEL_435F:
	jl [BUDDY_Y], [0x25], LABEL_438D
	add [0x25], 0x0014
	jg [BUDDY_Y], [0x25], LABEL_438D
	mov [0x21], [BUDDY_X]
	mov [0x22], [BUDDY_X]
	sub [0x21], 0x001E
	add [0x22], 0x0032
	jl [0x24], [0x21], LABEL_438D
	jg [0x24], [0x22], LABEL_438D
	mov [0x13], 0x0001

LABEL_438D:
	ret

LABEL_438E:
	mov [0x26], [BUDDY_X]
	jne [0x10], 0x01, LABEL_439A
	call LABEL_43B6

LABEL_439A:
	add [0x26], 0x000A
	jne [0x11], 0x01, LABEL_43A7
	call LABEL_43B6

LABEL_43A7:
	add [0x26], 0x000A
	jne [0x12], 0x01, LABEL_43B4
	call LABEL_43B6

LABEL_43B4:
	ret
LABEL_43B5:
	db 0x11

LABEL_43B6:
	jne [0x09], 0x01, LABEL_43C2
	ret
	video offset=CINEMATIC_695, x=[0x26], y=[BUDDY_Y]

LABEL_43C2:
	jne [0x09], 0x02, LABEL_43CE
	video offset=CINEMATIC_697, x=[0x26], y=[BUDDY_Y]
	ret

LABEL_43CE:
	jne [0x09], 0x03, LABEL_43E3
	selectVideoPage 0x00
	video offset=CINEMATIC_695, x=[0x26], y=[BUDDY_Y]
	selectVideoPage 0xFF
	video offset=CINEMATIC_696, x=[0x26], y=[BUDDY_Y]
	ret

LABEL_43E3:
	jne [0x09], 0x04, LABEL_43F8
	selectVideoPage 0x00
	video offset=CINEMATIC_500, x=[0x26], y=[BUDDY_Y]
	selectVideoPage 0xFF
	video offset=CINEMATIC_500, x=[0x26], y=[BUDDY_Y]
	ret

LABEL_43F8:
	ret
LABEL_43F9:
	db 0x11

LABEL_43FA:
	je [0x49], 0x7FFF, LABEL_4414
	jge [0x49], 0x4000, LABEL_4414
	mov [BUDDY_X], [0x48]
	mov [0x09], [0x49]
	call LABEL_42A7
	mov [0x49], [0x29]

LABEL_4414:
	je [0x4B], 0x7FFF, LABEL_442E
	jge [0x4B], 0x4000, LABEL_442E
	mov [BUDDY_X], [0x4A]
	mov [0x09], [0x4B]
	call LABEL_42A7
	mov [0x4B], [0x29]

LABEL_442E:
	je [0x4D], 0x7FFF, LABEL_4448
	jge [0x4D], 0x4000, LABEL_4448
	mov [BUDDY_X], [0x4C]
	mov [0x09], [0x4D]
	call LABEL_42A7
	mov [0x4D], [0x29]

LABEL_4448:
	break
	jmp LABEL_43FA
LABEL_444C:
	db 0x11

LABEL_444D:
	je [0x49], 0x7FFF, LABEL_445D
	mov [BUDDY_X], [0x48]
	mov [0x09], [0x49]
	call LABEL_447E

LABEL_445D:
	je [0x4B], 0x7FFF, LABEL_446D
	mov [BUDDY_X], [0x4A]
	mov [0x09], [0x4B]
	call LABEL_447E

LABEL_446D:
	je [0x4D], 0x7FFF, SHARED_RET
	mov [BUDDY_X], [0x4C]
	mov [0x09], [0x4D]
	call LABEL_447E
	ret

LABEL_447E:
	call LABEL_424D
	call LABEL_4485
	ret

LABEL_4485:
	video offset=CINEMATIC_499, x=[BUDDY_X], y=[BUDDY_Y]
	jne [0x10], 0x01, LABEL_4495
	video offset=CINEMATIC_500, x=[BUDDY_X], y=[BUDDY_Y]

LABEL_4495:
	add [BUDDY_X], 0x000A
	jl [0x0E], 0x02, SHARED_RET
	video offset=CINEMATIC_499, x=[BUDDY_X], y=[BUDDY_Y]
	jne [0x11], 0x01, LABEL_44AF
	video offset=CINEMATIC_500, x=[BUDDY_X], y=[BUDDY_Y]

LABEL_44AF:
	add [BUDDY_X], 0x000A
	jl [0x0E], 0x03, SHARED_RET
	video offset=CINEMATIC_499, x=[BUDDY_X], y=[BUDDY_Y]
	jne [0x12], 0x01, SHARED_RET
	video offset=CINEMATIC_500, x=[BUDDY_X], y=[BUDDY_Y]
	ret
LABEL_44CA:
	db 0x11

LABEL_44CB:
	jl [BUDDY_X], 0x0150, LABEL_44EE
	mov [0x2C], [0x10]
	add [0x10], 0x0001
	sub [0x29], 0x0154
	sub [BUDDY_X], 0x015F
	jne [0x10], 0x8F, LABEL_4504
	mov [0x10], 0x006F
	jmp LABEL_4504

LABEL_44EE:
	jg [BUDDY_X], 0xFFF0, LABEL_4524
	mov [0x2C], [0x10]
	sub [0x10], 0x0001
	add [0x29], 0x0154
	add [BUDDY_X], 0x015F

LABEL_4504:
	mov [0x27], [0x2C]
	call LABEL_7383
	mov [BUDDY_Y], [0x22]
	ret
	mov [0x2C], [0x21]
	mov [0x27], [0x10]
	call LABEL_7383
	jne [BUDDY_Y], [0x2C], INLINE_COPY_VAR22_TO_VAR08
	mov [BUDDY_Y], [0x21]
	ret
