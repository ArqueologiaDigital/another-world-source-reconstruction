PRISON_HERO_WALK_LEFT_TURN_PRELUDE:
	sub [HERO_X], 0x0004
	video offset=CINEMATIC_555, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	break

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_STEP_DRAW_CIN555_LEFT4_RIGHT1.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_STEP_DRAW_CIN555_LEFT4_RIGHT1.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_STEP_DRAW_CIN555_LEFT4_RIGHT1.inc"
.endif

PRISON_HERO_WALK_RIGHT_TURN_PRELUDE:
	add [HERO_X], 0x0000
	video offset=CINEMATIC_555, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0003
	break

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_CIN555_STEP_RIGHT3.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DRAW_CIN555_STEP_RIGHT3.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CIN555_STEP_RIGHT3.inc"
.endif

.include "../_helpers/INLINE_BREAK_035.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_BREAK_035.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_BREAK_035.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_BREAK_035.inc"
.endif

.include "../_helpers/INLINE_BREAK_035.inc"

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_BREAK_036.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_BREAK_036.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_BREAK_036.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_187_TO_222_2F_AT_8E66E193:
	sub [HERO_X], 0x0004
	video offset=CINEMATIC_187, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_222, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_187_TO_222_2F_AT_8E66E193_L0:
	break
	video offset=CINEMATIC_222, x=[HERO_X], y=[HERO_Y]
	je [HERO_ACTION_POS_MASK], 0x84, PRISON_DRAW_CIN_187_TO_222_2F_AT_8E66E193_L0
	add [HERO_X], 0x0002
	break
	video offset=CINEMATIC_223, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0002
	je [HERO_POS_JUMP_DOWN], 0x01, PRISON_DRAW_CIN_187_TO_222_2F_AT_8E66E193_L1
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_212_TO_213_2F_AT_6B0D0A47:
	add [HERO_X], 0x0004
	video offset=CINEMATIC_212, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_213, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0001
.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_CIN_212_TO_213_2F_AT_6B0D0A47.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CIN_212_TO_213_2F_AT_6B0D0A47.inc"
.endif

.include "../_helpers/INLINE_BREAK_035.inc"

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_BREAK_037.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_BREAK_037.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_BREAK_037.inc"
.endif

.include "../_helpers/INLINE_BREAK_035.inc"

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_BREAK_038.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_BREAK_038.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_BREAK_038.inc"
.endif

