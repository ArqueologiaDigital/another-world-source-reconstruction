CAVES_FOLD_BODY_94B_9F1D7AF8_L9:
	or [0x04], 0x4000
	mov [0x03], 0x0014
	song id=0x0BDD, delay=0x0000, pos=0x00
	setup channel=0x3F, address=CAVES_INLINE_SET_VAR01_TO_E_L1
	deleteChannels first=0x14, last=0x16
	mov [0x13], 0xFFFF
	mov [0xF8], [0x04]
	and [0xF8], 0x00FF
	play id=0x005D, freq=0x14, vol=0x40, channel=0x01
	jl [0xF8], 0x20, LABEL_68DC
	sub [0xF8], 0x0020
	setup channel=0x14, address=LABEL_4B26
	jl [0xF8], 0x10, SHARED_RET
	setup channel=0x14, address=LABEL_4B41
	ret


LABEL_68DC:
	setup channel=0x14, address=LABEL_4A5B
	jl [0xF8], 0x10, SHARED_RET
	setup channel=0x14, address=LABEL_4A82
	ret


CAVES_FOLD_BODY_94B_9F1D7AF8_L10:
	call LABEL_695F
	mov [0xF8], [0x2B]
	and [0xF8], 0x0800
	jne [0xF8], 0x00, LABEL_6953
	play id=0x005D, freq=0x14, vol=0x40, channel=0x00
	call LABEL_1A89
	mov [0xF8], [0x2B]
	and [0xF8], 0x1000
	jne [0x1D], 0x28, LABEL_691F
	setup channel=0x23, address=LABEL_4C44
	je [0xF8], 0x00, LABEL_6947
	setup channel=0x23, address=LABEL_4C9D

LABEL_691F:
	jne [0x1D], 0x29, LABEL_6933
	setup channel=0x25, address=LABEL_4C44
	je [0xF8], 0x00, LABEL_6947
	setup channel=0x25, address=LABEL_4C9D

LABEL_6933:
	jne [0x1D], 0x2A, LABEL_6947
	setup channel=0x27, address=LABEL_4C44
	je [0xF8], 0x00, LABEL_6947
	setup channel=0x27, address=LABEL_4C9D

LABEL_6947:
	or [0x2B], 0x0800
	call CAVES_LASER_IMPACT_ANIM_LEFT_ABOVE_04
	mov [0x13], 0xFFFF
	ret


LABEL_6953:
	or [0x2B], 0x4000
	call CAVES_LASER_IMPACT_ANIM_LEFT_ABOVE_04
	mov [0x13], 0xFFFF
	ret


LABEL_695F:
	jne [0x1D], 0x28, LABEL_6969
	mov [0x2B], [0x6B]
	ret


LABEL_6969:
	jne [0x1D], 0x29, LABEL_6973
	mov [0x2B], [0x73]
	ret


LABEL_6973:
	jne [0x1D], 0x2A, LABEL_697C
	mov [0x2B], [0x7B]

LABEL_697C:
	ret


LABEL_697D:
	db 0x11

CAVES_LASER_IMPACT_ANIM_LEFT_ABOVE_04:
	jne [0x1D], 0x28, LABEL_6988
	mov [0x6B], [0x2B]
	ret


LABEL_6988:
	jne [0x1D], 0x29, LABEL_6992
	mov [0x73], [0x2B]
	ret


LABEL_6992:
	jne [0x1D], 0x2A, LABEL_699B
	mov [0x7B], [0x2B]

LABEL_699B:
	ret


	killChannel
	video offset=CINEMATIC_884, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	break
	video offset=CINEMATIC_885, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0004
	break
	video offset=CINEMATIC_885, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0003
	break
	video offset=CINEMATIC_886, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0002
	break
	video offset=CINEMATIC_886, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	break
	video offset=CINEMATIC_885, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	mov [0x03], 0x0028

LABEL_69DC:
	break
	video offset=CINEMATIC_887, x=[HERO_X], y=[HERO_Y]
	jmp LABEL_69DC
LABEL_69E5:
	db 0x11

LABEL_69E6:
	mov [0x21], [0x22]
	mov [0x13], 0x0001
	call LABEL_6733
	jne [0x13], 0xFFFF, LABEL_69F8
	ret


LABEL_69F8:
	and [0x13], 0x7FFF
	mov [0x0E], 0x0000
	call CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT
	add [0x13], 0x0001
	or [0x13], 0x8000
	je [0x0E], 0x00, SHARED_RET
	or [0x27], 0x4000
	ret


LABEL_6A16:
	db 0x11

LABEL_6A17:
	mov [0x21], [0x22]
	mov [0x13], 0x0001
	call LABEL_6733
	jne [0x13], 0xFFFF, LABEL_6A2A
	ret


CAVES_LASER_IMPACT_ANIM_LEFT_CASE_75:
	db 0x11

LABEL_6A2A:
	and [0x13], 0x7FFF
	mov [0x0E], 0x0001
	call CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT
	add [0x13], 0x0001
	or [0x13], 0x8000
	je [0x0E], 0x00, SHARED_RET
	or [0x27], 0x4000
	ret


CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT:
	jge [0x13], 0x64, LABEL_6A94
	jle [0x13], 0x03, LABEL_6A76
	jle [0x13], 0x05, LABEL_6A64
	video offset=CINEMATIC_CAVES_LASER_IMPACT_RIGHT_2, x=[0x21], y=[0x27]
	mov [0x13], 0xFFFE
	ret


LABEL_6A64:
	jle [0x13], 0x04, DRAW_CIN_792
	video offset=CINEMATIC_793, x=[0x21], y=[0x27]
	ret


DRAW_CIN_792:
	video offset=CINEMATIC_CAVES_LASER_IMPACT_RIGHT_4, x=[0x21], y=[0x27]
	ret


LABEL_6A76:
	jle [0x13], 0x02, LABEL_6A82
	video offset=CINEMATIC_791, x=[0x21], y=[0x27]
	ret


LABEL_6A82:
	jle [0x13], 0x01, DRAW_CIN_789
	video offset=CINEMATIC_790, x=[0x21], y=[0x27]
	ret


DRAW_CIN_789:
	video offset=CINEMATIC_789, x=[0x21], y=[0x27]
	ret


LABEL_6A94:
	jge [0x13], 0xC8, LABEL_6BA7
	je [0x13], 0x64, LABEL_6D42
	je [0x13], 0x65, LABEL_6D62
	jge [0x13], 0x81, LABEL_6B31
	jne [0x13], 0x6E, LABEL_6AC7
	play id=0x0056, freq=0x14, vol=0x40, channel=0x01
	selectVideoPage 0x00
	video offset=CINEMATIC_227, x=[0x21], y=[0x27]
	selectVideoPage 0xFF
	video offset=CINEMATIC_788, x=[0x21], y=[0x27]
	ret


LABEL_6AC7:
	jne [0x13], 0x6F, LABEL_6AD3
	video offset=CINEMATIC_787, x=[0x21], y=[0x27]
	ret


LABEL_6AD3:
	jne [0x13], 0x70, LABEL_6ADF
	video offset=CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_CASE_70, x=[0x21], y=[0x27]
	ret


LABEL_6ADF:
	jne [0x13], 0x71, LABEL_6AEB
	video offset=CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_CASE_71, x=[0x21], y=[0x27]
	ret


LABEL_6AEB:
	jne [0x13], 0x72, LABEL_6AF7
	video offset=CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_CASE_72, x=[0x21], y=[0x27]
	ret


LABEL_6AF7:
	jne [0x13], 0x73, LABEL_6B03
	video offset=CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_CASE_73, x=[0x21], y=[0x27]
	ret


LABEL_6B03:
	jne [0x13], 0x74, LABEL_6B0F
	video offset=CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_CASE_74, x=[0x21], y=[0x27]
	ret


LABEL_6B0F:
	jne [0x13], 0x75, LABEL_6B1B
	video offset=CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_CASE_75, x=[0x21], y=[0x27]
	ret


LABEL_6B1B:
	jne [0x13], 0x76, LABEL_6B27
	video offset=CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_CASE_76, x=[0x21], y=[0x27]
	ret


LABEL_6B27:
	video offset=CINEMATIC_779, x=[0x21], y=[0x27]
	mov [0x13], 0xFFFE
	ret


LABEL_6B31:
	jne [0x13], 0x81, LABEL_6B43
	play id=0x005A, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_778, x=[0x21], y=[0x27]
	ret


LABEL_6B43:
	jne [0x13], 0x82, LABEL_6B4F
	video offset=CINEMATIC_777, x=[0x21], y=[0x27]
	ret


LABEL_6B4F:
	jne [0x13], 0x83, LABEL_6B5B
	video offset=CINEMATIC_776, x=[0x21], y=[0x27]
	ret


LABEL_6B5B:
	jne [0x13], 0x84, LABEL_6B67
	video offset=CINEMATIC_775, x=[0x21], y=[0x27]
	ret


LABEL_6B67:
	jne [0x13], 0x85, LABEL_6B73
	video offset=CINEMATIC_774, x=[0x21], y=[0x27]
	ret


LABEL_6B73:
	jne [0x13], 0x86, LABEL_6B7F
	video offset=CINEMATIC_773, x=[0x21], y=[0x27]
	ret


LABEL_6B7F:
	jne [0x13], 0x87, LABEL_6B8B
	video offset=CINEMATIC_772, x=[0x21], y=[0x27]
	ret


LABEL_6B8B:
	jne [0x13], 0x88, LABEL_6B97
	video offset=CINEMATIC_CAVES_LASER_IMPACT_RIGHT_0, x=[0x21], y=[0x27]
	ret


LABEL_6B97:
	jne [0x13], 0x89, LABEL_6BA7
	video offset=CINEMATIC_CAVES_LASER_IMPACT_RIGHT_1, x=[0x21], y=[0x27]
	mov [0x13], 0xFFFE
	ret


LABEL_6BA7:
	ret


LABEL_6BA8:
	db 0x11

CAVES_LASER_IMPACT_ANIM_DISPATCH_LEFT:
	jge [0x13], 0x64, LABEL_6BF5
	jle [0x13], 0x03, LABEL_6BD7
	jle [0x13], 0x05, LABEL_6BC5
	video offset=CINEMATIC_836, x=[0x21], y=[0x27]
	mov [0x13], 0xFFFE
	ret


LABEL_6BC5:
	jle [0x13], 0x04, DRAW_CIN_834
	video offset=CINEMATIC_835, x=[0x21], y=[0x27]
	ret


DRAW_CIN_834:
	video offset=CINEMATIC_CAVES_LASER_IMPACT_LEFT_5, x=[0x21], y=[0x27]
	ret


LABEL_6BD7:
	jle [0x13], 0x02, LABEL_6BE3
	video offset=CINEMATIC_833, x=[0x21], y=[0x27]
	ret


LABEL_6BE3:
	jle [0x13], 0x01, DRAW_CIN_831
	video offset=CINEMATIC_832, x=[0x21], y=[0x27]
	ret


DRAW_CIN_831:
	video offset=CINEMATIC_831, x=[0x21], y=[0x27]
	ret


LABEL_6BF5:
	jge [0x13], 0xC8, LABEL_6D08
	je [0x13], 0x64, LABEL_6D0A
	je [0x13], 0x65, LABEL_6D2A
	jge [0x13], 0x81, LABEL_6C92
	jne [0x13], 0x6E, LABEL_6C28
	play id=0x0056, freq=0x14, vol=0x40, channel=0x01
	selectVideoPage 0x00
	video offset=CINEMATIC_227, x=[0x21], y=[0x27]
	selectVideoPage 0xFF
	video offset=CINEMATIC_788, x=[0x21], y=[0x27]
	ret


LABEL_6C28:
	jne [0x13], 0x6F, LABEL_6C34
	video offset=CINEMATIC_CAVES_LASER_BOLT_SPAN_LEFT_3, x=[0x21], y=[0x27]
	ret


LABEL_6C34:
	jne [0x13], 0x70, LABEL_6C40
	video offset=CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_3, x=[0x21], y=[0x27]
	ret


LABEL_6C40:
	jne [0x13], 0x71, LABEL_6C4C
	video offset=CINEMATIC_CAVES_LASER_BOLT_SPAN_LEFT_2, x=[0x21], y=[0x27]
	ret


LABEL_6C4C:
	jne [0x13], 0x72, LABEL_6C58
	video offset=CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_2, x=[0x21], y=[0x27]
	ret


LABEL_6C58:
	jne [0x13], 0x73, LABEL_6C64
	video offset=CINEMATIC_CAVES_LASER_BOLT_SPAN_LEFT_1, x=[0x21], y=[0x27]
	ret


LABEL_6C64:
	jne [0x13], 0x74, LABEL_6C70
	video offset=CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_1, x=[0x21], y=[0x27]
	ret


LABEL_6C70:
	jne [0x13], 0x75, LABEL_6C7C
	video offset=CINEMATIC_CAVES_LASER_BOLT_SPAN_LEFT_0, x=[0x21], y=[0x27]
	ret


LABEL_6C7C:
	jne [0x13], 0x76, LABEL_6C88
	video offset=CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_0, x=[0x21], y=[0x27]
	ret


LABEL_6C88:
	video offset=CINEMATIC_822, x=[0x21], y=[0x27]
	mov [0x13], 0xFFFE
	ret


LABEL_6C92:
	jne [0x13], 0x81, LABEL_6CA4
	play id=0x005A, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_778, x=[0x21], y=[0x27]
	ret


LABEL_6CA4:
	jne [0x13], 0x82, LABEL_6CB0
	video offset=CINEMATIC_777, x=[0x21], y=[0x27]
	ret


LABEL_6CB0:
	jne [0x13], 0x83, LABEL_6CBC
	video offset=CINEMATIC_776, x=[0x21], y=[0x27]
	ret


LABEL_6CBC:
	jne [0x13], 0x84, LABEL_6CC8
	video offset=CINEMATIC_775, x=[0x21], y=[0x27]
	ret


LABEL_6CC8:
	jne [0x13], 0x85, LABEL_6CD4
	video offset=CINEMATIC_774, x=[0x21], y=[0x27]
	ret


LABEL_6CD4:
	jne [0x13], 0x86, LABEL_6CE0
	video offset=CINEMATIC_773, x=[0x21], y=[0x27]
	ret


LABEL_6CE0:
	jne [0x13], 0x87, LABEL_6CEC
	video offset=CINEMATIC_772, x=[0x21], y=[0x27]
	ret


LABEL_6CEC:
	jne [0x13], 0x88, LABEL_6CF8
	video offset=CINEMATIC_CAVES_LASER_IMPACT_RIGHT_0, x=[0x21], y=[0x27]
	ret


LABEL_6CF8:
	jne [0x13], 0x89, LABEL_6D08
	video offset=CINEMATIC_CAVES_LASER_IMPACT_RIGHT_1, x=[0x21], y=[0x27]
	mov [0x13], 0xFFFE
	ret


LABEL_6D08:
	ret


LABEL_6D09:
	db 0x11

LABEL_6D0A:
	mov [0x22], [0x21]
	sub [0x22], 0x0064
	mov [0x09], [0x22]
	call CAVES_DEDUP_CAVES_5B_004_L0
	call CAVES_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14_L9
	mov [0x2C], 0x0001
	jne [0x1D], 0x00, LABEL_6D7A
	video offset=CINEMATIC_769, x=[0x22], y=[0x27]
	ret


LABEL_6D2A:
	mov [0x22], [0x21]
	sub [0x22], 0x0140
	mov [0x09], [0x22]
	call CAVES_DEDUP_CAVES_5B_004_L0
	call CAVES_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14_L9
	mov [0x2C], 0x0001
	jmp LABEL_6D7A
LABEL_6D41:
	db 0x11

LABEL_6D42:
	mov [0x22], [0x21]
	add [0x22], 0x0064
	mov [0x09], [0x22]
	call CAVES_DEDUP_CAVES_5B_004_L0
	call CAVES_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14_L9
	mov [0x2C], 0x0000
	jne [0x1D], 0x00, LABEL_6D7A
	video offset=CINEMATIC_769, x=[0x22], y=[0x27]
	ret


LABEL_6D62:
	mov [0x22], [0x21]
	add [0x22], 0x0190
	mov [0x09], [0x22]
	call CAVES_DEDUP_CAVES_5B_004_L0
	call CAVES_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14_L9
	mov [0x2C], 0x0000
	jmp LABEL_6D7A
LABEL_6D79:
	db 0x11

LABEL_6D7A:
	video offset=CINEMATIC_CAVES_LASER_IMPACT_RIGHT_3, x=[0x22], y=[0x27]
	mov [0x13], 0x0080
	mov [0x21], [0x22]
	jl [0x1D], 0x0A, CALL_LABEL_6ED8_AND_RET
	jl [0x1D], 0x14, LABEL_6DF4
	jl [0x1D], 0x1E, LABEL_6DB9
	je [0x1D], 0x1E, LABEL_6DC8
	jge [0x1D], 0x28, LABEL_6DA8

CALL_LABEL_6ED8_AND_RET:
	call CAVES_COPY_VAR40_TO_VAR27_L5
	ret


LABEL_6DA8:
	call CAVES_FOLD_BODY_94B_9F1D7AF8_L10
	mov [0x13], 0xFFFE
	je [0x2C], 0x01, LABEL_6D2A
	jmp LABEL_6D62
LABEL_6DB8:
	db 0x05

LABEL_6DB9:
	call CAVES_COPY_VAR40_TO_VAR27_L5
	call CAVES_SHIELD_ENERGY_LOAD_CASE_14
	mov [0x11], 0xFFFF
	call CAVES_SHIELD_ENERGY_STORE_CASE_14
	ret


LABEL_6DC7:
	db 0x11

LABEL_6DC8:
	call CAVES_FOLD_BODY_94B_9F1D7AF8_L9
	mov [0x13], 0xFFFE
	je [0x2C], 0x01, LABEL_6D2A
	jmp LABEL_6D62
LABEL_6DD8:
	db 0x05

LABEL_6DD9:
	and [0xF8], 0x0080
	jne [0xF8], 0x00, MASK_VAR11_NOSIGN_INCR_VAR21_BY_14
	mov [0xF8], [0x11]
	and [0xF8], 0x0100
	jne [0xF8], 0x00, LABEL_6E23
	jmp CAVES_LASER_BLAST_SWEEP_RIGHT_CASE_64
LABEL_6DF3:
	db 0x11

LABEL_6DF4:
	call LABEL_6F63
	call CAVES_COPY_VAR40_TO_VAR27_L5
	mov [0x21], [0x10]
	mov [0x13], 0x006E
	mov [0xF8], [0x11]
	je [0x2C], 0x01, LABEL_6DD9
	and [0xF8], 0x03FF
	jl [0xF8], 0x0200, LABEL_6E1C

CAVES_LASER_BLAST_SWEEP_RIGHT_CASE_64:
	and [0x11], 0xFDFF
	jmp CAVES_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14_L0

LABEL_6E1C:
	jl [0xF8], 0x0100, MASK_VAR11_NOSIGN_INCR_VAR21_BY_14

LABEL_6E23:
	and [0x11], 0xFEFF
	add [0x21], 0x000A
	jmp CAVES_MASK_VAR11_NOSIGN_INCR_VAR21_BY_14_L0
