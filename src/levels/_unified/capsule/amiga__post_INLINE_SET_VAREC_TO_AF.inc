DELAY_LOOP_VAREC:
	break
	djnz [0xEC], DELAY_LOOP_VAREC
	mov [0xEA], [0x01]
	sub [0xEA], 0x0064
	setup channel=0x05, address=LABEL_0771
	break
	mov [0xEB], [0x01]
	sub [0xEB], 0x003C
	setup channel=0x06, address=LABEL_078F
	mov [0xEC], 0x0018

DELAY_LOOP_VAREC_AT_07D1:
	break
	djnz [0xEC], DELAY_LOOP_VAREC_AT_07D1
	mov [0xEA], [0x01]
	add [0xEA], 0x0014
	setup channel=0x05, address=LABEL_0771
	break
	mov [0xEB], [0x01]
	sub [0xEB], 0x0032
	setup channel=0x06, address=LABEL_078F
	mov [0xEC], 0x0012

DELAY_LOOP_VAREC_AT_07F1:
	break
	djnz [0xEC], DELAY_LOOP_VAREC_AT_07F1
	mov [0xEA], [0x01]
	setup channel=0x05, address=LABEL_0771
	break
	setup channel=0x03, address=KILL_CHANNEL_LANDING
	break
	mov [0x04], 0x0010
	call LABEL_47F0
	killChannel

LABEL_080B:
	video type=1, offset=CINEMATIC_366, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_367, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_368, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_369, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp LABEL_04AB

LABEL_0826:
	video type=1, offset=CINEMATIC_370, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_ACTION], 0x01, LABEL_0518
	je [HERO_POS_LEFT_RIGHT], 0x01, LABEL_04AB
	je [HERO_POS_LEFT_RIGHT], 0x00, LABEL_0826
	sub [0x01], 0x0001
	video type=1, offset=CINEMATIC_379, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video type=1, offset=CINEMATIC_380, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video type=1, offset=CINEMATIC_381, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0xE6], 0x0006

ANIM_CIN_382_LOOP_VARE6_AT_0860:
	video type=1, offset=CINEMATIC_382, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0xE6], ANIM_CIN_382_LOOP_VARE6_AT_0860
	sub [0x01], 0x0001
	video type=1, offset=CINEMATIC_383, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video type=1, offset=CINEMATIC_384, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video type=1, offset=CINEMATIC_385, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_370, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp LABEL_0826

LABEL_0895:
	mov [0x01], 0x0097
	mov [0x02], 0x00C8
	video type=1, offset=CINEMATIC_460, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_460, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_460, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_461, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_461, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_461, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_462, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_462, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_462, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_462, x=[0x01], y=[0x02], zoom=0x40
	killChannel

LABEL_08D9:
	mov [0x01], 0x00D8
	mov [0x02], 0x00A3
	mov [0x32], 0x0001
	video type=1, offset=CINEMATIC_443, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0002
	add [0x02], 0x000C
	video type=1, offset=CINEMATIC_444, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0001
	add [0x02], 0x0011
	video type=1, offset=CINEMATIC_444, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0001
	mov [0x02], 0x009D
	play id=0x005E, freq=0x14, vol=0x20, channel=0x00
	video type=1, offset=CINEMATIC_445, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_446, x=[0x01], y=[0x02], zoom=0x40
	play id=0x007A, freq=0x14, vol=0x20, channel=0x01
	break
	video type=1, offset=CINEMATIC_445, x=[0x01], y=[0x02], zoom=0x40
	mov [0xE6], 0x000A

LABEL_0930:
	break
	video type=1, offset=CINEMATIC_447, x=[0x01], y=[0x02], zoom=0x40
	djnz [0xE6], LABEL_0930
	mov [0xE8], 0x0000
	video type=1, offset=CINEMATIC_448, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_449, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_450, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_451, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_452, x=[0x01], y=[0x02], zoom=0x40
	mov [0xE7], 0x0002

SET_VARE6_TO_A:
	mov [0xE6], 0x000A

LABEL_0963:
	break
	video type=1, offset=CINEMATIC_453, x=[0x01], y=[0x02], zoom=0x40
	je [0xE8], 0x01, LABEL_098B
	djnz [0xE6], LABEL_0963
	mov [0xE6], 0x000A

LABEL_0977:
	break
	video type=1, offset=CINEMATIC_459, x=[0x01], y=[0x02], zoom=0x40
	je [0xE8], 0x01, LABEL_098B
	djnz [0xE6], LABEL_0977
	djnz [0xE7], SET_VARE6_TO_A

LABEL_098B:
	break
	video type=1, offset=CINEMATIC_454, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x15], 0x000C
	video type=1, offset=CINEMATIC_455, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_456, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_457, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_458, x=[0x01], y=[0x02], zoom=0x40
	killChannel
