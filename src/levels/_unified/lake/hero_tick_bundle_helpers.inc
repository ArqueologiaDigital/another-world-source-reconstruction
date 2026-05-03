HERO_TICK_BUNDLE_062_063:
	break
	add [0x01], 0x0002
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_CV_062_063_AND_CIN_002
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_FALL_LEFT_F1, x=[0x01], y=[0x02], zoom=[0x03]
;@endif

HERO_TICK_BUNDLE_060_061:
	break
	add [0x01], 0x0002
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_CV_060_061_AND_CIN_002
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_LEFT_PROFILE, x=[0x01], y=[0x02], zoom=[0x03]
;@endif

HERO_LEFT_PROFILE_DONE_X_INC:
	add [0x01], 0x0001
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	jmp RESUME_L_CV079080_DONE
;@elif BRANCH == "chahi_amiga_1991"
	jmp MAYBE_RESUME_WALK_LEFT_IF_GROUNDED
;@endif
	break
	add [0x01], 0x0002
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_VIDEO_075_AND_CINEMATIC_2_RET
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_RESUME_LEFT_F5, x=[0x01], y=[0x02], zoom=[0x03]
;@endif

HERO_TICK_VIDEO_074:
	break
	add [0x01], 0x0002
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_VIDEO_074_AND_CINEMATIC_HERO_SHADOW_RET
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_RESUME_LEFT_F4, x=[0x01], y=[0x02], zoom=[0x03]
;@endif

HERO_TICK_VIDEO_073:
	break
	add [0x01], 0x0002
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_VIDEO_073_AND_CIN_002
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_RESUME_LEFT_F3, x=[0x01], y=[0x02], zoom=[0x03]
;@endif

HERO_RESUME_LEFT_F3_DONE:
	add [0x01], 0x0001
	jmp HERO_FALL_L_F2_HOLD_LOOP
	killChannel

