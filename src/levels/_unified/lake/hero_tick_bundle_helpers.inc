CINEMATIC_HERO_LEFT_PROFILE		EQU 0x0640
CINEMATIC_HERO_RESUME_LEFT_3		EQU 0x0B54
CINEMATIC_HERO_RESUME_LEFT_4		EQU 0x0310
CINEMATIC_HERO_RESUME_LEFT_5		EQU 0x039C
.if BRANCH == "chahi_amiga_1991"
CINEMATIC_HERO_FALL_LEFT_1		EQU 0x0A3C
.endif

HERO_TICK_BUNDLE_062_063:
	break
	add [HERO_X], 0x0002
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_CV_062_063_AND_CIN_002
.elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_FALL_LEFT_1, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
.endif

HERO_TICK_BUNDLE_060_061:
	break
	add [HERO_X], 0x0002
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_LEFT_PROFILE
.elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LEFT_PROFILE, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
.endif

HERO_LEFT_PROFILE_DONE_X_INC:
	add [HERO_X], 0x0001
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	jmp HERO_LEFT_ACTION_JOIN_WALK_OR_STAND
.elif BRANCH == "chahi_amiga_1991"
	jmp MAYBE_RESUME_WALK_LEFT_IF_GROUNDED
.endif
	break
	add [HERO_X], 0x0002
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_RESUME_LEFT_F5
.elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RESUME_LEFT_5, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
.endif

HERO_TICK_VIDEO_074:
	break
	add [HERO_X], 0x0002
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_RESUME_LEFT_F4
.elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RESUME_LEFT_4, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
.endif

HERO_TICK_VIDEO_073:
	break
	add [HERO_X], 0x0002
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_RESUME_LEFT_F3
.elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RESUME_LEFT_3, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
.endif

HERO_RESUME_LEFT_F3_DONE:
	add [HERO_X], 0x0001
	jmp HERO_FALL_L_F2_HOLD_LOOP
	killChannel

