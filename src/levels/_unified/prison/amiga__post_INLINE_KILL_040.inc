PRISON_OFFSCREEN_SHOT_LAUNCH_FROM_RIGHT:
	call PRISON_OFFSCREEN_SHOT_ORIGIN_FROM_RIGHT
	jmp PRISON_DRAW_CIN505_AT_X21_Y27_L1
LABEL_0D9E:
	db 0x05

PRISON_OFFSCREEN_SHOT_ORIGIN_FROM_RIGHT:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	mov [0x21], 0x0140
	add [0x21], [RANDOM_SEED]
	mov [0x27], 0x008C
	add [0x27], [0x3A]
	or [0x27], 0x1800
	ret


LABEL_0DB5:
	db 0x11

LABEL_0DB6:
	call PRISON_OFFSCREEN_SHOT_ORIGIN_FROM_LEFT
	jmp PRISON_DRAW_CIN505_AT_X21_Y27_L5
LABEL_0DBC:
	db 0x05

LABEL_0DBD:
	call PRISON_OFFSCREEN_SHOT_ORIGIN_FROM_LEFT
	mov [0x21], 0xFFEC
	sub [0x27], 0x0040
	jmp PRISON_DRAW_CIN505_AT_X21_Y27_L5

PRISON_OFFSCREEN_SHOT_ORIGIN_FROM_LEFT:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	mov [0x21], 0xFF24
	add [0x21], [RANDOM_SEED]
	mov [0x27], 0x008C
	add [0x27], [0x3A]
	or [0x27], 0x1800
	ret


LABEL_0DE1:
	db 0x11

LABEL_0DE2:
	break
	je [0x72], [SCREEN_NUM], LABEL_0DE2
	mov [0xF8], [SCREEN_NUM]
	sub [0xF8], 0x0001
	je [0x72], [0xF8], LABEL_0DF9
	jmp LABEL_0DE2

LABEL_0DF9:
	call LABEL_0DB6
	mov [0xAF], [0x3B]
	add [0xAF], 0x0001

PRISON_OFFSCREEN_SHOT_FROM_LEFT_DELAY_LOOP:
	break
	djnz [0xAF], PRISON_OFFSCREEN_SHOT_FROM_LEFT_DELAY_LOOP
	jmp LABEL_0DE2
LABEL_0E0B:
	db 0x11

LABEL_0E0C:
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
	jmp LABEL_0E0C
LABEL_0E39:
	db 0x11

LABEL_0E3A:
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
	jmp LABEL_0E3A
LABEL_0E67:
	db 0x11

LABEL_0E68:
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
	jmp LABEL_0E68
LABEL_0E9B:
	db 0x11
