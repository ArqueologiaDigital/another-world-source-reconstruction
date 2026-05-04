INLINE_SET_VAR03_TO_7:
	mov [0x03], 0x0007

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR03_TO_7.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR03_TO_7.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR03_TO_7.inc"
;@endif

;@include "../_helpers/INCREMENT_VAR31.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INCREMENT_VAR31_BY_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INCREMENT_VAR31_BY_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INCREMENT_VAR31_BY_1.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/SCROLL_BLIT_P80_TO_PFF_OFFSET_00C8.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_SCROLL_BLIT_P80_TO_PFF_OFFSET_00C8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SCROLL_BLIT_P80_TO_PFF_OFFSET_00C8.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_CLEAR_PAGES_1_2_AND_BLIT_CHAIN_X8.inc"
;@endif

;@include "../_helpers/COPY_HASH_VAR_37_TO_RANGE.inc"
;@include "../_helpers/ACCUMULATE_HASH_INTO_VAR37_38.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_ACCUMULATE_HASH_VAR37_38_X3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_ACCUMULATE_HASH_VAR37_38_X3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_ACCUMULATE_HASH_VAR37_38_X3.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_311_THEN_CIN_314:
	video type=1, offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40
	video type=1, offset=CINEMATIC_314, x=[0xe6], y=[0xe7], zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_311_TO_313_2F_AT_6BB0E3FE:
	video type=1, offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40
	add [0xE6], 0x0001
	video type=1, offset=CINEMATIC_313, x=[0xe6], y=[0xe7], zoom=0x40
	sub [0xE6], 0x0001
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_311_TO_312_2F_AT_1550824C:
	video type=1, offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40
	add [0xE6], 0x0002
	video type=1, offset=CINEMATIC_312, x=[0xe6], y=[0xe7], zoom=0x40
	sub [0xE6], 0x0002
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_311_TO_312_2F_AT_26843400:
	video type=1, offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40
	add [0xE6], 0x0003
	video type=1, offset=CINEMATIC_312, x=[0xe6], y=[0xe7], zoom=0x40
	sub [0xE6], 0x0003
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_311_TO_312_2F_AT_2A88A18A:
	video type=1, offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40
	add [0xE6], 0x0004
	video type=1, offset=CINEMATIC_312, x=[0xe6], y=[0xe7], zoom=0x40
	sub [0xE6], 0x0004
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_311_TO_312_2F_AT_76F1E2F4:
	video type=1, offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40
	add [0xE6], 0x0006
	video type=1, offset=CINEMATIC_312, x=[0xe6], y=[0xe7], zoom=0x40
	sub [0xE6], 0x0006
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_311_TO_312_2F_AT_A6494EF7:
	video type=1, offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40
	add [0xE6], 0x0008
	video type=1, offset=CINEMATIC_312, x=[0xe6], y=[0xe7], zoom=0x40
	sub [0xE6], 0x0008
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_311_TO_312_2F_AT_A6494EF7.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_311_TO_312_2F_AT_A6494EF7.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_315_PROGRESSIVE:
	add [0xF8], 0x004B
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_315, x=[0xf8], y=187, zoom=0x40
	add [0xF8], 0x0055
	video type=1, offset=CINEMATIC_315, x=[0xf8], y=186, zoom=0x40
	add [0xF8], 0x002C
	video type=1, offset=CINEMATIC_315, x=[0xf8], y=186, zoom=0x40
	add [0xF8], 0x0003
	video type=1, offset=CINEMATIC_315, x=[0xf8], y=187, zoom=0x40
	add [0xF8], 0x0004
	video type=1, offset=CINEMATIC_315, x=[0xf8], y=93, zoom=0x40
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_316_TO_316_2F_AT_A17C45BF:
	add [0xF8], 0x0038
	video type=1, offset=CINEMATIC_316, x=[0xf8], y=186, zoom=0x40
	add [0xF8], 0x0029
	video type=1, offset=CINEMATIC_316, x=[0xf8], y=186, zoom=0x40
	selectVideoPage 0xFF
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_316_TO_316_2F_AT_A17C45BF.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_316_TO_316_2F_AT_A17C45BF.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_319_TO_319_4F_AT_9E666694:
	video type=1, offset=CINEMATIC_319, x=53, y=141
	video type=1, offset=CINEMATIC_319, x=153, y=141
	video type=1, offset=CINEMATIC_319, x=208, y=141
	video type=1, offset=CINEMATIC_319, x=302, y=141, zoom=0x40
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_319_TO_319_4F_AT_9E666694.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_319_TO_319_4F_AT_9E666694.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_318_TO_318_2F_AT_93A8CE70:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_318, x=225, y=50
	video type=1, offset=CINEMATIC_318, x=278, y=50, zoom=0x40
	selectVideoPage 0xFF
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_318_TO_318_2F_AT_93A8CE70.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_318_TO_318_2F_AT_93A8CE70.inc"
;@endif

INLINE_SET_VARE6_TO_50:
	mov [0xE6], 0x0050

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VARE6_TO_50.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VARE6_TO_50.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VARE6_TO_50.inc"
;@endif

INLINE_SET_VARE7_TO_5:
	mov [0xE7], 0x0005

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VARE7_TO_5.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VARE7_TO_5.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VARE7_TO_5.inc"
;@endif

INIT_VARS_E7_E8:
	mov [0xE7], 0x0007
	mov [0xE8], 0x0064

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_E7_E8.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_E7_E8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_E7_E8.inc"
;@endif

INLINE_SET_VARE9_TO_8:
	mov [0xE9], 0x0008

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VARE9_TO_8.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VARE9_TO_8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VARE9_TO_8.inc"
;@endif

KILL_CHANNEL_LANDING__PRISON_INLINE_SETTERS_AND_INIT_001:
	killChannel

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_KILL_040.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_KILL_040.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_KILL_040.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_154_TO_156_3F_AT_A74B7DB1:
	video type=1, offset=CINEMATIC_154, x=160, y=[0x19], zoom=0x40
	play id=0x0058, freq=0x14, vol=0x20, channel=0x01
	break
	video type=1, offset=CINEMATIC_155, x=160, y=[0x19], zoom=0x40
	break
	video type=1, offset=CINEMATIC_156, x=160, y=[0x19], zoom=0x40
	killChannel
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_151_TO_153_3F_AT_40D20636:
	video type=1, offset=CINEMATIC_151, x=160, y=[0x19], zoom=0x40
	play id=0x0058, freq=0x0F, vol=0x10, channel=0x00
	break
	video type=1, offset=CINEMATIC_152, x=160, y=[0x19], zoom=0x40
	break
	video type=1, offset=CINEMATIC_153, x=160, y=[0x19], zoom=0x40
	killChannel
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_149_TO_150_2F_AT_F63AB95D:
	video type=1, offset=CINEMATIC_149, x=160, y=[0x19], zoom=0x40
	play id=0x0058, freq=0x0C, vol=0x18, channel=0x01
	break
	video type=1, offset=CINEMATIC_150, x=160, y=[0x19], zoom=0x40
	killChannel
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_132_TO_133_2F_AT_BB9185F0:
	video type=1, offset=CINEMATIC_132, x=160, y=[0x19], zoom=0x40
	play id=0x0058, freq=0x14, vol=0x1C, channel=0x00
	break
	video type=1, offset=CINEMATIC_133, x=160, y=[0x19], zoom=0x40
	killChannel
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_132_TO_133_2F_AT_BB9185F0.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_132_TO_133_2F_AT_BB9185F0.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_280_TO_281_2F_AT_75ED3E60:
	sub [0x01], 0x0003
	video type=1, offset=CINEMATIC_280, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_281, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	mov [0x03], 0x0003
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_280_TO_281_2F_AT_75ED3E60.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_280_TO_281_2F_AT_75ED3E60.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_284_BLOCK_95B:
	video type=1, offset=CINEMATIC_284, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_285, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_286, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_287, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_288, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_289, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_290, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_291, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_292, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_293, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_294, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_295, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_296, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_297, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_296, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_296, x=[0x01], y=[0x02], zoom=0x40
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_284_BLOCK_95B.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_284_BLOCK_95B.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_146_TO_147_4F_AT_8AA18039:
	video type=1, offset=CINEMATIC_146, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_147, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_148, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_147, x=[0x01], y=[0x02], zoom=0x40
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_137_138_BLOCK:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_137, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	play id=0x005A, freq=0x14, vol=0x40, channel=0x00
	break
	video type=1, offset=CINEMATIC_138, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_139, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_140, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_141, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_142, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_143, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_144, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_145, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	killChannel
	video type=1, offset=CINEMATIC_146, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_147, x=[0x01], y=[0x02], zoom=0x40
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_137_138_BLOCK.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_137_138_BLOCK.inc"
;@endif

;@include "../_helpers/DERIVE_VAR12_11_10_FROM_VAR9.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DERIVE_VAR12_11_10_FROM_VAR9.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DERIVE_VAR12_11_10_FROM_VAR9.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DERIVE_VAR12_11_10_FROM_VAR9.inc"
;@endif

;@include "../_helpers/INLINE_COPY_VAR22_TO_VAR08.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_COPY_VAR22_TO_VAR08.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_COPY_VAR22_TO_VAR08.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_COPY_VAR22_TO_VAR08.inc"
;@endif

;@include "../_helpers/SPLIT_VAR09_BITS_INTO_VAR0D.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SPLIT_VAR09_BITS_INTO_VAR0D.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SPLIT_VAR09_BITS_INTO_VAR0D.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SPLIT_VAR09_BITS_INTO_VAR0D.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_393_AT_VAR07_08:
	video type=1, offset=CINEMATIC_393, x=[0x07], y=[0x08], zoom=0x40
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_393_AT_VAR07_08.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_393_AT_VAR07_08.inc"
;@endif

INLINE_SET_VAR29_TO_5:
	mov [0x29], 0x0005

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR29_TO_5.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR29_TO_5.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR29_TO_5.inc"
;@endif

;@include "../_helpers/INLINE_SET_VAR29_TO_6.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR29_TO_6.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR29_TO_6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR29_TO_6.inc"
;@endif

INLINE_SET_VARF1_TO_64:
	mov [0xF1], 0x0064

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VARF1_TO_64.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VARF1_TO_64.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VARF1_TO_64.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_406_408_BLOCK:
	video type=1, offset=CINEMATIC_406, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_407, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_408, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_409, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_409, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_408, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_409, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_410, x=160, y=100
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_411, x=[0x07], y=[0x08], zoom=0x40
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_406_408_BLOCK.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_406_408_BLOCK.inc"
;@endif

INLINE_SET_VAR29_TO_28:
	mov [0x29], 0x0028

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR29_TO_28.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR29_TO_28.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR29_TO_28.inc"
;@endif

INLINE_SUB_VAR08_INIT_VAR29:
	sub [0x08], 0x0005
	mov [0x29], 0x000A

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_FOLD_BODY_89B_179104BB.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_FOLD_BODY_89B_179104BB.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_FOLD_BODY_89B_179104BB.inc"
;@endif

SET_VAR29_TO_000A:
	mov [0x29], 0x000A
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR29_TO_000A.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR29_TO_000A.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR29_TO_000A.inc"
;@endif

INIT_VARS_0E_29:
	mov [0x0E], 0x0000
	mov [0x29], 0xFFFF
	ret


DECREMENT_VAR29_BY_1:
	sub [0x29], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DECREMENT_VAR29_BY_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DECREMENT_VAR29_BY_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DECREMENT_VAR29_BY_1.inc"
;@endif

BIT_EXTRACT_FROM_VAR24_TO_VAR25:
	mov [0x25], [0x24]
	and [0x25], 0x00FF
	shr [0x24], 0x0008
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_FOLD_BODY_144B_C55279EA.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_FOLD_BODY_144B_C55279EA.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_FOLD_BODY_144B_C55279EA.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_569_TO_572_6F_AT_F8680E45:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_569, x=160, y=100
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_570, x=228, y=175
	break
	video type=1, offset=CINEMATIC_571, x=232, y=175
	video type=1, offset=CINEMATIC_572, x=160, y=100
	break
	video type=1, offset=CINEMATIC_573, x=245, y=175
	video type=1, offset=CINEMATIC_572, x=160, y=100
	killChannel
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_570_574_BLOCK:
	mov [0x57], 0x0002
	video type=1, offset=CINEMATIC_574, x=239, y=175
	video type=1, offset=CINEMATIC_572, x=160, y=100
	break
	video type=1, offset=CINEMATIC_570, x=230, y=175
	video type=1, offset=CINEMATIC_574, x=230, y=175
	video type=1, offset=CINEMATIC_572, x=160, y=100
	break
	video type=1, offset=CINEMATIC_570, x=228, y=175
	break
	video type=1, offset=CINEMATIC_575, x=227, y=175
	break
	video type=1, offset=CINEMATIC_575, x=226, y=175
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_575, x=226, y=175
	selectVideoPage 0xFF
	killChannel
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_576_578_BLOCK:
	video type=1, offset=CINEMATIC_576, x=215, y=131
	break
	video type=1, offset=CINEMATIC_577, x=227, y=141
	break
	mov [0x31], 0x0000
	video type=1, offset=CINEMATIC_578, x=231, y=158
	break
	video type=1, offset=CINEMATIC_579, x=239, y=175
	break
	video type=1, offset=CINEMATIC_578, x=243, y=174
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_274, x=245, y=175
	mov [0x31], 0x0000
	break
	video type=1, offset=CINEMATIC_580, x=247, y=175
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_274, x=249, y=175
	break
	video type=1, offset=CINEMATIC_274, x=250, y=175
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_274, x=251, y=175
	selectVideoPage 0xFF
	killChannel
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_576_578_BLOCK.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_576_578_BLOCK.inc"
;@endif

;@include "../_helpers/AND_VAR11_WITH_EFFF.inc"
;@include "../_helpers/INLINE_OR_VAR11_WITH_1000.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_FOLD_BODY_58B_A2D4469A.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_FOLD_BODY_58B_A2D4469A.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_FOLD_BODY_58B_A2D4469A.inc"
;@endif

SET_VAR2F_TO_001A:
	mov [0x2F], 0x001A
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR2F_TO_001A.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR2F_TO_001A.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR2F_TO_001A.inc"
;@endif

INIT_VARS_2F_29_3:
	mov [0x2F], 0x0003
	mov [0x29], 0x01A4
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_2F_29_3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_2F_29_3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_2F_29_3.inc"
;@endif

INIT_VARS_2F_29:
	mov [0x2F], 0x0019
	mov [0x29], 0x0154
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_2F_29.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_2F_29.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_2F_29.inc"
;@endif

INIT_VARS_2F_29_2:
	mov [0x2F], 0x0009
	mov [0x29], 0x0002
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_2F_29_2.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_2F_29_2.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_2F_29_2.inc"
;@endif

INIT_VARS_B2_2F_29:
	mov [0xB2], 0x0007
	mov [0x2F], 0x0009
	mov [0x29], 0x0001
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_B2_2F_29.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_B2_2F_29.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_B2_2F_29.inc"
;@endif

SET_VAR2F_TO_0009:
	mov [0x2F], 0x0009
	ret


SET_VAR2F_TO_001B:
	mov [0x2F], 0x001B
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR2F_TO_001B.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR2F_TO_001B.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR2F_TO_001B.inc"
;@endif

INIT_VAR29_FROM_VAR50_PLUS_A_VAR2F_10:
	mov [0x29], [0x50]
	add [0x29], 0x000A
	mov [0x2F], 0x0010
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VAR29_FROM_VAR50_PLUS_A_VAR2F_10.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VAR29_FROM_VAR50_PLUS_A_VAR2F_10.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VAR29_FROM_VAR50_PLUS_A_VAR2F_10.inc"
;@endif

INIT_VARS_29_2F:
	mov [0x29], 0x00A1
	mov [0x2F], 0x0018
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_29_2F.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_29_2F.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_29_2F.inc"
;@endif

INIT_VARS_07_2F:
	mov [0x07], 0x001F
	mov [0x2F], 0x0015
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_07_2F.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_07_2F.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_07_2F.inc"
;@endif

INIT_VARS_2F_29_1:
	mov [0x2F], 0x0003
	mov [0x29], 0x0168
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_2F_29_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_2F_29_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_2F_29_1.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
SET_VARS_29_2F:
	mov [0x29], [0x01]
	mov [0x2F], 0x0018
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_FOLD_BODY_99B_32B55F1E.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_FOLD_BODY_99B_32B55F1E.inc"
;@endif

;@include "../_helpers/SET_VAR2F_TO_000F.inc"
SET_VAR2F_TO_000F:
	mov [0x2F], 0x000F
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_PRISON_5B_023.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_PRISON_5B_023.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_PRISON_5B_023.inc"
;@endif

;@include "../_helpers/STEP_VAR29_DOWN10_SET_VAR2F_11.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_STEP_VAR29_DOWN10_SET_VAR2F_11.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_STEP_VAR29_DOWN10_SET_VAR2F_11.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_STEP_VAR29_DOWN10_SET_VAR2F_11.inc"
;@endif

;@include "../_helpers/COMPUTE_VAR26_AS_VAR21_MINUS_VAR22.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COMPUTE_VAR26_AS_VAR21_MINUS_VAR22.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COMPUTE_VAR26_AS_VAR21_MINUS_VAR22.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COMPUTE_VAR26_AS_VAR21_MINUS_VAR22.inc"
;@endif

;@include "../_helpers/INCREMENT_VAR21_BY_F.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INCREMENT_VAR21_BY_F.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INCREMENT_VAR21_BY_F.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INCREMENT_VAR21_BY_F.inc"
;@endif

;@include "../_helpers/INLINE_SUB_VAR22_BY_23.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SUB_VAR22_BY_23.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SUB_VAR22_BY_23.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SUB_VAR22_BY_23.inc"
;@endif

;@include "../_helpers/INLINE_OR_VAR2B_WITH_4000.inc"
COPY_VAR22_TO_VAR07:
	mov [0x07], [0x22]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_VAR22_TO_VAR07.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_VAR22_TO_VAR07.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_VAR22_TO_VAR07.inc"
;@endif

;@include "../_helpers/ADD_VAR2C_TO_VAR22.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_ADD_VAR2C_TO_VAR22.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_ADD_VAR2C_TO_VAR22.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_ADD_VAR2C_TO_VAR22.inc"
;@endif

;@include "../_helpers/COPY_VAR27_TO_VAR07.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_VAR27_TO_VAR07.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_VAR27_TO_VAR07.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_VAR27_TO_VAR07.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN505_AT_X21_Y27:
	video type=1, offset=CINEMATIC_505, x=[0x21], y=[0x27], zoom=0x40
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN505_AT_X21_Y27.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN505_AT_X21_Y27.inc"
;@endif

;@include "../_helpers/SET_VAR13_TO_FFFF.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR13_TO_FFFF.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR13_TO_FFFF.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR13_TO_FFFF.inc"
;@endif

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


