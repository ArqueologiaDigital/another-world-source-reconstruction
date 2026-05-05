;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_HERO_LIFTOFF		EQU 0x054C
;@endif
;@if BRANCH == "chahi_amiga_1991"
CINEMATIC_HERO_LIFTOFF		EQU 0x0E78
;@endif

CINEMATIC_HERO_LEAP_LEFT_0		EQU 0x1884
CINEMATIC_HERO_LEAP_LEFT_1		EQU 0x1928
CINEMATIC_HERO_LEAP_LEFT_2		EQU 0x19D4
CINEMATIC_HERO_LEAP_LEFT_3		EQU 0x1A84
CINEMATIC_HERO_LEAP_LEFT_4		EQU 0x1B48
CINEMATIC_HERO_LEAP_LEFT_5		EQU 0x1BDC
CINEMATIC_HERO_LEAP_LEFT_6		EQU 0x1C04
CINEMATIC_HERO_LEAP_LEFT_7		EQU 0x1C2C
CINEMATIC_HERO_LEAP_LEFT_8		EQU 0x1C54
CINEMATIC_HERO_LEAP_LEFT_9		EQU 0x1C80

DISPATCH_TO_HERO_ACTION_LEFT:
	mov [0x63], 0x0001
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	jmp RESUME_L_CV079080_DONE
;@elif BRANCH == "chahi_amiga_1991"
	jmp MAYBE_RESUME_WALK_LEFT_IF_GROUNDED
;@endif
	killChannel

HERO_LEAP_LEFT_PRELUDE:
	sub [0x01], 0x0004
	video offset=CINEMATIC_HERO_LIFTOFF, x=[0x01], y=[0x02], zoom=[0x03]
	add [0x01], 0x0001
	je [HERO_POS_MASK], 0x00, DISPATCH_TO_HERO_ACTION_LEFT
	break

HERO_STAND_L_IDLE_LOOP:
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_CV_000_001_002_AND_CIN_002
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_STANDING_LEFT_IDLE, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	je [HERO_POS_MASK], 0x00, DISPATCH_TO_HERO_ACTION_LEFT
	break
	je [HERO_POS_MASK], 0x00, HERO_STAND_L_IDLE_LOOP

HERO_LEAP_LEFT_LOOP:
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	setup channel=0x15, address=POST_RUN_LEFT_DECEL_LOOP
;@elif BRANCH == "chahi_amiga_1991"
	setup channel=0x15, address=WAIT_RUN_LEFT_THEN_DECEL
;@endif
	sub [0x01], 0x0004

HERO_LEAP_LEFT_F0_LOOP:
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_SHADOW_2NDSCR_108
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LEAP_LEFT_0, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	mov [0x29], [0x01]
	sub [0x01], 0x0006
	play id=0x0051, freq=0x0F, vol=0x28, channel=0x01
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_SHADOW_BUNDLE_109_110
	je [HERO_POS_JUMP_DOWN], 0xFFFF, HERO_RUN_LEFT_ENTRY_WITH_PREP
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LEAP_LEFT_1, x=[0x01], y=[0x02], zoom=[0x03]
	je [HERO_POS_JUMP_DOWN], 0xFFFF, HERO_RUN_LEFT_ENTRY_WITH_PREP
;@endif
	sub [0x01], 0x0008
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_SHADOW_BUNDLE_111_112
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LEAP_LEFT_2, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	sub [0x01], 0x0008
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_SHADOW_BUNDLE_113_114
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LEAP_LEFT_3, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	mov [0x29], [0x01]
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_SHADOW_115
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LEAP_LEFT_4, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	mov [0x29], [0x01]
	add [0x02], 0x0000
	je [HERO_POS_MASK], 0x00, DISPATCH_TO_HERO_ACTION_LEFT
	sub [0x01], 0x000A
	break

HERO_LEAP_LEFT_F5_LOOP:
	mov [0x63], 0x0005
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_SHADOW_BUNDLE_097_098
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LEAP_LEFT_5, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	mov [0x29], [0x01]
	sub [0x01], 0x0006
	play id=0x0051, freq=0x0A, vol=0x28, channel=0x01
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_SHADOW_BUNDLE_099_100
	je [HERO_POS_JUMP_DOWN], 0xFFFF, HERO_RUN_LEFT_ENTRY_WITH_PREP
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LEAP_LEFT_6, x=[0x01], y=[0x02], zoom=[0x03]
	je [HERO_POS_JUMP_DOWN], 0xFFFF, HERO_RUN_LEFT_ENTRY_WITH_PREP
;@endif
	sub [0x01], 0x0008
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_SHADOW_BUNDLE_101_102
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LEAP_LEFT_7, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	sub [0x01], 0x0008
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_SHADOW_BUNDLE_103_104
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LEAP_LEFT_8, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	mov [0x29], [0x01]
	sub [0x01], 0x0008
	add [0x02], 0x0000
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_HERO_SHADOW_BUNDLE_105_106
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LEAP_LEFT_9, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	mov [0x29], [0x01]
	add [0x02], 0x0000
	je [HERO_POS_MASK], 0x00, DISPATCH_TO_HERO_ACTION_LEFT
	sub [0x01], 0x000A
	break
	jmp HERO_LEAP_LEFT_F0_LOOP
	killChannel

WAIT_RUN_RIGHT_THEN_DECEL:
	break
	je [0x63], 0x06, WAIT_RUN_RIGHT_THEN_DECEL
	add [0x01], 0x0003
	break
	add [0x01], 0x0002
	break
	add [0x01], 0x0002
	break
	add [0x01], 0x0001
	break
	add [0x01], 0x0001
	break
	add [0x01], 0x0001
	killChannel

DISPATCH_TO_HERO_ACTION_RIGHT:
	mov [0x63], 0x0002
;@if BRANCH == "cartridge_1992"
	jmp RESUME_R_AFTER_VINE_LAND
;@elif BRANCH in ("dos_1992", "gba_2004")
	jmp RESUME_R_AFTER_VINE_LAND
;@elif BRANCH == "chahi_amiga_1991"
	jmp MAYBE_RESUME_WALK_RIGHT_IF_GROUNDED
;@endif
	killChannel

HERO_LEAP_RIGHT_PRELUDE:
	video offset=CINEMATIC_HERO_LIFTOFF, x=[0x01], y=[0x02], zoom=[0x03]
	add [0x01], 0x0003
	je [HERO_POS_MASK], 0x00, DISPATCH_TO_HERO_ACTION_RIGHT
	break

MAYBE_LESTER_FRAME_LOOP:
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	call DRAW_LESTER_FRAME_BUNDLE
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_FRAME, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	je [HERO_POS_MASK], 0x00, DISPATCH_TO_HERO_ACTION_RIGHT
	break
	je [HERO_POS_MASK], 0x00, MAYBE_LESTER_FRAME_LOOP

