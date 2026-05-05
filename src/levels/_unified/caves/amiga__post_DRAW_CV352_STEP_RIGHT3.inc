LABEL_E54E:
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	call LABEL_98E9
	je [HERO_POS_MASK], 0x00, LABEL_E519
	add [0x01], 0x0002
	mov [0x36], 0xFFFB
	break
	call LABEL_98FA
	je [HERO_POS_MASK], 0x00, LABEL_E511
	add [0x01], 0x0002
	mov [0x36], 0xFFF9
	break
	call LABEL_990B
	je [HERO_POS_MASK], 0x00, LABEL_E509
	add [0x01], 0x0002
	mov [0x36], 0x0007
	break
	call LABEL_991C
	add [0x01], 0x0003
	mov [0x36], 0x0005
	break
	call LABEL_992D
	add [0x01], 0x0002
	mov [0x36], 0x0003
	break
	call LABEL_993E
	add [0x01], 0x0002
	mov [0x36], 0x0001
	break
	call LABEL_9955
	add [0x01], 0x0002
	mov [0x36], 0x0000

LABEL_E5BA:
	break
	je [HERO_POS_MASK], 0x09, LABEL_EA63
	call SET_VAR04_TO_0030
	call LABEL_9966
	jne [HERO_POS_MASK], 0x01, LABEL_E5BA
	add [0x01], 0x0002
	mov [0x36], 0xFFFD
	break
	call LABEL_997A
	je [HERO_POS_MASK], 0x00, LABEL_E538
	add [0x01], 0x0002
	mov [0x36], 0xFFFB
	break
	call LABEL_97D0
	je [HERO_POS_MASK], 0x00, LABEL_E530
	add [0x01], 0x0002
	mov [0x36], 0xFFF9
	break
	call LABEL_987A
	je [HERO_POS_MASK], 0x00, LABEL_E528
	add [0x01], 0x0002
	mov [0x36], 0xFFF8
	break
	call LABEL_988B
	add [0x01], 0x0003
	mov [0x36], 0x0005
	break
	call LABEL_989C
	add [0x01], 0x0002
	mov [0x36], 0x0003
	break
	call LABEL_98AD
	add [0x01], 0x0002
	mov [0x36], 0x0001
	break
	call LABEL_98C4
	add [0x01], 0x0002

HERO_WALK_RIGHT_LOOP:
	break
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_EE06
	je [HERO_POS_MASK], 0x09, LABEL_EA63

LABEL_E644:
	call LABEL_98D5
	call SET_VAR04_TO_0030
	jne [HERO_POS_MASK], 0x01, HERO_WALK_RIGHT_LOOP
	add [0x01], 0x0002
	mov [0x36], 0xFFFD
	break
	jmp LABEL_E54E
LABEL_E65C:
	db 0x11

LABEL_E65D:
	break
	je [0x63], 0x05, LABEL_E65D
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

LABEL_E682:
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_E689:
	db 0x11

LABEL_E68A:
	sub [0x01], 0x0004
	video offset=CINEMATIC_170, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	je [HERO_POS_MASK], 0x00, LABEL_E682
	break

LABEL_E69E:
	call LABEL_9B11
	je [HERO_POS_MASK], 0x00, LABEL_E682
	break
	je [HERO_POS_MASK], 0x00, LABEL_E69E

LABEL_E6AE:
	setup channel=0x15, address=LABEL_E65D
	sub [0x01], 0x0004

LABEL_E6B6:
	call LABEL_9CBD
	call SET_VAR04_TO_0020
	mov [0x2A], 0x000F
	sub [0x01], 0x0006
	break
	call LABEL_9CDA
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_E9A8
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_9CF1
	sub [0x01], 0x0008
	break
	call LABEL_9D08
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_9D1F
	add [0x02], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_E682
	sub [0x01], 0x000A
	break

LABEL_E6FE:
	mov [0x63], 0x0005
	call LABEL_9D2E
	sub [0x01], 0x0006
	break
	call LABEL_9D4B
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_E9A8
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_9D62
	sub [0x01], 0x0008
	break
	call LABEL_9D79
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_9D90
	add [0x02], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_E682
	sub [0x01], 0x000A
	break
	jmp LABEL_E6B6
LABEL_E746:
	db 0x11

LABEL_E747:
	break
	je [0x63], 0x06, LABEL_E747
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

LABEL_E76C:
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_E773:
	db 0x11

LABEL_E774:
	video offset=CINEMATIC_170, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0003
	je [HERO_POS_MASK], 0x00, LABEL_E76C
	break

LABEL_E784:
	call LABEL_98D5
	je [HERO_POS_MASK], 0x00, LABEL_E76C
	break
	je [HERO_POS_MASK], 0x00, LABEL_E784

LABEL_E794:
	setup channel=0x15, address=LABEL_E747
	add [0x01], 0x0004

LABEL_E79C:
	call LABEL_9C01
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	add [0x01], 0x0006
	mov [0x36], 0xFFF4
	break
	call LABEL_9C18
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_EB0A
	add [0x01], 0x0008
	mov [0x36], 0xFFEF
	break
	call LABEL_9C29
	add [0x01], 0x0008
	mov [0x36], 0xFFFE
	break
	call LABEL_9C3A
	add [0x01], 0x0008
	mov [0x36], 0x0005
	break
	call LABEL_9C4B
	je [HERO_POS_MASK], 0x00, LABEL_E76C
	add [0x01], 0x000A
	mov [0x36], 0xFFF9
	break

LABEL_E7EC:
	mov [0x63], 0x0006
	call LABEL_9C5C
	add [0x01], 0x0006
	mov [0x36], 0xFFF4
	break
	call LABEL_9C73
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_EB0A
	add [0x02], 0x0000
	add [0x01], 0x0008
	mov [0x36], 0xFFEF
	break
	call LABEL_9C84
	add [0x01], 0x0008
	mov [0x36], 0xFFFE
	break
	call LABEL_9C95
	add [0x02], 0x0000
	add [0x01], 0x0008
	mov [0x36], 0x0005
	break
	call LABEL_9CA6
	add [0x02], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_E76C
	add [0x01], 0x000A
	mov [0x36], 0xFFF9
	break
	jmp LABEL_E79C
LABEL_E848:
	db 0x11

LABEL_E849:
	call LABEL_9B11
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_E849
	call LABEL_9B11
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP

LABEL_E85D:
	call SET_VAR04_TO_0020
	je [0x0A], 0x00, LABEL_E849
	mov [0x2A], 0x0020
	sub [0x01], 0x0001
	call LABEL_7B5E
	sub [0x01], 0x0003
	call LABEL_99D9
	sub [0x01], 0x0001

LABEL_E87C:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_E8AA
	call LABEL_99EB
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_E87C
	break
	add [0x01], 0x0002
	call LABEL_99D9
	add [0x01], 0x0002
	break
	video offset=CINEMATIC_174, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0001
	mov [0x0A], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_E8A9:
	db 0x11

LABEL_E8AA:
	jne [0x0F], 0x00, LABEL_E8DF
	sub [0x01], 0x0002
	call LABEL_9A15
	mov [0x21], [0x01]
	mov [0x27], [0x02]
	sub [0x21], 0x001E
	sub [0x27], 0x0027
	call LABEL_6265
	break
	add [0x01], 0x0001
	call LABEL_99D9
	add [0x01], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_E87C
	setup channel=0x17, address=LABEL_71A7
