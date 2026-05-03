DECOR_F7_BLINK_3X_LOOP:
	mov [0x14], 0x0003

DECOR_F7_BLINK_3X_LOOP_BODY:
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F7, x=[0x32], y=[0x33], zoom=0x40
	break
	djnz [0x14], DECOR_F7_BLINK_3X_LOOP_BODY
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F7, x=[0x32], y=[0x33], zoom=0x40
	break
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F7, x=[0x32], y=[0x33], zoom=0x40
	break
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F7, x=[0x32], y=[0x33], zoom=0x40
	break
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F8, x=[0x32], y=[0x33], zoom=0x40
	break
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F8, x=[0x32], y=[0x33], zoom=0x40
	break
	mov [0x14], 0x0006

DECOR_F8_HOLD_LOOP:
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F8, x=[0x32], y=[0x33], zoom=0x40
	break
	djnz [0x14], DECOR_F8_HOLD_LOOP
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F8, x=[0x32], y=[0x33], zoom=0x40
	break
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F8, x=[0x32], y=[0x33], zoom=0x40
	break
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F8, x=[0x32], y=[0x33], zoom=0x40
	break
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F7, x=[0x32], y=[0x33], zoom=0x40
	break
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F7, x=[0x32], y=[0x33], zoom=0x40
	break
	mov [0x14], 0x0006
	jmp DECOR_F7_BLINK_3X_LOOP_BODY
	killChannel

DECOR_F9_THEN_F10_LOOP:
	mov [0x14], 0x0002

DECOR_F9_THEN_F10_F9_BODY:
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F9, x=[0x32], y=[0x33], zoom=0x40
	break
	djnz [0x14], DECOR_F9_THEN_F10_F9_BODY
	mov [0x14], 0x0003

DECOR_F9_THEN_F10_F10_BODY:
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F10, x=[0x32], y=[0x33], zoom=0x40
	break
	djnz [0x14], DECOR_F9_THEN_F10_F10_BODY
	mov [0x14], 0x0003

DECOR_F11_HOLD_LOOP:
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F11, x=[0x32], y=[0x33], zoom=0x40
	break
	djnz [0x14], DECOR_F11_HOLD_LOOP
	mov [0x14], 0x0003

DECOR_F10_REPEAT_LOOP:
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F10, x=[0x32], y=[0x33], zoom=0x40
	break
	djnz [0x14], DECOR_F10_REPEAT_LOOP
	mov [0x14], 0x0002

DECOR_F9_REPEAT_LOOP:
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F9, x=[0x32], y=[0x33], zoom=0x40
	break
	djnz [0x14], DECOR_F9_REPEAT_LOOP
	mov [0x14], 0x0003

DECOR_F12_HOLD_LOOP:
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F12, x=[0x32], y=[0x33], zoom=0x40
	break
	djnz [0x14], DECOR_F12_HOLD_LOOP
	mov [0x14], 0x0003

DECOR_F13_HOLD_LOOP:
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F13, x=[0x32], y=[0x33], zoom=0x40
	break
	djnz [0x14], DECOR_F13_HOLD_LOOP
	mov [0x14], 0x0003

DECOR_F12_REPEAT_LOOP:
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F12, x=[0x32], y=[0x33], zoom=0x40
	break
	djnz [0x14], DECOR_F12_REPEAT_LOOP
	mov [0x14], 0x0002
	jmp DECOR_F9_THEN_F10_F9_BODY
	killChannel

DECOR_AT_305_155_F14_F9_BG:
	copyVideoPage src=0x03, dst=0x00
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F14, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F9, x=[0x32], y=[0x33], zoom=0x40
	selectVideoPage 0xFF
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F14, x=[0x32], y=[0x33], zoom=0x40
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F9, x=[0x32], y=[0x33], zoom=0x40
	break
	setPalette 0x06
	killChannel

ENTITY_DROP_THEN_F15_LOOP:
	mov [PAUSE_SLICES], 0x0006
	mov [0x1A], 0x000A

ENTITY_DROP_LOOP_BODY:
	video type=1, offset=CINEMATIC_LAKE_ENTITY_DROP, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0x1A], ENTITY_DROP_LOOP_BODY
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F15, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F16, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0051, freq=0x0A, vol=0x30, channel=0x01
	break
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F17, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_DECOR_AT_305_155_F18, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0007
	sub [0x02], 0x000E
	video type=1, offset=CINEMATIC_RIGHT_CROUCHING_2, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_RIGHT_CROUCHING_2, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_RIGHT_CROUCHING_1, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_RIGHT_CROUCHING_1, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_RIGHT_CROUCHING_0, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_RIGHT_CROUCHING_0, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0051, freq=0x0A, vol=0x1C, channel=0x01
	mov [0x1A], 0x0014

LESTER_RAISES_A_HAND:
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_LESTER_FRAME_BUNDLE
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_LESTER_FRAME, x=[0x01], y=[0x02], zoom=0x40
;@endif
	djnz [0x1A], LESTER_RAISES_A_HAND
	break
	video type=1, offset=CINEMATIC_LESTER_RAISE_HAND_F0, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LESTER_RAISE_HAND_F1, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LESTER_RAISE_HAND_F2, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_LESTER_RAISE_HAND_F3, x=[0x01], y=[0x02], zoom=0x40

LESTER_AT_POOL_HOLD_LOOP:
	break
	video type=1, offset=CINEMATIC_LAKE_LESTER_AT_POOL, x=[0x01], y=[0x02], zoom=0x40
	mov [PAUSE_SLICES], 0x0004
	jmp LESTER_AT_POOL_HOLD_LOOP
	killChannel

