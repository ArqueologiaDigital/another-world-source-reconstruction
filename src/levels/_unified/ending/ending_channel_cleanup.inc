DELETE_ALL_CHANS_AND_KILL:
	deleteChannels first=0x00, last=0x3F
	killChannel

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DELETE_ALL_CHANS_AND_KILL.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRELOAD_RESOURCES_8_TO_1:
	load id=0x0008
	load id=0x008A
	load id=0x0081
	load id=0x0082
	load id=0x0083
	load id=0x0080
	load id=0x0001
	load id=0x0057
	load id=0x005E
	load id=0x000E
	load id=0x000F
	load id=0x005F
	load id=0x000C
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_97_TO_100:
	video type=1, offset=CINEMATIC_097, x=160, y=100
	break
	video type=1, offset=CINEMATIC_098, x=160, y=100
	break
	video type=1, offset=CINEMATIC_099, x=160, y=100
	break
	video type=1, offset=CINEMATIC_100, x=160, y=100
	break
	video type=1, offset=CINEMATIC_099, x=160, y=100
	break
	video type=1, offset=CINEMATIC_098, x=160, y=100
	break
	jmp DRAW_CIN_97_TO_100
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
;@include "post_DRAW_CIN_97_TO_100.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_101_102_FADE_PAL_C:
	video type=1, offset=CINEMATIC_101, x=160, y=125
	setPalette 0x0C
	break
	video type=1, offset=CINEMATIC_101, x=160, y=118
	break
	video type=1, offset=CINEMATIC_102, x=160, y=112
	break
	video type=1, offset=CINEMATIC_103, x=160, y=107
	break
	video type=1, offset=CINEMATIC_104, x=160, y=105
	break
	video type=1, offset=CINEMATIC_104, x=160, y=109
	break
	video type=1, offset=CINEMATIC_104, x=160, y=110
	break
	video type=1, offset=CINEMATIC_103, x=160, y=115
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_103_LOOP__ENDING_CHANNEL_CLEANUP:
	break
	video type=1, offset=CINEMATIC_103, x=160, y=118
	jmp DRAW_CIN_103_LOOP__ENDING_CHANNEL_CLEANUP
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
;@include "post_DRAW_CIN_103_LOOP.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_58_ANIM_LOOP:
	video type=1, offset=CINEMATIC_058, x=160, y=100, zoom=[0x04]
	break
	jmp DRAW_CIN_58_ANIM_LOOP
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
;@include "post_DRAW_CIN_58_ANIM_LOOP.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_59_TO_64_VAR_POS:
	video type=1, offset=CINEMATIC_059, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_060, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_061, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_062, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_063, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_064, x=[0x01], y=[0x02], zoom=[0x03]
	break
	video type=1, offset=CINEMATIC_065, x=[0x01], y=[0x02], zoom=[0x03]
	break
	jmp DRAW_CIN_59_TO_64_VAR_POS
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_59_TO_64_VAR_POS.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_59_TO_64_VAR_POS.inc"
;@endif

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

