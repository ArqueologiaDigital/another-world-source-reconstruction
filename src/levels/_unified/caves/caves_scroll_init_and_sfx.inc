INIT_VARS_2F_29_12:
	mov [0x2F], 0x0009
	mov [0x29], 0x0000
	mov [0x12], 0x4010
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_2F_29_12.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_2F_29_12.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_2F_29_12.inc"
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

;@include "../_helpers/SET_VARS_07_08.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_FOLD_BODY_94B_9F1D7AF8.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_FOLD_BODY_94B_9F1D7AF8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_FOLD_BODY_94B_9F1D7AF8.inc"
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

;@include "../_helpers/SET_VAR13_TO_FFFF.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR13_TO_FFFF.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR13_TO_FFFF.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR13_TO_FFFF.inc"
;@endif

PLAY_SFX_005C_CH00:
	play id=0x005C, freq=0x19, vol=0x40, channel=0x00
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PLAY_SFX_005C_CH00.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PLAY_SFX_005C_CH00.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PLAY_SFX_005C_CH00.inc"
;@endif

;@include "../_helpers/MASK_VAR11_NOSIGN_INCR_VAR21_BY_14.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14.inc"
;@endif

;@include "../_helpers/INLINE_ADD_VAR2C_BY_1.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_ADD_VAR2C_BY_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_ADD_VAR2C_BY_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_ADD_VAR2C_BY_1.inc"
;@endif

;@include "../_helpers/COPY_VAR40_TO_VAR27.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_VAR40_TO_VAR27.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_VAR40_TO_VAR27.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_VAR40_TO_VAR27.inc"
;@endif

;@include "../_helpers/COPY_VARAD_TO_VAR11.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_VARAD_TO_VAR11.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_VARAD_TO_VAR11.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_VARAD_TO_VAR11.inc"
;@endif

;@include "../_helpers/COPY_VAR11_TO_VARAD.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_VAR11_TO_VARAD.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_VAR11_TO_VARAD.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_VAR11_TO_VARAD.inc"
;@endif

;@include "../_helpers/DECREMENT_VAR22.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DECREMENT_VAR22.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DECREMENT_VAR22.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DECREMENT_VAR22.inc"
;@endif

;@include "../_helpers/COMPUTE_VAR22_AS_VAR40_MINUS_28.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COMPUTE_VAR22_AS_VAR40_MINUS_28.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COMPUTE_VAR22_AS_VAR40_MINUS_28.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COMPUTE_VAR22_AS_VAR40_MINUS_28.inc"
;@endif

;@include "../_helpers/DEDUP_CAVES_5B_003.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_003.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_003.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_003.inc"
;@endif

DEDUP_CAVES_5B_003__CAVES_INLINE_SETTERS_AND_INIT:
	mov [0x0F], 0x0000
	killChannel

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_004.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_004.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_004.inc"
;@endif

;@include "../_helpers/COMPUTE_VARF8_AS_VAR22_MINUS_VAR09.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COMPUTE_VARF8_AS_VAR22_MINUS_VAR09.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COMPUTE_VARF8_AS_VAR22_MINUS_VAR09.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COMPUTE_VARF8_AS_VAR22_MINUS_VAR09.inc"
;@endif

;@include "../_helpers/INLINE_COPY_VAR44_TO_VAR25.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_COPY_VAR44_TO_VAR25.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_COPY_VAR44_TO_VAR25.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_COPY_VAR44_TO_VAR25.inc"
;@endif

;@include "../_helpers/DEDUP_CAVES_6B_001.inc"
;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
;@include "amiga_dos__post_DEDUP_CAVES_6B_001.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_6B_001.inc"
;@endif

;@include "../_helpers/INIT_VAR2B_2C_FROM_VAR01_VAR29_10.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VAR2B_2C_FROM_VAR01_VAR29_10.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VAR2B_2C_FROM_VAR01_VAR29_10.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VAR2B_2C_FROM_VAR01_VAR29_10.inc"
;@endif

;@include "../_helpers/ADD_VAR11_TO_VAR34.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_ADD_VAR11_TO_VAR34.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_ADD_VAR11_TO_VAR34.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_ADD_VAR11_TO_VAR34.inc"
;@endif

;@include "../_helpers/COPY_VAR40_TO_VAR22.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_VAR40_TO_VAR22.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_VAR40_TO_VAR22.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_VAR40_TO_VAR22.inc"
;@endif

;@include "../_helpers/DECREMENT_VARF8_BY_10.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DECREMENT_VARF8_BY_10.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DECREMENT_VARF8_BY_10.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DECREMENT_VARF8_BY_10.inc"
;@endif

;@include "../_helpers/DECREMENT_VAR22_BY_10.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DECREMENT_VAR22_BY_10.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DECREMENT_VAR22_BY_10.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DECREMENT_VAR22_BY_10.inc"
;@endif

;@include "../_helpers/COPY_VAR01_TO_VAR28.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_VAR01_TO_VAR28.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_VAR01_TO_VAR28.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_VAR01_TO_VAR28.inc"
;@endif

