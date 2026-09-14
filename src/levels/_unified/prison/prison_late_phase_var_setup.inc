INIT_VARS_02_06:
	mov [HERO_Y], 0xFFF7
	mov [0x06], 0xFFF9


ACCUMULATE_VAR_03_04_BY_01_02:
	add [0x03], [HERO_X]
	add [0x04], [HERO_Y]
	mov [HERO_X], [0x1E]
	ret


.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
PRISON_CAGE_SWING_TILT_OFFSET_DISPATCH:
	mov [0x1A], [0x03]
	mov [0x1B], [0x04]
	jne [0x06], 0x00, PRISON_CAGE_SWING_TILT_OFFSET_CASE_01
	add [0x1A], 0x0001
	ret


PRISON_CAGE_SWING_TILT_OFFSET_CASE_01:
	jne [0x06], 0x01, PRISON_CAGE_SWING_TILT_OFFSET_CASE_02
	add [0x1A], 0x0002
	ret


PRISON_CAGE_SWING_TILT_OFFSET_CASE_02:
	jne [0x06], 0x02, PRISON_CAGE_SWING_TILT_OFFSET_CASE_03
	add [0x1A], 0x0003
	sub [0x1B], 0x0001
	ret


PRISON_CAGE_SWING_TILT_OFFSET_CASE_03:
	jne [0x06], 0x03, PRISON_CAGE_SWING_TILT_OFFSET_CASE_04
	add [0x1A], 0x0004
	sub [0x1B], 0x0002
	ret


PRISON_CAGE_SWING_TILT_OFFSET_CASE_04:
	jne [0x06], 0x04, PRISON_CAGE_SWING_TILT_OFFSET_CASE_05
	add [0x1A], 0x0006
	sub [0x1B], 0x0002
	ret


PRISON_CAGE_SWING_TILT_OFFSET_CASE_05:
	jne [0x06], 0x05, PRISON_CAGE_SWING_TILT_OFFSET_CASE_06
	add [0x1A], 0x0007
	sub [0x1B], 0x0002
	ret


PRISON_CAGE_SWING_TILT_OFFSET_CASE_06:
	jne [0x06], 0x06, PRISON_CAGE_SWING_TILT_OFFSET_CASE_07
	add [0x1A], 0x0008
	sub [0x1B], 0x0003
	ret


PRISON_CAGE_SWING_TILT_OFFSET_CASE_07:
	jne [0x06], 0x07, PRISON_CAGE_SWING_TILT_OFFSET_CASE_FFFF
	add [0x1A], 0x0009
	sub [0x1B], 0x0003
	ret


PRISON_CAGE_SWING_TILT_OFFSET_CASE_FFFF:
	jne [0x06], 0xFFFF, PRISON_CAGE_SWING_TILT_OFFSET_CASE_FFFE
	ret


PRISON_CAGE_SWING_TILT_OFFSET_CASE_FFFE:
	jne [0x06], 0xFFFE, PRISON_CAGE_SWING_TILT_OFFSET_CASE_FFFD
	sub [0x1A], 0x0001
	ret


PRISON_CAGE_SWING_TILT_OFFSET_CASE_FFFD:
	jne [0x06], 0xFFFD, PRISON_CAGE_SWING_TILT_OFFSET_CASE_FFFC
	sub [0x1A], 0x0002
	ret


PRISON_CAGE_SWING_TILT_OFFSET_CASE_FFFC:
	jne [0x06], 0xFFFC, PRISON_CAGE_SWING_TILT_OFFSET_CASE_FFFB
	sub [0x1A], 0x0003
	ret


PRISON_CAGE_SWING_TILT_OFFSET_CASE_FFFB:
	jne [0x06], 0xFFFB, PRISON_CAGE_SWING_TILT_OFFSET_CASE_FFFA
	sub [0x1A], 0x0004
	add [0x1B], 0x0001
	ret


PRISON_CAGE_SWING_TILT_OFFSET_CASE_FFFA:
	jne [0x06], 0xFFFA, STEP_VAR1A_DOWN5_VAR1B_UP2
	sub [0x1A], 0x0005
	add [0x1B], 0x0001
	ret
.endif

STEP_VAR1A_DOWN5_VAR1B_UP2:
	sub [0x1A], 0x0005
	add [0x1B], 0x0002
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_STEP_VAR1A_DOWN5_VAR1B_UP2.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_STEP_VAR1A_DOWN5_VAR1B_UP2.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_STEP_VAR1A_DOWN5_VAR1B_UP2.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_HERO_PUMP_POSE_TILT_01:
	video offset=CINEMATIC_075, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_01_DONE:
	video offset=CINEMATIC_076, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_02:
	jne [0x06], 0x02, PRISON_CAGE_WITH_HERO_TILT_CASE_03
	jg [0x14], 0x00, PRISON_CAGE_HERO_PUMP_POSE_TILT_02
	video offset=CINEMATIC_074, x=[0x03], y=[0x04]
	jmp PRISON_CAGE_WITH_HERO_TILT_CASE_02_DONE
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_HERO_PUMP_POSE_TILT_02:
	video offset=CINEMATIC_072, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_02_DONE:
	video offset=CINEMATIC_073, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_03:
	jne [0x06], 0x03, PRISON_CAGE_WITH_HERO_TILT_CASE_04
	jg [0x14], 0x00, PRISON_CAGE_HERO_PUMP_POSE_TILT_03
	video offset=CINEMATIC_071, x=[0x03], y=[0x04]
	jmp PRISON_CAGE_WITH_HERO_TILT_CASE_03_DONE
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_HERO_PUMP_POSE_TILT_03:
	video offset=CINEMATIC_069, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_03_DONE:
	video offset=CINEMATIC_070, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_04:
	jne [0x06], 0x04, PRISON_CAGE_WITH_HERO_TILT_CASE_05
	jg [0x14], 0x00, PRISON_CAGE_HERO_PUMP_POSE_TILT_04
	video offset=CINEMATIC_068, x=[0x03], y=[0x04]
	jmp PRISON_CAGE_WITH_HERO_TILT_CASE_04_DONE
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_HERO_PUMP_POSE_TILT_04:
	video offset=CINEMATIC_066, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_04_DONE:
	video offset=CINEMATIC_067, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_05:
	jne [0x06], 0x05, PRISON_CAGE_WITH_HERO_TILT_CASE_06
	jg [0x14], 0x00, PRISON_CAGE_HERO_PUMP_POSE_TILT_05
	video offset=CINEMATIC_065, x=[0x03], y=[0x04]
	jmp PRISON_CAGE_WITH_HERO_TILT_CASE_05_DONE
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_HERO_PUMP_POSE_TILT_05:
	video offset=CINEMATIC_063, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_05_DONE:
	video offset=CINEMATIC_064, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_06:
	jne [0x06], 0x06, PRISON_CAGE_SWING_POSE_FROM_07
	jg [0x14], 0x00, PRISON_CAGE_HERO_PUMP_POSE_TILT_06
	video offset=CINEMATIC_062, x=[0x03], y=[0x04]
	jmp PRISON_CAGE_WITH_HERO_TILT_CASE_06_DONE
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_HERO_PUMP_POSE_TILT_06:
	video offset=CINEMATIC_060, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_06_DONE:
	video offset=CINEMATIC_061, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_SWING_POSE_FROM_07:
	jl [0x06], 0x07, PRISON_CAGE_SWING_POSE_CASE_FFFF
	jg [0x14], 0x00, PRISON_CAGE_HERO_PUMP_POSE_TILT_FROM_07
	video offset=CINEMATIC_059, x=[0x03], y=[0x04]
	jmp PRISON_CAGE_SWING_POSE_FROM_07_DONE
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_HERO_PUMP_POSE_TILT_FROM_07:
	video offset=CINEMATIC_057, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_SWING_POSE_FROM_07_DONE:
	video offset=CINEMATIC_058, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_CIN_058.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CIN_058.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN054_AT_X03_Y04:
	video offset=CINEMATIC_054, x=[0x03], y=[0x04]
.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_CIN054_AT_X03_Y04.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CIN054_AT_X03_Y04.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN051_AT_X03_Y04:
	video offset=CINEMATIC_051, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_FFFE_DONE:
	video offset=CINEMATIC_052, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_FFFD:
	jne [0x06], 0xFFFD, PRISON_CAGE_WITH_HERO_TILT_CASE_FFFC
	jl [0x14], 0x00, DRAW_CIN048_AT_X03_Y04
	video offset=CINEMATIC_050, x=[0x03], y=[0x04]
	jmp PRISON_CAGE_WITH_HERO_TILT_CASE_FFFD_DONE
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN048_AT_X03_Y04:
	video offset=CINEMATIC_048, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_FFFD_DONE:
	video offset=CINEMATIC_049, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_FFFC:
	jne [0x06], 0xFFFC, PRISON_CAGE_WITH_HERO_TILT_CASE_FFFB
	jl [0x14], 0x00, DRAW_CIN045_AT_X03_Y04
	video offset=CINEMATIC_047, x=[0x03], y=[0x04]
	jmp PRISON_CAGE_WITH_HERO_TILT_CASE_FFFC_DONE
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN045_AT_X03_Y04:
	video offset=CINEMATIC_045, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_FFFC_DONE:
	video offset=CINEMATIC_046, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_FFFB:
	jne [0x06], 0xFFFB, PRISON_CAGE_WITH_HERO_TILT_CASE_FFFA
	jl [0x14], 0x00, DRAW_CIN042_AT_X03_Y04
	video offset=CINEMATIC_044, x=[0x03], y=[0x04]
	jmp PRISON_CAGE_WITH_HERO_TILT_CASE_FFFB_DONE
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN042_AT_X03_Y04:
	video offset=CINEMATIC_042, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_FFFB_DONE:
	video offset=CINEMATIC_043, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_FFFA:
	jne [0x06], 0xFFFA, PRISON_CAGE_WITH_HERO_TILT_LEFT_LIMIT
	jl [0x14], 0x00, DRAW_CIN039_AT_X03_Y04
	video offset=CINEMATIC_041, x=[0x03], y=[0x04]
	jmp PRISON_CAGE_WITH_HERO_TILT_CASE_FFFA_DONE
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN039_AT_X03_Y04:
	video offset=CINEMATIC_039, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_CASE_FFFA_DONE:
	video offset=CINEMATIC_040, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_LEFT_LIMIT:
	jl [0x14], 0x00, PRISON_CAGE_HERO_PUMP_POSE_TILT_LEFT_LIMIT
	video offset=CINEMATIC_038, x=[0x03], y=[0x04]
	jmp PRISON_CAGE_WITH_HERO_TILT_LEFT_LIMIT_DONE
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_HERO_PUMP_POSE_TILT_LEFT_LIMIT:
	video offset=CINEMATIC_036, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_CAGE_WITH_HERO_TILT_LEFT_LIMIT_DONE:
	video offset=CINEMATIC_037, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_CIN_037.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CIN_037.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_540_543_WITH_SFX_57:
	video offset=CINEMATIC_540, x=[0x1a], y=[0x1b]
	video offset=CINEMATIC_541, x=[0x1a], y=[0x1b]
	break
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x02
	video offset=CINEMATIC_542, x=[0x1a], y=[0x1b]
	video offset=CINEMATIC_543, x=[0x1a], y=[0x1b]
	break
	video offset=CINEMATIC_544, x=[0x1a], y=[0x1b]
	video offset=CINEMATIC_545, x=[0x1a], y=[0x1b]
	break
	video offset=CINEMATIC_546, x=[0x1a], y=[0x1b]
	break
	video offset=CINEMATIC_547, x=[0x1a], y=[0x1b]
	break
	video offset=CINEMATIC_548, x=[0x1a], y=[0x1b]
	break
	video offset=CINEMATIC_547, x=[0x1a], y=[0x1b]
	break
	video offset=CINEMATIC_548, x=[0x1a], y=[0x1b]
	killChannel
.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_CIN_540_543_WITH_SFX_57.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CIN_540_543_WITH_SFX_57.inc"
.endif

INIT_VARS_15_19_18_14_PLUS4:
	mov [0x15], 0x0002
	mov [0x19], 0x0000
	mov [0x18], 0x0000
	mov [0x14], 0x0000
	mov [0x06], 0x0001
	mov [HERO_X], 0x0000
	mov [HERO_Y], 0x0000
	mov [0x21], 0xFFE2

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VARS_15_19_18_14_PLUS4.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_15_19_18_14_PLUS4.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_15_19_18_14_PLUS4.inc"
.endif

DEDUP_PRISON_4B_033:
	copyVideoPage src=0x83, dst=0xFF
	ret


.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
PRISON_DEDUP_PRISON_4B_033_L0:
	db 0x11

PRISON_LIFT_SHAFT_BLIT_CURRENT_STRIP:
	je [0x16], 0x00, DEDUP_PRISON_4B_034
	je [0x17], 0x01, DEDUP_PRISON_4B_034
	copyVideoPage src=0x80, dst=0xFF
	ret
.endif

DEDUP_PRISON_4B_034:
	copyVideoPage src=0x83, dst=0xFF
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_PRISON_4B_034.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_PRISON_4B_034.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_PRISON_4B_034.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_092:
	video offset=CINEMATIC_092, x=160, y=[0x21]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_LIFT_LANDING_BACKGROUND_DRAW:
	je [HACK_VAR_67], 0x65, PRISON_DRAW_CIN_092_L1
	video offset=CINEMATIC_106, x=160, y=100
	je [HACK_VAR_67], 0x45, PRISON_DRAW_CIN_092_L2
	video offset=CINEMATIC_092, x=160, y=100

PRISON_DRAW_CIN_092_L2:
	call PRISON_DRAW_CIN_092_L3
	video offset=CINEMATIC_105, x=160, y=129
	ret


PRISON_DRAW_CIN_092_L1:
	video offset=CINEMATIC_090, x=160, y=100
	video offset=CINEMATIC_091, x=160, y=100
	call PRISON_DRAW_CIN_092_L3
	video offset=CINEMATIC_104, x=200, y=100
	video offset=CINEMATIC_105, x=160, y=129
	ret


PRISON_DRAW_CIN_092_L4:
	db 0x11

PRISON_LIFT_RIDE_RANDOM_EVENT_DISPATCH:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	call INCREMENT_VAR31
	jne [RANDOM_SEED], 0x00, PRISON_LIFT_RIDE_RANDOM_EVENT_CASE_01
	setup channel=0x38, address=DRAW_CIN_154_TO_156_3F_AT_A74B7DB1

PRISON_LIFT_RIDE_RANDOM_EVENT_CASE_01:
	jne [RANDOM_SEED], 0x01, PRISON_LIFT_RIDE_RANDOM_EVENT_CASE_02
	setup channel=0x39, address=DRAW_CIN_151_TO_153_3F_AT_40D20636

PRISON_LIFT_RIDE_RANDOM_EVENT_CASE_02:
	jne [RANDOM_SEED], 0x02, PRISON_LIFT_RIDE_RANDOM_EVENT_CASE_03
	setup channel=0x38, address=DRAW_CIN_149_TO_150_2F_AT_F63AB95D

PRISON_LIFT_RIDE_RANDOM_EVENT_CASE_03:
	jne [RANDOM_SEED], 0x03, PRISON_LIFT_RIDE_RANDOM_EVENT_CASE_04
	setup channel=0x39, address=DRAW_CIN_132_TO_133_2F_AT_BB9185F0

PRISON_LIFT_RIDE_RANDOM_EVENT_CASE_04:
	jne [RANDOM_SEED], 0x04, PRISON_LIFT_RIDE_RANDOM_EVENT_CASE_05
	play id=0x0058, freq=0x0F, vol=0x10, channel=0x03

PRISON_LIFT_RIDE_RANDOM_EVENT_CASE_05:
	jne [RANDOM_SEED], 0x05, PRISON_LIFT_RIDE_RANDOM_EVENT_CASE_06
	play id=0x0058, freq=0x0F, vol=0x10, channel=0x02

PRISON_LIFT_RIDE_RANDOM_EVENT_CASE_06:
	jne [RANDOM_SEED], 0x06, PRISON_LIFT_RIDE_RANDOM_EVENT_FROM_1E
	play id=0x0058, freq=0x14, vol=0x20, channel=0x03

PRISON_LIFT_RIDE_RANDOM_EVENT_FROM_1E:
	jl [RANDOM_SEED], 0x1E, PRISON_DRAW_CIN_092_L13
	play id=0x0058, freq=0x0A, vol=0x18, channel=0x00

PRISON_DRAW_CIN_092_L13:
	call PRISON_LIFT_LANDING_IN_VIEW_FROM_2968
	call PRISON_LIFT_SHAFT_SCROLL_WRAP_BLIT
	call PRISON_DRAW_CIN_092_L3
	video offset=CINEMATIC_102, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_103, x=160, y=[HERO_Y]
	je [0x11], 0x00, SHARED_RET
	video offset=CINEMATIC_131, x=[BUDDY_X], y=[BUDDY_Y]
	ret


PRISON_LIFT_MOVE_STEP:
	jne [0x63], 0xFFFF, SCROLL_UP_16_VAR14_VAR18_AND_SCROLL_Y
	add [0x14], 0x0010
	add [0x18], 0x0010
	add [SCROLL_Y], 0x0010
	ret
.endif

