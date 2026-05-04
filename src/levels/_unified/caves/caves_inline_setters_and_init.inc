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
	mov [0x01], 0x000E

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

INIT_VARS_E6_68_69_6B:
	mov [0xE6], 0x000A
	mov [0x68], 0x00DA
	mov [0x69], 0x00BA
	mov [0x6B], 0x0200

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_E6_68_69_6B.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_E6_68_69_6B.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_E6_68_69_6B.inc"
;@endif

INIT_VARS_EB_EC_ED:
	mov [0xEB], 0x0014
	mov [0xEC], 0x0064
	mov [0xED], 0x0064

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_EB_EC_ED.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_EB_EC_ED.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_EB_EC_ED.inc"
;@endif

INLINE_SET_VAR76_TO_0001_037:
	mov [0x76], 0x0001

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR76_TO_0001_037.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR76_TO_0001_037.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR76_TO_0001_037.inc"
;@endif

INLINE_SET_VAR76_TO_0001_038:
	mov [0x76], 0x0001

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR76_TO_0001_038.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR76_TO_0001_038.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR76_TO_0001_038.inc"
;@endif

INLINE_SET_VAR79_TO_1:
	mov [0x79], 0x0001

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR79_TO_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR79_TO_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR79_TO_1.inc"
;@endif

INLINE_SET_VAR7C_TO_0001_039:
	mov [0x7C], 0x0001

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR7C_TO_0001_039.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR7C_TO_0001_039.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR7C_TO_0001_039.inc"
;@endif

INLINE_SET_VAR7C_TO_0001_040:
	mov [0x7C], 0x0001

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR7C_TO_0001_040.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR7C_TO_0001_040.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR7C_TO_0001_040.inc"
;@endif

INIT_VAR09_TO_7_VAR08_FROM_VAR22:
	mov [0x09], 0x0007
	mov [0x08], [0x22]

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VAR09_TO_7_VAR08_FROM_VAR22.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VAR09_TO_7_VAR08_FROM_VAR22.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VAR09_TO_7_VAR08_FROM_VAR22.inc"
;@endif

INLINE_SET_VAR74_TO_6:
	mov [0x74], 0x0006

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR74_TO_6.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR74_TO_6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR74_TO_6.inc"
;@endif

INLINE_SET_VAR75_TO_6:
	mov [0x75], 0x0006

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR75_TO_6.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR75_TO_6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR75_TO_6.inc"
;@endif

INLINE_SET_VAR76_TO_6:
	mov [0x76], 0x0006

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR76_TO_6.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR76_TO_6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR76_TO_6.inc"
;@endif

INLINE_SET_VAR73_TO_6:
	mov [0x73], 0x0006

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR73_TO_6.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR73_TO_6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR73_TO_6.inc"
;@endif

RESET_VAR09_AND_DECR_VAR08_BY_4:
	mov [0x09], 0x0000
	sub [0x08], 0x0004
	ret


RESET_VAR09_AND_INCR_VAR08_BY_2:
	mov [0x09], 0x0000
	add [0x08], 0x0002
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_RESET_VAR09_AND_INCR_VAR08_BY_2.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_RESET_VAR09_AND_INCR_VAR08_BY_2.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_RESET_VAR09_AND_INCR_VAR08_BY_2.inc"
;@endif

INIT_VARS_E6_E7:
	mov [0xE6], 0x0014
	mov [0xE7], 0x0000

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_E6_E7.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_E6_E7.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_E6_E7.inc"
;@endif

INLINE_SET_VARE8_TO_8:
	mov [0xE8], 0x0008

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VARE8_TO_8.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VARE8_TO_8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VARE8_TO_8.inc"
;@endif

INIT_VARS_EA_EB:
	mov [0xEA], 0x000E
	mov [0xEB], 0x0055

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_EA_EB.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_EA_EB.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_EA_EB.inc"
;@endif

COPY_VARE6E7_TO_VARE8_E9_EA_EB:
	mov [0xE8], [0xE6]
	mov [0xE9], [0xE7]
	mov [0xEA], [0xE6]
	mov [0xEB], [0xE7]


STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6:
	mov [0xEC], 0x0006
	add [0xE9], 0x0010
	sub [0xE8], 0x0001

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6.inc"
;@endif

INIT_VAR08_FROM_VARE9_VAR09_TO_4:
	mov [0x08], [0xE9]
	mov [0x09], 0x0004

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VAR08_FROM_VARE9_VAR09_TO_4.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VAR08_FROM_VARE9_VAR09_TO_4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VAR08_FROM_VARE9_VAR09_TO_4.inc"
;@endif

MUL_VAR6B_BY_11_INTO_VAR21:
	mov [0x21], [0x6B]
	shl [0x21], 0x0003
	add [0x21], [0x6B]
	add [0x21], [0x6B]
	add [0x21], [0x6B]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_MUL_VAR6B_BY_11_INTO_VAR21.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_MUL_VAR6B_BY_11_INTO_VAR21.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_MUL_VAR6B_BY_11_INTO_VAR21.inc"
;@endif

INLINE_SET_VARE6_TO_32:
	mov [0xE6], 0x0032

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VARE6_TO_32.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VARE6_TO_32.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VARE6_TO_32.inc"
;@endif

INLINE_SET_VARE8_TO_2F:
	mov [0xE8], 0x002F

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VARE8_TO_2F.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VARE8_TO_2F.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VARE8_TO_2F.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
INLINE_SET_VAR6B_TO_1:
	mov [0x6B], 0x0001
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR6B_TO_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR6B_TO_1.inc"
;@endif

INIT_VARS_6C_6B:
	mov [0x6C], 0x03E8
	mov [0x6B], 0x000A

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_6C_6B.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_6C_6B.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_6C_6B.inc"
;@endif

;@include "../_helpers/INCREMENT_VAR31.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INCREMENT_VAR31_BY_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INCREMENT_VAR31_BY_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INCREMENT_VAR31_BY_1.inc"
;@endif

