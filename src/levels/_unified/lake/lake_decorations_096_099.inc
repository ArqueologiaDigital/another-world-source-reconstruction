;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_VINE_DECOR_0		EQU 0x8A3E
CINEMATIC_VINE_DECOR_1		EQU 0x8A8E
CINEMATIC_VINE_DECOR_2		EQU 0x8ADE
CINEMATIC_VINE_DECOR_3		EQU 0x8B2E
;@endif
;@if BRANCH == "chahi_amiga_1991"
CINEMATIC_VINE_DECOR_0		EQU 0x9E4E
CINEMATIC_VINE_DECOR_1		EQU 0x9E9E
CINEMATIC_VINE_DECOR_2		EQU 0x9EEE
CINEMATIC_VINE_DECOR_3		EQU 0x9F3E
;@endif

LESTER_VINE_SWING_INIT:
	setup channel=0x04, address=DRAW_VINE_DECOR_0_LOOP
	break
	setup channel=0x04, address=LOOP_DRAW_LAKE_097_DECOR_AT_71_171
	break
	setup channel=0x04, address=DRAW_VINE_DECOR_2_LOOP
	break

LESTER_VINE_SWING_CYCLE:
	setup channel=0x04, address=DRAW_VINE_DECOR_3_LOOP
	break
	break
	break
	setup channel=0x04, address=DRAW_VINE_DECOR_2_LOOP
	break
	break
	setup channel=0x04, address=LOOP_DRAW_LAKE_097_DECOR_AT_71_171
	break
	break
	setup channel=0x04, address=DRAW_VINE_DECOR_0_LOOP
	break
	break
	break
	setup channel=0x04, address=LOOP_DRAW_LAKE_097_DECOR_AT_71_171
	break
	break
	setup channel=0x04, address=DRAW_VINE_DECOR_2_LOOP
	break
	break
	jmp LESTER_VINE_SWING_CYCLE
	killChannel

DRAW_VINE_DECOR_0_LOOP:
	video offset=CINEMATIC_VINE_DECOR_0, x=160, y=100
	mov [HERO_X], 0x0048
	mov [HERO_Y], 0x00AB
	break
	jmp DRAW_VINE_DECOR_0_LOOP
	killChannel

LOOP_DRAW_LAKE_097_DECOR_AT_71_171:
	video offset=CINEMATIC_VINE_DECOR_1, x=160, y=100
	mov [HERO_X], 0x0047
	mov [HERO_Y], 0x00AB
	break
	jmp LOOP_DRAW_LAKE_097_DECOR_AT_71_171
	killChannel

DRAW_VINE_DECOR_2_LOOP:
	video offset=CINEMATIC_VINE_DECOR_2, x=160, y=100
	mov [HERO_X], 0x0046
	mov [HERO_Y], 0x00AC
	break
	jmp DRAW_VINE_DECOR_2_LOOP
	killChannel

DRAW_VINE_DECOR_3_LOOP:
	video offset=CINEMATIC_VINE_DECOR_3, x=160, y=100
	mov [HERO_X], 0x0045
	mov [HERO_Y], 0x00AC
	break
	jmp DRAW_VINE_DECOR_3_LOOP
	killChannel

