LABEL_ECE4:
	call LABEL_999D
	je [HERO_ACTION_POS_MASK], 0x84, INLINE_BREAK_035
	jmp LABEL_ED09
LABEL_ECF0:
	db 0x11

LABEL_ECF1:
	mov [0x2A], 0x0020
	sub [0x01], 0x0001
	call LABEL_7B5E
	add [0x01], 0x0003
	video type=0, offset=COMMON_VIDEO_333, x=[0x01], y=[0x02], zoom=0x40
	break
	call LABEL_998B

LABEL_ED09:
	break
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_ECAC
	je [HERO_ACTION_POS_MASK], 0x86, LABEL_ECAC
	call LABEL_999D
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_ED09
	break
	sub [0x01], 0x0002
	video type=0, offset=COMMON_VIDEO_336, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0001
	mov [0x0A], 0x0003
	jmp HERO_WALK_LEFT_LOOP
LABEL_ED34:
	db 0x11

LABEL_ED35:
	mov [0x63], 0x0064
	call SET_VAR04_TO_0000
	jne [0x0A], 0x00, LABEL_ECF1
	jne [HACK_VAR_67], 0x6D, LABEL_ED54
	jl [0x01], 0x5A, LABEL_ED54
	jl [0x01], 0x82, LABEL_1681

LABEL_ED54:
	add [0x01], 0x0002
	video type=0, offset=COMMON_VIDEO_333, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_337, x=[0x01], y=[0x02], zoom=0x40

LABEL_ED63:
	break
	video type=0, offset=COMMON_VIDEO_337, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_ED63
	break
	sub [0x01], 0x0002
	video type=0, offset=COMMON_VIDEO_336, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_ED80:
	db 0x11

LABEL_ED81:
	jne [0x0F], 0x00, LABEL_EDB9
	add [0x01], 0x0003
	call LABEL_7B5E
	call LABEL_973F
	mov [0x21], [0x01]
	mov [0x27], [0x02]
	add [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_62DD
	break
	sub [0x01], 0x0002
	call LABEL_9703
	sub [0x01], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_EDDA
	setup channel=0x17, address=LABEL_71FB
