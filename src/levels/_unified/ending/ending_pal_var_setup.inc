SET_VAR_E6_5_PAL_B:
	mov [0xE6], 0x0005
	setPalette 0x0B	;@raw=0x0B,0x0B,0xFF

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR_E6_5_PAL_B.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR_E6_5_PAL_B.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR_E6_5_PAL_B.inc"
;@endif

INIT_VARS_07_08_09:
	mov [0x07], 0x004C
	mov [0x08], 0x0097
	mov [0x09], 0x0003

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_07_08_09.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_07_08_09.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_07_08_09.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_STARS_PAGE0_CIN_000:
	selectVideoPage 0x00
	fill page=0x00, color=0x01
	video type=1, offset=CINEMATIC_000, x=253, y=34, zoom=[0x0a]	;@enc=alt
	video type=1, offset=CINEMATIC_000, x=269, y=29, zoom=[0x10]	;@enc=alt
	video type=1, offset=CINEMATIC_000, x=273, y=78, zoom=[0x10]	;@enc=alt
	video type=1, offset=CINEMATIC_000, x=303, y=57, zoom=[0x10]	;@enc=alt
	video type=1, offset=CINEMATIC_000, x=140, y=79, zoom=[0x08]	;@enc=alt
	video type=1, offset=CINEMATIC_000, x=214, y=85, zoom=[0x10]	;@enc=alt
	video type=1, offset=CINEMATIC_000, x=66, y=79, zoom=[0x10]	;@enc=alt
	video type=1, offset=CINEMATIC_000, x=111, y=52, zoom=[0x20]	;@enc=alt
	video type=1, offset=CINEMATIC_000, x=95, y=103, zoom=[0x10]	;@enc=alt
	video type=1, offset=CINEMATIC_000, x=153, y=89, zoom=[0x10]	;@enc=alt
	video type=1, offset=CINEMATIC_000, x=132, y=107, zoom=[0x10]	;@enc=alt
	video type=1, offset=CINEMATIC_000, x=4, y=85, zoom=[0x10]	;@enc=alt
	video type=1, offset=CINEMATIC_000, x=65, y=115, zoom=[0x20]	;@enc=alt
	video type=1, offset=CINEMATIC_000, x=293, y=139, zoom=0x40	;@raw=0x78,0x09,0x0E,0x25,0x8B
	video type=1, offset=CINEMATIC_000, x=11, y=109, zoom=[0x1c]	;@enc=alt
	video type=1, offset=CINEMATIC_000, x=11, y=146	;@raw=0x89,0x0E,0x0B,0x92
	video type=1, offset=CINEMATIC_001, x=31, y=187	;@raw=0x86,0xEE,0x1F,0xBB
	video type=1, offset=CINEMATIC_002, x=301, y=14, zoom=0x40	;@raw=0x78,0x08,0x3C,0x2D,0x0E
	video type=1, offset=CINEMATIC_001, x=294, y=188, zoom=0x40	;@raw=0x78,0x06,0xEE,0x26,0xBC
	video type=1, offset=CINEMATIC_003, x=2, y=167	;@raw=0x86,0xB2,0x02,0xA7
	video type=1, offset=CINEMATIC_002, x=92, y=30	;@raw=0x88,0x3C,0x5C,0x1E
	video type=1, offset=CINEMATIC_002, x=128, y=11	;@raw=0x88,0x3C,0x80,0x0B
	video type=1, offset=CINEMATIC_002, x=166, y=10	;@raw=0x88,0x3C,0xA6,0x0A
	video type=1, offset=CINEMATIC_002, x=85, y=19	;@raw=0x88,0x3C,0x55,0x13
	video type=1, offset=CINEMATIC_002, x=48, y=12	;@raw=0x88,0x3C,0x30,0x0C
	video type=1, offset=CINEMATIC_002, x=111, y=3	;@raw=0x88,0x3C,0x6F,0x03
	video type=1, offset=CINEMATIC_002, x=13, y=11, zoom=[0x20]	;@enc=alt
	selectVideoPage 0xFF
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_STARS_PAGE0_CIN_000.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_STARS_PAGE0_CIN_000.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_STARS_PAGE3_CIN_004:
	selectVideoPage 0x03
	fill page=0x03, color=0x01
	video type=1, offset=CINEMATIC_004, x=253, y=34, zoom=[0x0a]	;@enc=alt
	video type=1, offset=CINEMATIC_004, x=269, y=29, zoom=[0x10]	;@enc=alt
	video type=1, offset=CINEMATIC_004, x=273, y=78, zoom=[0x10]	;@enc=alt
	video type=1, offset=CINEMATIC_004, x=303, y=57, zoom=[0x10]	;@enc=alt
	video type=1, offset=CINEMATIC_004, x=140, y=79, zoom=[0x08]	;@enc=alt
	video type=1, offset=CINEMATIC_004, x=214, y=85, zoom=[0x10]	;@enc=alt
	video type=1, offset=CINEMATIC_004, x=66, y=79, zoom=[0x10]	;@enc=alt
	video type=1, offset=CINEMATIC_004, x=111, y=52, zoom=[0x20]	;@enc=alt
	video type=1, offset=CINEMATIC_004, x=95, y=103, zoom=[0x10]	;@enc=alt
	video type=1, offset=CINEMATIC_004, x=153, y=89, zoom=[0x10]	;@enc=alt
	video type=1, offset=CINEMATIC_004, x=132, y=107, zoom=[0x10]	;@enc=alt
	video type=1, offset=CINEMATIC_004, x=4, y=85, zoom=[0x10]	;@enc=alt
	video type=1, offset=CINEMATIC_004, x=65, y=115, zoom=[0x20]	;@enc=alt
	video type=1, offset=CINEMATIC_004, x=293, y=139, zoom=0x40	;@raw=0x78,0x17,0x68,0x25,0x8B
	video type=1, offset=CINEMATIC_004, x=11, y=109, zoom=[0x1c]	;@enc=alt
	video type=1, offset=CINEMATIC_004, x=11, y=146	;@raw=0x97,0x68,0x0B,0x92
	video type=1, offset=CINEMATIC_005, x=31, y=187	;@raw=0x92,0xD8,0x1F,0xBB
	video type=1, offset=CINEMATIC_006, x=301, y=14, zoom=0x40	;@raw=0x78,0x14,0x12,0x2D,0x0E
	video type=1, offset=CINEMATIC_005, x=294, y=188, zoom=0x40	;@raw=0x78,0x12,0xD8,0x26,0xBC
	video type=1, offset=CINEMATIC_007, x=2, y=167	;@raw=0x99,0xBE,0x02,0xA7
	video type=1, offset=CINEMATIC_006, x=92, y=30	;@raw=0x94,0x12,0x5C,0x1E
	video type=1, offset=CINEMATIC_006, x=128, y=11	;@raw=0x94,0x12,0x80,0x0B
	video type=1, offset=CINEMATIC_006, x=166, y=10	;@raw=0x94,0x12,0xA6,0x0A
	video type=1, offset=CINEMATIC_006, x=85, y=19	;@raw=0x94,0x12,0x55,0x13
	video type=1, offset=CINEMATIC_006, x=48, y=12	;@raw=0x94,0x12,0x30,0x0C
	video type=1, offset=CINEMATIC_006, x=111, y=3	;@raw=0x94,0x12,0x6F,0x03
	video type=1, offset=CINEMATIC_006, x=13, y=11, zoom=[0x20]	;@enc=alt
	selectVideoPage 0xFF
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_STARS_PAGE3_CIN_004.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_STARS_PAGE3_CIN_004.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_STARS_CIN_38_39_40_5_6:
	video type=1, offset=CINEMATIC_006, x=126, y=25	;@raw=0x94,0x12,0x7E,0x19
	video type=1, offset=CINEMATIC_038, x=133, y=102, zoom=[0x20]	;@enc=alt
	video type=1, offset=CINEMATIC_038, x=129, y=114, zoom=[0x20]	;@enc=alt
	video type=1, offset=CINEMATIC_038, x=114, y=126, zoom=[0x20]	;@enc=alt
	video type=1, offset=CINEMATIC_006, x=91, y=8, zoom=[0x20]	;@enc=alt
	video type=1, offset=CINEMATIC_039, x=16, y=114	;@raw=0x94,0x85,0x10,0x72
	video type=1, offset=CINEMATIC_039, x=74, y=177, zoom=[0x20]	;@enc=alt
	video type=1, offset=CINEMATIC_040, x=78, y=166	;@raw=0x93,0x3F,0x4E,0xA6
	video type=1, offset=CINEMATIC_005, x=283, y=175, zoom=0x40	;@raw=0x78,0x12,0xD8,0x1B,0xAF
	video type=1, offset=CINEMATIC_005, x=294, y=183, zoom=0x40	;@raw=0x78,0x12,0xD8,0x26,0xB7
	video type=1, offset=CINEMATIC_005, x=58, y=185	;@raw=0x92,0xD8,0x3A,0xB9
	video type=1, offset=CINEMATIC_005, x=5, y=170	;@raw=0x92,0xD8,0x05,0xAA
	video type=1, offset=CINEMATIC_041, x=197, y=160, zoom=[0x20]	;@enc=alt
	video type=1, offset=CINEMATIC_041, x=61, y=169	;@raw=0x94,0xE4,0x3D,0xA9
	video type=1, offset=CINEMATIC_041, x=300, y=28, zoom=0x40	;@raw=0x78,0x14,0xE4,0x2C,0x1C
	video type=1, offset=CINEMATIC_041, x=202, y=86, zoom=[0x30]	;@enc=alt
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_STARS_CIN_38_39_40_5_6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_STARS_CIN_38_39_40_5_6.inc"
;@endif

;@include "../_helpers/CLEAR_PAGES_1_2_AND_BLIT.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_CLEAR_PAGES_1_2_AND_BLIT.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_CLEAR_PAGES_1_2_AND_BLIT.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_CLEAR_PAGES_1_2_AND_BLIT.inc"
;@endif

