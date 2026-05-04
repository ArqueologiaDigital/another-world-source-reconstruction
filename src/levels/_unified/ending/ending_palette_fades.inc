PAL_FADE_18_TO_1D:
	setPalette 0x18	;@raw=0x0B,0x18,0xFF
	break
	setPalette 0x19	;@raw=0x0B,0x19,0xFF
	break
	setPalette 0x1A	;@raw=0x0B,0x1A,0xFF
	break
	setPalette 0x1B	;@raw=0x0B,0x1B,0xFF
	break
	setPalette 0x1C	;@raw=0x0B,0x1C,0xFF
	break
	setPalette 0x1D	;@raw=0x0B,0x1D,0xFF
	killChannel
	setPalette 0x1D	;@raw=0x0B,0x1D,0xFF
	break
	setPalette 0x1C	;@raw=0x0B,0x1C,0xFF
	break
	setPalette 0x1B	;@raw=0x0B,0x1B,0xFF
	break
	setPalette 0x1A	;@raw=0x0B,0x1A,0xFF
	break
	setPalette 0x19	;@raw=0x0B,0x19,0xFF
	break
	setPalette 0x18	;@raw=0x0B,0x18,0xFF
	break
	setPalette 0x17	;@raw=0x0B,0x17,0xFF
	killChannel

;@if BRANCH == "cartridge_1992"
;@include "cart__post_PAL_FADE_18_TO_1D.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_71_72_FADE:
	video type=1, offset=CINEMATIC_071, x=160, y=100	;@raw=0xA3,0x74,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_071, x=160, y=100	;@raw=0xA3,0x74,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_071, x=160, y=100	;@raw=0xA3,0x74,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_072, x=160, y=100	;@raw=0xA3,0x54,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_072, x=160, y=100	;@raw=0xA3,0x54,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_073, x=160, y=100	;@raw=0xA3,0x34,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_073, x=160, y=100	;@raw=0xA3,0x34,0xA0,0x64
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_71_72_FADE.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_71_72_FADE.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_106_107_FX_57:
	video type=1, offset=CINEMATIC_106, x=160, y=100	;@raw=0xA3,0x94,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_106, x=160, y=100	;@raw=0xA3,0x94,0xA0,0x64
	break
	play id=0x0057, freq=0x22, vol=0x20, channel=0x03
	video type=1, offset=CINEMATIC_107, x=160, y=100	;@raw=0xA3,0xBF,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_107, x=160, y=100	;@raw=0xA3,0xBF,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_107, x=160, y=100	;@raw=0xA3,0xBF,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_107, x=160, y=100	;@raw=0xA3,0xBF,0xA0,0x64
	break
	video type=1, offset=CINEMATIC_106, x=160, y=100	;@raw=0xA3,0x94,0xA0,0x64
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_106_107_FX_57.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_106_107_FX_57.inc"
;@endif

