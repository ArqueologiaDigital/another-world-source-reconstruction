.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_HERO_FALL_PRELUDE_FRAME		EQU 0x04B0
.endif
.if BRANCH == "chahi_amiga_1991"
CINEMATIC_HERO_FALL_PRELUDE_FRAME		EQU 0x0CA0
.endif

CINEMATIC_HERO_WALK_LEFT_5		EQU 0x0ADC
CINEMATIC_HERO_WALK_LEFT_6		EQU 0x0B04
CINEMATIC_HERO_WALK_LEFT_7		EQU 0x0B2C
CINEMATIC_HERO_WALK_LEFT_11		EQU 0x0408
CINEMATIC_HERO_WALK_LEFT_12		EQU 0x0488
CINEMATIC_HERO_WALK_LEFT_13		EQU 0x0504
CINEMATIC_HERO_WALK_LEFT_14		EQU 0x0574
.if BRANCH == "chahi_amiga_1991"
CINEMATIC_HERO_WALK_LEFT_3		EQU 0x0A8C
CINEMATIC_HERO_WALK_LEFT_4		EQU 0x0AB4
.endif

HERO_WALK_LEFT_CYCLE_PRELUDE:
	sub [HERO_X], 0x0004
	video offset=CINEMATIC_HERO_FALL_PRELUDE_FRAME, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
	add [HERO_X], 0x0001
	break

HERO_WALK_LEFT_CYCLE_LOOP:
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_WALK_LEFT_F0
.elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_LEFT_0, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
.endif
	call DRAW_DROPLET_VARIANT_ON_BG_Y_PLUS_1
	je [HERO_POS_MASK], 0x00, HERO_WALK_LEFT_F0_DONE_X_INC
	sub [HERO_X], 0x0002
	break
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_WALK_LEFT_F1
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, WALK_LEFT_F1_X_DELTA_DONE
.elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_LEFT_1, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
.endif
	je [HERO_POS_MASK], 0x00, HERO_TICK_BUNDLE_060_061
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	sub [HERO_X], 0x0001

WALK_LEFT_F1_X_DELTA_DONE:
	sub [HERO_X], 0x0001
.elif BRANCH == "chahi_amiga_1991"
	sub [HERO_X], 0x0002
.endif
	break
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_WALK_LEFT_F2
.elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_LEFT_2, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
.endif
	mov [0x29], [HERO_X]
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, WALK_LEFT_F2_X_DELTA_DONE
.endif
	je [HERO_POS_MASK], 0x00, HERO_TICK_BUNDLE_062_063
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	sub [HERO_X], 0x0001

WALK_LEFT_F2_X_DELTA_DONE:
	sub [HERO_X], 0x0001
.elif BRANCH == "chahi_amiga_1991"
	add [HERO_Y], 0x0000
	sub [HERO_X], 0x0002
.endif
	break
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_WALK_LEFT_F3
.elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_LEFT_3, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
.endif
	mov [0x29], [HERO_X]
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	sub [HERO_X], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, WALK_LEFT_F3_X_DELTA_DONE
.elif BRANCH == "chahi_amiga_1991"
	sub [HERO_X], 0x0003
	break
	video offset=CINEMATIC_HERO_WALK_LEFT_4, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
	add [HERO_Y], 0x0000
.endif
	sub [HERO_X], 0x0002
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")

WALK_LEFT_F3_X_DELTA_DONE:
	break
	call DRAW_HERO_WALK_LEFT_F4
	sub [HERO_X], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, WALK_LEFT_F3_INNER_DONE
	sub [HERO_X], 0x0001

WALK_LEFT_F3_INNER_DONE:
.endif
	break
	play id=0x0051, freq=0x14, vol=0x1D, channel=0x01
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_WALK_LEFT_F5
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, WALK_LEFT_F4_X_DELTA_DONE
.elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_LEFT_5, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
.endif
	sub [HERO_X], 0x0002
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")

WALK_LEFT_F4_X_DELTA_DONE:
.endif
	break
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_WALK_LEFT_F6
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, HERO_WALK_LEFT_F7_HOLD_LOOP
.elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_LEFT_6, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
.endif
	sub [HERO_X], 0x0002

HERO_WALK_LEFT_F7_HOLD_LOOP:
	break
	mov [0x29], [HERO_X]
	je [HERO_POS_JUMP_DOWN], 0xFFFF, HERO_RUN_LEFT_BURST_LOOP
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_WALK_LEFT_F7
.elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_LEFT_7, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
.endif
	jne [HERO_POS_MASK], 0x02, HERO_WALK_LEFT_F7_HOLD_LOOP
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, MAYBE_START_RUN_LEFT_IF_GROUNDED
.elif BRANCH == "chahi_amiga_1991"
	sub [HERO_X], 0x0002
	break
	video offset=CINEMATIC_HERO_WALK_LEFT_8, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
	je [HERO_POS_MASK], 0x00, HERO_WALK_LEFT_F8_DONE
	sub [HERO_X], 0x0002
	break
	video offset=CINEMATIC_HERO_WALK_LEFT_9, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
	je [HERO_POS_MASK], 0x00, HERO_TICK_VIDEO_073
	sub [HERO_X], 0x0002
	break
	video offset=CINEMATIC_HERO_WALK_LEFT_10, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
	call DRAW_DROPLET_VARIANT_ON_BG
	mov [0x29], [HERO_X]
	je [HERO_POS_MASK], 0x00, HERO_TICK_VIDEO_074
	add [HERO_Y], 0x0000
	sub [HERO_X], 0x0002
	break
	video offset=CINEMATIC_HERO_WALK_LEFT_11, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
	mov [0x29], [HERO_X]
	sub [HERO_X], 0x0003
	break
	video offset=CINEMATIC_HERO_WALK_LEFT_12, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
	add [HERO_Y], 0x0000
	sub [HERO_X], 0x0002
	break
	play id=0x0051, freq=0x0B, vol=0x20, channel=0x01
	video offset=CINEMATIC_HERO_WALK_LEFT_13, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
	sub [HERO_X], 0x0002
	break
	video offset=CINEMATIC_HERO_WALK_LEFT_14, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
.endif
	sub [HERO_X], 0x0002

MAYBE_START_RUN_LEFT_IF_GROUNDED:
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	break
	call DRAW_HERO_WALK_LEFT_F8
	je [HERO_POS_MASK], 0x00, HERO_WALK_LEFT_F8_DONE
	sub [HERO_X], 0x0002
	break
	call DRAW_HERO_WALK_LEFT_F9
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, RESUME_L_V074_DONE
	je [HERO_POS_MASK], 0x00, HERO_TICK_VIDEO_073
	sub [HERO_X], 0x0001

RESUME_L_V074_DONE:
	sub [HERO_X], 0x0001
	break
	call DRAW_HERO_WALK_LEFT_F10
	call DRAW_DROPLET_VARIANT_ON_BG
	mov [0x29], [HERO_X]
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, RESUME_L_V075_DONE
	je [HERO_POS_MASK], 0x00, HERO_TICK_VIDEO_074
	sub [HERO_X], 0x0001

RESUME_L_V075_DONE:
	sub [HERO_X], 0x0001
	break
	call DRAW_HERO_WALK_LEFT_F11
	mov [0x29], [HERO_X]
	sub [HERO_X], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, RESUME_L_V076_DONE
	sub [HERO_X], 0x0002

RESUME_L_V076_DONE:
	break
	call DRAW_HERO_WALK_LEFT_F12
	sub [HERO_X], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, RESUME_L_V077_DONE
	sub [HERO_X], 0x0001

RESUME_L_V077_DONE:
	break
	play id=0x0051, freq=0x0B, vol=0x20, channel=0x01
	call DRAW_HERO_WALK_LEFT_F13
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, RESUME_L_V078_DONE
	sub [HERO_X], 0x0002

RESUME_L_V078_DONE:
	break
	call DRAW_HERO_WALK_LEFT_F14
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, HERO_LEFT_ACTION_JOIN_WALK_OR_STAND
	sub [HERO_X], 0x0002

HERO_LEFT_ACTION_JOIN_WALK_OR_STAND:
.endif
	break
	je [HERO_POS_JUMP_DOWN], 0xFFFF, HERO_RUN_LEFT_BURST_LOOP

