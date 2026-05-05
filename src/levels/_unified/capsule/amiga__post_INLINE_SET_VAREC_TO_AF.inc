DELAY_LOOP_VAREC:
	break
	djnz [0xEC], DELAY_LOOP_VAREC
	mov [0xEA], [HERO_X]
	sub [0xEA], 0x0064
	setup channel=0x05, address=LABEL_0771
	break
	mov [0xEB], [HERO_X]
	sub [0xEB], 0x003C
	setup channel=0x06, address=LABEL_078F
	mov [0xEC], 0x0018

DELAY_LOOP_VAREC_AT_07D1:
	break
	djnz [0xEC], DELAY_LOOP_VAREC_AT_07D1
	mov [0xEA], [HERO_X]
	add [0xEA], 0x0014
	setup channel=0x05, address=LABEL_0771
	break
	mov [0xEB], [HERO_X]
	sub [0xEB], 0x0032
	setup channel=0x06, address=LABEL_078F
	mov [0xEC], 0x0012

DELAY_LOOP_VAREC_AT_07F1:
	break
	djnz [0xEC], DELAY_LOOP_VAREC_AT_07F1
	mov [0xEA], [HERO_X]
	setup channel=0x05, address=LABEL_0771
	break
	setup channel=0x03, address=KILL_CHANNEL_LANDING
	break
	mov [0x04], 0x0010
	call LABEL_47F0
	killChannel

LABEL_080B:
	video offset=CINEMATIC_366, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_367, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_368, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_369, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_04AB

LABEL_0826:
	video offset=CINEMATIC_370, x=[HERO_X], y=[HERO_Y]
	break
	je [HERO_ACTION], 0x01, LABEL_0518
	je [HERO_POS_LEFT_RIGHT], 0x01, LABEL_04AB
	je [HERO_POS_LEFT_RIGHT], 0x00, LABEL_0826
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_379, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_380, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_381, x=[HERO_X], y=[HERO_Y]
	break
	mov [0xE6], 0x0006

ANIM_CIN_382_LOOP_VARE6_AT_0860:
	video offset=CINEMATIC_382, x=[HERO_X], y=[HERO_Y]
	break
	djnz [0xE6], ANIM_CIN_382_LOOP_VARE6_AT_0860
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_383, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_384, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_385, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0002
	video offset=CINEMATIC_370, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_0826

LABEL_0895:
	mov [HERO_X], 0x0097
	mov [HERO_Y], 0x00C8
	video offset=CINEMATIC_460, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_460, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_460, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_461, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_461, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_461, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_462, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_462, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_462, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_462, x=[HERO_X], y=[HERO_Y]
	killChannel

LABEL_08D9:
	mov [HERO_X], 0x00D8
	mov [HERO_Y], 0x00A3
	mov [0x32], 0x0001
	video offset=CINEMATIC_443, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0002
	add [HERO_Y], 0x000C
	video offset=CINEMATIC_444, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	add [HERO_Y], 0x0011
	video offset=CINEMATIC_444, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	mov [HERO_Y], 0x009D
	play id=0x005E, freq=0x14, vol=0x20, channel=0x00
	video offset=CINEMATIC_445, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_446, x=[HERO_X], y=[HERO_Y]
	play id=0x007A, freq=0x14, vol=0x20, channel=0x01
	break
	video offset=CINEMATIC_445, x=[HERO_X], y=[HERO_Y]
	mov [0xE6], 0x000A

LABEL_0930:
	break
	video offset=CINEMATIC_447, x=[HERO_X], y=[HERO_Y]
	djnz [0xE6], LABEL_0930
	mov [0xE8], 0x0000
	video offset=CINEMATIC_448, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_449, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_450, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_451, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_452, x=[HERO_X], y=[HERO_Y]
	mov [0xE7], 0x0002

SET_VARE6_TO_A:
	mov [0xE6], 0x000A

LABEL_0963:
	break
	video offset=CINEMATIC_453, x=[HERO_X], y=[HERO_Y]
	je [0xE8], 0x01, LABEL_098B
	djnz [0xE6], LABEL_0963
	mov [0xE6], 0x000A

LABEL_0977:
	break
	video offset=CINEMATIC_459, x=[HERO_X], y=[HERO_Y]
	je [0xE8], 0x01, LABEL_098B
	djnz [0xE6], LABEL_0977
	djnz [0xE7], SET_VARE6_TO_A

LABEL_098B:
	break
	video offset=CINEMATIC_454, x=[HERO_X], y=[HERO_Y]
	break
	sub [0x15], 0x000C
	video offset=CINEMATIC_455, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_456, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_457, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_458, x=[HERO_X], y=[HERO_Y]
	killChannel
