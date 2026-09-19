INIT_VARS_2F_29_12:
	mov [0x2F], 0x0009
	mov [0x29], 0x0000
	mov [0x12], 0x4010
	ret


.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_INIT_VARS_2F_29_12_L0:
	mov [0x2F], 0x000B
	jne [0x0F], 0x00, SHARED_RET
	mov [0x29], 0x0000
	mov [0x2F], 0x0009
	ret


CAVES_COPY_VAR40_TO_VAR22_L8:
	jg [0x21], [0x22], COMPUTE_VAR26_AS_VAR21_MINUS_VAR22
	mov [0x26], [0x22]
	sub [0x26], [0x21]
	ret
.endif

.include "../_helpers/COMPUTE_VAR26_AS_VAR21_MINUS_VAR22.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_COMPUTE_VAR26_AS_VAR21_MINUS_VAR22.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_COMPUTE_VAR26_AS_VAR21_MINUS_VAR22.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_COMPUTE_VAR26_AS_VAR21_MINUS_VAR22.inc"
.endif

.include "../_helpers/INCREMENT_VAR21_BY_F.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_INCREMENT_VAR21_BY_F_L0:
	mov [0x22], [HERO_X]
	mov [0xF8], [0x04]
	jge [0xF8], 0x4000, CAVES_INCREMENT_VAR21_BY_F_L1
	jl [0xF8], 0x20, CAVES_HERO_FRONT_PROBE_X_BY_FACING
	sub [0xF8], 0x0020

CAVES_HERO_FRONT_PROBE_X_BY_FACING:
	jl [0xF8], 0x10, INLINE_SUB_VAR22_BY_23
	add [0x22], 0x0023
	ret
.endif

.include "../_helpers/INLINE_SUB_VAR22_BY_23.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_SUB_VAR22_BY_23.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_SUB_VAR22_BY_23.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_SUB_VAR22_BY_23.inc"
.endif

.include "../_helpers/INLINE_OR_VAR2B_WITH_4000.inc"

.include "../_helpers/SET_VARS_07_08.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_FOLD_BODY_94B_9F1D7AF8_L0:
	db 0x11

CAVES_FOLD_BODY_94B_9F1D7AF8_L1:
	mov [0x09], 0x0000
	call CAVES_FOLD_BODY_94B_9F1D7AF8_L2
	mov [0x1D], 0x0000
	call CAVES_COPY_VAR01_TO_VAR28_L3
	je [0x1D], 0x00, CAVES_FOLD_BODY_94B_9F1D7AF8_L3
	jl [0x2B], 0x4000, CAVES_FOLD_BODY_94B_9F1D7AF8_L4
	and [0x2B], 0x3FFF
	jmp CAVES_FOLD_BODY_94B_9F1D7AF8_L3

CAVES_FOLD_BODY_94B_9F1D7AF8_L4:
	or [0x2B], 0x4000
	jmp CAVES_FOLD_BODY_94B_9F1D7AF8_L3

CAVES_FOLD_BODY_94B_9F1D7AF8_L3:
	mov [0x07], [0x22]
	mov [0x08], [0x40]
	mov [0x22], [0x21]
	add [0x21], 0x000C
	sub [0x22], 0x000C
	call CAVES_FOLD_BODY_94B_9F1D7AF8_L5
	call CAVES_FOLD_BODY_94B_9F1D7AF8_L6
	jl [0x1D], 0x1E, CAVES_FOLD_BODY_94B_9F1D7AF8_L7
	mov [0x09], 0x0001
	mov [0x07], [0x22]
	jne [0x1D], 0x1E, CAVES_GRENADE_HIT_ACTOR_SLOT
	call CAVES_FOLD_BODY_94B_9F1D7AF8_L9

CAVES_GRENADE_HIT_ACTOR_SLOT:
	jl [0x1D], 0x28, CAVES_FOLD_BODY_94B_9F1D7AF8_L7
	call CAVES_FOLD_BODY_94B_9F1D7AF8_L10

CAVES_FOLD_BODY_94B_9F1D7AF8_L7:
	ret


CAVES_FOLD_BODY_94B_9F1D7AF8_L11:
	db 0x11

CAVES_FOLD_BODY_94B_9F1D7AF8_L2:
	mov [0x22], [0x21]
	mov [0x2C], [0x2B]
	mov [0xF8], [0x2B]
	and [0x2C], 0x00FF
	jl [0xF8], 0x4000, ADD_VAR2C_TO_VAR22
	sub [0x22], [0x2C]
	jmp CAVES_ADD_VAR2C_TO_VAR22_L0
.endif

.include "../_helpers/ADD_VAR2C_TO_VAR22.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_ADD_VAR2C_TO_VAR22_L0:
	and [0xF8], 0x1000
	mov [0x27], [0x44]
	jne [0xF8], 0x00, COPY_VAR27_TO_VAR07
	mov [0x27], [0x40]
.endif

.include "../_helpers/COPY_VAR27_TO_VAR07.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_COPY_VAR27_TO_VAR07.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_COPY_VAR27_TO_VAR07.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_COPY_VAR27_TO_VAR07.inc"
.endif

.include "../_helpers/SET_VAR13_TO_FFFF.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_SET_VAR13_TO_FFFF.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_SET_VAR13_TO_FFFF.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_SET_VAR13_TO_FFFF.inc"
.endif

PLAY_SFX_005C_CH00:
	play id=0x005C, freq=0x19, vol=0x40, channel=0x00
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_PLAY_SFX_005C_CH00.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_PLAY_SFX_005C_CH00.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_PLAY_SFX_005C_CH00.inc"
.endif

.include "../_helpers/MASK_VAR11_NOSIGN_INCR_VAR21_BY_14.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14_L0:
	call CAVES_BARRIER_STATE_STORE_CASE_0A
	call CAVES_BARRIER_STATE_PERSIST_CASE_4E
	mov [0xF8], [0x11]
	and [0xF8], 0x0007
	jne [0xF8], 0x06, CAVES_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14_L3
	mov [0x13], 0x006F
	call CAVES_BARRIER_BREACH_EVENT_CASE_8A

CAVES_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14_L3:
	mov [0xF8], [0x11]
	and [0xF8], 0x03FF
	jg [0xF8], 0x7F, CAVES_LASER_IMPACT_ANIM_DISPATCH_BY_DIRECTION
	mov [0xF8], [0x0E]
	mov [0x0E], 0x0000
	je [0x2C], 0x01, CAVES_LASER_IMPACT_ANIM_DISPATCH_BY_DIRECTION
	mov [0x0E], 0x0001

CAVES_LASER_IMPACT_ANIM_DISPATCH_BY_DIRECTION:
	je [0x2C], 0x01, CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT
	jmp CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT
CAVES_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14_L8:
	db 0x05

CAVES_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14_L9:
	mov [0x2B], [0x21]
	mov [0x2C], [0x22]
	sub [0x2C], [0x21]
	jl [0x21], [0x22], INLINE_ADD_VAR2C_BY_1
	mov [0x2B], [0x22]
	mov [0x2C], [0x21]
	sub [0x2C], [0x22]
.endif

.include "../_helpers/INLINE_ADD_VAR2C_BY_1.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_ADD_VAR2C_BY_1.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_ADD_VAR2C_BY_1.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_ADD_VAR2C_BY_1.inc"
.endif

.include "../_helpers/COPY_VAR40_TO_VAR27.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_COPY_VAR40_TO_VAR27_L0:
	db 0x11

CAVES_SHIELD_ENERGY_LOAD_CASE_14:
	jne [0x1D], 0x14, CAVES_SHIELD_ENERGY_LOAD_CASE_15
	mov [0x11], [0xA1]
	ret


CAVES_SHIELD_ENERGY_LOAD_CASE_15:
	jne [0x1D], 0x15, CAVES_SHIELD_ENERGY_LOAD_CASE_16
	mov [0x11], [0xA4]
	ret


CAVES_SHIELD_ENERGY_LOAD_CASE_16:
	jne [0x1D], 0x16, CAVES_SHIELD_ENERGY_LOAD_CASE_17
	mov [0x11], [0xA7]
	ret


CAVES_SHIELD_ENERGY_LOAD_CASE_17:
	jne [0x1D], 0x17, COPY_VARAD_TO_VAR11
	mov [0x11], [0xAA]
	jne [SCREEN_NUM], 0x46, SHARED_RET
	je [0xB4], 0x00, SHARED_RET
	mov [0x11], 0xFFFF
	mov [0xB4], 0x0000
	mov [0x13], 0x0082
	mov [0x21], [0x22]
	call CAVES_COPY_VAR40_TO_VAR27_L5
	mov [0x46], 0xF060
	ret
.endif

.include "../_helpers/COPY_VARAD_TO_VAR11.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_COPY_VARAD_TO_VAR11_L0:
	db 0x11

CAVES_SHIELD_ENERGY_STORE_CASE_14:
	jne [0x1D], 0x14, CAVES_SHIELD_ENERGY_STORE_CASE_15
	mov [0xA1], [0x11]
	ret


CAVES_SHIELD_ENERGY_STORE_CASE_15:
	jne [0x1D], 0x15, CAVES_SHIELD_ENERGY_STORE_CASE_16
	mov [0xA4], [0x11]
	ret


CAVES_SHIELD_ENERGY_STORE_CASE_16:
	jne [0x1D], 0x16, CAVES_SHIELD_ENERGY_STORE_CASE_17
	mov [0xA7], [0x11]
	ret


CAVES_SHIELD_ENERGY_STORE_CASE_17:
	jne [0x1D], 0x17, COPY_VAR11_TO_VARAD
	mov [0xAA], [0x11]
	ret
.endif

.include "../_helpers/COPY_VAR11_TO_VARAD.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_COPY_VAR11_TO_VARAD.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_COPY_VAR11_TO_VARAD.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_COPY_VAR11_TO_VARAD.inc"
.endif

.include "../_helpers/DECREMENT_VAR22.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DECREMENT_VAR22.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DECREMENT_VAR22.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DECREMENT_VAR22.inc"
.endif

.include "../_helpers/COMPUTE_VAR22_AS_VAR40_MINUS_28.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_COMPUTE_VAR22_AS_VAR40_MINUS_28.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_COMPUTE_VAR22_AS_VAR40_MINUS_28.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_COMPUTE_VAR22_AS_VAR40_MINUS_28.inc"
.endif

.include "../_helpers/DEDUP_CAVES_5B_003.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_CAVES_5B_003.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_CAVES_5B_003.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_CAVES_5B_003.inc"
.endif

DEDUP_CAVES_5B_003__CAVES_INLINE_SETTERS_AND_INIT:
	mov [0x0F], 0x0000
	killChannel

.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_DEDUP_CAVES_5B_004_L0:
	call CAVES_DEDUP_CAVES_5B_004_L1
	jg [0x22], [0x21], COMPUTE_VARF8_AS_VAR22_MINUS_VAR09
	mov [0xF8], [0x09]
	sub [0xF8], [0x22]
	jmp CAVES_LASER_SHOT_RANGE_FALLOFF_GATE
.endif

.include "../_helpers/COMPUTE_VARF8_AS_VAR22_MINUS_VAR09.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_COMPUTE_VARF8_AS_VAR22_MINUS_VAR09.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_COMPUTE_VARF8_AS_VAR22_MINUS_VAR09.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_COMPUTE_VARF8_AS_VAR22_MINUS_VAR09.inc"
.endif

.include "../_helpers/INLINE_COPY_VAR44_TO_VAR25.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_COPY_VAR44_TO_VAR25.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_COPY_VAR44_TO_VAR25.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_COPY_VAR44_TO_VAR25.inc"
.endif

.include "../_helpers/DEDUP_CAVES_6B_001.inc"
.if BRANCH in ("chahi_amiga_1991", "dos_1992")
.include "amiga_dos__post_DEDUP_CAVES_6B_001.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_CAVES_6B_001.inc"
.endif

.include "../_helpers/INIT_VAR2B_2C_FROM_VAR01_VAR29_10.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L0:
	add [0x2B], 0x0002
	mov [0x21], [0x2B]
	mov [0x22], [HERO_Y]
	mov [0x23], 0x0000
	call CAVES_GROUND_MAP_DISPATCH
	sub [0x22], [HERO_Y]
	jl [0x22], 0x10, SHARED_RET
	sub [0x2C], 0x0002
	mov [0x21], [0x2C]
	mov [0x22], [HERO_Y]
	mov [0x23], 0x0000
	call CAVES_GROUND_MAP_DISPATCH
	sub [0x22], [HERO_Y]
	sub [0x29], 0x0001
	jl [0x29], 0x00, SHARED_RET
	jge [0x22], 0x10, CAVES_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L0
	mov [0x2B], [0x2C]
	ret


CAVES_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L1:
	db 0x11

CAVES_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L2:
	add [HERO_X], [0x34]
	add [HERO_Y], [0x35]
	call CAVES_COPY_VAR40_TO_VAR22_L3
	mov [0x0E], [0x34]
	jge [0x0E], 0x00, CAVES_HERO_LANDING_SURFACE_DISPATCH
	mov [0x34], 0x0000
	sub [0x34], [0x0E]

CAVES_HERO_LANDING_SURFACE_DISPATCH:
	jl [HERO_Y], [0x22], CAVES_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L4
	mov [0x10], [0x34]
	mov [0x0D], [HERO_Y]
	sub [0x0D], [0x22]
	mov [HERO_Y], [0x22]
	mov [0xF8], [0x23]
	and [0xF8], 0x0007
	je [0x23], 0x00, CAVES_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L4
	jne [0xF8], 0x00, CAVES_HERO_LANDING_SURFACE_CASE_01
	mov [0x2B], 0x0000
	mov [0x2C], 0x001C
	mov [0x11], 0x0000
	shr [0x10], 0x0003
	shr [0x0D], 0x0003

CAVES_HERO_LANDING_SURFACE_CASE_01:
	jne [0xF8], 0x01, CAVES_HERO_LANDING_SURFACE_CASE_02
	mov [0x2B], 0x0000
	mov [0x2C], 0x001C
	mov [0x11], 0x0002
	shr [0x10], 0x0002
	shr [0x0D], 0x0002

CAVES_HERO_LANDING_SURFACE_CASE_02:
	jne [0xF8], 0x02, CAVES_HERO_LANDING_SURFACE_CASE_03
	mov [0x2B], 0x0005
	mov [0x2C], 0x001A
	mov [0x11], 0x0006
	shr [0x10], 0x0001
	shr [0x0D], 0x0002

CAVES_HERO_LANDING_SURFACE_CASE_03:
	jne [0xF8], 0x03, CAVES_HERO_LANDING_SURFACE_CASE_04
	mov [0x2B], 0x000A
	mov [0x2C], 0x0014
	mov [0x11], 0x0007

CAVES_HERO_LANDING_SURFACE_CASE_04:
	jne [0xF8], 0x04, CAVES_HERO_LANDING_SURFACE_CASE_05
	mov [0x2B], 0x0004
	mov [0x2C], 0x0008
	mov [0x11], 0x0005
	mov [0x10], 0x0008

CAVES_HERO_LANDING_SURFACE_CASE_05:
	jne [0xF8], 0x05, CAVES_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L10
	mov [0x2B], 0x0001
	mov [0x2C], 0x0004
	mov [0x11], 0x0005
	mov [0x10], 0x0008

CAVES_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L10:
	mov [0xF8], [0x23]
	and [0xF8], 0x0008
	sub [0x34], 0x0004
	add [0x11], [0x0D]
	je [0xF8], 0x00, CAVES_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L11
	jg [0x0E], 0x00, ADD_VAR11_TO_VAR34
	jmp CAVES_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L12

CAVES_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L11:
	jl [0x0E], 0x00, ADD_VAR11_TO_VAR34

CAVES_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L12:
	sub [0x34], [0x11]
	jmp CAVES_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L13
.endif

.include "../_helpers/ADD_VAR11_TO_VAR34.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_ADD_VAR11_TO_VAR34.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_ADD_VAR11_TO_VAR34.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_ADD_VAR11_TO_VAR34.inc"
.endif

.include "../_helpers/COPY_VAR40_TO_VAR22.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_COPY_VAR40_TO_VAR22_L0:
	mov [0x21], [0x07]
	mov [0x22], [0x08]
	mov [0x23], 0x0000
	mov [0x24], [SCREEN_NUM]
	mov [SCREEN_NUM], [0x10]
	call CAVES_GROUND_MAP_DISPATCH
	mov [SCREEN_NUM], [0x24]
	ret


CAVES_COPY_VAR40_TO_VAR22_L2:
	mov [0xF8], [0x32]
	and [0xF8], 0x0001
	jne [0xF8], 0x00, SHARED_RET
	call CAVES_COPY_VAR40_TO_VAR22_L3
	mov [0xF8], [0x04]
	and [0xF8], 0x0004
	je [0xF8], 0x00, CAVES_COPY_VAR40_TO_VAR22_L4
	jl [HERO_Y], [0x22], SHARED_RET
	jmp CAVES_COPY_VAR40_TO_VAR22_L5

CAVES_COPY_VAR40_TO_VAR22_L4:
	mov [0xF8], [0x22]
	sub [0xF8], [HERO_Y]
	call CAVES_STAND_GAP_ALLOWANCE_BY_SCREEN
	jl [0xF8], 0x10, CAVES_COPY_VAR40_TO_VAR22_L5
	jg [0x63], 0x02, CAVES_COPY_VAR40_TO_VAR22_L7
	jne [HERO_POS_LEFT_RIGHT], 0x00, CAVES_COPY_VAR40_TO_VAR22_L7
	call INIT_VAR2B_2C_FROM_VAR01_VAR29_10
	mov [0x21], [HERO_X]
	mov [0x22], [0x2B]
	call CAVES_COPY_VAR40_TO_VAR22_L8
	jg [0x26], 0x0A, CAVES_COPY_VAR40_TO_VAR22_L7
	mov [HERO_X], [0x2B]
	call CAVES_COPY_VAR40_TO_VAR22_L3
	jmp CAVES_COPY_VAR40_TO_VAR22_L5

CAVES_COPY_VAR40_TO_VAR22_L7:
	call CAVES_COPY_VAR40_TO_VAR22_L9
	jne [SCREEN_NUM], 0x25, SHARED_RET
	setup channel=0x14, address=CAVES_COPY_VAR40_TO_VAR22_L10
	ret


CAVES_COPY_VAR40_TO_VAR22_L5:
	mov [HERO_Y], [0x22]
	mov [0xF8], [0x23]
	and [0xF8], 0x0010
	je [0xF8], 0x00, SHARED_RET
	je [0x63], 0x05, SHARED_RET
	je [0x63], 0x06, SHARED_RET
	je [0x63], 0x64, SHARED_RET
	mov [0x34], 0xFFF6
	mov [0xF8], [0x23]
	and [0xF8], 0x0008
	je [0xF8], 0x00, CAVES_COPY_VAR40_TO_VAR22_L11
	mov [0x34], 0x0004

CAVES_COPY_VAR40_TO_VAR22_L11:
	mov [0x35], 0x0006
	setup channel=0x14, address=CAVES_COPY_VAR40_TO_VAR22_L12
	ret


CAVES_COPY_VAR40_TO_VAR22_L13:
	db 0x11

CAVES_STAND_GAP_ALLOWANCE_BY_SCREEN:
	je [SCREEN_NUM], 0x88, DECREMENT_VARF8_BY_10
	je [SCREEN_NUM], 0x89, DECREMENT_VARF8_BY_10
	ret
.endif

.include "../_helpers/DECREMENT_VARF8_BY_10.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_LEDGE_PROBE_ALLOWANCE_BY_SCREEN:
	je [SCREEN_NUM], 0x88, DECREMENT_VAR22_BY_10
	je [SCREEN_NUM], 0x89, DECREMENT_VAR22_BY_10
	ret
.endif

.include "../_helpers/DECREMENT_VAR22_BY_10.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DECREMENT_VAR22_BY_10.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DECREMENT_VAR22_BY_10.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DECREMENT_VAR22_BY_10.inc"
.endif

.include "../_helpers/COPY_VAR01_TO_VAR28.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_COPY_VAR01_TO_VAR28_L0:
	mov [0x21], [0x28]
	sub [0x22], [0x2A]
	call CAVES_COPY_VAR01_TO_VAR28_L1
	add [0x22], [0x2A]
	jle [0x22], [HERO_X], COPY_VAR01_TO_VAR28
	mov [HERO_X], [0x22]
	mov [0x28], [HERO_X]
	ret


CAVES_COPY_VAR01_TO_VAR28_L2:
	db 0x11

CAVES_COPY_VAR01_TO_VAR28_L3:
	mov [0x23], 0x0000
	jg [0x27], [0x44], CAVES_COPY_VAR01_TO_VAR28_L1
	mov [0x23], 0x0001

CAVES_COPY_VAR01_TO_VAR28_L1:
	jl [0x22], [0x21], CAVES_OBSTACLE_SWEEP_LEFTWARD
	je [0x23], 0x00, CAVES_COPY_VAR01_TO_VAR28_L5
	jg [0x47], [0x22], CAVES_COPY_VAR01_TO_VAR28_L6
	mov [0x22], [0x47]
	mov [0x1D], 0x0004
	jmp CAVES_COPY_VAR01_TO_VAR28_L6

CAVES_COPY_VAR01_TO_VAR28_L5:
	jg [0x43], [0x22], CAVES_COPY_VAR01_TO_VAR28_L6
	mov [0x22], [0x43]
	mov [0x1D], 0x0002

CAVES_COPY_VAR01_TO_VAR28_L6:
	mov [0x24], [0x48]
	mov [0x25], [0x49]
	mov [0x1C], 0x000A
	call CAVES_BARRIER_HIT_TEST_RIGHTWARD
	mov [0x24], [0x4A]
	mov [0x25], [0x4B]
	mov [0x1C], 0x000B
	call CAVES_BARRIER_HIT_TEST_RIGHTWARD
	mov [0x24], [0x4C]
	mov [0x25], [0x4D]
	mov [0x1C], 0x000C
	call CAVES_BARRIER_HIT_TEST_RIGHTWARD
	ret


CAVES_OBSTACLE_SWEEP_LEFTWARD:
	je [0x23], 0x00, CAVES_COPY_VAR01_TO_VAR28_L8
	jl [0x46], [0x22], CAVES_COPY_VAR01_TO_VAR28_L9
	mov [0x22], [0x46]
	mov [0x1D], 0x0003
	jmp CAVES_COPY_VAR01_TO_VAR28_L9

CAVES_COPY_VAR01_TO_VAR28_L8:
	jl [0x42], [0x22], CAVES_COPY_VAR01_TO_VAR28_L9
	mov [0x22], [0x42]
	mov [0x1D], 0x0001

CAVES_COPY_VAR01_TO_VAR28_L9:
	mov [0x24], [0x48]
	mov [0x25], [0x49]
	mov [0x1C], 0x000A
	call CAVES_BARRIER_HIT_TEST_LEFTWARD
	mov [0x24], [0x4A]
	mov [0x25], [0x4B]
	mov [0x1C], 0x000B
	call CAVES_BARRIER_HIT_TEST_LEFTWARD
	mov [0x24], [0x4C]
	mov [0x25], [0x4D]
	mov [0x1C], 0x000C
	call CAVES_BARRIER_HIT_TEST_LEFTWARD
	ret


CAVES_BARRIER_HIT_TEST_LEFTWARD:
	jge [0x25], 0x2000, CAVES_COPY_VAR01_TO_VAR28_L11
	jge [0x25], 0x1000, CAVES_COPY_VAR01_TO_VAR28_L12
	je [0x23], 0x01, CAVES_COPY_VAR01_TO_VAR28_L11
	jmp CAVES_COPY_VAR01_TO_VAR28_L13

CAVES_COPY_VAR01_TO_VAR28_L12:
	sub [0x25], 0x1000
	je [0x23], 0x00, CAVES_COPY_VAR01_TO_VAR28_L11

CAVES_COPY_VAR01_TO_VAR28_L13:
	add [0x24], 0x0008
	jl [0x25], 0x0200, CAVES_COPY_VAR01_TO_VAR28_L14
	sub [0x25], 0x0200
	jg [0x24], [0x21], CAVES_COPY_VAR01_TO_VAR28_L11
	jl [0x24], [0x22], CAVES_COPY_VAR01_TO_VAR28_L14
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

CAVES_COPY_VAR01_TO_VAR28_L14:
	add [0x24], 0x000A
	jl [0x25], 0x0100, CAVES_COPY_VAR01_TO_VAR28_L15
	sub [0x25], 0x0100
	jg [0x24], [0x21], CAVES_COPY_VAR01_TO_VAR28_L11
	jl [0x24], [0x22], CAVES_COPY_VAR01_TO_VAR28_L15
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

CAVES_COPY_VAR01_TO_VAR28_L15:
	add [0x24], 0x000A
	jl [0x25], 0x80, CAVES_COPY_VAR01_TO_VAR28_L11
	sub [0x25], 0x0080
	jg [0x24], [0x21], CAVES_COPY_VAR01_TO_VAR28_L11
	jl [0x24], [0x22], CAVES_COPY_VAR01_TO_VAR28_L11
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

CAVES_COPY_VAR01_TO_VAR28_L11:
	ret


CAVES_BARRIER_HIT_TEST_RIGHTWARD:
	jge [0x25], 0x2000, CAVES_COPY_VAR01_TO_VAR28_L16
	jge [0x25], 0x1000, CAVES_COPY_VAR01_TO_VAR28_L17
	je [0x23], 0x01, CAVES_COPY_VAR01_TO_VAR28_L16
	jmp CAVES_BARRIER_SEGMENT_SCAN_RIGHTWARD

CAVES_COPY_VAR01_TO_VAR28_L17:
	sub [0x25], 0x1000
	je [0x23], 0x00, CAVES_COPY_VAR01_TO_VAR28_L16

CAVES_BARRIER_SEGMENT_SCAN_RIGHTWARD:
	jl [0x25], 0x0200, CAVES_COPY_VAR01_TO_VAR28_L19
	jl [0x24], [0x21], CAVES_COPY_VAR01_TO_VAR28_L19
	jg [0x24], [0x22], CAVES_COPY_VAR01_TO_VAR28_L19
	jmp DEDUP_CAVES_6B_001

CAVES_COPY_VAR01_TO_VAR28_L19:
	add [0x24], 0x000A
	jl [0x25], 0x0100, CAVES_COPY_VAR01_TO_VAR28_L20
	jl [0x24], [0x21], CAVES_COPY_VAR01_TO_VAR28_L20
	jg [0x24], [0x22], CAVES_COPY_VAR01_TO_VAR28_L20
	jmp DEDUP_CAVES_6B_001

CAVES_COPY_VAR01_TO_VAR28_L20:
	add [0x24], 0x000A
	jl [0x25], 0x80, CAVES_COPY_VAR01_TO_VAR28_L16
	jl [0x24], [0x21], CAVES_COPY_VAR01_TO_VAR28_L16
	jg [0x24], [0x22], CAVES_COPY_VAR01_TO_VAR28_L16
.endif

