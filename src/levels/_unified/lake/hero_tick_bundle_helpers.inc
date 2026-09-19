CINEMATIC_HERO_WALK_LEFT_0		EQU 0x0640
CINEMATIC_HERO_WALK_LEFT_8		EQU 0x0B54
CINEMATIC_HERO_WALK_LEFT_9		EQU 0x0310
CINEMATIC_HERO_WALK_LEFT_10		EQU 0x039C
.if BRANCH == "chahi_amiga_1991"
CINEMATIC_HERO_WALK_LEFT_1		EQU 0x0A3C
.endif

HERO_TICK_BUNDLE_062_063:
	break
	add [HERO_X], 0x0002
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_WALK_LEFT_F1
.elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_LEFT_1, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
.endif

HERO_TICK_BUNDLE_060_061:
	break
	add [HERO_X], 0x0002
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_WALK_LEFT_F0
.elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_LEFT_0, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
.endif

HERO_WALK_LEFT_F0_DONE_X_INC:
	add [HERO_X], 0x0001
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	jmp HERO_LEFT_ACTION_JOIN_WALK_OR_STAND
.elif BRANCH == "chahi_amiga_1991"
	jmp MAYBE_START_RUN_LEFT_IF_GROUNDED
.endif
	break
	add [HERO_X], 0x0002
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_WALK_LEFT_F10
.elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_LEFT_10, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
.endif

HERO_TICK_VIDEO_074:
	break
	add [HERO_X], 0x0002
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_WALK_LEFT_F9
.elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_LEFT_9, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
.endif

HERO_TICK_VIDEO_073:
	break
	add [HERO_X], 0x0002
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_WALK_LEFT_F8
.elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_LEFT_8, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
.endif

HERO_WALK_LEFT_F8_DONE:
	add [HERO_X], 0x0001
	jmp HERO_WALK_LEFT_F7_HOLD_LOOP
	killChannel

