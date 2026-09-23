DEDUP_CAVES_6B_001:
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_CAVES_6B_002.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_CAVES_6B_002.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_CAVES_6B_002.inc"
.endif

.include "../_helpers/SHARED_RET.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_SHARED_RET.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_SHARED_RET.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_SHARED_RET.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV204_AT_X07_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_FIGURE_WALK_LEFT_F00:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F00, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_SUBFRAME_3_VAR09
	call CAVES_DRAW_CV204_AT_X07_Y08_L1
	ret


CAVES_DRAW_CV204_AT_X07_Y08_L2:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV204_AT_X07_PLUS1_Y08
	call CAVES_DRAW_CV204_AT_X07_Y08_L3
	jmp CAVES_DRAW_CV204_AT_X07_Y08_L4
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV204_AT_X07_PLUS1_Y08.inc"
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_DRAW_CV204_AT_X07_PLUS1_Y08.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CV204_AT_X07_PLUS1_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_216_027.inc"
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_INLINE_DRAW_CV_216_029.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_DRAW_CV_216_029.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_220_008.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_FIGURE_WALK_LEFT_F06:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F06, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_SUBFRAME_3_VAR09
	call CAVES_INLINE_DRAW_CV_220_016_L1
	ret


CAVES_INLINE_DRAW_CV_220_016_L2:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV224_AT_X07_Y08
	call CAVES_INLINE_DRAW_CV_220_016_L3
	jmp DRAW_FIGURE_WALK_LEFT_F07
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV224_AT_X07_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_FIGURE_WALK_LEFT_F07:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F07, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_SUBFRAME_3_VAR09
	call CAVES_DRAW_CV224_AT_X07_Y08_L1
	ret


CAVES_DRAW_CV224_AT_X07_Y08_L2:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, INLINE_DRAW_CV_228_018__HELPER
	call CAVES_DRAW_CV224_AT_X07_Y08_L3
	jmp DRAW_FIGURE_WALK_LEFT_F08
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_228_018.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_FIGURE_WALK_LEFT_F08:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F08, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_SUBFRAME_3_VAR09
	call CAVES_INLINE_DRAW_CV_228_018_L0
	ret


CAVES_INLINE_DRAW_CV_228_018_L1:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, INLINE_DRAW_CV_228_018
	call CAVES_DRAW_CV224_AT_X07_Y08_L3
	jmp DRAW_FIGURE_WALK_LEFT_F09
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_228_018:
	video type=0, offset=CV_FIGURE_WALK_LEFT_LIMB_POSE_03, x=[0x07], y=[0x08], zoom=0x40
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_FIGURE_WALK_LEFT_F09:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F09, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_SUBFRAME_3_VAR09
	add [0x07], 0x0001
	call CAVES_INLINE_DRAW_CV_228_018_L0
	sub [0x07], 0x0001
	ret


CAVES_INLINE_DRAW_CV_228_019_L0:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, INLINE_DRAW_CV_220_008
	call CAVES_INLINE_DRAW_CV_220_016_L3
	jmp DRAW_FIGURE_WALK_LEFT_F10
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_220_008:
	video type=0, offset=CV_FIGURE_WALK_LEFT_LIMB_POSE_02, x=[0x07], y=[0x08], zoom=0x40
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_FIGURE_WALK_LEFT_F10:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F10, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_SUBFRAME_3_VAR09
	call CAVES_INLINE_DRAW_CV_220_016_L1
	ret


CAVES_INLINE_DRAW_CV_220_017_L1:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	je [0x0D], 0x00, INLINE_DRAW_CV_216_027
	call CAVES_INLINE_DRAW_CV_220_016_L3
	jmp DRAW_FIGURE_WALK_LEFT_F11
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_216_027:
	video type=0, offset=CV_FIGURE_WALK_LEFT_LIMB_POSE_01, x=[0x07], y=[0x08], zoom=0x40
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_INLINE_DRAW_CV_216_030.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_DRAW_CV_216_030.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV263_AT_X07_Y08.inc"
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_DRAW_CV263_AT_X07_Y08.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CV263_AT_X07_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_266_005.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_INLINE_DRAW_CV_266_005_L0:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F01, x=[0x07], y=[0x08], zoom=0x40
	call CAVES_INLINE_DRAW_CV_266_005_L1
	ret


CAVES_ACTOR_RUN_LEFT_PHASE_3_FRAME:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, INLINE_DRAW_CV_269_024__HELPER
	call DRAW_CV_304_THEN_305
	jmp CAVES_ACTOR_RUN_LEFT_PHASE_3_DONE
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_269_024.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_ACTOR_RUN_LEFT_PHASE_3_DONE:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F02, x=[0x07], y=[0x08], zoom=0x40
	call CAVES_INLINE_DRAW_CV_269_024_L0
	sub [0x08], 0x0001
	ret


CAVES_ACTOR_RUN_LEFT_PHASE_4_FRAME:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, INLINE_DRAW_CV_272_003__HELPER
	call DRAW_CV_304_THEN_305
	jmp CAVES_ACTOR_RUN_LEFT_PHASE_4_DONE
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_272_003.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_ACTOR_RUN_LEFT_PHASE_4_DONE:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F03, x=[0x07], y=[0x08], zoom=0x40
	call CAVES_INLINE_DRAW_CV_272_013_L0
	sub [0x08], 0x0001
	ret


CAVES_INLINE_DRAW_CV_272_013_L1:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV275_AT_X07_Y08
	call DRAW_CV_304_THEN_305
	jmp CAVES_INLINE_DRAW_CV_272_013_L2
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
INLINE_DRAW_CV_272_003_001:
	video type=0, offset=CV_31EC, x=[0x07], y=[0x08], zoom=0x40
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_INLINE_DRAW_CV_272_014.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_DRAW_CV_272_014.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_272_003_002:
	video type=0, offset=CV_31EC, x=[0x07], y=[0x08], zoom=0x40
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_INLINE_DRAW_CV_272_015_L0:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F06, x=[0x07], y=[0x08], zoom=0x40
	call CAVES_INLINE_DRAW_CV_272_013_L0
	ret


CAVES_ACTOR_RUN_LEFT_PHASE_8_FRAME:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, INLINE_DRAW_CV_269_024_001
	call CAVES_INLINE_DRAW_CV_220_016_L3
	jmp CAVES_ACTOR_RUN_LEFT_PHASE_8_DONE
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_269_024_001:
	video type=0, offset=CV_31F6, x=[0x07], y=[0x08], zoom=0x40
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_ACTOR_RUN_LEFT_PHASE_8_DONE:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F07, x=[0x07], y=[0x08], zoom=0x40
	call CAVES_INLINE_DRAW_CV_269_025_L1
	sub [0x08], 0x0001
	ret


CAVES_ACTOR_RUN_LEFT_PHASE_9_FRAME:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, INLINE_DRAW_CV_269_024_002
	call CAVES_DRAW_CV224_AT_X07_Y08_L3
	jmp CAVES_ACTOR_RUN_LEFT_PHASE_9_DONE
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_269_024_002:
	video type=0, offset=CV_31F6, x=[0x07], y=[0x08], zoom=0x40
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_ACTOR_RUN_LEFT_PHASE_9_DONE:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F08, x=[0x07], y=[0x08], zoom=0x40
	call CAVES_INLINE_DRAW_CV_269_026_L0
	sub [0x08], 0x0001
	ret


CAVES_INLINE_DRAW_CV_269_026_L1:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, INLINE_DRAW_CV_266_005
	call CAVES_INLINE_DRAW_CV_220_016_L3
	jmp CAVES_INLINE_DRAW_CV_269_026_L2
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_266_005:
	video type=0, offset=CV_3200, x=[0x07], y=[0x08], zoom=0x40
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_INLINE_DRAW_CV_266_006.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_DRAW_CV_266_006.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_243_012.inc"
.endif


.include "../_helpers/DEDUP_CAVES_5B_020.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_CAVES_5B_020.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_CAVES_5B_020.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_CAVES_5B_020.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV246_AT_X07_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_DRAW_CV246_AT_X07_Y08_L0:
	ret


CAVES_ACTOR_RUN_RIGHT_PHASE_3_FRAME:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x08], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_RIGHT_LIMB_POSE_02, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F02, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, DRAW_CV249_AT_X07_Y08
	call CAVES_DRAW_CV246_AT_X07_Y08_L2
	jmp DEDUP_CAVES_5B_007__HELPER
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV249_AT_X07_Y08.inc"
.endif


.include "../_helpers/DEDUP_CAVES_5B_007.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_CAVES_5B_007.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_CAVES_5B_007.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_CAVES_5B_007.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_252_018.inc"
.endif


DEDUP_CAVES_5B_007_001:
	sub [0x08], 0x0001
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_CAVES_5B_008.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_CAVES_5B_008.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_CAVES_5B_008.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_255_010.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_INLINE_DRAW_CV_255_031_L0:
	ret


CAVES_ACTOR_RUN_RIGHT_PHASE_6_FRAME:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [0x08], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_RIGHT_LIMB_POSE_03, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F05, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, INLINE_DRAW_CV_255_010
	call CAVES_INLINE_DRAW_CV_255_031_L2
	jmp DEDUP_CAVES_5B_020
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_255_010:
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_04, x=[0x07], y=[0x08], zoom=0x40
.endif


DEDUP_CAVES_5B_020:
	add [0x08], 0x0001
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_CAVES_5B_021.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_CAVES_5B_021.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_CAVES_5B_021.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_252_018:
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_03, x=[0x07], y=[0x08], zoom=0x40
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_INLINE_DRAW_CV_252_023_L0:
	ret


CAVES_ACTOR_RUN_RIGHT_PHASE_8_FRAME:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x08], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_RIGHT_LIMB_POSE_02, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F07, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, DRAW_CV259_AT_X07_Y08
	call CAVES_DRAW_CV_355_L9
	jmp DEDUP_CAVES_5B_007_002
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV259_AT_X07_Y08.inc"
.endif


DEDUP_CAVES_5B_007_002:
	sub [0x08], 0x0001
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_CAVES_5B_009.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_CAVES_5B_009.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_CAVES_5B_009.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV261_AT_X07_Y08.inc"
.endif


DEDUP_CAVES_5B_007_003:
	sub [0x08], 0x0001
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_CAVES_5B_010.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_CAVES_5B_010.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_CAVES_5B_010.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_243_012:
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_00, x=[0x07], y=[0x08], zoom=0x40
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
DRAW_HERO_POSE_0_0:
	video type=0, offset=CV_1C78, x=[0x07], y=[0x08], zoom=0x40
	ret


.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_DRAW_CV_301.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CV_301.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_355.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_DRAW_CV_355_L0:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=CV_FIGURE_CROUCH_FACING_LEFT, x=[0x07], y=[0x08], zoom=0x40
	call CAVES_DRAW_CV_355_L1
	ret


CAVES_DRAW_CV_355_L2:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=CV_4324, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x0001
	call CAVES_DRAW_CV_355_L3
	add [0x08], 0x0001
	add [0x07], 0x0001
	ret


CAVES_DRAW_CV_355_L4:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=CV_FIGURE_CROUCH_FACING_LEFT, x=[0x07], y=[0x08], zoom=0x40
	call CAVES_DRAW_CV_355_L5
	ret


CAVES_DRAW_CV_355_L6:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=CV_FIGURE_CROUCH_FACING_LEFT, x=[0x07], y=[0x08], zoom=0x40
	call CAVES_DRAW_CV_355_L3
	ret


CAVES_DRAW_CV_355_L7:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=CV_FIGURE_CROUCH_FACING_LEFT, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	je [0x0D], 0x00, CAVES_DRAW_CV_355_L8
	call CAVES_DRAW_CV_355_L9
	jmp DECREMENT_VAR08_BY_D

CAVES_DRAW_CV_355_L8:
	call CAVES_DRAW_CV_355_L10
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
CAVES_DRAW_HERO_WALK_LEFT_BODY_F09:
	video type=0, offset=0x0020, x=[0x01], y=[0x02], zoom=0x40
	ret
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_DRAW_CV_074_L0:
	je [0x0A], 0x00, DRAW_CV_075
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_075.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_DRAW_CV_075_L0:
	je [0x0A], 0x00, DRAW_CV_076
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_076.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_DRAW_CV_076_L0:
	je [0x0A], 0x00, DRAW_CV_077
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_077.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_DRAW_CV_077_L0:
	je [0x0A], 0x00, DRAW_HERO_WALK_LEFT_F13
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_HERO_WALK_LEFT_F13:
	video type=0, offset=HERO_WALK_LEFT_BODY_F13, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x01
	ret


.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_HERO_WALK_LEFT_STRIDE_PHASE_15:
	jne [0x0A], 0x00, CAVES_DRAW_CV078_PLAY_60_F0B_V22_C1_L1
	video type=0, offset=HERO_WALK_LEFT_ARM_F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_080

CAVES_DRAW_CV078_PLAY_60_F0B_V22_C1_L1:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_080.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_DRAW_CV_080_L0:
	jne [0x0A], 0x00, CAVES_DRAW_CV_080_L1
	video type=0, offset=HERO_STAND_LEFT_ARM, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp CAVES_DRAW_CV_080_L2

CAVES_DRAW_CV_080_L1:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

CAVES_DRAW_CV_080_L2:
	call CAVES_HERO_WATER_DEPTH_SPRITE_LEFT_CASE_00
	video type=0, offset=HERO_STAND_LEFT_BODY, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAVES_HERO_WALK_LEFT_STRIDE_PHASE_1:
	jne [0x0A], 0x00, CAVES_DRAW_CV_080_L4
	video type=0, offset=HERO_WALK_LEFT_ARM_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_061

CAVES_DRAW_CV_080_L4:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_061.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_HERO_WALK_LEFT_STRIDE_PHASE_2:
	jne [0x0A], 0x00, CAVES_DRAW_CV_061_L1
	video type=0, offset=HERO_WALK_LEFT_ARM_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_063

CAVES_DRAW_CV_061_L1:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_063.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_HERO_WALK_LEFT_STRIDE_PHASE_3:
	jne [0x0A], 0x00, CAVES_DRAW_CV_063_L1
	video type=0, offset=HERO_WALK_LEFT_ARM_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_065

CAVES_DRAW_CV_063_L1:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_065.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_HERO_WALK_LEFT_STRIDE_PHASE_4:
	jne [0x0A], 0x00, CAVES_DRAW_CV_065_L1
	video type=0, offset=HERO_WALK_LEFT_ARM_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_067

CAVES_DRAW_CV_065_L1:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_067.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_HERO_WALK_LEFT_STRIDE_PHASE_5:
	jne [0x0A], 0x00, CAVES_DRAW_CV_067_L1
	video type=0, offset=HERO_WALK_LEFT_ARM_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_069

CAVES_DRAW_CV_067_L1:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_069.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_DRAW_CV_069_L0:
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
CAVES_DRAW_CV070_PLAY_60_F14_V20_C1_L0:
	je [0x0A], 0x00, DRAW_CV_071
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_071.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_DRAW_CV_071_L0:
	call CAVES_HERO_WATER_DEPTH_SPRITE_LEFT_CASE_00
	je [0x0A], 0x00, DRAW_CV_072
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_072.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_DRAW_CV_072_L0:
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
DRAW_HERO_RUN_RIGHT_F00:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x01
	jne [0x0A], 0x00, DRAW_CV_295
	video type=0, offset=HERO_RUN_RIGHT_ARM_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F01:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_296
	video type=0, offset=HERO_RUN_RIGHT_ARM_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F02:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_299
	video type=0, offset=HERO_RUN_RIGHT_ARM_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F03:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_300
	video type=0, offset=HERO_RUN_RIGHT_ARM_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F04:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_300
	video type=0, offset=HERO_RUN_RIGHT_ARM_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F05:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0A, vol=0x2A, channel=0x01
	jne [0x0A], 0x00, DRAW_CV_295
	video type=0, offset=HERO_RUN_RIGHT_ARM_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F06:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_295
	video type=0, offset=HERO_RUN_RIGHT_ARM_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F07:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_296
	video type=0, offset=HERO_RUN_RIGHT_ARM_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F08:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_297
	video type=0, offset=HERO_RUN_RIGHT_ARM_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F09:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_297
	video type=0, offset=HERO_RUN_RIGHT_ARM_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_298.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_HERO_RUN_LEFT_DRAW_PHASE_1:
	je [0x0A], 0x00, DRAW_CV107_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV108_PLAY_60_F0F_V2A_C1
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV107_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV108_PLAY_60_F0F_V2A_C1:
	video type=0, offset=HERO_RUN_LEFT_BODY_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x01
	ret


.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_HERO_RUN_LEFT_DRAW_PHASE_2:
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
CAVES_HERO_RUN_LEFT_DRAW_PHASE_3:
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
CAVES_HERO_RUN_LEFT_DRAW_PHASE_4:
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
CAVES_DRAW_CV_114_L0:
	je [0x0A], 0x00, DRAW_CV_115
	call DRAW_CV_298
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_115.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_HERO_RUN_LEFT_DRAW_PHASE_6:
	je [0x0A], 0x00, DRAW_CV097_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV098_PLAY_60_F0A_V2A_C1
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV097_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV098_PLAY_60_F0A_V2A_C1:
	video type=0, offset=HERO_RUN_LEFT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0A, vol=0x2A, channel=0x01
	ret


.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_HERO_RUN_LEFT_DRAW_PHASE_7:
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
CAVES_HERO_RUN_LEFT_DRAW_PHASE_8:
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
CAVES_HERO_RUN_LEFT_DRAW_PHASE_9:
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
CAVES_HERO_RUN_LEFT_DRAW_PHASE_10:
	je [0x0A], 0x00, DRAW_CV105_AT_X01_Y02
	call DRAW_CV_298
	jmp CAVES_DRAW_HERO_RUN_LEFT_BODY_F09
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV105_AT_X01_Y02.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_DRAW_HERO_RUN_LEFT_BODY_F09:
	video type=0, offset=HERO_RUN_LEFT_BODY_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


	je [0x1F], 0x00, CAVES_DRAW_CV105_AT_X01_Y02_L0
	jl [0x1E], 0x00, INLINE_SET_VAR20_TO_1
	mov [0x20], 0xFFFF

CAVES_DRAW_CV105_AT_X01_Y02_L1:
	sub [0x1E], [0x1F]
	add [0x20], 0x0001
	jge [0x1E], 0x00, CAVES_DRAW_CV105_AT_X01_Y02_L1
	ret
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_SET_VAR20_TO_1.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_INLINE_SET_VAR20_TO_1_L0:
	add [0x1E], [0x1F]
	sub [0x20], 0x0001
	jle [0x1E], 0x00, CAVES_INLINE_SET_VAR20_TO_1_L0

CAVES_DRAW_CV105_AT_X01_Y02_L0:
	ret


	killChannel
	jne [SCREEN_NUM], [0x65], SHELVE_BACKDROP_TO_PAGE3
	copyVideoPage src=0x03, dst=0xFF
	copyVideoPage src=0x00, dst=0x03
	copyVideoPage src=0xFF, dst=0x00
	mov [SCREEN_NUM], [0x65]
	mov [0x65], [CACHED_SCREEN_NUM]
	mov [CACHED_SCREEN_NUM], [SCREEN_NUM]
	jmp CAVES_SHELVE_BACKDROP_TO_PAGE3_L0
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/SHELVE_BACKDROP_TO_PAGE3.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
CAVES_SHELVE_BACKDROP_TO_PAGE3_L0:
	ret


CAVES_SHELVE_BACKDROP_TO_PAGE3_L1:
	jg [HERO_Y], [0x51], COPY_VAR51_TO_VAR02_KILL_CHANNEL
	add [HERO_Y], 0x0001
	break
	jmp CAVES_SHELVE_BACKDROP_TO_PAGE3_L1
.endif

.include "../_helpers/COPY_VAR51_TO_VAR02_KILL_CHANNEL.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_TELEPORT_DOWN_SETTLE_LOOP:
	jg [HERO_Y], [0x52], COPY_VAR52_TO_VAR02_KILL_CHANNEL
	add [HERO_Y], 0x0001
	break
	jmp CAVES_TELEPORT_DOWN_SETTLE_LOOP
.endif

.include "../_helpers/COPY_VAR52_TO_VAR02_KILL_CHANNEL.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_COPY_VAR52_TO_VAR02_KILL_CHANNEL.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_COPY_VAR52_TO_VAR02_KILL_CHANNEL.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_COPY_VAR52_TO_VAR02_KILL_CHANNEL.inc"
.endif

.include "../_helpers/RESET_HERO_ACTION_KEEP_POS_4LSB.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_RESET_HERO_ACTION_KEEP_POS_4LSB.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_RESET_HERO_ACTION_KEEP_POS_4LSB.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_RESET_HERO_ACTION_KEEP_POS_4LSB.inc"
.endif

.include "../_helpers/INLINE_SUB_VAR50_BY_14.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_SUB_VAR50_BY_14.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_SUB_VAR50_BY_14.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_SUB_VAR50_BY_14.inc"
.endif

