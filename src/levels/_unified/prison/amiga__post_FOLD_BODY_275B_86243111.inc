LABEL_5009:
	break
	sub [0x15], 0x0001
	djnz [0x16], LABEL_5009
	mov [0x16], 0x0004

LABEL_5016:
	break
	add [0x15], 0x0001
	djnz [0x16], LABEL_5016
	mov [0x16], 0x0006
	mov [PAUSE_SLICES], 0x000A

LABEL_5027:
	break
	sub [0x15], 0x0001
	djnz [0x16], LABEL_5027
	break
	mov [PAUSE_SLICES], 0x000B
	break
	copyVideoPage src=0xFE, dst=0x00
	setup channel=0x02, address=KILL_CHANNEL_LANDING
	break
	mov [PAUSE_SLICES], 0x0008
	video offset=CINEMATIC_686, x=160, y=100
	break
	video offset=CINEMATIC_687, x=160, y=100
	break
	mov [0x16], 0x0005

DELAY_LOOP_VAR16:
	break
	djnz [0x16], DELAY_LOOP_VAR16
	mov [PAUSE_SLICES], 0x0004
	deleteChannels first=0x01, last=0x03
	setup channel=0x22, address=LABEL_4C18
	setup channel=0x23, address=PRISON_FILL_AND_DRAW_CIN_24_28_L0
	setup channel=0x14, address=INIT_VARS_15_19_18_14_PLUS4
	setup channel=0x15, address=LABEL_777F
	setup channel=0x00, address=LABEL_1CB8
	call LABEL_1CC9
	killChannel

DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E:
	mov [0xF8], [0x09]
	shr [0xF8], 0x0004
	jne [0x0E], 0x00, LABEL_509B
	je [0xF8], 0x00, DRAW_PRISON_BUDDY_POSE_0_0
	je [0xF8], 0x01, DRAW_PRISON_BUDDY_POSE_0_1
	je [0xF8], 0x02, DRAW_PRISON_BUDDY_POSE_0_2
	je [0xF8], 0x03, DRAW_PRISON_BUDDY_POSE_0_3
	ret


LABEL_509B:
	jne [0x0E], 0x01, LABEL_50AA
	je [0xF8], 0x01, DRAW_CIN_234
	jmp DRAW_CIN_235

LABEL_50AA:
	jne [0x0E], 0x02, LABEL_50B9
	je [0xF8], 0x01, DRAW_CIN_232
	jmp DRAW_CIN_233

LABEL_50B9:
	jne [0x0E], 0x03, LABEL_50C2
	jmp DRAW_PRISON_BUDDY_POSE_3

LABEL_50C2:
	jne [0x0E], 0x04, LABEL_50D1
	je [0xF8], 0x01, DRAW_CIN_229
	jmp DRAW_CIN_230

LABEL_50D1:
	jne [0x0E], 0x05, LABEL_50DA
	jmp DRAW_PRISON_BUDDY_POSE_5

LABEL_50DA:
	jne [0x0E], 0x06, LABEL_50E6
	video offset=CINEMATIC_227, x=[BUDDY_X], y=[BUDDY_Y]
	ret


LABEL_50E6:
	jne [0x0E], 0x07, LABEL_50F9
	je [0xF8], 0x00, DRAW_CIN_225
	je [0xF8], 0x01, DRAW_CIN_226
	ret


LABEL_50F9:
	ret


LABEL_50FA:
	db 0x11
