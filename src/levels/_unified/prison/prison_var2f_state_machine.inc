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
	mov [BUDDY_X], 0x001F
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
	mov [0x29], [HERO_X]
	mov [0x2F], 0x0018
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_FOLD_BODY_99B_32B55F1E.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_FOLD_BODY_99B_32B55F1E.inc"
;@endif

;@include "../_helpers/SET_VAR2F_TO_000F.inc"
;@include "../_helpers/SET_VAR2F_TO_000F.inc"

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
	mov [BUDDY_X], [0x22]
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
	video offset=CINEMATIC_505, x=[0x21], y=[0x27]
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

