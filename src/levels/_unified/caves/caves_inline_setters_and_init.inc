DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29:
	mov [0xF8], [0xB1]
	and [0xF8], 0x0005
	mov [0xF5], [0xB2]
	and [0xF5], 0x0002
	add [0xF8], [0xF5]
	add [0xF8], 0x0029

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29.inc"
;@endif

COPY_VAR00_TO_VARF8:
	mov [0xF8], [0x00]
	ret


COPY_VARF8_TO_VAR00:
	mov [0x00], [0xF8]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_VARF8_TO_VAR00.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_VARF8_TO_VAR00.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_VARF8_TO_VAR00.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
INLINE_SET_VARE6_TO_3:
	mov [0xE6], 0x0003
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VARE6_TO_3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VARE6_TO_3.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
INIT_VARS_E6_E7_E8:
	mov [0xE6], 0x0008
	mov [0xE7], 0x0050
	mov [0xE8], 0x00AA
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_E6_E7_E8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_E6_E7_E8.inc"
;@endif

INIT_VARS_E6_E7_E8_E8_PLUS3:
	mov [0xE6], 0x0063
	mov [0xE7], 0x0000
	mov [0xE8], 0x010F
	mov [0xE8], 0x0000
	mov [0xF1], 0x0090
	mov [0xF0], 0x0019
	mov [0xEE], 0x0046

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_E6_E7_E8_E8_PLUS3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_E6_E7_E8_E8_PLUS3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_E6_E7_E8_E8_PLUS3.inc"
;@endif

INIT_VARS_6D_71_70:
	mov [0x6D], 0x000E
	mov [0x71], 0xFFFF
	mov [0x70], 0x0009

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_6D_71_70.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_6D_71_70.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_6D_71_70.inc"
;@endif

INLINE_SET_VAR70_TO_8:
	mov [0x70], 0x0008

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR70_TO_8.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR70_TO_8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR70_TO_8.inc"
;@endif

INIT_VARS_71_6C_6D:
	mov [0x71], 0x0064
	mov [0x6C], 0x00B1
	mov [0x6D], 0x0006

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_71_6C_6D.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_71_6C_6D.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_71_6C_6D.inc"
;@endif

INIT_VARS_6C_6D_71_70:
	mov [0x6C], 0x00B1
	mov [0x6D], 0x0006
	mov [0x71], 0x0064
	mov [0x70], 0x001E

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_6C_6D_71_70.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_6C_6D_71_70.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_6C_6D_71_70.inc"
;@endif

INIT_VARS_E6_E7_2:
	mov [0xE6], 0x011D
	mov [0xE7], 0x000A

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_E6_E7_2.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_E6_E7_2.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_E6_E7_2.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_E6_E7_1:
	mov [0xE6], 0x004E
	mov [0xE7], 0x000A
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_E6_E7_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_E6_E7_1.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_E6_E9_E8:
	mov [0xE6], 0x006C
	mov [0xE9], 0xFFFF
	mov [0xE8], 0x0014
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_E6_E9_E8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_E6_E9_E8.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_E6_E7_E9_E8:
	mov [0xE6], 0x0064
	mov [0xE7], 0x0038
	mov [0xE9], 0x0001
	mov [0xE8], 0x0014
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_E6_E7_E9_E8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_E6_E7_E9_E8.inc"
;@endif

INIT_VARS_0E_29:
	mov [0x0E], 0x0007
	mov [0x29], 0x0005

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_0E_29.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_0E_29.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_0E_29.inc"
;@endif

INIT_VARS_EE_EF:
	mov [0xEE], 0x00FA
	mov [0xEF], 0x0005

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_EE_EF.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_EE_EF.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_EE_EF.inc"
;@endif

INLINE_SET_VAREF_TO_5:
	mov [0xEF], 0x0005

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAREF_TO_5.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAREF_TO_5.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAREF_TO_5.inc"
;@endif

INLINE_SET_VAR68_TO_32:
	mov [0x68], 0x0032

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR68_TO_32.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR68_TO_32.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR68_TO_32.inc"
;@endif

INLINE_SET_VAR6A_TO_2F:
	mov [0x6A], 0x002F

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR6A_TO_2F.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR6A_TO_2F.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR6A_TO_2F.inc"
;@endif

INLINE_SET_VAR01_TO_E:
	mov [HERO_X], 0x000E

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR01_TO_E.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR01_TO_E.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR01_TO_E.inc"
;@endif

INLINE_SET_VARE6_TO_1E:
	mov [0xE6], 0x001E

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VARE6_TO_1E.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VARE6_TO_1E.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VARE6_TO_1E.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_E8_E6:
	mov [0xE8], 0x0050
	mov [0xE6], 0x0000
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_E8_E6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_E8_E6.inc"
;@endif

