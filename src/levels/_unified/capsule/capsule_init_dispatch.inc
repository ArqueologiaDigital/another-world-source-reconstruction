INIT_VARS_2F_29_12:
	mov [0x2F], 0x0009
	mov [0x29], 0x0000
	mov [0x12], 0x4010
	ret


.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAPSULE_INIT_VARS_2F_29_12_L0:
	mov [0x2F], 0x000B
	jne [0x0F], 0x00, SHARED_RET
	mov [0x29], 0x0000
	mov [0x2F], 0x0009
	ret


CAPSULE_INIT_VARS_2F_29_12_L1:
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
CAPSULE_INCREMENT_VAR21_BY_F_L0:
	mov [0x22], [HERO_X]
	mov [0xF8], [0x04]
	jge [0xF8], 0x4000, CAPSULE_INCREMENT_VAR21_BY_F_L1
	jl [0xF8], 0x20, CAPSULE_HERO_FRONT_X_APPLY_FACING
	sub [0xF8], 0x0020

CAPSULE_HERO_FRONT_X_APPLY_FACING:
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
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_FOLD_BODY_94B_9F1D7AF8.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_FOLD_BODY_94B_9F1D7AF8.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_FOLD_BODY_94B_9F1D7AF8.inc"
.endif

.include "../_helpers/ADD_VAR2C_TO_VAR22.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAPSULE_ADD_VAR2C_TO_VAR22_L0:
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

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/RET_THEN_KILL_CHANNEL.inc"
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_RET_THEN_KILL_CHANNEL.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_RET_THEN_KILL_CHANNEL.inc"
.endif

.include "../_helpers/MASK_VAR11_NOSIGN_INCR_VAR21_BY_14.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14.inc"
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
CAPSULE_COPY_VAR40_TO_VAR27_L0:
	db 0x11

CAPSULE_SHIELD_SLOT_ENERGY_LOAD_CASE_14:
	jne [0x1D], 0x14, CAPSULE_SHIELD_SLOT_ENERGY_LOAD_CASE_15
	mov [0x11], [0xA1]
	ret


CAPSULE_SHIELD_SLOT_ENERGY_LOAD_CASE_15:
	jne [0x1D], 0x15, CAPSULE_SHIELD_SLOT_ENERGY_LOAD_CASE_16
	mov [0x11], [0xA4]
	ret


CAPSULE_SHIELD_SLOT_ENERGY_LOAD_CASE_16:
	jne [0x1D], 0x16, CAPSULE_SHIELD_SLOT_ENERGY_LOAD_CASE_17
	mov [0x11], [0xA7]
	ret


CAPSULE_SHIELD_SLOT_ENERGY_LOAD_CASE_17:
	jne [0x1D], 0x17, COPY_VARAD_TO_VAR11
	mov [0x11], [0xAA]
	jne [SCREEN_NUM], 0x46, SHARED_RET
	je [0xB4], 0x00, SHARED_RET
	mov [0x11], 0xFFFF
	mov [0xB4], 0x0000
	mov [0x13], 0x0082
	mov [0x21], [0x22]
	call CAPSULE_COPY_VAR40_TO_VAR27_L5
	mov [0x46], 0xF060
	ret
.endif

.include "../_helpers/COPY_VARAD_TO_VAR11.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAPSULE_COPY_VARAD_TO_VAR11_L0:
	db 0x11

CAPSULE_SHIELD_SLOT_ENERGY_STORE_CASE_14:
	jne [0x1D], 0x14, CAPSULE_SHIELD_SLOT_ENERGY_STORE_CASE_15
	mov [0xA1], [0x11]
	ret


CAPSULE_SHIELD_SLOT_ENERGY_STORE_CASE_15:
	jne [0x1D], 0x15, CAPSULE_SHIELD_SLOT_ENERGY_STORE_CASE_16
	mov [0xA4], [0x11]
	ret


CAPSULE_SHIELD_SLOT_ENERGY_STORE_CASE_16:
	jne [0x1D], 0x16, CAPSULE_SHIELD_SLOT_ENERGY_STORE_CASE_17
	mov [0xA7], [0x11]
	ret


CAPSULE_SHIELD_SLOT_ENERGY_STORE_CASE_17:
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

.include "../_helpers/INIT_VAR2B_2C_FROM_VAR01_VAR29_10.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAPSULE_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L0:
	add [0x2B], 0x0002
	mov [0x21], [0x2B]
	mov [0x22], [HERO_Y]
	mov [0x23], 0x0000
	call CAPSULE_FLOOR_LEVEL_SELECT_BY_HEIGHT
	sub [0x22], [HERO_Y]
	jl [0x22], 0x10, SHARED_RET
	sub [0x2C], 0x0002
	mov [0x21], [0x2C]
	mov [0x22], [HERO_Y]
	mov [0x23], 0x0000
	call CAPSULE_FLOOR_LEVEL_SELECT_BY_HEIGHT
	sub [0x22], [HERO_Y]
	sub [0x29], 0x0001
	jl [0x29], 0x00, SHARED_RET
	jge [0x22], 0x10, CAPSULE_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L0
	mov [0x2B], [0x2C]
	ret


CAPSULE_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L2:
	db 0x11

CAPSULE_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L3:
	add [HERO_X], [0x34]
	add [HERO_Y], [0x35]
	call CAPSULE_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L4
	mov [0x0E], [0x34]
	jge [0x0E], 0x00, CAPSULE_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L5
	mov [0x34], 0x0000
	sub [0x34], [0x0E]

CAPSULE_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L5:
	jl [HERO_Y], [0x22], CAPSULE_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L6
	mov [0x10], [0x34]
	mov [0x0D], [HERO_Y]
	sub [0x0D], [0x22]
	mov [HERO_Y], [0x22]
	mov [0xF8], [0x23]
	and [0xF8], 0x0007
	je [0x23], 0x00, CAPSULE_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L6
	jne [0xF8], 0x00, CAPSULE_HERO_LANDING_SURFACE_CASE_01
	mov [0x2B], 0x0000
	mov [0x2C], 0x001C
	mov [0x11], 0x0000
	shr [0x10], 0x0003
	shr [0x0D], 0x0003

CAPSULE_HERO_LANDING_SURFACE_CASE_01:
	jne [0xF8], 0x01, CAPSULE_HERO_LANDING_SURFACE_CASE_02
	mov [0x2B], 0x0000
	mov [0x2C], 0x001C
	mov [0x11], 0x0002
	shr [0x10], 0x0002
	shr [0x0D], 0x0002

CAPSULE_HERO_LANDING_SURFACE_CASE_02:
	jne [0xF8], 0x02, CAPSULE_HERO_LANDING_SURFACE_CASE_03
	mov [0x2B], 0x0005
	mov [0x2C], 0x001A
	mov [0x11], 0x0006
	shr [0x10], 0x0001
	shr [0x0D], 0x0002

CAPSULE_HERO_LANDING_SURFACE_CASE_03:
	jne [0xF8], 0x03, CAPSULE_HERO_LANDING_SURFACE_CASE_04
	mov [0x2B], 0x000A
	mov [0x2C], 0x0014
	mov [0x11], 0x0007

CAPSULE_HERO_LANDING_SURFACE_CASE_04:
	jne [0xF8], 0x04, CAPSULE_HERO_LANDING_SURFACE_CASE_05
	mov [0x2B], 0x0004
	mov [0x2C], 0x0008
	mov [0x11], 0x0005
	mov [0x10], 0x0008

CAPSULE_HERO_LANDING_SURFACE_CASE_05:
	jne [0xF8], 0x05, CAPSULE_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L12
	mov [0x2B], 0x0001
	mov [0x2C], 0x0004
	mov [0x11], 0x0005
	mov [0x10], 0x0008

CAPSULE_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L12:
	mov [0xF8], [0x23]
	and [0xF8], 0x0008
	sub [0x34], 0x0004
	add [0x11], [0x0D]
	je [0xF8], 0x00, CAPSULE_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L13
	jg [0x0E], 0x00, ADD_VAR11_TO_VAR34
	jmp CAPSULE_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L14

CAPSULE_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L13:
	jl [0x0E], 0x00, ADD_VAR11_TO_VAR34

CAPSULE_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L14:
	sub [0x34], [0x11]
	jmp CAPSULE_INIT_VAR2B_2C_FROM_VAR01_VAR29_10_L15
.endif

.include "../_helpers/ADD_VAR11_TO_VAR34.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_ADD_VAR11_TO_VAR34.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_ADD_VAR11_TO_VAR34.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_ADD_VAR11_TO_VAR34.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV139_AT_X01_Y02:
	video type=0, offset=HERO_CRAWL_POSE_10, x=[HERO_X], y=[HERO_Y], zoom=0x40
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_DRAW_CV139_AT_X01_Y02.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CV139_AT_X01_Y02.inc"
.endif

.include "../_helpers/COPY_VAR40_TO_VAR22.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_COPY_VAR40_TO_VAR22.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_COPY_VAR40_TO_VAR22.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_COPY_VAR40_TO_VAR22.inc"
.endif

.include "../_helpers/DECREMENT_VARF8_BY_10.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAPSULE_HERO_LEDGE_DROP_TOLERANCE:
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
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_COPY_VAR01_TO_VAR28.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_COPY_VAR01_TO_VAR28.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_COPY_VAR01_TO_VAR28.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV204_AT_X07_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_DRAW_CV204_AT_X07_Y08_L0:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F00, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call BUDDY_RIGHT_SUBFRAME_3_DISPATCH
	call CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L1
	ret


CAPSULE_DRAW_CV204_AT_X07_Y08_L1:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV204_AT_X07_PLUS1_Y08
	call CAPSULE_DRAW_CV204_AT_X07_Y08_L2
	jmp CAPSULE_BUDDY_WALK_LEFT_DRAW_1_DONE
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV204_AT_X07_PLUS1_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_BUDDY_WALK_LEFT_DRAW_1_DONE:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F01, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call BUDDY_RIGHT_SUBFRAME_3_DISPATCH
	call CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L1
	ret


CAPSULE_BUDDY_WALK_LEFT_DRAW_2:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L3
	call DRAW_CV_304_THEN_305

CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L3:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F02, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call BUDDY_RIGHT_SUBFRAME_3_DISPATCH
	call CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L4
	ret


CAPSULE_BUDDY_WALK_LEFT_DRAW_3:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	je [0x0D], 0x00, DRAW_FIGURE_WALK_LEFT_F03
	call DRAW_CV_304_THEN_305

DRAW_FIGURE_WALK_LEFT_F03:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F03, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call BUDDY_RIGHT_SUBFRAME_3_DISPATCH
	call CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L7
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	ret


CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L8:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, CAPSULE_BUDDY_WALK_LEFT_DRAW_4_DONE
	call DRAW_CV_304_THEN_305

CAPSULE_BUDDY_WALK_LEFT_DRAW_4_DONE:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F04, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call BUDDY_RIGHT_SUBFRAME_3_DISPATCH
	call CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L10
	ret


CAPSULE_BUDDY_WALK_LEFT_DRAW_5:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L12
	call CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L13
	jmp CAPSULE_BUDDY_WALK_LEFT_DRAW_5_DONE

CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L12:
	video type=0, offset=CV_FIGURE_WALK_LEFT_LIMB_POSE_01, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

CAPSULE_BUDDY_WALK_LEFT_DRAW_5_DONE:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F05, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call BUDDY_RIGHT_SUBFRAME_3_DISPATCH
	call CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L15
	ret


CAPSULE_BUDDY_WALK_LEFT_DRAW_6:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L17
	call CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L18
	jmp CAPSULE_BUDDY_WALK_LEFT_DRAW_6_DONE

CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L17:
	video type=0, offset=CV_FIGURE_WALK_LEFT_LIMB_POSE_02, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

CAPSULE_BUDDY_WALK_LEFT_DRAW_6_DONE:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F06, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call BUDDY_RIGHT_SUBFRAME_3_DISPATCH
	call CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L20
	ret


CAPSULE_BUDDY_WALK_LEFT_DRAW_7:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV224_AT_X07_Y08
	call CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L22
	jmp CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L23
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV224_AT_X07_Y08.inc"
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_DRAW_CV224_AT_X07_Y08.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CV224_AT_X07_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV263_AT_X07_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_ACTOR_RUN_LEFT_DRAW_0_DONE:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F00, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call CAPSULE_DRAW_CV263_AT_X07_Y08_L1
	add [BUDDY_Y], 0x0001
	ret


CAPSULE_DRAW_CV263_AT_X07_Y08_L2:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, CAPSULE_DRAW_CV263_AT_X07_Y08_L3
	call CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L18
	jmp CAPSULE_DRAW_CV263_AT_X07_Y08_L4

CAPSULE_DRAW_CV263_AT_X07_Y08_L3:
	video type=0, offset=CV_FIGURE_RUN_LEFT_LIMB_POSE_01, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

CAPSULE_DRAW_CV263_AT_X07_Y08_L4:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F01, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call CAPSULE_DRAW_CV263_AT_X07_Y08_L5
	ret


CAPSULE_DRAW_CV263_AT_X07_Y08_L6:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [BUDDY_Y], 0x0001
	je [0x0D], 0x00, CAPSULE_DRAW_CV263_AT_X07_Y08_L7
	call DRAW_CV_304_THEN_305
	jmp CAPSULE_ACTOR_RUN_LEFT_DRAW_2_DONE

CAPSULE_DRAW_CV263_AT_X07_Y08_L7:
	video type=0, offset=CV_FIGURE_RUN_LEFT_LIMB_POSE_02, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

CAPSULE_ACTOR_RUN_LEFT_DRAW_2_DONE:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F02, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call CAPSULE_DRAW_CV263_AT_X07_Y08_L9
	sub [BUDDY_Y], 0x0001
	ret


CAPSULE_ACTOR_RUN_LEFT_DRAW_3:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	add [BUDDY_Y], 0x0001
	je [0x0D], 0x00, CAPSULE_DRAW_CV263_AT_X07_Y08_L11
	call DRAW_CV_304_THEN_305
	jmp CAPSULE_ACTOR_RUN_LEFT_DRAW_3_DONE

CAPSULE_DRAW_CV263_AT_X07_Y08_L11:
	video type=0, offset=CV_FIGURE_RUN_LEFT_LIMB_POSE_03, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

CAPSULE_ACTOR_RUN_LEFT_DRAW_3_DONE:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F03, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call CAPSULE_DRAW_CV263_AT_X07_Y08_L13
	sub [BUDDY_Y], 0x0001
	ret


CAPSULE_BUDDY_RUN_LEFT_DRAW_4:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV275_AT_X07_Y08
	call DRAW_CV_304_THEN_305
	jmp CAPSULE_DRAW_CV263_AT_X07_Y08_L15
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV275_AT_X07_Y08.inc"
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_DRAW_CV275_AT_X07_Y08.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CV275_AT_X07_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV246_AT_X07_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_DRAW_CV246_AT_X07_Y08_L0:
	ret


CAPSULE_ACTOR_RUN_RIGHT_DRAW_2:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	add [BUDDY_Y], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_RIGHT_LIMB_POSE_02, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F02, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, DRAW_CV249_AT_X07_Y08
	call CAPSULE_DRAW_CV246_AT_X07_Y08_L2
	jmp CAPSULE_DRAW_CV246_AT_X07_Y08_L3
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV249_AT_X07_Y08.inc"
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_DRAW_CV249_AT_X07_Y08.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CV249_AT_X07_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV259_AT_X07_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_DRAW_CV259_AT_X07_Y08_L0:
	sub [BUDDY_Y], 0x0001
	ret


CAPSULE_ACTOR_RUN_RIGHT_DRAW_8:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [BUDDY_Y], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_RIGHT_LIMB_POSE_02, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F08, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, DRAW_CV261_AT_X07_Y08
	call CAPSULE_DRAW_CV259_AT_X07_Y08_L2
	jmp CAPSULE_DRAW_CV259_AT_X07_Y08_L3
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV261_AT_X07_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_DRAW_CV259_AT_X07_Y08_L3:
	sub [BUDDY_Y], 0x0001
	ret


CAPSULE_DRAW_CV261_AT_X07_Y08_L0:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_RIGHT_LIMB_POSE_01, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F09, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	sub [BUDDY_X], 0x0001
	je [0x0D], 0x00, CAPSULE_DRAW_CV261_AT_X07_Y08_L1
	call CAPSULE_DRAW_CV261_AT_X07_Y08_L2
	jmp INCREMENT_VAR07_BY_1

CAPSULE_DRAW_CV261_AT_X07_Y08_L1:
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_00, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
.endif

.include "../_helpers/INCREMENT_VAR07_BY_1.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INCREMENT_VAR07_BY_1.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INCREMENT_VAR07_BY_1.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INCREMENT_VAR07_BY_1.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_355.inc"
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_DRAW_CV_355.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CV_355.inc"
.endif

.include "../_helpers/DECREMENT_VAR08_BY_D.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DECREMENT_VAR08_BY_D.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DECREMENT_VAR08_BY_D.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DECREMENT_VAR08_BY_D.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_DRAW_HERO_WALK_LEFT_BODY_F09:
	video type=0, offset=0x0020, x=[0x01], y=[0x02], zoom=0x40
	ret
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_WALK_LEFT_DRAW_10:
	je [0x0A], 0x00, DRAW_CV_075
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_075.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_WALK_LEFT_DRAW_11:
	je [0x0A], 0x00, DRAW_CV_076
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_076.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_WALK_LEFT_DRAW_12:
	je [0x0A], 0x00, DRAW_CV_077
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_077.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_WALK_LEFT_DRAW_13:
	je [0x0A], 0x00, CAPSULE_HERO_WALK_LEFT_FOOTSTEP_PHASE_2
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_WALK_LEFT_FOOTSTEP_PHASE_2:
	video type=0, offset=HERO_WALK_LEFT_BODY_F13, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x01
	ret


.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_WALK_LEFT_DRAW_14:
	jne [0x0A], 0x00, CAPSULE_HERO_WALK_LEFT_DRAW_14_GUN_RAISED
	video type=0, offset=HERO_WALK_LEFT_ARM_F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_080

CAPSULE_HERO_WALK_LEFT_DRAW_14_GUN_RAISED:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_080.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_DRAW_CV_080_L0:
	jne [0x0A], 0x00, CAPSULE_DRAW_CV_080_L1
	video type=0, offset=HERO_STAND_LEFT_ARM, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp CAPSULE_DRAW_CV_080_L2

CAPSULE_DRAW_CV_080_L1:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

CAPSULE_DRAW_CV_080_L2:
	call DRAW_HERO_WATER_DEPTH_LEFT_CASE_00
	video type=0, offset=HERO_STAND_LEFT_BODY, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAPSULE_HERO_WALK_LEFT_DRAW_0:
	jne [0x0A], 0x00, CAPSULE_HERO_WALK_LEFT_DRAW_0_GUN_RAISED
	video type=0, offset=HERO_WALK_LEFT_ARM_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_061

CAPSULE_HERO_WALK_LEFT_DRAW_0_GUN_RAISED:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_061.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_WALK_LEFT_DRAW_1:
	jne [0x0A], 0x00, CAPSULE_HERO_WALK_LEFT_DRAW_1_GUN_RAISED
	video type=0, offset=HERO_WALK_LEFT_ARM_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_063

CAPSULE_HERO_WALK_LEFT_DRAW_1_GUN_RAISED:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_063.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_WALK_LEFT_DRAW_2:
	jne [0x0A], 0x00, CAPSULE_HERO_WALK_LEFT_DRAW_2_GUN_RAISED
	video type=0, offset=HERO_WALK_LEFT_ARM_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_065

CAPSULE_HERO_WALK_LEFT_DRAW_2_GUN_RAISED:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_065.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_WALK_LEFT_DRAW_3:
	jne [0x0A], 0x00, CAPSULE_HERO_WALK_LEFT_DRAW_3_GUN_RAISED
	video type=0, offset=HERO_WALK_LEFT_ARM_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_067

CAPSULE_HERO_WALK_LEFT_DRAW_3_GUN_RAISED:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_067.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_WALK_LEFT_DRAW_4:
	jne [0x0A], 0x00, CAPSULE_HERO_WALK_LEFT_DRAW_4_GUN_RAISED
	video type=0, offset=HERO_WALK_LEFT_ARM_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_069

CAPSULE_HERO_WALK_LEFT_DRAW_4_GUN_RAISED:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_069.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_WALK_LEFT_DRAW_5:
	je [0x0A], 0x00, DRAW_HERO_WALK_LEFT_F05
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_HERO_WALK_LEFT_F05:
	video type=0, offset=HERO_WALK_LEFT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x20, channel=0x01
	ret


.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_WALK_LEFT_DRAW_6:
	je [0x0A], 0x00, DRAW_CV_071
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_071.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_DRAW_CV_071_L0:
	call DRAW_HERO_WATER_DEPTH_LEFT_CASE_00
	je [0x0A], 0x00, DRAW_CV_072
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_072.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_WALK_LEFT_DRAW_8:
	je [0x0A], 0x00, DRAW_CV_073
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_073.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_300.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_299.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_295.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_296.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_297.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_RUN_RIGHT_FOOTSTEP_PHASE_1:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x01
	jne [0x0A], 0x00, DRAW_CV_295
	video type=0, offset=HERO_RUN_RIGHT_ARM_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAPSULE_HERO_RUN_RIGHT_DRAW_1:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_296
	video type=0, offset=HERO_RUN_RIGHT_ARM_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAPSULE_HERO_RUN_RIGHT_DRAW_2:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_299
	video type=0, offset=HERO_RUN_RIGHT_ARM_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAPSULE_HERO_RUN_RIGHT_DRAW_3:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_300
	video type=0, offset=HERO_RUN_RIGHT_ARM_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAPSULE_HERO_RUN_RIGHT_DRAW_4:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_300
	video type=0, offset=HERO_RUN_RIGHT_ARM_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAPSULE_HERO_RUN_RIGHT_FOOTSTEP_PHASE_2:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0A, vol=0x2A, channel=0x01
	jne [0x0A], 0x00, DRAW_CV_295
	video type=0, offset=HERO_RUN_RIGHT_ARM_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAPSULE_HERO_RUN_RIGHT_DRAW_6:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_295
	video type=0, offset=HERO_RUN_RIGHT_ARM_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAPSULE_DRAW_CV_297_L7:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_296
	video type=0, offset=HERO_RUN_RIGHT_ARM_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAPSULE_HERO_RUN_RIGHT_DRAW_8:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_297
	video type=0, offset=HERO_RUN_RIGHT_ARM_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAPSULE_HERO_RUN_RIGHT_DRAW_9:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_297
	video type=0, offset=HERO_RUN_RIGHT_ARM_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_298.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_RUN_LEFT_DRAW_0:
	je [0x0A], 0x00, DRAW_CV107_AT_X01_Y02
	call DRAW_CV_298
	jmp CAPSULE_HERO_RUN_LEFT_FOOTSTEP_PHASE_1
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV107_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_RUN_LEFT_FOOTSTEP_PHASE_1:
	video type=0, offset=HERO_RUN_LEFT_BODY_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x01
	ret


.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_RUN_LEFT_DRAW_1:
	je [0x0A], 0x00, DRAW_CV109_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV_110
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV109_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_110.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_RUN_LEFT_DRAW_2:
	je [0x0A], 0x00, DRAW_CV111_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV_112
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV111_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_112.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_RUN_LEFT_DRAW_3:
	je [0x0A], 0x00, DRAW_CV113_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV_114
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV113_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_114.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_RUN_LEFT_DRAW_4:
	je [0x0A], 0x00, DRAW_CV_115
	call DRAW_CV_298
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_115.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_RUN_LEFT_DRAW_5:
	je [0x0A], 0x00, DRAW_CV097_AT_X01_Y02
	call DRAW_CV_298
	jmp CAPSULE_HERO_RUN_LEFT_FOOTSTEP_PHASE_2
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV097_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_RUN_LEFT_FOOTSTEP_PHASE_2:
	video type=0, offset=HERO_RUN_LEFT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0A, vol=0x2A, channel=0x01
	ret


.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_RUN_LEFT_DRAW_6:
	je [0x0A], 0x00, DRAW_CV099_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV_100
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV099_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_100.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_RUN_LEFT_DRAW_7:
	je [0x0A], 0x00, DRAW_CV101_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV_102
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV101_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_102.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_RUN_LEFT_DRAW_8:
	je [0x0A], 0x00, DRAW_CV103_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV_104
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV103_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_104.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_HERO_RUN_LEFT_DRAW_9:
	je [0x0A], 0x00, DRAW_CV105_AT_X01_Y02
	call DRAW_CV_298
	jmp CAPSULE_DRAW_HERO_RUN_LEFT_BODY_F09
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV105_AT_X01_Y02.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_DRAW_HERO_RUN_LEFT_BODY_F09:
	video type=0, offset=HERO_RUN_LEFT_BODY_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


	je [0x1F], 0x00, CAPSULE_DRAW_CV105_AT_X01_Y02_L0
	jl [0x1E], 0x00, INLINE_SET_VAR20_TO_1
	mov [0x20], 0xFFFF

CAPSULE_DRAW_CV105_AT_X01_Y02_L1:
	sub [0x1E], [0x1F]
	add [0x20], 0x0001
	jge [0x1E], 0x00, CAPSULE_DRAW_CV105_AT_X01_Y02_L1
	ret
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_SET_VAR20_TO_1.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_INLINE_SET_VAR20_TO_1_L0:
	add [0x1E], [0x1F]
	sub [0x20], 0x0001
	jle [0x1E], 0x00, CAPSULE_INLINE_SET_VAR20_TO_1_L0

CAPSULE_DRAW_CV105_AT_X01_Y02_L0:
	ret


	killChannel
	jne [SCREEN_NUM], [0x65], SHELVE_BACKDROP_TO_PAGE3
	copyVideoPage src=0x03, dst=0xFF
	copyVideoPage src=0x00, dst=0x03
	copyVideoPage src=0xFF, dst=0x00
	mov [SCREEN_NUM], [0x65]
	mov [0x65], [CACHED_SCREEN_NUM]
	mov [CACHED_SCREEN_NUM], [SCREEN_NUM]
	jmp CAPSULE_SHELVE_BACKDROP_TO_PAGE3_L0
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/SHELVE_BACKDROP_TO_PAGE3.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_SHELVE_BACKDROP_TO_PAGE3_L0:
	ret


CAPSULE_SHELVE_BACKDROP_TO_PAGE3_L1:
	jg [HERO_Y], [0x51], COPY_VAR51_TO_VAR02_KILL_CHANNEL
	add [HERO_Y], 0x0001
	break
.endif

.include "../_helpers/COPY_VAR51_TO_VAR02_KILL_CHANNEL.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_COPY_VAR51_TO_VAR02_KILL_CHANNEL.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_COPY_VAR51_TO_VAR02_KILL_CHANNEL.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_COPY_VAR51_TO_VAR02_KILL_CHANNEL.inc"
.endif

.include "../_helpers/COPY_VAR52_TO_VAR02_KILL_CHANNEL.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_COPY_VAR52_TO_VAR02_KILL_CHANNEL.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_COPY_VAR52_TO_VAR02_KILL_CHANNEL.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_COPY_VAR52_TO_VAR02_KILL_CHANNEL.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_03_32_02_1:
	mov [0x03], 0x0006
	mov [0x32], 0x0001
	mov [HERO_Y], 0x00DC
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_03_32_02_1.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_03_32_02_1.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_03_32_02:
	mov [0x03], 0x0006
	mov [0x32], 0x0001
	mov [HERO_Y], 0x0000
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_03_32_02.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_03_32_02.inc"
.endif

.include "../_helpers/RESET_HERO_ACTION_KEEP_POS_4LSB.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_RESET_HERO_ACTION_KEEP_POS_4LSB.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_RESET_HERO_ACTION_KEEP_POS_4LSB.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_RESET_HERO_ACTION_KEEP_POS_4LSB.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_ADD_VAR50_BY_C:
	add [0x50], 0x000C
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_INLINE_ADD_VAR50_BY_C.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_ADD_VAR50_BY_C.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_SUB_VAR50_BY_C:
	sub [0x50], 0x000C
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAPSULE_INLINE_SUB_VAR50_BY_C_L0:
	ret


CAPSULE_INLINE_SUB_VAR50_BY_C_L1:
	db 0x11

CAPSULE_INLINE_SUB_VAR50_BY_C_L2:
	call CAPSULE_INLINE_SUB_VAR50_BY_C_L3
	break
	jmp CAPSULE_INLINE_SUB_VAR50_BY_C_L2

CAPSULE_INLINE_SUB_VAR50_BY_C_L3:
	mov [0x50], 0x002F
	mov [0x51], 0xFFCE
	mov [0x52], 0x0055
	jl [HERO_X], 0x64, SHARED_RET
	mov [0x50], 0x00B4
	mov [0x51], 0x0055
	mov [0x52], 0x0118
	ret
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INIT_HASH_VARS_A9_TO_AD:
	mov [0xA9], 0x010B
	mov [0xAC], 0x0115
	and [0xAD], 0x01FF
	or [0xAA], 0x0100
	or [0xAD], 0x0100
	mov [0xAB], 0x00AA
	mov [0xAE], 0x00AA
	or [0xAB], 0x8000
	or [0xAE], 0x8000
	ret


.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_INIT_HASH_VARS_A9_TO_AD.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_HASH_VARS_A9_TO_AD.inc"
.endif

