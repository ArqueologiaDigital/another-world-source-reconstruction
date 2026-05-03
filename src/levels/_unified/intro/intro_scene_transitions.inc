SCENE_TRANSITION_NEXT_PHASE:
	break
	mov [0x02], 0x0001
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP

WAIT_INTRO_SCENE_1:
	break
	djnz [0x02], WAIT_INTRO_SCENE_1
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_144, x=80, y=80
	video type=1, offset=CINEMATIC_145, x=160, y=100
	selectVideoPage 0xFF
	setup channel=0x09, address=DRAW_CINEMATICS_166_TO_171
	mov [0x02], 0x0009

WAIT_INTRO_SCENE_2:
	break
	djnz [0x02], WAIT_INTRO_SCENE_2
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_144, x=82, y=82
	video type=1, offset=CINEMATIC_146, x=160, y=100
	selectVideoPage 0xFF
	setup channel=0x09, address=DRAW_CINEMATICS_166_TO_171
	mov [0x02], 0x0009

WAIT_INTRO_SCENE_3:
	break
	djnz [0x02], WAIT_INTRO_SCENE_3
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_144, x=82, y=82
	video type=1, offset=CINEMATIC_147, x=80, y=80, zoom=[0x20]	;@raw=0x6A,0x7A,0xC2,0x50,0x50,0x20
	selectVideoPage 0xFF
	setup channel=0x09, address=DRAW_CINEMATICS_166_TO_171
	mov [0x02], 0x0009

WAIT_INTRO_SCENE_4:
	break
	djnz [0x02], WAIT_INTRO_SCENE_4
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_144, x=82, y=82
	video type=1, offset=CINEMATIC_147, x=80, y=80
	selectVideoPage 0xFF
	setup channel=0x09, address=DRAW_CINEMATICS_166_TO_171
	setup channel=0x08, address=SETUP_INTRO_DNA_CHANNELS
	mov [PAUSE_SLICES], 0x0004
	mov [0x02], 0x0032

WAIT_INTRO_SCENE_5:
	break
	djnz [0x02], WAIT_INTRO_SCENE_5
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_144, x=82, y=82
	video type=1, offset=CINEMATIC_CARKEY, x=160, y=100
	selectVideoPage 0xFF
	setup channel=0x09, address=DRAW_CINEMATICS_166_TO_171
	killChannel

