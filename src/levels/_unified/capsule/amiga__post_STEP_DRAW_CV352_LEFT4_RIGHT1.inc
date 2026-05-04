LABEL_9028:
	call SET_VAR04_TO_0020
	mov [0x2A], 0x000F
	call LABEL_7B3F
	je [HERO_POS_MASK], 0x00, LABEL_8FF3
	sub [0x01], 0x0002
	break
	call LABEL_7B56
	je [HERO_POS_MASK], 0x00, LABEL_8FEB
	sub [0x01], 0x0002
	break
	call LABEL_7B6D
	je [HERO_POS_MASK], 0x00, LABEL_8FE3
	add [0x02], 0x0000
	sub [0x01], 0x0002
	break
	call LABEL_7B84
	sub [0x01], 0x0003
	break
	call LABEL_7B9B
	add [0x02], 0x0000
	sub [0x01], 0x0002
	break
	call LABEL_7BB2
	sub [0x01], 0x0002
	break
	call LABEL_7BC7
	sub [0x01], 0x0002

LABEL_9080:
	call SET_VAR04_TO_0020
	break
	je [HERO_POS_MASK], 0x0A, LABEL_94F9
	call LABEL_7BD6
	jne [HERO_POS_MASK], 0x02, LABEL_9080
	sub [0x01], 0x0002
	break
	call LABEL_7BE8
	je [HERO_POS_MASK], 0x00, LABEL_9012
	sub [0x01], 0x0002
	break
	call LABEL_7ABD
	je [HERO_POS_MASK], 0x00, LABEL_900A
	sub [0x01], 0x0002
	break
	call LABEL_7ACC
	je [HERO_POS_MASK], 0x00, LABEL_9002
	add [0x02], 0x0000
	sub [0x01], 0x0002
	break
	call LABEL_7ADB
	sub [0x01], 0x0003
	break
	call LABEL_7AEA
	add [0x02], 0x0000
	sub [0x01], 0x0002
	break
	call LABEL_7AF9
	sub [0x01], 0x0002
	break
	call LABEL_7B0E
	sub [0x01], 0x0002

HERO_WALK_LEFT_LOOP:
	break
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_991B
	je [HERO_POS_MASK], 0x0A, LABEL_94F9

LABEL_90F6:
	call LABEL_7B25
	call SET_VAR04_TO_0020
	jne [HERO_POS_MASK], 0x02, HERO_WALK_LEFT_LOOP
	sub [0x01], 0x0002
	break
	jmp LABEL_9028
LABEL_910A:
	db 0x11, 0x06, 0x03, 0x01, 0xFF, 0xFE, 0x04, 0x79
	db 0x8B

LABEL_9113:
	break
	sub [0x01], 0x0002
	call LABEL_797A

LABEL_911B:
	break
	sub [0x01], 0x0002
	call LABEL_7969

LABEL_9123:
	sub [0x01], 0x0001
	jmp HERO_WALK_RIGHT_LOOP
LABEL_912A:
	db 0x06, 0x03, 0x01, 0xFF, 0xFE, 0x04, 0x78, 0xFA

LABEL_9132:
	break
	sub [0x01], 0x0002
	call LABEL_785C

LABEL_913A:
	break
	sub [0x01], 0x0002
	call LABEL_79FA

LABEL_9142:
	sub [0x01], 0x0001
	jmp LABEL_91C4
LABEL_9149:
	db 0x11
