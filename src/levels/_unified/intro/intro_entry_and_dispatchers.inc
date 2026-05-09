ENTRY_POINT_OF_INTRO_LEVEL:
	call INIT_VIDEO_BUFFERS__INTRO_ENTRY_AND_DISPATCHERS
	mov [PAUSE_SLICES], 0x0001
	setup channel=0x3C, address=BLIT_AND_DISPATCH_HERO_ACTION
	mov [MUS_MARK], 0x0000
	break
	je [0xDB], 0x00, LOAD_RESOURCES_AND_PLAY_MUSIC
	load id=0x07D1
	song id=0x0BDE, delay=0x0000, pos=0x00
	jmp SETUP_CHANNELS_AFTER_LOAD

LOAD_RESOURCES_AND_PLAY_MUSIC:
	song id=0x0000, delay=0x0000, pos=0x00
	load id=0x0036
	load id=0x0008
	load id=0x000A
	load id=0x000E
	load id=0x000F
	load id=0x002C
	load id=0x0003
	load id=0x0002
	load id=0x0001
	load id=0x0007
	load id=0x0041
	load id=0x0004
	load id=0x0005
	load id=0x0006
	load id=0x0007
	load id=0x0008
	load id=0x0009
	load id=0x000A
	load id=0x000B
	load id=0x000D
	load id=0x0036
	load id=0x003C
	load id=0x000C
	load id=0x0033
	load id=0x003F
	load id=0x002F
	load id=0x0040
	song id=0x0007, delay=0x3D54, pos=0x00

SETUP_CHANNELS_AFTER_LOAD:
	setup channel=0x01, address=INTRO_SCENE_INIT_PARTICLES
;@if BRANCH == "gba_2004"
	song id=0x0FB9, delay=0x0000, pos=0x01
;@endif
	setup channel=0x02, address=INTRO_PLAY_BG_AUDIO_LOOP
	setup channel=0x03, address=DRAW_CINEMATIC_005_LOOP
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	killChannel

;@include "../_helpers/KILL_CHANNEL_ROUTINE.inc"

BLIT_AND_DISPATCH_HERO_ACTION:
	add [0xC7], 0x0001
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	jne [HERO_ACTION], 0x00, INTRO_RESET_PAGES_AND_PAL_0
	copyVideoPage src=0x40, dst=0xFF
	break
	jmp BLIT_AND_DISPATCH_HERO_ACTION

BLIT_AND_COPY_PAGE_FF_LOOP:
	add [0xC7], 0x0001
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
	add [0xC7], 0x0001
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
	jmp BLIT_AND_DISPATCH_HERO_ACTION

BLIT_AND_DISPATCH_VAR3:
	add [0xC7], 0x0001
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	jne [HERO_ACTION], 0x00, INTRO_RESET_PAGES_AND_PAL_0
	copyVideoPage src=0x00, dst=0xFF
	break
	jmp BLIT_AND_DISPATCH_VAR3

BLIT_DISPATCH_HERO_ACTION_ALT:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	jne [HERO_ACTION], 0x00, INTRO_RESET_PAGES_AND_PAL_0
	break
	jmp BLIT_DISPATCH_HERO_ACTION_ALT
BLIT_DISPATCH_VAR3_LOOP:
	add [0xC7], 0x0001
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	jne [HERO_ACTION], 0x00, INTRO_RESET_PAGES_AND_PAL_0
	fill page=0xFF, color=0x01
	break
	jmp BLIT_DISPATCH_VAR3_LOOP

INIT_VIDEO_BUFFERS__INTRO_ENTRY_AND_DISPATCHERS:
	fill page=0x01, color=0x00
	fill page=0x02, color=0x00
	selectVideoPage 0x01
	blitFramebuffer 0x01
	blitFramebuffer 0xFF
	blitFramebuffer 0x02
	ret

