SET_VAR18_TO_0122:
	mov [0x18], 0x0122
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR18_TO_0122.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR18_TO_0122.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR18_TO_0122.inc"
;@endif

;@include "../_helpers/INLINE_SET_VAR63_TO_1.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR63_TO_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR63_TO_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR63_TO_1.inc"
;@endif

;@include "../_helpers/INLINE_SET_VAR63_TO_2.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR63_TO_2.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR63_TO_2.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR63_TO_2.inc"
;@endif

;@include "../_helpers/INLINE_SET_VAR63_TO_5.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR63_TO_5.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR63_TO_5.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR63_TO_5.inc"
;@endif

;@include "../_helpers/INLINE_SET_VAR63_TO_6.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR63_TO_6.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR63_TO_6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR63_TO_6.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/WALK_RIGHT_DRAW_CV142_MULTISTEP.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_WALK_RIGHT_DRAW_CV142_MULTISTEP.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_WALK_RIGHT_DRAW_CV142_MULTISTEP.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
STEP_LEFT4_DRAW_CV140_LEFT4:
	sub [0x01], 0x0004
	break
	video type=0, offset=COMMON_VIDEO_140, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x57,0x24,0x2E,0x01,0x02
	sub [0x01], 0x0004
	break
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_STEP_LEFT4_DRAW_CV140_LEFT4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_STEP_LEFT4_DRAW_CV140_LEFT4.inc"
;@endif

;@include "../_helpers/STEP_DRAW_CV352_LEFT4_RIGHT1.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_STEP_DRAW_CV352_LEFT4_RIGHT1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_STEP_DRAW_CV352_LEFT4_RIGHT1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_STEP_DRAW_CV352_LEFT4_RIGHT1.inc"
;@endif

;@include "../_helpers/DRAW_CV352_STEP_RIGHT3.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CV352_STEP_RIGHT3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV352_STEP_RIGHT3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV352_STEP_RIGHT3.inc"
;@endif

;@include "../_helpers/INLINE_BREAK_035.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_BREAK_041.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_BREAK_041.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_BREAK_041.inc"
;@endif

INLINE_BREAK_035:
	break

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_BREAK_042.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_BREAK_042.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_BREAK_042.inc"
;@endif

INLINE_BREAK_035:
	break

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_BREAK_043.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_BREAK_043.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_BREAK_043.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
STEP_DRAW_CV336_THEN_CV340:
	add [0x01], 0x0002
	video type=0, offset=COMMON_VIDEO_336, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x57,0x0B,0xD4,0x01,0x02
	break
	video type=0, offset=COMMON_VIDEO_340, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x57,0x0B,0xC2,0x01,0x02
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_STEP_DRAW_CV336_THEN_CV340.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_STEP_DRAW_CV336_THEN_CV340.inc"
;@endif

INLINE_BREAK_035:
	break

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_BREAK_044.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_BREAK_044.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_BREAK_044.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
STEP_DRAW_CV329_THEN_CV335:
	sub [0x01], 0x0002
	video type=0, offset=COMMON_VIDEO_329, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x57,0x0B,0x00,0x01,0x02
	break
	video type=0, offset=COMMON_VIDEO_335, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x57,0x30,0xD8,0x01,0x02
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_STEP_DRAW_CV329_THEN_CV335.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_STEP_DRAW_CV329_THEN_CV335.inc"
;@endif

