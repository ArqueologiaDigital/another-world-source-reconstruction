LABEL_EB39:
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	call LABEL_9C47
	je [HERO_POS_MASK], 0x00, LABEL_EB04
	add [0x01], 0x0002
	mov [0x36], 0xFFFB
	break
	call LABEL_9C58
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_EB65
	je [HERO_POS_MASK], 0x00, LABEL_EAFC
	add [0x01], 0x0001

LABEL_EB65:
	add [0x01], 0x0001
	mov [0x36], 0xFFF9
	break
	call LABEL_9C69
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_EB81
	je [HERO_POS_MASK], 0x00, LABEL_EAF4
	add [0x01], 0x0001

LABEL_EB81:
	add [0x01], 0x0001
	mov [0x36], 0x0007
	break
	call LABEL_9C7A
	mov [0x36], 0x0005
	add [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_EB9F
	add [0x01], 0x0002

LABEL_EB9F:
	break
	call LABEL_9C8B
	mov [0x36], 0x0003
	add [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_EBB5
	add [0x01], 0x0001

LABEL_EBB5:
	break
	call LABEL_9C9C
	mov [0x36], 0x0001
	je [HERO_POS_LEFT_RIGHT], 0x00, LABEL_EBC7
	add [0x01], 0x0002

LABEL_EBC7:
	break
	call LABEL_9CB3
	mov [0x36], 0x0000
	je [HERO_POS_LEFT_RIGHT], 0x00, LABEL_EBD9
	add [0x01], 0x0002

LABEL_EBD9:
	break
	je [HERO_POS_MASK], 0x09, LABEL_F0CE
	call SET_VAR04_TO_0030
	call LABEL_9CC4
	jne [HERO_POS_MASK], 0x01, LABEL_EBD9
	mov [0x36], 0xFFFD
	add [0x01], 0x0002
	break
	call LABEL_9CD8
	je [HERO_POS_MASK], 0x00, LABEL_EB23
	add [0x01], 0x0002
	mov [0x36], 0xFFFB
	break
	call LABEL_9B2E
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_EC1A
	je [HERO_POS_MASK], 0x00, LABEL_EB1B
	add [0x01], 0x0001

LABEL_EC1A:
	mov [0x36], 0xFFF9
	add [0x01], 0x0001
	break
	call LABEL_9BD8
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_EC36
	je [HERO_POS_MASK], 0x00, LABEL_EB13
	add [0x01], 0x0001

LABEL_EC36:
	mov [0x36], 0xFFF8
	add [0x01], 0x0001
	break
	call LABEL_9BE9
	mov [0x36], 0x0005
	add [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_EC54
	add [0x01], 0x0002

LABEL_EC54:
	break
	call LABEL_9BFA
	mov [0x36], 0x0003
	add [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_EC6A
	add [0x01], 0x0001

LABEL_EC6A:
	break
	call LABEL_9C0B
	mov [0x36], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_EC7C
	add [0x01], 0x0002

LABEL_EC7C:
	break
	call LABEL_9C22
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_WALK_RIGHT_LOOP
	add [0x01], 0x0002

HERO_WALK_RIGHT_LOOP:
	break
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_F483
	je [HERO_POS_MASK], 0x09, LABEL_F0CE

LABEL_EC97:
	call LABEL_9C33
	call SET_VAR04_TO_0030
	jne [HERO_POS_MASK], 0x01, HERO_WALK_RIGHT_LOOP
	mov [0x36], 0xFFFD
	je [HERO_POS_LEFT_RIGHT], 0x00, LABEL_ECB1
	add [0x01], 0x0002

LABEL_ECB1:
	break
	jmp LABEL_EB39
LABEL_ECB5:
	db 0x11

LABEL_ECB6:
	break
	je [0x63], 0x05, LABEL_ECB6
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

LABEL_ECDB:
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_ECE2:
	db 0x11

LABEL_ECE3:
	sub [0x01], 0x0004
	video offset=CINEMATIC_170, x=[0x01], y=[0x02]
	add [0x01], 0x0001
	je [HERO_POS_MASK], 0x00, LABEL_ECDB
	break

LABEL_ECF7:
	call LABEL_9E6F
	je [HERO_POS_MASK], 0x00, LABEL_ECDB
	break
	je [HERO_POS_MASK], 0x00, LABEL_ECF7

LABEL_ED07:
	setup channel=0x15, address=LABEL_ECB6
	sub [0x01], 0x0004

LABEL_ED0F:
	call LABEL_A01B
	call SET_VAR04_TO_0020
	mov [0x2A], 0x000F
	sub [0x01], 0x0006
	break
	call LABEL_A038
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_F007
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_A04F
	sub [0x01], 0x0008
	break
	call LABEL_A066
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_A07D
	add [0x02], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_ECDB
	sub [0x01], 0x000A
	break

LABEL_ED57:
	mov [0x63], 0x0005
	call LABEL_A08C
	sub [0x01], 0x0006
	break
	call LABEL_A0A9
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_F007
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_A0C0
	sub [0x01], 0x0008
	break
	call LABEL_A0D7
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
	call LABEL_A0EE
	add [0x02], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_ECDB
	sub [0x01], 0x000A
	break
	jmp LABEL_ED0F
LABEL_ED9F:
	db 0x11

LABEL_EDA0:
	break
	je [0x63], 0x06, LABEL_EDA0
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

LABEL_EDC5:
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_EDCC:
	db 0x11

LABEL_EDCD:
	video offset=CINEMATIC_170, x=[0x01], y=[0x02]
	add [0x01], 0x0003
	je [HERO_POS_MASK], 0x00, LABEL_EDC5
	break

LABEL_EDDD:
	call LABEL_9C33
	je [HERO_POS_MASK], 0x00, LABEL_EDC5
	break
	je [HERO_POS_MASK], 0x00, LABEL_EDDD

LABEL_EDED:
	setup channel=0x15, address=LABEL_EDA0
	add [0x01], 0x0004

LABEL_EDF5:
	call LABEL_9F5F
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	add [0x01], 0x0006
	mov [0x36], 0xFFF4
	break
	call LABEL_9F76
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_F17B
	add [0x01], 0x0008
	mov [0x36], 0xFFEF
	break
	call LABEL_9F87
	add [0x01], 0x0008
	mov [0x36], 0xFFFE
	break
	call LABEL_9F98
	add [0x01], 0x0008
	mov [0x36], 0x0005
	break
	call LABEL_9FA9
	je [HERO_POS_MASK], 0x00, LABEL_EDC5
	add [0x01], 0x000A
	mov [0x36], 0xFFF9
	break

LABEL_EE45:
	mov [0x63], 0x0006
	call LABEL_9FBA
	add [0x01], 0x0006
	mov [0x36], 0xFFF4
	break
	call LABEL_9FD1
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_F17B
	add [0x02], 0x0000
	add [0x01], 0x0008
	mov [0x36], 0xFFEF
	break
	call LABEL_9FE2
	add [0x01], 0x0008
	mov [0x36], 0xFFFE
	break
	call LABEL_9FF3
	add [0x02], 0x0000
	add [0x01], 0x0008
	mov [0x36], 0x0005
	break
	call LABEL_A004
	add [0x02], 0x0000
	je [HERO_POS_MASK], 0x00, LABEL_EDC5
	add [0x01], 0x000A
	mov [0x36], 0xFFF9
	break
	jmp LABEL_EDF5
LABEL_EEA1:
	db 0x11

LABEL_EEA2:
	call LABEL_9E6F
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_EEA2
	call LABEL_9E6F
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP

LABEL_EEB6:
	call SET_VAR04_TO_0020
	je [0x0A], 0x00, LABEL_EEA2
	mov [0x2A], 0x0020
	sub [0x01], 0x0001
	call LABEL_7EBC
	sub [0x01], 0x0003
	call LABEL_9D37
	sub [0x01], 0x0001

LABEL_EED5:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_EF03
	call LABEL_9D49
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_EED5
	break
	add [0x01], 0x0002
	call LABEL_9D37
	add [0x01], 0x0002
	break
	video offset=CINEMATIC_174, x=[0x01], y=[0x02]
	mov [0x63], 0x0001
	mov [0x0A], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_EF02:
	db 0x11

LABEL_EF03:
	jne [0x0F], 0x00, LABEL_EF38
	sub [0x01], 0x0002
	call LABEL_9D73
	mov [0x21], [0x01]
	mov [0x27], [0x02]
	sub [0x21], 0x001E
	sub [0x27], 0x0027
	call LABEL_6588
	break
	add [0x01], 0x0001
	call LABEL_9D37
	add [0x01], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_EED5
	setup channel=0x17, address=LABEL_74C1
