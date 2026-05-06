; ENDING credits cinematic-draw loops. The credits sequence
; iterates through CIN_097..104 (the alien-natives celebration
; animation), then CIN_058 (the spaceship ascent), then
; CIN_059..065 (the freeze-frame credits roll). Each loop runs as
; its own channel.
;
; Several labels carry an `__ENDING_CHANNEL_CLEANUP` suffix as a
; historical marker — the base names (e.g. `DRAW_CIN_103_LOOP`)
; collide with labels in `cart__post_DELETE_ALL_CHANS_AND_KILL.inc`,
; so the suffix disambiguates. Suffix preserved verbatim during
; the split out of `ending_channel_cleanup.inc`.

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_97_TO_100:
	video offset=CINEMATIC_097, x=160, y=100
	break
	video offset=CINEMATIC_098, x=160, y=100
	break
	video offset=CINEMATIC_099, x=160, y=100
	break
	video offset=CINEMATIC_100, x=160, y=100
	break
	video offset=CINEMATIC_099, x=160, y=100
	break
	video offset=CINEMATIC_098, x=160, y=100
	break
	jmp DRAW_CIN_97_TO_100
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
;@include "post_DRAW_CIN_97_TO_100.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_101_102_FADE_PAL_C:
	video offset=CINEMATIC_101, x=160, y=125
	setPalette 0x0C
	break
	video offset=CINEMATIC_101, x=160, y=118
	break
	video offset=CINEMATIC_102, x=160, y=112
	break
	video offset=CINEMATIC_103, x=160, y=107
	break
	video offset=CINEMATIC_104, x=160, y=105
	break
	video offset=CINEMATIC_104, x=160, y=109
	break
	video offset=CINEMATIC_104, x=160, y=110
	break
	video offset=CINEMATIC_103, x=160, y=115
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_103_LOOP__ENDING_CHANNEL_CLEANUP:
	break
	video offset=CINEMATIC_103, x=160, y=118
	jmp DRAW_CIN_103_LOOP__ENDING_CHANNEL_CLEANUP
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
;@include "post_DRAW_CIN_103_LOOP.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_58_ANIM_LOOP:
	video offset=CINEMATIC_058, x=160, y=100, zoom=[0x04]
	break
	jmp DRAW_CIN_58_ANIM_LOOP
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
;@include "post_DRAW_CIN_58_ANIM_LOOP.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_59_TO_64_VAR_POS:
	video offset=CINEMATIC_059, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_060, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_061, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_062, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_063, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_064, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video offset=CINEMATIC_065, x=[0x01], y=[0x02], zoom=[0x03]
	break
	jmp DRAW_CIN_59_TO_64_VAR_POS
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_59_TO_64_VAR_POS.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_59_TO_64_VAR_POS.inc"
;@endif

