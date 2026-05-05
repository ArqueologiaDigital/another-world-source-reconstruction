DELAY_LOOP_VAR09:
	break
	djnz [0x09], DELAY_LOOP_VAR09
	play id=0x0057, freq=0x0F, vol=0x20, channel=0x03
	video offset=CINEMATIC_021, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_022, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_023, x=[0x07], y=[0x08], zoom=0x40
	mov [0x09], 0x000A

LABEL_07BD:
	break
	video offset=CINEMATIC_024, x=[0x07], y=[0x08], zoom=0x40
	video offset=CINEMATIC_025, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x09], LABEL_07BD
	setup channel=0x11, address=DRAW_CIN_024_LOOP
	setup channel=0x12, address=DRAW_CV_192_195_196_SEQ
	setup channel=0x13, address=DRAW_CV_193_185_181_SEQ
	setup channel=0x0C, address=DRIFT_VAR07_PLUS_2_3X
	mov [0x09], 0x0010

DELAY_LOOP_VAR09_AT_07E0:
	break
	djnz [0x09], DELAY_LOOP_VAR09_AT_07E0
	setup channel=0x0C, address=KILL_CHANNEL_LANDING
	deleteChannels first=0x11, last=0x13
	break
	video offset=CINEMATIC_026, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_027, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_028, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_029, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_030, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_031, x=[0x07], y=[0x08], zoom=0x40
	setup channel=0x05, address=DRAW_CIN_106_107_FX_57
	mov [0x09], 0x000A

LABEL_0819:
	break
	video offset=CINEMATIC_032, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x09], LABEL_0819
	setup channel=0x1E, address=KILL_CHANNEL_LANDING
	break
	video offset=CINEMATIC_033, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_034, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_035, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_036, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_037, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_037, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0x00
	fill page=0x00, color=0x01
	call DRAW_STARS_CIN_38_39_40_5_6
	selectVideoPage 0xFF
	setup channel=0x05, address=KILL_CHANNEL_LANDING
	setup channel=0x0A, address=SET_VAR_E6_5_PAL_B
	killChannel

DRAW_CIN_024_LOOP:
	video offset=CINEMATIC_024, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp DRAW_CIN_024_LOOP
LABEL_0867:
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
LABEL_08CB:
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
LABEL_092F:
	db 0x11

DRIFT_VAR07_PLUS_2_3X:
	mov [0x0A], 0x0003
	add [0x07], 0x0002
	break
	djnz [0x0A], DRIFT_VAR07_PLUS_2_3X
	mov [0x0A], 0x0005

LABEL_0941:
	add [0x07], 0x0003
	break
	djnz [0x0A], LABEL_0941
	jmp DRIFT_VAR07_PLUS_2_3X
	killChannel
	video offset=CINEMATIC_108, x=160, y=100
	video type=0, offset=COMMON_VIDEO_301, x=160, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_291, x=160, y=100, zoom=0x40
	video type=0, offset=COMMON_VIDEO_202, x=160, y=100, zoom=0x40
	killChannel

DRAW_STARS_PAGE0_CIN_000:
	selectVideoPage 0x00
	fill page=0x00, color=0x01
	video offset=CINEMATIC_000, x=253, y=34, zoom=[0x0a]	;@enc=alt
	video offset=CINEMATIC_000, x=269, y=29, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_000, x=273, y=78, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_000, x=303, y=57, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_000, x=140, y=79, zoom=[0x08]	;@enc=alt
	video offset=CINEMATIC_000, x=214, y=85, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_000, x=66, y=79, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_000, x=111, y=52, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_000, x=95, y=103, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_000, x=153, y=89, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_000, x=132, y=107, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_000, x=4, y=85, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_000, x=65, y=115, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_000, x=293, y=139, zoom=0x40
	video offset=CINEMATIC_000, x=11, y=109, zoom=[0x1c]	;@enc=alt
	video offset=CINEMATIC_000, x=11, y=146
	video offset=CINEMATIC_001, x=31, y=187
	video offset=CINEMATIC_002, x=301, y=14, zoom=0x40
	video offset=CINEMATIC_001, x=294, y=188, zoom=0x40
	video offset=CINEMATIC_003, x=2, y=167
	video offset=CINEMATIC_002, x=92, y=30
	video offset=CINEMATIC_002, x=128, y=11
	video offset=CINEMATIC_002, x=166, y=10
	video offset=CINEMATIC_002, x=85, y=19
	video offset=CINEMATIC_002, x=48, y=12
	video offset=CINEMATIC_002, x=111, y=3
	video offset=CINEMATIC_002, x=13, y=11, zoom=[0x20]	;@enc=alt
	selectVideoPage 0xFF
	ret
LABEL_09F7:
	db 0x11

DRAW_STARS_PAGE3_CIN_004:
	selectVideoPage 0x03
	fill page=0x03, color=0x01
	video offset=CINEMATIC_004, x=253, y=34, zoom=[0x0a]	;@enc=alt
	video offset=CINEMATIC_004, x=269, y=29, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_004, x=273, y=78, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_004, x=303, y=57, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_004, x=140, y=79, zoom=[0x08]	;@enc=alt
	video offset=CINEMATIC_004, x=214, y=85, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_004, x=66, y=79, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_004, x=111, y=52, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_004, x=95, y=103, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_004, x=153, y=89, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_004, x=132, y=107, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_004, x=4, y=85, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_004, x=65, y=115, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_004, x=293, y=139, zoom=0x40
	video offset=CINEMATIC_004, x=11, y=109, zoom=[0x1c]	;@enc=alt
	video offset=CINEMATIC_004, x=11, y=146
	video offset=CINEMATIC_005, x=31, y=187
	video offset=CINEMATIC_006, x=301, y=14, zoom=0x40
	video offset=CINEMATIC_005, x=294, y=188, zoom=0x40
	video offset=CINEMATIC_007, x=2, y=167
	video offset=CINEMATIC_006, x=92, y=30
	video offset=CINEMATIC_006, x=128, y=11
	video offset=CINEMATIC_006, x=166, y=10
	video offset=CINEMATIC_006, x=85, y=19
	video offset=CINEMATIC_006, x=48, y=12
	video offset=CINEMATIC_006, x=111, y=3
	video offset=CINEMATIC_006, x=13, y=11, zoom=[0x20]	;@enc=alt
	selectVideoPage 0xFF
	ret
LABEL_0A8D:
	db 0x11

DRAW_STARS_CIN_38_39_40_5_6:
	video offset=CINEMATIC_006, x=126, y=25
	video offset=CINEMATIC_038, x=133, y=102, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_038, x=129, y=114, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_038, x=114, y=126, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_006, x=91, y=8, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_039, x=16, y=114
	video offset=CINEMATIC_039, x=74, y=177, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_040, x=78, y=166
	video offset=CINEMATIC_005, x=283, y=175, zoom=0x40
	video offset=CINEMATIC_005, x=294, y=183, zoom=0x40
	video offset=CINEMATIC_005, x=58, y=185
	video offset=CINEMATIC_005, x=5, y=170
	video offset=CINEMATIC_041, x=197, y=160, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_041, x=61, y=169
	video offset=CINEMATIC_041, x=300, y=28, zoom=0x40
	video offset=CINEMATIC_041, x=202, y=86, zoom=[0x30]	;@enc=alt
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
