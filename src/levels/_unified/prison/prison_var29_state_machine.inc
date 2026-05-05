INLINE_SET_VAR29_TO_5:
	mov [0x29], 0x0005

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR29_TO_5.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR29_TO_5.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR29_TO_5.inc"
;@endif

;@include "../_helpers/INLINE_SET_VAR29_TO_6.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR29_TO_6.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR29_TO_6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR29_TO_6.inc"
;@endif

INLINE_SET_VARF1_TO_64:
	mov [0xF1], 0x0064

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
;@include "amiga_dos__post_INLINE_SET_VARF1_TO_64.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VARF1_TO_64.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_406_408_BLOCK:
	video type=1, offset=CINEMATIC_406, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_407, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_408, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_409, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_409, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_408, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_409, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_410, x=160, y=100
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_411, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_406_408_BLOCK.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_406_408_BLOCK.inc"
;@endif

INLINE_SET_VAR29_TO_28:
	mov [0x29], 0x0028

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR29_TO_28.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR29_TO_28.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR29_TO_28.inc"
;@endif

INLINE_SUB_VAR08_INIT_VAR29:
	sub [0x08], 0x0005
	mov [0x29], 0x000A

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_FOLD_BODY_89B_179104BB.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_FOLD_BODY_89B_179104BB.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_FOLD_BODY_89B_179104BB.inc"
;@endif

SET_VAR29_TO_000A:
	mov [0x29], 0x000A
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR29_TO_000A.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR29_TO_000A.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR29_TO_000A.inc"
;@endif

INIT_VARS_0E_29:
	mov [0x0E], 0x0000
	mov [0x29], 0xFFFF
	ret


DECREMENT_VAR29_BY_1:
	sub [0x29], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DECREMENT_VAR29_BY_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DECREMENT_VAR29_BY_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DECREMENT_VAR29_BY_1.inc"
;@endif

BIT_EXTRACT_FROM_VAR24_TO_VAR25:
	mov [0x25], [0x24]
	and [0x25], 0x00FF
	shr [0x24], 0x0008
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_FOLD_BODY_144B_C55279EA.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_FOLD_BODY_144B_C55279EA.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_FOLD_BODY_144B_C55279EA.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_569_TO_572_6F_AT_F8680E45:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_569, x=160, y=100
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_570, x=228, y=175
	break
	video type=1, offset=CINEMATIC_571, x=232, y=175
	video type=1, offset=CINEMATIC_572, x=160, y=100
	break
	video type=1, offset=CINEMATIC_573, x=245, y=175
	video type=1, offset=CINEMATIC_572, x=160, y=100
	killChannel
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_570_574_BLOCK:
	mov [0x57], 0x0002
	video type=1, offset=CINEMATIC_574, x=239, y=175
	video type=1, offset=CINEMATIC_572, x=160, y=100
	break
	video type=1, offset=CINEMATIC_570, x=230, y=175
	video type=1, offset=CINEMATIC_574, x=230, y=175
	video type=1, offset=CINEMATIC_572, x=160, y=100
	break
	video type=1, offset=CINEMATIC_570, x=228, y=175
	break
	video type=1, offset=CINEMATIC_575, x=227, y=175
	break
	video type=1, offset=CINEMATIC_575, x=226, y=175
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_575, x=226, y=175
	selectVideoPage 0xFF
	killChannel
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_576_578_BLOCK:
	video type=1, offset=CINEMATIC_576, x=215, y=131
	break
	video type=1, offset=CINEMATIC_577, x=227, y=141
	break
	mov [0x31], 0x0000
	video type=1, offset=CINEMATIC_578, x=231, y=158
	break
	video type=1, offset=CINEMATIC_579, x=239, y=175
	break
	video type=1, offset=CINEMATIC_578, x=243, y=174
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_274, x=245, y=175
	mov [0x31], 0x0000
	break
	video type=1, offset=CINEMATIC_580, x=247, y=175
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_274, x=249, y=175
	break
	video type=1, offset=CINEMATIC_274, x=250, y=175
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_274, x=251, y=175
	selectVideoPage 0xFF
	killChannel
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_576_578_BLOCK.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_576_578_BLOCK.inc"
;@endif

;@include "../_helpers/AND_VAR11_WITH_EFFF.inc"
;@include "../_helpers/INLINE_OR_VAR11_WITH_1000.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_FOLD_BODY_58B_A2D4469A.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_FOLD_BODY_58B_A2D4469A.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_FOLD_BODY_58B_A2D4469A.inc"
;@endif

