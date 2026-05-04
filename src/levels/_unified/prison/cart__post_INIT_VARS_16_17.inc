DELAY_LOOP_VAR17__CART__POST_INIT_VARS_16_17:
	break
	djnz [0x17], DELAY_LOOP_VAR17__CART__POST_INIT_VARS_16_17
	mov [0x17], 0x0004

LABEL_4EB6:
	break
	sub [0x16], 0x0001
	djnz [0x17], LABEL_4EB6
	mov [0x17], 0x0002

LABEL_4EC3:
	break
	break
	sub [0x16], 0x0001
	djnz [0x17], LABEL_4EC3
	break
	add [0x16], 0x0001
	break
	break
	break
	add [0x16], 0x0001
	killChannel

LABEL_4EDA:
	video type=1, offset=CINEMATIC_656, x=[0x1a], y=[0x1b], zoom=0x40
	jg [0x16], 0x01, LABEL_4EED
	video type=1, offset=CINEMATIC_682, x=[0x1a], y=[0x1b], zoom=0x40
	jmp LABEL_4F38

LABEL_4EED:
	jg [0x16], 0x02, LABEL_4EFB
	video type=1, offset=CINEMATIC_681, x=[0x1a], y=[0x1b], zoom=0x40
	jmp LABEL_4F38

LABEL_4EFB:
	jg [0x16], 0x03, LABEL_4F09
	video type=1, offset=CINEMATIC_680, x=[0x1a], y=[0x1b], zoom=0x40
	jmp LABEL_4F38

LABEL_4F09:
	jg [0x16], 0x04, LABEL_4F17
	video type=1, offset=CINEMATIC_679, x=[0x1a], y=[0x1b], zoom=0x40
	jmp LABEL_4F38

LABEL_4F17:
	jg [0x16], 0x05, LABEL_4F25
	video type=1, offset=CINEMATIC_678, x=[0x1a], y=[0x1b], zoom=0x40
	jmp LABEL_4F38

LABEL_4F25:
	jg [0x16], 0x06, LABEL_4F33
	video type=1, offset=CINEMATIC_677, x=[0x1a], y=[0x1b], zoom=0x40
	jmp LABEL_4F38

LABEL_4F33:
	video type=1, offset=CINEMATIC_657, x=[0x1a], y=[0x1b], zoom=0x40

LABEL_4F38:
	video type=1, offset=CINEMATIC_658, x=[0x1a], y=[0x1b], zoom=0x40
	jg [0x15], 0x00, LABEL_4F4A
	video type=1, offset=CINEMATIC_676, x=160, y=100
	jmp LABEL_501E

LABEL_4F4A:
	jg [0x15], 0x02, LABEL_4F57
	video type=1, offset=CINEMATIC_675, x=160, y=100
	jmp LABEL_501E

LABEL_4F57:
	jg [0x15], 0x04, LABEL_4F64
	video type=1, offset=CINEMATIC_674, x=160, y=100
	jmp LABEL_501E

LABEL_4F64:
	jg [0x15], 0x06, LABEL_4F71
	video type=1, offset=CINEMATIC_673, x=160, y=100
	jmp LABEL_501E

LABEL_4F71:
	jg [0x15], 0x08, LABEL_4F7E
	video type=1, offset=CINEMATIC_672, x=160, y=100
	jmp LABEL_501E

LABEL_4F7E:
	jg [0x15], 0x0A, LABEL_4F8B
	video type=1, offset=CINEMATIC_671, x=160, y=100
	jmp LABEL_501E

LABEL_4F8B:
	jg [0x15], 0x0C, LABEL_4F98
	video type=1, offset=CINEMATIC_670, x=160, y=100
	jmp LABEL_501E

LABEL_4F98:
	jg [0x15], 0x0E, LABEL_4FA5
	video type=1, offset=CINEMATIC_669, x=160, y=100
	jmp LABEL_501E

LABEL_4FA5:
	jg [0x15], 0x10, LABEL_4FB2
	video type=1, offset=CINEMATIC_668, x=160, y=100
	jmp LABEL_501E

LABEL_4FB2:
	jg [0x15], 0x12, LABEL_4FBF
	video type=1, offset=CINEMATIC_667, x=160, y=100
	jmp LABEL_501E

LABEL_4FBF:
	jg [0x15], 0x14, LABEL_4FCC
	video type=1, offset=CINEMATIC_666, x=160, y=100
	jmp LABEL_501E

LABEL_4FCC:
	jg [0x15], 0x16, LABEL_4FD9
	video type=1, offset=CINEMATIC_665, x=160, y=100
	jmp LABEL_501E

LABEL_4FD9:
	jg [0x15], 0x18, LABEL_4FE6
	video type=1, offset=CINEMATIC_664, x=160, y=100
	jmp LABEL_501E

LABEL_4FE6:
	jg [0x15], 0x1A, LABEL_4FF3
	video type=1, offset=CINEMATIC_663, x=160, y=100
	jmp LABEL_501E

LABEL_4FF3:
	jg [0x15], 0x1C, LABEL_5000
	video type=1, offset=CINEMATIC_662, x=160, y=100
	jmp LABEL_501E

LABEL_5000:
	jg [0x15], 0x1E, LABEL_500D
	video type=1, offset=CINEMATIC_661, x=160, y=100
	jmp LABEL_501E

LABEL_500D:
	jg [0x15], 0x20, LABEL_501A
	video type=1, offset=CINEMATIC_660, x=160, y=100
	jmp LABEL_501E

LABEL_501A:
	video type=1, offset=CINEMATIC_659, x=160, y=100

LABEL_501E:
	break
	jmp LABEL_4EDA
LABEL_5022:
	db 0x11
