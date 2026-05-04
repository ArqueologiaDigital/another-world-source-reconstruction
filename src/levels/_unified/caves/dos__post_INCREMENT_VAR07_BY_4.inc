LABEL_4985:
	mov [0x21], 0x0000
	jne [0x22], 0x92, LABEL_4992
	mov [0x21], [0xB8]

LABEL_4992:
	jne [0x22], 0x93, LABEL_49A0
	mov [0x21], [0xB9]
	and [0x21], 0x01FF
	ret

LABEL_49A0:
	jne [0x22], 0x94, SHARED_RET
	mov [0x21], [0xB9]
	and [0x21], 0xFE00
	ret

LABEL_49AE:
	jne [0x22], 0x92, LABEL_49B9
	mov [0xB8], 0x0000
	ret

LABEL_49B9:
	jne [0x22], 0x93, LABEL_49C4
	and [0xB9], 0xFE00
	ret

LABEL_49C4:
	jne [0x22], 0x94, SHARED_RET
	and [0xB9], 0x01FF
	ret

LABEL_49CF:
	mov [0x21], 0x0001
	jne [0xAA], 0xFFFF, SHARED_RET
	jne [0xAD], 0xFFFF, SHARED_RET
	mov [0x21], 0x0000
	ret
	mov [0x21], 0x0001
	jne [0xA1], 0xFFFF, SHARED_RET
	jne [0xA4], 0xFFFF, SHARED_RET
	jne [0xA7], 0xFFFF, SHARED_RET
	mov [0x21], 0x0000
	ret

LABEL_4A04:
	break
	add [0xF0], 0x0001
	jl [0xF0], 0x32, LABEL_4A04
	mov [0xF8], [0xF1]
	add [0xF8], 0x0001
	je [0xF8], [HACK_VAR_67], LABEL_4A04
	add [0xF1], 0x0001
	mov [0x22], [0xF1]
	call LABEL_49AE
	mov [0xF0], 0x000A
	jle [0xF1], 0x93, LABEL_4A04
	mov [0xF0], 0x0000
	jmp LABEL_4A04

LABEL_4A37:
	jge [0x04], 0x4000, KILL_CHAN_AT_016E
	mov [0xF8], [0xF1]
	add [0xF8], 0x0001
	jg [HACK_VAR_67], [0xF8], LABEL_4A67
	jl [0x02], 0x64, LABEL_4A73
	mov [0x22], 0x0092
	call LABEL_4985
	je [0xF1], 0x94, LABEL_4A67
	call LABEL_4A77
	je [0x21], 0x00, LABEL_4A67

LABEL_4A67:
	call LABEL_49CF
	je [0x21], 0x01, LABEL_4A73
	call LABEL_4B2F

LABEL_4A73:
	break
	jmp LABEL_4A37

LABEL_4A77:
	mov [0x21], 0xFFEC
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x27], 0x0078
	add [0x27], [RANDOM_SEED]
	mov [0x23], 0x0064
	or [0x23], 0x8000
	call LABEL_4A91
	ret

LABEL_4A91:
	jne [0x8B], 0xFFFF, LABEL_4AA7
	mov [0x8B], [0x23]
	mov [0x96], [0x21]
	mov [0x97], [0x27]
	mov [0x9F], [0x21]
	jmp LABEL_65FE

LABEL_4AA7:
	jne [0x8C], 0xFFFF, LABEL_4ABD
	mov [0x8C], [0x23]
	mov [0x98], [0x21]
	mov [0x99], [0x27]
	mov [0x8E], [0x21]
	jmp LABEL_65FE

LABEL_4ABD:
	jne [0x8D], 0xFFFF, SHARED_RET
	mov [0x8D], [0x23]
	mov [0x9A], [0x21]
	mov [0x9B], [0x27]
	mov [0x8F], [0x21]
	ret

JUNK__4AD1:
	break
	mov [0xAF], 0x0000
	je [0xB0], 0x00, KILL_CHAN_AT_4B10
	je [0xB0], 0x01, JUNK__4AD1
	je [0x72], [HACK_VAR_67], JUNK__4AD1
	jne [0x6A], [HACK_VAR_67], JUNK__4AD1
	jl [0x70], 0x00, JUNK__4AD1
	jg [0x68], 0x010E, JUNK__4AD1
	call LABEL_4B11
	call SETUP_HASH_AND_DERIVE_BUCKETS
	mov [0xAF], [0x3A]
	add [0xAF], 0x0001

DELAY_LOOP_VARAF:
	break
	djnz [0xAF], DELAY_LOOP_VARAF
	jmp JUNK__4AD1

KILL_CHAN_AT_4B10:
	killChannel

LABEL_4B11:
	call LABEL_4B18
	jmp LABEL_6578
LABEL_4B17:
	db 0x05

LABEL_4B18:
	call SETUP_HASH_AND_DERIVE_BUCKETS
	mov [0x21], 0x0140
	add [0x21], [RANDOM_SEED]
	mov [0x27], 0x008C
	add [0x27], [0x3A]
	or [0x27], 0x1800
	ret
LABEL_4B2E:
	db 0x11

LABEL_4B2F:
	call LABEL_4B41
	jmp LABEL_6599
	ret
	call LABEL_4B41
	add [0x21], 0x00DC
	jmp LABEL_6599
LABEL_4B40:
	db 0x05

LABEL_4B41:
	call SETUP_HASH_AND_DERIVE_BUCKETS
	mov [0x21], 0xFEC0
	add [0x21], [RANDOM_SEED]
	mov [0x27], 0x008C
	add [0x27], [0x3A]
	or [0x27], 0x1800
	ret
LABEL_4B57:
	db 0x11

LABEL_4B58:
	break
	jge [0x73], 0x4000, LABEL_4B74
	jl [0x74], 0x4000, LABEL_4B74
	mov [0xF8], [HACK_VAR_67]
	sub [0xF8], 0x0001
	je [0x72], [0xF8], LABEL_4B92

LABEL_4B74:
	jge [0x7B], 0x4000, LABEL_4B58
	jl [0x7C], 0x4000, LABEL_4B58
	mov [0xF8], [HACK_VAR_67]
	sub [0xF8], 0x0001
	je [0x7A], [0xF8], LABEL_4B92
	jmp LABEL_4B58

LABEL_4B92:
	call LABEL_4B2F
	break
	break
	break
	break
	break
	jmp LABEL_4B58
LABEL_4B9D:
	db 0x11

LABEL_4B9E:
	add [0x01], 0x0003
	video type=1, offset=CINEMATIC_124, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_125, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	break
	video type=1, offset=CINEMATIC_126, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_125, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CIN_98_99_BLOCK
LABEL_4BC4:
	db 0x11

LABEL_4BC5:
	sub [0x01], 0x0003
	video type=1, offset=CINEMATIC_094, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_095, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	mov [0x03], 0x0003

LABEL_4BE0:
	break
	video type=1, offset=CINEMATIC_096, x=[0x01], y=[0x02], zoom=0x40
	djnz [0x03], LABEL_4BE0
	setup channel=0x15, address=DRAW_CIN_110_BLOCK
	mov [0x03], 0x0003

LABEL_4BF2:
	break
	video type=1, offset=CINEMATIC_097, x=[0x01], y=[0x02], zoom=0x40
	djnz [0x03], LABEL_4BF2
	jmp DRAW_CIN_98_99_BLOCK
LABEL_4BFF:
	db 0x11

DRAW_CIN_110_BLOCK:
	video type=1, offset=CINEMATIC_110, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_111, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_112, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_113, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_114, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_115, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_116, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_117, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_118, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_119, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_120, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_121, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_122, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_123, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_122, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_122, x=[0x01], y=[0x02], zoom=0x40

LABEL_4C5F:
	break
	video type=1, offset=CINEMATIC_121, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_4C5F
LABEL_4C68:
	db 0x11

LABEL_4C69:
	video type=1, offset=CINEMATIC_127, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_128, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_129, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_128, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CIN_98_99_BLOCK
LABEL_4C83:
	db 0x11

LABEL_4C84:
	video type=1, offset=CINEMATIC_107, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_108, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_109, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_108, x=[0x01], y=[0x02], zoom=0x40

DRAW_CIN_98_99_BLOCK:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_098, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	play id=0x005A, freq=0x14, vol=0x40, channel=0x01
	break
	video type=1, offset=CINEMATIC_099, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_100, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_101, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_102, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_103, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_104, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_105, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_106, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	killChannel
	video type=1, offset=CINEMATIC_107, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_108, x=[0x01], y=[0x02], zoom=0x40

LABEL_4CEC:
	break
	video type=1, offset=CINEMATIC_109, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_4CEC
	killChannel
	video type=1, offset=CINEMATIC_091, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_897, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_092, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_4D0C
LABEL_4D0B:
	db 0x11

LABEL_4D0C:
	or [0x11], 0x4000
	jne [0x10], [HACK_VAR_67], LABEL_4D72
	play id=0x005A, freq=0x14, vol=0x40, channel=0x00
	video type=1, offset=CINEMATIC_082, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_4D72
	video type=1, offset=CINEMATIC_083, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_4D72
	video type=1, offset=CINEMATIC_084, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_4D72
	video type=1, offset=CINEMATIC_085, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_4D72
	video type=1, offset=CINEMATIC_086, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_4D72
	video type=1, offset=CINEMATIC_087, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_4D72
	video type=1, offset=CINEMATIC_088, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_089, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0xFF

LABEL_4D72:
	call LABEL_5BAF
	jmp LABEL_4D79
LABEL_4D78:
	db 0x11

LABEL_4D79:
	call SET_VAR2F_TO_0000
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	break
	jmp LABEL_4D79
LABEL_4D86:
	db 0x11

LABEL_4D87:
	jne [0x10], [HACK_VAR_67], LABEL_4D0C
	video type=1, offset=CINEMATIC_091, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_4D0C
	video type=1, offset=CINEMATIC_092, x=[0x07], y=[0x08], zoom=0x40
	mov [0x29], 0x0014

LABEL_4DA2:
	break
	jne [0x10], [HACK_VAR_67], LABEL_4D0C
	video type=1, offset=CINEMATIC_093, x=[0x07], y=[0x08], zoom=0x40
	jge [0x11], 0x4000, LABEL_4DB9
	djnz [0x29], LABEL_4DA2

LABEL_4DB9:
	break
	jne [0x10], [HACK_VAR_67], LABEL_4D0C
	video type=1, offset=CINEMATIC_092, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_4D0C
	killChannel
	video type=1, offset=CINEMATIC_080, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_897, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_081, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_4D0C
LABEL_4DDF:
	db 0x11

LABEL_4DE0:
	video type=1, offset=CINEMATIC_080, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_081, x=[0x07], y=[0x08], zoom=0x40
	mov [0x29], 0x0014

LABEL_4DEF:
	break
	jne [0x10], [HACK_VAR_67], LABEL_4D0C
	video type=1, offset=CINEMATIC_090, x=[0x07], y=[0x08], zoom=0x40
	jge [0x11], 0x4000, LABEL_4E06
	djnz [0x29], LABEL_4DEF

LABEL_4E06:
	break
	jne [0x10], [HACK_VAR_67], LABEL_4D0C
	video type=1, offset=CINEMATIC_081, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_4D0C
LABEL_4E16:
	db 0x11

LABEL_4E17:
	mov [0x29], [0x09]
	and [0x09], 0x1FFF
	mov [0x08], [0x40]
	jl [0x09], 0x1000, DERIVE_VAR12_11_10_FROM_VAR9
	mov [0x08], [0x44]


; (dos has no chunk here — dos_post_a above already spans through to DERIVE)
