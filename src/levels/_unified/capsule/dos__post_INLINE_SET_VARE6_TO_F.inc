DELAY_LOOP_VARE6_AT_3BCD:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_3BCD
	mov [0x27], [0x40]
	je [0x63], 0x06, LABEL_3BF1
	sub [0x27], 0x001E
	call LABEL_3C43
	mov [0x8D], [0x23]
	mov [0x9A], [0x21]
	mov [0x9B], [0x27]
	mov [0x8F], [0x21]
	jmp INLINE_SET_VARE6_TO_F

LABEL_3BF1:
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	sub [0x27], 0x0032
	add [0x27], [0x3B]
	call LABEL_3C59
	jmp INLINE_SET_VARE6_TO_F
LABEL_3C01:
	db 0x11

LABEL_3C02:
	jge [0x04], 0x4000, KILL_CHAN_AT_1471
	mov [0x22], 0x0092
	call LABEL_3B71
	je [0x21], 0x00, LABEL_3C30
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x27], 0x003C
	add [0x27], [0x3A]
	je [HACK_VAR_67], 0xEB, LABEL_3C2D
	mov [0x27], 0x0052
	add [0x27], [0x3B]

LABEL_3C2D:
	call LABEL_3C43

LABEL_3C30:
	call LABEL_3B94
	je [0x21], 0x01, LABEL_3C3C
	call LABEL_3D31

LABEL_3C3C:
	break
	break
	break
	break
	jmp LABEL_3C02

LABEL_3C43:
	mov [0x21], 0xFFEC
	mov [0x23], 0x0064
	or [0x23], 0x8000
	play id=0x0056, freq=0x0A, vol=0x3F, channel=0x02
	call LABEL_3C6F
	ret

LABEL_3C59:
	mov [0x21], 0xFFEC
	mov [0x23], 0x0064
	or [0x23], 0x8000
	play id=0x0056, freq=0x0A, vol=0x3F, channel=0x02
	call LABEL_3CAB
	ret

LABEL_3C6F:
	jne [0x8B], 0xFFFF, LABEL_3C83
	mov [0x8B], [0x23]
	mov [0x96], [0x21]
	mov [0x97], [0x27]
	mov [0x9F], [0x21]
	ret

LABEL_3C83:
	jne [0x8C], 0xFFFF, SHARED_RET
	mov [0x8C], [0x23]
	mov [0x98], [0x21]
	mov [0x99], [0x27]
	mov [0x8E], [0x21]
	ret
	jne [0x8D], 0xFFFF, SHARED_RET
	mov [0x8D], [0x23]
	mov [0x9A], [0x21]
	mov [0x9B], [0x27]
	mov [0x8F], [0x21]
	ret

LABEL_3CAB:
	jne [0x89], 0xFFFF, LABEL_3CBF
	mov [0x89], [0x23]
	mov [0x92], [0x21]
	mov [0x93], [0x27]
	mov [0x9D], [0x21]
	ret

LABEL_3CBF:
	jne [0x8A], 0xFFFF, SHARED_RET
	mov [0x8A], [0x23]
	mov [0x94], [0x21]
	mov [0x95], [0x27]
	mov [0x9E], [0x21]
	ret

JUNK__3CD3:
	break
	mov [0xAF], 0x0000
	je [0xB0], 0x00, KILL_CHAN_AT_3D12
	je [0xB0], 0x01, JUNK__3CD3
	je [0x72], [HACK_VAR_67], JUNK__3CD3
	jne [0x6A], [HACK_VAR_67], JUNK__3CD3
	jl [0x70], 0x00, JUNK__3CD3
	jg [0x68], 0x010E, JUNK__3CD3
	call LABEL_3D13
	call LABEL_30C3
	mov [0xAF], [0x3A]
	add [0xAF], 0x0001

DELAY_LOOP_VARAF:
	break
	djnz [0xAF], DELAY_LOOP_VARAF
	jmp JUNK__3CD3

KILL_CHAN_AT_3D12:
	killChannel

LABEL_3D13:
	call LABEL_3D1A
	jmp JUNK__5B54
LABEL_3D19:
	db 0x05

LABEL_3D1A:
	call LABEL_30C3
	mov [0x21], 0x0140
	add [0x21], [RANDOM_SEED]
	mov [0x27], 0x008C
	add [0x27], [0x3A]
	or [0x27], 0x1800
	ret
LABEL_3D30:
	db 0x11

LABEL_3D31:
	call LABEL_3D38
	jmp LABEL_5B75
LABEL_3D37:
	db 0x05

LABEL_3D38:
	call LABEL_30C3
	mov [0x21], 0xFEC0
	add [0x21], [RANDOM_SEED]
	mov [0x27], 0x008C
	add [0x27], [0x3A]
	or [0x27], 0x1800
	ret
LABEL_3D4E:
	db 0x11

LABEL_3D4F:
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x21], 0xFFC4
	add [0x21], [RANDOM_SEED]
	mov [0x27], 0x0064
	add [0x27], [RANDOM_SEED]
	or [0x27], 0x1800
	or [0x27], 0x2000
	call LABEL_5B75
	break
	break
	jmp LABEL_3D4F

LABEL_3D70:
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x21], 0xFED4
	add [0x21], [RANDOM_SEED]
	mov [0x27], [0x40]
	sub [0x27], 0x0032
	add [0x27], [RANDOM_SEED]
	or [0x27], 0x1800
	or [0x27], 0x2000
	call LABEL_5B75
	break
	break
	jmp LABEL_3D70

LABEL_3D94:
	mov [0xEF], 0x0006

LABEL_3D98:
	jne [HACK_VAR_67], 0x6A, LABEL_3DBE
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x21], 0x015E
	add [0x21], [RANDOM_SEED]
	mov [0x27], 0x0073
	add [0x27], [0x3B]
	or [0x27], 0x1800
	or [0x27], 0x4000
	or [0x27], 0x0000
	call LABEL_5BED

LABEL_3DBE:
	break
	break
	djnz [0xEF], LABEL_3D98
	killChannel

LABEL_3DC5:
	break
	jge [0x73], 0x4000, LABEL_3DE1
	jl [0x74], 0x4000, LABEL_3DE1
	mov [0xF8], [HACK_VAR_67]
	sub [0xF8], 0x0001
	je [0x72], [0xF8], LABEL_3DFF

LABEL_3DE1:
	jge [0x7B], 0x4000, LABEL_3DC5
	jl [0x7C], 0x4000, LABEL_3DC5
	mov [0xF8], [HACK_VAR_67]
	sub [0xF8], 0x0001
	je [0x7A], [0xF8], LABEL_3DFF
	jmp LABEL_3DC5

LABEL_3DFF:
	call LABEL_3D31
	break
	break
	break
	break
	break
	jmp LABEL_3DC5
LABEL_3E0A:
	db 0x11

LABEL_3E0B:
	break
	jl [0x01], 0x91, LABEL_3E0B
	video offset=CINEMATIC_482, x=[0x01], y=[0x02], zoom=[0xc8]	;@enc=alt
	play id=0x0052, freq=0x0A, vol=0x40, channel=0x02
	break
	video offset=CINEMATIC_482, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_482, x=[0x01], y=[0x02], zoom=[0x10]	;@enc=alt
	setup channel=0x04, address=LABEL_3E3D
	break
	video offset=CINEMATIC_483, x=[0x01], y=[0x02], zoom=[0x50]	;@enc=alt
	play id=0x005A, freq=0x0C, vol=0x40, channel=0x02
	killChannel

LABEL_3E3D:
	selectVideoPage 0x00
	video offset=CINEMATIC_484, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	break
	or [0x04], 0x0010
	video offset=CINEMATIC_483, x=[0x01], y=[0x02], zoom=0x40
	deleteChannels first=0x14, last=0x16
	setup channel=0x16, address=LABEL_3E62
	break
	or [0x04], 0x0010
	deleteChannels first=0x14, last=0x15
	killChannel

LABEL_3E62:
	video offset=CINEMATIC_039, x=[0x01], y=100, zoom=0x40
	break
	video offset=CINEMATIC_040, x=[0x01], y=103, zoom=0x40
	break
	video offset=CINEMATIC_041, x=[0x01], y=105, zoom=0x40
	break
	video offset=CINEMATIC_042, x=[0x01], y=106, zoom=0x40
	break
	video offset=CINEMATIC_043, x=[0x01], y=107, zoom=0x40
	break
	sub [0x01], 0x0003
	video offset=CINEMATIC_043, x=[0x01], y=125, zoom=0x40
	break
	sub [0x01], 0x0003
	video offset=CINEMATIC_079, x=[0x01], y=153, zoom=0x40
	break
	sub [0x01], 0x0003
	video offset=CINEMATIC_079, x=[0x01], y=188, zoom=0x40
	break
	sub [0x01], 0x0003
	video offset=CINEMATIC_079, x=[0x01], y=228, zoom=0x40
	mov [0x6C], 0x0002
	setup channel=0x23, address=LABEL_3EBE
	break
	killChannel
	deleteChannels first=0x00, last=0x3B
	setup channel=0x3F, address=KILL_CHANNEL_LANDING
	setup channel=0x04, address=LABEL_1A72
	killChannel

LABEL_3EBE:
	mov [0x29], 0x012C
	mov [0x2F], 0x0019
	jmp DISPATCH_VAR2F_STATE

LABEL_3EC9:
	video offset=CINEMATIC_035, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_035, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_035, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_036, x=[0x07], y=[0x08], zoom=0x40
	break
	mov [0x29], 0x0005

ANIM_CIN_037_LOOP_VAR29_AT_3EE5:
	video offset=CINEMATIC_037, x=[0x07], y=[0x08], zoom=0x40
	break
	djnz [0x29], ANIM_CIN_037_LOOP_VAR29_AT_3EE5
	video offset=CINEMATIC_036, x=[0x07], y=[0x08], zoom=0x40
	break
	mov [0x29], 0x0005

ANIM_CIN_038_LOOP_VAR29:
	video offset=CINEMATIC_038, x=[0x07], y=[0x08], zoom=0x40
	break
	djnz [0x29], ANIM_CIN_038_LOOP_VAR29
	video offset=CINEMATIC_036, x=[0x07], y=[0x08], zoom=0x40
	break
	mov [0x29], 0x0006

ANIM_CIN_037_LOOP_VAR29_AT_3F0D:
	video offset=CINEMATIC_037, x=[0x07], y=[0x08], zoom=0x40
	break
	djnz [0x29], ANIM_CIN_037_LOOP_VAR29_AT_3F0D
	video offset=CINEMATIC_037, x=[0x07], y=[0x08], zoom=0x40
	deleteChannels first=0x00, last=0x3B
	setup channel=0x3F, address=KILL_CHANNEL_LANDING
	setup channel=0x04, address=LABEL_1A72
	killChannel
	video offset=CINEMATIC_039, x=[0x01], y=100, zoom=0x40
	break
	video offset=CINEMATIC_040, x=[0x01], y=103, zoom=0x40
	break
	video offset=CINEMATIC_041, x=[0x01], y=123, zoom=0x40
	break
	video offset=CINEMATIC_042, x=[0x01], y=153, zoom=0x40
	break
	video offset=CINEMATIC_043, x=[0x01], y=188, zoom=0x40
	break
	video offset=CINEMATIC_043, x=[0x01], y=228, zoom=0x40
	sub [0x01], 0x0003
	break
	sub [0x01], 0x0003
	mov [0x03], 0x000A

DELAY_LOOP_VAR03:
	break
	djnz [0x03], DELAY_LOOP_VAR03
	break
	deleteChannels first=0x00, last=0x3B
	setup channel=0x3F, address=KILL_CHANNEL_LANDING
	setup channel=0x04, address=LABEL_1A72
	killChannel

LABEL_3F6C:
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x21], 0xFED4
	add [0x21], [RANDOM_SEED]
	jne [HACK_VAR_67], 0x4B, LABEL_3F82
	jg [0x01], 0x3C, LABEL_3F93

LABEL_3F82:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, LABEL_3F93
	mov [0x21], 0xFFEC

LABEL_3F93:
	mov [0x27], 0x0032
	add [0x27], [RANDOM_SEED]
	or [0x27], 0x0000
	or [0x27], 0x2000
	call LABEL_5B75
	mov [0xF0], [0x3B]
	add [0xF0], 0x0001

LABEL_3FAC:
	break
	jl [0x01], 0x3C, LABEL_3F6C
	djnz [0xF0], LABEL_3FAC
	jmp LABEL_3F6C

LABEL_3FBA:
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x21], 0xFED4
	add [0x21], [RANDOM_SEED]
	jg [0x01], 0x28, LABEL_3FDB
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, LABEL_3FDB
	mov [0x21], 0xFFEC

LABEL_3FDB:
	mov [0x27], 0x0032
	add [0x27], [RANDOM_SEED]
	or [0x27], 0x0000
	or [0x27], 0x2000
	call LABEL_5B75
	mov [0xF0], [0x3B]
	add [0xF0], 0x000A
	break
	jl [0x01], 0x28, LABEL_3FBA
	djnz [0xF0], LABEL_3FAC
	jmp LABEL_3FBA

LABEL_4002:
	add [0x01], 0x0003
	video offset=CINEMATIC_175, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	video offset=CINEMATIC_176, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	break
	video offset=CINEMATIC_177, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_176, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_40FF
LABEL_4028:
	db 0x11

LABEL_4029:
	sub [0x01], 0x0003
	video offset=CINEMATIC_145, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	video offset=CINEMATIC_146, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	mov [0x03], 0x0003

LABEL_4044:
	break
	video offset=CINEMATIC_147, x=[0x01], y=[0x02], zoom=0x40
	djnz [0x03], LABEL_4044
	setup channel=0x15, address=LABEL_4064
	mov [0x03], 0x0003

LABEL_4056:
	break
	video offset=CINEMATIC_148, x=[0x01], y=[0x02], zoom=0x40
	djnz [0x03], LABEL_4056
	jmp LABEL_40FF
LABEL_4063:
	db 0x11

LABEL_4064:
	video offset=CINEMATIC_161, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_162, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_163, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_164, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_165, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_166, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_167, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_168, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_169, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_170, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_171, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_172, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_173, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_174, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_173, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_173, x=[0x01], y=[0x02], zoom=0x40

LABEL_40C3:
	break
	video offset=CINEMATIC_172, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_40C3
LABEL_40CC:
	db 0x11

LABEL_40CD:
	video offset=CINEMATIC_178, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_179, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_180, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_179, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_40FF
LABEL_40E7:
	db 0x11

LABEL_40E8:
	video offset=CINEMATIC_158, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_159, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_160, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_159, x=[0x01], y=[0x02], zoom=0x40

LABEL_40FF:
	selectVideoPage 0x00
	play id=0x005A, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_149, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_150, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_151, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_152, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0x00
	video offset=CINEMATIC_153, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_154, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_155, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_156, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0x00
	video offset=CINEMATIC_157, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	killChannel
	video offset=CINEMATIC_158, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_159, x=[0x01], y=[0x02], zoom=0x40

LABEL_4150:
	break
	video offset=CINEMATIC_160, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_4150
	killChannel
	video offset=CINEMATIC_226, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_707, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_227, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_4170
LABEL_416F:
	db 0x11

LABEL_4170:
	or [0x11], 0x4000
	jne [0x10], [HACK_VAR_67], LABEL_41D6
	play id=0x005A, freq=0x14, vol=0x40, channel=0x00
	video offset=CINEMATIC_217, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_41D6
	video offset=CINEMATIC_218, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_41D6
	video offset=CINEMATIC_219, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_41D6
	video offset=CINEMATIC_220, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_41D6
	video offset=CINEMATIC_221, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_41D6
	video offset=CINEMATIC_222, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_41D6
	video offset=CINEMATIC_223, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0x00
	video offset=CINEMATIC_224, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0xFF

LABEL_41D6:
	call LABEL_5093
	jmp LABEL_41DD
LABEL_41DC:
	db 0x11

LABEL_41DD:
	call SET_VAR2F_TO_0000
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	break
	jmp LABEL_41DD
LABEL_41EA:
	db 0x11

LABEL_41EB:
	jne [0x10], [HACK_VAR_67], LABEL_4170
	video offset=CINEMATIC_226, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_4170
	video offset=CINEMATIC_227, x=[0x07], y=[0x08], zoom=0x40
	mov [0x29], 0x0014

LABEL_4206:
	break
	jne [0x10], [HACK_VAR_67], LABEL_4170
	video offset=CINEMATIC_228, x=[0x07], y=[0x08], zoom=0x40
	jge [0x11], 0x4000, LABEL_421D
	djnz [0x29], LABEL_4206

LABEL_421D:
	break
	jne [0x10], [HACK_VAR_67], LABEL_4170
	video offset=CINEMATIC_227, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_4170
	killChannel
	video offset=CINEMATIC_215, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_707, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_216, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_4170
LABEL_4243:
	db 0x11

LABEL_4244:
	video offset=CINEMATIC_215, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_216, x=[0x07], y=[0x08], zoom=0x40
	mov [0x29], 0x0014

LABEL_4253:
	break
	jne [0x10], [HACK_VAR_67], LABEL_4170
	video offset=CINEMATIC_225, x=[0x07], y=[0x08], zoom=0x40
	jge [0x11], 0x4000, LABEL_426A
	djnz [0x29], LABEL_4253

LABEL_426A:
	break
	jne [0x10], [HACK_VAR_67], LABEL_4170
	video offset=CINEMATIC_216, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_4170
LABEL_427A:
	db 0x11

LABEL_427B:
	mov [0x29], [0x09]
	and [0x09], 0x1FFF
	mov [0x08], [0x40]
	jl [0x09], 0x1000, DERIVE_VAR12_11_10_FROM_VAR9
	mov [0x08], [0x44]
