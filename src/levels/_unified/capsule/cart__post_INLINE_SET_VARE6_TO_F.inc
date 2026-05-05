DELAY_LOOP_VARE6_AT_3B95:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_3B95
	mov [0x27], [0x40]
	je [0x63], 0x06, LABEL_3BB9
	sub [0x27], 0x001E
	call LABEL_3C0B
	mov [0x8D], [0x23]
	mov [0x9A], [0x21]
	mov [0x9B], [0x27]
	mov [0x8F], [0x21]
	jmp INLINE_SET_VARE6_TO_F

LABEL_3BB9:
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	sub [0x27], 0x0032
	add [0x27], [0x3B]
	call LABEL_3C21
	jmp INLINE_SET_VARE6_TO_F
LABEL_3BC9:
	db 0x11

LABEL_3BCA:
	jge [0x04], 0x4000, KILL_CHAN_AT_157F
	mov [0x22], 0x0092
	call LABEL_3B39
	je [0x21], 0x00, LABEL_3BF8
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x27], 0x003C
	add [0x27], [0x3A]
	je [HACK_VAR_67], 0xEB, LABEL_3BF5
	mov [0x27], 0x0052
	add [0x27], [0x3B]

LABEL_3BF5:
	call LABEL_3C0B

LABEL_3BF8:
	call LABEL_3B5C
	je [0x21], 0x01, LABEL_3C04
	call LABEL_3CF9

LABEL_3C04:
	break
	break
	break
	break
	jmp LABEL_3BCA

LABEL_3C0B:
	mov [0x21], 0xFFEC
	mov [0x23], 0x0064
	or [0x23], 0x8000
	play id=0x0056, freq=0x0A, vol=0x3F, channel=0x02
	call LABEL_3C37
	ret

LABEL_3C21:
	mov [0x21], 0xFFEC
	mov [0x23], 0x0064
	or [0x23], 0x8000
	play id=0x0056, freq=0x0A, vol=0x3F, channel=0x02
	call LABEL_3C73
	ret

LABEL_3C37:
	jne [0x8B], 0xFFFF, LABEL_3C4B
	mov [0x8B], [0x23]
	mov [0x96], [0x21]
	mov [0x97], [0x27]
	mov [0x9F], [0x21]
	ret

LABEL_3C4B:
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

LABEL_3C73:
	jne [0x89], 0xFFFF, LABEL_3C87
	mov [0x89], [0x23]
	mov [0x92], [0x21]
	mov [0x93], [0x27]
	mov [0x9D], [0x21]
	ret

LABEL_3C87:
	jne [0x8A], 0xFFFF, SHARED_RET
	mov [0x8A], [0x23]
	mov [0x94], [0x21]
	mov [0x95], [0x27]
	mov [0x9E], [0x21]
	ret

JUNK__3C9B:
	break
	mov [0xAF], 0x0000
	je [0xB0], 0x00, KILL_CHAN_AT_3CDA
	je [0xB0], 0x01, JUNK__3C9B
	je [0x72], [HACK_VAR_67], JUNK__3C9B
	jne [0x6A], [HACK_VAR_67], JUNK__3C9B
	jl [0x70], 0x00, JUNK__3C9B
	jg [0x68], 0x010E, JUNK__3C9B
	call LABEL_3CDB
	call LABEL_3240
	mov [0xAF], [0x3A]
	add [0xAF], 0x0001

DELAY_LOOP_VARAF:
	break
	djnz [0xAF], DELAY_LOOP_VARAF
	jmp JUNK__3C9B

KILL_CHAN_AT_3CDA:
	killChannel

LABEL_3CDB:
	call LABEL_3CE2
	jmp JUNK__5B44
LABEL_3CE1:
	db 0x05

LABEL_3CE2:
	call LABEL_3240
	mov [0x21], 0x0140
	add [0x21], [RANDOM_SEED]
	mov [0x27], 0x008C
	add [0x27], [0x3A]
	or [0x27], 0x1800
	ret
LABEL_3CF8:
	db 0x11

LABEL_3CF9:
	call LABEL_3D00
	jmp LABEL_5B78
LABEL_3CFF:
	db 0x05

LABEL_3D00:
	call LABEL_3240
	mov [0x21], 0xFEC0
	add [0x21], [RANDOM_SEED]
	mov [0x27], 0x008C
	add [0x27], [0x3A]
	or [0x27], 0x1800
	ret
LABEL_3D16:
	db 0x11

LABEL_3D17:
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x21], 0xFFC4
	add [0x21], [RANDOM_SEED]
	mov [0x27], 0x0064
	add [0x27], [RANDOM_SEED]
	or [0x27], 0x1800
	or [0x27], 0x2000
	call LABEL_5B78
	break
	break
	jmp LABEL_3D17

LABEL_3D38:
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x21], 0xFED4
	add [0x21], [RANDOM_SEED]
	mov [0x27], [0x40]
	sub [0x27], 0x0032
	add [0x27], [RANDOM_SEED]
	or [0x27], 0x1800
	or [0x27], 0x2000
	call LABEL_5B78
	break
	break
	jmp LABEL_3D38

LABEL_3D5C:
	mov [0xEF], 0x0006

LABEL_3D60:
	jne [HACK_VAR_67], 0x6A, LABEL_3D86
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x21], 0x015E
	add [0x21], [RANDOM_SEED]
	mov [0x27], 0x0073
	add [0x27], [0x3B]
	or [0x27], 0x1800
	or [0x27], 0x4000
	or [0x27], 0x0000
	call LABEL_5BF0

LABEL_3D86:
	break
	break
	djnz [0xEF], LABEL_3D60
	killChannel

LABEL_3D8D:
	break
	jge [0x73], 0x4000, LABEL_3DA9
	jl [0x74], 0x4000, LABEL_3DA9
	mov [0xF8], [HACK_VAR_67]
	sub [0xF8], 0x0001
	je [0x72], [0xF8], LABEL_3DC7

LABEL_3DA9:
	jge [0x7B], 0x4000, LABEL_3D8D
	jl [0x7C], 0x4000, LABEL_3D8D
	mov [0xF8], [HACK_VAR_67]
	sub [0xF8], 0x0001
	je [0x7A], [0xF8], LABEL_3DC7
	jmp LABEL_3D8D

LABEL_3DC7:
	call LABEL_3CF9
	break
	break
	break
	break
	break
	jmp LABEL_3D8D
LABEL_3DD2:
	db 0x11

LABEL_3DD3:
	break
	jl [0x01], 0x91, LABEL_3DD3
	setup channel=0x05, address=KILL_CHANNEL_LANDING
	video offset=CINEMATIC_486, x=[0x01], y=[0x02], zoom=[0xc8]	;@enc=alt
	play id=0x0052, freq=0x0A, vol=0x40, channel=0x02
	break
	video offset=CINEMATIC_486, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_486, x=[0x01], y=[0x02], zoom=[0x10]	;@enc=alt
	setup channel=0x04, address=LABEL_3E09
	break
	video offset=CINEMATIC_487, x=[0x01], y=[0x02], zoom=[0x50]	;@enc=alt
	play id=0x005A, freq=0x0C, vol=0x40, channel=0x02
	killChannel

LABEL_3E09:
	selectVideoPage 0x00
	video offset=CINEMATIC_488, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	break
	or [0x04], 0x0010
	video offset=CINEMATIC_487, x=[0x01], y=[0x02], zoom=0x40
	deleteChannels first=0x14, last=0x16
	setup channel=0x16, address=LABEL_3E2E
	break
	or [0x04], 0x0010
	deleteChannels first=0x14, last=0x15
	killChannel

LABEL_3E2E:
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
	setup channel=0x23, address=LABEL_3E8A
	break
	killChannel
	deleteChannels first=0x00, last=0x3B
	setup channel=0x3F, address=KILL_CHANNEL_LANDING
	setup channel=0x04, address=LABEL_1B80
	killChannel

LABEL_3E8A:
	mov [0x29], 0x012C
	mov [0x2F], 0x0019
	jmp DISPATCH_VAR2F_STATE

LABEL_3E95:
	video offset=CINEMATIC_035, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_035, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_035, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_036, x=[0x07], y=[0x08], zoom=0x40
	break
	mov [0x29], 0x0005

ANIM_CIN_037_LOOP_VAR29_AT_3EB1:
	video offset=CINEMATIC_037, x=[0x07], y=[0x08], zoom=0x40
	break
	djnz [0x29], ANIM_CIN_037_LOOP_VAR29_AT_3EB1
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

ANIM_CIN_037_LOOP_VAR29_AT_3ED9:
	video offset=CINEMATIC_037, x=[0x07], y=[0x08], zoom=0x40
	break
	djnz [0x29], ANIM_CIN_037_LOOP_VAR29_AT_3ED9
	video offset=CINEMATIC_037, x=[0x07], y=[0x08], zoom=0x40
	deleteChannels first=0x00, last=0x3B
	setup channel=0x3F, address=KILL_CHANNEL_LANDING
	setup channel=0x04, address=LABEL_1B80
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
	setup channel=0x04, address=LABEL_1B80
	killChannel

LABEL_3F38:
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x21], 0xFED4
	add [0x21], [RANDOM_SEED]
	jne [HACK_VAR_67], 0x4B, LABEL_3F4E
	jg [0x01], 0x3C, LABEL_3F5F

LABEL_3F4E:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, LABEL_3F5F
	mov [0x21], 0xFFEC

LABEL_3F5F:
	mov [0x27], 0x0032
	add [0x27], [RANDOM_SEED]
	or [0x27], 0x0000
	or [0x27], 0x2000
	call LABEL_5B78
	mov [0xF0], [0x3B]
	add [0xF0], 0x0001

LABEL_3F78:
	break
	jl [0x01], 0x3C, LABEL_3F38
	djnz [0xF0], LABEL_3F78
	jmp LABEL_3F38

LABEL_3F86:
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [0x21], 0xFED4
	add [0x21], [RANDOM_SEED]
	jg [0x01], 0x28, LABEL_3FA7
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, LABEL_3FA7
	mov [0x21], 0xFFEC

LABEL_3FA7:
	mov [0x27], 0x0032
	add [0x27], [RANDOM_SEED]
	or [0x27], 0x0000
	or [0x27], 0x2000
	call LABEL_5B78
	mov [0xF0], [0x3B]
	add [0xF0], 0x000A
	break
	jl [0x01], 0x28, LABEL_3F86
	djnz [0xF0], LABEL_3F78
	jmp LABEL_3F86

LABEL_3FCE:
	add [0x01], 0x0003
	video offset=CINEMATIC_176, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	video offset=CINEMATIC_177, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	break
	video offset=CINEMATIC_178, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_177, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_40CB
LABEL_3FF4:
	db 0x11

LABEL_3FF5:
	sub [0x01], 0x0003
	video offset=CINEMATIC_146, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	video offset=CINEMATIC_147, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	mov [0x03], 0x0003

LABEL_4010:
	break
	video offset=CINEMATIC_148, x=[0x01], y=[0x02], zoom=0x40
	djnz [0x03], LABEL_4010
	setup channel=0x15, address=LABEL_4030
	mov [0x03], 0x0003

LABEL_4022:
	break
	video offset=CINEMATIC_149, x=[0x01], y=[0x02], zoom=0x40
	djnz [0x03], LABEL_4022
	jmp LABEL_40CB
LABEL_402F:
	db 0x11

LABEL_4030:
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
	video offset=CINEMATIC_175, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_174, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_174, x=[0x01], y=[0x02], zoom=0x40

LABEL_408F:
	break
	video offset=CINEMATIC_173, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_408F
LABEL_4098:
	db 0x11

LABEL_4099:
	video offset=CINEMATIC_179, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_180, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_181, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_180, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_40CB
LABEL_40B3:
	db 0x11

LABEL_40B4:
	video offset=CINEMATIC_159, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_160, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_161, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_160, x=[0x01], y=[0x02], zoom=0x40

LABEL_40CB:
	selectVideoPage 0x00
	play id=0x005A, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_150, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_151, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_152, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_153, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0x00
	video offset=CINEMATIC_154, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_155, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_156, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_157, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0x00
	video offset=CINEMATIC_158, x=[0x01], y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	killChannel
	video offset=CINEMATIC_159, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_160, x=[0x01], y=[0x02], zoom=0x40

LABEL_411C:
	break
	video offset=CINEMATIC_161, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_411C
	killChannel
	video offset=CINEMATIC_227, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_710, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_228, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_413C
LABEL_413B:
	db 0x11

LABEL_413C:
	or [0x11], 0x4000
	jne [0x10], [HACK_VAR_67], LABEL_41A2
	play id=0x005A, freq=0x14, vol=0x40, channel=0x00
	video offset=CINEMATIC_217, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_41A2
	video offset=CINEMATIC_218, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_41A2
	video offset=CINEMATIC_219, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_41A2
	video offset=CINEMATIC_220, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_41A2
	video offset=CINEMATIC_221, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_41A2
	video offset=CINEMATIC_222, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_41A2
	video offset=CINEMATIC_223, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0x00
	video offset=CINEMATIC_224, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0xFF

LABEL_41A2:
	call LABEL_506F
	jmp LABEL_41A9
LABEL_41A8:
	db 0x11

LABEL_41A9:
	call SET_VAR2F_TO_0000
	jne [0x2F], 0x00, DISPATCH_VAR2F_STATE
	break
	jmp LABEL_41A9
LABEL_41B6:
	db 0x11

LABEL_41B7:
	jne [0x10], [HACK_VAR_67], LABEL_413C
	video offset=CINEMATIC_227, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_413C
	video offset=CINEMATIC_228, x=[0x07], y=[0x08], zoom=0x40
	mov [0x29], 0x0014

LABEL_41D2:
	break
	jne [0x10], [HACK_VAR_67], LABEL_413C
	video offset=CINEMATIC_229, x=[0x07], y=[0x08], zoom=0x40
	jge [0x11], 0x4000, LABEL_41E9
	djnz [0x29], LABEL_41D2

LABEL_41E9:
	break
	jne [0x10], [HACK_VAR_67], LABEL_413C
	video offset=CINEMATIC_228, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_413C
	killChannel
	video offset=CINEMATIC_216, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_710, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_226, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_413C
LABEL_420F:
	db 0x11

LABEL_4210:
	video offset=CINEMATIC_216, x=[0x07], y=[0x08], zoom=0x40
	break
	jne [0x10], [HACK_VAR_67], LABEL_4221
	video offset=CINEMATIC_226, x=[0x07], y=[0x08], zoom=0x40

LABEL_4221:
	mov [0x29], 0x0014

LABEL_4225:
	break
	jne [0x10], [HACK_VAR_67], LABEL_413C
	video offset=CINEMATIC_225, x=[0x07], y=[0x08], zoom=0x40
	jge [0x11], 0x4000, LABEL_423C
	djnz [0x29], LABEL_4225

LABEL_423C:
	break
	jne [0x10], [HACK_VAR_67], LABEL_413C
	video offset=CINEMATIC_226, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_413C
LABEL_424C:
	db 0x11

LABEL_424D:
	mov [0x29], [0x09]
	and [0x09], 0x1FFF
	mov [0x08], [0x40]
	jl [0x09], 0x1000, DERIVE_VAR12_11_10_FROM_VAR9
	mov [0x08], [0x44]
