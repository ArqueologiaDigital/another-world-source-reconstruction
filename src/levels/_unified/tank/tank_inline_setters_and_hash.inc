INIT_VARS_48_49_4A:
	mov [0x48], 0xFFEC
	mov [0x49], 0x0064
	mov [0x4A], 0x0004

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_48_49_4A.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_48_49_4A.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_48_49_4A.inc"
;@endif

INLINE_SET_VAR66_TO_32:
	mov [0x66], 0x0032

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR66_TO_32.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR66_TO_32.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR66_TO_32.inc"
;@endif

SUM_HASH_VARS_TO_VAR_64:
	add [0x64], 0x0071
	add [0x64], [0x32]
	add [0x64], [0x01]
	add [0x64], [0x0A]
	add [0x64], [0x0B]
	add [0x64], [HERO_ACTION_POS_MASK]
	mov [0x65], [0x64]
	and [0x65], 0x00FF
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SUM_HASH_VARS_TO_VAR_64.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_TANK_DRIVE_VARS:
	mov [0x0F], 0x008C
	mov [0x10], 0x0064
	mov [0x01], 0x00A0
	mov [0x02], 0x0064
	mov [0x03], 0x0040
	mov [0x3E], 0x0000
	mov [0x41], 0x0000
	mov [0x37], 0x0000
	mov [0x45], 0x0000
	mov [0x46], 0x0000
	mov [0x47], 0x0000
	mov [0x4E], 0x0000
	mov [0x4F], 0x0000
	mov [0x56], 0x0000
	mov [0x57], 0x0000
	mov [0x62], 0x000B
	mov [0x5F], 0x000B
	mov [0x63], 0x0000
	mov [HACK_VAR_67], 0x0000
	mov [0x69], 0x00FA
	mov [0x6E], 0x0000
	mov [0x70], 0x0000
	mov [0x71], 0x0000
	mov [0x72], 0x0000
	mov [0x73], 0x0000
	mov [0x74], 0x0000
	mov [0x75], 0x0000
	mov [0x76], 0x0000
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INIT_TANK_DRIVE_VARS.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_TANK_DRIVE_VARS.inc"
;@endif

