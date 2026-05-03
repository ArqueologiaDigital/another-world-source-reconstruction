GOO_DRIPPING_FROM_SLUGS_CLAW_ANIMATION:
	video type=1, offset=CINEMATIC_GOO_DRIPPING_FROM_SLUGS_CLAW_0, x=[0x15], y=[0x16], zoom=0x40
	break
	play id=0x004A, freq=0x14, vol=0x3F, channel=0x01
	video type=1, offset=CINEMATIC_GOO_DRIPPING_FROM_SLUGS_CLAW_1, x=[0x15], y=[0x16], zoom=0x40
	play id=0x004A, freq=0x0F, vol=0x3F, channel=0x00
	break
	video type=1, offset=CINEMATIC_GOO_DRIPPING_FROM_SLUGS_CLAW_2, x=[0x15], y=[0x16], zoom=0x40
	break
	video type=1, offset=CINEMATIC_GOO_DRIPPING_FROM_SLUGS_CLAW_3, x=[0x15], y=[0x16], zoom=0x40
	break
	video type=1, offset=CINEMATIC_GOO_DRIPPING_FROM_SLUGS_CLAW_4, x=[0x15], y=[0x16], zoom=0x40
	break
	video type=1, offset=CINEMATIC_GOO_DRIPPING_FROM_SLUGS_CLAW_5, x=[0x15], y=[0x16], zoom=0x40
	break
	video type=1, offset=CINEMATIC_GOO_DRIPPING_FROM_SLUGS_CLAW_6, x=[0x15], y=[0x16], zoom=0x40
	break
	video type=1, offset=CINEMATIC_GOO_DRIPPING_FROM_SLUGS_CLAW_7, x=[0x15], y=[0x16], zoom=0x40
	break
	video type=1, offset=CINEMATIC_GOO_DRIPPING_FROM_SLUGS_CLAW_8, x=[0x15], y=[0x16], zoom=0x40
	break
	killChannel

CLEAR_FRAMEBUFFER_TO_COLOR_4_LOOP:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x04
	break
	jmp CLEAR_FRAMEBUFFER_TO_COLOR_4_LOOP
	killChannel

TRIGGER_SCENE_RESUME:
	je [0x2B], 0x00, SLUG_ATTACK_INTRO

SLUG_ATTACK_INTRO:
	mov [PAUSE_SLICES], 0x0003
	mov [0x1C], 0x0002
	unfreezeChannels first=0x00, last=0x2A
	unfreezeChannels first=0x2E, last=0x3A
	unfreezeChannels first=0x3D, last=0x3F
	mov [0x2B], 0x0001
	copyVideoPage src=0x00, dst=0x03
	mov [0x65], [0x66]
	setup channel=0x3C, address=CLEAR_FRAMEBUFFER_TO_COLOR_4_LOOP
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")
	song id=0x0BE0, delay=0x0000, pos=0x00
;@endif
	setup channel=0x3C, address=CLEAR_FRAMEBUFFER_TO_COLOR_4_LOOP
	fill page=0xFF, color=0x04
	mov [0x15], 0x00DC
	mov [0x16], 0x00C8
	mov [0x17], 0x0005
	setPalette 0x0F

SLUG_ATTACK_CLAW_DRIFT_FAST:
	video type=1, offset=CINEMATIC_SLUG_ATTACK__CLOSED_CLAW, x=[0x15], y=[0x16], zoom=0x40
	sub [0x16], 0x000F
	sub [0x15], 0x0003
	break
	djnz [0x17], SLUG_ATTACK_CLAW_DRIFT_FAST
	mov [0x17], 0x0005
	add [0x16], 0x000A

SLUG_ATTACK_CLAW_DRIFT_SLOW:
	video type=1, offset=CINEMATIC_SLUG_ATTACK__CLOSED_CLAW, x=[0x15], y=[0x16], zoom=0x40
	sub [0x16], 0x0005
	sub [0x15], 0x0003
	break
	djnz [0x17], SLUG_ATTACK_CLAW_DRIFT_SLOW
	setup channel=0x3B, address=GOO_DRIPPING_FROM_SLUGS_CLAW_ANIMATION
	video type=1, offset=CINEMATIC_SLUG_ATTACK__CLOSED_CLAW, x=[0x15], y=[0x16], zoom=0x40
	break
	mov [0x17], 0x000A

SLUG_ATTACK_OPEN_CLAW_LOOP:
	video type=1, offset=CINEMATIC_SLUG_ATTACK__OPEN_CLAW, x=[0x15], y=[0x16], zoom=0x40
	sub [0x16], 0x0002
	sub [0x15], 0x0001
	break
	djnz [0x17], SLUG_ATTACK_OPEN_CLAW_LOOP
	setPalette 0x0A
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
	selectVideoPage 0x00
	fill page=0x00, color=0x0B
	video type=1, offset=CINEMATIC_LESTER_ATTACK_SCENE_BACKGROUND, x=160, y=100
	selectVideoPage 0xFF
	mov [0x17], 0x0002

SLUG_ATTACK_FB_FILL_LOOP:
	fill page=0xFF, color=0x00
	break
	djnz [0x17], SLUG_ATTACK_FB_FILL_LOOP
	video type=1, offset=CINEMATIC_SLUG_ATTACKING_LEG_0, x=160, y=100
	break
	video type=1, offset=CINEMATIC_SLUG_ATTACKING_LEG_0, x=155, y=100
	play id=0x004F, freq=0x1A, vol=0x3F, channel=0x00
	break
	play id=0x004F, freq=0x14, vol=0x3F, channel=0x01
	video type=1, offset=CINEMATIC_SLUG_ATTACKING_LEG_1, x=160, y=100
	break
	video type=1, offset=CINEMATIC_SLUG_ATTACKING_LEG_1, x=155, y=100
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=1, offset=CINEMATIC_SLUG_ATTACKING_LEG_2, x=160, y=100, zoom=[0x82]	;@raw=0x6A,0x3E,0x25,0xA0,0x64,0x82
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_SLUG_ATTACKING_LEG_2, x=160, y=100, zoom=[0x82]	;@raw=0x6A,0x48,0x2D,0xA0,0x64,0x82
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=1, offset=CINEMATIC_SLUG_ATTACKING_LEG_3, x=160, y=100, zoom=[0x5a]	;@raw=0x6A,0x3E,0x39,0xA0,0x64,0x5A
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_SLUG_ATTACKING_LEG_3, x=160, y=100, zoom=[0x5a]	;@raw=0x6A,0x48,0x41,0xA0,0x64,0x5A
;@endif
	break
	video type=1, offset=CINEMATIC_SLUG_ATTACKING_LEG_4, x=160, y=100
	setup channel=0x2C, address=SLUG_ATTACK_LEG_LOOP
	mov [0x16], 0x0046
	mov [0x15], 0x00AA
	play id=0x004E, freq=0x1A, vol=0x3F, channel=0x00
	break
	video type=1, offset=CINEMATIC_SLUG_ATTACKING_LEG_5, x=[0x15], y=100, zoom=[0x16]
	mov [0x16], 0x0050
	play id=0x004E, freq=0x14, vol=0x3F, channel=0x01
	break
	video type=1, offset=CINEMATIC_SLUG_ATTACKING_LEG_6, x=[0x15], y=100, zoom=[0x16]
	mov [0x16], 0x005A
	break
	video type=1, offset=CINEMATIC_SLUG_ATTACKING_LEG_7, x=[0x15], y=100, zoom=[0x16]
	video type=1, offset=CINEMATIC_SLUG_ATTACKING_LEG_6, x=[0x15], y=160, zoom=[0x16]
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	mov [0x17], 0x0013
;@elif BRANCH == "chahi_amiga_1991"
	mov [0x17], 0x0014
;@endif

SLUG_ATTACK_LEG_DRAW_LOOP:
	break
	video type=1, offset=CINEMATIC_SLUG_ATTACKING_LEG_8, x=[0x15], y=100, zoom=[0x16]
;@if BRANCH in ("cartridge_1992", "gba_2004")
	je [0xDB], 0x00, SLUG_ATTACK_LEG_LOOP_NOOP_BR

SLUG_ATTACK_LEG_LOOP_NOOP_BR:
;@endif
;@if BRANCH == "dos_1992"
	je [0xDB], 0x00, SLUG_ATTACK_LEG_LOOP_NOOP_BR

SLUG_ATTACK_LEG_LOOP_NOOP_BR:
;@endif
	djnz [0x17], SLUG_ATTACK_LEG_DRAW_LOOP
;@if BRANCH in ("cartridge_1992", "gba_2004")
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
	break
	video type=1, offset=CINEMATIC_SLUG_ATTACKING_LEG_8, x=[0x15], y=100, zoom=[0x16]
	je [0xDB], 0x00, SLUG_ATTACK_LEG_FINAL_NOOP_BR

SLUG_ATTACK_LEG_FINAL_NOOP_BR:
;@endif
;@if BRANCH == "dos_1992"
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
	break
	video type=1, offset=CINEMATIC_SLUG_ATTACKING_LEG_8, x=[0x15], y=100, zoom=[0x16]
	je [0xDB], 0x00, SLUG_ATTACK_LEG_FINAL_NOOP_BR

SLUG_ATTACK_LEG_FINAL_NOOP_BR:
;@endif
	mov [PAUSE_SLICES], 0x0004
	setup channel=0x2C, address=KILL_CHANNEL_ROUTINE
	freezeChannels first=0x00, last=0x3F
	deleteChannels first=0x14, last=0x16
	setup channel=0x2B, address=LESTER_FRAME_LOOP
	copyVideoPage src=0x03, dst=0x00
	mov [0x1C], 0x0001
	break
	setPalette 0x05
	killChannel

SLUG_ATTACK_LEG_LOOP:
	video type=1, offset=CINEMATIC_SLUG_ATTACK__LESTERS_LEG, x=[0x15], y=100, zoom=[0x16]
	break
	jmp SLUG_ATTACK_LEG_LOOP
	killChannel
	killChannel
	killChannel
	killChannel

