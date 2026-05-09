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
;@include "../_helpers/RET_THEN_KILL_CHANNEL.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_RET_THEN_KILL_CHANNEL.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_RET_THEN_KILL_CHANNEL.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_486:
	video offset=CINEMATIC_486, x=[0x21], y=[0x27]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_486.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_486.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_483:
	video offset=CINEMATIC_483, x=[0x21], y=[0x27]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_483.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_483.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN473_AT_X21_Y27_ZOOM_40:
	video offset=CINEMATIC_473, x=[0x21], y=[0x27]
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
	video offset=CINEMATIC_502, x=[0x21], y=[0x27]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_502.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_502.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_499:
	video offset=CINEMATIC_499, x=[0x21], y=[0x27]
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_499.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_499.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN489_AT_X21_Y27_ZOOM_40:
	video offset=CINEMATIC_489, x=[0x21], y=[0x27]
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
	video offset=CINEMATIC_085, x=132, y=39
	video offset=CINEMATIC_085, x=297, y=39
	video offset=CINEMATIC_086, x=132, y=39
	video offset=CINEMATIC_086, x=297, y=39
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
	video offset=CINEMATIC_305, x=160, y=100
	video offset=CINEMATIC_306, x=160, y=100
	video offset=CINEMATIC_307, x=160, y=100
	video offset=CINEMATIC_308, x=160, y=100
	video offset=CINEMATIC_309, x=160, y=100
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_305_TO_333_7F_AT_96C7E6A8:
	fill page=0x00, color=0x03
	video offset=CINEMATIC_305, x=160, y=100
	video offset=CINEMATIC_328, x=160, y=100
	video offset=CINEMATIC_329, x=160, y=100
	video offset=CINEMATIC_330, x=160, y=100
	video offset=CINEMATIC_331, x=160, y=100
	video offset=CINEMATIC_332, x=160, y=100
	video offset=CINEMATIC_333, x=160, y=100
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
	video offset=CINEMATIC_024, x=160, y=100
	video offset=CINEMATIC_025, x=160, y=100
	video offset=CINEMATIC_026, x=160, y=100
	video offset=CINEMATIC_027, x=160, y=100
	video offset=CINEMATIC_028, x=160, y=100
	video offset=CINEMATIC_029, x=160, y=400
	video offset=CINEMATIC_030, x=160, y=100
	video offset=CINEMATIC_031, x=160, y=100
	video offset=CINEMATIC_032, x=160, y=100
	video offset=CINEMATIC_033, x=160, y=100
	video offset=CINEMATIC_034, x=160, y=100
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_FILL_AND_DRAW_CIN_24_28.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_FILL_AND_DRAW_CIN_24_28.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_624_TO_628_5F_AT_499AFE0A:
	video offset=CINEMATIC_624, x=160, y=100
	break
	video offset=CINEMATIC_625, x=160, y=100
	break
	video offset=CINEMATIC_626, x=160, y=100
	break
	video offset=CINEMATIC_627, x=160, y=100
	break
	video offset=CINEMATIC_628, x=160, y=100
	killChannel
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_628_TO_625_4F_AT_2F47D6D0:
	video offset=CINEMATIC_628, x=160, y=100
	break
	video offset=CINEMATIC_627, x=160, y=100
	break
	video offset=CINEMATIC_626, x=160, y=100
	break
	video offset=CINEMATIC_625, x=160, y=100
	break
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_628_TO_625_4F_AT_2F47D6D0.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_628_TO_625_4F_AT_2F47D6D0.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_229_TO_632_2F_AT_1C4A817A:
	video offset=CINEMATIC_229, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_632, x=[BUDDY_X], y=[BUDDY_Y]
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
	video offset=CINEMATIC_683, x=160, y=100
	video offset=CINEMATIC_684, x=160, y=100
	video offset=CINEMATIC_685, x=160, y=100
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

