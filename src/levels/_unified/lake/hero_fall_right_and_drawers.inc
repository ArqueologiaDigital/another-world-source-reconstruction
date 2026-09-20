.if BRANCH == "chahi_amiga_1991"
CINEMATIC_HERO_STOP_RIGHT_2		EQU 0xF608
.endif
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_HERO_SHADOW		EQU 0xDFFC
CINEMATIC_HERO_SHADOW_STOP_RIGHT_2		EQU 0xDFF2
.endif

CV_5DE4		EQU 0x5DE4
HERO_STAND_LEFT_ARM		EQU 0x3322
HERO_STAND_LEFT_BODY		EQU 0x0358
CV_5DDC		EQU 0x5DDC
CV_0F90		EQU 0x0F90
CV_338E		EQU 0x338E
HERO_WALK_RIGHT_BODY_F00		EQU 0x0FF8
HERO_WALK_RIGHT_ARM_F00		EQU 0x3398
HERO_WALK_RIGHT_BODY_F01		EQU 0x1060
HERO_WALK_RIGHT_ARM_F01		EQU 0x33A2
HERO_WALK_RIGHT_BODY_F02		EQU 0x108C
HERO_WALK_RIGHT_ARM_F02		EQU 0x33AC
HERO_WALK_RIGHT_BODY_F03		EQU 0x10B8
HERO_WALK_RIGHT_ARM_F03		EQU 0x33B6
HERO_WALK_RIGHT_BODY_F04		EQU 0x10E4
HERO_WALK_RIGHT_ARM_F04		EQU 0x33C0
HERO_WALK_RIGHT_BODY_F05		EQU 0x1110
HERO_WALK_RIGHT_ARM_F05		EQU 0x33CA
HERO_WALK_RIGHT_BODY_F06		EQU 0x1136
HERO_WALK_RIGHT_ARM_F06		EQU 0x33D4
HERO_WALK_RIGHT_BODY_F07		EQU 0x115C
HERO_WALK_RIGHT_ARM_F07		EQU 0x33DE
HERO_WALK_RIGHT_BODY_F08		EQU 0x117E
HERO_WALK_RIGHT_ARM_F08		EQU 0x33E8
HERO_WALK_RIGHT_BODY_F09		EQU 0x0CBA
HERO_WALK_RIGHT_ARM_F09		EQU 0x3352
HERO_WALK_RIGHT_BODY_F10		EQU 0x0D48
HERO_WALK_RIGHT_ARM_F10		EQU 0x335C
HERO_WALK_RIGHT_BODY_F11		EQU 0x0DB6
HERO_WALK_RIGHT_ARM_F11		EQU 0x3366
HERO_WALK_RIGHT_BODY_F12		EQU 0x0E38
HERO_WALK_RIGHT_ARM_F12		EQU 0x3370
HERO_WALK_RIGHT_BODY_F13		EQU 0x0EB6
HERO_WALK_RIGHT_ARM_F13		EQU 0x337A
HERO_WALK_RIGHT_BODY_F14		EQU 0x0F28
HERO_WALK_RIGHT_ARM_F14		EQU 0x3384
CV_332A		EQU 0x332A
CV_037C		EQU 0x037C
CV_3332		EQU 0x3332
CV_0764		EQU 0x0764
CV_333A		EQU 0x333A
CV_0790		EQU 0x0790
CV_3342		EQU 0x3342
CV_07BC		EQU 0x07BC
CV_334A		EQU 0x334A
CV_07E8		EQU 0x07E8
CV_0814		EQU 0x0814
CV_0844		EQU 0x0844
CV_0874		EQU 0x0874
CV_08A0		EQU 0x08A0
CV_00B4		EQU 0x00B4
CV_0128		EQU 0x0128
CV_01B0		EQU 0x01B0
CV_0234		EQU 0x0234
CV_331A		EQU 0x331A
CV_02AC		EQU 0x02AC
HERO_RUN_RIGHT_BODY_F00		EQU 0x03E4
HERO_RUN_RIGHT_ARM_F00		EQU 0x34AA
HERO_RUN_RIGHT_BODY_F01		EQU 0x0472
HERO_RUN_RIGHT_ARM_F01		EQU 0x34B2
HERO_RUN_RIGHT_BODY_F05		EQU 0x06A2
HERO_RUN_RIGHT_ARM_F05		EQU 0x34D6
HERO_RUN_RIGHT_BODY_F06		EQU 0x06C8
HERO_RUN_RIGHT_ARM_F06		EQU 0x34DE
HERO_RUN_RIGHT_BODY_F07		EQU 0x06EE
HERO_RUN_RIGHT_ARM_F07		EQU 0x34E6
HERO_RUN_RIGHT_BODY_F08		EQU 0x0714
HERO_RUN_RIGHT_ARM_F08		EQU 0x34EE
HERO_RUN_RIGHT_BODY_F09		EQU 0x073E
HERO_RUN_RIGHT_ARM_F09		EQU 0x34F6
CV_3650		EQU 0x3650
CV_150A		EQU 0x150A
CV_3674		EQU 0x3674
CV_1530		EQU 0x1530
CV_3658		EQU 0x3658
CV_1556		EQU 0x1556
CV_3660		EQU 0x3660
CV_157C		EQU 0x157C
CV_366C		EQU 0x366C
CV_15A2		EQU 0x15A2
CV_11B8		EQU 0x11B8
CV_3638		EQU 0x3638
CV_125A		EQU 0x125A
CV_3640		EQU 0x3640
CV_1304		EQU 0x1304
CV_3648		EQU 0x3648
CV_13B2		EQU 0x13B2
CV_1474		EQU 0x1474
HERO_RUN_RIGHT_BODY_F02		EQU 0x04F4
HERO_RUN_RIGHT_ARM_F02		EQU 0x34BA
HERO_RUN_RIGHT_BODY_F03		EQU 0x058E
HERO_RUN_RIGHT_ARM_F03		EQU 0x34C2
HERO_RUN_RIGHT_BODY_F04		EQU 0x0624
HERO_RUN_RIGHT_ARM_F04		EQU 0x34CE

MAYBE_RESUME_WALK_RIGHT_IF_GROUNDED:
	break
.if BRANCH in ("cartridge_1992", "gba_2004")
	call DRAW_DROPLET_VARIANT_ON_BG
	call DRAW_HERO_STOP_R_BUNDLE_042_043
	mov [0x29], [HERO_X]
	add [HERO_X], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, WAIT_RUN_LEFT_THEN_DECEL
	add [HERO_X], 0x0001

WAIT_RUN_LEFT_THEN_DECEL:
	break
	play id=0x0051, freq=0x0B, vol=0x20, channel=0x01
	call DRAW_HERO_STOP_R_BUNDLE_044_045
.if BRANCH == "cartridge_1992"
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_TICK_BUNDLE_046_047
.elif BRANCH == "gba_2004"
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_TICK_BUNDLE_046_047
.endif
	add [HERO_X], 0x0002

.if BRANCH == "cartridge_1992"
HERO_TICK_BUNDLE_046_047:
.elif BRANCH == "gba_2004"
HERO_TICK_BUNDLE_046_047:
.endif
	break
	call DRAW_HERO_STOP_R_BUNDLE_046_047
.if BRANCH == "cartridge_1992"
	jne [HERO_POS_LEFT_RIGHT], 0x01, RESUME_R_AFTER_VINE_LAND
.elif BRANCH == "gba_2004"
	jne [HERO_POS_LEFT_RIGHT], 0x01, RESUME_R_AFTER_VINE_LAND
.endif
	add [HERO_X], 0x0002

.if BRANCH == "cartridge_1992"
RESUME_R_AFTER_VINE_LAND:
.elif BRANCH == "gba_2004"
RESUME_R_AFTER_VINE_LAND:
.endif
	break
.endif
.if BRANCH == "dos_1992"
	call DRAW_DROPLET_VARIANT_ON_BG
	call DRAW_HERO_STOP_R_BUNDLE_042_043
	mov [0x29], [HERO_X]
	add [HERO_X], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, WAIT_RUN_LEFT_THEN_DECEL
	add [HERO_X], 0x0001

WAIT_RUN_LEFT_THEN_DECEL:
	break
	play id=0x0051, freq=0x0B, vol=0x20, channel=0x01
	call DRAW_HERO_STOP_R_BUNDLE_044_045
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_TICK_BUNDLE_046_047
	add [HERO_X], 0x0002

HERO_TICK_BUNDLE_046_047:
	break
	call DRAW_HERO_STOP_R_BUNDLE_046_047
	jne [HERO_POS_LEFT_RIGHT], 0x01, RESUME_R_AFTER_VINE_LAND
	add [HERO_X], 0x0002

RESUME_R_AFTER_VINE_LAND:
	break
.endif
	je [HERO_POS_JUMP_DOWN], 0xFFFF, HERO_WALK_RIGHT_LOOP

DRAW_LESTER_FRAME_THEN_FALL:
	mov [0x29], [HERO_X]
.if BRANCH in ("cartridge_1992", "gba_2004")
	call DRAW_LESTER_FRAME_BUNDLE
.if BRANCH == "cartridge_1992"
	jne [HERO_POS_MASK], 0x01, RESUME_R_AFTER_VINE_LAND
	jne [HERO_POS_LEFT_RIGHT], 0x01, WAIT_TICK_THEN_HERO_FALL_RIGHT_LOOP
.elif BRANCH == "gba_2004"
	jne [HERO_POS_MASK], 0x01, RESUME_R_AFTER_VINE_LAND
	jne [HERO_POS_LEFT_RIGHT], 0x01, WAIT_TICK_THEN_HERO_FALL_RIGHT_LOOP
.endif
.elif BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_FRAME, x=[HERO_X], y=[HERO_Y], zoom=[0x03]
	jne [HERO_POS_MASK], 0x01, MAYBE_RESUME_WALK_RIGHT_IF_GROUNDED
.elif BRANCH == "dos_1992"
	call DRAW_LESTER_FRAME_BUNDLE
	jne [HERO_POS_MASK], 0x01, RESUME_R_AFTER_VINE_LAND
	jne [HERO_POS_LEFT_RIGHT], 0x01, WAIT_TICK_THEN_HERO_FALL_RIGHT_LOOP
.endif
	add [HERO_X], 0x0002

; One definition, unguarded. dos_1992 used to get a second, identical label on
; the very same address inside a `.if BRANCH == "dos_1992"` arm — two label-only
; lines in a row, which the assembler resolves by keeping one (#0118).
WAIT_TICK_THEN_HERO_FALL_RIGHT_LOOP:
	break
	jmp HERO_FALL_RIGHT_LOOP
	killChannel

.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
DRAW_VIDEO_036_037_AND_HERO_STOP_RIGHT_FRAME_2_RET:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_WALK_RIGHT_ARM_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_STOP_R_BUNDLE_038_039:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_WALK_RIGHT_ARM_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_STOP_R_BUNDLE_040_041:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_WALK_RIGHT_ARM_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_STOP_R_BUNDLE_042_043:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_WALK_RIGHT_ARM_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_STOP_R_BUNDLE_044_045:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F13, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_WALK_RIGHT_ARM_F13, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_STOP_R_BUNDLE_046_047:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_WALK_RIGHT_ARM_F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_LESTER_FRAME_BUNDLE:
	video type=0, offset=CV_5DDC, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=CV_0F90, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=CV_338E, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_STOP_R_BUNDLE_018_019:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_WALK_RIGHT_ARM_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_STOP_R_BUNDLE_020_021:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_WALK_RIGHT_ARM_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_STOP_R_BUNDLE_022_023:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_WALK_RIGHT_ARM_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_STOP_R_BUNDLE_024_025:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_WALK_RIGHT_ARM_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_STOP_R_BUNDLE_026_027:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_WALK_RIGHT_ARM_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_STOP_R_BUNDLE_028_029:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_WALK_RIGHT_ARM_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_STOP_R_BUNDLE_030_031:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_WALK_RIGHT_ARM_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_STOP_R_BUNDLE_015_032_033:
	video type=0, offset=CV_5DDC, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_WALK_RIGHT_BODY_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_WALK_RIGHT_ARM_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_STOP_R_BUNDLE_034_035:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_WALK_RIGHT_ARM_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_STOP_R_BUNDLE_081_082:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_RUN_RIGHT_ARM_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0003
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0003
	ret


DRAW_HERO_STOP_R_BUNDLE_083_084:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_RUN_RIGHT_ARM_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0004
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0004
	ret


DRAW_HERO_STOP_R_BUNDLE_116_117:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_RUN_RIGHT_ARM_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0002
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0002
	ret


DRAW_HERO_STOP_R_BUNDLE_118_119:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_RUN_RIGHT_ARM_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0001
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0001
	ret


DRAW_HERO_STOP_R_BUNDLE_120_121:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_RUN_RIGHT_ARM_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0001
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0001
	ret


DRAW_HERO_STOP_R_BUNDLE_086_087:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_RUN_RIGHT_ARM_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0003
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0003
	ret


DRAW_HERO_STOP_R_BUNDLE_088_089:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_RUN_RIGHT_ARM_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0004
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0004
	ret


DRAW_HERO_STOP_R_BUNDLE_090_091:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_RUN_RIGHT_ARM_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0002
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0002
	ret


DRAW_HERO_STOP_R_BUNDLE_092_093:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_RUN_RIGHT_ARM_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0001
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0001
	ret


DRAW_HERO_STOP_R_BUNDLE_094_095:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_RUN_RIGHT_ARM_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0001
	video offset=CINEMATIC_HERO_SHADOW_STOP_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0001
	ret


DRAW_HERO_WALK_LEFT_F9:
	video type=0, offset=CV_0020, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_WALK_LEFT_F10:
	video type=0, offset=CV_00B4, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_WALK_LEFT_F11:
	video type=0, offset=CV_0128, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_WALK_LEFT_F12:
	video type=0, offset=CV_01B0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_WALK_LEFT_F13:
	video type=0, offset=CV_0234, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_WALK_LEFT_F14:
	video type=0, offset=CV_331A, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=CV_02AC, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_STANDING_LEFT_IDLE:
	video type=0, offset=CV_5DE4, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_STAND_LEFT_ARM, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=HERO_STAND_LEFT_BODY, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_WALK_LEFT_F0:
	video type=0, offset=CV_332A, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=CV_037C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_WALK_LEFT_F1:
	video type=0, offset=CV_3332, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=CV_0764, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_WALK_LEFT_F2:
	video type=0, offset=CV_333A, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=CV_0790, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_WALK_LEFT_F3:
	video type=0, offset=CV_3342, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=CV_07BC, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_WALK_LEFT_F4:
	video type=0, offset=CV_334A, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=CV_07E8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_WALK_LEFT_F5:
	video type=0, offset=CV_0814, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_WALK_LEFT_F6:
	video type=0, offset=CV_0844, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_WALK_LEFT_F7:
	video type=0, offset=CV_5DE4, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=CV_0874, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_WALK_LEFT_F8:
	video type=0, offset=CV_08A0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_SHADOW_2NDSCR_108:
	video type=0, offset=CINEMATIC_SCENARIO_2ND_SCREEN_TO_THE_RIGHT_2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=CV_11B8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0003
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0003
	ret


DRAW_HERO_SHADOW_BUNDLE_109_110:
	video type=0, offset=CV_3638, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=CV_125A, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0004
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0004
	ret


DRAW_HERO_SHADOW_BUNDLE_111_112:
	video type=0, offset=CV_3640, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=CV_1304, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0002
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0002
	ret


DRAW_HERO_SHADOW_BUNDLE_113_114:
	video type=0, offset=CV_3648, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=CV_13B2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0001
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0001
	ret


DRAW_HERO_SHADOW_115:
	video type=0, offset=CV_1474, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0001
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0001
	ret


DRAW_HERO_SHADOW_BUNDLE_097_098:
	video type=0, offset=CV_3650, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=CV_150A, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0003
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0003
	ret


DRAW_HERO_SHADOW_BUNDLE_099_100:
	video type=0, offset=CV_3674, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=CV_1530, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0004
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0004
	ret


DRAW_HERO_SHADOW_BUNDLE_101_102:
	video type=0, offset=CV_3658, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=CV_1556, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0002
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0002
	ret


DRAW_HERO_SHADOW_BUNDLE_103_104:
	video type=0, offset=CV_3660, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=CV_157C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0001
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0001
	ret


DRAW_HERO_SHADOW_BUNDLE_105_106:
	video type=0, offset=CV_366C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	video type=0, offset=CV_15A2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_Y], 0x0001
	video offset=CINEMATIC_HERO_SHADOW, x=[HERO_X], y=[HERO_Y]
	sub [HERO_Y], 0x0001
	ret


POST_RUN_LEFT_DECEL_LOOP:
.elif BRANCH == "chahi_amiga_1991"
WAIT_RUN_LEFT_THEN_DECEL:
.endif
	break
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	je [0x63], 0x05, POST_RUN_LEFT_DECEL_LOOP
.elif BRANCH == "chahi_amiga_1991"
	je [0x63], 0x05, WAIT_RUN_LEFT_THEN_DECEL
.endif
	sub [HERO_X], 0x0003
	break
	sub [HERO_X], 0x0002
	break
	sub [HERO_X], 0x0002
	break
	sub [HERO_X], 0x0001
	break
	sub [HERO_X], 0x0001
	break
	sub [HERO_X], 0x0001
	killChannel

