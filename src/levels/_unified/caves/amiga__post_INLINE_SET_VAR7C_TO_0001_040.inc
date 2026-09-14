CAVES_FALLING_ROCK_SLOT_2_MEDIUM_LOOP:
	mov [0x07], [0x7A]
	mov [0x08], [0x7B]
	mov [0x09], [0x7C]
	call CAVES_FALLING_ROCK_PHYSICS_TICK
	call CAVES_FALLING_ROCK_MEDIUM_DRAW
	mov [0x7A], [0x07]
	mov [0x7B], [0x08]
	mov [0x7C], [0x09]
	break
	jmp CAVES_FALLING_ROCK_SLOT_2_MEDIUM_LOOP
LABEL_29A6:
	db 0x11

LABEL_29A7:
	video offset=CINEMATIC_604, x=[HERO_X], y=[HERO_Y]
	or [0x04], 0x4000
	break
	jmp LABEL_29A7

CAVES_FALLING_ROCK_PHYSICS_TICK:
	je [0x09], 0x00, SHARED_RET
	jg [0x09], 0x07, LABEL_2A46
	add [0x08], 0x0019
	mov [0x21], [0x07]
	mov [0x22], 0x00C8
	call CAVES_GROUND_MAP_DISPATCH
	jge [0x08], [0x22], INIT_VAR09_TO_7_VAR08_FROM_VAR22
	mov [0x21], [0x08]
	add [0x21], 0x0019
	jl [0x21], [0x22], LABEL_29E9
	mov [SCROLL_Y], 0x0001
	setup channel=0x3C, address=COMMIT_WORK_PAGE_TO_PAGE_3_AND_REFETCH

LABEL_29E9:
	mov [0xF8], [0x07]
	je [0x09], 0x02, SHARED_RET
	mov [0x21], [0x08]
	add [0x21], 0x0032
	jl [0x21], [0x22], SHARED_RET
	mov [0x09], 0x0002
	sub [0xF8], 0x0014
	jl [HERO_X], [0xF8], SHARED_RET
	add [0xF8], 0x0024
	jg [HERO_X], [0xF8], SHARED_RET
	jl [HERO_Y], 0x7C, SHARED_RET
	setup channel=0x3C, address=CAVES_ROCK_CRUSH_PALETTE_FLASH_FRAME
	deleteChannels first=0x14, last=0x16
	setup channel=0x14, address=LABEL_29A7
	mov [0x03], 0x000A
	jge [0x04], 0x4000, SHARED_RET
	setup channel=0x3F, address=CAVES_INLINE_SET_VAR01_TO_E_L1
	play id=0x007A, freq=0x14, vol=0x40, channel=0x01
	ret
