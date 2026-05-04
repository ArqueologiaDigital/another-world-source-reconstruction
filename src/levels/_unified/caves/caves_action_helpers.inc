INIT_VARS_E6_EA:
	mov [0xE6], 0xFFF9
	mov [0xEA], 0x0006

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_E6_EA.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_E6_EA.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_E6_EA.inc"
;@endif

LOAD_RES44_AND_RET:
	load id=0x0044
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_LOAD_RES44_AND_RET.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_LOAD_RES44_AND_RET.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_LOAD_RES44_AND_RET.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
COPY_PAGE0_TO_3_LOAD_RES45:
	copyVideoPage src=0x00, dst=0x03
	load id=0x0045
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_COPY_PAGE0_TO_3_LOAD_RES45.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_PAGE0_TO_3_LOAD_RES45.inc"
;@endif

;@include "../_helpers/INIT_RANGE_48_TO_4D_TO_MAX.inc"

;@include "../_helpers/INIT_VARS_AA_AD_5B_5E_PLUS1.inc"

;@include "../_helpers/INIT_VARS_A1_A4_A7.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_A1_A4_A7.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_A1_A4_A7.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_A1_A4_A7.inc"
;@endif

DELETE_GAME_AND_FX_CHANNELS:
	deleteChannels first=0x22, last=0x2E
	deleteChannels first=0x30, last=0x3B
	deleteChannels first=0x00, last=0x08
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DELETE_GAME_AND_FX_CHANNELS.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DELETE_GAME_AND_FX_CHANNELS.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DELETE_GAME_AND_FX_CHANNELS.inc"
;@endif

;@include "../_helpers/COPY_HACK67_TO_VAR66.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_HACK67_TO_VAR66.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_HACK67_TO_VAR66.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_HACK67_TO_VAR66.inc"
;@endif

;@include "../_helpers/ADD_HACK67_BY_20.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_ADD_HACK67_BY_20.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_ADD_HACK67_BY_20.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_ADD_HACK67_BY_20.inc"
;@endif

;@include "../_helpers/SUB_HACK67_BY_20.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SUB_HACK67_BY_20.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SUB_HACK67_BY_20.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SUB_HACK67_BY_20.inc"
;@endif

;@include "../_helpers/DECR_HACK67_BY_1.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DECR_HACK67_BY_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DECR_HACK67_BY_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DECR_HACK67_BY_1.inc"
;@endif

;@include "../_helpers/INCR_HACK67_BY_1.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INCR_HACK67_BY_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INCR_HACK67_BY_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INCR_HACK67_BY_1.inc"
;@endif

INIT_AI_VARS_AT_280_10:
	mov [0x01], 0x0118
	mov [0x0F], 0x0000
	mov [0x28], [0x01]
	mov [0x02], 0x000A
	mov [0x04], 0x0020
	mov [0x05], 0x0000
	mov [0x06], 0x03DE
	mov [0x0A], 0x0001
	mov [0xBE], 0x0001
	mov [0x63], 0x0000
	mov [0x2A], 0x000F
	ret


;@include "../_helpers/SET_VAR04_TO_0020.inc"

;@include "../_helpers/SET_VAR04_TO_0030.inc"

;@include "../_helpers/SET_VAR04_TO_0000.inc"

;@include "../_helpers/SET_VAR04_TO_0010.inc"

;@include "../_helpers/SET_VAR04_TO_0008.inc"

;@include "../_helpers/SET_VAR04_TO_0034.inc"

;@include "../_helpers/SET_VAR04_TO_0024.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR04_TO_0024.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR04_TO_0024.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR04_TO_0024.inc"
;@endif

DEDUP_CAVES_5B_035:
	mov [0x05], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_035.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_035.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_035.inc"
;@endif

DEDUP_CAVES_5B_036:
	mov [0x05], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_036.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_036.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_036.inc"
;@endif

