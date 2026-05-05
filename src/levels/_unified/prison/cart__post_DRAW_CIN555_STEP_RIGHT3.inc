LABEL_928E:
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	call LABEL_6DB1
	je [HERO_POS_MASK], 0x00, LABEL_9259
	add [0x01], 0x0002
	break
	call LABEL_6DC2
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_92B6
	je [HERO_POS_MASK], 0x00, LABEL_9251
	add [0x01], 0x0001

LABEL_92B6:
	add [0x01], 0x0001
	break
	call LABEL_6DD3
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_92CE
	je [HERO_POS_MASK], 0x00, LABEL_9249
	add [0x01], 0x0001

LABEL_92CE:
	add [0x01], 0x0001
	break
	call LABEL_6DE4
	add [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_92E4
	add [0x01], 0x0002

LABEL_92E4:
	break
	call LABEL_6DF5
	add [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_92F6
	add [0x01], 0x0001

LABEL_92F6:
	break
	call LABEL_6E06
	play id=0x0060, freq=0x14, vol=0x20, channel=0x00
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_930A
	add [0x01], 0x0002

LABEL_930A:
	break
	call LABEL_6E17
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_9318
	add [0x01], 0x0002

LABEL_9318:
	call SET_VAR04_TO_0030
	break
	call LABEL_6E28
	jne [HERO_POS_MASK], 0x01, LABEL_9318
	add [0x01], 0x0002
	break
	call LABEL_6E3C
	je [HERO_POS_MASK], 0x00, LABEL_9278
	add [0x01], 0x0002
	break
	call LABEL_6CAA
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_934B
	je [HERO_POS_MASK], 0x00, LABEL_9270
	add [0x01], 0x0001

LABEL_934B:
	add [0x01], 0x0001
	break
	call LABEL_6D48
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_9363
	je [HERO_POS_MASK], 0x00, LABEL_9268
	add [0x01], 0x0001

LABEL_9363:
	add [0x01], 0x0001
	break
	call LABEL_6D59
	add [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_9379
	add [0x01], 0x0002

LABEL_9379:
	break
	call LABEL_6D6A
	add [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_938B
	add [0x01], 0x0001

LABEL_938B:
	break
	call LABEL_6D7B
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x00
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_939F
	add [0x01], 0x0002

LABEL_939F:
	break
	call LABEL_6D8C
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_WALK_RIGHT_LOOP
	add [0x01], 0x0002

HERO_WALK_RIGHT_LOOP:
	break
	je [HERO_POS_MASK], 0x04, LABEL_9C49
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_97A4

LABEL_93BB:
	call LABEL_6D9D
	call SET_VAR04_TO_0030
	jne [HERO_POS_MASK], 0x01, HERO_WALK_RIGHT_LOOP
	add [0x01], 0x0002
	break
	jmp LABEL_928E
LABEL_93CF:
	db 0x11

LABEL_93D0:
	break
	je [0x63], 0x05, LABEL_93D0
	sub [0x01], 0x0003
	break
	sub [0x01], 0x0002
	break
	sub [0x01], 0x0002
	break
	sub [0x01], 0x0001
	break
	sub [0x01], 0x0001
	break
	sub [0x01], 0x0001
	killChannel

LABEL_93F5:
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_93FC:
	db 0x11

LABEL_93FD:
	sub [0x01], 0x0004
	video offset=CINEMATIC_568, x=[0x01], y=[0x02]
	add [0x01], 0x0001
	je [HERO_POS_MASK], 0x00, LABEL_93F5
	break

LABEL_9411:
	call LABEL_6F61
	je [HERO_POS_MASK], 0x00, LABEL_93F5
	break
	je [HERO_POS_MASK], 0x00, LABEL_9411

LABEL_9421:
	setup channel=0x15, address=LABEL_93D0
	sub [0x01], 0x0004

LABEL_9429:
	call LABEL_7107
	call SET_VAR04_TO_0020
	mov [0x2A], 0x000F
	sub [0x01], 0x0006
	break
	call LABEL_7124
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_96FF
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_713B
	sub [0x01], 0x0008
	break
	call LABEL_7152
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_7169
	add [0x02], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_93F5
	sub [0x01], 0x000A
	break

LABEL_9471:
	mov [0x63], 0x0005
	call LABEL_7178
	sub [0x01], 0x0006
	break
	call LABEL_7195
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_96FF
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_71AC
	sub [0x01], 0x0008
	break
	call LABEL_71C3
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_71DA
	add [0x02], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_93F5
	sub [0x01], 0x000A
	break
	jmp LABEL_9429
LABEL_94B9:
	db 0x11

LABEL_94BA:
	break
	je [0x63], 0x06, LABEL_94BA
	add [0x01], 0x0003
	break
	add [0x01], 0x0002
	break
	add [0x01], 0x0002
	break
	add [0x01], 0x0001
	break
	add [0x01], 0x0001
	break
	add [0x01], 0x0001
	killChannel

LABEL_94DF:
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_94E6:
	db 0x11

LABEL_94E7:
	video offset=CINEMATIC_568, x=[0x01], y=[0x02]
	add [0x01], 0x0003
	je [HERO_POS_MASK], 0x00, LABEL_94DF
	break

LABEL_94F7:
	call LABEL_6D9D
	je [HERO_POS_MASK], 0x00, LABEL_94DF
	break
	je [HERO_POS_MASK], 0x00, LABEL_94F7

LABEL_9507:
	setup channel=0x15, address=LABEL_94BA
	add [0x01], 0x0004

LABEL_950F:
	call LABEL_704B
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	add [0x01], 0x0006
	break
	call LABEL_7062
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_9824
	add [0x01], 0x0008
	break
	call LABEL_7073
	add [0x01], 0x0008
	break
	call LABEL_7084
	add [0x01], 0x0008
	break
	call LABEL_7095
	je [HERO_POS_MASK], 0x00, LABEL_94DF
	add [0x01], 0x000A
	break

LABEL_954B:
	mov [0x63], 0x0006
	call LABEL_70A6
	add [0x01], 0x0006
	break
	call LABEL_70BD
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_9824
	add [0x02], 0x0000
	add [0x01], 0x0008
	break
	call LABEL_70CE
	add [0x01], 0x0008
	break
	call LABEL_70DF
	add [0x02], 0x0000
	add [0x01], 0x0008
	break
	call LABEL_70F0
	add [0x02], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_94DF
	add [0x01], 0x000A
	break
	jmp LABEL_950F
LABEL_9593:
	db 0x11

LABEL_9594:
	call SET_VAR04_TO_0020
	je [0x0A], 0x00, LABEL_95E5
	mov [0x2A], 0x0021
	sub [0x01], 0x0001
	call HANDLE_HORIZ_VAR01_VS_VAR28
	sub [0x01], 0x0003
	video offset=CINEMATIC_558, x=[0x01], y=[0x02]
	sub [0x01], 0x0001

LABEL_95B5:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_95ED
	call LABEL_6E6B
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_95B5
	break
	add [0x01], 0x0002
	video offset=CINEMATIC_558, x=[0x01], y=[0x02]
	add [0x01], 0x0002
	break
	video offset=CINEMATIC_557, x=[0x01], y=[0x02]
	mov [0x63], 0x0001
	mov [0x0A], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_95E4:
	db 0x11

LABEL_95E5:
	mov [0x63], 0x0001
	jmp LABEL_922C
LABEL_95EC:
	db 0x11

LABEL_95ED:
	jne [0x0F], 0x00, LABEL_9629
	sub [0x01], 0x0002
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video offset=CINEMATIC_559, x=[0x01], y=[0x02]
	mov [0x21], [0x01]
	mov [0x27], [0x02]
	sub [0x21], 0x001E
	sub [0x27], 0x0027
	call LABEL_3889
	break
	add [0x01], 0x0001
	video offset=CINEMATIC_558, x=[0x01], y=[0x02]
	add [0x01], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_95B5
	setup channel=0x17, address=LABEL_45A9
