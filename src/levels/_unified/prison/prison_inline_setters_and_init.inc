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

