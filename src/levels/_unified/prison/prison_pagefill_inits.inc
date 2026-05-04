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


