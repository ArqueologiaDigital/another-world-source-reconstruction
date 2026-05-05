ANIM_CIN_585_LOOP_VAR03_AT_067D:
	video offset=CINEMATIC_585, x=[0x01], y=[0x02]
	break
	djnz [0x03], ANIM_CIN_585_LOOP_VAR03_AT_067D
	mov [0x03], 0x0006

ANIM_CIN_586_LOOP_VAR03:
	video offset=CINEMATIC_586, x=[0x01], y=[0x02]
	break
	djnz [0x03], ANIM_CIN_586_LOOP_VAR03
	mov [0x03], 0x0004

ANIM_CIN_585_LOOP_VAR03_AT_0699:
	video offset=CINEMATIC_585, x=[0x01], y=[0x02]
	break
	djnz [0x03], ANIM_CIN_585_LOOP_VAR03_AT_0699
	play id=0x0060, freq=0x14, vol=0x14, channel=0x02
	video offset=CINEMATIC_587, x=[0x01], y=[0x02]
	break
	mov [0x03], 0x0004

ANIM_CIN_588_LOOP_VAR03_AT_06B3:
	video offset=CINEMATIC_588, x=[0x01], y=[0x02]
	break
	djnz [0x03], ANIM_CIN_588_LOOP_VAR03_AT_06B3
	mov [0x03], 0x0006

ANIM_CIN_589_LOOP_VAR03_AT_06C1:
	video offset=CINEMATIC_589, x=[0x01], y=[0x02]
	break
	djnz [0x03], ANIM_CIN_589_LOOP_VAR03_AT_06C1
	mov [0x03], 0x0004

ANIM_CIN_588_LOOP_VAR03_AT_06CF:
	video offset=CINEMATIC_588, x=[0x01], y=[0x02]
	break
	djnz [0x03], ANIM_CIN_588_LOOP_VAR03_AT_06CF
	mov [0x03], 0x0006
	play id=0x0060, freq=0x14, vol=0x14, channel=0x02

ANIM_CIN_589_LOOP_VAR03_AT_06E3:
	video offset=CINEMATIC_589, x=[0x01], y=[0x02]
	break
	djnz [0x03], ANIM_CIN_589_LOOP_VAR03_AT_06E3
	play id=0x0067, freq=0x14, vol=0x40, channel=0x02
	or [0xB9], 0x0080
	mov [0x03], 0x000A

ANIM_CIN_590_LOOP_VAR03:
	video offset=CINEMATIC_590, x=[0x01], y=[0x02]
	break
	djnz [0x03], ANIM_CIN_590_LOOP_VAR03
	setup channel=0x04, address=PLAY_FX_30_CH2_VOL_C_SET_VARED_A
	setup channel=0x05, address=PLAY_FX_56_CH3_SET_VAREE_F
	mov [0x03], 0x000A

LABEL_0711:
	video type=0, offset=COMMON_VIDEO_335, x=[0x01], y=[0x02], zoom=0x40
	djnz [0x03], LABEL_0711
	break
	mov [0x63], 0x0002
	call SET_VAR04_TO_0020
	video offset=CINEMATIC_073, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_074, x=[0x01], y=[0x02]
	jmp HERO_WALK_RIGHT_LOOP
LABEL_0730:
	db 0x11

HANG_DRAW_CIN_591:
	video offset=CINEMATIC_591, x=160, y=100
	break
	jmp HANG_DRAW_CIN_591

LABEL_0739:
	mov [0xF8], [0xB9]
	and [0xF8], 0x0080
	jne [0xF8], 0x00, HANG_DRAW_CIN_591
	video offset=CINEMATIC_592, x=160, y=100
	break
	jmp LABEL_0739
