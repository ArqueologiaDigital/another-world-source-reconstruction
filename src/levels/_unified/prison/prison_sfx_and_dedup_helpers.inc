PLAY_SFX_005C_CH01:
	play id=0x005C, freq=0x19, vol=0x40, channel=0x01
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_PLAY_SFX_005C_CH01.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_PLAY_SFX_005C_CH01.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_PLAY_SFX_005C_CH01.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/RET_THEN_KILL_CHANNEL.inc"
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_RET_THEN_KILL_CHANNEL.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_RET_THEN_KILL_CHANNEL.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_486:
	video offset=CINEMATIC_486, x=[0x21], y=[0x27]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_486_L0:
	jle [0x13], 0x02, PRISON_DRAW_CIN_486_L1
	video offset=CINEMATIC_485, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_486_L1:
	jle [0x13], 0x01, DRAW_CIN_483
	video offset=CINEMATIC_484, x=[0x21], y=[0x27]
	ret
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_483:
	video offset=CINEMATIC_483, x=[0x21], y=[0x27]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_483_L0:
	jge [0x13], 0xC8, PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L9
	je [0x13], 0x64, PRISON_SUPERBLAST_ADVANCE_RIGHT_CASE_64
	je [0x13], 0x65, PRISON_SUPERBLAST_SWEEP_RIGHT_CASE_65
	jge [0x13], 0x81, PRISON_SHOT_IMPACT_RIGHT_CASE_81
	jne [0x13], 0x6E, PRISON_DRAW_CIN_483_L3
	play id=0x0056, freq=0x14, vol=0x40, channel=0x00
	selectVideoPage 0x00
	video offset=CINEMATIC_452, x=[0x21], y=[0x27]
	selectVideoPage 0xFF
	video offset=CINEMATIC_482, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_483_L3:
	jne [0x13], 0x6F, PRISON_DRAW_CIN_483_L4
	video offset=CINEMATIC_481, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_483_L4:
	jne [0x13], 0x70, PRISON_DRAW_CIN_483_L5
	video offset=CINEMATIC_480, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_483_L5:
	jne [0x13], 0x71, PRISON_DRAW_CIN_483_L6
	video offset=CINEMATIC_479, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_483_L6:
	jne [0x13], 0x72, PRISON_DRAW_CIN_483_L7
	video offset=CINEMATIC_478, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_483_L7:
	jne [0x13], 0x73, PRISON_DRAW_CIN_483_L8
	video offset=CINEMATIC_477, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_483_L8:
	jne [0x13], 0x74, PRISON_DRAW_CIN_483_L9
	video offset=CINEMATIC_476, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_483_L9:
	jne [0x13], 0x75, PRISON_DRAW_CIN_483_L10
	video offset=CINEMATIC_475, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_483_L10:
	jne [0x13], 0x76, PRISON_SHOT_BLAST_FINAL_FRAME_RIGHT
	video offset=CINEMATIC_474, x=[0x21], y=[0x27]
	ret
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_SHOT_BLAST_FINAL_FRAME_RIGHT:
	video offset=CINEMATIC_473, x=[0x21], y=[0x27]
	mov [0x13], 0xFFFE
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_SHOT_IMPACT_RIGHT_CASE_81:
	jne [0x13], 0x81, PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L1
	play id=0x005A, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_472, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L1:
	jne [0x13], 0x82, PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L2
	video offset=CINEMATIC_471, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L2:
	jne [0x13], 0x83, PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L3
	video offset=CINEMATIC_470, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L3:
	jne [0x13], 0x84, PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L4
	video offset=CINEMATIC_469, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L4:
	jne [0x13], 0x85, PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L5
	video offset=CINEMATIC_468, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L5:
	jne [0x13], 0x86, PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L6
	video offset=CINEMATIC_467, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L6:
	jne [0x13], 0x87, PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L7
	video offset=CINEMATIC_466, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L7:
	jne [0x13], 0x88, PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L8
	video offset=CINEMATIC_465, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L8:
	jne [0x13], 0x89, PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L9
	video offset=CINEMATIC_464, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L9:
	ret


PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L10:
	db 0x11

PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L11:
	jge [0x13], 0x64, PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L12
	jle [0x13], 0x03, PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L13
	jle [0x13], 0x05, PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L14
	video offset=CINEMATIC_504, x=[0x21], y=[0x27]
	mov [0x13], 0xFFFE
	ret


PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L14:
	jle [0x13], 0x04, DRAW_CIN_502
	video offset=CINEMATIC_503, x=[0x21], y=[0x27]
	ret
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_502:
	video offset=CINEMATIC_502, x=[0x21], y=[0x27]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L13:
	jle [0x13], 0x02, PRISON_DRAW_CIN_502_L0
	video offset=CINEMATIC_501, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_502_L0:
	jle [0x13], 0x01, DRAW_CIN_499
	video offset=CINEMATIC_500, x=[0x21], y=[0x27]
	ret
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_499:
	video offset=CINEMATIC_499, x=[0x21], y=[0x27]
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN473_AT_X21_Y27_ZOOM_40_L12:
	jge [0x13], 0xC8, PRISON_DRAW_CIN_499_L0
	je [0x13], 0x64, PRISON_SUPERBLAST_ADVANCE_LEFT_CASE_64
	je [0x13], 0x65, PRISON_SUPERBLAST_SWEEP_LEFT_CASE_65
	jge [0x13], 0x81, PRISON_SHOT_IMPACT_LEFT_CASE_81
	jne [0x13], 0x6E, PRISON_DRAW_CIN_499_L4
	play id=0x0056, freq=0x14, vol=0x40, channel=0x00
	selectVideoPage 0x00
	video offset=CINEMATIC_452, x=[0x21], y=[0x27]
	selectVideoPage 0xFF
	video offset=CINEMATIC_498, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_499_L4:
	jne [0x13], 0x6F, PRISON_DRAW_CIN_499_L5
	video offset=CINEMATIC_497, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_499_L5:
	jne [0x13], 0x70, PRISON_DRAW_CIN_499_L6
	video offset=CINEMATIC_496, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_499_L6:
	jne [0x13], 0x71, PRISON_DRAW_CIN_499_L7
	video offset=CINEMATIC_495, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_499_L7:
	jne [0x13], 0x72, PRISON_DRAW_CIN_499_L8
	video offset=CINEMATIC_494, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_499_L8:
	jne [0x13], 0x73, PRISON_DRAW_CIN_499_L9
	video offset=CINEMATIC_493, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_499_L9:
	jne [0x13], 0x74, PRISON_DRAW_CIN_499_L10
	video offset=CINEMATIC_492, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_499_L10:
	jne [0x13], 0x75, PRISON_DRAW_CIN_499_L11
	video offset=CINEMATIC_491, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_499_L11:
	jne [0x13], 0x76, PRISON_SHOT_BLAST_FINAL_FRAME_LEFT
	video offset=CINEMATIC_490, x=[0x21], y=[0x27]
	ret
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_SHOT_BLAST_FINAL_FRAME_LEFT:
	video offset=CINEMATIC_489, x=[0x21], y=[0x27]
	mov [0x13], 0xFFFE
	ret


.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_CIN489_AT_X21_Y27_ZOOM_40.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CIN489_AT_X21_Y27_ZOOM_40.inc"
.endif

.include "../_helpers/MASK_VAR11_NOSIGN_INCR_VAR21_BY_14.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14.inc"
.endif

.include "../_helpers/INLINE_ADD_VAR2C_BY_1.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
PRISON_INLINE_ADD_VAR2C_BY_1_L0:
	jl [0x2C], 0x70, PRISON_INLINE_ADD_VAR2C_BY_1_L1
	video offset=CINEMATIC_462, x=[0x2b], y=[0x27]
	sub [0x2C], 0x0070
	add [0x2B], 0x0070
	jmp PRISON_INLINE_ADD_VAR2C_BY_1_L0

PRISON_INLINE_ADD_VAR2C_BY_1_L1:
	jl [0x2C], 0x30, PRISON_INLINE_ADD_VAR2C_BY_1_L2
	video offset=CINEMATIC_461, x=[0x2b], y=[0x27]
	sub [0x2C], 0x0030
	add [0x2B], 0x0030
	jmp PRISON_INLINE_ADD_VAR2C_BY_1_L0

PRISON_INLINE_ADD_VAR2C_BY_1_L2:
	jl [0x2C], 0x10, PRISON_INLINE_ADD_VAR2C_BY_1_L3
	video offset=CINEMATIC_460, x=[0x2b], y=[0x27]
	sub [0x2C], 0x0010
	add [0x2B], 0x0010
	jmp PRISON_INLINE_ADD_VAR2C_BY_1_L0

PRISON_INLINE_ADD_VAR2C_BY_1_L3:
	ret


PRISON_INLINE_ADD_VAR2C_BY_1_L4:
	db 0x05

PRISON_INLINE_ADD_VAR2C_BY_1_L5:
	jg [0x27], [0x44], COPY_VAR40_TO_VAR27
	mov [0x27], [0x44]
	ret
.endif

.include "../_helpers/COPY_VAR40_TO_VAR27.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
PRISON_COPY_VAR40_TO_VAR27_L0:
	db 0x11

PRISON_COPY_VAR40_TO_VAR27_L1:
	jne [0x1D], 0x14, PRISON_COPY_VAR40_TO_VAR27_L2
	mov [0x11], [0xA1]
	ret


PRISON_COPY_VAR40_TO_VAR27_L2:
	jne [0x1D], 0x15, PRISON_COPY_VAR40_TO_VAR27_L3
	mov [0x11], [0xA4]
	ret


PRISON_COPY_VAR40_TO_VAR27_L3:
	jne [0x1D], 0x16, PRISON_COPY_VAR40_TO_VAR27_L4
	mov [0x11], [0xA7]
	ret


PRISON_COPY_VAR40_TO_VAR27_L4:
	jne [0x1D], 0x17, COPY_VARAD_TO_VAR11
	mov [0x11], [0xAA]
	ret
.endif

.include "../_helpers/COPY_VARAD_TO_VAR11.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
PRISON_COPY_VARAD_TO_VAR11_L0:
	db 0x11

PRISON_COPY_VARAD_TO_VAR11_L1:
	jne [0x1D], 0x14, PRISON_COPY_VARAD_TO_VAR11_L2
	mov [0xA1], [0x11]
	ret


PRISON_COPY_VARAD_TO_VAR11_L2:
	jne [0x1D], 0x15, PRISON_COPY_VARAD_TO_VAR11_L3
	mov [0xA4], [0x11]
	ret


PRISON_COPY_VARAD_TO_VAR11_L3:
	jne [0x1D], 0x16, PRISON_COPY_VARAD_TO_VAR11_L4
	mov [0xA7], [0x11]
	ret


PRISON_COPY_VARAD_TO_VAR11_L4:
	jne [0x1D], 0x17, COPY_VAR11_TO_VARAD
	mov [0xAA], [0x11]
	ret
.endif

.include "../_helpers/COPY_VAR11_TO_VARAD.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_COPY_VAR11_TO_VARAD.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_COPY_VAR11_TO_VARAD.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_COPY_VAR11_TO_VARAD.inc"
.endif

.include "../_helpers/DECREMENT_VAR22.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DECREMENT_VAR22.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DECREMENT_VAR22.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DECREMENT_VAR22.inc"
.endif

.include "../_helpers/DEDUP_CAVES_5B_003.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_PRISON_5B_031.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_PRISON_5B_031.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_PRISON_5B_031.inc"
.endif

DEDUP_CAVES_5B_003__PRISON_INLINE_SETTERS_AND_INIT:
	mov [0x0F], 0x0000
	killChannel

.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
PRISON_DEDUP_PRISON_5B_032_L0:
	call PRISON_DEDUP_PRISON_5B_032_L1
	jg [0x22], [0x21], COMPUTE_VARF8_AS_VAR22_MINUS_VAR09
	mov [0xF8], [0x09]
	sub [0xF8], [0x22]
	jmp PRISON_DEDUP_PRISON_5B_032_L2
.endif

.include "../_helpers/COMPUTE_VARF8_AS_VAR22_MINUS_VAR09.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_COMPUTE_VARF8_AS_VAR22_MINUS_VAR09.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_COMPUTE_VARF8_AS_VAR22_MINUS_VAR09.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_COMPUTE_VARF8_AS_VAR22_MINUS_VAR09.inc"
.endif

TOGGLE_SIGN_VAR26_INIT_VAR25_FROM_VAR44:
	sub [0x26], 0x8000
	mov [0x25], [0x44]

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_TOGGLE_SIGN_VAR26_INIT_VAR25_FROM_VAR44.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_TOGGLE_SIGN_VAR26_INIT_VAR25_FROM_VAR44.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_TOGGLE_SIGN_VAR26_INIT_VAR25_FROM_VAR44.inc"
.endif

.include "../_helpers/DEDUP_CAVES_6B_001.inc"
.include "../_helpers/SHARED_RET.inc"
.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
PRISON_TRIVIAL_RET_L0:
	je [0x0F], 0x00, PRISON_TRIVIAL_RET_L1
	mov [0x2A], 0x002A
	je [0x28], [HERO_X], PRISON_TRIVIAL_RET_L1

PRISON_TRIVIAL_RET_L1:
	je [0x32], 0x00, HANDLE_HORIZ_VAR01_VS_VAR28
	mov [0x28], [HERO_X]
	ret


HANDLE_HORIZ_VAR01_VS_VAR28:
	call PRISON_TRIVIAL_RET_L2
	mov [0x22], [HERO_X]
	jl [HERO_X], [0x28], PRISON_HERO_MOVE_CLAMP_LEFT
	jl [HERO_X], [0x28], PRISON_HERO_MOVE_CLAMP_RIGHT
	mov [0x21], [0x04]
	and [0x21], 0x0010
	je [0x21], 0x00, PRISON_HERO_MOVE_CLAMP_LEFT

PRISON_HERO_MOVE_CLAMP_RIGHT:
	mov [0x21], [0x28]
	add [0x22], [0x2A]
	call PRISON_TRIVIAL_RET_L5
	sub [0x22], [0x2A]
	jge [0x22], [HERO_X], COPY_VAR01_TO_VAR28
	mov [HERO_X], [0x22]
	mov [0x28], [HERO_X]
	ret
.endif

.include "../_helpers/COPY_VAR01_TO_VAR28.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_COPY_VAR01_TO_VAR28.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_COPY_VAR01_TO_VAR28.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_COPY_VAR01_TO_VAR28.inc"
.endif

DEDUP_CAVES_6B_001:
	mov [0x22], [0x24]
	mov [0x1D], [0x1C]

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_PRISON_6B_002.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
FOLD_BODY_104B_22B91458:
	ret


	mov [0xF8], 0x0000
	mov [0x21], 0x0010
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_FOLD_BODY_104B_22B91458.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_FOLD_BODY_104B_22B91458.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_SEQ_085_085_086:
	video offset=CINEMATIC_085, x=132, y=39
	video offset=CINEMATIC_085, x=297, y=39
	video offset=CINEMATIC_086, x=132, y=39
	video offset=CINEMATIC_086, x=297, y=39
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_SEQ_085_085_086_L0:
	db 0x11
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_305_TO_309_5F_AT_AACB4DF5:
	fill page=0x00, color=0x03
	video offset=CINEMATIC_305, x=160, y=100
	video offset=CINEMATIC_306, x=160, y=100
	video offset=CINEMATIC_307, x=160, y=100
	video offset=CINEMATIC_308, x=160, y=100
	video offset=CINEMATIC_309, x=160, y=100
	ret


.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_305_TO_333_7F_AT_96C7E6A8:
	fill page=0x00, color=0x03
	video offset=CINEMATIC_305, x=160, y=100
	video offset=CINEMATIC_328, x=160, y=100
	video offset=CINEMATIC_329, x=160, y=100
	video offset=CINEMATIC_330, x=160, y=100
	video offset=CINEMATIC_331, x=160, y=100
	video offset=CINEMATIC_332, x=160, y=100
	video offset=CINEMATIC_333, x=160, y=100
	ret


.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_CIN_305_TO_333_7F_AT_96C7E6A8.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CIN_305_TO_333_7F_AT_96C7E6A8.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
FILL_AND_DRAW_CIN_24_28:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_024, x=160, y=100
	video offset=CINEMATIC_025, x=160, y=100
	video offset=CINEMATIC_026, x=160, y=100
	video offset=CINEMATIC_027, x=160, y=100
	video offset=CINEMATIC_028, x=160, y=100
	video offset=CINEMATIC_029, x=160, y=400
	video offset=CINEMATIC_030, x=160, y=100
	video offset=CINEMATIC_031, x=160, y=100
	video offset=CINEMATIC_032, x=160, y=100
	video offset=CINEMATIC_033, x=160, y=100
	video offset=CINEMATIC_034, x=160, y=100
	ret


.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_FILL_AND_DRAW_CIN_24_28_L0:
	video offset=CINEMATIC_596, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_597, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_598, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_599, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_600, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_601, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_602, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_603, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_604, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_605, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_606, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_607, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_608, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_609, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_610, x=[BUDDY_X], y=[BUDDY_Y]
	setup channel=0x22, address=DRAW_CIN_229_TO_632_2F_AT_1C4A817A
	break
	video offset=CINEMATIC_611, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_612, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_613, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_614, x=[BUDDY_X], y=[BUDDY_Y]
	setup channel=0x22, address=KILL_CHANNEL_LANDING
	break
	video offset=CINEMATIC_342, x=[BUDDY_X], y=[BUDDY_Y]
	break
	setup channel=0x08, address=DRAW_CIN_628_TO_625_4F_AT_2F47D6D0
	video offset=CINEMATIC_615, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_616, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_617, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_618, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_619, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_620, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_621, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_622, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_623, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_622, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_620, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_618, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_620, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_622, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_622, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_618, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_616, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_616, x=[BUDDY_X], y=[BUDDY_Y]
	setup channel=0x21, address=PRISON_FILL_AND_DRAW_CIN_24_28_L1
	setup channel=0x22, address=PRISON_FILL_AND_DRAW_CIN_24_28_L2
	setup channel=0x24, address=PRISON_FILL_AND_DRAW_CIN_24_28_L3
	mov [HACK_VAR_67], 0x0001
	mov [0x68], 0x0118
	mov [0x69], 0x00B6
	mov [0x6A], 0x0001
	mov [0x6B], 0x2000
	mov [0x6D], 0x0011
	break
	video offset=CINEMATIC_616, x=[BUDDY_X], y=[BUDDY_Y]
	setup channel=0x08, address=DRAW_CIN_624_TO_628_5F_AT_499AFE0A
	killChannel
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_624_TO_628_5F_AT_499AFE0A:
	video offset=CINEMATIC_624, x=160, y=100
	break
	video offset=CINEMATIC_625, x=160, y=100
	break
	video offset=CINEMATIC_626, x=160, y=100
	break
	video offset=CINEMATIC_627, x=160, y=100
	break
	video offset=CINEMATIC_628, x=160, y=100
	killChannel
.endif


.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_628_TO_625_4F_AT_2F47D6D0:
	video offset=CINEMATIC_628, x=160, y=100
	break
	video offset=CINEMATIC_627, x=160, y=100
	break
	video offset=CINEMATIC_626, x=160, y=100
	break
	video offset=CINEMATIC_625, x=160, y=100
	break
.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_CIN_628_TO_625_4F_AT_2F47D6D0.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CIN_628_TO_625_4F_AT_2F47D6D0.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_229_TO_632_2F_AT_1C4A817A:
	video offset=CINEMATIC_229, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_632, x=[BUDDY_X], y=[BUDDY_Y]
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
PRISON_DRAW_CIN_229_TO_632_2F_AT_1C4A817A_L0:
	break
	video offset=CINEMATIC_237, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_632, x=[BUDDY_X], y=[BUDDY_Y]
	jmp PRISON_DRAW_CIN_229_TO_632_2F_AT_1C4A817A_L0
PRISON_DRAW_CIN_229_TO_632_2F_AT_1C4A817A_L1:
	db 0x11
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
DRAW_CIN_683_TO_685_3F_AT_1EB7324B:
	setPalette 0x0B
	selectVideoPage 0x00
	fill page=0x00, color=0x04
	video offset=CINEMATIC_683, x=160, y=100
	video offset=CINEMATIC_684, x=160, y=100
	video offset=CINEMATIC_685, x=160, y=100
	copyVideoPage src=0x00, dst=0xFF
	selectVideoPage 0xFF
	mov [0x1A], 0x00A0
	mov [0x1B], 0x0064
	mov [0x15], 0x0000
	mov [0x14], 0x0007
.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DRAW_CIN_683_TO_685_3F_AT_1EB7324B.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DRAW_CIN_683_TO_685_3F_AT_1EB7324B.inc"
.endif

