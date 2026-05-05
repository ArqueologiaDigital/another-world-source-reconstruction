LABEL_8F62:
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	call LABEL_6C01
	je [HERO_POS_MASK], 0x00, LABEL_8F2D
	add [HERO_X], 0x0002
	break
	call LABEL_6C12
	je [HERO_POS_MASK], 0x00, LABEL_8F25
	add [HERO_X], 0x0002
	break
	call LABEL_6C23
	je [HERO_POS_MASK], 0x00, LABEL_8F1D
	add [HERO_X], 0x0002
	break
	call LABEL_6C34
	add [HERO_X], 0x0003
	break
	call LABEL_6C45
	add [HERO_X], 0x0002
	break
	call LABEL_6C56
	play id=0x0060, freq=0x14, vol=0x20, channel=0x00
	add [HERO_X], 0x0002
	break
	call LABEL_6C67
	add [HERO_X], 0x0002

LABEL_8FB8:
	break
	call SET_VAR04_TO_0030
	call LABEL_6C78
	jne [HERO_POS_MASK], 0x01, LABEL_8FB8
	add [HERO_X], 0x0002
	break
	call LABEL_6C8C
	je [HERO_POS_MASK], 0x00, LABEL_8F4C
	add [HERO_X], 0x0002
	break
	call LABEL_6AFA
	je [HERO_POS_MASK], 0x00, LABEL_8F44
	add [HERO_X], 0x0002
	break
	call LABEL_6B98
	je [HERO_POS_MASK], 0x00, LABEL_8F3C
	add [HERO_X], 0x0002
	break
	call LABEL_6BA9
	add [HERO_X], 0x0003
	break
	call LABEL_6BBA
	add [HERO_X], 0x0002
	break
	call LABEL_6BCB
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x00
	add [HERO_X], 0x0002
	break
	call LABEL_6BDC
	add [HERO_X], 0x0002

HERO_WALK_LOOP:
	break
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_9865
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_93F4

LABEL_9027:
	call LABEL_6BED
	call SET_VAR04_TO_0030
	jne [HERO_POS_MASK], 0x01, HERO_WALK_LOOP
	add [HERO_X], 0x0002
	break
	jmp LABEL_8F62
LABEL_903B:
	db 0x11

LABEL_903C:
	break
	je [0x63], 0x05, LABEL_903C
	sub [HERO_X], 0x0003
	break
	sub [HERO_X], 0x0002
	break
	sub [HERO_X], 0x0002
	break
	sub [HERO_X], 0x0001
	break
	sub [HERO_X], 0x0001
	break
	sub [HERO_X], 0x0001
	killChannel

LABEL_9061:
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_9068:
	db 0x11

LABEL_9069:
	sub [HERO_X], 0x0004
	video offset=CINEMATIC_568, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	je [HERO_POS_MASK], 0x00, LABEL_9061
	break

LABEL_907D:
	call LABEL_6DB1
	je [HERO_POS_MASK], 0x00, LABEL_9061
	break
	je [HERO_POS_MASK], 0x00, LABEL_907D

LABEL_908D:
	setup channel=0x15, address=LABEL_903C
	sub [HERO_X], 0x0004

LABEL_9095:
	call LABEL_6F57
	call SET_VAR04_TO_0020
	mov [0x2A], 0x000F
	sub [HERO_X], 0x0006
	break
	call LABEL_6F74
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_9365
	sub [HERO_X], 0x0008
	add [HERO_Y], 0x0000
	break
	call LABEL_6F8B
	sub [HERO_X], 0x0008
	break
	call LABEL_6FA2
	sub [HERO_X], 0x0008
	add [HERO_Y], 0x0000
	break
	call LABEL_6FB9
	add [HERO_Y], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_9061
	sub [HERO_X], 0x000A
	break

LABEL_90DD:
	mov [0x63], 0x0005
	call LABEL_6FC8
	sub [HERO_X], 0x0006
	break
	call LABEL_6FE5
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_9365
	sub [HERO_X], 0x0008
	add [HERO_Y], 0x0000
	break
	call LABEL_6FFC
	sub [HERO_X], 0x0008
	break
	call LABEL_7013
	sub [HERO_X], 0x0008
	add [HERO_Y], 0x0000
	break
	call LABEL_702A
	add [HERO_Y], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_9061
	sub [HERO_X], 0x000A
	break
	jmp LABEL_9095
LABEL_9125:
	db 0x11

LABEL_9126:
	break
	je [0x63], 0x06, LABEL_9126
	add [HERO_X], 0x0003
	break
	add [HERO_X], 0x0002
	break
	add [HERO_X], 0x0002
	break
	add [HERO_X], 0x0001
	break
	add [HERO_X], 0x0001
	break
	add [HERO_X], 0x0001
	killChannel

LABEL_914B:
	mov [0x63], 0x0002
	jmp HERO_WALK_LOOP
LABEL_9152:
	db 0x11

LABEL_9153:
	video offset=CINEMATIC_568, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0003
	je [HERO_POS_MASK], 0x00, LABEL_914B
	break

LABEL_9163:
	call LABEL_6BED
	je [HERO_POS_MASK], 0x00, LABEL_914B
	break
	je [HERO_POS_MASK], 0x00, LABEL_9163

LABEL_9173:
	setup channel=0x15, address=LABEL_9126
	add [HERO_X], 0x0004

LABEL_917B:
	call LABEL_6E9B
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	add [HERO_X], 0x0006
	break
	call LABEL_6EB2
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_946E
	add [HERO_X], 0x0008
	break
	call LABEL_6EC3
	add [HERO_X], 0x0008
	break
	call LABEL_6ED4
	add [HERO_X], 0x0008
	break
	call LABEL_6EE5
	je [HERO_POS_MASK], 0x00, LABEL_914B
	add [HERO_X], 0x000A
	break

LABEL_91B7:
	mov [0x63], 0x0006
	call LABEL_6EF6
	add [HERO_X], 0x0006
	break
	call LABEL_6F0D
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_946E
	add [HERO_Y], 0x0000
	add [HERO_X], 0x0008
	break
	call LABEL_6F1E
	add [HERO_X], 0x0008
	break
	call LABEL_6F2F
	add [HERO_Y], 0x0000
	add [HERO_X], 0x0008
	break
	call LABEL_6F40
	add [HERO_Y], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_914B
	add [HERO_X], 0x000A
	break
	jmp LABEL_917B
LABEL_91FF:
	db 0x11

LABEL_9200:
	call SET_VAR04_TO_0020
	je [0x0A], 0x00, LABEL_9251
	mov [0x2A], 0x0021
	sub [HERO_X], 0x0001
	call HANDLE_HORIZ_VAR01_VS_VAR28
	sub [HERO_X], 0x0003
	video offset=CINEMATIC_558, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0001

LABEL_9221:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_9259
	call LABEL_6CBB
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_9221
	break
	add [HERO_X], 0x0002
	video offset=CINEMATIC_558, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0002
	break
	video offset=CINEMATIC_557, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0001
	mov [0x0A], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_9250:
	db 0x11

LABEL_9251:
	mov [0x63], 0x0001
	jmp LABEL_8F00
LABEL_9258:
	db 0x11

LABEL_9259:
	jne [0x0F], 0x00, LABEL_9295
	sub [HERO_X], 0x0002
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video offset=CINEMATIC_559, x=[HERO_X], y=[HERO_Y]
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	sub [0x21], 0x001E
	sub [0x27], 0x0027
	call LABEL_3733
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_558, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_9221
	setup channel=0x17, address=LABEL_444D
