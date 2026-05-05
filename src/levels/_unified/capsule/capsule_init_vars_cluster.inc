;@if BRANCH in ("cartridge_1992", "dos_1992")
INCR_VAR07_OR_VARBB_VAR73_INIT_VAR29:
	add [BUDDY_X], 0x0014
	or [0xBB], 0x0004
	or [0x73], 0x4000
	mov [0x29], 0x0010
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INCR_VAR07_OR_VARBB_VAR73_INIT_VAR29.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INCR_VAR07_OR_VARBB_VAR73_INIT_VAR29.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_29_0E:
	mov [0x29], 0x000A
	mov [0x0E], 0x0000
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_29_0E.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_29_0E.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_E6_07_08:
	mov [0xE6], 0x0003
	mov [BUDDY_X], 0x007B
	mov [BUDDY_Y], 0x00AC
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_E6_07_08.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_E6_07_08.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_0E_29:
	mov [0x0E], 0x0000
	mov [0x29], 0x0005
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_0E_29.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_0E_29.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_63_01_02_03:
	mov [0x63], 0x0064
	mov [HERO_X], 0x00C4
	mov [HERO_Y], 0x00B9
	mov [0x03], 0x0004
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_63_01_02_03.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_63_01_02_03.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_E7_E8:
	mov [0xE7], 0x0000
	mov [0xE8], 0x001E
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_E7_E8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_E7_E8.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_E9_EA:
	mov [0xE9], 0x012C
	mov [0xEA], 0x0014
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_E9_EA.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_E9_EA.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_SET_VARE6_TO_14:
	mov [0xE6], 0x0014
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VARE6_TO_14.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VARE6_TO_14.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_SET_VARE6_TO_28:
	mov [0xE6], 0x0028
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VARE6_TO_28.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VARE6_TO_28.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
PLAY_FX_30_CH2_LOUD_SET_VARED_5:
	mov [0xED], 0x0005
	play id=0x0030, freq=0x11, vol=0x22, channel=0x02
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_PLAY_FX_30_CH2_LOUD_SET_VARED_5.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PLAY_FX_30_CH2_LOUD_SET_VARED_5.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
PLAY_FX_52_CH3_SET_VARED_A:
	mov [0xED], 0x000A
	play id=0x0052, freq=0x02, vol=0x18, channel=0x03
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_PLAY_FX_52_CH3_SET_VARED_A.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PLAY_FX_52_CH3_SET_VARED_A.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
PLAY_FX_30_CH2_VOL_C_SET_VARED_A:
	mov [0xED], 0x000A
	play id=0x0030, freq=0x11, vol=0x0C, channel=0x02
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_PLAY_FX_30_CH2_VOL_C_SET_VARED_A.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PLAY_FX_30_CH2_VOL_C_SET_VARED_A.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
PLAY_FX_56_CH3_SET_VAREE_F:
	mov [0xEE], 0x000F
	play id=0x0056, freq=0x07, vol=0x0C, channel=0x03
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_PLAY_FX_56_CH3_SET_VAREE_F.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PLAY_FX_56_CH3_SET_VAREE_F.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_E6_E7:
	mov [0xE6], 0x00E8
	mov [0xE7], 0x0041
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_E6_E7.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_E6_E7.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_03_01:
	mov [0x03], 0x000A
	mov [HERO_X], 0x00C7
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_03_01.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_03_01.inc"
;@endif
