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
.if BRANCH in ("cartridge_1992", "gba_2004")
	je [0xDB], 0x00, POST_LAKE_INTRO_FADE_AND_TEXT
	jmp POST_LAKE_INTRO_FADE_AND_TEXT
	mov [0x03], 0x0032

LAKE_INTRO_FADE_DELAY:
	break
	djnz [0x03], LAKE_INTRO_FADE_DELAY

POST_LAKE_INTRO_FADE_AND_TEXT:
.endif
.if BRANCH == "dos_1992"
	je [0xDB], 0x00, POST_LAKE_INTRO_FADE_AND_TEXT
	mov [0x03], 0x0032

; Same role as the cartridge/gba arm above, and the two arms are mutually
; exclusive, so sharing the name is not a duplicate in any single branch. It was
; previously called LAKE_END_TRANSITION_DELAY, which is the name of a DIFFERENT
; delay loop further down — the one after the title text. Both definitions landed
; in every dos build and only the assembler's positional resolution made the two
; `djnz` instructions pair with the right one (#0120).
LAKE_INTRO_FADE_DELAY:
	break
	djnz [0x03], LAKE_INTRO_FADE_DELAY

POST_LAKE_INTRO_FADE_AND_TEXT:
.endif
	freezeChannels first=0x00, last=0x3B
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	setup channel=0x00, address=DISPLAY_TEXT_01FA_AND_FADE_TO_PAL_2
.endif
	deleteChannels first=0x00, last=0x3B
	load id=0x3E83
	killChannel
.if BRANCH == "chahi_amiga_1991"
	setup channel=0x00, address=DISPLAY_TEXT_01FA_AND_FADE_TO_PAL_2
.endif

DISPLAY_TEXT_01FA_AND_FADE_TO_PAL_2:
	fill page=0x00, color=0x00
	selectVideoPage 0x00
	text id=0x01FA, x=6, y=70, color=0x0F
	selectVideoPage 0xFF
	break
	setPalette 0x02
	mov [PAUSE_SLICES], 0x0005
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	mov [0x03], 0x0050
.elif BRANCH == "chahi_amiga_1991"
	mov [0x03], 0x001E
.endif

LAKE_END_TRANSITION_DELAY:
	break
	djnz [0x03], LAKE_END_TRANSITION_DELAY
	load id=0x3E81
	killChannel

