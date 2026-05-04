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
	video type=1, offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40	;@raw=0x54,0x61,0x57,0xE6,0xE7
	video type=1, offset=CINEMATIC_314, x=[0xe6], y=[0xe7], zoom=0x40	;@raw=0x54,0x61,0xA5,0xE6,0xE7
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_311_TO_313_2F_AT_6BB0E3FE:
	video type=1, offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40	;@raw=0x54,0x61,0x57,0xE6,0xE7
	add [0xE6], 0x0001
	video type=1, offset=CINEMATIC_313, x=[0xe6], y=[0xe7], zoom=0x40	;@raw=0x54,0x61,0xAB,0xE6,0xE7
	sub [0xE6], 0x0001
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_311_TO_312_2F_AT_1550824C:
	video type=1, offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40	;@raw=0x54,0x61,0x57,0xE6,0xE7
	add [0xE6], 0x0002
	video type=1, offset=CINEMATIC_312, x=[0xe6], y=[0xe7], zoom=0x40	;@raw=0x54,0x61,0xB1,0xE6,0xE7
	sub [0xE6], 0x0002
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_311_TO_312_2F_AT_26843400:
	video type=1, offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40	;@raw=0x54,0x61,0x57,0xE6,0xE7
	add [0xE6], 0x0003
	video type=1, offset=CINEMATIC_312, x=[0xe6], y=[0xe7], zoom=0x40	;@raw=0x54,0x61,0xB1,0xE6,0xE7
	sub [0xE6], 0x0003
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_311_TO_312_2F_AT_2A88A18A:
	video type=1, offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40	;@raw=0x54,0x61,0x57,0xE6,0xE7
	add [0xE6], 0x0004
	video type=1, offset=CINEMATIC_312, x=[0xe6], y=[0xe7], zoom=0x40	;@raw=0x54,0x61,0xB1,0xE6,0xE7
	sub [0xE6], 0x0004
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_311_TO_312_2F_AT_76F1E2F4:
	video type=1, offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40	;@raw=0x54,0x61,0x57,0xE6,0xE7
	add [0xE6], 0x0006
	video type=1, offset=CINEMATIC_312, x=[0xe6], y=[0xe7], zoom=0x40	;@raw=0x54,0x61,0xB1,0xE6,0xE7
	sub [0xE6], 0x0006
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_311_TO_312_2F_AT_A6494EF7:
	video type=1, offset=CINEMATIC_311, x=[0xe6], y=[0xe7], zoom=0x40	;@raw=0x54,0x61,0x57,0xE6,0xE7
	add [0xE6], 0x0008
	video type=1, offset=CINEMATIC_312, x=[0xe6], y=[0xe7], zoom=0x40	;@raw=0x54,0x61,0xB1,0xE6,0xE7
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
	video type=1, offset=CINEMATIC_315, x=[0xf8], y=187, zoom=0x40	;@raw=0x58,0x53,0xCD,0xF8,0xBB
	add [0xF8], 0x0055
	video type=1, offset=CINEMATIC_315, x=[0xf8], y=186, zoom=0x40	;@raw=0x58,0x53,0xCD,0xF8,0xBA
	add [0xF8], 0x002C
	video type=1, offset=CINEMATIC_315, x=[0xf8], y=186, zoom=0x40	;@raw=0x58,0x53,0xCD,0xF8,0xBA
	add [0xF8], 0x0003
	video type=1, offset=CINEMATIC_315, x=[0xf8], y=187, zoom=0x40	;@raw=0x58,0x53,0xCD,0xF8,0xBB
	add [0xF8], 0x0004
	video type=1, offset=CINEMATIC_315, x=[0xf8], y=93, zoom=0x40	;@raw=0x58,0x53,0xCD,0xF8,0x5D
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_316_TO_316_2F_AT_A17C45BF:
	add [0xF8], 0x0038
	video type=1, offset=CINEMATIC_316, x=[0xf8], y=186, zoom=0x40	;@raw=0x58,0x53,0xD3,0xF8,0xBA
	add [0xF8], 0x0029
	video type=1, offset=CINEMATIC_316, x=[0xf8], y=186, zoom=0x40	;@raw=0x58,0x53,0xD3,0xF8,0xBA
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
	video type=1, offset=CINEMATIC_319, x=53, y=141	;@raw=0xD3,0xC3,0x35,0x8D
	video type=1, offset=CINEMATIC_319, x=153, y=141	;@raw=0xD3,0xC3,0x99,0x8D
	video type=1, offset=CINEMATIC_319, x=208, y=141	;@raw=0xD3,0xC3,0xD0,0x8D
	video type=1, offset=CINEMATIC_319, x=302, y=141, zoom=0x40	;@raw=0x78,0x53,0xC3,0x2E,0x8D
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_319_TO_319_4F_AT_9E666694.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_319_TO_319_4F_AT_9E666694.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_318_TO_318_2F_AT_93A8CE70:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_318, x=225, y=50	;@raw=0xD3,0xBE,0xE1,0x32
	video type=1, offset=CINEMATIC_318, x=278, y=50, zoom=0x40	;@raw=0x78,0x53,0xBE,0x16,0x32
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

KILL_CHANNEL_LANDING:
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
	video type=1, offset=CINEMATIC_154, x=160, y=[0x19], zoom=0x40	;@raw=0x64,0x42,0xA5,0xA0,0x19
	play id=0x0058, freq=0x14, vol=0x20, channel=0x01
	break
	video type=1, offset=CINEMATIC_155, x=160, y=[0x19], zoom=0x40	;@raw=0x64,0x42,0xB1,0xA0,0x19
	break
	video type=1, offset=CINEMATIC_156, x=160, y=[0x19], zoom=0x40	;@raw=0x64,0x42,0xBD,0xA0,0x19
	killChannel
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_151_TO_153_3F_AT_40D20636:
	video type=1, offset=CINEMATIC_151, x=160, y=[0x19], zoom=0x40	;@raw=0x64,0x42,0xC9,0xA0,0x19
	play id=0x0058, freq=0x0F, vol=0x10, channel=0x00
	break
	video type=1, offset=CINEMATIC_152, x=160, y=[0x19], zoom=0x40	;@raw=0x64,0x42,0xD5,0xA0,0x19
	break
	video type=1, offset=CINEMATIC_153, x=160, y=[0x19], zoom=0x40	;@raw=0x64,0x42,0xE1,0xA0,0x19
	killChannel
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_149_TO_150_2F_AT_F63AB95D:
	video type=1, offset=CINEMATIC_149, x=160, y=[0x19], zoom=0x40	;@raw=0x64,0x42,0xED,0xA0,0x19
	play id=0x0058, freq=0x0C, vol=0x18, channel=0x01
	break
	video type=1, offset=CINEMATIC_150, x=160, y=[0x19], zoom=0x40	;@raw=0x64,0x42,0xF9,0xA0,0x19
	killChannel
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_132_TO_133_2F_AT_BB9185F0:
	video type=1, offset=CINEMATIC_132, x=160, y=[0x19], zoom=0x40	;@raw=0x64,0x43,0x05,0xA0,0x19
	play id=0x0058, freq=0x14, vol=0x1C, channel=0x00
	break
	video type=1, offset=CINEMATIC_133, x=160, y=[0x19], zoom=0x40	;@raw=0x64,0x43,0x11,0xA0,0x19
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
	video type=1, offset=CINEMATIC_280, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2C,0xD0,0x01,0x02
	sub [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_281, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2D,0x14,0x01,0x02
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
	video type=1, offset=CINEMATIC_284, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2D,0xAB,0x01,0x02
	break
	video type=1, offset=CINEMATIC_285, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2D,0xCB,0x01,0x02
	break
	video type=1, offset=CINEMATIC_286, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2D,0xCF,0x01,0x02
	break
	video type=1, offset=CINEMATIC_287, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2D,0xD3,0x01,0x02
	break
	video type=1, offset=CINEMATIC_288, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2D,0xD7,0x01,0x02
	break
	video type=1, offset=CINEMATIC_289, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2D,0xDB,0x01,0x02
	break
	video type=1, offset=CINEMATIC_290, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2D,0xDF,0x01,0x02
	break
	video type=1, offset=CINEMATIC_291, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2D,0xE3,0x01,0x02
	break
	video type=1, offset=CINEMATIC_292, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2D,0xE7,0x01,0x02
	break
	video type=1, offset=CINEMATIC_293, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2D,0xEB,0x01,0x02
	break
	video type=1, offset=CINEMATIC_294, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2D,0xEF,0x01,0x02
	break
	video type=1, offset=CINEMATIC_295, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2D,0xF3,0x01,0x02
	break
	video type=1, offset=CINEMATIC_296, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2E,0x01,0x01,0x02
	break
	video type=1, offset=CINEMATIC_297, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2E,0x05,0x01,0x02
	break
	video type=1, offset=CINEMATIC_296, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2E,0x01,0x01,0x02
	break
	video type=1, offset=CINEMATIC_296, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2E,0x01,0x01,0x02
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_284_BLOCK_95B.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_284_BLOCK_95B.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_146_TO_147_4F_AT_8AA18039:
	video type=1, offset=CINEMATIC_146, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2B,0xFC,0x01,0x02
	break
	video type=1, offset=CINEMATIC_147, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2C,0x3A,0x01,0x02
	break
	video type=1, offset=CINEMATIC_148, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2C,0xB2,0x01,0x02
	break
	video type=1, offset=CINEMATIC_147, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2C,0x3A,0x01,0x02
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_137_138_BLOCK:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_137, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x3C,0xB2,0x01,0x02
	selectVideoPage 0xFF
	play id=0x005A, freq=0x14, vol=0x40, channel=0x00
	break
	video type=1, offset=CINEMATIC_138, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x3C,0x4C,0x01,0x02
	break
	video type=1, offset=CINEMATIC_139, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x3C,0xBC,0x01,0x02
	break
	video type=1, offset=CINEMATIC_140, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x3D,0x02,0x01,0x02
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_141, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x3D,0x3E,0x01,0x02
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_142, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x3D,0x52,0x01,0x02
	break
	video type=1, offset=CINEMATIC_143, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x3D,0x70,0x01,0x02
	break
	video type=1, offset=CINEMATIC_144, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x3D,0x9A,0x01,0x02
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_145, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x3D,0xBA,0x01,0x02
	selectVideoPage 0xFF
	killChannel
	video type=1, offset=CINEMATIC_146, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2B,0xFC,0x01,0x02
	break
	video type=1, offset=CINEMATIC_147, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x2C,0x3A,0x01,0x02
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
	video type=1, offset=CINEMATIC_393, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x53,0xE9,0x07,0x08
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
	video type=1, offset=CINEMATIC_406, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x51,0xC0,0x07,0x08
	break
	video type=1, offset=CINEMATIC_407, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x51,0xE0,0x07,0x08
	break
	video type=1, offset=CINEMATIC_408, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x51,0xFE,0x07,0x08
	break
	video type=1, offset=CINEMATIC_409, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x52,0x10,0x07,0x08
	break
	video type=1, offset=CINEMATIC_409, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x52,0x10,0x07,0x08
	break
	video type=1, offset=CINEMATIC_408, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x51,0xFE,0x07,0x08
	break
	video type=1, offset=CINEMATIC_409, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x52,0x10,0x07,0x08
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_410, x=160, y=100	;@raw=0xE0,0x07,0xA0,0x64
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_411, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x52,0x22,0x07,0x08
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
	video type=1, offset=CINEMATIC_569, x=160, y=100	;@raw=0xCC,0x81,0xA0,0x64
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_570, x=228, y=175	;@raw=0xAA,0x0A,0xE4,0xAF
	break
	video type=1, offset=CINEMATIC_571, x=232, y=175	;@raw=0xAA,0xB1,0xE8,0xAF
	video type=1, offset=CINEMATIC_572, x=160, y=100	;@raw=0xAA,0xA7,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_573, x=245, y=175	;@raw=0xAA,0xF9,0xF5,0xAF
	video type=1, offset=CINEMATIC_572, x=160, y=100	;@raw=0xAA,0xA7,0xA0,0x64
	killChannel
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_570_574_BLOCK:
	mov [0x57], 0x0002
	video type=1, offset=CINEMATIC_574, x=239, y=175	;@raw=0xAA,0x72,0xEF,0xAF
	video type=1, offset=CINEMATIC_572, x=160, y=100	;@raw=0xAA,0xA7,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_570, x=230, y=175	;@raw=0xAA,0x0A,0xE6,0xAF
	video type=1, offset=CINEMATIC_574, x=230, y=175	;@raw=0xAA,0x72,0xE6,0xAF
	video type=1, offset=CINEMATIC_572, x=160, y=100	;@raw=0xAA,0xA7,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_570, x=228, y=175	;@raw=0xAA,0x0A,0xE4,0xAF
	break
	video type=1, offset=CINEMATIC_575, x=227, y=175	;@raw=0xAA,0x52,0xE3,0xAF
	break
	video type=1, offset=CINEMATIC_575, x=226, y=175	;@raw=0xAA,0x52,0xE2,0xAF
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_575, x=226, y=175	;@raw=0xAA,0x52,0xE2,0xAF
	selectVideoPage 0xFF
	killChannel
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_576_578_BLOCK:
	video type=1, offset=CINEMATIC_576, x=215, y=131	;@raw=0xAB,0x26,0xD7,0x83
	break
	video type=1, offset=CINEMATIC_577, x=227, y=141	;@raw=0xAB,0x38,0xE3,0x8D
	break
	mov [0x31], 0x0000
	video type=1, offset=CINEMATIC_578, x=231, y=158	;@raw=0xAB,0x4C,0xE7,0x9E
	break
	video type=1, offset=CINEMATIC_579, x=239, y=175	;@raw=0xAB,0x62,0xEF,0xAF
	break
	video type=1, offset=CINEMATIC_578, x=243, y=174	;@raw=0xAB,0x4C,0xF3,0xAE
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_274, x=245, y=175	;@raw=0xAB,0x80,0xF5,0xAF
	mov [0x31], 0x0000
	break
	video type=1, offset=CINEMATIC_580, x=247, y=175	;@raw=0xAB,0x74,0xF7,0xAF
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_274, x=249, y=175	;@raw=0xAB,0x80,0xF9,0xAF
	break
	video type=1, offset=CINEMATIC_274, x=250, y=175	;@raw=0xAB,0x80,0xFA,0xAF
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_274, x=251, y=175	;@raw=0xAB,0x80,0xFB,0xAF
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
	video type=1, offset=CINEMATIC_505, x=[0x21], y=[0x27], zoom=0x40	;@raw=0x54,0x26,0xAF,0x21,0x27
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
	video type=1, offset=CINEMATIC_486, x=[0x21], y=[0x27], zoom=0x40	;@raw=0x54,0x39,0x9F,0x21,0x27
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_486.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_486.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_483:
	video type=1, offset=CINEMATIC_483, x=[0x21], y=[0x27], zoom=0x40	;@raw=0x54,0x39,0x73,0x21,0x27
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_483.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_483.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN473_AT_X21_Y27_ZOOM_40:
	video type=1, offset=CINEMATIC_473, x=[0x21], y=[0x27], zoom=0x40	;@raw=0x54,0x3B,0x5B,0x21,0x27
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
	video type=1, offset=CINEMATIC_502, x=[0x21], y=[0x27], zoom=0x40	;@raw=0x54,0x38,0xA5,0x21,0x27
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_502.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_502.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_499:
	video type=1, offset=CINEMATIC_499, x=[0x21], y=[0x27], zoom=0x40	;@raw=0x54,0x38,0x6D,0x21,0x27
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_499.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_499.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN489_AT_X21_Y27_ZOOM_40:
	video type=1, offset=CINEMATIC_489, x=[0x21], y=[0x27], zoom=0x40	;@raw=0x54,0x5B,0x5D,0x21,0x27
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

DEDUP_CAVES_5B_003:
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
	video type=1, offset=CINEMATIC_085, x=132, y=39	;@raw=0xD0,0xD6,0x84,0x27
	video type=1, offset=CINEMATIC_085, x=297, y=39, zoom=0x40	;@raw=0x78,0x50,0xD6,0x29,0x27
	video type=1, offset=CINEMATIC_086, x=132, y=39	;@raw=0xD0,0xF8,0x84,0x27
	video type=1, offset=CINEMATIC_086, x=297, y=39, zoom=0x40	;@raw=0x78,0x50,0xF8,0x29,0x27
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
	video type=1, offset=CINEMATIC_305, x=160, y=100	;@raw=0xA6,0x89,0xA0,0x64
	video type=1, offset=CINEMATIC_306, x=160, y=100	;@raw=0xCC,0x98,0xA0,0x64
	video type=1, offset=CINEMATIC_307, x=160, y=100	;@raw=0xD2,0xEB,0xA0,0x64
	video type=1, offset=CINEMATIC_308, x=160, y=100	;@raw=0xCF,0x30,0xA0,0x64
	video type=1, offset=CINEMATIC_309, x=160, y=100	;@raw=0xD0,0x29,0xA0,0x64
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_305_TO_333_7F_AT_96C7E6A8:
	fill page=0x00, color=0x03
	video type=1, offset=CINEMATIC_305, x=160, y=100	;@raw=0xA6,0x89,0xA0,0x64
	video type=1, offset=CINEMATIC_328, x=160, y=100	;@raw=0xCC,0xF8,0xA0,0x64
	video type=1, offset=CINEMATIC_329, x=160, y=100	;@raw=0xCD,0xEC,0xA0,0x64
	video type=1, offset=CINEMATIC_330, x=160, y=100	;@raw=0xD3,0x2C,0xA0,0x64
	video type=1, offset=CINEMATIC_331, x=160, y=100	;@raw=0xD3,0x3E,0xA0,0x64
	video type=1, offset=CINEMATIC_332, x=160, y=100	;@raw=0xCD,0xFA,0xA0,0x64
	video type=1, offset=CINEMATIC_333, x=160, y=100	;@raw=0xE3,0x99,0xA0,0x64
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
	video type=1, offset=CINEMATIC_024, x=160, y=100	;@raw=0xC8,0x09,0xA0,0x64
	video type=1, offset=CINEMATIC_025, x=160, y=100	;@raw=0xC9,0xC0,0xA0,0x64
	video type=1, offset=CINEMATIC_026, x=160, y=100	;@raw=0xC9,0xB2,0xA0,0x64
	video type=1, offset=CINEMATIC_027, x=160, y=100	;@raw=0xC8,0x3B,0xA0,0x64
	video type=1, offset=CINEMATIC_028, x=160, y=100	;@raw=0xC8,0x9B,0xA0,0x64
	video type=1, offset=CINEMATIC_029, x=160, y=400, zoom=0x40	;@raw=0x60,0x49,0x24,0xA0,0x01,0x90
	video type=1, offset=CINEMATIC_030, x=160, y=100	;@raw=0xA5,0x57,0xA0,0x64
	video type=1, offset=CINEMATIC_031, x=160, y=100	;@raw=0xAB,0xEC,0xA0,0x64
	video type=1, offset=CINEMATIC_032, x=160, y=100	;@raw=0xA6,0x50,0xA0,0x64
	video type=1, offset=CINEMATIC_033, x=160, y=100	;@raw=0xCA,0x0A,0xA0,0x64
	video type=1, offset=CINEMATIC_034, x=160, y=100	;@raw=0xC4,0x77,0xA0,0x64
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_FILL_AND_DRAW_CIN_24_28.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_FILL_AND_DRAW_CIN_24_28.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_624_TO_628_5F_AT_499AFE0A:
	video type=1, offset=CINEMATIC_624, x=160, y=100	;@raw=0xA8,0xA6,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_625, x=160, y=100	;@raw=0xA8,0x95,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_626, x=160, y=100	;@raw=0xA8,0x86,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_627, x=160, y=100	;@raw=0xA8,0x6D,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_628, x=160, y=100	;@raw=0xA8,0x5A,0xA0,0x64
	killChannel
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_628_TO_625_4F_AT_2F47D6D0:
	video type=1, offset=CINEMATIC_628, x=160, y=100	;@raw=0xA8,0x5A,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_627, x=160, y=100	;@raw=0xA8,0x6D,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_626, x=160, y=100	;@raw=0xA8,0x86,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_625, x=160, y=100	;@raw=0xA8,0x95,0xA0,0x64
	break
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_628_TO_625_4F_AT_2F47D6D0.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_628_TO_625_4F_AT_2F47D6D0.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_229_TO_632_2F_AT_1C4A817A:
	video type=1, offset=CINEMATIC_229, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x68,0x8A,0x07,0x08
	video type=1, offset=CINEMATIC_632, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x16,0x26,0x07,0x08
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_229_TO_632_2F_AT_1C4A817A.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_229_TO_632_2F_AT_1C4A817A.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_683_TO_685_3F_AT_1EB7324B:
	setPalette 0x0B	;@raw=0x0B,0x0B,0xFF
	selectVideoPage 0x00
	fill page=0x00, color=0x04
	video type=1, offset=CINEMATIC_683, x=160, y=100	;@raw=0x97,0x51,0xA0,0x64
	video type=1, offset=CINEMATIC_684, x=160, y=100	;@raw=0x99,0x60,0xA0,0x64
	video type=1, offset=CINEMATIC_685, x=160, y=100	;@raw=0x9B,0xC1,0xA0,0x64
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
	video type=1, offset=CINEMATIC_657, x=[0x1a], y=[0x1b], zoom=0x40	;@raw=0x54,0x1D,0xCF,0x1A,0x1B
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN657_AT_X1A_Y1B.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN657_AT_X1A_Y1B.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
INLINE_DRAW_CIN_659_AT_160_100:
	video type=1, offset=CINEMATIC_659, x=160, y=100	;@raw=0x9D,0x33,0xA0,0x64
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
	setPalette 0x07	;@raw=0x0B,0x07,0xFF
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
	video type=1, offset=CINEMATIC_236, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x17,0x35,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_237:
	video type=1, offset=CINEMATIC_237, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x5F,0xB2,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_238:
	video type=1, offset=CINEMATIC_238, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x62,0xE9,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_239:
	video type=1, offset=CINEMATIC_239, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x62,0xF6,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_235:
	video type=1, offset=CINEMATIC_235, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x21,0x58,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_234:
	video type=1, offset=CINEMATIC_234, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x68,0x56,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_233:
	video type=1, offset=CINEMATIC_233, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x21,0x76,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_232:
	video type=1, offset=CINEMATIC_232, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x68,0x74,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_231:
	video type=1, offset=CINEMATIC_231, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x21,0x82,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_230:
	video type=1, offset=CINEMATIC_230, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x21,0x9C,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_229:
	video type=1, offset=CINEMATIC_229, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x68,0x8A,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_228:
	video type=1, offset=CINEMATIC_228, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x29,0x8F,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_225:
	video type=1, offset=CINEMATIC_225, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x5F,0x9B,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_226:
	video type=1, offset=CINEMATIC_226, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x5F,0xC6,0x07,0x08
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_226.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_226.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_352:
	video type=1, offset=CINEMATIC_352, x=[0xf5], y=[0x08], zoom=0x40	;@raw=0x54,0x62,0x3B,0xF5,0x08
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
	video type=1, offset=CINEMATIC_169, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x62,0x20,0x07,0x08
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
	video type=1, offset=CINEMATIC_240, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x62,0x7D,0x07,0x08
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_240.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_240.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_241:
	video type=1, offset=CINEMATIC_241, x=[0xf5], y=[0x08], zoom=0x40	;@raw=0x54,0x62,0x6F,0xF5,0x08
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
	video type=0, offset=COMMON_VIDEO_228, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x16,0xAB,0x07,0x08
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_228_021.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_228_021.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_220_008:
	video type=0, offset=COMMON_VIDEO_220, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x16,0xAF,0x07,0x08
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_220_009.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_220_009.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_216_027:
	video type=0, offset=COMMON_VIDEO_216, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x16,0xB3,0x07,0x08
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
INLINE_DRAW_CV_272_003:
	video type=0, offset=COMMON_VIDEO_272, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x18,0xF6,0x07,0x08
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_272_004.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_272_004.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_272_003:
	video type=0, offset=COMMON_VIDEO_272, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x18,0xF6,0x07,0x08
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_272_005.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_272_005.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_269_024:
	video type=0, offset=COMMON_VIDEO_269, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x18,0xFB,0x07,0x08
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_269_025.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_269_025.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_269_024:
	video type=0, offset=COMMON_VIDEO_269, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x18,0xFB,0x07,0x08
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_269_026.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_269_026.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_266_005:
	video type=0, offset=COMMON_VIDEO_266, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x19,0x00,0x07,0x08
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


DEDUP_CAVES_5B_007:
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
	video type=0, offset=COMMON_VIDEO_255, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x11,0x09,0x07,0x08
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
	video type=0, offset=COMMON_VIDEO_252, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x11,0x00,0x07,0x08
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_DRAW_CV_252_019.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_DRAW_CV_252_019.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/DRAW_CV259_AT_X07_Y08.inc"
;@endif


DEDUP_CAVES_5B_007:
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


DEDUP_CAVES_5B_007:
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
	video type=0, offset=COMMON_VIDEO_243, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x57,0x30,0x84,0x07,0x08
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
	video type=1, offset=CINEMATIC_164, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x0B,0xFD,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_165:
	video type=1, offset=CINEMATIC_165, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x5B,0x88,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_166:
	video type=1, offset=CINEMATIC_166, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x5B,0x9C,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_167:
	video type=1, offset=CINEMATIC_167, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x5B,0xB0,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_163:
	video type=1, offset=CINEMATIC_163, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x20,0xEE,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_162:
	video type=1, offset=CINEMATIC_162, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x21,0x0C,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_161:
	video type=1, offset=CINEMATIC_161, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x21,0x18,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_160:
	video type=1, offset=CINEMATIC_160, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x21,0x38,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_159:
	video type=1, offset=CINEMATIC_159, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x5F,0x5F,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_158:
	video type=1, offset=CINEMATIC_158, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x45,0x3B,0x07,0x08
	ret
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_157:
	video type=1, offset=CINEMATIC_157, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x5F,0x76,0x07,0x08
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_157.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_157.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_168:
	video type=1, offset=CINEMATIC_168, x=[0x07], y=[0x08], zoom=0x40	;@raw=0x54,0x62,0x04,0x07,0x08
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_168.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_168.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_169:
	video type=1, offset=CINEMATIC_169, x=[0xf5], y=[0x08], zoom=0x40	;@raw=0x54,0x62,0x20,0xF5,0x08
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

KILL_CHANNEL_LANDING:
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
	video type=0, offset=COMMON_VIDEO_078, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x57,0x01,0x1A,0x01,0x02
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
	video type=0, offset=COMMON_VIDEO_070, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x57,0x04,0x0A,0x01,0x02
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
	video type=0, offset=COMMON_VIDEO_108, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x57,0x08,0xDC,0x01,0x02
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
	video type=0, offset=COMMON_VIDEO_098, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x57,0x0A,0x85,0x01,0x02
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
	video type=0, offset=COMMON_VIDEO_106, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x57,0x0A,0xD1,0x01,0x02
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
	video type=1, offset=CINEMATIC_075, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x0E,0xAA,0x03,0x04
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_076:
	video type=1, offset=CINEMATIC_076, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x07,0xAB,0x03,0x04
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_076.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_076.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN072_AT_X03_Y04:
	video type=1, offset=CINEMATIC_072, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x0E,0xEF,0x03,0x04
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_073:
	video type=1, offset=CINEMATIC_073, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x07,0xF1,0x03,0x04
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_073.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_073.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN069_AT_X03_Y04:
	video type=1, offset=CINEMATIC_069, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x0F,0x02,0x03,0x04
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_070:
	video type=1, offset=CINEMATIC_070, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x08,0x37,0x03,0x04
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_070.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_070.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN066_AT_X03_Y04:
	video type=1, offset=CINEMATIC_066, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x0F,0x35,0x03,0x04
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_067:
	video type=1, offset=CINEMATIC_067, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x08,0x7D,0x03,0x04
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_067.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_067.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN063_AT_X03_Y04:
	video type=1, offset=CINEMATIC_063, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x0F,0x48,0x03,0x04
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_064:
	video type=1, offset=CINEMATIC_064, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x08,0xC3,0x03,0x04
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_064.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_064.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN060_AT_X03_Y04:
	video type=1, offset=CINEMATIC_060, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x0F,0x7B,0x03,0x04
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_061:
	video type=1, offset=CINEMATIC_061, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x09,0x09,0x03,0x04
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_061.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_061.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN057_AT_X03_Y04:
	video type=1, offset=CINEMATIC_057, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x0F,0x8E,0x03,0x04
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_058:
	video type=1, offset=CINEMATIC_058, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x09,0x4F,0x03,0x04
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_058.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_058.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN054_AT_X03_Y04:
	video type=1, offset=CINEMATIC_054, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x0F,0xA1,0x03,0x04
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN054_AT_X03_Y04.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN054_AT_X03_Y04.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN051_AT_X03_Y04:
	video type=1, offset=CINEMATIC_051, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x0F,0xEE,0x03,0x04
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_052:
	video type=1, offset=CINEMATIC_052, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x09,0xDB,0x03,0x04
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_052.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_052.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN048_AT_X03_Y04:
	video type=1, offset=CINEMATIC_048, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x10,0x01,0x03,0x04
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_049:
	video type=1, offset=CINEMATIC_049, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x0A,0x21,0x03,0x04
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_049.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_049.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN045_AT_X03_Y04:
	video type=1, offset=CINEMATIC_045, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x10,0x34,0x03,0x04
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_046:
	video type=1, offset=CINEMATIC_046, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x0A,0x5D,0x03,0x04
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_046.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_046.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN042_AT_X03_Y04:
	video type=1, offset=CINEMATIC_042, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x10,0x47,0x03,0x04
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_043:
	video type=1, offset=CINEMATIC_043, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x0A,0xA3,0x03,0x04
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_043.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_043.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN039_AT_X03_Y04:
	video type=1, offset=CINEMATIC_039, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x10,0x74,0x03,0x04
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_040:
	video type=1, offset=CINEMATIC_040, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x0A,0xE9,0x03,0x04
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_040.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_040.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN036_AT_X03_Y04:
	video type=1, offset=CINEMATIC_036, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x10,0x87,0x03,0x04
;@endif


;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_037:
	video type=1, offset=CINEMATIC_037, x=[0x03], y=[0x04], zoom=0x40	;@raw=0x54,0x0B,0x2F,0x03,0x04
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_037.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_037.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_540_543_WITH_SFX_57:
	video type=1, offset=CINEMATIC_540, x=[0x1a], y=[0x1b], zoom=0x40	;@raw=0x54,0x14,0x10,0x1A,0x1B
	video type=1, offset=CINEMATIC_541, x=[0x1a], y=[0x1b], zoom=0x40	;@raw=0x54,0x15,0x36,0x1A,0x1B
	break
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x02
	video type=1, offset=CINEMATIC_542, x=[0x1a], y=[0x1b], zoom=0x40	;@raw=0x54,0x14,0x38,0x1A,0x1B
	video type=1, offset=CINEMATIC_543, x=[0x1a], y=[0x1b], zoom=0x40	;@raw=0x54,0x15,0x28,0x1A,0x1B
	break
	video type=1, offset=CINEMATIC_544, x=[0x1a], y=[0x1b], zoom=0x40	;@raw=0x54,0x14,0x28,0x1A,0x1B
	video type=1, offset=CINEMATIC_545, x=[0x1a], y=[0x1b], zoom=0x40	;@raw=0x54,0x15,0x1A,0x1A,0x1B
	break
	video type=1, offset=CINEMATIC_546, x=[0x1a], y=[0x1b], zoom=0x40	;@raw=0x54,0x15,0x0C,0x1A,0x1B
	break
	video type=1, offset=CINEMATIC_547, x=[0x1a], y=[0x1b], zoom=0x40	;@raw=0x54,0x15,0x08,0x1A,0x1B
	break
	video type=1, offset=CINEMATIC_548, x=[0x1a], y=[0x1b], zoom=0x40	;@raw=0x54,0x15,0x04,0x1A,0x1B
	break
	video type=1, offset=CINEMATIC_547, x=[0x1a], y=[0x1b], zoom=0x40	;@raw=0x54,0x15,0x08,0x1A,0x1B
	break
	video type=1, offset=CINEMATIC_548, x=[0x1a], y=[0x1b], zoom=0x40	;@raw=0x54,0x15,0x04,0x1A,0x1B
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
	video type=1, offset=CINEMATIC_092, x=160, y=[0x21], zoom=0x40	;@raw=0x64,0x47,0x2B,0xA0,0x21
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
	video type=1, offset=CINEMATIC_090, x=160, y=100	;@raw=0xE4,0xB4,0xA0,0x64
	video type=1, offset=CINEMATIC_091, x=160, y=100	;@raw=0xE7,0xFE,0xA0,0x64
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_104, x=200, y=100	;@raw=0xE8,0x22,0xC8,0x64
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
	video type=1, offset=CINEMATIC_552, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x27,0xDD,0x01,0x02
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_552.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_552.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_550:
	video type=1, offset=CINEMATIC_550, x=[0x01], y=[0x02], zoom=0x40	;@raw=0x54,0x27,0xFF,0x01,0x02
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

