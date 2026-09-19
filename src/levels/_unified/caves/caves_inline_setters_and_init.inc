DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29:
	mov [0xF8], [0xB1]
	and [0xF8], 0x0005
	mov [0xF5], [0xB2]
	and [0xF5], 0x0002
	add [0xF8], [0xF5]
	add [0xF8], 0x0029

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DERIVE_VARF8_FROM_VARB1_LO5_VARB2_LO2_PLUS_29.inc"
.endif

CAVES_ACCESS_CODE_INDEX_LOAD:
	mov [0xF8], [0x00]
	ret


CAVES_ACCESS_CODE_INDEX_COMMIT:
	mov [0x00], [0xF8]
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_COPY_VARF8_TO_VAR00.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_COPY_VARF8_TO_VAR00.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_COPY_VARF8_TO_VAR00.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
INLINE_SET_VARE6_TO_3:
	mov [0xE6], 0x0003
.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_SET_VARE6_TO_3.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_SET_VARE6_TO_3.inc"
.endif

.if BRANCH in ("chahi_amiga_1991", "dos_1992")
INIT_VARS_E6_E7_E8:
	mov [0xE6], 0x0008
	mov [0xE7], 0x0050
	mov [0xE8], 0x00AA
.endif

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VARS_E6_E7_E8.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_E6_E7_E8.inc"
.endif

INIT_VARS_E6_E7_E8_E8_PLUS3:
	mov [0xE6], 0x0063
	mov [0xE7], 0x0000
	mov [0xE8], 0x010F
	mov [0xE8], 0x0000
	mov [0xF1], 0x0090
	mov [0xF0], 0x0019
	mov [0xEE], 0x0046

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VARS_E6_E7_E8_E8_PLUS3.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_E6_E7_E8_E8_PLUS3.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_E6_E7_E8_E8_PLUS3.inc"
.endif

CAVES_AMBIENT_DRIFT_ENTRY_INIT:
	mov [0x6D], 0x000E
	mov [0x71], 0xFFFF
	mov [0x70], 0x0009

.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_5:
	break
	add [0x6E], 0x0871
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x00E3
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	add [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_5
	mov [0x70], 0x0002

CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_6:
	break
	add [0x6E], 0x0780
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x0980
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	add [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_6
	mov [0x70], 0x0009

CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_7:
	break
	add [0x6E], 0x03E3
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x0C00
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	add [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_7
	mov [0x70], 0x0001

CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_8:
	break
	add [0x6E], 0x0F00
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x0E00
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	add [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_8
	mov [0x70], 0x0002

CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_9:
	break
	add [0x6E], 0x0D80
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x0180
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_9
	mov [0x70], 0x0006

CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_10:
	break
	add [0x6E], 0x04AA
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x082A
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_10
	mov [0x70], 0x0008

CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_11:
	break
	add [0x6E], 0x08A0
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x02A0
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_11
	mov [0x70], 0x0007

CAVES_INIT_VARS_6D_71_70_L7:
	break
	add [0x6E], 0x0292
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x0292
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_INIT_VARS_6D_71_70_L7
	mov [0x71], 0x0001
	mov [0x70], 0x0001

CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_13:
	break
	add [0x6E], 0x0800
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	add [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x0800
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_13
	mov [0x70], 0x0009

CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_14:
	break
	add [0x6E], 0x0D8E
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	add [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x01E3
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	add [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_14
	mov [0x70], 0x0003

CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_15:
	break
	add [0x6E], 0x0F55
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	add [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x0400
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_15
	mov [0x70], 0x0003

CAVES_INIT_VARS_6D_71_70_L11:
	break
	add [0x6E], 0x07AA
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	add [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x0A00
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_INIT_VARS_6D_71_70_L11
	mov [0x71], 0xFFFF
	mov [0x70], 0x0007

CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_17:
	break
	add [0x6E], 0x00B6
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x02B6
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_17
	mov [0x70], 0x0007

CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_18:
	break
	add [0x6E], 0x0624
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x01B6
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_18
	mov [0x70], 0x0007

CAVES_INIT_VARS_6D_71_70_L14:
	break
	add [0x6E], 0x0CB6
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x0524
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	add [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_INIT_VARS_6D_71_70_L14
	or [0xB1], 0x00C0
	jne [SCREEN_NUM], 0xC8, INLINE_SET_VAR70_TO_8
	setup channel=0x23, address=CAVES_INIT_VARS_6D_71_70_L15
	setup channel=0x24, address=CAVES_INIT_VARS_6D_71_70_L16
.endif

INLINE_SET_VAR70_TO_8:
	mov [0x70], 0x0008

.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_INLINE_SET_VAR70_TO_8_L0:
	sub [0x6B], 0x0002
	break
	djnz [0x70], CAVES_INLINE_SET_VAR70_TO_8_L0
	mov [0x71], 0x0064
	mov [0x6D], 0xFFFE
	killChannel
.endif

CAVES_AMBIENT_DRIFT_PERCH_WAIT_INIT:
	mov [0x71], 0x0064
	mov [0x6C], 0x00B1
	mov [0x6D], 0x0006

.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_INIT_VARS_71_6C_6D_L0:
	break
	call CAVES_INIT_VARS_71_6C_6D_L1
	jg [HERO_Y], 0x48, CAVES_INIT_VARS_71_6C_6D_L0
	je [0x21], 0x00, CAVES_INIT_VARS_71_6C_6D_L0
	or [0xB1], 0x0040
	mov [0x71], 0xFFFF
	mov [0x70], 0x0004

CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_1:
	break
	add [0x6E], 0x0740
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x04C0
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	add [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_1
	mov [0x70], 0x0009

CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_2:
	break
	add [0x6E], 0x08AA
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x01E3
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	add [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_2
	mov [0x70], 0x0001

CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_3:
	break
	add [0x6E], 0x1100
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x0300
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_AMBIENT_DRIFT_PATH_HERO_HIGH_PHASE_3
	mov [0x70], 0x0006

CAVES_INIT_VARS_71_6C_6D_L5:
	break
	add [0x6E], 0x0A66
	mov [0xF8], [0x6E]
	shr [0xF8], 0x0008
	sub [0x6C], [0xF8]
	and [0x6E], 0x00FF
	add [0x6F], 0x06CC
	mov [0xF8], [0x6F]
	shr [0xF8], 0x0008
	sub [0x6D], [0xF8]
	and [0x6F], 0x00FF
	djnz [0x70], CAVES_INIT_VARS_71_6C_6D_L5
	jmp CAVES_INIT_VARS_71_6C_6D_L6
.endif

INIT_VARS_6C_6D_71_70:
	mov [0x6C], 0x00B1
	mov [0x6D], 0x0006
	mov [0x71], 0x0064
	mov [0x70], 0x001E

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VARS_6C_6D_71_70.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_6C_6D_71_70.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_6C_6D_71_70.inc"
.endif

INIT_VARS_E6_E7_2:
	mov [0xE6], 0x011D
	mov [0xE7], 0x000A

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VARS_E6_E7_2.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_E6_E7_2.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_E6_E7_2.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_E6_E7_1:
	mov [0xE6], 0x004E
	mov [0xE7], 0x000A
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_E6_E7_1.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_E6_E7_1.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_E6_E9_E8:
	mov [0xE6], 0x006C
	mov [0xE9], 0xFFFF
	mov [0xE8], 0x0014
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_E6_E9_E8.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_E6_E9_E8.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_E6_E7_E9_E8:
	mov [0xE6], 0x0064
	mov [0xE7], 0x0038
	mov [0xE9], 0x0001
	mov [0xE8], 0x0014
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_E6_E7_E9_E8.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_E6_E7_E9_E8.inc"
.endif

INIT_VARS_0E_29:
	mov [0x0E], 0x0007
	mov [0x29], 0x0005

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VARS_0E_29.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_0E_29.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_0E_29.inc"
.endif

INIT_VARS_EE_EF:
	mov [0xEE], 0x00FA
	mov [0xEF], 0x0005

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INIT_VARS_EE_EF.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_EE_EF.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_EE_EF.inc"
.endif

INLINE_SET_VAREF_TO_5:
	mov [0xEF], 0x0005

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_SET_VAREF_TO_5.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_SET_VAREF_TO_5.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_SET_VAREF_TO_5.inc"
.endif

INLINE_SET_VAR68_TO_32:
	mov [0x68], 0x0032

.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_INLINE_SET_VAR68_TO_32_L0:
	add [0x69], 0x0008
	mov [0x21], [0x69]
	call CAVES_INLINE_SET_VAR68_TO_32_L1
	break
	djnz [0x68], CAVES_INLINE_SET_VAR68_TO_32_L0
	mov [0x68], 0x0032

CAVES_INLINE_SET_VAR68_TO_32_L2:
	sub [0x69], 0x0008
	mov [0x21], [0x69]
	call CAVES_INLINE_SET_VAR68_TO_32_L1
	break
	djnz [0x68], CAVES_INLINE_SET_VAR68_TO_32_L2
	jmp INLINE_SET_VAR68_TO_32
.endif

INLINE_SET_VAR6A_TO_2F:
	mov [0x6A], 0x002F

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_SET_VAR6A_TO_2F.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_SET_VAR6A_TO_2F.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_SET_VAR6A_TO_2F.inc"
.endif

INLINE_SET_VAR01_TO_E:
	mov [HERO_X], 0x000E

.if BRANCH in ("chahi_amiga_1991", "cartridge_1992", "dos_1992")
CAVES_INLINE_SET_VAR01_TO_E_L0:
	add [0xE8], 0x0005
	sub [0xE9], 0x001E
	add [0xEA], 0x000C
	sub [0xEB], 0x000F
	add [0xEC], 0x0009
	sub [0xED], 0x0014
	add [0xEE], 0x000F
	sub [0xEF], 0x000C
	break
	djnz [HERO_X], CAVES_INLINE_SET_VAR01_TO_E_L0
	setup channel=0x13, address=KILL_CHANNEL_LANDING
	mov [0x03], 0x0005
	setup channel=0x3F, address=CAVES_INLINE_SET_VAR01_TO_E_L1
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	killChannel

CAVES_INLINE_SET_VAR01_TO_E_L2:
	video offset=CINEMATIC_008, x=160, y=[0xe7]
	break
	setPalette 0x0D
	play id=0x0052, freq=0x0A, vol=0x40, channel=0x02
	video offset=CINEMATIC_009, x=160, y=[0xe7]
	break
	setPalette 0x08
	video offset=CINEMATIC_010, x=160, y=[0xe7]
	break
	video offset=CINEMATIC_011, x=160, y=[0xe7]
	killChannel

CAVES_INLINE_SET_VAR01_TO_E_L3:
	video offset=CINEMATIC_008, x=160, y=[0xe8]
	break
	play id=0x0052, freq=0x14, vol=0x40, channel=0x02
	video offset=CINEMATIC_009, x=160, y=[0xe8]
	break
	video offset=CINEMATIC_010, x=160, y=[0xe8]
	break
	video offset=CINEMATIC_011, x=160, y=[0xe8]
	killChannel

HANG_DRAW_CIN_012:
	video offset=CINEMATIC_012, x=160, y=100
	break
	jmp HANG_DRAW_CIN_012
CAVES_INLINE_SET_VAR01_TO_E_L4:
	db 0x11
.endif

INLINE_SET_VARE6_TO_1E:
	mov [0xE6], 0x001E

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_SET_VARE6_TO_1E.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_SET_VARE6_TO_1E.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_SET_VARE6_TO_1E.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INIT_VARS_E8_E6:
	mov [0xE8], 0x0050
	mov [0xE6], 0x0000
.endif

.if BRANCH == "cartridge_1992"
.include "cart__post_INIT_VARS_E8_E6.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INIT_VARS_E8_E6.inc"
.endif

