DRAW_CIN_694_695_PROGRESSIVE:
	video offset=CINEMATIC_694, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	break
	video offset=CINEMATIC_695, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0004
	break
	video offset=CINEMATIC_695, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0003
	break
	video offset=CINEMATIC_696, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0002
	break
	video offset=CINEMATIC_696, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	break
	video offset=CINEMATIC_695, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	mov [0x03], 0x0028

LABEL_3BA9:
	break
	video offset=CINEMATIC_422, x=[HERO_X], y=[HERO_Y]
	jmp LABEL_3BA9
LABEL_3BB2:
	db 0x11

PRISON_SHOT_RIGHT_IMPACT_RESOLVE:
	mov [0x21], [0x22]
	mov [0x13], 0x0001
	call PRISON_SET_VAR13_TO_FFFF_L1
	jne [0x13], 0xFFFF, PRISON_DRAW_CIN505_AT_X21_Y27_L33
	ret


PRISON_DRAW_CIN505_AT_X21_Y27_L33:
	and [0x13], 0x7FFF
	mov [0x0E], 0x0000
	call LABEL_3C15
	add [0x13], 0x0001
	or [0x13], 0x8000
	je [0x0E], 0x00, SHARED_RET
	or [0x27], 0x4000
	ret


LABEL_3BE3:
	db 0x11

PRISON_SHOT_LEFT_IMPACT_RESOLVE:
	mov [0x21], [0x22]
	mov [0x13], 0x0001
	call PRISON_SET_VAR13_TO_FFFF_L1
	jne [0x13], 0xFFFF, PRISON_DRAW_CIN505_AT_X21_Y27_L27
	ret


LABEL_3BF6:
	db 0x11

PRISON_DRAW_CIN505_AT_X21_Y27_L27:
	and [0x13], 0x7FFF
	mov [0x0E], 0x0001
	call PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L11
	add [0x13], 0x0001
	or [0x13], 0x8000
	je [0x0E], 0x00, SHARED_RET
	or [0x27], 0x4000
	ret


LABEL_3C15:
	jge [0x13], 0x64, PRISON_DRAW_CIN_483_L0
	jle [0x13], 0x03, PRISON_DRAW_CIN_486_L0
	jle [0x13], 0x05, LABEL_3C31
	video offset=CINEMATIC_488, x=[0x21], y=[0x27]
	mov [0x13], 0xFFFE
	ret


LABEL_3C31:
	jle [0x13], 0x04, DRAW_CIN_486
	video offset=CINEMATIC_487, x=[0x21], y=[0x27]
	ret