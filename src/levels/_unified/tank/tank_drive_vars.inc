INCREMENT_VAR44_BY_37:
	add [0x44], 0x0037
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INCREMENT_VAR44_BY_37.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INCREMENT_VAR44_BY_37.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INCREMENT_VAR44_BY_37.inc"
;@endif

INIT_VARS_50_NEG40_51_32:
	mov [0x50], 0xFFD8
	mov [0x51], 0x0020

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_50_NEG40_51_32.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_50_NEG40_51_32.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_50_NEG40_51_32.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VAR1_NEG50_PLAY_8B_TWICE:
	mov [0x01], 0xFFCE
	mov [0x02], 0x0064
	mov [0x03], 0x0040
	mov [0x2B], 0x0023
	play id=0x008B, freq=0x22, vol=0x40, channel=0x01
	play id=0x008B, freq=0x14, vol=0x40, channel=0x00
	mov [PAUSE_SLICES], 0x0006
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VAR1_NEG50_PLAY_8B_TWICE.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VAR1_NEG50_PLAY_8B_TWICE.inc"
;@endif

;@include "../_helpers/SHARED_RET.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SHARED_RET.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SHARED_RET.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SHARED_RET.inc"
;@endif

