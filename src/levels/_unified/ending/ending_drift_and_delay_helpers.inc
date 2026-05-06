; ENDING tail: drift / delay helpers used by the credits sequence
; to step var-3 / var-4 across frames and gate channel transitions.
; All five labels carry the `__ENDING_CHANNEL_CLEANUP` suffix as a
; historical marker (the base names collide with labels in
; `cart__post_DELETE_ALL_CHANS_AND_KILL.inc`, so the suffix
; disambiguates).

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRIFT_VAR_4_PLUS_10_LOOP__ENDING_CHANNEL_CLEANUP:
	break
	add [0x04], 0x000A
	djnz [0x06], DRIFT_VAR_4_PLUS_10_LOOP__ENDING_CHANNEL_CLEANUP
	setup channel=0x0B, address=KILL_CHANNEL_LANDING
	mov [0x06], 0x0030
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRIFT_VAR_3_MINUS_1_LOOP__ENDING_CHANNEL_CLEANUP:
	break
	sub [0x03], 0x0001
	djnz [0x06], DRIFT_VAR_3_MINUS_1_LOOP__ENDING_CHANNEL_CLEANUP
	setup channel=0x10, address=INIT_VARE_TO_12
	setup channel=0x11, address=DRAW_CIN_70_ANIM_LOOP
	mov [0x0F], 0x0001
	mov [0x06], 0x000C
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRIFT_VAR_3_MINUS_1_TWO_BRKS__ENDING_CHANNEL_CLEANUP:
	break
	break
	sub [0x03], 0x0001
	djnz [0x06], DRIFT_VAR_3_MINUS_1_TWO_BRKS__ENDING_CHANNEL_CLEANUP
	mov [0x06], 0x0019
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DELAY_VAR6_THEN_VAR3_MINUS_1__ENDING_CHANNEL_CLEANUP:
	break
	djnz [0x06], DELAY_VAR6_THEN_VAR3_MINUS_1__ENDING_CHANNEL_CLEANUP
	sub [0x03], 0x0001
	mov [0x06], 0x0019
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DELAY_VAR6_THEN_KILL_CHAN__ENDING_CHANNEL_CLEANUP:
	break
	djnz [0x06], DELAY_VAR6_THEN_KILL_CHAN__ENDING_CHANNEL_CLEANUP
	sub [0x03], 0x0001
	killChannel
;@endif

