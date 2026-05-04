LABEL_CC52:
	jne [0x24], 0x00, LABEL_CC5F
	video type=1, offset=CINEMATIC_391, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CC5F:
	je [0x24], 0x02, DRAW_CIN_389
	video type=1, offset=CINEMATIC_390, x=[0x21], y=[0x22], zoom=[0x23]
	ret

DRAW_CIN_389:
	video type=1, offset=CINEMATIC_389, x=[0x21], y=[0x22], zoom=[0x23]
	ret

LABEL_CC73:
	mov [0x21], [0xE7]
	mov [0x22], [0xE8]
	mov [0x23], [0xE9]
	call LABEL_CC52
	mov [0x21], [0xEC]
	mov [0x22], 0x0082
	mov [0x23], 0x0020
	call LABEL_CC52
	mov [0x21], [0xED]
	mov [0x22], 0x0096
	mov [0x23], 0x0030
	call LABEL_CC52
	ret

LABEL_CC9C:
	break
	call LABEL_5F0A
	je [0x21], 0x00, LABEL_CC9C
	break
	break
	break
	break
	setup channel=0x05, address=INCR_VARE6_PLAY_FX55_2X_CH0_CH2

LABEL_CCAE:
	break
	break
	break
	break
	break
	break
	break
	break
	play id=0x0052, freq=0x1E, vol=0x40, channel=0x00
	mov [0x24], 0x0000
	call LABEL_CC73
	video type=1, offset=CINEMATIC_392, x=128, y=201, zoom=0x40
	break
	mov [0x24], 0x0001
	call LABEL_CC73
	video type=1, offset=CINEMATIC_392, x=88, y=161
	video type=1, offset=CINEMATIC_392, x=117, y=190
	break
	mov [0x24], 0x0002
	call LABEL_CC73
	mov [0x8B], 0x8001
	mov [0x96], 0x0046
	mov [0x97], 0x0094
	video type=1, offset=CINEMATIC_392, x=88, y=161
	break
	break
	break
	break
	mov [0x24], 0x0000
	call LABEL_CC73
	video type=1, offset=CINEMATIC_392, x=132, y=201, zoom=0x40
	break
	mov [0x24], 0x0001
	call LABEL_CC73
	video type=1, offset=CINEMATIC_392, x=92, y=161
	video type=1, offset=CINEMATIC_392, x=121, y=190
	break
	mov [0x24], 0x0002
	call LABEL_CC73
	mov [0x8B], 0x8001
	mov [0x96], 0x004C
	mov [0x97], 0x0094
	video type=1, offset=CINEMATIC_392, x=92, y=161
	break
	break
	break
	jmp LABEL_CCAE
LABEL_CD2E:
	db 0x11

HANG_DRAW_CIN_372:
	video type=1, offset=CINEMATIC_372, x=[0xe7], y=[0xe8], zoom=[0xe9]
	break
	jmp HANG_DRAW_CIN_372
LABEL_CD39:
	db 0x11

LABEL_CD3A:
	break
	break
	break
	add [0xE7], 0x0001
	break
	break
	break
	break
	break
	sub [0xE7], 0x0001
	break
	break
	break
	sub [0xE7], 0x0001
	break
	break
	break
	break
	break
	add [0xE7], 0x0001
	jmp LABEL_CD3A
LABEL_CD5D:
	db 0x11

DRAW_BULLET_FROM_VAR_E7_E8_E9:
	mov [0x21], [0xE7]
	mov [0x22], [0xE8]
	mov [0x23], [0xE9]
	call DRAW_CIN_387_IF_VAR_E6_VALID
	mov [0x21], [0xEC]
	mov [0x22], 0x0082
	mov [0x23], 0x0020
	sub [0xE6], 0x0001
	call DRAW_CIN_387_IF_VAR_E6_VALID
	mov [0x21], [0xED]
	mov [0x22], 0x0096
	mov [0x23], 0x0030
	sub [0xE6], 0x0001
	call DRAW_CIN_387_IF_VAR_E6_VALID
	add [0xE6], 0x0002
	ret

INCR_VARE6_PLAY_FX55_2X_CH0_CH2:
	add [0xE6], 0x0001
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	play id=0x0055, freq=0x1B, vol=0x14, channel=0x02

LABEL_CDA3:
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	jl [0xE6], 0x0E, INCR_VARE6_PLAY_FX55_2X_CH0_CH2
	jmp LABEL_CDA3

LABEL_CDB0:
	mov [0xE6], 0x0000
	call DRAW_BULLET_FROM_VAR_E7_E8_E9
	break
	jmp LABEL_CDB0
