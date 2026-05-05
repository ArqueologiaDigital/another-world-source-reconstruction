;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DELAY_4_QUANTUMS:
	break
	break
	break
	break
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DELAY_4_QUANTUMS.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DELAY_4_QUANTUMS.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRELOAD_PRISON_RESOURCES:
	load id=0x0052
	load id=0x0055
	load id=0x0056
	load id=0x0057
	load id=0x0058
	load id=0x0059
	load id=0x005A
	load id=0x005B
	load id=0x005C
	load id=0x005D
	load id=0x005E
	load id=0x005F
	load id=0x0060
	load id=0x0061
	load id=0x0062
	load id=0x0063
	load id=0x0064
	load id=0x0065
	load id=0x0073
	load id=0x0067
	load id=0x0070
	load id=0x0071
	load id=0x0072
	load id=0x0066
	load id=0x0068
	load id=0x0069
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PRELOAD_PRISON_RESOURCES.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PRELOAD_PRISON_RESOURCES.inc"
;@endif

;@include "../_helpers/KILL_CHANNEL_LANDING.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_KILL_039.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_KILL_039.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_KILL_039.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
BANK4_AFTER_CIN_414:
	mov [0x01], 0x0041
	add [0x02], 0x0016
	video offset=CINEMATIC_414, x=[0x01], y=[0x02], zoom=0x40
	add [0x02], 0x001A
	break
	add [0x02], 0x0020
	video offset=CINEMATIC_415, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x00], 0x001E
	bankSwitch 4;  Gas tunnels, Caves and Pool
	killChannel
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_BANK4_AFTER_CIN_414.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_BANK4_AFTER_CIN_414.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_422_WITH_POS_STEP_AT_C7A1BFCB:
	sub [0x02], 0x0009
	video offset=CINEMATIC_422, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	mov [0x03], 0x000B
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CIN_422_WITH_POS_STEP_AT_C7A1BFCB.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CIN_422_WITH_POS_STEP_AT_C7A1BFCB.inc"
;@endif
