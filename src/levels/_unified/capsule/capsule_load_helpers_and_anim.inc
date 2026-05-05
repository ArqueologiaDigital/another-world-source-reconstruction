LOAD_RES90_COPY_PAGE0_TO_3_LOAD_RES91:
	load id=0x0090
	copyVideoPage src=0x00, dst=0x03
	load id=0x0091
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_LOAD_RES90_COPY_PAGE0_TO_3_LOAD_RES91.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_LOAD_RES90_COPY_PAGE0_TO_3_LOAD_RES91.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_LOAD_RES90_COPY_PAGE0_TO_3_LOAD_RES91.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/SET_VAR22_TO_00B8.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00B8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00B8.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
SET_VAR22_TO_00B4:
	mov [0x22], 0x00B4
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00B4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00B4.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
SET_VAR22_TO_0097:
	mov [0x22], 0x0097
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_0097.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_0097.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
SET_VAR22_TO_00FA:
	mov [0x22], 0x00FA
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00FA.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00FA.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
PROJ_VAR22_B0_PLUS_VAR21_MINUS_9A:
	sub [0x21], 0x009A
	mov [0x22], 0x00B0
	add [0x22], [0x21]
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_B0_PLUS_VAR21_MINUS_9A.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_B0_PLUS_VAR21_MINUS_9A.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
PROJ_VAR22_37_PLUS_VAR21_PLUS_A:
	add [0x21], 0x000A
	mov [0x22], 0x0037
	add [0x22], [0x21]
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_37_PLUS_VAR21_PLUS_A.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_37_PLUS_VAR21_PLUS_A.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
SET_VAR22_TO_003E:
	mov [0x22], 0x003E
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_003E.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_003E.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_SET_VAR02_TO_97:
	mov [HERO_Y], 0x0097
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR02_TO_97.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR02_TO_97.inc"
;@endif

;@include "../_helpers/INIT_RANGE_48_TO_4D_TO_MAX.inc"
;@include "../_helpers/INIT_VARS_AA_AD_5B_5E_PLUS1.inc"
;@include "../_helpers/INIT_VARS_A1_A4_A7.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_A1_A4_A7.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_A1_A4_A7.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_A1_A4_A7.inc"
;@endif

;@include "../_helpers/COPY_PAGE0_TO_PAGE_FF.inc"
;@include "../_helpers/COPY_HACK67_TO_VAR66.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_COPY_HACK67_TO_VAR66.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_COPY_HACK67_TO_VAR66.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_COPY_HACK67_TO_VAR66.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/ADD_HACK67_BY_20.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_ADD_HACK67_BY_20.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_ADD_HACK67_BY_20.inc"
;@endif

;@include "../_helpers/SUB_HACK67_BY_20.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SUB_HACK67_BY_20.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SUB_HACK67_BY_20.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SUB_HACK67_BY_20.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
SET_VARHACK_VAR_67_TO_00AA:
	mov [HACK_VAR_67], 0x00AA
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_SET_VARHACK_VAR_67_TO_00AA.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VARHACK_VAR_67_TO_00AA.inc"
;@endif

;@include "../_helpers/DECR_HACK67_BY_1.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DECR_HACK67_BY_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DECR_HACK67_BY_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DECR_HACK67_BY_1.inc"
;@endif

;@include "../_helpers/INCR_HACK67_BY_1.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INCR_HACK67_BY_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INCR_HACK67_BY_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INCR_HACK67_BY_1.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
INIT_BIRD_AI_VARS:
	mov [HERO_X], 0x0091
	mov [HERO_Y], 0x008F
	mov [0x0F], 0x0000
	mov [0x28], [HERO_X]
	mov [0x04], 0x0020
	mov [0x05], 0x0000
	mov [0x06], 0x03DE
	mov [0x0A], 0x0001
	mov [0x63], 0x0001
	mov [0x2A], 0x000F
	ret
;@endif


;@include "../_helpers/SET_VAR04_TO_0020.inc"
;@include "../_helpers/SET_VAR04_TO_0030.inc"
;@include "../_helpers/SET_VAR04_TO_0000.inc"
;@include "../_helpers/SET_VAR04_TO_0010.inc"
;@include "../_helpers/SET_VAR04_TO_0008.inc"
;@include "../_helpers/SET_VAR04_TO_0034.inc"
;@include "../_helpers/SET_VAR04_TO_0024.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR04_TO_0024.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR04_TO_0024.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR04_TO_0024.inc"
;@endif

;@include "../_helpers/INLINE_SET_VAR63_TO_1.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR63_TO_1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR63_TO_1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR63_TO_1.inc"
;@endif

;@include "../_helpers/INLINE_SET_VAR63_TO_2.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR63_TO_2.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR63_TO_2.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR63_TO_2.inc"
;@endif

;@include "../_helpers/INLINE_SET_VAR63_TO_5.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR63_TO_5.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR63_TO_5.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR63_TO_5.inc"
;@endif

;@include "../_helpers/INLINE_SET_VAR63_TO_6.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INLINE_SET_VAR63_TO_6.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INLINE_SET_VAR63_TO_6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INLINE_SET_VAR63_TO_6.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/WALK_RIGHT_DRAW_CV142_MULTISTEP.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_WALK_RIGHT_DRAW_CV142_MULTISTEP.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_WALK_RIGHT_DRAW_CV142_MULTISTEP.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
;@include "../_helpers/WALK_LEFT_DRAW_CV140_MULTISTEP.inc"
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_WALK_LEFT_DRAW_CV140_MULTISTEP.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_WALK_LEFT_DRAW_CV140_MULTISTEP.inc"
;@endif

;@include "../_helpers/STEP_DRAW_CV352_LEFT4_RIGHT1.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_STEP_DRAW_CV352_LEFT4_RIGHT1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_STEP_DRAW_CV352_LEFT4_RIGHT1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_STEP_DRAW_CV352_LEFT4_RIGHT1.inc"
;@endif

;@include "../_helpers/DRAW_CV352_STEP_RIGHT3.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DRAW_CV352_STEP_RIGHT3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DRAW_CV352_STEP_RIGHT3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DRAW_CV352_STEP_RIGHT3.inc"
;@endif

