ENDING_SKY_SHOT_ENTRY:
	mov [0xE6], 0x0005
	setPalette 0x0B

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_SET_VAR_E6_5_PAL_B.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_SET_VAR_E6_5_PAL_B.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_SET_VAR_E6_5_PAL_B.inc"
.endif

ALIEN_ARRIVAL_POSITION_INIT:
	mov [0x07], 0x004C
	mov [0x08], 0x0097
	mov [0x09], 0x0003

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VARS_07_08_09.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_07_08_09.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_07_08_09.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
ENDING_CLOUD_SKY_BACKDROP_PAGE_0:
	selectVideoPage 0x00
	fill page=0x00, color=0x01
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=253, y=34, zoom=0x0a
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=269, y=29, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=273, y=78, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=303, y=57, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=140, y=79, zoom=0x08
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=214, y=85, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=66, y=79, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=111, y=52, zoom=0x20
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=95, y=103, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=153, y=89, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=132, y=107, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=4, y=85, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=65, y=115, zoom=0x20
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=293, y=139
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=11, y=109, zoom=0x1c
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F0, x=11, y=146
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F1, x=31, y=187
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F2, x=301, y=14
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F1, x=294, y=188
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F3, x=2, y=167
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F2, x=92, y=30
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F2, x=128, y=11
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F2, x=166, y=10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F2, x=85, y=19
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F2, x=48, y=12
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F2, x=111, y=3
	video offset=CINEMATIC_ENDING_CLOUD_SKY_F2, x=13, y=11, zoom=0x20
	selectVideoPage 0xFF
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
ENDING_DRAW_STARS_PAGE0_CIN_000_L0:
	db 0x11
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
ENDING_CLOUD_SKY_BACKDROP_PAGE_3:
	selectVideoPage 0x03
	fill page=0x03, color=0x01
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=253, y=34, zoom=0x0a
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=269, y=29, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=273, y=78, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=303, y=57, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=140, y=79, zoom=0x08
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=214, y=85, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=66, y=79, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=111, y=52, zoom=0x20
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=95, y=103, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=153, y=89, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=132, y=107, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=4, y=85, zoom=0x10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=65, y=115, zoom=0x20
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=293, y=139
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=11, y=109, zoom=0x1c
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F0, x=11, y=146
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F1, x=31, y=187
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=301, y=14
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F1, x=294, y=188
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F3, x=2, y=167
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=92, y=30
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=128, y=11
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=166, y=10
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=85, y=19
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=48, y=12
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=111, y=3
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=13, y=11, zoom=0x20
	selectVideoPage 0xFF
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
ENDING_DRAW_STARS_PAGE3_CIN_004_L0:
	db 0x11
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_STARS_CIN_38_39_40_5_6:
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=126, y=25
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F4, x=133, y=102, zoom=0x20
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F4, x=129, y=114, zoom=0x20
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F4, x=114, y=126, zoom=0x20
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F2, x=91, y=8, zoom=0x20
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F5, x=16, y=114
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F5, x=74, y=177, zoom=0x20
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F6, x=78, y=166
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F1, x=283, y=175
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F1, x=294, y=183
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F1, x=58, y=185
	video offset=CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F1, x=5, y=170
	video offset=CINEMATIC_ENDING_CLOUD_BANK, x=197, y=160, zoom=0x20
	video offset=CINEMATIC_ENDING_CLOUD_BANK, x=61, y=169
	video offset=CINEMATIC_ENDING_CLOUD_BANK, x=300, y=28
	video offset=CINEMATIC_ENDING_CLOUD_BANK, x=202, y=86, zoom=0x30
	ret


.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_STARS_CIN_38_39_40_5_6.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_STARS_CIN_38_39_40_5_6.inc"
.endif

.include "../_helpers/CLEAR_PAGES_1_2_AND_BLIT.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
ENDING_CLEAR_PAGES_1_2_AND_BLIT_L0:
	db 0x11, 0x11, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
.endif

