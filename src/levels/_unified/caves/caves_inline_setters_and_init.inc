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

;@if BRANCH == "chahi_amiga_1991"
;@elif BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

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

;@if BRANCH == "chahi_amiga_1991"
;@elif BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

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

;@if BRANCH == "chahi_amiga_1991"
;@elif BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

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
;@if BRANCH == "chahi_amiga_1991"
;@elif BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

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

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
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

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

SETUP_67_4B_VARS_B0_3_01_50_AF_58_B1:
	mov [HACK_VAR_67], 0x004B
	mov [0xB0], 0x0003
	mov [0x01], 0x0050
	mov [0xAF], 0x0058
	or [0xB1], 0x0010
	ret

;@if BRANCH == "chahi_amiga_1991"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SETUP_67_4B_VARS_B0_3_01_50_AF_58_B1.inc"
;@elif BRANCH == "dos_1992"
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
;@elif BRANCH == "cartridge_1992"
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
;@if BRANCH == "chahi_amiga_1991"
;@elif BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

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
;@if BRANCH == "chahi_amiga_1991"
;@elif BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

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
;@if BRANCH == "chahi_amiga_1991"
;@elif BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

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
;@if BRANCH == "chahi_amiga_1991"
;@elif BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

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

DEDUP_CAVES_5B_003:
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

DEDUP_CAVES_6B_001:
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_6B_002.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_6B_002.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_6B_002.inc"
;@endif

;@include "../_helpers/SHARED_RET.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SHARED_RET.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SHARED_RET.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SHARED_RET.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV204_AT_X07_Y08.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV204_AT_X07_Y08.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV204_AT_X07_Y08.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV204_AT_X07_PLUS1_Y08.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV204_AT_X07_PLUS1_Y08.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV204_AT_X07_PLUS1_Y08.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_216_027.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_216_029.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_216_029.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_220_008.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_220_016.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_220_016.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV224_AT_X07_Y08.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV224_AT_X07_Y08.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV224_AT_X07_Y08.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_228_018.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_228_018.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_228_018.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_228_018:
	video type=0, offset=COMMON_VIDEO_228, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x16,0xAB,0x07,0x08
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_228_019.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_228_019.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_220_008:
	video type=0, offset=COMMON_VIDEO_220, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x16,0xAF,0x07,0x08
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_220_017.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_220_017.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_216_027:
	video type=0, offset=COMMON_VIDEO_216, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x16,0xB3,0x07,0x08
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_216_030.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_216_030.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV263_AT_X07_Y08.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV263_AT_X07_Y08.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV263_AT_X07_Y08.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_266_005.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_266_005.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_266_005.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_269_024.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_269_024.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_269_024.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_272_003.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_272_013.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_272_013.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV275_AT_X07_Y08.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV275_AT_X07_Y08.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV275_AT_X07_Y08.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_272_003:
	video type=0, offset=COMMON_VIDEO_272, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x18,0xF6,0x07,0x08
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_272_014.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_272_014.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_272_003:
	video type=0, offset=COMMON_VIDEO_272, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x18,0xF6,0x07,0x08
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_272_015.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_272_015.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_269_024:
	video type=0, offset=COMMON_VIDEO_269, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x18,0xFB,0x07,0x08
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_269_025.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_269_025.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_269_024:
	video type=0, offset=COMMON_VIDEO_269, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x18,0xFB,0x07,0x08
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_269_026.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_269_026.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_266_005:
	video type=0, offset=COMMON_VIDEO_266, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x19,0x00,0x07,0x08
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_266_006.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_266_006.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_243_012.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

;@include "../_helpers/DEDUP_CAVES_5B_020.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_020.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_020.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_020.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV246_AT_X07_Y08.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV246_AT_X07_Y08.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV246_AT_X07_Y08.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV249_AT_X07_Y08.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

;@include "../_helpers/DEDUP_CAVES_5B_007.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_007.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_007.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_007.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_252_018.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

DEDUP_CAVES_5B_007:
	sub [0x08], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_008.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_008.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_008.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_255_010.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_255_031.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_255_031.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_255_010:
	video type=0, offset=COMMON_VIDEO_255, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x11,0x09,0x07,0x08
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

DEDUP_CAVES_5B_020:
	add [0x08], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_021.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_021.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_021.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_252_018:
	video type=0, offset=COMMON_VIDEO_252, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x11,0x00,0x07,0x08
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_252_023.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_252_023.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV259_AT_X07_Y08.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

DEDUP_CAVES_5B_007:
	sub [0x08], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_009.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_009.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_009.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV261_AT_X07_Y08.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

DEDUP_CAVES_5B_007:
	sub [0x08], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_010.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_010.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_010.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_243_012:
	video type=0, offset=COMMON_VIDEO_243, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x30,0x84,0x07,0x08
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

;@include "../_helpers/INCREMENT_VAR07_BY_1.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INCREMENT_VAR07_BY_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INCREMENT_VAR07_BY_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INCREMENT_VAR07_BY_1.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV_301:
	video type=0, offset=COMMON_VIDEO_301, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x0E,0x3C,0x07,0x08
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_301.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_301.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_355.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_355.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_355.inc"
;@endif

;@include "../_helpers/DECREMENT_VAR08_BY_D.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DECREMENT_VAR08_BY_D.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DECREMENT_VAR08_BY_D.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DECREMENT_VAR08_BY_D.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_074.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_074.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_074.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_075.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_075.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_075.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_076.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_076.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_076.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_077.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_077.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_077.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV078_PLAY_60_F0B_V22_C1:
	video type=0, offset=COMMON_VIDEO_078, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x57,0x01,0x1A,0x01,0x02
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x01
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV078_PLAY_60_F0B_V22_C1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV078_PLAY_60_F0B_V22_C1.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_080.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_080.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_080.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_061.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_061.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_061.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_063.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_063.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_063.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_065.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_065.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_065.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_067.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_067.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_067.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_069.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_069.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_069.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV070_PLAY_60_F14_V20_C1:
	video type=0, offset=COMMON_VIDEO_070, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x57,0x04,0x0A,0x01,0x02
	play id=0x0060, freq=0x14, vol=0x20, channel=0x01
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV070_PLAY_60_F14_V20_C1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV070_PLAY_60_F14_V20_C1.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_071.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_071.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_071.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_072.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_072.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_072.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_073.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_300.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_299.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_295.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_296.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_297.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_297.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_297.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_298.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_298.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_298.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV107_AT_X01_Y02.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV108_PLAY_60_F0F_V2A_C1:
	video type=0, offset=COMMON_VIDEO_108, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x57,0x08,0xDC,0x01,0x02
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x01
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV108_PLAY_60_F0F_V2A_C1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV108_PLAY_60_F0F_V2A_C1.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV109_AT_X01_Y02.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_110.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_110.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_110.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV111_AT_X01_Y02.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_112.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_112.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_112.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV113_AT_X01_Y02.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_114.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_114.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_114.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_115.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_115.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_115.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV097_AT_X01_Y02.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV098_PLAY_60_F0A_V2A_C1:
	video type=0, offset=COMMON_VIDEO_098, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x57,0x0A,0x85,0x01,0x02
	play id=0x0060, freq=0x0A, vol=0x2A, channel=0x01
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV098_PLAY_60_F0A_V2A_C1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV098_PLAY_60_F0A_V2A_C1.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV099_AT_X01_Y02.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_100.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_100.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_100.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV101_AT_X01_Y02.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_102.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_102.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_102.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV103_AT_X01_Y02.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_104.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_104.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_104.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV105_AT_X01_Y02.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV105_AT_X01_Y02.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV105_AT_X01_Y02.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_SET_VAR20_TO_1.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR20_TO_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR20_TO_1.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/COPY_PAGE0_TO_3_AND_VAR66_TO_VAR65.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_COPY_PAGE0_TO_3_AND_VAR66_TO_VAR65.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_PAGE0_TO_3_AND_VAR66_TO_VAR65.inc"
;@endif

;@include "../_helpers/COPY_VAR51_TO_VAR02_KILL_CHANNEL.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_VAR51_TO_VAR02_KILL_CHANNEL.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_VAR51_TO_VAR02_KILL_CHANNEL.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_VAR51_TO_VAR02_KILL_CHANNEL.inc"
;@endif

;@include "../_helpers/COPY_VAR52_TO_VAR02_KILL_CHANNEL.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_VAR52_TO_VAR02_KILL_CHANNEL.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_VAR52_TO_VAR02_KILL_CHANNEL.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_VAR52_TO_VAR02_KILL_CHANNEL.inc"
;@endif

;@include "../_helpers/RESET_HERO_ACTION_KEEP_POS_4LSB.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_RESET_HERO_ACTION_KEEP_POS_4LSB.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_RESET_HERO_ACTION_KEEP_POS_4LSB.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_RESET_HERO_ACTION_KEEP_POS_4LSB.inc"
;@endif

;@include "../_helpers/INLINE_SUB_VAR50_BY_14.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SUB_VAR50_BY_14.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SUB_VAR50_BY_14.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SUB_VAR50_BY_14.inc"
;@endif

SET_VAR22_TO_006B:
	mov [0x22], 0x006B
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_006B.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_006B.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_006B.inc"
;@endif

SET_VAR22_TO_0061:
	mov [0x22], 0x0061
	ret

;@if BRANCH == "chahi_amiga_1991"
;@elif BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

SET_VAR22_TO_00C8:
	mov [0x22], 0x00C8
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_00C8.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00C8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00C8.inc"
;@endif

PROJ_VAR22_68_MINUS_VAR21_MINUS_F2_SHR4:
	sub [0x21], 0x00F2
	shr [0x21], 0x0004
	mov [0x22], 0x0068
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_68_MINUS_VAR21_MINUS_F2_SHR4.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_68_MINUS_VAR21_MINUS_F2_SHR4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_68_MINUS_VAR21_MINUS_F2_SHR4.inc"
;@endif

DEDUP_CAVES_5B_027:
	mov [0x22], 0x006F
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_027.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_027.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_027.inc"
;@endif

PROJ_VAR22_2F_MINUS_VAR21_MINUS_ED_SHR1:
	sub [0x21], 0x00ED
	shr [0x21], 0x0001
	mov [0x22], 0x002F
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_2F_MINUS_VAR21_MINUS_ED_SHR1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_2F_MINUS_VAR21_MINUS_ED_SHR1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_2F_MINUS_VAR21_MINUS_ED_SHR1.inc"
;@endif

SET_VAR22_TO_00AB:
	mov [0x22], 0x00AB
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_00AB.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00AB.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00AB.inc"
;@endif

PROJ_VAR22_17_MINUS_VAR21_MINUS_F0_SHL3:
	sub [0x21], 0x00F0
	shl [0x21], 0x0003
	mov [0x22], 0x0017
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_17_MINUS_VAR21_MINUS_F0_SHL3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_17_MINUS_VAR21_MINUS_F0_SHL3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_17_MINUS_VAR21_MINUS_F0_SHL3.inc"
;@endif

PROJ_VAR22_AA_MINUS_VAR21_MINUS_115_SHR3:
	sub [0x21], 0x0115
	shr [0x21], 0x0003
	mov [0x22], 0x00AA
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_AA_MINUS_VAR21_MINUS_115_SHR3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_AA_MINUS_VAR21_MINUS_115_SHR3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_AA_MINUS_VAR21_MINUS_115_SHR3.inc"
;@endif

INIT_VARS_01_22:
	mov [0x01], 0x0078
	mov [0x22], 0x0064
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_01_22.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_01_22.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_01_22.inc"
;@endif

PROJ_VAR22_B3_MINUS_VAR21_MINUS_109_SHR3:
	sub [0x21], 0x0109
	shr [0x21], 0x0003
	mov [0x22], 0x00B3
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_B3_MINUS_VAR21_MINUS_109_SHR3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_B3_MINUS_VAR21_MINUS_109_SHR3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_B3_MINUS_VAR21_MINUS_109_SHR3.inc"
;@endif

PROJ_VAR22_53_PLUS_VAR21_MINUS_106_SHR3:
	sub [0x21], 0x0106
	shr [0x21], 0x0003
	mov [0x22], 0x0053
	add [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_53_PLUS_VAR21_MINUS_106_SHR3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_53_PLUS_VAR21_MINUS_106_SHR3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_53_PLUS_VAR21_MINUS_106_SHR3.inc"
;@endif

PROJ_VAR22_9E_MINUS_VAR21_MINUS_121_SHR3:
	sub [0x21], 0x0121
	shr [0x21], 0x0003
	mov [0x22], 0x009E
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_9E_MINUS_VAR21_MINUS_121_SHR3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_9E_MINUS_VAR21_MINUS_121_SHR3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_9E_MINUS_VAR21_MINUS_121_SHR3.inc"
;@endif

PROJ_VAR22_7E_MINUS_VAR21_MINUS_11B_SHR4:
	sub [0x21], 0x011B
	shr [0x21], 0x0004
	mov [0x22], 0x007E
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_7E_MINUS_VAR21_MINUS_11B_SHR4.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_7E_MINUS_VAR21_MINUS_11B_SHR4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_7E_MINUS_VAR21_MINUS_11B_SHR4.inc"
;@endif

PROJ_VAR22_75_MINUS_VAR21_MINUS_FD_SHR6:
	sub [0x21], 0x00FD
	shr [0x21], 0x0006
	mov [0x22], 0x0075
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_75_MINUS_VAR21_MINUS_FD_SHR6.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_75_MINUS_VAR21_MINUS_FD_SHR6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_75_MINUS_VAR21_MINUS_FD_SHR6.inc"
;@endif

PROJ_VAR22_76_MINUS_VAR21_MINUS_108_SHR5:
	sub [0x21], 0x0108
	shr [0x21], 0x0005
	mov [0x22], 0x0076
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_76_MINUS_VAR21_MINUS_108_SHR5.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_76_MINUS_VAR21_MINUS_108_SHR5.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_76_MINUS_VAR21_MINUS_108_SHR5.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
PROJ_VAR22_49_MINUS_VAR21_MINUS_113_SHR4:
	sub [0x21], 0x0113
	shr [0x21], 0x0004
	mov [0x22], 0x0049
	sub [0x22], [0x21]
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_49_MINUS_VAR21_MINUS_113_SHR4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_49_MINUS_VAR21_MINUS_113_SHR4.inc"
;@endif

SET_VAR22_TO_007D:
	mov [0x22], 0x007D
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_007D.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_007D.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_007D.inc"
;@endif

SET_VAR22_TO_0080:
	mov [0x22], 0x0080
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_0080.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_0080.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_0080.inc"
;@endif

SET_VAR22_TO_00AC:
	mov [0x22], 0x00AC
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_00AC.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00AC.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00AC.inc"
;@endif

SET_VAR22_TO_0087:
	mov [0x22], 0x0087
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_0087.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_0087.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_0087.inc"
;@endif

PROJ_VAR22_85_PLUS_VAR21_MINUS_56:
	sub [0x21], 0x0056
	mov [0x22], 0x0085
	add [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@elif BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

SET_VAR22_TO_0085:
	mov [0x22], 0x0085
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_0085.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_0085.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_0085.inc"
;@endif

SET_VAR22_TO_00C3:
	mov [0x22], 0x00C3
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_00C3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00C3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00C3.inc"
;@endif

PROJ_VAR22_A8_MINUS_VAR21_MINUS_112_SHR4:
	sub [0x21], 0x0112
	shr [0x21], 0x0004
	mov [0x22], 0x00A8
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_A8_MINUS_VAR21_MINUS_112_SHR4.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_A8_MINUS_VAR21_MINUS_112_SHR4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_A8_MINUS_VAR21_MINUS_112_SHR4.inc"
;@endif

DEDUP_CAVES_5B_011:
	mov [0x22], 0x00B0
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_011.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_011.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_011.inc"
;@endif

PROJ_VAR22_B0_PLUS_VAR21_MINUS_69:
	sub [0x21], 0x0069
	mov [0x22], 0x00B0
	add [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@elif BRANCH == "cartridge_1992"
;@elif BRANCH == "dos_1992"
;@endif

DEDUP_CAVES_5B_012:
	mov [0x22], 0x00B0
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_012.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_012.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_012.inc"
;@endif

DEDUP_CAVES_5B_028:
	mov [0x22], 0x006F
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_028.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_028.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_028.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
SET_VAR22_TO_0042:
	mov [0x22], 0x0042
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_0042.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_0042.inc"
;@endif

SET_VAR22_TO_00AE:
	mov [0x22], 0x00AE
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_00AE.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00AE.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00AE.inc"
;@endif

PROJ_VAR22_A7_MINUS_VAR21_MINUS_125_SHR3:
	sub [0x21], 0x0125
	shr [0x21], 0x0003
	mov [0x22], 0x00A7
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_A7_MINUS_VAR21_MINUS_125_SHR3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_A7_MINUS_VAR21_MINUS_125_SHR3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_A7_MINUS_VAR21_MINUS_125_SHR3.inc"
;@endif

;@include "../_helpers/SET_VAR22_TO_00B8.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_00B8.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00B8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00B8.inc"
;@endif

INIT_VARS_EB_47:
	mov [0xEB], 0x000A
	mov [0x47], 0x010A

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_EB_47.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_EB_47.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_EB_47.inc"
;@endif

PLAY_FX_6B_THEN_KILL_CHANNEL:
	play id=0x006B, freq=0x1C, vol=0x40, channel=0x03
	killChannel

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PLAY_FX_6B_THEN_KILL_CHANNEL.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PLAY_FX_6B_THEN_KILL_CHANNEL.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PLAY_FX_6B_THEN_KILL_CHANNEL.inc"
;@endif

