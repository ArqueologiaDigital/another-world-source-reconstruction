INIT_VARS_02_06:
	mov [HERO_Y], 0xFFF7
	mov [0x06], 0xFFF9


ACCUMULATE_VAR_03_04_BY_01_02:
	add [0x03], [HERO_X]
	add [0x04], [HERO_Y]
	mov [HERO_X], [0x1E]
	ret


.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L0:
	mov [0x1A], [0x03]
	mov [0x1B], [0x04]
	jne [0x06], 0x00, PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L1
	add [0x1A], 0x0001
	ret


PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L1:
	jne [0x06], 0x01, PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L2
	add [0x1A], 0x0002
	ret


PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L2:
	jne [0x06], 0x02, PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L3
	add [0x1A], 0x0003
	sub [0x1B], 0x0001
	ret


PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L3:
	jne [0x06], 0x03, PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L4
	add [0x1A], 0x0004
	sub [0x1B], 0x0002
	ret


PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L4:
	jne [0x06], 0x04, PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L5
	add [0x1A], 0x0006
	sub [0x1B], 0x0002
	ret


PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L5:
	jne [0x06], 0x05, PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L6
	add [0x1A], 0x0007
	sub [0x1B], 0x0002
	ret


PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L6:
	jne [0x06], 0x06, PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L7
	add [0x1A], 0x0008
	sub [0x1B], 0x0003
	ret


PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L7:
	jne [0x06], 0x07, PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L8
	add [0x1A], 0x0009
	sub [0x1B], 0x0003
	ret


PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L8:
	jne [0x06], 0xFFFF, PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L9
	ret


PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L9:
	jne [0x06], 0xFFFE, PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L10
	sub [0x1A], 0x0001
	ret


PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L10:
	jne [0x06], 0xFFFD, PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L11
	sub [0x1A], 0x0002
	ret


PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L11:
	jne [0x06], 0xFFFC, PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L12
	sub [0x1A], 0x0003
	ret


PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L12:
	jne [0x06], 0xFFFB, PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L13
	sub [0x1A], 0x0004
	add [0x1B], 0x0001
	ret


PRISON_ACCUMULATE_VAR_03_04_BY_01_02_L13:
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
DRAW_CIN075_AT_X03_Y04:
	video offset=CINEMATIC_075, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_076:
	video offset=CINEMATIC_076, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_076_L0:
	jne [0x06], 0x02, PRISON_DRAW_CIN_073_L0
	jg [0x14], 0x00, DRAW_CIN072_AT_X03_Y04
	video offset=CINEMATIC_074, x=[0x03], y=[0x04]
	jmp DRAW_CIN_073
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN072_AT_X03_Y04:
	video offset=CINEMATIC_072, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_073:
	video offset=CINEMATIC_073, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_073_L0:
	jne [0x06], 0x03, PRISON_DRAW_CIN_070_L0
	jg [0x14], 0x00, DRAW_CIN069_AT_X03_Y04
	video offset=CINEMATIC_071, x=[0x03], y=[0x04]
	jmp DRAW_CIN_070
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN069_AT_X03_Y04:
	video offset=CINEMATIC_069, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_070:
	video offset=CINEMATIC_070, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_070_L0:
	jne [0x06], 0x04, PRISON_DRAW_CIN_067_L0
	jg [0x14], 0x00, DRAW_CIN066_AT_X03_Y04
	video offset=CINEMATIC_068, x=[0x03], y=[0x04]
	jmp DRAW_CIN_067
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN066_AT_X03_Y04:
	video offset=CINEMATIC_066, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_067:
	video offset=CINEMATIC_067, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_067_L0:
	jne [0x06], 0x05, PRISON_DRAW_CIN_064_L0
	jg [0x14], 0x00, DRAW_CIN063_AT_X03_Y04
	video offset=CINEMATIC_065, x=[0x03], y=[0x04]
	jmp DRAW_CIN_064
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN063_AT_X03_Y04:
	video offset=CINEMATIC_063, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_064:
	video offset=CINEMATIC_064, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_064_L0:
	jne [0x06], 0x06, PRISON_DRAW_CIN_061_L0
	jg [0x14], 0x00, DRAW_CIN060_AT_X03_Y04
	video offset=CINEMATIC_062, x=[0x03], y=[0x04]
	jmp DRAW_CIN_061
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN060_AT_X03_Y04:
	video offset=CINEMATIC_060, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_061:
	video offset=CINEMATIC_061, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_061_L0:
	jl [0x06], 0x07, PRISON_DRAW_CIN_061_L1
	jg [0x14], 0x00, DRAW_CIN057_AT_X03_Y04
	video offset=CINEMATIC_059, x=[0x03], y=[0x04]
	jmp DRAW_CIN_058
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN057_AT_X03_Y04:
	video offset=CINEMATIC_057, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_058:
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
DRAW_CIN_052:
	video offset=CINEMATIC_052, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_052_L0:
	jne [0x06], 0xFFFD, PRISON_DRAW_CIN_049_L0
	jl [0x14], 0x00, DRAW_CIN048_AT_X03_Y04
	video offset=CINEMATIC_050, x=[0x03], y=[0x04]
	jmp DRAW_CIN_049
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN048_AT_X03_Y04:
	video offset=CINEMATIC_048, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_049:
	video offset=CINEMATIC_049, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_049_L0:
	jne [0x06], 0xFFFC, PRISON_DRAW_CIN_046_L0
	jl [0x14], 0x00, DRAW_CIN045_AT_X03_Y04
	video offset=CINEMATIC_047, x=[0x03], y=[0x04]
	jmp DRAW_CIN_046
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN045_AT_X03_Y04:
	video offset=CINEMATIC_045, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_046:
	video offset=CINEMATIC_046, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_046_L0:
	jne [0x06], 0xFFFB, PRISON_DRAW_CIN_043_L0
	jl [0x14], 0x00, DRAW_CIN042_AT_X03_Y04
	video offset=CINEMATIC_044, x=[0x03], y=[0x04]
	jmp DRAW_CIN_043
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN042_AT_X03_Y04:
	video offset=CINEMATIC_042, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_043:
	video offset=CINEMATIC_043, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_043_L0:
	jne [0x06], 0xFFFA, PRISON_DRAW_CIN_040_L0
	jl [0x14], 0x00, DRAW_CIN039_AT_X03_Y04
	video offset=CINEMATIC_041, x=[0x03], y=[0x04]
	jmp DRAW_CIN_040
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN039_AT_X03_Y04:
	video offset=CINEMATIC_039, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_040:
	video offset=CINEMATIC_040, x=[0x03], y=[0x04]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_040_L0:
	jl [0x14], 0x00, DRAW_CIN036_AT_X03_Y04
	video offset=CINEMATIC_038, x=[0x03], y=[0x04]
	jmp DRAW_CIN_037
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN036_AT_X03_Y04:
	video offset=CINEMATIC_036, x=[0x03], y=[0x04]
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_037:
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
PRISON_DRAW_CIN_092_L0:
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

PRISON_DRAW_CIN_092_L5:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	call INCREMENT_VAR31
	jne [RANDOM_SEED], 0x00, PRISON_DRAW_CIN_092_L6
	setup channel=0x38, address=DRAW_CIN_154_TO_156_3F_AT_A74B7DB1

PRISON_DRAW_CIN_092_L6:
	jne [RANDOM_SEED], 0x01, PRISON_DRAW_CIN_092_L7
	setup channel=0x39, address=DRAW_CIN_151_TO_153_3F_AT_40D20636

PRISON_DRAW_CIN_092_L7:
	jne [RANDOM_SEED], 0x02, PRISON_DRAW_CIN_092_L8
	setup channel=0x38, address=DRAW_CIN_149_TO_150_2F_AT_F63AB95D

PRISON_DRAW_CIN_092_L8:
	jne [RANDOM_SEED], 0x03, PRISON_DRAW_CIN_092_L9
	setup channel=0x39, address=DRAW_CIN_132_TO_133_2F_AT_BB9185F0

PRISON_DRAW_CIN_092_L9:
	jne [RANDOM_SEED], 0x04, PRISON_DRAW_CIN_092_L10
	play id=0x0058, freq=0x0F, vol=0x10, channel=0x03

PRISON_DRAW_CIN_092_L10:
	jne [RANDOM_SEED], 0x05, PRISON_DRAW_CIN_092_L11
	play id=0x0058, freq=0x0F, vol=0x10, channel=0x02

PRISON_DRAW_CIN_092_L11:
	jne [RANDOM_SEED], 0x06, PRISON_DRAW_CIN_092_L12
	play id=0x0058, freq=0x14, vol=0x20, channel=0x03

PRISON_DRAW_CIN_092_L12:
	jl [RANDOM_SEED], 0x1E, PRISON_DRAW_CIN_092_L13
	play id=0x0058, freq=0x0A, vol=0x18, channel=0x00

PRISON_DRAW_CIN_092_L13:
	call PRISON_DRAW_CIN_090_TO_104_3F_AT_8C208B32_L7
	call PRISON_DRAW_CIN_092_L14
	call PRISON_DRAW_CIN_092_L3
	video offset=CINEMATIC_102, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_103, x=160, y=[HERO_Y]
	je [0x11], 0x00, SHARED_RET
	video offset=CINEMATIC_131, x=[BUDDY_X], y=[BUDDY_Y]
	ret


PRISON_DRAW_CIN_092_L15:
	jne [0x63], 0xFFFF, SCROLL_UP_16_VAR14_VAR18_AND_SCROLL_Y
	add [0x14], 0x0010
	add [0x18], 0x0010
	add [SCROLL_Y], 0x0010
	ret
.endif

