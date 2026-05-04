INIT_VARS_A_B_PAL_1:
	mov [0x0A], 0x0082
	mov [0x0B], 0x0032
	setPalette 0x01

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_A_B_PAL_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_A_B_PAL_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_A_B_PAL_1.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_6_27_28_AND_RET:
	video type=1, offset=CINEMATIC_006, x=160, y=100
	video type=1, offset=CINEMATIC_027, x=160, y=100
	video type=1, offset=CINEMATIC_028, x=160, y=100
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_6_27_28_AND_RET.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_6_27_28_AND_RET.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_6_AND_RET:
	video type=1, offset=CINEMATIC_006, x=160, y=100
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_6_AND_RET.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_6_AND_RET.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_BG_DOTS_CIN_001_004:
	video type=1, offset=CINEMATIC_004, x=299, y=37, zoom=0x40
	video type=1, offset=CINEMATIC_004, x=289, y=23, zoom=0x40
	video type=1, offset=CINEMATIC_001, x=205, y=21
	video type=1, offset=CINEMATIC_001, x=187, y=27
	video type=1, offset=CINEMATIC_001, x=247, y=25
	video type=1, offset=CINEMATIC_001, x=167, y=20
	video type=1, offset=CINEMATIC_001, x=142, y=21
	video type=1, offset=CINEMATIC_001, x=228, y=22
	video type=1, offset=CINEMATIC_001, x=279, y=21, zoom=0x40
	video type=1, offset=CINEMATIC_001, x=310, y=20, zoom=0x40
	video type=1, offset=CINEMATIC_002, x=186, y=24
	video type=1, offset=CINEMATIC_002, x=207, y=21
	video type=1, offset=CINEMATIC_002, x=161, y=22
	video type=1, offset=CINEMATIC_002, x=240, y=21
	video type=1, offset=CINEMATIC_002, x=303, y=18, zoom=0x40
	video type=1, offset=CINEMATIC_002, x=140, y=20
	video type=1, offset=CINEMATIC_002, x=242, y=22
	video type=1, offset=CINEMATIC_002, x=224, y=21
	video type=1, offset=CINEMATIC_002, x=287, y=21, zoom=0x40
	video type=1, offset=CINEMATIC_002, x=259, y=27, zoom=0x40
	video type=1, offset=CINEMATIC_002, x=140, y=20
	video type=1, offset=CINEMATIC_003, x=164, y=23
	video type=1, offset=CINEMATIC_003, x=198, y=21
	video type=1, offset=CINEMATIC_003, x=216, y=25
	video type=1, offset=CINEMATIC_003, x=147, y=24
	video type=1, offset=CINEMATIC_003, x=302, y=17, zoom=0x40
	video type=1, offset=CINEMATIC_003, x=273, y=21, zoom=0x40
	video type=1, offset=CINEMATIC_003, x=255, y=21
	video type=1, offset=CINEMATIC_003, x=222, y=18
	video type=1, offset=CINEMATIC_003, x=134, y=21
	video type=1, offset=CINEMATIC_003, x=114, y=23
	video type=1, offset=CINEMATIC_003, x=190, y=20
	video type=1, offset=CINEMATIC_003, x=245, y=23
	video type=1, offset=CINEMATIC_003, x=294, y=19, zoom=0x40
	video type=1, offset=CINEMATIC_005, x=211, y=26
	video type=1, offset=CINEMATIC_005, x=196, y=19
	video type=1, offset=CINEMATIC_005, x=156, y=17
	video type=1, offset=CINEMATIC_005, x=141, y=28
	video type=1, offset=CINEMATIC_005, x=124, y=23
	video type=1, offset=CINEMATIC_005, x=182, y=13
	video type=1, offset=CINEMATIC_005, x=221, y=17
	video type=1, offset=CINEMATIC_005, x=257, y=18, zoom=0x40
	video type=1, offset=CINEMATIC_005, x=242, y=18
	video type=1, offset=CINEMATIC_005, x=295, y=21, zoom=0x40
	video type=1, offset=CINEMATIC_005, x=303, y=19, zoom=0x40
	video type=1, offset=CINEMATIC_005, x=280, y=17, zoom=0x40
	video type=1, offset=CINEMATIC_005, x=87, y=20
	video type=1, offset=CINEMATIC_005, x=107, y=22
	video type=1, offset=CINEMATIC_005, x=35, y=17
	video type=1, offset=CINEMATIC_005, x=61, y=18
	video type=1, offset=CINEMATIC_005, x=0, y=21
	video type=1, offset=CINEMATIC_005, x=10, y=21
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_BG_DOTS_CIN_001_004.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_BG_DOTS_CIN_001_004.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_BG_DOTS_CIN_007_008:
	video type=1, offset=CINEMATIC_007, x=299, y=37, zoom=0x40
	video type=1, offset=CINEMATIC_007, x=289, y=23, zoom=0x40
	video type=1, offset=CINEMATIC_008, x=205, y=21
	video type=1, offset=CINEMATIC_008, x=187, y=27
	video type=1, offset=CINEMATIC_008, x=247, y=25
	video type=1, offset=CINEMATIC_008, x=167, y=20
	video type=1, offset=CINEMATIC_008, x=142, y=21
	video type=1, offset=CINEMATIC_008, x=228, y=22
	video type=1, offset=CINEMATIC_008, x=279, y=21, zoom=0x40
	video type=1, offset=CINEMATIC_008, x=310, y=20, zoom=0x40
	video type=1, offset=CINEMATIC_009, x=186, y=24
	video type=1, offset=CINEMATIC_009, x=207, y=21
	video type=1, offset=CINEMATIC_009, x=161, y=22
	video type=1, offset=CINEMATIC_009, x=240, y=21
	video type=1, offset=CINEMATIC_009, x=303, y=18, zoom=0x40
	video type=1, offset=CINEMATIC_009, x=140, y=20
	video type=1, offset=CINEMATIC_009, x=242, y=22
	video type=1, offset=CINEMATIC_009, x=224, y=21
	video type=1, offset=CINEMATIC_009, x=287, y=21, zoom=0x40
	video type=1, offset=CINEMATIC_009, x=259, y=27, zoom=0x40
	video type=1, offset=CINEMATIC_009, x=140, y=20
	video type=1, offset=CINEMATIC_010, x=164, y=23
	video type=1, offset=CINEMATIC_010, x=198, y=21
	video type=1, offset=CINEMATIC_010, x=216, y=25
	video type=1, offset=CINEMATIC_010, x=147, y=24
	video type=1, offset=CINEMATIC_010, x=302, y=17, zoom=0x40
	video type=1, offset=CINEMATIC_010, x=273, y=21, zoom=0x40
	video type=1, offset=CINEMATIC_010, x=255, y=21
	video type=1, offset=CINEMATIC_010, x=222, y=18
	video type=1, offset=CINEMATIC_010, x=134, y=21
	video type=1, offset=CINEMATIC_010, x=114, y=23
	video type=1, offset=CINEMATIC_010, x=190, y=20
	video type=1, offset=CINEMATIC_010, x=245, y=23
	video type=1, offset=CINEMATIC_010, x=294, y=19, zoom=0x40
	video type=1, offset=CINEMATIC_011, x=211, y=26
	video type=1, offset=CINEMATIC_011, x=196, y=19
	video type=1, offset=CINEMATIC_011, x=156, y=17
	video type=1, offset=CINEMATIC_011, x=141, y=28
	video type=1, offset=CINEMATIC_011, x=124, y=23
	video type=1, offset=CINEMATIC_011, x=182, y=13
	video type=1, offset=CINEMATIC_011, x=221, y=17
	video type=1, offset=CINEMATIC_011, x=257, y=18, zoom=0x40
	video type=1, offset=CINEMATIC_011, x=242, y=18
	video type=1, offset=CINEMATIC_011, x=295, y=21, zoom=0x40
	video type=1, offset=CINEMATIC_011, x=303, y=19, zoom=0x40
	video type=1, offset=CINEMATIC_011, x=280, y=17, zoom=0x40
	video type=1, offset=CINEMATIC_011, x=87, y=20
	video type=1, offset=CINEMATIC_011, x=107, y=22
	video type=1, offset=CINEMATIC_011, x=35, y=17
	video type=1, offset=CINEMATIC_011, x=61, y=18
	video type=1, offset=CINEMATIC_011, x=0, y=21
	video type=1, offset=CINEMATIC_011, x=10, y=21
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_BG_DOTS_CIN_007_008.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_BG_DOTS_CIN_007_008.inc"
;@endif

;@include "../_helpers/CLEAR_PAGES_1_2_AND_BLIT.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_CLEAR_PAGES_1_2_AND_BLIT.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_CLEAR_PAGES_1_2_AND_BLIT.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_CLEAR_PAGES_1_2_AND_BLIT.inc"
;@endif

