;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_LAKE_SCENE_DECOR_RIGHT		EQU 0xD68E
;@endif
;@if BRANCH == "chahi_amiga_1991"
CINEMATIC_LAKE_SCENE_DECOR_RIGHT		EQU 0xEA9E
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_DECOR_AT_305_155_F0		EQU 0xD6E4
CINEMATIC_DECOR_AT_327_164_F0		EQU 0xD6F0
CINEMATIC_DECOR_AT_327_164_F1		EQU 0xD6D2
;@endif
;@if BRANCH == "chahi_amiga_1991"
CINEMATIC_DECOR_AT_305_155_F0		EQU 0xEAF4
CINEMATIC_DECOR_AT_327_164_F0		EQU 0xEB00
CINEMATIC_DECOR_AT_327_164_F1		EQU 0xEAE2
;@endif

SCENE_TRANSITION_TO_GETTING_OUT_OF_POOL:
	deleteChannels first=0x0B, last=0x16
	mov [PAUSE_SLICES], 0x0004
	mov [0x46], 0x0168
	mov [0x47], 0x00A3
	mov [0x49], 0x01B8
	mov [0x4A], 0x00A4
	mov [0x32], 0x0154
	mov [0x33], 0x00A2
	setPalette 0x06
	setup channel=0x0B, address=MULTIPLEX_ANIM_RING3_SLOT_0
	setup channel=0x0C, address=DRAW_LAKE_051_SEQ_FROM_WORKING_POS
	setup channel=0x0D, address=DECOR_F7_BLINK_3X_LOOP
	setup channel=0x0E, address=MULTIPLEX_ANIM_RING3_SLOT_1
	setup channel=0x0F, address=DRAW_LAKE_051_SEQ_FROM_WORKING_POS
	setup channel=0x10, address=DECOR_F7_BLINK_3X_LOOP
	setup channel=0x11, address=MULTIPLEX_ANIM_RING3_SLOT_2
	setup channel=0x14, address=DRAW_LAKE_051_SEQ_FROM_WORKING_POS
	setup channel=0x15, address=DECOR_F9_THEN_F10_LOOP
	setup channel=0x16, address=LESTER_FALLING_PLAY_AND_ANIM
	setup channel=0x29, address=KILL_CHANNEL_ROUTINE
	deleteChannels first=0x0B, last=0x13
	mov [0x34], 0x0036

BEAST_PRE_KILL_WAIT:
	break
	sub [0x34], 0x0001
	je [0x34], 0x01, BEAST_KILLED_POST_DELAY
	jl [0x0E], 0xB4, BEAST_PRE_KILL_WAIT
	setup channel=0x28, address=KILL_CHANNEL_ROUTINE
	setup channel=0x29, address=THE_BEAST_IS_KILLED_BY_A_LASER_SHOT

BEAST_KILLED_POST_DELAY:
	break
	djnz [0x34], BEAST_KILLED_POST_DELAY
	jmp LAKE_INTRO_SETUP
	killChannel

LAKE_PALETTE_FADE_IN:
	break
	mov [PAUSE_SLICES], 0x0008
	setPalette 0x11
	break
	setPalette 0x12
	break
	setPalette 0x13
	break
	setPalette 0x14
	break
	setPalette 0x15
	break
	setPalette 0x16
	break
	setPalette 0x17
	break
	setPalette 0x18
	play id=0x003D, freq=0x14, vol=0x00, channel=0x00
	play id=0x003D, freq=0x14, vol=0x00, channel=0x01
	play id=0x003D, freq=0x14, vol=0x00, channel=0x02
	play id=0x003D, freq=0x14, vol=0x00, channel=0x03
;@if BRANCH in ("cartridge_1992", "gba_2004")
	je [0xDB], 0x00, POST_LAKE_INTRO_FADE_AND_TEXT
	jmp POST_LAKE_INTRO_FADE_AND_TEXT
	mov [0x03], 0x0032

WAIT_VAR_03_FRAMES_LOOP:
	break
	djnz [0x03], WAIT_VAR_03_FRAMES_LOOP

POST_LAKE_INTRO_FADE_AND_TEXT:
;@endif
;@if BRANCH == "dos_1992"
	je [0xDB], 0x00, POST_LAKE_INTRO_FADE_AND_TEXT
	mov [0x03], 0x0032

WAIT_VAR_03_FRAMES_LOOP:
	break
	djnz [0x03], WAIT_VAR_03_FRAMES_LOOP

POST_LAKE_INTRO_FADE_AND_TEXT:
;@endif
	freezeChannels first=0x00, last=0x3B
;@if BRANCH in ("cartridge_1992", "gba_2004")
	setup channel=0x00, address=DISPLAY_TEXT_01FA_AND_FADE_TO_PAL_2
;@endif
;@if BRANCH == "dos_1992"
	setup channel=0x00, address=DISPLAY_TEXT_01FA_AND_FADE_TO_PAL_2
;@endif
	deleteChannels first=0x00, last=0x3B
	load id=0x3E83
	killChannel
;@if BRANCH == "chahi_amiga_1991"
	setup channel=0x00, address=DISPLAY_TEXT_01FA_AND_FADE_TO_PAL_2
;@endif

DISPLAY_TEXT_01FA_AND_FADE_TO_PAL_2:
	fill page=0x00, color=0x00
	selectVideoPage 0x00
	text id=0x01FA, x=6, y=70, color=0x0F
	selectVideoPage 0xFF
	break
	setPalette 0x02
	mov [PAUSE_SLICES], 0x0005
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	mov [0x03], 0x0050
;@elif BRANCH == "chahi_amiga_1991"
	mov [0x03], 0x001E
;@endif

WAIT_VAR_03_FRAMES_LOOP:
	break
	djnz [0x03], WAIT_VAR_03_FRAMES_LOOP
	load id=0x3E81
	killChannel

LOOP_DRAW_DECOR_215_AT_327_164:
	video offset=CINEMATIC_LAKE_SCENE_DECOR_RIGHT, x=327, y=164
	break
	jmp LOOP_DRAW_DECOR_215_AT_327_164
	killChannel

DECOR_AT_327_164_BLINK_LOOP:
	video offset=CINEMATIC_DECOR_AT_327_164_F0, x=245, y=155
	play id=0x0052, freq=0x1E, vol=0x3F, channel=0x00
	break
	break
	video offset=CINEMATIC_DECOR_AT_327_164_F1, x=105, y=155
	break
	video offset=CINEMATIC_DECOR_AT_327_164_F1, x=65501, y=155
	break
	video offset=CINEMATIC_DECOR_AT_327_164_F1, x=65374, y=155
	killChannel

LOOP_DRAW_LAKE_037_AT_305_155:
	video offset=CINEMATIC_DECOR_AT_305_155_F0, x=305, y=155
	break
	jmp LOOP_DRAW_LAKE_037_AT_305_155
	killChannel

