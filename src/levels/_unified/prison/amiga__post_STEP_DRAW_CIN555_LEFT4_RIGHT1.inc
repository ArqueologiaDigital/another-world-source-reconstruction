LABEL_8E2B:
	call SET_VAR04_TO_0020
	mov [0x2A], 0x000F
	call LABEL_6DCB
	je [HERO_POS_MASK], 0x00, LABEL_8DF6
	sub [0x01], 0x0002
	break
	call LABEL_6DE2
	je [HERO_POS_MASK], 0x00, LABEL_8DEE
	sub [0x01], 0x0002
	break
	call LABEL_6DF9
	je [HERO_POS_MASK], 0x00, LABEL_8DE6
	add [0x02], 0x0000
	sub [0x01], 0x0002
	break
	call LABEL_6E10
	sub [0x01], 0x0003
	break
	call LABEL_6E27
	add [0x02], 0x0000
	sub [0x01], 0x0002
	break
	call LABEL_6E3E
	play id=0x0060, freq=0x14, vol=0x20, channel=0x00
	sub [0x01], 0x0002
	break
	call LABEL_6E4D
	sub [0x01], 0x0002

LABEL_8E89:
	call SET_VAR04_TO_0020
	break
	call LABEL_6E5C
	jne [HERO_POS_MASK], 0x02, LABEL_8E89
	sub [0x01], 0x0002
	break
	call LABEL_6E6E
	je [HERO_POS_MASK], 0x00, LABEL_8E15
	sub [0x01], 0x0002
	break
	call LABEL_6D4F
	je [HERO_POS_MASK], 0x00, LABEL_8E0D
	sub [0x01], 0x0002
	break
	call LABEL_6D5E
	je [HERO_POS_MASK], 0x00, LABEL_8E05
	add [0x02], 0x0000
	sub [0x01], 0x0002
	break
	call LABEL_6D6D
	sub [0x01], 0x0003
	break
	call LABEL_6D7C
	add [0x02], 0x0000
	sub [0x01], 0x0002
	break
	call LABEL_6D8B
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x00
	sub [0x01], 0x0002
	break
	call LABEL_6D9A
	sub [0x01], 0x0002

HERO_WALK_LEFT_LOOP:
	break
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_978A
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_92EB

LABEL_8F00:
	call LABEL_6DB1
	call SET_VAR04_TO_0020
	jne [HERO_POS_MASK], 0x02, HERO_WALK_LEFT_LOOP
	sub [0x01], 0x0002
	break
	jmp LABEL_8E2B
LABEL_8F14:
	db 0x11, 0x06, 0x03, 0x01, 0xFF, 0xFE, 0x04, 0x6C
	db 0x23

LABEL_8F1D:
	break
	sub [0x01], 0x0002
	call LABEL_6C12

LABEL_8F25:
	break
	sub [0x01], 0x0002
	call LABEL_6C01

LABEL_8F2D:
	sub [0x01], 0x0001
	jmp HERO_WALK_LOOP
LABEL_8F34:
	db 0x06, 0x03, 0x01, 0xFF, 0xFE, 0x04, 0x6B, 0x98

LABEL_8F3C:
	break
	sub [0x01], 0x0002
	call LABEL_6AFA

LABEL_8F44:
	break
	sub [0x01], 0x0002
	call LABEL_6C8C

LABEL_8F4C:
	sub [0x01], 0x0001
	jmp LABEL_8FB8
LABEL_8F53:
	db 0x11
