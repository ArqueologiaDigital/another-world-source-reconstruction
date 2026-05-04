DELAY_LOOP_VAR09:
	break
	djnz [0x09], DELAY_LOOP_VAR09
	play id=0x0057, freq=0x0F, vol=0x20, channel=0x03
	video type=1, offset=CINEMATIC_021, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_022, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_023, x=[0x07], y=[0x08], zoom=0x40
	mov [0x09], 0x000A

LABEL_07A9:
	break
	video type=1, offset=CINEMATIC_024, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_025, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x09], LABEL_07A9
	setup channel=0x11, address=DRAW_CIN_024_LOOP
	setup channel=0x12, address=DRAW_CV_192_195_196_SEQ
	setup channel=0x13, address=DRAW_CV_193_185_181_SEQ
	setup channel=0x0C, address=DRIFT_VAR07_PLUS_2_3X
	mov [0x09], 0x0010

DELAY_LOOP_VAR09_AT_07CC:
	break
	djnz [0x09], DELAY_LOOP_VAR09_AT_07CC
	setup channel=0x0C, address=KILL_CHANNEL_LANDING
	deleteChannels first=0x11, last=0x13
	break
	video type=1, offset=CINEMATIC_026, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_027, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_028, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_029, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_030, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_031, x=[0x07], y=[0x08], zoom=0x40
	setup channel=0x05, address=DRAW_CIN_106_107_FX_57
	mov [0x09], 0x000A

LABEL_0805:
	break
	video type=1, offset=CINEMATIC_032, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x09], LABEL_0805
	setup channel=0x1E, address=KILL_CHANNEL_LANDING
	break
	video type=1, offset=CINEMATIC_033, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_034, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_035, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_036, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_037, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_037, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0x00
	fill page=0x00, color=0x01
	call DRAW_STARS_CIN_38_39_40_5_6
	selectVideoPage 0xFF
	setup channel=0x05, address=KILL_CHANNEL_LANDING
	setup channel=0x0A, address=SET_VAR_E6_5_PAL_B
	killChannel

DRAW_CIN_024_LOOP:
	video type=1, offset=CINEMATIC_024, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp DRAW_CIN_024_LOOP
LABEL_0853:
	db 0x11

DRAW_CV_192_195_196_SEQ:
	video type=0, offset=COMMON_VIDEO_192, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_195, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_196, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_197, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_198, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_199, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_200, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_201, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_168, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_171, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_172, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_175, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_178, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_180, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_184, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_188, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp DRAW_CV_192_195_196_SEQ
LABEL_08B7:
	db 0x11

DRAW_CV_193_185_181_SEQ:
	video type=0, offset=COMMON_VIDEO_193, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_185, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_181, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_129, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_176, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_173, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_202, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_202, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_169, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_169, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_173, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_176, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_129, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_181, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_185, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_189, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp DRAW_CV_193_185_181_SEQ
LABEL_091B:
	db 0x11

DRIFT_VAR07_PLUS_2_3X:
	mov [0x0A], 0x0003
	add [0x07], 0x0002
	break
	djnz [0x0A], DRIFT_VAR07_PLUS_2_3X
	mov [0x0A], 0x0005

LABEL_092D:
	add [0x07], 0x0003
	break
	djnz [0x0A], LABEL_092D
	jmp DRIFT_VAR07_PLUS_2_3X
	killChannel
	video type=1, offset=CINEMATIC_108, x=160, y=100
	video type=0, offset=COMMON_VIDEO_301, x=160, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_291, x=160, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_202, x=160, y=100, zoom=0x40
	killChannel
