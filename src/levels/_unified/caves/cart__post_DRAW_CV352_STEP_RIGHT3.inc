LABEL_EBC2:
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	call LABEL_9BBE
	je [HERO_POS_MASK], 0x00, LABEL_EB8D
	add [0x01], 0x0002
	mov [0x36], 0xFFFB
	break
	call LABEL_9BCF
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_EBEE
	je [HERO_POS_MASK], 0x00, LABEL_EB85
	add [0x01], 0x0001

LABEL_EBEE:
	add [0x01], 0x0001
	mov [0x36], 0xFFF9
	break
	call LABEL_9BE0
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_EC0A
	je [HERO_POS_MASK], 0x00, LABEL_EB7D
	add [0x01], 0x0001

LABEL_EC0A:
	add [0x01], 0x0001
	mov [0x36], 0x0007
	break
	call LABEL_9BF1
	mov [0x36], 0x0005
	add [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_EC28
	add [0x01], 0x0002

LABEL_EC28:
	break
	call LABEL_9C02
	mov [0x36], 0x0003
	add [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_EC3E
	add [0x01], 0x0001

LABEL_EC3E:
	break
	call LABEL_9C13
	mov [0x36], 0x0001
	je [HERO_POS_LEFT_RIGHT], 0x00, LABEL_EC50
	add [0x01], 0x0002

LABEL_EC50:
	break
	call LABEL_9C2A
	mov [0x36], 0x0000
	je [HERO_POS_LEFT_RIGHT], 0x00, LABEL_EC62
	add [0x01], 0x0002

LABEL_EC62:
	break
	je [HERO_POS_MASK], 0x09, LABEL_F157
	call SET_VAR04_TO_0030
	call LABEL_9C3B
	jne [HERO_POS_MASK], 0x01, LABEL_EC62
	mov [0x36], 0xFFFD
	add [0x01], 0x0002
	break
	call LABEL_9C4F
	je [HERO_POS_MASK], 0x00, LABEL_EBAC
	add [0x01], 0x0002
	mov [0x36], 0xFFFB
	break
	call LABEL_9AA5
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_ECA3
	je [HERO_POS_MASK], 0x00, LABEL_EBA4
	add [0x01], 0x0001

LABEL_ECA3:
	mov [0x36], 0xFFF9
	add [0x01], 0x0001
	break
	call LABEL_9B4F
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_ECBF
	je [HERO_POS_MASK], 0x00, LABEL_EB9C
	add [0x01], 0x0001

LABEL_ECBF:
	mov [0x36], 0xFFF8
	add [0x01], 0x0001
	break
	call LABEL_9B60
	mov [0x36], 0x0005
	add [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_ECDD
	add [0x01], 0x0002

LABEL_ECDD:
	break
	call LABEL_9B71
	mov [0x36], 0x0003
	add [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_ECF3
	add [0x01], 0x0001

LABEL_ECF3:
	break
	call LABEL_9B82
	mov [0x36], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_ED05
	add [0x01], 0x0002

LABEL_ED05:
	break
	call LABEL_9B99
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_WALK_RIGHT_LOOP
	add [0x01], 0x0002

HERO_WALK_RIGHT_LOOP:
	break
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_F50C
	je [HERO_POS_MASK], 0x09, LABEL_F157

LABEL_ED20:
	call LABEL_9BAA
	call SET_VAR04_TO_0030
	jne [HERO_POS_MASK], 0x01, HERO_WALK_RIGHT_LOOP
	mov [0x36], 0xFFFD
	je [HERO_POS_LEFT_RIGHT], 0x00, LABEL_ED3A
	add [0x01], 0x0002

LABEL_ED3A:
	break
	jmp LABEL_EBC2
LABEL_ED3E:
	db 0x11

LABEL_ED3F:
	break
	je [0x63], 0x05, LABEL_ED3F
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

LABEL_ED64:
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_ED6B:
	db 0x11

LABEL_ED6C:
	sub [0x01], 0x0004
	video offset=CINEMATIC_170, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	je [HERO_POS_MASK], 0x00, LABEL_ED64
	break

LABEL_ED80:
	call LABEL_9DE6
	je [HERO_POS_MASK], 0x00, LABEL_ED64
	break
	je [HERO_POS_MASK], 0x00, LABEL_ED80

LABEL_ED90:
	setup channel=0x15, address=LABEL_ED3F
	sub [0x01], 0x0004

LABEL_ED98:
	call LABEL_9F92
	call SET_VAR04_TO_0020
	mov [0x2A], 0x000F
	sub [0x01], 0x0006
	break
	call LABEL_9FAF
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_F090
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_9FC6
	sub [0x01], 0x0008
	break
	call LABEL_9FDD
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_9FF4
	add [0x02], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_ED64
	sub [0x01], 0x000A
	break

LABEL_EDE0:
	mov [0x63], 0x0005
	call LABEL_A003
	sub [0x01], 0x0006
	break
	call LABEL_A020
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_F090
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_A037
	sub [0x01], 0x0008
	break
	call LABEL_A04E
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_A065
	add [0x02], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_ED64
	sub [0x01], 0x000A
	break
	jmp LABEL_ED98
LABEL_EE28:
	db 0x11

LABEL_EE29:
	break
	je [0x63], 0x06, LABEL_EE29
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

LABEL_EE4E:
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_EE55:
	db 0x11

LABEL_EE56:
	video offset=CINEMATIC_170, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0003
	je [HERO_POS_MASK], 0x00, LABEL_EE4E
	break

LABEL_EE66:
	call LABEL_9BAA
	je [HERO_POS_MASK], 0x00, LABEL_EE4E
	break
	je [HERO_POS_MASK], 0x00, LABEL_EE66

LABEL_EE76:
	setup channel=0x15, address=LABEL_EE29
	add [0x01], 0x0004

LABEL_EE7E:
	call LABEL_9ED6
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	add [0x01], 0x0006
	mov [0x36], 0xFFF4
	break
	call LABEL_9EED
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_F204
	add [0x01], 0x0008
	mov [0x36], 0xFFEF
	break
	call LABEL_9EFE
	add [0x01], 0x0008
	mov [0x36], 0xFFFE
	break
	call LABEL_9F0F
	add [0x01], 0x0008
	mov [0x36], 0x0005
	break
	call LABEL_9F20
	je [HERO_POS_MASK], 0x00, LABEL_EE4E
	add [0x01], 0x000A
	mov [0x36], 0xFFF9
	break

LABEL_EECE:
	mov [0x63], 0x0006
	call LABEL_9F31
	add [0x01], 0x0006
	mov [0x36], 0xFFF4
	break
	call LABEL_9F48
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_F204
	add [0x02], 0x0000
	add [0x01], 0x0008
	mov [0x36], 0xFFEF
	break
	call LABEL_9F59
	add [0x01], 0x0008
	mov [0x36], 0xFFFE
	break
	call LABEL_9F6A
	add [0x02], 0x0000
	add [0x01], 0x0008
	mov [0x36], 0x0005
	break
	call LABEL_9F7B
	add [0x02], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_EE4E
	add [0x01], 0x000A
	mov [0x36], 0xFFF9
	break
	jmp LABEL_EE7E
LABEL_EF2A:
	db 0x11

LABEL_EF2B:
	call LABEL_9DE6
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_EF2B
	call LABEL_9DE6
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP

LABEL_EF3F:
	call SET_VAR04_TO_0020
	je [0x0A], 0x00, LABEL_EF2B
	mov [0x2A], 0x0020
	sub [0x01], 0x0001
	call LABEL_7E33
	sub [0x01], 0x0003
	call LABEL_9CAE
	sub [0x01], 0x0001

LABEL_EF5E:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_EF8C
	call LABEL_9CC0
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_EF5E
	break
	add [0x01], 0x0002
	call LABEL_9CAE
	add [0x01], 0x0002
	break
	video offset=CINEMATIC_174, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0001
	mov [0x0A], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_EF8B:
	db 0x11

LABEL_EF8C:
	jne [0x0F], 0x00, LABEL_EFC1
	sub [0x01], 0x0002
	call LABEL_9CEA
	mov [0x21], [0x01]
	mov [0x27], [0x02]
	sub [0x21], 0x001E
	sub [0x27], 0x0027
	call LABEL_64AF
	break
	add [0x01], 0x0001
	call LABEL_9CAE
	add [0x01], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_EF5E
	setup channel=0x17, address=LABEL_7400
