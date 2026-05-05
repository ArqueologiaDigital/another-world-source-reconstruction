DELAY_LOOP_VAREC:
	break
	djnz [0xEC], DELAY_LOOP_VAREC
	mov [0xEA], [0x01]
	sub [0xEA], 0x0064
	setup channel=0x05, address=LABEL_171F
	break
	mov [0xEB], [0x01]
	sub [0xEB], 0x003C
	setup channel=0x06, address=LABEL_173D
	mov [0xEC], 0x0018

DELAY_LOOP_VAREC_AT_177F:
	break
	djnz [0xEC], DELAY_LOOP_VAREC_AT_177F
	mov [0xEA], [0x01]
	add [0xEA], 0x0014
	setup channel=0x05, address=LABEL_171F
	break
	mov [0xEB], [0x01]
	sub [0xEB], 0x0032
	setup channel=0x06, address=LABEL_173D
	mov [0xEC], 0x0012

DELAY_LOOP_VAREC_AT_179F:
	break
	djnz [0xEC], DELAY_LOOP_VAREC_AT_179F
	mov [0xEA], [0x01]
	setup channel=0x05, address=LABEL_171F
	break
	setup channel=0x03, address=KILL_CHANNEL_LANDING
	break
	mov [0x04], 0x0010
	call LABEL_5F5A
	killChannel

LABEL_17B9:
	video offset=CINEMATIC_181, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_182, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_183, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_184, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp LABEL_147F

LABEL_17D4:
	video offset=CINEMATIC_185, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_ACTION], 0x01, LABEL_14EC
	je [HERO_POS_LEFT_RIGHT], 0x01, LABEL_147F
	je [HERO_POS_LEFT_RIGHT], 0x00, LABEL_17D4
	sub [0x01], 0x0001
	video offset=CINEMATIC_194, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video offset=CINEMATIC_195, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video offset=CINEMATIC_196, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0xE6], 0x0006

ANIM_CIN_197_LOOP_VARE6_AT_180E:
	video offset=CINEMATIC_197, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0xE6], ANIM_CIN_197_LOOP_VARE6_AT_180E
	sub [0x01], 0x0001
	video offset=CINEMATIC_198, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video offset=CINEMATIC_199, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video offset=CINEMATIC_200, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0002
	video offset=CINEMATIC_185, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp LABEL_17D4

LABEL_1843:
	mov [0x01], 0x0097
	mov [0x02], 0x00C8
	video offset=CINEMATIC_334, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_334, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_334, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_332, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_332, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_332, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_333, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_333, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_333, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_333, x=[0x01], y=[0x02], zoom=0x40
	killChannel

LABEL_1887:
	mov [0x01], 0x00D8
	mov [0x02], 0x00A3
	mov [0x32], 0x0001
	video offset=CINEMATIC_536, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0002
	add [0x02], 0x000C
	video offset=CINEMATIC_537, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0001
	add [0x02], 0x0011
	video offset=CINEMATIC_537, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0001
	mov [0x02], 0x009D
	play id=0x005E, freq=0x14, vol=0x20, channel=0x00
	video offset=CINEMATIC_538, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_539, x=[0x01], y=[0x02], zoom=0x40
	play id=0x007A, freq=0x14, vol=0x20, channel=0x01
	break
	video offset=CINEMATIC_538, x=[0x01], y=[0x02], zoom=0x40
	mov [0xE6], 0x000A

LABEL_18DE:
	break
	video offset=CINEMATIC_540, x=[0x01], y=[0x02], zoom=0x40
	djnz [0xE6], LABEL_18DE
	mov [0xE8], 0x0000
	video offset=CINEMATIC_541, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_542, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_543, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_544, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_545, x=[0x01], y=[0x02], zoom=0x40
	mov [0xE7], 0x0002

LABEL_190D:
	mov [0xE6], 0x000A

LABEL_1911:
	break
	video offset=CINEMATIC_546, x=[0x01], y=[0x02], zoom=0x40
	je [0xE8], 0x01, LABEL_1939
	djnz [0xE6], LABEL_1911
	mov [0xE6], 0x000A

LABEL_1925:
	break
	video offset=CINEMATIC_550, x=[0x01], y=[0x02], zoom=0x40
	je [0xE8], 0x01, LABEL_1939
	djnz [0xE6], LABEL_1925
	djnz [0xE7], LABEL_190D

LABEL_1939:
	break
	video offset=CINEMATIC_547, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x15], 0x000C
	video offset=CINEMATIC_516, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_517, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_548, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_549, x=[0x01], y=[0x02], zoom=0x40
	killChannel
