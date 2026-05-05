ANIM_CIN_078_LOOP_VAR03_AT_3AB0:
	video offset=CINEMATIC_078, x=[HERO_X], y=[HERO_Y]
	break
	djnz [0x03], ANIM_CIN_078_LOOP_VAR03_AT_3AB0
	mov [0x63], 0x0001
	call SET_VAR04_TO_0020
	video offset=CINEMATIC_076, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_077, x=[HERO_X], y=[HERO_Y]
	jmp HERO_WALK_LEFT_LOOP
	killChannel
	mov [0x29], 0x0008
	mov [0x07], 0x012C
	mov [0x08], 0x000A

LABEL_3ADC:
	break
	call LABEL_3B29
	break
	call LABEL_3B29
	add [0x07], 0x0003
	break
	call LABEL_3B35
	break
	call LABEL_3B35
	add [0x07], 0x0003
	break
	call LABEL_3B41
	break
	call LABEL_3B41
	add [0x07], 0x0002
	break
	call LABEL_3B4D
	break
	call LABEL_3B4D
	add [0x07], 0x0003
	break
	call LABEL_3B59
	break
	call LABEL_3B59
	add [0x07], 0x0003
	break
	call LABEL_3B65
	break
	call LABEL_3B65
	add [0x07], 0x0003
	djnz [0x29], LABEL_3ADC
	killChannel

LABEL_3B29:
	jne [0x10], [HACK_VAR_67], SHARED_RET
	video offset=CINEMATIC_708, x=[0x07], y=[0x08]
	ret

LABEL_3B35:
	jne [0x10], [HACK_VAR_67], SHARED_RET
	video offset=CINEMATIC_709, x=[0x07], y=[0x08]
	ret

LABEL_3B41:
	jne [0x10], [HACK_VAR_67], SHARED_RET
	video offset=CINEMATIC_710, x=[0x07], y=[0x08]
	ret

LABEL_3B4D:
	jne [0x10], [HACK_VAR_67], SHARED_RET
	video offset=CINEMATIC_711, x=[0x07], y=[0x08]
	ret

LABEL_3B59:
	jne [0x10], [HACK_VAR_67], SHARED_RET
	video offset=CINEMATIC_712, x=[0x07], y=[0x08]
	ret

LABEL_3B65:
	jne [0x10], [HACK_VAR_67], SHARED_RET
	video offset=CINEMATIC_713, x=[0x07], y=[0x08]
	ret

LABEL_3B71:
	mov [0x21], 0x0000
	jne [0x22], 0x92, LABEL_3B84
	je [0xB8], 0x00, SHARED_RET
	mov [0x21], [0xB8]

LABEL_3B84:
	jne [0x22], 0x93, SHARED_RET
	je [0xB9], 0x00, SHARED_RET
	mov [0x21], [0xB9]
	ret

LABEL_3B94:
	mov [0x21], 0x0001
	jne [0xAA], 0xFFFF, SHARED_RET
	jne [0xAD], 0xFFFF, SHARED_RET
	mov [0x21], 0x0000
	ret
	mov [0x21], 0x0001
	jne [0xA1], 0xFFFF, SHARED_RET
	jne [0xA4], 0xFFFF, SHARED_RET
	jne [0xA7], 0xFFFF, SHARED_RET
	mov [0x21], 0x0000
	ret
