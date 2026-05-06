DELETE_ALL_CHANS_AND_KILL:
	deleteChannels first=0x00, last=0x3F
	killChannel

;@if BRANCH == "cartridge_1992"
;@include "cart__post_DELETE_ALL_CHANS_AND_KILL.inc"
;@endif

;@if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRELOAD_RESOURCES_8_TO_1:
	load id=0x0008
	load id=0x008A
	load id=0x0081
	load id=0x0082
	load id=0x0083
	load id=0x0080
	load id=0x0001
	load id=0x0057
	load id=0x005E
	load id=0x000E
	load id=0x000F
	load id=0x005F
	load id=0x000C
	ret
;@endif

