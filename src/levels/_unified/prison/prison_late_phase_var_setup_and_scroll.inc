INIT_VARS_02_06:
	mov [0x02], 0xFFF7
	mov [0x06], 0xFFF9


ACCUMULATE_VAR_03_04_BY_01_02:
	add [0x03], [0x01]
	add [0x04], [0x02]
	mov [0x01], [0x1E]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_ACCUMULATE_VAR_03_04_BY_01_02.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_ACCUMULATE_VAR_03_04_BY_01_02.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_ACCUMULATE_VAR_03_04_BY_01_02.inc"
;@endif

STEP_VAR1A_DOWN5_VAR1B_UP2:
	sub [0x1A], 0x0005
	add [0x1B], 0x0002
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_STEP_VAR1A_DOWN5_VAR1B_UP2.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_STEP_VAR1A_DOWN5_VAR1B_UP2.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_STEP_VAR1A_DOWN5_VAR1B_UP2.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN075_AT_X03_Y04:
	video type=1, offset=CINEMATIC_075, x=[0x03], y=[0x04], zoom=0x40
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_076:
	video type=1, offset=CINEMATIC_076, x=[0x03], y=[0x04], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_076.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_076.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN072_AT_X03_Y04:
	video type=1, offset=CINEMATIC_072, x=[0x03], y=[0x04], zoom=0x40
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_073:
	video type=1, offset=CINEMATIC_073, x=[0x03], y=[0x04], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_073.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_073.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN069_AT_X03_Y04:
	video type=1, offset=CINEMATIC_069, x=[0x03], y=[0x04], zoom=0x40
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_070:
	video type=1, offset=CINEMATIC_070, x=[0x03], y=[0x04], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_070.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_070.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN066_AT_X03_Y04:
	video type=1, offset=CINEMATIC_066, x=[0x03], y=[0x04], zoom=0x40
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_067:
	video type=1, offset=CINEMATIC_067, x=[0x03], y=[0x04], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_067.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_067.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN063_AT_X03_Y04:
	video type=1, offset=CINEMATIC_063, x=[0x03], y=[0x04], zoom=0x40
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_064:
	video type=1, offset=CINEMATIC_064, x=[0x03], y=[0x04], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_064.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_064.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN060_AT_X03_Y04:
	video type=1, offset=CINEMATIC_060, x=[0x03], y=[0x04], zoom=0x40
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_061:
	video type=1, offset=CINEMATIC_061, x=[0x03], y=[0x04], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_061.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_061.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN057_AT_X03_Y04:
	video type=1, offset=CINEMATIC_057, x=[0x03], y=[0x04], zoom=0x40
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_058:
	video type=1, offset=CINEMATIC_058, x=[0x03], y=[0x04], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_058.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_058.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN054_AT_X03_Y04:
	video type=1, offset=CINEMATIC_054, x=[0x03], y=[0x04], zoom=0x40
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN054_AT_X03_Y04.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN054_AT_X03_Y04.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN051_AT_X03_Y04:
	video type=1, offset=CINEMATIC_051, x=[0x03], y=[0x04], zoom=0x40
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_052:
	video type=1, offset=CINEMATIC_052, x=[0x03], y=[0x04], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_052.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_052.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN048_AT_X03_Y04:
	video type=1, offset=CINEMATIC_048, x=[0x03], y=[0x04], zoom=0x40
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_049:
	video type=1, offset=CINEMATIC_049, x=[0x03], y=[0x04], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_049.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_049.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN045_AT_X03_Y04:
	video type=1, offset=CINEMATIC_045, x=[0x03], y=[0x04], zoom=0x40
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_046:
	video type=1, offset=CINEMATIC_046, x=[0x03], y=[0x04], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_046.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_046.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN042_AT_X03_Y04:
	video type=1, offset=CINEMATIC_042, x=[0x03], y=[0x04], zoom=0x40
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_043:
	video type=1, offset=CINEMATIC_043, x=[0x03], y=[0x04], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_043.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_043.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN039_AT_X03_Y04:
	video type=1, offset=CINEMATIC_039, x=[0x03], y=[0x04], zoom=0x40
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_040:
	video type=1, offset=CINEMATIC_040, x=[0x03], y=[0x04], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_040.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_040.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN036_AT_X03_Y04:
	video type=1, offset=CINEMATIC_036, x=[0x03], y=[0x04], zoom=0x40
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_037:
	video type=1, offset=CINEMATIC_037, x=[0x03], y=[0x04], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_037.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_037.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_540_543_WITH_SFX_57:
	video type=1, offset=CINEMATIC_540, x=[0x1a], y=[0x1b], zoom=0x40
	video type=1, offset=CINEMATIC_541, x=[0x1a], y=[0x1b], zoom=0x40
	break
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x02
	video type=1, offset=CINEMATIC_542, x=[0x1a], y=[0x1b], zoom=0x40
	video type=1, offset=CINEMATIC_543, x=[0x1a], y=[0x1b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_544, x=[0x1a], y=[0x1b], zoom=0x40
	video type=1, offset=CINEMATIC_545, x=[0x1a], y=[0x1b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_546, x=[0x1a], y=[0x1b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_547, x=[0x1a], y=[0x1b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_548, x=[0x1a], y=[0x1b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_547, x=[0x1a], y=[0x1b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_548, x=[0x1a], y=[0x1b], zoom=0x40
	killChannel
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_540_543_WITH_SFX_57.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_540_543_WITH_SFX_57.inc"
;@endif

INIT_VARS_15_19_18_14_PLUS4:
	mov [0x15], 0x0002
	mov [0x19], 0x0000
	mov [0x18], 0x0000
	mov [0x14], 0x0000
	mov [0x06], 0x0001
	mov [0x01], 0x0000
	mov [0x02], 0x0000
	mov [0x21], 0xFFE2

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_15_19_18_14_PLUS4.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_15_19_18_14_PLUS4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_15_19_18_14_PLUS4.inc"
;@endif

DEDUP_PRISON_4B_033:
	copyVideoPage src=0x83, dst=0xFF
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_PRISON_4B_033.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_PRISON_4B_033.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_PRISON_4B_033.inc"
;@endif

DEDUP_PRISON_4B_034:
	copyVideoPage src=0x83, dst=0xFF
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_PRISON_4B_034.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_PRISON_4B_034.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_PRISON_4B_034.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_092:
	video type=1, offset=CINEMATIC_092, x=160, y=[0x21], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_092.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_092.inc"
;@endif

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
	video type=1, offset=CINEMATIC_090, x=160, y=100
	video type=1, offset=CINEMATIC_091, x=160, y=100
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_104, x=200, y=100
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
	video type=1, offset=CINEMATIC_552, x=[0x01], y=[0x02], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_552.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_552.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_550:
	video type=1, offset=CINEMATIC_550, x=[0x01], y=[0x02], zoom=0x40
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

