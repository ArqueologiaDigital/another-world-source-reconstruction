LABEL_9128:
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	call LABEL_6CAE
	je [HERO_POS_MASK], 0x00, LABEL_90F3
	add [HERO_X], 0x0002
	break
	call LABEL_6CBF
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_9150
	je [HERO_POS_MASK], 0x00, LABEL_90EB
	add [HERO_X], 0x0001

LABEL_9150:
	add [HERO_X], 0x0001
	break
	call LABEL_6CD0
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_9168
	je [HERO_POS_MASK], 0x00, LABEL_90E3
	add [HERO_X], 0x0001

LABEL_9168:
	add [HERO_X], 0x0001
	break
	call LABEL_6CE1
	add [HERO_X], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_917E
	add [HERO_X], 0x0002

LABEL_917E:
	break
	call LABEL_6CF2
	add [HERO_X], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_9190
	add [HERO_X], 0x0001

LABEL_9190:
	break
	call LABEL_6D03
	play id=0x0060, freq=0x14, vol=0x20, channel=0x00
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_91A4
	add [HERO_X], 0x0002

LABEL_91A4:
	break
	call LABEL_6D14
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_91B2
	add [HERO_X], 0x0002

LABEL_91B2:
	call SET_VAR04_TO_0030
	break
	call LABEL_6D25
	jne [HERO_POS_MASK], 0x01, LABEL_91B2
	add [HERO_X], 0x0002
	break
	call LABEL_6D39
	je [HERO_POS_MASK], 0x00, LABEL_9112
	add [HERO_X], 0x0002
	break
	call LABEL_6BA7
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_91E5
	je [HERO_POS_MASK], 0x00, LABEL_910A
	add [HERO_X], 0x0001

LABEL_91E5:
	add [HERO_X], 0x0001
	break
	call LABEL_6C45
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_91FD
	je [HERO_POS_MASK], 0x00, LABEL_9102
	add [HERO_X], 0x0001

LABEL_91FD:
	add [HERO_X], 0x0001
	break
	call LABEL_6C56
	add [HERO_X], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_9213
	add [HERO_X], 0x0002

LABEL_9213:
	break
	call LABEL_6C67
	add [HERO_X], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_9225
	add [HERO_X], 0x0001

LABEL_9225:
	break
	call LABEL_6C78
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x00
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_9239
	add [HERO_X], 0x0002

LABEL_9239:
	break
	call LABEL_6C89
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_WALK_RIGHT_LOOP
	add [HERO_X], 0x0002

HERO_WALK_RIGHT_LOOP:
	break
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_9ABF
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_9638

LABEL_9255:
	call LABEL_6C9A
	call SET_VAR04_TO_0030
	jne [HERO_POS_MASK], 0x01, HERO_WALK_RIGHT_LOOP
	add [HERO_X], 0x0002
	break
	jmp LABEL_9128
LABEL_9269:
	db 0x11

LABEL_926A:
	break
	je [0x63], 0x05, LABEL_926A
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

LABEL_928F:
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_9296:
	db 0x11

LABEL_9297:
	sub [HERO_X], 0x0004
	video offset=CINEMATIC_568, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	je [HERO_POS_MASK], 0x00, LABEL_928F
	break

LABEL_92AB:
	call LABEL_6E5E
	je [HERO_POS_MASK], 0x00, LABEL_928F
	break
	je [HERO_POS_MASK], 0x00, LABEL_92AB

LABEL_92BB:
	setup channel=0x15, address=LABEL_926A
	sub [HERO_X], 0x0004

LABEL_92C3:
	call LABEL_7004
	call SET_VAR04_TO_0020
	mov [0x2A], 0x000F
	sub [HERO_X], 0x0006
	break
	call LABEL_7021
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_9599
	sub [HERO_X], 0x0008
	add [HERO_Y], 0x0000
	break
	call LABEL_7038
	sub [HERO_X], 0x0008
	break
	call LABEL_704F
	sub [HERO_X], 0x0008
	add [HERO_Y], 0x0000
	break
	call LABEL_7066
	add [HERO_Y], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_928F
	sub [HERO_X], 0x000A
	break

LABEL_930B:
	mov [0x63], 0x0005
	call LABEL_7075
	sub [HERO_X], 0x0006
	break
	call LABEL_7092
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_9599
	sub [HERO_X], 0x0008
	add [HERO_Y], 0x0000
	break
	call LABEL_70A9
	sub [HERO_X], 0x0008
	break
	call LABEL_70C0
	sub [HERO_X], 0x0008
	add [HERO_Y], 0x0000
	break
	call LABEL_70D7
	add [HERO_Y], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_928F
	sub [HERO_X], 0x000A
	break
	jmp LABEL_92C3
LABEL_9353:
	db 0x11

LABEL_9354:
	break
	je [0x63], 0x06, LABEL_9354
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

LABEL_9379:
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_9380:
	db 0x11

LABEL_9381:
	video offset=CINEMATIC_568, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0003
	je [HERO_POS_MASK], 0x00, LABEL_9379
	break

LABEL_9391:
	call LABEL_6C9A
	je [HERO_POS_MASK], 0x00, LABEL_9379
	break
	je [HERO_POS_MASK], 0x00, LABEL_9391

LABEL_93A1:
	setup channel=0x15, address=LABEL_9354
	add [HERO_X], 0x0004

LABEL_93A9:
	call LABEL_6F48
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	add [HERO_X], 0x0006
	break
	call LABEL_6F5F
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_96B8
	add [HERO_X], 0x0008
	break
	call LABEL_6F70
	add [HERO_X], 0x0008
	break
	call LABEL_6F81
	add [HERO_X], 0x0008
	break
	call LABEL_6F92
	je [HERO_POS_MASK], 0x00, LABEL_9379
	add [HERO_X], 0x000A
	break

LABEL_93E5:
	mov [0x63], 0x0006
	call LABEL_6FA3
	add [HERO_X], 0x0006
	break
	call LABEL_6FBA
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_96B8
	add [HERO_Y], 0x0000
	add [HERO_X], 0x0008
	break
	call LABEL_6FCB
	add [HERO_X], 0x0008
	break
	call LABEL_6FDC
	add [HERO_Y], 0x0000
	add [HERO_X], 0x0008
	break
	call LABEL_6FED
	add [HERO_Y], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_9379
	add [HERO_X], 0x000A
	break
	jmp LABEL_93A9
LABEL_942D:
	db 0x11

LABEL_942E:
	call SET_VAR04_TO_0020
	je [0x0A], 0x00, LABEL_947F
	mov [0x2A], 0x0021
	sub [HERO_X], 0x0001
	call HANDLE_HORIZ_VAR01_VS_VAR28
	sub [HERO_X], 0x0003
	video offset=CINEMATIC_558, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0001

LABEL_944F:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_9487
	call LABEL_6D68
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_944F
	break
	add [HERO_X], 0x0002
	video offset=CINEMATIC_558, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0002
	break
	video offset=CINEMATIC_557, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0001
	mov [0x0A], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_947E:
	db 0x11

LABEL_947F:
	mov [0x63], 0x0001
	jmp LABEL_90C6
LABEL_9486:
	db 0x11

LABEL_9487:
	jne [0x0F], 0x00, LABEL_94C3
	sub [HERO_X], 0x0002
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video offset=CINEMATIC_559, x=[HERO_X], y=[HERO_Y]
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	sub [0x21], 0x001E
	sub [0x27], 0x0027
	call LABEL_3795
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_558, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_944F
	setup channel=0x17, address=LABEL_44AF
