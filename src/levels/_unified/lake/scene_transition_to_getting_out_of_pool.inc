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

