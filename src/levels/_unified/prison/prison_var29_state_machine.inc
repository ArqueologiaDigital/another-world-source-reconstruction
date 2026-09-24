INLINE_SET_VAR29_TO_5:
	mov [0x29], 0x0005

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_SET_VAR29_TO_5.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_SET_VAR29_TO_5.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_SET_VAR29_TO_5.inc"
.endif

.include "../_helpers/INLINE_SET_VAR29_TO_6.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
PRISON_BUDDY_HACK_SECOND_OFFSCREEN_HOLD:
	break
	je [SCREEN_NUM], 0x04, PRISON_BUDDY_HACK_SECOND_BURST_DISPATCH
	djnz [0x29], PRISON_BUDDY_HACK_SECOND_OFFSCREEN_HOLD
	jmp PRISON_BUDDY_HACK_SECOND_BURST_DISPATCH
PRISON_INLINE_SET_VAR29_TO_6_L2:
	db 0x11

PRISON_BUDDY_HACK_SECOND_BURST_DISPATCH:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	add [0xF1], 0x0001
	jg [0xF1], 0x20, PRISON_BUDDY_HACK_SECOND_DONE
	jne [SCREEN_NUM], 0x04, INLINE_SET_VAR29_TO_6
	je [0x3A], 0x00, PRISON_INLINE_SET_VAR29_TO_6_L4
	je [0x3A], 0x01, PRISON_INLINE_SET_VAR29_TO_6_L5
	jl [0x3A], 0x05, PRISON_INLINE_SET_VAR29_TO_6_L6
	jmp PRISON_INLINE_SET_VAR29_TO_6_L7

PRISON_BUDDY_HACK_SECOND_DONE:
	jne [SCREEN_NUM], 0x04, PRISON_BUDDY_HACK_SECOND_HANDOFF
	selectVideoPage 0x00
	video offset=CINEMATIC_379, x=160, y=100
	selectVideoPage 0xFF

PRISON_BUDDY_HACK_SECOND_HANDOFF:
	mov [0x12], 0x0000
	mov [0xB1], 0x0001
	and [0x49], 0x7F9F
	or [0x49], 0x0040
	or [0x49], 0x0380
	mov [0x29], 0x012C
	setup channel=0x08, address=INLINE_SET_VARF1_TO_64
	mov [0xF8], [0x49]
	and [0xF8], 0x0380
	je [0xF8], 0x0380, PRISON_ACTOR_FACE_RIGHT_THEN_WALK_RIGHT
	mov [0x29], 0x000A
	jmp PRISON_ACTOR_FACE_LEFT_THEN_RUN_LEFT
.endif

INLINE_SET_VARF1_TO_64:
	mov [0xF1], 0x0064

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
.include "amiga_dos__post_INLINE_SET_VARF1_TO_64.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_SET_VARF1_TO_64.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_406_408_BLOCK:
	video offset=CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F0, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F1, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F2, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F3, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F3, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F2, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F3, x=[BUDDY_X], y=[BUDDY_Y]
	selectVideoPage 0x00
	video offset=CINEMATIC_410, x=160, y=100
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F4, x=[BUDDY_X], y=[BUDDY_Y]
.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_CIN_406_408_BLOCK.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CIN_406_408_BLOCK.inc"
.endif

INLINE_SET_VAR29_TO_28:
	mov [0x29], 0x0028

.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
PRISON_INLINE_SET_VAR29_TO_28_L0:
	call GUARDED_DRAW_CIN_242_243
	break
	djnz [0x29], PRISON_INLINE_SET_VAR29_TO_28_L0
	killChannel
.endif

INLINE_SUB_VAR08_INIT_VAR29:
	sub [BUDDY_Y], 0x0005
	mov [0x29], 0x000A

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_FOLD_BODY_89B_179104BB.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_FOLD_BODY_89B_179104BB.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_FOLD_BODY_89B_179104BB.inc"
.endif

SET_VAR29_TO_000A:
	mov [0x29], 0x000A
	ret


.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
PRISON_CAGE_GUARD_IDLE_NEXT_POSE_CASE_00:
	jne [0x0E], 0x00, PRISON_CAGE_GUARD_IDLE_NEXT_POSE_CASE_01
	jl [0x39], 0x02, INIT_VARS_0E_29
	mov [0x0E], 0x0001

PRISON_CAGE_GUARD_IDLE_NEXT_POSE_CASE_01:
	jne [0x0E], 0x01, INIT_VARS_0E_29
	mov [0x0E], 0x0000
	mov [0x29], 0xFFFE
	ret
.endif

INIT_VARS_0E_29:
	mov [0x0E], 0x0000
	mov [0x29], 0xFFFF
	ret


DECREMENT_VAR29_BY_1:
	sub [0x29], 0x0001
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DECREMENT_VAR29_BY_1.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DECREMENT_VAR29_BY_1.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DECREMENT_VAR29_BY_1.inc"
.endif

BIT_EXTRACT_FROM_VAR24_TO_VAR25:
	mov [0x25], [0x24]
	and [0x25], 0x00FF
	shr [0x24], 0x0008
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_FOLD_BODY_144B_C55279EA.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_FOLD_BODY_144B_C55279EA.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_FOLD_BODY_144B_C55279EA.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_569_TO_572_6F_AT_F8680E45:
	selectVideoPage 0x00
	video offset=CINEMATIC_PRISON_BACKGROUND_DOORWAY_BACKDROP, x=160, y=100
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F0, x=228, y=175
	break
	video offset=CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F3, x=232, y=175
	video offset=CINEMATIC_PRISON_BACKGROUND_DOORWAY_POST, x=160, y=100
	break
	video offset=CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F4, x=245, y=175
	video offset=CINEMATIC_PRISON_BACKGROUND_DOORWAY_POST, x=160, y=100
	killChannel
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_570_574_BLOCK:
	mov [0x57], 0x0002
	video offset=CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F2, x=239, y=175
	video offset=CINEMATIC_PRISON_BACKGROUND_DOORWAY_POST, x=160, y=100
	break
	video offset=CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F0, x=230, y=175
	video offset=CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F2, x=230, y=175
	video offset=CINEMATIC_PRISON_BACKGROUND_DOORWAY_POST, x=160, y=100
	break
	video offset=CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F0, x=228, y=175
	break
	video offset=CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F1, x=227, y=175
	break
	video offset=CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F1, x=226, y=175
	selectVideoPage 0x00
	video offset=CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F1, x=226, y=175
	selectVideoPage 0xFF
	killChannel
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_576_578_BLOCK:
	video offset=CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F0, x=215, y=131
	break
	video offset=CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F1, x=227, y=141
	break
	mov [0x31], 0x0000
	video offset=CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F2, x=231, y=158
	break
	video offset=CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F3, x=239, y=175
	break
	video offset=CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F2, x=243, y=174
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F5, x=245, y=175
	mov [0x31], 0x0000
	break
	video offset=CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F4, x=247, y=175
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F5, x=249, y=175
	break
	video offset=CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F5, x=250, y=175
	selectVideoPage 0x00
	video offset=CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F5, x=251, y=175
	selectVideoPage 0xFF
	killChannel
.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_CIN_576_578_BLOCK.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CIN_576_578_BLOCK.inc"
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

