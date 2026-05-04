SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8:
	add [SCROLL_Y], 0x00C8
	copyVideoPage src=0x83, dst=0xFF
	sub [SCROLL_Y], 0x00C8

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_E6_E7_EB:
	mov [0xE6], 0x0026
	mov [0xE7], 0x000E
	mov [0xEB], 0x000C
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_E6_E7_EB.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_E6_E7_EB.inc"
;@endif

INLINE_SET_VAR7F_TO_6:
	mov [0x7F], 0x0006

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR7F_TO_6.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR7F_TO_6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR7F_TO_6.inc"
;@endif

SET_VARE6_TO_64_KILL_CHANNEL:
	mov [0xE6], 0x0064
	killChannel

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VARE6_TO_64_KILL_CHANNEL.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VARE6_TO_64_KILL_CHANNEL.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VARE6_TO_64_KILL_CHANNEL.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8.inc"
;@endif

;@include "../_helpers/COPY_HASH_VAR_37_TO_RANGE.inc"

;@include "../_helpers/ACCUMULATE_HASH_INTO_VAR37_38.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_ACCUMULATE_HASH_INTO_VAR37_38.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_ACCUMULATE_HASH_INTO_VAR37_38.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_ACCUMULATE_HASH_INTO_VAR37_38.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
SETUP_67_45_VAR01_46_VARB1_NOSIGN:
	mov [HACK_VAR_67], 0x0045
	mov [0x01], 0x0046
	and [0xB1], 0x7FFF
	ret
;@endif


SETUP_67_67_VAR01_1E_VARBE_3:
	mov [HACK_VAR_67], 0x0067
	mov [0x01], 0x001E
	mov [0xBE], 0x0003
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SETUP_67_67_VAR01_1E_VARBE_3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SETUP_67_67_VAR01_1E_VARBE_3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SETUP_67_67_VAR01_1E_VARBE_3.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
SETUP_67_25_VAR06_0_VARB1_NOSIGN:
	mov [HACK_VAR_67], 0x0025
	mov [0x06], 0x0000
	and [0xB1], 0x7FFF
	ret
;@endif


SETUP_67_4B_VARS_B0_3_01_50_AF_58_B1:
	mov [HACK_VAR_67], 0x004B
	mov [0xB0], 0x0003
	mov [0x01], 0x0050
	mov [0xAF], 0x0058
	or [0xB1], 0x0010
	ret

;@if BRANCH == "cartridge_1992"
;@include "cart__post_SETUP_67_4B_VARS_B0_3_01_50_AF_58_B1.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
SETUP_67_A7_VARS_B0_2_02_5D_01_7F_BE_3:
	mov [HACK_VAR_67], 0x00A7
	mov [0xB0], 0x0002
	mov [0x02], 0x005D
	mov [0x01], 0x007F
	mov [0xBE], 0x0003
	or [0xB1], 0x00C0
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SETUP_67_A7_VARS_B0_2_02_5D_01_7F_BE_3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SETUP_67_A7_VARS_B0_2_02_5D_01_7F_BE_3.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "cartridge_1992")
INIT_HASH_VARS_67_66_65_68_69:
	mov [HACK_VAR_67], 0x0001
	mov [0x66], 0x0001
	mov [0x65], 0x0001
	mov [0x68], 0x00C8
	mov [0x69], 0x00B6
	mov [0x6A], 0x0001
	mov [0x6B], 0x3000
	mov [0x6C], 0x0000
	mov [0x6D], 0x0000
	mov [0x30], 0x0064
	mov [0x32], 0x0000
	mov [0xB4], 0x0001
	mov [0x70], 0x0118
	mov [0x71], 0x00B6
	mov [0x72], 0x0003
	mov [0x73], 0x2000
	mov [0x74], 0x2008
	mov [0x75], 0x0811
	mov [0x78], 0x0122
	mov [0x79], 0x00B6
	mov [0x7A], 0x000A
	mov [0x7B], 0x2000
	mov [0x7C], 0x2000
	mov [0x7D], 0x0800
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_HASH_VARS_67_66_65_68_69.inc"
;@endif

INIT_VARS_29_07_08:
	mov [0x29], 0x0028
	mov [0x07], 0x00C8
	mov [0x08], 0x000A

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_29_07_08.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_29_07_08.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_29_07_08.inc"
;@endif

INCREMENT_VAR07_BY_4:
	add [0x07], 0x0004
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INCREMENT_VAR07_BY_4.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INCREMENT_VAR07_BY_4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INCREMENT_VAR07_BY_4.inc"
;@endif

;@include "../_helpers/DERIVE_VAR12_11_10_FROM_VAR9.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DERIVE_VAR12_11_10_FROM_VAR9.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DERIVE_VAR12_11_10_FROM_VAR9.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DERIVE_VAR12_11_10_FROM_VAR9.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_COPY_VAR22_TO_VAR08.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_COPY_VAR22_TO_VAR08.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_COPY_VAR22_TO_VAR08.inc"
;@endif

;@include "../_helpers/SPLIT_VAR09_BITS_INTO_VAR0D.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SPLIT_VAR09_BITS_INTO_VAR0D.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SPLIT_VAR09_BITS_INTO_VAR0D.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SPLIT_VAR09_BITS_INTO_VAR0D.inc"
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

;@include "../_helpers/SET_VAR2F_TO_000F.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR2F_TO_000F.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR2F_TO_000F.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR2F_TO_000F.inc"
;@endif

;@include "../_helpers/SET_VAR2F_TO_001D.inc"

;@include "../_helpers/SET_VAR2F_TO_000D.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR2F_TO_000D.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR2F_TO_000D.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR2F_TO_000D.inc"
;@endif

;@include "../_helpers/STEP_VAR29_DOWN10_SET_VAR2F_11.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_STEP_VAR29_DOWN10_SET_VAR2F_11.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_STEP_VAR29_DOWN10_SET_VAR2F_11.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_STEP_VAR29_DOWN10_SET_VAR2F_11.inc"
;@endif

SET_VAR21_TO_0001:
	mov [0x21], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR21_TO_0001.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR21_TO_0001.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR21_TO_0001.inc"
;@endif

;@include "../_helpers/INIT_VARS_2F_29_12.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_2F_29_12_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_2F_29_12_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_2F_29_12_1.inc"
;@endif

;@include "../_helpers/FOLD_BODY_189B_29E88AAE.inc"

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
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_6B_001.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_6B_001.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_6B_001.inc"
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

