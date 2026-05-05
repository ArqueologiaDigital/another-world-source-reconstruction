STEP_DRAW_CIN555_LEFT4_RIGHT1:
	sub [0x01], 0x0004
	video offset=CINEMATIC_555, x=[0x01], y=[0x02]
	add [0x01], 0x0001
	break

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_STEP_DRAW_CIN555_LEFT4_RIGHT1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_STEP_DRAW_CIN555_LEFT4_RIGHT1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_STEP_DRAW_CIN555_LEFT4_RIGHT1.inc"
;@endif

DRAW_CIN555_STEP_RIGHT3:
	add [0x01], 0x0000
	video offset=CINEMATIC_555, x=[0x01], y=[0x02]
	add [0x01], 0x0003
	break

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN555_STEP_RIGHT3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CIN555_STEP_RIGHT3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN555_STEP_RIGHT3.inc"
;@endif

;@include "../_helpers/INLINE_BREAK_035.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_BREAK_035.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_BREAK_035.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_BREAK_035.inc"
;@endif

INLINE_BREAK_035:
	break

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_BREAK_036.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_BREAK_036.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_BREAK_036.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_187_TO_222_2F_AT_8E66E193:
	sub [0x01], 0x0004
	video offset=CINEMATIC_187, x=[0x01], y=[0x02]
	break
	add [0x01], 0x0001
	video offset=CINEMATIC_222, x=[0x01], y=[0x02]
	add [0x01], 0x0001
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_187_TO_222_2F_AT_8E66E193.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_187_TO_222_2F_AT_8E66E193.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_212_TO_213_2F_AT_6B0D0A47:
	add [0x01], 0x0004
	video offset=CINEMATIC_212, x=[0x01], y=[0x02]
	break
	sub [0x01], 0x0001
	video offset=CINEMATIC_213, x=[0x01], y=[0x02]
	sub [0x01], 0x0001
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_212_TO_213_2F_AT_6B0D0A47.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_212_TO_213_2F_AT_6B0D0A47.inc"
;@endif

INLINE_BREAK_035:
	break

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_BREAK_037.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_BREAK_037.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_BREAK_037.inc"
;@endif

INLINE_BREAK_035:
	break

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_BREAK_038.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_BREAK_038.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_BREAK_038.inc"
;@endif

