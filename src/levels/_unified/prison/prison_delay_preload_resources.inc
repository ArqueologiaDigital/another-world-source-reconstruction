.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DELAY_4_QUANTUMS:
	break
	break
	break
	break
.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DELAY_4_QUANTUMS.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DELAY_4_QUANTUMS.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRELOAD_PRISON_RESOURCES:
	load id=0x0052
	load id=0x0055
	load id=0x0056
	load id=0x0057
	load id=0x0058
	load id=0x0059
	load id=0x005A
	load id=0x005B
	load id=0x005C
	load id=0x005D
	load id=0x005E
	load id=0x005F
	load id=0x0060
	load id=0x0061
	load id=0x0062
	load id=0x0063
	load id=0x0064
	load id=0x0065
	load id=0x0073
	load id=0x0067
	load id=0x0070
	load id=0x0071
	load id=0x0072
	load id=0x0066
	load id=0x0068
	load id=0x0069
	ret


.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_PRELOAD_PRISON_RESOURCES.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_PRELOAD_PRISON_RESOURCES.inc"
.endif

.include "../_helpers/KILL_CHANNEL_LANDING.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_KILL_039.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_KILL_039.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_KILL_039.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
BANK4_AFTER_CIN_414:
	mov [HERO_X], 0x0041
	add [HERO_Y], 0x0016
	video offset=CINEMATIC_414, x=[HERO_X], y=[HERO_Y]
	add [HERO_Y], 0x001A
	break
	add [HERO_Y], 0x0020
	video offset=CINEMATIC_415, x=[HERO_X], y=[HERO_Y]
	break
	mov [0x00], 0x001E
	bankSwitch 4;  Gas tunnels, Caves and Pool
	killChannel
.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_BANK4_AFTER_CIN_414.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_BANK4_AFTER_CIN_414.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_422_WITH_POS_STEP_AT_C7A1BFCB:
	sub [HERO_Y], 0x0009
	video offset=CINEMATIC_PRISON_HERO_PRONE_TRANSITION_RIGHT_F04, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0001
	mov [0x03], 0x000B
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_422_WITH_POS_STEP_AT_C7A1BFCB_L0:
	break
	video offset=CINEMATIC_PRISON_HERO_PRONE_TRANSITION_RIGHT_F04, x=[HERO_X], y=[HERO_Y]
	djnz [0x03], PRISON_DRAW_CIN_422_WITH_POS_STEP_AT_C7A1BFCB_L0
	break
	video offset=CINEMATIC_PRISON_HERO_PRONE_TRANSITION_RIGHT_F03, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_PRISON_HERO_PRONE_TRANSITION_RIGHT_F02, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_PRISON_HERO_PRONE_TRANSITION_RIGHT_F01, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_PRISON_HERO_PRONE_TRANSITION_RIGHT_F00, x=[HERO_X], y=[HERO_Y]
	mov [0x03], 0x0009

PRISON_DRAW_CIN_422_WITH_POS_STEP_AT_C7A1BFCB_L1:
	break
	video offset=CINEMATIC_215, x=[HERO_X], y=[HERO_Y]
	djnz [0x03], PRISON_DRAW_CIN_422_WITH_POS_STEP_AT_C7A1BFCB_L1
	break
	video offset=CINEMATIC_PRISON_HERO_CROUCH_DOWN_RIGHT, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_PRISON_HERO_STAND_ARMED_RIGHT, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0002
	break
	play id=0x0060, freq=0x14, vol=0x1E, channel=0x00
	call PRISON_DRAW_CIN_422_WITH_POS_STEP_AT_C7A1BFCB_L2
	setup channel=0x15, address=INLINE_SET_VAR03_TO_7
	break
	jmp PRISON_HERO_WALK_JUMP_RIGHT
PRISON_DRAW_CIN_422_WITH_POS_STEP_AT_C7A1BFCB_L4:
	db 0x11
.endif
