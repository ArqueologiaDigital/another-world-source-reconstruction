HERO_STAND_LEFT_LOOP:
	mov [0x29], [0x01]
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_CV_000_001_002_AND_CIN_002
	jne [HERO_POS_MASK], 0x02, RESUME_L_CV079080_DONE
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, STAND_L_FALL_LEFT_PATH
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_STANDING_LEFT_IDLE, x=[0x01], y=[0x02], zoom=[0x03]
	jne [HERO_POS_MASK], 0x02, MAYBE_RESUME_WALK_LEFT_IF_GROUNDED
;@endif
	sub [0x01], 0x0002
;@if BRANCH in ("cartridge_1992", "gba_2004")

STAND_L_FALL_LEFT_PATH:
;@endif
;@if BRANCH == "dos_1992"

STAND_L_FALL_LEFT_PATH:
;@endif
	break
	jmp HERO_FALL_LEFT_LOOP
	killChannel
	break
	sub [0x01], 0x0002
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_STOP_R_BUNDLE_022_023
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_RESUME_RIGHT_F2, x=[0x01], y=[0x02], zoom=[0x03]
;@endif

STAND_L_LAND_AFTER_RESUME_R_F2:
	break
	sub [0x01], 0x0002
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_STOP_R_BUNDLE_020_021
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_RESUME_RIGHT_F1, x=[0x01], y=[0x02], zoom=[0x03]
;@endif

STAND_L_LAND_AFTER_RESUME_R_F1:
	break
	sub [0x01], 0x0002
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_STOP_R_BUNDLE_018_019
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_RESUME_RIGHT_F0, x=[0x01], y=[0x02], zoom=0x40
;@endif

STAND_L_LAND_AFTER_RESUME_R_F0:
	sub [0x01], 0x0001
;@if BRANCH == "cartridge_1992"
	jmp RESUME_R_AFTER_VINE_LAND
;@elif BRANCH in ("dos_1992", "gba_2004")
	jmp RESUME_R_AFTER_VINE_LAND
;@elif BRANCH == "chahi_amiga_1991"
	jmp MAYBE_RESUME_WALK_RIGHT_IF_GROUNDED
;@endif
	break
	sub [0x01], 0x0002
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_STOP_R_BUNDLE_038_039
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_LEAP_RIGHT_F038_BUNDLE, x=[0x01], y=[0x02], zoom=[0x03]
;@endif

STAND_L_LAND_AFTER_LEAP_R_F2:
	break
	sub [0x01], 0x0002
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_VIDEO_036_037_AND_HERO_STOP_RIGHT_FRAME_2_RET
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_LEAP_RIGHT_F036_BUNDLE, x=[0x01], y=[0x02], zoom=[0x03]
;@endif

STAND_L_LAND_AFTER_LEAP_R_F1:
	break
	sub [0x01], 0x0002
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_STOP_R_BUNDLE_034_035
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_LEAP_RIGHT_F034_BUNDLE, x=[0x01], y=[0x02], zoom=[0x03]
;@endif

STAND_L_LAND_AFTER_LEAP_R_F0:
	sub [0x01], 0x0001
;@if BRANCH == "cartridge_1992"
	jmp HERO_TICK_BUNDLE_030_031_DONE
;@elif BRANCH == "chahi_amiga_1991"
	jmp HERO_TICK_BUNDLE_026_027
;@elif BRANCH in ("dos_1992", "gba_2004")
	jmp HERO_TICK_BUNDLE_030_031_DONE
;@endif
	killChannel

