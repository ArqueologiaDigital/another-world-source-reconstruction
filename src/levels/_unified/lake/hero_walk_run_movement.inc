HERO_WALK_RIGHT_LOOP:
	mov [0x63], 0x0064
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	je [HERO_POS_MASK], 0x0A, HERO_WALK_LEFT_LOOP
	video type=0, offset=COMMON_VIDEO_003, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_WALK_RIGHT_0, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_RIGHT_0, x=[0x01], y=[0x02], zoom=0x40
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_004, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_WALK_RIGHT_1, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_RIGHT_1, x=[0x01], y=[0x02], zoom=0x40
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_005, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_WALK_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_006, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_WALK_RIGHT_3, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_RIGHT_3, x=[0x01], y=[0x02], zoom=0x40
;@endif
	add [0x01], 0x0005
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_007, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_RUN_RIGHT_0, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_RIGHT_0, x=[0x01], y=[0x02], zoom=0x40
;@endif
	add [0x01], 0x0007
	mov [0x1B], 0x0001
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_008, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	video offset=CINEMATIC_HERO_WALK_RIGHT_1, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_RIGHT_1, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000D
	break
	video offset=CINEMATIC_HERO_RUN_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
;@endif
	add [0x01], 0x000C
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_009, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_RUN_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000C
	break
	video type=0, offset=COMMON_VIDEO_010, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_RUN_RIGHT_4, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_RIGHT_4, x=[0x01], y=[0x02], zoom=0x40
;@endif
	add [0x01], 0x0002
	break
	mov [0x1B], 0x0000
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_011, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_WALK_RIGHT_0, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_RIGHT_5, x=[0x01], y=[0x02], zoom=0x40
;@endif
	add [0x01], 0x0007
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_012, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_STOP_RIGHT_0, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_STOP_RIGHT_0, x=[0x01], y=[0x02], zoom=0x40
;@endif
	add [0x01], 0x0004
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_013, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0005
	video offset=CINEMATIC_HERO_WALK_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000C
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_STOP_RIGHT_1, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0007
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_014, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
;@endif
	break
	mov [0x63], 0x0002
	jmp DRAW_LESTER_FRAME_THEN_FALL
	killChannel

HERO_RUN_RIGHT_ENTRY_WITH_PREP:
;@if BRANCH in ("cartridge_1992", "gba_2004")
	je [HERO_POS_MASK], 0x0A, HERO_RUN_LEFT_ENTRY_WITH_PREP
;@endif
;@if BRANCH == "dos_1992"
	je [HERO_POS_MASK], 0x0A, HERO_RUN_LEFT_ENTRY_WITH_PREP
;@endif
	add [0x01], 0x0005
	add [0x01], 0x0007
	setup channel=0x15, address=KILL_CHANNEL_ROUTINE
	mov [0x63], 0x0064
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")

HERO_RUN_RIGHT_LOOP:
	setup channel=0x15, address=KILL_CHANNEL_ROUTINE
	je [HERO_POS_MASK], 0x0A, HERO_RUN_LEFT_LOOP
	video type=0, offset=COMMON_VIDEO_008, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	video offset=CINEMATIC_HERO_WALK_RIGHT_1, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000C
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_RIGHT_1, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000D
;@endif
	sub [0x02], 0x0002
	mov [0x1B], 0x0001
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_009, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_RUN_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
;@endif
	add [0x01], 0x000C
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_085, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	video offset=CINEMATIC_HERO_RUN_RIGHT_4, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000B
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_RIGHT_3, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000C
;@endif
	add [0x02], 0x0001
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_085, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	video offset=CINEMATIC_HERO_RUN_RIGHT_4, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000B
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_RIGHT_3, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000C
;@endif
	add [0x02], 0x0001
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_010, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_RUN_RIGHT_4, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_RIGHT_4, x=[0x01], y=[0x02], zoom=0x40
;@endif
	add [0x01], 0x0002
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_011, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_WALK_RIGHT_0, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_RIGHT_5, x=[0x01], y=[0x02], zoom=0x40
;@endif
	add [0x01], 0x0007
	mov [0x1B], 0x0000
	break
	add [0x01], 0x0005
	je [HERO_ACTION], 0x01, HERO_LEAP_R_F5_TO_F9_ENTRY
	sub [0x01], 0x0005
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_012, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_STOP_RIGHT_0, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_STOP_RIGHT_0, x=[0x01], y=[0x02], zoom=0x40
;@endif
	add [0x01], 0x0004
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_013, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0005
	video offset=CINEMATIC_HERO_WALK_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000C
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_STOP_RIGHT_1, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0007
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_014, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
;@endif
	break
	mov [0x63], 0x0002
	jmp DRAW_LESTER_FRAME_THEN_FALL
	killChannel

HERO_WALK_LEFT_LOOP:
	mov [0x63], 0x0064
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	je [HERO_POS_MASK], 0x09, HERO_WALK_RIGHT_LOOP
	video type=0, offset=COMMON_VIDEO_048, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_WALK_LEFT_0, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_LEFT_0, x=[0x01], y=[0x02], zoom=0x40
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_049, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_WALK_LEFT_1, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_LEFT_1, x=[0x01], y=[0x02], zoom=0x40
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_050, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_WALK_LEFT_2, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_LEFT_2, x=[0x01], y=[0x02], zoom=0x40
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_051, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_WALK_LEFT_3, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_WALK_LEFT_3, x=[0x01], y=[0x02], zoom=0x40
;@endif
	sub [0x01], 0x0005
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_052, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_RUN_LEFT_0, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_LEFT_0, x=[0x01], y=[0x02], zoom=0x40
;@endif
	sub [0x01], 0x0007
	mov [0x1B], 0x0001
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_053, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	video offset=CINEMATIC_HERO_WALK_LEFT_1, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_LEFT_1, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000D
	break
	video offset=CINEMATIC_HERO_RUN_LEFT_2, x=[0x01], y=[0x02], zoom=0x40
;@endif
	sub [0x01], 0x000C
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_054, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_RUN_LEFT_2, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000C
	break
	video type=0, offset=COMMON_VIDEO_055, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_RUN_LEFT_4, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_LEFT_4, x=[0x01], y=[0x02], zoom=0x40
;@endif
	sub [0x01], 0x0002
	break
	mov [0x1B], 0x0000
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_056, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_WALK_LEFT_0, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_LEFT_5, x=[0x01], y=[0x02], zoom=0x40
;@endif
	sub [0x01], 0x0007
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_057, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_STOP_LEFT_0, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_STOP_LEFT_0, x=[0x01], y=[0x02], zoom=0x40
;@endif
	sub [0x01], 0x0004
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_058, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0006
	video offset=CINEMATIC_HERO_WALK_LEFT_2, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000D
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_STOP_LEFT_1, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0007
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_059, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	video offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_STOP_LEFT_2, x=[0x01], y=[0x02], zoom=0x40
;@endif
	break
	mov [0x63], 0x0001
	jmp HERO_STAND_LEFT_LOOP
	killChannel

;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
HERO_RUN_LEFT_ENTRY_WITH_PREP:
	je [HERO_POS_MASK], 0x09, HERO_RUN_RIGHT_ENTRY_WITH_PREP
;@elif BRANCH == "chahi_amiga_1991"
HERO_RUN_LEFT_ENTRY_WITH_PREP:
;@endif
	sub [0x01], 0x0005
	sub [0x01], 0x0007
	setup channel=0x15, address=KILL_CHANNEL_ROUTINE
	mov [0x63], 0x0064
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")

HERO_RUN_LEFT_LOOP:
	setup channel=0x15, address=KILL_CHANNEL_ROUTINE
	je [HERO_POS_MASK], 0x09, HERO_RUN_RIGHT_LOOP
;@endif
;@if BRANCH == "dos_1992"

HERO_RUN_LEFT_LOOP:
	setup channel=0x15, address=KILL_CHANNEL_ROUTINE
	je [HERO_POS_MASK], 0x09, HERO_RUN_RIGHT_LOOP
;@endif
	mov [0x1B], 0x0001
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_053, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	video offset=CINEMATIC_HERO_WALK_LEFT_1, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000C
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_LEFT_1, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000D
;@endif
	sub [0x02], 0x0002
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_054, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_RUN_LEFT_2, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_LEFT_2, x=[0x01], y=[0x02], zoom=0x40
;@endif
	sub [0x01], 0x000C
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_096, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	video offset=CINEMATIC_HERO_RUN_LEFT_4, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000B
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_LEFT_3, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000C
;@endif
	add [0x02], 0x0001
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_096, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	video offset=CINEMATIC_HERO_RUN_LEFT_4, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000B
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_LEFT_3, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000C
;@endif
	add [0x02], 0x0001
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_055, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_RUN_LEFT_4, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_LEFT_4, x=[0x01], y=[0x02], zoom=0x40
;@endif
	sub [0x01], 0x0002
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_056, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_WALK_LEFT_0, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_RUN_LEFT_5, x=[0x01], y=[0x02], zoom=0x40
;@endif
	sub [0x01], 0x0007
	mov [0x1B], 0x0000
	break
	sub [0x01], 0x0005
	je [HERO_ACTION], 0x01, HERO_LEAP_LEFT_F5_LOOP
	add [0x01], 0x0005
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_057, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_HERO_STOP_LEFT_0, x=[0x01], y=[0x02], zoom=0x40
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_STOP_LEFT_0, x=[0x01], y=[0x02], zoom=0x40
;@endif
	sub [0x01], 0x0004
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_058, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0006
	video offset=CINEMATIC_HERO_WALK_LEFT_2, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000D
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_STOP_LEFT_1, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0007
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	video type=0, offset=COMMON_VIDEO_059, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	video offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_STOP_LEFT_2, x=[0x01], y=[0x02], zoom=0x40
;@endif
	break
	mov [0x63], 0x0001
	jmp HERO_STAND_LEFT_LOOP
	killChannel
	add [0x01], 0x0004
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video offset=CINEMATIC_HERO_LAND_LEFT, x=[0x01], y=[0x02], zoom=[0x03]
;@elif BRANCH == "gba_2004"
	video offset=ADDR_AT_08FC, x=[0x01], y=[0x02], zoom=[0x03]
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LAND_LEFT, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	break
	sub [0x01], 0x0001
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video offset=CINEMATIC_HERO_LAND_LEFT, x=[0x01], y=[0x02], zoom=[0x03]
;@elif BRANCH == "gba_2004"
	video offset=ADDR_AT_08FC, x=[0x01], y=[0x02], zoom=[0x03]
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LAND_LEFT, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	sub [0x01], 0x0001

HERO_LAND_LEFT_HOLD_LOOP:
	break
;@if BRANCH in ("cartridge_1992", "dos_1992")
	video offset=CINEMATIC_HERO_LAND_LEFT, x=[0x01], y=[0x02], zoom=[0x03]
;@elif BRANCH == "gba_2004"
	video offset=ADDR_AT_08FC, x=[0x01], y=[0x02], zoom=[0x03]
;@elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_HERO_LAND_LEFT, x=[0x01], y=[0x02], zoom=[0x03]
;@endif
	je [HERO_ACTION_POS_MASK], 0x88, HERO_LAND_LEFT_HOLD_LOOP
	break
	sub [0x01], 0x0002
	video offset=CINEMATIC_RIGHT_KICK_1, x=[0x01], y=[0x02], zoom=[0x03]
	mov [0x63], 0x0002
	sub [0x01], 0x0002
;@if BRANCH == "cartridge_1992"
	jmp RESUME_R_AFTER_VINE_LAND
;@elif BRANCH in ("dos_1992", "gba_2004")
	jmp RESUME_R_AFTER_VINE_LAND
;@elif BRANCH == "chahi_amiga_1991"
	jmp MAYBE_RESUME_WALK_RIGHT_IF_GROUNDED
;@endif
	killChannel

