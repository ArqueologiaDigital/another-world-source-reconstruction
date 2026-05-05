INLINE_SET_VAR29_TO_4:
	mov [0x29], 0x0004

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR29_TO_4.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR29_TO_4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR29_TO_4.inc"
;@endif

RAMP_VAR1_PLUS_C_9_5_3_BREAKS:
	add [HERO_X], 0x000C
	break
	add [HERO_X], 0x0009
	break
	add [HERO_X], 0x0005
	break
	add [HERO_X], 0x0004
	break
	add [HERO_X], 0x0003
	break
	add [HERO_X], 0x0002
	break
	add [HERO_X], 0x0001
	break
	add [HERO_X], 0x0001
	killChannel


BREAK_5X_THEN_INIT_VAR03_14:
	break
	break
	break
	break
	break
	mov [0x03], 0x0014

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_BREAK_5X_THEN_INIT_VAR03_14.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_BREAK_5X_THEN_INIT_VAR03_14.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_BREAK_5X_THEN_INIT_VAR03_14.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_SET_VAR03_TO_14:
	mov [0x03], 0x0014
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR03_TO_14.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR03_TO_14.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_TEXT_0174_AT_26_180:
	text id=0x0174, x=26, y=180, color=0x0D ; "string_0174"
	ret
	mov [HERO_X], 0x03E8
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_TEXT_0174_AT_26_180.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_TEXT_0174_AT_26_180.inc"
;@endif

INLINE_SET_VAREC_TO_AF:
	mov [0xEC], 0x00AF

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAREC_TO_AF.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAREC_TO_AF.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAREC_TO_AF.inc"
;@endif

INIT_VARS_07_08_29:
	mov [0x07], 0x009D
	mov [0x08], 0x009D
	mov [0x29], 0x000A

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_07_08_29.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_07_08_29.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_07_08_29.inc"
;@endif

SET_VAR01_TO_6E_KILL_CHANNEL:
	mov [HERO_X], 0x006E
	killChannel

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR01_TO_6E_KILL_CHANNEL.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR01_TO_6E_KILL_CHANNEL.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR01_TO_6E_KILL_CHANNEL.inc"
;@endif

TWEEN_VARE8_DOWN_8_STEPS:
	sub [0xE8], 0x0001
	break
	sub [0xE8], 0x0002
	break
	sub [0xE8], 0x0001
	break
	sub [0xE8], 0x0001
	break
	break
	add [0xE8], 0x0001
	break

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_TWEEN_VARE8_DOWN_8_STEPS.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_TWEEN_VARE8_DOWN_8_STEPS.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_TWEEN_VARE8_DOWN_8_STEPS.inc"
;@endif

INLINE_SET_VARED_TO_6:
	mov [0xED], 0x0006

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VARED_TO_6.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VARED_TO_6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VARED_TO_6.inc"
;@endif

INLINE_SET_VARED_TO_5:
	mov [0xED], 0x0005

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VARED_TO_5.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VARED_TO_5.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VARED_TO_5.inc"
;@endif

INLINE_SET_VARE6_TO_4:
	mov [0xE6], 0x0004

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VARE6_TO_4.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VARE6_TO_4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VARE6_TO_4.inc"
;@endif

INLINE_SET_VAREF_TO_A0:
	mov [0xEF], 0x00A0

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAREF_TO_A0.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAREF_TO_A0.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAREF_TO_A0.inc"
;@endif

INIT_VARS_E6_E7_1:
	mov [0xE6], 0x00F0
	mov [0xE7], 0x00A8

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_E6_E7_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_E6_E7_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_E6_E7_1.inc"
;@endif

INLINE_SET_VARE8_TO_F:
	mov [0xE8], 0x000F

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VARE8_TO_F.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VARE8_TO_F.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VARE8_TO_F.inc"
;@endif

SET_VARB1_TO_0000:
	mov [0xB1], 0x0000
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VARB1_TO_0000.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VARB1_TO_0000.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VARB1_TO_0000.inc"
;@endif

SET_VARB3_TO_0000:
	mov [0xB3], 0x0000
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VARB3_TO_0000.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VARB3_TO_0000.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VARB3_TO_0000.inc"
;@endif

;@include "../_helpers/INCREMENT_VAR31.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INCREMENT_VAR31.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INCREMENT_VAR31.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INCREMENT_VAR31.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/SCROLL_BLIT_P80_TO_PFF_OFFSET_00C8.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_SCROLL_BLIT_P80_TO_PFF_OFFSET_00C8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SCROLL_BLIT_P80_TO_PFF_OFFSET_00C8.inc"
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
INIT_VAR6F_TO_A_PAUSE_3:
	mov [0x6F], 0x000A
	mov [PAUSE_SLICES], 0x0003
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VAR6F_TO_A_PAUSE_3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VAR6F_TO_A_PAUSE_3.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_SET_VAR29_TO_6.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR29_TO_6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR29_TO_6.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_SET_VAR29_TO_8:
	mov [0x29], 0x0008
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR29_TO_8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR29_TO_8.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_03_01_02:
	mov [0x03], 0x0003
	mov [HERO_X], 0x0063
	mov [HERO_Y], 0x00A8
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_03_01_02.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_03_01_02.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_SET_VARE6_TO_F:
	mov [0xE6], 0x000F
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VARE6_TO_F.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VARE6_TO_F.inc"
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

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_29_2F:
	mov [0x29], 0x0002
	mov [0x2F], 0x0009
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_29_2F.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_29_2F.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_2F_29_1:
	mov [0x2F], 0x0009
	mov [0x29], 0x0003
	ret
;@endif


;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_2F_29:
	mov [0x2F], 0x0007
	mov [0x29], 0x0002
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_2F_29.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_2F_29.inc"
;@endif

;@include "../_helpers/INIT_VARS_2F_29_12.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_2F_29_12.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_2F_29_12.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_2F_29_12.inc"
;@endif

;@include "../_helpers/FOLD_BODY_189B_29E88AAE.inc"
