SET_VAR22_TO_006B:
	mov [0x22], 0x006B
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_006B.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_006B.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_006B.inc"
;@endif

SET_VAR22_TO_0061:
	mov [0x22], 0x0061
	ret


SET_VAR22_TO_00C8:
	mov [0x22], 0x00C8
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_00C8.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00C8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00C8.inc"
;@endif

PROJ_VAR22_68_MINUS_VAR21_MINUS_F2_SHR4:
	sub [0x21], 0x00F2
	shr [0x21], 0x0004
	mov [0x22], 0x0068
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_68_MINUS_VAR21_MINUS_F2_SHR4.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_68_MINUS_VAR21_MINUS_F2_SHR4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_68_MINUS_VAR21_MINUS_F2_SHR4.inc"
;@endif

DEDUP_CAVES_5B_027:
	mov [0x22], 0x006F
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_027.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_027.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_027.inc"
;@endif

PROJ_VAR22_2F_MINUS_VAR21_MINUS_ED_SHR1:
	sub [0x21], 0x00ED
	shr [0x21], 0x0001
	mov [0x22], 0x002F
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_2F_MINUS_VAR21_MINUS_ED_SHR1.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_2F_MINUS_VAR21_MINUS_ED_SHR1.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_2F_MINUS_VAR21_MINUS_ED_SHR1.inc"
;@endif

SET_VAR22_TO_00AB:
	mov [0x22], 0x00AB
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_00AB.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00AB.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00AB.inc"
;@endif

PROJ_VAR22_17_MINUS_VAR21_MINUS_F0_SHL3:
	sub [0x21], 0x00F0
	shl [0x21], 0x0003
	mov [0x22], 0x0017
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_17_MINUS_VAR21_MINUS_F0_SHL3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_17_MINUS_VAR21_MINUS_F0_SHL3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_17_MINUS_VAR21_MINUS_F0_SHL3.inc"
;@endif

PROJ_VAR22_AA_MINUS_VAR21_MINUS_115_SHR3:
	sub [0x21], 0x0115
	shr [0x21], 0x0003
	mov [0x22], 0x00AA
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_AA_MINUS_VAR21_MINUS_115_SHR3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_AA_MINUS_VAR21_MINUS_115_SHR3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_AA_MINUS_VAR21_MINUS_115_SHR3.inc"
;@endif

INIT_VARS_01_22:
	mov [0x01], 0x0078
	mov [0x22], 0x0064
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_01_22.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_01_22.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_01_22.inc"
;@endif

PROJ_VAR22_B3_MINUS_VAR21_MINUS_109_SHR3:
	sub [0x21], 0x0109
	shr [0x21], 0x0003
	mov [0x22], 0x00B3
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_B3_MINUS_VAR21_MINUS_109_SHR3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_B3_MINUS_VAR21_MINUS_109_SHR3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_B3_MINUS_VAR21_MINUS_109_SHR3.inc"
;@endif

PROJ_VAR22_53_PLUS_VAR21_MINUS_106_SHR3:
	sub [0x21], 0x0106
	shr [0x21], 0x0003
	mov [0x22], 0x0053
	add [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_53_PLUS_VAR21_MINUS_106_SHR3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_53_PLUS_VAR21_MINUS_106_SHR3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_53_PLUS_VAR21_MINUS_106_SHR3.inc"
;@endif

PROJ_VAR22_9E_MINUS_VAR21_MINUS_121_SHR3:
	sub [0x21], 0x0121
	shr [0x21], 0x0003
	mov [0x22], 0x009E
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_9E_MINUS_VAR21_MINUS_121_SHR3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_9E_MINUS_VAR21_MINUS_121_SHR3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_9E_MINUS_VAR21_MINUS_121_SHR3.inc"
;@endif

PROJ_VAR22_7E_MINUS_VAR21_MINUS_11B_SHR4:
	sub [0x21], 0x011B
	shr [0x21], 0x0004
	mov [0x22], 0x007E
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_7E_MINUS_VAR21_MINUS_11B_SHR4.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_7E_MINUS_VAR21_MINUS_11B_SHR4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_7E_MINUS_VAR21_MINUS_11B_SHR4.inc"
;@endif

PROJ_VAR22_75_MINUS_VAR21_MINUS_FD_SHR6:
	sub [0x21], 0x00FD
	shr [0x21], 0x0006
	mov [0x22], 0x0075
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_75_MINUS_VAR21_MINUS_FD_SHR6.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_75_MINUS_VAR21_MINUS_FD_SHR6.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_75_MINUS_VAR21_MINUS_FD_SHR6.inc"
;@endif

PROJ_VAR22_76_MINUS_VAR21_MINUS_108_SHR5:
	sub [0x21], 0x0108
	shr [0x21], 0x0005
	mov [0x22], 0x0076
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_76_MINUS_VAR21_MINUS_108_SHR5.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_76_MINUS_VAR21_MINUS_108_SHR5.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_76_MINUS_VAR21_MINUS_108_SHR5.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
PROJ_VAR22_49_MINUS_VAR21_MINUS_113_SHR4:
	sub [0x21], 0x0113
	shr [0x21], 0x0004
	mov [0x22], 0x0049
	sub [0x22], [0x21]
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_49_MINUS_VAR21_MINUS_113_SHR4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_49_MINUS_VAR21_MINUS_113_SHR4.inc"
;@endif

SET_VAR22_TO_007D:
	mov [0x22], 0x007D
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_007D.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_007D.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_007D.inc"
;@endif

SET_VAR22_TO_0080:
	mov [0x22], 0x0080
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_0080.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_0080.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_0080.inc"
;@endif

SET_VAR22_TO_00AC:
	mov [0x22], 0x00AC
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_00AC.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00AC.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00AC.inc"
;@endif

SET_VAR22_TO_0087:
	mov [0x22], 0x0087
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_0087.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_0087.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_0087.inc"
;@endif

PROJ_VAR22_85_PLUS_VAR21_MINUS_56:
	sub [0x21], 0x0056
	mov [0x22], 0x0085
	add [0x22], [0x21]
	ret


SET_VAR22_TO_0085:
	mov [0x22], 0x0085
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_0085.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_0085.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_0085.inc"
;@endif

SET_VAR22_TO_00C3:
	mov [0x22], 0x00C3
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_00C3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00C3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00C3.inc"
;@endif

PROJ_VAR22_A8_MINUS_VAR21_MINUS_112_SHR4:
	sub [0x21], 0x0112
	shr [0x21], 0x0004
	mov [0x22], 0x00A8
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_A8_MINUS_VAR21_MINUS_112_SHR4.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_A8_MINUS_VAR21_MINUS_112_SHR4.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_A8_MINUS_VAR21_MINUS_112_SHR4.inc"
;@endif

DEDUP_CAVES_5B_011:
	mov [0x22], 0x00B0
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_011.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_011.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_011.inc"
;@endif

PROJ_VAR22_B0_PLUS_VAR21_MINUS_69:
	sub [0x21], 0x0069
	mov [0x22], 0x00B0
	add [0x22], [0x21]
	ret


DEDUP_CAVES_5B_012:
	mov [0x22], 0x00B0
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_012.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_012.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_012.inc"
;@endif

DEDUP_CAVES_5B_028:
	mov [0x22], 0x006F
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_DEDUP_CAVES_5B_028.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_DEDUP_CAVES_5B_028.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_DEDUP_CAVES_5B_028.inc"
;@endif

;@if BRANCH in ("cartridge_1992", "dos_1992")
SET_VAR22_TO_0042:
	mov [0x22], 0x0042
	ret
;@endif

;@if BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_0042.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_0042.inc"
;@endif

SET_VAR22_TO_00AE:
	mov [0x22], 0x00AE
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_00AE.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00AE.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00AE.inc"
;@endif

PROJ_VAR22_A7_MINUS_VAR21_MINUS_125_SHR3:
	sub [0x21], 0x0125
	shr [0x21], 0x0003
	mov [0x22], 0x00A7
	sub [0x22], [0x21]
	ret

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PROJ_VAR22_A7_MINUS_VAR21_MINUS_125_SHR3.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PROJ_VAR22_A7_MINUS_VAR21_MINUS_125_SHR3.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PROJ_VAR22_A7_MINUS_VAR21_MINUS_125_SHR3.inc"
;@endif

;@include "../_helpers/SET_VAR22_TO_00B8.inc"
;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_SET_VAR22_TO_00B8.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_SET_VAR22_TO_00B8.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_SET_VAR22_TO_00B8.inc"
;@endif

INIT_VARS_EB_47:
	mov [0xEB], 0x000A
	mov [0x47], 0x010A

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_INIT_VARS_EB_47.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_INIT_VARS_EB_47.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_INIT_VARS_EB_47.inc"
;@endif

PLAY_FX_6B_THEN_KILL_CHANNEL:
	play id=0x006B, freq=0x1C, vol=0x40, channel=0x03
	killChannel

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_PLAY_FX_6B_THEN_KILL_CHANNEL.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_PLAY_FX_6B_THEN_KILL_CHANNEL.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_PLAY_FX_6B_THEN_KILL_CHANNEL.inc"
;@endif

