;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_BEAST_SURPRISE_SCENARIO_BACKGROUND		EQU 0xA8CC
;@endif
;@if BRANCH == "chahi_amiga_1991"
CINEMATIC_BEAST_SURPRISE_SCENARIO_BACKGROUND		EQU 0xBCDC
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_LAKE_INTRO_ANIM_0		EQU 0xCC98
CINEMATIC_LAKE_INTRO_ANIM_1		EQU 0xCCB4
CINEMATIC_LAKE_INTRO_ANIM_2		EQU 0xCD00
CINEMATIC_LAKE_INTRO_BG		EQU 0xCDFC
CINEMATIC_LAKE_INTRO_DECOR		EQU 0xCE64
CINEMATIC_LAKE_INTRO_LESTER		EQU 0x017C
CINEMATIC_LAKE_SCENE2_BG		EQU 0xCE6C
CINEMATIC_LAKE_SCENE2_DECOR		EQU 0xCEB8
CINEMATIC_LAKE_SCENE3_DECOR		EQU 0xD6C6
;@endif
;@if BRANCH == "chahi_amiga_1991"
CINEMATIC_LAKE_INTRO_ANIM_0		EQU 0xE0A8
CINEMATIC_LAKE_INTRO_ANIM_1		EQU 0xE0C4
CINEMATIC_LAKE_INTRO_ANIM_2		EQU 0xE110
CINEMATIC_LAKE_INTRO_BG		EQU 0xE20C
CINEMATIC_LAKE_INTRO_DECOR		EQU 0xE274
CINEMATIC_LAKE_INTRO_LESTER		EQU 0x0188
CINEMATIC_LAKE_SCENE2_BG		EQU 0xE27C
CINEMATIC_LAKE_SCENE2_DECOR		EQU 0xE2C8
CINEMATIC_LAKE_SCENE3_DECOR		EQU 0xEAD6
;@endif

LAKE_INTRO_SETUP:
	unfreezeChannels first=0x00, last=0x09
	unfreezeChannels first=0x0B, last=0x3B
	copyVideoPage src=0x00, dst=0x03
	freezeChannels first=0x14, last=0x17
	setup channel=0x17, address=DECOR_AT_305_155_F14_F9_BG
	setup channel=0x14, address=ENTITY_DROP_THEN_F15_LOOP
	setup channel=0x15, address=KILL_CHANNEL_ROUTINE
	setup channel=0x16, address=KILL_CHANNEL_ROUTINE
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	mov [0x19], 0x003B
;@elif BRANCH == "chahi_amiga_1991"
	mov [0x19], 0x003C
;@endif

LAKE_INTRO_PRE_DELAY:
	break
	djnz [0x19], LAKE_INTRO_PRE_DELAY
;@if BRANCH in ("cartridge_1992", "gba_2004")
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
	break
;@endif
;@if BRANCH == "dos_1992"
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
	break
;@endif
	unfreezeChannels first=0x0B, last=0x3B
	mov [0x18], 0x006E
	fill page=0x00, color=0x0B
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_LAKE_INTRO_BG, x=160, y=100
	video type=1, offset=CINEMATIC_LAKE_INTRO_LESTER, x=[0x18], y=110, zoom=0x40
	video type=1, offset=CINEMATIC_LAKE_INTRO_DECOR, x=180, y=100
	selectVideoPage 0xFF
	mov [0x19], 0x0020
	break
	setPalette 0x0B
	video type=1, offset=CINEMATIC_LAKE_INTRO_ANIM_0, x=[0x18], y=110, zoom=0x40

LAKE_INTRO_ANIM_F0_LOOP:
	break
	video type=1, offset=CINEMATIC_LAKE_INTRO_ANIM_0, x=[0x18], y=110, zoom=0x40
	djnz [0x19], LAKE_INTRO_ANIM_F0_LOOP
	mov [0x19], 0x0010

LAKE_INTRO_ANIM_F1_LOOP:
	break
	video type=1, offset=CINEMATIC_LAKE_INTRO_ANIM_1, x=[0x18], y=110, zoom=0x40
	djnz [0x19], LAKE_INTRO_ANIM_F1_LOOP
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	mov [0x19], 0x000F
;@elif BRANCH == "chahi_amiga_1991"
	mov [0x19], 0x0010
;@endif

LAKE_INTRO_ANIM_F2_LOOP:
	break
	video type=1, offset=CINEMATIC_LAKE_INTRO_ANIM_2, x=[0x18], y=110, zoom=0x40
	djnz [0x19], LAKE_INTRO_ANIM_F2_LOOP
;@if BRANCH in ("cartridge_1992", "gba_2004")
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
	break
;@endif
;@if BRANCH == "dos_1992"
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
	break
;@endif
	selectVideoPage 0x00
	fill page=0x00, color=0x0B
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_SCENARIO_BACKGROUND, x=160, y=100
	setPalette 0x19
	video type=1, offset=CINEMATIC_LAKE_SCENE2_BG, x=160, y=100
	video type=1, offset=CINEMATIC_LAKE_SCENE2_DECOR, x=200, y=100
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	mov [0x19], 0x001F
;@elif BRANCH == "chahi_amiga_1991"
	mov [0x19], 0x0020
;@endif

LAKE_INTRO_PRE_TRANS_DELAY:
	break
	djnz [0x19], LAKE_INTRO_PRE_TRANS_DELAY
;@if BRANCH in ("cartridge_1992", "gba_2004")
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
	break
;@endif
;@if BRANCH == "dos_1992"
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
	break
;@endif
	copyVideoPage src=0x03, dst=0x00
	freezeChannels first=0x14, last=0x16
	setup channel=0x14, address=LESTER_AT_POOL_LOOP
	setup channel=0x15, address=LOOP_DRAW_DECOR_215_AT_327_164
	deleteChannels first=0x16, last=0x16
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_LAKE_SCENE3_DECOR, x=275, y=162, zoom=0x40
	selectVideoPage 0xFF
	break
	setPalette 0x06
	killChannel

