LABEL_74FA:
	mov [0x21], [0x28]
	sub [0x22], [0x2A]
	call LABEL_7522
	add [0x22], [0x2A]
	jle [0x22], [HERO_X], COPY_VAR01_TO_VAR28
	mov [HERO_X], [0x22]
	mov [0x28], [HERO_X]
	ret


LABEL_7513:
	db 0x11

LABEL_7514:
	mov [0x23], 0x0000
	jg [0x27], [0x44], LABEL_7522
	mov [0x23], 0x0001

LABEL_7522:
	jl [0x22], [0x21], LABEL_7573
	je [0x23], 0x00, LABEL_753E
	jg [0x47], [0x22], LABEL_754B
	mov [0x22], [0x47]
	mov [0x1D], 0x0004
	jmp LABEL_754B

LABEL_753E:
	jg [0x43], [0x22], LABEL_754B
	mov [0x22], [0x43]
	mov [0x1D], 0x0002

LABEL_754B:
	mov [0x24], [0x48]
	mov [0x25], [0x49]
	mov [0x1C], 0x000A
	call LABEL_7642
	mov [0x24], [0x4A]
	mov [0x25], [0x4B]
	mov [0x1C], 0x000B
	call LABEL_7642
	mov [0x24], [0x4C]
	mov [0x25], [0x4D]
	mov [0x1C], 0x000C
	call LABEL_7642
	ret


LABEL_7573:
	je [0x23], 0x00, LABEL_7589
	jl [0x46], [0x22], LABEL_7596
	mov [0x22], [0x46]
	mov [0x1D], 0x0003
	jmp LABEL_7596

LABEL_7589:
	jl [0x42], [0x22], LABEL_7596
	mov [0x22], [0x42]
	mov [0x1D], 0x0001

LABEL_7596:
	mov [0x24], [0x48]
	mov [0x25], [0x49]
	mov [0x1C], 0x000A
	call LABEL_75BE
	mov [0x24], [0x4A]
	mov [0x25], [0x4B]
	mov [0x1C], 0x000B
	call LABEL_75BE
	mov [0x24], [0x4C]
	mov [0x25], [0x4D]
	mov [0x1C], 0x000C
	call LABEL_75BE
	ret


LABEL_75BE:
	jge [0x25], 0x2000, LABEL_7641
	jge [0x25], 0x1000, LABEL_75D5
	je [0x23], 0x01, LABEL_7641
	jmp LABEL_75DF

LABEL_75D5:
	sub [0x25], 0x1000
	je [0x23], 0x00, LABEL_7641

LABEL_75DF:
	add [0x24], 0x0008
	jl [0x25], 0x0200, LABEL_7600
	sub [0x25], 0x0200
	jg [0x24], [0x21], LABEL_7641
	jl [0x24], [0x22], LABEL_7600
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

LABEL_7600:
	add [0x24], 0x000A
	jl [0x25], 0x0100, LABEL_7621
	sub [0x25], 0x0100
	jg [0x24], [0x21], LABEL_7641
	jl [0x24], [0x22], LABEL_7621
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

LABEL_7621:
	add [0x24], 0x000A
	jl [0x25], 0x80, LABEL_7641
	sub [0x25], 0x0080
	jg [0x24], [0x21], LABEL_7641
	jl [0x24], [0x22], LABEL_7641
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

LABEL_7641:
	ret


LABEL_7642:
	jge [0x25], 0x2000, LABEL_76AF
	jge [0x25], 0x1000, LABEL_7659
	je [0x23], 0x01, LABEL_76AF
	jmp LABEL_7663

LABEL_7659:
	sub [0x25], 0x1000
	je [0x23], 0x00, LABEL_76AF

LABEL_7663:
	jl [0x25], 0x0200, LABEL_7679
	jl [0x24], [0x21], LABEL_7679
	jg [0x24], [0x22], LABEL_7679
	jmp LABEL_76A9

LABEL_7679:
	add [0x24], 0x000A
	jl [0x25], 0x0100, LABEL_7693
	jl [0x24], [0x21], LABEL_7693
	jg [0x24], [0x22], LABEL_7693
	jmp LABEL_76A9

LABEL_7693:
	add [0x24], 0x000A
	jl [0x25], 0x80, LABEL_76AF
	jl [0x24], [0x21], LABEL_76AF
	jg [0x24], [0x22], LABEL_76AF

LABEL_76A9:
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

LABEL_76AF:
	ret


DRAW_HERO_SPRITE_BY_VAR09_0E:
	mov [0xF8], [0x09]
	shr [0xF8], 0x0004
	and [0xF8], 0x000F
	jne [0x0E], 0x00, LABEL_76F2
	je [0xF8], 0x00, DRAW_HERO_POSE_0_0
	je [0xF8], 0x01, DRAW_HERO_POSE_0_1
	je [0xF8], 0x02, DRAW_HERO_POSE_0_2
	je [0xF8], 0x03, DRAW_HERO_POSE_0_3
	je [0xF8], 0x04, DRAW_HERO_POSE_0_4
	je [0xF8], 0x05, DRAW_ALIEN_POSE_0_5
	je [0xF8], 0x06, DRAW_HERO_POSE_0_6
	je [0xF8], 0x07, DRAW_HERO_POSE_0_7
	ret


LABEL_76F2:
	jne [0x0E], 0x01, LABEL_76FB
	jmp DRAW_HERO_POSE_1

LABEL_76FB:
	jne [0x0E], 0x02, LABEL_7704
	jmp DRAW_HERO_POSE_2

LABEL_7704:
	jne [0x0E], 0x03, LABEL_7713
	je [0xF8], 0x03, DRAW_CIN_015
	jmp DRAW_CIN_019

LABEL_7713:
	jne [0x0E], 0x04, LABEL_7722
	je [0xF8], 0x03, DRAW_CIN_017
	jmp DRAW_CIN_018

LABEL_7722:
	jne [0x0E], 0x05, LABEL_7731
	je [0xF8], 0x03, DRAW_CIN_015
	jmp DRAW_CIN_016

LABEL_7731:
	jne [0x0E], 0x06, LABEL_773D
	video offset=CINEMATIC_014, x=[BUDDY_X], y=[BUDDY_Y]
	ret


LABEL_773D:
	jne [0x0E], 0x07, LABEL_7750
	je [0xF8], 0x00, DRAW_CIN_012
	je [0xF8], 0x01, DRAW_CIN_013
	ret


LABEL_7750:
	ret


LABEL_7751:
	db 0x11

DRAW_HERO_POSE_0_0:
	video offset=CINEMATIC_022, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_HERO_POSE_0_1:
	video offset=CINEMATIC_023, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_HERO_POSE_0_2:
	video offset=CINEMATIC_024, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_HERO_POSE_0_3:
	video offset=CINEMATIC_025, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_HERO_POSE_0_4:
	video offset=CINEMATIC_026, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_ALIEN_POSE_0_5:
	video offset=CINEMATIC_027, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_HERO_POSE_0_6:
	video offset=CINEMATIC_028, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_HERO_POSE_0_7:
	video offset=CINEMATIC_029, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_HERO_POSE_1:
	video offset=CINEMATIC_021, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_HERO_POSE_2:
	video offset=CINEMATIC_020, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_CIN_019:
	video offset=CINEMATIC_019, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_CIN_015:
	video offset=CINEMATIC_015, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_CIN_018:
	video offset=CINEMATIC_018, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_CIN_017:
	video offset=CINEMATIC_017, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_CIN_016:
	video offset=CINEMATIC_016, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_CIN_012:
	video offset=CINEMATIC_012, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_CIN_013:
	video offset=CINEMATIC_013, x=[BUDDY_X], y=[BUDDY_Y]
	ret


LABEL_77B8:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_247
	je [0xF8], 0x02, DRAW_CIN_248
	ret


DRAW_CIN_247:
	video offset=CINEMATIC_247, x=[0xf5], y=[BUDDY_Y]
	ret


DRAW_CIN_248:
	video offset=CINEMATIC_248, x=[0xf5], y=[BUDDY_Y]
	ret


LABEL_77D8:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, LABEL_77EC
	je [0xF8], 0x02, LABEL_7802
	ret


LABEL_77EC:
	add [BUDDY_Y], 0x000D
	sub [BUDDY_X], 0x0002
	video offset=CINEMATIC_112, x=[BUDDY_X], y=[BUDDY_Y]
	add [BUDDY_X], 0x0002
	sub [BUDDY_Y], 0x000D
	ret


LABEL_7802:
	add [BUDDY_Y], 0x000D
	sub [BUDDY_X], 0x0002
	video offset=CINEMATIC_113, x=[BUDDY_X], y=[BUDDY_Y]
	add [BUDDY_X], 0x0002
	sub [BUDDY_Y], 0x000D
	ret


LABEL_7818:
	video type=0, offset=CV_3EEC, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jg [0xF6], 0x00, LABEL_782B
	video type=0, offset=CV_6004, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_782B:
	jg [0x13], [0x30], LABEL_77B8
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_77B8
	video type=0, offset=CV_5CBC, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp LABEL_77B8

LABEL_7846:
	video type=0, offset=CV_3F4A, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, LABEL_785D
	video type=0, offset=CV_6010, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_785D:
	jg [0x13], [0x30], LABEL_77B8
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_77B8
	video type=0, offset=CV_5CC4, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp LABEL_77B8

LABEL_7878:
	video type=0, offset=CV_4058, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jg [0x13], [0x30], LABEL_77D8
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_77D8
	video type=0, offset=CV_5CCC, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp LABEL_77D8

LABEL_7898:
	video type=0, offset=CV_4416, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp LABEL_77D8

LABEL_78A0:
	sub [BUDDY_X], 0x0001
	call CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L22
	add [BUDDY_X], 0x0001
	ret


CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L22:
	video type=0, offset=CV_FIGURE_GUN_LIMB_LEFT_POSE_00, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_FIGURE_GUN_LIMB_LEFT_POSE_00_CHARGE_BLINK, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	ret


CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L18:
	sub [BUDDY_X], 0x0001
	call CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L13
	add [BUDDY_X], 0x0001
	ret


CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L13:
	video type=0, offset=CV_FIGURE_GUN_LIMB_LEFT_POSE_01, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_FIGURE_GUN_LIMB_LEFT_POSE_01_CHARGE_BLINK, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	ret


DRAW_CV_304_THEN_305:
	video type=0, offset=CV_FIGURE_GUN_LIMB_LEFT_POSE_02, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_FIGURE_GUN_LIMB_LEFT_POSE_02_CHARGE_BLINK, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	ret


CAPSULE_DRAW_CV204_AT_X07_Y08_L2:
	add [BUDDY_X], 0x0001
	call DRAW_CV_304_THEN_305
	sub [BUDDY_X], 0x0001
	ret


SHARED_RET:
	ret


BUDDY_RIGHT_SUBFRAME_3_DISPATCH:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_030
	je [0xF8], 0x02, DRAW_CIN_031
	je [0xF8], 0x03, DRAW_CIN_032
	ret


DRAW_CIN_030:
	video offset=CINEMATIC_030, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_CIN_031:
	video offset=CINEMATIC_031, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_CIN_032:
	video offset=CINEMATIC_032, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_HERO_SUBFRAME_2_VAR09_LOW:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_033
	je [0xF8], 0x02, DRAW_CIN_034
	ret


DRAW_CIN_033:
	video offset=CINEMATIC_033, x=[0xf5], y=[BUDDY_Y]
	ret


DRAW_CIN_034:
	video offset=CINEMATIC_034, x=[0xf5], y=[BUDDY_Y]
	ret


LABEL_796B:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_08, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jg [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FBC, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L1:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_00, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jg [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FC4, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L4:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_01, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FCC, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L7:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_02, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jg [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FD4, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L10:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_03, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FDC, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L15:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_04, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FE4, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L20:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_05, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FEC, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

LABEL_7A46:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_06, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FF4, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

LABEL_7A67:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_07, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FFC, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

CAPSULE_DRAW_CV263_AT_X07_Y08_L5:
	video type=0, offset=CV_FIGURE_RUN_LEFT_UPPER_POSE_01, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

CAPSULE_DRAW_CV263_AT_X07_Y08_L9:
	video type=0, offset=CV_FIGURE_RUN_LEFT_UPPER_POSE_02, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

CAPSULE_DRAW_CV263_AT_X07_Y08_L13:
	video type=0, offset=CV_FIGURE_RUN_LEFT_UPPER_POSE_03, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

LABEL_7AA9:
	video type=0, offset=CV_FIGURE_RUN_LEFT_UPPER_POSE_04, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

LABEL_7AB4:
	video type=0, offset=CV_FIGURE_RUN_LEFT_UPPER_POSE_05, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

LABEL_7ABF:
	video type=0, offset=CV_FIGURE_RUN_LEFT_UPPER_POSE_06, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

CAPSULE_DRAW_CV263_AT_X07_Y08_L1:
	video type=0, offset=CV_FIGURE_RUN_LEFT_UPPER_POSE_00, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

LABEL_7AD5:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV204_AT_X07_Y08
	call CAPSULE_DRAW_CV204_AT_X07_Y08_L2
	jmp CAPSULE_DRAW_CV204_AT_X07_Y08_L0
