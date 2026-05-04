LABEL_E41E:
	call SET_VAR04_TO_0020
	mov [0x2A], 0x000F
	call LABEL_9B2B
	je [HERO_POS_MASK], 0x00, LABEL_E3E9
	sub [0x01], 0x0002
	break
	call LABEL_9B42
	je [HERO_POS_MASK], 0x00, LABEL_E3E1
	sub [0x01], 0x0002
	break
	call LABEL_9B59
	je [HERO_POS_MASK], 0x00, LABEL_E3D9
	add [0x02], 0x0000
	sub [0x01], 0x0002
	break
	call LABEL_9B70
	sub [0x01], 0x0003
	break
	call LABEL_9B87
	add [0x02], 0x0000
	sub [0x01], 0x0002
	break
	call LABEL_9B9E
	sub [0x01], 0x0002
	break
	call LABEL_9BB3
	sub [0x01], 0x0002

LABEL_E476:
	call SET_VAR04_TO_0020
	break
	je [HERO_POS_MASK], 0x0A, LABEL_E901
	call LABEL_9BC2
	jne [HERO_POS_MASK], 0x02, LABEL_E476
	sub [0x01], 0x0002
	break
	call LABEL_9BD4
	je [HERO_POS_MASK], 0x00, LABEL_E408
	sub [0x01], 0x0002
	break
	call LABEL_9AA9
	je [HERO_POS_MASK], 0x00, LABEL_E400
	sub [0x01], 0x0002
	break
	call LABEL_9AB8
	je [HERO_POS_MASK], 0x00, LABEL_E3F8
	add [0x02], 0x0000
	sub [0x01], 0x0002
	break
	call LABEL_9AC7
	sub [0x01], 0x0003
	break
	call LABEL_9AD6
	add [0x02], 0x0000
	sub [0x01], 0x0002
	break
	call LABEL_9AE5
	sub [0x01], 0x0002
	break
	call LABEL_9AFA
	sub [0x01], 0x0002

HERO_WALK_LEFT_LOOP:
	break
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_ED35
	je [HERO_POS_MASK], 0x0A, LABEL_E901

LABEL_E4EC:
	call LABEL_9B11
	call SET_VAR04_TO_0020
	jne [HERO_POS_MASK], 0x02, HERO_WALK_LEFT_LOOP
	sub [0x01], 0x0002
	break
	jmp LABEL_E41E
LABEL_E500:
	db 0x11, 0x06, 0x03, 0x01, 0xFF, 0xFE, 0x04, 0x99
	db 0x0B

LABEL_E509:
	break
	sub [0x01], 0x0002
	call LABEL_98FA

LABEL_E511:
	break
	sub [0x01], 0x0002
	call LABEL_98E9

LABEL_E519:
	sub [0x01], 0x0001
	jmp HERO_WALK_RIGHT_LOOP
LABEL_E520:
	db 0x06, 0x03, 0x01, 0xFF, 0xFE, 0x04, 0x98, 0x7A

LABEL_E528:
	break
	sub [0x01], 0x0002
	call LABEL_97D0

LABEL_E530:
	break
	sub [0x01], 0x0002
	call LABEL_997A

LABEL_E538:
	sub [0x01], 0x0001
	jmp LABEL_E5BA
LABEL_E53F:
	db 0x11
