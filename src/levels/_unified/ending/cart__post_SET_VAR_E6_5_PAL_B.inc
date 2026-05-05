ANIM_CIN_042_LOOP_VARE6:
	video offset=CINEMATIC_042, x=160, y=100
	break
	djnz [0xE6], ANIM_CIN_042_LOOP_VARE6
	play id=0x0057, freq=0x0F, vol=0x20, channel=0x03
	video offset=CINEMATIC_043, x=160, y=100
	break
	video offset=CINEMATIC_044, x=160, y=100
	break
	video offset=CINEMATIC_045, x=160, y=100
	break
	video offset=CINEMATIC_046, x=160, y=100
	mov [0xE6], 0x0007

LABEL_0635:
	break
	video offset=CINEMATIC_046, x=160, y=100
	djnz [0xE6], LABEL_0635
	play id=0x0057, freq=0x0F, vol=0x20, channel=0x03
	break
	video offset=CINEMATIC_047, x=160, y=100
	break
	video offset=CINEMATIC_048, x=160, y=100
	break
	video offset=CINEMATIC_049, x=160, y=100
	break
	video offset=CINEMATIC_050, x=160, y=100
	mov [0xE6], 0x000A

LABEL_065C:
	break
	video offset=CINEMATIC_051, x=160, y=100
	djnz [0xE6], LABEL_065C
	setup channel=0x0A, address=ZOOM_LOOP_CIN_105
	setup channel=0x0B, address=DRAW_CIN_101_102_FADE_PAL_C
	setup channel=0x0C, address=DRAW_CIN_97_TO_100
	setup channel=0x0D, address=LABEL_00BF
	killChannel

LABEL_0676:
	call DRAW_STARS_PAGE0_CIN_000
	call DRAW_STARS_PAGE3_CIN_004
	setup channel=0x05, address=HANG_DRAWING_CIN_071
	selectVideoPage 0x00
	play id=0x0008, freq=0x05, vol=0x20, channel=0x00
	play id=0x0008, freq=0x07, vol=0x30, channel=0x01
	video offset=CINEMATIC_008, x=160, y=100
	video offset=CINEMATIC_009, x=160, y=100
	video offset=CINEMATIC_010, x=160, y=100
	selectVideoPage 0xFF
	mov [PAUSE_SLICES], 0x0004
	mov [0x03], 0x000A
	mov [0x01], 0x00A0
	mov [0x02], 0x0064
	setPalette 0x0A

DELAY_LOOP_VAR03:
	break
	djnz [0x03], DELAY_LOOP_VAR03
	setup channel=0x05, address=DRAW_CIN_71_72_FADE
	video offset=CINEMATIC_011, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0008, freq=0x0A, vol=0x16, channel=0x00
	play id=0x0057, freq=0x14, vol=0x20, channel=0x02
	break
	video offset=CINEMATIC_012, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_013, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_014, x=[0x01], y=[0x02], zoom=0x40
	play id=0x000E, freq=0x03, vol=0x20, channel=0x03
	mov [0x03], 0x0014

LABEL_06E5:
	break
	video offset=CINEMATIC_015, x=[0x01], y=[0x02], zoom=0x40
	djnz [0x03], LABEL_06E5
	mov [PAUSE_SLICES], 0x000A
	mov [0x03], 0x0006
	play id=0x000F, freq=0x03, vol=0x30, channel=0x03
	break
	play id=0x0008, freq=0x07, vol=0x11, channel=0x01

LABEL_0704:
	video offset=CINEMATIC_014, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_014, x=[0x01], y=[0x02], zoom=0x40
	break
	jne [0x03], 0x04, LABEL_0722
	song id=0x008A, delay=0x3A98, pos=0x00
	play id=0x0008, freq=0x0A, vol=0x16, channel=0x00

LABEL_0722:
	jne [0x03], 0x03, LABEL_072E
	play id=0x0008, freq=0x0A, vol=0x0B, channel=0x00

LABEL_072E:
	video offset=CINEMATIC_013, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0002
	video offset=CINEMATIC_016, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_016, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0001
	video offset=CINEMATIC_017, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_017, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_018, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_018, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_018, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_015, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_014, x=[0x01], y=[0x02], zoom=0x40
	break
	add [PAUSE_SLICES], 0x0002
	djnz [0x03], LABEL_0704
	mov [PAUSE_SLICES], 0x0006
	video offset=CINEMATIC_019, x=[0x01], y=[0x02], zoom=0x40
	setup channel=0x14, address=INIT_VARS_07_08_09

LABEL_0787:
	break
	video offset=CINEMATIC_020, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_0787
LABEL_0790:
	db 0x11
