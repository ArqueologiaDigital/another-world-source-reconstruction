SET_VAR_E6_5_PAL_B:
	mov [0xE6], 0x0005
	setPalette 0x0B

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
	video offset=CINEMATIC_000, x=253, y=34, zoom=[0x0a]	;@enc=alt
	video offset=CINEMATIC_000, x=269, y=29, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_000, x=273, y=78, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_000, x=303, y=57, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_000, x=140, y=79, zoom=[0x08]	;@enc=alt
	video offset=CINEMATIC_000, x=214, y=85, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_000, x=66, y=79, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_000, x=111, y=52, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_000, x=95, y=103, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_000, x=153, y=89, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_000, x=132, y=107, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_000, x=4, y=85, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_000, x=65, y=115, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_000, x=293, y=139, zoom=0x40
	video offset=CINEMATIC_000, x=11, y=109, zoom=[0x1c]	;@enc=alt
	video offset=CINEMATIC_000, x=11, y=146
	video offset=CINEMATIC_001, x=31, y=187
	video offset=CINEMATIC_002, x=301, y=14, zoom=0x40
	video offset=CINEMATIC_001, x=294, y=188, zoom=0x40
	video offset=CINEMATIC_003, x=2, y=167
	video offset=CINEMATIC_002, x=92, y=30
	video offset=CINEMATIC_002, x=128, y=11
	video offset=CINEMATIC_002, x=166, y=10
	video offset=CINEMATIC_002, x=85, y=19
	video offset=CINEMATIC_002, x=48, y=12
	video offset=CINEMATIC_002, x=111, y=3
	video offset=CINEMATIC_002, x=13, y=11, zoom=[0x20]	;@enc=alt
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
	video offset=CINEMATIC_004, x=253, y=34, zoom=[0x0a]	;@enc=alt
	video offset=CINEMATIC_004, x=269, y=29, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_004, x=273, y=78, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_004, x=303, y=57, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_004, x=140, y=79, zoom=[0x08]	;@enc=alt
	video offset=CINEMATIC_004, x=214, y=85, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_004, x=66, y=79, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_004, x=111, y=52, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_004, x=95, y=103, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_004, x=153, y=89, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_004, x=132, y=107, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_004, x=4, y=85, zoom=[0x10]	;@enc=alt
	video offset=CINEMATIC_004, x=65, y=115, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_004, x=293, y=139, zoom=0x40
	video offset=CINEMATIC_004, x=11, y=109, zoom=[0x1c]	;@enc=alt
	video offset=CINEMATIC_004, x=11, y=146
	video offset=CINEMATIC_005, x=31, y=187
	video offset=CINEMATIC_006, x=301, y=14, zoom=0x40
	video offset=CINEMATIC_005, x=294, y=188, zoom=0x40
	video offset=CINEMATIC_007, x=2, y=167
	video offset=CINEMATIC_006, x=92, y=30
	video offset=CINEMATIC_006, x=128, y=11
	video offset=CINEMATIC_006, x=166, y=10
	video offset=CINEMATIC_006, x=85, y=19
	video offset=CINEMATIC_006, x=48, y=12
	video offset=CINEMATIC_006, x=111, y=3
	video offset=CINEMATIC_006, x=13, y=11, zoom=[0x20]	;@enc=alt
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
	video offset=CINEMATIC_006, x=126, y=25
	video offset=CINEMATIC_038, x=133, y=102, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_038, x=129, y=114, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_038, x=114, y=126, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_006, x=91, y=8, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_039, x=16, y=114
	video offset=CINEMATIC_039, x=74, y=177, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_040, x=78, y=166
	video offset=CINEMATIC_005, x=283, y=175, zoom=0x40
	video offset=CINEMATIC_005, x=294, y=183, zoom=0x40
	video offset=CINEMATIC_005, x=58, y=185
	video offset=CINEMATIC_005, x=5, y=170
	video offset=CINEMATIC_041, x=197, y=160, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_041, x=61, y=169
	video offset=CINEMATIC_041, x=300, y=28, zoom=0x40
	video offset=CINEMATIC_041, x=202, y=86, zoom=[0x30]	;@enc=alt
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

