ENTRY_POINT_OF_LAKE_LEVEL:
	call INIT_VIDEO_BUFFERS
;@if BRANCH == "gba_2004"
	song id=0x0FA1, delay=0x0000, pos=0x03
;@endif
;@if BRANCH in ("cartridge_1992", "gba_2004")
	mov [0xE3], 0x0000
	je [0xDB], 0x00, EXTRA_RESOURCE_LOADS_BLOCK_2
	load id=0x07D2
	jmp INIT_AUDIO_AND_SCENE_AFTER_LOADS

EXTRA_RESOURCE_LOADS_BLOCK_2:
	load id=0x0030
	load id=0x0032
	load id=0x0039
	load id=0x003E
;@endif
;@if BRANCH == "dos_1992"
	load id=0x0030
	load id=0x0032
	load id=0x0039
	load id=0x003E
;@endif
	load id=0x0010
	load id=0x0008
	load id=0x0051
;@if BRANCH == "chahi_amiga_1991"
	load id=0x0030
;@endif
	load id=0x0031
	load id=0x0032
	load id=0x0035
	load id=0x0039
	load id=0x003A
	load id=0x003D
	load id=0x003E
	load id=0x004A
	load id=0x004B
	load id=0x004C
	load id=0x004D
	load id=0x004E
	load id=0x004F
	load id=0x003B
	load id=0x0050
	load id=0x003C
	load id=0x0052
	load id=0x0054
	load id=0x002D
	jmp INIT_AUDIO_AND_SCENE_AFTER_LOADS
	load id=0x0089
	load id=0x0002
	load id=0x0081
	load id=0x0003

INIT_AUDIO_AND_SCENE_AFTER_LOADS:
	play id=0x0030, freq=0x00, vol=0x00, channel=0x00
	play id=0x0030, freq=0x00, vol=0x00, channel=0x01
	play id=0x0030, freq=0x00, vol=0x00, channel=0x02
	play id=0x0030, freq=0x00, vol=0x00, channel=0x03
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	setup channel=0x3C, address=BLIT_FROM_PAGE_40_LOOP
;@elif BRANCH == "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
;@endif
	mov [0x0C], 0x0000
	mov [0x04], 0x0000
	mov [HERO_ACTION_POS_MASK], 0x0000
	mov [0x01], 0x0000
;@if BRANCH in ("cartridge_1992", "chahi_amiga_1991", "dos_1992")
	mov [PAUSE_SLICES], 0x0004
;@elif BRANCH == "gba_2004"
	mov [PAUSE_SLICES], 0x0007
;@endif
	break
	call VERIFY_INTEGRITY_OR_HALT
	setup channel=0x03, address=A_CALM_ALIEN_POOL_BEFORE_LESTERS_ARRIVAL
	killChannel

KILL_CHANNEL_ROUTINE:
	killChannel

VERIFY_INTEGRITY_OR_HALT:
;@if BRANCH == "gba_2004"
	ret
;@endif
	and [0xBC], 0x0010
;@if BRANCH in ("cartridge_1992", "gba_2004")
	mov [0xF8], [0xE4]
	and [0xF8], 0x003C
;@if BRANCH == "cartridge_1992"
	ret
;@endif
;@elif BRANCH == "chahi_amiga_1991"
	and [0xC6], 0x0080
;@elif BRANCH == "dos_1992"
	mov [0xF8], [0xE4]
	and [0xF8], 0x003C
;@endif
	je [0xBC], 0x00, SHUTDOWN_VM
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	jne [0xF2], 0x0FA0, SHUTDOWN_VM
;@elif BRANCH == "chahi_amiga_1991"
	je [0xC6], 0x00, SHUTDOWN_VM
	jne [0xF2], 0x1770, SHUTDOWN_VM
;@endif
	jne [HACK_VAR_DC], 0x21, SHUTDOWN_VM
	ret

SHUTDOWN_VM:
	deleteChannels first=0x00, last=0x3F
	setup channel=0x3C, address=KILL_CHANNEL_ROUTINE
	killChannel

LAKE_LEVEL_INIT:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	fill page=0xFF, color=0x00
	mov [PAUSE_SLICES], 0x0005
;@if BRANCH in ("cartridge_1992", "gba_2004")
	or [0xE3], 0x0001
;@endif
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
	call VERIFY_INTEGRITY_OR_HALT
;@if BRANCH in ("cartridge_1992", "gba_2004")
	setPalette 0x1D
;@endif
;@if BRANCH == "gba_2004"
	song id=0x0FA0, delay=0x0000, pos=0x00
;@endif

INTRO_WAIT_KEY_RELEASE:
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")
	text id=0x013D, x=5, y=80, color=0x0C
	text id=0x013C, x=5, y=180, color=0x0D
	text id=0x015E, x=26, y=180, color=0x0E
	call SET_HERO_ACTION_TO_1_IF_GROUNDED_AND_DB_SET
;@endif
;@if BRANCH == "dos_1992"
	call SET_HERO_ACTION_TO_1_IF_GROUNDED_AND_DB_SET
;@endif
	jne [HERO_ACTION], 0x00, INTRO_WAIT_KEY_RELEASE
;@if BRANCH == "chahi_amiga_1991"
	setPalette 0x1D
;@endif
;@if BRANCH == "dos_1992"
	setPalette 0x1D
;@endif

INTRO_WAIT_KEY_PRESS:
	text id=0x013D, x=5, y=80, color=0x0C
	text id=0x013C, x=5, y=180, color=0x0D
	text id=0x015E, x=26, y=180, color=0x0E
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call SET_HERO_ACTION_TO_1_IF_GROUNDED_AND_DB_SET
;@endif
;@if BRANCH == "dos_1992"
	call SET_HERO_ACTION_TO_1_IF_GROUNDED_AND_DB_SET
;@endif
	je [HERO_ACTION], 0x00, INTRO_WAIT_KEY_PRESS
	mov [0x00], 0x000A
	setup channel=0x00, address=ENTRY_POINT_OF_LAKE_LEVEL
	killChannel
;@if BRANCH in ("cartridge_1992", "gba_2004")

SET_HERO_ACTION_TO_1_IF_GROUNDED_AND_DB_SET:
	je [0xDB], 0x00, RET_TARGET_1A88
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, RET_TARGET_1A88
	mov [HERO_ACTION], 0x0001
	ret
;@endif
;@if BRANCH == "dos_1992"

SET_HERO_ACTION_TO_1_IF_GROUNDED_AND_DB_SET:
	je [0xDB], 0x00, RET_TARGET_1A88
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, RET_TARGET_1A88
	mov [HERO_ACTION], 0x0001
	ret
;@endif
	break
	break
	break
	break
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
	fill page=0x00, color=0x00
	deleteChannels first=0x00, last=0x3B
	load id=0x3E80
	killChannel

;@if BRANCH in ("cartridge_1992", "gba_2004")
BLIT_FROM_PAGE_40_LOOP:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x40, dst=0xFF
	break
	jmp BLIT_FROM_PAGE_40_LOOP

;@endif
;@if BRANCH == "dos_1992"
BLIT_FROM_PAGE_40_LOOP:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x40, dst=0xFF
	break
	jmp BLIT_FROM_PAGE_40_LOOP

;@endif
