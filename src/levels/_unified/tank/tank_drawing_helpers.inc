INIT_VARS_A_B_PAL_1:
	mov [0x0A], 0x0082
	mov [0x0B], 0x0032
	setPalette 0x01	;@raw=0x0B,0x01,0xFF

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_A_B_PAL_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_A_B_PAL_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_A_B_PAL_1.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_6_27_28_AND_RET:
	video type=1, offset=CINEMATIC_006, x=160, y=100	;@raw=0x89,0x0A,0xA0,0x64
	video type=1, offset=CINEMATIC_027, x=160, y=100	;@raw=0x89,0x20,0xA0,0x64
	video type=1, offset=CINEMATIC_028, x=160, y=100	;@raw=0xAB,0xF9,0xA0,0x64
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_6_27_28_AND_RET.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_6_27_28_AND_RET.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_6_AND_RET:
	video type=1, offset=CINEMATIC_006, x=160, y=100	;@raw=0x89,0x0A,0xA0,0x64
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_6_AND_RET.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_6_AND_RET.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_BG_DOTS_CIN_001_004:
	video type=1, offset=CINEMATIC_004, x=299, y=37, zoom=0x40	;@raw=0x78,0x07,0x87,0x2B,0x25
	video type=1, offset=CINEMATIC_004, x=289, y=23, zoom=0x40	;@raw=0x78,0x07,0x87,0x21,0x17
	video type=1, offset=CINEMATIC_001, x=205, y=21	;@raw=0x87,0xBA,0xCD,0x15
	video type=1, offset=CINEMATIC_001, x=187, y=27	;@raw=0x87,0xBA,0xBB,0x1B
	video type=1, offset=CINEMATIC_001, x=247, y=25	;@raw=0x87,0xBA,0xF7,0x19
	video type=1, offset=CINEMATIC_001, x=167, y=20	;@raw=0x87,0xBA,0xA7,0x14
	video type=1, offset=CINEMATIC_001, x=142, y=21	;@raw=0x87,0xBA,0x8E,0x15
	video type=1, offset=CINEMATIC_001, x=228, y=22	;@raw=0x87,0xBA,0xE4,0x16
	video type=1, offset=CINEMATIC_001, x=279, y=21, zoom=0x40	;@raw=0x78,0x07,0xBA,0x17,0x15
	video type=1, offset=CINEMATIC_001, x=310, y=20, zoom=0x40	;@raw=0x78,0x07,0xBA,0x36,0x14
	video type=1, offset=CINEMATIC_002, x=186, y=24	;@raw=0x87,0xDE,0xBA,0x18
	video type=1, offset=CINEMATIC_002, x=207, y=21	;@raw=0x87,0xDE,0xCF,0x15
	video type=1, offset=CINEMATIC_002, x=161, y=22	;@raw=0x87,0xDE,0xA1,0x16
	video type=1, offset=CINEMATIC_002, x=240, y=21	;@raw=0x87,0xDE,0xF0,0x15
	video type=1, offset=CINEMATIC_002, x=303, y=18, zoom=0x40	;@raw=0x78,0x07,0xDE,0x2F,0x12
	video type=1, offset=CINEMATIC_002, x=140, y=20	;@raw=0x87,0xDE,0x8C,0x14
	video type=1, offset=CINEMATIC_002, x=242, y=22	;@raw=0x87,0xDE,0xF2,0x16
	video type=1, offset=CINEMATIC_002, x=224, y=21	;@raw=0x87,0xDE,0xE0,0x15
	video type=1, offset=CINEMATIC_002, x=287, y=21, zoom=0x40	;@raw=0x78,0x07,0xDE,0x1F,0x15
	video type=1, offset=CINEMATIC_002, x=259, y=27, zoom=0x40	;@raw=0x78,0x07,0xDE,0x03,0x1B
	video type=1, offset=CINEMATIC_002, x=140, y=20	;@raw=0x87,0xDE,0x8C,0x14
	video type=1, offset=CINEMATIC_003, x=164, y=23	;@raw=0x88,0x14,0xA4,0x17
	video type=1, offset=CINEMATIC_003, x=198, y=21	;@raw=0x88,0x14,0xC6,0x15
	video type=1, offset=CINEMATIC_003, x=216, y=25	;@raw=0x88,0x14,0xD8,0x19
	video type=1, offset=CINEMATIC_003, x=147, y=24	;@raw=0x88,0x14,0x93,0x18
	video type=1, offset=CINEMATIC_003, x=302, y=17, zoom=0x40	;@raw=0x78,0x08,0x14,0x2E,0x11
	video type=1, offset=CINEMATIC_003, x=273, y=21, zoom=0x40	;@raw=0x78,0x08,0x14,0x11,0x15
	video type=1, offset=CINEMATIC_003, x=255, y=21	;@raw=0x88,0x14,0xFF,0x15
	video type=1, offset=CINEMATIC_003, x=222, y=18	;@raw=0x88,0x14,0xDE,0x12
	video type=1, offset=CINEMATIC_003, x=134, y=21	;@raw=0x88,0x14,0x86,0x15
	video type=1, offset=CINEMATIC_003, x=114, y=23	;@raw=0x88,0x14,0x72,0x17
	video type=1, offset=CINEMATIC_003, x=190, y=20	;@raw=0x88,0x14,0xBE,0x14
	video type=1, offset=CINEMATIC_003, x=245, y=23	;@raw=0x88,0x14,0xF5,0x17
	video type=1, offset=CINEMATIC_003, x=294, y=19, zoom=0x40	;@raw=0x78,0x08,0x14,0x26,0x13
	video type=1, offset=CINEMATIC_005, x=211, y=26	;@raw=0x88,0x40,0xD3,0x1A
	video type=1, offset=CINEMATIC_005, x=196, y=19	;@raw=0x88,0x40,0xC4,0x13
	video type=1, offset=CINEMATIC_005, x=156, y=17	;@raw=0x88,0x40,0x9C,0x11
	video type=1, offset=CINEMATIC_005, x=141, y=28	;@raw=0x88,0x40,0x8D,0x1C
	video type=1, offset=CINEMATIC_005, x=124, y=23	;@raw=0x88,0x40,0x7C,0x17
	video type=1, offset=CINEMATIC_005, x=182, y=13	;@raw=0x88,0x40,0xB6,0x0D
	video type=1, offset=CINEMATIC_005, x=221, y=17	;@raw=0x88,0x40,0xDD,0x11
	video type=1, offset=CINEMATIC_005, x=257, y=18, zoom=0x40	;@raw=0x78,0x08,0x40,0x01,0x12
	video type=1, offset=CINEMATIC_005, x=242, y=18	;@raw=0x88,0x40,0xF2,0x12
	video type=1, offset=CINEMATIC_005, x=295, y=21, zoom=0x40	;@raw=0x78,0x08,0x40,0x27,0x15
	video type=1, offset=CINEMATIC_005, x=303, y=19, zoom=0x40	;@raw=0x78,0x08,0x40,0x2F,0x13
	video type=1, offset=CINEMATIC_005, x=280, y=17, zoom=0x40	;@raw=0x78,0x08,0x40,0x18,0x11
	video type=1, offset=CINEMATIC_005, x=87, y=20	;@raw=0x88,0x40,0x57,0x14
	video type=1, offset=CINEMATIC_005, x=107, y=22	;@raw=0x88,0x40,0x6B,0x16
	video type=1, offset=CINEMATIC_005, x=35, y=17	;@raw=0x88,0x40,0x23,0x11
	video type=1, offset=CINEMATIC_005, x=61, y=18	;@raw=0x88,0x40,0x3D,0x12
	video type=1, offset=CINEMATIC_005, x=0, y=21	;@raw=0x88,0x40,0x00,0x15
	video type=1, offset=CINEMATIC_005, x=10, y=21	;@raw=0x88,0x40,0x0A,0x15
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_BG_DOTS_CIN_001_004.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_BG_DOTS_CIN_001_004.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_BG_DOTS_CIN_007_008:
	video type=1, offset=CINEMATIC_007, x=299, y=37, zoom=0x40	;@raw=0x78,0x09,0x32,0x2B,0x25
	video type=1, offset=CINEMATIC_007, x=289, y=23, zoom=0x40	;@raw=0x78,0x09,0x32,0x21,0x17
	video type=1, offset=CINEMATIC_008, x=205, y=21	;@raw=0x89,0x65,0xCD,0x15
	video type=1, offset=CINEMATIC_008, x=187, y=27	;@raw=0x89,0x65,0xBB,0x1B
	video type=1, offset=CINEMATIC_008, x=247, y=25	;@raw=0x89,0x65,0xF7,0x19
	video type=1, offset=CINEMATIC_008, x=167, y=20	;@raw=0x89,0x65,0xA7,0x14
	video type=1, offset=CINEMATIC_008, x=142, y=21	;@raw=0x89,0x65,0x8E,0x15
	video type=1, offset=CINEMATIC_008, x=228, y=22	;@raw=0x89,0x65,0xE4,0x16
	video type=1, offset=CINEMATIC_008, x=279, y=21, zoom=0x40	;@raw=0x78,0x09,0x65,0x17,0x15
	video type=1, offset=CINEMATIC_008, x=310, y=20, zoom=0x40	;@raw=0x78,0x09,0x65,0x36,0x14
	video type=1, offset=CINEMATIC_009, x=186, y=24	;@raw=0x89,0x89,0xBA,0x18
	video type=1, offset=CINEMATIC_009, x=207, y=21	;@raw=0x89,0x89,0xCF,0x15
	video type=1, offset=CINEMATIC_009, x=161, y=22	;@raw=0x89,0x89,0xA1,0x16
	video type=1, offset=CINEMATIC_009, x=240, y=21	;@raw=0x89,0x89,0xF0,0x15
	video type=1, offset=CINEMATIC_009, x=303, y=18, zoom=0x40	;@raw=0x78,0x09,0x89,0x2F,0x12
	video type=1, offset=CINEMATIC_009, x=140, y=20	;@raw=0x89,0x89,0x8C,0x14
	video type=1, offset=CINEMATIC_009, x=242, y=22	;@raw=0x89,0x89,0xF2,0x16
	video type=1, offset=CINEMATIC_009, x=224, y=21	;@raw=0x89,0x89,0xE0,0x15
	video type=1, offset=CINEMATIC_009, x=287, y=21, zoom=0x40	;@raw=0x78,0x09,0x89,0x1F,0x15
	video type=1, offset=CINEMATIC_009, x=259, y=27, zoom=0x40	;@raw=0x78,0x09,0x89,0x03,0x1B
	video type=1, offset=CINEMATIC_009, x=140, y=20	;@raw=0x89,0x89,0x8C,0x14
	video type=1, offset=CINEMATIC_010, x=164, y=23	;@raw=0x89,0xBF,0xA4,0x17
	video type=1, offset=CINEMATIC_010, x=198, y=21	;@raw=0x89,0xBF,0xC6,0x15
	video type=1, offset=CINEMATIC_010, x=216, y=25	;@raw=0x89,0xBF,0xD8,0x19
	video type=1, offset=CINEMATIC_010, x=147, y=24	;@raw=0x89,0xBF,0x93,0x18
	video type=1, offset=CINEMATIC_010, x=302, y=17, zoom=0x40	;@raw=0x78,0x09,0xBF,0x2E,0x11
	video type=1, offset=CINEMATIC_010, x=273, y=21, zoom=0x40	;@raw=0x78,0x09,0xBF,0x11,0x15
	video type=1, offset=CINEMATIC_010, x=255, y=21	;@raw=0x89,0xBF,0xFF,0x15
	video type=1, offset=CINEMATIC_010, x=222, y=18	;@raw=0x89,0xBF,0xDE,0x12
	video type=1, offset=CINEMATIC_010, x=134, y=21	;@raw=0x89,0xBF,0x86,0x15
	video type=1, offset=CINEMATIC_010, x=114, y=23	;@raw=0x89,0xBF,0x72,0x17
	video type=1, offset=CINEMATIC_010, x=190, y=20	;@raw=0x89,0xBF,0xBE,0x14
	video type=1, offset=CINEMATIC_010, x=245, y=23	;@raw=0x89,0xBF,0xF5,0x17
	video type=1, offset=CINEMATIC_010, x=294, y=19, zoom=0x40	;@raw=0x78,0x09,0xBF,0x26,0x13
	video type=1, offset=CINEMATIC_011, x=211, y=26	;@raw=0x89,0xEB,0xD3,0x1A
	video type=1, offset=CINEMATIC_011, x=196, y=19	;@raw=0x89,0xEB,0xC4,0x13
	video type=1, offset=CINEMATIC_011, x=156, y=17	;@raw=0x89,0xEB,0x9C,0x11
	video type=1, offset=CINEMATIC_011, x=141, y=28	;@raw=0x89,0xEB,0x8D,0x1C
	video type=1, offset=CINEMATIC_011, x=124, y=23	;@raw=0x89,0xEB,0x7C,0x17
	video type=1, offset=CINEMATIC_011, x=182, y=13	;@raw=0x89,0xEB,0xB6,0x0D
	video type=1, offset=CINEMATIC_011, x=221, y=17	;@raw=0x89,0xEB,0xDD,0x11
	video type=1, offset=CINEMATIC_011, x=257, y=18, zoom=0x40	;@raw=0x78,0x09,0xEB,0x01,0x12
	video type=1, offset=CINEMATIC_011, x=242, y=18	;@raw=0x89,0xEB,0xF2,0x12
	video type=1, offset=CINEMATIC_011, x=295, y=21, zoom=0x40	;@raw=0x78,0x09,0xEB,0x27,0x15
	video type=1, offset=CINEMATIC_011, x=303, y=19, zoom=0x40	;@raw=0x78,0x09,0xEB,0x2F,0x13
	video type=1, offset=CINEMATIC_011, x=280, y=17, zoom=0x40	;@raw=0x78,0x09,0xEB,0x18,0x11
	video type=1, offset=CINEMATIC_011, x=87, y=20	;@raw=0x89,0xEB,0x57,0x14
	video type=1, offset=CINEMATIC_011, x=107, y=22	;@raw=0x89,0xEB,0x6B,0x16
	video type=1, offset=CINEMATIC_011, x=35, y=17	;@raw=0x89,0xEB,0x23,0x11
	video type=1, offset=CINEMATIC_011, x=61, y=18	;@raw=0x89,0xEB,0x3D,0x12
	video type=1, offset=CINEMATIC_011, x=0, y=21	;@raw=0x89,0xEB,0x00,0x15
	video type=1, offset=CINEMATIC_011, x=10, y=21	;@raw=0x89,0xEB,0x0A,0x15
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

