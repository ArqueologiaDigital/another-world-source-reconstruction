INIT_VARS_E6_EA:
	mov [0xE6], 0xFFF9
	mov [0xEA], 0x0006

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VARS_E6_EA.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_E6_EA.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_E6_EA.inc"
.endif

LOAD_RES44_AND_RET:
	load id=0x0044
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_LOAD_RES44_AND_RET.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_LOAD_RES44_AND_RET.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_LOAD_RES44_AND_RET.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
COPY_PAGE0_TO_3_LOAD_RES45:
	copyVideoPage src=0x00, dst=0x03
	load id=0x0045
	ret


.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_COPY_PAGE0_TO_3_LOAD_RES45.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_COPY_PAGE0_TO_3_LOAD_RES45.inc"
.endif

.include "../_helpers/INIT_RANGE_48_TO_4D_TO_MAX.inc"

.include "../_helpers/INIT_VARS_AA_AD_5B_5E_PLUS1.inc"

.include "../_helpers/INIT_VARS_A1_A4_A7.inc"
.include "post_INIT_VARS_A1_A4_A7.inc"

DELETE_GAME_AND_FX_CHANNELS:
	deleteChannels first=0x22, last=0x2E
	deleteChannels first=0x30, last=0x3B
	deleteChannels first=0x00, last=0x08
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DELETE_GAME_AND_FX_CHANNELS.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DELETE_GAME_AND_FX_CHANNELS.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DELETE_GAME_AND_FX_CHANNELS.inc"
.endif

.include "../_helpers/CACHE_SCREEN_NUM_RET.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_CACHE_SCREEN_NUM_RET_L0:
	db 0x11

CAVES_SCREEN_EXIT_DOWN_LINK_CASE_28:
	jne [SCREEN_NUM], 0x28, CAVES_SCREEN_EXIT_DOWN_LINK_CASE_49
	mov [SCREEN_NUM], 0x0067
	mov [HERO_X], 0x000A
	ret


CAVES_SCREEN_EXIT_DOWN_LINK_CASE_49:
	jne [SCREEN_NUM], 0x49, SCREEN_STEP_DOWN_ONE_ROW
	mov [SCREEN_NUM], 0x0069
	mov [HERO_X], 0x0032
	ret
.endif

.include "../_helpers/SCREEN_STEP_DOWN_ONE_ROW.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_SCREEN_EXIT_UP_LINK_CASE_69:
	jne [SCREEN_NUM], 0x69, SCREEN_STEP_UP_ONE_ROW
	mov [SCREEN_NUM], 0x0049
	mov [HERO_X], 0x00AA
	ret
.endif

.include "../_helpers/SCREEN_STEP_UP_ONE_ROW.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_SCREEN_EXIT_LEFT_LINK_CASE_AF:
	jne [SCREEN_NUM], 0xAF, CAVES_SCREEN_EXIT_LEFT_LINK_CASE_C8
	mov [SCREEN_NUM], 0x00CE
	mov [HERO_Y], 0x0078
	ret


CAVES_SCREEN_EXIT_LEFT_LINK_CASE_C8:
	jne [SCREEN_NUM], 0xC8, CAVES_SCREEN_EXIT_LEFT_LINK_CASE_68
	mov [SCREEN_NUM], 0x00A7
	jg [HERO_Y], 0x50, SHARED_RET
	call CAVES_SCREEN_STEP_UP_ONE_ROW_L3
	call SET_VAR04_TO_0024
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	mov [0x34], 0x0000
	mov [HERO_Y], 0x0014
	mov [HERO_X], 0x0140
	call CAVES_SCREEN_STEP_UP_ONE_ROW_L4
	ret


CAVES_SCREEN_EXIT_LEFT_LINK_CASE_68:
	jne [SCREEN_NUM], 0x68, SCREEN_STEP_LEFT_ONE_COLUMN
	jl [HERO_Y], 0x96, SCREEN_STEP_LEFT_ONE_COLUMN
	mov [SCREEN_NUM], 0x0087
	mov [HERO_Y], 0x0028
	ret
.endif

.include "../_helpers/SCREEN_STEP_LEFT_ONE_COLUMN.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_SCREEN_STEP_LEFT_ONE_COLUMN.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_SCREEN_STEP_LEFT_ONE_COLUMN.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_SCREEN_STEP_LEFT_ONE_COLUMN.inc"
.endif

.include "../_helpers/SCREEN_STEP_RIGHT_ONE_COLUMN.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_SCREEN_STEP_RIGHT_ONE_COLUMN.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_SCREEN_STEP_RIGHT_ONE_COLUMN.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_SCREEN_STEP_RIGHT_ONE_COLUMN.inc"
.endif

INIT_AI_VARS_AT_280_10:
	mov [HERO_X], 0x0118
	mov [0x0F], 0x0000
	mov [0x28], [HERO_X]
	mov [HERO_Y], 0x000A
	mov [0x04], 0x0020
	mov [0x05], 0x0000
	mov [0x06], 0x03DE
	mov [0x0A], 0x0001
	mov [0xBE], 0x0001
	mov [0x63], 0x0000
	mov [0x2A], 0x000F
	ret


.include "../_helpers/SET_VAR04_TO_0020.inc"

.include "../_helpers/SET_VAR04_TO_0030.inc"

.include "../_helpers/SET_VAR04_TO_0000.inc"

.include "../_helpers/SET_VAR04_TO_0010.inc"

.include "../_helpers/SET_VAR04_TO_0008.inc"

.include "../_helpers/SET_VAR04_TO_0034.inc"

.include "../_helpers/SET_VAR04_TO_0024.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_SET_VAR04_TO_0024.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_SET_VAR04_TO_0024.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_SET_VAR04_TO_0024.inc"
.endif

DEDUP_CAVES_5B_035:
	mov [0x05], 0x0001
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_CAVES_5B_035.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_CAVES_5B_035.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_CAVES_5B_035.inc"
.endif

DEDUP_CAVES_5B_036:
	mov [0x05], 0x0001
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_CAVES_5B_036.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_CAVES_5B_036.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_CAVES_5B_036.inc"
.endif

