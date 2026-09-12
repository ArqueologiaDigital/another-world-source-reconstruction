.if BRANCH == "chahi_amiga_1991"
CINEMATIC_138		EQU 0xF754
.else
CINEMATIC_138		EQU 0xCEFA
.endif
.if BRANCH == "chahi_amiga_1991"
CINEMATIC_139		EQU 0xF9A6
.else
CINEMATIC_139		EQU 0xCF0A
.endif
.if BRANCH == "chahi_amiga_1991"
CINEMATIC_140		EQU 0xF9F6
.else
CINEMATIC_140		EQU 0xCEA6
.endif
.if BRANCH == "chahi_amiga_1991"
CINEMATIC_141		EQU 0xF612
.else
CINEMATIC_141		EQU 0xCE8E
.endif
CINEMATIC_142		EQU 0xCE76
CINEMATIC_143		EQU 0xCECE

INTRO_PAUSE_3_AND_DRAW_CIN_138:
	mov [PAUSE_SLICES], 0x0003
	fill page=0xFF, color=0x02
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_132, x=322, y=145
	video offset=CINEMATIC_133, x=322, y=59
	video offset=CINEMATIC_134, x=17, y=100
	video offset=CINEMATIC_135, x=322, y=100
	video offset=CINEMATIC_136, x=65534, y=99
	video offset=CINEMATIC_137, x=160, y=108
.else
	video offset=CINEMATIC_138, x=322, y=145
	video offset=CINEMATIC_139, x=322, y=59
	video offset=CINEMATIC_140, x=17, y=100
	video offset=CINEMATIC_141, x=322, y=100
	video offset=CINEMATIC_142, x=65534, y=99
	video offset=CINEMATIC_143, x=160, y=108
.endif
	text id=0x0192, x=22, y=16, color=0x05
	copyVideoPage src=0xFF, dst=0x00
	copyVideoPage src=0xFF, dst=0x03
	setPalette 0x0B
	mov [0x04], 0x00DC
	mov [0x06], 0x0040
	setup channel=0x06, address=SCENE_TRANSITION_NEXT_PHASE
	mov [0x01], 0x0032

WAIT_VAR_01_50_TICKS:
	break
	djnz [0x01], WAIT_VAR_01_50_TICKS
	mov [0x01], 0x0023
.if BRANCH != "chahi_amiga_1991"
	mov [PAUSE_SLICES], 0x0005
.endif

DISPLAY_TEXT_190_LOOP:
	break
	text id=0x0190, x=3, y=168, color=0x0B
	djnz [0x01], DISPLAY_TEXT_190_LOOP
.if BRANCH == "chahi_amiga_1991"
	mov [0x01], 0x0032
.else
	mov [0x01], 0x0031
	mov [PAUSE_SLICES], 0x0005
.endif

DISPLAY_TEXT_191_LOOP:
	break
	text id=0x0191, x=3, y=168, color=0x0B
	djnz [0x01], DISPLAY_TEXT_191_LOOP
	setup channel=0x08, address=DELETE_CHANNELS_0A_TO_1F
.if BRANCH != "chahi_amiga_1991"
	break
	text id=0x0191, x=3, y=168, color=0x0B
.endif
	setup channel=0x02, address=INTRO_TRANSITION_TO_LAKE_SCENE
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
.endif
	killChannel

