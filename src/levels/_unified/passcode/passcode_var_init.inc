SET_VAR_E6_F_PAUSE_4:
	mov [0xE6], 0x000F
	mov [PAUSE_SLICES], 0x0004

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR_E6_F_PAUSE_4.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR_E6_F_PAUSE_4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR_E6_F_PAUSE_4.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
SET_PAL_0_AND_RESTART:
	setPalette 0x00	;@raw=0x0B,0x00,0xFF
	jmp PASSCODE_ENTRY
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_SET_PAL_0_AND_RESTART.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_PAL_0_AND_RESTART.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
CLEAR_LAST_KEYCHAR:
	mov [LAST_KEYCHAR], 0x0000
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_CLEAR_LAST_KEYCHAR.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_CLEAR_LAST_KEYCHAR.inc"
;@endif

INIT_VAR08_TO_150:
	mov [0x08], 0x0096

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VAR08_TO_150.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VAR08_TO_150.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VAR08_TO_150.inc"
;@endif

