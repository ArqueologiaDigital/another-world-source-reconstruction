SCROLL_UP_16_VAR14_VAR18_AND_SCROLL_Y:
	sub [0x14], 0x0010
	sub [0x18], 0x0010
	sub [SCROLL_Y], 0x0010
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SCROLL_UP_16_VAR14_VAR18_AND_SCROLL_Y.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SCROLL_UP_16_VAR14_VAR18_AND_SCROLL_Y.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SCROLL_UP_16_VAR14_VAR18_AND_SCROLL_Y.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
RESET_HERO_POS_UP_DOWN:
	mov [HERO_POS_UP_DOWN], 0x0000
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_RESET_HERO_POS_UP_DOWN.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_RESET_HERO_POS_UP_DOWN.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_090_TO_104_3F_AT_8C208B32:
	break
	copyVideoPage src=0x03, dst=0x00
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_090, x=160, y=100
	video offset=CINEMATIC_091, x=160, y=100
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_104, x=200, y=100
	selectVideoPage 0xFF
	killChannel
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_090_TO_104_3F_AT_8C208B32.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_090_TO_104_3F_AT_8C208B32.inc"
;@endif

INLINE_SET_VAR16_TO_0:
	mov [0x16], 0x0000

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR16_TO_0.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR16_TO_0.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR16_TO_0.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/COPY_PAGE0_TO_3_AND_VAR66_TO_VAR65.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_COPY_PAGE0_TO_3_AND_VAR66_TO_VAR65.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_PAGE0_TO_3_AND_VAR66_TO_VAR65.inc"
;@endif

;@include "../_helpers/COPY_VAR51_TO_VAR02_KILL_CHANNEL.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_VAR51_TO_VAR02_KILL_CHANNEL.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_VAR51_TO_VAR02_KILL_CHANNEL.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_VAR51_TO_VAR02_KILL_CHANNEL.inc"
;@endif

;@include "../_helpers/COPY_VAR52_TO_VAR02_KILL_CHANNEL.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_VAR52_TO_VAR02_KILL_CHANNEL.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_VAR52_TO_VAR02_KILL_CHANNEL.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_VAR52_TO_VAR02_KILL_CHANNEL.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_552:
	video offset=CINEMATIC_552, x=[0x01], y=[0x02]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_552.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_552.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_550:
	video offset=CINEMATIC_550, x=[0x01], y=[0x02]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_550.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_550.inc"
;@endif

;@include "../_helpers/RESET_HERO_ACTION_KEEP_POS_4LSB.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_RESET_HERO_ACTION_KEEP_POS_4LSB.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_RESET_HERO_ACTION_KEEP_POS_4LSB.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_RESET_HERO_ACTION_KEEP_POS_4LSB.inc"
;@endif

;@include "../_helpers/INLINE_SUB_VAR50_BY_14.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SUB_VAR50_BY_14.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SUB_VAR50_BY_14.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SUB_VAR50_BY_14.inc"
;@endif

ADD_VAR43_VAR47_BY_20:
	add [0x43], 0x0020
	add [0x47], 0x0020

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_ADD_VAR43_VAR47_BY_20.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_ADD_VAR43_VAR47_BY_20.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_ADD_VAR43_VAR47_BY_20.inc"
;@endif

COPY_PAGE0_TO_FF_KILL_CHANNEL:
	copyVideoPage src=0x00, dst=0xFF
	killChannel

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_PAGE0_TO_FF_KILL_CHANNEL.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_PAGE0_TO_FF_KILL_CHANNEL.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_PAGE0_TO_FF_KILL_CHANNEL.inc"
;@endif

COPY_PAGE3_TO_PAGE0:
	copyVideoPage src=0x03, dst=0x00

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_PAGE3_TO_PAGE0.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_PAGE3_TO_PAGE0.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_PAGE3_TO_PAGE0.inc"
;@endif

;@include "../_helpers/INIT_RANGE_48_TO_4D_TO_MAX.inc"
INIT_VARS_A1_A4_A7_AA_PLUS4:
	mov [0xA1], 0xFFFF
	mov [0xA4], 0xFFFF
	mov [0xA7], 0xFFFF
	mov [0xAA], 0xFFFF
	mov [0xAD], 0xFFFF
	mov [0x5B], 0x0FA0
	mov [0x5E], 0x0FA0
	mov [0x61], 0x0FA0
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_A1_A4_A7_AA_PLUS4.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_A1_A4_A7_AA_PLUS4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_A1_A4_A7_AA_PLUS4.inc"
;@endif

;@include "../_helpers/COPY_PAGE0_TO_PAGE_FF.inc"
;@include "../_helpers/COPY_HACK67_TO_VAR66.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_HACK67_TO_VAR66.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_HACK67_TO_VAR66.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_HACK67_TO_VAR66.inc"
;@endif

DECREMENT_VAR10_BY_1:
	sub [0x10], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DECREMENT_VAR10_BY_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DECREMENT_VAR10_BY_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DECREMENT_VAR10_BY_1.inc"
;@endif

SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01:
	mov [0x01], 0x00B0
	mov [0x0F], 0x0000
	mov [0x28], [0x01]
	mov [0x02], 0x00B6
	mov [0x04], 0x0020
	mov [0x05], 0x0000
	mov [0x06], 0x00C7
	mov [0x0A], 0x0000
	mov [0x63], 0x0000
	mov [0x2A], 0x000F
	killChannel


;@include "../_helpers/SET_VAR04_TO_0020.inc"
;@include "../_helpers/SET_VAR04_TO_0030.inc"
;@include "../_helpers/SET_VAR04_TO_0000.inc"
;@include "../_helpers/SET_VAR04_TO_0010.inc"
;@include "../_helpers/SET_VAR04_TO_0008.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR04_TO_0008.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR04_TO_0008.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR04_TO_0008.inc"
;@endif

;@include "../_helpers/INLINE_SET_VAR63_TO_1.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR63_TO_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR63_TO_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR63_TO_1.inc"
;@endif

;@include "../_helpers/INLINE_SET_VAR63_TO_2.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR63_TO_2.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR63_TO_2.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR63_TO_2.inc"
;@endif

;@include "../_helpers/INLINE_SET_VAR63_TO_5.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR63_TO_5.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR63_TO_5.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR63_TO_5.inc"
;@endif

;@include "../_helpers/INLINE_SET_VAR63_TO_6.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR63_TO_6.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR63_TO_6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR63_TO_6.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/WALK_RIGHT_DRAW_CV142_MULTISTEP.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_WALK_RIGHT_DRAW_CV142_MULTISTEP.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_WALK_RIGHT_DRAW_CV142_MULTISTEP.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/WALK_LEFT_DRAW_CV140_MULTISTEP.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_WALK_LEFT_DRAW_CV140_MULTISTEP.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_WALK_LEFT_DRAW_CV140_MULTISTEP.inc"
;@endif

