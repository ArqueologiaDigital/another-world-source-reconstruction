CINEMATIC_HERO_LEAP_RIGHT_F015_BUNDLE		EQU 0x181C
CINEMATIC_HERO_LEAP_RIGHT_F040_BUNDLE		EQU 0x1498
CINEMATIC_HERO_RESUME_RIGHT_3		EQU 0x1784
CINEMATIC_HERO_RESUME_RIGHT_4		EQU 0x17AC
CINEMATIC_HERO_RESUME_RIGHT_5		EQU 0x17D4
CINEMATIC_HERO_RESUME_RIGHT_6		EQU 0x17F8
CINEMATIC_HERO_RESUME_WALK_R_0		EQU 0x1594
CINEMATIC_HERO_RESUME_WALK_R_1		EQU 0x1604
CINEMATIC_HERO_STAND_R_BG_GHOST		EQU 0x1518

HERO_FALL_RIGHT_PRELUDE:
	add [HERO_X], 0x0000
	video offset=CINEMATIC_HERO_FALL_PRELUDE_FRAME, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
	add [HERO_X], 0x0003
	break

HERO_FALL_RIGHT_LOOP:
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_STOP_R_BUNDLE_018_019
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RESUME_RIGHT_0, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
;@endif
	je [HERO_POS_MASK], 0x00, STAND_L_LAND_AFTER_RESUME_R_F0
	add [HERO_X], 0x0002
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_STOP_R_BUNDLE_020_021
	jne [HERO_POS_LEFT_RIGHT], 0x01, FALL_R_F1_X_DELTA_DONE
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RESUME_RIGHT_1, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
;@endif
	je [HERO_POS_MASK], 0x00, STAND_L_LAND_AFTER_RESUME_R_F1
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	add [HERO_X], 0x0001

FALL_R_F1_X_DELTA_DONE:
	add [HERO_X], 0x0001
;@elif BRANCH == "chahi_amiga_1991"
	add [HERO_X], 0x0002
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_STOP_R_BUNDLE_022_023
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RESUME_RIGHT_2, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
;@endif
	call DRAW_HELPER_AT_Y_PLUS_1
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	jne [HERO_POS_LEFT_RIGHT], 0x01, FALL_R_F2_X_DELTA_DONE
;@endif
	je [HERO_POS_MASK], 0x00, STAND_L_LAND_AFTER_RESUME_R_F2
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	add [HERO_X], 0x0001

FALL_R_F2_X_DELTA_DONE:
	add [HERO_X], 0x0001
;@elif BRANCH == "chahi_amiga_1991"
	add [HERO_Y], 0x0000
	add [HERO_X], 0x0002
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_STOP_R_BUNDLE_024_025
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RESUME_RIGHT_3, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
;@endif
	mov [0x29], [HERO_X]
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	add [HERO_X], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_TICK_BUNDLE_026_027
;@elif BRANCH == "chahi_amiga_1991"
	add [HERO_X], 0x0003
	break
	video offset=CINEMATIC_HERO_RESUME_RIGHT_4, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
	mov [0x29], [HERO_X]
	add [HERO_Y], 0x0000
	add [HERO_X], 0x0002
	break
	play id=0x0051, freq=0x14, vol=0x1D, channel=0x01
	video offset=CINEMATIC_HERO_RESUME_RIGHT_5, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
	add [HERO_X], 0x0002
	break
	video offset=CINEMATIC_HERO_RESUME_RIGHT_6, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
;@endif
	add [HERO_X], 0x0002

;@if BRANCH in ("cartridge_1992", "gba_2004")
HERO_TICK_BUNDLE_026_027:
	break
	call DRAW_HERO_STOP_R_BUNDLE_026_027
	mov [0x29], [HERO_X]
	add [HERO_X], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_TICK_BUNDLE_028_029
	add [HERO_X], 0x0001

HERO_TICK_BUNDLE_028_029:
	break
	play id=0x0051, freq=0x14, vol=0x1D, channel=0x01
	call DRAW_HERO_STOP_R_BUNDLE_028_029
;@if BRANCH == "cartridge_1992"
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_TICK_BUNDLE_030_031
;@elif BRANCH == "gba_2004"
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_TICK_BUNDLE_030_031
;@endif
	add [HERO_X], 0x0002

;@if BRANCH == "cartridge_1992"
HERO_TICK_BUNDLE_030_031:
;@elif BRANCH == "gba_2004"
HERO_TICK_BUNDLE_030_031:
;@endif
	break
	call DRAW_HERO_STOP_R_BUNDLE_030_031
;@if BRANCH == "cartridge_1992"
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_TICK_BUNDLE_030_031_DONE
;@elif BRANCH == "gba_2004"
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_TICK_BUNDLE_030_031_DONE
;@endif
	add [HERO_X], 0x0002

;@if BRANCH == "cartridge_1992"
HERO_TICK_BUNDLE_030_031_DONE:
;@elif BRANCH == "gba_2004"
HERO_TICK_BUNDLE_030_031_DONE:
;@endif
;@elif BRANCH == "chahi_amiga_1991"
HERO_TICK_BUNDLE_026_027:
;@elif BRANCH == "dos_1992"
HERO_TICK_BUNDLE_026_027:
	break
	call DRAW_HERO_STOP_R_BUNDLE_026_027
	mov [0x29], [HERO_X]
	add [HERO_X], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_TICK_BUNDLE_028_029
	add [HERO_X], 0x0001

HERO_TICK_BUNDLE_028_029:
	break
	play id=0x0051, freq=0x14, vol=0x1D, channel=0x01
	call DRAW_HERO_STOP_R_BUNDLE_028_029
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_TICK_BUNDLE_030_031
	add [HERO_X], 0x0002

HERO_TICK_BUNDLE_030_031:
	break
	call DRAW_HERO_STOP_R_BUNDLE_030_031
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_TICK_BUNDLE_030_031_DONE
	add [HERO_X], 0x0002

HERO_TICK_BUNDLE_030_031_DONE:
;@endif
	break
	mov [0x29], [HERO_X]
	je [HERO_POS_JUMP_DOWN], 0xFFFF, HERO_WALK_RIGHT_LOOP
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call DRAW_HERO_STOP_R_BUNDLE_015_032_033
;@if BRANCH == "cartridge_1992"
	jne [HERO_POS_MASK], 0x01, HERO_TICK_BUNDLE_030_031_DONE
;@elif BRANCH == "gba_2004"
	jne [HERO_POS_MASK], 0x01, HERO_TICK_BUNDLE_030_031_DONE
;@endif
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LEAP_RIGHT_F015_BUNDLE, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
	jne [HERO_POS_MASK], 0x01, HERO_TICK_BUNDLE_026_027
;@elif BRANCH == "dos_1992"
	call DRAW_HERO_STOP_R_BUNDLE_015_032_033
	jne [HERO_POS_MASK], 0x01, HERO_TICK_BUNDLE_030_031_DONE
;@endif
	add [HERO_X], 0x0002
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_STOP_R_BUNDLE_034_035
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LEAP_RIGHT_F034_BUNDLE, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
;@endif
	je [HERO_POS_MASK], 0x00, STAND_L_LAND_AFTER_LEAP_R_F0
	add [HERO_X], 0x0002
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call DRAW_VIDEO_036_037_AND_HERO_STOP_RIGHT_FRAME_2_RET
;@if BRANCH == "cartridge_1992"
	jne [HERO_POS_LEFT_RIGHT], 0x01, LEAP_R_F036_X_DELTA_DONE
;@elif BRANCH == "gba_2004"
	jne [HERO_POS_LEFT_RIGHT], 0x01, LEAP_R_F036_X_DELTA_DONE
;@endif
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LEAP_RIGHT_F036_BUNDLE, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
;@elif BRANCH == "dos_1992"
	call DRAW_VIDEO_036_037_AND_HERO_STOP_RIGHT_FRAME_2_RET
	jne [HERO_POS_LEFT_RIGHT], 0x01, LEAP_R_F036_X_DELTA_DONE
;@endif
	je [HERO_POS_MASK], 0x00, STAND_L_LAND_AFTER_LEAP_R_F1
;@if BRANCH in ("cartridge_1992", "gba_2004")
	add [HERO_X], 0x0001

;@if BRANCH == "cartridge_1992"
LEAP_R_F036_X_DELTA_DONE:
;@elif BRANCH == "gba_2004"
LEAP_R_F036_X_DELTA_DONE:
;@endif
	add [HERO_X], 0x0001
;@elif BRANCH == "chahi_amiga_1991"
	add [HERO_X], 0x0002
;@elif BRANCH == "dos_1992"
	add [HERO_X], 0x0001

LEAP_R_F036_X_DELTA_DONE:
	add [HERO_X], 0x0001
;@endif
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call DRAW_HERO_STOP_R_BUNDLE_038_039
;@if BRANCH == "cartridge_1992"
	jne [HERO_POS_LEFT_RIGHT], 0x01, LEAP_R_F038_X_DELTA_DONE
;@elif BRANCH == "gba_2004"
	jne [HERO_POS_LEFT_RIGHT], 0x01, LEAP_R_F038_X_DELTA_DONE
;@endif
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LEAP_RIGHT_F038_BUNDLE, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
;@elif BRANCH == "dos_1992"
	call DRAW_HERO_STOP_R_BUNDLE_038_039
	jne [HERO_POS_LEFT_RIGHT], 0x01, LEAP_R_F038_X_DELTA_DONE
;@endif
	je [HERO_POS_MASK], 0x00, STAND_L_LAND_AFTER_LEAP_R_F2
;@if BRANCH in ("cartridge_1992", "gba_2004")
	add [HERO_X], 0x0001

;@if BRANCH == "cartridge_1992"
LEAP_R_F038_X_DELTA_DONE:
;@elif BRANCH == "gba_2004"
LEAP_R_F038_X_DELTA_DONE:
;@endif
	add [HERO_X], 0x0001
;@elif BRANCH == "chahi_amiga_1991"
	add [HERO_Y], 0x0000
	add [HERO_X], 0x0002
;@elif BRANCH == "dos_1992"
	add [HERO_X], 0x0001

LEAP_R_F038_X_DELTA_DONE:
	add [HERO_X], 0x0001
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_STOP_R_BUNDLE_040_041
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LEAP_RIGHT_F040_BUNDLE, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
;@endif
	mov [0x29], [HERO_X]
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	add [HERO_X], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, MAYBE_RESUME_WALK_RIGHT_IF_GROUNDED
;@elif BRANCH == "chahi_amiga_1991"
	add [HERO_X], 0x0003
	break
	call INVOKE_DRAW_HELPER_ON_BG_PAGE
	video offset=CINEMATIC_HERO_STAND_R_BG_GHOST, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
	mov [0x29], [HERO_X]
	add [HERO_Y], 0x0000
	add [HERO_X], 0x0002
	break
	play id=0x0051, freq=0x0B, vol=0x20, channel=0x01
	video offset=CINEMATIC_HERO_RESUME_WALK_R_0, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
	add [HERO_X], 0x0002
	break
	video offset=CINEMATIC_HERO_RESUME_WALK_R_1, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
;@endif
	add [HERO_X], 0x0002

