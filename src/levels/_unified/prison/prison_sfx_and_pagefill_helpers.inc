PLAY_SFX_005C_CH01:
	play id=0x005C, freq=0x19, vol=0x40, channel=0x01
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PLAY_SFX_005C_CH01.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PLAY_SFX_005C_CH01.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PLAY_SFX_005C_CH01.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/FOLD_BODY_37B_9FD2CEA6.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_FOLD_BODY_37B_9FD2CEA6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_FOLD_BODY_37B_9FD2CEA6.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_486:
	video type=1, offset=CINEMATIC_486, x=[0x21], y=[0x27], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_486.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_486.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_483:
	video type=1, offset=CINEMATIC_483, x=[0x21], y=[0x27], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_483.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_483.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN473_AT_X21_Y27_ZOOM_40:
	video type=1, offset=CINEMATIC_473, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN473_AT_X21_Y27_ZOOM_40.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN473_AT_X21_Y27_ZOOM_40.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_502:
	video type=1, offset=CINEMATIC_502, x=[0x21], y=[0x27], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_502.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_502.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_499:
	video type=1, offset=CINEMATIC_499, x=[0x21], y=[0x27], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_499.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_499.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN489_AT_X21_Y27_ZOOM_40:
	video type=1, offset=CINEMATIC_489, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN489_AT_X21_Y27_ZOOM_40.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN489_AT_X21_Y27_ZOOM_40.inc"
;@endif

;@include "../_helpers/MASK_VAR11_NOSIGN_INCR_VAR21_BY_14.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14.inc"
;@endif

;@include "../_helpers/INLINE_ADD_VAR2C_BY_1.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_ADD_VAR2C_BY_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_ADD_VAR2C_BY_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_ADD_VAR2C_BY_1.inc"
;@endif

;@include "../_helpers/COPY_VAR40_TO_VAR27.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_VAR40_TO_VAR27.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_VAR40_TO_VAR27.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_VAR40_TO_VAR27.inc"
;@endif

;@include "../_helpers/COPY_VARAD_TO_VAR11.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_VARAD_TO_VAR11.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_VARAD_TO_VAR11.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_VARAD_TO_VAR11.inc"
;@endif

;@include "../_helpers/COPY_VAR11_TO_VARAD.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_VAR11_TO_VARAD.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_VAR11_TO_VARAD.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_VAR11_TO_VARAD.inc"
;@endif

;@include "../_helpers/DECREMENT_VAR22.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DECREMENT_VAR22.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DECREMENT_VAR22.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DECREMENT_VAR22.inc"
;@endif

;@include "../_helpers/DEDUP_CAVES_5B_003.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_PRISON_5B_031.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_PRISON_5B_031.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_PRISON_5B_031.inc"
;@endif

DEDUP_CAVES_5B_003__PRISON_INLINE_SETTERS_AND_INIT:
	mov [0x0F], 0x0000
	killChannel

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_PRISON_5B_032.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_PRISON_5B_032.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_PRISON_5B_032.inc"
;@endif

;@include "../_helpers/COMPUTE_VARF8_AS_VAR22_MINUS_VAR09.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COMPUTE_VARF8_AS_VAR22_MINUS_VAR09.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COMPUTE_VARF8_AS_VAR22_MINUS_VAR09.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COMPUTE_VARF8_AS_VAR22_MINUS_VAR09.inc"
;@endif

TOGGLE_SIGN_VAR26_INIT_VAR25_FROM_VAR44:
	sub [0x26], 0x8000
	mov [0x25], [0x44]

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_TOGGLE_SIGN_VAR26_INIT_VAR25_FROM_VAR44.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_TOGGLE_SIGN_VAR26_INIT_VAR25_FROM_VAR44.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_TOGGLE_SIGN_VAR26_INIT_VAR25_FROM_VAR44.inc"
;@endif

;@include "../_helpers/DEDUP_CAVES_6B_001.inc"
;@include "../_helpers/SHARED_RET.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_TRIVIAL_RET.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_TRIVIAL_RET.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_TRIVIAL_RET.inc"
;@endif

;@include "../_helpers/COPY_VAR01_TO_VAR28.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_VAR01_TO_VAR28.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_VAR01_TO_VAR28.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_VAR01_TO_VAR28.inc"
;@endif

DEDUP_CAVES_6B_001:
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_PRISON_6B_002.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
FOLD_BODY_104B_22B91458:
	ret
	mov [0xF8], 0x0000
	mov [0x21], 0x0010
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_FOLD_BODY_104B_22B91458.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_FOLD_BODY_104B_22B91458.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_SEQ_085_085_086:
	video type=1, offset=CINEMATIC_085, x=132, y=39
	video type=1, offset=CINEMATIC_085, x=297, y=39, zoom=0x40
	video type=1, offset=CINEMATIC_086, x=132, y=39
	video type=1, offset=CINEMATIC_086, x=297, y=39, zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_SEQ_085_085_086.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_SEQ_085_085_086.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_305_TO_309_5F_AT_AACB4DF5:
	fill page=0x00, color=0x03
	video type=1, offset=CINEMATIC_305, x=160, y=100
	video type=1, offset=CINEMATIC_306, x=160, y=100
	video type=1, offset=CINEMATIC_307, x=160, y=100
	video type=1, offset=CINEMATIC_308, x=160, y=100
	video type=1, offset=CINEMATIC_309, x=160, y=100
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_305_TO_333_7F_AT_96C7E6A8:
	fill page=0x00, color=0x03
	video type=1, offset=CINEMATIC_305, x=160, y=100
	video type=1, offset=CINEMATIC_328, x=160, y=100
	video type=1, offset=CINEMATIC_329, x=160, y=100
	video type=1, offset=CINEMATIC_330, x=160, y=100
	video type=1, offset=CINEMATIC_331, x=160, y=100
	video type=1, offset=CINEMATIC_332, x=160, y=100
	video type=1, offset=CINEMATIC_333, x=160, y=100
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_305_TO_333_7F_AT_96C7E6A8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_305_TO_333_7F_AT_96C7E6A8.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
FILL_AND_DRAW_CIN_24_28:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_024, x=160, y=100
	video type=1, offset=CINEMATIC_025, x=160, y=100
	video type=1, offset=CINEMATIC_026, x=160, y=100
	video type=1, offset=CINEMATIC_027, x=160, y=100
	video type=1, offset=CINEMATIC_028, x=160, y=100
	video type=1, offset=CINEMATIC_029, x=160, y=400, zoom=0x40
	video type=1, offset=CINEMATIC_030, x=160, y=100
	video type=1, offset=CINEMATIC_031, x=160, y=100
	video type=1, offset=CINEMATIC_032, x=160, y=100
	video type=1, offset=CINEMATIC_033, x=160, y=100
	video type=1, offset=CINEMATIC_034, x=160, y=100
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_FILL_AND_DRAW_CIN_24_28.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_FILL_AND_DRAW_CIN_24_28.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_624_TO_628_5F_AT_499AFE0A:
	video type=1, offset=CINEMATIC_624, x=160, y=100
	break
	video type=1, offset=CINEMATIC_625, x=160, y=100
	break
	video type=1, offset=CINEMATIC_626, x=160, y=100
	break
	video type=1, offset=CINEMATIC_627, x=160, y=100
	break
	video type=1, offset=CINEMATIC_628, x=160, y=100
	killChannel
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_628_TO_625_4F_AT_2F47D6D0:
	video type=1, offset=CINEMATIC_628, x=160, y=100
	break
	video type=1, offset=CINEMATIC_627, x=160, y=100
	break
	video type=1, offset=CINEMATIC_626, x=160, y=100
	break
	video type=1, offset=CINEMATIC_625, x=160, y=100
	break
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_628_TO_625_4F_AT_2F47D6D0.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_628_TO_625_4F_AT_2F47D6D0.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_229_TO_632_2F_AT_1C4A817A:
	video type=1, offset=CINEMATIC_229, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_632, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_229_TO_632_2F_AT_1C4A817A.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_229_TO_632_2F_AT_1C4A817A.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_683_TO_685_3F_AT_1EB7324B:
	setPalette 0x0B
	selectVideoPage 0x00
	fill page=0x00, color=0x04
	video type=1, offset=CINEMATIC_683, x=160, y=100
	video type=1, offset=CINEMATIC_684, x=160, y=100
	video type=1, offset=CINEMATIC_685, x=160, y=100
	copyVideoPage src=0x00, dst=0xFF
	selectVideoPage 0xFF
	mov [0x1A], 0x00A0
	mov [0x1B], 0x0064
	mov [0x15], 0x0000
	mov [0x14], 0x0007
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_683_TO_685_3F_AT_1EB7324B.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_683_TO_685_3F_AT_1EB7324B.inc"
;@endif

INIT_VARS_16_17:
	mov [0x16], 0x0007
	mov [0x17], 0x0023

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_16_17.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_16_17.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_16_17.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN657_AT_X1A_Y1B:
	video type=1, offset=CINEMATIC_657, x=[0x1a], y=[0x1b], zoom=0x40
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN657_AT_X1A_Y1B.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN657_AT_X1A_Y1B.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
INLINE_DRAW_CIN_659_AT_160_100:
	video type=1, offset=CINEMATIC_659, x=160, y=100
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_DRAW_CIN_659_AT_160_100.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CIN_659_AT_160_100.inc"
;@endif

FILL_PFF_PLAY_SFX_0061_AT_C0D45EFA:
	fill page=0xFF, color=0x00
	play id=0x0061, freq=0x0A, vol=0x0A, channel=0x00
	break
	mov [0x14], 0x00A0
	mov [0x17], 0x00A1
	mov [0x16], 0x0006
	mov [PAUSE_SLICES], 0x0007

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_FOLD_BODY_338B_C0D45EFA.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_FOLD_BODY_338B_C0D45EFA.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_FOLD_BODY_338B_C0D45EFA.inc"
;@endif

SET_PAL_07_FILL_TWO_PAGES_86243111:
	setPalette 0x07
	fill page=0x00, color=0x00
	fill page=0xFF, color=0x00
	mov [0x15], 0x0005
	mov [0x16], 0x0003
	mov [PAUSE_SLICES], 0x0008

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_FOLD_BODY_275B_86243111.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_FOLD_BODY_275B_86243111.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_FOLD_BODY_275B_86243111.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_236:
	video type=1, offset=CINEMATIC_236, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_237:
	video type=1, offset=CINEMATIC_237, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_238:
	video type=1, offset=CINEMATIC_238, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_239:
	video type=1, offset=CINEMATIC_239, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_235:
	video type=1, offset=CINEMATIC_235, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_234:
	video type=1, offset=CINEMATIC_234, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_233:
	video type=1, offset=CINEMATIC_233, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_232:
	video type=1, offset=CINEMATIC_232, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_231:
	video type=1, offset=CINEMATIC_231, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_230:
	video type=1, offset=CINEMATIC_230, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_229:
	video type=1, offset=CINEMATIC_229, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_228:
	video type=1, offset=CINEMATIC_228, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_225:
	video type=1, offset=CINEMATIC_225, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_226:
	video type=1, offset=CINEMATIC_226, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_226.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_226.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_352:
	video type=1, offset=CINEMATIC_352, x=[0xf5], y=[0x08], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_352.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_352.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_169_WITH_POS_STEP_AT_B673C5FF:
	add [0x08], 0x000D
	sub [0x07], 0x0002
	video type=1, offset=CINEMATIC_169, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0002
	sub [0x08], 0x000D
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_169_WITH_POS_STEP_AT_B673C5FF.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_169_WITH_POS_STEP_AT_B673C5FF.inc"
;@endif

SHARED_RET:
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SHARED_RET.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SHARED_RET.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SHARED_RET.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_240:
	video type=1, offset=CINEMATIC_240, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_240.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_240.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_241:
	video type=1, offset=CINEMATIC_241, x=[0xf5], y=[0x08], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_241.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_241.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV204_AT_X07_Y08.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV204_AT_X07_Y08.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV204_AT_X07_Y08.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV204_AT_X07_PLUS1_Y08.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV204_AT_X07_PLUS1_Y08.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV204_AT_X07_PLUS1_Y08.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_216_027.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_216_027.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_216_027.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_220_008.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_220_008.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_220_008.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV224_AT_X07_Y08.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV224_AT_X07_Y08.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV224_AT_X07_Y08.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_228_018.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_228_020.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_228_020.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_228_018:
	video type=0, offset=COMMON_VIDEO_228, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_228_021.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_228_021.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_220_008:
	video type=0, offset=COMMON_VIDEO_220, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_220_009.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_220_009.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_216_027:
	video type=0, offset=COMMON_VIDEO_216, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_216_028.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_216_028.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV263_AT_X07_Y08.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV263_AT_X07_Y08.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV263_AT_X07_Y08.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_266_005.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_266_029.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_266_029.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_269_024.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_269_024.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_269_024.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_272_003.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_272_003.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_272_003.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV275_AT_X07_Y08.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV275_AT_X07_Y08.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV275_AT_X07_Y08.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_272_003__PRISON_INLINE_SETTERS_AND_INIT_001:
	video type=0, offset=COMMON_VIDEO_272, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_272_004.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_272_004.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_272_003__PRISON_INLINE_SETTERS_AND_INIT_002:
	video type=0, offset=COMMON_VIDEO_272, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_272_005.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_272_005.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_269_024__PRISON_INLINE_SETTERS_AND_INIT_001:
	video type=0, offset=COMMON_VIDEO_269, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_269_025.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_269_025.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_269_024__PRISON_INLINE_SETTERS_AND_INIT_002:
	video type=0, offset=COMMON_VIDEO_269, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_269_026.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_269_026.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_266_005:
	video type=0, offset=COMMON_VIDEO_266, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_266_030.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_266_030.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_243_012.inc"
;@endif


;@include "../_helpers/DEDUP_CAVES_5B_020.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_PRISON_5B_006.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_PRISON_5B_006.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_PRISON_5B_006.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV246_AT_X07_Y08.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV246_AT_X07_Y08.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV246_AT_X07_Y08.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV249_AT_X07_Y08.inc"
;@endif


;@include "../_helpers/DEDUP_CAVES_5B_007.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_PRISON_5B_014.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_PRISON_5B_014.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_PRISON_5B_014.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_252_018.inc"
;@endif


