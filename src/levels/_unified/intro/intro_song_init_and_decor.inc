.if BRANCH == "chahi_amiga_1991"
CINEMATIC_131		EQU 0xB17E
CINEMATIC_IDENT_SCREEN_EDGE_RIGHT_LOWER		EQU 0xCF88
CINEMATIC_IDENT_SCREEN_EDGE_RIGHT_UPPER		EQU 0xCF98
CINEMATIC_IDENT_SCREEN_EDGE_LEFT_INNER		EQU 0xCF34
CINEMATIC_IDENT_SCREEN_EDGE_RIGHT		EQU 0xCF1C
CINEMATIC_IDENT_SCREEN_EDGE_LEFT_OUTER		EQU 0xCF04
CINEMATIC_IDENT_SCREEN_GRATICULE		EQU 0xCF5C
CINEMATIC_457		EQU 0x4C62
CINEMATIC_458		EQU 0x4BFA
CINEMATIC_459		EQU 0x4C2E
CINEMATIC_460		EQU 0x4C96
CINEMATIC_461		EQU 0x4CCA
CINEMATIC_462		EQU 0x4CFE
CINEMATIC_BIOMETRIC_SCANNER_RING_7		EQU 0x4D32
CINEMATIC_BIOMETRIC_SCANNER_RING_8		EQU 0x4D66
CINEMATIC_LIFT_DOORWAY_WALL		EQU 0x418C
.else
CINEMATIC_131		EQU 0xF578
CINEMATIC_132		EQU 0xF4E0
CINEMATIC_133		EQU 0xF53C
CINEMATIC_134		EQU 0x4B3C
CINEMATIC_135		EQU 0xAED0
CINEMATIC_136		EQU 0xAEDC
CINEMATIC_137		EQU 0xB0F0
CINEMATIC_457		EQU 0x4B54
CINEMATIC_458		EQU 0x4BD4
CINEMATIC_459		EQU 0x4B6C
CINEMATIC_460		EQU 0x4BA0
CINEMATIC_461		EQU 0x4C08
CINEMATIC_462		EQU 0x4C3C
CINEMATIC_463		EQU 0x4C70
CINEMATIC_464		EQU 0x4CA4
CINEMATIC_465		EQU 0x4CD8
.endif

INTRO_PAUSE_3_PLAY_SONG_INIT:
	mov [PAUSE_SLICES], 0x0003
	song id=0x0000, delay=0x3E1C, pos=0x00
	setup channel=0x03, address=BIOMETRIC_SCAN_LINE_SWEEP_DOWN_INIT
	setup channel=0x04, address=BIOMETRIC_SCAN_LINE_SWEEP_ACROSS_INIT
	setup channel=0x05, address=BIOMETRIC_SCAN_BEAM_SWEEP_UP_INIT
	setup channel=0x06, address=BIOMETRIC_SCANNER_RING_ORBIT_PASS
	setup channel=0x07, address=LAB_AUTH_DOT_PAIR_CROSSING_ENTRY
	setup channel=0x0A, address=SHOW_PAGE_0_LOOP_INTRO
	setup channel=0x10, address=SHOW_PAGE_FF_LOOP_INTRO
	setup channel=0x08, address=DRAW_SCIENTIST_THEN_DIVERGE_INIT
	setup channel=0x09, address=LAB_AUTH_CRT_SCAN_BRACKET_DRAW_LOOP
	mov [0x03], 0x0032

LAB_AUTH_CRT_SCAN_HOLD_THEN_INTERFERENCE:
	break
	djnz [0x03], LAB_AUTH_CRT_SCAN_HOLD_THEN_INTERFERENCE
	setup channel=0x09, address=KILL_CHANNEL_ROUTINE
	setup channel=0x11, address=LAB_AUTH_CRT_INTERFERENCE_BURST
.if BRANCH == "chahi_amiga_1991"
	mov [0x03], 0x000A
.else
	mov [0x03], 0x0009
.endif

LAB_AUTH_CRT_OVERLAY_STAMP_PHASE_1:
	break
	djnz [0x03], LAB_AUTH_CRT_OVERLAY_STAMP_PHASE_1
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
.endif
	selectVideoPage 0x00
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F5_AMIGA_EXTRA, x=228, y=44
	video offset=CINEMATIC_126, x=160, y=100
.else
	video offset=CINEMATIC_131, x=228, y=44
	video offset=CINEMATIC_132, x=160, y=100
.endif
	selectVideoPage 0xFF
	setup channel=0x11, address=LAB_AUTH_CRT_INTERFERENCE_BURST
.if BRANCH == "chahi_amiga_1991"
	mov [0x03], 0x000A
.else
	mov [0x03], 0x0009
.endif

LAB_AUTH_CRT_OVERLAY_STAMP_PHASE_2:
	break
	djnz [0x03], LAB_AUTH_CRT_OVERLAY_STAMP_PHASE_2
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
.endif
	selectVideoPage 0x00
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F5_AMIGA_EXTRA, x=228, y=44
	video offset=CINEMATIC_127, x=160, y=100
.else
	video offset=CINEMATIC_131, x=228, y=44
	video offset=CINEMATIC_133, x=160, y=100
.endif
	selectVideoPage 0xFF
	setup channel=0x11, address=LAB_AUTH_CRT_INTERFERENCE_BURST
	mov [0x03], 0x000A

DELAY_10F_BEFORE_KILL_CHANNELS:
	break
	djnz [0x03], DELAY_10F_BEFORE_KILL_CHANNELS
	setup channel=0x11, address=KILL_CHANNEL_ROUTINE
	setup channel=0x03, address=KILL_CHANNEL_ROUTINE
	setup channel=0x04, address=KILL_CHANNEL_ROUTINE
	setup channel=0x05, address=KILL_CHANNEL_ROUTINE
	setup channel=0x06, address=KILL_CHANNEL_ROUTINE
	setup channel=0x07, address=KILL_CHANNEL_ROUTINE
	setup channel=0x0A, address=KILL_CHANNEL_ROUTINE
	setup channel=0x10, address=KILL_CHANNEL_ROUTINE
	setup channel=0x02, address=INTRO_IDENT_SCREEN_INIT
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
.endif
	killChannel

BIOMETRIC_SCAN_LINE_SWEEP_DOWN_INIT:
	mov [0x01], 0xFFF6
	mov [0x02], 0x0017

BIOMETRIC_SCAN_LINE_SWEEP_DOWN_LOOP:
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_BIOMETRIC_SCANNER_BEAM_LINE, x=110, y=[0x01]
.else
	video offset=CINEMATIC_134, x=110, y=[0x01]
.endif
	add [0x01], 0x000A
	break
	djnz [0x02], BIOMETRIC_SCAN_LINE_SWEEP_DOWN_LOOP
	killChannel

BIOMETRIC_SCAN_LINE_SWEEP_ACROSS_INIT:
	mov [0x04], 0x0032
	mov [0x05], 0x0050

BIOMETRIC_SCAN_LINE_SWEEP_ACROSS_LOOP:
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_129, x=[0x04], y=100
.else
	video offset=CINEMATIC_135, x=[0x04], y=100
.endif
	add [0x04], 0x0002
	break
	djnz [0x05], BIOMETRIC_SCAN_LINE_SWEEP_ACROSS_LOOP
	killChannel

BIOMETRIC_SCAN_BEAM_SWEEP_UP_INIT:
	mov [0x06], 0x00DC
	mov [0x07], 0x0017

BIOMETRIC_SCAN_BEAM_SWEEP_UP_LOOP:
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_BIOMETRIC_SCAN_BEAM_RISING, x=110, y=[0x06]
.else
	video offset=CINEMATIC_136, x=110, y=[0x06]
.endif
	sub [0x06], 0x000A
	djnz [0x07], BIOMETRIC_SCAN_BEAM_SWEEP_UP_LOOP
	killChannel

LAB_AUTH_DOT_PAIR_CROSSING_ENTRY:
	break
	mov [0x08], 0x007F
	mov [0x09], 0x0006
	mov [0x0B], 0x008E

LAB_AUTH_DOT_PAIR_STEP_INIT:
	mov [0x0A], 0x0002

LAB_AUTH_DOT_PAIR_STEP_HOLD_LOOP:
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_131, x=280, y=[0x08]
	video offset=CINEMATIC_131, x=283, y=[0x0b]
.else
	video offset=CINEMATIC_137, x=280, y=[0x08]
	video offset=CINEMATIC_137, x=283, y=[0x0b]
.endif
	djnz [0x0A], LAB_AUTH_DOT_PAIR_STEP_HOLD_LOOP
	add [0x08], 0x0003
	sub [0x0B], 0x0003
	djnz [0x09], LAB_AUTH_DOT_PAIR_STEP_INIT
	jmp LAB_AUTH_DOT_PAIR_CROSSING_ENTRY
LABEL_19C5:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

BIOMETRIC_SCANNER_RING_ORBIT_PASS:
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_456, x=318, y=139
	video offset=CINEMATIC_456, x=298, y=139
.else
	video offset=CINEMATIC_457, x=318, y=139
	video offset=CINEMATIC_457, x=298, y=139
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_456, x=278, y=139
	video offset=CINEMATIC_456, x=258, y=139
.else
	video offset=CINEMATIC_457, x=278, y=139
	video offset=CINEMATIC_457, x=258, y=139
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_456, x=238, y=139
	video offset=CINEMATIC_456, x=218, y=139
.else
	video offset=CINEMATIC_457, x=238, y=139
	video offset=CINEMATIC_457, x=218, y=139
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_456, x=198, y=139
	video offset=CINEMATIC_456, x=178, y=139
.else
	video offset=CINEMATIC_457, x=198, y=139
	video offset=CINEMATIC_457, x=178, y=139
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_456, x=158, y=139
.else
	video offset=CINEMATIC_457, x=158, y=139
.endif
	break
	break
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_457, x=59, y=140
	video offset=CINEMATIC_458, x=39, y=140
.else
	video offset=CINEMATIC_458, x=59, y=140
	video offset=CINEMATIC_459, x=39, y=140
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_459, x=19, y=144
.else
	video offset=CINEMATIC_460, x=19, y=144
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_460, x=65532, y=152
.else
	video offset=CINEMATIC_461, x=65532, y=152
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_461, x=25, y=167
.else
	video offset=CINEMATIC_462, x=25, y=167
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_462, x=26, y=183
.else
	video offset=CINEMATIC_463, x=26, y=183
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_BIOMETRIC_SCANNER_RING_7, x=70, y=193
.else
	video offset=CINEMATIC_464, x=70, y=193
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_BIOMETRIC_SCANNER_RING_8, x=132, y=181
.else
	video offset=CINEMATIC_465, x=132, y=181
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_BIOMETRIC_SCANNER_RING_8, x=219, y=181
.else
	video offset=CINEMATIC_465, x=219, y=181
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_BIOMETRIC_SCANNER_RING_8, x=307, y=181
.else
	video offset=CINEMATIC_465, x=307, y=181
.endif
	killChannel

