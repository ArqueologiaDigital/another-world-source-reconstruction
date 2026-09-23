ALIEN_ARRIVAL_DELAY_THEN_DISSOLVE_IN:
	break
	djnz [0x09], ALIEN_ARRIVAL_DELAY_THEN_DISSOLVE_IN
	play id=0x0057, freq=0x0F, vol=0x20, channel=0x03
	video offset=CINEMATIC_ENDING_ALIEN_DISSOLVE_F0, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_ENDING_ALIEN_DISSOLVE_F1, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_ENDING_ALIEN_DISSOLVE_F2, x=[0x07], y=[0x08]
	mov [0x09], 0x000A

ALIEN_STAND_HOLD_THEN_WALK_START:
	break
	video offset=CINEMATIC_024, x=[0x07], y=[0x08]
	video offset=CINEMATIC_ENDING_ALIEN_STANDING, x=[0x07], y=[0x08]
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
	video offset=CINEMATIC_ENDING_ALIEN_WALK_F0, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_ENDING_ALIEN_WALK_F1, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_ENDING_ALIEN_WALK_F2, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_ENDING_ALIEN_WALK_F3, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_ENDING_ALIEN_WALK_F4, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_ENDING_ALIEN_WALK_F5, x=[0x07], y=[0x08]
	setup channel=0x05, address=PTERANODON_HEAD_BEAK_OPEN_ANIM
	mov [0x09], 0x000A

ALIEN_LIFT_HOLD_THEN_CUT_TO_SKY:
	break
	video offset=CINEMATIC_ENDING_ALIEN_LIFT_F0, x=[0x07], y=[0x08]
	djnz [0x09], ALIEN_LIFT_HOLD_THEN_CUT_TO_SKY
	setup channel=0x1E, address=KILL_CHANNEL_LANDING
	break
	video offset=CINEMATIC_ENDING_ALIEN_LIFT_F1, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_ENDING_ALIEN_LIFT_F2, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_ENDING_ALIEN_LIFT_F3, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_ENDING_ALIEN_LIFT_F4, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_ENDING_ALIEN_LIFT_F5, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_ENDING_ALIEN_LIFT_F5, x=[0x07], y=[0x08]
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
LABEL_0749:
	db 0x11

DRAW_COMMON_VIDS_148_151_152_153:
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F08, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F09, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F10, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F11, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F12, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F13, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F14, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F15, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F00, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F01, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F02, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F03, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F04, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F05, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F06, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F07, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp DRAW_COMMON_VIDS_148_151_152_153
LABEL_07AD:
	db 0x11

DRAW_COMMON_VIDS_149_141_137_10:
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_07, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_05, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_04, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_03, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_02, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_01, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_08, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_08, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_00, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_00, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_01, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_02, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_03, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_04, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_05, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_06, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp DRAW_COMMON_VIDS_149_141_137_10
LABEL_0811:
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
LABEL_082F:
	db 0x11, 0x80, 0x06, 0xA0, 0x64, 0x6B, 0x0E, 0x3C
	db 0xA0, 0x64, 0x6B, 0x21, 0xA3, 0xA0, 0x64, 0x6B
	db 0x0D, 0x2A, 0xA0, 0x64, 0x11
