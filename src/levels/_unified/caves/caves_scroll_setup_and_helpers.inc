SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8:
	add [SCROLL_Y], 0x00C8
	copyVideoPage src=0x83, dst=0xFF
	sub [SCROLL_Y], 0x00C8

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_E6_E7_EB:
	mov [0xE6], 0x0026
	mov [0xE7], 0x000E
	mov [0xEB], 0x000C
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_E6_E7_EB.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_E6_E7_EB.inc"
.endif

INLINE_SET_VAR7F_TO_6:
	mov [0x7F], 0x0006

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_SET_VAR7F_TO_6.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_SET_VAR7F_TO_6.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_SET_VAR7F_TO_6.inc"
.endif

SET_VARE6_TO_64_KILL_CHANNEL:
	mov [0xE6], 0x0064
	killChannel

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_SET_VARE6_TO_64_KILL_CHANNEL.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_SET_VARE6_TO_64_KILL_CHANNEL.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_SET_VARE6_TO_64_KILL_CHANNEL.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8.inc"
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8.inc"
.endif

.include "../_helpers/COPY_HASH_VAR_37_TO_RANGE.inc"

.include "../_helpers/ACCUMULATE_HASH_INTO_VAR37_38.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_ACCUMULATE_HASH_INTO_VAR37_38.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_ACCUMULATE_HASH_INTO_VAR37_38.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_ACCUMULATE_HASH_INTO_VAR37_38.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
SETUP_67_45_VAR01_46_VARB1_NOSIGN:
	mov [SCREEN_NUM], 0x0045
	mov [HERO_X], 0x0046
	and [0xB1], 0x7FFF
	ret


.endif


SETUP_67_67_VAR01_1E_VARBE_3:
	mov [SCREEN_NUM], 0x0067
	mov [HERO_X], 0x001E
	mov [0xBE], 0x0003
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_SETUP_67_67_VAR01_1E_VARBE_3.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_SETUP_67_67_VAR01_1E_VARBE_3.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_SETUP_67_67_VAR01_1E_VARBE_3.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
SETUP_67_25_VAR06_0_VARB1_NOSIGN:
	mov [SCREEN_NUM], 0x0025
	mov [0x06], 0x0000
	and [0xB1], 0x7FFF
	ret


.endif


SETUP_67_4B_VARS_B0_3_01_50_AF_58_B1:
	mov [SCREEN_NUM], 0x004B
	mov [0xB0], 0x0003
	mov [HERO_X], 0x0050
	mov [0xAF], 0x0058
	or [0xB1], 0x0010
	ret


.if BRANCH == "cartridge_1992"
.include "cart__post_SETUP_67_4B_VARS_B0_3_01_50_AF_58_B1.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
SETUP_67_A7_VARS_B0_2_02_5D_01_7F_BE_3:
	mov [SCREEN_NUM], 0x00A7
	mov [0xB0], 0x0002
	mov [HERO_Y], 0x005D
	mov [HERO_X], 0x007F
	mov [0xBE], 0x0003
	or [0xB1], 0x00C0
	ret


.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_SETUP_67_A7_VARS_B0_2_02_5D_01_7F_BE_3.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_SETUP_67_A7_VARS_B0_2_02_5D_01_7F_BE_3.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "cartridge_1992")
INIT_HASH_VARS_67_66_65_68_69:
	mov [SCREEN_NUM], 0x0001
	mov [CACHED_SCREEN_NUM], 0x0001
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


.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_HASH_VARS_67_66_65_68_69.inc"
.endif

CAVES_CREATURE_WALK_RIGHT_INIT:
	mov [0x29], 0x0028
	mov [0x07], 0x00C8
	mov [0x08], 0x000A

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VARS_29_07_08.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_29_07_08.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_29_07_08.inc"
.endif

INCREMENT_VAR07_BY_4:
	add [0x07], 0x0004
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INCREMENT_VAR07_BY_4.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INCREMENT_VAR07_BY_4.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INCREMENT_VAR07_BY_4.inc"
.endif

.include "../_helpers/DERIVE_VAR12_11_10_FROM_VAR9.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DERIVE_VAR12_11_10_FROM_VAR9.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DERIVE_VAR12_11_10_FROM_VAR9.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DERIVE_VAR12_11_10_FROM_VAR9.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_COPY_VAR22_TO_VAR08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_INLINE_COPY_VAR22_TO_VAR08_L0:
	mov [0x27], [0x11]
	and [0x27], 0x0200
	jne [0x27], 0x00, SHARED_RET
	call CAVES_COPY_VAR40_TO_VAR22_L0
	mov [0x08], [0x22]
	ret


CAVES_INLINE_COPY_VAR22_TO_VAR08_L1:
	call CAVES_INLINE_COPY_VAR22_TO_VAR08_L2
	shl [0x0E], 0x000C
	shl [0x0D], 0x000B
	add [0x09], [0x0E]
	add [0x09], [0x0D]
	ret
.endif

.include "../_helpers/SPLIT_VAR09_BITS_INTO_VAR0D.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_SPLIT_VAR09_BITS_INTO_VAR0D.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_SPLIT_VAR09_BITS_INTO_VAR0D.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_SPLIT_VAR09_BITS_INTO_VAR0D.inc"
.endif

.include "../_helpers/AND_VAR11_WITH_EFFF.inc"

.include "../_helpers/INLINE_OR_VAR11_WITH_1000.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_FOLD_BODY_58B_A2D4469A.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_FOLD_BODY_58B_A2D4469A.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_FOLD_BODY_58B_A2D4469A.inc"
.endif

.include "../_helpers/SET_VAR2F_TO_000F.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_SET_VAR2F_TO_000F_L0:
	je [0x12], 0x58, SET_VAR2F_TO_001D
	mov [0x2F], 0x000F
	ret
.endif

.include "../_helpers/SET_VAR2F_TO_001D.inc"

.include "../_helpers/SET_VAR2F_TO_000D.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_SET_VAR2F_TO_000D_L0:
	call CAVES_SET_VAR2F_TO_000D_L1
	jg [0x1D], 0x1D, CAVES_SET_VAR2F_TO_000D_L2
	je [0x12], 0x58, SET_VAR2F_TO_000D
	mov [0x21], [0x07]
	call CAVES_COPY_VAR40_TO_VAR22_L8
	mov [0x25], [0x26]
	mov [0x21], [HERO_X]
	call CAVES_COPY_VAR40_TO_VAR22_L8
	mov [0x24], [0x26]
	jle [0x24], [0x25], CAVES_SET_VAR2F_TO_000D_L2
	mov [0x29], [0x22]
	jl [0x07], [HERO_X], STEP_VAR29_DOWN10_SET_VAR2F_11
	add [0x29], 0x000A
	mov [0x2F], 0x0011
	ret
.endif

.include "../_helpers/STEP_VAR29_DOWN10_SET_VAR2F_11.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_STEP_VAR29_DOWN10_SET_VAR2F_11.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_STEP_VAR29_DOWN10_SET_VAR2F_11.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_STEP_VAR29_DOWN10_SET_VAR2F_11.inc"
.endif

.include "../_helpers/SET_VAR21_TO_0001.inc"

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_SET_VAR21_TO_0001.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_SET_VAR21_TO_0001.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_SET_VAR21_TO_0001.inc"
.endif

.include "../_helpers/INIT_VARS_2F_29_12.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
STATE_VAR12_BIG_DISPATCH_CASE_08:
	mov [0x2B], [0x12]
	and [0x2B], 0x1FFF
	shr [0x2B], 0x0003
	jne [0x2B], 0x01, CAVES_INIT_VARS_2F_29_12_L0
	or [0x12], 0x6000
	mov [0x21], [0x07]
	mov [0x22], [HERO_X]
	call CAVES_COPY_VAR40_TO_VAR22_L8
	jle [0x26], 0x46, INIT_VARS_2F_29_12
	sub [0x26], 0x0046
	mov [0x29], [0x07]
	jg [0x07], [HERO_X], FOLD_BODY_189B_29E88AAE
	add [0x29], [0x26]
	mov [0x2F], 0x0018
	mov [0x2F], 0x0001
	mov [0x29], 0x0000
	ret
.endif

.include "../_helpers/FOLD_BODY_189B_29E88AAE.inc"

