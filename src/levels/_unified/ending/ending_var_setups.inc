INIT_VARE_TO_12:
	mov [0x0E], 0x000C

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARE_TO_12.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRIFT_VAR_F_PLUS_1_LOOP:
	break
	add [0x0F], 0x0001
	djnz [0x0E], DRIFT_VAR_F_PLUS_1_LOOP
	mov [0x0E], 0x0009
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRIFT_VAR_F_PLUS_4_LOOP:
	break
	add [0x0F], 0x0004
	djnz [0x0E], DRIFT_VAR_F_PLUS_4_LOOP
	mov [0x0E], 0x0032
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DELAY_VARE_THEN_INIT_VARE_5:
	break
	djnz [0x0E], DELAY_VARE_THEN_INIT_VARE_5
	mov [0x0E], 0x0005
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRIFT_VAR_F_PLUS_8_LOOP:
	break
	add [0x0F], 0x0008
	djnz [0x0E], DRIFT_VAR_F_PLUS_8_LOOP
	setup channel=0x36, address=LABEL_022B
	break
	add [0x0F], 0x000C
	break
	add [0x0F], 0x0018
	break
	add [0x0F], 0x0026
	break
	add [0x0F], 0x0038
	killChannel
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_70_ANIM_LOOP:
	video type=1, offset=CINEMATIC_070, x=[0x01], y=[0x02], zoom=[0x0f]	;@raw=0x55,0x26,0xB5,0x01,0x02,0x0F
	break
	jmp DRAW_CIN_70_ANIM_LOOP
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_70_ANIM_LOOP.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_70_ANIM_LOOP.inc"
;@endif
