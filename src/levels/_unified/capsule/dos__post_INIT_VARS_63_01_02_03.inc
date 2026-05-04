ANIM_CIN_576_LOOP_VAR03_AT_05C7:
	video type=1, offset=CINEMATIC_576, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0x03], ANIM_CIN_576_LOOP_VAR03_AT_05C7
	mov [0x03], 0x0006

ANIM_CIN_577_LOOP_VAR03:
	video type=1, offset=CINEMATIC_577, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0x03], ANIM_CIN_577_LOOP_VAR03
	mov [0x03], 0x0004

ANIM_CIN_576_LOOP_VAR03_AT_05E3:
	video type=1, offset=CINEMATIC_576, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0x03], ANIM_CIN_576_LOOP_VAR03_AT_05E3
	play id=0x0060, freq=0x14, vol=0x14, channel=0x02
	video type=1, offset=CINEMATIC_578, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x03], 0x0004

ANIM_CIN_579_LOOP_VAR03_AT_05FD:
	video type=1, offset=CINEMATIC_579, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0x03], ANIM_CIN_579_LOOP_VAR03_AT_05FD
	mov [0x03], 0x0006

ANIM_CIN_580_LOOP_VAR03_AT_060B:
	video type=1, offset=CINEMATIC_580, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0x03], ANIM_CIN_580_LOOP_VAR03_AT_060B
	mov [0x03], 0x0004

ANIM_CIN_579_LOOP_VAR03_AT_0619:
	video type=1, offset=CINEMATIC_579, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0x03], ANIM_CIN_579_LOOP_VAR03_AT_0619
	mov [0x03], 0x0006
	play id=0x0060, freq=0x14, vol=0x14, channel=0x02

ANIM_CIN_580_LOOP_VAR03_AT_062D:
	video type=1, offset=CINEMATIC_580, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0x03], ANIM_CIN_580_LOOP_VAR03_AT_062D
	play id=0x0067, freq=0x14, vol=0x40, channel=0x02
	or [0xB9], 0x0080
	mov [0x03], 0x000A

ANIM_CIN_581_LOOP_VAR03:
	video type=1, offset=CINEMATIC_581, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0x03], ANIM_CIN_581_LOOP_VAR03
	setup channel=0x04, address=PLAY_FX_30_CH2_VOL_C_SET_VARED_A
	setup channel=0x05, address=PLAY_FX_56_CH3_SET_VAREE_F
	mov [0x03], 0x000A

LABEL_065B:
	video type=0, offset=COMMON_VIDEO_335, x=[0x01], y=[0x02], zoom=0x40
	djnz [0x03], LABEL_065B
	break
	mov [0x63], 0x0002
	call SET_VAR04_TO_0020
	video type=1, offset=CINEMATIC_073, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_074, x=[0x01], y=[0x02], zoom=0x40
	jmp HERO_WALK_RIGHT_LOOP
LABEL_067A:
	db 0x11

HANG_DRAW_CIN_582:
	video type=1, offset=CINEMATIC_582, x=160, y=100
	break
	jmp HANG_DRAW_CIN_582

LABEL_0683:
	mov [0xF8], [0xB9]
	and [0xF8], 0x0080
	jne [0xF8], 0x00, HANG_DRAW_CIN_582
	video type=1, offset=CINEMATIC_583, x=160, y=100
	break
	jmp LABEL_0683
