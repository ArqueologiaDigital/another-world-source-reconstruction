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

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VARF1_TO_64.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VARF1_TO_64.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VARF1_TO_64.inc"
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

SET_VAR2F_TO_001A:
	mov [0x2F], 0x001A
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR2F_TO_001A.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR2F_TO_001A.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR2F_TO_001A.inc"
;@endif

INIT_VARS_2F_29_3:
	mov [0x2F], 0x0003
	mov [0x29], 0x01A4
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_2F_29_3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_2F_29_3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_2F_29_3.inc"
;@endif

INIT_VARS_2F_29:
	mov [0x2F], 0x0019
	mov [0x29], 0x0154
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_2F_29.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_2F_29.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_2F_29.inc"
;@endif

INIT_VARS_2F_29_2:
	mov [0x2F], 0x0009
	mov [0x29], 0x0002
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_2F_29_2.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_2F_29_2.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_2F_29_2.inc"
;@endif

INIT_VARS_B2_2F_29:
	mov [0xB2], 0x0007
	mov [0x2F], 0x0009
	mov [0x29], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_B2_2F_29.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_B2_2F_29.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_B2_2F_29.inc"
;@endif

SET_VAR2F_TO_0009:
	mov [0x2F], 0x0009
	ret


SET_VAR2F_TO_001B:
	mov [0x2F], 0x001B
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR2F_TO_001B.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR2F_TO_001B.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR2F_TO_001B.inc"
;@endif

INIT_VAR29_FROM_VAR50_PLUS_A_VAR2F_10:
	mov [0x29], [0x50]
	add [0x29], 0x000A
	mov [0x2F], 0x0010
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VAR29_FROM_VAR50_PLUS_A_VAR2F_10.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VAR29_FROM_VAR50_PLUS_A_VAR2F_10.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VAR29_FROM_VAR50_PLUS_A_VAR2F_10.inc"
;@endif

INIT_VARS_29_2F:
	mov [0x29], 0x00A1
	mov [0x2F], 0x0018
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_29_2F.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_29_2F.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_29_2F.inc"
;@endif

INIT_VARS_07_2F:
	mov [0x07], 0x001F
	mov [0x2F], 0x0015
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_07_2F.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_07_2F.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_07_2F.inc"
;@endif

INIT_VARS_2F_29_1:
	mov [0x2F], 0x0003
	mov [0x29], 0x0168
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_2F_29_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_2F_29_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_2F_29_1.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
SET_VARS_29_2F:
	mov [0x29], [0x01]
	mov [0x2F], 0x0018
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_FOLD_BODY_99B_32B55F1E.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_FOLD_BODY_99B_32B55F1E.inc"
;@endif

;@include "../_helpers/SET_VAR2F_TO_000F.inc"
SET_VAR2F_TO_000F:
	mov [0x2F], 0x000F
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_PRISON_5B_023.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_PRISON_5B_023.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_PRISON_5B_023.inc"
;@endif

;@include "../_helpers/STEP_VAR29_DOWN10_SET_VAR2F_11.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_STEP_VAR29_DOWN10_SET_VAR2F_11.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_STEP_VAR29_DOWN10_SET_VAR2F_11.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_STEP_VAR29_DOWN10_SET_VAR2F_11.inc"
;@endif

;@include "../_helpers/COMPUTE_VAR26_AS_VAR21_MINUS_VAR22.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COMPUTE_VAR26_AS_VAR21_MINUS_VAR22.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COMPUTE_VAR26_AS_VAR21_MINUS_VAR22.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COMPUTE_VAR26_AS_VAR21_MINUS_VAR22.inc"
;@endif

;@include "../_helpers/INCREMENT_VAR21_BY_F.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INCREMENT_VAR21_BY_F.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INCREMENT_VAR21_BY_F.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INCREMENT_VAR21_BY_F.inc"
;@endif

;@include "../_helpers/INLINE_SUB_VAR22_BY_23.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SUB_VAR22_BY_23.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SUB_VAR22_BY_23.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SUB_VAR22_BY_23.inc"
;@endif

;@include "../_helpers/INLINE_OR_VAR2B_WITH_4000.inc"
COPY_VAR22_TO_VAR07:
	mov [0x07], [0x22]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_VAR22_TO_VAR07.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_VAR22_TO_VAR07.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_VAR22_TO_VAR07.inc"
;@endif

;@include "../_helpers/ADD_VAR2C_TO_VAR22.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_ADD_VAR2C_TO_VAR22.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_ADD_VAR2C_TO_VAR22.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_ADD_VAR2C_TO_VAR22.inc"
;@endif

;@include "../_helpers/COPY_VAR27_TO_VAR07.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_VAR27_TO_VAR07.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_VAR27_TO_VAR07.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_VAR27_TO_VAR07.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN505_AT_X21_Y27:
	video type=1, offset=CINEMATIC_505, x=[0x21], y=[0x27], zoom=0x40
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN505_AT_X21_Y27.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN505_AT_X21_Y27.inc"
;@endif

;@include "../_helpers/SET_VAR13_TO_FFFF.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR13_TO_FFFF.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR13_TO_FFFF.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR13_TO_FFFF.inc"
;@endif

