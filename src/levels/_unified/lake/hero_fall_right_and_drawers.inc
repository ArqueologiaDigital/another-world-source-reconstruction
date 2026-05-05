CINEMATIC_HERO_STOP_RIGHT_2		EQU 0xF608
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_HERO_SHADOW		EQU 0xDFFC
CINEMATIC_HERO_STOP_RIGHT_2		EQU 0xDFF2
;@endif

COMMON_VIDEO_000		EQU 0x5DE4
COMMON_VIDEO_001		EQU 0x3322
COMMON_VIDEO_002		EQU 0x0358
COMMON_VIDEO_015		EQU 0x5DDC
COMMON_VIDEO_016		EQU 0x0F90
COMMON_VIDEO_017		EQU 0x338E
COMMON_VIDEO_018		EQU 0x0FF8
COMMON_VIDEO_019		EQU 0x3398
COMMON_VIDEO_020		EQU 0x1060
COMMON_VIDEO_021		EQU 0x33A2
COMMON_VIDEO_022		EQU 0x108C
COMMON_VIDEO_023		EQU 0x33AC
COMMON_VIDEO_024		EQU 0x10B8
COMMON_VIDEO_025		EQU 0x33B6
COMMON_VIDEO_026		EQU 0x10E4
COMMON_VIDEO_027		EQU 0x33C0
COMMON_VIDEO_028		EQU 0x1110
COMMON_VIDEO_029		EQU 0x33CA
COMMON_VIDEO_030		EQU 0x1136
COMMON_VIDEO_031		EQU 0x33D4
COMMON_VIDEO_032		EQU 0x115C
COMMON_VIDEO_033		EQU 0x33DE
COMMON_VIDEO_034		EQU 0x117E
COMMON_VIDEO_035		EQU 0x33E8
COMMON_VIDEO_036		EQU 0x0CBA
COMMON_VIDEO_037		EQU 0x3352
COMMON_VIDEO_038		EQU 0x0D48
COMMON_VIDEO_039		EQU 0x335C
COMMON_VIDEO_040		EQU 0x0DB6
COMMON_VIDEO_041		EQU 0x3366
COMMON_VIDEO_042		EQU 0x0E38
COMMON_VIDEO_043		EQU 0x3370
COMMON_VIDEO_044		EQU 0x0EB6
COMMON_VIDEO_045		EQU 0x337A
COMMON_VIDEO_046		EQU 0x0F28
COMMON_VIDEO_047		EQU 0x3384
COMMON_VIDEO_060		EQU 0x332A
COMMON_VIDEO_061		EQU 0x037C
COMMON_VIDEO_062		EQU 0x3332
COMMON_VIDEO_063		EQU 0x0764
COMMON_VIDEO_064		EQU 0x333A
COMMON_VIDEO_065		EQU 0x0790
COMMON_VIDEO_066		EQU 0x3342
COMMON_VIDEO_067		EQU 0x07BC
COMMON_VIDEO_068		EQU 0x334A
COMMON_VIDEO_069		EQU 0x07E8
COMMON_VIDEO_070		EQU 0x0814
COMMON_VIDEO_071		EQU 0x0844
COMMON_VIDEO_072		EQU 0x0874
COMMON_VIDEO_073		EQU 0x08A0
COMMON_VIDEO_075		EQU 0x00B4
COMMON_VIDEO_076		EQU 0x0128
COMMON_VIDEO_077		EQU 0x01B0
COMMON_VIDEO_078		EQU 0x0234
COMMON_VIDEO_079		EQU 0x331A
COMMON_VIDEO_080		EQU 0x02AC
COMMON_VIDEO_081		EQU 0x03E4
COMMON_VIDEO_082		EQU 0x34AA
COMMON_VIDEO_083		EQU 0x0472
COMMON_VIDEO_084		EQU 0x34B2
COMMON_VIDEO_086		EQU 0x06A2
COMMON_VIDEO_087		EQU 0x34D6
COMMON_VIDEO_088		EQU 0x06C8
COMMON_VIDEO_089		EQU 0x34DE
COMMON_VIDEO_090		EQU 0x06EE
COMMON_VIDEO_091		EQU 0x34E6
COMMON_VIDEO_092		EQU 0x0714
COMMON_VIDEO_093		EQU 0x34EE
COMMON_VIDEO_094		EQU 0x073E
COMMON_VIDEO_095		EQU 0x34F6
COMMON_VIDEO_097		EQU 0x3650
COMMON_VIDEO_098		EQU 0x150A
COMMON_VIDEO_099		EQU 0x3674
COMMON_VIDEO_100		EQU 0x1530
COMMON_VIDEO_101		EQU 0x3658
COMMON_VIDEO_102		EQU 0x1556
COMMON_VIDEO_103		EQU 0x3660
COMMON_VIDEO_104		EQU 0x157C
COMMON_VIDEO_105		EQU 0x366C
COMMON_VIDEO_106		EQU 0x15A2
COMMON_VIDEO_108		EQU 0x11B8
COMMON_VIDEO_109		EQU 0x3638
COMMON_VIDEO_110		EQU 0x125A
COMMON_VIDEO_111		EQU 0x3640
COMMON_VIDEO_112		EQU 0x1304
COMMON_VIDEO_113		EQU 0x3648
COMMON_VIDEO_114		EQU 0x13B2
COMMON_VIDEO_115		EQU 0x1474
COMMON_VIDEO_116		EQU 0x04F4
COMMON_VIDEO_117		EQU 0x34BA
COMMON_VIDEO_118		EQU 0x058E
COMMON_VIDEO_119		EQU 0x34C2
COMMON_VIDEO_120		EQU 0x0624
COMMON_VIDEO_121		EQU 0x34CE

MAYBE_RESUME_WALK_RIGHT_IF_GROUNDED:
	break
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call INVOKE_DRAW_HELPER_ON_BG_PAGE
	call DRAW_HERO_STOP_R_BUNDLE_042_043
	mov [0x29], [0x01]
	add [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, WAIT_RUN_LEFT_THEN_DECEL
	add [0x01], 0x0001

WAIT_RUN_LEFT_THEN_DECEL:
	break
	play id=0x0051, freq=0x0B, vol=0x20, channel=0x01
	call DRAW_VIDEO_044_045_AND_CINEMATIC_11_RET
;@if BRANCH == "cartridge_1992"
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_TICK_BUNDLE_046_047
;@elif BRANCH == "gba_2004"
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_TICK_BUNDLE_046_047
;@endif
	add [0x01], 0x0002

;@if BRANCH == "cartridge_1992"
HERO_TICK_BUNDLE_046_047:
;@elif BRANCH == "gba_2004"
HERO_TICK_BUNDLE_046_047:
;@endif
	break
	call DRAW_HERO_STOP_R_BUNDLE_046_047
;@if BRANCH == "cartridge_1992"
	jne [HERO_POS_LEFT_RIGHT], 0x01, RESUME_R_AFTER_VINE_LAND
;@elif BRANCH == "gba_2004"
	jne [HERO_POS_LEFT_RIGHT], 0x01, RESUME_R_AFTER_VINE_LAND
;@endif
	add [0x01], 0x0002

;@if BRANCH == "cartridge_1992"
RESUME_R_AFTER_VINE_LAND:
;@elif BRANCH == "gba_2004"
RESUME_R_AFTER_VINE_LAND:
;@endif
	break
;@endif
;@if BRANCH == "dos_1992"
	call INVOKE_DRAW_HELPER_ON_BG_PAGE
	call DRAW_HERO_STOP_R_BUNDLE_042_043
	mov [0x29], [0x01]
	add [0x01], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, WAIT_RUN_LEFT_THEN_DECEL
	add [0x01], 0x0001

WAIT_RUN_LEFT_THEN_DECEL:
	break
	play id=0x0051, freq=0x0B, vol=0x20, channel=0x01
	call DRAW_VIDEO_044_045_AND_CINEMATIC_11_RET
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_TICK_BUNDLE_046_047
	add [0x01], 0x0002

HERO_TICK_BUNDLE_046_047:
	break
	call DRAW_HERO_STOP_R_BUNDLE_046_047
	jne [HERO_POS_LEFT_RIGHT], 0x01, RESUME_R_AFTER_VINE_LAND
	add [0x01], 0x0002

RESUME_R_AFTER_VINE_LAND:
	break
;@endif
	je [HERO_POS_JUMP_DOWN], 0xFFFF, HERO_WALK_RIGHT_LOOP

DRAW_LESTER_FRAME_THEN_FALL:
	mov [0x29], [0x01]
;@if BRANCH in ("cartridge_1992", "gba_2004")
	call DRAW_LESTER_FRAME_BUNDLE
;@if BRANCH == "cartridge_1992"
	jne [HERO_POS_MASK], 0x01, RESUME_R_AFTER_VINE_LAND
	jne [HERO_POS_LEFT_RIGHT], 0x01, JMP_TO_HERO_FALL_RIGHT_LOOP
;@elif BRANCH == "gba_2004"
	jne [HERO_POS_MASK], 0x01, RESUME_R_AFTER_VINE_LAND
	jne [HERO_POS_LEFT_RIGHT], 0x01, JMP_TO_HERO_FALL_RIGHT_LOOP
;@endif
;@elif BRANCH == "chahi_amiga_1991"
	video type=1, offset=CINEMATIC_LESTER_FRAME, x=[0x01], y=[0x02], zoom=[0x03]
	jne [HERO_POS_MASK], 0x01, MAYBE_RESUME_WALK_RIGHT_IF_GROUNDED
;@elif BRANCH == "dos_1992"
	call DRAW_LESTER_FRAME_BUNDLE
	jne [HERO_POS_MASK], 0x01, RESUME_R_AFTER_VINE_LAND
	jne [HERO_POS_LEFT_RIGHT], 0x01, JMP_TO_HERO_FALL_RIGHT_LOOP
;@endif
	add [0x01], 0x0002

JMP_TO_HERO_FALL_RIGHT_LOOP:
;@if BRANCH == "dos_1992"
JMP_TO_HERO_FALL_RIGHT_LOOP:
;@endif
	break
	jmp HERO_FALL_RIGHT_LOOP
	killChannel

;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
DRAW_VIDEO_036_037_AND_HERO_STOP_RIGHT_FRAME_2_RET:
	video type=0, offset=COMMON_VIDEO_036, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_037, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_HERO_STOP_R_BUNDLE_038_039:
	video type=0, offset=COMMON_VIDEO_038, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_039, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_HERO_STOP_R_BUNDLE_040_041:
	video type=0, offset=COMMON_VIDEO_040, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_041, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_HERO_STOP_R_BUNDLE_042_043:
	video type=0, offset=COMMON_VIDEO_042, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_043, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_VIDEO_044_045_AND_CINEMATIC_11_RET:
	video type=0, offset=COMMON_VIDEO_044, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_045, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_HERO_STOP_R_BUNDLE_046_047:
	video type=0, offset=COMMON_VIDEO_046, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_047, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_LESTER_FRAME_BUNDLE:
	video type=0, offset=COMMON_VIDEO_015, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_016, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_017, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_HERO_STOP_R_BUNDLE_018_019:
	video type=0, offset=COMMON_VIDEO_018, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_019, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_HERO_STOP_R_BUNDLE_020_021:
	video type=0, offset=COMMON_VIDEO_020, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_021, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_HERO_STOP_R_BUNDLE_022_023:
	video type=0, offset=COMMON_VIDEO_022, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_023, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_HERO_STOP_R_BUNDLE_024_025:
	video type=0, offset=COMMON_VIDEO_024, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_025, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_HERO_STOP_R_BUNDLE_026_027:
	video type=0, offset=COMMON_VIDEO_026, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_027, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_HERO_STOP_R_BUNDLE_028_029:
	video type=0, offset=COMMON_VIDEO_028, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_029, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_HERO_STOP_R_BUNDLE_030_031:
	video type=0, offset=COMMON_VIDEO_030, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_031, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_HERO_STOP_R_BUNDLE_015_032_033:
	video type=0, offset=COMMON_VIDEO_015, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_032, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_033, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_HERO_STOP_R_BUNDLE_034_035:
	video type=0, offset=COMMON_VIDEO_034, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_035, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_HERO_STOP_R_BUNDLE_081_082:
	video type=0, offset=COMMON_VIDEO_081, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_082, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0003
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0003
	ret

DRAW_HERO_STOP_R_BUNDLE_083_084:
	video type=0, offset=COMMON_VIDEO_083, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_084, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0004
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0004
	ret

DRAW_HERO_STOP_R_BUNDLE_116_117:
	video type=0, offset=COMMON_VIDEO_116, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_117, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0002
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0002
	ret

DRAW_HERO_STOP_R_BUNDLE_118_119:
	video type=0, offset=COMMON_VIDEO_118, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_119, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0001
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0001
	ret

DRAW_HERO_STOP_R_BUNDLE_120_121:
	video type=0, offset=COMMON_VIDEO_120, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_121, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0001
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0001
	ret

DRAW_HERO_STOP_R_BUNDLE_086_087:
	video type=0, offset=COMMON_VIDEO_086, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_087, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0003
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0003
	ret

DRAW_HERO_STOP_R_BUNDLE_088_089:
	video type=0, offset=COMMON_VIDEO_088, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_089, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0004
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0004
	ret

DRAW_HERO_STOP_R_BUNDLE_090_091:
	video type=0, offset=COMMON_VIDEO_090, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_091, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0002
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0002
	ret

DRAW_HERO_STOP_R_BUNDLE_092_093:
	video type=0, offset=COMMON_VIDEO_092, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_093, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0001
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0001
	ret

DRAW_HERO_STOP_R_BUNDLE_094_095:
	video type=0, offset=COMMON_VIDEO_094, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_095, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0001
	video type=1, offset=CINEMATIC_HERO_STOP_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0001
	ret

DRAW_VIDEO_074_AND_CINEMATIC_HERO_SHADOW_RET:
	video type=0, offset=COMMON_VIDEO_074, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_VIDEO_075_AND_CINEMATIC_2_RET:
	video type=0, offset=COMMON_VIDEO_075, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_VIDEO_076_AND_CIN_002:
	video type=0, offset=COMMON_VIDEO_076, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_VIDEO_077_AND_CIN_002:
	video type=0, offset=COMMON_VIDEO_077, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_VIDEO_078_AND_CIN_002:
	video type=0, offset=COMMON_VIDEO_078, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CV_079_080_AND_CIN_002:
	video type=0, offset=COMMON_VIDEO_079, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_080, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CV_000_001_002_AND_CIN_002:
	video type=0, offset=COMMON_VIDEO_000, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_001, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_002, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CV_060_061_AND_CIN_002:
	video type=0, offset=COMMON_VIDEO_060, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_061, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CV_062_063_AND_CIN_002:
	video type=0, offset=COMMON_VIDEO_062, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_063, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_VIDEO_064_065_AND_CINEMATIC_HERO_SHADOW_RET:
	video type=0, offset=COMMON_VIDEO_064, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_065, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CV_066_067_AND_CIN_002:
	video type=0, offset=COMMON_VIDEO_066, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_067, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CV_068_069_AND_CIN_002:
	video type=0, offset=COMMON_VIDEO_068, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_069, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_VIDEO_070_AND_CIN_002:
	video type=0, offset=COMMON_VIDEO_070, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_VIDEO_071_AND_CIN_002:
	video type=0, offset=COMMON_VIDEO_071, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_CV_000_072_AND_CIN_002:
	video type=0, offset=COMMON_VIDEO_000, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_072, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_VIDEO_073_AND_CIN_002:
	video type=0, offset=COMMON_VIDEO_073, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	ret

DRAW_HERO_SHADOW_2NDSCR_108:
	video type=0, offset=CINEMATIC_SCENARIO_2ND_SCREEN_TO_THE_RIGHT_2, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_108, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0003
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0003
	ret

DRAW_HERO_SHADOW_BUNDLE_109_110:
	video type=0, offset=COMMON_VIDEO_109, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_110, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0004
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0004
	ret

DRAW_HERO_SHADOW_BUNDLE_111_112:
	video type=0, offset=COMMON_VIDEO_111, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_112, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0002
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0002
	ret

DRAW_HERO_SHADOW_BUNDLE_113_114:
	video type=0, offset=COMMON_VIDEO_113, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_114, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0001
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0001
	ret

DRAW_HERO_SHADOW_115:
	video type=0, offset=COMMON_VIDEO_115, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0001
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0001
	ret

DRAW_HERO_SHADOW_BUNDLE_097_098:
	video type=0, offset=COMMON_VIDEO_097, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_098, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0003
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0003
	ret

DRAW_HERO_SHADOW_BUNDLE_099_100:
	video type=0, offset=COMMON_VIDEO_099, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_100, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0004
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0004
	ret

DRAW_HERO_SHADOW_BUNDLE_101_102:
	video type=0, offset=COMMON_VIDEO_101, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_102, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0002
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0002
	ret

DRAW_HERO_SHADOW_BUNDLE_103_104:
	video type=0, offset=COMMON_VIDEO_103, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_104, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0001
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0001
	ret

DRAW_HERO_SHADOW_BUNDLE_105_106:
	video type=0, offset=COMMON_VIDEO_105, x=[0x01], y=[0x02], zoom=0x40
	video type=0, offset=COMMON_VIDEO_106, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x0001
	video type=1, offset=CINEMATIC_HERO_SHADOW, x=[0x01], y=[0x02], zoom=0x40
	sub [0x02], 0x0001
	ret

POST_RUN_LEFT_DECEL_LOOP:
;@elif BRANCH == "chahi_amiga_1991"
WAIT_RUN_LEFT_THEN_DECEL:
;@endif
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	je [0x63], 0x05, POST_RUN_LEFT_DECEL_LOOP
;@elif BRANCH == "chahi_amiga_1991"
	je [0x63], 0x05, WAIT_RUN_LEFT_THEN_DECEL
;@endif
	sub [0x01], 0x0003
	break
	sub [0x01], 0x0002
	break
	sub [0x01], 0x0002
	break
	sub [0x01], 0x0001
	break
	sub [0x01], 0x0001
	break
	sub [0x01], 0x0001
	killChannel

