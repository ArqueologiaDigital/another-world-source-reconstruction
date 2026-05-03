SLUG_ANIMATION:
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call CLEAR_PROXIMITY_FLAG_THEN_CHECK
;@elif BRANCH in ("chahi_amiga_1991", "dos_1992")
	call CHECK_HORIZONTAL_PROXIMITY
;@endif
	jne [0x07], 0x00, DISPATCH_ON_PROXIMITY_TO_SLUG_FLIP_OR_306C
	video type=1, offset=CINEMATIC_SLUG_0, x=[0x0c], y=[0x0d], zoom=0x40
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call CLEAR_PROXIMITY_FLAG_THEN_CHECK
;@elif BRANCH in ("chahi_amiga_1991", "dos_1992")
	call CHECK_HORIZONTAL_PROXIMITY
;@endif
	jne [0x07], 0x00, DISPATCH_ON_PROXIMITY_TO_SLUG_FLIP_OR_306C
	video type=1, offset=CINEMATIC_SLUG_1, x=[0x0c], y=[0x0d], zoom=0x40
	break

SLUG_F1_PROXIMITY_CHK:
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call CLEAR_PROXIMITY_FLAG_THEN_CHECK
;@elif BRANCH in ("chahi_amiga_1991", "dos_1992")
	call CHECK_HORIZONTAL_PROXIMITY
;@endif
	jne [0x07], 0x00, DISPATCH_ON_PROXIMITY_TO_SLUG_FLIP_OR_306C
	video type=1, offset=CINEMATIC_SLUG_2, x=[0x0c], y=[0x0d], zoom=0x40
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call CLEAR_PROXIMITY_FLAG_THEN_CHECK
;@elif BRANCH in ("chahi_amiga_1991", "dos_1992")
	call CHECK_HORIZONTAL_PROXIMITY
;@endif
	jne [0x07], 0x00, DISPATCH_ON_PROXIMITY_TO_SLUG_FLIP_OR_306C
	video type=1, offset=CINEMATIC_SLUG_3, x=[0x0c], y=[0x0d], zoom=0x40
	break

SLUG_F3_PROXIMITY_CHK:
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call CLEAR_PROXIMITY_FLAG_THEN_CHECK
;@elif BRANCH in ("chahi_amiga_1991", "dos_1992")
	call CHECK_HORIZONTAL_PROXIMITY
;@endif
	jne [0x07], 0x00, DISPATCH_ON_PROXIMITY_TO_SLUG_FLIP_OR_306C
	video type=1, offset=CINEMATIC_SLUG_4, x=[0x0c], y=[0x0d], zoom=0x40
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call CLEAR_PROXIMITY_FLAG_THEN_CHECK
;@elif BRANCH in ("chahi_amiga_1991", "dos_1992")
	call CHECK_HORIZONTAL_PROXIMITY
;@endif
	jne [0x07], 0x00, DISPATCH_ON_PROXIMITY_TO_SLUG_FLIP_OR_306C
	video type=1, offset=CINEMATIC_SLUG_5, x=[0x0c], y=[0x0d], zoom=0x40
	break

SLUG_F5_PROXIMITY_CHK:
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call CLEAR_PROXIMITY_FLAG_THEN_CHECK
;@elif BRANCH in ("chahi_amiga_1991", "dos_1992")
	call CHECK_HORIZONTAL_PROXIMITY
;@endif
	jne [0x07], 0x00, DISPATCH_ON_PROXIMITY_TO_SLUG_FLIP_OR_306C
	sub [0x0C], 0x0001
	video type=1, offset=CINEMATIC_SLUG_6, x=[0x0c], y=[0x0d], zoom=0x40
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call CLEAR_PROXIMITY_FLAG_THEN_CHECK
;@elif BRANCH in ("chahi_amiga_1991", "dos_1992")
	call CHECK_HORIZONTAL_PROXIMITY
;@endif
	jne [0x07], 0x00, DISPATCH_ON_PROXIMITY_TO_SLUG_FLIP_OR_306C
	sub [0x0C], 0x0001
	video type=1, offset=CINEMATIC_SLUG_7, x=[0x0c], y=[0x0d], zoom=0x40
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call CLEAR_PROXIMITY_FLAG_THEN_CHECK
;@elif BRANCH in ("chahi_amiga_1991", "dos_1992")
	call CHECK_HORIZONTAL_PROXIMITY
;@endif
	jne [0x07], 0x00, DISPATCH_ON_PROXIMITY_TO_SLUG_FLIP_OR_306C
	sub [0x0C], 0x0001
	video type=1, offset=CINEMATIC_SLUG_8, x=[0x0c], y=[0x0d], zoom=0x40
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call CLEAR_PROXIMITY_FLAG_THEN_CHECK
;@elif BRANCH in ("chahi_amiga_1991", "dos_1992")
	call CHECK_HORIZONTAL_PROXIMITY
;@endif
	jne [0x07], 0x00, DISPATCH_ON_PROXIMITY_TO_SLUG_FLIP_OR_306C
	sub [0x0C], 0x0003
	video type=1, offset=CINEMATIC_SLUG_9, x=[0x0c], y=[0x0d], zoom=0x40
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call CLEAR_PROXIMITY_FLAG_THEN_CHECK
;@elif BRANCH in ("chahi_amiga_1991", "dos_1992")
	call CHECK_HORIZONTAL_PROXIMITY
;@endif
	jne [0x07], 0x00, DISPATCH_ON_PROXIMITY_TO_SLUG_FLIP_OR_306C
	sub [0x0C], 0x0002
	video type=1, offset=CINEMATIC_SLUG_10, x=[0x0c], y=[0x0d], zoom=0x40
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call CLEAR_PROXIMITY_FLAG_THEN_CHECK
;@elif BRANCH in ("chahi_amiga_1991", "dos_1992")
	call CHECK_HORIZONTAL_PROXIMITY
;@endif
	jne [0x07], 0x00, DISPATCH_ON_PROXIMITY_TO_SLUG_FLIP_OR_306C
	sub [0x0C], 0x0001
	video type=1, offset=CINEMATIC_SLUG_11, x=[0x0c], y=[0x0d], zoom=0x40
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call CLEAR_PROXIMITY_FLAG_THEN_CHECK
;@elif BRANCH in ("chahi_amiga_1991", "dos_1992")
	call CHECK_HORIZONTAL_PROXIMITY
;@endif
	jne [0x07], 0x00, DISPATCH_ON_PROXIMITY_TO_SLUG_FLIP_OR_306C
	sub [0x0C], 0x0001
	video type=1, offset=CINEMATIC_SLUG_12, x=[0x0c], y=[0x0d], zoom=0x40
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call CLEAR_PROXIMITY_FLAG_THEN_CHECK
;@elif BRANCH in ("chahi_amiga_1991", "dos_1992")
	call CHECK_HORIZONTAL_PROXIMITY
;@endif
	jne [0x07], 0x00, DISPATCH_ON_PROXIMITY_TO_SLUG_FLIP_OR_306C
	sub [0x0C], 0x0001
	video type=1, offset=CINEMATIC_SLUG_13, x=[0x0c], y=[0x0d], zoom=0x40
	break
	add [0x0C], 0x0002
	jmp SLUG_ANIMATION
	killChannel

DRAW_BEAST_421_422_WITH_SOUND_35:
	video type=1, offset=CINEMATIC_BEAST_AI_F1, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_AI_F2, x=[0x0c], y=[0x0d], zoom=0x40
	play id=0x0035, freq=0x14, vol=0x3F, channel=0x00
	je [0x1B], 0x01, BEAST_CONT_FRAMES_423_426
	je [0x2B], 0x01, BEAST_CONT_FRAMES_423_426
	mov [0x2B], 0x0001
	setup channel=0x2D, address=TRIGGER_SCENE_RESUME

BEAST_CONT_FRAMES_423_426:
	break
	video type=1, offset=CINEMATIC_BEAST_AI_F3, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_AI_F4, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_AI_F5, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_AI_F6, x=[0x0c], y=[0x0d], zoom=0x40
	break
	add [0x0C], 0x000C
	jmp SLUG_WALK_PROX_LOOP
	killChannel

SLUG_FLIP_WALKS:
	video type=1, offset=CINEMATIC_SLUG_FLIP_WALKING_0, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_FLIP_WALKING_1, x=[0x0c], y=[0x0d], zoom=0x40
	play id=0x0035, freq=0x14, vol=0x3F, channel=0x00
	je [0x1B], 0x01, SLUG_FLIP_CONT_FRAMES_2_5
	je [0x2B], 0x01, SLUG_FLIP_CONT_FRAMES_2_5
	mov [0x2B], 0x0001
	setup channel=0x2D, address=TRIGGER_SCENE_RESUME

SLUG_FLIP_CONT_FRAMES_2_5:
	break
	video type=1, offset=CINEMATIC_SLUG_FLIP_WALKING_2, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_FLIP_WALKING_3, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_FLIP_WALKING_4, x=[0x0c], y=[0x0d], zoom=0x40
	break
	video type=1, offset=CINEMATIC_SLUG_FLIP_WALKING_5, x=[0x0c], y=[0x0d], zoom=0x40
	break
	sub [0x0C], 0x000C
	jmp SLUG_ANIMATION
	killChannel
	mov [0x0A], 0x0032
	mov [0x0B], 0x00B6

