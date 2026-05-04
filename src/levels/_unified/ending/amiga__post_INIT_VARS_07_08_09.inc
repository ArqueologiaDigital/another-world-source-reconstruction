DELAY_LOOP_VAR09__AMIGA__POST_INIT_VARS_07_08_09:
	break
	djnz [0x09], DELAY_LOOP_VAR09__AMIGA__POST_INIT_VARS_07_08_09
	play id=0x0057, freq=0x0F, vol=0x20, channel=0x03
	video type=1, offset=CINEMATIC_021, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_022, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_023, x=[0x07], y=[0x08], zoom=0x40
	mov [0x09], 0x000A

LABEL_069F:
	break
	video type=1, offset=CINEMATIC_024, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_025, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x09], LABEL_069F
	setup channel=0x11, address=DRAW_CIN_024_LOOP__AMIGA__POST_INIT_VARS_07_08_09
	setup channel=0x12, address=DRAW_COMMON_VIDS_148_151_152_153
	setup channel=0x13, address=DRAW_COMMON_VIDS_149_141_137_10
	setup channel=0x0C, address=DRIFT_VAR07_PLUS_2_3X__AMIGA__POST_INIT_VARS_07_08_09
	mov [0x09], 0x0010

DELAY_LOOP_VAR09_AT_06C2:
	break
	djnz [0x09], DELAY_LOOP_VAR09_AT_06C2
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

LABEL_06FB:
	break
	video type=1, offset=CINEMATIC_032, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x09], LABEL_06FB
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

DRAW_CIN_024_LOOP__AMIGA__POST_INIT_VARS_07_08_09:
	video type=1, offset=CINEMATIC_024, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp DRAW_CIN_024_LOOP__AMIGA__POST_INIT_VARS_07_08_09
LABEL_0749:
	db 0x11

DRAW_COMMON_VIDS_148_151_152_153:
	video type=0, offset=COMMON_VIDEO_148, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_151, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_152, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_153, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_154, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_155, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_156, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_157, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_124, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_127, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_128, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_131, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_134, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_136, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_140, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_144, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp DRAW_COMMON_VIDS_148_151_152_153
LABEL_07AD:
	db 0x11

DRAW_COMMON_VIDS_149_141_137_10:
	video type=0, offset=COMMON_VIDEO_149, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_141, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_137, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_010, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_132, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_129, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_158, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_158, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_125, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_125, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_129, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_132, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_010, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_137, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_141, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_145, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp DRAW_COMMON_VIDS_149_141_137_10
LABEL_0811:
	db 0x11

DRIFT_VAR07_PLUS_2_3X__AMIGA__POST_INIT_VARS_07_08_09:
	mov [0x0A], 0x0003
	add [0x07], 0x0002
	break
	djnz [0x0A], DRIFT_VAR07_PLUS_2_3X__AMIGA__POST_INIT_VARS_07_08_09
	mov [0x0A], 0x0005

LABEL_0823:
	add [0x07], 0x0003
	break
	djnz [0x0A], LABEL_0823
	jmp DRIFT_VAR07_PLUS_2_3X__AMIGA__POST_INIT_VARS_07_08_09
LABEL_082F:
	db 0x11, 0x80, 0x06, 0xA0, 0x64, 0x6B, 0x0E, 0x3C
	db 0xA0, 0x64, 0x6B, 0x21, 0xA3, 0xA0, 0x64, 0x6B
	db 0x0D, 0x2A, 0xA0, 0x64, 0x11
