LABEL_42D4:
	db 0x11

LABEL_42D5:
	call LABEL_427B
	jne [0x13], [0x0E], LABEL_438B
	mov [0x13], 0x0000
	je [0x0D], 0x00, LABEL_4334
	jg [0x0D], 0x02, LABEL_431B
	jne [0x6A], [HACK_VAR_67], LABEL_42FD
	mov [0x24], [0x68]
	mov [0x25], [0x69]
	call LABEL_438D

LABEL_42FD:
	jne [0x72], [HACK_VAR_67], LABEL_430C
	mov [0x24], [0x70]
	mov [0x25], [0x71]
	call LABEL_438D

LABEL_430C:
	jne [0x7A], [HACK_VAR_67], LABEL_431B
	mov [0x24], [0x78]
	mov [0x25], [0x79]
	call LABEL_438D

LABEL_431B:
	jl [0x0D], 0x02, LABEL_4334
	mov [0x24], [HERO_X]
	mov [0x25], [HERO_Y]
	call LABEL_438D
	jne [0x0D], 0x03, LABEL_4334
	mov [0x13], 0x0001

LABEL_4334:
	jne [0x13], 0x01, LABEL_434E
	jge [0x29], 0x2000, LABEL_435F
	play id=0x005F, freq=0x1C, vol=0x40, channel=0x00
	add [0x29], 0x2000
	jmp LABEL_435F

LABEL_434E:
	jl [0x29], 0x2000, LABEL_435F
	sub [0x29], 0x2000
	play id=0x005F, freq=0x14, vol=0x40, channel=0x00

LABEL_435F:
	jl [0x29], 0x2000, LABEL_437A
	jl [0x09], 0x01, LABEL_438B
	sub [0x29], 0x0001
	sub [0x09], 0x0001
	call LABEL_43B2
	jmp LABEL_438B

LABEL_437A:
	jg [0x09], 0x04, LABEL_438B
	add [0x29], 0x0001
	add [0x09], 0x0001
	call LABEL_43B2

LABEL_438B:
	ret
LABEL_438C:
	db 0x11

LABEL_438D:
	jne [BUDDY_Y], [0x25], LABEL_43B1
	mov [0x21], [BUDDY_X]
	mov [0x22], [BUDDY_X]
	sub [0x21], 0x001E
	add [0x22], 0x0032
	jl [0x24], [0x21], LABEL_43B1
	jg [0x24], [0x22], LABEL_43B1
	mov [0x13], 0x0001

LABEL_43B1:
	ret

LABEL_43B2:
	mov [0x26], [BUDDY_X]
	jne [0x10], 0x01, LABEL_43BE
	call LABEL_43DA

LABEL_43BE:
	add [0x26], 0x000A
	jne [0x11], 0x01, LABEL_43CB
	call LABEL_43DA

LABEL_43CB:
	add [0x26], 0x000A
	jne [0x12], 0x01, LABEL_43D8
	call LABEL_43DA

LABEL_43D8:
	ret
LABEL_43D9:
	db 0x11

LABEL_43DA:
	jne [0x09], 0x01, LABEL_43E6
	ret
	video offset=CINEMATIC_686, x=[0x26], y=[BUDDY_Y]

LABEL_43E6:
	jne [0x09], 0x02, LABEL_43F2
	video offset=CINEMATIC_688, x=[0x26], y=[BUDDY_Y]
	ret

LABEL_43F2:
	jne [0x09], 0x03, LABEL_4407
	selectVideoPage 0x00
	video offset=CINEMATIC_686, x=[0x26], y=[BUDDY_Y]
	selectVideoPage 0xFF
	video offset=CINEMATIC_687, x=[0x26], y=[BUDDY_Y]
	ret

LABEL_4407:
	jne [0x09], 0x04, LABEL_441C
	selectVideoPage 0x00
	video offset=CINEMATIC_497, x=[0x26], y=[BUDDY_Y]
	selectVideoPage 0xFF
	video offset=CINEMATIC_497, x=[0x26], y=[BUDDY_Y]
	ret

LABEL_441C:
	ret
LABEL_441D:
	db 0x11

LABEL_441E:
	je [0x49], 0x7FFF, LABEL_4438
	jge [0x49], 0x4000, LABEL_4438
	mov [BUDDY_X], [0x48]
	mov [0x09], [0x49]
	call LABEL_42D5
	mov [0x49], [0x29]

LABEL_4438:
	je [0x4B], 0x7FFF, LABEL_4452
	jge [0x4B], 0x4000, LABEL_4452
	mov [BUDDY_X], [0x4A]
	mov [0x09], [0x4B]
	call LABEL_42D5
	mov [0x4B], [0x29]

LABEL_4452:
	je [0x4D], 0x7FFF, LABEL_446C
	jge [0x4D], 0x4000, LABEL_446C
	mov [BUDDY_X], [0x4C]
	mov [0x09], [0x4D]
	call LABEL_42D5
	mov [0x4D], [0x29]

LABEL_446C:
	break
	jmp LABEL_441E
LABEL_4470:
	db 0x11

LABEL_4471:
	je [0x49], 0x7FFF, LABEL_4481
	mov [BUDDY_X], [0x48]
	mov [0x09], [0x49]
	call LABEL_44A2

LABEL_4481:
	je [0x4B], 0x7FFF, LABEL_4491
	mov [BUDDY_X], [0x4A]
	mov [0x09], [0x4B]
	call LABEL_44A2

LABEL_4491:
	je [0x4D], 0x7FFF, SHARED_RET
	mov [BUDDY_X], [0x4C]
	mov [0x09], [0x4D]
	call LABEL_44A2
	ret

LABEL_44A2:
	call LABEL_427B
	call LABEL_44A9
	ret

LABEL_44A9:
	video offset=CINEMATIC_496, x=[BUDDY_X], y=[BUDDY_Y]
	jne [0x10], 0x01, LABEL_44B9
	video offset=CINEMATIC_497, x=[BUDDY_X], y=[BUDDY_Y]

LABEL_44B9:
	add [BUDDY_X], 0x000A
	jl [0x0E], 0x02, SHARED_RET
	video offset=CINEMATIC_496, x=[BUDDY_X], y=[BUDDY_Y]
	jne [0x11], 0x01, LABEL_44D3
	video offset=CINEMATIC_497, x=[BUDDY_X], y=[BUDDY_Y]

LABEL_44D3:
	add [BUDDY_X], 0x000A
	jl [0x0E], 0x03, SHARED_RET
	video offset=CINEMATIC_496, x=[BUDDY_X], y=[BUDDY_Y]
	jne [0x12], 0x01, SHARED_RET
	video offset=CINEMATIC_497, x=[BUDDY_X], y=[BUDDY_Y]
	ret
LABEL_44EE:
	db 0x11

LABEL_44EF:
	jl [BUDDY_X], 0x0150, LABEL_4512
	mov [0x2C], [0x10]
	add [0x10], 0x0001
	sub [0x29], 0x0154
	sub [BUDDY_X], 0x015F
	jne [0x10], 0x8F, LABEL_4528
	mov [0x10], 0x006F
	jmp LABEL_4528

LABEL_4512:
	jg [BUDDY_X], 0xFFF0, LABEL_4548
	mov [0x2C], [0x10]
	sub [0x10], 0x0001
	add [0x29], 0x0154
	add [BUDDY_X], 0x015F

LABEL_4528:
	mov [0x27], [0x2C]
	call LABEL_731A
	mov [BUDDY_Y], [0x22]
	ret
	mov [0x2C], [0x21]
	mov [0x27], [0x10]
	call LABEL_731A
	jne [BUDDY_Y], [0x2C], INLINE_COPY_VAR22_TO_VAR08
	mov [BUDDY_Y], [0x21]
	ret
