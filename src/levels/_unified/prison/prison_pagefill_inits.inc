INIT_VARS_16_17:
	mov [0x16], 0x0007
	mov [0x17], 0x0023

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VARS_16_17.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_16_17.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_16_17.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_WAKE_CLOSEUP_PUPIL_WIDEST:
	video offset=CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_2, x=[0x1a], y=[0x1b]
.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_CIN657_AT_X1A_Y1B.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CIN657_AT_X1A_Y1B.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
INLINE_DRAW_CIN_659_AT_160_100:
	video offset=CINEMATIC_659, x=160, y=100
.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_DRAW_CIN_659_AT_160_100.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_DRAW_CIN_659_AT_160_100.inc"
.endif

FILL_PFF_PLAY_SFX_0061_AT_C0D45EFA:
	fill page=0xFF, color=0x00
	play id=0x0061, freq=0x0A, vol=0x0A, channel=0x00
	break
	mov [0x14], 0x00A0
	mov [0x17], 0x00A1
	mov [0x16], 0x0006
	mov [PAUSE_SLICES], 0x0007

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_FOLD_BODY_338B_C0D45EFA.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_FOLD_BODY_338B_C0D45EFA.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_FOLD_BODY_338B_C0D45EFA.inc"
.endif

SET_PAL_07_FILL_TWO_PAGES_86243111:
	setPalette 0x07
	fill page=0x00, color=0x00
	fill page=0xFF, color=0x00
	mov [0x15], 0x0005
	mov [0x16], 0x0003
	mov [PAUSE_SLICES], 0x0008

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_FOLD_BODY_275B_86243111.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_FOLD_BODY_275B_86243111.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_FOLD_BODY_275B_86243111.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_PRISON_BUDDY_POSE_0_0:
	video offset=CINEMATIC_236, x=[BUDDY_X], y=[BUDDY_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_PRISON_BUDDY_POSE_0_1:
	video offset=CINEMATIC_237, x=[BUDDY_X], y=[BUDDY_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_PRISON_BUDDY_POSE_0_2:
	video offset=CINEMATIC_238, x=[BUDDY_X], y=[BUDDY_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_PRISON_BUDDY_POSE_0_3:
	video offset=CINEMATIC_239, x=[BUDDY_X], y=[BUDDY_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_235:
	video offset=CINEMATIC_235, x=[BUDDY_X], y=[BUDDY_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_234:
	video offset=CINEMATIC_234, x=[BUDDY_X], y=[BUDDY_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_233:
	video offset=CINEMATIC_233, x=[BUDDY_X], y=[BUDDY_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_232:
	video offset=CINEMATIC_232, x=[BUDDY_X], y=[BUDDY_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_PRISON_BUDDY_POSE_3:
	video offset=CINEMATIC_231, x=[BUDDY_X], y=[BUDDY_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_230:
	video offset=CINEMATIC_230, x=[BUDDY_X], y=[BUDDY_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_229:
	video offset=CINEMATIC_229, x=[BUDDY_X], y=[BUDDY_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_PRISON_BUDDY_POSE_5:
	video offset=CINEMATIC_228, x=[BUDDY_X], y=[BUDDY_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_225:
	video offset=CINEMATIC_225, x=[BUDDY_X], y=[BUDDY_Y]
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_226:
	video offset=CINEMATIC_226, x=[BUDDY_X], y=[BUDDY_Y]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_226_L0:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_352
	ret
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_352:
	video offset=CINEMATIC_352, x=[0xf5], y=[BUDDY_Y]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_352_L0:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_169_WITH_POS_STEP_AT_B673C5FF
	ret
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_169_WITH_POS_STEP_AT_B673C5FF:
	add [BUDDY_Y], 0x000D
	sub [BUDDY_X], 0x0002
	video offset=CINEMATIC_169, x=[BUDDY_X], y=[BUDDY_Y]
	add [BUDDY_X], 0x0002
	sub [BUDDY_Y], 0x000D
	ret


.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_CIN_169_WITH_POS_STEP_AT_B673C5FF.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CIN_169_WITH_POS_STEP_AT_B673C5FF.inc"
.endif

SHARED_RET:
	ret


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
.include "amiga_dos__post_SHARED_RET.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_SHARED_RET.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_240:
	video offset=CINEMATIC_240, x=[BUDDY_X], y=[BUDDY_Y]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
.include "post_DRAW_CIN_240.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_241:
	video offset=CINEMATIC_241, x=[0xf5], y=[BUDDY_Y]
	ret


.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_CIN_241.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CIN_241.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV204_AT_X07_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_ACTOR_WALK_LEFT_POSE_00_DONE:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F00, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call PRISON_DRAW_CV204_AT_X07_PLUS1_Y08_L1
	ret


PRISON_ACTOR_WALK_LEFT_POSE_01:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV204_AT_X07_PLUS1_Y08
	call PRISON_DRAW_CV204_AT_X07_Y08_L2
	jmp PRISON_ACTOR_WALK_LEFT_POSE_01_DONE
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV204_AT_X07_PLUS1_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_ACTOR_WALK_LEFT_POSE_01_DONE:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F01, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call PRISON_DRAW_CV204_AT_X07_PLUS1_Y08_L1
	ret


PRISON_ACTOR_WALK_LEFT_DRAW_PHASE_02:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, PRISON_ACTOR_WALK_LEFT_POSE_02_DONE
	call DRAW_CIN_242_THEN_243

PRISON_ACTOR_WALK_LEFT_POSE_02_DONE:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F02, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call PRISON_DRAW_CV204_AT_X07_PLUS1_Y08_L4
	ret


PRISON_DRAW_CV204_AT_X07_PLUS1_Y08_L5:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x01
	je [0x0D], 0x00, PRISON_ACTOR_WALK_LEFT_POSE_03_DONE
	call DRAW_CIN_242_THEN_243

PRISON_ACTOR_WALK_LEFT_POSE_03_DONE:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F03, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call PRISON_DRAW_CV204_AT_X07_PLUS1_Y08_L7
	ret


PRISON_ACTOR_WALK_LEFT_DRAW_PHASE_04:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, PRISON_ACTOR_WALK_LEFT_POSE_04_DONE
	call DRAW_CIN_242_THEN_243

PRISON_ACTOR_WALK_LEFT_POSE_04_DONE:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F04, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call PRISON_DRAW_CV204_AT_X07_PLUS1_Y08_L10
	ret


PRISON_ACTOR_WALK_LEFT_POSE_05:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, INLINE_DRAW_CV_216_027__HELPER
	call DRAW_CIN_338_THEN_339
	jmp PRISON_ACTOR_WALK_LEFT_POSE_05_DONE
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_216_027.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_ACTOR_WALK_LEFT_POSE_05_DONE:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F05, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call PRISON_INLINE_DRAW_CV_216_027_L0
	ret


PRISON_ACTOR_WALK_LEFT_POSE_06:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, INLINE_DRAW_CV_220_008__HELPER
	call PRISON_DRAW_CV263_AT_X07_Y08_L3
	jmp PRISON_ACTOR_WALK_LEFT_POSE_06_DONE
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_220_008.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_ACTOR_WALK_LEFT_POSE_06_DONE:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F06, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call PRISON_INLINE_DRAW_CV_220_008_L0
	ret


PRISON_ACTOR_WALK_LEFT_POSE_07:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV224_AT_X07_Y08
	call PRISON_INLINE_DRAW_CV_220_008_L2
	jmp PRISON_ACTOR_WALK_LEFT_POSE_07_DONE
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV224_AT_X07_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_ACTOR_WALK_LEFT_POSE_07_DONE:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F07, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call PRISON_DRAW_CV224_AT_X07_Y08_L1
	ret


PRISON_ACTOR_WALK_LEFT_POSE_08:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, INLINE_DRAW_CV_228_018__HELPER
	call PRISON_DRAW_CV224_AT_X07_Y08_L3
	jmp PRISON_ACTOR_WALK_LEFT_POSE_08_DONE
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_228_018.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_ACTOR_WALK_LEFT_POSE_08_DONE:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F08, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call PRISON_INLINE_DRAW_CV_228_020_L0
	ret


PRISON_ACTOR_WALK_LEFT_POSE_09:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, INLINE_DRAW_CV_228_018
	call PRISON_DRAW_CV224_AT_X07_Y08_L3
	jmp DRAW_FIGURE_WALK_LEFT_F09
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_228_018:
	video type=0, offset=CV_FIGURE_WALK_LEFT_LIMB_POSE_03, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_FIGURE_WALK_LEFT_F09:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F09, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	add [BUDDY_X], 0x0001
	call PRISON_INLINE_DRAW_CV_228_020_L0
	sub [BUDDY_X], 0x0001
	ret


PRISON_ACTOR_WALK_LEFT_POSE_10:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, INLINE_DRAW_CV_220_008
	call PRISON_INLINE_DRAW_CV_220_008_L2
	jmp PRISON_ACTOR_WALK_LEFT_POSE_10_DONE
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_220_008:
	video type=0, offset=CV_FIGURE_WALK_LEFT_LIMB_POSE_02, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_ACTOR_WALK_LEFT_POSE_10_DONE:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_LEFT_BODY_F10, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call PRISON_INLINE_DRAW_CV_220_008_L0
	ret


PRISON_INLINE_DRAW_CV_220_009_L1:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x01
	je [0x0D], 0x00, INLINE_DRAW_CV_216_027
	call PRISON_INLINE_DRAW_CV_220_008_L2
	jmp PRISON_ACTOR_WALK_LEFT_POSE_11_DONE
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_216_027:
	video type=0, offset=CV_FIGURE_WALK_LEFT_LIMB_POSE_01, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_INLINE_DRAW_CV_216_028.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_DRAW_CV_216_028.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV263_AT_X07_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_ACTOR_WALK_LEFT_PHASE_0_DONE:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F00, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call PRISON_DRAW_CV263_AT_X07_Y08_L1
	add [BUDDY_Y], 0x0001
	ret


PRISON_ACTOR_RUN_LEFT_POSE_01:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, INLINE_DRAW_CV_266_005__HELPER
	call PRISON_DRAW_CV263_AT_X07_Y08_L3
	jmp PRISON_DRAW_CV263_AT_X07_Y08_L4
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_266_005.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV263_AT_X07_Y08_L4:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F01, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call PRISON_INLINE_DRAW_CV_266_029_L0
	ret


PRISON_INLINE_DRAW_CV_266_029_L1:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [BUDDY_Y], 0x0001
	je [0x0D], 0x00, INLINE_DRAW_CV_269_024__HELPER
	call DRAW_CIN_242_THEN_243
	jmp PRISON_INLINE_DRAW_CV_266_029_L2
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_269_024.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_INLINE_DRAW_CV_266_029_L2:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F02, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call PRISON_INLINE_DRAW_CV_269_024_L0
	sub [BUDDY_Y], 0x0001
	ret


PRISON_BUDDY_WALK_LEFT_PHASE_3:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [BUDDY_Y], 0x0001
	je [0x0D], 0x00, INLINE_DRAW_CV_272_003__HELPER
	call DRAW_CIN_242_THEN_243
	jmp PRISON_ACTOR_WALK_LEFT_PHASE_3_DONE
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_272_003.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_ACTOR_WALK_LEFT_PHASE_3_DONE:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F03, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call PRISON_INLINE_DRAW_CV_272_003_L0
	sub [BUDDY_Y], 0x0001
	ret


PRISON_ACTOR_RUN_LEFT_POSE_04:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV275_AT_X07_Y08
	call DRAW_CIN_242_THEN_243
	jmp PRISON_DRAW_CV275_AT_X07_Y08_L0
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV275_AT_X07_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV275_AT_X07_Y08_L0:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F04, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call PRISON_DRAW_CV275_AT_X07_Y08_L1
	ret


PRISON_BUDDY_WALK_LEFT_PHASE_5:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [BUDDY_Y], 0x0001
	je [0x0D], 0x00, INLINE_DRAW_CV_272_003_001
	call PRISON_DRAW_CV263_AT_X07_Y08_L3
	jmp PRISON_ACTOR_WALK_LEFT_PHASE_5_DONE
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_272_003_001:
	video type=0, offset=CV_FIGURE_RUN_LEFT_LIMB_POSE_03, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_ACTOR_WALK_LEFT_PHASE_5_DONE:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F05, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call PRISON_DRAW_CV275_AT_X07_Y08_L1
	add [BUDDY_Y], 0x0001
	ret


PRISON_INLINE_DRAW_CV_272_004_L0:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, INLINE_DRAW_CV_272_003_002
	call PRISON_DRAW_CV263_AT_X07_Y08_L3
	jmp PRISON_INLINE_DRAW_CV_272_004_L1
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_272_003_002:
	video type=0, offset=CV_FIGURE_RUN_LEFT_LIMB_POSE_03, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_INLINE_DRAW_CV_272_004_L1:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F06, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call PRISON_INLINE_DRAW_CV_272_003_L0
	ret


PRISON_BUDDY_WALK_LEFT_PHASE_7:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [BUDDY_Y], 0x0001
	je [0x0D], 0x00, INLINE_DRAW_CV_269_024_001
	call PRISON_INLINE_DRAW_CV_220_008_L2
	jmp PRISON_ACTOR_WALK_LEFT_PHASE_7_DONE
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_269_024_001:
	video type=0, offset=CV_FIGURE_RUN_LEFT_LIMB_POSE_02, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_ACTOR_WALK_LEFT_PHASE_7_DONE:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F07, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call PRISON_INLINE_DRAW_CV_269_025_L1
	sub [BUDDY_Y], 0x0001
	ret


PRISON_BUDDY_WALK_LEFT_PHASE_8:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [BUDDY_Y], 0x0001
	je [0x0D], 0x00, INLINE_DRAW_CV_269_024_002
	call PRISON_DRAW_CV224_AT_X07_Y08_L3
	jmp PRISON_ACTOR_WALK_LEFT_PHASE_8_DONE
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_269_024_002:
	video type=0, offset=CV_FIGURE_RUN_LEFT_LIMB_POSE_02, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_ACTOR_WALK_LEFT_PHASE_8_DONE:
	call DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_RUN_LEFT_BODY_F08, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call PRISON_INLINE_DRAW_CV_269_026_L0
	sub [BUDDY_Y], 0x0001
	ret


PRISON_INLINE_DRAW_CV_269_026_L1:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, INLINE_DRAW_CV_266_005
	call PRISON_INLINE_DRAW_CV_220_008_L2
	jmp PRISON_INLINE_DRAW_CV_269_026_L2
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_266_005:
	video type=0, offset=CV_FIGURE_RUN_LEFT_LIMB_POSE_01, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_INLINE_DRAW_CV_266_030.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_DRAW_CV_266_030.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_243_012.inc"
.endif


.include "../_helpers/DEDUP_CAVES_5B_020.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_PRISON_5B_006.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_PRISON_5B_006.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_PRISON_5B_006.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV246_AT_X07_Y08.inc"
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_DRAW_CV246_AT_X07_Y08.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CV246_AT_X07_Y08.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV249_AT_X07_Y08.inc"
.endif


.include "../_helpers/DEDUP_CAVES_5B_007.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_PRISON_5B_014.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_PRISON_5B_014.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_PRISON_5B_014.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_252_018.inc"
.endif


