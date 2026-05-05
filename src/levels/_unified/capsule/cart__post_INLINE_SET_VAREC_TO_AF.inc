DELAY_LOOP_VAREC:
	break
	djnz [0xEC], DELAY_LOOP_VAREC
	mov [0xEA], [HERO_X]
	sub [0xEA], 0x0064
	setup channel=0x05, address=LABEL_182D
	break
	mov [0xEB], [HERO_X]
	sub [0xEB], 0x003C
	setup channel=0x06, address=LABEL_184B
	mov [0xEC], 0x0018

DELAY_LOOP_VAREC_AT_188D:
	break
	djnz [0xEC], DELAY_LOOP_VAREC_AT_188D
	mov [0xEA], [HERO_X]
	add [0xEA], 0x0014
	setup channel=0x05, address=LABEL_182D
	break
	mov [0xEB], [HERO_X]
	sub [0xEB], 0x0032
	setup channel=0x06, address=LABEL_184B
	mov [0xEC], 0x0012

DELAY_LOOP_VAREC_AT_18AD:
	break
	djnz [0xEC], DELAY_LOOP_VAREC_AT_18AD
	mov [0xEA], [HERO_X]
	setup channel=0x05, address=LABEL_182D
	break
	setup channel=0x03, address=KILL_CHANNEL_LANDING
	break
	mov [0x04], 0x0010
	call LABEL_5F5D
	killChannel

LABEL_18C7:
	video offset=CINEMATIC_182, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_183, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_184, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_185, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_158D

LABEL_18E2:
	video offset=CINEMATIC_186, x=[HERO_X], y=[HERO_Y]
	break
	je [HERO_ACTION], 0x01, LABEL_15FA
	je [HERO_POS_LEFT_RIGHT], 0x01, LABEL_158D
	je [HERO_POS_LEFT_RIGHT], 0x00, LABEL_18E2
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_195, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_196, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_197, x=[HERO_X], y=[HERO_Y]
	break
	mov [0xE6], 0x0006

ANIM_CIN_198_LOOP_VARE6_AT_191C:
	video offset=CINEMATIC_198, x=[HERO_X], y=[HERO_Y]
	break
	djnz [0xE6], ANIM_CIN_198_LOOP_VARE6_AT_191C
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_199, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_200, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_201, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0002
	video offset=CINEMATIC_186, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_18E2

LABEL_1951:
	mov [HERO_X], 0x0097
	mov [HERO_Y], 0x00C8
	video offset=CINEMATIC_335, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_335, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_335, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	killChannel

LABEL_1995:
	mov [HERO_X], 0x00D8
	mov [HERO_Y], 0x00A3
	mov [0x32], 0x0001
	video offset=CINEMATIC_542, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0002
	add [HERO_Y], 0x000C
	video offset=CINEMATIC_543, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	add [HERO_Y], 0x0011
	video offset=CINEMATIC_543, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	mov [HERO_Y], 0x009D
	play id=0x005E, freq=0x14, vol=0x20, channel=0x00
	video offset=CINEMATIC_544, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_545, x=[HERO_X], y=[HERO_Y]
	play id=0x007A, freq=0x14, vol=0x20, channel=0x01
	break
	video offset=CINEMATIC_544, x=[HERO_X], y=[HERO_Y]
	mov [0xE6], 0x000A

LABEL_19EC:
	break
	video offset=CINEMATIC_546, x=[HERO_X], y=[HERO_Y]
	djnz [0xE6], LABEL_19EC
	mov [0xE8], 0x0000
	video offset=CINEMATIC_547, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_548, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_549, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_550, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_551, x=[HERO_X], y=[HERO_Y]
	mov [0xE7], 0x0002

LABEL_1A1B:
	mov [0xE6], 0x000A

LABEL_1A1F:
	break
	video offset=CINEMATIC_552, x=[HERO_X], y=[HERO_Y]
	je [0xE8], 0x01, LABEL_1A47
	djnz [0xE6], LABEL_1A1F
	mov [0xE6], 0x000A

LABEL_1A33:
	break
	video offset=CINEMATIC_556, x=[HERO_X], y=[HERO_Y]
	je [0xE8], 0x01, LABEL_1A47
	djnz [0xE6], LABEL_1A33
	djnz [0xE7], LABEL_1A1B

LABEL_1A47:
	break
	video offset=CINEMATIC_553, x=[HERO_X], y=[HERO_Y]
	break
	sub [0x15], 0x000C
	video offset=CINEMATIC_519, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_520, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_554, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_555, x=[HERO_X], y=[HERO_Y]
	killChannel
