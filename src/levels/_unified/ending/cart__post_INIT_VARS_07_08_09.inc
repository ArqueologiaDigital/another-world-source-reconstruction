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

LABEL_07BD:
	break
	video offset=CINEMATIC_024, x=[0x07], y=[0x08]
	video offset=CINEMATIC_ENDING_ALIEN_STANDING, x=[0x07], y=[0x08]
	djnz [0x09], LABEL_07BD
	setup channel=0x11, address=ALIEN_WALK_HEAD_LOOP
	setup channel=0x12, address=DRAW_COMMON_VIDS_148_151_152_153
	setup channel=0x13, address=DRAW_COMMON_VIDS_149_141_137_10
	setup channel=0x0C, address=ENDING_X_SLIDE_RIGHT_ACCEL
	mov [0x09], 0x0010

DELAY_LOOP_VAR09_AT_07E0:
	break
	djnz [0x09], DELAY_LOOP_VAR09_AT_07E0
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

LABEL_0819:
	break
	video offset=CINEMATIC_ENDING_ALIEN_LIFT_F0, x=[0x07], y=[0x08]
	djnz [0x09], LABEL_0819
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
LABEL_0867:
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
LABEL_08CB:
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
LABEL_092F:
	db 0x11

ENDING_X_SLIDE_RIGHT_ACCEL:
	mov [0x0A], 0x0003
	add [0x07], 0x0002
	break
	djnz [0x0A], ENDING_X_SLIDE_RIGHT_ACCEL
	mov [0x0A], 0x0005

LABEL_0941:
	add [0x07], 0x0003
	break
	djnz [0x0A], LABEL_0941
	jmp ENDING_X_SLIDE_RIGHT_ACCEL
	killChannel
	video offset=CINEMATIC_108, x=160, y=100
	video type=0, offset=CV_1C78, x=160, y=100, zoom=0x40
	video type=0, offset=CV_4346, x=160, y=100, zoom=0x40
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_08, x=160, y=100, zoom=0x40
	killChannel

ENDING_CLOUD_SKY_BACKDROP_PAGE_0:
	selectVideoPage 0x00
	fill page=0x00, color=0x01
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=253, y=34, zoom=0x0a
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=269, y=29, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=273, y=78, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=303, y=57, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=140, y=79, zoom=0x08
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=214, y=85, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=66, y=79, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=111, y=52, zoom=0x20
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=95, y=103, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=153, y=89, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=132, y=107, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=4, y=85, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=65, y=115, zoom=0x20
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=293, y=139
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=11, y=109, zoom=0x1c
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=11, y=146
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F1, x=31, y=187
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F2, x=301, y=14
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F1, x=294, y=188
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F3, x=2, y=167
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F2, x=92, y=30
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F2, x=128, y=11
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F2, x=166, y=10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F2, x=85, y=19
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F2, x=48, y=12
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F2, x=111, y=3
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F2, x=13, y=11, zoom=0x20
	selectVideoPage 0xFF
	ret


LABEL_09F7:
	db 0x11

ENDING_CLOUD_SKY_BACKDROP_PAGE_3:
	selectVideoPage 0x03
	fill page=0x03, color=0x01
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=253, y=34, zoom=0x0a
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=269, y=29, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=273, y=78, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=303, y=57, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=140, y=79, zoom=0x08
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=214, y=85, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=66, y=79, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=111, y=52, zoom=0x20
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=95, y=103, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=153, y=89, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=132, y=107, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=4, y=85, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=65, y=115, zoom=0x20
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=293, y=139
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=11, y=109, zoom=0x1c
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=11, y=146
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F1, x=31, y=187
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=301, y=14
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F1, x=294, y=188
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F3, x=2, y=167
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=92, y=30
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=128, y=11
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=166, y=10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=85, y=19
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=48, y=12
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=111, y=3
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=13, y=11, zoom=0x20
	selectVideoPage 0xFF
	ret


LABEL_0A8D:
	db 0x11

DRAW_STARS_CIN_38_39_40_5_6:
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=126, y=25
	video offset=CINEMATIC_038, x=133, y=102, zoom=0x20
	video offset=CINEMATIC_038, x=129, y=114, zoom=0x20
	video offset=CINEMATIC_038, x=114, y=126, zoom=0x20
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=91, y=8, zoom=0x20
	video offset=CINEMATIC_039, x=16, y=114
	video offset=CINEMATIC_039, x=74, y=177, zoom=0x20
	video offset=CINEMATIC_040, x=78, y=166
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F1, x=283, y=175
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F1, x=294, y=183
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F1, x=58, y=185
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F1, x=5, y=170
	video offset=CINEMATIC_041, x=197, y=160, zoom=0x20
	video offset=CINEMATIC_041, x=61, y=169
	video offset=CINEMATIC_041, x=300, y=28
	video offset=CINEMATIC_041, x=202, y=86, zoom=0x30
	ret


BLITTER_LOOP_COPY_PAGE_00:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
	jmp BLITTER_LOOP_COPY_PAGE_00

JUNK__0AEB:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	break
	jmp JUNK__0AEB

BLITTER_LOOP_COPY_PAGE_80:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x00
	copyVideoPage src=0x80, dst=0xFF
	break
	jmp BLITTER_LOOP_COPY_PAGE_80

SCROLL_Y_BLIT_DISPATCHER:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	jg [SCROLL_Y], 0xFF38, SCROLL_Y_UP_PAGE_80_THEN_83
	add [SCROLL_Y], 0x00C8
	jmp SCROLL_Y_DOWN_PAGE_83_THEN_80

SCROLL_Y_UP_PAGE_80_THEN_83:
	copyVideoPage src=0x80, dst=0xFF
	add [SCROLL_Y], 0x00C8
	copyVideoPage src=0x83, dst=0xFF
	sub [SCROLL_Y], 0x00C8
	break
	jmp SCROLL_Y_BLIT_DISPATCHER

SCROLL_Y_BLIT_DISPATCHER_VARIANT:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	jg [SCROLL_Y], 0xFF38, SCROLL_Y_DOWN_PAGE_83_THEN_80
	add [SCROLL_Y], 0x00C8
	jmp SCROLL_Y_UP_PAGE_80_THEN_83

SCROLL_Y_DOWN_PAGE_83_THEN_80:
	copyVideoPage src=0x83, dst=0xFF
	add [SCROLL_Y], 0x00C8
	copyVideoPage src=0x80, dst=0xFF
	sub [SCROLL_Y], 0x00C8
	break
	jmp SCROLL_Y_BLIT_DISPATCHER_VARIANT
