LABEL_875A:
	db 0x11

LABEL_875B:
	mov [0x21], [0x01]
	mov [0x23], [0x01]
	sub [0x21], [0x2A]
	add [0x23], [0x2A]
	mov [0x24], [0x02]
	add [0x24], [0x19]
	mov [0x22], [0x02]
	call LABEL_8777
	mov [0x02], [0x22]
	ret

LABEL_8777:
	je [HACK_VAR_67], 0x6F, LABEL_877E
	ret

LABEL_877E:
	mov [0x05], 0x0000
	jg [0x01], 0x8C, LABEL_87B0
	jg [0x01], 0x41, LABEL_8792
	mov [0x01], 0x0041

LABEL_8792:
	jl [0x01], 0x50, LABEL_879C
	mov [0x01], 0x0050

LABEL_879C:
	jg [0x22], 0x80, LABEL_87A5
	call SET_VAR18_TO_010E

LABEL_87A5:
	jg [0x22], 0x7A, SHARED_RET
	mov [0x22], 0x007A
	ret

LABEL_87B0:
	jg [0x01], 0xC8, LABEL_87BA
	mov [0x01], 0x00C8

LABEL_87BA:
	jl [0x01], 0xD2, LABEL_87C4
	mov [0x01], 0x00D2

LABEL_87C4:
	jg [0x22], 0x87, SHARED_RET
	mov [0x22], 0x0087
	ret

LABEL_87CF:
	je [0x63], 0x64, LABEL_8898
	je [0x05], 0x00, LABEL_8898
	jne [0x63], 0x01, LABEL_8808
	je [HERO_POS_MASK], 0x02, LABEL_8808
	jne [HERO_POS_MASK], 0x01, LABEL_87F0
	call INCREMENT_VAR31

LABEL_87F0:
	jl [0x05], 0x02, LABEL_8808
	jne [HERO_POS_MASK], 0x04, LABEL_87FF
	call INCREMENT_VAR31

LABEL_87FF:
	jne [HERO_POS_MASK], 0x08, LABEL_8808
	call INCREMENT_VAR31

LABEL_8808:
	jne [0x63], 0x02, LABEL_8835
	je [HERO_POS_MASK], 0x01, LABEL_8835
	jne [HERO_POS_MASK], 0x02, LABEL_881D
	call INCREMENT_VAR31

LABEL_881D:
	jl [0x05], 0x02, LABEL_8835
	jne [HERO_POS_MASK], 0x04, LABEL_882C
	call INCREMENT_VAR31

LABEL_882C:
	jne [HERO_POS_MASK], 0x08, LABEL_8835
	call INCREMENT_VAR31

LABEL_8835:
	jne [0x63], 0x03, LABEL_886A
	je [HERO_POS_MASK], 0x04, LABEL_886A
	jne [HERO_POS_MASK], 0x08, LABEL_884A
	call INCREMENT_VAR31

LABEL_884A:
	mov [0xF8], [0x05]
	and [0xF8], 0x0001
	je [0xF8], 0x00, LABEL_886A
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_8860
	call INCREMENT_VAR31

LABEL_8860:
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_886A
	call INCREMENT_VAR31

LABEL_886A:
	jne [0x63], 0x04, LABEL_8898
	je [HERO_POS_MASK], 0x08, LABEL_8898
	jne [HERO_POS_MASK], 0x04, LABEL_887F
	call INCREMENT_VAR31

LABEL_887F:
	je [0xF8], 0x00, LABEL_8898
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_888E
	call INCREMENT_VAR31

LABEL_888E:
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_8898
	call INCREMENT_VAR31

LABEL_8898:
	mov [0x32], 0x0009
	mov [0x21], [HERO_POS_LEFT_RIGHT]
	mov [0x22], [0x34]
	call LABEL_8B06
	mov [0x34], [0x22]
	add [0x01], [0x34]
	mov [0x21], [HERO_POS_JUMP_DOWN]
	mov [0x22], [0x35]
	call LABEL_8B06
	mov [0x35], [0x22]
	add [0x02], [0x35]
	add [0x02], 0x0001
	call LABEL_875B
	call LABEL_8A9D
	je [0x22], 0x03E8, LABEL_89AB
	je [0x22], 0x03E9, LABEL_8A24
	sub [0x18], 0x0001
	jl [0x18], 0x00, LABEL_181B
	call LABEL_88E4
	break
	jmp LABEL_87CF
LABEL_88E3:
	db 0x11

LABEL_88E4:
	mov [0xF8], [0x18]
	and [0xF8], 0x007F
	je [0xF8], 0x00, LABEL_893C
	je [0x18], 0x0190, LABEL_893C
	je [0x18], 0x012C, LABEL_893C
	je [0x18], 0xDC, LABEL_893C
	je [0x18], 0xAA, LABEL_893C
	je [0x18], 0x78, LABEL_893C
	je [0x18], 0x64, LABEL_893C
	je [0x18], 0x50, LABEL_893C
	je [0x18], 0x32, LABEL_893C
	je [0x18], 0x1E, LABEL_893C
	je [0x18], 0x0F, LABEL_893C
	je [0x18], 0x0A, LABEL_893C
	je [0x18], 0x05, LABEL_893C
	ret

LABEL_893C:
	mov [0x1A], [0x01]
	mov [0x1B], [0x02]
	jne [0x63], 0x02, LABEL_8953
	add [0x1A], 0x001E
	add [0x1B], 0x0000
	jmp SETUP_CHAN_0F_AT_RET

LABEL_8953:
	jne [0x63], 0x01, LABEL_8964
	sub [0x1A], 0x001E
	add [0x1B], 0x0000
	jmp SETUP_CHAN_0F_AT_RET

LABEL_8964:
	jne [0x63], 0x03, LABEL_8975
	add [0x1A], 0x0000
	add [0x1B], 0x001B
	jmp SETUP_CHAN_0F_AT_RET

LABEL_8975:
	jne [0x63], 0x04, SHARED_RET
	add [0x1A], 0x0000
	sub [0x1B], 0x000A

SETUP_CHAN_0F_AT_RET:
	setup channel=0x0F, address=LABEL_8988
	ret

LABEL_8988:
	video type=1, offset=CINEMATIC_324, x=[0x1a], y=[0x1b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_325, x=[0x1a], y=[0x1b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_326, x=[0x1a], y=[0x1b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_327, x=[0x1a], y=[0x1b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_328, x=[0x1a], y=[0x1b], zoom=0x40
	killChannel

SET_VAR18_TO_010E:
	mov [0x18], 0x010E
	ret

LABEL_89AB:
	deleteChannels first=0x15, last=0x16
	break
	jne [HACK_VAR_67], 0x6F, LABEL_89C4
	call LABEL_15C6
	call LABEL_15E3
	mov [0x01], 0x00E6
	mov [0x02], 0x007D

LABEL_89C4:
	jne [HACK_VAR_67], 0xED, LABEL_89D2
	mov [0x01], 0x00C8
	mov [0x02], 0x0050

LABEL_89D2:
	add [0x01], 0x000A
	video type=1, offset=CINEMATIC_308, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_309, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_310, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_311, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_312, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_313, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0002
	mov [PAUSE_SLICES], 0x0004
	mov [0x32], 0x0000
	setup channel=0x16, address=LABEL_8B45
	setup channel=0x14, address=LABEL_9158
	setup channel=0x3E, address=LABEL_81EF
	mov [0x01], 0x00D9
	jne [HACK_VAR_67], 0x6F, KILL_CHAN_AT_8A23
	setup channel=0x3E, address=LABEL_81EF
	mov [0x01], 0x010E

KILL_CHAN_AT_8A23:
	killChannel

LABEL_8A24:
	deleteChannels first=0x15, last=0x16
	call LABEL_15C6
	call LABEL_15E3
	break
	mov [0x01], 0x005A
	mov [0x02], 0x007D
	sub [0x01], 0x000A
	video type=1, offset=CINEMATIC_314, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_315, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_316, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_317, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_318, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_319, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0001
	mov [PAUSE_SLICES], 0x0004
	mov [0x32], 0x0000
	setup channel=0x16, address=LABEL_8B45
	setup channel=0x14, address=LABEL_9028
	setup channel=0x3E, address=LABEL_81EF
	mov [0x01], 0x003C
	killChannel
	jne [HACK_VAR_67], 0x6F, LABEL_8A8C
	jg [0x02], 0x8C, SHARED_RET
	mov [0x22], 0x03E8
	ret

LABEL_8A8C:
	jne [HACK_VAR_67], 0xED, SHARED_RET
	jg [0x02], 0x5A, SHARED_RET
	mov [0x22], 0x03E8
	ret

LABEL_8A9D:
	je [0x63], 0x03, SHARED_RET
	je [0x63], 0x64, SHARED_RET
	jne [HACK_VAR_67], 0x6F, LABEL_8AE3
	jg [0x02], 0x85, SHARED_RET
	mov [0xF8], [0x01]
	add [0xF8], [0x2A]
	jl [0xF8], 0xFF, LABEL_8ACC
	je [0x63], 0x01, SHARED_RET
	mov [0x22], 0x03E8
	ret

LABEL_8ACC:
	mov [0xF8], [0x01]
	sub [0xF8], [0x2A]
	jg [0xF8], 0x4B, SHARED_RET
	je [0x63], 0x02, SHARED_RET
	mov [0x22], 0x03E9
	ret

LABEL_8AE3:
	jne [HACK_VAR_67], 0xED, SHARED_RET
	jg [0x02], 0x55, SHARED_RET
	mov [0xF8], [0x01]
	add [0xF8], [0x2A]
	jl [0xF8], 0xD2, SHARED_RET
	je [0x63], 0x01, SHARED_RET
	mov [0x22], 0x03E8
	ret

LABEL_8B06:
	add [0x22], [0x21]
	add [0x22], [0x21]
	jle [0x22], 0x06, LABEL_8B16
	mov [0x22], 0x0006

LABEL_8B16:
	jge [0x22], 0xFFFA, LABEL_8B21
	mov [0x22], 0xFFFA

LABEL_8B21:
	jle [0x22], 0x00, LABEL_8B36
	sub [0x22], 0x0001
	jg [0x22], 0x00, SHARED_RET
	mov [0x22], 0x0000
	ret

LABEL_8B36:
	add [0x22], 0x0001
	jl [0x22], 0x00, SHARED_RET
	mov [0x22], 0x0000
	ret

LABEL_8B45:
	je [0x63], 0x64, LABEL_8C88
	jge [HERO_ACTION_POS_MASK], 0x80, LABEL_8BDE
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_8B70
	je [0x63], 0x01, LABEL_8B70
	setup channel=0x14, address=LABEL_9028
	je [0x63], 0x05, INLINE_SET_VAR63_TO_1
	setup channel=0x14, address=STEP_DRAW_CV352_LEFT4_RIGHT1
