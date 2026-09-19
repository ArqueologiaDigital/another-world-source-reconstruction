SET_VAR18_TO_0122:
	mov [0x18], 0x0122
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_SET_VAR18_TO_0122.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_SET_VAR18_TO_0122.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_SET_VAR18_TO_0122.inc"
.endif

.include "../_helpers/INLINE_SET_VAR63_TO_1.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
HERO_INPUT_WALK_RIGHT_DISPATCH:
	jne [HERO_POS_LEFT_RIGHT], 0x01, CAVES_HERO_INPUT_CROUCH_RIGHT_DISPATCH
	je [0x63], 0x02, CAVES_HERO_INPUT_CROUCH_RIGHT_DISPATCH
	setup channel=0x14, address=CAVES_INLINE_SET_VAR63_TO_1_L2
	je [0x63], 0x06, INLINE_SET_VAR63_TO_2
	setup channel=0x14, address=DRAW_CV352_STEP_RIGHT3
.endif

.include "../_helpers/INLINE_SET_VAR63_TO_2.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_SET_VAR63_TO_2.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_SET_VAR63_TO_2.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_SET_VAR63_TO_2.inc"
.endif

.include "../_helpers/INLINE_SET_VAR63_TO_5.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
HERO_INPUT_RUN_RIGHT_DISPATCH:
	jne [HERO_ACTION_POS_MASK], 0x81, CAVES_HERO_INPUT_RUN_JUMP_RIGHT_DISPATCH
	je [0x63], 0x06, CAVES_HERO_INPUT_RUN_JUMP_RIGHT_DISPATCH
	setup channel=0x14, address=HERO_RUN_RIGHT_ENTRY
	jne [0x63], 0x01, INLINE_SET_VAR63_TO_6
	setup channel=0x14, address=CAVES_INLINE_SET_VAR63_TO_5_L3
.endif

.include "../_helpers/INLINE_SET_VAR63_TO_6.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_SET_VAR63_TO_6.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_SET_VAR63_TO_6.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_SET_VAR63_TO_6.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/WALK_RIGHT_DRAW_CV142_MULTISTEP.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
HERO_PRONE_RISE_RIGHT:
	je [SCREEN_NUM], 0x25, CAVES_WALK_RIGHT_DRAW_CV142_MULTISTEP_L1
	video type=0, offset=COMMON_VIDEO_140, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_149, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_150, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_151, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_152, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x2A], 0x000F
	call SET_VAR04_TO_0010
	jmp HERO_CROUCH_ARMED_RIGHT_LOOP
CAVES_WALK_RIGHT_DRAW_CV142_MULTISTEP_L2:
	db 0x11

CAVES_WALK_RIGHT_DRAW_CV142_MULTISTEP_L1:
	video type=0, offset=COMMON_VIDEO_140, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L9
	je [HERO_ACTION_POS_MASK], 0x06, CAVES_HERO_CRAWL_LEFT_PHASE_3
	jmp CAVES_WALK_RIGHT_DRAW_CV142_MULTISTEP_L1
CAVES_WALK_RIGHT_DRAW_CV142_MULTISTEP_L3:
	db 0x11

CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L9:
	video type=0, offset=COMMON_VIDEO_140, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, CAVES_HERO_CRAWL_LEFT_PHASE_2

CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L7:
	jne [HERO_ACTION_POS_MASK], 0x05, HERO_PRONE_RISE_RIGHT
	video type=0, offset=COMMON_VIDEO_163, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_POS_MASK], 0x06, CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L5

CAVES_HERO_CRAWL_RIGHT_PHASE_3:
	jne [HERO_ACTION_POS_MASK], 0x05, HERO_PRONE_RISE_RIGHT
	video type=0, offset=COMMON_VIDEO_139, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x06, CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L26

CAVES_HERO_CRAWL_RIGHT_PHASE_4:
	jne [HERO_ACTION_POS_MASK], 0x05, HERO_PRONE_RISE_RIGHT
	video type=0, offset=COMMON_VIDEO_141, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, CAVES_HERO_CRAWL_LEFT_PHASE_10

CAVES_HERO_CRAWL_RIGHT_PHASE_5:
	jne [HERO_ACTION_POS_MASK], 0x05, HERO_PRONE_RISE_RIGHT
	video type=0, offset=COMMON_VIDEO_142, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	break
	je [HERO_POS_MASK], 0x06, CAVES_HERO_CRAWL_LEFT_PHASE_9

CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L22:
	video type=0, offset=COMMON_VIDEO_143, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x06, CAVES_HERO_CRAWL_LEFT_PHASE_8

CAVES_HERO_CRAWL_RIGHT_PHASE_7:
	video type=0, offset=COMMON_VIDEO_144, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, CAVES_HERO_CRAWL_LEFT_PHASE_7

CAVES_HERO_CRAWL_RIGHT_PHASE_8:
	video type=0, offset=COMMON_VIDEO_145, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x06, CAVES_HERO_CRAWL_LEFT_PHASE_6

CAVES_HERO_CRAWL_RIGHT_PHASE_9:
	video type=0, offset=COMMON_VIDEO_146, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, CAVES_WALK_RIGHT_DRAW_CV142_MULTISTEP_L4
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, CAVES_HERO_CRAWL_LEFT_PHASE_5

CAVES_HERO_CRAWL_RIGHT_PHASE_10:
	video type=0, offset=COMMON_VIDEO_148, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, CAVES_WALK_RIGHT_DRAW_CV142_MULTISTEP_L4
	add [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x06, CAVES_HERO_CRAWL_LEFT_PHASE_4

CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L11:
	video type=0, offset=COMMON_VIDEO_147, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, CAVES_HERO_CRAWL_LEFT_PHASE_3
	jne [HERO_ACTION_POS_MASK], 0x05, HERO_PRONE_RISE_RIGHT
	jmp CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L9
	killChannel
	video type=0, offset=COMMON_VIDEO_133, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_134, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_135, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	call SET_VAR04_TO_0008
	break
	video type=0, offset=COMMON_VIDEO_136, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_137, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_138, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0005
	break
	mov [0x2A], 0x000F
	jmp CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L5
CAVES_WALK_RIGHT_DRAW_CV142_MULTISTEP_L5:
	db 0x11

CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L19:
	break
	video type=0, offset=COMMON_VIDEO_143, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0003
	break
	jmp HERO_PRONE_RISE_LEFT
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
STEP_LEFT4_DRAW_CV140_LEFT4:
	sub [HERO_X], 0x0004
	break
	video type=0, offset=COMMON_VIDEO_140, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0004
	break
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
HERO_PRONE_RISE_LEFT:
	je [SCREEN_NUM], 0x25, HERO_PRONE_IDLE_LEFT_LOOP
	video type=0, offset=COMMON_VIDEO_141, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_137, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_135, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_134, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_133, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x2A], 0x000F
	call SET_VAR04_TO_0000
	jmp HERO_CROUCH_ARMED_LEFT_LOOP
CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L3:
	db 0x11

HERO_PRONE_IDLE_LEFT_LOOP:
	video type=0, offset=COMMON_VIDEO_141, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, CAVES_HERO_CRAWL_RIGHT_PHASE_4
	je [HERO_ACTION_POS_MASK], 0x06, CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L5
	jmp HERO_PRONE_IDLE_LEFT_LOOP
CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L6:
	db 0x11

CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L5:
	video type=0, offset=COMMON_VIDEO_139, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_POS_MASK], 0x05, CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L7

CAVES_HERO_CRAWL_LEFT_PHASE_2:
	jne [HERO_ACTION_POS_MASK], 0x06, HERO_PRONE_RISE_LEFT
	video type=0, offset=COMMON_VIDEO_163, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L9

CAVES_HERO_CRAWL_LEFT_PHASE_3:
	jne [HERO_ACTION_POS_MASK], 0x06, HERO_PRONE_RISE_LEFT
	video type=0, offset=COMMON_VIDEO_140, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L11

CAVES_HERO_CRAWL_LEFT_PHASE_4:
	video type=0, offset=COMMON_VIDEO_147, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, STEP_LEFT4_DRAW_CV140_LEFT4
	sub [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x05, CAVES_HERO_CRAWL_RIGHT_PHASE_10

CAVES_HERO_CRAWL_LEFT_PHASE_5:
	video type=0, offset=COMMON_VIDEO_148, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, STEP_LEFT4_DRAW_CV140_LEFT4
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, CAVES_HERO_CRAWL_RIGHT_PHASE_9

CAVES_HERO_CRAWL_LEFT_PHASE_6:
	video type=0, offset=COMMON_VIDEO_146, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, STEP_LEFT4_DRAW_CV140_LEFT4
	sub [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x05, CAVES_HERO_CRAWL_RIGHT_PHASE_8

CAVES_HERO_CRAWL_LEFT_PHASE_7:
	video type=0, offset=COMMON_VIDEO_145, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L19
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, CAVES_HERO_CRAWL_RIGHT_PHASE_7

CAVES_HERO_CRAWL_LEFT_PHASE_8:
	video type=0, offset=COMMON_VIDEO_144, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L19
	sub [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x05, CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L22

CAVES_HERO_CRAWL_LEFT_PHASE_9:
	video type=0, offset=COMMON_VIDEO_143, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L19
	sub [HERO_X], 0x0004
	break
	je [HERO_POS_MASK], 0x05, CAVES_HERO_CRAWL_RIGHT_PHASE_5

CAVES_HERO_CRAWL_LEFT_PHASE_10:
	jne [HERO_ACTION_POS_MASK], 0x06, HERO_PRONE_RISE_LEFT
	video type=0, offset=COMMON_VIDEO_142, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, CAVES_HERO_CRAWL_RIGHT_PHASE_4

CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L26:
	jne [HERO_ACTION_POS_MASK], 0x06, HERO_PRONE_RISE_LEFT
	video type=0, offset=COMMON_VIDEO_141, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x05, CAVES_HERO_CRAWL_RIGHT_PHASE_3
	jne [HERO_ACTION_POS_MASK], 0x06, HERO_PRONE_RISE_LEFT
	jmp CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L5
	killChannel
	break
	add [HERO_X], 0x0002
	call CAVES_HERO_WALK_LEFT_STRIDE_PHASE_3

CAVES_HERO_WALK_LEFT_STOP_AFTER_PHASE_3:
	break
	add [HERO_X], 0x0002
	call CAVES_HERO_WALK_LEFT_STRIDE_PHASE_2

CAVES_HERO_WALK_LEFT_STOP_AFTER_PHASE_2:
	break
	add [HERO_X], 0x0002
	call CAVES_HERO_WALK_LEFT_STRIDE_PHASE_1

CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L30:
	add [HERO_X], 0x0001
	jmp HERO_WALK_LEFT_LOOP
	break
	add [HERO_X], 0x0002
	call CAVES_DRAW_CV_074_L0

CAVES_HERO_WALK_LEFT_STOP_AFTER_PHASE_11:
	break
	add [HERO_X], 0x0002
	call CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L32

CAVES_HERO_WALK_LEFT_STOP_AFTER_PHASE_10:
	break
	add [HERO_X], 0x0002
	call CAVES_DRAW_CV_072_L0

CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L34:
	add [HERO_X], 0x0001
	jmp CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L35
CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L36:
	db 0x11
.endif

.include "../_helpers/STEP_DRAW_CV352_LEFT4_RIGHT1.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_STEP_DRAW_CV352_LEFT4_RIGHT1.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_STEP_DRAW_CV352_LEFT4_RIGHT1.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_STEP_DRAW_CV352_LEFT4_RIGHT1.inc"
.endif

.include "../_helpers/DRAW_CV352_STEP_RIGHT3.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_CV352_STEP_RIGHT3.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DRAW_CV352_STEP_RIGHT3.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CV352_STEP_RIGHT3.inc"
.endif

.include "../_helpers/INLINE_BREAK_035.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_BREAK_041.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_BREAK_041.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_BREAK_041.inc"
.endif

.include "../_helpers/INLINE_BREAK_035.inc"

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_BREAK_042.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_BREAK_042.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_BREAK_042.inc"
.endif

.include "../_helpers/INLINE_BREAK_035.inc"

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_BREAK_043.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_BREAK_043.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_BREAK_043.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
HERO_CROUCH_DOWN_LEFT_STEP:
	add [HERO_X], 0x0002
	video type=0, offset=COMMON_VIDEO_336, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_340, x=[HERO_X], y=[HERO_Y], zoom=0x40
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
HERO_CROUCH_HOLD_LEFT_LOOP:
	break
	video type=0, offset=COMMON_VIDEO_340, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [HERO_POS_JUMP_DOWN], 0x01, HERO_CROUCH_HOLD_LEFT_LOOP
	break
	sub [HERO_X], 0x0002
	video type=0, offset=COMMON_VIDEO_339, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
CAVES_STEP_DRAW_CV336_THEN_CV340_L1:
	db 0x11

CAVES_STEP_DRAW_CV336_THEN_CV340_L2:
	jne [0x0F], 0x00, CAVES_STEP_DRAW_CV336_THEN_CV340_L3
	add [HERO_X], 0x0003
	call CAVES_STEP_DRAW_CV336_THEN_CV340_L4
	call CAVES_STEP_DRAW_CV336_THEN_CV340_L5
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	add [0x21], 0x001E
	sub [0x27], 0x0016
	call CAVES_STEP_DRAW_CV336_THEN_CV340_L6
	break
	sub [HERO_X], 0x0002
	call CAVES_STEP_DRAW_CV336_THEN_CV340_L7
	sub [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, HERO_CROUCH_ARMED_RIGHT_LOOP
	setup channel=0x17, address=CAVES_STEP_DRAW_CV336_THEN_CV340_L9
.endif

.include "../_helpers/INLINE_BREAK_035.inc"

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_BREAK_044.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_BREAK_044.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_BREAK_044.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
HERO_CROUCH_DOWN_RIGHT_STEP:
	sub [HERO_X], 0x0002
	video type=0, offset=COMMON_VIDEO_329, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_335, x=[HERO_X], y=[HERO_Y], zoom=0x40
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
HERO_CROUCH_HOLD_RIGHT_LOOP:
	break
	video type=0, offset=COMMON_VIDEO_335, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [HERO_POS_JUMP_DOWN], 0x01, HERO_CROUCH_HOLD_RIGHT_LOOP
	break
	add [HERO_X], 0x0002
	video type=0, offset=COMMON_VIDEO_334, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
CAVES_STEP_DRAW_CV329_THEN_CV335_L1:
	db 0x11, 0x57, 0x04, 0xFB, 0x01, 0x02, 0x11, 0x57
	db 0x05, 0xEF, 0x01, 0x02, 0x11, 0xFF, 0xFF, 0xFF
.endif

