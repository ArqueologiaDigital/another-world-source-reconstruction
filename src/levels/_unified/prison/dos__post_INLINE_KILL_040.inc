LABEL_0D78:
	call LABEL_0D7F
	jmp LABEL_3785
LABEL_0D7E:
	db 0x05

LABEL_0D7F:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	mov [0x21], 0x0140
	add [0x21], [RANDOM_SEED]
	mov [0x27], 0x008C
	add [0x27], [0x3A]
	or [0x27], 0x1800
	ret
LABEL_0D95:
	db 0x11

LABEL_0D96:
	call LABEL_0DAB
	jmp LABEL_37A6
LABEL_0D9C:
	db 0x05

LABEL_0D9D:
	call LABEL_0DAB
	mov [0x21], 0xFFEC
	sub [0x27], 0x0040
	jmp LABEL_37A6

LABEL_0DAB:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	mov [0x21], 0xFF24
	add [0x21], [RANDOM_SEED]
	mov [0x27], 0x008C
	add [0x27], [0x3A]
	or [0x27], 0x1800
	ret
LABEL_0DC1:
	db 0x11

LABEL_0DC2:
	break
	je [0x72], [HACK_VAR_67], LABEL_0DC2
	mov [0xF8], [HACK_VAR_67]
	sub [0xF8], 0x0001
	je [0x72], [0xF8], LABEL_0DD9
	jmp LABEL_0DC2

LABEL_0DD9:
	call LABEL_0D96
	mov [0xAF], [0x3B]
	add [0xAF], 0x0001

DELAY_LOOP_VARAF_AT_0DE3:
	break
	djnz [0xAF], DELAY_LOOP_VARAF_AT_0DE3
	jmp LABEL_0DC2
LABEL_0DEB:
	db 0x11

LABEL_0DEC:
	video offset=CINEMATIC_113, x=160, y=[0x19]
	play id=0x005B, freq=0x05, vol=0x0A, channel=0x02
	break
	video offset=CINEMATIC_114, x=160, y=[0x19]
	break
	video offset=CINEMATIC_115, x=160, y=[0x19]
	break
	video offset=CINEMATIC_116, x=160, y=[0x19]
	break
	video offset=CINEMATIC_117, x=160, y=[0x19]
	break
	video offset=CINEMATIC_118, x=160, y=[0x19]
	break
	jmp LABEL_0DEC
LABEL_0E19:
	db 0x11

LABEL_0E1A:
	video offset=CINEMATIC_107, x=160, y=[0x19]
	play id=0x005B, freq=0x07, vol=0x0A, channel=0x03
	break
	video offset=CINEMATIC_108, x=160, y=[0x19]
	break
	video offset=CINEMATIC_109, x=160, y=[0x19]
	break
	video offset=CINEMATIC_110, x=160, y=[0x19]
	break
	video offset=CINEMATIC_111, x=160, y=[0x19]
	break
	video offset=CINEMATIC_112, x=160, y=[0x19]
	break
	jmp LABEL_0E1A
LABEL_0E47:
	db 0x11

LABEL_0E48:
	video offset=CINEMATIC_119, x=160, y=[0x19]
	break
	video offset=CINEMATIC_120, x=160, y=[0x19]
	break
	video offset=CINEMATIC_121, x=160, y=[0x19]
	break
	video offset=CINEMATIC_122, x=160, y=[0x19]
	break
	video offset=CINEMATIC_123, x=160, y=[0x19]
	break
	video offset=CINEMATIC_124, x=160, y=[0x19]
	break
	video offset=CINEMATIC_125, x=160, y=[0x19]
	break
	video offset=CINEMATIC_126, x=160, y=[0x19]
	break
	jmp LABEL_0E48
LABEL_0E7B:
	db 0x11
