CHECK_IF_THE_BEAST_HAS_ALREADY_REACHED_LESTER:
	mov [0x11], [0x0E]
	sub [0x11], 0x0028
	jg [0x11], [0x01], THE_BEAST_IS_STILL_AT_A_DISTANCE

THE_BEAST_IS_CLOSE_ENOUGH:
	jne [0x2B], 0x00, THE_BEAST_IS_STILL_AT_A_DISTANCE
	setup channel=0x28, address=THE_BEAST_KILLS_LESTER
;@if BRANCH in ("cartridge_1992", "gba_2004")
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
;@endif
;@if BRANCH == "dos_1992"
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
;@endif
	unfreezeChannels first=0x00, last=0x27
	unfreezeChannels first=0x2A, last=0x3B
	unfreezeChannels first=0x3D, last=0x3F
	killChannel

THE_BEAST_IS_STILL_AT_A_DISTANCE:
	break
	jmp CHECK_IF_THE_BEAST_HAS_ALREADY_REACHED_LESTER
	killChannel

WAIT_UNTIL_BEAST_CLOSE:
	mov [0x11], [0x0E]
	add [0x11], 0x0028
	jg [0x11], [0x01], THE_BEAST_IS_CLOSE_ENOUGH
	break
	jmp WAIT_UNTIL_BEAST_CLOSE
	killChannel
;@if BRANCH in ("cartridge_1992", "gba_2004")

BEAST_AI_INIT_POS_HEINEMAN:
	mov [0x0E], 0x0000
	mov [0x0F], 0x00B6
	mov [0x10], 0x0001
	jmp BEAST_APPROACH_PHASE_1
;@endif
;@if BRANCH == "dos_1992"

BEAST_AI_INIT_POS_HEINEMAN:
	mov [0x0E], 0x0000
	mov [0x0F], 0x00B6
	mov [0x10], 0x0001
	jmp BEAST_APPROACH_PHASE_1
;@endif

BEAST_AI_SPAWN_FAR_LEFT:
	mov [0x0E], 0xFFC4
	mov [0x0F], 0x00B6
	mov [0x10], 0x0023

BEAST_APPROACH_PHASE_1:
	video type=1, offset=CINEMATIC_BEAST_APPROACH_FRAME_0, x=[0x0e], y=[0x0f], zoom=0x40
	break
	djnz [0x10], BEAST_APPROACH_PHASE_1
	add [0x0E], 0x000F
	video type=1, offset=CINEMATIC_BEAST_APPROACH_FRAME_1, x=[0x0e], y=[0x0f], zoom=0x40
	break

BEAST_APPROACH_PHASE_2:
	add [0x0E], 0x000F
	video type=1, offset=CINEMATIC_BEAST_APPROACH_FRAME_2, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x000F
	video type=1, offset=CINEMATIC_BEAST_APPROACH_FRAME_3, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x000D
	video type=1, offset=CINEMATIC_BEAST_APPROACH_FRAME_4, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x000D
	video type=1, offset=CINEMATIC_BEAST_APPROACH_FRAME_5, x=[0x0e], y=[0x0f], zoom=0x40
	break
	play id=0x003A, freq=0x0A, vol=0x18, channel=0x00
	add [0x0E], 0x000D
	video type=1, offset=CINEMATIC_BEAST_APPROACH_FRAME_6, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x000B
	video type=1, offset=CINEMATIC_BEAST_APPROACH_FRAME_7, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x000D
	video type=1, offset=CINEMATIC_BEAST_APPROACH_FRAME_8, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0006
	video type=1, offset=CINEMATIC_BEAST_APPROACH_FRAME_9, x=[0x0e], y=[0x0f], zoom=0x40
	call RANDOM_BEAST_AMBIENT_SOUND
	break
	add [0x0E], 0x000C
	video type=1, offset=CINEMATIC_BEAST_APPROACH_FRAME_10, x=[0x0e], y=[0x0f], zoom=0x40
	break
	add [0x0E], 0x0001
	jmp BEAST_APPROACH_PHASE_2
	killChannel

BEAST_AI_SPAWN_FAR_RIGHT:
	mov [0x0E], 0x01EC
	mov [0x0F], 0x00B6
	jmp DRAW_BEAST_DRIFT_LEFT_PREROLL_FRAME
	killChannel

