INIT_VARS_02_06:
	mov [HERO_Y], 0xFFF7
	mov [0x06], 0xFFF9


ACCUMULATE_VAR_03_04_BY_01_02:
	add [0x03], [HERO_X]
	add [0x04], [HERO_Y]
	mov [HERO_X], [0x1E]
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
	video offset=CINEMATIC_075, x=[0x03], y=[0x04]
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_076:
	video offset=CINEMATIC_076, x=[0x03], y=[0x04]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_076.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_076.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN072_AT_X03_Y04:
	video offset=CINEMATIC_072, x=[0x03], y=[0x04]
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_073:
	video offset=CINEMATIC_073, x=[0x03], y=[0x04]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_073.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_073.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN069_AT_X03_Y04:
	video offset=CINEMATIC_069, x=[0x03], y=[0x04]
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_070:
	video offset=CINEMATIC_070, x=[0x03], y=[0x04]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_070.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_070.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN066_AT_X03_Y04:
	video offset=CINEMATIC_066, x=[0x03], y=[0x04]
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_067:
	video offset=CINEMATIC_067, x=[0x03], y=[0x04]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_067.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_067.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN063_AT_X03_Y04:
	video offset=CINEMATIC_063, x=[0x03], y=[0x04]
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_064:
	video offset=CINEMATIC_064, x=[0x03], y=[0x04]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_064.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_064.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN060_AT_X03_Y04:
	video offset=CINEMATIC_060, x=[0x03], y=[0x04]
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_061:
	video offset=CINEMATIC_061, x=[0x03], y=[0x04]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_061.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_061.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN057_AT_X03_Y04:
	video offset=CINEMATIC_057, x=[0x03], y=[0x04]
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_058:
	video offset=CINEMATIC_058, x=[0x03], y=[0x04]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_058.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_058.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN054_AT_X03_Y04:
	video offset=CINEMATIC_054, x=[0x03], y=[0x04]
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN054_AT_X03_Y04.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN054_AT_X03_Y04.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN051_AT_X03_Y04:
	video offset=CINEMATIC_051, x=[0x03], y=[0x04]
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_052:
	video offset=CINEMATIC_052, x=[0x03], y=[0x04]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_052.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_052.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN048_AT_X03_Y04:
	video offset=CINEMATIC_048, x=[0x03], y=[0x04]
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_049:
	video offset=CINEMATIC_049, x=[0x03], y=[0x04]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_049.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_049.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN045_AT_X03_Y04:
	video offset=CINEMATIC_045, x=[0x03], y=[0x04]
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_046:
	video offset=CINEMATIC_046, x=[0x03], y=[0x04]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_046.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_046.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN042_AT_X03_Y04:
	video offset=CINEMATIC_042, x=[0x03], y=[0x04]
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_043:
	video offset=CINEMATIC_043, x=[0x03], y=[0x04]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_043.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_043.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN039_AT_X03_Y04:
	video offset=CINEMATIC_039, x=[0x03], y=[0x04]
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_040:
	video offset=CINEMATIC_040, x=[0x03], y=[0x04]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_040.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_040.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN036_AT_X03_Y04:
	video offset=CINEMATIC_036, x=[0x03], y=[0x04]
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_037:
	video offset=CINEMATIC_037, x=[0x03], y=[0x04]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_037.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_037.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
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
	mov [HERO_X], 0x0000
	mov [HERO_Y], 0x0000
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
	video offset=CINEMATIC_092, x=160, y=[0x21]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_092.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_092.inc"
;@endif

