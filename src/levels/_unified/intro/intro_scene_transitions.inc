CINEMATIC_144		EQU 0xF6C6
CINEMATIC_145		EQU 0xF918
CINEMATIC_146		EQU 0xF968
CINEMATIC_147		EQU 0xF584
.if BRANCH == "chahi_amiga_1991"
CINEMATIC_CARKEY		EQU 0xF760
.else
CINEMATIC_CARKEY		EQU 0xF6D2
.endif

SCENE_TRANSITION_NEXT_PHASE:
	break
	mov [0x02], 0x0001
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
.endif

WAIT_INTRO_SCENE_1:
	break
	djnz [0x02], WAIT_INTRO_SCENE_1
	selectVideoPage 0x00
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LAB_AUTH_ID_SCREEN_BG, x=80, y=80
	video offset=CINEMATIC_LAB_AUTH_ID_SCREEN_SCAN_F0, x=160, y=100
.else
	video offset=CINEMATIC_144, x=80, y=80
	video offset=CINEMATIC_145, x=160, y=100
.endif
	selectVideoPage 0xFF
	setup channel=0x09, address=DRAW_CINEMATICS_166_TO_171
.if BRANCH == "chahi_amiga_1991"
	mov [0x02], 0x000A
.else
	mov [0x02], 0x0009
.endif

WAIT_INTRO_SCENE_2:
	break
	djnz [0x02], WAIT_INTRO_SCENE_2
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
.endif
	selectVideoPage 0x00
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LAB_AUTH_ID_SCREEN_BG, x=82, y=82
	video offset=CINEMATIC_LAB_AUTH_ID_SCREEN_SCAN_F1, x=160, y=100
.else
	video offset=CINEMATIC_144, x=82, y=82
	video offset=CINEMATIC_146, x=160, y=100
.endif
	selectVideoPage 0xFF
	setup channel=0x09, address=DRAW_CINEMATICS_166_TO_171
.if BRANCH == "chahi_amiga_1991"
	mov [0x02], 0x000A
.else
	mov [0x02], 0x0009
.endif

WAIT_INTRO_SCENE_3:
	break
	djnz [0x02], WAIT_INTRO_SCENE_3
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
.endif
	selectVideoPage 0x00
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LAB_AUTH_ID_SCREEN_BG, x=82, y=82
	video offset=CINEMATIC_LAB_AUTH_ID_SCREEN_SCAN_F2, x=80, y=80, zoom=0x20
.else
	video offset=CINEMATIC_144, x=82, y=82
	video offset=CINEMATIC_147, x=80, y=80, zoom=0x20
.endif
	selectVideoPage 0xFF
	setup channel=0x09, address=DRAW_CINEMATICS_166_TO_171
.if BRANCH == "chahi_amiga_1991"
	mov [0x02], 0x000A
.else
	mov [0x02], 0x0009
.endif

WAIT_INTRO_SCENE_4:
	break
	djnz [0x02], WAIT_INTRO_SCENE_4
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
.endif
	selectVideoPage 0x00
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LAB_AUTH_ID_SCREEN_BG, x=82, y=82
	video offset=CINEMATIC_LAB_AUTH_ID_SCREEN_SCAN_F2, x=80, y=80
.else
	video offset=CINEMATIC_144, x=82, y=82
	video offset=CINEMATIC_147, x=80, y=80
.endif
	selectVideoPage 0xFF
	setup channel=0x09, address=DRAW_CINEMATICS_166_TO_171
	setup channel=0x08, address=SETUP_INTRO_DNA_CHANNELS
.if BRANCH != "chahi_amiga_1991"
	mov [PAUSE_SLICES], 0x0004
.endif
	mov [0x02], 0x0032

WAIT_INTRO_SCENE_5:
	break
	djnz [0x02], WAIT_INTRO_SCENE_5
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
.endif
	break
	selectVideoPage 0x00
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LAB_AUTH_ID_SCREEN_BG, x=82, y=82
.else
	video offset=CINEMATIC_144, x=82, y=82
.endif
	video offset=CINEMATIC_CARKEY, x=160, y=100
	selectVideoPage 0xFF
	setup channel=0x09, address=DRAW_CINEMATICS_166_TO_171
	killChannel

