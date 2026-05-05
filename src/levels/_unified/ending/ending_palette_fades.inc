PAL_FADE_18_TO_1D:
	setPalette 0x18
	break
	setPalette 0x19
	break
	setPalette 0x1A
	break
	setPalette 0x1B
	break
	setPalette 0x1C
	break
	setPalette 0x1D
	killChannel
	setPalette 0x1D
	break
	setPalette 0x1C
	break
	setPalette 0x1B
	break
	setPalette 0x1A
	break
	setPalette 0x19
	break
	setPalette 0x18
	break
	setPalette 0x17
	killChannel

;@if BRANCH == "cartridge_1992"
;@include "cart__post_PAL_FADE_18_TO_1D.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_71_72_FADE:
	video offset=CINEMATIC_071, x=160, y=100
	break
	video offset=CINEMATIC_071, x=160, y=100
	break
	video offset=CINEMATIC_071, x=160, y=100
	break
	video offset=CINEMATIC_072, x=160, y=100
	break
	video offset=CINEMATIC_072, x=160, y=100
	break
	video offset=CINEMATIC_073, x=160, y=100
	break
	video offset=CINEMATIC_073, x=160, y=100
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_71_72_FADE.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_71_72_FADE.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_106_107_FX_57:
	video offset=CINEMATIC_106, x=160, y=100
	break
	video offset=CINEMATIC_106, x=160, y=100
	break
	play id=0x0057, freq=0x22, vol=0x20, channel=0x03
	video offset=CINEMATIC_107, x=160, y=100
	break
	video offset=CINEMATIC_107, x=160, y=100
	break
	video offset=CINEMATIC_107, x=160, y=100
	break
	video offset=CINEMATIC_107, x=160, y=100
	break
	video offset=CINEMATIC_106, x=160, y=100
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_106_107_FX_57.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_106_107_FX_57.inc"
;@endif

