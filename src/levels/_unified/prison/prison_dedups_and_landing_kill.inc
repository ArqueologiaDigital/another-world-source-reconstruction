DEDUP_CAVES_5B_007_001:
	sub [BUDDY_Y], 0x0001
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_PRISON_5B_015.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_PRISON_5B_015.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_PRISON_5B_015.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_255_010.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_INLINE_DRAW_CV_255_010_L0:
	ret


PRISON_INLINE_DRAW_CV_255_010_L1:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	play id=0x0055, freq=0x1C, vol=0x0A, channel=0x01
	sub [BUDDY_Y], 0x0001
	call DRAW_PRISON_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2548, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F05, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, INLINE_DRAW_CV_255_010
	call PRISON_INLINE_DRAW_CV_255_010_L2
	jmp DEDUP_CAVES_5B_020
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_255_010:
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_04, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
.endif


DEDUP_CAVES_5B_020:
	add [BUDDY_Y], 0x0001
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_PRISON_5B_007.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_PRISON_5B_007.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_PRISON_5B_007.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_252_018:
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_03, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_INLINE_DRAW_CV_252_019_L0:
	ret


PRISON_INLINE_DRAW_CV_252_019_L1:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [BUDDY_Y], 0x0001
	call DRAW_PRISON_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2552, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F07, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, DRAW_CV259_AT_X07_Y08
	call PRISON_INLINE_DRAW_CV_252_019_L2
	jmp DEDUP_CAVES_5B_007_002
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV259_AT_X07_Y08.inc"
.endif


DEDUP_CAVES_5B_007_002:
	sub [BUDDY_Y], 0x0001
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_PRISON_5B_016.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_PRISON_5B_016.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_PRISON_5B_016.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV261_AT_X07_Y08.inc"
.endif


DEDUP_CAVES_5B_007_003:
	sub [BUDDY_Y], 0x0001
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_PRISON_5B_017.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_PRISON_5B_017.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_PRISON_5B_017.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_243_012:
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

; Cellmate (BUDDY) animation frame draws CIN_157..169 — split out for clarity (see buddy_animation_frames/cellmate_cin_157_169.inc).
.include "buddy_animation_frames/cellmate_cin_157_169.inc"

.include "../_helpers/DECREMENT_VAR08_BY_D.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DECREMENT_VAR08_BY_D.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DECREMENT_VAR08_BY_D.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DECREMENT_VAR08_BY_D.inc"
.endif

KILL_CHANNEL_LANDING_002:
	killChannel

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_KILL_041.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_KILL_041.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_KILL_041.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV_074:
	video type=0, offset=0x0020, x=[0x01], y=[0x02], zoom=0x40
	ret
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_074_L0:
	je [0x0A], 0x00, DRAW_CV_075
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_075.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_075_L0:
	je [0x0A], 0x00, DRAW_CV_076
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_076.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_076_L0:
	je [0x0A], 0x00, DRAW_CV_077
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_077.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_077_L0:
	je [0x0A], 0x00, DRAW_HERO_WALK_LEFT_F13
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_HERO_WALK_LEFT_F13:
	video type=0, offset=HERO_WALK_LEFT_BODY_F13, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_HERO_WALK_LEFT_DRAW_PHASE_14:
	jne [0x0A], 0x00, PRISON_DRAW_CV_078_L1
	video type=0, offset=HERO_WALK_LEFT_ARM_F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_080

PRISON_DRAW_CV_078_L1:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_080.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_080_L0:
	jne [0x0A], 0x00, PRISON_DRAW_CV_080_L1
	video type=0, offset=HERO_STAND_LEFT_ARM, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_HERO_STAND_LEFT

PRISON_DRAW_CV_080_L1:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01

DRAW_HERO_STAND_LEFT:
	call DRAW_HERO_WATER_DEPTH_LEFT_CASE_00
	video type=0, offset=HERO_STAND_LEFT_BODY, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_WALK_LEFT_DRAW_PHASE_00:
	jne [0x0A], 0x00, PRISON_DRAW_CV_080_L4
	video type=0, offset=HERO_WALK_LEFT_ARM_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_061

PRISON_DRAW_CV_080_L4:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_061.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_HERO_WALK_LEFT_DRAW_PHASE_01:
	jne [0x0A], 0x00, PRISON_DRAW_CV_061_L1
	video type=0, offset=HERO_WALK_LEFT_ARM_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_063

PRISON_DRAW_CV_061_L1:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_063.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_HERO_WALK_LEFT_DRAW_PHASE_02:
	jne [0x0A], 0x00, PRISON_DRAW_CV_063_L1
	video type=0, offset=HERO_WALK_LEFT_ARM_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_065

PRISON_DRAW_CV_063_L1:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_065.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_HERO_WALK_LEFT_DRAW_PHASE_03:
	jne [0x0A], 0x00, PRISON_DRAW_CV_065_L1
	video type=0, offset=HERO_WALK_LEFT_ARM_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_067

PRISON_DRAW_CV_065_L1:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_067.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_HERO_WALK_LEFT_DRAW_PHASE_04:
	jne [0x0A], 0x00, PRISON_DRAW_CV_067_L1
	video type=0, offset=HERO_WALK_LEFT_ARM_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_069

PRISON_DRAW_CV_067_L1:
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_069.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_069_L0:
	je [0x0A], 0x00, DRAW_HERO_WALK_LEFT_F05
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_HERO_WALK_LEFT_F05:
	video type=0, offset=HERO_WALK_LEFT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_070_L0:
	je [0x0A], 0x00, DRAW_CV_071
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_071.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_071_L0:
	call DRAW_HERO_WATER_DEPTH_LEFT_CASE_00
	je [0x0A], 0x00, DRAW_CV_072
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_072.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_072_L0:
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
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x00
	jne [0x0A], 0x00, DRAW_CV_295
	video type=0, offset=HERO_RUN_RIGHT_ARM_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_RUN_RIGHT_POSE_01:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_296
	video type=0, offset=HERO_RUN_RIGHT_ARM_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_RUN_RIGHT_POSE_02:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_299
	video type=0, offset=HERO_RUN_RIGHT_ARM_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_RUN_RIGHT_POSE_03:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_300
	video type=0, offset=HERO_RUN_RIGHT_ARM_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_RUN_RIGHT_POSE_04:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_300
	video type=0, offset=HERO_RUN_RIGHT_ARM_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F05:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x00
	jne [0x0A], 0x00, DRAW_CV_295
	video type=0, offset=HERO_RUN_RIGHT_ARM_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_RUN_RIGHT_POSE_06:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_295
	video type=0, offset=HERO_RUN_RIGHT_ARM_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_RUN_RIGHT_POSE_07:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_296
	video type=0, offset=HERO_RUN_RIGHT_ARM_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_RUN_RIGHT_POSE_08:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_297
	video type=0, offset=HERO_RUN_RIGHT_ARM_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_HERO_RUN_RIGHT_POSE_09:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_297
	video type=0, offset=HERO_RUN_RIGHT_ARM_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_298.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_HERO_RUN_LEFT_DRAW_PHASE_00:
	je [0x0A], 0x00, DRAW_CV107_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV108_PLAY_60_F0F_V2A_C0
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV107_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV108_PLAY_60_F0F_V2A_C0:
	video type=0, offset=HERO_RUN_LEFT_BODY_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x00
	ret


.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_HERO_RUN_LEFT_DRAW_PHASE_01:
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
PRISON_HERO_RUN_LEFT_DRAW_PHASE_02:
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
PRISON_HERO_RUN_LEFT_DRAW_PHASE_03:
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
PRISON_DRAW_CV_114_L0:
	je [0x0A], 0x00, DRAW_CV_115
	call DRAW_CV_298
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_115.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_HERO_RUN_LEFT_DRAW_PHASE_05:
	je [0x0A], 0x00, DRAW_CV097_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV098_PLAY_60_F0F_V2A_C0
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV097_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV098_PLAY_60_F0F_V2A_C0:
	video type=0, offset=HERO_RUN_LEFT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x00
	ret


.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_HERO_RUN_LEFT_DRAW_PHASE_06:
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
PRISON_HERO_RUN_LEFT_DRAW_PHASE_07:
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
PRISON_HERO_RUN_LEFT_DRAW_PHASE_08:
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
PRISON_HERO_RUN_LEFT_DRAW_PHASE_09:
	je [0x0A], 0x00, DRAW_CV105_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV_106
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV105_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV_106:
	video type=0, offset=HERO_RUN_LEFT_BODY_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_106_L0:
	je [0x1F], 0x00, PRISON_DRAW_CV_106_L1
	jl [0x1E], 0x00, INLINE_SET_VAR20_TO_1
	mov [0x20], 0xFFFF

PRISON_DRAW_CV_106_L2:
	sub [0x1E], [0x1F]
	add [0x20], 0x0001
	jge [0x1E], 0x00, PRISON_DRAW_CV_106_L2
	ret
.endif

.include "../_helpers/INLINE_SET_VAR20_TO_1.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_SET_VAR20_TO_1.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_SET_VAR20_TO_1.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_SET_VAR20_TO_1.inc"
.endif

