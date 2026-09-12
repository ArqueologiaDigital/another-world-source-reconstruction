INIT_VARS_E6_68_69_6B:
	mov [0xE6], 0x000A
	mov [0x68], 0x00DA
	mov [0x69], 0x00BA
	mov [0x6B], 0x0200

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VARS_E6_68_69_6B.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_E6_68_69_6B.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_E6_68_69_6B.inc"
.endif

INIT_VARS_EB_EC_ED:
	mov [0xEB], 0x0014
	mov [0xEC], 0x0064
	mov [0xED], 0x0064

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VARS_EB_EC_ED.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_EB_EC_ED.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_EB_EC_ED.inc"
.endif

INLINE_SET_VAR76_TO_0001_037:
	mov [0x76], 0x0001

.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_INLINE_SET_VAR76_TO_0001_037_L0:
	mov [0x07], [0x74]
	mov [0x08], [0x75]
	mov [0x09], [0x76]
	call CAVES_FALLING_ROCK_PHYSICS_TICK
	call CAVES_FALLING_ROCK_SMALL_DRAW
	mov [0x74], [0x07]
	mov [0x75], [0x08]
	mov [0x76], [0x09]
	break
	jmp CAVES_INLINE_SET_VAR76_TO_0001_037_L0
CAVES_INLINE_SET_VAR76_TO_0001_037_L3:
	db 0x11
.endif

INLINE_SET_VAR76_TO_0001_038:
	mov [0x76], 0x0001

.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_INLINE_SET_VAR76_TO_0001_038_L0:
	mov [0x07], [0x74]
	mov [0x08], [0x75]
	mov [0x09], [0x76]
	call CAVES_FALLING_ROCK_PHYSICS_TICK
	call CAVES_FALLING_ROCK_MEDIUM_DRAW
	mov [0x74], [0x07]
	mov [0x75], [0x08]
	mov [0x76], [0x09]
	break
	jmp CAVES_INLINE_SET_VAR76_TO_0001_038_L0
CAVES_INLINE_SET_VAR76_TO_0001_038_L2:
	db 0x11
.endif

INLINE_SET_VAR79_TO_1:
	mov [0x79], 0x0001

.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_INLINE_SET_VAR79_TO_1_L0:
	mov [0x07], [0x77]
	mov [0x08], [0x78]
	mov [0x09], [0x79]
	call CAVES_FALLING_ROCK_PHYSICS_TICK
	call CAVES_FALLING_ROCK_MEDIUM_DRAW
	mov [0x77], [0x07]
	mov [0x78], [0x08]
	mov [0x79], [0x09]
	break
	jmp CAVES_INLINE_SET_VAR79_TO_1_L0
CAVES_INLINE_SET_VAR79_TO_1_L1:
	db 0x11
.endif

INLINE_SET_VAR7C_TO_0001_039:
	mov [0x7C], 0x0001

.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_INLINE_SET_VAR7C_TO_0001_039_L0:
	mov [0x07], [0x7A]
	mov [0x08], [0x7B]
	mov [0x09], [0x7C]
	call CAVES_FALLING_ROCK_PHYSICS_TICK
	call CAVES_FALLING_ROCK_LARGE_DRAW
	mov [0x7A], [0x07]
	mov [0x7B], [0x08]
	mov [0x7C], [0x09]
	break
	jmp CAVES_INLINE_SET_VAR7C_TO_0001_039_L0
CAVES_INLINE_SET_VAR7C_TO_0001_039_L2:
	db 0x11
.endif

INLINE_SET_VAR7C_TO_0001_040:
	mov [0x7C], 0x0001

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_SET_VAR7C_TO_0001_040.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_SET_VAR7C_TO_0001_040.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_SET_VAR7C_TO_0001_040.inc"
.endif

INIT_VAR09_TO_7_VAR08_FROM_VAR22:
	mov [0x09], 0x0007
	mov [0x08], [0x22]

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VAR09_TO_7_VAR08_FROM_VAR22.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VAR09_TO_7_VAR08_FROM_VAR22.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VAR09_TO_7_VAR08_FROM_VAR22.inc"
.endif

INLINE_SET_VAR74_TO_6:
	mov [0x74], 0x0006

.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_INLINE_SET_VAR74_TO_6_L0:
	mov [0x07], [0x6E]
	mov [0x08], [0x6F]
	call RESET_VAR09_AND_DECR_VAR08_BY_4
	mov [0x6F], [0x08]
	break
	djnz [0x74], CAVES_INLINE_SET_VAR74_TO_6_L0
	mov [0x74], 0x0028

CAVES_INLINE_SET_VAR74_TO_6_L1:
	mov [0x07], [0x6E]
	mov [0x08], [0x6F]
	mov [0x09], 0x0000
	break
	djnz [0x74], CAVES_INLINE_SET_VAR74_TO_6_L1
	mov [0x74], 0x000C

CAVES_INLINE_SET_VAR74_TO_6_L2:
	mov [0x07], [0x6E]
	mov [0x08], [0x6F]
	call RESET_VAR09_AND_INCR_VAR08_BY_2
	mov [0x6F], [0x08]
	break
	djnz [0x74], CAVES_INLINE_SET_VAR74_TO_6_L2
	mov [0x49], 0x13A6
	jmp CAVES_INLINE_SET_VAR74_TO_6_L3
CAVES_INLINE_SET_VAR74_TO_6_L4:
	db 0x11
.endif

INLINE_SET_VAR75_TO_6:
	mov [0x75], 0x0006

.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_INLINE_SET_VAR75_TO_6_L0:
	mov [0x07], [0x70]
	mov [0x08], [0x71]
	call RESET_VAR09_AND_DECR_VAR08_BY_4
	mov [0x71], [0x08]
	break
	djnz [0x75], CAVES_INLINE_SET_VAR75_TO_6_L0
	mov [0x75], 0x0028

CAVES_INLINE_SET_VAR75_TO_6_L1:
	mov [0x07], [0x70]
	mov [0x08], [0x71]
	mov [0x09], 0x0000
	break
	djnz [0x75], CAVES_INLINE_SET_VAR75_TO_6_L1
	mov [0x75], 0x000C

CAVES_INLINE_SET_VAR75_TO_6_L2:
	mov [0x07], [0x70]
	mov [0x08], [0x71]
	call RESET_VAR09_AND_INCR_VAR08_BY_2
	mov [0x71], [0x08]
	break
	djnz [0x75], CAVES_INLINE_SET_VAR75_TO_6_L2
	mov [0x4B], 0x13A6
	jmp CAVES_INLINE_SET_VAR75_TO_6_L3
CAVES_INLINE_SET_VAR75_TO_6_L4:
	db 0x11
.endif

INLINE_SET_VAR76_TO_6:
	mov [0x76], 0x0006

.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_INLINE_SET_VAR76_TO_6_L0:
	mov [0x07], [0x72]
	mov [0x08], [0x73]
	call RESET_VAR09_AND_DECR_VAR08_BY_4
	mov [0x73], [0x08]
	break
	djnz [0x76], CAVES_INLINE_SET_VAR76_TO_6_L0
	mov [0x76], 0x0028

CAVES_INLINE_SET_VAR76_TO_6_L1:
	mov [0x07], [0x72]
	mov [0x08], [0x73]
	mov [0x09], 0x0000
	break
	djnz [0x76], CAVES_INLINE_SET_VAR76_TO_6_L1
	mov [0x76], 0x000C

CAVES_INLINE_SET_VAR76_TO_6_L2:
	mov [0x07], [0x72]
	mov [0x08], [0x73]
	call RESET_VAR09_AND_INCR_VAR08_BY_2
	mov [0x73], [0x08]
	break
	djnz [0x76], CAVES_INLINE_SET_VAR76_TO_6_L2
	mov [0x4D], 0x13A6
	jmp CAVES_INLINE_SET_VAR76_TO_6_L3
CAVES_INLINE_SET_VAR76_TO_6_L4:
	db 0x11
.endif

INLINE_SET_VAR73_TO_6:
	mov [0x73], 0x0006

.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_INLINE_SET_VAR73_TO_6_L0:
	mov [0x07], [0x68]
	mov [0x08], [0x69]
	call RESET_VAR09_AND_DECR_VAR08_BY_4
	mov [0x69], [0x08]
	break
	djnz [0x73], CAVES_INLINE_SET_VAR73_TO_6_L0
	mov [0x73], 0x0028

CAVES_INLINE_SET_VAR73_TO_6_L1:
	mov [0x07], [0x68]
	mov [0x08], [0x69]
	mov [0x09], 0x0000
	break
	djnz [0x73], CAVES_INLINE_SET_VAR73_TO_6_L1
	mov [0x73], 0x000C

CAVES_INLINE_SET_VAR73_TO_6_L2:
	mov [0x07], [0x68]
	mov [0x08], [0x69]
	call RESET_VAR09_AND_INCR_VAR08_BY_2
	mov [0x69], [0x08]
	break
	djnz [0x73], CAVES_INLINE_SET_VAR73_TO_6_L2
	mov [0x49], 0x13A6
	jmp CAVES_INLINE_SET_VAR73_TO_6_L3
CAVES_INLINE_SET_VAR73_TO_6_L4:
	db 0x11
.endif

RESET_VAR09_AND_DECR_VAR08_BY_4:
	mov [0x09], 0x0000
	sub [0x08], 0x0004
	ret


RESET_VAR09_AND_INCR_VAR08_BY_2:
	mov [0x09], 0x0000
	add [0x08], 0x0002
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_RESET_VAR09_AND_INCR_VAR08_BY_2.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_RESET_VAR09_AND_INCR_VAR08_BY_2.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_RESET_VAR09_AND_INCR_VAR08_BY_2.inc"
.endif

INIT_VARS_E6_E7:
	mov [0xE6], 0x0014
	mov [0xE7], 0x0000

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VARS_E6_E7.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_E6_E7.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_E6_E7.inc"
.endif

INLINE_SET_VARE8_TO_8:
	mov [0xE8], 0x0008

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_SET_VARE8_TO_8.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_SET_VARE8_TO_8.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_SET_VARE8_TO_8.inc"
.endif

INIT_VARS_EA_EB:
	mov [0xEA], 0x000E
	mov [0xEB], 0x0055

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VARS_EA_EB.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_EA_EB.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_EA_EB.inc"
.endif

COPY_VARE6E7_TO_VARE8_E9_EA_EB:
	mov [0xE8], [0xE6]
	mov [0xE9], [0xE7]
	mov [0xEA], [0xE6]
	mov [0xEB], [0xE7]


STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6:
	mov [0xEC], 0x0006
	add [0xE9], 0x0010
	sub [0xE8], 0x0001

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6.inc"
.endif

INIT_VAR08_FROM_VARE9_VAR09_TO_4:
	mov [0x08], [0xE9]
	mov [0x09], 0x0004

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VAR08_FROM_VARE9_VAR09_TO_4.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VAR08_FROM_VARE9_VAR09_TO_4.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VAR08_FROM_VARE9_VAR09_TO_4.inc"
.endif

MUL_VAR6B_BY_11_INTO_VAR21:
	mov [0x21], [0x6B]
	shl [0x21], 0x0003
	add [0x21], [0x6B]
	add [0x21], [0x6B]
	add [0x21], [0x6B]
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_MUL_VAR6B_BY_11_INTO_VAR21.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_MUL_VAR6B_BY_11_INTO_VAR21.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_MUL_VAR6B_BY_11_INTO_VAR21.inc"
.endif

INLINE_SET_VARE6_TO_32:
	mov [0xE6], 0x0032

.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_INLINE_SET_VARE6_TO_32_L0:
	add [0xE7], 0x0008
	mov [0x21], [0xE7]
	call CAVES_INLINE_SET_VARE6_TO_32_L1
	break
	djnz [0xE6], CAVES_INLINE_SET_VARE6_TO_32_L0
	mov [0xE6], 0x0032

CAVES_INLINE_SET_VARE6_TO_32_L2:
	sub [0xE7], 0x0008
	mov [0x21], [0xE7]
	call CAVES_INLINE_SET_VARE6_TO_32_L1
	break
	djnz [0xE6], CAVES_INLINE_SET_VARE6_TO_32_L2
	jmp INLINE_SET_VARE6_TO_32
.endif

INLINE_SET_VARE8_TO_2F:
	mov [0xE8], 0x002F

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_SET_VARE8_TO_2F.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_SET_VARE8_TO_2F.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_SET_VARE8_TO_2F.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
INLINE_SET_VAR6B_TO_1:
	mov [0x6B], 0x0001
.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_SET_VAR6B_TO_1.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_SET_VAR6B_TO_1.inc"
.endif

INIT_VARS_6C_6B:
	mov [0x6C], 0x03E8
	mov [0x6B], 0x000A

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VARS_6C_6B.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_6C_6B.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_6C_6B.inc"
.endif

.include "../_helpers/INCREMENT_VAR31.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INCREMENT_VAR31_BY_1.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INCREMENT_VAR31_BY_1.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INCREMENT_VAR31_BY_1.inc"
.endif

