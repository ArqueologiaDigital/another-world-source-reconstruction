SNEAKY_TENTACLE_FROM_THE_POOL:
	call COMPUTE_RANDOM_BIT_MASKS
	mov [0x33], [0x3E]
	add [0x33], 0x000C

SNEAKY_TENTACLE_INIT_DELAY:
	break
	djnz [0x33], SNEAKY_TENTACLE_INIT_DELAY
	mov [0x32], [0x01]
	sub [0x32], 0x0014
	mov [0x33], 0x007C
	mov [0x34], 0x0004

SNEAKY_TENTACLE_GOING_UP:
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_0, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	sub [0x33], 0x0001
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_0, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	sub [0x33], 0x0001
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_1, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	sub [0x33], 0x0001
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_1, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	sub [0x33], 0x0001
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_2, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	sub [0x33], 0x0001
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_2, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	sub [0x33], 0x0001
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_3, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	sub [0x33], 0x0001
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_3, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	sub [0x33], 0x0001
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_4, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	sub [0x33], 0x0001
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_4, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	sub [0x33], 0x0001
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_5, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	sub [0x33], 0x0001
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_5, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	sub [0x33], 0x0001
	break
	djnz [0x34], SNEAKY_TENTACLE_GOING_UP
	mov [0x33], [0x32]
	add [0x33], 0x000A
	jg [0x33], [0x01], SNEAKY_TENTACLE_GIVES_UP_FOR_NOW
	add [0x33], 0x0010
	jl [0x33], [0x01], SNEAKY_TENTACLE_GIVES_UP_FOR_NOW
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_F0, x=[0x32], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_F1, x=[0x32], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_F2, x=[0x32], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_F3, x=[0x32], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_F4, x=[0x32], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_F5, x=[0x32], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_F6, x=[0x32], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_F7, x=[0x32], y=100, zoom=0x40
	add [0x32], 0x0012
	jg [0x32], [0x01], SNEAKY_TENTACLE_HIT_HERO
	add [0x32], 0x0004
	jl [0x32], [0x01], SNEAKY_TENTACLE_HIT_HERO
	deleteChannels first=0x14, last=0x16
	sub [0x32], 0x0012
	break
	setup channel=0x14, address=KILL_CHANNEL_ROUTINE
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_F8, x=[0x32], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_F9, x=[0x32], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_F10, x=[0x32], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_F11, x=[0x32], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_TENTACLE_RISE_F0, x=[0x32], y=100, zoom=0x40
	mov [PAUSE_SLICES], 0x0004
	break
	play id=0x004B, freq=0x0A, vol=0x3F, channel=0x01
	video type=1, offset=CINEMATIC_TENTACLE_RISE_F1, x=[0x32], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_TENTACLE_RISE_F2, x=[0x32], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_TENTACLE_RISE_F3, x=[0x32], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_TENTACLE_RISE_F4, x=[0x32], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_TENTACLE_RISE_F5, x=[0x32], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_TENTACLE_RISE_F6, x=[0x32], y=100, zoom=0x40
	break
	video type=1, offset=CINEMATIC_TENTACLE_RISE_F7, x=[0x32], y=100, zoom=0x40
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_F12, x=[0x32], y=100, zoom=0x40
	jmp INIT_VAR_03_TO_0x1E
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_F12, x=[0x32], y=100, zoom=0x40
	jmp INIT_VAR_03_TO_0x1E
;@elif BRANCH == "dos_1992"
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_F12, x=[0x32], y=100, zoom=0x40
	jmp INIT_VAR_03_TO_0x1E
;@endif
	killChannel

SNEAKY_TENTACLE_HIT_HERO:
	break
	sub [0x32], 0x0005
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_0, x=[0x32], y=100, zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	break
	add [0x32], 0x0002
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_2, x=[0x32], y=106, zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	jmp SNEAKY_TENTACLE_FROM_THE_POOL
	killChannel

SNEAKY_TENTACLE_GIVES_UP_FOR_NOW:
	mov [0x34], 0x0002
	mov [0x33], 0x004C

SNEAKY_TENTACLE_GOING_DOWN:
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_0, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	add [0x33], 0x0002
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_0, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	add [0x33], 0x0002
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_1, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	add [0x33], 0x0002
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_1, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	add [0x33], 0x0002
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_2, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	add [0x33], 0x0002
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_2, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	add [0x33], 0x0002
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_3, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	add [0x33], 0x0002
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_3, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	add [0x33], 0x0002
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_4, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	add [0x33], 0x0002
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_4, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	add [0x33], 0x0002
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_5, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	add [0x33], 0x0002
	break
	video type=1, offset=CINEMATIC_SNEAKY_TENTACLE_5, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_VIDEO_MASK_FOR_SNEAKY_TENTACLE_ANIMATION, x=[0x32], y=100, zoom=0x40
	add [0x33], 0x0002
	break
	djnz [0x34], SNEAKY_TENTACLE_GOING_DOWN
	jmp SNEAKY_TENTACLE_FROM_THE_POOL
	killChannel

