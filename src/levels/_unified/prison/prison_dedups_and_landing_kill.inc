DEDUP_CAVES_5B_007_001:
	sub [0x08], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_PRISON_5B_015.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_PRISON_5B_015.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_PRISON_5B_015.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/INLINE_DRAW_CV_255_010.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_255_010.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_255_010.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_255_010:
	video type=0, offset=COMMON_VIDEO_255, x=[0x07], y=[0x08], zoom=0x40
;@endif


DEDUP_CAVES_5B_020:
	add [0x08], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_PRISON_5B_007.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_PRISON_5B_007.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_PRISON_5B_007.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_252_018:
	video type=0, offset=COMMON_VIDEO_252, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_252_019.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_252_019.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV259_AT_X07_Y08.inc"
;@endif


DEDUP_CAVES_5B_007_002:
	sub [0x08], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_PRISON_5B_016.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_PRISON_5B_016.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_PRISON_5B_016.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV261_AT_X07_Y08.inc"
;@endif


DEDUP_CAVES_5B_007_003:
	sub [0x08], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_PRISON_5B_017.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_PRISON_5B_017.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_PRISON_5B_017.inc"
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

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_164:
	video type=1, offset=CINEMATIC_164, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_165:
	video type=1, offset=CINEMATIC_165, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_166:
	video type=1, offset=CINEMATIC_166, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_167:
	video type=1, offset=CINEMATIC_167, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_163:
	video type=1, offset=CINEMATIC_163, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_162:
	video type=1, offset=CINEMATIC_162, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_161:
	video type=1, offset=CINEMATIC_161, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_160:
	video type=1, offset=CINEMATIC_160, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_159:
	video type=1, offset=CINEMATIC_159, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_158:
	video type=1, offset=CINEMATIC_158, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_157:
	video type=1, offset=CINEMATIC_157, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_157.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_157.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_168:
	video type=1, offset=CINEMATIC_168, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
;@include "post_DRAW_CIN_168.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_169:
	video type=1, offset=CINEMATIC_169, x=[0xf5], y=[0x08], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_169.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_169.inc"
;@endif

;@include "../_helpers/DECREMENT_VAR08_BY_D.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DECREMENT_VAR08_BY_D.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DECREMENT_VAR08_BY_D.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DECREMENT_VAR08_BY_D.inc"
;@endif

KILL_CHANNEL_LANDING_002:
	killChannel

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_KILL_041.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_KILL_041.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_KILL_041.inc"
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
DRAW_CV_078:
	video type=0, offset=COMMON_VIDEO_078, x=[0x01], y=[0x02], zoom=0x40
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_078.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_078.inc"
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
DRAW_CV_070:
	video type=0, offset=COMMON_VIDEO_070, x=[0x01], y=[0x02], zoom=0x40
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_070.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_070.inc"
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
DRAW_CV108_PLAY_60_F0F_V2A_C0:
	video type=0, offset=COMMON_VIDEO_108, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x00
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV108_PLAY_60_F0F_V2A_C0.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV108_PLAY_60_F0F_V2A_C0.inc"
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
DRAW_CV098_PLAY_60_F0F_V2A_C0:
	video type=0, offset=COMMON_VIDEO_098, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x00
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV098_PLAY_60_F0F_V2A_C0.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV098_PLAY_60_F0F_V2A_C0.inc"
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


;@if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV_106:
	video type=0, offset=COMMON_VIDEO_106, x=[0x01], y=[0x02], zoom=0x40
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV_106.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV_106.inc"
;@endif

;@include "../_helpers/INLINE_SET_VAR20_TO_1.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR20_TO_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR20_TO_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR20_TO_1.inc"
;@endif

