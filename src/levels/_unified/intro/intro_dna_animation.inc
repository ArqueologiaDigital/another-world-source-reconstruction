.if BRANCH == "chahi_amiga_1991"
CINEMATIC_LESTER_EXITING_CAR_F7		EQU 0xBE46
CINEMATIC_LESTER_EXITING_CAR_F8		EQU 0xBE68
CINEMATIC_LESTER_EXITING_CAR_F9		EQU 0xBEBA
CINEMATIC_LESTER_EXITING_CAR_F10		EQU 0xBF0C
CINEMATIC_LESTER_EXITING_CAR_F11		EQU 0xC03A
CINEMATIC_LESTER_EXITING_CAR_F12		EQU 0xC0DC
CINEMATIC_LESTER_EXITING_CAR_F13		EQU 0xC11A
CINEMATIC_LESTER_EXITING_CAR_F14		EQU 0xC1E4
CINEMATIC_LESTER_EXITING_CAR_F15		EQU 0xC2C4
CINEMATIC_STORM_LIGHTNING_FLASH_F0		EQU 0xABEC
CINEMATIC_STORM_LIGHTNING_FLASH_F1		EQU 0xAC20
CINEMATIC_STORM_LIGHTNING_FLASH_F2		EQU 0xAC54
CINEMATIC_STORM_LIGHTNING_FLASH_F3		EQU 0xAC88
CINEMATIC_CARPARK_NEAR_PILLAR		EQU 0x1742
CINEMATIC_166		EQU 0x3A70
CINEMATIC_PARTICLE_LAB_BG_F0		EQU 0x33A0
CINEMATIC_PARTICLE_LAB_BG_F1		EQU 0x3BF8
CINEMATIC_PARTICLE_LAB_BG_F2		EQU 0x3658
CINEMATIC_PARTICLE_LAB_BG_F3		EQU 0x3AC4
CINEMATIC_171		EQU 0x3830
CINEMATIC_LAB_AUTH_CRT_INTERFERENCE_F1		EQU 0xF4B8
CINEMATIC_LAB_AUTH_CRT_INTERFERENCE_F2		EQU 0xF500
CINEMATIC_LAB_AUTH_CRT_INTERFERENCE_F3		EQU 0xF530
CINEMATIC_456		EQU 0x4BE2
CINEMATIC_DNA_0		EQU 0xF866
CINEMATIC_DNA_1		EQU 0xF878
CINEMATIC_DNA_10		EQU 0xF922
CINEMATIC_DNA_11		EQU 0xF936
CINEMATIC_DNA_12		EQU 0xF94A
CINEMATIC_DNA_13		EQU 0xF95E
CINEMATIC_DNA_14		EQU 0xF970
CINEMATIC_DNA_15		EQU 0xF982
CINEMATIC_DNA_16		EQU 0xF994
CINEMATIC_DNA_2		EQU 0xF88A
CINEMATIC_DNA_3		EQU 0xF89E
CINEMATIC_DNA_4		EQU 0xF8B0
CINEMATIC_DNA_5		EQU 0xF8C2
CINEMATIC_DNA_6		EQU 0xF8D6
CINEMATIC_DNA_7		EQU 0xF8EA
CINEMATIC_DNA_8		EQU 0xF8FE
CINEMATIC_DNA_9		EQU 0xF90E
.else
CINEMATIC_035		EQU 0xBC3C
CINEMATIC_036		EQU 0xBC7C
CINEMATIC_037		EQU 0xBCD0
CINEMATIC_038		EQU 0xBD24
CINEMATIC_039		EQU 0xBD68
CINEMATIC_040		EQU 0xBDB8
CINEMATIC_041		EQU 0xBDDA
CINEMATIC_042		EQU 0xBE2C
CINEMATIC_043		EQU 0xBE7E
CINEMATIC_044		EQU 0xBFAC
CINEMATIC_045		EQU 0xC04E
CINEMATIC_046		EQU 0xC08C
CINEMATIC_047		EQU 0xC156
CINEMATIC_048		EQU 0xC236
CINEMATIC_166		EQU 0xF5D8
CINEMATIC_167		EQU 0xF63E
CINEMATIC_168		EQU 0xF688
CINEMATIC_169		EQU 0xF2F6
CINEMATIC_170		EQU 0xF3B0
CINEMATIC_171		EQU 0xF3BC
CINEMATIC_453		EQU 0xF3E0
CINEMATIC_454		EQU 0xF42A
CINEMATIC_455		EQU 0xF472
CINEMATIC_456		EQU 0xF4A2
CINEMATIC_DNA_0		EQU 0xF7D8
CINEMATIC_DNA_1		EQU 0xF7EA
CINEMATIC_DNA_10		EQU 0xF894
CINEMATIC_DNA_11		EQU 0xF8A8
CINEMATIC_DNA_12		EQU 0xF8BC
CINEMATIC_DNA_13		EQU 0xF8D0
CINEMATIC_DNA_14		EQU 0xF8E2
CINEMATIC_DNA_15		EQU 0xF8F4
CINEMATIC_DNA_16		EQU 0xF906
CINEMATIC_DNA_2		EQU 0xF7FC
CINEMATIC_DNA_3		EQU 0xF810
CINEMATIC_DNA_4		EQU 0xF822
CINEMATIC_DNA_5		EQU 0xF834
CINEMATIC_DNA_6		EQU 0xF848
CINEMATIC_DNA_7		EQU 0xF85C
CINEMATIC_DNA_8		EQU 0xF870
CINEMATIC_DNA_9		EQU 0xF880
.endif

SETUP_INTRO_DNA_CHANNELS:
	setup channel=0x0A, address=DRAW_DNA_RUNG_ROTATION_LOOP
	setup channel=0x0B, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x0C, address=DNA_HELIX_ADVANCE_DRAW_Y_LOOP
	setup channel=0x0D, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x0E, address=DNA_HELIX_ADVANCE_DRAW_Y_LOOP
	setup channel=0x0F, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x10, address=DNA_HELIX_ADVANCE_DRAW_Y_LOOP
	setup channel=0x11, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x12, address=DNA_HELIX_ADVANCE_DRAW_Y_LOOP
	setup channel=0x13, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x14, address=DNA_HELIX_ADVANCE_DRAW_Y_LOOP
	setup channel=0x15, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x16, address=DNA_HELIX_ADVANCE_DRAW_Y_LOOP
	setup channel=0x17, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x18, address=DNA_HELIX_ADVANCE_DRAW_Y_LOOP
	setup channel=0x19, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x1A, address=DNA_HELIX_ADVANCE_DRAW_Y_LOOP
	setup channel=0x1B, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x1C, address=DNA_HELIX_ADVANCE_DRAW_Y_LOOP
	setup channel=0x1D, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x1E, address=DNA_HELIX_ADVANCE_DRAW_Y_LOOP
	setup channel=0x1F, address=DRAW_DNA_ANIMATION_LOOP
	killChannel

DELETE_CHANNELS_0A_TO_1F:
	deleteChannels first=0x0A, last=0x1F
	killChannel

DRAW_DNA_RUNG_ROTATION_LOOP:
	mov [0x05], 0x002A
	break
	jmp DRAW_DNA_RUNG_ROTATION_LOOP
LABEL_02AF:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

DNA_HELIX_ADVANCE_DRAW_Y_LOOP:
	add [0x05], 0x000A
	break
	jmp DNA_HELIX_ADVANCE_DRAW_Y_LOOP
LABEL_02B8:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

DRAW_DNA_ANIMATION_LOOP:
	break
	video offset=CINEMATIC_DNA_0, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_1, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_2, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_3, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_4, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_5, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_6, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_7, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_8, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_9, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_10, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_11, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_12, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_13, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_14, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_15, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_16, x=[0x04], y=[0x05], zoom=[0x06]
	jmp DRAW_DNA_ANIMATION_LOOP
LABEL_0333:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

DRAW_CINEMATICS_166_TO_171:
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LAB_AUTH_ID_SCREEN_INTERFERENCE_F0, x=160, y=100
.else
	video offset=CINEMATIC_166, x=160, y=100
.endif
	play id=0x002C, freq=0x0F, vol=0x3F, channel=0x02
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LAB_AUTH_ID_SCREEN_INTERFERENCE_F1, x=160, y=100
.else
	video offset=CINEMATIC_167, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LAB_AUTH_ID_SCREEN_INTERFERENCE_F2, x=160, y=100
.else
	video offset=CINEMATIC_168, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LAB_AUTH_ID_SCREEN_INTERFERENCE_F0, x=160, y=100
.else
	video offset=CINEMATIC_166, x=160, y=100
.endif
	killChannel

DRAW_SCIENTIST_THEN_DIVERGE_INIT:
	mov [0x10], 0x00E4
	mov [0x11], 0x00E4
	selectVideoPage 0x00
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LAB_AUTH_CRT_LESTER_FULL_BODY, x=157, y=100
.else
	video offset=CINEMATIC_169, x=157, y=100
.endif
	selectVideoPage 0xFF
	mov [0x0F], 0x001E

LAB_AUTH_CRT_SCAN_BRACKET_OPEN_DELAY:
	break
	djnz [0x0F], LAB_AUTH_CRT_SCAN_BRACKET_OPEN_DELAY
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_DISPATCH_VAR3
.endif
	mov [0x0F], 0x000A

LAB_AUTH_CRT_SCAN_BRACKET_SPREAD_LOOP:
	add [0x10], 0x0001
	break
	sub [0x11], 0x0001
	break
	djnz [0x0F], LAB_AUTH_CRT_SCAN_BRACKET_SPREAD_LOOP
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
.endif
	killChannel

LAB_AUTH_CRT_SCAN_BRACKET_DRAW_LOOP:
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LAB_AUTH_CRT_SCAN_BRACKET_RIGHT, x=[0x10], y=44
	video offset=CINEMATIC_LAB_AUTH_CRT_SCAN_BRACKET_LEFT, x=[0x11], y=44
.else
	video offset=CINEMATIC_170, x=[0x10], y=44
	video offset=CINEMATIC_171, x=[0x11], y=44
.endif
	break
	jmp LAB_AUTH_CRT_SCAN_BRACKET_DRAW_LOOP
LABEL_0390:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

LAB_AUTH_CRT_INTERFERENCE_BURST:
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LAB_AUTH_CRT_INTERFERENCE_F0, x=160, y=100
.else
	video offset=CINEMATIC_453, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LAB_AUTH_CRT_INTERFERENCE_F1, x=160, y=100
.else
	video offset=CINEMATIC_454, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LAB_AUTH_CRT_INTERFERENCE_F2, x=160, y=100
.else
	video offset=CINEMATIC_455, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LAB_AUTH_CRT_INTERFERENCE_F3, x=160, y=100
.else
	video offset=CINEMATIC_456, x=160, y=100
.endif
	killChannel

LESTER_EXITING_CAR_ANIMATION:
	setPalette 0x03
	mov [PAUSE_SLICES], 0x0003
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_EXITING_CAR_F2, x=160, y=100
.else
	video offset=CINEMATIC_035, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_EXITING_CAR_F3, x=160, y=100
.else
	video offset=CINEMATIC_036, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_EXITING_CAR_F4, x=160, y=100
.else
	video offset=CINEMATIC_037, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_EXITING_CAR_F5, x=160, y=100
.else
	video offset=CINEMATIC_038, x=160, y=100
.endif
	play id=0x003C, freq=0x16, vol=0x0F, channel=0x00
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_EXITING_CAR_F6, x=160, y=100
.else
	video offset=CINEMATIC_039, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_EXITING_CAR_F7, x=160, y=100
.else
	video offset=CINEMATIC_040, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_EXITING_CAR_F8, x=160, y=100
.else
	video offset=CINEMATIC_041, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_EXITING_CAR_F9, x=160, y=100
.else
	video offset=CINEMATIC_042, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_EXITING_CAR_F10, x=160, y=100
.else
	video offset=CINEMATIC_043, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_EXITING_CAR_F11, x=160, y=100
.else
	video offset=CINEMATIC_044, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_EXITING_CAR_F12, x=160, y=100
.else
	video offset=CINEMATIC_045, x=160, y=100
.endif
	break
	mov [PAUSE_SLICES], 0x0004
	setPalette 0x1B
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_EXITING_CAR_F13, x=160, y=100
.else
	video offset=CINEMATIC_046, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_EXITING_CAR_F14, x=160, y=100
.else
	video offset=CINEMATIC_047, x=160, y=100
.endif
	mov [0x01], 0x000F

LESTER_EXITING_CAR_LAST_FRAME_HOLD:
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_EXITING_CAR_F15, x=160, y=100
.else
	video offset=CINEMATIC_048, x=160, y=100
.endif
	djnz [0x01], LESTER_EXITING_CAR_LAST_FRAME_HOLD
	setup channel=0x01, address=DRAW_CARPARK_ENTRANCE_COMPOSITE
	setup channel=0x02, address=INTRO_PLAY_FX_AND_PALETTE_4_LOOP
	setup channel=0x03, address=DRAW_CINEMATIC_053_LOOP
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
.endif
	killChannel

