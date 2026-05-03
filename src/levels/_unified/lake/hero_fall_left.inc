HERO_FALL_LEFT_PRELUDE:
	sub [0x01], 0x0004
	video type=1, offset=CINEMATIC_HERO_FALL_PRELUDE_FRAME, x=[0x01], y=[0x02], zoom=[0x03]
	add [0x01], 0x0001
	break

HERO_FALL_LEFT_LOOP:
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_CV_060_061_AND_CIN_002
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_LEFT_PROFILE, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	call DRAW_HELPER_AT_Y_PLUS_1
	je [HERO_POS_MASK], 0x00, HERO_LEFT_PROFILE_DONE_X_INC
	sub [0x01], 0x0002
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_CV_062_063_AND_CIN_002
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, FALL_L_F1_X_DELTA_DONE
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_FALL_LEFT_F1, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	je [HERO_POS_MASK], 0x00, HERO_TICK_BUNDLE_060_061
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	sub [0x01], 0x0001

FALL_L_F1_X_DELTA_DONE:
	sub [0x01], 0x0001
;@elif BRANCH == "chahi_amiga_1991"
	sub [0x01], 0x0002
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_VIDEO_064_065_AND_CINEMATIC_HERO_SHADOW_RET
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_FALL_LEFT_F2, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	mov [0x29], [0x01]
;@if BRANCH in ("cartridge_1992", "gba_2004")
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, FALL_L_F2_X_DELTA_DONE
;@endif
;@if BRANCH == "dos_1992"
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, FALL_L_F2_X_DELTA_DONE
;@endif
	je [HERO_POS_MASK], 0x00, HERO_TICK_BUNDLE_062_063
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	sub [0x01], 0x0001

FALL_L_F2_X_DELTA_DONE:
	sub [0x01], 0x0001
;@elif BRANCH == "chahi_amiga_1991"
	add [0x02], 0x0000
	sub [0x01], 0x0002
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_CV_066_067_AND_CIN_002
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_FALL_LEFT_F3, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	mov [0x29], [0x01]
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	sub [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, FALL_L_F3_X_DELTA_DONE
;@elif BRANCH == "chahi_amiga_1991"
	sub [0x01], 0x0003
	break
	video type=1, offset=CINEMATIC_HERO_FALL_LEFT_F4, x=[0x01], y=[0x02], zoom=[0x03]
	add [0x02], 0x0000
;@endif
	sub [0x01], 0x0002
;@if BRANCH in ("cartridge_1992", "gba_2004")

FALL_L_F3_X_DELTA_DONE:
	break
	call DRAW_CV_068_069_AND_CIN_002
	sub [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, FALL_L_F3_INNER_DONE
	sub [0x01], 0x0001

FALL_L_F3_INNER_DONE:
;@endif
;@if BRANCH == "dos_1992"

FALL_L_F3_X_DELTA_DONE:
	break
	call DRAW_CV_068_069_AND_CIN_002
	sub [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, FALL_L_F3_INNER_DONE
	sub [0x01], 0x0001

FALL_L_F3_INNER_DONE:
;@endif
	break
	play id=0x0051, freq=0x14, vol=0x1D, channel=0x01
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_VIDEO_070_AND_CIN_002
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, FALL_L_F4_X_DELTA_DONE
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_RESUME_LEFT_F0, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	sub [0x01], 0x0002
;@if BRANCH in ("cartridge_1992", "gba_2004")

FALL_L_F4_X_DELTA_DONE:
;@endif
;@if BRANCH == "dos_1992"

FALL_L_F4_X_DELTA_DONE:
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_VIDEO_071_AND_CIN_002
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, HERO_FALL_L_F2_HOLD_LOOP
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_RESUME_LEFT_F1, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	sub [0x01], 0x0002

HERO_FALL_L_F2_HOLD_LOOP:
	break
	mov [0x29], [0x01]
	je [HERO_POS_JUMP_DOWN], 0xFFFF, HERO_WALK_LEFT_LOOP
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_CV_000_072_AND_CIN_002
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_HERO_RESUME_LEFT_F2, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	jne [HERO_POS_MASK], 0x02, HERO_FALL_L_F2_HOLD_LOOP
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, MAYBE_RESUME_WALK_LEFT_IF_GROUNDED
;@elif BRANCH == "chahi_amiga_1991"
	sub [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_HERO_RESUME_LEFT_F3, x=[0x01], y=[0x02], zoom=[0x03]
	je [HERO_POS_MASK], 0x00, HERO_RESUME_LEFT_F3_DONE
	sub [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_HERO_RESUME_LEFT_F4, x=[0x01], y=[0x02], zoom=[0x03]
	je [HERO_POS_MASK], 0x00, HERO_TICK_VIDEO_073
	sub [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_HERO_RESUME_LEFT_F5, x=[0x01], y=[0x02], zoom=[0x03]
	call INVOKE_DRAW_HELPER_ON_BG_PAGE
	mov [0x29], [0x01]
	je [HERO_POS_MASK], 0x00, HERO_TICK_VIDEO_074
	add [0x02], 0x0000
	sub [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_HERO_RESUME_LEFT_F6, x=[0x01], y=[0x02], zoom=[0x03]
	mov [0x29], [0x01]
	sub [0x01], 0x0003
	break
	video type=1, offset=CINEMATIC_HERO_RESUME_LEFT_F7, x=[0x01], y=[0x02], zoom=[0x03]
	add [0x02], 0x0000
	sub [0x01], 0x0002
	break
	play id=0x0051, freq=0x0B, vol=0x20, channel=0x01
	video type=1, offset=CINEMATIC_HERO_RESUME_LEFT_F8, x=[0x01], y=[0x02], zoom=[0x03]
	sub [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_HERO_RESUME_LEFT_F9, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	sub [0x01], 0x0002

MAYBE_RESUME_WALK_LEFT_IF_GROUNDED:
;@if BRANCH in ("cartridge_1992", "gba_2004")
	break
	call DRAW_VIDEO_073_AND_CIN_002
	je [HERO_POS_MASK], 0x00, HERO_RESUME_LEFT_F3_DONE
	sub [0x01], 0x0002
	break
	call DRAW_VIDEO_074_AND_CINEMATIC_HERO_SHADOW_RET
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, RESUME_L_V074_DONE
	je [HERO_POS_MASK], 0x00, HERO_TICK_VIDEO_073
	sub [0x01], 0x0001

RESUME_L_V074_DONE:
	sub [0x01], 0x0001
	break
	call DRAW_VIDEO_075_AND_CINEMATIC_2_RET
	call INVOKE_DRAW_HELPER_ON_BG_PAGE
	mov [0x29], [0x01]
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, RESUME_L_V075_DONE
	je [HERO_POS_MASK], 0x00, HERO_TICK_VIDEO_074
	sub [0x01], 0x0001

RESUME_L_V075_DONE:
	sub [0x01], 0x0001
	break
	call DRAW_VIDEO_076_AND_CIN_002
	mov [0x29], [0x01]
	sub [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, RESUME_L_V076_DONE
	sub [0x01], 0x0002

RESUME_L_V076_DONE:
	break
	call DRAW_VIDEO_077_AND_CIN_002
	sub [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, RESUME_L_V077_DONE
	sub [0x01], 0x0001

RESUME_L_V077_DONE:
	break
	play id=0x0051, freq=0x0B, vol=0x20, channel=0x01
	call DRAW_VIDEO_078_AND_CIN_002
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, RESUME_L_V078_DONE
	sub [0x01], 0x0002

RESUME_L_V078_DONE:
	break
	call DRAW_CV_079_080_AND_CIN_002
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, RESUME_L_CV079080_DONE
	sub [0x01], 0x0002

RESUME_L_CV079080_DONE:
;@endif
;@if BRANCH == "dos_1992"
	break
	call DRAW_VIDEO_073_AND_CIN_002
	je [HERO_POS_MASK], 0x00, HERO_RESUME_LEFT_F3_DONE
	sub [0x01], 0x0002
	break
	call DRAW_VIDEO_074_AND_CINEMATIC_HERO_SHADOW_RET
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, RESUME_L_V074_DONE
	je [HERO_POS_MASK], 0x00, HERO_TICK_VIDEO_073
	sub [0x01], 0x0001

RESUME_L_V074_DONE:
	sub [0x01], 0x0001
	break
	call DRAW_VIDEO_075_AND_CINEMATIC_2_RET
	call INVOKE_DRAW_HELPER_ON_BG_PAGE
	mov [0x29], [0x01]
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, RESUME_L_V075_DONE
	je [HERO_POS_MASK], 0x00, HERO_TICK_VIDEO_074
	sub [0x01], 0x0001

RESUME_L_V075_DONE:
	sub [0x01], 0x0001
	break
	call DRAW_VIDEO_076_AND_CIN_002
	mov [0x29], [0x01]
	sub [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, RESUME_L_V076_DONE
	sub [0x01], 0x0002

RESUME_L_V076_DONE:
	break
	call DRAW_VIDEO_077_AND_CIN_002
	sub [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, RESUME_L_V077_DONE
	sub [0x01], 0x0001

RESUME_L_V077_DONE:
	break
	play id=0x0051, freq=0x0B, vol=0x20, channel=0x01
	call DRAW_VIDEO_078_AND_CIN_002
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, RESUME_L_V078_DONE
	sub [0x01], 0x0002

RESUME_L_V078_DONE:
	break
	call DRAW_CV_079_080_AND_CIN_002
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, RESUME_L_CV079080_DONE
	sub [0x01], 0x0002

RESUME_L_CV079080_DONE:
;@endif
	break
	je [HERO_POS_JUMP_DOWN], 0xFFFF, HERO_WALK_LEFT_LOOP

