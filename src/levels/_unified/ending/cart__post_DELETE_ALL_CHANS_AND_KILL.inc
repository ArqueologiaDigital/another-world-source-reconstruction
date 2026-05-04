PRELOAD_RESOURCES_8_TO_1:
	jne [0xDB], 0x00, LABEL_0060
	load id=0x0008
	load id=0x008A
	load id=0x0081
	load id=0x0082
	load id=0x0083
	load id=0x0080
	load id=0x0001
	load id=0x0057
	load id=0x005E
	load id=0x000E
	load id=0x000F
	load id=0x005F
	load id=0x000C
	ret

LABEL_0060:
	load id=0x07DF
	song id=0x0BDC, delay=0x0000, pos=0x00
	ret

DRAW_CIN_97_TO_100:
	video type=1, offset=CINEMATIC_097, x=160, y=100
	break
	video type=1, offset=CINEMATIC_098, x=160, y=100
	break
	video type=1, offset=CINEMATIC_099, x=160, y=100
	break
	video type=1, offset=CINEMATIC_100, x=160, y=100
	break
	video type=1, offset=CINEMATIC_099, x=160, y=100
	break
	video type=1, offset=CINEMATIC_098, x=160, y=100
	break
	jmp DRAW_CIN_97_TO_100
LABEL_008B:
	db 0x11

DRAW_CIN_101_102_FADE_PAL_C:
	video type=1, offset=CINEMATIC_101, x=160, y=125
	setPalette 0x0C
	break
	video type=1, offset=CINEMATIC_101, x=160, y=118
	break
	video type=1, offset=CINEMATIC_102, x=160, y=112
	break
	video type=1, offset=CINEMATIC_103, x=160, y=107
	break
	video type=1, offset=CINEMATIC_104, x=160, y=105
	break
	video type=1, offset=CINEMATIC_104, x=160, y=109
	break
	video type=1, offset=CINEMATIC_104, x=160, y=110
	break
	video type=1, offset=CINEMATIC_103, x=160, y=115

DRAW_CIN_103_LOOP:
	break
	video type=1, offset=CINEMATIC_103, x=160, y=118
	jmp DRAW_CIN_103_LOOP
LABEL_00BE:
	db 0x11

LABEL_00BF:
	mov [0x01], 0x00A0
	mov [0x02], 0x0064
	mov [0x03], 0x0040
	video type=1, offset=CINEMATIC_052, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_053, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_054, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_055, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_056, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_054, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_057, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_053, x=[0x01], y=[0x02], zoom=[0x03]
	deleteChannels first=0x0A, last=0x0E
	copyVideoPage src=0x03, dst=0x00
	setup channel=0x0A, address=LABEL_0159
	setup channel=0x0B, address=DRAW_CIN_58_ANIM_LOOP
	setup channel=0x0E, address=HANG_DRAWING_CIN_066_VAR03
	setup channel=0x0F, address=DRAW_CIN_59_TO_64_VAR_POS
	killChannel

DRAW_CIN_58_ANIM_LOOP:
	video type=1, offset=CINEMATIC_058, x=160, y=100, zoom=[0x04]
	break
	jmp DRAW_CIN_58_ANIM_LOOP
LABEL_0124:
	db 0x11

DRAW_CIN_59_TO_64_VAR_POS:
	video type=1, offset=CINEMATIC_059, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_060, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_061, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_062, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_063, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_064, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_065, x=[0x01], y=[0x02], zoom=[0x03]
	break
	jmp DRAW_CIN_59_TO_64_VAR_POS

LABEL_0159:
	mov [0x01], 0x00A0
	mov [0x02], 0x0064
	mov [0x03], 0x0040
	mov [0x04], 0x0040
	setPalette 0x0B
	add [0x04], 0x0002
	video type=1, offset=CINEMATIC_067, x=[0x01], y=[0x02], zoom=[0x03]
	break
	add [0x04], 0x0005
	video type=1, offset=CINEMATIC_068, x=[0x01], y=[0x02], zoom=[0x03]
	break
	add [0x04], 0x0008
	video type=1, offset=CINEMATIC_069, x=[0x01], y=[0x02], zoom=[0x03]
	setup channel=0x0C, address=DRAW_CIN_086_087_SEQ
	setup channel=0x0D, address=DRAW_CIN_075_076_SEQ
	mov [0x06], 0x000A

DRIFT_VAR_4_PLUS_10_LOOP:
	break
	add [0x04], 0x000A
	djnz [0x06], DRIFT_VAR_4_PLUS_10_LOOP
	setup channel=0x0B, address=KILL_CHANNEL_LANDING
	mov [0x06], 0x0030

DRIFT_VAR_3_MINUS_1_LOOP:
	break
	sub [0x03], 0x0001
	djnz [0x06], DRIFT_VAR_3_MINUS_1_LOOP
	setup channel=0x10, address=INIT_VARE_TO_12
	setup channel=0x11, address=DRAW_CIN_70_ANIM_LOOP
	mov [0x0F], 0x0001
	mov [0x06], 0x000C

DRIFT_VAR_3_MINUS_1_TWO_BRKS:
	break
	break
	sub [0x03], 0x0001
	djnz [0x06], DRIFT_VAR_3_MINUS_1_TWO_BRKS
	mov [0x06], 0x0019

DELAY_VAR6_THEN_VAR3_MINUS_1:
	break
	djnz [0x06], DELAY_VAR6_THEN_VAR3_MINUS_1
	sub [0x03], 0x0001
	mov [0x06], 0x0019

DELAY_VAR6_THEN_KILL_CHAN:
	break
	djnz [0x06], DELAY_VAR6_THEN_KILL_CHAN
	sub [0x03], 0x0001
	killChannel
