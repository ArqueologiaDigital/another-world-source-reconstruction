;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRELOAD_RES_6A_77_6D_6E_74_76_78_7C:
	load id=0x006A
	load id=0x0077
	load id=0x006D
	load id=0x006E
	load id=0x0074
	load id=0x0076
	load id=0x0078
	load id=0x007C
	load id=0x0079
	load id=0x007A
	load id=0x007B
	load id=0x006C
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@elif BRANCH == "dos_1992"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRELOAD_CAVES_RESOURCES:
	load id=0x006B
	load id=0x0055
	load id=0x0056
	load id=0x0057
	load id=0x005E
	load id=0x005F
	load id=0x006B
	load id=0x006C
	load id=0x006D
	load id=0x0075
	load id=0x0074
	load id=0x0078
	load id=0x007A
	load id=0x0077
	load id=0x0066
	load id=0x0088
	load id=0x0070
	load id=0x0071
	load id=0x0072
	ret
;@endif

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PRELOAD_CAVES_RESOURCES.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PRELOAD_CAVES_RESOURCES.inc"
;@endif

;@include "../_helpers/KILL_CHANNEL_LANDING.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_KILL_CHANNEL_LANDING.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_KILL_CHANNEL_LANDING.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_KILL_CHANNEL_LANDING.inc"
;@endif

