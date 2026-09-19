ALIEN_ARRIVAL_DELAY_THEN_DISSOLVE_IN:
	break
	djnz [0x09], ALIEN_ARRIVAL_DELAY_THEN_DISSOLVE_IN
	play id=0x0057, freq=0x0F, vol=0x20, channel=0x03
	video offset=CINEMATIC_021, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_022, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_023, x=[0x07], y=[0x08]
	mov [0x09], 0x000A

ALIEN_STAND_HOLD_THEN_WALK_START:
	break
	video offset=CINEMATIC_024, x=[0x07], y=[0x08]
	video offset=CINEMATIC_025, x=[0x07], y=[0x08]
	djnz [0x09], ALIEN_STAND_HOLD_THEN_WALK_START
	setup channel=0x11, address=ALIEN_WALK_HEAD_LOOP
	setup channel=0x12, address=DRAW_COMMON_VIDS_148_151_152_153
	setup channel=0x13, address=DRAW_COMMON_VIDS_149_141_137_10
	setup channel=0x0C, address=ENDING_X_SLIDE_RIGHT_ACCEL
	mov [0x09], 0x0010

ALIEN_WALK_DELAY_THEN_KNEEL:
	break
	djnz [0x09], ALIEN_WALK_DELAY_THEN_KNEEL
	setup channel=0x0C, address=KILL_CHANNEL_LANDING
	deleteChannels first=0x11, last=0x13
	break
	video offset=CINEMATIC_026, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_027, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_028, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_029, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_030, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_031, x=[0x07], y=[0x08]
	setup channel=0x05, address=PTERANODON_HEAD_BEAK_OPEN_ANIM
	mov [0x09], 0x000A

ALIEN_KNEEL_HOLD_THEN_LIFT_AND_SCENE_HANDOFF:
	break
	video offset=CINEMATIC_032, x=[0x07], y=[0x08]
	djnz [0x09], ALIEN_KNEEL_HOLD_THEN_LIFT_AND_SCENE_HANDOFF
	setup channel=0x1E, address=KILL_CHANNEL_LANDING
	break
	video offset=CINEMATIC_033, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_034, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_035, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_036, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_037, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_037, x=[0x07], y=[0x08]
	selectVideoPage 0x00
	fill page=0x00, color=0x01
	call DRAW_STARS_CIN_38_39_40_5_6
	selectVideoPage 0xFF
	setup channel=0x05, address=KILL_CHANNEL_LANDING
	setup channel=0x0A, address=ENDING_SKY_SHOT_ENTRY
	killChannel

ALIEN_WALK_HEAD_LOOP:
	video offset=CINEMATIC_024, x=[0x07], y=[0x08]
	break
	jmp ALIEN_WALK_HEAD_LOOP
LABEL_0853:
	db 0x11

DRAW_COMMON_VIDS_148_151_152_153:
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
	jmp DRAW_COMMON_VIDS_148_151_152_153
LABEL_08B7:
	db 0x11

DRAW_COMMON_VIDS_149_141_137_10:
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
	jmp DRAW_COMMON_VIDS_149_141_137_10
LABEL_091B:
	db 0x11

ENDING_X_SLIDE_RIGHT_ACCEL:
	mov [0x0A], 0x0003
	add [0x07], 0x0002
	break
	djnz [0x0A], ENDING_X_SLIDE_RIGHT_ACCEL
	mov [0x0A], 0x0005

ENDING_X_SLIDE_RIGHT_PLUS3_DJNZ_THEN_ACCEL:
	add [0x07], 0x0003
	break
	djnz [0x0A], ENDING_X_SLIDE_RIGHT_PLUS3_DJNZ_THEN_ACCEL
	jmp ENDING_X_SLIDE_RIGHT_ACCEL
	killChannel
	video offset=CINEMATIC_108, x=160, y=100
	video type=0, offset=COMMON_VIDEO_301, x=160, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_291, x=160, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_202, x=160, y=100, zoom=0x40
	killChannel
