DEDUP_CAVES_5B_007_001:
	sub [BUDDY_Y], 0x0001
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_PRISON_5B_015.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_PRISON_5B_015.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_PRISON_5B_015.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/INLINE_DRAW_CV_255_010.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_INLINE_DRAW_CV_255_010_L0:
	ret


PRISON_INLINE_DRAW_CV_255_010_L1:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x1C, vol=0x0A, channel=0x01
	sub [BUDDY_Y], 0x0001
	call DRAW_PRISON_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_250, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_256, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, INLINE_DRAW_CV_255_010
	call PRISON_INLINE_DRAW_CV_255_010_L2
	jmp DEDUP_CAVES_5B_020
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_255_010:
	video type=0, offset=COMMON_VIDEO_255, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
.endif


DEDUP_CAVES_5B_020:
	add [BUDDY_Y], 0x0001
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_PRISON_5B_007.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_PRISON_5B_007.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_PRISON_5B_007.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_252_018:
	video type=0, offset=COMMON_VIDEO_252, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_INLINE_DRAW_CV_252_019_L0:
	ret


PRISON_INLINE_DRAW_CV_252_019_L1:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [BUDDY_Y], 0x0001
	call DRAW_PRISON_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_247, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_258, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, DRAW_CV259_AT_X07_Y08
	call PRISON_INLINE_DRAW_CV_252_019_L2
	jmp DEDUP_CAVES_5B_007_002
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV259_AT_X07_Y08.inc"
.endif


DEDUP_CAVES_5B_007_002:
	sub [BUDDY_Y], 0x0001
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_PRISON_5B_016.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_PRISON_5B_016.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_PRISON_5B_016.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV261_AT_X07_Y08.inc"
.endif


DEDUP_CAVES_5B_007_003:
	sub [BUDDY_Y], 0x0001
	ret


.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DEDUP_PRISON_5B_017.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DEDUP_PRISON_5B_017.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DEDUP_PRISON_5B_017.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
INLINE_DRAW_CV_243_012:
	video type=0, offset=COMMON_VIDEO_243, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
.endif


.include "../_helpers/INCREMENT_VAR07_BY_1.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INCREMENT_VAR07_BY_1.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INCREMENT_VAR07_BY_1.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INCREMENT_VAR07_BY_1.inc"
.endif

; Cellmate (BUDDY) animation frame draws CIN_157..169 — split out for clarity (see buddy_animation_frames/cellmate_cin_157_169.inc).
.include "buddy_animation_frames/cellmate_cin_157_169.inc"

.include "../_helpers/DECREMENT_VAR08_BY_D.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_DECREMENT_VAR08_BY_D.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_DECREMENT_VAR08_BY_D.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_DECREMENT_VAR08_BY_D.inc"
.endif

KILL_CHANNEL_LANDING_002:
	killChannel

.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_KILL_041.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_KILL_041.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_KILL_041.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV_074:
	video type=0, offset=0x0020, x=[0x01], y=[0x02], zoom=0x40
	ret
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_074_L0:
	je [0x0A], 0x00, DRAW_CV_075
	call GUARDED_DRAW_CV_126
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_075.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_075_L0:
	je [0x0A], 0x00, DRAW_CV_076
	call GUARDED_DRAW_CV_126
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_076.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_076_L0:
	je [0x0A], 0x00, DRAW_CV_077
	call GUARDED_DRAW_CV_126
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_077.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_077_L0:
	je [0x0A], 0x00, DRAW_CV_078
	call GUARDED_DRAW_CV_126
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV_078:
	video type=0, offset=COMMON_VIDEO_078, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_078_L0:
	jne [0x0A], 0x00, PRISON_DRAW_CV_078_L1
	video type=0, offset=COMMON_VIDEO_079, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_080

PRISON_DRAW_CV_078_L1:
	call GUARDED_DRAW_CV_126
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_080.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_080_L0:
	jne [0x0A], 0x00, PRISON_DRAW_CV_080_L1
	video type=0, offset=COMMON_VIDEO_001, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp PRISON_DRAW_CV_080_L2

PRISON_DRAW_CV_080_L1:
	call GUARDED_DRAW_CV_126

PRISON_DRAW_CV_080_L2:
	call PRISON_DRAW_CV_071_L1
	video type=0, offset=COMMON_VIDEO_002, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_DRAW_CV_080_L3:
	jne [0x0A], 0x00, PRISON_DRAW_CV_080_L4
	video type=0, offset=COMMON_VIDEO_060, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_061

PRISON_DRAW_CV_080_L4:
	call GUARDED_DRAW_CV_126
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_061.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_061_L0:
	jne [0x0A], 0x00, PRISON_DRAW_CV_061_L1
	video type=0, offset=COMMON_VIDEO_062, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_063

PRISON_DRAW_CV_061_L1:
	call GUARDED_DRAW_CV_126
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_063.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_063_L0:
	jne [0x0A], 0x00, PRISON_DRAW_CV_063_L1
	video type=0, offset=COMMON_VIDEO_064, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_065

PRISON_DRAW_CV_063_L1:
	call GUARDED_DRAW_CV_126
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_065.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_065_L0:
	jne [0x0A], 0x00, PRISON_DRAW_CV_065_L1
	video type=0, offset=COMMON_VIDEO_066, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_067

PRISON_DRAW_CV_065_L1:
	call GUARDED_DRAW_CV_126
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_067.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_067_L0:
	jne [0x0A], 0x00, PRISON_DRAW_CV_067_L1
	video type=0, offset=COMMON_VIDEO_068, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_069

PRISON_DRAW_CV_067_L1:
	call GUARDED_DRAW_CV_126
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_069.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_069_L0:
	je [0x0A], 0x00, DRAW_CV_070
	call GUARDED_DRAW_CV_126
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV_070:
	video type=0, offset=COMMON_VIDEO_070, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_070_L0:
	je [0x0A], 0x00, DRAW_CV_071
	call GUARDED_DRAW_CV_126
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_071.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_071_L0:
	call PRISON_DRAW_CV_071_L1
	je [0x0A], 0x00, DRAW_CV_072
	call GUARDED_DRAW_CV_126
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_072.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_072_L0:
	je [0x0A], 0x00, DRAW_CV_073
	call GUARDED_DRAW_CV_126
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_073.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_300.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_299.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_295.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_296.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_297.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_297_L0:
	video type=0, offset=COMMON_VIDEO_081, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x00
	jne [0x0A], 0x00, DRAW_CV_295
	video type=0, offset=COMMON_VIDEO_082, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_DRAW_CV_297_L1:
	video type=0, offset=COMMON_VIDEO_083, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_296
	video type=0, offset=COMMON_VIDEO_084, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_DRAW_CV_297_L2:
	video type=0, offset=COMMON_VIDEO_116, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_299
	video type=0, offset=COMMON_VIDEO_117, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_DRAW_CV_297_L3:
	video type=0, offset=COMMON_VIDEO_118, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_300
	video type=0, offset=COMMON_VIDEO_119, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_DRAW_CV_297_L4:
	video type=0, offset=COMMON_VIDEO_120, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_300
	video type=0, offset=COMMON_VIDEO_121, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_DRAW_CV_297_L5:
	video type=0, offset=COMMON_VIDEO_086, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x00
	jne [0x0A], 0x00, DRAW_CV_295
	video type=0, offset=COMMON_VIDEO_087, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_DRAW_CV_297_L6:
	video type=0, offset=COMMON_VIDEO_088, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_295
	video type=0, offset=COMMON_VIDEO_089, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_DRAW_CV_297_L7:
	video type=0, offset=COMMON_VIDEO_090, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_296
	video type=0, offset=COMMON_VIDEO_091, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_DRAW_CV_297_L8:
	video type=0, offset=COMMON_VIDEO_092, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_297
	video type=0, offset=COMMON_VIDEO_093, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


PRISON_DRAW_CV_297_L9:
	video type=0, offset=COMMON_VIDEO_094, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_297
	video type=0, offset=COMMON_VIDEO_095, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_298.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_298_L0:
	je [0x0A], 0x00, DRAW_CV107_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV108_PLAY_60_F0F_V2A_C0
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV107_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV108_PLAY_60_F0F_V2A_C0:
	video type=0, offset=COMMON_VIDEO_108, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x00
	ret


.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV108_PLAY_60_F0F_V2A_C0_L0:
	je [0x0A], 0x00, DRAW_CV109_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV_110
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV109_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_110.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_110_L0:
	je [0x0A], 0x00, DRAW_CV111_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV_112
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV111_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_112.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_112_L0:
	je [0x0A], 0x00, DRAW_CV113_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV_114
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV113_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_114.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_114_L0:
	je [0x0A], 0x00, DRAW_CV_115
	call DRAW_CV_298
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_115.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_115_L0:
	je [0x0A], 0x00, DRAW_CV097_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV098_PLAY_60_F0F_V2A_C0
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV097_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV098_PLAY_60_F0F_V2A_C0:
	video type=0, offset=COMMON_VIDEO_098, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x00
	ret


.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV098_PLAY_60_F0F_V2A_C0_L0:
	je [0x0A], 0x00, DRAW_CV099_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV_100
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV099_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_100.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_100_L0:
	je [0x0A], 0x00, DRAW_CV101_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV_102
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV101_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_102.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_102_L0:
	je [0x0A], 0x00, DRAW_CV103_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV_104
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV103_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV_104.inc"
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_104_L0:
	je [0x0A], 0x00, DRAW_CV105_AT_X01_Y02
	call DRAW_CV_298
	jmp DRAW_CV_106
.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
.include "../_helpers/DRAW_CV105_AT_X01_Y02.inc"
.endif


.if BRANCH in ("cartridge_1992", "dos_1992")
DRAW_CV_106:
	video type=0, offset=COMMON_VIDEO_106, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


.endif

.if BRANCH in ("cartridge_1992", "dos_1992")
PRISON_DRAW_CV_106_L0:
	je [0x1F], 0x00, PRISON_DRAW_CV_106_L1
	jl [0x1E], 0x00, INLINE_SET_VAR20_TO_1
	mov [0x20], 0xFFFF

PRISON_DRAW_CV_106_L2:
	sub [0x1E], [0x1F]
	add [0x20], 0x0001
	jge [0x1E], 0x00, PRISON_DRAW_CV_106_L2
	ret
.endif

.include "../_helpers/INLINE_SET_VAR20_TO_1.inc"
.if BRANCH == "chahi_amiga_1991"
.include "amiga__post_INLINE_SET_VAR20_TO_1.inc"
.elif BRANCH == "cartridge_1992"
.include "cart__post_INLINE_SET_VAR20_TO_1.inc"
.elif BRANCH == "dos_1992"
.include "dos__post_INLINE_SET_VAR20_TO_1.inc"
.endif

