DEDUP_CAVES_6B_001:
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_6B_002.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_6B_002.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_6B_002.inc"
;@endif

;@include "../_helpers/SHARED_RET.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SHARED_RET.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SHARED_RET.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SHARED_RET.inc"
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
;@include "cart__post_INLINE_DRAW_CV_216_029.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_216_029.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_220_008.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_220_016.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_220_016.inc"
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
;@include "cart__post_INLINE_DRAW_CV_228_018.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_228_018.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_228_018:
	video type=0, offset=COMMON_VIDEO_228, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_228_019.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_228_019.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_220_008:
	video type=0, offset=COMMON_VIDEO_220, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_220_017.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_220_017.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_216_027:
	video type=0, offset=COMMON_VIDEO_216, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_216_030.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_216_030.inc"
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
;@include "cart__post_INLINE_DRAW_CV_266_005.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_266_005.inc"
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
;@include "cart__post_INLINE_DRAW_CV_272_013.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_272_013.inc"
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
INLINE_DRAW_CV_272_003__CAVES_INLINE_SETTERS_AND_INIT_001:
	video type=0, offset=COMMON_VIDEO_272, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_272_014.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_272_014.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_272_003__CAVES_INLINE_SETTERS_AND_INIT_002:
	video type=0, offset=COMMON_VIDEO_272, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_272_015.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_272_015.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_269_024__CAVES_INLINE_SETTERS_AND_INIT_001:
	video type=0, offset=COMMON_VIDEO_269, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_269_025.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_269_025.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_269_024__CAVES_INLINE_SETTERS_AND_INIT_002:
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
;@include "cart__post_INLINE_DRAW_CV_266_006.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_266_006.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_243_012.inc"
;@endif


;@include "../_helpers/DEDUP_CAVES_5B_020.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_020.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_020.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_020.inc"
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
;@include "amiga__post_DEDUP_CAVES_5B_007.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_007.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_007.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_252_018.inc"
;@endif


DEDUP_CAVES_5B_007__CAVES_INLINE_SETTERS_AND_INIT_001:
	sub [0x08], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_008.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_008.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_008.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_255_010.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_255_031.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_255_031.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_255_010:
	video type=0, offset=COMMON_VIDEO_255, x=[0x07], y=[0x08], zoom=0x40
;@endif


DEDUP_CAVES_5B_020:
	add [0x08], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_021.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_021.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_021.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_252_018:
	video type=0, offset=COMMON_VIDEO_252, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_252_023.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_252_023.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV259_AT_X07_Y08.inc"
;@endif


DEDUP_CAVES_5B_007__CAVES_INLINE_SETTERS_AND_INIT_002:
	sub [0x08], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_009.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_009.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_009.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV261_AT_X07_Y08.inc"
;@endif


DEDUP_CAVES_5B_007__CAVES_INLINE_SETTERS_AND_INIT_003:
	sub [0x08], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_010.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_010.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_010.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_243_012:
	video type=0, offset=COMMON_VIDEO_243, x=[0x07], y=[0x08], zoom=0x40
;@endif


;@include "../_helpers/INCREMENT_VAR07_BY_1.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INCREMENT_VAR07_BY_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INCREMENT_VAR07_BY_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INCREMENT_VAR07_BY_1.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV_301:
	video type=0, offset=COMMON_VIDEO_301, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_301.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_301.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_355.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_355.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_355.inc"
;@endif

;@include "../_helpers/DECREMENT_VAR08_BY_D.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DECREMENT_VAR08_BY_D.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DECREMENT_VAR08_BY_D.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DECREMENT_VAR08_BY_D.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_074.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_074.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_074.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_075.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_075.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_075.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_076.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_076.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_076.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_077.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_077.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_077.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV078_PLAY_60_F0B_V22_C1:
	video type=0, offset=COMMON_VIDEO_078, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x01
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV078_PLAY_60_F0B_V22_C1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV078_PLAY_60_F0B_V22_C1.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_080.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_080.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_080.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_061.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_061.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_061.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_063.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_063.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_063.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_065.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_065.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_065.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_067.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_067.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_067.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_069.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_069.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_069.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV070_PLAY_60_F14_V20_C1:
	video type=0, offset=COMMON_VIDEO_070, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x20, channel=0x01
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV070_PLAY_60_F14_V20_C1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV070_PLAY_60_F14_V20_C1.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_071.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_071.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_071.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_072.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_072.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_072.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_073.inc"
;@endif


;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_300.inc"
;@endif


;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_299.inc"
;@endif


;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_295.inc"
;@endif


;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_296.inc"
;@endif


;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_297.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_297.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_297.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_298.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_298.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_298.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV107_AT_X01_Y02.inc"
;@endif


;@if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV108_PLAY_60_F0F_V2A_C1:
	video type=0, offset=COMMON_VIDEO_108, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x01
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV108_PLAY_60_F0F_V2A_C1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV108_PLAY_60_F0F_V2A_C1.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV109_AT_X01_Y02.inc"
;@endif


;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_110.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_110.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_110.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV111_AT_X01_Y02.inc"
;@endif


;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_112.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_112.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_112.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV113_AT_X01_Y02.inc"
;@endif


;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_114.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_114.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_114.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_115.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_115.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_115.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV097_AT_X01_Y02.inc"
;@endif


;@if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV098_PLAY_60_F0A_V2A_C1:
	video type=0, offset=COMMON_VIDEO_098, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x0A, vol=0x2A, channel=0x01
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV098_PLAY_60_F0A_V2A_C1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV098_PLAY_60_F0A_V2A_C1.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV099_AT_X01_Y02.inc"
;@endif


;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_100.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_100.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_100.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV101_AT_X01_Y02.inc"
;@endif


;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_102.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_102.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_102.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV103_AT_X01_Y02.inc"
;@endif


;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV_104.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_104.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_104.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV105_AT_X01_Y02.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV105_AT_X01_Y02.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV105_AT_X01_Y02.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_SET_VAR20_TO_1.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR20_TO_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR20_TO_1.inc"
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

SET_VAR22_TO_006B:
	mov [0x22], 0x006B
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_006B.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_006B.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_006B.inc"
;@endif

SET_VAR22_TO_0061:
	mov [0x22], 0x0061
	ret


SET_VAR22_TO_00C8:
	mov [0x22], 0x00C8
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_00C8.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00C8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00C8.inc"
;@endif

PROJ_VAR22_68_MINUS_VAR21_MINUS_F2_SHR4:
	sub [0x21], 0x00F2
	shr [0x21], 0x0004
	mov [0x22], 0x0068
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_68_MINUS_VAR21_MINUS_F2_SHR4.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_68_MINUS_VAR21_MINUS_F2_SHR4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_68_MINUS_VAR21_MINUS_F2_SHR4.inc"
;@endif

DEDUP_CAVES_5B_027:
	mov [0x22], 0x006F
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_027.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_027.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_027.inc"
;@endif

PROJ_VAR22_2F_MINUS_VAR21_MINUS_ED_SHR1:
	sub [0x21], 0x00ED
	shr [0x21], 0x0001
	mov [0x22], 0x002F
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_2F_MINUS_VAR21_MINUS_ED_SHR1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_2F_MINUS_VAR21_MINUS_ED_SHR1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_2F_MINUS_VAR21_MINUS_ED_SHR1.inc"
;@endif

SET_VAR22_TO_00AB:
	mov [0x22], 0x00AB
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_00AB.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00AB.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00AB.inc"
;@endif

PROJ_VAR22_17_MINUS_VAR21_MINUS_F0_SHL3:
	sub [0x21], 0x00F0
	shl [0x21], 0x0003
	mov [0x22], 0x0017
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_17_MINUS_VAR21_MINUS_F0_SHL3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_17_MINUS_VAR21_MINUS_F0_SHL3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_17_MINUS_VAR21_MINUS_F0_SHL3.inc"
;@endif

PROJ_VAR22_AA_MINUS_VAR21_MINUS_115_SHR3:
	sub [0x21], 0x0115
	shr [0x21], 0x0003
	mov [0x22], 0x00AA
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_AA_MINUS_VAR21_MINUS_115_SHR3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_AA_MINUS_VAR21_MINUS_115_SHR3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_AA_MINUS_VAR21_MINUS_115_SHR3.inc"
;@endif

INIT_VARS_01_22:
	mov [0x01], 0x0078
	mov [0x22], 0x0064
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_01_22.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_01_22.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_01_22.inc"
;@endif

PROJ_VAR22_B3_MINUS_VAR21_MINUS_109_SHR3:
	sub [0x21], 0x0109
	shr [0x21], 0x0003
	mov [0x22], 0x00B3
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_B3_MINUS_VAR21_MINUS_109_SHR3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_B3_MINUS_VAR21_MINUS_109_SHR3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_B3_MINUS_VAR21_MINUS_109_SHR3.inc"
;@endif

PROJ_VAR22_53_PLUS_VAR21_MINUS_106_SHR3:
	sub [0x21], 0x0106
	shr [0x21], 0x0003
	mov [0x22], 0x0053
	add [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_53_PLUS_VAR21_MINUS_106_SHR3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_53_PLUS_VAR21_MINUS_106_SHR3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_53_PLUS_VAR21_MINUS_106_SHR3.inc"
;@endif

PROJ_VAR22_9E_MINUS_VAR21_MINUS_121_SHR3:
	sub [0x21], 0x0121
	shr [0x21], 0x0003
	mov [0x22], 0x009E
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_9E_MINUS_VAR21_MINUS_121_SHR3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_9E_MINUS_VAR21_MINUS_121_SHR3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_9E_MINUS_VAR21_MINUS_121_SHR3.inc"
;@endif

PROJ_VAR22_7E_MINUS_VAR21_MINUS_11B_SHR4:
	sub [0x21], 0x011B
	shr [0x21], 0x0004
	mov [0x22], 0x007E
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_7E_MINUS_VAR21_MINUS_11B_SHR4.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_7E_MINUS_VAR21_MINUS_11B_SHR4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_7E_MINUS_VAR21_MINUS_11B_SHR4.inc"
;@endif

PROJ_VAR22_75_MINUS_VAR21_MINUS_FD_SHR6:
	sub [0x21], 0x00FD
	shr [0x21], 0x0006
	mov [0x22], 0x0075
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_75_MINUS_VAR21_MINUS_FD_SHR6.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_75_MINUS_VAR21_MINUS_FD_SHR6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_75_MINUS_VAR21_MINUS_FD_SHR6.inc"
;@endif

PROJ_VAR22_76_MINUS_VAR21_MINUS_108_SHR5:
	sub [0x21], 0x0108
	shr [0x21], 0x0005
	mov [0x22], 0x0076
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_76_MINUS_VAR21_MINUS_108_SHR5.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_76_MINUS_VAR21_MINUS_108_SHR5.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_76_MINUS_VAR21_MINUS_108_SHR5.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
PROJ_VAR22_49_MINUS_VAR21_MINUS_113_SHR4:
	sub [0x21], 0x0113
	shr [0x21], 0x0004
	mov [0x22], 0x0049
	sub [0x22], [0x21]
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_49_MINUS_VAR21_MINUS_113_SHR4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_49_MINUS_VAR21_MINUS_113_SHR4.inc"
;@endif

SET_VAR22_TO_007D:
	mov [0x22], 0x007D
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_007D.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_007D.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_007D.inc"
;@endif

SET_VAR22_TO_0080:
	mov [0x22], 0x0080
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_0080.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_0080.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_0080.inc"
;@endif

SET_VAR22_TO_00AC:
	mov [0x22], 0x00AC
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_00AC.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00AC.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00AC.inc"
;@endif

SET_VAR22_TO_0087:
	mov [0x22], 0x0087
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_0087.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_0087.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_0087.inc"
;@endif

PROJ_VAR22_85_PLUS_VAR21_MINUS_56:
	sub [0x21], 0x0056
	mov [0x22], 0x0085
	add [0x22], [0x21]
	ret


SET_VAR22_TO_0085:
	mov [0x22], 0x0085
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_0085.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_0085.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_0085.inc"
;@endif

SET_VAR22_TO_00C3:
	mov [0x22], 0x00C3
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_00C3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00C3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00C3.inc"
;@endif

PROJ_VAR22_A8_MINUS_VAR21_MINUS_112_SHR4:
	sub [0x21], 0x0112
	shr [0x21], 0x0004
	mov [0x22], 0x00A8
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_A8_MINUS_VAR21_MINUS_112_SHR4.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_A8_MINUS_VAR21_MINUS_112_SHR4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_A8_MINUS_VAR21_MINUS_112_SHR4.inc"
;@endif

DEDUP_CAVES_5B_011:
	mov [0x22], 0x00B0
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_011.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_011.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_011.inc"
;@endif

PROJ_VAR22_B0_PLUS_VAR21_MINUS_69:
	sub [0x21], 0x0069
	mov [0x22], 0x00B0
	add [0x22], [0x21]
	ret


DEDUP_CAVES_5B_012:
	mov [0x22], 0x00B0
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_012.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_012.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_012.inc"
;@endif

DEDUP_CAVES_5B_028:
	mov [0x22], 0x006F
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_028.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_028.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_028.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
SET_VAR22_TO_0042:
	mov [0x22], 0x0042
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_0042.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_0042.inc"
;@endif

SET_VAR22_TO_00AE:
	mov [0x22], 0x00AE
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_00AE.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00AE.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00AE.inc"
;@endif

PROJ_VAR22_A7_MINUS_VAR21_MINUS_125_SHR3:
	sub [0x21], 0x0125
	shr [0x21], 0x0003
	mov [0x22], 0x00A7
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_A7_MINUS_VAR21_MINUS_125_SHR3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_A7_MINUS_VAR21_MINUS_125_SHR3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_A7_MINUS_VAR21_MINUS_125_SHR3.inc"
;@endif

;@include "../_helpers/SET_VAR22_TO_00B8.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_00B8.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00B8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00B8.inc"
;@endif

INIT_VARS_EB_47:
	mov [0xEB], 0x000A
	mov [0x47], 0x010A

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_EB_47.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_EB_47.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_EB_47.inc"
;@endif

PLAY_FX_6B_THEN_KILL_CHANNEL:
	play id=0x006B, freq=0x1C, vol=0x40, channel=0x03
	killChannel

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PLAY_FX_6B_THEN_KILL_CHANNEL.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PLAY_FX_6B_THEN_KILL_CHANNEL.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PLAY_FX_6B_THEN_KILL_CHANNEL.inc"
;@endif

